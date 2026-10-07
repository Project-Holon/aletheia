/*
 * file:     unit_021C5E78_p02.c
 * unit:     yes
 * function: func_021C6004, func_021C6048, func_021C60A0, func_021C60AC
 * address:  0x021C6004
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned long u32_021C60A0;

typedef unsigned char u8;

typedef unsigned int u32_021C60AC;

int func_021C6004(unsigned char *dst, char *p, int n);
int func_021C6048(unsigned char c);
u32_021C60A0 DWCi_Ndi_getDecodeLenBASE64(int len);
int func_021C60AC(int n);

/*
 * sdk:      getNchar (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int func_021C6004(unsigned char *dst, char *p, int n)
{
    int i;
    int len;

    len = 0;
    for (i = 0; i < n; i++) {
        if (*p != 0) {
            *dst++ = *p;
            len++;
            p++;
        } else {
            *dst++ = 0;
        }
    }
    return len;
}

/*
 * sdk:      decodeChar (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C6048(unsigned char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	if (c >= '0' && c <= '9')
		return c - '0' + 52;
	if (c == '.')
		return 62;
	if (c == '-')
		return 63;
	return -1;
}


u32_021C60A0 DWCi_Ndi_getDecodeLenBASE64(int len)
{
    return (len >> 2) * 3;
}

/*
 * Row stride: rounds `n` up into 3-byte triples and scales by 4.
 */
int func_021C60AC(int n)
{
    return ((n + 2) / 3) * 4;
}
