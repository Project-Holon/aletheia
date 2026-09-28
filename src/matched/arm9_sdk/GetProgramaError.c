/*
 * function: GetProgramaError
 * address:  0x0205D178
 * packet:   pkt_0205D178
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 */

asm int GetProgramaError(int err)
{
    cmp r0, #3
    addls pc, pc, r0, lsl #2
    b loc_default

    b case_0
    b case_1
    b case_2
    b case_3

case_1:
    mvn r0, #8
    bx lr

case_0:
    mvn r0, #9
    bx lr

case_2:
    mvn r0, #7
    bx lr

case_3:
    mvn r0, #6
    bx lr

loc_default:
    mov r0, #0
    bx lr
}
