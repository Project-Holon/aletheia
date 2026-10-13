/*
 * function: INTRUDE_COMM_IsValidProfileCode
 * address: 0x021756D0
 * packet: pkt_ov011_021756D0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * The 32-byte follower at 021756F0 already has its own matched shard.
 * A ternary loop condition preserves the branch to the bottom test.
 * symbols:
 *   gIntrudeCommValidProfileCodes 0x02176AD0 data ov011 a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 gIntrudeCommValidProfileCodes[];
int INTRUDE_COMM_IsValidProfileCode(u32 x)
{
    u32 i;
    for (i = 0; (i < 0x1c) ? 1 : 0; i++) {
        if (x == gIntrudeCommValidProfileCodes[i]) {
            return 1;
        }
    }
    return 0;
}
