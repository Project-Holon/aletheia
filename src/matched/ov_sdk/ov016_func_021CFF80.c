/*
 * function: func_021CFF80
 * address:  0x021CFF80
 * packet:   pkt_ov016_021CFF80
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SNDlEnd (libdwcutil.TWL.HYB.a(sound.o))
 *
 * symbols:
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE648  0x021DE648  data
 */

typedef struct {
	char pad[0xa8];
	void *task;
} SND;

extern void func_021D7724(int kind, void *task);
extern void func_021D6438(void **mem);
extern SND *g_021DE648;

void func_021CFF80(void)
{
	func_021D7724(0, g_021DE648->task);
	func_021D6438((void **)0x021DE648);
}
