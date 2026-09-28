/*
 * function: pad_mem
 * address:  0x0215BD58
 * packet:   pkt_ov009_0215BD58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      pad_mem (libcps.TWL.HYB.a network.o)
 * symbols:
 *   MI_CpuFill8                      0x02082bcc arm
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

static unsigned char *pad_mem(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen)
{
	unsigned long n;

	if (curlen < minimum) {
		n = minimum - curlen;
		MI_CpuFill8(d, pattern, n);
		d += n;
	}
	return d;
}

