/*
 * unit:     yes
 * function: _ll_divmod_entry_signed, _ll_divmod_body, _ll_divmod_entry_flag0,
 *           _ll_divmod_entry_flag1
 * address:  0x0209BE4C
 * packet:   pkt_0209BE4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f          0x0209C0A4  arm
 *   _u32_div_not_0_f    0x0209C2B8  arm
 *
 * mwccarm/MSL runtime.a hand-written assembly, layout/runtime_arm9.txt rows
 * 0x0209BE4C, 0x0209BE5C, 0x0209C00C, 0x0209C018 (64-bit divide/modulo).
 * The four entries are filed as one asm function because two of them branch
 * into the interior of another (0x0209BE4C -> 0x0209BE6C, twelve bytes into
 * _ll_divmod_body; 0x0209C00C/0x0209C018 -> 0x0209C020, inside each other),
 * which mwccarm's one-section-per-function model cannot produce as separate
 * C functions; see docs/notes/pkt_0209BDBC_runtime_library.c.txt.  The other
 * three entry addresses are kept as plain labels inside this one function
 * and documented here for readers and for any future caller that needs to
 * branch to one of them directly by address.
 */

extern void _s32_div_f(void);
extern void _u32_div_not_0_f(void);

asm void _ll_divmod_entry_signed(void)
{
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, r1
    orr r4, r4, #1
    b L_0209BE6C

_ll_divmod_body:
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    eor r4, r1, r3
    mov r4, r4, asr #1
    mov r4, r4, lsl #1
L_0209BE6C:
    orrs r5, r3, r2
    bne L_0209BE7C
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BE7C:
    mov r5, r0, lsr #0x1f
    add r5, r5, r1
    mov r6, r2, lsr #0x1f
    add r6, r6, r3
    orrs r6, r5, r6
    bne L_0209BEB0
    mov r1, r2
    bl _s32_div_f
    ands r4, r4, #1
    movne r0, r1
    mov r1, r0, asr #0x1f
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BEB0:
    cmp r1, #0
    bge L_0209BEC0
    rsbs r0, r0, #0
    rsc r1, r1, #0
L_0209BEC0:
    cmp r3, #0
    bge L_0209BED0
    rsbs r2, r2, #0
    rsc r3, r3, #0
L_0209BED0:
    orrs r5, r1, r0
    beq L_0209BFF4
    mov r5, #0
    mov r6, #1
    cmp r3, #0
    bmi L_0209BEFC
L_0209BEE8:
    add r5, r5, #1
    adds r2, r2, r2
    adcs r3, r3, r3
    bpl L_0209BEE8
    add r6, r6, r5
L_0209BEFC:
    cmp r1, #0
    blt L_0209BF1C
L_0209BF04:
    cmp r6, #1
    beq L_0209BF1C
    sub r6, r6, #1
    adds r0, r0, r0
    adcs r1, r1, r1
    bpl L_0209BF04
L_0209BF1C:
    mov r7, #0
    mov ip, #0
    mov r11, #0
    b L_0209BF44
L_0209BF2C:
    orr ip, ip, #1
    subs r6, r6, #1
    beq L_0209BF9C
    adds r0, r0, r0
    adcs r1, r1, r1
    adcs r7, r7, r7
L_0209BF44:
    subs r0, r0, r2
    sbcs r1, r1, r3
    sbcs r7, r7, #0
    adds ip, ip, ip
    adc r11, r11, r11
    cmp r7, #0
    bge L_0209BF2C
L_0209BF60:
    subs r6, r6, #1
    beq L_0209BF94
    adds r0, r0, r0
    adcs r1, r1, r1
    adc r7, r7, r7
    adds r0, r0, r2
    adcs r1, r1, r3
    adc r7, r7, #0
    adds ip, ip, ip
    adc r11, r11, r11
    cmp r7, #0
    bge L_0209BF2C
    b L_0209BF60
L_0209BF94:
    adds r0, r0, r2
    adc r1, r1, r3
L_0209BF9C:
    ands r7, r4, #1
    moveq r0, ip
    moveq r1, r11
    beq L_0209BFD4
    subs r7, r5, #0x20
    movge r0, r1, lsr r7
    bge L_0209BFF8
    rsb r7, r5, #0x20
    mov r0, r0, lsr r5
    orr r0, r0, r1, lsl r7
    mov r1, r1, lsr r5
    b L_0209BFD4
    mov r0, r1, lsr r7
    mov r1, #0
L_0209BFD4:
    cmp r4, #0
    blt L_0209BFE4
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BFE4:
    rsbs r0, r0, #0
    rsc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209BFF4:
    mov r0, #0
L_0209BFF8:
    mov r1, #0
    cmp r4, #0
    blt L_0209BFE4
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr

_ll_divmod_entry_flag0:
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, #0
    b L_0209C020
_ll_divmod_entry_flag1:
    stmdb sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, #1
L_0209C020:
    orrs r5, r3, r2
    bne L_0209C030
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
L_0209C030:
    orrs r5, r1, r3
    bne L_0209BED0
    mov r1, r2
    bl _u32_div_not_0_f
    cmp r4, #0
    movne r0, r1
    mov r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
}
