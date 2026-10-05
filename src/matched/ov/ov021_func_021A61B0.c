/*
 * function: func_021A61B0
 * address:  0x021A61B0
 * packet:   pkt_ov021_021A61B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * 
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A607C  0x021A607C  thumb  ov021
 *   func_021A60DC  0x021A60DC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D3CC(int a0);
extern int func_021A607C(void *a, void *b, int c, int d, u16 e, int f);
extern int func_021A60DC(void *a, void *b, int c, int d, int e, int f);

int func_021A61B0(void *a, void *b, int c, int d, u16 e, int f)
{
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    return func_021A60DC(a, b, c, d, e, f);
}
