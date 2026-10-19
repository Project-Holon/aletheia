/*
 * file:     demo3d_data.c
 * unit:     yes
 * function: DEMO3D_DATA_Create, DEMO3D_DATA_Delete, DEMO3D_DATA_BuildTable, DEMO3D_DATA_GetPair, DEMO3D_DATA_GetTimeStep, DEMO3D_DATA_IsDouble3dDisplay, DEMO3D_DATA_GetTextureSize, DEMO3D_DATA_GetCommandList, DEMO3D_DATA_GetExitCommandList, DEMO3D_DATA_CreateCapture, DEMO3D_DATA_DeleteCapture, DEMO3D_DATA_CreateTask, DEMO3D_DATA_DeleteTask, DEMO3D_DATA_ApplyCapture, DEMO3D_DATA_FinishTask, DEMO3D_DATA_StartCapture, DEMO3D_DATA_PlaySe, DEMO3D_DATA_StopSe, DEMO3D_DATA_FadeSeVolume, DEMO3D_DATA_FadeSeSlotParam1, DEMO3D_DATA_FadeSeSlotParam2, DEMO3D_DATA_CreateSeFade, DEMO3D_DATA_UpdateSeFade, DEMO3D_DATA_ApplySeFade, DEMO3D_DATA_PlayBgm, DEMO3D_DATA_StopBgm, DEMO3D_DATA_TaskFadeOutBgm, DEMO3D_DATA_TaskPlayBgm, DEMO3D_DATA_CreateBgmFade, DEMO3D_DATA_BgmFadeMain, DEMO3D_DATA_TaskFadeBrightness, DEMO3D_DATA_CreateBrightnessFade, DEMO3D_DATA_BrightnessFadeMain, DEMO3D_DATA_TaskBrightnessSeq, DEMO3D_DATA_CreateBrightnessSeq, DEMO3D_DATA_BrightnessSeqMain, DEMO3D_DATA_TaskSetLightSlot, DEMO3D_DATA_TaskSetLightVector, DEMO3D_DATA_TaskShowMessage, DEMO3D_DATA_CreateMessage, DEMO3D_DATA_MessageMain, DEMO3D_DATA_CreateMessageWindow, DEMO3D_DATA_DeleteMessageWindow, DEMO3D_DATA_TaskFade, DEMO3D_DATA_CreateFade, DEMO3D_DATA_FadeMain, DEMO3D_DATA_CreateFadeWork, DEMO3D_DATA_DeleteFadeWork, DEMO3D_DATA_TaskCreateCapture, DEMO3D_DATA_TaskDeleteCapture, DEMO3D_DATA_ScaleTime
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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   memset 0x02082BCC arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   FX_Div 0x0207C768 arm
 *   d_021C3CF0 0x021C3CF0 data a1
 *   d_021C0348 0x021C0348 data a4
 *   d_021C1868 0x021C1868 data a4
 *   d_021C1860  0x021C1860  data
 *   DEMO3D_ENGINE_ClampDemoId  0x021BE79C  thumb  ov203
 *   d_021C1864  0x021C1864  data
 *   d_021C3B98 0x021C3B98 data a4
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   GX_GetBankForLCDC 0x02080C54 arm
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   GX_SetBankForLCDC 0x0208068C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_SetSeSlotVolume 0x020062BC thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   DEMO3D_DATA_ScaleTime 0x021BF7AC thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
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
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENUWORK_FreeTileRun 0x0201F614 thumb
 *   GAME_VERSION_Code 0x0209DF08 data a1
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   memset 0x02082BCC arm
 *   DEMO3D_DATA_CreateCapture 0x021BE9B8 thumb
 *   DEMO3D_DATA_DeleteCapture 0x021BE9E8 thumb
 *   DEMO3D_DATA_GetExitCommandList 0x021BE9A4 thumb ov203
 *   DEMO3D_DATA_GetCommandList 0x021BE990 thumb ov203
 *   DEMO3D_ENGINE_GetCameraRecord 0x021BE7A8 thumb ov203
 *   GFL_USE_StopSeSlot           0x020061F8  thumb
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "demo3d_graphic_shared_types.h"
#include "demo3d_engine_shared_types.h"
#include "demo3d_data_shared_types.h"

struct TcblNode;

#include "../types.h"

typedef struct Entry { int x; unsigned short id, pad; int flag; } Entry;

typedef struct Pair { const unsigned short *ids; unsigned count; } Pair;

typedef struct Group { const Pair *pairs; unsigned count; } Group;

typedef struct Selector { const Group *groups; unsigned short count, selector; } Selector;

typedef struct Row { const Selector *selectors; unsigned words[4]; } Row;

/* Data context built by DEMO3D_DATA_Create (16 bytes). */
typedef struct Demo3dData {
    Entry         *entries; /* 0x00 six-entry table */
    unsigned short count;   /* 0x04 */
    unsigned char  pad_6[2];
    char          *extra;   /* 0x08 */
    unsigned short active;  /* 0x0C */
    unsigned char  pad_E[2];
} Demo3dData;

typedef char Demo3dData_SizeCheck[(sizeof(Demo3dData) == 0x10) ? 1 : -1];

