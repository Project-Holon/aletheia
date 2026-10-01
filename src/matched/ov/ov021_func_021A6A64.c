/*
 * function: func_021A6A64
 * address:  0x021A6A64
 * packet:   pkt_ov021_021A6A64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D608  0x0216D608  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A6908  0x021A6908  thumb
 */

typedef unsigned short u16;

typedef struct {
    int pad[7];
    int f1c;
} S;

extern u16 func_0216D608(int a);
extern void func_020061E4(int x);
extern int func_021A6908(S *a, int b, int c);

int func_021A6A64(S *a, int b, int c)
{
    if (func_0216D608(a->f1c) == 3) {
        func_020061E4(0x55e);
    }
    return func_021A6908(a, b, c);
}
