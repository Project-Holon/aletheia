/*
 * file:     unit_0215CD3C_p04.c
 * unit:     yes
 * function: func_0215CF88, func_0215CF98
 * address:  0x0215CF88
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215CF14  0x0215CF14  arm
 */
extern void func_0215CF14(int v);
void func_0215CF88(const int *p);
void func_0215CF98(const int *p);


/*
 * Tail call on the word at +0xa0 of the object.
 */
void func_0215CF88(const int *p)
{
    func_0215CF14(p[0x28]);
}


/*
 * Tail call on the word at +0xa4 of the object.
 */
void func_0215CF98(const int *p)
{
    func_0215CF14(p[0x29]);
}
