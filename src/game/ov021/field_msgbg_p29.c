/*
 * file:     field_msgbg_p29.c
 * unit:     yes
 * function: func_0218CA78, func_0218CB34, func_0218CC34, func_0218CC64, func_0218CD20, func_0218CEE0, func_0218CEE4, func_0218D05C, func_0218D0D8, func_0218D104, func_0218D13C, func_0218D158, func_0218D168, func_0218D1D0
 * address:  0x0218CA78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218DD70  0x0218DD70  thumb ov021
 *   func_0218D304  0x0218D304  thumb ov021
 *   func_0218D444  0x0218D444  thumb ov021
 *   func_0218D570  0x0218D570  thumb ov021
 *   func_0218D7A8  0x0218D7A8  thumb ov021
 *   func_0216932C  0x0216932C  thumb ov010
 *   sub_0207C768   0x0207C768  arm
 *   func_0218DE78  0x0218DE78  thumb  ov021
 *   func_02169520  0x02169520  thumb  ov010
 *   func_02169308  0x02169308  thumb  ov010
 *   func_0218DEFC  0x0218DEFC  thumb  ov021
 *   func_0218DF80  0x0218DF80  thumb  ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0218B83C  0x0218B83C  thumb  ov021
 *   func_021A73DC  0x021A73DC  thumb  ov021
 *   func_0218DEF0  0x0218DEF0  thumb  ov021
 *   func_0218DFE0  0x0218DFE0  thumb ov021
 *   func_02169510  0x02169510  thumb ov010
 *   func_02169500  0x02169500  thumb ov010
 *   func_02169354  0x02169354  thumb ov010
 *   func_0218B88C  0x0218B88C  thumb ov021
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
 *   func_0218DC84  0x0218DC84  thumb  ov021
 *   d_021D3DDC     0x021D3DDC  data
 *   func_0218DD14  0x0218DD14  thumb  ov021
 *   func_02169148  0x02169148  thumb  ov010
 *   func_0216937C  0x0216937C  thumb  ov010
 *   func_021693B4  0x021693B4  thumb  ov010
 *   func_021693C4  0x021693C4  thumb  ov010
 *   func_0218BB04  0x0218BB04  thumb  ov021
 *   func_021693CC  0x021693CC  thumb ov010
 *   func_021693BC  0x021693BC  thumb ov010
 *   func_021693A0  0x021693A0  thumb ov010
 *   func_0216928C  0x0216928C  thumb ov010
 *   func_0218DD38  0x0218DD38  thumb ov021
 *   func_021A73C0  0x021A73C0  thumb ov021
 *   func_02022040  0x02022040  thumb
 *   func_021694FC  0x021694FC  thumb ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218DD80  0x0218DD80  thumb  ov021
 *   func_0218DD9C  0x0218DD9C  thumb  ov021
 */
#include "../../matched/include/Obj00806.h"
#include "../../matched/include/Obj00807.h"
#include "../../matched/include/Obj02072.h"
#include "../../matched/include/Obj19549.h"
#include "../../matched/include/Obj01208.h"
#include "../../matched/include/Obj12581.h"
#include "../../matched/include/Obj07415.h"
#include "../../matched/include/Obj19550.h"
#include "../../matched/include/Obj07416.h"
#include "../../matched/include/Obj01846.h"
#include "../../matched/include/Obj02687.h"

struct Elem;
struct Cam;
struct Cell;
struct Obj;
struct V3;
struct BigObj;
struct Ctx;
struct Mgr;
struct Tagged;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    int h;
    unsigned char pad[0x24];
} Ent_0218CC34;

typedef struct {
    unsigned char pad[0x1C];
    int f1C;
    int f20;
    Ent_0218CC34 *f24;
    unsigned char pad2[6];
    unsigned short n;
} S;

typedef struct {
    u32 v;
} Tile;

typedef struct {
    u8 pad0[0x18];
    u32 pos;
    u8 pad1[0x28 - 0x1C];
} Ent_0218CD20;

typedef struct {
    u16 heap;
    u8 pad0[0x12];
    u16 w;
    u16 h;
    u32 n;
    Tile *tiles;
    u32 pad1;
    Ent_0218CD20 *ents;
    u8 pad2[0x2E - 0x28];
    u16 nEnts;
    u32 pos;
} Map;

typedef struct Cfg {
    u32 size;
    u32 texSize;
    u32 f08;
    void *f0c;
    u32 f10;
    u16 nA;
    u16 nB;
    u32 f18;
    u32 f1c;
} Cfg;

