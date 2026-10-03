/*
 * function: func_021D7E88
 * address: 0x021D7E88
 * packet: pkt_ov120_021D7E88
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: separately filed 021D7E9C.
 * symbols:
 *   func_021D7CE8 0x021D7CE8 thumb ov120
 *   d_021D8BD8 0x021D8BD8 data a2
 */
typedef unsigned short u16;
extern const u16 d_021D8BD8[];
extern void func_021D7CE8(char *p, u16 n, int i);
void func_021D7E88(char *p,int i) {func_021D7CE8(p,d_021D8BD8[i],*(int *)(p+0x24));}
