/*
 * file:     unit_0219E9C0.c
 * unit:     yes
 * function: func_0219E9C0, func_0219E9C8, func_0219E9D0
 * address:  0x0219E9C0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_0219E9C0(int *p, int v);
void func_0219E9C8(unsigned char *p, unsigned char v);
unsigned char func_0219E9D0(const unsigned char *p);

/*
 * Stores a word at +0x10.
 */
void func_0219E9C0(int *p, int v)
{
    p[4] = v;
}

/*
 * Stores a byte at +0x14.
 */
void func_0219E9C8(unsigned char *p, unsigned char v)
{
    p[0x14] = v;
}

/*
 * Byte at +0x14.
 */
unsigned char func_0219E9D0(const unsigned char *p)
{
    return p[0x14];
}
