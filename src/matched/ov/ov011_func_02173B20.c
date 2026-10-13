/*
 * function: INTRUDE_COMM_RecvNotice
 * address: 0x02173B20
 * packet: pkt_ov011_02173B20
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_SetRequestResult 0x021754E8 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
void INTRUDE_COMM_SetRequestResult(u8 *p, int a, int b, int c);

void INTRUDE_COMM_RecvNotice(int a, int b, u8 *c, u8 *d)
{
    if (d[0x154] == a && d[0x158] == c[0]) INTRUDE_COMM_SetRequestResult((u8 *)((int)d), a, 3, c[0]);
}
