/*
 * file:     demo3d.c
 * unit:     yes
 * function: DEMO3D_Init, DEMO3D_Exit, DEMO3D_Main, DEMO3D_StartWipe, DEMO3D_CheckSkip, DEMO3D_CreateContext, DEMO3D_DeleteContext, DEMO3D_UpdateContext, DEMO3D_SetupGx
 * address:  0x021BDA40
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   DEMO3D_GRAPHIC_Create 0x021BDDD8 thumb ov203
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   DEMO3D_ENGINE_Create 0x021BE160 thumb ov203
 *   DEMO3D_ENGINE_GetFrameNum 0x021BE62C thumb ov203
 *   DEMO3D_DATA_GetTextureSize 0x021BE948 thumb ov203
 *   ov067_id 0x00000043 data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   DEMO3D_ENGINE_Delete 0x021BE4B4 thumb ov203
 *   DEMO3D_GRAPHIC_Delete 0x021BDE98 thumb ov203
 *   DEMO3D_GRAPHIC_Draw 0x021BDF00 thumb ov203
 *   DEMO3D_ENGINE_Update 0x021BE538 thumb ov203
 *   DEMO3D_ENGINE_GetFrame 0x021BE620 thumb ov203
 *   DEMO3D_ENGINE_SetMode 0x021BE638 thumb ov203
 *   d_02FFFC3C 0x02FFFC3C data
 *   WIPE_SetMstBrightColor 0x02022268 thumb
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021C3CC0 0x021C3CC0 data a1
 *   d_021C3BC4 0x021C3BC4 data a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BFB7C 0x021BFB7C data a2
 *   BRIGHTNESS_ChangeReset  0x02023F98  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 */

typedef struct Demo3dArg {
    unsigned char pad0[4];
    void *data;
    int limit;
    unsigned char padC[4];
    int frame;
    int phase;
} Demo3dArg;

typedef struct Demo3dContext Demo3dContext;
typedef struct Demo3dMethods { void (*init)(struct Demo3dContext *); void (*update)(struct Demo3dContext *); void (*destroy)(struct Demo3dContext *); } Demo3dMethods;

typedef struct Demo3dWork {
    unsigned short heapId;
    unsigned short pad;
    Demo3dArg *arg;
    int state;
    void *view;
    void *str;
    void *msg;
    void *model;
    struct Demo3dContext *ctx;
    int prevTime;
    int deltaTime;
    int totalTime;
} Demo3dWork;

struct Demo3dContext { unsigned short heapId, pad; void *view, *model; const Demo3dMethods *methods; void *work; int mode; };

#define DISP3DCNT (*(volatile unsigned short *)0x04000060)
struct ProcOwner;
struct MsgBank;
struct Cfg;
struct Ctx;
struct PrintSys;
struct Rec;
struct Proc;
#include "../types.h"

#include "../sdk_gx.h"

extern int GF_OVERLAY_Load(int);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, unsigned int size, unsigned int heapId);
extern void MI_CpuFill8(void *, int, unsigned);
extern void *DEMO3D_GRAPHIC_Create(unsigned, void *, unsigned);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct PrintQueue;
extern struct PrintQueue *PRINTSYS_QUE_Create(unsigned int heap);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern struct Ctx *DEMO3D_ENGINE_Create(void *owner, struct Cfg *cfg, u16 heap);
extern u32 DEMO3D_ENGINE_GetFrameNum(char *p);
extern void DEMO3D_DATA_GetTextureSize(void *, int, u8 *, u8 *);
extern void BRIGHTNESS_ChangeReset(u32 mask);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void PRINTSYS_QUE_Delete(struct PrintQueue *queue);
extern void DEMO3D_ENGINE_Delete(char *ctx);
struct Demo3dGraphic;
extern void DEMO3D_GRAPHIC_Delete(struct Demo3dGraphic *ctx);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void GF_OVERLAY_Unload(int);
extern u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);
extern void DEMO3D_GRAPHIC_Draw(struct Demo3dGraphic *p);
extern int DEMO3D_ENGINE_Update(const struct Demo3dContext *ctx, u32 frames);
extern int DEMO3D_ENGINE_GetFrame(char *p);
extern void DEMO3D_ENGINE_SetMode(char *p, int a);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SetMstBrightColor(unsigned);
extern int FADE_GetSpeed(void);
extern void WIPE_SYS_Start(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern unsigned KEY_GetTrg(void);
extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_EnableBg0WithPriority(unsigned);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, int);
struct G3dLight;
extern void G3D_SYSTEM_SetLight(unsigned int lightIdx, struct G3dLight *light);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
int DEMO3D_Init(void *manager, int unused, Demo3dArg *p);
int DEMO3D_Exit(void *a, void *b, void *c, Demo3dWork *work);
int DEMO3D_Main(void *unused, int *state, void *c, Demo3dWork *work);
int DEMO3D_StartWipe(void *ctx, unsigned mode, unsigned heap);
int DEMO3D_CheckSkip(Demo3dWork *p);
Demo3dContext *DEMO3D_CreateContext(int mode, void *a, void *b, unsigned heap);
void DEMO3D_DeleteContext(Demo3dContext *a);
void DEMO3D_UpdateContext(Demo3dContext *a);
void DEMO3D_SetupGx(void);
extern const char ov067_id[];
extern unsigned int d_02FFFC3C;
extern const char d_021C3CC0[];
extern const Demo3dMethods d_021C3BC4;
extern const unsigned short d_021BFB7C[][4];

