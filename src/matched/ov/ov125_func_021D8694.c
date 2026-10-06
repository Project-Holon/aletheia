/*
 * function: func_021D8694
 * address: 0x021D8694
 * packet: pkt_ov125_021D8694
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   func_021D7A10 0x021D7A10 arm ov125
 */
typedef struct { unsigned words[0x18a4/4]; } Data;
typedef struct { Data data; int length; char bytes[256]; } Packet;
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern int func_021D7A10(int id, void *buf, int x, int sz);
int func_021D8694(const Data *data, const void *bytes, int length, int n) {
 Packet p={0};
 if (length > 256) return 0;
 p.data = *data;
 p.length = length;
 func_02092344(p.bytes, bytes, length);
 return func_021D7A10(0x55f0, &p, n, -1);
}
