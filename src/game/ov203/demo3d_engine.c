/*
 * file:     demo3d_engine.c
 * unit:     yes
 * function: DEMO3D_ENGINE_Create, DEMO3D_ENGINE_Delete, DEMO3D_ENGINE_SetClipPlanes, DEMO3D_ENGINE_Update, DEMO3D_ENGINE_GetFrame, DEMO3D_ENGINE_GetFrameNum, DEMO3D_ENGINE_SetMode, DEMO3D_ENGINE_SetupLighting, DEMO3D_ENGINE_ClampDemoId, DEMO3D_ENGINE_GetCameraRecord, DEMO3D_ENGINE_CreateAnimeStream, DEMO3D_ENGINE_GetAnimeKind
 * address:  0x021BE160
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
 *   GFL_HEAP_Free 0x020307B0 arm
 *   TIMEZONE_GetTimeZoneOfHour 0x020113F0 thumb
 *   FX_Div 0x0207C768 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_GetNearClipAlt 0x02048B9C arm
 *   G3D_CAMERA_GetFarClipAlt 0x02048BB0 arm
 *   DOUBLE3DDISP_Init 0x0204E8C0 arm
 *   GFL_USE_SetVBlankHook 0x02005654 thumb
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   ICA_ANIME_SetFrame 0x020115EC thumb
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   DEMO3D_CMDSYS_Create 0x021BF7C0 thumb ov203
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021C3CE0 0x021C3CE0 data a1
 *   d_021BFCE0 0x021BFCE0 data a4
 *   d_021BFCD4 0x021BFCD4 data a4
 *   d_021BFCEC 0x021BFCEC data a4
 *   DEMO3D_CMDSYS_Delete 0x021BF810 thumb ov203
 *   GFL_USE_ClearVBlankHook 0x0200566C thumb
 *   DOUBLE3DDISP_Exit 0x0204EA0C arm
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   DOUBLE3DDISP_GetMode 0x0204EA38 arm
 *   G3D_CAMERA_SetNearClipAlt 0x02048BA8 arm
 *   G3D_CAMERA_SetFarClipAlt 0x02048BBC arm
 *   ICA_ANIME_GetFrame 0x0201160C thumb
 *   DEMO3D_CMDSYS_Update 0x021BF858 thumb
 *   ICA_ANIME_IncFrameNoLoop 0x020115C0 thumb
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   DOUBLE3DDISP_SetDrawDone 0x0204EA4C arm
 *   ICA_ANIME_GetFrameNum 0x02011608 thumb
 *   ZONEDATA_GetTimeLightColors 0x0201493C thumb
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetFogTable 0x0207DD10 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3X_SetDisp1DotDepth 0x0207DE88 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021C185C  0x021C185C  data
 *   d_021C186C 0x021C186C data a4
 *   ICA_ANIME_CreateStream  0x02011510  thumb  arm9
 *   DEMO3D_ENGINE_ClampDemoId  0x021BE79C  thumb  ov203
 *   DEMO3D_GRAPHIC_UpdateLookAt 0x021BDF18 thumb ov203
 *   DEMO3D_GRAPHIC_EndDraw 0x021BDF24 thumb ov203
 *   DEMO3D_GRAPHIC_SetupLightBlock 0x021BDF3C thumb ov203
 *   DEMO3D_GRAPHIC_DeleteDouble3d 0x021BE150 thumb ov203
 *   DEMO3D_GRAPHIC_DeleteCamera 0x021BE158 thumb ov203
 *   DEMO3D_DATA_Create 0x021BE7F0 thumb ov203
 *   DEMO3D_DATA_Delete 0x021BE85C thumb ov203
 *   DEMO3D_DATA_BuildTable 0x021BE874 thumb ov203
 *   DEMO3D_DATA_GetTimeStep 0x021BE920 thumb ov203
 *   DEMO3D_DATA_IsDouble3dDisplay 0x021BE938 thumb ov203
 */
#include "demo3d_graphic_shared_types.h"
#include "demo3d_engine_shared_types.h"

