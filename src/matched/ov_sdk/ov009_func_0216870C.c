/*
 * function: DWC_GetFriendStatus
 * address:  0x0216870C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with the last argument moved to the fourth slot.
 *
 * symbols:
 *   DWC_GetFriendStatusSC  0x02168724  arm  ov009
 */

typedef unsigned char  u8;
extern u8 DWC_GetFriendStatusSC(void *friendData, u8 *maxEntry, u8 *numEntry, char *statusString);

u8 DWC_GetFriendStatus(int a, int b)
{
    return DWC_GetFriendStatusSC((void *)a, 0, 0, (char *)b);
}

