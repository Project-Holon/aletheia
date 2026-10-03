/*
 * function: func_02158204
 * address:  0x02158204
 * packet:   pkt_ov009_02158204
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_ip_frag (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   func_0215781C            0x0215781C  arm  ov009
 *   func_02158134            0x02158134  arm  ov009
 *   func_02157928            0x02157928  arm  ov009
 *   MI_CpuCopy               0x02082EA4  arm
 *   OS_DisableInterrupts     0x02087988  arm
 *   func_02157A44            0x02157A44  arm  ov009
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A1CC0               0x021A1CC0  data
 *   g_021A82D4               0x021A82D4  data
 */

extern unsigned short func_0215781C(unsigned char *s, unsigned long len);
extern void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
extern int func_02157928(unsigned v);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned long OS_DisableInterrupts(void);
extern void func_02157A44(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern unsigned char g_021A826C;
extern char g_021A1CC0[];
extern unsigned char g_021A82D4[6];

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))
static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}

void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset)
{
	unsigned long enabled;

	*(unsigned short *)(hdr - 0x12) = swap16((unsigned short)(hdr_len + 0x14 + body_len));
	*(unsigned short *)(hdr - 0xe) = swap16((unsigned short)offset);
	*(unsigned short *)(hdr - 0xa) = 0;
	*(unsigned short *)(hdr - 0xa) = swap16(func_0215781C(hdr - 0x14, 0x14));
	if (ip_to != 0x7f000001 && ip_to != NV(0x50, unsigned long))
		func_02158134(hdr - 0x14, hdr_len + 0x14, body, body_len, ip_to, 0x800);
	if (ip_to != 0x7f000001 && ip_to != NV(0x50, unsigned long) && !func_02157928(ip_to))
		return;
	MI_CpuCopy(g_021A1CC0, hdr - 0x1c, 8);
	enabled = OS_DisableInterrupts();
	func_02157A44(g_021A82D4, g_021A82D4, hdr - 0x1c, hdr_len + 0x1c, body, body_len);
	OS_RestoreInterrupts(enabled);
}