#define DISP (*(volatile u16 *)0x04000060)

struct Config;

struct G3dSys;

struct Light;

struct Record;

struct IcaAnime;

struct AnmCtl;

struct Ctx;

struct Arg;

struct Config { u8 pad[0xd],hour,minute; u8 second:7,spare:1; };

typedef short s16;

typedef long long s64;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef signed int     s32;

typedef int BOOL;

typedef enum { FOG_BLEND_0,FOG_BLEND_1 } GXFogBlend;

typedef enum { FOG_SLOPE_0,FOG_SLOPE_10=10 } GXFogSlope;

struct Record {
    u16 reserved00,reserved02,id;
    u16 b0:1,b1:1,blend:1,anti:1,fog:1,edge:1,mode1:1,mode2:1,test:1,ref:5,padbits:2;
    u8 pad08[0x1c];
    int depthoffset;
    u16 clear,alpha;
    u16 polygon:15,polybit:1;
    u16 depth,fogcolor;
    u8 fogalpha,slope;
    u16 offset:15,mode:1;
    u8 fogtable[8];
    u16 edgecolors[8];
};

extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);

extern u32 GFL_HEAP_Free(void *p);

extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);

extern fx32 FX_Div(fx32, fx32);

extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, VecFx32 *, VecFx32 *, VecFx32 *, int);
struct G3dCamera;

extern void G3D_CAMERA_GetNearClipAlt(struct G3dCamera *camera, unsigned int *out);

extern void G3D_CAMERA_GetFarClipAlt(struct G3dCamera *camera, unsigned int *out);

extern void DOUBLE3DDISP_Init(u32);

extern int GFL_USE_SetVBlankHook(int a, int b);

extern void MTX_Identity33_(void *);

extern void ICA_ANIME_SetFrame(struct IcaAnime *p, signed int v);

extern u32 G3D_UTIL_Create(u16, u16, u32);

extern u16 G3D_UTIL_AddUnit(u32, void *);
struct G3dObject;


extern unsigned short G3D_SYSTEM_GetObjectAnimeCount(struct G3dObject *obj);

extern int G3D_SYSTEM_EnableObjectAnime(struct G3dObject *obj, unsigned int anmIdx);

extern int G3D_SYSTEM_SetObjectAnimeFrame(struct G3dObject *obj, unsigned short anmIdx, int *frame);
struct Demo3dCmdContext;

extern struct Demo3dCmdContext *DEMO3D_CMDSYS_Create(char *owner, unsigned int heap);

extern void DEMO3D_CMDSYS_Delete(char *p);

extern void GFL_USE_ClearVBlankHook(void);

extern int DOUBLE3DDISP_Exit(void);

extern void ICA_ANIME_Delete(struct IcaAnime *p);

extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

extern void G3D_UTIL_Delete(struct Rec *p);

extern u32 DOUBLE3DDISP_GetMode(void);

extern void G3D_CAMERA_SetNearClipAlt(struct G3dCamera *camera, unsigned int v);

extern void G3D_CAMERA_SetFarClipAlt(struct G3dCamera *camera, unsigned int v);

extern u32 ICA_ANIME_GetFrame(struct IcaAnime *p);

extern void DEMO3D_CMDSYS_Update(struct Demo3dCmdContext *p, int time, int flag);

extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *,int);

extern void ICA_ANIME_SetCameraStatus(void *camera, struct IcaAnime *anime);

extern u32 G3D_UTIL_GetObject(u8 *,int);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(struct G3dObject *obj, int anmIdx, int step);

extern void G3D_CAMERA_Reset(struct G3dCamera *camera);
struct G3dObjectStatus;

extern void G3D_SYSTEM_DrawObject(struct G3dObject *obj, struct G3dObjectStatus *status);

extern void DOUBLE3DDISP_SetDrawDone(void);

extern u32 ICA_ANIME_GetFrameNum(struct IcaAnime *p);

