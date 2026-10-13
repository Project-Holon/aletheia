/*
 * function: BTLV_SCU_InitMsgWinFade
 * address:  0x021ED76C
 * packet:   pkt_ov093_021ED76C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm  arm9
 */
typedef unsigned char u8;
struct S { int a; int x4; int x8; int xc; int x10; u8 state; u8 b15; };
extern void func_0207D63C(int, int, int, int, int);
void BTLV_SCU_InitMsgWinFade(struct S *s, int a)
{
    s->a = a;
    s->state = 0;
    s->x4 = 0x1f000;
    s->x8 = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}
