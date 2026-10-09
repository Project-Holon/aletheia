/*
 * file:     ircbattlemenu_p09.c
 * unit:     yes
 * function: func_02198978, func_02198998, func_021989A4, func_021989B0, func_021989BC, func_021989C8, func_021989D4, func_021989E0
 * address:  0x02198978
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
 *   func_0216D6D4 0x0216D6D4  thumb  ov010
 *   func_0216D7CC 0x0216D7CC  thumb  ov010
 *   func_02198960  0x02198960  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef int BOOL;

extern void *func_0216D6D4(void *p);
extern void func_0216D7CC(u8 *p);
extern void func_02198960(u32 a1, u32 a2);
int func_02198978(u32 a);
u32 func_02198998(u32 a1);
u32 func_021989A4(u32 a1);
u32 func_021989B0(u32 a1);
u32 func_021989BC(u32 a1);
u32 func_021989C8(u32 a1);
u32 func_021989D4(u32 a1);
u32 func_021989E0(u32 a1);



/*
 * Addresses are Black-image addresses.
 */
int func_02198978(u32 a)
{
    int *p;

    p = (int *)func_0216D6D4((void *)a);
    if (*p != 0) {
        *p -= 1;
        return 0;
    }
    func_0216D7CC((u8 *)a);
    return 1;
}




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
