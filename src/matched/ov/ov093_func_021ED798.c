/*
 * function: BTLV_SCU_StartMsgWinFadeOut
 * address:  0x021ED798
 * packet:   pkt_ov093_021ED798
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned char u8;
struct S { int a; int x4; int x8; int xc; int x10; u8 state; u8 b15; };
void BTLV_SCU_StartMsgWinFadeOut(struct S *s)
{
    u8 st = s->state;
    if (st == 0 || st == 3) {
        s->x4 = 0x1f000;
        s->x8 = 0x7000;
        s->xc = -0x52aa;
        s->x10 = 0x1800;
        s->b15 = 6;
        s->state = 1;
    }
}
