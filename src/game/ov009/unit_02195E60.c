/*
 * file:     unit_02195E60.c
 * unit:     yes
 * function: func_02195E60, func_02195E68, func_02195E70, func_02195E78
 * address:  0x02195E60
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
int func_02195E60(const int *p);
void func_02195E68(int *p, int v);
void func_02195E70(int *p, int v);
int func_02195E78(const int *p);

/*
 * First word of the object, as a getter.
 */
int func_02195E60(const int *p)
{
    return *p;
}

/*
 * Stores a word at +0x30.
 */
void func_02195E68(int *p, int v)
{
    p[0xc] = v;
}

void func_02195E70(int *p, int v)
{
    p[0x10] = v;
}

/*
 * Word at +0x40.
 */
int func_02195E78(const int *p)
{
    return p[0x10];
}
