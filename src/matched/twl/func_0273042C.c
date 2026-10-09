/*
 * function: func_0273042C
 * address:  0x0273042C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027303A4 0x027303A4 arm twl
 */
typedef unsigned int u32;

extern u32 func_027303A4(void);

u32 func_0273042C(u32 a)
{
    return func_027303A4() + (a << 16);
}
