/*
 * function: func_021B97A8
 * address:  0x021B97A8
 * packet:   pkt_ov016_021B97A8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * w9_nm2:   still DIFF (173 to 182 B), not improved. Tried a BTAUTO struct for the
 *           global (alloc pointer at +4, mem +0x54, work +0x40/+0x5c, maxap +0x70),
 *           dropping the `t` local (the compiler folds 0xd0 + 0xc0 into 0x190 and
 *           hoists 0x24d0/0xc0), and three local declaration orders. The object
 *           keeps maxap in r6 and t in r7 with no frame; ours spills maxap to
 *           [sp] and materialises 0xc0 and the 0x24d0 pool word early.
 *
 * sdk:      InitAtermApcNetwork (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * symbols:
 *   func_021B970C  0x021B970C  thumb  ov016
 *   func_021B95EC  0x021B95EC  thumb  ov016
 *   func_02085A38  0x02085A38  arm
 *   func_021B9734  0x021B9734  thumb  ov016
 *   func_021B976C  0x021B976C  thumb  ov016
 *   g_021DCFD0  0x021DCFD0  data
 */

extern void func_021B970C(void);
extern int func_021B95EC(void (*cb)(int), void *work, int size);
extern void func_02085A38(unsigned long msec);
extern int func_021B9734(void);
extern void func_021B976C(int event);
extern int g_021DCFD0[];

int func_021B97A8(int maxap)
{
	int loop_flag;
	int retv;
	int ev;
	int t;
	loop_flag = 1;
	g_021DCFD0[28] = maxap;
	func_021B970C();
	t = maxap * 0xd0;
	g_021DCFD0[21] = ((int (*)(int))g_021DCFD0[1])(t + 0x24d0 + maxap * 0xc0);
	if (g_021DCFD0[21] == 0)
		return -1;
	g_021DCFD0[16] = (g_021DCFD0[21] + 0x1f) & -32;
	g_021DCFD0[23] = (g_021DCFD0[16] + (t + 0x2490) + 0x1f) & -32;
	if (func_021B95EC(func_021B976C, (void *)g_021DCFD0[16], t + 0x2490) == 0)
		return -2;
	do {
		func_02085A38(10);
		while ((ev = func_021B9734()) != 0) {
			switch (ev) {
			case 4:
			case 5:
				break;
			case 6:
				loop_flag = 0;
				retv = 1;
				break;
			default:
				loop_flag = 0;
				retv = -2;
				break;
			}
		}
	} while (loop_flag);
	return retv;
}
