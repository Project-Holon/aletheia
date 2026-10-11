/*
 * file:     unit_06899050.c
 * unit:     yes
 * function: func_06899050, func_0689905C
 * address:  0x06899050
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
 *   d_0689D758 0x0689D758 data a4
 */
typedef unsigned char u8;

extern int func_021D775C(int);
extern int func_021B9A40(int);
extern int func_021D76BC(int, int);
unsigned int *func_06899050(unsigned int *out);
void func_0689905C(int a0, int a1, int value, int *out);
extern unsigned int d_0689D758;

/*
 * follower: store-return leaf after non-C veneer 0x06899040.
 */
unsigned int *func_06899050(unsigned int *out)
{
    *out = 2;
    return &d_0689D758;
}

void func_0689905C(int a0, int a1, int value, int *out)
{
    u8 v;
    v = func_021D775C(2);
    if (value == func_021B9A40(v)) {
        if (func_021D775C(0x20) < 0) {
            if (v != func_021D775C(3)) {
                *out = func_021D76BC(0x41, 1);
            }
        }
    }
}
