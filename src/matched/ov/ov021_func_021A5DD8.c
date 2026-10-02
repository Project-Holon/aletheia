/*
 * function: func_021A5DD8
 * address:  0x021A5DD8
 * packet:   pkt_ov021_021A5DD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A5CA4  0x021A5CA4  thumb  ov021
 *   func_021A5D04  0x021A5D04  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D3CC(void *p);
extern int func_021A5CA4(void *a, void *b, int c, int d, int e, int f);
extern int func_021A5D04(void *a, void *b, int c, int d, int e, int f);

int func_021A5DD8(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A5CA4(a, b, c, d, e, f);
    }
    return func_021A5D04(a, b, c, d, e, f);
}
