/*
 * function: func_02208478
 * address:  0x02208478
 * packet:   pkt_02208478
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208F68 0x02208F68 data
 *   func_02030734 0x02030734 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;
typedef s16 fx16;

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

extern char d_02208F68[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

Quad *func_02208478(u32 tex, u32 pltt, u16 heap)
{
    Quad *p = func_02030734(heap, sizeof(Quad), 1, d_02208F68, 0xd31);

    p->tex = tex;
    p->pltt = pltt;
    p->tz = 0;
    p->ty = 0;
    p->tx = 0;
    p->sx = 0x2465a;
    p->sy = 0x2465a;
    p->sz = 0x1000;
    p->polyId = 0x3b;
    p->s0 = 0x10000;
    p->t0 = 0x10000;
    p->s1 = 0x70000;
    p->t1 = 0x70000;
    p->alpha = 0x1f;
    p->v[0][0] = -0x800;
    p->v[0][1] = 0x800;
    p->v[0][2] = 0;
    p->v[1][0] = -0x800;
    p->v[1][1] = -0x800;
    p->v[1][2] = 0;
    p->v[2][0] = 0x800;
    p->v[2][1] = -0x800;
    p->v[2][2] = 0;
    p->v[3][0] = 0x800;
    p->v[3][1] = 0x800;
    p->v[3][2] = 0;
    p->f4e = 0;
    return p;
}
