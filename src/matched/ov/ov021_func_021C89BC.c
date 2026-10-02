/*
 * function: func_021C89BC
 * address:  0x021C89BC
 * packet:   pkt_ov021_021C89BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8AAC  0x021C8AAC  thumb  ov021
 *   func_021C89A8  0x021C89A8  thumb  ov021
 *   func_021C8AD0  0x021C8AD0  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021C8B48  0x021C8B48  thumb  ov021
 *   func_021C8B5C  0x021C8B5C  thumb  ov021
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021C8B14  0x021C8B14  thumb  ov021
 *   func_021C8B78  0x021C8B78  thumb  ov021
 */

extern int func_021C8AAC(int *p);
extern int func_021C89A8(int a);
extern void func_021C8AD0(int *p);
extern int func_0216D454(int a);
extern void func_021C8B48(int *p);
extern int func_021C8B5C(int *p);
extern int func_02006148(int a);
extern void func_020061F8(int a);
extern void func_021C8B14(int *p);
extern void func_021C8B78(int *p);

int func_021C89BC(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        if (func_021C89A8(func_021C8AAC(p)) == 0) {
            *st = 2;
        } else {
            *st = 1;
        }
        break;
    case 1:
        func_021C8AD0(p);
        if (func_0216D454(p[3])) {
            func_021C8B48(p);
            if (func_021C8B5C(p)) {
                func_020061F8(func_02006148(0x694));
                *st = 2;
            } else {
                func_021C8B14(p);
            }
        }
        break;
    case 2:
        func_021C8B78(p);
        return 1;
    }
    return 0;
}
