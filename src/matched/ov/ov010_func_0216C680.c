/*
 * function: func_0216C680
 * address:  0x0216C680
 * packet:   pkt_ov010_0216C680
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02191388  0x02191388  thumb  ov021
 *   func_021914CC  0x021914CC  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 *   func_02045808  0x02045808  arm
 */

typedef unsigned int u32;

extern int func_02191388(int);
extern void func_021914CC(int);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern int func_021912D8(u32 a);
extern int func_021912F8(int);
extern void func_02045808(int);

int func_0216C680(int a, int *st, int *o)
{
    switch (*st) {
    case 0:
        if (!func_02191388(o[5]))
            break;
        (*st)++;
    case 1:
        func_021914CC(o[5]);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        func_021912D8(o[5]);
        (*st)++;
        break;
    case 2:
        if (func_021912F8(o[5]) == 1) {
            func_02045808(o[6]);
            return 1;
        }
        break;
    }
    return 0;
}
