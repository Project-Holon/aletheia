/*
 * function: DWCi_Language
 * address:  0x020461E4
 * packet:   pkt_020461E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A54 0x02146A54 data
 */

extern void g_02146A54(void);
asm void DWCi_Language(void)
{
    ldr r0, =g_02146A54
    ldrb r0, [r0]
    bx lr
}
