/*
 * function: DWCi_SEARCHlBegin
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
 *   gSearchWork  0x021DE640  data
 *   sSearchScanParam  0x021DA8CC  data
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
extern MS *gSearchWork;
extern SCANPRM sSearchScanParam;

int DWCi_SEARCHlBegin(void)
{
	int rs;

	MIi_CpuClear16(0, gSearchWork->ap, 0x348);
	rs = WM_Initialize(gSearchWork, func_021CF174, 3);
	if (rs != 2)
		return 0;
	do {
		WM_ReadStatus(&gSearchWork->status);
	} while (gSearchWork->status.state != 2);
	gSearchWork->scan = sSearchScanParam;
	gSearchWork->scan.buf = gSearchWork->buf;
	gSearchWork->scan.period = WM_GetDispersionScanPeriod();
	return func_021CF04C() != 0;
}
