/*
 * unit: yes
 * function: func_068993A4
 * address: 0x068993A4
 * packet: pkt_ov095_068993A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled store-and-return follower after veneer 0x06899394.
 * symbols:
 *   data_0689D700 0x0689D700 data a4
 */
typedef unsigned int u32;
extern u32 data_0689D700;
void *func_068993A4(u32 *p) { *p = 1; return &data_0689D700; }
