/*
 * function: WF2DMAP_TOUCH_SetTileRecordField
 * address: 0x021C9EF4
 * packet: pkt_ov128_021C9EF4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
typedef unsigned int u32;
void WF2DMAP_TOUCH_SetTileRecordField(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap) { *(u32 *)(p+44+index*4)=value; }
