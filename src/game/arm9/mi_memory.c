/*
 * file:     mi_memory.c
 * unit:     yes
 * function: MIi_CpuClear16, MIi_CpuCopy16, MIi_CpuClear32, MIi_CpuCopy32, MIi_CpuSend32, MIi_CpuClearFast, MIi_CpuCopyFast, MI_Copy32B, MI_Copy36B, MI_Copy48B, MI_Copy64B, MI_CpuFill8, MI_CpuFill, MI_CpuCopy8, MI_CpuComp8, MI_CpuCopy, MI_CpuMove, MI_Zero36B
 * address:  0x02082A48
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * TwlSDK libmi mi_memory.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor object.  void MI_CpuMove(const void *srcp,
 * void *destp, u32 size): an overlapping-safe copy.  A forward move is
 * handed to MI_CpuCopy; a backward one copies from the end, by a computed
 * jump into a byte ladder for up to 8 bytes, otherwise by 32-byte ldm/stm
 * blocks with the source realigned to the destination's byte offset.
 */
typedef unsigned long u32;

typedef unsigned char u8;

asm void MIi_CpuClear16(void);
asm void MIi_CpuCopy16(void);
asm void MIi_CpuClear32(void);
asm void MIi_CpuCopy32(void);
asm void MIi_CpuSend32(void);
asm void MIi_CpuClearFast(void);
asm void MIi_CpuCopyFast(void);
asm void MI_Copy32B(void);
asm void MI_Copy36B(void);
asm void MI_Copy48B(void);
asm void MI_Copy64B(void *pSrc, void *pDest);
asm void MI_CpuFill8(void);
asm void MI_CpuFill(void);
asm void MI_CpuCopy8(void);
int MI_CpuComp8(const void *mem1, const void *mem2, u32 size);
asm void MI_CpuCopy(void);
asm void MI_CpuMove(void);
asm void MI_Zero36B(void *dst);



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MIi_CpuClear16(void)
{
    mov r3, #0
loc_02082A4C:
    cmp r3, r2
    strlth r0, [r1, r3]
    addlt r3, r3, #2
    blt loc_02082A4C
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MIi_CpuCopy16(void)
{
    mov ip, #0
loc_02082A64:
    cmp ip, r2
    ldrlth r3, [r0, ip]
    strlth r3, [r1, ip]
    addlt ip, ip, #2
    blt loc_02082A64
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MIi_CpuClear32(void)
{
    add ip, r1, r2
loc_02082A80:
    cmp r1, ip
    stmltia r1!, {r0}
    blt loc_02082A80
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MIi_CpuCopy32(void)
{
    add ip, r1, r2
loc_02082A94:
    cmp r1, ip
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt loc_02082A94
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MIi_CpuSend32(void)
{
    add ip, r0, r2
loc_02082AAC:
    cmp r0, ip
    ldmltia r0!, {r2}
    strlt r2, [r1]
    blt loc_02082AAC
    bx lr
}



/*
 * sdk:      MIi_CpuClearFast (libmi.TWL.HYB.a mi_memory.o)
 * asm:      eight-register fixed stm block fill (stmlt r1!, {r0, r2-r8}); DWARF subprogram has no variables.
 *
 * void MIi_CpuClearFast(u32 data, void *destp, u32 size).
 * hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction
 */
asm void MIi_CpuClearFast(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9}
    add r9, r1, r2
    mov r12, r2, lsr #5
    add r12, r1, r12, lsl #5
    mov r2, r0
    mov r3, r2
    mov r4, r2
    mov r5, r2
    mov r6, r2
    mov r7, r2
    mov r8, r2
@loop32:
    cmp r1, r12
    stmltia r1!, {r0, r2, r3, r4, r5, r6, r7, r8}
    blt @loop32
@loop4:
    cmp r1, r9
    stmltia r1!, {r0}
    blt @loop4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}



/*
 * sdk:      MIi_CpuCopyFast (libmi.TWL.HYB.a mi_memory.o)
 * asm:      eight-register fixed ldm/stm block copy (ldmlt r0!, {r2-r9}); DWARF subprogram has no variables.
 *
 * void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size).
 * hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction
 */
asm void MIi_CpuCopyFast(void)
{
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    add r10, r1, r2
    mov r12, r2, lsr #5
    add r12, r1, r12, lsl #5
@loop32:
    cmp r1, r12
    ldmltia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt @loop32
@loop4:
    cmp r1, r10
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt @loop4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx lr
}



/*
 * sdk:      MI_Copy32B (libmi.TWL.HYB.a mi_memory.o)
 * asm:      fixed-register ldm/stm block copy (ldm r0!,{r2,r3,r12}) has no C spelling.
 *
 * void MI_Copy32B(void *pSrc, void *pDest).
 * hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction
 */
asm void MI_Copy32B(void)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3}
    stmia r1!, {r2, r3}
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_Copy36B(void)
{
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_Copy48B(void)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    bx lr
}



/*
 * sdk:      MI_Copy64B (libmi.TWL.HYB.a mi_memory.o)
 * asm:      fixed-register ldm/stm block copy (r2, r3, r12, then r0 reused as a fourth data register); the DWARF subprogram has no DW_TAG_variable children.
 * hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction
 */
asm void MI_Copy64B(void *pSrc, void *pDest)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0, {r0, r2, r3, r12}
    stmia r1!, {r0, r2, r3, r12}
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_CpuFill8(void)
{
    cmp r2, #0
    bxeq lr
    tst r0, #1
    beq @_aligned
    ldrh ip, [r0, #-1]
    and ip, ip, #0xff
    orr r3, ip, r1, lsl #8
    strh r3, [r0, #-1]
    add r0, r0, #1
    subs r2, r2, #1
    bxeq lr
@_aligned:
    cmp r2, #2
    blo @_tail
    orr r1, r1, r1, lsl #8
    tst r0, #2
    beq @_word
    strh r1, [r0], #2
    subs r2, r2, #2
    bxeq lr
@_word:
    orr r1, r1, r1, lsl #16
    bics r3, r2, #3
    beq @_half
    sub r2, r2, r3
    add ip, r3, r0
@_loop:
    str r1, [r0], #4
    cmp r0, ip
    blo @_loop
@_half:
    tst r2, #2
    strneh r1, [r0], #2
@_tail:
    tst r2, #1
    bxeq lr
    ldrh r3, [r0]
    and r3, r3, #0xff00
    and r1, r1, #0xff
    orr r1, r1, r3
    strh r1, [r0]
    bx lr
}



/*
 * sdk:      MI_CpuFill (libmi.TWL.HYB.a mi_memory.o)
 * asm:      computed jump into a strb run (add pc, pc, r3, lsl #2) and a mid-body push around an eight-register stm; DWARF subprogram has no variables.
 *
 * void MI_CpuFill(void *dstp, u8 data, u32 size).
 * hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction
 */
asm void MI_CpuFill(void)
{
    cmp r2, #0
    bxeq lr
    cmp r2, #8
    bgt @_large
    rsb r3, r2, #8
    add pc, pc, r3, lsl #2
    mov r0, r0
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    strb r1, [r0], #1
    bx lr
@_large:
    orr r1, r1, r1, lsl #8
    orr r1, r1, r1, lsl #16
    tst r0, #1
    subne r2, r2, #1
    strneb r1, [r0], #1
    tst r0, #2
    subne r2, r2, #2
    strneh r1, [r0], #2
    tst r0, #4
    subne r2, r2, #4
    strne r1, [r0], #4
    cmp r2, #32
    blt @_words
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    subs r2, r2, #32
@_loop32:
    stmgeia r0!, {r1, r4, r5, r6, r7, r8, r9, r10}
    subges r2, r2, #32
    bge @_loop32
    add r2, r2, #32
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
@_words:
    cmp r2, #4
    blt @_bytes
    subs r2, r2, #4
@_loop4:
    strge r1, [r0], #4
    subs r2, r2, #4
    bge @_loop4
    add r2, r2, #4
@_bytes:
    subs r2, r2, #1
    strgeb r1, [r0], #1
    subges r2, r2, #1
    strgeb r1, [r0], #1
    subges r2, r2, #1
    strgeb r1, [r0], #1
    bx lr
}



/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_CpuCopy8(void)
{
    cmp r2, #0
    bxeq lr
    tst r1, #1
    beq @_dst_aligned
    ldrh ip, [r1, #-1]
    and ip, ip, #0xff
    tst r0, #1
    ldrneh r3, [r0, #-1]
    movne r3, r3, lsr #8
    ldreqh r3, [r0]
    orr r3, ip, r3, lsl #8
    strh r3, [r1, #-1]
    add r0, r0, #1
    add r1, r1, #1
    subs r2, r2, #1
    bxeq lr
@_dst_aligned:
    eor ip, r1, r0
    tst ip, #1
    beq @_same_parity
    bic r0, r0, #1
    ldrh ip, [r0], #2
    mov r3, ip, lsr #8
    subs r2, r2, #2
    blo @_odd_tail
@_odd_loop:
    ldrh ip, [r0], #2
    orr ip, r3, ip, lsl #8
    strh ip, [r1], #2
    mov r3, ip, lsr #16
    subs r2, r2, #2
    bhs @_odd_loop
@_odd_tail:
    tst r2, #1
    bxeq lr
    ldrh ip, [r1]
    and ip, ip, #0xff00
    orr ip, ip, r3
    strh ip, [r1]
    bx lr
@_same_parity:
    tst ip, #2
    beq @_word
    bics r3, r2, #1
    beq @_last
    sub r2, r2, r3
    add ip, r3, r1
@_half_loop:
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    cmp r1, ip
    blo @_half_loop
    b @_last
@_word:
    cmp r2, #2
    blo @_last
    tst r1, #2
    beq @_word2
    ldrh r3, [r0], #2
    strh r3, [r1], #2
    subs r2, r2, #2
    bxeq lr
@_word2:
    bics r3, r2, #3
    beq @_half
    sub r2, r2, r3
    add ip, r3, r1
@_word_loop:
    ldr r3, [r0], #4
    str r3, [r1], #4
    cmp r1, ip
    blo @_word_loop
@_half:
    tst r2, #2
    ldrneh r3, [r0], #2
    strneh r3, [r1], #2
@_last:
    tst r2, #1
    bxeq lr
    ldrh r2, [r1]
    ldrh r0, [r0]
    and r2, r2, #0xff00
    and r0, r0, #0xff
    orr r0, r2, r0
    strh r0, [r1]
    bx lr
}




/*
 * sdk:      MI_CpuComp8 (libmi.TWL.HYB.a mi_memory.o)
 */
int MI_CpuComp8(const void *mem1, const void *mem2, u32 size)
{
    const u8 *p1 = (const u8 *)mem1;
    const u8 *p2 = (const u8 *)mem2;
    const u8 *p1end = p1 + size;

    while (p1 < p1end) {
        int d = (int)*p1++ - (int)*p2++;
        if (d != 0) {
            return d;
        }
    }
    return 0;
}


/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_CpuCopy(void)
{
    cmp r2, #8
    bgt @_2082EFC
    rsb r3, r2, #8
    add pc, pc, r3, lsl #3
    mov r0, r0
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    ldrb r3, [r0], #1
    strb r3, [r1], #1
    bx lr
@_2082EFC:
    tst r0, #1
    subne r2, r2, #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r0, #2
    subne r2, r2, #2
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    and r3, r1, #3
    bic r1, r1, #3
    cmp r3, #0
    beq @_2082F48
    cmp r3, #1
    beq @_2082F84
    cmp r3, #2
    beq @_208301C
    b @_20830B4
@_2082F48:
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2082F50:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2082F50
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2082F6C:
    ldrge r3, [r0], #4
    strge r3, [r1], #4
    subges r2, r2, #4
    bge @_2082F6C
    add r2, r2, #4
    b @_208314C
@_2082F84:
    ldr ip, [r1]
    mov ip, ip, lsl #0x18
    mov ip, ip, lsr #0x18
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2082F98:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #0x18
    orrge r4, ip, r4, lsl #8
    movge ip, r5, lsr #0x18
    orrge r5, r3, r5, lsl #8
    movge r3, r6, lsr #0x18
    orrge r6, ip, r6, lsl #8
    movge ip, r7, lsr #0x18
    orrge r7, r3, r7, lsl #8
    movge r3, r8, lsr #0x18
    orrge r8, ip, r8, lsl #8
    movge ip, r9, lsr #0x18
    orrge r9, r3, r9, lsl #8
    movge r3, r10, lsr #0x18
    orrge r10, ip, r10, lsl #8
    movge ip, lr, lsr #0x18
    orrge lr, r3, lr, lsl #8
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2082F98
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2082FF4:
    ldrge r3, [r0], #4
    orrge ip, ip, r3, lsl #8
    strge ip, [r1], #4
    movge ip, r3, lsr #0x18
    subges r2, r2, #4
    bge @_2082FF4
    add r2, r2, #4
    sub r0, r0, #1
    add r2, r2, #1
    b @_208314C
@_208301C:
    ldr ip, [r1]
    mov ip, ip, lsl #0x10
    mov ip, ip, lsr #0x10
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2083030:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #0x10
    orrge r4, ip, r4, lsl #16
    movge ip, r5, lsr #0x10
    orrge r5, r3, r5, lsl #16
    movge r3, r6, lsr #0x10
    orrge r6, ip, r6, lsl #16
    movge ip, r7, lsr #0x10
    orrge r7, r3, r7, lsl #16
    movge r3, r8, lsr #0x10
    orrge r8, ip, r8, lsl #16
    movge ip, r9, lsr #0x10
    orrge r9, r3, r9, lsl #16
    movge r3, r10, lsr #0x10
    orrge r10, ip, r10, lsl #16
    movge ip, lr, lsr #0x10
    orrge lr, r3, lr, lsl #16
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2083030
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_208308C:
    ldrge r3, [r0], #4
    orrge ip, ip, r3, lsl #16
    strge ip, [r1], #4
    movge ip, r3, lsr #0x10
    subges r2, r2, #4
    bge @_208308C
    add r2, r2, #4
    sub r0, r0, #2
    add r2, r2, #2
    b @_208314C
@_20830B4:
    ldr ip, [r1]
    mov ip, ip, lsl #8
    mov ip, ip, lsr #8
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_20830C8:
    ldmgeia r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, r4, lsr #8
    orrge r4, ip, r4, lsl #24
    movge ip, r5, lsr #8
    orrge r5, r3, r5, lsl #24
    movge r3, r6, lsr #8
    orrge r6, ip, r6, lsl #24
    movge ip, r7, lsr #8
    orrge r7, r3, r7, lsl #24
    movge r3, r8, lsr #8
    orrge r8, ip, r8, lsl #24
    movge ip, r9, lsr #8
    orrge r9, r3, r9, lsl #24
    movge r3, r10, lsr #8
    orrge r10, ip, r10, lsl #24
    movge ip, lr, lsr #8
    orrge lr, r3, lr, lsl #24
    stmgeia r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_20830C8
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083124:
    ldrge r3, [r0], #4
    orrge ip, ip, r3, lsl #24
    strge ip, [r1], #4
    movge ip, r3, lsr #8
    subges r2, r2, #4
    bge @_2083124
    add r2, r2, #4
    sub r0, r0, #3
    add r2, r2, #3
    b @_208314C
@_208314C:
    tst r2, #4
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r2, #2
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    tst r2, #1
    ldrneb r3, [r0], #1
    strneb r3, [r1], #1
    bx lr
}


/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_CpuMove(void)
{
    cmp r2, #0
    subnes r3, r0, r1
    bxeq lr
    bgt MI_CpuCopy
    add r1, r1, r2
    add r0, r0, r2
    cmp r2, #8
    bgt @_2083204
    rsb r3, r2, #8
    add pc, pc, r3, lsl #3
    mov r0, r0
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    ldrb r3, [r0, #-1]!
    strb r3, [r1, #-1]!
    bx lr
@_2083204:
    tst r0, #2
    subne r2, r2, #2
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    tst r0, #1
    subne r2, r2, #1
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    and r3, r1, #3
    bic r1, r1, #3
    cmp r3, #0
    beq @_2083250
    cmp r3, #1
    beq @_208328C
    cmp r3, #2
    beq @_2083328
    b @_20833C4
@_2083250:
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_2083258:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    stmgedb r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_2083258
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083274:
    ldrge r3, [r0, #-4]!
    strge r3, [r1, #-4]!
    subges r2, r2, #4
    bge @_2083274
    add r2, r2, #4
    b @_2083460
@_208328C:
    ldr ip, [r1]
    mov ip, ip, lsr #8
    mov ip, ip, lsl #8
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_20832A0:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, lr, lsl #8
    orrge lr, ip, lr, lsr #24
    movge ip, r10, lsl #8
    orrge r10, r3, r10, lsr #24
    movge r3, r9, lsl #8
    orrge r9, ip, r9, lsr #24
    movge ip, r8, lsl #8
    orrge r8, r3, r8, lsr #24
    movge r3, r7, lsl #8
    orrge r7, ip, r7, lsr #24
    movge ip, r6, lsl #8
    orrge r6, r3, r6, lsr #24
    movge r3, r5, lsl #8
    orrge r5, ip, r5, lsr #24
    movge ip, r4, lsl #8
    orrge r4, r3, r4, lsr #24
    stmgeda r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_20832A0
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_20832FC:
    ldrge r3, [r0, #-4]!
    orrge ip, ip, r3, lsr #24
    strge ip, [r1], #-4
    movge ip, r3, lsl #8
    subges r2, r2, #4
    bge @_20832FC
    add r2, r2, #4
    add r1, r1, #4
    add r0, r0, #3
    add r2, r2, #3
    b @_2083460
@_2083328:
    ldr ip, [r1]
    mov ip, ip, lsr #0x10
    mov ip, ip, lsl #0x10
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_208333C:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, lr, lsl #0x10
    orrge lr, ip, lr, lsr #16
    movge ip, r10, lsl #0x10
    orrge r10, r3, r10, lsr #16
    movge r3, r9, lsl #0x10
    orrge r9, ip, r9, lsr #16
    movge ip, r8, lsl #0x10
    orrge r8, r3, r8, lsr #16
    movge r3, r7, lsl #0x10
    orrge r7, ip, r7, lsr #16
    movge ip, r6, lsl #0x10
    orrge r6, r3, r6, lsr #16
    movge r3, r5, lsl #0x10
    orrge r5, ip, r5, lsr #16
    movge ip, r4, lsl #0x10
    orrge r4, r3, r4, lsr #16
    stmgeda r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_208333C
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083398:
    ldrge r3, [r0, #-4]!
    orrge ip, ip, r3, lsr #16
    strge ip, [r1], #-4
    movge ip, r3, lsl #0x10
    subges r2, r2, #4
    bge @_2083398
    add r2, r2, #4
    add r1, r1, #4
    add r0, r0, #2
    add r2, r2, #2
    b @_2083460
@_20833C4:
    ldr ip, [r1]
    mov ip, ip, lsr #0x18
    mov ip, ip, lsl #0x18
    stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #0x20
@_20833D8:
    ldmgedb r0!, {r4, r5, r6, r7, r8, r9, r10, lr}
    movge r3, lr, lsl #0x18
    orrge lr, ip, lr, lsr #8
    movge ip, r10, lsl #0x18
    orrge r10, r3, r10, lsr #8
    movge r3, r9, lsl #0x18
    orrge r9, ip, r9, lsr #8
    movge ip, r8, lsl #0x18
    orrge r8, r3, r8, lsr #8
    movge r3, r7, lsl #0x18
    orrge r7, ip, r7, lsr #8
    movge ip, r6, lsl #0x18
    orrge r6, r3, r6, lsr #8
    movge r3, r5, lsl #0x18
    orrge r5, ip, r5, lsr #8
    movge ip, r4, lsl #0x18
    orrge r4, r3, r4, lsr #8
    stmgeda r1!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subges r2, r2, #0x20
    bge @_20833D8
    add r2, r2, #0x20
    ldmia sp!, {r4, r5, r6, r7, r8, r9, r10, lr}
    subs r2, r2, #4
@_2083434:
    ldrge r3, [r0, #-4]!
    orrge ip, ip, r3, lsr #8
    strge ip, [r1], #-4
    movge ip, r3, lsl #0x18
    subges r2, r2, #4
    bge @_2083434
    add r2, r2, #4
    add r1, r1, #4
    add r0, r0, #1
    add r2, r2, #1
    b @_2083460
@_2083460:
    tst r2, #4
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    tst r2, #2
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    tst r2, #1
    ldrneb r3, [r0, #-1]!
    strneb r3, [r1, #-1]!
    bx lr
}

#pragma thumb on

/* hand-written in the original: hand-scheduled memory routine with ldm/stm, one SDK line-table row per instruction */
asm void MI_Zero36B(void *dst)
{
    mov r1, #0
    mov r2, #0
    mov r3, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r2, r3}
    bx lr
}

#pragma thumb reset