/* Per-object table built alongside Demo3dData (16 bytes). */
typedef struct Demo3dDataExtra {
    unsigned char  pad_0[8];
    void          *table;   /* 0x08 */
    unsigned short count;   /* 0x0C */
} Demo3dDataExtra;

typedef char Demo3dDataExtra_SizeCheck[(sizeof(Demo3dDataExtra) == 0x10) ? 1 : -1];

extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);

extern void *GFL_USE_AddMainTask(unsigned, unsigned, unsigned);
struct TcbTask;

extern void TCB_DeleteTask(struct TcbTask *task);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 GFL_HEAP_Free(void *p);

extern void BG_SYS_FreeSlot(unsigned char);

extern u32 DEMO3D_ENGINE_ClampDemoId(u32 id);

u32 DEMO3D_ENGINE_GetCameraRecord(u32 id);

void *DEMO3D_DATA_Create(unsigned heap);

void DEMO3D_DATA_Delete(char *a);

void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type);

void * DEMO3D_DATA_GetPair(char *p,u8 *q);

u32 DEMO3D_DATA_GetTimeStep(u32 a);

int DEMO3D_DATA_IsDouble3dDisplay(void *a);

void DEMO3D_DATA_GetTextureSize(void *ctx, int mode, unsigned char *width, unsigned char *height);

u32 DEMO3D_DATA_GetCommandList(u32 id);

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
    ctx = GFL_HEAP_Alloc(heap, 16, 1, d_021C3CF0, 0xab);
    entries = GFL_HEAP_Alloc(heap, 72, 1, d_021C3CF0, 0xac);
    extra = GFL_HEAP_Alloc(heap, 16, 1, d_021C3CF0, 0xad);
    for (i = 0; i < 6; i++) {
        entries[i].x = 160;
        entries[i].flag = 0;
    }
    ((Demo3dDataExtra *)extra)->table = d_021C0348;
    ((Demo3dData *)ctx)->entries = entries;
    ((Demo3dData *)ctx)->extra = extra;
    return ctx;
}

void DEMO3D_DATA_Delete(char *a)
{
    GFL_HEAP_Free(((Demo3dData *)a)->extra);
    GFL_HEAP_Free(((Demo3dData *)a)->entries);
    GFL_HEAP_Free(a);
}

void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type)
{
    Entry *entries = ((Demo3dData *)ctx)->entries;
    char *extra = ((Demo3dData *)ctx)->extra;
    unsigned choice = 0;
    const Group *group;
    int i;
    const Pair *pair;
    group = DEMO3D_DATA_GetPair((char *)(&d_021C1868[*(unsigned *)config].selectors[type]), (u8 *)config);
    if (group->count > 1) choice = ((Demo3dCfg *)config)->timeZone;
    if (choice >= group->count) choice = 0;
    pair = &group->pairs[choice];
    ((Demo3dData *)ctx)->count = pair->count;
    for (i = 0; i < 6; i++) {
        if (i < pair->count) entries[i].id = pair->ids[i];
        else entries[i].id = 0;
    }
    ((Demo3dData *)ctx)->active = 1;
    ((Demo3dDataExtra *)extra)->count = pair->count - 1;
}

void * DEMO3D_DATA_GetPair(char *p,u8 *q) { const Selector *sel=(const Selector *)p;int x=0;switch(sel->selector){case 1:x=q[10];break;case 2:x=q[8];break;case 3:x=q[13];break;}if(x>=sel->count)x=0;return (void *)((unsigned int)sel->groups+x*8); }

/*
 * The light record's flag halfword at +6 is struct Cam.doubled (bit 0): the
 * original extracts it with the equal shift pair `lsls #0x1f / lsrs #0x1f`
 * and shifts 0x1000 by it, so bit 0 selects 0x1000 or 0x800.
 * Addresses are Black-image addresses.
 */
u32 DEMO3D_DATA_GetTimeStep(u32 a)
{
    struct Cam *cam = (struct Cam *)DEMO3D_ENGINE_GetCameraRecord(a);

    return 0x1000 >> cam->doubled;
}

int DEMO3D_DATA_IsDouble3dDisplay(void *a)
{
    struct Cam *cam = (struct Cam *)DEMO3D_ENGINE_GetCameraRecord((u32)a);

    return cam->count;
}

void DEMO3D_DATA_GetTextureSize(void *ctx, int mode, unsigned char *width, unsigned char *height)
{
    unsigned char *record = (unsigned char *)DEMO3D_ENGINE_GetCameraRecord((u32)ctx);
    if (mode == 0) {
        *width = record[0x4e];
        *height = record[0x4f] * (((struct Cam *)record)->doubled + 1);
    } else {
        *width = record[0x50];
        *height = record[0x51] * (((struct Cam *)record)->doubled + 1);
    }
}

/*
 * closed: dropping the contested ov203 token lets the function's own region
 * pick the object; the +0010 ABS32 resolves as sole-ref/data and the file is
 * EXACT.  See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 * Addresses are Black-image addresses.
 */
