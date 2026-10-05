/*
 * function: func_021CE94C
 * address:  0x021CE94C
 * packet:   pkt_ov016_021CE94C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SBlEnd (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 */

typedef struct {
	void *cell;
	int pad[2];
	void *task;
} SB;

typedef unsigned char  u8;
extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D4F60(u8 *p);
extern void func_021D6438(void **mem);
extern SB *g_021DE63C;

void func_021CE94C(void)
{
	func_021D7744(0, g_021DE63C->task);
	func_021D4F60(g_021DE63C->cell);
	func_021D6438((void **)0x021DE63C);
}
