/*
 * function: func_021BAFA0
 * address:  0x021BAFA0
 * packet:   pkt_ov091_021BAFA0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Each arm has two separate then-blocks with the same call (the
 * `beq -> b` and `b` into the other block's `movs r2,#8` are cross-jumps);
 * one `||` condition was 4 bytes short. a[0xc] read at each use (a
 * local puts the load before `cmp r6,#1`). The result buffer comes back from
 * a static inline wrapper of func_021BB56C, which sets r5 after the
 * argument registers; a plain `p = b1;` sets it first.
 *
 * symbols:
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BB050  0x021BB050  thumb  ov091
 *   func_0204B878  0x0204B878  arm
 *   func_021BB56C  0x021BB56C  thumb  ov091
 *   func_0204B404  0x0204B404  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Obj;
struct Vec2;
extern int func_021B9A84(u32 p);
extern void func_021BB050(int unused, u8 *s, int k);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021BB56C(u8 *s, int a, int b, s16 *out);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

static inline s16 *get(u8 *s, int x, int y, s16 *buf)
{
    func_021BB56C(s, x, y, buf);
    return buf;
}

void func_021BAFA0(u8 *a, u8 *s, int k)
{
    s16 b1[2];
    s16 b0[2];
    s16 *p;

    if (k == 1) {
        if ((u8)(a[0xc] + 253) <= 1)
            func_021BB050((int)a, s, 8);
        else if (func_021B9A84((u32)a) == 1 && *(int *)(s + 0x1c) < 6)
            func_021BB050((int)a, s, 8);
        else
            func_021BB050((int)a, s, 6);
        func_0204B878((struct Obj *)(*(int *)(s + 0x34)), 1);
        p = get(s, 0x1a, 0x13, b1);
    } else {
        if ((a[0xc] == 3 && *(int *)(a + 0x30) == s[4]) ||
            (a[0xc] == 4 && *(int *)(a + 0x34) == s[4]))
            func_021BB050((int)a, s, 5);
        else if (func_021B9A84((u32)a) == 1 && *(int *)(s + 0x1c) < 6)
            func_021BB050((int)a, s, 5);
        else
            func_021BB050((int)a, s, 3);
        func_0204B878((struct Obj *)(*(int *)(s + 0x34)), 0);
        p = get(s, 0x18, 0x10, b0);
    }
    func_0204B404((struct Obj *)(*(int *)(s + 0x30)), (const struct Vec2 *)p, 0);
    *(int *)(s + 0x10) = k;
}
