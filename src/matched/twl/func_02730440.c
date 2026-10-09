/*
 * function: func_02730440
 * address:  0x02730440
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027303C4 0x027303C4 arm twl
 */
typedef unsigned int u32;

extern u32 func_027303C4(void);

u32 func_02730440(u32 a)
{
    return func_027303C4() + (a << 15);
}
