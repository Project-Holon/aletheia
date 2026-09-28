/*
 * function: tcp_write_do2
 * address:  0x0215B15C
 * packet:   pkt_ov009_0215B15C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      tcp_write_do2 (libcps.TWL.HYB.a network.o)
 * symbols:
 *   tcp_write_do                     0x0215b09c arm
 */

struct _CPSSoc;

extern unsigned long tcp_write_do(unsigned char *buf, unsigned long len, struct _CPSSoc *soc, int need_probe);

static void tcp_write_do2(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, struct _CPSSoc *soc, int need_probe)
{
	if (tcp_write_do(buf, len, soc, need_probe) != 0 && len2 != 0)
		tcp_write_do(buf2, len2, soc, 0);
}

