/*
 * function: func_021CF114
 * address:  0x021CF114
 * packet:   pkt_ov016_021CF114
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SEARCHlGetApInfo (libdwcutil.TWL.HYB.a(search.o))
 *
 * symbols:
 *   memcmp  0x020923F0  arm
 *   g_021DE640  0x021DE640  data
 *   g_021DA8C4  0x021DA8C4  data
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

extern int memcmp(const void *a, const void *b, unsigned long n);
extern MS *g_021DE640;
extern unsigned char g_021DA8C4[6];

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