extern void ZONEDATA_GetTimeLightColors(u32,u32,u32,u32,u32,u16 *,u16);

extern void G3X_SetEdgeColorTable(void *src);

extern void G3X_SetFog(BOOL,GXFogBlend,GXFogSlope,int);

extern void G3X_SetFogTable(void *src);

extern void G3X_SetClearColor(u16,int,int,int,BOOL);

extern void G3X_SetDisp1DotDepth(int);

extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);

extern struct IcaAnime *ICA_ANIME_CreateStream(u32 heap, u32 arcId, u32 dataId, u32 bufFrameNum);

void DEMO3D_GRAPHIC_UpdateLookAt(Demo3dGraphic *p);

void DEMO3D_GRAPHIC_EndDraw(Demo3dGraphic *p);

void DEMO3D_GRAPHIC_SetupLightBlock(Demo3dGraphic *graphic, unsigned short *colors, int unused);

void DEMO3D_GRAPHIC_DeleteDouble3d(void);

void DEMO3D_GRAPHIC_DeleteCamera(void *p);

struct Ctx *DEMO3D_ENGINE_Create(void *owner, struct Cfg *cfg, u16 heap);

void DEMO3D_ENGINE_Delete(struct Ctx *ctx);

void DEMO3D_ENGINE_SetClipPlanes(struct Ctx *p, struct Light *q);

int DEMO3D_ENGINE_Update(const struct Ctx *ctx, u32 frames);

int DEMO3D_ENGINE_GetFrame(struct Ctx *p);

u32 DEMO3D_ENGINE_GetFrameNum(struct Ctx *p);

void DEMO3D_ENGINE_SetMode(struct Ctx *p,int a);

void DEMO3D_ENGINE_SetupLighting(struct Ctx *ctx,struct Config *cfg,const struct Record *record,u16 heap);

unsigned DEMO3D_ENGINE_ClampDemoId(unsigned x);

u32 DEMO3D_ENGINE_GetCameraRecord(u32 id);

void *DEMO3D_ENGINE_CreateAnimeStream(u32 a, u32 b, u32 c);

u8 DEMO3D_ENGINE_GetAnimeKind(unsigned x);

void *DEMO3D_DATA_Create(unsigned heap);

void DEMO3D_DATA_Delete(char *a);

void DEMO3D_DATA_BuildTable(char *ctx, const char *config, u8 type);

u32 DEMO3D_DATA_GetTimeStep(u32 a);

int DEMO3D_DATA_IsDouble3dDisplay(void *a);

extern const char d_021C3CE0[];

extern const s16 FX_SinCosTable_[];

extern VecFx32 d_021BFCE0;

extern VecFx32 d_021BFCD4;

extern VecFx32 d_021BFCEC;

extern u8 d_021C185C[];

extern char d_021C186C[];

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

/*
 * 2026-10-05 (integrator): the angle divisor is the plain literal 360 and the alloc size the literal 0x88; mwcc derives 0x168 from the live 0x88 itself (`adds r7,#0xE0`), so the earlier `sz` local was not needed. EXACT in c99 and c.
 * note: 2026-10-05 wave P2 lane Q3 (pengy share, user-approved). Levers: heap is a u16
 *   parameter (entry spill of r2 first, raw reload at every use); cam written as
 *   `cam = ctx->f74 = DEMO3D_ENGINE_GetCameraRecord(...)` (store to ctx first, then the local slot sp+0x24);
 *   cnt is a signed int (ble guard); ortho bounds as in ov088 021B9C2C (FX_Mul/FX_Div,
 *   top = FX_Div(t, c), bottom = -FX_Div(t, c)). The angle divisor is written sz + 0xE0:
 *   the original keeps 0x88 live in r7 (alloc size) and derives 0x168 from it with
 *   adds #0xE0; flagged for the integrator as an odd but listing-forced form.
 */
struct Ctx *DEMO3D_ENGINE_Create(void *owner, struct Cfg *cfg, u16 heap)
{
    struct Ctx *ctx;