u32 DEMO3D_DATA_GetCommandList(u32 id)
{
    return *(u32 *)(d_021C1860 + DEMO3D_ENGINE_ClampDemoId(id) * 0x14);
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

struct Demo3dSeFadeWork { Demo3dCmdContext *owner; u8 state,kind,target,pad; int duration,start,end,current,step; };
struct TcblSystem;
struct TcblTask;

extern struct TcblTask *TCBL_AddTask(struct TcblSystem *tcbl, void (*)(void *,void *), unsigned int workSize, unsigned int priority);

extern void *TCBL_GetWork(struct TcblTask *task);

extern unsigned short GX_GetBankForLCDC(void);

extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);

extern void GX_SetBankForLCDC(int);

extern void MIi_CpuClearFast(unsigned,void *,unsigned);

extern void TCBL_DeleteTask(struct TcblTask *task);

extern void GFL_USE_PlaySeInSlot(unsigned int seqNo, int slot);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern int GFL_USE_GetSeSlot(unsigned);

extern void GFL_USE_SetSeSlotVolume(int,unsigned);

extern void GFL_USE_SetSeSlotParams(int,unsigned,unsigned,unsigned);

extern void GFL_USE_StopSeSlot(int);

extern void MI_CpuFill8(void *,int,int);

int DEMO3D_DATA_ScaleTime(char *p, int v);

extern u32 FX_Div(u32,u32);

extern void GFL_USE_CancelChangeAndPlayBgm(unsigned int bgmNo, unsigned int trackMask);

extern void GFL_USE_CancelChangeAndStopBgm(void);

u32 DEMO3D_DATA_GetExitCommandList(u32 id);

extern void *DEMO3D_DATA_CreateCapture(void *p, unsigned a, unsigned b);

extern void DEMO3D_DATA_DeleteCapture(int);

void *DEMO3D_DATA_CreateTask(void *manager, const Config *source);

void DEMO3D_DATA_DeleteTask(int *s,unsigned a,unsigned b,unsigned c);

void DEMO3D_DATA_ApplyCapture(void *task, const int *ctx);

void DEMO3D_DATA_FinishTask(void *node,int *s);

void DEMO3D_DATA_StartCapture(CaptureConfig *s);

void DEMO3D_DATA_PlaySe(void *unused,int ignored,int *s);

void DEMO3D_DATA_StopSe(u32 a, u32 b, int *c);

void DEMO3D_DATA_FadeSeVolume(int ctx, int unused, int *src);

void DEMO3D_DATA_FadeSeSlotParam1(Demo3dCmdContext *p,int unused,int *v);

void DEMO3D_DATA_FadeSeSlotParam2(Demo3dCmdContext *p,int unused,int *s);

void DEMO3D_DATA_CreateSeFade(Demo3dCmdContext *owner,u8 kind,u16 target,int start,int end,int duration,int flag);

void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p,char *q);

void DEMO3D_DATA_ApplySeFade(int mode,int channel,int value);

void DEMO3D_DATA_PlayBgm(int a,int b,int *s);

void DEMO3D_DATA_StopBgm(void);

extern u8 d_021C1864[];

extern const Config d_021C3B98;

u32 DEMO3D_DATA_GetExitCommandList(u32 id)
{
    return *(u32 *)(d_021C1864 + DEMO3D_ENGINE_ClampDemoId(id) * 0x14);
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
    ctx->id = GX_GetBankForLCDC();
    DEMO3D_DATA_StartCapture((struct CaptureConfig *)((char *)ctx + 4));
    GFL_USE_AddMainTask((unsigned)DEMO3D_DATA_FinishTask, (unsigned)ctx, 0);
    return (void *)ctx;
}

void DEMO3D_DATA_DeleteTask(int *s,unsigned a,unsigned b,unsigned c)
{
    GX_SetGraphicsMode(a,b,c);GX_SetBankForLCDC(s[0]);
    switch(s[1]){
    case 2:MIi_CpuClearFast(0,(void *)0x06800000,0x20000);break;
    case 6:MIi_CpuClearFast(0,(void *)0x06820000,0x20000);break;
    case 10:MIi_CpuClearFast(0,(void *)0x06840000,0x20000);break;
    case 14:MIi_CpuClearFast(0,(void *)0x06860000,0x20000);break;
    default:GX_SetBankForLCDC(0);break;
    }
    TCBL_DeleteTask((struct TcblTask *)s[13]);
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
    GX_SetBankForLCDC(bank);GX_SetGraphicsMode(s[1],s[2],s[3]);s[12]=1;TCB_DeleteTask(node);
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
    if(s[4]!=-1){GFL_USE_PlaySeInSlot((unsigned int)s[0],s[4]);channel=s[4];}
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

void DEMO3D_DATA_FadeSeVolume(int ctx, int unused, int *src)
{
    DEMO3D_DATA_CreateSeFade((Demo3dCmdContext *)ctx, 0, (unsigned short)src[0], src[1], src[2], src[3], src[4]);
}

void DEMO3D_DATA_FadeSeSlotParam1(Demo3dCmdContext *p,int unused,int *v) {DEMO3D_DATA_CreateSeFade(p,1,(u16)v[0],v[1],v[2],v[3],v[4]);}

void DEMO3D_DATA_FadeSeSlotParam2(Demo3dCmdContext *p,int unused,int *s) { DEMO3D_DATA_CreateSeFade(p,2,s[0],s[1],s[2],s[3],s[4]); }

/*
 * The u16 target parameter fixes the otherwise swapped home stores at +6/+8.
 */
void DEMO3D_DATA_CreateSeFade(Demo3dCmdContext *owner,u8 kind,u16 target,int start,int end,int duration,int flag)
{
    struct Demo3dSeFadeWork *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)owner->task,(void (*)(void *, void *))DEMO3D_DATA_UpdateSeFade,0x1c,0));
    MI_CpuFill8(work,0,0x1c);
    work->owner=owner;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=DEMO3D_DATA_ScaleTime((char *)owner,duration);
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

