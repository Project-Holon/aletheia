/*
 * function: func_0218DC84
 * address:  0x0218DC84
 * packet:   pkt_ov021_0218DC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DD9E0     0x021DD9E0  data ov021 a2
 *   g_021DD9E0     0x021DD9E0  data ov021 a2
 *   func_021A7360  0x021A7360  thumb ov021
 */

typedef unsigned short u16;

extern u16 d_021DD9E0[];
extern u16 g_021DD9E0[];
typedef unsigned int   u32;
struct D;
extern u32 *func_021A7360(const struct D *p, u32 c, u32 heap);

void func_0218DC84(int a, int b, const int *q, int c)
{
    int x;
    int y;

    d_021DD9E0[1] = a;
    x = q[0];
    if (x == -1) {
        d_021DD9E0[0] = d_021DD9E0[0] & ~0xff;
    } else {
        d_021DD9E0[0] = (d_021DD9E0[0] & ~0xff) | 1;
        d_021DD9E0[3] = x;
    }
    y = q[1];
    if (y == -1) {
        d_021DD9E0[0] = d_021DD9E0[0] & 0xffff00ff;
    } else {
        d_021DD9E0[0] = (d_021DD9E0[0] & 0xffff00ff) | 0x100;
        d_021DD9E0[5] = y;
    }
    func_021A7360((const struct D *)g_021DD9E0, b, (u16)c);
}
