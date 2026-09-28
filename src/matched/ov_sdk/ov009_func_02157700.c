/*
 * function: func_02157700
 * address:  0x02157700
 * packet:   pkt_ov009_02157700
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      calc_checksum_do (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 */

unsigned long func_02157700(unsigned char *s, unsigned long len, unsigned long sum)
{
	int align;
	unsigned long tmp;
	unsigned long tmp2;
	unsigned long tmps;

	tmp = 0;
	align = (unsigned long)s & 3;
	if (align != 0) {
		tmp2 = *(unsigned long *)((unsigned long)s & ~3);
		s = (unsigned char *)(((unsigned long)s & ~3) + 4);
		switch (align) {
		case 1:
			tmp2 &= 0xffffff00;
			if (len < 3) {
				len += 1;
				goto partial;
			}
			len -= 3;
			break;
		case 2:
			tmp2 &= 0xffff0000;
			if (len < 2) {
				len += 2;
				goto partial;
			}
			len -= 2;
			break;
		default:
			tmp2 &= 0xff000000;
			len -= 1;
			break;
		}
		tmp = tmp2;
	}
	while (len >= 4) {
		tmp2 = *(unsigned long *)s;
		len -= 4;
		tmp += tmp2;
		if (tmp < tmp2)
			tmp++;
		s += 4;
	}
	if (len != 0) {
		tmp2 = *(unsigned long *)s;
partial:
		if (len == 1)
			tmp2 &= 0xff;
		else if (len == 2)
			tmp2 &= 0xffff;
		else
			tmp2 &= 0xffffff;
		tmp += tmp2;
		if (tmp < tmp2)
			tmp++;
	}
	tmps = (tmp & 0xffff) + (tmp >> 16);
	tmps = (tmps & 0xffff) + (tmps >> 16);
	if ((align & 1) == 0)
		tmps = ((tmps << 8) & 0xff00) + (tmps >> 8);
	tmps += sum;
	return (tmps & 0xffff) + (tmps >> 16);
}