    int ang, right, d, w, top, t, s, j, near, mid, far, bottom;
    struct Cam *cam;
    int c, q;
    int i, k, n;
    float r;
    int left;
    int cnt;
    void *e;
    u32 h;

    ctx = GFL_HEAP_Alloc(heap, 0x88, 1, d_021C3CE0, 0x79);
    ctx->graphic = owner;
    ctx->id = cfg->f4;
    ctx->data.id = ctx->id;
    ctx->data.color = cfg->fc;
    ctx->data.frame = cfg->f8;
    ctx->data.timeZone = TIMEZONE_GetTimeZoneOfHour((u8)cfg->sec, (u8)cfg->fd);
    ctx->data.flag = cfg->bit7;
    ctx->data.mode = cfg->fd;
    ctx->data.extra = cfg->fe;
    ctx->data.sec = cfg->sec;
    cam = ctx->cam = (struct Cam *)DEMO3D_ENGINE_GetCameraRecord(ctx->id);
    q = (((cam->fc >> 12) / 2) << 16) / 360;
    c = FX_SinCosTable_[(q >> 4) * 2 + 1];
    far = cam->f1c;
    mid = cam->f18;
    near = cam->f14;
    q = (((cam->f8 >> 12) / 2) << 16) / 360;
    s = FX_SinCosTable_[(q >> 4) * 2];
    t = FX_Mul(near, s);
    top = FX_Div(t, c);
    bottom = -FX_Div(t, c);
    w = FX_Mul(near, 0x1555);
    d = 0x1000;
    right = FX_Div(FX_Mul(FX_Div(w, d), s), c);
    left = -FX_Div(FX_Mul(FX_Div(w, d), s), c);
    ctx->light = G3D_CAMERA_Create(1, top, bottom, left, right, near, mid, far,
                             &d_021BFCE0, &d_021BFCD4, &d_021BFCEC, heap);
    G3D_CAMERA_GetNearClipAlt(ctx->light, &ctx->nearClip);
    G3D_CAMERA_GetFarClipAlt(ctx->light, &ctx->farClip);
    DEMO3D_ENGINE_SetupLighting(ctx, (struct Config *)cfg, (const struct Record *)ctx->cam, heap);
    ctx->step = DEMO3D_DATA_GetTimeStep(ctx->id);
    ctx->animeOn = DEMO3D_DATA_IsDouble3dDisplay((void *)ctx->id);
    if (ctx->animeOn) {
        DOUBLE3DDISP_Init(heap);
        GFL_USE_SetVBlankHook((int)DEMO3D_GRAPHIC_DeleteDouble3d, 0);
    }
    ctx->scale[0] = 0;
    ctx->scale[1] = 0;
    ctx->scale[2] = 0;
    ctx->scale[3] = 0x1000;
    ctx->scale[4] = 0x1000;
    ctx->scale[5] = 0x1000;
    MTX_Identity33_(ctx->matrix);
    ctx->count = DEMO3D_ENGINE_GetAnimeKind(ctx->id);
    ctx->indices = GFL_HEAP_Alloc(heap, ctx->count * 2, 1, d_021C3CE0, 0xB7);
    ctx->anime = DEMO3D_ENGINE_CreateAnimeStream(ctx->id, heap, 10);
    if (ctx->data.frame)
        r = (0.5f + (float)(ctx->data.frame << 12));
    else
        r = ((float)(ctx->data.frame << 12) - 0.5f);
    ICA_ANIME_SetFrame(ctx->anime, (int)r);
    n = ctx->count * 6;
    ctx->table = G3D_UTIL_Create((u16)n, (u16)n, heap);
    e = DEMO3D_DATA_Create(heap);
    for (i = 0; i < ctx->count; i++) {
        DEMO3D_DATA_BuildTable(e, (const char *)(&ctx->data), i);
        ctx->indices[i] = G3D_UTIL_AddUnit(ctx->table, e);
    }
    DEMO3D_DATA_Delete(e);
    for (j = 0; j < ctx->count; j++) {
        h = G3D_UTIL_GetObject((u8 *)ctx->table, (u16)ctx->indices[j]);
        cnt = G3D_SYSTEM_GetObjectAnimeCount((struct G3dObject *)h);
        for (k = 0; k < cnt; k++) {
            if (ctx->data.frame)
                r = (0.5f + (float)(ctx->data.frame << 12));
            else
                r = ((float)(ctx->data.frame << 12) - 0.5f);
            ang = (int)r;
            G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)h, (u16)k);
            G3D_SYSTEM_SetObjectAnimeFrame((struct G3dObject *)h, k, &ang);
        }
    }
    ctx->cmdSys = (unsigned int)DEMO3D_CMDSYS_Create((char *)ctx, (unsigned int)heap);
    return ctx;
}

