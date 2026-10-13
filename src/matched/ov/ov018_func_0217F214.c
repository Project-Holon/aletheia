/*
 * function: INTRUDE_SUBDISP_ClearInfoPanel
 * address: 0x0217F214
 * packet: pkt_ov018_0217F214
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
extern void func_02041300(unsigned int, int, int, int, u8, u8, u8);
extern void func_02041B6C(unsigned int);
void INTRUDE_SUBDISP_ClearInfoPanel(void)
{
    func_02041300(6, 0x3001, 0x14, 0x16, 0xc, 2, 0x11);
    func_02041B6C(6);
}
