/*
 * function: func_0215D2A4
 * address:  0x0215D2A4
 * packet:   pkt_ov010_0215D2A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215D1E4  0x0215D1E4  thumb  ov010
 *   d_02172900     0x02172900  data
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    void *f00;
    u32 pad04[2];
    u32 f0c;
    u32 pad10[9];
    u32 f34;
    u32 f38;
    u32 f3c;
} A;

typedef struct {
    void *f00;
    u32 f04;
    u32 f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
    u8 f10;
    u8 pad11[7];
    u32 f18;
} B;

typedef struct {
    void *f0;
    u32 f4;
    A *f8;
    B *fC;
    u32 f10;
} Ctx;

typedef unsigned short u16;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0200CA1C(void *);
extern u32 func_0200CA38(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0201AA18(void *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_0215D1E4(void *, u32 *, Ctx *);
extern const char d_02172900[];

void *func_0215D2A4(void *a, u32 b, u32 c)
{
    void *r7 = func_020120F4(a);
    void *v = func_02012934(r7);
    u32 w = func_0200CA1C(r7);
    A *x = func_02030734(4, 0x98, 0, d_02172900, 0x22B);
    B *y;
    Ctx *ctx;
    void *h;
    x->f00 = v;
    x->f34 = 0x12;
    x->f38 = 0;
    x->f3c = 0;
    y = func_02030734(4, 0x28, 0, d_02172900, 0x232);
    y->f00 = x->f00;
    y->f04 = x->f0c;
    y->f08 = (u32)r7;
    y->f0c = 1;
    y->f0e = func_0201AA18(v);
    y->f0d = 0;
    y->f10 = 0;
    y->f0f = 0;
    y->f18 = func_0200CA38(w);
    h = func_020122C0(a, 0, (void *)func_0215D1E4, 0x14);
    ctx = func_020124E8(h);
    ctx->f0 = a;
    ctx->f4 = b;
    ctx->f8 = x;
    ctx->fC = y;
    ctx->f10 = c;
    return h;
}
