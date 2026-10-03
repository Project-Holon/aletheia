/*
 * unit: yes
 * function: func_068994A8
 * address: 0x068994A8
 * packet: pkt_ov095_068994A8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Unlabelled store-and-return follower after veneer 0x06899498.
 * symbols:
 *   data_0689D718 0x0689D718 data a4
 */
typedef unsigned int u32;
extern u32 data_0689D718;
void *func_068994A8(u32 *p) { *p = 1; return &data_0689D718; }
