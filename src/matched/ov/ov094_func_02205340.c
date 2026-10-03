/*
 * function: func_02205340
 * address:  0x02205340
 * packet:   pkt_ov094_02205340
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_020498F4  0x020498F4  arm
 *   func_02204C98  0x02204C98  thumb  ov094
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

typedef struct Main {
    unsigned char pad00[0x48];
    int f48;
    unsigned char pad4C[0x224 - 0x4C];
    int o224;
    unsigned char pad228[0x22c - 0x228];
    int o22c;
    unsigned char pad230[0x240 - 0x230];
    u16 h240;
    unsigned char pad242[0x25a - 0x242];
    u8 b25a;
    u8 b25b;
} Main;

typedef unsigned int   u32;
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(int a, s16 x, s16 y, int d, int e);
extern void func_020498F4(int a, int b, int c, int d, int e, int f, int g);
extern void func_02204C98(int a, int b, int *w, int *h);

void func_02205340(Main *m, const int *c)
{
    int w;
    int h;

    func_0201DD78(1, 2, 0);
    func_02204C98(c[0], m->o224, &w, &h);
    func_0201C7A4(m->o22c, 0x80 - w / 2, 0x10, c[0], m->o224);
    func_02204C98(c[1], m->o224, &w, &h);
    func_0201C7A4(m->o22c, 0x80 - w / 2, 0x40, c[1], m->o224);
    m->b25a = 1;
    m->b25b = 1;
    func_020498F4(m->f48, 0x6b, 5, 0, 0, 0, m->h240);
}
