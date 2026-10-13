/*
 * function: UNION_COMM_RemoveMemberOfBeaconPc
 * address:  0x02173650
 * packet:   pkt_ov012_02173650
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_COMM_RemoveMember  0x02173614  thumb  ov012
 */

typedef unsigned char u8;

extern void UNION_COMM_RemoveMember(u8 *self, const u8 *mac);

void UNION_COMM_RemoveMemberOfBeaconPc(int a, u8 *b)
{
    UNION_COMM_RemoveMember((u8 *)a, b + 0x64);
}
