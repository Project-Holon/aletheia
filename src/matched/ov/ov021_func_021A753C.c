/*
 * function: FIELD_GROUND_ANIME_AnmEntryBind
 * address:  0x021A753C
 * packet:   pkt_ov021_021A753C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_GetResourceFile  0x02046F48  arm
 *   NNS_G3dGetMdlSet  0x0206E954  arm
 *   func_02047250  0x02047250  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   NNS_G3dAnmObjInit  0x02069C74  arm
 *   NNS_G3dRenderObjAddAnmObj  0x02069E88  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Res { u32 x0, x1; u8 a, cnt; u16 b, c, ofs; } Res;
typedef struct Ctx { u32 flags; u32 *buf; u32 v; } Ctx;

struct Tagged;
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern int NNS_G3dGetMdlSet(int p0);
extern u32 func_02047250(u32 a);
extern void MI_CpuFill8(u32 *p, u32 v, u32 n);
extern void NNS_G3dAnmObjInit(u32 *a, u32 b, u32 c, u32 d);
extern void NNS_G3dRenderObjAddAnmObj(u32 a, u32 *b);

static inline u32 *ent(Res *x, u32 idx)
{
    u8 *y = (u8 *)x + 8;
    if (y != 0 && idx < x->cnt)
        return (u32 *)(y + x->ofs + 4 + idx * 4);
    return 0;
}

static inline u32 res0(Res *x)
{
    u32 *z;
    if (x != 0) {
        z = ent(x, 0);
        if (z != 0)
            return (u32)x + *z;
    }
    return 0;
}

u32 FIELD_GROUND_ANIME_AnmEntryBind(Ctx *s, u32 b, u32 c, u32 d)
{
    u32 r6;
    r6 = res0((Res *)NNS_G3dGetMdlSet((u32)G3D_SYSTEM_GetResourceFile((struct Tagged *)b)));
    if (c != 0)
        c = func_02047250(c);
    else
        c = 0;
    MI_CpuFill8(s->buf, 0, 0x80);
    NNS_G3dAnmObjInit(s->buf, s->v, r6, c);
    NNS_G3dRenderObjAddAnmObj(d, s->buf);
    s->flags = (s->flags & ~1) | 1;
    return s->flags;
}
