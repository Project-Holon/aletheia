/*
 * function: func_021C2F34
 * address:  0x021C2F34
 * packet:   pkt_ov016_021C2F34
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCAE4  0x021BCAE4  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5A8  0x021DE5A8  data
 *   func_021C2FA0  0x021C2FA0  arm  ov016
 */

#include "../include/G_FocusPosT.h"

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

extern int func_021D5580(int lcd);
extern void func_021BCAE4(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021C0E40(unsigned int v);
extern void func_021C2FA0(void);
extern struct FocusPosT g_021DE5A8;

void func_021C2F34(void)
{
	if (func_021D5580(1))
		return;
	if (g_021DE5A8.flag)
		func_021BCAE4();
	func_021D55A4(3, 1, 1, 8);
	func_021D55A4(3, 0, 0x14, 8);
	func_021C0E40((unsigned int)func_021C2FA0);
}
