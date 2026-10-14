/*
 * function: POKETRADE_SAVE_PrintGender
 * address: 0x021E1670
 * packet: pkt_ov119_021E1670
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintColor(void *,short,short,int,int,int);
void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,char *p,int mode,int guard) {int v,w,id,color;v=POKE_TOOL_GetPartyValue(a,110,0);w=POKE_TOOL_GetPartyValue(a,173,0);id=POKE_TOOL_GetPartyValue(a,5,0);if(v<=1 && w!=0 && !(guard && id==29) && !(guard && id==32)) {if(mode) {if(v==1)color=0x31a0;else color=0x39e0;}else {if(v==1)color=0xc80;else color=0x14c0;}MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),v+46,(void *)(*(int *)&((struct Obj00001 *)p)->f730));PRINTSYS_PrintColor(b,x,y,*(int *)&((struct Obj00001 *)p)->f730,*(int *)&((struct Obj00001 *)p)->f728,color);}}
