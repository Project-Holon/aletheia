/*
 * function: DWCi_SEARCHlEnd
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
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gSearchWork  0x021DE640  data
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
extern void DWCi_HEAPlFree_(void **mem);
extern MS *gSearchWork;
extern MS *g_021DE640_b;

void DWCi_SEARCHlEnd(void)
{
	if (gSearchWork != 0) {
		while (WM_GetAllowedChannel() != 0x8000) {
		}
		DWCi_HEAPlFree_((void **)&g_021DE640_b);
	}
}
