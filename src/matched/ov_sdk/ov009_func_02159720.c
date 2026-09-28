/*
 * function: func_02159720
 * address:  0x02159720
 * packet:   pkt_ov009_02159720
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dt_syn (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_02158F84  0x02158F84  arm  ov009
 *   func_021596A8  0x021596A8  arm  ov009
 *   func_021590BC  0x021590BC  arm  ov009
 *   func_021595C0  0x021595C0  arm  ov009
 *   func_020858D8  0x020858D8  arm
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

struct _CPSSoc;

extern unsigned long func_02158F84(unsigned long ip1, unsigned long ip2);
extern unsigned long func_021596A8(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
extern struct _CPSSoc *func_021590BC(unsigned char *iphdr, unsigned char *tcphdr);
extern void func_021595C0(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
extern void func_020858D8(void);

void func_02159720(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	if (func_02158F84(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	if (func_021596A8(iphdr, tcphdr, len) != 0)
		return;
	soc = func_021590BC(iphdr, tcphdr);
	if (soc != 0) {
		func_021595C0(iphdr, tcphdr, soc);
		return;
	}
	func_020858D8();
	soc = func_021590BC(iphdr, tcphdr);
	if (soc != 0)
		func_021595C0(iphdr, tcphdr, soc);
}
