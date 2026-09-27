/*
 * function: CARD_GetBackupSectorSize
 * address:  0x02076B6C
 * packet:   pkt_02076B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02150200 0x02150200 data
 */

extern void g_02150200(void);

asm void CARD_GetBackupSectorSize(void)
{
    ldr r0, =g_02150200
    ldr	r0, [r0]
    ldr	r0, [r0, #0x1c]
    bx	lr
}
