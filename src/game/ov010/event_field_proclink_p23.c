/*
 * file:     event_field_proclink_p23.c
 * unit:     yes
 * function: func_02161484, func_02161534
 * address:  0x02161484
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02034A5C 0x02034A5C arm
 *   func_021C3E00 0x021C3E00 thumb ov136
 *   func_021C3E04 0x021C3E04 thumb ov136
 *   ov136_id 0x00000088 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_021C3E24 0x021C3E24 thumb ov136
 */
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Ctx {
    u8 pad00[8];
    u32 f08;
    u32 f0c;
    u8 pad10[8];
    u32 **f18;
    u8 pad1c[0x60 - 0x1C];
    u8 f60;
    u8 pad61[7];
    u32 f68;
} Ctx;

typedef signed int     s32;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *a, u32 b);
extern void func_02034A5C(s32 handle);
extern u32 func_021C3E00(u32 *p);
extern int func_021C3E04(u32 *p, void *q);
extern int func_02034AC4(s32 handle);
extern void func_021C3E24(unsigned char *);
int func_02161484(Ctx *c, void *p);
void func_02161534(unsigned char *p);
extern u8 ov136_id[];

/*
 * Lever: second state writes f0c separately in each arm; cross-jumping
 * retains the dead branch after func_021C3E04 rather than after movs #0.
 */
int func_02161484(Ctx *c, void *p)
{
    void *sv;
    u32 v;
    sv = func_020120F4((const struct Ctx *)(*c->f18));
    if (c->f08 == 0) {
        if (c->f68 == 0 || c->f68 == 2) {
            if (func_021C3E00(p) == 1) {
                func_021C3E04(p, func_0201AB28(func_02012934(sv), c->f60));
                v = 0;
            } else if (c->f68 == 0) {
                v = 2;
            } else {
                v = 0;
            }
        } else {
            v = 0;
        }
        c->f0c = v;
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    if (c->f08 == 2) {
        if (c->f68 == 2) {
            if (func_021C3E00(p) == 1) {
                func_021C3E04(p, func_0201AB28(func_02012934(sv), c->f60));
                c->f0c = 0;
            } else {
                c->f0c = 0;
            }
        } else {
            c->f0c = 2;
        }
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    c->f0c = 2;
    func_02034A5C((u32)ov136_id);
    return 4;
}

void func_02161534(unsigned char *p) { func_02034AC4((u32)ov136_id); func_021C3E24(p); func_02034A5C((u32)ov136_id); }
