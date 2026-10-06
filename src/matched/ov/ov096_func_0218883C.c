/*
 * function: func_0218883C
 * address: 0x0218883C
 * packet: pkt_ov096_0218883C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218885C 0x0218885C thumb ov096
 */
#include "../include/Obj21924.h"
struct Cursor;
extern int func_0218885C(struct Cursor *a, int b, int c);
int func_0218883C(struct Cursor *a, int b)
{
    func_0218885C(a, b, 3);
    return ((struct Obj21924 *)((unsigned int)b))->fC4;
}
