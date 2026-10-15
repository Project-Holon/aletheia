/*
 * file:     demo3d_data.c
 * unit:     yes
 * function: DEMO3D_DATA_Create, DEMO3D_DATA_Delete, DEMO3D_DATA_BuildTable, DEMO3D_DATA_GetPair, DEMO3D_DATA_GetAnimId, DEMO3D_DATA_GetAnimCount, DEMO3D_DATA_GetTextureSize, DEMO3D_DATA_GetAnimIndex, DEMO3D_DATA_GetRecordField, DEMO3D_DATA_CreateCapture, DEMO3D_DATA_DeleteCapture, DEMO3D_DATA_CreateTask, DEMO3D_DATA_DeleteTask, DEMO3D_DATA_ApplyCapture, DEMO3D_DATA_FinishTask, DEMO3D_DATA_StartCapture, DEMO3D_DATA_PlaySe, DEMO3D_DATA_StopSe, DEMO3D_DATA_FadeSeVolume, DEMO3D_DATA_FadeSeSlotParam1, DEMO3D_DATA_FadeSeSlotParam2, DEMO3D_DATA_CreateSeFade, DEMO3D_DATA_UpdateSeFade, DEMO3D_DATA_ApplySeFade, DEMO3D_DATA_PlayBgm, DEMO3D_DATA_StopBgm, DEMO3D_DATA_TaskFadeOutBgm, DEMO3D_DATA_TaskPlayBgm, DEMO3D_DATA_CreateBgmFade, DEMO3D_DATA_BgmFadeMain, DEMO3D_DATA_TaskFadeBrightness, DEMO3D_DATA_CreateBrightnessFade, DEMO3D_DATA_BrightnessFadeMain, DEMO3D_DATA_TaskBrightnessSeq, DEMO3D_DATA_CreateBrightnessSeq, DEMO3D_DATA_BrightnessSeqMain, DEMO3D_DATA_TaskSetLightSlot, DEMO3D_DATA_TaskSetLightVector, DEMO3D_DATA_TaskShowMessage, DEMO3D_DATA_CreateMessage, DEMO3D_DATA_MessageMain, DEMO3D_DATA_CreateMessageWindow, DEMO3D_DATA_DeleteMessageWindow, DEMO3D_DATA_TaskFade, DEMO3D_DATA_CreateFade, DEMO3D_DATA_FadeMain, DEMO3D_DATA_CreateFadeWork, DEMO3D_DATA_DeleteFadeWork, DEMO3D_DATA_TaskCreateCapture, DEMO3D_DATA_TaskDeleteCapture, DEMO3D_DATA_IsCaptureDone
 * address:  0x021BE7F0
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from demo3d_graphic.c, demo3d_data.c, demo3d_cmdsys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   FX_Div 0x0207C768 arm
 *   d_021C3CF0 0x021C3CF0 data a1
 *   d_021C0348 0x021C0348 data a4
 *   d_021C1868 0x021C1868 data a4
 *   d_021C1860  0x021C1860  data
 *   DEMO3D_ENGINE_ClampAnimeId  0x021BE79C  thumb  ov203
 *   d_021C1864  0x021C1864  data
 *   d_021C3B98 0x021C3B98 data a4
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   func_02080C54 0x02080C54 arm
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   func_0208068C 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   DEMO3D_DATA_IsCaptureDone 0x021BF7AC thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   DEMO3D_GRAPHIC_SetLightSlot 0x021BDF74 thumb ov203
 *   DEMO3D_GRAPHIC_SetLightVector 0x021BDF88 thumb ov203
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENUWORK_DrawWindowEx 0x0201F79C thumb
 *   sub_02045C04 0x02045C04 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENUWORK_DeleteHalf 0x0201F614 thumb
 *   GAME_VERSION_Code 0x0209DF08 data a1
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   func_02049990 0x02049990 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02049658 0x02049658 arm
 *   memset 0x02082BCC arm
 *   DEMO3D_DATA_CreateCapture 0x021BE9B8 thumb
 *   DEMO3D_DATA_DeleteCapture 0x021BE9E8 thumb
 *   DEMO3D_DATA_GetRecordField 0x021BE9A4 thumb ov203
 *   DEMO3D_DATA_GetAnimIndex 0x021BE990 thumb ov203
 *   DEMO3D_ENGINE_GetAnimeId 0x021BE7A8 thumb ov203
 */
#include "../../matched/include/Obj14588.h"
#include "../../matched/include/Obj25319.h"
#include "../../matched/include/Obj14590.h"
#include "../../matched/include/Obj08376.h"
#include "../../matched/include/Obj08377.h"
#include "../../matched/include/Obj25320.h"
#include "../../matched/include/Obj10863.h"
#include "../../matched/include/Obj03917.h"
#include "../../matched/include/Obj01291.h"
#include "../../matched/include/Obj25324.h"
#include "../../matched/include/Obj25327.h"
#include "../../matched/include/Obj14596.h"
#include "../../matched/include/Obj14597.h"
#include "../../matched/include/Obj14599.h"
#include "../../matched/include/Obj25328.h"
#include "demo3d_graphic_shared_types.h"
#include "demo3d_engine_shared_types.h"
#include "demo3d_data_shared_types.h"

struct Owner;

