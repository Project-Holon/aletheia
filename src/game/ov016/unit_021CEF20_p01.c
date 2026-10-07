/*
 * file:     unit_021CEF20_p01.c
 * unit:     yes
 * function: func_021CEF20, func_021CEF50
 * address:  0x021CEF20
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   g_021DE640  0x021DE640  data
 *   WM_GetAllowedChannel  0x0208EE60  arm
 *   func_021D6438  0x021D6438  arm  ov016
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

extern void *func_021D6414(unsigned long size, int alignment);
extern unsigned short WM_GetAllowedChannel(void);
extern void func_021D6438(void **mem);
void func_021CEF20(void);
void func_021CEF50(void);
extern MS *g_021DE640;
extern MS *g_021DE640_b;


/*
 * sdk:      DWCi_SEARCHlInit (libdwcutil.TWL.HYB.a(search.o))
 */
void func_021CEF20(void)
{
	if (g_021DE640 == 0)
		g_021DE640 = (MS *)func_021D6414(0x1e60, 0x20);
}


/*
 * sdk:      DWCi_SEARCHlEnd (libdwcutil.TWL.HYB.a(search.o))
 *
 * notes:    the two pool words are the same address (MemSearch); the second
 *           extern g_021DE640_b keeps them apart.
 */
void func_021CEF50(void)
{
	if (g_021DE640 != 0) {
		while (WM_GetAllowedChannel() != 0x8000) {
		}
		func_021D6438((void **)&g_021DE640_b);
	}
}
