/*
 * function: dt_syn
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
 *   valid_IP  0x02158F84  arm  ov009
 *   find_specific_socket  0x021596A8  arm  ov009
 *   check_listener  0x021590BC  arm  ov009
 *   dt_syn_LISTEN  0x021595C0  arm  ov009
 *   OS_YieldThread  0x020858D8  arm
 */

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))
#define BE32(p, o) (((unsigned long)SWAP16(*(unsigned short *)((p) + (o))) << 16) | SWAP16(*(unsigned short *)((p) + (o) + 2)))

struct _CPSSoc;

extern unsigned long valid_IP(unsigned long ip1, unsigned long ip2);
extern unsigned long find_specific_socket(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len);
struct Soc;
extern struct Soc *check_listener(unsigned char *iphdr, unsigned char *tcphdr);
extern void dt_syn_LISTEN(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
extern void OS_YieldThread(void);

void dt_syn(unsigned char *iphdr, unsigned char *tcphdr, unsigned long len)
{
	struct _CPSSoc *soc;

	if (valid_IP(BE32(iphdr, 0xc), BE32(iphdr, 0x10)) == 0)
		return;
	if (find_specific_socket(iphdr, tcphdr, len) != 0)
		return;
	soc = (struct _CPSSoc *)check_listener(iphdr, tcphdr);
	if (soc != 0) {
		dt_syn_LISTEN(iphdr, tcphdr, soc);
		return;
	}
	OS_YieldThread();
	soc = (struct _CPSSoc *)check_listener(iphdr, tcphdr);
	if (soc != 0)
		dt_syn_LISTEN(iphdr, tcphdr, soc);
}