struct TcblNode;

typedef signed char    s8;

typedef struct Entry { int x; unsigned short id, pad; int flag; } Entry;

typedef struct Pair { const unsigned short *ids; unsigned count; } Pair;

typedef struct Group { const Pair *pairs; unsigned count; } Group;

typedef struct Selector { const Group *groups; unsigned short count, selector; } Selector;

typedef struct Row { const Selector *selectors; unsigned words[4]; } Row;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} bf_021BE920;

typedef struct Flags { unsigned short doubled:1; unsigned short rest:15; } Flags;

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);

extern void *func_020056A0(unsigned, unsigned, unsigned);

extern void func_02030EAC(struct Node *n);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 func_020307B0(void *p);

extern void BG_SYS_FreeSlot(unsigned char);

extern u32 DEMO3D_ENGINE_ClampAnimeId(u32 id);

u32 DEMO3D_ENGINE_GetAnimeId(u32 id);

void *DEMO3D_DATA_Create(unsigned heap);

void DEMO3D_DATA_Delete(char *a);

void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type);

void * DEMO3D_DATA_GetPair(char *p,u8 *q);

u32 DEMO3D_DATA_GetAnimId(u32 a);

int DEMO3D_DATA_GetAnimCount(void *a);

void DEMO3D_DATA_GetTextureSize(void *ctx, int mode, unsigned char *width, unsigned char *height);

u32 DEMO3D_DATA_GetAnimIndex(u32 id);

extern const char d_021C3CF0[];

extern unsigned d_021C0348[];

extern const Row d_021C1868[];

extern u8 d_021C1860[];

void *DEMO3D_DATA_Create(unsigned heap)
{
    char *ctx;
    Entry *entries;
    char *extra;
    int i;
    ctx = func_02030734(heap, 16, 1, d_021C3CF0, 0xab);
    entries = func_02030734(heap, 72, 1, d_021C3CF0, 0xac);
    extra = func_02030734(heap, 16, 1, d_021C3CF0, 0xad);
    for (i = 0; i < 6; i++) {
        entries[i].x = 160;
        entries[i].flag = 0;
    }
    ((struct Obj25319 *)extra)->f8 = d_021C0348;
    *(Entry * *)&((struct Obj14588 *)ctx)->f0 = entries;
    *(char * *)&((struct Obj14588 *)ctx)->f8 = extra;
    return ctx;
}

void DEMO3D_DATA_Delete(char *a)
{
    func_020307B0((void *)((struct Obj14590 *)a)->f8);
    func_020307B0((void *)((struct Obj14590 *)a)->f0);
    func_020307B0(a);
}

void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type)
{
    Entry *entries = *(Entry * *)&((struct Obj08376 *)ctx)->f0;
    char *extra = *(char * *)&((struct Obj08376 *)ctx)->f8;
    unsigned choice = 0;
    const Group *group;
    int i;
    const Pair *pair;
    group = DEMO3D_DATA_GetPair((char *)(&d_021C1868[*(unsigned *)config].selectors[type]), (u8 *)config);
    if (group->count > 1) choice = *(const unsigned char *)&((struct Obj08377 *)config)->f9;
    if (choice >= group->count) choice = 0;
    pair = &group->pairs[choice];
    ((struct Obj08376 *)ctx)->f4 = pair->count;
    for (i = 0; i < 6; i++) {
        if (i < pair->count) entries[i].id = pair->ids[i];
        else entries[i].id = 0;
    }
    ((struct Obj08376 *)ctx)->fC = 1;
    ((struct Obj25320 *)extra)->fC = pair->count - 1;
}

void * DEMO3D_DATA_GetPair(char *p,u8 *q) { int x=0;switch(((struct Obj10863 *)p)->f6){case 1:x=q[10];break;case 2:x=q[8];break;case 3:x=q[13];break;}if(x>=((struct Obj10863 *)p)->f4)x=0;return (void *)(((struct Obj10863 *)p)->f0+x*8); }

/*
 * The width-1 bitfield must sit at bit 0 (`b0:1`), not bit 15: the original
 * extracts with the equal shift pair `lsls #0x1f / lsrs #0x1f`, so it is the
 * low bit of the halfword at +6 that is shifted by 0x1000.
 * Addresses are Black-image addresses.
 */
u32 DEMO3D_DATA_GetAnimId(u32 a)
{
    bf_021BE920 *p = (bf_021BE920 *)(DEMO3D_ENGINE_GetAnimeId(a) + 6);

    return 0x1000 >> p->b0;
}

int DEMO3D_DATA_GetAnimCount(void *a)
{
    unsigned int v = *(unsigned short *)(DEMO3D_ENGINE_GetAnimeId((u32)a) + 6);
    return (v << 30) >> 31;
}

void DEMO3D_DATA_GetTextureSize(void *ctx, int mode, unsigned char *width, unsigned char *height)
{
    unsigned char *record = (unsigned char *)DEMO3D_ENGINE_GetAnimeId((u32)ctx);
    if (mode == 0) {
        *width = record[0x4e];
        *height = record[0x4f] * (((Flags *)(record + 6))->doubled + 1);
    } else {
        *width = record[0x50];
        *height = record[0x51] * (((Flags *)(record + 6))->doubled + 1);
    }
}

