/*
 * function: func_021EF3A4
 * address:  0x021EF3A4
 * packet:   pkt_ov093_021EF3A4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of func_021EF460 (partial sum in a named local, x added last).
 *
 * symbols:
 *   func_021EED00  0x021EED00  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EF40  0x0201EF40  thumb
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data  ov093  a4
 *   d_021F63D8     0x021F63D8  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 t[8];
    u8 pad[0x20];
    u32 f50;
    u32 f54;
} G;

typedef struct {
    u8 pad[0x10];
    u16 f10;
    u8 pad2[6];
    u16 f18;
    u16 f1a;
} H;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fc;
} P;

extern G d_021F6398;
extern H d_021F63D8;
struct WordSet;
extern u8 func_021B8DDC(u32 x);
extern int func_021B8CE8(int a, u8 b, int c);
extern void *func_021B86B8(void ***p);
extern void func_02045CAC(void *s, u16 v, void *buf);
extern void func_021EED00(u8 a, u32 b);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void func_021EF3A4(u32 a, u32 b, P *p)
{
    u8 idx;
    int sel;
    int x;
    u8 k;
    u32 pos;

    idx = p->f8 - 1;
    sel = 0;
    if (p->fc >= 3)
        sel = 2;
    if (p->fc == 2)
        sel = 1;
    b = (u16)(b + (u16)(sel * 0x15));
    k = p->f0;
    if (d_021F63D8.f18 == 0
        && func_021B8CE8(d_021F6398.f00, (u8)d_021F6398.f54, func_021B8DDC(k)) != 0) {
        if (func_021B86B8((void ***)d_021F6398.f00) == 0 || (int)func_021B86B8((void ***)d_021F6398.f00) == 4)
            x = 1;
        else
            x = 2;
    } else {
        x = 0;
    }
    func_021EED00(p->f0, 0);
    func_0201EF40((void *)d_021F6398.f08, 1, p->f4);
    pos = b + idx * 3;
    func_02045CAC((void *)d_021F6398.t[1], pos + x, (void *)d_021F6398.f0c);
    func_0201F250((void *)d_021F6398.f08, (void *)a, (void *)d_021F6398.f0c);
}
