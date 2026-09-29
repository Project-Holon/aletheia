/*
 * function: func_021C1488
 * address:  0x021C1488
 * packet:   pkt_ov016_021C1488
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RAKUlInit (libdwcutil.TWL.HYB.a(rakuraku.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021BC63C  0x021BC63C  thumb  ov016
 *   OS_Terminate  0x02088234  arm
 *   func_02085A38  0x02085A38  arm
 *   g_021DE594  0x021DE594  data
 *   func_021C1624  0x021C1624  arm  ov016
 *   func_021C15FC  0x021C15FC  arm  ov016
 *   func_021C1614  0x021C1614  arm  ov016
 */

extern void *func_021D6414(unsigned long size, int align);
extern int func_021BC63C(int prio, int maxap, void (*notify)(void *), void *(*alloc)(unsigned long), void (*free)(void *), unsigned long stack);
extern void OS_Terminate(void);
extern void func_02085A38(unsigned long msec);
extern void func_021C1624(void *ptr);
extern void func_021C15FC(void *arg);
extern void *func_021C1614(unsigned long size);
extern void *g_021DE594;

void func_021C1488(void)
{
	g_021DE594 = func_021D6414(0xc, -4);
	if (func_021BC63C(0xf, 0x40, func_021C15FC, func_021C1614, func_021C1624, 0x800) != 1)
		OS_Terminate();
	func_02085A38(10);
}