/*
 * closed: dropping the contested ov203 token lets the function's own region
 * pick the object; the +0010 ABS32 resolves as sole-ref/data and the file is
 * EXACT.  See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 * Addresses are Black-image addresses.
 */
u32 DEMO3D_DATA_GetAnimIndex(u32 id)
{
    return *(u32 *)(d_021C1860 + DEMO3D_ENGINE_ClampAnimeId(id) * 0x14);
}

struct CaptureConfig;

struct S02030FB4;

typedef enum {GX_CAPTURE_SIZE_128x128=0,GX_CAPTURE_SIZE_256x64=1,GX_CAPTURE_SIZE_256x128=2,GX_CAPTURE_SIZE_256x192=3} GXCaptureSize;

typedef enum {GX_CAPTURE_MODE_A=0,GX_CAPTURE_MODE_B=1,GX_CAPTURE_MODE_AB=2} GXCaptureMode;

typedef enum {GX_CAPTURE_SRCA_2D3D=0,GX_CAPTURE_SRCA_3D=1} GXCaptureSrcA;

typedef enum {GX_CAPTURE_SRCB_VRAM_0x00000=0,GX_CAPTURE_SRCB_MRAM=1,GX_CAPTURE_SRCB_VRAM_0x08000=2,GX_CAPTURE_SRCB_VRAM_0x10000=4,GX_CAPTURE_SRCB_VRAM_0x18000=6} GXCaptureSrcB;

typedef enum {GX_CAPTURE_DEST_VRAM_A_0x00000=0,GX_CAPTURE_DEST_VRAM_D_0x18000=15} GXCaptureDest;

typedef struct CaptureConfig {int bank,pad[2];GXCaptureSize size;GXCaptureMode mode;GXCaptureSrcA a;GXCaptureSrcB b;GXCaptureDest dest;} CaptureConfig;

typedef struct Config {unsigned words[11];} Config;

typedef struct Demo3dDataCtx { unsigned int id; Config config; int active; void *task; } Demo3dDataCtx;

struct Owner { u8 pad[0x20]; struct Tcbl *manager; };

struct Work { struct Owner *owner; u8 state,kind,target,pad; int duration,start,end,current,step; };

extern void *TCBL_AddTask(void *,void (*)(void *,void *),unsigned,unsigned);

extern void *TCBL_GetWork(struct S02030FB4 *);

extern unsigned short func_02080C54(void);

extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);

extern void func_0208068C(int);

extern void MIi_CpuClearFast(unsigned,void *,unsigned);

extern void TCBL_DeleteTask(struct TcblNode *);

extern void GFL_USE_PlaySeInSlot(void *,int);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern int GFL_USE_GetSeSlot(unsigned);

extern void GFL_USE_SetSeSlotVolume(int,unsigned);

extern void GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);

extern void GFL_USE_StopSeSlot(int);

extern void MI_CpuFill8(void *,int,int);

int DEMO3D_DATA_IsCaptureDone(char *p, int v);

extern u32 FX_Div(u32,u32);

extern void GFL_USE_CancelChangeAndPlayBgm(int,int);

extern void GFL_USE_CancelChangeAndStopBgm(void);

u32 DEMO3D_DATA_GetRecordField(u32 id);

extern void *DEMO3D_DATA_CreateCapture(void *p, unsigned a, unsigned b);

extern void DEMO3D_DATA_DeleteCapture(int);

void *DEMO3D_DATA_CreateTask(void *manager, const Config *source);

void DEMO3D_DATA_DeleteTask(int *s,unsigned a,unsigned b,unsigned c);

void DEMO3D_DATA_ApplyCapture(void *task, const int *ctx);

void DEMO3D_DATA_FinishTask(void *node,int *s);

void DEMO3D_DATA_StartCapture(CaptureConfig *s);

void DEMO3D_DATA_PlaySe(void *unused,int ignored,int *s);

void DEMO3D_DATA_StopSe(u32 a, u32 b, int *c);

void DEMO3D_DATA_FadeSeVolume(int a0, int a1, int *src);

void DEMO3D_DATA_FadeSeSlotParam1(struct Owner *p,int unused,int *v);

void DEMO3D_DATA_FadeSeSlotParam2(struct Owner *p,int unused,int *s);

void DEMO3D_DATA_CreateSeFade(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag);

void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p,char *q);

void DEMO3D_DATA_ApplySeFade(int mode,int channel,int value);

void DEMO3D_DATA_PlayBgm(int a,int b,int *s);

void DEMO3D_DATA_StopBgm(void);

extern u8 d_021C1864[];

extern const Config d_021C3B98;

u32 DEMO3D_DATA_GetRecordField(u32 id)
{
    return *(u32 *)(d_021C1864 + DEMO3D_ENGINE_ClampAnimeId(id) * 0x14);
}

void * DEMO3D_DATA_CreateCapture(void *p,unsigned a,unsigned b) { Config c;c=d_021C3B98;c.words[8]=a;c.words[9]=b;return DEMO3D_DATA_CreateTask(p, &c); }

void DEMO3D_DATA_DeleteCapture(int a)
{
    DEMO3D_DATA_DeleteTask((int *)a, 1, 0, 1);
}

