/*
 * function: func_02208570
 * address:  0x02208570
 * packet:   pkt_ov195_02208570
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * One textured quad in immediate geometry: texture image and palette base,
 * push, polygon attributes, translate, scale, four vertices, pop.
 *
 * 2026-10-05 (D8): residue is only the z of the last vertex (v[3][2], offset
 * 0x46, beyond the ldrh immediate range). Original: movs r5,#0x46; ldrsh r6,[r4,r5]
 * then lsls/lsrs #16 before the store (sign load, explicit u16 truncation, not
 * folded). Ours folds to adds/adds/ldrh and stores r6 directly (6 bytes
 * shorter in that block, so the early skip branch differs only by length).
 * Everything before it is byte-identical. Tried: fx16 local, s32 local for z,
 * raw *(s16 *)((u8 *)p + 0x46). None changes the load form. The first three
 * z values (offsets 0x3a, 0x40) fold to ldrh in the original, so the last one
 * likely has a second signed use or a different source type; not found.
 *
 * 2026-10-05 (D9-14): closed, EXACT. The z of the third vertex (offset 0x46; the
 * D8 note said v[3][2], it is v[2][2]) is read into an int local after the third
 * texcoord and passed to G3_Vtx. The int local keeps the sign-extending load
 * (ldrsh) and the explicit u16 truncation after the x/y store. An fx16 local in the
 * same place folds to ldrh (81 bytes); the local read before G3_TexCoord gives the
 * ldrsh but schedules it into the texcoord block (29 bytes).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
typedef s16 fx16;
typedef volatile u32 vu32;

#define REG_MTX_PUSH       (*(vu32 *)0x04000444)
#define REG_MTX_POP        (*(vu32 *)0x04000448)
#define REG_MTX_SCALE      (*(vu32 *)0x0400046C)
#define REG_MTX_TRANS      (*(vu32 *)0x04000470)
#define REG_NORMAL         (*(vu32 *)0x04000484)
#define REG_TEXCOORD       (*(vu32 *)0x04000488)
#define REG_VTX_16         (*(vu32 *)0x0400048C)
#define REG_POLYGON_ATTR   (*(vu32 *)0x040004A4)
#define REG_TEXIMAGE_PARAM (*(vu32 *)0x040004A8)
#define REG_TEXPLTT_BASE   (*(vu32 *)0x040004AC)
#define REG_BEGIN_VTXS     (*(vu32 *)0x04000500)
#define REG_END_VTXS       (*(vu32 *)0x04000504)

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

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

typedef struct Quad {
    u32 tex;
    u32 pltt;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u32 polyId;
    fx32 s0, s1, t0, t1;
    u8 alpha;
    u8 pad35;
    fx16 v[4][3];
    u8 f4e;
} Quad;

void func_02208570(Quad *p, u16 heap)
{
    int z;

    if (p->f4e < 0x12) {
        REG_TEXIMAGE_PARAM = (p->tex >> 3) | 0x6E430000;
        REG_TEXPLTT_BASE = p->pltt >> 4;
        REG_MTX_PUSH = 0;
        REG_POLYGON_ATTR = ((p->alpha != 0 ? 2 : 0) << 6) | (p->polyId << 24) | (p->alpha << 16);
        G3_Translate(p->tx, p->ty, p->tz);
        G3_Scale(p->sx, p->sy, p->sz);
        REG_BEGIN_VTXS = 1;
        REG_NORMAL = 0x20000000;
        G3_TexCoord(p->s0, p->t0);
        G3_Vtx(p->v[0][0], p->v[0][1], p->v[0][2]);
        G3_TexCoord(p->s0, p->t1);
        G3_Vtx(p->v[1][0], p->v[1][1], p->v[1][2]);
        G3_TexCoord(p->s1, p->t1);
        z = p->v[2][2];
        G3_Vtx(p->v[2][0], p->v[2][1], z);
        G3_TexCoord(p->s1, p->t0);
        G3_Vtx(p->v[3][0], p->v[3][1], p->v[3][2]);
        REG_END_VTXS = 0;
        REG_MTX_POP = 1;
    }
}
