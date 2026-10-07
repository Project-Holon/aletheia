/*
 * file:     unit_068991A4.c
 * unit:     yes
 * function: func_068991A4, func_068991B0
 * address:  0x068991A4
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
 *   d_0689D738 0x0689D738 data a4
 *   func_068991D4 0x068991D4 thumb ov095
 *   func_068991E4 0x068991E4 thumb ov095
 *   func_068991F4 0x068991F4 thumb ov095
 */
typedef unsigned char u8;

extern int func_068991D4(int);
extern int func_068991E4(u8);
extern void func_068991F4(int, int);
unsigned int *func_068991A4(unsigned int *out);
void func_068991B0(int a0, int a1, int value);
extern unsigned int d_0689D738;

/*
 * follower: store-return leaf after non-C veneer 0x06899194.
 */
unsigned int *func_068991A4(unsigned int *out)
{
    *out = 1;
    return &d_0689D738;
}

/*
 * extent: trailing two-byte alignment padding at 0x068991D2.
 */
void func_068991B0(int a0, int a1, int value)
{
    int two;
    two = 2;
    if (value == func_068991E4(func_068991D4(two))) {
        func_068991F4(0x35, two << 12);
    }
}
