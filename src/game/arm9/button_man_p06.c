/*
 * file:     button_man_p06.c
 * unit:     yes
 * function: func_02053D30, func_02053E1C
 * address:  0x02053D30
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02053E1C_Verts  0x020A1B38  data
 *   func_02053E1C_Hooks  0x020A7FE4  data
 *   func_02053E1C_Hooks2 0x020A7FDC  data
 *   func_0207B598        0x0207B598  arm
 *   func_0207B5F4        0x0207B5F4  thumb
 *   func_0207B9F0        0x0207B9F0  arm
 *   func_0207CA68        0x0207CA68  arm
 *   func_0207CAE8        0x0207CAE8  arm
 *   func_0207CCA4        0x0207CCA4  arm
 *   func_0207D8E0        0x0207D8E0  arm
 *   func_0207D918        0x0207D918  arm
 */
#define FX32_ONE ((fx32)0x00001000L)
#define reg_G3_MTX_MODE        (*(volatile u32 *)0x04000440)
#define reg_G3_MTX_IDENTITY    (*(volatile u32 *)0x04000454)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr) \
    ((u32)((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) | ((flip) << 18) | ((pltt0) << 29))
#define GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt) ((u32)((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4))))
typedef signed int s32;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed long long s64;

typedef unsigned char u8;

struct VecFx32 { s32 x, y, z; };

struct MtxFx43 { s32 m[12]; };

struct Bf16 {
    u16 b0 : 5;
    u16 b5 : 5;
    u16 b10 : 6;
};

struct BfSel {
    u32 lo : 6;
    u32 sel : 1;
    u32 hi : 25;
};

struct BfZero {
    u32 f0 : 17;
    u32 sel2 : 2;
    u32 sel1 : 1;
    u32 f20 : 3;
    u32 flag : 1;
    u32 f24 : 8;
};

struct Bf28 {
    u32 lo : 28;
    u32 sel : 3;
    u32 hi : 1;
};

struct BfHw {
    u16 a : 9;
    u16 sel2 : 2;
    u16 sel1 : 1;
    u16 b : 4;
};

struct SubD {
    struct BfHw hw;
    u8 pad02[0x0e];
    struct BfSel f10;
};

struct SubC {
    struct BfZero f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u8 pad10[0x20];
    s16 f30;
    u8 pad32[0x16];
    struct Bf28 f48;
    u8 pad4c[0x04];
    s16 f50;
    s16 f52;
};

struct SubX {
    struct SubC *f00;
    u8 pad04[0x10];
    struct SubD *f14;
};

struct SubB {
    u8 pad00[0x20];
    struct SubX *f20;
    u8 pad24[0x4e];
    u16 f72;
    u8 pad74[0x04];
    s16 f78;
    s16 f7a;
    s16 f7c;
    s16 f7e;
};

struct Obj {
    u8 pad00[0x3c];
    u32 f3c;
    struct SubB *f40;
    struct MtxFx43 *f44;
};

struct S {
    u8 pad00[0x08];
    struct VecFx32 p1;
    struct VecFx32 p2;
    u16 f20;
    u8 pad22[0x0c];
    struct Bf16 w;
    s32 f30;
    s16 f34;
    u16 f36;
    u32 f38;
    u32 f3c;
    u32 f40;
};

struct Frame {
    struct MtxFx43 m1;
    struct MtxFx43 m2;
    struct MtxFx43 m3;
    struct VecFx32 v0;
    struct VecFx32 v1;
    struct VecFx32 v2;
    struct VecFx32 v3;
    struct MtxFx43 m4;
};

typedef s32 fx32;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_A3I5 = 1, GX_TEXFMT_PLTT4 = 2, GX_TEXFMT_PLTT16 = 3, GX_TEXFMT_PLTT256 = 4, GX_TEXFMT_COMP4x4 = 5, GX_TEXFMT_A5I3 = 6, GX_TEXFMT_DIRECT = 7 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1, GX_TEXGEN_NORMAL = 2, GX_TEXGEN_VERTEX = 3 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0 } GXTexPlttColor0;

typedef enum { GX_MTXMODE_PROJECTION = 0, GX_MTXMODE_POSITION = 1, GX_MTXMODE_POSITION_VECTOR = 2, GX_MTXMODE_TEXTURE = 3 } GXMtxMode;

typedef union SPLTextureParam {
    u32 all;
    struct {
        u32 format : 4;
        u32 s : 4;
        u32 t : 4;
        u32 repeat : 2;
        u32 flip : 2;
        u32 palColor0 : 1;
        u32 useSharedTexture : 1;
        u32 sharedTexID : 8;
        u32 : 6;
    };
} SPLTextureParam;

