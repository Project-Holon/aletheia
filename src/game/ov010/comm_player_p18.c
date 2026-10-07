/*
 * file:     comm_player_p18.c
 * unit:     yes
 * function: func_02169148, func_0216928C, func_02169308
 * address:  0x02169148
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   func_02046C94  0x02046C94  arm
 *   func_0216990C  0x0216990C  thumb  ov010
 *   d_02172A40     0x02172A40  data
 *   g_020A8140     0x020A8140  data
 *   g_020A8148     0x020A8148  data
 *   func_021693A0  0x021693A0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 */
#include "../../matched/include/Obj12384.h"
#include "../../matched/include/Obj04162.h"

#define F(o) (*(u32 *)((char *)p + (o)))
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

typedef void (*Cb)(u8 *, u32);

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02046C94(void);
extern void func_0216990C(u8 *p);
extern void func_021693A0(int a0);
extern u32 func_020307B0(void *p);
Mgr *func_02169148(const Cfg *cfg, u32 heap);
void func_0216928C(void *p);
void func_02169308(u8 *p);
extern const char d_02172A40[];

extern u32 (*g_020A8140)(u32 size, u32 is4x4, u32 opt);

extern u32 (*g_020A8148)(u32 size, u32 is4pltt, u32 opt);


/*
 * Create the 0xDC-byte effect manager from its Cfg: two record lists,
 * work buffers, and texture/palette VRAM keys through the NNS default
 * allocator hooks. Levers: the buffer size from cfg (not the just-stored
 * copy), and the list terminator cleared through m->head.
 */
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
    func_0216990C((u8 *)m);
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

extern void (*d_020A814C)(u32);

extern void (*d_020A8144)(u32);


void func_0216928C(void *p)
{
    func_021693A0((int)p);
    if (F(0x20) != 0) {
        d_020A814C(F(0x90));
        d_020A8144(F(0x8c));
    }
    func_020307B0((void *)F(0x88));
    func_020307B0((void *)F(0x84));
    func_020307B0((void *)F(0xd4));
    if (((struct Obj12384 *)p)->fA4 != 0)
        func_020307B0((void *)F(0x9c));
    if (((struct Obj12384 *)p)->fA6 != 0)
        func_020307B0((void *)F(0xa0));
    func_020307B0((void *)((u32)p));
}

/*
 * address arithmetic: unsigned 32-bit index scaling and base addition
 * preserve the original lsls/adds wraparound without an invented index bound.
 */
void func_02169308(u8 *p) { Cb cb; if (((struct Obj04162 *)p)->fB0) { cb = *(Cb *)(((struct Obj04162 *)p)->f28+((struct Obj04162 *)p)->f18*16u+4u); if(cb) cb(p,((struct Obj04162 *)p)->fD8); } }
