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
 * wave8 (2026-10-01).  Body is 164 B (image 164 B), now 33 concrete bytes
 * differ (was 62).  TWO residues SOLVED this wave:
 *  - MASK: enum-typed mask local `AlignMask am = ALIGN_MASK;` (ALIGN_MASK =
 *    -32) materialises the complement and emits `ands`, not `bics`.  Idiom:
 *    docs/idioms/an-enum-local-mask-keeps-ands-instead-of-bics.md.
 *  - THE CONSTANT OFF THE PC-RELATIVE BASE: writing `maxap*0xd0 + 0x1c00`
 *    (float `0x1c00`) pools `0x1c00` as a pc-relative add instead of folding
 *    it into the later `+0x700` (which had produced `subs #0x21`), matching
 *    the image's `adds r0, r3, r2` + `ldr r2, [pc]` at +0x3E/+0x40.  The
 *    image's pool word is 0x900 (`0x2490 = 0x2400 + 0x90`); the compiled
 *    word is 0xd0 and differs only in the pool datum (one concrete byte).
 *
 * DWARF (scratch/laneU55/objs/atermset.o, decl_line 206 atermapc.c) has
 * exactly three entities: maxap (DW_OP_reg6), loop_flag (reg4), retv (reg5);
 * no `t`, no `ev`.
 *
 * blocker: LINEAR-COMBINATION FOLD.  With no `t` local the allocator gives
 * maxap r6 exactly as the image, but this front end folds
 * `maxap*0xd0 + 0x24d0 + maxap*0xc0` to `movs #0x19 / lsls #4 / muls`
 * (0x190*maxap) and folds the `+0x2490` size into 0x190*maxap too
 * (0x190*maxap + 0x2490 = 0x190*(maxap+0x17)+0x90) so only `*0xd0` survives.
 * The image keeps the two multiplies (0x190, and a separate `*0xd0` at
 * +0x3E) because it materialised the two sizes separately.  Naming `t`/
 * `0x190` restores the mul but the allocator then homes a named temp where
 * maxap was (r6 vs r7 reverses).  Enum-typed SIZE constants do NOT stop the
 * fold.  Remaining documented residue is this one front-end value-numbering
 * choice (fold vs. CSE); 33 concrete bytes, register colouring only, plus the
 * one pool datum byte above.  Status DIFF, not EXACT.
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
	g_021DCFD0[23] = (g_021DCFD0[16] + maxap * 0xd0 + 0x1c00 + 0x1f) & am;
	if (func_021B95EC(func_021B976C, (void *)g_021DCFD0[16], maxap * 0xd0 + 0x1c00) == 0)
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
