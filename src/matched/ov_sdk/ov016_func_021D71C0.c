/*
 * function: func_021D71C0
 * address:  0x021D71C0
 * packet:   pkt_ov016_021D71C0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OVRlFree (libdwcutil.TWL.HYB.a(objvram.o))
 *
 * symbols:
 *   func_021D6D8C  0x021D6D8C  arm  ov016
 *   func_021D546C  0x021D546C  arm  ov016
 *   g_021DE6AC  0x021DE6AC  data
 */

typedef struct {
	char pad[0x180];
	int node[6];
	void *list;
	void *que;
} OvrInfo;

extern void func_021D6D8C(void *ob);
extern void func_021D546C(void *que, void *data);
extern OvrInfo *g_021DE6AC;

void func_021D71C0(void *ovram)
{
	int lcd = 0;

	func_021D6D8C(ovram);
	if ((char *)ovram >= (char *)g_021DE6AC + 0x1a0)
		lcd = 1;
	func_021D546C(g_021DE6AC[lcd].que, ovram);
}
