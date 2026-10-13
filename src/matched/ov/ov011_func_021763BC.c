/*
 * function: INTRUDE_COMM_ResetOutcomes
 * address:  0x021763BC
 * packet:   pkt_ov011_021763BC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_PickEntryForKind  0x021763D8  thumb  ov011
 *
 * Zeroes the six bytes at +6 one at a time, and after each store lets
 * INTRUDE_COMM_PickEntryForKind fill p[key] for key 0..5.  Called from arm9 func_0200BDE4
 * (bl at 0x0200BDF2) and from ov011 at 0x0217644C.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void INTRUDE_COMM_PickEntryForKind(u8 *p, u32 key);

void INTRUDE_COMM_ResetOutcomes(u8 *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        p[i + 6] = 0;
        INTRUDE_COMM_PickEntryForKind(p, i);
    }
}
