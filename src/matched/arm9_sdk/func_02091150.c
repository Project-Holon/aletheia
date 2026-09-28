/*
 * function: func_02091150
 * address:  0x02091150
 * packet:   pkt_02091150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088610  0x02088610  arm
 *   func_02004490  0x02004490  thumb
 */

typedef unsigned int u32;

extern u32 func_02088610(u32 a, u32 b, u32 c);
extern void func_02004490(u32 v);

void func_02091150(u32 a0)
{
    if (func_02088610(0xd, a0, 0) == 0)
        return;

    do {
        func_02004490(1);
    } while (func_02088610(0xd, a0, 0) != 0);
}
