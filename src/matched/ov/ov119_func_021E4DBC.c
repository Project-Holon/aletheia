/*
 * function: func_021E4DBC
 * address: 0x021E4DBC
 * packet: pkt_ov119_021E4DBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a separate adjusted-coordinate local keeps the subtraction before division.
 */
#include "../include/Obj22807.h"
int func_021E4DBC(char *p)
{
    int x, q, r, v;
    x = ((struct Obj22807 *)p)->f107C;
    if (x < 48) x = 0;
    else if (x < 96) x = 1;
    else {
        v = x - 96;
        q = v / 160;
        r = v - q * 160;
        x = q * 6 + 2;
        if (r >= 8) {
            if (r >= 152) x += 5;
            else x += (r - 8) / 24;
        }
    }
    return x;
}
