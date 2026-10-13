/*
 * function: VCT_Exit
 * address:  0x021B3844
 * packet:   pkt_021B3844
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60CC  0x021B60CC  data  ov013
 *   VCT_SESSION_ClearMemberCount  0x021B0600  arm  ov013
 *   VCT_SESSION_ClearPeerLists  0x021B23C8  arm  ov013
 *   VCT_POOL_Reset  0x021B2F98  arm  ov013
 */

extern int  d_021B60CC[];
extern void VCT_SESSION_ClearMemberCount(void);
extern void VCT_SESSION_ClearPeerLists(void);
extern void VCT_POOL_Reset(void);

void VCT_Exit(void)
{
    VCT_SESSION_ClearMemberCount();
    VCT_SESSION_ClearPeerLists();
    VCT_POOL_Reset();
    d_021B60CC[7] = 0;
    d_021B60CC[2] = 0;
}
