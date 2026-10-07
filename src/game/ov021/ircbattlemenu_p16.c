/*
 * file:     ircbattlemenu_p16.c
 * unit:     yes
 * function: func_021989D4, func_021989E0
 * address:  0x021989D4
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
u32 func_021989D4(u32 a1);
u32 func_021989E0(u32 a1);


/*
 * Calls func_02198960(its own argument 1, 0x10) and returns 0x1.
 */
u32 func_021989D4(u32 a1)
{
    func_02198960(a1, 0x10);

    return 0x1;
}


/*
 * Calls func_02198960(its own argument 1, 0x20) and returns 0x1.
 */
u32 func_021989E0(u32 a1)
{
    func_02198960(a1, 0x20);

    return 0x1;
}
