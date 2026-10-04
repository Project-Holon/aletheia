/*
 * function: func_02188A84
 * address: 0x02188A84
 * packet: pkt_ov096_02188A84
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188AB4 0x02188AB4 thumb ov096
 */
#include "../include/Obj21938.h"
struct Cursor;
extern int func_02188AB4(struct Cursor *a, unsigned char *b, int c);
int func_02188A84(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 3);
    return ((struct Obj21938 *)b)->fC4;
}
