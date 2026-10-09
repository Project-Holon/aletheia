/*
 * file:     unit_06899D2C_p01.c
 * unit:     yes
 * function: func_06899D2C, func_06899D38, func_06899D3C
 * address:  0x06899D2C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_06899D54 0x06899D54 thumb ov095
 *   func_06899D64 0x06899D64 thumb ov095
 */
typedef unsigned int u32;

extern int func_06899D54(u32);
extern void func_06899D64(u32);
void func_06899D2C(void);
void func_06899D30(void);
void func_06899D38(void);
void func_06899D3C(u32 p);


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

void func_06899D3C(u32 p)
{
    if (func_06899D54(*(u32 *)(p + 0xB0)) != 0) func_06899D64(p);
}
