/*
 * file:     unit_021DA624_p05.c
 * unit:     yes
 * function: func_021DAB24, func_021DAB48
 * address:  0x021DAB24
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 *   d_021F0790 0x021F0790 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 */
extern int func_021DA8A8(int, int, int);
extern void func_021DA96C(void *, int, unsigned int, int);
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
void func_021DAB24(int a, void *b, int c);
void func_021DAB48(int a, int b, int c);
void *func_021DAB6C(int *p);
extern unsigned char d_021F0790[];


/*
 * extent: trailing two-byte alignment padding.
 */
void func_021DAB24(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 0xc))
        func_021DA96C(b, c, 5, 1);
}


/*
 * extent: includes store-and-return followers 021DAB6C.
 */
void func_021DAB48(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x15) == 7)
        func_021D76BC(0x4b, 1);
}


void *func_021DAB6C(int *p)
{
    *p = 1;
    return d_021F0790;
}
