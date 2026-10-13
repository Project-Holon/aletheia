/*
 * function: func_021CF04C
 * address:  0x021CF04C
 * packet:   pkt_ov016_021CF04C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      startScan (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   WM_StartScanEx  0x0208F698  arm
 *   func_021CF174  0x021CF174  arm  ov016
 *   gSearchWork  0x021DE640  data
 */

typedef struct {
	char pad0[0x20];
	unsigned char essid[6];
	char pad1[4];
} APINFO;

typedef struct {
	char pad0[0x1300];
	APINFO ap[20];
	char scan[0x1e5c - 0x1300 - 20 * 0x2a];
	unsigned char flag;
	char pad1[3];
} MS;

extern int WM_StartScanEx(void (*callback)(void *), void *param);
extern void func_021CF174(void *arg);
extern MS *gSearchWork;

int func_021CF04C(void)
{
	return WM_StartScanEx(func_021CF174, gSearchWork->scan) == 2;
}
