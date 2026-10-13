/*
 * function: INTRUDE_COMM_IsSessionFinished
 * address:  0x02175BBC
 * packet:   pkt_ov011_02175BBC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 INTRUDE_FIELD_TryStartOfferEvent: bit 3 of the byte
 * at +0x1A5.
 */

typedef unsigned char u8;

typedef struct { u8 a : 3; u8 b : 1; u8 c : 4; } Fb;

int INTRUDE_COMM_IsSessionFinished(u8 *p)
{
    return ((Fb *)(p + 0x1A5))->b;
}
