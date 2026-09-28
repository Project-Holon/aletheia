/*
 * function: func_02169148
 * address:  0x02169148
 * packet:   pkt_ov010_02169148
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Create the 0xDC-byte effect manager from its Cfg: two record lists,
 * work buffers, and texture/palette VRAM keys through the NNS default
 * allocator hooks. Levers: the buffer size from cfg (not the just-stored
 * copy), and the list terminator cleared through m->head.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_0216990C  0x0216990C  thumb  ov010
 *   d_02172A40     0x02172A40  data
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Cfg {
    u32 size;           /* 0x00 */
    u32 texSize;        /* 0x04 */
    u32 f08;            /* 0x08 */
    u32 f0c;            /* 0x0C */
    u32 f10;            /* 0x10 */
    u16 nA;             /* 0x14 */
    u16 nB;             /* 0x16 */
    u32 f18;            /* 0x18 */
    u32 f1c;            /* 0x1C */
} Cfg;

typedef struct Node {
    u32 f00;
    u32 f04;
} Node;

typedef struct Mgr {
    u8 pad00[0x10];
    u32 f10;            /* 0x10 */
    u8 pad14[0x1C - 0x14];
    u32 size;           /* 0x1C */
    u32 texSize;        /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
    Node *head;         /* 0x2C */
    Node node;          /* 0x30 */
    u8 pad38[0x84 - 0x38];
    void *f84;          /* 0x84 */
    void *f88;          /* 0x88 */
    u32 texKey;         /* 0x8C */
    u32 plttKey;        /* 0x90 */
    u32 f94;            /* 0x94 */
    u8 pad98[4];
    void *listA;        /* 0x9C */
    void *listB;        /* 0xA0 */
    u16 nA;             /* 0xA4 */
    u16 nB;             /* 0xA6 */
    u32 fA8;            /* 0xA8 */
    u32 fAC;            /* 0xAC */
    u8 padB0[0xD4 - 0xB0];
    void *buf;          /* 0xD4 */
    u32 fD8;            /* 0xD8 */
} Mgr;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02046C94(void);
extern void func_0216990C(Mgr *m);
extern const char d_02172A40[];
extern u32 (*g_020A8140)(u32 size, u32 is4x4, u32 opt);
extern u32 (*g_020A8148)(u32 size, u32 is4pltt, u32 opt);

Mgr *func_02169148(const Cfg *cfg, u32 heap)
{
    Mgr *m;
    u32 sz;

    m = sub_02030734(heap, sizeof(Mgr), 1, d_02172A40, 0x6E);
    sz = func_02046C94();
    m->nA = cfg->nA;
    m->nB = cfg->nB;
    m->fA8 = cfg->f18;
    m->fAC = cfg->f1c;
    if (m->nA != 0)
        m->listA = sub_02030734(heap, cfg->nA * 20, 1, d_02172A40, 0x77);
    if (m->nB != 0)
        m->listB = sub_02030734(heap, cfg->nB * 20, 1, d_02172A40, 0x7A);
    func_0216990C(m);
    m->f28 = cfg->f08;
    m->size = cfg->size;
    m->buf = sub_02030734(heap, cfg->size, 1, d_02172A40, 0x86);
    if (cfg->f10 == 0)
        m->f24 = 0x800;
    else
        m->f24 = cfg->f10;
    m->fD8 = cfg->f0c;
    m->head = &m->node;
    m->head->f04 = 0;
    m->f10 = 0;
    m->f84 = sub_02030734(heap, sz, 1, d_02172A40, 0x97);
    m->f88 = sub_02030734(heap, sz, 1, d_02172A40, 0x9A);
    m->f94 = 0;
    if (cfg->texSize != 0) {
        m->texSize = cfg->texSize;
        m->texKey = g_020A8140(cfg->texSize, 0, 0);
        m->plttKey = g_020A8148(0x200, 0, 0);
    } else {
        m->texSize = 0;
        m->texKey = 0;
        m->plttKey = 0;
    }
    return m;
}
