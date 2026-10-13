/*
 * unit:     yes
 * function: MCSS_Draw
 * address:  0x02014D2C
 * packet:   pkt_02014D2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/MCSS_Draw.c \
 *       --addr 0x02014D2C --thumb
 *
 * The mcss.c frame walker, ONE function over 0x02014D2C..0x020155A0
 * (2164 bytes).  0x02014D90 and 0x02015590 are not function starts: they
 * are the targets of two bl instructions the compiler emits as long
 * branches (0x02014D74 to the shared epilogue, 0x0201558C back to the
 * outer loop head), both beyond Thumb b reach.  They were once listed on the
 * function line only so the three worklist rows are attested by this one
 * compared range; the integrator may drop them as starts.
 *
 * The lever that closed it (wave 15, from 43 bytes out): the texture
 * parameter write is the SDK inline G3_TexImageParam with the SDK's ENUM
 * parameter types (GXTexFmt, GXTexGen, GXTexSizeS/T, GXTexRepeat,
 * GXTexFlip, GXTexPlttColor0).  With int parameters the inline is 2168
 * bytes (540 out); with a hand-written or-chain 43 out (the STORE constant
 * 0x1e CSE'd with 0x1e << 15).  Enum parameters are materialised as
 * temporaries before the body, which is what keeps 0x1e rematerialised.
 * See docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md.
 * History: docs/notes/pkt_02014D2C_boundary.c.txt.
 *
 * symbols:
 *   func_0206DB80    0x0206DB80  arm
 *   MTX_Inverse43    0x0207B67C  arm
 *   MI_Copy36B       0x02082B60  arm
 *   MTX_Copy33To44_  0x0207ADE8  arm
 *   MTX_Copy43To44_  0x0207B5C0  arm
 *   MTX_Concat44     0x0207BE14  arm
 *   G3i_LookAt_      0x0207D7C4  arm
 *   G3_RotX          0x0207D810  arm
 *   G3_RotZ          0x0207D888  arm
 *   G3_MultMtx44     0x0207D8FC  arm
 *   FX_Div     0x0207C768  arm
 *   MCSS_MulVecMtx44    0x02016FC8  thumb
 *   MCSS_InitEdgeColor     0x020169D4  thumb
 *   MCSS_DrawShadow    0x020155A0  thumb
 *   _ll_mul          0x0209C054  arm
 *   _fflt            0x0209BDBC  arm
 *   _ffix            0x0209C494  arm
 *   _fadd            0x0209C95C  arm
 *   _fsub            0x0209CB8C  arm
 *   g_renderStateDrawParams       0x02148B98  data
 *   SCREENTEX_ProjectionMatrix       0x02148B54  data
 *   SCREENTEX_CameraPositionOut       0x02148D8C  data
 *   SCREENTEX_CameraTargetOut       0x02148D98  data
 *   SCREENTEX_CameraUpOut       0x02148DA4  data
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_0209E090       0x0209E090  data
 *   d_0209E09C       0x0209E09C  data
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef signed long long s64;
typedef s32 fx32;
typedef s64 fx64;
typedef volatile u32 vu32;

typedef struct { fx32 x, y, z; } VecFx32;
typedef struct { fx32 m[4][3]; } MtxFx43;
typedef struct { fx32 m[3][3]; } MtxFx33;
typedef struct { fx32 m[4][4]; } MtxFx44;

extern void func_0206DB80(void);
extern int  MTX_Inverse43(const MtxFx43 *src, MtxFx43 *dst);
extern void MI_Copy36B(const void *src, void *dst);
extern void MTX_Copy33To44_(const MtxFx33 *src, MtxFx44 *dst);
extern void MTX_Copy43To44_(const MtxFx43 *src, MtxFx44 *dst);
extern void MTX_Concat44(const MtxFx44 *a, const MtxFx44 *b, MtxFx44 *ab);
extern void G3i_LookAt_(const VecFx32 *camPos, const VecFx32 *camUp,
                        const VecFx32 *target, int draw, MtxFx43 *mtx);
extern void G3_RotX(fx32 s, fx32 c);
extern void G3_RotZ(fx32 s, fx32 c);
extern void G3_MultMtx44(const MtxFx44 *m);
extern u32 FX_Div(u32 a, u32 b);
struct McssSys;
struct McssWork;
struct MtxFx44;
struct Pose;
struct Tex;
struct VecFx32;
extern void MCSS_MulVecMtx44(const struct VecFx32 *v, const struct MtxFx44 *mtx, struct VecFx32 *dst, s32 *w);
extern void MCSS_InitEdgeColor(void);

extern MtxFx43 g_renderStateDrawParams;
extern MtxFx44 SCREENTEX_ProjectionMatrix;
extern VecFx32 SCREENTEX_CameraPositionOut;
extern VecFx32 SCREENTEX_CameraTargetOut;
extern VecFx32 SCREENTEX_CameraUpOut;
extern s16 FX_SinCosTable_[];
extern const VecFx32 d_0209E090;
extern const VecFx32 d_0209E09C;

#define REG_MTX_MODE     (*(vu32 *)0x04000440)
#define REG_MTX_PUSH     (*(vu32 *)0x04000444)
#define REG_MTX_POP      (*(vu32 *)0x04000448)
#define REG_MTX_STORE    (*(vu32 *)0x0400044C)
#define REG_MTX_IDENTITY (*(vu32 *)0x04000454)
#define REG_MTX_SCALE    (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS    (*(vu32 *)0x04000470)
#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)

static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_TRANS = (u32)x;
    REG_MTX_TRANS = (u32)y;
    REG_MTX_TRANS = (u32)z;
}

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    REG_MTX_SCALE = (u32)x;
    REG_MTX_SCALE = (u32)y;
    REG_MTX_SCALE = (u32)z;
}

static inline void G3_LookAt(const VecFx32 *camPos, const VecFx32 *camUp,
                             const VecFx32 *target, MtxFx43 *mtx)
{
    G3i_LookAt_(camPos, camUp, target, 1, mtx);
}

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;
typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;
typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;
typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;
typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;
typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;
typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;
static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG_TEXIMAGE_PARAM = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}
static inline void G3_StoreMtx(int num) { REG_MTX_STORE = (u32)num; }
struct Pose {
    u16  f00;
    u16  rot;
    fx32 sx;
    fx32 sy;
    s16  ox;
    s16  oy;
};

struct PoseT { u16 f00; u16 pad; s16 ox; s16 oy; };

struct AnimFrame { void *content; u16 frames; u16 pad; };
struct AnimSeq   { u16 numFrames; u16 loopStart; u32 type; };

struct AnimCtrl {
    struct AnimFrame *cur;
    u8   pad04[0x1c - 0x04];
    struct AnimSeq *seq;
};

struct Node {
    struct AnimCtrl ctrl;
    u8   pad20[0x5c - 0x20];
};

struct Cell  { s16 f00; s16 f02; s16 f04; u16 f06; };
struct Frame { u16 count; u16 pad; struct Cell *cells; };
struct MAnim { u32 f00; struct Frame *frames; };

struct Quad  { s32 x, y, w, h, s, t; };
struct Rec   { struct Quad q0; struct Quad q1; };

struct TexInfo {
    u32 addr;
    u32 f04;
    u32 f08;
    u32 s;
    u32 t;
    u32 fmt;
    u32 f18;
    u32 pltt0;
};

struct McssTex { s32 fmt; u32 f04; u32 plttBase; };

struct McssSys {
    u8   pad00[0x10];
    s32  count;
    struct McssWork **slots;
    struct McssTex tex;
    u8   pad24[0x2c - 0x24];
    u32  f2c_0 : 1;
    u32  f2c_r : 31;
    u8   pad30[0x44 - 0x30];
    fx32 f44;
    s32  f48;
};

struct McssWork {
    u8   pad00[0x2c];
    u8  *f2c;
    u8   pad30[0x34 - 0x30];
    struct AnimCtrl ctrl;
    u8   pad54[0x74 - 0x54];
    struct Node *nodes;
    struct MAnim *anim;
    u8   pad7c[0x9c - 0x7c];
    struct TexInfo tex;
    u8   padbc[0xe0 - 0xbc];
    fx32 fe0, fe4, fe8;
    fx32 fec, ff0, ff4;
    u8   padf8[0x100 - 0xf8];
    fx32 f100;
    fx32 f104, f108, f10c;
    fx32 f110, f114, f118;
    fx32 f11c, f120, f124;
    fx32 f128, f12c, f130;
    u8   pad134[0x140 - 0x134];
    u32  b0  : 8;
    u32  b8  : 1;
    u32  b9  : 2;
    u32  b11 : 1;
    u32  b12 : 1;
    u32  b13 : 1;
    u32  b14 : 9;
    u32  b23 : 1;
    u32  b24 : 5;
    u32  b29 : 1;
    u32  b30 : 1;
    u32  b31 : 1;
    u8   pad144[0x178 - 0x144];
    u16  f178;
    u16  f17a;
    fx32 f17c, f180, f184;
};

extern void MCSS_DrawShadow(struct McssSys *sys, struct McssWork *w, s32 x, s32 y, s32 width, s32 height, s32 s, s32 t, struct Pose *pose, u16 *frame, struct Tex *tex, int id, int proj, u32 *z, u8 flip);

void MCSS_Draw(struct McssSys *sys)
{
    struct Pose pose;
    struct Pose part;
    VecFx32 pos;
    MtxFx44 bb;
    MtxFx43 inv;
    MtxFx33 rot33;
    u32 z;
    s32 wv;
    struct McssWork *w;
    struct AnimCtrl *ctrl;
    int k;
    int idx;
    u16 rot;
    fx32 tx, ty;
    fx32 sx, sy;
    struct TexInfo *tex;
    int i;
    struct Node **nodes;
    u8 flip;
    fx32 c;
    fx32 s;
    int billboard;
    int param;

    func_0206DB80();
    REG_MTX_PUSH = 0;
    REG_MTX_MODE = 0;
    REG_MTX_STORE = 0;
    REG_MTX_MODE = 3;
    REG_MTX_IDENTITY = 0;
    REG_MTX_MODE = 2;
    MTX_Inverse43(&g_renderStateDrawParams, &inv);
    MI_Copy36B(&inv, &rot33);
    MTX_Copy33To44_(&rot33, &bb);

    i = 0;
    if (sys->count > 0) {
    do {
        if (sys->slots[i] == 0 || sys->slots[i]->b11 != 0 || sys->slots[i]->b13 != 1) {
            continue;
        }
        billboard = 0;
        z = 0;
        if (sys->f2c_0) {
            billboard = sys->slots[i]->b29;
        }
        w = sys->slots[i];
        tex = &w->tex;
        if (billboard == 0) {
            G3_LookAt(&SCREENTEX_CameraPositionOut, &SCREENTEX_CameraTargetOut, &SCREENTEX_CameraUpOut, 0);
        } else {
            VecFx32 camPos = { 0, 0, 0 };
            VecFx32 camUp = d_0209E090;
            VecFx32 camTgt = d_0209E09C;
            G3_LookAt(&camPos, &camUp, &camTgt, 0);
        }
        ctrl = &w->ctrl;
        nodes = &w->nodes;
        switch ((u16)ctrl->seq->type) {
        case 0:
            pose.f00 = *(u16 *)ctrl->cur->content;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ox = 0;
            pose.oy = 0;
            break;
        case 1:
            pose = *(struct Pose *)ctrl->cur->content;
            break;
        case 2: {
            struct PoseT *t = (struct PoseT *)ctrl->cur->content;
            pose.f00 = t->f00;
            pose.rot = 0;
            pose.sx = 0x1000;
            pose.sy = 0x1000;
            pose.ox = t->ox;
            pose.oy = t->oy;
            break;
        }
        }
        pos.x = w->fe0 + w->f11c;
        pos.y = w->fe4 + w->f120;
        pos.z = w->fe8 + w->f124;
        if (billboard == 0) {
            tx = FX_MUL(pose.ox << 8, sys->f44);
            ty = FX_MUL(-pose.oy << 8, sys->f44);
        } else {
            MtxFx44 m;
            sx = FX_MUL(w->fec, w->f128);
            sy = FX_MUL(w->ff0, w->f12c);
            MTX_Copy43To44_(&g_renderStateDrawParams, &m);
            MTX_Concat44(&m, &SCREENTEX_ProjectionMatrix, &m);
            MCSS_MulVecMtx44((const struct VecFx32 *)(&pos), (const struct MtxFx44 *)(&m), (struct VecFx32 *)(&pos), &wv);
            pos.x = FX_MUL(FX_Div(pos.x, wv), 0x80000);
            pos.y = FX_MUL(FX_Div(pos.y, wv), 0x60000);
            pos.z = -pos.z;
            tx = FX_F32_TO_FX32(pose.ox);
            ty = FX_F32_TO_FX32(-pose.oy);
            tx = FX_MUL(tx, sx / 16);
            ty = FX_MUL(ty, sy / 16);
        }
        G3_Translate(pos.x, pos.y, pos.z);
        if (billboard == 0) {
            G3_MultMtx44(&bb);
        }
        rot = pose.rot + (w->f100 >> 12);
        G3_Translate(tx, ty, 0);
        flip = 0;
        idx = rot >> 4;
        c = FX_SinCosTable_[idx * 2 + 1];
        s = -FX_SinCosTable_[idx * 2];
        G3_RotZ(s, c);
        G3_Scale(FX_MUL(FX_MUL(pose.sx, w->fec), w->f128),
                 FX_MUL(FX_MUL(pose.sy, w->ff0), w->f12c), 0x1000);
        if (w->fec < 0) {
            flip++;
        }
        G3_StoreMtx(29);
        G3_LookAt(&SCREENTEX_CameraPositionOut, &SCREENTEX_CameraTargetOut, &SCREENTEX_CameraUpOut, 0);
        G3_Translate(w->fe0 + w->f11c + w->f17c, w->fe4 + w->f180,
                     w->fe8 + w->f124 + w->f184);
        idx = w->f178 >> 4;
        G3_RotX(FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        G3_Translate(FX_MUL(FX_MUL(pose.ox << 8, sys->f44), w->f104),
                     FX_MUL(FX_MUL(-pose.oy << 8, sys->f44), w->f108), 0);
        idx = w->f17a >> 4;
        G3_RotZ(-FX_SinCosTable_[idx * 2], FX_SinCosTable_[idx * 2 + 1]);
        G3_RotZ(s, c);
        G3_Scale(FX_MUL(FX_MUL(FX_MUL(pose.sx, w->f104), w->f110), w->f128),
                 FX_MUL(FX_MUL(FX_MUL(pose.sy, w->f108), w->f114), w->f12c),
                 0x1000);
        G3_StoreMtx(30);
        MCSS_InitEdgeColor();
        G3_TexImageParam(tex->fmt, GX_TEXGEN_TEXCOORD, tex->s, tex->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, tex->pltt0, tex->addr);
        for (k = 0; k < w->anim->frames[pose.f00].count; k++) {
            struct Node *node;
            struct Rec *rec;
            int id;
            if (w->b0 != 0x1f || w->b30) {
                id = w->anim->frames[pose.f00].count - 1 - k;
            } else {
                id = k;
            }
            node = &(*nodes)[(w->anim->frames[pose.f00].cells[id].f06 & 0xff00) >> 8];
            switch ((u16)node->ctrl.seq->type) {
            case 0:
                part.f00 = *(u16 *)node->ctrl.cur->content;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ox = 0;
                part.oy = 0;
                break;
            case 1:
                part = *(struct Pose *)node->ctrl.cur->content;
                break;
            case 2: {
                struct PoseT *t = (struct PoseT *)node->ctrl.cur->content;
                part.f00 = t->f00;
                part.rot = 0;
                part.sx = 0x1000;
                part.sy = 0x1000;
                part.ox = t->ox;
                part.oy = t->oy;
                break;
            }
            }
            rec = (struct Rec *)(w->f2c + 0xc) + part.f00;
            if (rec->q1.w != 0 && w->b30 == 0) {
                if (w->b8) {
                    MCSS_DrawShadow(sys, w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h,
                                  rec->q1.s, rec->q1.t + rec->q1.h,
                                  &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                } else {
                    MCSS_DrawShadow(sys, w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h,
                                  rec->q1.s, rec->q1.t,
                                  &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                }
            }
            MCSS_DrawShadow(sys, w, rec->q0.x, rec->q0.y, rec->q0.w, rec->q0.h,
                          rec->q0.s, rec->q0.t,
                          &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
            if (rec->q1.w != 0 && w->b30 == 1) {
                if (w->b8) {
                    MCSS_DrawShadow(sys, w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h,
                                  rec->q1.s, rec->q1.t + rec->q1.h,
                                  &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                } else {
                    MCSS_DrawShadow(sys, w, rec->q1.x, rec->q1.y, rec->q1.w, rec->q1.h,
                                  rec->q1.s, rec->q1.t,
                                  &part, &pose.f00, (struct Tex *)(&sys->tex), id, billboard, &z, flip);
                }
            }
        }
    } while (++i < sys->count);
    }
    REG_MTX_POP = 1;
}