void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p,char *q) { int old;old=((struct Demo3dSeFadeWork *)q)->duration;((struct Demo3dSeFadeWork *)q)->duration=old-1;if(old>0){DEMO3D_DATA_ApplySeFade(((struct Demo3dSeFadeWork *)q)->kind,((struct Demo3dSeFadeWork *)q)->target,((struct Demo3dSeFadeWork *)q)->current>>12);((struct Demo3dSeFadeWork *)q)->current+=((struct Demo3dSeFadeWork *)q)->step;}else {DEMO3D_DATA_ApplySeFade(((struct Demo3dSeFadeWork *)q)->kind,((struct Demo3dSeFadeWork *)q)->target,((struct Demo3dSeFadeWork *)q)->end);TCBL_DeleteTask((struct TcblTask *)p);} }

void DEMO3D_DATA_ApplySeFade(int mode,int channel,int value)
{
    switch(mode){case 0:GFL_USE_SetSeSlotVolume(channel,value);break;case 1:GFL_USE_SetSeSlotParams(channel,-1,-1,value);break;case 2:GFL_USE_SetSeSlotParams(channel,-1,value,-1);break;}
}

void DEMO3D_DATA_PlayBgm(int a,int b,int *s){GFL_USE_CancelChangeAndPlayBgm(s[0],0xffff);}

void DEMO3D_DATA_StopBgm(void){GFL_USE_CancelChangeAndStopBgm();}

struct Demo3dMessageContext;

struct MsgBank;

struct Descriptor;

struct CharBuf;

struct Rec3;

struct U16Vec;

/*
 * BGM cross-fade work (0x18 bytes).  step 0 waits for the current BGM fade to
 * finish, step 1 pushes or pops the saved BGM and starts the new one.  pushPrev
 * is set when mode 3 asks to save the previous BGM, popPrev when mode 4 asks to
 * restore it.
 */
typedef struct Demo3dBgmFadeWork {char *owner;unsigned reserved;unsigned char step,pushPrev,popPrev,mode;int channel,start,end;} Demo3dBgmFadeWork;

struct Demo3dBrightnessFadeWork { Demo3dCmdContext *owner; int state,mask,kind,duration,start,end,current,step; int *counter; };

/*
 * Brightness-sequence work (0x20 bytes).  The sequence is two brightness
 * ramps through three levels: firstLevel -> secondLevel over firstDuration,
 * then secondLevel -> thirdLevel over secondDuration.  The first ramp is
 * built by DEMO3D_DATA_CreateBrightnessSeq, which passes the caller's levels
 * and duration directly; the second ramp is rebuilt by
 * DEMO3D_DATA_BrightnessSeqMain from secondLevel/thirdLevel/secondDuration.
 *
 * firstLevel (0x09) and firstDuration (0x0C) are stored but never read back:
 * the first ramp consumes the caller's arguments, so those two stores are
 * write-only in this file.  They reproduce the original stores and are kept
 * for the bytes.
 */
typedef struct Demo3dBrightnessSeqWork {
    char          *owner;         /* 0x00 */
    unsigned       reserved;      /* 0x04 */
    union {
        signed char   state;      /* 0x08 fade-sequence step, read and advanced */
        unsigned char done;       /* 0x08 builder flag, only zero-filled */
    } step;
    signed char    firstLevel;    /* 0x09 first ramp start level (write-only) */
    signed char    secondLevel;   /* 0x0A mid level: ramp 1 end, ramp 2 start */
    signed char    thirdLevel;    /* 0x0B ramp 2 end level */
    int            firstDuration; /* 0x0C ramp 1 frame count (write-only) */
    int            secondDuration;/* 0x10 ramp 2 frame count */
    int            counter;       /* 0x14 active-fade counter, shared with the fade task */
    unsigned       engineMask;    /* 0x18 BRIGHTNESS_Set engine mask */
    unsigned       blendParam;    /* 0x1C BRIGHTNESS_Set a1, constant 63 */
} Demo3dBrightnessSeqWork;

typedef char Demo3dBrightnessSeqWork_SizeCheck[(sizeof(Demo3dBrightnessSeqWork) == 0x20) ? 1 : -1];

struct Demo3dLightVector{unsigned short x,y,z;};

