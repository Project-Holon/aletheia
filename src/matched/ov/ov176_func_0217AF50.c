/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_CreateText
 * address: 0x0217AF50
 * packet: pkt_ov176_0217AF50
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two bytes alignment padding at 0x0217AF9A.
 * symbols:
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021E8568 0x021E8568 thumb ov177
 */
#include "../include/Obj02888.h"
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *func_021E8568(unsigned,unsigned,unsigned,unsigned,void *,void *,unsigned);
void BATTLE_CHAMPIONSHIP_FLOW_CreateText(char *p)
{
    ((struct Obj02888 *)p)->fC=GF_FONT_Create(0x17,0,0,0,((struct Obj02888 *)p)->f0);
    ((struct Obj02888 *)p)->f10=func_02045B38(0,2,4,((struct Obj02888 *)p)->f0);
    ((struct Obj02888 *)p)->f14=(void *)PRINTSYS_QUE_Create((void *)(((struct Obj02888 *)p)->f0));
    ((struct Obj02888 *)p)->f8=func_021E8568(0,15,14,10,((struct Obj02888 *)p)->f14,((struct Obj02888 *)p)->fC,((struct Obj02888 *)p)->f0);
}
