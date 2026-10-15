/*
 * function: Wf2dmapFriend_DrawEntryPageTransfer
 * address: 0x021C899C
 * packet: pkt_ov128_021C899C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_DrawEntryPage 0x021C8904 thumb ov128
 *   WF2DMAP_TOUCH_TransferScreen 0x021CA4B4 thumb ov128
 */
#include "../include/Obj05381.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void Wf2dmapFriend_DrawEntryPage(char *,char *,void *,void *,int,char *,int,u16);
extern void WF2DMAP_TOUCH_TransferScreen(char *);
void Wf2dmapFriend_DrawEntryPageTransfer(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {Wf2dmapFriend_DrawEntryPage(p,q,r,s,t,table,page,heap);WF2DMAP_TOUCH_TransferScreen(**(char ** *)&((struct Obj05381 *)p)->f8);}
