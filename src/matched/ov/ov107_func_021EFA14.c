/*
 * function: MB_COMM_SYS_MainRecruit
 * address: 0x021EFA14
 * packet: pkt_ov107_021EFA14
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 * symbols:
 *   MB_PARENT_SYS_GetState 0x021F0D28 thumb ov107
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MB_PARENT_SYS_AllBootable 0x021F0A28 thumb ov107
 *   MB_PARENT_SYS_StartBoot 0x021F0A64 thumb ov107
 *   MB_PARENT_SYS_Cancel 0x021F0AE4 thumb ov107
 *   MB_UTIL_MSG_ClearWindow 0x021F1898 thumb ov107
 *   MB_UTIL_MSG_SetWindowLayout 0x021F1628 thumb ov107
 *   func_02012FFC 0x02012FFC thumb
 *   MB_UTIL_MSG_PrintStream 0x021F1704 thumb ov107
 *   MB_UTIL_MSG_IsStreamIdle 0x021F1B14 thumb ov107
 *   MB_UTIL_MSG_OpenYesNoTaskMenu 0x021F1930 thumb ov107
 *   MB_UTIL_MSG_OpenYesNoMenu 0x021F19E4 thumb ov107
 *   MB_UTIL_MSG_GetTaskMenuResult 0x021F19C8 thumb ov107
 *   MB_UTIL_MSG_ProcessYesNoMenu 0x021F1A2C thumb ov107
 *   func_02034714 0x02034714 arm
 *   MB_COMM_SYS_UpdateSaveState 0x021EFC1C thumb ov107
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MB_UTIL_MSG_CloseTaskMenu 0x021F19B8 thumb ov107
 *   MB_UTIL_MSG_ClearYesNoMenu 0x021F1A24 thumb ov107
 *   MB_UTIL_MSG_CreateWordSet 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   MB_UTIL_MSG_SetNumberZeroPad 0x021F1918 thumb ov107
 *   MB_UTIL_MSG_DeleteWordSet 0x021F18EC thumb ov107
 *   d_021F6AF8 0x021F6AF8 data a4
 *   d_021F6E08 0x021F6E08 data a4
 */
#include "../include/Obj00072.h"
#include "../include/Obj22278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 MB_PARENT_SYS_GetState(void);
struct Obj;
extern int TOUCHPANEL_HitTrg(const void *);
extern int MB_PARENT_SYS_AllBootable(void);
extern int MB_UTIL_MSG_IsStreamIdle(void *);
extern int MB_UTIL_MSG_GetTaskMenuResult(unsigned char *a);
extern int MB_UTIL_MSG_ProcessYesNoMenu(void *);
extern u32 KEY_GetTrg(void);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MB_PARENT_SYS_StartBoot(void),MB_PARENT_SYS_Cancel(void),MB_UTIL_MSG_ClearWindow(void *),MB_UTIL_MSG_SetWindowLayout(void *,int);
struct Sub0200852CObj;
extern signed char func_02012FFC(void);
extern void MB_UTIL_MSG_PrintStream(void *,int,int);
extern void MB_UTIL_MSG_OpenYesNoTaskMenu(char *p, int kind);
extern void MB_UTIL_MSG_OpenYesNoMenu(void *,int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MB_COMM_SYS_UpdateSaveState(u8 *,int);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MB_UTIL_MSG_CloseTaskMenu(unsigned char *a);
extern void MB_UTIL_MSG_ClearYesNoMenu(u8 *p);
extern void MB_UTIL_MSG_CreateWordSet(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void MB_UTIL_MSG_SetNumberZeroPad(unsigned char *a, int b, int c, int d);
extern void MB_UTIL_MSG_DeleteWordSet(void *);
extern u8 d_021F6AF8[],d_021F6E08[];
void MB_COMM_SYS_MainRecruit(u8 *p)
{
 int a;void *q;
 MB_PARENT_SYS_GetState();
 switch(MB_PARENT_SYS_GetState()){
 case 2:
  if(p[0x26]==0){
   a=TOUCHPANEL_HitTrg(d_021F6AF8);
   if(KEY_GetTrg()==2 || (a==0 && p[0x28]==0)){
    p[0x26]=1;CLACT_SetActorAnimSeq(((struct Obj00072 *)p)->f7C,9);CLACT_SetActorAutoAnim(((struct Obj00072 *)p)->f7C,1);GFL_USE_PlaySeDefaultVolume(1361);
   }else if(MB_PARENT_SYS_AllBootable()){MB_PARENT_SYS_StartBoot();}
  }break;
 case 5:p[0x24]=4;break;
 case 7:MB_PARENT_SYS_Cancel();break;
 case 0:p[0x24]=8;break;
 case 1:case 3:case 4:case 6:default:break;
 }
 switch(p[0x26]){
 case 1:
  MB_UTIL_MSG_ClearWindow(((struct Obj00072 *)p)->f68);CLACT_SetActorAnimSeq(((struct Obj00072 *)p)->f7C,15);
  if(p[0x28]==0){MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,7);MB_UTIL_MSG_PrintStream(((struct Obj00072 *)p)->f68,9,func_02012FFC());}
  else {MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,5);MB_UTIL_MSG_PrintStream(((struct Obj00072 *)p)->f68,42,func_02012FFC());}
  p[0x26]=2;break;
 case 2:
  if(MB_UTIL_MSG_IsStreamIdle(((struct Obj00072 *)p)->f68)==1){
   if(p[0x28]==0)MB_UTIL_MSG_OpenYesNoTaskMenu(((struct Obj00072 *)p)->f68,0);
   else MB_UTIL_MSG_OpenYesNoMenu(((struct Obj00072 *)p)->f68,0);
   p[0x26]=3;
  }break;
 case 3:
  if(p[0x28]==0)a=MB_UTIL_MSG_GetTaskMenuResult(((struct Obj00072 *)p)->f68);
  else a=MB_UTIL_MSG_ProcessYesNoMenu(((struct Obj00072 *)p)->f68);
  if(a==1){
   if(MB_PARENT_SYS_GetState()!=2)func_02034714((const char *)d_021F6E08,0,(const char *)d_021F6E08);
   MB_COMM_SYS_UpdateSaveState(p,4);MB_PARENT_SYS_Cancel();p[0x26]=4;
  }else if(a==2){
   q=GAME_DATA_GetMyStatus(((struct Obj22278 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);
   if(p[0x28]==0)MB_UTIL_MSG_CloseTaskMenu(((struct Obj00072 *)p)->f68);else MB_UTIL_MSG_ClearYesNoMenu(((struct Obj00072 *)p)->f68);
   MB_UTIL_MSG_ClearWindow(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,2);else MB_UTIL_MSG_SetWindowLayout(((struct Obj00072 *)p)->f68,3);
   MB_UTIL_MSG_CreateWordSet(((struct Obj00072 *)p)->f68);MB_UTIL_MSG_SetNumberZeroPad(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   CLACT_SetActorAnimSeq(((struct Obj00072 *)p)->f7C,1);
   if(p[0x28]==0)MB_UTIL_MSG_PrintStream(((struct Obj00072 *)p)->f68,0,func_02012FFC());else MB_UTIL_MSG_PrintStream(((struct Obj00072 *)p)->f68,20,func_02012FFC());
   MB_UTIL_MSG_DeleteWordSet(((struct Obj00072 *)p)->f68);p[0x26]=0;
  }break;
 }
}
