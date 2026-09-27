/*
 * unit:     yes
 * function: __dcmp_1, __dcmp_2, __dcmp_3, __dcmp_4, __dcmp_5, __dcmp_6,
 *           __fcmp_1, __fcmp_2, __fcmp_3, __fcmp_4
 * address:  0x0209B7CC
 * packet:   pkt_0209B7CC_compares
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT (each verified independently with match.py one)
 *
 * PENDING, not filed to the manifest -- see converters.c in this same
 * scratchpad for the leak reason (tools/worklist.py's proven_game
 * short-circuit at a layout/runtime_arm9.txt address; no manifest kind
 * exists for hand-written runtime library code).
 *
 * All ten entries are the mrs/msr-apsr float and double comparators: each
 * computes a result and returns it in the condition flags via `mrs ip,
 * apsr` / bic-or-orr of bit 29 (C, the unsigned "hs/lo" family) or bit 30
 * (Z, the "eq/ne" family) / `msr cpsr_flg, ip`, which is a calling
 * convention no C construct can produce.  Verified with:
 *   python tools/match.py one --src <this file> --func <name> --addr <addr>
 *     --cc 1.1p1 --arm
 *
 * Note: 0x0209BB54..0x0209BBB0 (92 bytes), between __dcmp_6's real end and
 * __fcmp_1's listed start, is NOT part of __dcmp_6 and not a
 * layout/runtime_arm9.txt row; disassembly there is a fifth,
 * unlisted-looking float comparator (movge/movlt, bit 29 only). Left
 * completely untouched -- out of scope for this lane, and
 * layout/runtime_arm9.txt is not to be changed here.
 */

asm void __dcmp_1(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209B840
    cmn ip, r3, lsl #1
    bhs L_0209B854
L_0209B7E0:
    orrs ip, r3, r1
    bmi L_0209B810
    cmp r1, r3
    cmpeq r0, r2
    movhs r0, #1
    movlo r0, #0
    bx lr
L_0209B7FC:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B810:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhs r0, #1
    movlo r0, #0
    bx lr
L_0209B840:
    bne L_0209B7FC
    cmp r0, #0
    bhi L_0209B7FC
    cmn ip, r3, lsl #1
    blo L_0209B7E0
L_0209B854:
    bne L_0209B7FC
    cmp r2, #0
    bhi L_0209B7FC
    b L_0209B7E0
}

asm void __dcmp_2(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209B8D8
    cmn ip, r3, lsl #1
    bhs L_0209B8EC
L_0209B878:
    orrs ip, r3, r1
    bmi L_0209B8A8
    cmp r1, r3
    cmpeq r0, r2
    movhi r0, #1
    movls r0, #0
    bx lr
L_0209B894:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B8A8:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhi r0, #1
    movls r0, #0
    bx lr
L_0209B8D8:
    bne L_0209B894
    cmp r0, #0
    bhi L_0209B894
    cmn ip, r3, lsl #1
    blo L_0209B878
L_0209B8EC:
    bne L_0209B894
    cmp r2, #0
    bhi L_0209B894
    b L_0209B878
}

asm void __dcmp_3(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209B97C
    cmn ip, r3, lsl #1
    bhs L_0209B990
L_0209B910:
    orrs ip, r3, r1
    bmi L_0209B944
    cmp r1, r3
    cmpeq r0, r2
    movls r0, #1
    movhi r0, #0
    bx lr
L_0209B92C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B944:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bne L_0209B968
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    orr ip, ip, #0x40000000
    msr cpsr_flg, ip
    bxeq lr
L_0209B968:
    cmp r3, r1
    cmpeq r2, r0
    movls r0, #1
    movhi r0, #0
    bx lr
L_0209B97C:
    bne L_0209B92C
    cmp r0, #0
    bhi L_0209B92C
    cmn ip, r3, lsl #1
    blo L_0209B910
L_0209B990:
    bne L_0209B92C
    cmp r2, #0
    bhi L_0209B92C
    b L_0209B910
}

asm void __dcmp_4(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209BA18
    cmn ip, r3, lsl #1
    bhs L_0209BA2C
L_0209B9B4:
    orrs ip, r3, r1
    bmi L_0209B9E4
    cmp r1, r3
    cmpeq r0, r2
    movlo r0, #1
    movhs r0, #0
    bx lr
L_0209B9D0:
    mov r0, #0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209B9E4:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bne L_0209BA04
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bxeq lr
L_0209BA04:
    cmp r3, r1
    cmpeq r2, r0
    movlo r0, #1
    movhs r0, #0
    bx lr
L_0209BA18:
    bne L_0209B9D0
    cmp r0, #0
    bhi L_0209B9D0
    cmn ip, r3, lsl #1
    blo L_0209B9B4
L_0209BA2C:
    bne L_0209B9D0
    cmp r2, #0
    bhi L_0209B9D0
    b L_0209B9B4
}

asm void __dcmp_5(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209BAA4
    cmn ip, r3, lsl #1
    bhs L_0209BAB8
L_0209BA50:
    orrs ip, r3, r1
    bmi L_0209BA80
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #1
    movne r0, #0
    bx lr
L_0209BA6C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BA80:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #1
    movne r0, #0
    bx lr
L_0209BAA4:
    bne L_0209BA6C
    cmp r0, #0
    bhi L_0209BA6C
    cmn ip, r3, lsl #1
    blo L_0209BA50
L_0209BAB8:
    bne L_0209BA6C
    cmp r2, #0
    bhi L_0209BA6C
    b L_0209BA50
}

asm void __dcmp_6(void)
{
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_0209BB30
    cmn ip, r3, lsl #1
    bhs L_0209BB44
L_0209BADC:
    orrs ip, r3, r1
    bmi L_0209BB0C
    cmp r1, r3
    cmpeq r0, r2
    movne r0, #1
    moveq r0, #0
    bx lr
L_0209BAF8:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BB0C:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movne r0, #1
    moveq r0, #0
    bx lr
L_0209BB30:
    bne L_0209BAF8
    cmp r0, #0
    bhi L_0209BAF8
    cmn ip, r3, lsl #1
    blo L_0209BADC
L_0209BB44:
    bne L_0209BAF8
    cmp r2, #0
    bhi L_0209BAF8
    b L_0209BADC
}

asm void __fcmp_1(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BBF8
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movgt r0, #1
    movle r0, #0
    mrs ip, cpsr
    bicle ip, ip, #0x20000000
    orrgt ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209BBF8:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}

asm void __fcmp_2(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BC5C
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movle r0, #1
    movgt r0, #0
    mrs ip, cpsr
    orrgt ip, ip, #0x20000000
    bicgt ip, ip, #0x40000000
    bicle ip, ip, #0x20000000
    orrle ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BC5C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}

asm void __fcmp_3(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BCBC
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movlt r0, #1
    movge r0, #0
    mrs ip, cpsr
    orrge ip, ip, #0x20000000
    biclt ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209BCBC:
    mov r0, #0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}

asm void __fcmp_4(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    blo L_0209BD24
    cmp r3, r1, lsl #1
    blo L_0209BD24
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #0
    bne L_0209BD04
    mrs ip, cpsr
    orr ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BD04:
    cmp r0, r1
    movne r0, #1
    moveq r0, #0
    mrs ip, cpsr
    bicne ip, ip, #0x40000000
    orreq ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
L_0209BD24:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_flg, ip
    bx lr
}
