/*
 * function: func_021CEF84
 * address:  0x021CEF84
 * packet:   pkt_ov016_021CEF84
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SEARCHlBegin (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   MIi_CpuClear16  0x02082A48  arm
 *   WM_Initialize  0x0208F370  arm
 *   WM_ReadStatus  0x0208EBE4  arm
 *   WM_GetDispersionScanPeriod  0x0208EFC4  arm
 *   func_021CF04C  0x021CF04C  arm  ov016
 *   func_021CF174  0x021CF174  arm  ov016
 *   g_021DE640  0x021DE640  data
 *   g_021DA8CC  0x021DA8CC  data
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
} MS;

extern void MIi_CpuClear16(unsigned short data, void *destp, unsigned long size);
extern int WM_Initialize(void *wmSysBuf, void (*callback)(void *), unsigned short dmaNo);
extern int WM_ReadStatus(void *statusBuf);
extern unsigned short WM_GetDispersionScanPeriod(void);
extern int func_021CF04C(void);
extern void func_021CF174(void *arg);
extern MS *g_021DE640;
extern SCANPRM g_021DA8CC;

int func_021CEF84(void)
{
	int rs;

	MIi_CpuClear16(0, g_021DE640->ap, 0x348);
	rs = WM_Initialize(g_021DE640, func_021CF174, 3);
	if (rs != 2)
		return 0;
	do {
		WM_ReadStatus(&g_021DE640->status);
	} while (g_021DE640->status.state != 2);
	g_021DE640->scan = g_021DA8CC;
	g_021DE640->scan.buf = g_021DE640->buf;
	g_021DE640->scan.period = WM_GetDispersionScanPeriod();
	return func_021CF04C() != 0;
}
