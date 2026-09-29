/*
 * function: func_068994B4
 * address:  0x068994B4
 * packet:   pkt_ov095_068994B4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_06899514  0x06899514  thumb
 *   func_06899524  0x06899524  thumb
 *   func_06899534  0x06899534  thumb
 *   func_06899544  0x06899544  thumb
 *   func_06899554  0x06899554  thumb
 *   func_06899564  0x06899564  thumb
 *   func_06899574  0x06899574  thumb
 *   func_06899584  0x06899584  thumb
 *   func_06899594  0x06899594  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_06899514(int a);
extern int func_06899524(int a);
extern int func_06899534(int a);
extern int func_06899544(int a);
extern int func_06899554(u16 a, int b);
extern int func_06899564(int a, int b);
extern int func_06899574(int a);
extern void func_06899584(int p, int n, int c);
extern void func_06899594(int p, int v);

void func_068994B4(int a0, int a1, int x)
{
    u8 v;
    int q;

    v = func_06899514(4);
    if (x == func_06899524(v) && v != func_06899534(3)
        && func_06899554(func_06899544(0x12), 6) >= 1
        && func_06899564(0x40, 1) != 0) {
        q = func_06899574(0x3f);
        func_06899584(q, 2, 0x320);
        func_06899594(q, v);
    }
}
