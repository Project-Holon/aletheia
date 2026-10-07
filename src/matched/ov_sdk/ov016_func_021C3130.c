/*
 * function: func_021C3130
 * address:  0x021C3130
 * packet:   pkt_ov016_021C3130
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispPush (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   g_021DE5A8  0x021DE5A8  data
 *   g_021DA4B0  0x021DA4B0  data
 *   func_021CE7B0  0x021CE7B0  arm  ov016
 */

#include "../include/G_FocusPosT.h"

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

extern void func_021CE7B0(void *p, int a, int b);
extern struct FocusPosT g_021DE5A8;
extern unsigned char g_021DA4B0[3];

void func_021C3130(void)
{
	int n = g_021DA4B0[g_021DE5A8.idx];
	func_021CE7B0(g_021DE5A8.ptr, n, n);
}
