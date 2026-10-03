/*
 * function: FSi_ConvertStringSjisToUnicode
 * address:  0x02031948
 * packet:   pkt_02031948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203174C 0x0203174C arm
 */

typedef unsigned int   u32;
struct Blk;
struct In;
extern struct Blk *func_0203174C(const struct In *in, u32 heap, u32 c, u32 d, u32 e);
asm void FSi_ConvertStringSjisToUnicode(void)
{
    stmfd sp!, {r3, lr}
    ldr ip, [sp, #8]
    str ip, [sp]
    bl func_0203174C
    ldmfd sp!, {r3, pc}
}
