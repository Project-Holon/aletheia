/*
 * function: func_021D4A20
 * address:  0x021D4A20
 * packet:   pkt_ov016_021D4A20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_ARClEnd (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   func_02078C34  0x02078C34  arm
 *   func_0207A708  0x0207A708  arm
 *   func_0207A51C  0x0207A51C  arm
 *   func_02078484  0x02078484  arm
 *   func_02084F10  0x02084F10  arm
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DBFD8  0x021DBFD8  data
 *   g_021DE66C  0x021DE66C  data
 */

extern void func_02078C34(char *path);
extern void func_0207A708(void *arc);
extern void func_0207A51C(void *arc);
extern void func_02078484(void *arc);
extern void func_02084F10(int id);
extern void func_021D6438(void *p);
extern char g_021DBFD8[];
extern char *g_021DE66C;

void func_021D4A20(void)
{
	func_02078C34(g_021DBFD8);
	func_0207A708(g_021DE66C + 0x88);
	func_0207A51C(g_021DE66C + 0x88);
	func_02078484(g_021DE66C + 0x88);
	func_02084F10(*(unsigned short *)(g_021DE66C + 0xe4));
	*(unsigned short *)(g_021DE66C + 0xe4) = 0;
	func_021D6438(g_021DE66C);
	*(int *)g_021DE66C = 0;
	func_021D6438(&g_021DE66C);
}
