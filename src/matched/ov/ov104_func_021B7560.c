/*
 * function: IRC_RHYTHM_Init
 * address: 0x021B7560
 * packet: pkt_ov104_021B7560
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Preserve the visible seventh heap argument to 021B8030 despite its legacy six-argument declaration.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   IRC_RHYTHM_InitScreen 0x021B78EC thumb ov104
 *   IRC_RHYTHM_InitTextSystem 0x021B7D28 thumb ov104
 *   ICA_ANIME_GetField24 0x02012138 thumb
 *   IRC_RHYTHM_InitMessageWindow 0x021B7DF0 thumb ov104
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   IRC_RHYTHM_InitPulse 0x021B8E90 thumb ov104
 *   IRC_RHYTHM_PrintMessageWithName 0x021B8030 thumb ov104
 *   IRC_RHYTHM_PrintMessage 0x021B7F1C thumb ov104
 *   IRC_RHYTHM_InitCountdown 0x021B80D4 thumb ov104
 *   IRC_RHYTHM_InitTextWindow 0x021B7E58 thumb ov104
 *   IRC_RHYTHM_PrintCenteredMessage 0x021B7F80 thumb ov104
 *   BG_SYS_ChangeScale 0x02041F6C arm
 *   BG_SYS_ChangeCenter 0x02041FB0 arm
 *   IRC_RHYTHM_InitNetSync 0x021B8724 thumb ov104
 *   IRC_RHYTHM_InitRecord 0x021B85D8 thumb ov104
 *   IRC_RHYTHM_InitParticles 0x021B8A88 thumb ov104
 *   IRC_RHYTHM_GetScreenActorUnit 0x021B7974 thumb ov104
 *   IRC_RHYTHM_GetFont 0x021B7DE0 thumb ov104
 *   IRC_RHYTHM_GetPrintQueue 0x021B7DE4 thumb ov104
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   func_020056A0 0x020056A0 thumb
 *   IRC_RHYTHM_ClearBlendTask 0x021B8F08 thumb ov104
 *   IRC_RHYTHM_SetState 0x021B817C thumb ov104
 *   IRC_RHYTHM_StateIntro 0x021B8198 thumb ov104
 */
#include "../include/Obj07986.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Proc;
struct Ctx;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Proc *,u32,u32);
extern void MI_CpuFill8(void *,int,int);
extern void IRC_RHYTHM_InitScreen(u8 *,int);
extern void IRC_RHYTHM_InitTextSystem(unsigned *p, int mode, u16 heap);
extern u32 ICA_ANIME_GetField24(const struct Ctx *);
extern void IRC_RHYTHM_InitMessageWindow(u8 *,u32,u32,u8,u8,u8,u8,u16);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void IRC_RHYTHM_InitPulse(int *p, int a1);
extern void IRC_RHYTHM_PrintMessageWithName(u8 *,void *,int,u8 *,s16,s16,u16);
extern void IRC_RHYTHM_PrintMessage(u8 *,void *,int,int,s16);
extern void IRC_RHYTHM_InitCountdown(int *p, u8 *q, int a2);
extern void IRC_RHYTHM_InitTextWindow(u8 *,u32,u32,u8,u8,u8,u8,u16,u8,u16);
extern void IRC_RHYTHM_PrintCenteredMessage(u8 *,void *,int);
extern void BG_SYS_ChangeScale(u32 which, u32 op, u32 value);
extern void BG_SYS_ChangeCenter(u32,u32,u16);
extern void IRC_RHYTHM_InitNetSync(u8 *p, int a);
extern void IRC_RHYTHM_InitRecord(void *p);
extern void IRC_RHYTHM_InitParticles(u8 *,void *,int,int,int);
extern u32 IRC_RHYTHM_GetScreenActorUnit(u8 *);
extern int IRC_RHYTHM_GetFont(void *);
extern int IRC_RHYTHM_GetPrintQueue(void *);
extern void *IRC_APPBAR_Create(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *,int);
extern void G2x_SetBlendBrightness_(u32,int,int);
extern void *func_020056A0(u32,u32,u32);
extern void IRC_RHYTHM_ClearBlendTask(void *,u8 *);
extern void IRC_RHYTHM_SetState(char *p, u32 v);
extern void IRC_RHYTHM_StateIntro(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
int IRC_RHYTHM_Init(struct Proc *obj,void *state,u8 *context) {
 u8 *p; u32 bank; int tag; int font;
 GFL_HEAP_CreateChildHeap(1,0x38,0x20000);
 p=PROCSYS_AllocProcWork(obj,0x8b4,0x38);
 MI_CpuFill8(p,0,0x8b4);
 CTX(p)=context;
 IRC_RHYTHM_InitScreen(p,0x38);
 IRC_RHYTHM_InitTextSystem((unsigned int *)(p+0xbc),0,(u32)0x38);
 if(*(void **)CTX(p)) ICA_ANIME_GetField24(*(struct Ctx **)CTX(p));
 IRC_RHYTHM_InitMessageWindow(p+0xcc,5,1,18,30,5,8,0x38);
 BMP_MENUWORK_DrawWindow(((struct Obj07986 *)p)->fCC,0,(u16)(((struct Obj07986 *)p)->f0),6);
 IRC_RHYTHM_InitPulse((int *)(p+0x7cc),0x38);
 if(*(void **)CTX(p)) IRC_RHYTHM_PrintMessageWithName(p+0xcc,p+0xbc,0,*(u8 **)(CTX(p)+8),0,0,0x38);
 else IRC_RHYTHM_PrintMessage(p+0xcc,p+0xbc,0,0,0);
 IRC_RHYTHM_InitCountdown((int *)(p+0x7b0),p,0x38);
 IRC_RHYTHM_InitTextWindow(p+0x7dc,7,6,3,20,5,8,1,1,0x38);
 IRC_RHYTHM_PrintCenteredMessage(p+0x7dc,p+0xbc,7);
 BG_SYS_ChangeScale(7,3,0x1000);
 BG_SYS_ChangeScale(7,6,0x1000);
 BG_SYS_ChangeCenter(7,9,0x80);
 BG_SYS_ChangeCenter(7,12,0x28);
 IRC_RHYTHM_InitTextWindow(p+0x7f0,2,8,10,16,2,13,0,0,0x38);
 IRC_RHYTHM_InitNetSync(p+0xe0,(int)(*(void **)(CTX(p)+4)));
 IRC_RHYTHM_InitRecord(p+0x814);
 IRC_RHYTHM_InitParticles(p+0x278,p,1,0,0);
 bank=IRC_RHYTHM_GetScreenActorUnit(p);
 tag=IRC_RHYTHM_GetFont(p+0xbc);
 font=IRC_RHYTHM_GetPrintQueue(p+0xbc);
 ((struct Obj07986 *)p)->f7AC=IRC_APPBAR_Create(2,bank,0,14,13,2,tag,font,0x38);
 COMPATIBLE_IRC_SYS_SetOwnValue(*(int **)(CTX(p)+4),1);
 G2x_SetBlendBrightness_(0x04000050,0x22,-8);
 ((struct Obj07986 *)p)->f8A4=func_020056A0((u32)IRC_RHYTHM_ClearBlendTask,(u32)p,0);
 IRC_RHYTHM_SetState((char *)p,(u32)IRC_RHYTHM_StateIntro);
 return 1;
}
