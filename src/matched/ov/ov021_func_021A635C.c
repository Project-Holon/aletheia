/*
 * function: func_021A635C
 * address:  0x021A635C
 * packet:   pkt_ov021_021A635C
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A63EC  0x021A63EC  thumb  ov021
 *   func_021A63F0  0x021A63F0  thumb  ov021
 *   func_021A6428  0x021A6428  thumb  ov021
 *   func_021A6454  0x021A6454  thumb  ov021
 *   func_021A6478  0x021A6478  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021A3960(int p);
extern void func_021A63EC(void *a, int b, int c, int d, int e, int f);
extern void func_021A63F0(void *a, int b, int c, int d, int e, int f);
extern void func_021A6428(void *a, int b, int c, int d, int e, int f);
extern void func_021A6454(void *a, int b, int c, int d, int e, int f);
extern void func_021A6478(void *a, int b, int c, int d, int e, int f);

void func_021A635C(int *a, int sel, int c, int d, int e, int f)
{
    int x = func_021A3960(a[5]);
    switch (sel) {
    case 0: func_021A63EC(a, x, c, d, e, f); break;
    case 1: func_021A63F0(a, x, c, d, e, f); break;
    case 2: func_021A6428(a, x, c, d, e, f); break;
    case 3: func_021A6454(a, x, c, d, e, f); break;
    case 4: func_021A6478(a, x, c, d, e, f); break;
    }
}
