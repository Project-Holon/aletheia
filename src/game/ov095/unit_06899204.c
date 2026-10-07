/*
 * file:     unit_06899204.c
 * unit:     yes
 * function: func_06899204, func_06899210
 * address:  0x06899204
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
 *   d_0689D730 0x0689D730 data a4
 *   func_06899230 0x06899230 thumb ov095
 *   func_06899240 0x06899240 thumb ov095
 *   func_06899250 0x06899250 thumb ov095
 */
typedef unsigned char u8;

extern int func_06899230(int);
extern int func_06899240(u8);
extern void func_06899250(int, int);
unsigned int *func_06899204(unsigned int *out);
void func_06899210(int a0, int a1, int value);
extern unsigned int d_0689D730;

/*
 * follower: store-return leaf after non-C veneer 0x068991F4.
 */
unsigned int *func_06899204(unsigned int *out)
{
    *out = 1;
    return &d_0689D730;
}

void func_06899210(int a0, int a1, int value)
{
    if (value == func_06899240(func_06899230(4))) {
        func_06899250(0x41, 1);
    }
}
