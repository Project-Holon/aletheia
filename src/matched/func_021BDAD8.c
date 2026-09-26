/*
 * function: func_021BDAD8
 * address:  0x021BDAD8
 * packet:   pkt_021BDAD8
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02031194  0x02031194  arm
 */

typedef unsigned char u8;

extern int  func_02045770(int x);
extern int  func_0201C6C4(int q, int t);
extern void func_02045334(int x);
extern void func_02031194(int a);

void func_021BDAD8(int a, int **b)
{
    u8   *s = (u8 *)b[0] + 8;
    int   q = *(int *)((char *)b[1] + 0x12c);

    if (s[4]) {
        if (func_0201C6C4(q, func_02045770(*(int *)s)) == 0) {
            func_02045334(*(int *)s);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        if (b[2])
            --*(int *)b[2];
        func_02031194(a);
    }
}
