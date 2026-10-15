/*
 * function: BufferAddNTS
 * address:  0x0219FCF0
 * packet:   pkt_ov009_0219FCF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BufferAddNTS (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_02092344  0x02092344  arm
 *   gSBEmptyString  0x021A8230  data
 */

extern int gSBEmptyString;
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
void BufferAddNTS(char **buffer, char *str, int *len)
{
	int slen;
	if (!str)
		str = (char *)&gSBEmptyString;
	slen = func_0209477C((const u8 *)str) + 1;
	func_02092344(*buffer, str, slen);
	*len += slen;
	*buffer += slen;
}
