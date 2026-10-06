/*
 * function: func_021C7D34
 * address: 0x021C7D34
 * packet: pkt_ov093_021C7D34
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * witness: owned verified ov095 leaf 0x0689D5F4 resolves the tail pool.
 * ABI: full-word r1 index is preserved; ov095 body reads r0/r1 and returns
 * the byte in r0. Tail pool target is 0x0689D5F4 + 1. This ov095 leaf
 * was authorized by root separately; no domain assumptions.
 * symbols:
 *   func_0689D5F4 0x0689D5F4 thumb ov095
 */
typedef unsigned char u8;
extern int func_0689D5F4(u8 *p, int i);
int func_021C7D34(char *p, int i) { return func_0689D5F4((u8 *)(p + 0x1ab8), i); }
