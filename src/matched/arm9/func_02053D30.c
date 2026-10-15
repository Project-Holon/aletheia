/*
 * function: SPL_EMITTER_SetTextureParam
 * address:  0x02053D30
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SPLUtil_SetTexture of the NitroSystem-style particle library (SPL) this
 * cluster is: the texture-row setup both draw dispatchers call.  The body is
 * the SDK's own G3 inline sequence, G3_TexImageParam / G3_TexPlttBase /
 * G3_MtxMode / G3_Identity / G3_Scale / G3_MtxMode, over a copy of the
 * row's SPLTextureParam union (the copy is the dead `str r7, [sp]`).
 *
 * Closes docs/notes/SPL_EMITTER_SetTextureParam.c.txt (41 out after two lanes, the whole
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
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
#define FX32_ONE ((fx32)0x00001000L)
#define reg_G3_MTX_MODE        (*(volatile u32 *)0x04000440)
#define reg_G3_MTX_IDENTITY    (*(volatile u32 *)0x04000454)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_A3I5 = 1, GX_TEXFMT_PLTT4 = 2, GX_TEXFMT_PLTT16 = 3, GX_TEXFMT_PLTT256 = 4, GX_TEXFMT_COMP4x4 = 5, GX_TEXFMT_A5I3 = 6, GX_TEXFMT_DIRECT = 7 } GXTexFmt;
typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1, GX_TEXGEN_NORMAL = 2, GX_TEXGEN_VERTEX = 3 } GXTexGen;
typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;
typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;
typedef enum { GX_TEXREPEAT_NONE = 0 } GXTexRepeat;
typedef enum { GX_TEXFLIP_NONE = 0 } GXTexFlip;
typedef enum { GX_TEXPLTTCOLOR0_USE = 0 } GXTexPlttColor0;
typedef enum { GX_MTXMODE_PROJECTION = 0, GX_MTXMODE_POSITION = 1, GX_MTXMODE_POSITION_VECTOR = 2, GX_MTXMODE_TEXTURE = 3 } GXMtxMode;
#define GX_PACK_TEXIMAGE_PARAM(texFmt, texGen, s, t, repeat, flip, pltt0, addr) \
    ((u32)((addr) >> 3) | ((texFmt) << 26) | ((texGen) << 30) | ((s) << 20) | ((t) << 23) | ((repeat) << 16) | ((flip) << 18) | ((pltt0) << 29))
#define GX_PACK_TEXPLTTBASE_PARAM(addr, texfmt) ((u32)((addr) >> (4 - ((texfmt) == GX_TEXFMT_PLTT4))))
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
void SPL_EMITTER_SetTextureParam(SPLTexture *tex)
{
    SPLTextureParam param = tex->param;
    G3_TexImageParam(param.format, GX_TEXGEN_TEXCOORD, param.s, param.t, param.repeat, param.flip, param.palColor0, tex->texAddr);
    G3_TexPlttBase(tex->palAddr, param.format);
    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_Identity();
    G3_Scale(tex->width * FX32_ONE, tex->height * FX32_ONE, 0);
    G3_MtxMode(GX_MTXMODE_POSITION);
}
