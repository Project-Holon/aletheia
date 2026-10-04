/*
 * function: func_021E49DC
 * address: 0x021E49DC
 * packet: pkt_ov119_021E49DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8E24 0x021D8E24 thumb ov119
 */
#include "../include/Obj22805.h"
extern int func_021D8AF4(int, char *);
extern int func_021D8B0C(int, int);
extern char *func_021D8E24(int, int, char *);
char *func_021E49DC(int a, int b, char *p)
{
    int n;
    if (a >= 2) {
        n = func_021D8AF4(a, p);
        return func_021D8E24(n, func_021D8B0C(a, b), p);
    }
    if (b < 3)
        return func_021D8E24(((struct Obj22805 *)p)->f630, a + b * 2, p);
    return 0;
}
