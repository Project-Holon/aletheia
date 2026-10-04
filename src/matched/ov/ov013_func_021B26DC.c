/*
 * function: func_021B26DC
 * address:  0x021B26DC
 * packet:   pkt_ov013_021B26DC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_021B2620  0x021B2620  arm  ov013
 */

typedef unsigned char u8;

extern char d_021B4C0C;
extern void func_021B2848(void *o, u8 *p, int n);
extern int func_021B2620(int *o, u8 *p);

void func_021B26DC(int x)
{
    u8 buf[16];

    buf[4] = 0xff;
    func_021B2848(&d_021B4C0C, buf, 4);
    buf[10] = x;
    func_021B2620((int *)(&d_021B4C0C), buf);
}
