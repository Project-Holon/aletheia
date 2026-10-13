/*
 * function: func_021FC6EC
 * address: 0x021FC6EC
 * packet: pkt_ov132_021FC6EC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GAMESYSTEM_SetFieldMapState 0x02012124 thumb
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 * 0203D1B4's forwarding matched void declaration loses its live result.
 * 0203D7BC retains the original caller's unused zero argument.
 */
#include "../include/Obj08173.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry; struct Ctx;
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_Exit(int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern void GFL_NET_SetLoginOption(u8 a0);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_IsParentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(char *p, int id);
int func_021FC6EC(int *state,u8 *p)
{
 switch(*state) {
 case 0:
  if(GFL_NET_GetNegotiationNum()<=1) {GFL_NET_Exit(0);return 1;}
  if(((struct Obj08173 *)p)->fC==1) GFL_NET_COMMAND_DeleteCommandTable(0x1100);
  if(((struct Obj08173 *)p)->f8==1) {GFL_NET_SetLoginOption(0);func_021FCDEC((int)p,0x41);*state=1;}
  else *state=2;
  break;
 case 1:
  if(func_021FCE00((char *)p,0x41)==1) *state=2;
  if(GFL_NET_GetNegotiationNum()<=1 || func_0200FB24()!=0) *state=10;
  break;
 case 2:
  if(((struct Obj08173 *)p)->f8==0) {GFL_NET_Exit(0);return 1;}
  if(GFL_NET_IsParentAid()==0) {
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),1,0,0)==1) return 1;
  } else if(GFL_NET_GetNegotiationNum()<=1) {GFL_NET_Exit(0);return 1;}
  if(func_0200FB24()!=0) *state=10;
  break;
 case 10:
  if(func_0200FB24()!=0) GAMESYSTEM_SetFieldMapState(*(struct Ctx * *)&((struct Obj08173 *)p)->f54,1);
  GFL_NET_Exit(0);return 1;
 }
 return 0;
}
