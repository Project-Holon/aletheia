/*
 * function: func_0218CD20
 * address:  0x0218CD20
 * packet:   pkt_ov021_0218CD20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Appends a block of tile columns to the map grid and remaps cell indices.
 *
 * 2026-10-02: same size and ops; prologue, checks and the alloc match.
 * Left: register colour in three places. Copy-back loop: original loads
 * m->tiles before buf[k] (value r1, base r2; ours swapped). m->pos remap:
 * original w in r6, pos in r7 (ours swapped). Ents remap: original keeps
 * w (r6) and e (r7) in registers and spills pos (sp18) and the remainder
 * (sp8), so the product goes to r2 via a copy of nw; ours spills w.
 * First copy loop: original consumes m->w in muls r6,r4,r6, ours copies.
 * Measured inert: declaration order, w/p locals vs direct m-> expressions,
 * operand order of the product, inline Remap helpers (u32/int/u16/pointer),
 * separate loop counters per loop, int vs u32 for k.
 * The index shape m->tiles[j + m->w * i] (vs i * m->w + j) is what puts
 * bw in r7 and bn in r6 as in the original.
 *
 * symbols:
 *   func_02159BF4  0x02159BF4  thumb
 *   func_02159BF8  0x02159BF8  thumb
 *   func_02159BFC  0x02159BFC  thumb
 *   func_02159C20  0x02159C20  thumb
 *   func_02159C00  0x02159C00  thumb
 *   func_02030734  0x02030734  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012974  0x02012974  thumb
 *   func_0218DD84  0x0218DD84  thumb  ov021
 *   d_021DD9EC     0x021DD9EC  data   a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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
    u32 *tiles;
    u32 pad1;
    Ent *ents;
    u8 pad2[0x2E - 0x28];
    u16 nEnts;
    u32 pos;
} Map;

extern u16 func_02159BF4(void *p);
extern u16 func_02159BF8(void *p);
extern int func_02159BFC(void *p);
extern u32 *func_02159C20(void *p);
extern void func_02159C00(void *p, u8 w, u8 h);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_020307B0(void *p);
extern u32 func_02188C80(u32 a);
extern void *func_020120F4(u32 a);
extern void *func_02012974(void *p);
extern int func_0218DD84(u32 *p);
extern char d_021DD9EC[];

int func_0218CD20(u32 a, Map *m, void *blk)
{
    u32 *src;
    u32 nn;
    u32 *buf;
    u16 nh;
    u16 bh;
    u16 nw;
    u16 bw;
    int bn;
    u32 k;
    u32 w;
    Ent *e;
    int i;
    int j;

    bw = func_02159BF4(blk);
    bh = func_02159BF8(blk);
    bn = func_02159BFC(blk);
    src = func_02159C20(blk);
    nw = m->w + bw;
    nh = m->h;
    nn = m->n + bn;
    if (nh != bh)
        return 0;
    if (nn > 900 || nw > 30 || nh > 30)
        return 0;

    buf = func_02030734((u16)((m->heap & 0x7FFF) | 0x8000), nn * 4, 0, d_021DD9EC, 0x25F);
    for (i = 0; i < m->h; i++) {
        for (j = 0; j < m->w; j++)
            buf[i * nw + j] = m->tiles[j + m->w * i];
    }
    for (i = 0; i < bh; i++) {
        for (j = 0; j < bw; j++)
            buf[i * nw + m->w + j] = src[i * bw + j];
    }
    for (k = 0; k < nn; k++)
        m->tiles[k] = buf[k];

    w = m->w;
    m->pos = m->pos % w + m->pos / w * nw;
    for (i = 0; i < m->nEnts; i++) {
        if (func_0218DD84(&m->ents[i].pos)) {
            e = &m->ents[i];
            w = m->w;
            e->pos = e->pos % w + e->pos / w * nw;
        }
    }
    m->w = nw;
    m->h = nh;
    m->n = nn;
    func_02159C00(func_02012974(func_020120F4(func_02188C80(a))), nw, nh);
    func_020307B0(buf);
    return 1;
}
