/*
 * function: func_02158134
 * address:  0x02158134
 * packet:   pkt_ov009_02158134
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_ether (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02157928  0x02157928  arm  ov009
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157F60  0x02157F60  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_021579E8  0x021579E8  arm  ov009
 *   g_021A82D4  0x021A82D4  data
 */

extern int func_02157928(unsigned v);
extern unsigned long func_021578C8(unsigned long ip);
extern unsigned char (*func_02157D8C(unsigned long ip))[6];
extern unsigned char (*func_02157F60(unsigned long ip))[6];
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern unsigned char g_021A82D4[6];

void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type)
{
	unsigned char (*mac_to)[6];

	*(unsigned short *)(hdr - 2) = (type >> 8) | (type << 8);
	if (!func_02157928(ip_to)) {
		ip_to = func_021578C8(ip_to);
		if (ip_to == 0)
			return;
		mac_to = func_02157D8C(ip_to);
		if (mac_to == 0)
			mac_to = func_02157F60(ip_to);
		if (mac_to == 0)
			return;
		func_02082EA4(mac_to, hdr - 0xe, 6);
	} else {
		hdr[-0xe] = 1;
		hdr[-0xd] = 0;
		hdr[-0xc] = 0x5e;
		hdr[-0xb] = (ip_to >> 16) & 0x7f;
		hdr[-0xa] = ip_to >> 8;
		hdr[-9] = ip_to;
	}
	func_02082EA4(g_021A82D4, hdr - 8, 6);
	func_021579E8(hdr - 0xe, hdr_len + 0xe, body, body_len);
}
