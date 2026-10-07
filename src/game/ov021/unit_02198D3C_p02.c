/*
 * file:     unit_02198D3C_p02.c
 * unit:     yes
 * function: func_02198DFC, func_02198E0C, func_02198E1C, func_02198E2C, func_02198E44
 * address:  0x02198DFC
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
 *   DWCca_ghttp_caList  0x021D4A9C  data
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02198C08(u32 a1, u32 a2, u32 a3, u32 a4);
extern int func_02198C4C(u32 a, u32 *b);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern u32 func_0216D7CC(u32);
u32 func_02198DFC(u32 a1);
u32 func_02198E0C(u32 a1);
u32 func_02198E1C(u32 a1);
BOOL func_02198E2C(char *url);
int func_02198E44(u32 a, u32 b, u32 c, u32 d);
extern char DWCca_ghttp_caList[];


/*
 * Calls func_02198C08(its own argument 1, 0x1, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198DFC(u32 a1)
{
    func_02198C08(a1, 0x1, 0xc, 0x9);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x2, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198E0C(u32 a1)
{
    func_02198C08(a1, 0x2, 0xc, 0x9);

    return 0x1;
}


/*
 * Calls func_02198C08(its own argument 1, 0x3, 0xc, 0x9) and returns 0x1.
 */
u32 func_02198E1C(u32 a1)
{
    func_02198C08(a1, 0x3, 0xc, 0x9);

    return 0x1;
}


/*
 * TwlDWC GHTTP root CA list setter (libdwcghttp / dwc_ghttp.o).
 * Forwards the URL and this file's CA list to ghttpSetRootCAList and
 * returns whether it reports success (1).
 */
BOOL func_02198E2C(char *url)
{
    if (func_02198C4C((u32)url, (u32 *)DWCca_ghttp_caList) == 1)
    {
        return 1;
    }
    return 0;
}


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02198E44(u32 a, u32 b, u32 c, u32 d)
{
func_0216D6BC(a, 4, c);
func_0216D674((void *)a, 10);
func_0216D7CC(a);
return 0;
}
