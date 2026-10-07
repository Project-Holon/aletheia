/*
 * file:     unit_06898104.c
 * unit:     yes
 * function: func_06898104, func_06898110
 * address:  0x06898104
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
 *   d_0689D620 0x0689D620 data a4
 *   func_0689812C 0x0689812C thumb ov095
 *   func_0689813C 0x0689813C thumb ov095
 */
extern int func_0689812C(int);
extern void func_0689813C(int, int);
void *func_06898104(int *p);
void func_06898110(void);
extern unsigned char d_0689D620[];

/*
 * extent: 12-byte leaf, followed by labelled func_06898110.
 */
void *func_06898104(int *p)
{
    *p = 1;
    return d_0689D620;
}

void func_06898110(void)
{
    if (func_0689812C(22) == 9)
        func_0689813C(49, 0x548);
}
