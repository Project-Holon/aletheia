/*
 * file:     unit_06898194.c
 * unit:     yes
 * function: func_06898194, func_068981A0
 * address:  0x06898194
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
 *   d_0689D628 0x0689D628 data a4
 *   func_068981B4 0x068981B4 thumb ov095
 *   func_068981C4 0x068981C4 thumb ov095
 */
extern int func_068981B4(int);
extern void func_068981C4(int, int);
unsigned *func_06898194(unsigned *p);
void func_068981A0(void);
extern unsigned d_0689D628[];

unsigned *func_06898194(unsigned *p)
{
    *p = 1;
    return d_0689D628;
}

void func_068981A0(void)
{
    int value;
    value = func_068981B4(61);
    func_068981C4(61, value + 1);
}
