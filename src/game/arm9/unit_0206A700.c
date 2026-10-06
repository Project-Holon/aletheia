/*
 * file:     unit_0206A700.c
 * unit:     yes
 * function: func_0206A700, func_0206A854
 * address:  0x0206A700
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_02148B4C  0x02148B4C  data
 *   data_02148B54  0x02148B54  data
 *   data_02148B98  0x02148B98  data
 *   data_02148C08  0x02148C08  data
 *   func_0207B598  0x0207B598  arm
 *   func_0207BDB4  0x0207BDB4  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   g_02148B4C       0x02148B4C  data
 *   func_0206DDA4    0x0206DDA4  arm
 */
typedef unsigned int u32;

extern void func_0207B598(void *);
extern void func_0207BDB4(void *);
extern void func_0207ADC4(void *);
extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
void func_0206A700(void);
void func_0206A854(void);
extern u32 data_02148B4C[];
extern u32 data_02148B54[];
extern u32 data_02148B98[];
extern u32 data_02148C08[];
extern u32  g_02148B4C[];


/*
 * The 3D/rig register block init at data_02148B4C: sixteen pool constants
 * written into the block around three subsystem calls, then a second pass
 * over the 0xec..0x260 window after func_0207ADC4 returns.
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell (docs/FRONTEND-PINS.md),
 * in both of its recorded forms at once. (a) The image RE-LOADS the block
 * base pool word 0x02148B4C THREE separate times -- `ldr r1, [pc, #0x108]`
 * at 0x0206A708, `ldr r1, [pc, #0xb4]` at 0x0206A75C and `ldr r0, [pc,
 * #0x44]` at 0x0206A7CC, all three resolving to the SINGLE pool word at
 * 0x0206A818 -- which is why the frame is a bare `push {r3, lr}`
 * (`08 40 2d e9`). (b) It materialises the f04 zero as its own `mov r0, #0`
 * (`00 00 a0 e3`) at 0x0206A70C and stores f00/f04 as two separate `str`.
 * dsi/1.1p1 -O4,p hoists the base into callee-saved r5 and CSEs the zero
 * into r4, needing `push {r3, r4, r5, lr}`, and then MERGES the f00/f04
 * pair into one `stm r5, {r0, r4}`: 312 bytes against the original's 340,
 * 247 concrete bytes out. Under the pin the same C is 340 bytes,
 * 0 mismatches, all 7 relocation sites resolving.
 */
void func_0206A700(void)
{
    u32 *g = data_02148B4C;
    u32 a, b;

    g[0x00 / 4] = 0x17101610;
    g[0x04 / 4] = 0;
    g[0x48 / 4] = 2;
    g[0x7c / 4] = 0x32323232;
    g[0x90 / 4] = 0x60293130;
    g[0xa4 / 4] = 0x33333333;
    g[0xb8 / 4] = 0x002A1B19;
    func_0207B598(data_02148B98);
    func_0207BDB4(data_02148B54);

    a = 0x40000200;
    b = 0xC0080000;
    g = data_02148B4C;
    g[0x80 / 4] = 0x2D8B62D8;
    g[0x84 / 4] = a;
    g[0x88 / 4] = a + 0x3FFFFFFF;
    g[0x8c / 4] = b;
    g[0x94 / 4] = 0x4210C210;
    g[0x98 / 4] = 0x4210C210;
    g[0x9c / 4] = 0x001F008F;
    g[0xa0 / 4] = b - 0x90000;
    g[0xa8 / 4] = 0x00007FFF;
    g[0xac / 4] = 0x4000001F;
    g[0xb0 / 4] = 0x800003E0;
    g[0xb4 / 4] = 0x7e00 - a;
    g[0xe0 / 4] = 0;
    g[0xe4 / 4] = 0;
    g[0xe8 / 4] = 0;
    func_0207ADC4(data_02148C08);

    g = data_02148B4C;
    g[0xec / 4] = 0x1000;
    g[0xf0 / 4] = 0x1000;
    g[0xf4 / 4] = 0x1000;
    g[0xf8 / 4] = 0;
    g[0xfc / 4] = 0;
    g[0x248 / 4] = 0;
    g[0x244 / 4] = 0;
    g[0x240 / 4] = 0;
    g[0x254 / 4] = 0;
    g[0x24c / 4] = 0;
    g[0x250 / 4] = 0x1000;
    g[0x25c / 4] = 0;
    g[0x258 / 4] = 0;
    g[0x260 / 4] = (u32)-0x1000;
}


/*
 * The "leave this rig mode" counterpart of src/matched/func_0206A8FC.c: one
 * registration of the 0x3e record at g_02148B4C + 4, keyed by the word at
 * g_02148B4C[0], then bits 0 and 1 of the "initialised subsystems" flag word
 * at g_02148B4C + 0xFC are both cleared (the exact pair func_0206A8FC sets and
 * clears on the way in).
 *
 * PINNED ../2.0/sp2 on the "kept constants" tell, same family and same pass as
 * func_0206A8FC.  The image RE-LOADS the single pool word at 0x0206A880
 * (0x02148B4C) twice, at 0x0206A858 and 0x0206A868, and keeps the frame at
 * `push {r3, lr}` (`08 40 2d e9`).  dsi/1.1p1 -O4,p hoists that one address
 * into callee-saved r4, giving `push {r4, lr}` and a single `ldr r4, [pc]`,
 * 36 concrete bytes out at the same 48.  Under the pin the C below is 48
 * bytes, 0 mismatches, both sites resolving.
 *
 * TWO SPELLING POINTS, both of them four bytes each and both needed at once,
 * which is why the intermediate attempts all sat at 52 bytes:
 *   1. the record pointer is `(char *)g_02148B4C + 4`, NOT `g_02148B4C + 1`.
 *      Spelled as the array index the front end folds the offset into a
 *      SECOND pool word; through the char cast the offset stays a runtime add,
 *      which 2.0 then fuses with the value load into the image's single
 *      post-indexed `ldr r0, [r1], #4` at 0x0206A860.  The same cast is what
 *      pins the 0xE registration in func_0206A8FC, for the same reason.
 *   2. the two bit clears must be SEPARATE statements.  Written as one
 *      expression (`& ~1u & ~2u`, or `& ~3u`) the front end folds them to a
 *      single `bic r1, r1, #3`, four bytes short of the image's `bic #1` at
 *      0x0206A870 followed by `bic #2` at 0x0206A874.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A854.c \
 *       --func func_0206A854 --addr 0x0206A854 --arm --cc ../2.0/sp2
 */
void func_0206A854(void)
{
    func_0206DDA4(g_02148B4C[0], (char *)g_02148B4C + 4, 0x3e);
    g_02148B4C[0x3f] &= ~1u;
    g_02148B4C[0x3f] &= ~2u;
}
