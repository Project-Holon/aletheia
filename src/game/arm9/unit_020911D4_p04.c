/*
 * unit:     yes
 * function: _fgeq
 * address:  0x0209BB54
 * packet:   pkt_0209BB54_fgeq
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Filed as manifest kind `runtime` (tools/match.py): compared at its
 * layout/runtime_arm9.txt row, and worklist.py keeps the row out of the
 * game figure.
 *
 * 0x0209BB54..0x0209BBB0 (92 bytes), between __dcmp_6's end and __fcmp_1's
 * start, is a fifth float comparator: it returns its result through
 * `mrs ip, apsr` / bic-or-orr of bit 29 (C) / `msr apsr_nzcvq, ip`, the
 * same APSR-return calling convention as the __dcmp_1..6/__fcmp_1..4 rows
 * in src/matched/compares.c, which no C construct can produce. The
 * movge/movlt pair (bit 29 only, no bit 30 family) makes it the
 * greater-or-equal member, `_fgeq`. Verified with:
 *   python tools/match.py one --src <this file> --func _fgeq
 *     --addr 0x0209BB54 --cc 1.1p1 --arm
 */

asm void _fgeq(void)
{
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_0209BB9C
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movge r0, #1
    movlt r0, #0
    mrs ip, cpsr
    biclt ip, ip, #0x20000000
    orrge ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
L_0209BB9C:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_flg, ip
    bx lr
}
