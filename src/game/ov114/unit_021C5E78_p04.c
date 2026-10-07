/*
 * file:     unit_021C5E78_p04.c
 * unit:     yes
 * function: func_021C64E0, func_021C651C, func_021C654C, func_021C659C
 * address:  0x021C64E0
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
 *   func_021C5E78  0x021C5E78  arm  ov114
 *   func_021C78DC  0x021C78DC  arm  ov114
 *   func_021C7930  0x021C7930  arm  ov114
 *   g_021D3B9C     0x021D3B9C  data
 *   d_021D3B9C   0x021D3B9C  data
 *   nhttpCleanupCallback   0x021C64E0  arm
 *   func_021C78E0  0x021C78E0  arm  ov114
 *   func_021BF3BC  0x021BF3BC  arm  ov114
 *   func_021BF184  0x021BF184  arm  ov114
 *   func_021C78F4  0x021C78F4  arm  ov114
 *   func_02059F54  0x02059F54  arm
 */
typedef struct NdGlobals {
    unsigned char pad0[0x14];
    void (*f14)(void *arg);
    void *f18;
    void *f1C;
    unsigned char pad1[0x24 - 0x20];
    void (*f24)(void);
} NdGlobals;

typedef unsigned long u32;

extern void func_021C5E78(void);
extern void func_021C78DC(void);
extern void func_021C7930(void);
extern void func_021BE680(int a);
extern void nhttpCleanupCallback(void);
extern void func_021C78E0(void);
extern int func_021BF3BC(int a);
extern int func_021BF184(int a);
extern void func_021C78F4(void);
extern void func_02059F54(int error, int errorCode);
void func_021C64E0(void);
void DWCi_NdCleanupAsync(void *callback);
int func_021C654C(void *volatile handle);
void func_021C659C(int err, int servererror);
extern NdGlobals g_021D3B9C;
extern char d_021D3B9C[];


void func_021C64E0(void)
{
    func_021C5E78();
    func_021C78DC();
    func_021C7930();
    g_021D3B9C.f14(g_021D3B9C.f18);
    g_021D3B9C.f14(g_021D3B9C.f1C);
    g_021D3B9C.f24();
}


void DWCi_NdCleanupAsync(void *callback)
{
    *(u32 *)(d_021D3B9C + 8) = 0;
    *(void **)(d_021D3B9C + 0x24) = callback;
    func_021C654C(*(void **)(d_021D3B9C + 0x10));
    func_021BE680((int)nhttpCleanupCallback);
}


/*
 * sdk:      DWCi_NdCleanupConnectionHandle (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C654C(void *volatile handle)
{
	int result = 1;
	func_021C78E0();
	if (handle) {
		func_021BF3BC((int)handle);
		if (func_021BF184((int)handle) != 0)
			result = 0;
		else
			handle = 0;
	}
	func_021C78F4();
	return result;
}


/*
 * sdk:      DWCi_NdSetError (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
void func_021C659C(int err, int servererror)
{
	switch (err) {
	case 1:
		func_02059F54(9, -31001);
		break;
	case 3:
		func_02059F54(14, -31020);
		break;
	case 4:
		func_02059F54(13, -31040);
		break;
	case 7:
		func_02059F54(13, -31000 - servererror);
		break;
	case 5:
		func_02059F54(13, -31040);
		break;
	case 8:
		func_02059F54(9, -31009);
		break;
	case 2:
		func_02059F54(13, -31010);
		break;
	case 0:
	case 6:
		break;
	default:
		func_02059F54(9, -31009);
		break;
	}
}
