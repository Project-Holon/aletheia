/*
 * function: func_021888AC
 * address: 0x021888AC
 * packet: pkt_ov096_021888AC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021888BC 0x021888BC thumb ov096
 */
#include "../include/Obj21927.h"
struct Cursor;
extern int func_021888BC(struct Cursor *a, int b, int c);
int func_021888AC(struct Cursor *a, int b)
{
    func_021888BC(a, b, 3);
    return ((struct Obj21927 *)((unsigned int)b))->fC4;
}
