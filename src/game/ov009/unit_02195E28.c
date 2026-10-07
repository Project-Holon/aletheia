/*
 * file:     unit_02195E28.c
 * unit:     yes
 * function: func_02195E28, func_02195E30, func_02195E38, func_02195E40, func_02195E48
 * address:  0x02195E28
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
int func_02195E28(const int *p);
unsigned short func_02195E30(const unsigned short *p);
int func_02195E38(const int *p);
unsigned short func_02195E40(const unsigned short *p);
int func_02195E48(const int *p);

/*
 * First word of the object.
 */
int func_02195E28(const int *p)
{
    return *p;
}

/*
 * Halfword at +4.
 */
unsigned short func_02195E30(const unsigned short *p)
{
    return p[2];
}

/*
 * Word at +4.
 */
int func_02195E38(const int *p)
{
    return p[1];
}

/*
 * Halfword at +8.
 */
unsigned short func_02195E40(const unsigned short *p)
{
    return p[4];
}

/*
 * Word at +0x54.
 */
int func_02195E48(const int *p)
{
    return p[0x15];
}
