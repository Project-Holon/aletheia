/*
 * function: func_0215BC04
 * address:  0x0215BC04
 * packet:   pkt_ov009_0215BC04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dhcp_setcommon (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   MI_CpuFill8              0x02082BCC  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A82D4               0x021A82D4  data
 *   g_021A1CCC               0x021A1CCC  data
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned char g_021A826C;
extern unsigned char g_021A82D4[6];
extern char g_021A1CCC[];

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))
#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))

unsigned char *func_0215BC04(unsigned char *d, int type)
{
	MI_CpuFill8(d, 0, 0xec);
	*(unsigned short *)(d + 0) = 0x0101;
	d[2] = 6;
	*(unsigned short *)(d + 4) = SWAP16((unsigned short)(NV(0x30, unsigned long) >> 16));
	*(unsigned short *)(d + 6) = SWAP16((unsigned short)NV(0x30, unsigned long));
	*(unsigned short *)(d + 12) = SWAP16((unsigned short)(NV(0x50, unsigned long) >> 16));
	*(unsigned short *)(d + 14) = SWAP16((unsigned short)NV(0x50, unsigned long));
	MI_CpuCopy(g_021A82D4, d + 0x1c, 6);
	*(unsigned short *)(d + 0xec) = 0x8263;
	*(unsigned short *)(d + 0xee) = 0x6353;
	*(unsigned short *)(d + 0xf0) = 0x0135;
	d[0xf2] = (unsigned char)type;
	d[0xf3] = 0x3d;
	d[0xf4] = 7;
	d[0xf5] = 1;
	MI_CpuCopy(g_021A82D4, d + 0xf6, 6);
	d += 0xfc;
	if (type != 7) {
		d[0] = 0x0c;
		d[1] = 10;
		MI_CpuCopy(g_021A1CCC, d + 2, 10);
		d[12] = 0x37;
		d[13] = 3;
		d[14] = 1;
		d[15] = 3;
		d[16] = 6;
		d += 17;
	}
	return d;
}
