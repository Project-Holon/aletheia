/*
 * file:     unit_021D5EA8_p03.c
 * unit:     yes
 * function: func_021D621C, func_021D6238, func_021D6264, func_021D62A8
 * address:  0x021D621C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8918  0x021E8918  thumb  ov093
 *   func_021D7D6C  0x021D7D6C  thumb  ov093
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021E8928  0x021E8928  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 */
struct Unk021D621C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Slot { u32 a : 3; u32 rest : 29; };

struct Unk021D621C { u8 pad[0x40]; struct Slot f40; u8 pad44[0x71]; u8 fB5; };

struct UtilSlots_021D6238 { u8 pad[0x1c]; struct Slot s[16]; u8 pad5C[0x50]; u8 b[16]; };

struct UtilSlots_021D6264 { u8 pad[0x1c]; struct Slot s[36]; };

struct Unk021D62A8 { u8 pad[0x1C]; struct Slot e[6]; };

extern struct Slot func_021E8918(void);
extern int func_021D7D6C(int x);
extern void func_021D61F0(struct UtilSlots_021D6238 *p);
extern int func_021E8928(struct Slot s);
extern int func_021E8A98(struct Slot s);
void func_021D621C(struct Unk021D621C *p, int k);
void func_021D6238(struct UtilSlots_021D6238 *p, int k);
void func_021D6264(struct UtilSlots_021D6264 *p, int v);
int func_021D62A8(struct Unk021D62A8 *p);

void func_021D621C(struct Unk021D621C *p, int k)
{
    if (k == 2) {
        p->f40 = func_021E8918();
        p->fB5 = 0;
    }
}


void func_021D6238(struct UtilSlots_021D6238 *p, int k)
{
    if (func_021D7D6C(k) != 0) {
        func_021D61F0(p);
        return;
    }
    p->s[k] = func_021E8918();
    p->b[k] = 0;
}


void func_021D6264(struct UtilSlots_021D6264 *p, int v)
{
    u32 i;
    if (v != 0x1f) {
        for (i = 0; i < 0x24; i++) {
            if (func_021E8928(p->s[i]) == 0 && v == func_021E8A98(p->s[i])) {
                p->s[i] = func_021E8918();
                func_021D621C((struct Unk021D621C *)p, i);
            }
        }
    }
}

int func_021D62A8(struct Unk021D62A8 *p)
{
    u32 i;
    for (i = 1; i < 6; i++) {
        if (p->e[i].a) return i;
    }
    return 0;
}
