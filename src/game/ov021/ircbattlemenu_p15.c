/*
 * file:     ircbattlemenu_p15.c
 * unit:     yes
 * function: func_02198998, func_021989A4, func_021989B0, func_021989BC, func_021989C8
 * address:  0x02198998
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
 *   func_02198960  0x02198960  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern void func_02198960(u32 a1, u32 a2);
u32 func_02198998(u32 a1);
u32 func_021989A4(u32 a1);
u32 func_021989B0(u32 a1);
u32 func_021989BC(u32 a1);
u32 func_021989C8(u32 a1);


/*
 * Calls func_02198960(its own argument 1, 0x1) and returns 0x1.
 */
u32 func_02198998(u32 a1)
{
    func_02198960(a1, 0x1);

    return 0x1;
}


/*
 * Calls func_02198960(its own argument 1, 0x2) and returns 0x1.
 */
u32 func_021989A4(u32 a1)
{
    func_02198960(a1, 0x2);

    return 0x1;
}


/*
 * Calls func_02198960(its own argument 1, 0x4) and returns 0x1.
 */
u32 func_021989B0(u32 a1)
{
    func_02198960(a1, 0x4);

    return 0x1;
}


/*
 * Calls func_02198960(its own argument 1, 0x8) and returns 0x1.
 */
u32 func_021989BC(u32 a1)
{
    func_02198960(a1, 0x8);

    return 0x1;
}


/*
 * Calls func_02198960(its own argument 1, 0xf) and returns 0x1.
 */
u32 func_021989C8(u32 a1)
{
    func_02198960(a1, 0xf);

    return 0x1;
}
