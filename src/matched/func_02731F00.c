/*
 * function: func_02731F00
 * address:  0x02731F00
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02702980  0x02702980  arm  twl
 */

typedef unsigned int u32;

extern u32 func_02702980(void);

u32 func_02731F00(void)
{
    return (func_02702980() << 15) >> 16;
}
