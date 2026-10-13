/*
 * function: func_021E194C
 * address: 0x021E194C
 * packet: pkt_ov119_021E194C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 */
#include "../include/Obj00001.h"
typedef signed short s16;
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
void func_021E194C(int a,int b,int x,int y,char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),44,(void *)(*(int *)&((struct Obj00001 *)p)->f730));
    PRINTSYS_Print(func_02045770((struct Descriptor *)b),x,y,((struct Obj00001 *)p)->f730,((struct Obj00001 *)p)->f728);
}
