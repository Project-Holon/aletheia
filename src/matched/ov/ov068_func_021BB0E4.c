/*
 * function: OPTION_MENU_AreSettingsEqual
 * address: 0x021BB0E4
 * packet: pkt_ov068_021BB0E4
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int GF_STANDARD_CompareBytes(const u8 *, const u8 *, u32);
int OPTION_MENU_AreSettingsEqual(const u8 *p, const u8 *q)
{
    if (GF_STANDARD_CompareBytes(p, q, 5) == 0) return 1;
    return 0;
}
