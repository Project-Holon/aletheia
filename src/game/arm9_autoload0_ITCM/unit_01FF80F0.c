/*
 * file:     unit_01FF80F0.c
 * unit:     yes
 * function: func_01FF80F0, func_01FF8148
 * address:  0x01FF80F0
 * region:   arm9_autoload0_ITCM
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02731754  0x02731754  thumb
 *   d_02FE0020     0x02FE0020  data
 *   OSi_IrqThreadQueue  0x02FE00A0  data
 *   OSi_ThreadInfo      0x02150FEC  data
 *   CP_SaveContext      0x020775B8  arm
 *   CPi_RestoreContext  0x020775F8  arm
 */
extern void CP_SaveContext(void *p1, void *p2);
extern void CPi_RestoreContext(void *p1, void *p2);
asm void func_01FF80F0(void);
asm void func_01FF8148(void);
extern void *d_02FE0020[32];
extern void *OSi_IrqThreadQueue;
extern void *OSi_ThreadInfo;


asm void func_01FF80F0(void)
{
    stmdb   sp!, {lr}
    mov     ip, #0x4000000
    add     ip, ip, #0x210
    ldr     r1, [ip, #-8]
    cmp     r1, #0
    ldmeqfd sp!, {pc}
    ldmia   ip, {r1, r2}
    ands    r1, r1, r2
    ldmeqfd sp!, {pc}
    mov     r3, #0x80000000
@loop:
    clz     r0, r1
    bics    r1, r1, r3, lsr r0
    bne     @loop
    mov     r1, r3, lsr r0
    str     r1, [ip, #4]
    rsbs    r0, r0, #0x1f
    ldr     r1, =d_02FE0020
    ldr     r0, [r1, r0, lsl #2]
    ldr     lr, =func_01FF8148
    bx      r0
}


/*
 * sdk:      OS_IrqHandler_ThreadSwitch, sdk/TwlSDK/lib/ARM9-TS/Rom/libos.TWL.HYB.a
 *           member os_irqhandler.o (352 bytes, .itcm).  The original is
 *           hand-written `asm` at the path the .o line table names,
 *           sdk/TwlSDK/build/libraries/os/common/src/os_irqHandler.c:140 (the
 *           sibling os_irqTable.c is shipped in this SDK tree, os_irqHandler.c
 *           is not), so this is too.  DWARF agrees on the shape: the DIE at
 *           0xbea carries no children at all -- no DW_TAG_formal_parameter and
 *           no DW_TAG_variable -- so the arity is void, and the 88 decodedline
 *           rows cover exactly the 88 code words 0x00..0x14C, lines 145..303,
 *           none of the four literal words.  The four pool relocations are
 *           R_ARM_ABS32 to OSi_IrqThreadQueue, OSi_ThreadInfo, CP_SaveContext
 *           and CPi_RestoreContext.  Tail-called by name from the EXACT
 *           sibling func_01FF80F0, whose pool literal is an R_ARM_ABS32 to
 *           0x01FF8148.
 *
 * Two assembler facts pin three spellings in the body.  mwccarm 1.1p1's inline
 * assembler has no conditional byte or halfword transfer at all (`ldrhne`,
 * `ldrbne`, `strhne` are all "unknown assembler instruction mnemonic", while
 * the word forms `ldrne`/`cmpne` assemble), so +0x7C is the one instruction
 * written as its encoding -- `dcd 0x11D106B4`, LDRHNE r0, [r1, #0x64], the
 * same device func_02731754 uses for a whole ARM veneer.  And `blx rN` is
 * 0xE12FFF3N while `bx rN` is 0xE12FFF1N, so +0xC0 -- the function-pointer
 * dispatch the SDK reaches with lr preset by `mov lr, pc` -- is `bx r3`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_01FF8148.c \
 *       --func func_01FF8148 --addr 0x01FF8148 --cc 1.1p1 --arm \
 *       --region arm9_autoload0_ITCM
 */
asm void func_01FF8148(void)
{
    ldr     ip, =OSi_IrqThreadQueue
    mov     r3, #0
    ldr     ip, [ip]
    mov     r2, #1
    cmp     ip, #0
    beq     @afterQueue
@queueLoop:
    str     r2, [ip, #0x64]
    str     r3, [ip, #0x78]
    str     r3, [ip, #0x7c]
    ldr     r0, [ip, #0x80]
    str     r3, [ip, #0x80]
    mov     ip, r0
    cmp     ip, #0
    bne     @queueLoop
    ldr     ip, =OSi_IrqThreadQueue
    str     r3, [ip]
    str     r3, [ip, #4]
    ldr     ip, =OSi_ThreadInfo
    mov     r1, #1
    strh    r1, [ip]
@afterQueue:
    ldr     ip, =OSi_ThreadInfo
    ldrh    r1, [ip]
    cmp     r1, #0
    ldreq   pc, [sp], #4
    mov     r1, #0
    strh    r1, [ip]
    mov     r3, #0xd2
    msr     cpsr_c, r3
    add     r2, ip, #8
    ldr     r1, [r2]
@findThread:
    cmp     r1, #0
    dcd     0x11D106B4
    cmpne   r0, #1
    ldrne   r1, [r1, #0x68]
    bne     @findThread
    cmp     r1, #0
    bne     @switch
@irqRet:
    mov     r3, #0x92
    msr     cpsr_c, r3
    ldr     pc, [sp], #4
@switch:
    ldr     r0, [ip, #4]
    cmp     r1, r0
    beq     @irqRet
    ldr     r3, [ip, #0xc]
    cmp     r3, #0
    beq     @setRunning
    stmfd   sp!, {r0, r1, ip}
    mov     lr, pc
    bx      r3
    ldmfd   sp!, {r0, r1, ip}
@setRunning:
    str     r1, [ip, #4]
    mrs     r2, spsr
    str     r2, [r0, #0]!
    stmfd   sp!, {r0, r1}
    add     r0, r0, #0
    add     r0, r0, #0x48
    ldr     r1, =CP_SaveContext
    blx     r1
    ldmfd   sp!, {r0, r1}
    ldmib   sp!, {r2, r3}
    stmib   r0!, {r2, r3}
    ldmib   sp!, {r2, r3, ip, lr}
    stmib   r0, {r2-r14}^
    add     r0, r0, #0x34
    stmib   r0!, {lr}
    mov     r3, #0xd3
    msr     cpsr_c, r3
    stmib   r0!, {sp}
    stmfd   sp!, {r1}
    add     r0, r1, #0
    add     r0, r0, #0x48
    ldr     r1, =CPi_RestoreContext
    blx     r1
    ldmfd   sp!, {r1}
    ldr     sp, [r1, #0x44]
    mov     r3, #0xd2
    msr     cpsr_c, r3
    ldr     r2, [r1, #0]!
    msr     spsr_fc, r2
    ldr     lr, [r1, #0x40]
    ldmib   r1, {r0-r14}^
    mov     r0, r0
    stmda   sp!, {r0, r1, r2, r3, ip, lr}
    ldmfd   sp!, {pc}
}
