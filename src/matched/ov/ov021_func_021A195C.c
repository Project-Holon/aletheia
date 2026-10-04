/*
 * function: func_021A195C
 * address:  0x021A195C
 * packet:   pkt_ov021_021A195C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK G3_TexImageParam / G3_TexPlttBase inlines with the SDK enum parameter
 * types (enum parameters are materialised as temporaries before the body,
 * which gives the load order and the [sp] spill of the tex key), NNS key
 * address inlines, and the format read once into an int local.
 *
 * symbols:
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x20];
    u8 sizeS;
    u8 sizeT;
    u8 repeat;
    u8 flip;
    u8 fmt;
    u8 pltt0;
    u8 pad26[2];
    u32 key;
} Obj021A195C;

struct Layer;
u32 func_02047388(struct Layer *layer);
u32 func_020473B8(struct Layer *layer);

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;
typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;
typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;
typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;
typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;
typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;
typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;
static inline void G3_TexImageParam(GXTexFmt fmt, GXTexGen gen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    *(volatile u32 *)0x040004A8 = (u32)((addr >> 3) | (fmt << 26) | (gen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}

static inline void G3_TexPlttBase(u32 addr, GXTexFmt fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == GX_TEXFMT_PLTT4)));
    *(volatile u32 *)0x040004AC = param;
}

static inline u32 NNS_GfdGetTexKeyAddr(u32 key) { return (u32)((0x0000FFFF & key) << 3); }
static inline u32 NNS_GfdGetPlttKeyAddr(u32 key) { return (u32)((0x0000FFFF & key) << 3); }

void func_021A195C(Obj021A195C *p)
{
    u32 texKey = func_02047388((struct Layer *)p->key);
    int fmt = p->fmt;

    G3_TexImageParam(fmt, GX_TEXGEN_TEXCOORD, p->sizeS, p->sizeT, p->repeat, p->flip, p->pltt0, NNS_GfdGetTexKeyAddr(texKey));
    G3_TexPlttBase(NNS_GfdGetPlttKeyAddr(func_020473B8((struct Layer *)p->key)), fmt);
}
