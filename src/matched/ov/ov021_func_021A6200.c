/*
 * function: func_021A6200
 * address:  0x021A6200
 * packet:   pkt_ov021_021A6200
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
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_021A607C  0x021A607C  thumb  ov021
 *   func_021A60DC  0x021A60DC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D3CC(void *p);
extern u16 func_0216D5F8(void *p);
extern void func_0216D4B4(void *p);
extern int func_021A607C(void *a, void *b, int c, int d, int e, int f);
extern int func_021A60DC(void *a, void *b, int c, int d, int e, int f);

int func_021A6200(void *a, void *b, int c, int d, int e, int f)
{
    int t = func_0216D5F8(b);
    if (e != 9 && e != t) {
        func_0216D4B4(b);
        return func_021A60DC(a, b, c, d, e, f);
    }
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (e == 9) {
        return func_021A607C(a, b, c, d, e, f);
    }
    return func_021A60DC(a, b, c, d, e, f);
}
