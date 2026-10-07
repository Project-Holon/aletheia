/*
 * file:     unit_021CEF20_p02.c
 * unit:     yes
 * function: func_021CF080, func_021CF114
 * address:  0x021CF080
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WM_ReadStatus  0x0208EBE4  arm
 *   WM_Reset  0x0208F400  arm
 *   WM_End  0x0208F43C  arm
 *   func_021CF174  0x021CF174  arm  ov016
 *   g_021DE640  0x021DE640  data
 *   memcmp  0x020923F0  arm
 *   g_021DA8C4  0x021DA8C4  data
 */
typedef struct {
	char pad0[0x20];
	unsigned char essid[6];
	char pad1[4];
} APINFO;

typedef struct {
	void *buf;
	int w1;
	unsigned short period;
	unsigned short pad;
	int rest[14];
} SCANPRM;

typedef struct {
	unsigned short state;
	char pad[0x7ce];
} WMSTAT;

typedef struct {
	char pad0[0xf00];
	char buf[0x400];
	APINFO ap[20];
	SCANPRM scan;
	WMSTAT status;
	unsigned char flag;
	char pad1[3];
} MS_021CF080;

typedef struct {
	char pad0[0x1300];
	APINFO ap[20];
	char scan[0x1e5c - 0x1300 - 20 * 0x2a];
	unsigned char flag;
	char pad1[3];
} MS_021CF114;

extern int WM_ReadStatus(void *statusBuf);
extern int WM_Reset(void (*callback)(void *));
extern int WM_End(void (*callback)(void *));
extern void func_021CF174(void *arg);
extern int memcmp(const void *a, const void *b, unsigned long n);
int func_021CF080(void);
int func_021CF114(APINFO **info);
extern MS_021CF080 *g_021DE640;
extern unsigned char g_021DA8C4[6];


/*
 * sdk:      DWCi_SEARCHlStop (libdwcutil.TWL.HYB.a(search.o))
 */
int func_021CF080(void)
{
	int rs;

	g_021DE640->flag = 1;
	WM_ReadStatus(&g_021DE640->status);
	if (g_021DE640->status.state != 2) {
		rs = WM_Reset(func_021CF174);
		if (rs != 2)
			return 0;
		do {
			WM_ReadStatus(&g_021DE640->status);
		} while (g_021DE640->status.state != 2);
	}
	rs = WM_End(func_021CF174);
	if (rs != 2)
		return 0;
	return 1;
}


/*
 * sdk:      DWCi_SEARCHlGetApInfo (libdwcutil.TWL.HYB.a(search.o))
 */
int func_021CF114(APINFO **info)
{
	int num;
	int i;
	APINFO *ap;

	num = 0;
	ap = g_021DE640->ap;
	*info = ap;
	for (i = 0; i < 20; i++) {
		if (memcmp(ap[i].essid, g_021DA8C4, 6) != 0)
			num++;
	}
	return num;
}
