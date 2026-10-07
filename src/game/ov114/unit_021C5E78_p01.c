/*
 * file:     unit_021C5E78_p01.c
 * unit:     yes
 * function: func_021C5EBC, func_021C5F90
 * address:  0x021C5EBC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C7A18  0x021C7A18  arm  ov114
 *   func_021C659C  0x021C659C  arm  ov114
 *   func_021C60AC  0x021C60AC  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021D3BD8  0x021D3BD8  data
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021C5E78  0x021C5E78  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

extern u32 func_021C7A18(const u8 *a0);
extern void func_021C659C(int err, int servererror);
extern int func_021C60AC(int len);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
extern void func_021C78E0(void);
extern void func_021C5E78(void);
extern void func_021C78F4(void);
int func_021C5EBC(int id, char *attr);
int func_021C5F90(char *attr1, char *attr2, char *attr3);
extern int g_021D3B9C[];
extern char *g_021D3BD8[];


/*
 * sdk:      setAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C5EBC(int id, char *attr)
{
	int encLen;
	int n;
	if (*attr != 0) {
		if ((int)func_021C7A18((const u8 *)attr) > 10) {
			func_021C659C(5, 0);
			return 0;
		}
		n = func_021C7A18((const u8 *)attr);
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


/*
 * sdk:      DWCi_NdSetAttr (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C5F90(char *attr1, char *attr2, char *attr3)
{
	func_021C78E0();
	func_021C5E78();
	if (func_021C5EBC(0, attr1) && func_021C5EBC(1, attr2) && func_021C5EBC(2, attr3)) {
		func_021C78F4();
		return 1;
	}
	func_021C5E78();
	func_021C78F4();
	return 0;
}
