/*
 * file:     unit_06899D2C_p01.c
 * unit:     yes
 * function: func_06899D2C, func_06899D38
 * address:  0x06899D2C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_06899D2C(void);
void func_06899D30(void);
void func_06899D38(void);

/*
 * note: veneer follower unit; function_starts seeds 06899D2C, 06899D30.
 */
void func_06899D2C(void) {}

void func_06899D30(void) { func_06899D38(); }

/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_06899D38(void)
{
}
