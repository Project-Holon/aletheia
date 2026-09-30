/*
 * function: func_021D8654
 * address: 0x021D8654
 * packet: pkt_ov125_021D8654
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef struct { unsigned short a,b; long long value; } Packet;
extern int func_021D7A10(int, const void *, int, int);
int func_021D8654(int value, int n) {
 Packet p;
 p.a = 0; p.b = 0; p.value = value;
 return func_021D7A10(0x5209, &p, n, -1);
}
