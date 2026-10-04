/*
 * function: func_021856F4
 * address: 0x021856F4
 * packet: pkt_ov023_021856F4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_02185354 0x02185354 thumb ov023
 */
#include "../include/Obj20351.h"
extern void func_0202208C(void *, unsigned int, unsigned int, unsigned int,
                        unsigned int, unsigned int, unsigned int);
extern void func_02185354(char *);
int func_021856F4(char *p, int a)
{
    if (++((struct Obj20351 *)p)->f1A4 > 60) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        a = 3;
    }
    func_02185354(p);
    return a;
}
