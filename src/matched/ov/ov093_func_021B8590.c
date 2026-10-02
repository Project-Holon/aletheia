/*
 * function: func_021B8590
 * address: 0x021B8590
 * packet: pkt_ov093_021B8590
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
struct Flags { unsigned char low:2, bit:1, high:5; };
unsigned int func_021B8590(unsigned char *p) { return ((struct Flags *)(p+0x473))->bit; }
