/*
 * function: func_021CEF50
 * address:  0x021CEF50
 * packet:   pkt_ov016_021CEF50
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SEARCHlEnd (libdwcutil.TWL.HYB.a(search.o))
 *
 * notes:    the two pool words are the same address (MemSearch); the second
 *           extern g_021DE640_b keeps them apart.
 *
 * symbols:
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE640  0x021DE640  data
 *   g_021DE640_b  0x021DE640  data
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
extern MS *g_021DE640_b;

void func_021CEF50(void)
{
	if (g_021DE640 != 0) {
		while (WM_GetAllowedChannel() != 0x8000) {
		}
		func_021D6438((void **)&g_021DE640_b);
	}
}
