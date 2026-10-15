/*
 * function: IRCBATTLEMATCH_InitScreen
 * address: 0x021BA780
 * packet: pkt_ov100_021BA780
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: original entry R0 is preserved at 0201DD68; that callee's full
 *   matched body ignores it. 021BA028 likewise ignores the supplied context,
 *   but the original explicitly supplies it, so the caller retains it.
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WORDSET_Create 0x0201EC74 thumb
 *   IRCBATTLEMATCH_InitWindowSystem 0x021BA624 thumb ov100
 *   IRCBATTLEMATCH_SetupDisplay 0x021BA028 thumb ov100
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   FADE_Start 0x0204E720 arm
 *   IRCBATTLEMATCH_PrintWaitingMessage 0x021BA668 thumb ov100
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   IRCBATTLEMATCH_VBlankTask 0x021BA1C8 thumb ov100
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   IRCBATTLEMATCH_LoadActorResources 0x021B96EC thumb ov100
 *   IRCBATTLEMATCH_CreateActor 0x021B974C thumb ov100
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   IRCBATTLEMATCH_SetStep 0x021B95B8 thumb ov100
 *   IRCBATTLEMATCH_StepWaitFadeIn 0x021BAA9C thumb ov100
 *   gClActorInitParam 0x020A1448 data a4
 *   gIrcBattleMatchVramBanks 0x021BB6F0 data a4
 */
#include "../include/Obj00178.h"
#include "../include/Obj22083.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 gClActorInitParam[],gIrcBattleMatchVramBanks[];
struct Bank;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
struct Cfg;
extern void GF_FONT_SetDefaultTextColor(void);
extern void IRCBATTLEMATCH_InitWindowSystem(unsigned a);
extern void IRCBATTLEMATCH_SetupDisplay(char *);
extern void IRCBATTLEMATCH_PrintWaitingMessage(int a);
extern void IRCBATTLEMATCH_VBlankTask(void);
extern void IRCBATTLEMATCH_StepWaitFadeIn(int a);
extern void IRCBATTLEMATCH_LoadActorResources(char *);
extern void IRCBATTLEMATCH_CreateActor(int,int,int,int,int);
extern void IRCBATTLEMATCH_SetStep(u8 *p, u32 v);
struct WordSet;
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern int func_020056A0(u32,u32,u32);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void FADE_Start(u32,int,int,int);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void MI_CpuCopy8(const void *,void *,u32);
extern u32 func_020307B0(void *p);
void IRCBATTLEMATCH_InitScreen(char *p) {
 void *owner;
 void *raw;
 void *resource;
 int i;
 GF_FONT_SetDefaultTextColor();
 ((struct Obj00178 *)p)->f28C=(int)WORDSET_Create(11,200,((struct Obj00178 *)p)->f278);
 IRCBATTLEMATCH_InitWindowSystem((unsigned int)p);IRCBATTLEMATCH_SetupDisplay(p);
 ((struct Obj00178 *)p)->f298=(int)STRBUF_Create(200,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f294=(int)STRBUF_Create(200,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f290=(int)GF_FONT_Create(23,0,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f288=(int)func_02045B38(0,2,46,((struct Obj00178 *)p)->f278);
 owner=func_020490F4(28,((struct Obj00178 *)p)->f278);
 func_02049B68(owner,1,0,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2FC=(int)func_02049740(owner,6,0,0,0,((struct Obj00178 *)p)->f278);
 if(((struct Obj00178 *)p)->f24C!=5) ARC_UTIL_UploadBgPaletteAddFromHandle(owner,13,1,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);
 else {ARC_UTIL_UploadBgPaletteAddFromHandle(owner,13,0,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);ARC_UTIL_UploadBgPaletteAddFromHandle(owner,14,1,0,(u16)(((struct Obj00178 *)p)->f2FC),0,0,((struct Obj00178 *)p)->f278);}
 ARC_TOOL_DeleteHandle(owner);
 owner=func_020490F4(29,((struct Obj00178 *)p)->f278);
 func_02049B68(owner,1,4,0,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f308=(int)func_02049740(owner,4,4,0,0,((struct Obj00178 *)p)->f278);
 ARC_UTIL_UploadBgPaletteAddFromHandle(owner,9,4,0,(u16)(((struct Obj00178 *)p)->f308),0,0,((struct Obj00178 *)p)->f278);ARC_TOOL_DeleteHandle(owner);
 ((struct Obj00178 *)p)->f304=(int)BMP_MENUWORK_LoadFrameGfx((void *)5,14,0,((struct Obj00178 *)p)->f278);
 FADE_Start(3,16,0,2);IRCBATTLEMATCH_PrintWaitingMessage((int)p);
 CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)gIrcBattleMatchVramBanks,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2B4=(int)CLACT_CreateUnit(40,0,((struct Obj00178 *)p)->f278);
 ((struct Obj00178 *)p)->f2B0=func_020056A0((u32)IRCBATTLEMATCH_VBlankTask,(u32)p,0);
 ((struct Obj00178 *)p)->fCB8=PRINTSYS_QUE_Create((void *)(((struct Obj00178 *)p)->f278));
 ((struct Obj00178 *)p)->fCC4=(int)APP_TASKMENU_RES_Create(6,9,((struct Obj00178 *)p)->f290,((struct Obj00178 *)p)->fCB8,((struct Obj00178 *)p)->f278);
 IRCBATTLEMATCH_LoadActorResources(p);
 if(((struct Obj00178 *)p)->f24C!=5) {
  IRCBATTLEMATCH_CreateActor((int)p,57,154,2,10);IRCBATTLEMATCH_CreateActor((int)p,128,113,4,2);IRCBATTLEMATCH_CreateActor((int)p,200,38,0,11);IRCBATTLEMATCH_CreateActor((int)p,128,77,5,3);
 } else {
  IRCBATTLEMATCH_CreateActor((int)p,57,154,0,4);IRCBATTLEMATCH_CreateActor((int)p,198,154,1,5);IRCBATTLEMATCH_CreateActor((int)p,200,38,2,6);IRCBATTLEMATCH_CreateActor((int)p,55,38,3,7);IRCBATTLEMATCH_CreateActor((int)p,152,146,6,0);IRCBATTLEMATCH_CreateActor((int)p,103,146,7,1);IRCBATTLEMATCH_CreateActor((int)p,152,46,4,0);IRCBATTLEMATCH_CreateActor((int)p,103,46,5,1);
 }
 BG_SYS_SetMainVisiblePlanes((int)19);BG_SYS_SetSubVisiblePlanes((int)23);
 ((struct Obj00178 *)p)->f242=((struct Obj00178 *)p)->f278;
 owner=func_020490F4(28,((struct Obj00178 *)p)->f242);
 raw=ARC_UTIL_LoadPaletteBlockFromHandle(owner,2,(u32)(&resource),((struct Obj00178 *)p)->f242);
 MI_CpuCopy8(((struct Obj22083 *)resource)->fC,p,0x120);
 for(i=0;i<9;i++) MI_CpuCopy8(p+(8-i)*32,p+(i+9)*32,32);
 func_020307B0(raw);ARC_TOOL_DeleteHandle(owner);IRCBATTLEMATCH_SetStep((u8 *)p,(u32)IRCBATTLEMATCH_StepWaitFadeIn);
}
