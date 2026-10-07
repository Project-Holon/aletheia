/*
 * file:     fldmmdl_blact_p21.c
 * unit:     yes
 * function: func_0219DFCC, func_0219DFDC, func_0219DFEC
 * address:  0x0219DFCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0219DE64  0x0219DE64  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern void func_0219DE64(u32 a, u32 b, u16 c, u16 d);
u32 func_0219DFCC(u32 a1);
u32 func_0219DFDC(u32 a1);
u32 func_0219DFEC(u32 a1);


/*
 * Calls func_0219DE64(its own argument 1, 0x0, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFCC(u32 a1)
{
    func_0219DE64(a1, 0x0, 0x4, 0x4);

    return 0x1;
}


/*
 * Calls func_0219DE64(its own argument 1, 0x1, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFDC(u32 a1)
{
    func_0219DE64(a1, 0x1, 0x4, 0x4);

    return 0x1;
}


/*
 * Calls func_0219DE64(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_0219DFEC(u32 a1)
{
    func_0219DE64(a1, 0x2, 0x4, 0x4);

    return 0x1;
}
