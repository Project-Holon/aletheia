/*
 * file:     fldmmdl_blact_p06.c
 * unit:     yes
 * function: func_0219DC34, func_0219DC58, func_0219DC64, func_0219DC70
 * address:  0x0219DC34
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
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef int BOOL;

extern int func_02163F10(int a0);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D7CC(u32);
int func_0219DC34(u32 a, u32 b);
u32 func_0219DC58(u32 a1);
u32 func_0219DC64(u32 a1);
u32 func_0219DC70(u32 a1);


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
int func_0219DC34(u32 a, u32 b)
{
func_0216D5E0(a, ((b << 16) >> 16));
func_0216D674((void *)a, 0);
func_02163F10(a);
return func_0216D7CC(a);
}



/*
 * Calls func_0219DC34(its own argument 1, 0x0) and returns 0x1.
 */
u32 func_0219DC58(u32 a1)
{
    func_0219DC34(a1, 0x0);

    return 0x1;
}



/*
 * Calls func_0219DC34(its own argument 1, 0x1) and returns 0x1.
 */
u32 func_0219DC64(u32 a1)
{
    func_0219DC34(a1, 0x1);

    return 0x1;
}



/*
 * Calls func_0219DC34(its own argument 1, 0x2) and returns 0x1.
 */
u32 func_0219DC70(u32 a1)
{
    func_0219DC34(a1, 0x2);

    return 0x1;
}