/*
 * Demo3dMessageConfig is a view of the demo3d command context (Demo3dCmdContext)
 * reached through the message work's first field (work+0x00).  The field names
 * mirror Demo3dCmdContext: heap, alternate, config, ended, done, previous,
 * index, speed (flags[0], set from MSG_SPEED_GetWait in DEMO3D_CMDSYS_Init),
 * task and font (text).  Folding it into Demo3dCmdContext directly DIFFs
 * DEMO3D_DATA_MessageMain (the speed byte must load signed), so it is kept as a
 * separate view; see open_items.tsv.
 */
struct Demo3dMessageConfig { u16 heap,alternate; u32 config,ended,done,previous,index; s8 speed; u8 pad[7]; u32 task,font; };

struct Demo3dMessageContext { struct Demo3dMessageConfig *cfg; int state,count,limit; u32 file,index,base; void *desc; u32 printer; void *text; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;void *text;void *window;int pad20[2]; } Demo3dMessageWindowWork;

/*
 * Demo3dFadeConfig is a view of the demo3d command context (Demo3dCmdContext)
 * reached through the fade work's first field (work+0x00), with the same field
 * names as Demo3dMessageConfig.  DEMO3D_DATA_FadeMain reads done (scene ended),
 * alternate (heap selector) and assets (the archive handle).
 */
struct Demo3dFadeConfig { u16 heap,alternate; u32 config,ended,done,previous,index,flags,owner,task,font; void *assets; };

struct Demo3dFadeContext { struct Demo3dFadeConfig *cfg; int state,count,wait; u32 first,a14,second; int fadein,fadeout,blend,step; };

typedef struct { char *ctx;int pad4[2];int c;int a;int b;int d;int e;int f;int pad24[2]; } Demo3dFadeWindowWork;

extern void GFL_USE_FadeInBgmFull(u32 a);

extern void GFL_USE_FadeOutBgm(u32 a);

extern int GFL_USE_IsBgmFading(void);

extern void GFL_USE_SetBgmPaused(unsigned int value);

extern int GFL_USE_PushBgm(void),GFL_USE_PopBgm(void);

extern void BRIGHTNESS_Set(u32 brightness, u32 plane, u32 mask);
struct Demo3dGraphic;

extern void DEMO3D_GRAPHIC_SetLightSlot(struct Demo3dGraphic *p, unsigned int i, unsigned short val);

extern void DEMO3D_GRAPHIC_SetLightVector(struct Demo3dGraphic *p, int a, int b);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32,u32,u32,u32);

extern void *MSGDATA_AllocString(struct MsgBank *,u32);

extern void GF_FONT_SetTextColor(u32,u32,u32);

/* The caller stores the live r0 result, although the matched wrapper was typed void. */
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
struct BmpWin;

extern void BMP_WIN_TransferChars(struct BmpWin *win);

extern void BMP_WIN_MakeScreen(struct BmpWin *win);

extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);

extern void BG_SYS_PushTile(u32);

extern void BMP_MENUWORK_DrawWindowEx(struct BmpWin *desc, unsigned int commitMode, unsigned int tileBase, unsigned int palette);

extern u32 MSGDATA_Delete(struct MsgBank *bank);

extern void BG_SYS_SetPriority(int,u16);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
struct Bmp;

extern void BMP_Clear(struct Bmp *bmp, unsigned char value);

extern void *BMP_MENUWORK_LoadFrameGfx(unsigned int layer, unsigned int palSlot, unsigned int frameId, unsigned short heapId);

extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);

extern struct BmpWin *BMP_WIN_Create(unsigned int bgLayer, unsigned int posX, unsigned int posY, unsigned char width, unsigned char height, unsigned char palette, unsigned char allocDir);
struct TextPrinter;

extern void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer);
struct Strbuf;

extern void STRBUF_Delete(struct Strbuf *strbuf);

extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, unsigned int commitMode);

extern u32 BMP_WIN_Delete(struct BmpWin *win);

extern void BMP_MENUWORK_FreeTileRun(int a, u32 x);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);

extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *,u32,u32,u32,u32,u32,u32,u16);

extern void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b, unsigned int c, unsigned int d);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void *memset(void *,int,unsigned);

void DEMO3D_DATA_TaskFadeOutBgm(char *p,int unused,int *s);

void DEMO3D_DATA_TaskPlayBgm(char *p,int unused,int *s);

void DEMO3D_DATA_CreateBgmFade(char *p,int channel,int start,int end,unsigned mode);

void DEMO3D_DATA_BgmFadeMain(struct TcblNode *node,Demo3dBgmFadeWork *t);

void DEMO3D_DATA_TaskFadeBrightness(char *p,int unused,int *s);

void DEMO3D_DATA_CreateBrightnessFade(Demo3dCmdContext *owner,int mask,int kind,int start,int end,int duration,int *counter);

void DEMO3D_DATA_BrightnessFadeMain(struct TcblNode *node,int *s);

void DEMO3D_DATA_TaskBrightnessSeq(char *p,int unused,int *s);

void DEMO3D_DATA_CreateBrightnessSeq(char *p,unsigned char engineMask,signed char firstLevel,signed char secondLevel,signed char thirdLevel,int firstDuration,int secondDuration);

