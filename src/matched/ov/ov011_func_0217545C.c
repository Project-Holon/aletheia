/*
 * function: INTRUDE_COMM_ClearRequestOpen
 * address: 0x0217545C
 * packet: pkt_ov011_0217545C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: bitfield clear emits bics; byte mask emits ands with 0xEF.
 */
typedef unsigned char u8;
typedef struct { u8 low : 4; u8 flag : 1; u8 high : 3; } Flags;
void INTRUDE_COMM_ClearRequestOpen(u8 *p) { ((Flags *)(p + 0x8F8))->flag = 0; }