void *DEMO3D_DATA_CreateTask(void *manager, const Config *source)
{
    void *task;
    Demo3dDataCtx *ctx;
    task = TCBL_AddTask(manager, (void (*)(void *, void *))DEMO3D_DATA_ApplyCapture, 56, 5);
    ctx = (Demo3dDataCtx *) TCBL_GetWork(task);
    *(Config *)&ctx->config = *source;
    ctx->task = task;
    ctx->active = 0;
    ctx->id = func_02080C54();
    DEMO3D_DATA_StartCapture((struct CaptureConfig *)((char *)ctx + 4));
    func_020056A0((unsigned)DEMO3D_DATA_FinishTask, (unsigned)ctx, 0);
    return (void *)ctx;
}

void DEMO3D_DATA_DeleteTask(int *s,unsigned a,unsigned b,unsigned c)
{
    GX_SetGraphicsMode(a,b,c);func_0208068C(s[0]);
    switch(s[1]){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    default:func_0208068C(0);break;
    }
    TCBL_DeleteTask((struct TcblNode *)s[13]);
}

static inline void GX_SetCapture(GXCaptureSize sz, GXCaptureMode mode, GXCaptureSrcA a, GXCaptureSrcB b, GXCaptureDest dest, int eva, int evb)
{
    *(volatile unsigned *)0x04000064 = 0x80000000 | (mode << 29) | (b << 25) | (a << 24) | (sz << 20) | (dest << 16) | (evb << 8) | eva;
}

void DEMO3D_DATA_ApplyCapture(void *task, const int *ctx)
{
    if (ctx[12]) {
        GX_SetCapture(ctx[4], ctx[5], ctx[6], ctx[7], ctx[8], ctx[9], ctx[10]);
    }
}

void DEMO3D_DATA_FinishTask(void *node,int *s)
{
    int bank;
    switch(s[1]){case 2:bank=1;break;case 6:bank=2;break;case 10:bank=4;break;case 14:bank=8;break;default:bank=0;break;}
    func_0208068C(bank);GX_SetGraphicsMode(s[1],s[2],s[3]);s[12]=1;func_02030EAC(node);
}

/*
 * volatile: SDK GX_SetCapture write to DISPCAPCNT 04000064 at 021BEBB4.
 */
void DEMO3D_DATA_StartCapture(CaptureConfig *s)
{
    switch(s->bank){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    }
    GX_SetCapture(s->size,s->mode,s->a,s->b,s->dest,16,0);
}

void DEMO3D_DATA_PlaySe(void *unused,int ignored,int *s)
{
    int channel;
    if(s[4]!=-1){GFL_USE_PlaySeInSlot((void *)s[0],s[4]);channel=s[4];}
    else {GFL_USE_PlaySeDefaultVolume(s[0]);channel=GFL_USE_GetSeSlot(s[0]);}
    if(s[1]!=-1)GFL_USE_SetSeSlotVolume(channel,s[1]);
    if(s[2]!=-1)GFL_USE_SetSeSlotParams(channel,-1,-1,s[2]);
    if(s[3]!=-1)GFL_USE_SetSeSlotParams(channel,-1,s[3],-1);
}

void DEMO3D_DATA_StopSe(u32 a, u32 b, int *c)
{
    int ch = c[1];
    if (ch == -1) {
        ch = GFL_USE_GetSeSlot(c[0]);
    }
    GFL_USE_StopSeSlot(ch);
}

void DEMO3D_DATA_FadeSeVolume(int a0, int a1, int *src)
{
    DEMO3D_DATA_CreateSeFade((struct Owner *)a0, 0, (unsigned short)src[0], src[1], src[2], src[3], src[4]);
}

void DEMO3D_DATA_FadeSeSlotParam1(struct Owner *p,int unused,int *v) {DEMO3D_DATA_CreateSeFade(p,1,(u16)v[0],v[1],v[2],v[3],v[4]);}

void DEMO3D_DATA_FadeSeSlotParam2(struct Owner *p,int unused,int *s) { DEMO3D_DATA_CreateSeFade(p,2,s[0],s[1],s[2],s[3],s[4]); }

/*
 * The u16 target parameter fixes the otherwise swapped home stores at +6/+8.
 */
void DEMO3D_DATA_CreateSeFade(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(owner->manager,(void (*)(void *, void *))DEMO3D_DATA_UpdateSeFade,0x1c,0));
    MI_CpuFill8(work,0,0x1c);
    work->owner=owner;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=DEMO3D_DATA_IsCaptureDone((char *)owner,duration);
    if(flag == -1) work->target=flag;
    else work->target=GFL_USE_GetSeSlot(target);
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=FX_Div(final-work->current,(int)b);
}

void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p,char *q) { int old;old=((struct Work *)q)->duration;((struct Work *)q)->duration=old-1;if(old>0){DEMO3D_DATA_ApplySeFade(((struct Work *)q)->kind,((struct Work *)q)->target,((struct Work *)q)->current>>12);((struct Work *)q)->current+=((struct Work *)q)->step;}else {DEMO3D_DATA_ApplySeFade(((struct Work *)q)->kind,((struct Work *)q)->target,((struct Work *)q)->end);TCBL_DeleteTask(p);} }

