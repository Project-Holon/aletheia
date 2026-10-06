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

struct S;
struct U16Vec;
extern u32 func_02191388(u32 *a);
extern void func_021914CC(struct S *s);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern int func_021912D8(u32 a);
extern int func_021912F8(u32 a, u32 b, u32 c, u32 d);
extern void func_02045808(struct U16Vec *vec);

int func_0216C680(int a, int *st, int *o, u32 a3)
{
    switch (*st) {
    case 0:
        if (!func_02191388((u32 *)o[5]))
            break;
        (*st)++;
    case 1:
        func_021914CC((struct S *)o[5]);
        if ((func_020362DC() & 3) == 0)
            break;
        func_020061E4(0x547);
        func_021912D8(o[5]);
        (*st)++;
        break;
    case 2:
        if (func_021912F8(o[5], (u32)st, (u32)o, a3) == 1) {
            func_02045808((struct U16Vec *)o[6]);
            return 1;
        }
        break;
    }
    return 0;
}
