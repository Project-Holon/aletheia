/*
 * function: INTRUDE_COMM_GetMemberEntry
 * address:  0x0215840C
 * packet:   pkt_ov010_0215840C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Address of the idx-th 0x28-byte record at +0x1AC.
 */

typedef unsigned char u8;

typedef struct Rec28 {
    u8 data[0x28];
} Rec28;

typedef struct RecHolder {
    u8 pad[0x1AC];
    Rec28 recs[1];      /* 0x1AC */
} RecHolder;

Rec28 *INTRUDE_COMM_GetMemberEntry(RecHolder *h, int idx)
{
    return &h->recs[idx];
}
