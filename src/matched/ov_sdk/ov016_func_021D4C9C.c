/*
 * function: cmpBack
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
 *   strlen  0x0209477C  arm
 *   func_020923F0  0x020923F0  arm
 */

typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int func_020923F0(const u8 *a, const u8 *b, int n);

int cmpBack(char *str0, char *str1, int n)
{
	int len0;
	int len1;
	int rs;
	len0 = strlen((const u8 *)str0);
	len1 = strlen((const u8 *)str1);
	if (len0 < n || len1 < n)
		return 0;
	rs = func_020923F0((const u8 *)(str0 + (len0 - n)), (const u8 *)(str1 + (len1 - n)), n);
	return rs == 0;
}
