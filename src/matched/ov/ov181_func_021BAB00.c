/*
 * function: STAFF_ROLL_CmdSetRecord
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
 * record to STAFF_ROLL_PrintRowText, then copy one halfword and set a flag on ctx.
 *
 * symbols:
 *   STAFF_ROLL_PrintRowText    0x021BA558  thumb  ov181
 */
#include "../include/Obj14416.h"
#include "../include/Obj14417.h"

extern void STAFF_ROLL_PrintRowText(char *ctx, unsigned char *rec);

int STAFF_ROLL_CmdSetRecord(char *ctx, unsigned char *rec)
{
    rec = rec + (rec[7] << 4);
    STAFF_ROLL_PrintRowText(ctx, rec);
    ((struct Obj14416 *)ctx)->f2DA = ((struct Obj14417 *)rec)->f4;
    ((struct Obj14416 *)ctx)->f2EC = 1;
    return 1;
}
