/*
 * function: BTLV_SCU_UpdateMsgWinFade
 * address:  0x021ED814
 * packet:   pkt_ov093_021ED814
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the shared step block at 0x021ED84A is the same code written in
 * both arms (case 3 and case 1) with the same `if (cnt != 0)` polarity; the
 * compiler cross-jumps the second copy into `b 0x021ED84A`.  A goto into the
 * first copy, or `== 0` polarity, moves the branches.
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { int h; int x; int y; int dx; int dy; u8 state; u8 cnt; };

extern void func_0207D63C(void *, int, int, int, int);

int BTLV_SCU_UpdateMsgWinFade(struct S *s)
{
    switch (s->state) {
    case 2:
        return 1;
    case 0:
        return 1;
    case 4:
        s->state = 3;
        return 0;
    case 3:
        if (s->cnt != 0) {
            s->x += s->dx;
            s->y += s->dy;
            s->cnt = s->cnt - 1;
        } else {
            s->x = 0x1f000;
            s->y = 0x7000;
            s->state = 0;
        }
        break;
    case 1:
        if (s->cnt != 0) {
            s->x += s->dx;
            s->y += s->dy;
            s->cnt = s->cnt - 1;
        } else {
            s->x = 0;
            s->y = 0x10000;
            s->state = 2;
        }
        break;
    }
    func_0207D63C((void *)0x04000050, 2, 0x3d, (u8)(s->x >> 12), (u8)(s->y >> 12));
    return 0;
}
