/*
 * file:     ircbattlemenu_p21.c
 * unit:     yes
 * function: func_02198CA4, func_02198CB4, func_02198CC4
 * address:  0x02198CA4
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
 *   func_02198C08  0x02198C08  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_02198CA4(u32 a1);
u32 func_02198CB4(u32 a1);
u32 func_02198CC4(u32 a1);


/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CA4(u32 a1)
{
    func_02198C08(a1, 0x0, 0x6, 0x6);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CB4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x6, 0x6);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x6, 0x6) and returns 0x1.
 */
u32 func_02198CC4(u32 a1)
{
    func_02198C08(a1, 0x2, 0x6, 0x6);

    return 0x1;
}
