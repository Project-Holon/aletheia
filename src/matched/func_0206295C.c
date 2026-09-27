/*
 * function: func_0206295C
 * address:  0x0206295C
 * packet:   pkt_0206295C
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
asm void func_0206295C(void)
{
    ldr ip, =func_02062BAC
    add r0, r0, #8
    bx ip
}
