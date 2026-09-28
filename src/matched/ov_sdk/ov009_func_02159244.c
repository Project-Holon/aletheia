/*
 * function: find_socket
 * address:  0x02159244
 * packet:   pkt_ov009_02159244
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      find_socket (libcps.TWL.HYB.a network.o)
 * symbols:
 *   check_socket                     0x02159190 arm
 *   OSi_ThreadInfo                   0x02150fec data
 */

struct _OSThread;
struct _CPSSoc;

extern unsigned long check_socket(unsigned char *iphdr, unsigned char *tcphdr, struct _CPSSoc *soc);
extern int OSi_ThreadInfo;

static struct _CPSSoc *find_socket(unsigned char *iphdr, unsigned char *tcphdr)
{
	struct _CPSSoc *soc;
	struct _OSThread *t;

	t = *(struct _OSThread **)((char *)&OSi_ThreadInfo + 8);
	while (t != 0) {
		soc = *(struct _CPSSoc **)((char *)t + 0xa4);

		if (soc != 0 && *(struct _OSThread **)soc != 0) {
			if (check_socket(iphdr, tcphdr, soc) != 0)
				return soc;
		}
		t = *(struct _OSThread **)((char *)t + 0x68);
	}
	return 0;
}

