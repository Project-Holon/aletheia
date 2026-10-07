/*
 * file:     unit_0689814C.c
 * unit:     yes
 * function: func_0689814C, func_06898158
 * address:  0x0689814C
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
 *   d_0689D610 0x0689D610 data a4
 *   func_06898174 0x06898174 thumb ov095
 *   func_06898184 0x06898184 thumb ov095
 */
extern int func_06898174(int);
extern void func_06898184(int, int);
void *func_0689814C(int *p);
void func_06898158(void);
extern unsigned char d_0689D610[];

/*
 * extent: 12-byte leaf, followed by labelled func_06898158.
 */
void *func_0689814C(int *p)
{
    *p = 1;
    return d_0689D610;
}

void func_06898158(void)
{
    if (func_06898174(22) == 12)
        func_06898184(49, 0x548);
}
