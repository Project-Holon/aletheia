/*
 * function: IRC_RESULT_Init
 * address: 0x021B7560
 * packet: pkt_ov105_021B7560
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: Caller-only tu --suggest-split confirmed no viable partition
 * with unresolved80D8; parent-cleared leaf now verified in its own shard.
 * prototype: 3159C and 78D4 forward full-word allocation/accessor r0;
 * callers read it. Explicit third 3064C and sixth 7F78 inputs retained.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ICA_ANIME_GetField24 0x02012138 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BG_SYS_SetScrollY 0x02041F6C arm
 *   BG_SYS_SetAffine 0x02041FB0 arm
 *   IRC_RESULT_InitScreen 0x021B784C thumb ov105
 *   IRC_RESULT_InitTextSystem 0x021B7C20 thumb ov105
 *   IRC_RESULT_InitMessageWindow 0x021B7CB0 thumb ov105
 *   IRC_RESULT_InitTextWindow 0x021B7D20 thumb ov105
 *   IRC_RESULT_PrintCenteredMessage 0x021B7E48 thumb ov105
 *   IRC_RESULT_InitScoreDisplay 0x021B8348 thumb ov105
 *   COMPATIBLE_IRC_SYS_BuildProfile 0x021B658C thumb ov101
 *   IRC_RESULT_PrintMessageWithNames 0x021B7F78 thumb ov105
 *   IRC_RESULT_GetScreenActorUnit 0x021B78D4 thumb ov105
 *   IRC_RESULT_GetFont 0x021B7CA0 thumb ov105
 *   IRC_RESULT_GetPrintQueue 0x021B7CA4 thumb ov105
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   IRC_APPBAR_SetEnabled 0x021B728C thumb ov101
 *   IRC_RESULT_InitRankFade 0x021B84B4 thumb ov105
 *   IRC_RESULT_GetRewardQuantity 0x021B8840 thumb ov105
 *   IRC_RESULT_SetState 0x021B80BC thumb ov105
 *   IRC_RESULT_StateStart 0x021B80D8 thumb ov105
 */
#include "../include/Obj03234.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4; u8 high:4; u8 tail[32]; } Data;
typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display;
struct Task;
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
struct Ctx;
extern u32 ICA_ANIME_GetField24(const struct Ctx *p);
struct Rec;
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BG_SYS_SetScrollY(u32 which, u32 op, u32 value);
extern void BG_SYS_SetAffine(u32,u32,u16);
extern void IRC_RESULT_InitScreen(u8 *,int);
extern void IRC_RESULT_InitTextSystem(u32 *p, int flag, int heap);
extern void IRC_RESULT_InitMessageWindow(struct Rec *p, u32 a, u32 b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern void IRC_RESULT_InitTextWindow(u8 *,u32,u32,u8,u8,u8,u8,u16,u8,u16);
extern void IRC_RESULT_PrintCenteredMessage(u8 *,void *,int);
extern void IRC_RESULT_InitScoreDisplay(Display *,void *,int);
extern void COMPATIBLE_IRC_SYS_BuildProfile(void *,Data *);
extern void IRC_RESULT_PrintMessageWithNames(u8 *,void *,int,u8 *,u8 *,int);
extern u32 IRC_RESULT_GetScreenActorUnit(u8 *);
extern int IRC_RESULT_GetFont(void *),IRC_RESULT_GetPrintQueue(void *);
extern void *IRC_APPBAR_Create(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void IRC_APPBAR_SetEnabled(int,int);
extern void IRC_RESULT_InitRankFade(u8 *,int,int,int);
extern unsigned int IRC_RESULT_GetRewardQuantity(unsigned int x, int y);
extern void IRC_RESULT_SetState(unsigned char *p, unsigned int v);
extern void IRC_RESULT_StateStart(u8 *p);
#define CTX (*(u8 **)(p+0x1a4))
int IRC_RESULT_Init(struct Task *a,void *b,u8 *context)
{
    Data first,second;
    u8 *p;
    u32 handle;
    int tag,font;
    GFL_HEAP_CreateChildHeap(1,60,0x20000);
    p=PROCSYS_AllocProcWork((struct Obj0203159C *)a,0x1a8,60);
    MI_CpuFill8(p,0,0x1a8);
    *(u8 * *)&((struct Obj03234 *)p)->f1A4=context;
    IRC_RESULT_InitScreen(p,60);
    IRC_RESULT_InitTextSystem((u32 *)(p+0xb0),0,60);
    if(*(void **)CTX) ICA_ANIME_GetField24(*(void **)CTX);
    IRC_RESULT_InitMessageWindow((struct Rec *)(p+0xc0),5,1,(u32)18,30,5,5,60);
    BMP_MENUWORK_DrawWindow(((struct Obj03234 *)p)->fC0,0,(u16)(((struct Obj03234 *)p)->f0),6);
    IRC_RESULT_InitTextWindow(p+0xd4,7,6,3,20,5,8,1,1,60);
    IRC_RESULT_PrintCenteredMessage(p+0xd4,p+0xb0,1);
    BG_SYS_SetScrollY(7,3,4096);
    BG_SYS_SetScrollY(7,6,4096);
    BG_SYS_SetAffine(7,9,128);
    BG_SYS_SetAffine(7,12,40);
    IRC_RESULT_InitScoreDisplay((Display *)(p+0xe8),p,CTX[12]);
    if(*(void **)CTX) {
        COMPATIBLE_IRC_SYS_BuildProfile(*(void **)CTX,&first);
        IRC_RESULT_PrintMessageWithNames(p+0xc0,p+0xb0,0,(u8 *)&first,*(u8 **)(CTX+8),60);
    }
    handle=IRC_RESULT_GetScreenActorUnit(p);
    tag=IRC_RESULT_GetFont(p+0xb0);
    font=IRC_RESULT_GetPrintQueue(p+0xb0);
    ((struct Obj03234 *)p)->f188=IRC_APPBAR_Create(2,handle,0,13,13,2,tag,font,60);
    IRC_APPBAR_SetEnabled(*(int *)&((struct Obj03234 *)p)->f188,0);
    IRC_RESULT_InitRankFade(p+0x128,3,CTX[12],60);
    if(*(void **)CTX) {
        COMPATIBLE_IRC_SYS_BuildProfile(*(void **)CTX,&second);
        if(second.low && ((Data *)*(void **)(CTX+8))->low) ((struct Obj03234 *)p)->f19C=1;
        else ((struct Obj03234 *)p)->f19C=0;
        ((struct Obj03234 *)p)->f1A0=IRC_RESULT_GetRewardQuantity(CTX[12],((struct Obj03234 *)p)->f19C);
    }
    IRC_RESULT_SetState(p,(unsigned int)IRC_RESULT_StateStart);
    return 1;
}
