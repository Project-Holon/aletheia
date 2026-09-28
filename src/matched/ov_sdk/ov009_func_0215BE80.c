/*
 * function: func_0215BE80
 * address:  0x0215BE80
 * packet:   pkt_ov009_0215BE80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dhcp_send_request (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   func_0215BC04            0x0215BC04  arm  ov009
 *   func_0215BD58            0x0215BD58  arm  ov009
 *   func_0215B470            0x0215B470  arm  ov009
 *   g_021A878E               0x021A878E  data
 *   g_021A826C               0x021A826C  data
 */

extern unsigned char *func_0215BC04(unsigned char *d, int type);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
extern unsigned char g_021A878E[];
extern unsigned char g_021A826C;

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))
#define HI16(x) ((unsigned short)((x) >> 16))
#define LO16(x) ((unsigned short)(x))

unsigned long func_0215BE80(int mode)
{
	unsigned char *buf;
	unsigned char *d;

	buf = g_021A878E;
	d = func_0215BC04(buf, 3);
	if (mode == 0) {
		d[0] = 0x32;
		d[1] = 4;
		d[2] = (unsigned char)(HI16(NV(0x38, unsigned long)) >> 8);
		d[3] = (unsigned char)HI16(NV(0x38, unsigned long));
		d[4] = (unsigned char)(LO16(NV(0x38, unsigned long)) >> 8);
		d[5] = (unsigned char)LO16(NV(0x38, unsigned long));
		d[6] = 0x36;
		d[7] = 4;
		d[8] = (unsigned char)(HI16(NV(0x1c, unsigned long)) >> 8);
		d[9] = (unsigned char)HI16(NV(0x1c, unsigned long));
		d[10] = (unsigned char)(LO16(NV(0x1c, unsigned long)) >> 8);
		d[11] = (unsigned char)LO16(NV(0x1c, unsigned long));
		d += 12;
	}
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	return NV(0x30, unsigned long);
}
