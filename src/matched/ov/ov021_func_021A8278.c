/*
 * function: func_021A8278
 * address:  0x021A8278
 * packet:   pkt_ov021_021A8278
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A8268  0x021A8268  thumb
 *   func_0218C88C  0x0218C88C  thumb
 *   func_0218C990  0x0218C990  thumb
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned short u16;

typedef struct {
    int pad[10];
    int f28;
} S;

extern int func_021A8268(S *s);
extern void func_0218C88C(int a, int b, int c);
extern int func_0218C990(int a, u16 *v);
extern void func_020061E4(int x);

void func_021A8278(S *s)
{
    u16 v;
    if (func_021A8268(s)) {
        func_0218C88C(s->f28, 0, 0);
        if (func_0218C990(s->f28, &v)) {
            func_020061E4(v);
        }
    }
}
