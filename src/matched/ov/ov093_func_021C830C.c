/*
 * function: BTL_SERVER_FLOW_TestStateFlagBit0
 * address: 0x021C830C
 * packet: pkt_ov093_021C830C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: unsigned-char bitfield gives the byte load and 31-bit shift pair.
 */
typedef unsigned char u8;
struct Bits { unsigned char a:1; unsigned char rest:7; };
unsigned int BTL_SERVER_FLOW_TestStateFlagBit0(u8 *p) { return ((struct Bits *)(p+0x78a))->a; }
