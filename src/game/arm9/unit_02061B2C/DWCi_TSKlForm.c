/*
 * function: DWCi_TSKlForm
 * address:  0x02061EA4
 * packet:   pkt_02061EA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02061EB8 0x02061EB8 arm
 */

typedef unsigned int   u32;
struct Blk;
extern int func_02061EB8(struct Blk **list, struct Blk **pool, u32 *pRet, u32 size, u32 alignment);
asm void DWCi_TSKlForm(void)
{
    stmfd sp!, {r3, lr}
    mov ip, #0
    str ip, [sp]
    bl func_02061EB8
    ldmfd sp!, {r3, pc}
}
