/*
 * unit:     yes
 * function: INTRUDE_COMM_IsSessionAcceptedOrResultReady, INTRUDE_COMM_SetSessionReadyBit
 * address:  0x02175BE4
 * packet:   pkt_ov011_02175BE4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * INTRUDE_COMM_SetSessionReadyBit is an unlabelled leaf (sets one bit in a byte at +0x19f or +0x1a0).
 *
 * symbols:
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_COMM_GetSessionResult  0x02175BCC  thumb  ov011
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern int INTRUDE_COMM_IsSessionAccepted(u8 *p);
extern u8 *INTRUDE_COMM_GetSessionResult(u8 *p);

int INTRUDE_COMM_IsSessionAcceptedOrResultReady(void *a)
{
    if (INTRUDE_COMM_IsSessionAccepted(a) == 1 || INTRUDE_COMM_GetSessionResult(a) != 0) {
        return 1;
    }
    return 0;
}

void INTRUDE_COMM_SetSessionReadyBit(u8 *o, u32 bit)
{
    if (o[0xe0] == 4) {
        o[0x19f] |= (u8)(1 << bit);
    } else {
        o[0x1a0] |= (u8)(1 << bit);
    }
}
