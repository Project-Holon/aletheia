/*
 * function: WF2DMAP_OBJCMD_Update
 * address: 0x021C4CB4
 * packet: pkt_ov127_021C4CB4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_OBJ_GetSlot 0x021C49A4 thumb ov127
 *   WF2DMAP_OBJCMD_Restart 0x021C5334 thumb ov127
 *   sWf2dmapObjCmdTable 0x021C604C data a4
 */
#include "../include/Obj00535.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJ_GetSlot(u8 *,unsigned);
extern void WF2DMAP_OBJCMD_Restart(char *);
extern int (*sWf2dmapObjCmdTable)(u8 *);
void WF2DMAP_OBJCMD_Update(u8 *p)
{
 int i=WF2DMAP_OBJ_GetSlot(p,5); int r=(*(int (**)(u8 *))((unsigned)&sWf2dmapObjCmdTable+i*4))(p);
 (((struct Obj00535 *)p)->f16)++;
 if(r==1) {WF2DMAP_OBJCMD_Restart((char *)p); ((struct Obj00535 *)p)->f16=0;}
}
