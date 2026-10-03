/*
 * function: func_021B386C
 * address:  0x021B386C
 * packet:   pkt_ov013_021B386C
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60CC  0x021B60CC  data  a4
 *   func_021B23E0  0x021B23E0  arm  ov013
 *   func_021B11E8  0x021B11E8  arm  ov013
 *   func_021B111C  0x021B111C  arm  ov013
 */

extern int d_021B60CC[];
extern void func_021B23E0(void);
extern int func_021B11E8(void);
extern int func_021B111C(void);

void func_021B386C(void)
{
    if (d_021B60CC[2] == 0)
        return;
    d_021B60CC[0]++;
    if ((d_021B60CC[0] & 0xf) == 0)
        func_021B23E0();
    if (func_021B11E8())
        func_021B111C();
}
