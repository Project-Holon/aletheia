/*
 * file:     unit_021E18EC_p04.c
 * unit:     yes
 * function: func_021E1AA4, func_021E1AE4
 * address:  0x021E1AA4
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B10  0x021D7B10  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Ent { u16 a; u16 b; u8 c; u8 d; u8 e; u8 f; } Ent;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021D7B10(u32 a, u32 b);
extern int func_021D76BC(int key, u32 val);
extern u8 func_021D5440(u8 *p);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021B9A24(u32 a, u32 b);
extern int func_0201C1E8(int a);
void func_021E1AA4(void *p, int id, int u, int x, int arg);
int func_021E1AE4(void *m, int x, Ent *out);


void func_021E1AA4(void *p, int id, int u, int x, int arg)
{
    Ent e;
    if (id == func_021D775C(3)) {
        if (func_021E1AE4(func_021C7CF4(p, id), x, &e)) {
            func_021D76BC(0x37, func_021D7B10(e.b, arg));
        }
    }
}


int func_021E1AE4(void *m, int x, Ent *out)
{
    u8 q = func_021D5440(m);
    u8 i = 0;
    while (func_021D6940(m, 0, i++, (u16 *)out)) {
        if (func_021B9A24(q, out->d) == 0) {
            if (x == 0 || x == func_0201C1E8(out->a))
                return 1;
        }
    }
    return 0;
}
