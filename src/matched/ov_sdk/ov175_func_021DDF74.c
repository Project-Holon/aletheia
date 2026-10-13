/*
 * function: sakeiCreateRecordValidateInput
 * address:  0x021DDF74
 * packet:   pkt_021DDF74
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiValidateRequestFields  0x021DDB38  arm
 *
 * Pre-flight check of the +0x08 block, the signed sibling of sakeiGetMyRecordsValidateInput:
 * missing head or non-positive count rejected with 4 or 6, a missing name
 * table with 5 when the count is still positive, else the table is handed to
 * sakeiValidateRequestFields with the count as its second argument.
 */

typedef int s32;

extern s32 sakeiValidateRequestFields(s32, s32);

s32 sakeiCreateRecordValidateInput(char *p)
{
    s32 *q = *(s32 **)(p + 8);

    if (q[0] == 0)
        return 4;
    if (q[2] < 0)
        return 6;
    if (q[1] == 0) {
        if (q[2] > 0)
            return 5;
    }
    return sakeiValidateRequestFields(q[1], q[2]);
}
