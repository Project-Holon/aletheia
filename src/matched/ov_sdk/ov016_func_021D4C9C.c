/*
 * function: func_021D4C9C
 * address:  0x021D4C9C
 * packet:   pkt_ov016_021D4C9C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cmpBack (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_020923F0  0x020923F0  arm
 */

extern unsigned long func_0209477C(char *s);
extern int func_020923F0(void *a, void *b, unsigned long n);

int func_021D4C9C(char *str0, char *str1, int n)
{
	int len0;
	int len1;
	int rs;
	len0 = func_0209477C(str0);
	len1 = func_0209477C(str1);
	if (len0 < n || len1 < n)
		return 0;
	rs = func_020923F0(str0 + (len0 - n), str1 + (len1 - n), n);
	return rs == 0;
}
