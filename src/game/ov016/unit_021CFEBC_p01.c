/*
 * file:     unit_021CFEBC_p01.c
 * unit:     yes
 * function: func_021CFF80, func_021CFFAC
 * address:  0x021CFF80
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
 *   func_021D7724  0x021D7724  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE648  0x021DE648  data
 */
#include "../../matched/include/G_SND.h"

typedef struct {
	char pad[0xa8];
	void *task;
} SND;

typedef unsigned int   u32;

extern void func_021D7724(int kind, void *task);
extern void func_021D6438(void **mem);
extern u32 func_02075618(u32 a, u32 b, u32 c);
void func_021CFF80(void);
void func_021CFFAC(unsigned int v);
extern struct SND *g_021DE648;


/*
 * sdk:      DWCi_SNDlEnd (libdwcutil.TWL.HYB.a(sound.o))
 */
void func_021CFF80(void)
{
	func_021D7724(0, g_021DE648->task);
	func_021D6438((void **)0x021DE648);
}


void func_021CFFAC(unsigned int v)
{
    func_02075618((u32)(*(char **)0x021DE648 + 0xa0), 0, v);
}
