/*
 * function: FIELD_G3D_MAPPER_AppendMatrix
 * address:  0x0218CD20
 * packet:   pkt_ov021_0218CD20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Appends a block of tile columns to the map grid and remaps cell indices.
 *
 * Map cells are 4-byte structs (Tile): the cell copies are struct
 * assignments, which is what gives the copy loops the image's load order
 * and colours. The block's own cells are plain words (.v store).
 *
 * symbols:
 *   MAP_MATRIX_GetWidth  0x02159BF4  thumb
 *   MAP_MATRIX_GetHeight  0x02159BF8  thumb
 *   MAP_MATRIX_GetCount  0x02159BFC  thumb
 *   MAP_MATRIX_GetMapGrid  0x02159C20  thumb
 *   func_02159C00  0x02159C00  thumb
 *   func_02030734  0x02030734  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   FIELD_G3D_MAPPER_IsCellUsed  0x0218DD84  thumb  ov021
 *   gFieldG3dMapperSrcName     0x021DD9EC  data   a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 v;
} Tile;

typedef struct {
    u8 pad0[0x18];
    u32 pos;
    u8 pad1[0x28 - 0x1C];
} Ent;

typedef struct {
    u16 heap;
    u8 pad0[0x12];
    u16 w;
    u16 h;
    u32 n;
    Tile *tiles;
    u32 pad1;
    Ent *ents;
    u8 pad2[0x2E - 0x28];
    u16 nEnts;
    u32 pos;
} Map;

extern u16 MAP_MATRIX_GetWidth(void *p);
extern u16 MAP_MATRIX_GetHeight(void *p);
extern int MAP_MATRIX_GetCount(void *p);
extern u32 *MAP_MATRIX_GetMapGrid(void *p);
extern void func_02159C00(void *p, u8 w, u8 h);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
struct BigObj;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetFieldWork(const struct BigObj *p);
extern int FIELD_G3D_MAPPER_IsCellUsed(u32 a);
extern char gFieldG3dMapperSrcName[];

int FIELD_G3D_MAPPER_AppendMatrix(u32 a, Map *m, void *blk)
{
    u32 *src;
    u32 nn;
    Tile *buf;
    u32 q;
    u32 p;
    u16 nh;
    int bh;
    u16 nw;
    u16 bw;
    int bn;
    u32 k;
    u32 w;
    Ent *e;
    int i;
    int j;

    bw = MAP_MATRIX_GetWidth(blk);
    bh = MAP_MATRIX_GetHeight(blk);
    bn = MAP_MATRIX_GetCount(blk);
    src = MAP_MATRIX_GetMapGrid(blk);
    nw = m->w + bw;
    nh = m->h;
    nn = m->n + bn;
    if (nh != bh)
        return 0;
    if (nn > 900 || nw > 30 || nh > 30)
        return 0;

    buf = func_02030734((u16)((m->heap & 0x7FFF) | 0x8000), nn * 4, 0, gFieldG3dMapperSrcName, 0x25F);
    for (i = 0; i < m->h; i++) {
        for (j = 0; j < m->w; j++)
            buf[i * nw + j] = m->tiles[i * m->w + j];
    }
    for (i = 0; i < bh; i++) {
        for (j = 0; j < bw; j++)
            buf[i * nw + m->w + j].v = src[i * bw + j];
    }
    for (k = 0; k < nn; k++)
        m->tiles[k] = buf[k];

    w = m->w;
    p = m->pos;
    m->pos = p % w + p / w * nw;
    for (i = 0; i < m->nEnts; i++) {
        if (FIELD_G3D_MAPPER_IsCellUsed((u32)(&m->ents[i].pos))) {
            w = m->w;
            e = &m->ents[i];
            q = e->pos;
            e->pos = q % w + q / w * nw;
        }
    }
    m->w = nw;
    m->h = nh;
    m->n = nn;
    func_02159C00((void *)GAME_DATA_GetFieldWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), nw, nh);
    func_020307B0(buf);
    return 1;
}
