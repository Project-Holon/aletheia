/*
 * function: func_021CEF20
 * address:  0x021CEF20
 * packet:   pkt_ov016_021CEF20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SEARCHlInit (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
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

extern void *func_021D6414(unsigned long size, int alignment);
extern MS *g_021DE640;

void func_021CEF20(void)
{
	if (g_021DE640 == 0)
		g_021DE640 = (MS *)func_021D6414(0x1e60, 0x20);
}
