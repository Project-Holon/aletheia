/*
 * function: func_021A428C
 * address:  0x021A428C
 * packet:   pkt_ov021_021A428C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a sound id from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter at +0x1a.
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A5318  0x021A5318  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   d_021D8A00     0x021D8A00  data  ov021  a4
 *   d_021D8A0C     0x021D8A0C  data  ov021  a4
 *   d_021D89F4     0x021D89F4  data  ov021  a4
 *   d_021D8A2C     0x021D8A2C  data  a4
 * Addresses are Black-image addresses.
 * d_021D8A2C carries no ov021 token: with it the hint reads as contested.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 mask; int val; s16 a; s16 b; } T1;
typedef struct { int (*fn)(u16); u16 val; s8 a; s8 b; u8 kind; } T2;

extern T1 d_021D8A00[];
extern T1 d_021D8A0C[];
extern T2 d_021D89F4[];
extern T2 d_021D8A2C[];

extern int func_021A3974(u32);
extern u32 func_021A5318(u8 *, u32);
extern void *func_021A3960(unsigned char *p);
extern int func_02163E34(u32, int, u32 *);
extern u16 func_021AB0F8(u32);
extern void func_020061E4(int);

int func_021A428C(u8 *o, int unused, int c, int flag, int kind)
{
    int lim;
    int sel;
    u32 id;
    int mode;
    T1 *t;
    T2 *u;
    u32 bits;

    sel = 0x546;
    lim = 0;
    mode = 0;
    if (func_021A3974(*(u32 *)(o + 0xc)) == 1) {
        mode = 2;
    } else if (func_021A5318(o, 0x20) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        *(u16 *)(o + 0x18) = 0x546;
        *(u16 *)(o + 0x1a) = 0;
    }
    if (func_02163E34(func_021A3960(*(void **)(o + 0xc)), c, &id) == 1) {
        bits = func_021AB0F8(id);
        if (flag == 0) {
            t = d_021D8A00;
        } else {
            t = d_021D8A0C;
        }
        for (; t->mask != 0; t++) {
            if (t->mask & bits) {
                sel = t->val;
                if (mode == 1) {
                    lim = t->a;
                } else if (mode == 2) {
                    lim = t->b;
                }
                break;
            }
        }
        if (sel == 0x546) {
            u = d_021D89F4;
            if (flag != 0) {
                u = d_021D8A2C;
            }
            for (; u->fn != 0; u++) {
                if (u->fn((u16)id) == 1 && (u->kind == 4 || u->kind == kind)) {
                    sel = u->val;
                    if (mode == 1) {
                        lim = u->a;
                    } else if (mode == 2) {
                        lim = u->b;
                    }
                    break;
                }
            }
        }
        if (sel == 0x546) {
            if (flag == 1) {
                *(u16 *)(o + 0x1a) = 0;
            }
        } else if (mode != 0) {
            if (*(u16 *)(o + 0x18) != sel) {
                *(u16 *)(o + 0x1a) = 0;
            }
            if (*(u16 *)(o + 0x1a) != 0 && *(u16 *)(o + 0x1a) < lim) {
                sel = 0x546;
            }
            if (*(u16 *)(o + 0x1a) >= lim) {
                *(u16 *)(o + 0x1a) = 0;
            }
            *(u16 *)(o + 0x18) = sel;
            *(u16 *)(o + 0x1a) = *(u16 *)(o + 0x1a) + 1;
        }
        if (sel != 0x546) {
            func_020061E4(sel);
            return 1;
        }
    }
    return 0;
}
