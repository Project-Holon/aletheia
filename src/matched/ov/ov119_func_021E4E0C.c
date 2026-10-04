/*
 * function: func_021E4E0C
 * address: 0x021E4E0C
 * packet: pkt_ov119_021E4E0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 */
#include "../include/Obj08070.h"
extern int func_021E4DBC(char *);
int func_021E4E0C(char *p, int *out)
{
    int x, hi, n, t;
    x = func_021E4DBC(p);
    *out = x + 2;
    hi = x + 10;
    n = ((struct Obj08070 *)p)->f634;
    if (*out >= n) *out -= n;
    n = ((struct Obj08070 *)p)->f634;
    if (hi >= n) {
        t = ((struct Obj08070 *)p)->fF74;
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = ((struct Obj08070 *)p)->fF74;
        if (x <= t && t <= hi) return 1;
    }
    return 0;
}
