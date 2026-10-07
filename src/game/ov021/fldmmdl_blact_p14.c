/*
 * file:     fldmmdl_blact_p14.c
 * unit:     yes
 * function: func_0219DB44, func_0219DB48
 * address:  0x0219DB44
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
 *   func_0219DC08  0x0219DC08  thumb  ov021
 *   func_021AC578  0x021AC578  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0219DC08(u32 a);
extern u32 func_021AC578(u32, u32);
void func_0219DB44(u32 a0, u32 a1, u32 a2, u32 a3);
int func_0219DB48(u32 a, u32 b, u32 c, u32 d);


/*
 * An empty function.
 */
void func_0219DB44(u32 a0, u32 a1, u32 a2, u32 a3)
{
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219DB48(u32 a, u32 b, u32 c, u32 d)
{
return func_021AC578(a, func_0219DC08(a));
}