void DEMO3D_DATA_ApplySeFade(int mode,int channel,int value)
{
    switch(mode){case 0:GFL_USE_SetSeSlotVolume(channel,value);break;case 1:GFL_USE_SetSeSlotParams(channel,-1,-1,value);break;case 2:GFL_USE_SetSeSlotParams(channel,-1,value,-1);break;}
}

void DEMO3D_DATA_PlayBgm(int a,int b,int *s){GFL_USE_CancelChangeAndPlayBgm(s[0],0xffff);}

void DEMO3D_DATA_StopBgm(void){GFL_USE_CancelChangeAndStopBgm();}

struct Context_021BF290;

struct MsgBank;

struct Descriptor;

struct CharBuf;

struct Rec3;

struct U16Vec;

typedef struct Task_021BEE1C {char *owner;unsigned reserved;unsigned char done,a,b,mode;int channel,start,end;} Task_021BEE1C;



struct CmdWork { struct Owner *owner; int state,mask,kind,duration,start,end,current,step; int *counter; };

typedef struct Task_021BF168 {char *owner;unsigned reserved;unsigned char done;signed char a,b,c;int start,end,count;unsigned index,mask;} Task_021BF168;

struct Triple{unsigned short x,y,z;};

struct Config_021BF290 { u16 a0,a2; u32 a4,a8,ac,a10,a14; s8 a18; u8 pad[7]; u32 a20,a24; };

struct Context_021BF290 { struct Config_021BF290 *cfg; int state,count,limit; u32 file,index,base; void *desc; u32 printer; void *text; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;void *text;void *window;int pad20[2]; } Work_021BF290;

struct Config_021BF470 { u16 a0,heap; u32 a4,a8,stop,a10,a14,a18,a1c,a20,a24; void *archive; };

struct Context_021BF470 { struct Config_021BF470 *cfg; int state,count,wait; u32 first,a14,second; int fadein,fadeout,blend,step; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;int d;int e;int f;int pad24[2]; } Work_021BF470;

struct Q { char pad[6]; unsigned short flag : 1; };

extern void GFL_USE_FadeInBgmFull(u32 a);

extern void GFL_USE_FadeOutBgm(u32 a);

extern int GFL_USE_IsBgmFading(void);

extern void GFL_USE_SetBgmPlayerParam(void *);

extern int GFL_USE_PushBgm(void),GFL_USE_PopBgm(void);

extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);

extern void DEMO3D_GRAPHIC_SetLightSlot(char *p, unsigned i, unsigned short val);

extern void DEMO3D_GRAPHIC_SetLightVector(char *p, int a, int b);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32,u32,u32,u32);

extern void *MSGDATA_AllocString(struct MsgBank *,u32);

extern void GF_FONT_SetTextColor(u32,u32,u32);

/* The caller stores the live r0 result, although the matched wrapper was typed void. */
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void BMP_WIN_MakeScreen(struct Cfg *);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);

extern void BG_SYS_PushTile(u32);

extern void BMP_MENUWORK_DrawWindowEx(void *,u32,u32,u32);

extern u32 sub_02045C04(struct Rec *rec);

extern void BG_SYS_SetVisibleLayer(int,u16);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void *BMP_MENUWORK_LoadFrameGfx(void *,unsigned,unsigned,unsigned);

extern void *BMP_WIN_GetBmp(struct Descriptor *);

extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_MENUWORK_DrawWindowBorder(void *,unsigned);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_MENUWORK_DeleteHalf(int a, u32 x);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);

extern u32 func_02049990(void *,u32,u32,u32,u32,u32,u32,u16);

extern void func_0207D63C(u32,int,int,int,int);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void *memset(void *,int,unsigned);

void DEMO3D_DATA_TaskFadeOutBgm(char *p,int unused,int *s);

void DEMO3D_DATA_TaskPlayBgm(char *p,int unused,int *s);

void DEMO3D_DATA_CreateBgmFade(char *p,int channel,int start,int end,unsigned mode);

void DEMO3D_DATA_BgmFadeMain(struct TcblNode *node,Task_021BEE1C *t);

void DEMO3D_DATA_TaskFadeBrightness(char *p,int unused,int *s);

void DEMO3D_DATA_CreateBrightnessFade(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter);

void DEMO3D_DATA_BrightnessFadeMain(struct TcblNode *node,int *s);

void DEMO3D_DATA_TaskBrightnessSeq(char *p,int unused,int *s);

void DEMO3D_DATA_CreateBrightnessSeq(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end);

void DEMO3D_DATA_BrightnessSeqMain(void *task,char *work);

void DEMO3D_DATA_TaskSetLightSlot(unsigned unused,char **q,unsigned *v);

void DEMO3D_DATA_TaskSetLightVector(unsigned unused,char **q,unsigned *v);

void DEMO3D_DATA_TaskShowMessage(int a, int b, int *s);

void DEMO3D_DATA_CreateMessage(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);

void DEMO3D_DATA_MessageMain(struct TcblNode *task, struct Context_021BF290 *ctx);

void DEMO3D_DATA_CreateMessageWindow(char *p,Work_021BF290 *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);

void DEMO3D_DATA_DeleteMessageWindow(char *p);

void DEMO3D_DATA_TaskFade(char *p,int unused,int *record);

void DEMO3D_DATA_CreateFade(char *p,int a,int b,int c,int d,int e,int f);

