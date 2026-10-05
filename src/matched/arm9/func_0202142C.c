/*
 * function: func_0202142C
 * address:  0x0202142C
 * packet:   pkt_020213F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0008 ABS32 func_020213F8          : 020213F8 (thumb, from name) has no witness outside 0202142C..02021438
 */

extern unsigned short func_020213F8(int a0, int a1);

unsigned short func_0202142C(int a0)
{
    return func_020213F8(a0, 0);
}
