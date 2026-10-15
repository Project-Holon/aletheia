/*
 * function: WF2DMAP_TOUCH_CreateTileWidgets
 * address: 0x021C9E6C
 * packet: pkt_ov128_021C9E6C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_CreateWindow 0x021C63AC thumb ov128
 *   gWf2dmapTileWindowParams 0x021CA5A2 data a2
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const u8 gWf2dmapTileWindowParams[10][4];
extern void Wf2dmapFriend_CreateWindow(void *,u32 *,u32,u32,u8,u8,u8,u8,u32,u8);
void WF2DMAP_TOUCH_CreateTileWidgets(u8 *p,void *q)
{
    int i;
    p+=0x128;
    for(i=0;i<10;i++)
        Wf2dmapFriend_CreateWindow(q,(u32 *)(p+i*8),1,gWf2dmapTileWindowParams[i][0],gWf2dmapTileWindowParams[i][1],gWf2dmapTileWindowParams[i][2],gWf2dmapTileWindowParams[i][3],10,0,0);
}
