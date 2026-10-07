/*
 * file:     unit_0219E264.c
 * unit:     yes
 * function: func_0219E264, func_0219E26C
 * address:  0x0219E264
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_0219E264(int *p, int v);
int func_0219E26C(const int *p);

/*
 * Stores a word at +0x24.
 */
void func_0219E264(int *p, int v)
{
    p[9] = v;
}

/*
 * Word at +0x24.
 */
int func_0219E26C(const int *p)
{
    return p[9];
}