void DEMO3D_ENGINE_Delete(struct Ctx *ctx)
{
    unsigned i;
    DEMO3D_CMDSYS_Delete((char *)ctx->cmdSys);
    DEMO3D_GRAPHIC_DeleteCamera(ctx->light);
    if (ctx->animeOn) {
        GFL_USE_ClearVBlankHook();
        DOUBLE3DDISP_Exit();
    }
    ICA_ANIME_Delete(ctx->anime);
    for (i = 0; i < ctx->count; i++) {
        G3D_UTIL_RemoveUnit((struct Ctx *)ctx->table, ctx->indices[i]);
    }
    G3D_UTIL_Delete((struct Rec *)ctx->table);
    GFL_HEAP_Free(ctx->indices);
    GFL_HEAP_Free(ctx);
}

/*
 * extent: 46-byte body plus two-byte alignment at 0x021BE536.
 * blocked: ARM9 0x02048BA8 and 0x02048BBC; existing matched unit_02048AD0.c contains their bodies but omits both from function:.
 * spelling: loads repeated in explicit branch arms reproduce cmp-before-base-load; shared-base and offset ternary differ.
 *   0x02048BA8 ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void G3D_CAMERA_SetNearClipAlt(struct Light *p,u32 v) { *(u32 *)((char *)p+4)=v; }
 *   0x02048BBC ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void G3D_CAMERA_SetFarClipAlt(struct Light *p,u32 v) { *(u32 *)((char *)p+8)=v; }
 */
void DEMO3D_ENGINE_SetClipPlanes(struct Ctx *p,struct Light *q)
{
    int x;
    if(DOUBLE3DDISP_GetMode()==0)x=*(short *)((char *)p->cam+0x20);
    else x=*(short *)((char *)p->cam+0x22);
    G3D_CAMERA_SetNearClipAlt((struct G3dCamera *)q,x+p->nearClip);
    G3D_CAMERA_SetFarClipAlt((struct G3dCamera *)q,x+p->farClip);
}

int DEMO3D_ENGINE_Update(const struct Ctx *ctx, u32 frames)
{
    u32 done;
    long advance = 0;
    unsigned long time = ICA_ANIME_GetFrame(ctx->anime);
    u32 i;
    for(i=0;i<frames+1;i++) {
        if(ctx->cmdMode == 0) DEMO3D_CMDSYS_Update((void *)ctx->cmdSys,time+advance,i);
        else DEMO3D_CMDSYS_Update((void *)ctx->cmdSys,-4096,i);
        advance += ctx->step;
    }
    done = ICA_ANIME_IncFrameNoLoop(ctx->anime,advance);
    ICA_ANIME_SetCameraStatus(ctx->light,ctx->anime);
    for(i=0;i<ctx->count;i++) {
        void *obj=(void *)G3D_UTIL_GetObject((u8 *)ctx->table,ctx->indices[i]);
        int j, count=G3D_SYSTEM_GetObjectAnimeCount(obj);
        for(j=0;j<count;j++) G3D_SYSTEM_LoopObjectAnimeFrame(obj,(u16)j,advance);
    }
    if(ctx->animeOn != 0) DEMO3D_ENGINE_SetClipPlanes((struct Ctx *)ctx,ctx->light);
    G3D_CAMERA_Reset(ctx->light);
    DEMO3D_GRAPHIC_UpdateLookAt((Demo3dGraphic *)ctx->graphic);
    for(i=0;i<ctx->count;i++) {
        G3D_SYSTEM_DrawObject((void *)G3D_UTIL_GetObject((u8 *)ctx->table,ctx->indices[i]),(struct G3dObjectStatus *)ctx->scale);
    }
    DEMO3D_GRAPHIC_EndDraw((Demo3dGraphic *)ctx->graphic);
    if(ctx->animeOn != 0) DOUBLE3DDISP_SetDrawDone();
    return done;
}

