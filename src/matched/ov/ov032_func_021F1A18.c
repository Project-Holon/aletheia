/*
 * function: BEACON_VIEW_ShowPowerAnim
 * address: 0x021F1A18
 * packet: pkt_ov032_021F1A18
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BEACON_VIEW_StartPowerAnim 0x021F1A28 thumb ov032
 */

typedef unsigned char u8;
extern void BEACON_VIEW_StartPowerAnim(char *p, int b, u8 c, int *r);
void BEACON_VIEW_ShowPowerAnim(char *p, int b)
{
    BEACON_VIEW_StartPowerAnim(p, b, 2, (int *)(p + 0xa8));
}
