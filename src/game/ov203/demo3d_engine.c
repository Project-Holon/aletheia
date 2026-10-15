/*
 * file:     demo3d_engine.c
 * unit:     yes
 * function: func_021BE160, func_021BE4B4, func_021BE508, func_021BE538, func_021BE620, func_021BE62C, func_021BE638, func_021BE63C, func_021BE79C, func_021BE7A8, func_021BE7BC, func_021BE7D8
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
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   TIMEZONE_GetTimeZoneOfHour 0x020113F0 thumb
 *   FX_Div 0x0207C768 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_GetNearClipAlt 0x02048B9C arm
 *   G3D_CAMERA_GetFarClipAlt 0x02048BB0 arm
 *   DOUBLE3DDISP_Init 0x0204E8C0 arm
 *   func_02005654 0x02005654 thumb
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   ICA_ANIME_SetFrame 0x020115EC thumb
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
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
 *   func_0200566C 0x0200566C thumb
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
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   DOUBLE3DDISP_SetDrawDone 0x0204EA4C arm
 *   ICA_ANIME_GetFrameNum 0x02011608 thumb
 *   ZONEDATA_GetTimeLightColors 0x0201493C thumb
 *   func_0207DCF8 0x0207DCF8 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetFogTable 0x0207DD10 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3X_SetDisp1DotDepth 0x0207DE88 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021C185C  0x021C185C  data
 *   d_021C186C 0x021C186C data a4
 *   ICA_ANIME_CreateStream  0x02011510  thumb  arm9
 *   func_021BE79C  0x021BE79C  thumb  ov203
 *   func_021BDF18 0x021BDF18 thumb ov203
 *   func_021BDF24 0x021BDF24 thumb ov203
 *   func_021BDF3C 0x021BDF3C thumb ov203
 *   func_021BE150 0x021BE150 thumb ov203
 *   func_021BE158 0x021BE158 thumb ov203
 *   func_021BE7F0 0x021BE7F0 thumb ov203
 *   func_021BE85C 0x021BE85C thumb ov203
 *   func_021BE874 0x021BE874 thumb ov203
 *   func_021BE920 0x021BE920 thumb ov203
 *   func_021BE938 0x021BE938 thumb ov203
 */
#include "../../matched/include/Obj03354.h"
#include "../../matched/include/Obj25315.h"
#include "../../matched/include/Obj25316.h"
#include "../../matched/include/Obj25317.h"
#include "demo3d_graphic_shared_types.h"
#include "demo3d_engine_shared_types.h"

#define DISP (*(volatile u16 *)0x04000060)

struct Config;

struct Context;

struct G3dSys;

struct Light;

struct Record;

struct IcaAnime;

struct AnmCtl;

struct Ctx;

struct Arg;

struct Obj11245;

struct Obj11244;

struct Config { u8 pad[0xd],hour,minute; u8 second:7,spare:1; };

typedef short s16_021BE13C;

typedef long long s64;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

struct Cam {
    u8 pad0[8];
    fx32 f8, fc, f10, f14, f18, f1c;
};

struct Ctx {
    u32 owner, id, f8, fc, f10, f14; void *f18; u32 f1c;
    void *f20;
    u32 f24, f28, f2c;
    u32 z30[6];
    u8 mtx[0x24];
    u32 f6c;
    u16 *f70;
    struct Cam *f74;
    u32 f78, f7c;
    u8 b80, b81, b82, b83, b84, b85;
};

typedef signed int     s32;

struct Context { void *owner; u32 a4,a8,ac,a10,step; struct IcaAnime *anime; u8 *table; void *light; u32 a24,a28,count; u8 args[0x3c]; void *events; u16 *indices; struct Record *record; };

typedef int BOOL;

typedef enum { FOG_BLEND_0,FOG_BLEND_1 } GXFogBlend;

typedef enum { FOG_SLOPE_0,FOG_SLOPE_10=10 } GXFogSlope;

struct Record {
    u16 a0,a2,id;
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

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);

extern u32 func_020307B0(void *p);

extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);

extern fx32 FX_Div(fx32, fx32);

extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, VecFx32 *, VecFx32 *, VecFx32 *, int);

extern void G3D_CAMERA_GetNearClipAlt(struct Light *l, u32 *out);

extern void G3D_CAMERA_GetFarClipAlt(struct Light *l, u32 *out);

extern void DOUBLE3DDISP_Init(u32);

extern int func_02005654(int a, int b);

extern void MTX_Identity33_(void *);

extern int _ffltu(u32);

extern int _fadd(int, int);

extern int _fsub(int, int);

extern int _ffix(int);

extern void ICA_ANIME_SetFrame(struct IcaAnime *p, signed int v);

extern u32 G3D_UTIL_Create(u16, u16, u32);

extern u16 G3D_UTIL_AddUnit(u32, void *);

extern u32 func_02048A18(u8 *a0, int i);

extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);

extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

extern u32 DEMO3D_CMDSYS_Create(struct Ctx *, u32);

extern void DEMO3D_CMDSYS_Delete(char *p);

extern void func_0200566C(void);

extern int DOUBLE3DDISP_Exit(void);

extern void ICA_ANIME_Delete(struct IcaAnime *p);

extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

extern void G3D_UTIL_Delete(struct Rec *p);

extern u32 DOUBLE3DDISP_GetMode(void);

extern void G3D_CAMERA_SetNearClipAlt(struct Light *,u32);

extern void G3D_CAMERA_SetFarClipAlt(struct Light *,u32);

extern u32 ICA_ANIME_GetFrame(struct Obj11245 *p);

extern void DEMO3D_CMDSYS_Update(void *,int,int);

extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *,int);

extern void ICA_ANIME_SetCameraStatus(void *,void *);

extern u32 G3D_UTIL_GetObject(u8 *,int);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *,int,int);

extern void func_02048AD0(struct Light *);

extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);

extern void DOUBLE3DDISP_SetDrawDone(void);

extern u32 ICA_ANIME_GetFrameNum(struct Obj11244 *p);

extern void ZONEDATA_GetTimeLightColors(u32,u32,u32,u32,u32,u16 *,u16);

extern void func_0207DCF8(const u16 *);

extern void G3X_SetFog(BOOL,GXFogBlend,GXFogSlope,int);

extern void G3X_SetFogTable(const u32 *);

extern void G3X_SetClearColor(u16,int,int,int,BOOL);

extern void G3X_SetDisp1DotDepth(int);

extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);

extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);

void func_021BDF18(char *p);

void func_021BDF24(char *p);

void func_021BDF3C(struct Obj *obj, unsigned short *a, int a2);

void func_021BE150(void);

void func_021BE158(void *p);

struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap);

void func_021BE4B4(char *ctx, int b, int c, u32 d);

void func_021BE508(char *p,struct Light *q);

int func_021BE538(const struct Context *ctx, u32 frames);

int func_021BE620(char *p);

u32 func_021BE62C(char *p);

void func_021BE638(char *p,int a);

void func_021BE63C(struct Context *ctx,struct Config *cfg,const struct Record *record,u16 heap);

unsigned func_021BE79C(unsigned x);

u32 func_021BE7A8(u32 id);

void *func_021BE7BC(u32 a, u32 b, u32 c);

u8 func_021BE7D8(unsigned x);

void *func_021BE7F0(unsigned heap);

void func_021BE85C(char *a);

void func_021BE874(char *ctx, const char *config, u8 type);

u32 func_021BE920(u32 a);

int func_021BE938(void *a);

extern const char d_021C3CE0[];

extern const s16_021BE13C FX_SinCosTable_[];

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
 *   `cam = ctx->f74 = func_021BE7A8(...)` (store to ctx first, then the local slot sp+0x24);
 *   cnt is a signed int (ble guard); ortho bounds as in ov088 021B9C2C (FX_Mul/FX_Div,
 *   top = FX_Div(t, c), bottom = -FX_Div(t, c)). The angle divisor is written sz + 0xE0:
 *   the original keeps 0x88 live in r7 (alloc size) and derives 0x168 from it with
 *   adds #0xE0; flagged for the integrator as an odd but listing-forced form.
 */
struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap)
{
    struct Ctx *ctx;

    int ang, right, d, w, top, t, s, j, near, mid, far, bottom;
    struct Cam *cam;
    int c, q;
    int i, k, n, r;
    int left;
    int cnt;
    void *e;
    u32 h;

    ctx = func_02030734(heap, 0x88, 1, d_021C3CE0, 0x79);
    ctx->owner = (u32)owner;
    ctx->id = cfg->f4;
    ctx->f78 = ctx->id;
    ctx->b80 = cfg->fc;
    ctx->f7c = cfg->f8;
    ctx->b81 = TIMEZONE_GetTimeZoneOfHour((u8)cfg->sec, (u8)cfg->fd);
    ctx->b82 = cfg->bit7;
    ctx->b83 = cfg->fd;
    ctx->b84 = cfg->fe;
    ctx->b85 = cfg->sec;
    cam = ctx->f74 = (struct Cam *)func_021BE7A8(ctx->id);
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
    ctx->f20 = G3D_CAMERA_Create(1, top, bottom, left, right, near, mid, far,
                             &d_021BFCE0, &d_021BFCD4, &d_021BFCEC, heap);
    G3D_CAMERA_GetNearClipAlt(ctx->f20, &ctx->f24);
    G3D_CAMERA_GetFarClipAlt(ctx->f20, &ctx->f28);
    func_021BE63C((struct Context *)ctx, (struct Config *)cfg, (const struct Record *)ctx->f74, heap);
    ctx->f14 = func_021BE920(ctx->id);
    ctx->f10 = func_021BE938((void *)ctx->id);
    if (ctx->f10) {
        DOUBLE3DDISP_Init(heap);
        func_02005654((int)func_021BE150, 0);
    }
    ctx->z30[0] = 0;
    ctx->z30[1] = 0;
    ctx->z30[2] = 0;
    ctx->z30[3] = 0x1000;
    ctx->z30[4] = 0x1000;
    ctx->z30[5] = 0x1000;
    MTX_Identity33_(ctx->mtx);
    ctx->f2c = func_021BE7D8(ctx->id);
    ctx->f70 = func_02030734(heap, ctx->f2c * 2, 1, d_021C3CE0, 0xB7);
    ctx->f18 = func_021BE7BC(ctx->id, heap, 10);
    if (ctx->f7c)
        r = _fadd(0x3f000000, _ffltu(ctx->f7c << 12));
    else
        r = _fsub(_ffltu(ctx->f7c << 12), 0x3f000000);
    ICA_ANIME_SetFrame((struct IcaAnime *)ctx->f18, _ffix(r));
    n = ctx->f2c * 6;
    ctx->f1c = G3D_UTIL_Create((u16)n, (u16)n, heap);
    e = func_021BE7F0(heap);
    for (i = 0; i < ctx->f2c; i++) {
        func_021BE874(e, (const char *)(&ctx->f78), i);
        ctx->f70[i] = G3D_UTIL_AddUnit(ctx->f1c, e);
    }
    func_021BE85C(e);
    for (j = 0; j < ctx->f2c; j++) {
        h = func_02048A18((u8 *)ctx->f1c, (u16)ctx->f70[j]);
        cnt = G3D_SYSTEM_GetObjectAnimeCount((int *)h);
        for (k = 0; k < cnt; k++) {
            if (ctx->f7c)
                r = _fadd(0x3f000000, _ffltu(ctx->f7c << 12));
            else
                r = _fsub(_ffltu(ctx->f7c << 12), 0x3f000000);
            ang = _ffix(r);
            G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)h, (u16)k);
            G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)h, k, &ang);
        }
    }
    ctx->f6c = DEMO3D_CMDSYS_Create(ctx, heap);
    return ctx;
}

