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
 * wave8 (2026-09-30).  Best body is 160 B / 117 concrete (image 164 B); the
 * two residues below are unchanged from lane U10 and are the whole gap.
 *
 * NEW EVIDENCE this lane: the vendor atermset.o DWARF (scratch/laneU55/objs/
 * atermset.o) pins the source shape exactly.  InitAtermApcNetwork (decl_line
 * 206, atermapc.c) has EXACTLY THREE DWARF entities: the parameter maxap
 * (DW_OP_reg6), loop_flag (line 207, DW_OP_reg4) and retv (line 208,
 * DW_OP_reg5).  There is NO `t` and NO `ev` local; the `maxap * 0xd0` value in
 * r7 is a compiler CSE temp, and it is live across lines 212 and 217.  The
 * object's relocations are all `.bss + 0` (the section base 0x021DCFD0); the
 * members touched are gMaxApList +0x70, atermapc_work +0x54, apc_work +0x40,
 * ap_list +0x5c, gAtermAlloc +0x4 (symbol names from the object's own symbol
 * table).  atermset.o's .comment is `Metrowerks C/C++ for ARM 3.0.0.126`,
 * i.e. ../2.0/sp1p2 (docs/FRONTEND-PINS.md), so the pin is right.
 *
 * blocker: (a) LINEAR-COMBINATION FOLD.  The image keeps two multiplies,
 * `t = 0xd0*maxap` (r7) then `0xc0*maxap` (r0).  With no `t` local this build
 * folds `maxap*0xd0 + 0x24d0 + maxap*0xc0` at -O4,p into
 * `movs r0,#0x19 / lsls r0,r0,#4 / muls` (0x190*maxap) and then RE-computes
 * `maxap*0xd0` for line 217 (168 B).  Blocking the fold with a named `t`, an
 * unsigned/int cast on one factor, `sizeof(...)`, or an enum constant yields
 * the two muls but the allocator then gives r6 to the temp and r7 to the
 * parameter, the reverse of the image (160 B).
 * Spellings measured and rejected: `maxap*0xd0+0x24d0+maxap*0xc0` (fold),
 * `(unsigned)maxap*0xc0`, `(unsigned long)`, `(int)(...)`, `0xc0u`, `0xc0L`,
 * `(char*)0 + ...` (CCERR), parenthesised groups, both operands swapped,
 * `sizeof(struct of 0xd0/0xc0)`, enum-typed sizes, 10 declaration orders of
 * loop_flag/retv/ev/t, a shadow `maxap` local with the parameter renamed.
 * All ten ../2.0 subdirs give 168/141; ../1.2 and dsi give 168-192.
 * (b) MASK.  The image materialises -0x20 out of the live 0x1f
 * (`movs r1,#0x1f / adds r0,r1,#0 / subs r0,#0x3f`) and uses `ands`; this
 * build recognises `& ~0x1f`/`& -32` and folds each mask to
 * `movs rN,#0x1f / bics` (two instructions fewer, the 4-byte size gap).
 * `& -32`, `& ~0x1f`, `& -0x20`, `& (int)0xffffffe0`, `& ~0x1fu`,
 * `& (unsigned long)-32`, `& 0 - 32` are all byte-identical.  APC_Init in the
 * same object (0x021B95EC, matched EXACT under sp1p2) uses the same
 * `& ~0x1F` and DOES fold to bics, so the fold is genuine front-end
 * behaviour, not a source spelling this lane failed to find.  The only body
 * that reproduces the materialised mask is not reachable without also fixing
 * (a); the two are coupled through the scratch register that holds 0x1f.
 *
 * NOTE: the header from lane T6/U10 gave the compiler as ../2.0/sp1p2 and
 * said 188 B/164 under dsi/1.1p1.  The correct body no longer depends on the
 * pin for its size (all 2.0 subdirs are identical here); the residues are a
 * front-end difference that no bundled build reproduces.
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
	g_021DCFD0[23] = (g_021DCFD0[16] + t + 0x2490 + 0x1f) & -32;
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
