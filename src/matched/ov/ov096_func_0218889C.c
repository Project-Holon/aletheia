/*
 * function: func_0218889C
 * address: 0x0218889C
 * packet: pkt_ov096_0218889C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021888BC 0x021888BC thumb ov096
 */
#include "../include/Obj21926.h"
struct Cursor;
extern int func_021888BC(struct Cursor *a, int b, int c);
int func_0218889C(struct Cursor *a, int b)
{
    func_021888BC(a, b, 2);
    return ((struct Obj21926 *)((unsigned int)b))->fC4;
}
