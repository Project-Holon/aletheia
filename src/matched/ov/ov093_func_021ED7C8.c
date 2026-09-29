/*
 * function: func_021ED7C8
 * address:  0x021ED7C8
 * packet:   pkt_ov093_021ED7C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { int h; int x; int y; int dx; int dy; u8 state; u8 cnt; };

extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02045334(int);

void func_021ED7C8(struct S *s, int keep)
{
    if ((u8)(s->state + 0xff) <= 1) {
        if (keep == 0) {
            func_02043B5C(func_02045770(s->h), 0xc);
            func_02045334(s->h);
        }
        s->x = 0;
        s->y = 0x10000;
        s->dx = 0x52aa;
        s->dy = -0x1800;
        s->cnt = 6;
        s->state = 4;
    }
}
