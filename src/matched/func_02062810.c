/*
 * function: func_02062810
 * address:  0x02062810
 * packet:   pkt_02062810
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062BAC 0x02062BAC arm
 */

extern void func_02062BAC(void);
asm void func_02062810(void)
{
    ldr ip, =func_02062BAC
    add r0, r0, #8
    bx ip
}
