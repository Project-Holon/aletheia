/*
 * function: NHTTPi_GetConnection
 * address:  0x0204960C
 * packet:   pkt_0204960C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT *
 * symbols:
 *   func_02078B44 0x02078B44 arm
 */

extern void func_02078B44(void);
asm void NHTTPi_GetConnection(void)
{
    ldr ip, =func_02078B44
    mov r2, #0
    bx ip
}
