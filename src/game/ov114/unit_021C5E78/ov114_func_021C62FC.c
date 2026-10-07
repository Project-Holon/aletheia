/*
 * function: func_021C62FC
 * address:  0x021C62FC
 * packet:   pkt_ov114_021C62FC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      strAlloc (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C7A18  0x021C7A18  arm  ov114
 *   func_021C7A44  0x021C7A44  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021C7A18(const u8 *a0);
extern void func_021C7A44(void *dst, void *src, int size);
extern int g_021D3B9C[];

char *func_021C62FC(char *src)
{
	int n;
	char *dst;
	n = func_021C7A18((const u8 *)src);
	dst = ((char *(*)(int, int))g_021D3B9C[1])(n + 1, 4);
	if (dst) {
		func_021C7A44(dst, src, n);
		dst[n] = 0;
	}
	return dst;
}