typedef struct Src {
    int f00;
    int f04;
    u16 cols;
    u16 rows;
    u32 type;
    int f10;
    u16 f14;
    u16 f16;
    u32 n;
    int f1c;
    int f20;
    int f24[2];
    int f2c[2];
    int f34;
    u8 f38;
} Src;

typedef struct Obj {
    u16 heap;
    u16 pad02;
    int f04;
    int f08;
    u32 type;
    int f10;
    u16 f14;
    u16 f16;
    u32 n;
    int f1c;
    int f20;
    u8 *f24;
    void *f28;
    u8 f2c;
    u8 f2d;
    u16 f2e;
    u8 pad30[0x40 - 0x30];
    u8 f40;
    u8 pad41;
    u8 f42;
    u8 f43;
    void *f44;
    u8 pad48[0x60 - 0x48];
    int f60;
    int f64;
    int f68;
} Obj;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32_0218D0D8;

typedef signed int     s32_0218D104;

typedef signed int     s32_0218D13C;

typedef int s32_0218D158;

typedef struct V3 { s32_0218D158 x, y, z; } V3;

typedef struct T {
    char pad[0x34];
    V3 v;
} T;

typedef signed int     s32_0218D1D0;

typedef struct Elem { int idx; int x; int y; int z; } Elem;