int DEMO3D_Init(void *manager, int unused, Demo3dArg *p)
{
    Demo3dWork *w;
    u8 width, height;
    int delta;
    unsigned one = 1;
    unsigned heap = 0x6c;
    GF_OVERLAY_Load((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x6c, 0x130000);
    w = PROCSYS_AllocProcWork(manager, sizeof(Demo3dWork), 0x6c);
    MI_CpuFill8(w, 0, sizeof(Demo3dWork));
    w->heapId = heap;
    w->arg = p;
    w->view = DEMO3D_GRAPHIC_Create(1, p->data, w->heapId);
    w->msg = MSGDATA_CreateFromArchive(0, 2, 0x41, w->heapId);
    w->str = (void *)PRINTSYS_QUE_Create((unsigned int)w->heapId);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(3, 0);
    BG_SYS_SetPlaneVisible(2, 0);
    BG_SYS_SetPlaneVisible(1, 0);
    BG_SYS_SetMainPlaneVisible(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    w->model = DEMO3D_ENGINE_Create(w->view, (struct Cfg *)p, w->heapId);
    w->ctx = DEMO3D_CreateContext(*(int *)&p->data, w->view, w->model, w->heapId);
    delta = DEMO3D_ENGINE_GetFrameNum(w->model) - p->limit;
    DEMO3D_DATA_GetTextureSize(p->data, 0, &width, &height);
    if (delta > height) DEMO3D_StartWipe((void *)(u8)*(unsigned *)&p->data, one, w->heapId);
    return 1;
}

int DEMO3D_Exit(void *a, void *b, void *c, Demo3dWork *work)
{
    BRIGHTNESS_ChangeReset(3);
    DEMO3D_DeleteContext(work->ctx);
    MSGDATA_Delete(work->msg);
    PRINTSYS_QUE_Delete(work->str);
    DEMO3D_ENGINE_Delete(work->model);
    DEMO3D_GRAPHIC_Delete(work->view);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x6c);
    GF_OVERLAY_Unload((int)ov067_id);
    return 1;
}

int DEMO3D_Main(void *unused, int *state, void *c, Demo3dWork *work)
{
    int result;
    unsigned int now, delta;
    DEMO3D_UpdateContext(work->ctx);
    PRINTSYS_QUE_Main(work->str);
    DEMO3D_GRAPHIC_Draw((struct Demo3dGraphic *)(*(unsigned char * *)&work->view));
    result = DEMO3D_ENGINE_Update(work->model, work->deltaTime);
    now = d_02FFFC3C;
    delta = now - work->prevTime;
    work->deltaTime = 0;
    if (work->prevTime != 0 && delta > 1)
        work->deltaTime = delta - 1;
    work->prevTime = now;
    work->totalTime = work->totalTime + work->deltaTime;
    switch (*state) {
    case 0:
        if (DEMO3D_CheckSkip(work) != 0 || result != 0) {
            work->arg->frame = DEMO3D_ENGINE_GetFrame(work->model) >> 12;
            work->arg->phase = result + 1;
            DEMO3D_ENGINE_SetMode(work->model, work->arg->phase);
            (*state)++;
        }
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            if (DEMO3D_StartWipe((void *)(unsigned char)*(unsigned *)&work->arg->data, 0, work->heapId))
                return 1;
            (*state)++;
        }
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    return 0;
}

int DEMO3D_StartWipe(void *ctx, unsigned mode, unsigned heap)
{
    unsigned char width, height;
    unsigned char factor;
    int color;
    DEMO3D_DATA_GetTextureSize(ctx, (unsigned char)(mode == 0), &width, &height);
    color = 0;
    if (width) color = 32767;
    WIPE_SetMstBrightColor(color);
    if (height) {
        factor = FADE_GetSpeed();
        WIPE_SYS_Start(0, mode, mode, color, height * factor, 1, heap);
        return 0;
    }
    return 1;
}

int DEMO3D_CheckSkip(Demo3dWork *p){if(p->arg->phase!=0||!WIPE_SYS_EndCheck())return 0;if(p->ctx->mode!=0){if(KEY_GetTrg()&0xcf3)return 1;}return 0;}

Demo3dContext *DEMO3D_CreateContext(int mode, void *a, void *b, unsigned heap)
{
    Demo3dContext *ctx;
    ctx = GFL_HEAP_Alloc(heap, 24, 1, d_021C3CC0, 0x1e1);
    ctx->view = a;
    ctx->model = b;
    ctx->heapId = heap;
    ctx->methods = 0;
    ctx->mode = 0;
    if (mode == 1) {
        ctx->methods = &d_021C3BC4;
        ctx->mode = 1;
    }
    if (ctx->methods) ctx->methods->init(ctx);
    return ctx;
}

void DEMO3D_DeleteContext(Demo3dContext *a)
{
    if (a->methods)
        a->methods->destroy(a);
    GFL_HEAP_Free(a);
}

void DEMO3D_UpdateContext(Demo3dContext *a)
{
    if (a->methods)
        a->methods->update(a);
}

static inline void G3X_SetShading(GXShading shading) { DISP3DCNT = (unsigned short)((DISP3DCNT & ~0x3002) | (shading << 1)); }

static inline void G3X_AntiAlias(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 16); else DISP3DCNT &= (unsigned short)~0x3010; }

static inline void G3X_AlphaTest(int enable, int ref) { if (enable) { DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 4); *(volatile unsigned short *)0x04000340 = ref; } else DISP3DCNT &= (unsigned short)~0x3004; }

static inline void G3X_AlphaBlend(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 8); else DISP3DCNT &= (unsigned short)~0x3008; }

static inline void G3X_EdgeMarking(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 32); else DISP3DCNT &= (unsigned short)~0x3020; }

void DEMO3D_SetupGx(void)
{
    unsigned i = 0;
    BG_SYS_EnableBg0WithPriority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 32767, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, (struct G3dLight *)d_021BFB7C[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}
