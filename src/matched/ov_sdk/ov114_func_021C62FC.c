/*
 * function: strAlloc
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
 *   DWCi_Ndi_strlen  0x021C7A18  arm  ov114
 *   DWCi_Ndi_memcpy  0x021C7A44  arm  ov114
 *   gDwciNdStatics  0x021D3B9C  data
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 DWCi_Ndi_strlen(const u8 *a0);
extern void DWCi_Ndi_memcpy(void *dst, void *src, int size);
extern int gDwciNdStatics[];

char *strAlloc(char *src)
{
	int n;
	char *dst;
	n = DWCi_Ndi_strlen((const u8 *)src);
	dst = ((char *(*)(int, int))gDwciNdStatics[1])(n + 1, 4);
	if (dst) {
		DWCi_Ndi_memcpy(dst, src, n);
		dst[n] = 0;
	}
	return dst;
}
