/*
 * function: func_021D123C
 * address:  0x021D123C
 * packet:   pkt_ov093_021D123C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEC20  0x021EEC20  thumb  ov093
 *   func_021EE608  0x021EE608  thumb  ov093
 *   func_021BB4E0  0x021BB4E0  thumb  ov093
 *   func_021EE638  0x021EE638  thumb  ov093
 */
#include "../../../matched/include/Obj05203.h"

extern int func_021EEC20(int, int *);
typedef unsigned char  u8;
extern void func_021EE608(u8 *p, const u8 *src, int n);
extern void func_021BB4E0(int, int, int);
extern u8 func_021EE638(u8 *p);

int func_021D123C(int a)
{
    int tmp;
    int r4 = func_021EEC20(((struct Obj05203 *)a)->f50, &tmp);
    if (((struct Obj05203 *)a)->f10 != 0)
        func_021EE608((u8 *)(((struct Obj05203 *)a)->f10), (const u8 *)tmp, r4);
    if (((struct Obj05203 *)a)->fA0 != 0) {
        func_021BB4E0(((struct Obj05203 *)a)->fA0, tmp, r4);
        ((struct Obj05203 *)a)->f1AE = func_021EE638((u8 *)tmp);
    }
    return 1;
}
