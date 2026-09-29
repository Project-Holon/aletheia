/*
 * function: func_021B2488
 * address:  0x021B2488
 * packet:   pkt_ov013_021B2488
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   func_021B2D54  0x021B2D54  arm  ov013
 *   func_021B2AA0  0x021B2AA0  arm  ov013
 *   func_021B2BE0  0x021B2BE0  arm  ov013
 */

typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
    u8 pad[11];
    int fC;
} Ctx;

extern Ctx d_021B60D8;
extern int func_021B2D54(u8 *p, int x);
extern int func_021B2AA0(u8 *p, int x);
extern int func_021B2BE0(u8 *p, int x);

int func_021B2488(int a, u8 *p, int len, int x)
{
    if (len != 0x10)
        return 0;
    if (p[8] != a || p[9] != d_021B60D8.b0)
        return 0;
    if (p[5] != 0x10)
        return func_021B2D54(p, x);
    if (d_021B60D8.fC == 0)
        return func_021B2AA0(p, x);
    return func_021B2BE0(p, x);
}