typedef struct SPLTexture {
    const void *resource;
    u32 texAddr;
    u32 palAddr;
    SPLTextureParam param;
    u16 width;
    u16 height;
} SPLTexture;

extern void func_0207B598(void *);
extern u32 func_0207B5F4(void *, s32, s32, s32);
extern void func_0207B9F0(const void *, const void *, void *);
extern s32 func_0207CA68(const void *, const void *);
extern void func_0207CAE8(const void *, const void *, void *);
extern void func_0207CCA4(const void *, void *);
extern void func_0207D8E0(const void *);
extern void func_0207D918(const void *);
void func_02053E1C(struct Obj *obj, struct S *s);
void func_02053D30(SPLTexture *tex);
extern const s16 func_02053E1C_Verts[];

extern u32 (*const func_02053E1C_Hooks[])(s32, s32, void *);

extern u32 (*const func_02053E1C_Hooks2[])(s32, s32, s32, s32);


/*
 * Handler row 0 of the rig render-list dispatch (func_02053044 /
 * func_0205312C pool rows; docs/families/cluster_02052F58.h).  Same skeleton
 * as func_0205429C, transcribed from it with five differences read off the
 * listing:
 *   - the basis hook is selected by SubD->hw bits 9..10 (BfHw.sel2, as in
 *     func_02054718), not SubC->f00 bits 17..18;
 *   - the direction/negated-position choice is SubD->f10 bit 6 (BfSel.sel),
 *     not SubC->f48 bit 31;
 *   - the scale concat is MTX_Concat43(m2, m3, m1) -- operands the other way
 *     round from func_0205429C's (m3, m2, m1); the only 2 bytes the straight
 *     transcription had wrong;
 *   - the quad-emitter hook is SubD->hw bit 11 (BfHw.sel1);
 *   - its arguments are SubB +0x7c/+0x7e and two literal zeros.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02053E1C.c \
 *       --func func_02053E1C --addr 0x02053E1C --arm --cc ../1.2/sp2
 */
void func_02053E1C(struct Obj *obj, struct S *s)
{
    struct Frame f;
    struct SubC *p;
    s32 n;
    s32 i;
    s32 a;
    s32 x;
    s32 y;
    s64 a64;
    u32 v;
    s32 c1;
    u32 q4, q8, qc;
    s32 c2;

    n = (s32)s->w.b0 * (s32)(s->w.b5 + 1);
    v = ((u32)s->w.b10 << 24) | (obj->f3c | 0xc0) | ((u32)(n >> 5) << 16);
    *(volatile u32 *)0x040004A4 = v;
    v = *(volatile u32 *)0x040004A4;
    if ((n >> 5) == 0)
        return;

    i = (s32)s->f20 >> 4;
    func_02053E1C_Hooks[obj->f40->f20->f14->hw.sel2]
        (func_02053E1C_Verts[2 * i], func_02053E1C_Verts[2 * i + 1], &f.m2);

    func_0207B598(&f.m4);
    if (obj->f40->f20->f14->f10.sel == 0) {
        func_0207CCA4(&s->p2, &f.v0);
    } else {
        func_0207CCA4(&s->p1, &f.v0);
        f.v0.x = -f.v0.x;
        f.v0.y = -f.v0.y;
        f.v0.z = -f.v0.z;
    }

    f.v3.x = 0;
    f.v3.y = 0x1000;
    f.v3.z = 0;
    i = func_0207CA68(&f.v0, &f.v3);
    if (i > 0xCCD || i < -0xCCD) {
        f.v3.x = 0x1000;
        f.v3.y = 0;
        f.v3.z = 0;
    }

    func_0207CAE8(&f.v0, &f.v3, &f.v1);
    func_0207CAE8(&f.v0, &f.v1, &f.v2);

    f.m4.m[0] = f.v1.x;
    f.m4.m[1] = f.v1.y;
    f.m4.m[2] = f.v1.z;
    f.m4.m[3] = f.v0.x;
    f.m4.m[4] = f.v0.y;
    f.m4.m[5] = f.v0.z;
    f.m4.m[6] = f.v2.x;
    f.m4.m[7] = f.v2.y;
    f.m4.m[8] = f.v2.z;

    func_0207B9F0(&f.m2, &f.m4, &f.m2);

    a = s->f30;
    n = (s32)(((s64)a * obj->f40->f20->f00->f30 + 0x800) >> 12);
    x = n;
    y = a;
    a64 = (s64)(s32)a;
    switch (obj->f40->f20->f00->f48.sel) {
    case 0:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    case 1:
        x = (s32)(((s64)n * s->f34 + 0x800) >> 12);
        break;
    case 2:
        y = (s32)(((a64 * s->f34) + 0x800) >> 12);
        break;
    default:
        break;
    }

    func_0207B5F4(&f.m3, x, y, y);
    func_0207B9F0(&f.m2, &f.m3, &f.m1);

    if (obj->f40->f20->f00->f00.flag == 0) {
        f.m1.m[9] = s->p1.x + s->f38;
        f.m1.m[10] = s->p1.y + s->f3c;
        f.m1.m[11] = s->p1.z + s->f40;
        func_0207D8E0(obj->f44);
        func_0207D918(&f.m1);
    } else {
        f.m1.m[9] = s->p1.x + s->f38 - obj->f40->f20->f00->f04;
        f.m1.m[10] = s->p1.y + s->f3c - obj->f40->f20->f00->f08;
        f.m1.m[11] = s->p1.z + s->f40 - obj->f40->f20->f00->f0c;
        *(volatile u32 *)0x04000454 = 0;
        p = obj->f40->f20->f00;
        qc = p->f0c;  q8 = p->f08;  q4 = p->f04;
        *(volatile u32 *)0x04000470 = q4;
        *(volatile u32 *)0x04000470 = q8;
        *(volatile u32 *)0x04000470 = qc;
        func_0207D918(obj->f44);
        func_0207D918(&f.m1);
    }

    c1 = s->f36;
    c2 = obj->f40->f72;
    v = ((c1 & 0x1f) * (c2 & 0x1f) >> 5)
      | ((((c1 & 0x3e0) * (c2 & 0x3e0)) >> 15) << 5)
      | ((((c1 & 0x7c00) * (c2 & 0x7c00)) >> 25) << 10);
    *(volatile u32 *)0x04000480 = (u16)v;

    func_02053E1C_Hooks2[obj->f40->f20->f14->hw.sel1]
        (obj->f40->f7c, obj->f40->f7e, 0, 0);
}

