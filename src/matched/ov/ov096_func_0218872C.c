/*
 * function: func_0218872C
 * address: 0x0218872C
 * packet: pkt_ov096_0218872C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218875C 0x0218875C thumb ov096
 */
#include "../include/Obj21917.h"
typedef unsigned char u8;
struct Cursor;
extern int func_0218875C(struct Cursor *a, int unused, int c);
int func_0218872C(struct Cursor *a, u8 *b)
{
    func_0218875C(a, (int)b, 1);
    return ((struct Obj21917 *)b)->fC4;
}
