/*
 * file:     ircbattlemenu_p10.c
 * unit:     yes
 * function: func_02198460, func_02198470, func_02198480, func_02198490, func_021984A0
 * address:  0x02198460
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
 *   func_02198318  0x02198318  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern void func_02198318(u32 a, u32 b, u16 c, u16 d);
u32 func_02198460(u32 a1);
u32 func_02198470(u32 a1);
u32 func_02198480(u32 a1);
u32 func_02198490(u32 a1);
u32 func_021984A0(u32 a1);


/*
 * Calls func_02198318(its own argument 1, 0x2, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198460(u32 a1)
{
    func_02198318(a1, 0x2, 0x4, 0x4);

    return 0x1;
}


/*
 * Calls func_02198318(its own argument 1, 0x3, 0x4, 0x4) and returns 0x1.
 */
u32 func_02198470(u32 a1)
{
    func_02198318(a1, 0x3, 0x4, 0x4);

    return 0x1;
}


/*
 * Calls func_02198318(its own argument 1, 0x0, 0x2, 0x5) and returns 0x1.
 */
u32 func_02198480(u32 a1)
{
    func_02198318(a1, 0x0, 0x2, 0x5);

    return 0x1;
}


/*
 * Calls func_02198318(its own argument 1, 0x1, 0x2, 0x5) and returns 0x1.
 */
u32 func_02198490(u32 a1)
{
    func_02198318(a1, 0x1, 0x2, 0x5);

    return 0x1;
}


/*
 * Calls func_02198318(its own argument 1, 0x2, 0x2, 0x5) and returns 0x1.
 */
u32 func_021984A0(u32 a1)
{
    func_02198318(a1, 0x2, 0x2, 0x5);

    return 0x1;
}
