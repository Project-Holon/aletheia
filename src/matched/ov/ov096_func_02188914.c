/*
 * function: func_02188914
 * address: 0x02188914
 * packet: pkt_ov096_02188914
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188924 0x02188924 thumb ov096
 */
#include "../include/Obj21929.h"
struct Cursor;
extern int func_02188924(struct Cursor *a, int b, int c);
int func_02188914(struct Cursor *a, int b)
{
    func_02188924(a, b, 3);
    return ((struct Obj21929 *)b)->fC4;
}
