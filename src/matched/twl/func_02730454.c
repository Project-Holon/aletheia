/*
 * function: func_02730454
 * address:  0x02730454
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027303EC 0x027303EC arm twl
 */
typedef unsigned int u32;

extern u32 func_027303EC(void);

u32 func_02730454(u32 a)
{
    return func_027303EC() + (a << 15);
}
