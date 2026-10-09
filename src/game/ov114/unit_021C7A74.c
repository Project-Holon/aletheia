/*
 * file:     unit_021C7A74.c
 * unit:     yes
 * function: func_021C7A74, func_021C7B48
 * address:  0x021C7A74
 * region:   ov114
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ll_udiv  0x0209C00C  arm
 *   g_021CE138  0x021CE138  data
 */
typedef unsigned long long u64;

int func_021C7A74(char *p, u64 n, int figure);
int func_021C7B48(char *p, unsigned long n, int figure);
extern u64 g_021CE138[];


int func_021C7A74(char *p, u64 n, int figure)
{
	int i;
	int b;
	unsigned int x;
	int len = 0;
	if (n >= 100000000000000000ULL)
		return -1;
	for (i = 0, b = 0; i < 16; i++) {
		if (n >= g_021CE138[i]) {
			x = n / g_021CE138[i];
			n -= (u64)x * g_021CE138[i];
			p[len] = x + '0';
			b = 1;
		} else {
			if (b == 0 && 17 - i > figure)
				continue;
			p[len] = '0';
		}
		len++;
	}
	p[len] = n + '0';
	return len + 1;
}

int func_021C7B48(char *p, unsigned long n, int figure)
{
	int i;
	unsigned long x;
	int len = 0;
	if (figure > 8)
		return -1;
	for (i = 1; i <= figure; i++) {
		x = (n >> ((figure - i) * 4)) & 0xf;
		if (x < 10)
			p[len++] = x + '0';
		else
			p[len++] = x + 'a' - 10;
	}
	return len;
}
