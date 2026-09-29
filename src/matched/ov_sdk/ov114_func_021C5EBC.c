/*
 * function: func_021C5EBC
 * address:  0x021C5EBC
 * packet:   pkt_ov114_021C5EBC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      setAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C7A18  0x021C7A18  arm  ov114
 *   func_021C659C  0x021C659C  arm  ov114
 *   func_021C60AC  0x021C60AC  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021D3BD8  0x021D3BD8  data
 */

extern unsigned long func_021C7A18(char *p);
extern void func_021C659C(int err, int servererror);
extern int func_021C60AC(int len);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
extern int g_021D3B9C[];
extern char *g_021D3BD8[];

int func_021C5EBC(int id, char *attr)
{
	int encLen;
	int n;
	if (*attr != 0) {
		if ((int)func_021C7A18(attr) > 10) {
			func_021C659C(5, 0);
			return 0;
		}
		n = func_021C7A18(attr);
		if (n > 10) {
			func_021C659C(5, 0);
			return 0;
		}
		g_021D3BD8[id] = ((char *(*)(int, int))g_021D3B9C[1])(func_021C60AC(n) + 1, 4);
		if (g_021D3BD8[id] == 0) {
			func_021C659C(1, 0);
			return 0;
		}
		encLen = func_021C60C8(g_021D3BD8[id], attr, n);
		g_021D3BD8[id][encLen] = 0;
	}
	return 1;
}
