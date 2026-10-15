/*
 * function: SHINKA_DEMO_VIEW_DrawGrid
 * address:  0x02207510
 * packet:   pkt_02207510
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Grid of textured quads, rows of 0x12 cells of 0x80 bytes, one push /
 * translate / quad / pop per visible cell.
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

static inline void G3_TexCoord(fx32 s, fx32 t)
{
    REG_TEXCOORD = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

typedef struct Cell {
    u32 f00;
    fx32 s0, s1, t0, t1;
    u8 visible;
    u8 pad15;
    fx16 v[4][3];
    u8 pad2e[0x68 - 0x2e];
    fx32 tx, ty, tz;
    u8 pad74[0x80 - 0x74];
} Cell;

typedef struct Row {
    Cell cell[0x12];
} Row;

typedef struct Grid {
    u8 pad00[0x14];
    u32 tex;
    u32 pltt;
    fx32 x, y, z;
    u8 pad28[0x74 - 0x28];
    Row row[0x12];
    u8 rows;
} Grid;

void SHINKA_DEMO_VIEW_DrawGrid(Grid *w, u16 heap)
{
    int j;
    int i;
    Cell *c;

    REG_TEXIMAGE_PARAM = (w->tex >> 3) | 0x6E430000;
    REG_TEXPLTT_BASE = w->pltt >> 4;
    j = 0;
    REG_MTX_PUSH = j;
    G3_Translate(w->x, w->y, w->z);
    REG_POLYGON_ATTR = 0x001F0080;
    for (; j < w->rows; j++) {
        for (i = 0; i < 0x12; i++) {
            c = &w->row[j].cell[i];
            if (c->visible != 0) {
                REG_MTX_PUSH = 0;
                G3_Translate(c->tx, c->ty, c->tz);
                REG_BEGIN_VTXS = 1;
                REG_NORMAL = 0x20000000;
                G3_TexCoord(c->s0, c->t0);
                G3_Vtx(c->v[0][0], c->v[0][1], c->v[0][2]);
                G3_TexCoord(c->s0, c->t1);
                G3_Vtx(c->v[1][0], c->v[1][1], c->v[1][2]);
                G3_TexCoord(c->s1, c->t1);
                G3_Vtx(c->v[2][0], c->v[2][1], c->v[2][2]);
                G3_TexCoord(c->s1, c->t0);
                G3_Vtx(c->v[3][0], c->v[3][1], c->v[3][2]);
                REG_END_VTXS = 0;
                REG_MTX_POP = 1;
            }
        }
    }
    REG_MTX_POP = 1;
}
