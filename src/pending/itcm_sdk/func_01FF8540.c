/*
 * function: func_01FF8540
 * address:  0x01FF8540
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

#define TRUE 1
#define FALSE 0

#define HW_BOOT_SYNC_PHASE        0x02FFFC28
#define HW_BOOT_SHAKEHAND_9       0x02FFFC24
#define HW_BOOT_SHAKEHAND_7       0x02FFFC26
#define HW_ROM_BASE_OFFSET_BUF    0x02FFFC2C
#define HW_ROM_HEADER_BUF         0x02FFFE00
#define HW_TWL_ROM_HEADER_BUF     0x02FFE000

#define HW_CACHE_LINE_SIZE        32
#define HW_DCACHE_SIZE            0x1000
#define HW_C7_CACHE_SET_NO_SHIFT  30

extern void func_01FF8700(u32 src, void *dst, int len);

asm void func_01FF8540(BOOL ontwl)
{
    stmfd   sp!, {r4, lr}
    mov     r4, r0

@shakeHand01:
    cmp     r4, #0
    beq     @shakeHand01_end
    ldr     r0, =HW_BOOT_SYNC_PHASE
    mov     r1, #1
    strh    r1, [r0]
    ldr     r0, =HW_BOOT_SHAKEHAND_9
    ldr     r1, =HW_BOOT_SHAKEHAND_7
    ldrh    r2, [r1]
    ldrh    r3, [r0]
@shakeHand01_loop:
    add     r3, r3, #1
    strh    r3, [r0]
    ldrh    r12, [r1]
    cmp     r2, r12
    beq     @shakeHand01_loop
    add     r3, r3, #1
    strh    r3, [r0]
@shakeHand01_end:

    cmp     r4, #0
    movne   r0, #0
    ldreq   r0, =HW_ROM_BASE_OFFSET_BUF
    ldreq   r0, [r0]
    stmfd   sp!, {r0}
    cmp     r0, #0x8000
    ldrcs   r1, =HW_ROM_HEADER_BUF
    movcs   r2, #0x160
    blcs    func_01FF8700

@loadStatic:
    ldr     r12, =HW_ROM_HEADER_BUF
    ldr     r0, [r12, #0x20]
    ldr     r1, [r12, #0x28]
    ldr     r2, [r12, #0x2c]
    ldr     r3, [sp]
    add     r0, r0, r3
    subs    r3, r0, #0x8000
    movlt   r0, #0x8000
    sublt   r1, r1, r3
    addlt   r2, r2, r3
    cmp     r2, #0
    blgt    func_01FF8700

    ldr     r12, =HW_ROM_HEADER_BUF
    ldr     r0, [r12, #0x30]
    ldr     r1, [r12, #0x38]
    ldr     r2, [r12, #0x3c]
    ldr     r3, [sp]
    add     r0, r0, r3
    cmp     r2, #0
    blgt    func_01FF8700
    ldmfd   sp!, {r0}

@loadLtdStatic:
    cmp     r4, #0
    beq     @loadLtdStatic_end
    ldr     r12, =HW_TWL_ROM_HEADER_BUF
    ldr     r0, [r12, #0x1c0]
    ldr     r1, [r12, #0x1c8]
    ldr     r2, [r12, #0x1cc]
    add     r0, r0, #0x4000
    add     r1, r1, #0x4000
    sub     r2, r2, #0x4000
    subs    r3, r0, #0x8000
    movlt   r0, #0x8000
    sublt   r1, r1, r3
    addlt   r2, r2, r3
    cmp     r2, #0
    blgt    func_01FF8700

    ldr     r12, =HW_TWL_ROM_HEADER_BUF
    ldr     r0, [r12, #0x1d0]
    ldr     r1, [r12, #0x1d8]
    ldr     r2, [r12, #0x1dc]
    add     r0, r0, #0x4000
    add     r1, r1, #0x4000
    sub     r2, r2, #0x4000
    subs    r3, r0, #0x8000
    movlt   r0, #0x8000
    sublt   r1, r1, r3
    addlt   r2, r2, r3
    cmp     r2, #0
    blgt    func_01FF8700
@loadLtdStatic_end:

@arrangeCache:
    mov     r1, #0
@arrangeCache_loop01:
    mov     r0, #0
@arrangeCache_loop02:
    orr     r2, r1, r0
    mcr     p15, 0, r2, c7, c10, 2
    add     r0, r0, #HW_CACHE_LINE_SIZE
    cmp     r0, #(HW_DCACHE_SIZE / 4)
    blt     @arrangeCache_loop02
    adds    r1, r1, #(1 << HW_C7_CACHE_SET_NO_SHIFT)
    bne     @arrangeCache_loop01

    mov     r0, #0
    mcr     p15, 0, r0, c7, c6, 0
    mcr     p15, 0, r0, c7, c5, 0
    mcr     p15, 0, r0, c7, c10, 4

    cmp     r4, #0
    beq     @shakeHand02_end
    mov     r3, #2
    ldr     r0, =HW_BOOT_SYNC_PHASE
    strh    r3, [r0]
    ldr     r0, =HW_BOOT_SHAKEHAND_9
    ldr     r1, =HW_BOOT_SHAKEHAND_7
    ldrh    r2, [r1]
    ldrh    r3, [r0]
@shakeHand02_loop:
    add     r3, r3, #1
    strh    r3, [r0]
    ldrh    r12, [r1]
    cmp     r2, r12
    beq     @shakeHand02_loop
    add     r3, r3, #1
    strh    r3, [r0]
@shakeHand02_end:

    ldmfd   sp!, {r4, pc}
}