void DEMO3D_DATA_BrightnessSeqMain(void *task,char *work);

void DEMO3D_DATA_TaskSetLightSlot(unsigned unused,char **q,unsigned *v);

void DEMO3D_DATA_TaskSetLightVector(unsigned unused,char **q,unsigned *v);

void DEMO3D_DATA_TaskShowMessage(int a, int b, int *s);

void DEMO3D_DATA_CreateMessage(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);

void DEMO3D_DATA_MessageMain(struct TcblNode *task, struct Demo3dMessageContext *ctx);

void DEMO3D_DATA_CreateMessageWindow(char *p,Demo3dMessageWindowWork *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g);

void DEMO3D_DATA_DeleteMessageWindow(char *p);

void DEMO3D_DATA_TaskFade(char *p,int unused,int *record);

void DEMO3D_DATA_CreateFade(char *p,int a,int b,int c,int d,int e,int f);

void DEMO3D_DATA_FadeMain(struct TcblNode *task,struct Demo3dFadeContext *ctx);

void DEMO3D_DATA_CreateFadeWork(char *p,Demo3dFadeWindowWork *out,int a,int b,int c,int d,int e,int f);

void DEMO3D_DATA_DeleteFadeWork(void *p);

void DEMO3D_DATA_TaskCreateCapture(char *a, int unused, int *p);

void DEMO3D_DATA_TaskDeleteCapture(char *a);

extern const unsigned char GAME_VERSION_Code;

void DEMO3D_DATA_TaskFadeOutBgm(char *p,int unused,int *s) { int x;x=DEMO3D_DATA_ScaleTime(p,s[1]);if(s[0]==0)GFL_USE_FadeInBgmFull((u16)x);else GFL_USE_FadeOutBgm((u16)x); }

void DEMO3D_DATA_TaskPlayBgm(char *p,int unused,int *s)
{
    int channel,startVol,endVol;
    channel=s[0];startVol=DEMO3D_DATA_ScaleTime(p,s[1]);endVol=DEMO3D_DATA_ScaleTime(p,s[2]);
    if(s[3]==0){GFL_USE_CancelChangeAndPlayBgm(channel,0xffff);GFL_USE_FadeInBgmFull((unsigned short)endVol);}
    else {DEMO3D_DATA_CreateBgmFade(p,channel,startVol,endVol,s[3]);}
}

void DEMO3D_DATA_CreateBgmFade(char *p,int channel,int start,int end,unsigned mode)
{
    Demo3dBgmFadeWork *t;
    int flag=0;
    t=TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(((Demo3dCmdContext *)p)->task),(void (*)(void *,void *))DEMO3D_DATA_BgmFadeMain,24,0));
    MI_CpuFill8(t,0,24);
    t->owner=p;t->mode=mode;
    if(mode==3)flag=1;
    t->pushPrev=flag;
    if(mode==4)t->popPrev=1;else t->popPrev=0;
    t->channel=channel;t->start=start;t->end=end;
    if(start!=0)GFL_USE_FadeOutBgm((unsigned short)start);else t->step=1;
}

void DEMO3D_DATA_BgmFadeMain(struct TcblNode *node,Demo3dBgmFadeWork *t)
{
    switch(t->step){
    case 0:
        if(GFL_USE_IsBgmFading()!=0)return;
        ++t->step;
    case 1:
        if(t->pushPrev){
            if((unsigned char)t->owner[25]==0){GFL_USE_SetBgmPaused((unsigned int)1);GFL_USE_PushBgm();t->owner[25]=1;}
        }else {GFL_USE_CancelChangeAndStopBgm();if(t->mode==1)break;}
        if(t->popPrev){
            if((unsigned char)t->owner[25]!=0){GFL_USE_PopBgm();GFL_USE_SetBgmPaused(0);t->owner[25]=0;}
        }else {GFL_USE_CancelChangeAndPlayBgm(t->channel,0xffff);}
        if(t->end!=0)GFL_USE_FadeInBgmFull((unsigned short)t->end);
        break;
    }
    TCBL_DeleteTask((struct TcblTask *)node);
}

/*
 * trailing: two-byte zero alignment padding at 021BEFC2.
 */
void DEMO3D_DATA_TaskFadeBrightness(char *p,int unused,int *s)
{
    if(s[1]==0){BRIGHTNESS_Set((short)s[2],0x3f,s[0]);}
    else {DEMO3D_DATA_CreateBrightnessFade((Demo3dCmdContext *)p,s[0],0x3f,s[2],s[3],DEMO3D_DATA_ScaleTime(p,s[1]),0);}
}

void DEMO3D_DATA_CreateBrightnessFade(Demo3dCmdContext *owner,int mask,int kind,int start,int end,int duration,int *counter)
{
    struct Demo3dBrightnessFadeWork *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)owner->task,(void (*)(void *, void *))DEMO3D_DATA_BrightnessFadeMain,0x28,0));
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
        TCBL_DeleteTask((struct TcblTask *)node);return;
    }
    if(s[4]-->0){BRIGHTNESS_Set((short)(s[7]>>12),s[3],s[2]);s[7]+=s[8];}
    else {BRIGHTNESS_Set((short)s[6],s[3],s[2]);if(s[9]!=0)--*(int *)s[9];TCBL_DeleteTask((struct TcblTask *)node);}
}