void func_021BE4B4(char *ctx, int b, int c, u32 d)
{
    unsigned i;
    DEMO3D_CMDSYS_Delete(((struct Obj03354 *)ctx)->f6C);
    func_021BE158(((struct Obj03354 *)ctx)->f20);
    if (((struct Obj03354 *)ctx)->f10) {
        func_0200566C();
        DOUBLE3DDISP_Exit();
    }
    ICA_ANIME_Delete(((struct Obj03354 *)ctx)->f18);
    for (i = 0; i < ((struct Obj03354 *)ctx)->f2C; i++) {
        G3D_UTIL_RemoveUnit(((struct Obj03354 *)ctx)->f1C, (*(unsigned short **)(ctx + 0x70))[i]);
    }
    G3D_UTIL_Delete(((struct Obj03354 *)ctx)->f1C);
    func_020307B0(((struct Obj03354 *)ctx)->f70);
    func_020307B0(ctx);
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
void func_021BE508(char *p,struct Light *q)
{
    int x;
    if(DOUBLE3DDISP_GetMode()==0)x=*(short *)(*(char **)(p+0x74)+0x20);
    else x=*(short *)(*(char **)(p+0x74)+0x22);
    G3D_CAMERA_SetNearClipAlt(q,x+*(u32 *)(p+0x24));
    G3D_CAMERA_SetFarClipAlt(q,x+*(u32 *)(p+0x28));
}

int func_021BE538(const struct Context *ctx, u32 frames)
{
    u32 done;
    long advance = 0;
    unsigned long time = ICA_ANIME_GetFrame((struct Obj11245 *)ctx->anime);
    u32 i;
    for(i=0;i<frames+1;i++) {
        if(ctx->a8 == 0) DEMO3D_CMDSYS_Update(ctx->events,time+advance,i);
        else DEMO3D_CMDSYS_Update(ctx->events,-4096,i);
        advance += ctx->step;
    }
    done = ICA_ANIME_IncFrameNoLoop(ctx->anime,advance);
    ICA_ANIME_SetCameraStatus(ctx->light,ctx->anime);
    for(i=0;i<ctx->count;i++) {
        void *obj=(void *)G3D_UTIL_GetObject(ctx->table,ctx->indices[i]);
        int j, count=G3D_SYSTEM_GetObjectAnimeCount(obj);
        for(j=0;j<count;j++) G3D_SYSTEM_LoopObjectAnimeFrame(obj,(u16)j,advance);
    }
    if(ctx->a10 != 0) func_021BE508((char *)ctx,ctx->light);
    func_02048AD0(ctx->light);
    func_021BDF18(ctx->owner);
    for(i=0;i<ctx->count;i++) {
        G3D_SYSTEM_DrawObject((void *)G3D_UTIL_GetObject(ctx->table,ctx->indices[i]),(struct Arg *)ctx->args);
    }
    func_021BDF24(ctx->owner);
    if(ctx->a10 != 0) DOUBLE3DDISP_SetDrawDone();
    return done;
}

int func_021BE620(char *p) { return ICA_ANIME_GetFrame(((struct Obj25315 *)p)->f18); }

u32 func_021BE62C(char *p) { return ICA_ANIME_GetFrameNum(((struct Obj25316 *)p)->f18); }

void func_021BE638(char *p,int a) { ((struct Obj25317 *)p)->f8=a; }

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
void func_021BE63C(struct Context *ctx,struct Config *cfg,const struct Record *record,u16 heap)
{
    u16 colors[10];
    u32 fogtable[8];
    u32 i;
    ZONEDATA_GetTimeLightColors(record->id,cfg->hour,cfg->minute,0,cfg->second,colors,heap);
    func_021BDF3C(ctx->owner,colors,0);
    Anti(record->anti);
    Test(record->test,ctx->record->ref);
    Blend(record->blend);
    Edge(record->edge);
    if(record->edge) func_0207DCF8(record->edgecolors);
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

unsigned func_021BE79C(unsigned x) { if(x==0||x>=19)x=0;return x; }

u32 func_021BE7A8(u32 id)
{
    return *(u32 *)(d_021C185C + func_021BE79C(id) * 0x14);
}

void *func_021BE7BC(u32 a, u32 b, u32 c)
{
    u16 *t = (u16 *)func_021BE7A8(a);

    return ICA_ANIME_CreateStream(b, 0xa0, *t, c);
}

u8 func_021BE7D8(unsigned x) { return *(u32 *)(d_021C186C+func_021BE79C(x)*20); }
