/*
 * function: BTLV_B_GAUGE_PartyBallBarTaskDeleted
 * address:  0x02209214
 * packet:   pkt_ov094_02209214
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetOwnedWork  0x02030EE8  arm  arm9
 */

typedef struct { char pad[0xd8]; int fd8; } W;
extern W **TCBL_GetOwnedWork(void *h);

void BTLV_B_GAUGE_PartyBallBarTaskDeleted(void *h)
{
    (*TCBL_GetOwnedWork(h))->fd8 = 0;
}
