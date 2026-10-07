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
 *   d_0689D758 0x0689D758 data a4
 *   func_06899098 0x06899098 thumb ov095
 *   func_068990A8 0x068990A8 thumb ov095
 *   func_068990B8 0x068990B8 thumb ov095
 *   func_068990C8 0x068990C8 thumb ov095
 *   func_068990D8 0x068990D8 thumb ov095
 */
typedef unsigned char u8;

extern int func_06899098(int);
extern int func_068990A8(int);
extern int func_068990B8(int);
extern int func_068990C8(int);
extern int func_068990D8(int, int);
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
    v = func_06899098(2);
    if (value == func_068990A8(v)) {
        if (func_068990B8(0x20) < 0) {
            if (v != func_068990C8(3)) {
                *out = func_068990D8(0x41, 1);
            }
        }
    }
}
