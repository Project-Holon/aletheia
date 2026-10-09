/*
 * function: func_02731154
 * address:  0x02731154
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02004490 0x02004490 thumb
 *   func_02088610 0x02088610 arm
 */
typedef unsigned int u32;

extern void func_02004490(u32);
extern int func_02088610(u32, u32, u32);

void func_02731154(u32 a, u32 b)
{
    while (func_02088610(0x12, b, a) != 0) {
        func_02004490(1);
    }
}
