/*
 * file:     unit_021BEF3C.c
 * unit:     yes
 * function: func_021BEF3C, func_021BEF40, func_021BEF48, func_021BEF50, func_021BEF58
 * address:  0x021BEF3C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned int u32;

void func_021BEF3C(void);
void *func_021BEF40(int p);
void *func_021BEF48(int p);
void *func_021BEF50(int p);
void *func_021BEF58(int p);

/*
 * Empty ARM stub: `bx lr`.
 */
void func_021BEF3C(void)
{
}

/*
 * Field accessor: base + 0x28.
 */
void *func_021BEF40(int p)
{
    return (void *)((char *)p + 0x28);
}

/*
 * Field accessor: base + 0x30.
 */
void *func_021BEF48(int p)
{
    return (void *)((char *)p + 0x30);
}

/*
 * Field accessor: base + 0x50.
 */
void *func_021BEF50(int p)
{
    return (void *)((char *)p + 0x50);
}

/*
 * Field accessor: base + 0x34.
 */
void *func_021BEF58(int p)
{
    return (void *)((char *)p + 0x34);
}
