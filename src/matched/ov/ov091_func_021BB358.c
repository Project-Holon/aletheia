/*
 * function: func_021BB358
 * address:  0x021BB358
 * packet:   pkt_ov091_021BB358
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BB050  0x021BB050  thumb  ov091
 *   func_021BB2E0  0x021BB2E0  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct S {
    u8 pad[6];
    u16 a;
    u16 b;
} S;

extern void func_021BB050(int unused, u8 *s, int k);
extern void func_021BB2E0(u8 *a, u8 *s);

int func_021BB358(u8 *p, S *s)
{
    if (s->a < s->b) {
        if (s->a == 0) {
            func_021BB050((int)p, (u8 *)s, 6);
        }
        {
            u16 cur = s->a;
            signed char st = p[0x11E];
            u16 lim = s->b;
            if (cur + st > lim) {
                s->a = lim;
            } else {
                s->a = cur + (u16)st;
            }
        }
        func_021BB2E0(p, (u8 *)s);
        return 0;
    }
    if (s->a > s->b) {
        signed char st = p[0x11E];
        if (s->a + st < s->b) {
            s->a = s->b;
        } else {
            s->a = s->a + (u16)st;
        }
        func_021BB2E0(p, (u8 *)s);
        return 0;
    }
    return 1;
}
