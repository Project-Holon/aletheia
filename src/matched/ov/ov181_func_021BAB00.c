/*
 * function: func_021BAB00
 * address:  0x021BAB00
 * packet:   pkt_ov181_021BAB00
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 30-byte leaf: stride into a record table by its byte-7 selector, hand the
 * record to func_021BA558, then copy one halfword and set a flag on ctx.
 *
 * symbols:
 *   func_021BA558    0x021BA558  thumb  ov181
 */
#include "../include/Obj14416.h"
#include "../include/Obj14417.h"

extern void func_021BA558(char *ctx, unsigned char *rec);

int func_021BAB00(char *ctx, unsigned char *rec)
{
    rec = rec + (rec[7] << 4);
    func_021BA558(ctx, rec);
    ((struct Obj14416 *)ctx)->f2DA = ((struct Obj14417 *)rec)->f4;
    ((struct Obj14416 *)ctx)->f2EC = 1;
    return 1;
}
