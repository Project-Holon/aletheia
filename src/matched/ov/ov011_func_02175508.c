/*
 * function: INTRUDE_COMM_SetRequestResultAccepted
 * address:  0x02175508
 * packet:   pkt_ov011_02175508
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_SetRequestResult  0x021754E8  thumb ov011
 */

typedef unsigned char  u8;
void INTRUDE_COMM_SetRequestResult(u8 *p, int a, int b, int c);

void INTRUDE_COMM_SetRequestResultAccepted(int a, int b, int c)
{
    INTRUDE_COMM_SetRequestResult((u8 *)a, b, 3, c);
}
