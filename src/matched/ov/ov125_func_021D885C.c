/*
 * function: func_021D885C
 * address: 0x021D885C
 * packet: pkt_ov125_021D885C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef struct { unsigned short a,b; unsigned words[2]; int value; unsigned tail[3]; } Packet;
extern int func_021D7A10(int id, void *buf, int x, int sz);
int func_021D885C(int value, int n) {
 Packet p = {0};
 p.value = value;
 p.a = 2; p.tail[1] = 0; p.tail[2] = 0; p.b = 0;
 return func_021D7A10(0x55f1, &p, n, -1);
}
