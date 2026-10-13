/*
 * function: func_02208AB0
 * address:  0x02208AB0
 * packet:   pkt_02208AB0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * promoted: from src/pending on 2026-09-27, no C change. Its blocker, the
 *   two calls to the unlabelled ARM leaf 0x0204784C (sites +0x8E, +0x98),
 *   closed when that leaf was seeded in layout/function_starts.txt and
 *   matched (src/matched/G3D_SYSTEM_SetObjectAnimeFrame.c); all 11 relocations resolve.
 *
 * symbols:
 *   d_02208EC0 0x02208EC0 data
 *   func_022086C8 0x022086C8 thumb ov195
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_020489F4 0x020489F4 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef s32 fx32;

typedef struct Node {
    u16 id;
    u16 pad02;
    fx32 tx, ty, tz;
    fx32 sx, sy, sz;
    u8 mtx[0x24];
    u32 f40;
} Node;

typedef struct Anim {
    u16 heap;
    u8 pad02[0x12];
    void *res;
    u16 f18;
    u16 f1a;
    u16 count;
    u16 pad1e;
    Node *nodes;
    u32 f24;
    u32 f28;
} Anim;

extern char d_02208EC0[];
extern Node *func_022086C8(u16 heap, u16 n);
extern u16 G3D_UTIL_AddUnit(void *res, void *name);
struct G3dSys;
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A18(u8 *a0, int i);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

void func_02208AB0(Anim *p)
{
    u32 x;
    void *q;
    u16 i;
    Node *n;
    u16 id;

    p->f18 = G3D_UTIL_AddUnit(p->res, d_02208EC0);
    p->count = 1;
    p->nodes = func_022086C8(p->heap, p->count);
    id = func_020489F4(p->res, p->f18);
    n = p->nodes;
    p->f1a = 0;
    n->id = id;
    n->tx = 0;
    n->ty = 0;
    n->tz = 0;
    n->f40 = 1;
    for (i = 0; i < p->count; i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(p->res, p->nodes[i].id), 0);
    p->f24 = 0;
    q = (void *)func_02048A18(p->res, p->nodes[p->f1a].id);
    x = 0;
    p->f28 = 0;
    G3D_SYSTEM_EnableObjectAnime(q, 1);
    G3D_SYSTEM_EnableObjectAnime(q, 2);
    G3D_SYSTEM_SetObjectAnimeFrame(q, 1, (s32 *)(&x));
    G3D_SYSTEM_SetObjectAnimeFrame(q, 2, (s32 *)(&x));
}
