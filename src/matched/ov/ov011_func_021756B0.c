/*
 * function: INTRUDE_COMM_IsValidObjCode
 * address: 0x021756B0
 * packet: pkt_ov011_021756B0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * A ternary loop condition keeps the unrotated entry branch.
 * symbols:
 *   gIntrudeCommValidObjCodes 0x02176B08 data ov011 a2
 */
typedef unsigned short u16;
extern const u16 gIntrudeCommValidObjCodes[];
int INTRUDE_COMM_IsValidObjCode(int value)
{
    unsigned int i;
    for (i = 0; (i < 162) ? 1 : 0; i++) if (value == gIntrudeCommValidObjCodes[i]) return 1;
    return 0;
}
