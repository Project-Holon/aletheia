/*
 * function: UNION_ONESELF_EntryMenuRemoveMember
 * address:  0x0217DC94
 * packet:   pkt_ov019_0217DC94
 * region:   ov019
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

void UNION_ONESELF_EntryMenuRemoveMember(u8 *base, int obj, int x)
{
    UNION_COMM_RemoveMember(base + 0x2844, (const u8 *)x);
}
