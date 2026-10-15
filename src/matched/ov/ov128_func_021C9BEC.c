/*
 * function: WF2DMAP_TOUCH_SetValue
 * address: 0x021C9BEC
 * packet: pkt_ov128_021C9BEC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned short u16;
void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int a5) { if(flag==0) *p=value; }
