/*
 * function: func_021D4DF4
 * address: 0x021D4DF4
 * packet: pkt_ov115_021D4DF4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   func_021D580C 0x021D580C thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_021D580C(u8 *);
void func_021D4DF4(u8 *p) { if(*(int *)(p+8)==1) func_021D580C(p); }
