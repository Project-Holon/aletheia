/*
 * file:     fldmmdl_blact_p16.c
 * unit:     yes
 * function: func_0219DC58, func_0219DC64, func_0219DC70
 * address:  0x0219DC58
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
 *   func_0219DC34  0x0219DC34  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef int BOOL;

extern int func_0219DC34(u32 a, u32 b);
u32 func_0219DC58(u32 a1);
u32 func_0219DC64(u32 a1);
u32 func_0219DC70(u32 a1);


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
