/*
 * file:     ircbattlemenu_p19.c
 * unit:     yes
 * function: func_02198B4C, func_02198B80, func_02198BA8
 * address:  0x02198B4C
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D534  0x0216D534  thumb  ov010
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_021BB5C8  0x021BB5C8  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int BOOL;

extern void *func_0216D6BC(int a0, int a1, int a2);
extern void *func_0216D67C(void *a0);
extern u32 func_0216D534(void *p);
extern u32 func_02188CD0(u8 *p);
extern u32 func_021BB528(u32, u32, u32, u32);
extern void func_0216D7CC(u8 *p);
extern void *func_0216D6D4(void *p);
extern int func_021BB5C8(u32);
extern void func_021AC154(u32);
void func_02198B4C(u32 a, u32 b, u32 a3);
int func_02198B80(u32 a);
u32 func_02198BA8(u32 a1);


/*
 * Addresses are Black-image addresses.
 */
void func_02198B4C(u32 a, u32 b, u32 a3)
{
    u32 *p;

    p = func_0216D6BC(a, 8, a3);
    p[0] = b;
    p[1] = func_021BB528(func_02188CD0((u8 *)func_0216D534(func_0216D67C((void *)a))), a, b, 1);
    func_0216D7CC((u8 *)a);
}


int func_02198B80(u32 a)
{
    u32 *p;

    p = func_0216D6D4((void *)a);
    if (func_021BB5C8(p[1]) == 1) {
        func_021AC154(p[1]);
        func_0216D7CC((u8 *)a);
        return 1;
    }
    return 0;
}


/*
 * Calls func_02198B4C(its own argument 1, 0x0, 0x0) and returns 0x0.
 */
u32 func_02198BA8(u32 a1)
{
    func_02198B4C(a1, 0x0, 0x0);

    return 0x0;
}
