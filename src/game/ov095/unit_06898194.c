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
 *   func_021D76BC  0x021D76BC  thumb
 *   func_021D775C  0x021D775C  thumb
 *   d_0689D628 0x0689D628 data a4
 */
extern int func_021D775C(int);
extern void func_021D76BC(int, int);
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
    value = func_021D775C(61);
    func_021D76BC(61, value + 1);
}