int DEMO3D_ENGINE_GetFrame(struct Ctx *p) { return ICA_ANIME_GetFrame(p->anime); }

u32 DEMO3D_ENGINE_GetFrameNum(struct Ctx *p) { return ICA_ANIME_GetFrameNum(p->anime); }

void DEMO3D_ENGINE_SetMode(struct Ctx *p,int a) { p->cmdMode=a; }

static inline void Anti(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|16);
    else DISP &= (u16)~0x3010;
}

static inline void Test(BOOL enable,int ref) {
    if(enable) { DISP=(u16)((DISP & ~0x3000)|4); *(volatile u16 *)0x04000340=(u16)ref; }
    else DISP &= (u16)~0x3004;
}

static inline void Blend(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|8);
    else DISP &= (u16)~0x3008;
}

static inline void Edge(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|32);
    else DISP &= (u16)~0x3020;
}

/*
 * The original reserves 20 bytes for colors at sp+0x2c and 32 for fogtable
 * at sp+0x0c. Keeping cfg mutable moves the colors address before record's
 * parameter copy; const record preserves the later clear-color loads.
 * volatile: 0x04000060, 0x04000340, 0x04000358
 */
void DEMO3D_ENGINE_SetupLighting(struct Ctx *ctx,struct Config *cfg,const struct Record *record,u16 heap)
{
    u16 colors[10];
    u32 fogtable[8];
    u32 i;
    ZONEDATA_GetTimeLightColors(record->id,cfg->hour,cfg->minute,0,cfg->second,colors,heap);
    DEMO3D_GRAPHIC_SetupLightBlock((Demo3dGraphic *)ctx->graphic,colors,0);
    Anti(record->anti);
    Test(record->test,((struct Record *)ctx->cam)->ref);
    Blend(record->blend);
    Edge(record->edge);
    if(record->edge) G3X_SetEdgeColorTable((void *)record->edgecolors);
    G3X_SetFog(record->fog,(GXFogBlend)record->mode,(GXFogSlope)record->slope,record->offset);
    if(record->fog) {
        *(volatile u32 *)0x04000358=record->fogcolor|(record->fogalpha<<16);
        for(i=0;i<8;i++) fogtable[i]=record->fogtable[i];
        G3X_SetFogTable(fogtable);
    }
    G3X_SetClearColor(record->clear,record->alpha,record->depth,record->polygon,record->fog);
    G3X_SetDisp1DotDepth(record->depthoffset);
    G3D_SYSTEM_SetSwapBuffersMode(record->mode1,record->mode2);
}

unsigned DEMO3D_ENGINE_ClampDemoId(unsigned x) { if(x==0||x>=19)x=0;return x; }

u32 DEMO3D_ENGINE_GetCameraRecord(u32 id)
{
    return *(u32 *)(d_021C185C + DEMO3D_ENGINE_ClampDemoId(id) * 0x14);
}

void *DEMO3D_ENGINE_CreateAnimeStream(u32 a, u32 b, u32 c)
{
    u16 *t = (u16 *)DEMO3D_ENGINE_GetCameraRecord(a);

    return ICA_ANIME_CreateStream(b, 0xa0, *t, c);
}

u8 DEMO3D_ENGINE_GetAnimeKind(unsigned x) { return *(u32 *)(d_021C186C+DEMO3D_ENGINE_ClampDemoId(x)*20); }
