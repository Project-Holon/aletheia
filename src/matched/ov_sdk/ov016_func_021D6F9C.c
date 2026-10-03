/*
 * function: func_021D6F9C
 * address:  0x021D6F9C
 * packet:   pkt_ov016_021D6F9C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OVRlInit (libdwcutil.TWL.HYB.a(objvram.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_021D6D44  0x021D6D44  arm  ov016
 *   func_021D6E04  0x021D6E04  arm  ov016
 *   func_021D6DF4  0x021D6DF4  arm  ov016
 *   g_021DE6AC  0x021DE6AC  data
 */

typedef struct {
	int a;
	int b;
	short size;
	short d;
} OvrNode;

typedef struct {
	char pad[0x180];
	OvrNode node[2];
	void *list;
	void *que;
} OvrInfo;

extern void *func_021D6414(unsigned long size, int align);
extern void *func_021D5410(long size, void *data, long dsize);
struct ListCB;
extern struct ListCB *func_021D6D44(void);
extern void func_021D6E04(void *list, void *ob);
extern void func_021D6DF4(void *list, void *ob);
extern OvrInfo *g_021DE6AC;

void func_021D6F9C(void)
{
	int i;

	g_021DE6AC = func_021D6414(0x340, 4);
	for (i = 0; i < 2; i++) {
		g_021DE6AC[i].que = func_021D5410(0x20, &g_021DE6AC[i], 0xc);
		g_021DE6AC[i].list = func_021D6D44();
		g_021DE6AC[i].node[0].size = 0x300;
		g_021DE6AC[i].node[1].size = 0x400;
		func_021D6E04(g_021DE6AC[i].list, &g_021DE6AC[i].node[0]);
		func_021D6DF4(g_021DE6AC[i].list, &g_021DE6AC[i].node[1]);
	}
}
