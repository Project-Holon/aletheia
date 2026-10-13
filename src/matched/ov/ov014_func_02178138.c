/*
 * function: WIH_ChangeSysState
 * address: 0x02178138
 * packet: pkt_ov014_02178138
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 */
typedef unsigned char u8;
extern u8 *gWihWork;
void WIH_ChangeSysState(int state)
{
    *(int *)(gWihWork + 0x1e70) = state;
}