extern int func_0218DD70(unsigned int a);
extern void func_0218D304(char *p, int *v, struct Elem *e);
extern void func_0218D444(char *p, int *a, struct Elem *e);
extern void func_0218D570(struct Obj *p, struct Cam *cam, struct Cell *cells);
extern int func_0218D7A8(struct Obj *p, struct Cell *nc);
extern int func_0216932C(int a0);
extern u32 sub_0207C768(u32 a, u32 b);
extern void func_0218DE78(char *p);
extern int func_02169520(int a0, int a1);
extern void func_02169308(u8 *p);
extern void func_0218DEFC(char *p, int o, int i);
extern void func_0218DF80(u8 *a);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0218B83C(char *p);
extern void func_021A73DC(u32 *s);
void func_0218DEF0(char *p);
extern int func_0218DFE0(u8 *a, u32 idx, int flag, u32 *out);
extern void func_02169510(u8 *src, struct V3 *dst);
extern void func_02169500(u8 *p, u8 *q);
extern int func_02169354(int o, int a);
extern void func_0218B88C(unsigned char *p);
extern u16 func_02159BF4(void *p);
extern u16 func_02159BF8(void *p);
extern int func_02159BFC(void *p);
extern u32 *func_02159C20(void *p);
extern void func_02159C00(void *p, u8 w, u8 h);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012974(const struct BigObj *p);
extern int func_0218DD84(u32 a);
extern int func_0218DC84(int a, int b, const int *q, int c);
extern void func_0218DD14(int *dst, char *src, int a, int b);
extern struct Mgr *func_02169148(const struct Cfg *cfg, u32 heap);
extern void func_0216937C(u8 *p, int a, int b);
extern void func_021693B4(char *p, int v);
extern void func_021693C4(char *p, int v);
extern u8 *func_0218BB04(u8 *p);
extern void func_021693CC(char *p);
extern void func_021693BC(char *p);
extern void func_021693A0(int o);
extern void func_0216928C(void *p);
extern void func_0218DD38(void **a);
extern void func_021A73C0(int p);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02022040(u16 *pal, int n, const u8 *table);
extern void *func_02046DB8(u32 a0, u32 a1);
extern u32 func_020470A8(void *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern u16 func_021694FC(u8 *p);
extern void func_0218DD80(u8 *p, u32 v);
extern void func_0218DD9C(Elem *e, int x, int y, int z);
void func_0218CA78(char *p);
int func_0218CB34(char *p);
void func_0218CC34(S *p);
void func_0218CC64(char *p, int a, int m);
int func_0218CD20(u32 a, Map *m, void *blk);
void *func_0218CEE0(void *p);
void func_0218CEE4(Obj *p, const Src *src, void *c);
void func_0218D05C(char *p);
int func_0218D0D8(void *a, void *b);
void func_0218D104(u8 *a, u8 *b, void *c);
void func_0218D13C(u8 *a);
void func_0218D158(T *dst, const V3 *src);
int func_0218D168(char *p);
void func_0218D1D0(char *p, void *a, Elem *e);
extern char d_021DD9EC[];
extern char d_021D3DDC[];


void func_0218CA78(char *p)
{
    int i;
    int a;
    int b;

    if (((struct Obj00806 *)p)->f1C == 0)
        return;
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        func_0218DD70((unsigned int)(*(char * *)&((struct Obj00806 *)p)->f28 + i * 16));
    switch (((struct Obj00806 *)p)->fC) {
    case 0:
        func_0218D1D0(p, p + 0x34, ((struct Obj00806 *)p)->f28);
        break;
    case 1:
    default:
        func_0218D304(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 2:
        func_0218D444(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 3:
        func_0218D570((struct Obj *)p, (struct Cam *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    }
    func_0218D7A8((struct Obj *)p, ((struct Obj00806 *)p)->f28);
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        func_0216932C(*(int *)(*(char * *)&((struct Obj00806 *)p)->f24 + i * 0x28));
    a = sub_0207C768(((struct Obj00806 *)p)->f34, ((struct Obj00806 *)p)->f4);
    b = sub_0207C768(((struct Obj00806 *)p)->f3C, ((struct Obj00806 *)p)->f4);
    ((struct Obj00806 *)p)->f30 = (a >> 12) + (b >> 12) * ((struct Obj00806 *)p)->f14;
}


/*
 * Addresses are Black-image addresses.
 */
int func_0218CB34(char *p)
{
    int i;
    int r;
    int x;
    int y;
    u16 *h;

    if (((struct Obj00807 *)p)->f1C == 0)
        return 0;
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++)
        func_0218DD70((unsigned int)(*(char * *)&((struct Obj00807 *)p)->f28 + i * 16));
    switch (((struct Obj00807 *)p)->fC) {
    case 0:
        func_0218D1D0(p, p + 0x34, ((struct Obj00807 *)p)->f28);
        break;
    case 1:
    default:
        func_0218D304(p, (int *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    case 2:
        func_0218D444(p, (int *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    case 3:
        func_0218D570((struct Obj *)p, (struct Cam *)(p + 0x34), ((struct Obj00807 *)p)->f28);
        break;
    }
    func_0218D7A8((struct Obj *)p, ((struct Obj00807 *)p)->f28);
    r = 0;
    func_0218DE78(p);
    for (i = 0; i < ((struct Obj00807 *)p)->f2E; i++) {
        func_02169520(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), (int)(&h));
        if (*h == 1)
            r = 1;
        func_02169308((u8 *)(*(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28)));
        func_0218DEFC(p, *(int *)(*(char * *)&((struct Obj00807 *)p)->f24 + i * 0x28), i);
    }
    func_0218DF80((u8 *)p);
    x = func_0207C768(((struct Obj00807 *)p)->f34, ((struct Obj00807 *)p)->f4);
    y = func_0207C768(((struct Obj00807 *)p)->f3C, ((struct Obj00807 *)p)->f4);
    ((struct Obj00807 *)p)->f30 = (x >> 12) + (y >> 12) * ((struct Obj00807 *)p)->f14;
    func_0218B83C(((struct Obj00807 *)p)->f64);
    if (((struct Obj00807 *)p)->f68 != 0)
        func_021A73DC(((struct Obj00807 *)p)->f68);
    return r;
}


void func_0218CC34(S *p)
{
    int i;
    if (p->f1C != 0) {
        for (i = 0; i < p->n; i++)
            func_02169308((u8 *)p->f24[i].h);
        func_0218DEF0((char *)p);
    }
}


void func_0218CC64(char *p, int a, int m)
{
    int w[3];
    int v[3];
    int idx;
    int i;
    u8 *c;

    if (m == 0 && ((struct Obj02072 *)p)->f40 == 0)
        return;
    for (i = 0; i < ((struct Obj02072 *)p)->f2E; i++) {
        if (func_0218DFE0((u8 *)p, i, m, (u32 *)(&idx))) {
            int r;
            c = (u8 *)p + 0x43;
            func_02169510((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (struct V3 *)w);
            v[0] = w[0] + ((struct Obj02072 *)p)->f54;
            v[1] = w[1] + ((struct Obj02072 *)p)->f58;
            v[2] = w[2] + ((struct Obj02072 *)p)->f5C;
            func_02169500((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (u8 *)v);
            r = func_02169354(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28), a);
            func_02169500((u8 *)(*(int *)(*(char * *)&((struct Obj02072 *)p)->f24 + idx * 0x28)), (u8 *)w);
            if (r != 0 && ((struct Obj02072 *)p)->f43 < ((struct Obj02072 *)p)->f2E)
                *c = *c + 1;
        }
    }
    if (m == 1)
        func_0218B88C((unsigned char *)(((struct Obj02072 *)p)->f64));
}


/*
 * Appends a block of tile columns to the map grid and remaps cell indices.
 *
 * Map cells are 4-byte structs (Tile): the cell copies are struct
 * assignments, which is what gives the copy loops the image's load order
 * and colours. The block's own cells are plain words (.v store).
 *
 * Addresses are Black-image addresses.
 */
int func_0218CD20(u32 a, Map *m, void *blk)
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
    Ent_0218CD20 *e;
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
        if (func_0218DD84((u32)(&m->ents[i].pos))) {
            w = m->w;
            e = &m->ents[i];
            q = e->pos;
            e->pos = q % w + q / w * nw;
        }
    }
    m->w = nw;
    m->h = nh;
    m->n = nn;
    func_02159C00((void *)func_02012974(func_020120F4(func_02188C80((void *)a))), nw, nh);
    func_020307B0(buf);
    return 1;
}


/*
 * Unlabelled 4-byte getter (ldr r0, [r0, #0x70]; bx lr), a leaf of
 * ov043 func_021F36C0.
 */
void *func_0218CEE0(void *p)
{
    return ((struct Obj19549 *)p)->f70;
}


/*
 * Addresses are Black-image addresses.
 *
 * src is const: that lets the scheduler pull the long-lived field loads
 * (n, type, cols, rows) above the stores into p, as in the image.
 */
void func_0218CEE4(Obj *p, const Src *src, void *c)
{
    Cfg cfg;
    int i;
    int off;
    int h;

    p->f04 = src->f00;
    p->f08 = src->f04;
    p->f10 = src->f10;
    p->f14 = src->f14;
    p->f16 = src->f16;
    p->n = src->n;
    p->type = src->type;
    p->f1c = src->f1c;
    p->f2c = src->cols;
    p->f2d = src->rows;
    p->f2e = src->cols * src->rows;
    p->f40 = src->f38;
    p->f42 = p->f2e;
    p->f43 = p->f2e;
    switch (src->type) {
    case 0:
        if (src->n > p->f2e)
            p->type = 1;
        break;
    case 3:
        if (p->f14 * p->f16 > p->f2e / 2)
            p->type = 1;
        break;
    }
    p->f20 = src->f20;
    func_0218D104((u8 *)p, (u8 *)src, c);
    p->f68 = func_0218DC84(p->f2e, p->f60, src->f2c, p->heap);
    cfg.size = src->f34;
    cfg.texSize = 0;
    cfg.f08 = (u32)d_021D3DDC;
    cfg.f0c = 0;
    cfg.f10 = 0x800;
    cfg.nA = 0x20;
    cfg.nB = 0;
    cfg.f18 = 0x1000000;
    cfg.f1c = 0x400000;
    p->f24 = func_02030734(p->heap, p->f2e * 0x28, 1, (const char *)&d_021DD9EC, 0x306);
    p->f28 = func_02030734(p->heap, p->f2e << 4, 1, (const char *)&d_021DD9EC, 0x307);
    p->f44 = func_02030734(p->heap, p->f2e, 1, (const char *)&d_021DD9EC, 0x308);
    for (i = 0; i < p->f2e; i++) {
        off = i * 0x28;
        func_0218DD70((u32)(p->f24 + off + 0x18));
        func_0218DD14((int *)(p->f24 + off + 4), (char *)p, i, p->heap);
        cfg.f0c = p->f24 + off + 4;
        h = (int)func_02169148(&cfg, p->heap);
        *(int *)(p->f24 + off) = h;
        func_0216937C((u8 *)h, p->f10, p->heap);
        if (p->f60 != 0)
            func_021693B4((char *)h, p->f60);
        func_021693C4((char *)h, (int)func_0218BB04((u8 *)p->f64));
    }
}


void func_0218D05C(char *p)
{
    int i;

    if (*(int *)&((struct Obj01208 *)p)->f24 != 0) {
        for (i = 0; i < ((struct Obj01208 *)p)->f2E; i++) {
            int off = i * 0x28;
            func_021693CC((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_021693BC((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_021693A0(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off));
            func_0216928C((void *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_0218DD38((void **)(*(char * *)&((struct Obj01208 *)p)->f24 + off + 4));
        }
        func_020307B0(((struct Obj01208 *)p)->f24);
        func_020307B0(((struct Obj01208 *)p)->f28);
        func_020307B0(((struct Obj01208 *)p)->f44);
        *(int *)&((struct Obj01208 *)p)->f28 = 0;
        *(int *)&((struct Obj01208 *)p)->f24 = 0;
        *(int *)&((struct Obj01208 *)p)->f44 = 0;
        ((struct Obj01208 *)p)->f2E = 0;
    }
    if (((struct Obj01208 *)p)->f68 != 0) {
        func_021A73C0(((struct Obj01208 *)p)->f68);
        ((struct Obj01208 *)p)->f68 = 0;
    }
    func_0218D13C((u8 *)p);
}


/*
 * 2026-10-01: MATCH, capped only by the call to func_02022040 (arm9, Thumb,
 * unlabelled, no witness outside this function). It is a ~64+ byte RGB555
 * pixel converter (luma weights 76/151/29 over a lookup table); filing it
 * as an arm9 witness would lift this to EXACT.
 */
int func_0218D0D8(void *a, void *b)
{
    u8 *p = func_0206E964(func_02046F48(a));
    if (p != 0) {
        u32 size = ((struct Obj12581 *)p)->f30 << 3;
        u32 off = ((struct Obj12581 *)p)->f38;
        if (b != 0)
            func_02022040((u16 *)(p + off), size >> 1, b);
        return 1;
    }
    return 0;
}


void func_0218D104(u8 *a, u8 *b, void *c)
{
    u32 v = ((struct Obj19550 *)b)->f20;
    if (v != 0) {
        if (v == 1) {
            u32 *q = (u32 *)(b + 0x24);
            ((struct Obj07415 *)a)->f60 = (u32)func_02046DB8(q[0], q[1]);
            if (c != 0)
                func_0218D0D8((void *)(((struct Obj07415 *)a)->f60), c);
            func_020470A8((void *)(((struct Obj07415 *)a)->f60));
        }
    } else {
        ((struct Obj07415 *)a)->f60 = 0;
    }
}


void func_0218D13C(u8 *a)
{
    if (((struct Obj07416 *)a)->f60 != 0) {
        func_020470D0((u32 *)(((struct Obj07416 *)a)->f60));
        func_02046EFC((struct Tagged *)(((struct Obj07416 *)a)->f60));
        ((struct Obj07416 *)a)->f60 = 0;
    }
}


static inline void set3(V3 *d, s32_0218D158 x, s32_0218D158 y, s32_0218D158 z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}


/*
 * Copies a vector into dst+0x34 through an inline set3 helper with a const
 * source.  The image's c,b,a load order with the b,a,c store order needs
 * both: without const (or with plain statements or locals) the stores come
 * out in a,b,c order.  EXACT* only for the 2-byte alignment pad.
 */
void func_0218D158(T *dst, const V3 *src)
{
    set3(&dst->v, src->x, src->y, src->z);
}


int func_0218D168(char *p)
{
    int v[3];
    unsigned int i;

    for (i = 0; i < ((struct Obj01846 *)p)->f2E; i++) {
        if (func_021694FC((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28)))) {
            int h;
            int x;
            int z;
            int x0;
            int x1;
            int z0;
            int z1;
            func_02169510((u8 *)(*(int *)(*(char * *)&((struct Obj01846 *)p)->f24 + i * 0x28)), (struct V3 *)v);
            h = *(int *)&((struct Obj01846 *)p)->f4 / 2;
            x = v[0];
            z = v[2];
            x0 = x - h;
            z0 = z - h;
            x1 = x + h;
            z1 = z + h;
            if (((struct Obj01846 *)p)->f34 >= x0 && ((struct Obj01846 *)p)->f34 < x1
                && ((struct Obj01846 *)p)->f3C >= z0 && ((struct Obj01846 *)p)->f3C < z1)
                return i;
        }
    }
    return 0;
}


static inline s32_0218D1D0 FX_Mul(s32_0218D1D0 a, s32_0218D1D0 b)
{
    return (s32_0218D1D0)(((long long)a * b + 0x800LL) >> 12);
}


void func_0218D1D0(char *p, void *a, Elem *e)
{
    int r;
    int c;
    int idx;
    int col;
    u32 rows;
    u32 n;
    int base;
    u32 row;
    int y;
    int t;
    int s;

    n = ((struct Obj02687 *)p)->f14 * ((struct Obj02687 *)p)->f16;
    rows = ((struct Obj02687 *)p)->f18 / n;
    if (((struct Obj02687 *)p)->f18 % n != 0)
        rows++;
    s = ((struct Obj02687 *)p)->f4;
    base = func_0207C768(((struct Obj02687 *)p)->f4, 0x2000);
    idx = 0;
    t = ((struct Obj02687 *)p)->f8;
    for (row = 0; row < rows; row++) {
        for (col = 0; col < n; col++) {
            y = FX_Mul(row << 12, t);
            c = col % ((struct Obj02687 *)p)->f14;
            r = col / ((struct Obj02687 *)p)->f14;
            if (idx >= ((struct Obj02687 *)p)->f18)
                idx = -1;
            func_0218DD80((u8 *)(e + idx), idx);
            func_0218DD9C(e + idx, base + FX_Mul(c << 12, s), y, base + FX_Mul(r << 12, s));
            idx++;
        }
    }
}
