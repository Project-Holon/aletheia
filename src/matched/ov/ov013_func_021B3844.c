/*
 * function: func_021B3844
 * address:  0x021B3844
 * packet:   pkt_021B3844
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60CC  0x021B60CC  data  ov013
 *   func_021B0600  0x021B0600  arm  ov013
 *   func_021B23C8  0x021B23C8  arm  ov013
 *   func_021B2F98  0x021B2F98  arm  ov013
 */

extern int  d_021B60CC[];
extern void func_021B0600(void);
extern void func_021B23C8(void);
extern void func_021B2F98(void);

void func_021B3844(void)
{
    func_021B0600();
    func_021B23C8();
    func_021B2F98();
    d_021B60CC[7] = 0;
    d_021B60CC[2] = 0;
}
