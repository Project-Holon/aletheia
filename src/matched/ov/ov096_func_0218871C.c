/*
 * function: func_0218871C
 * address: 0x0218871C
 * packet: pkt_ov096_0218871C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0218875C 0x0218875C thumb ov096
 */
#include "../include/Obj21916.h"
typedef unsigned char u8;
struct Cursor;
extern int func_0218875C(struct Cursor *a, int unused, int c);
int func_0218871C(struct Cursor *p, int q)
{
    func_0218875C(p, q, 0);
    return ((struct Obj21916 *)q)->fC4;
}
