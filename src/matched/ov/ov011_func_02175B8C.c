/*
 * function: INTRUDE_COMM_IsSessionAccepted
 * address: 0x02175B8C
 * packet: pkt_ov011_02175B8C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 */
typedef unsigned char u8;
typedef struct { u8 a:2; u8 bit:1; u8 rest:5; } Flags;
extern int INTRUDE_COMM_IsSessionActive(u8 *p);
int INTRUDE_COMM_IsSessionAccepted(u8 *p)
{
    if (INTRUDE_COMM_IsSessionActive(p) == 1) return ((Flags *)(p + 0x1A5))->bit;
    return 0;
}
