/*
 * function: func_021D8AF4
 * address: 0x021D8AF4
 * packet: pkt_ov119_021D8AF4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0209C0A4 0x0209C0A4 arm
 */
#include "../include/Obj22704.h"
extern int func_0209C0A4(int a, int b);
int func_021D8AF4(int a, char *p)
{
    if (a >= 2)
        return func_0209C0A4(a - 2, 6);
    return ((struct Obj22704 *)p)->f630;
}
