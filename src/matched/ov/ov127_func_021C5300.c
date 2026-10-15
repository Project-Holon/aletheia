/*
 * function: WF2DMAP_OBJCMD_AdvanceTimer
 * address: 0x021C5300
 * packet: pkt_ov127_021C5300
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJ_SetSlot 0x021C4A00 thumb ov127
 */
typedef unsigned char u8;
extern int WF2DMAP_OBJ_GetSlot(u8 *,unsigned);
extern void WF2DMAP_OBJ_SetSlot(void *,int,int);
int WF2DMAP_OBJCMD_AdvanceTimer(u8 *p)
{
 int a=WF2DMAP_OBJ_GetSlot(p,8), b=WF2DMAP_OBJ_GetSlot(p,9);
 if(a<b) { WF2DMAP_OBJ_SetSlot(p,8,a+1); if(a+1<b) return 0; }
 return 1;
}
