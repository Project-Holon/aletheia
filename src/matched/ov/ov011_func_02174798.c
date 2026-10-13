/*
 * function: INTRUDE_COMM_RecvReturnResult
 * address: 0x02174798
 * packet: pkt_ov011_02174798
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_021743B4.c and filed here.
 *
 * symbols:
 *   func_02161FF0 0x02161FF0 thumb ov010
 */

typedef unsigned char  u8;
void func_02161FF0(u8 *p, int v);
void INTRUDE_COMM_RecvReturnResult(int a, int b, int c, u8 *p);

void INTRUDE_COMM_RecvReturnResult(int a, int b, int c, u8 *p)
{
    func_02161FF0(p + 0x35c, c);
}