static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS sSize, GXTexSizeT tSize, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    reg_G3_TEXIMAGE_PARAM = GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, sSize, tSize, repeat, flip, pltt0, addr);
}

static inline void G3_TexPlttBase(u32 addr, GXTexFmt texfmt)
{
    reg_G3_TEXPLTT_BASE = GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt);
}

static inline void G3_MtxMode(GXMtxMode mode) { reg_G3_MTX_MODE = (u32)mode; }

static inline void G3_Identity(void) { reg_G3_MTX_IDENTITY = 0; }

static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}

/*
 * SPLUtil_SetTexture of the NitroSystem-style particle library (SPL) this
 * cluster is: the texture-row setup both draw dispatchers call.  The body is
 * the SDK's own G3 inline sequence, G3_TexImageParam / G3_TexPlttBase /
 * G3_MtxMode / G3_Identity / G3_Scale / G3_MtxMode, over a copy of the
 * row's SPLTextureParam union (the copy is the dead `str r7, [sp]`).
 *
 * Closes docs/notes/func_02053D30.c.txt (41 out after two lanes, the whole
 * residue register naming).  What closed it, wave 9 third lane: the
 * function's structure and names were taken from the public pret/pokeplatinum
 * decompilation of the same library (lib/spl/src/spl_emitter.c,
 * SPLUtil_SetTexture), with the SDK inlines written with their real
 * parameter lists.  Measured load-bearing: the G3_TexImageParam inline with
 * its enum-typed parameters and GX_PACK_TEXIMAGE_PARAM (writing the macro
 * straight into the register store: 50 out) and the G3_Scale inline with its
 * three fx32 parameters (direct stores through sx/sy locals: 57 out).  Not
 * load-bearing: G3_TexPlttBase as an inline, `* FX32_ONE` versus `<< 12`,
 * and the union versus a plain bitfield struct.
 */
void func_02053D30(SPLTexture *tex)
{
    SPLTextureParam param = tex->param;
    G3_TexImageParam(param.format, GX_TEXGEN_TEXCOORD, param.s, param.t, param.repeat, param.flip, param.palColor0, tex->texAddr);
    G3_TexPlttBase(tex->palAddr, param.format);
    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_Identity();
    G3_Scale(tex->width * FX32_ONE, tex->height * FX32_ONE, 0);
    G3_MtxMode(GX_MTXMODE_POSITION);
}