void DEMO3D_DATA_TaskBrightnessSeq(char *p,int unused,int *s)
{
    int a,b;
    a=DEMO3D_DATA_ScaleTime(p,s[4]);b=DEMO3D_DATA_ScaleTime(p,s[5]);
    DEMO3D_DATA_CreateBrightnessSeq(p,s[0],s[1],s[2],s[3],a,b);
}

void DEMO3D_DATA_CreateBrightnessSeq(char *p,unsigned char engineMask,signed char firstLevel,signed char secondLevel,signed char thirdLevel,int firstDuration,int secondDuration)
{
    Demo3dBrightnessSeqWork *t;
    t=TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(((Demo3dCmdContext *)p)->task),(void (*)(void *,void *))DEMO3D_DATA_BrightnessSeqMain,32,1));
    MI_CpuFill8(t,0,32);
    t->owner=p;t->firstLevel=firstLevel;t->secondLevel=secondLevel;t->thirdLevel=thirdLevel;t->engineMask=engineMask;t->blendParam=63;t->firstDuration=firstDuration;t->secondDuration=secondDuration;
    DEMO3D_DATA_CreateBrightnessFade((Demo3dCmdContext *)p,t->engineMask,t->blendParam,firstLevel,secondLevel,firstDuration,&t->counter);
}

void DEMO3D_DATA_BrightnessSeqMain(void *task,char *work)
{
    Demo3dBrightnessSeqWork *w = (Demo3dBrightnessSeqWork *)work;
    if(((Demo3dCmdContext *)w->owner)->done) {
        BRIGHTNESS_Set(w->thirdLevel,w->blendParam,w->engineMask);
        TCBL_DeleteTask(task);return;
    }
    switch(w->step.state) {
    case 0:
        if(w->counter==0) {
            DEMO3D_DATA_CreateBrightnessFade((Demo3dCmdContext *)w->owner,(int)w->engineMask,(int)w->blendParam,w->secondLevel,w->thirdLevel,w->secondDuration,(int *)(work+0x14));
            w->step.state++;
        }
        break;
    case 1:
        if(w->counter) return;
        break;
    }
    BRIGHTNESS_Set(w->thirdLevel,w->blendParam,w->engineMask);
    TCBL_DeleteTask(task);
}

void DEMO3D_DATA_TaskSetLightSlot(unsigned unused,char **q,unsigned *v){DEMO3D_GRAPHIC_SetLightSlot((struct Demo3dGraphic *)(*q),(unsigned char)v[0],v[1]|(v[2]<<5)|(v[3]<<10));}

void DEMO3D_DATA_TaskSetLightVector(unsigned unused,char **q,unsigned *v){struct Demo3dLightVector t;t.x=v[1];t.y=v[2];t.z=v[3];DEMO3D_GRAPHIC_SetLightVector((struct Demo3dGraphic *)(*q),(unsigned char)v[0],(int)&t);}

void DEMO3D_DATA_TaskShowMessage(int a, int b, int *s)
{
    unsigned char x = ((struct Ctx *)b)->data.color;
    int r6 = s[2] * x;
    int r4 = s[1];
    int t = DEMO3D_DATA_ScaleTime((char *)a, s[3]);

    DEMO3D_DATA_CreateMessage((char *)a, s[0], r4 + r6, t, (unsigned char)s[4],
                  (unsigned char)s[5], (unsigned char)s[6], (unsigned char)s[7]);
}

void DEMO3D_DATA_CreateMessage(char *p,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    DEMO3D_DATA_CreateMessageWindow(p,TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(((Demo3dCmdContext *)p)->task),(void (*)(void *,void *))DEMO3D_DATA_MessageMain,0x28,1)),a,b,c,d,e,f,g);
}

void DEMO3D_DATA_MessageMain(struct TcblNode *task, struct Demo3dMessageContext *ctx)
{
    struct Demo3dMessageConfig *cfg = ctx->cfg;
    if (cfg->done != 0) {
        DEMO3D_DATA_DeleteMessageWindow((char *)ctx);
        TCBL_DeleteTask((struct TcblTask *)task);
        return;
    }
    switch (ctx->state) {
    case 0: {
        struct MsgBank *bank = MSGDATA_CreateFromArchive(0,2,(u16)ctx->file,cfg->alternate);
        void *desc;
        ctx->text = MSGDATA_AllocString(bank,ctx->index);
        GF_FONT_SetTextColor(1,2,15);
        ctx->printer = PRINTSYS_PrintStream((u32)ctx->desc,0,0,(u32)ctx->text,cfg->font,cfg->speed,cfg->task,0,cfg->heap,15);
        desc = ctx->desc;
        BMP_WIN_TransferChars(desc);
        BMP_WIN_MakeScreen(desc);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(desc));
        BMP_MENUWORK_DrawWindowEx(ctx->desc,1,ctx->base,0);
        MSGDATA_Delete((struct MsgBank *)bank);
        BG_SYS_SetPriority(1,0);
        BG_SYS_SetPriority(0,1);
        BG_SYS_SetPlaneVisible(1,1);
        ctx->state++;
        break;
    }
    case 1:
        if (ctx->count++ >= ctx->limit) {
            DEMO3D_DATA_DeleteMessageWindow((char *)ctx);
            TCBL_DeleteTask((struct TcblTask *)task);
        }
        break;
    }
}

