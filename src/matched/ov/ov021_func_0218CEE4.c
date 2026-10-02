/*
 * function: func_0218CEE4
 * address:  0x0218CEE4
 * packet:   pkt_ov021_0218CEE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218D104  0x0218D104  thumb  ov021
 *   func_0218DC84  0x0218DC84  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021D3DDC     0x021D3DDC  data
 *   d_021DD9EC     0x021DD9EC  data
 *   func_0218DD70  0x0218DD70  thumb  ov021
 *   func_0218DD14  0x0218DD14  thumb  ov021
 *   func_02169148  0x02169148  thumb  ov010
 *   func_0216937C  0x0216937C  thumb  ov010
 *   func_021693B4  0x021693B4  thumb  ov010
 *   func_021693C4  0x021693C4  thumb  ov010
 *   func_0218BB04  0x0218BB04  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * src is const: that lets the scheduler pull the long-lived field loads
 * (n, type, cols, rows) above the stores into p, as in the image.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

extern void func_0218D104(u8 *a, u8 *b, void *c);
extern int func_0218DC84(int a, int b, const int *q, int c);
extern void *func_02030734(int, int, int, void *, int);
extern char d_021D3DDC[];
extern int d_021DD9EC;
extern void func_0218DD70(void *e);
extern void func_0218DD14(void *dst, char *src, int a, int b);
extern int func_02169148(Cfg *cfg, u32 heap);
extern void func_0216937C(int h, int a, int b);
extern void func_021693B4(int h, int v);
extern void func_021693C4(int h, int v);
extern int func_0218BB04(int p);

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
    p->f24 = func_02030734(p->heap, p->f2e * 0x28, 1, &d_021DD9EC, 0x306);
    p->f28 = func_02030734(p->heap, p->f2e << 4, 1, &d_021DD9EC, 0x307);
    p->f44 = func_02030734(p->heap, p->f2e, 1, &d_021DD9EC, 0x308);
    for (i = 0; i < p->f2e; i++) {
        off = i * 0x28;
        func_0218DD70(p->f24 + off + 0x18);
        func_0218DD14(p->f24 + off + 4, (char *)p, i, p->heap);
        cfg.f0c = p->f24 + off + 4;
        h = func_02169148(&cfg, p->heap);
        *(int *)(p->f24 + off) = h;
        func_0216937C(h, p->f10, p->heap);
        if (p->f60 != 0)
            func_021693B4(h, p->f60);
        func_021693C4(h, func_0218BB04(p->f64));
    }
}
