/*
 * file:     unit_02198D3C_p01.c
 * unit:     yes
 * function: func_02198D3C, func_02198D4C, func_02198D5C, func_02198D6C, func_02198D7C, func_02198D94, func_02198DA4, func_02198DB4, func_02198DC4, func_02198DD4, func_02198DEC
 * address:  0x02198D3C
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
 *   func_02198C4C       0x02198C4C  thumb
 *   DWCca_ghttp_caList  0x021D4A44  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);
extern int func_02198C4C(u32 a, u32 *b);
u32 func_02198D3C(u32 a1);
u32 func_02198D4C(u32 a1);
u32 func_02198D5C(u32 a1);
u32 func_02198D6C(u32 a1);
BOOL func_02198D7C(char *url);
u32 func_02198D94(u32 a1);
u32 func_02198DA4(u32 a1);
u32 func_02198DB4(u32 a1);
u32 func_02198DC4(u32 a1);
BOOL func_02198DD4(char *url);
u32 func_02198DEC(u32 a1);
extern char DWCca_ghttp_caList[];


/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D3C(u32 a1)
{
    func_02198C08(a1, 0x0, 0x3, 0x7);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D4C(u32 a1)
{
    func_02198C08(a1, 0x1, 0x3, 0x7);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D5C(u32 a1)
{
    func_02198C08(a1, 0x2, 0x3, 0x7);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x3, 0x7) and returns 0x1.
 */
u32 func_02198D6C(u32 a1)
{
    func_02198C08(a1, 0x3, 0x3, 0x7);

    return 0x1;
}


/*
 * TwlDWC GHTTP root CA list setter (libdwcghttp / dwc_ghttp.o).
 * Forwards the URL and this file's CA list to ghttpSetRootCAList and
 * returns whether it reports success (1).
 */
BOOL func_02198D7C(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}


/*
 * Calls func_02198C08(its own argument 1, 0x0, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198D94(u32 a1)
{
    func_02198C08(a1, 0x0, 0x7, 0x8);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x1, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198DA4(u32 a1)
{
    func_02198C08(a1, 0x1, 0x7, 0x8);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x2, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198DB4(u32 a1)
{
    func_02198C08(a1, 0x2, 0x7, 0x8);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x3, 0x7, 0x8) and returns 0x1.
 */
u32 func_02198DC4(u32 a1)
{
    func_02198C08(a1, 0x3, 0x7, 0x8);

    return 0x1;
}


BOOL func_02198DD4(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}


/*
 * Calls func_02198C08(its own argument 1, 0x0, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198DEC(u32 a1)
{
    func_02198C08(a1, 0x0, 0xc, 0x9);

    return 0x1;
}