void DEMO3D_DATA_CreateMessageWindow(char *p,Demo3dMessageWindowWork *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    MI_CpuFill8(out,0,0x28);
    out->a=a;out->c=c;out->ctx=p;out->b=b;
    out->text=BMP_MENUWORK_LoadFrameGfx((unsigned int)1,0,1,((Demo3dCmdContext *)p)->alternate);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,32,32,((Demo3dCmdContext *)p)->alternate);
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
    BMP_MENUWORK_FreeTileRun(1,*(int *)(p+0x18));MI_CpuFill8(p,0,0x28);
    BG_SYS_SetPriority(1,1);BG_SYS_SetPriority(0,0);BG_SYS_SetPlaneVisible(1,0);
}

void DEMO3D_DATA_TaskFade(char *p,int unused,int *record)
{
    int a,b,c;
    if(record[0]==0xFF || record[0]==GAME_VERSION_Code) {
        a=DEMO3D_DATA_ScaleTime(p,record[4]);b=DEMO3D_DATA_ScaleTime(p,record[5]);c=DEMO3D_DATA_ScaleTime(p,record[6]);
        DEMO3D_DATA_CreateFade(p,record[1],record[2],record[3],a,b,c);
    }
}

void DEMO3D_DATA_CreateFade(char *p,int a,int b,int c,int d,int e,int f)
{
    DEMO3D_DATA_CreateFadeWork(p,TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(((Demo3dCmdContext *)p)->task),(void (*)(void *,void *))DEMO3D_DATA_FadeMain,0x2C,1)),a,b,c,d,e,f);
}

/*
 * volatile: 0x04000052
 */
void DEMO3D_DATA_FadeMain(struct TcblNode *task,struct Demo3dFadeContext *ctx)
{
    struct Demo3dFadeConfig *cfg=ctx->cfg;
    float a;
    if(cfg->done != 0) {
        DEMO3D_DATA_DeleteFadeWork(ctx);
        TCBL_DeleteTask((struct TcblTask *)task);
        return;
    }
    switch(ctx->state) {
    case 0:
        ARC_UTIL_UploadPaletteFromHandleWhole(cfg->assets,ctx->first,0,0,0,cfg->alternate);
        ARC_UTIL_UploadBgPaletteAddFromHandle(cfg->assets,ctx->second,1,0,0,0,1,cfg->alternate);
        ctx->state++;
        break;
    case 1:
        ctx->count=0;
        ctx->blend=0;
        if(ctx->fadein>0) a=0.5f+(float)(ctx->fadein<<12);
        else a=(float)(ctx->fadein<<12)-0.5f;
        ctx->step=FX_Div(0x10000,(int)a);
        BG_SYS_SetPriority(1,0);
        BG_SYS_SetPriority(0,1);
        G2x_SetBlendAlpha_((unsigned int *)0x04000050,2,1,0,16);
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
        TCBL_DeleteTask((struct TcblTask *)task);
        break;
    }
}

void DEMO3D_DATA_CreateFadeWork(char *p,Demo3dFadeWindowWork *out,int a,int b,int c,int d,int e,int f)
{
    MI_CpuFill8(out,0,0x2C);
    out->ctx=p;out->c=d;out->a=a;out->d=c;out->b=b;out->e=e;out->f=f;
    ARC_UTIL_UploadBgCharFromHandle((void *)(((Demo3dCmdContext *)p)->assets),out->b,1,0,0,1,((Demo3dCmdContext *)p)->alternate);
}

void DEMO3D_DATA_DeleteFadeWork(void *p){unsigned z=0;memset(p,0,0x2c);BG_SYS_SetPlaneVisible(1,0);BG_SYS_SetPriority(0,0);BG_SYS_SetPriority(1,1);*(volatile unsigned short *)0x04000050=z;BG_SYS_FreeSlot(1);}

void DEMO3D_DATA_TaskCreateCapture(char *a, int unused, int *p)
{
    ((Demo3dCmdContext *)a)->extra = (int)DEMO3D_DATA_CreateCapture((void *)((Demo3dCmdContext *)a)->task, p[0], p[1]);
}

void DEMO3D_DATA_TaskDeleteCapture(char *a)
{
    DEMO3D_DATA_DeleteCapture(((Demo3dCmdContext *)a)->extra);
    ((Demo3dCmdContext *)a)->extra = 0;
}

int DEMO3D_DATA_ScaleTime(char *p, int v)
{
    struct Cam *cam = ((struct Ctx *)((Demo3dCmdContext *)p)->owner)->cam;
    int flag = cam->doubled;

    if (flag == 1)
        v *= 2;
    return v;
}
