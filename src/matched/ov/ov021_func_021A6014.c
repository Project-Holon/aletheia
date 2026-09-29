/*
 * function: func_021A6014
 * address:  0x021A6014
 * packet:   pkt_ov021_021A6014
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
 *   func_021A607C  0x021A607C  thumb  ov021
 *   func_021A60DC  0x021A60DC  thumb  ov021
 *   func_021A61B0  0x021A61B0  thumb  ov021
 *   func_021A6200  0x021A6200  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021A607C(void *a, int b, int c, int d, int e, int f);
extern int func_021A60DC(void *a, int b, int c, int d, int e, int f);
extern int func_021A61B0(void *a, int b, int c, int d, int e, int f);
extern int func_021A6200(void *a, int b, int c, int d, int e, int f);

int func_021A6014(int *a, int b, int c, int d, int e)
{
    int sw = a[0];
    int r = 0;
    int p = a[7];
    switch (sw) {
    case 0: r = func_021A607C(a, p, b, c, d, e); break;
    case 1: r = func_021A60DC(a, p, b, c, d, e); break;
    case 2: r = func_021A61B0(a, p, b, c, d, e); break;
    case 3: r = func_021A6200(a, p, b, c, d, e); break;
    }
    return r;
}
