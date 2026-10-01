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
 * sdk:      InitAtermApcNetwork (libdwcutil.TWL.HYB.a(atermset.o))
 *
 * wave8 (2026-10-01).  Best body is now 164 B (image 164 B), 62 concrete
 * bytes differ; previously 160 B / 117.  The MASK residue is SOLVED by an
 * enum-typed mask local (see docs/idioms/an-enum-local-mask-keeps-ands-
 * instead-of-bics.md): `AlignMask am = ALIGN_MASK;` with `ALIGN_MASK = -32`
 * makes the backend materialise the complement and use `ands` instead of
 * folding `& -32` to `movs #0x1f / bics`, restoring the 4-byte size gap.
 *
 * DWARF (scratch/laneU55/objs/atermset.o, decl_line 206 atermapc.c) has
 * exactly three entities: maxap (DW_OP_reg6), loop_flag (reg4), retv (reg5);
 * no `t`, no `ev`.  Members touched: gMaxApList +0x70, atermapc_work +0x54,
 * apc_work +0x40, ap_list +0x5c, gAtermAlloc +0x4.  .comment 3.0.0.126 =
 * ../2.0/sp1p2, so the pin is right.
 *
 * blocker: LINEAR-COMBINATION FOLD.  With no `t` local the allocator gives
 * maxap r6 exactly as the image, but this front end folds
 * `maxap*0xd0 + 0x24d0 + maxap*0xc0` to `movs #0x19 / lsls #4 / muls`
 * (0x190*maxap) and re-computes maxap*0xd0 at line 217.  The image keeps the
 * two multiplies because it materialised `t` (r7).  Naming `t` restores the
 * two muls but the allocator then homes the named temp in r6 and the
 * parameter in r7 — the reverse of the image (all of int/unsigned/long/enum/
 * register `t` and two named temps measured: same).  Enum-typed SIZE
 * constants (SZ_ATERM/SZ_APC) do NOT stop the fold.  All ../2.0 subdirs give
 * the same; this residue is a front-end value-numbering preference and no
 * bundled build reproduces the image's CSE-over-fold choice.
 * Spellings measured and rejected: casts ((unsigned)/(unsigned long)/(int)),
 * 0xc0u/0xc0L, sizeof, enum sizes, parenthesised groups, swapped operands,
 * 10 declaration orders, shadow maxap, two named temps, register/width of t.
 *
 * Remaining residue is ONE front-end choice: same size (164 B), maxap already
 * in r6; the fold vs. CSE-of-t decision.  Status DIFF, not EXACT.
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

typedef enum { ALIGN_MASK = -32 } AlignMask;

int func_021B97A8(int maxap)
{
	int loop_flag;
	int retv;
	int ev;
	AlignMask am = ALIGN_MASK;
	loop_flag = 1;
	g_021DCFD0[28] = maxap;
	func_021B970C();
	g_021DCFD0[21] = ((int (*)(int))g_021DCFD0[1])(maxap * 0xd0 + 0x24d0 + maxap * 0xc0);
	if (g_021DCFD0[21] == 0)
		return -1;
	g_021DCFD0[16] = (g_021DCFD0[21] + 0x1f) & am;
	g_021DCFD0[23] = (g_021DCFD0[16] + maxap * 0xd0 + 0x2490 + 0x1f) & am;
	if (func_021B95EC(func_021B976C, (void *)g_021DCFD0[16], maxap * 0xd0 + 0x2490) == 0)
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
