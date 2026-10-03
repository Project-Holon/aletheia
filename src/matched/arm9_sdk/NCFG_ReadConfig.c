/*
 * function: NCFG_ReadConfig
 * address:  0x0205FAA8
 * packet:   pkt_0205FAA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0205FFC4 0x0205FFC4 arm
 */

struct NCFGConfig;
extern int func_0205FFC4(struct NCFGConfig *config);

asm void NCFG_ReadConfig(void)
{
    stmfd sp!, {r3, lr}
    bl func_0205FFC4
    cmp	r0, #0
    movne	r0, #0
    mvneq	r0, #0
    ldmfd sp!, {r3, pc}
}
