/*
 * file:     fld3d_ci_p09.c
 * unit:     yes
 * function: func_021C2EBC, func_021C2ECC, func_021C2EDC
 * address:  0x021C2EBC
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
 *   func_021C2F50  0x021C2F50  thumb  ov021
 */
#include "../../matched/include/Obj18295.h"
#include "../../matched/include/Obj18296.h"
#include "../../matched/include/Obj18297.h"
#include "../../matched/include/Obj18298.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 v[4]; } T;

extern void func_021C2F50(char *dst, const char *src);
extern int func_0206E62C(void *a, T *t);
int func_021C2EBC(u32 a, u32 b);
int func_021C2ECC(u32 a, u32 b);
int func_021C2EDC(u8 *p, const char *name);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2EBC(u32 a, u32 b)
{
return (((((struct Obj18296 *)((u8 *)(b)))->f0 << 16) >> 13) + ((((struct Obj18295 *)((u8 *)(a)))->f8 << 16) >> 13));
}


int func_021C2ECC(u32 a, u32 b)
{
return ((((struct Obj18298 *)((u8 *)(b)))->f0 << 3) + ((((struct Obj18297 *)((u8 *)(a)))->f2C << 16) >> 13));
}


/*
 * Builds a request block and dispatches func_021C2EBC on success (EXACT*: pad).
 */
int func_021C2EDC(u8 *p, const char *name)
{
    T t;
    int r;

    func_021C2F50((char *)&t, name);
    if (p != 0)
        r = func_0206E62C(p + 0x3C, &t);
    else
        r = 0;
    if (r == 0)
        return 0;
    return func_021C2EBC((u32)p, r);
}