void DEMO3D_DATA_FadeMain(struct TcblNode *task,struct Context_021BF470 *ctx);

void DEMO3D_DATA_CreateFadeWork(char *p,Work_021BF470 *out,int a,int b,int c,int d,int e,int f);

void DEMO3D_DATA_DeleteFadeWork(void *p);

void DEMO3D_DATA_TaskCreateCapture(char *a, int unused, int *p);

void DEMO3D_DATA_TaskDeleteCapture(char *a);

extern const unsigned char GAME_VERSION_Code;

void DEMO3D_DATA_TaskFadeOutBgm(char *p,int unused,int *s) { int x;x=DEMO3D_DATA_IsCaptureDone(p,s[1]);if(s[0]==0)GFL_USE_FadeInBgmFull((u16)x);else GFL_USE_FadeOutBgm((u16)x); }

void DEMO3D_DATA_TaskPlayBgm(char *p,int unused,int *s)
{
    int channel,a,b;
    channel=s[0];a=DEMO3D_DATA_IsCaptureDone(p,s[1]);b=DEMO3D_DATA_IsCaptureDone(p,s[2]);
    if(s[3]==0){GFL_USE_CancelChangeAndPlayBgm(channel,0xffff);GFL_USE_FadeInBgmFull((unsigned short)b);}
    else {DEMO3D_DATA_CreateBgmFade(p,channel,a,b,s[3]);}
}

void DEMO3D_DATA_CreateBgmFade(char *p,int channel,int start,int end,unsigned mode)
{
    Task_021BEE1C *t;
    int flag=0;
    t=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(void *,void *))DEMO3D_DATA_BgmFadeMain,24,0));
    MI_CpuFill8(t,0,24);
    t->owner=p;t->mode=mode;
    if(mode==3)flag=1;
    t->a=flag;
    if(mode==4)t->b=1;else t->b=0;
    t->channel=channel;t->start=start;t->end=end;
    if(start!=0)GFL_USE_FadeOutBgm((unsigned short)start);else t->done=1;
}

void DEMO3D_DATA_BgmFadeMain(struct TcblNode *node,Task_021BEE1C *t)
{
    switch(t->done){
    case 0:
        if(GFL_USE_IsBgmFading()!=0)return;
        ++t->done;
    case 1:
        if(t->a){
            if((unsigned char)t->owner[25]==0){GFL_USE_SetBgmPlayerParam((void *)1);GFL_USE_PushBgm();t->owner[25]=1;}
        }else {GFL_USE_CancelChangeAndStopBgm();if(t->mode==1)break;}
        if(t->b){
            if((unsigned char)t->owner[25]!=0){GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);t->owner[25]=0;}
        }else {GFL_USE_CancelChangeAndPlayBgm(t->channel,0xffff);}
        if(t->end!=0)GFL_USE_FadeInBgmFull((unsigned short)t->end);
        break;
    }
    TCBL_DeleteTask(node);
}

/*
 * trailing: two-byte zero alignment padding at 021BEFC2.
 */
void DEMO3D_DATA_TaskFadeBrightness(char *p,int unused,int *s)
{
    if(s[1]==0){BRIGHTNESS_Set((short)s[2],0x3f,s[0]);}
    else {DEMO3D_DATA_CreateBrightnessFade((struct Owner *)p,s[0],0x3f,s[2],s[3],DEMO3D_DATA_IsCaptureDone(p,s[1]),0);}
}

void DEMO3D_DATA_CreateBrightnessFade(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter)
{
    struct CmdWork *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(owner->manager,(void (*)(void *, void *))DEMO3D_DATA_BrightnessFadeMain,0x28,0));
    MI_CpuFill8(work,0,0x28);
    work->owner=owner;
    work->mask=mask;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=duration;
    work->counter=counter;
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=FX_Div(final-work->current,(int)b);
    if(counter != 0) (*counter)++;
    BRIGHTNESS_Set((short)work->start,work->kind,work->mask);
}

void DEMO3D_DATA_BrightnessFadeMain(struct TcblNode *node,int *s)
{
    if(*(int *)((char *)s[0]+12)!=0){
        BRIGHTNESS_Set((short)s[6],s[3],s[2]);
        if(s[9]!=0)--*(int *)s[9];
        TCBL_DeleteTask(node);return;
    }
    if(s[4]-->0){BRIGHTNESS_Set((short)(s[7]>>12),s[3],s[2]);s[7]+=s[8];}
    else {BRIGHTNESS_Set((short)s[6],s[3],s[2]);if(s[9]!=0)--*(int *)s[9];TCBL_DeleteTask(node);}
}

void DEMO3D_DATA_TaskBrightnessSeq(char *p,int unused,int *s)
{
    int a,b;
    a=DEMO3D_DATA_IsCaptureDone(p,s[4]);b=DEMO3D_DATA_IsCaptureDone(p,s[5]);
    DEMO3D_DATA_CreateBrightnessSeq(p,s[0],s[1],s[2],s[3],a,b);
}

