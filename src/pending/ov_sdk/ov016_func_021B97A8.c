/*
 * function: func_021B97A8
 * address:  0x021B97A8
 * packet:   pkt_ov016_021B97A8
 * region:   ov016
 * compiler: ../2.0/sp1p2
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
 * T6: pin corrected to ../2.0/sp1p2 (atermset.o, the object SetFrameData
 * 0x021B9FE0 already pins). Under it this function drops from 188 B / 164
 * concrete diffs (dsi/1.1p1) to 160 B / 117 (image 164 B). Residue, in order:
 * (a) the object keeps maxap in r6 and t = maxap*0xd0 in r7, this build swaps
 * them (maxap r7, t r6) - visible from +0002; (b) both `& -32` masks: the
 * object materialises -0x20 as `movs r1,#0x1f / adds r0,r1,#0 / subs r0,#0x3f`
 * and uses `ands`, this build folds each to `movs r3,#0x1f / bics`; that fold
 * is exactly the 4-byte size gap. Tried: four local declaration orders,
 * `& -32`/`& -0x20`/`& 0xFFFFFFE0`/`& 0xffffffe0u`/`& (int)0xffffffe0u`, an
 * `int mask = -32;` local used by both masks, `int t` declared mid-block,
 * unsigned int t` - all byte-identical at 160 B.
 *
 * lane U10 (2026-09-30), pin ../2.0/sp1p2 recorded in the compiler field.
 * Re-measured 160 B / 117 diffs (image 164).  10 local declaration orders
 * (loop_flag/retv/ev/t in every position, `long t`, t declared mid-block, t in
 * a nested block) are all 160/117; R7 order 160/119.  The two residues are
 * independent and both in the first block:
 *  (a) PROLOGUE, +0002: image `adds r6, r0, #0` keeps maxap in r6 and the
 *      maxap*0xd0 temp in r7; ours swaps them (`adds r7, r0, #0`, t in r6).
 *      Dropping the `t` local fixes the prologue exactly (maxap r6) and leaves
 *      168 B / 140: the front end then folds maxap*0xd0 + maxap*0xc0 into
 *      0x190*maxap (`movs r0,#0x19 / lsls r0,r0,#4 / muls`), which the image
 *      does not do (it keeps `movs r0,#0xd0 / adds r7,r6,#0 / muls r7,r0,r7`).
 *      So `t` must stay a declared local for the multiply, and a declared
 *      local takes r6 before the parameter does.  Reordering the multiply's
 *      operands and passing `t` in the first expression do not move it.
 *  (b) MASKS, +0030: image materialises -0x20 out of the live 0x1f
 *      (`movs r1,#0x1f / adds r2,r0,r1 / adds r0,r1,#0 / subs r0,#0x3f /
 *      adds r3,r2,#0 / ands r3,r0`) and reuses r1 for the second mask; ours
 *      recognises `& -32` and folds each to `movs r3,#0x1f / bics`, two
 *      instructions fewer, which is the 4-byte size gap.  `& -32`, `& ~0x1f`,
 *      `& 0xFFFFFFE0`, `& 0xffffffe0u`, an int mask local: identical.
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
