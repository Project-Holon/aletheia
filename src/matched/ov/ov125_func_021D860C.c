/*
 * function: func_021D860C
 * address: 0x021D860C
 * packet: pkt_ov125_021D860C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef struct { unsigned words[0x230/4]; } Packet;
extern int func_021D7A10(int, const void *, int, int);
int func_021D860C(const Packet *p, int n) {
 Packet copy;
 copy = *p;
 return func_021D7A10(0x5208, &copy, n, -1);
}