void DEMO3D_DATA_CreateBrightnessSeq(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end)
{
    Task_021BF168 *t;
    t=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(void *,void *))DEMO3D_DATA_BrightnessSeqMain,32,1));
    MI_CpuFill8(t,0,32);
    t->owner=p;t->a=a;t->b=b;t->c=c;t->index=index;t->mask=63;t->start=start;t->end=end;
    DEMO3D_DATA_CreateBrightnessFade((struct Owner *)p,t->index,t->mask,a,b,start,&t->count);
}

void DEMO3D_DATA_BrightnessSeqMain(void *task,char *work)
{
    if(((struct Obj25324 *)(*(char * *)&((struct Obj01291 *)work)->f0))->fC) {
        BRIGHTNESS_Set(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
        TCBL_DeleteTask(task);return;
    }
    switch(((struct Obj01291 *)work)->f8) {
    case 0:
        if(((struct Obj01291 *)work)->f14==0) {
            DEMO3D_DATA_CreateBrightnessFade((struct Owner *)(*(char * *)&((struct Obj01291 *)work)->f0),*(int *)&((struct Obj01291 *)work)->f18,*(int *)&((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->fA,((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f10,(int *)(work+0x14));
            (((struct Obj01291 *)work)->f8)++;
        }
        break;
    case 1:
        if(((struct Obj01291 *)work)->f14) return;
        break;
    }
    BRIGHTNESS_Set(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
    TCBL_DeleteTask(task);
}

void DEMO3D_DATA_TaskSetLightSlot(unsigned unused,char **q,unsigned *v){DEMO3D_GRAPHIC_SetLightSlot(*q,(unsigned char)v[0],v[1]|(v[2]<<5)|(v[3]<<10));}

void DEMO3D_DATA_TaskSetLightVector(unsigned unused,char **q,unsigned *v){struct Triple t;t.x=v[1];t.y=v[2];t.z=v[3];DEMO3D_GRAPHIC_SetLightVector(*q,(unsigned char)v[0],(int)&t);}

void DEMO3D_DATA_TaskShowMessage(int a, int b, int *s)
{
    unsigned char x = ((struct Obj25327 *)b)->f80;
    int r6 = s[2] * x;
    int r4 = s[1];
    int t = DEMO3D_DATA_IsCaptureDone((char *)a, s[3]);

    DEMO3D_DATA_CreateMessage((char *)a, s[0], r4 + r6, t, (unsigned char)s[4],
                  (unsigned char)s[5], (unsigned char)s[6], (unsigned char)s[7]);
}

void DEMO3D_DATA_CreateMessage(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    DEMO3D_DATA_CreateMessageWindow(p,TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(void *,void *))DEMO3D_DATA_MessageMain,0x28,1)),a,b,c,d,e,f,g);
}

void DEMO3D_DATA_MessageMain(struct TcblNode *task, struct Context_021BF290 *ctx)
{
    struct Config_021BF290 *cfg = ctx->cfg;
    if (cfg->ac != 0) {
        DEMO3D_DATA_DeleteMessageWindow((char *)ctx);
        TCBL_DeleteTask(task);
        return;
    }
    switch (ctx->state) {
    case 0: {
        struct MsgBank *bank = MSGDATA_CreateFromArchive(0,2,(u16)ctx->file,cfg->a2);
        void *desc;
        ctx->text = MSGDATA_AllocString(bank,ctx->index);
        GF_FONT_SetTextColor(1,2,15);
        ctx->printer = PRINTSYS_PrintStream((u32)ctx->desc,0,0,(u32)ctx->text,cfg->a24,cfg->a18,cfg->a20,0,cfg->a0,15);
        desc = ctx->desc;
        BMP_WIN_TransferChars(desc);
        BMP_WIN_MakeScreen(desc);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(desc));
        BMP_MENUWORK_DrawWindowEx(ctx->desc,1,ctx->base,0);
        sub_02045C04((struct Rec *)bank);
        BG_SYS_SetVisibleLayer(1,0);
        BG_SYS_SetVisibleLayer(0,1);
        BG_SYS_SetPlaneVisible(1,1);
        ctx->state++;
        break;
    }
    case 1:
        if (ctx->count++ >= ctx->limit) {
            DEMO3D_DATA_DeleteMessageWindow((char *)ctx);
            TCBL_DeleteTask(task);
        }
        break;
    }
}

void DEMO3D_DATA_CreateMessageWindow(char *p,Work_021BF290 *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    MI_CpuFill8(out,0,0x28);
    out->a=a;out->c=c;out->ctx=p;out->b=b;
    out->text=BMP_MENUWORK_LoadFrameGfx((void *)1,0,1,((struct Obj14596 *)p)->f2);
    func_02049B40(23,5,0,32,32,((struct Obj14596 *)p)->f2);
    out->window=(void *)BMP_WIN_Create(1,d,e,f,g,1,0);
    BMP_Clear(BMP_WIN_GetBmp(out->window),15);
}

/*
 * padding: 0x021BF4C2..0x021BF4C4 is zero alignment padding.
 */
void DEMO3D_DATA_DeleteMessageWindow(char *p)
{
    if(*(void **)(p+0x20)) PRINTSYS_PrintStreamDelete(*(void **)(p+0x20));
    STRBUF_Delete(*(void **)(p+0x24));GF_FONT_SetDefaultTextColor();
    BMP_MENUWORK_DrawWindowBorder(*(void **)(p+0x1C),1);BMP_WIN_Delete(*(void **)(p+0x1C));
    BMP_MENUWORK_DeleteHalf(1,*(int *)(p+0x18));MI_CpuFill8(p,0,0x28);
    BG_SYS_SetVisibleLayer(1,1);BG_SYS_SetVisibleLayer(0,0);func_02040588(1,0);
}

void DEMO3D_DATA_TaskFade(char *p,int unused,int *record)
{
    int a,b,c;
    if(record[0]==0xFF || record[0]==GAME_VERSION_Code) {
        a=DEMO3D_DATA_IsCaptureDone(p,record[4]);b=DEMO3D_DATA_IsCaptureDone(p,record[5]);c=DEMO3D_DATA_IsCaptureDone(p,record[6]);
        DEMO3D_DATA_CreateFade(p,record[1],record[2],record[3],a,b,c);
    }
}

void DEMO3D_DATA_CreateFade(char *p,int a,int b,int c,int d,int e,int f)
{
    DEMO3D_DATA_CreateFadeWork(p,TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(void *,void *))DEMO3D_DATA_FadeMain,0x2C,1)),a,b,c,d,e,f);
}

