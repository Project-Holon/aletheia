/*
 * file:     unit_021C7934.c
 * unit:     yes
 * function: func_021C7934, func_021C797C, func_021C79AC, func_021C79C0
 * address:  0x021C7934
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
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   g_021D3C20  0x021D3C20  data
 *   g_021D3B9C  0x021D3B9C  data
 *   d_021D3C20   0x021D3C20  data
 *   d_021D3B9C   0x021D3B9C  data
 *   func_02087C6C  0x02087C6C  arm
 *   func_021C7B48  0x021C7B48  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 */
typedef unsigned long u32_021C797C;

typedef unsigned char u8;

typedef unsigned int u32_021C79AC;

extern void func_02086028(void *m);
extern void func_02086078(void *m);
extern void OS_LockMutex(void *mutex);
extern void OS_UnlockMutex(void *mutex);
extern void func_02085DBC(int, int, int);
extern void func_02087C6C(unsigned char *macAddress);
extern int func_021C7B48(char *p, unsigned long n, int figure);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
int func_021C7934(void);
void DWCi_Ndi_unprepareHttpCallback(void);
void func_021C79AC(int a);
void func_021C79C0(char *macaddr);
extern char g_021D3C20[];
extern int g_021D3B9C[];
extern char d_021D3C20[];
extern char d_021D3B9C[];


int func_021C7934(void)
{
	int rc;
	func_02086028(g_021D3C20);
	rc = (g_021D3B9C[8] == 0);
	if (rc)
		g_021D3B9C[8] = 1;
	func_02086078(g_021D3C20);
	return rc;
}


void DWCi_Ndi_unprepareHttpCallback(void)
{
    OS_LockMutex(d_021D3C20);
    *(u32_021C797C *)(d_021D3B9C + 0x20) = 0;
    OS_UnlockMutex(d_021D3C20);
}


/*
 * Thunk: func_02085DBC(a, 0, 0).
 */
void func_021C79AC(int a)
{
    func_02085DBC(a, 0, 0);
}


/*
 * sdk:      DWCi_Ndi_getMacAddress (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void func_021C79C0(char *macaddr)
{
	unsigned char madr[6];
	char strmadr[12];
	int i;
	func_02087C6C(madr);
	for (i = 0; i < 6; i++)
		func_021C7B48(strmadr + i * 2, madr[i], 2);
	func_021C60C8(macaddr, strmadr, 12);
}
