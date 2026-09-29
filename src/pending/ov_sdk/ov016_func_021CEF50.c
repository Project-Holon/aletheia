/*
 * function: func_021CEF50
 * address:  0x021CEF50
 * packet:   pkt_ov016_021CEF50
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_SEARCHlEnd (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE640  0x021DE640  data
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

extern unsigned short WM_GetAllowedChannel(void);
extern void func_021D6438(void **mem);
extern MS *g_021DE640;

void func_021CEF50(void)
{
	if (g_021DE640 != 0) {
		if (WM_GetAllowedChannel() == 0x8000)
			func_021D6438((void **)0x021DE640);
	}
}