/*
 * volatile: 0x04000052
 */
void DEMO3D_DATA_FadeMain(struct TcblNode *task,struct Context_021BF470 *ctx)
{
    struct Config_021BF470 *cfg=ctx->cfg;
    float a;
    if(cfg->stop != 0) {
        DEMO3D_DATA_DeleteFadeWork(ctx);
        TCBL_DeleteTask(task);
        return;
    }
    switch(ctx->state) {
    case 0:
        ARC_UTIL_UploadPaletteFromHandleWhole(cfg->archive,ctx->first,0,0,0,cfg->heap);
        func_02049990(cfg->archive,ctx->second,1,0,0,0,1,cfg->heap);
        ctx->state++;
        break;
    case 1:
        ctx->count=0;
        ctx->blend=0;
        if(ctx->fadein>0) a=0.5f+(float)(ctx->fadein<<12);
        else a=(float)(ctx->fadein<<12)-0.5f;
        ctx->step=FX_Div(0x10000,(int)a);
        BG_SYS_SetVisibleLayer(1,0);
        BG_SYS_SetVisibleLayer(0,1);
        func_0207D63C(0x04000050,2,1,0,16);
        BG_SYS_SetPlaneVisible(1,1);
        ctx->state++;
        break;
    case 2:
        if(ctx->count++ < ctx->fadein) {
            int value;
            ctx->blend += ctx->step;
            value=ctx->blend>>12;
            *(volatile u16 *)0x04000052=value|((16-value)<<8);
        } else {
            *(volatile u16 *)0x04000052=16;
            ctx->count=0;
            ctx->state++;
        }
        break;
    case 3:
        if(ctx->count++ >= ctx->wait) {
            ctx->count=0;
            ctx->blend=0;
            if(ctx->fadeout>0) a=0.5f+(float)(ctx->fadeout<<12);
            else a=(float)(ctx->fadeout<<12)-0.5f;
            ctx->step=FX_Div(0x10000,(int)a);
            ctx->state++;
        }
        break;
    case 4:
        if(ctx->count++ < ctx->fadeout) {
            int value;
            ctx->blend += ctx->step;
            value=ctx->blend>>12;
            *(volatile u16 *)0x04000052=(16-value)|(value<<8);
        } else {
            *(volatile u16 *)0x04000052=0x1000;
            ctx->count=0;
            ctx->state++;
        }
        break;
    default:
        DEMO3D_DATA_DeleteFadeWork(ctx);
        TCBL_DeleteTask(task);
        break;
    }
}

void DEMO3D_DATA_CreateFadeWork(char *p,Work_021BF470 *out,int a,int b,int c,int d,int e,int f)
{
    MI_CpuFill8(out,0,0x2C);
    out->ctx=p;out->c=d;out->a=a;out->d=c;out->b=b;out->e=e;out->f=f;
    func_02049658((void *)(((struct Obj03917 *)p)->f28),out->b,1,0,0,1,((struct Obj03917 *)p)->f2);
}

void DEMO3D_DATA_DeleteFadeWork(void *p){unsigned z=0;memset(p,0,0x2c);func_02040588(1,0);BG_SYS_SetVisibleLayer(0,0);BG_SYS_SetVisibleLayer(1,1);*(volatile unsigned short *)0x04000050=z;BG_SYS_FreeSlot(1);}

void DEMO3D_DATA_TaskCreateCapture(char *a, int unused, int *p)
{
    ((struct Obj14597 *)a)->f2C = (int)DEMO3D_DATA_CreateCapture((void *)(((struct Obj14597 *)a)->f20), p[0], p[1]);
}

void DEMO3D_DATA_TaskDeleteCapture(char *a)
{
    DEMO3D_DATA_DeleteCapture(((struct Obj14599 *)a)->f2C);
    ((struct Obj14599 *)a)->f2C = 0;
}

int DEMO3D_DATA_IsCaptureDone(char *p, int v)
{
    struct Q *q = *(struct Q * *)&((struct Obj25328 *)(*(char * *)&((struct Obj03917 *)p)->f1C))->f74;
    int flag = q->flag;

    if (flag == 1)
        v *= 2;
    return v;
}
