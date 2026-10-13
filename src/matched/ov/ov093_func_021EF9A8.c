/*
 * function: BTL_FIELD_GetCountdownByte
 * address: 0x021EF9A8
 * packet: pkt_ov093_021EF9A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Sole blocker of the claimed 021D3D84 follower.
 * Body ends at 021EF9B0; larger unlabelled follower remains outside this leaf.
 */
typedef unsigned int u32;
typedef unsigned char u8;
u8 BTL_FIELD_GetCountdownByte(u32 *p) { return (u8)*p; }
