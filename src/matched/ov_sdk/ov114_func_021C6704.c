/*
 * function: func_021C6704
 * address:  0x021C6704
 * packet:   pkt_ov114_021C6704
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Ndi_getApInfo (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_0205CD24  0x0205CD24  arm
 *   func_021C7A68  0x021C7A68  arm  ov114
 *   func_021C7A44  0x021C7A44  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 *   g_021CE0E4  0x021CE0E4  data
 *   g_021D3C8C  0x021D3C8C  data
 */

typedef struct {
	char b[13];
} B13;

typedef struct {
	int type;
	int idx;
	int pad;
	char bssid[9];
} ApInfo;

extern int func_0205CD24(ApInfo *apinfo);
typedef unsigned int   u32;
extern void func_021C7A68(char *p, u32 n);
extern void func_021C7A44(void *dst, void *src, int size);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
extern B13 g_021CE0E4;
extern ApInfo g_021D3C8C;

int func_021C6704(char *apinfo)
{
	B13 strAp = g_021CE0E4;
	if (func_0205CD24(&g_021D3C8C)) {
		if (g_021D3C8C.type >= 0 && g_021D3C8C.type < 10)
			strAp.b[1] = g_021D3C8C.type + '0';
		else if (g_021D3C8C.type >= 10 && g_021D3C8C.type < 100)
			func_021C7A68(strAp.b, g_021D3C8C.type);
		if (g_021D3C8C.type == 4 || g_021D3C8C.type == 8) {
			if (g_021D3C8C.idx >= 0 && g_021D3C8C.idx < 10)
				strAp.b[3] = g_021D3C8C.idx + '0';
			func_021C7A44(&strAp.b[4], g_021D3C8C.bssid, 9);
		}
		func_021C60C8(apinfo, strAp.b, 13);
		return 1;
	}
	return 0;
}
