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
 *   func_021B9A40  0x021B9A40  thumb
 *   func_021D76BC  0x021D76BC  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D730 0x0689D730 data a4
 */
typedef unsigned char u8;

extern int func_021D775C(int);
extern int func_021B9A40(u8);
extern void func_021D76BC(int, int);
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
    if (value == func_021B9A40(func_021D775C(4))) {
        func_021D76BC(0x41, 1);
    }
}
