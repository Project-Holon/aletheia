/*
 * function: OSi_ReloadRomData
 * address:  0x01FF8540
 * packet:   pkt_01FF8540
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      OSi_ReloadRomData, sdk/TwlSDK/lib/ARM9-TS/Rom/libos.TWL.HYB.a
 *           member os_reset.o (448 bytes, .itcm), declared
 *           `static asm void OSi_ReloadRomData(BOOL ontwl)` at
 *           sdk/TwlSDK/build/libraries/os/common/src/os_reset.c:678 -- the
 *           original is inline assembly, so this is too.  DWARF agrees: no
 *           locals at all, the sole formal `ontwl` is BOOL=int at fbreg+8,
 *           and the 106 decoded line rows cover exactly the 106 code words
 *           0x00..0x1A4 of os_reset.c:680..824, none of the six literal
 *           words.  The .o matches the game in 443 of 448 bytes; the five
 *           differences are the low byte of the five `bl` PC24 fields.
 * symbols:
 *   OSi_ReadCardRom32    0x01FF8700  arm
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

extern void OSi_ReadCardRom32(u32 src, void *dst, int len);

asm void OSi_ReloadRomData(BOOL ontwl)
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
    blcs    OSi_ReadCardRom32

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
    blgt    OSi_ReadCardRom32

    ldr     r12, =HW_ROM_HEADER_BUF
    ldr     r0, [r12, #0x30]
    ldr     r1, [r12, #0x38]
    ldr     r2, [r12, #0x3c]
    ldr     r3, [sp]
    add     r0, r0, r3
    cmp     r2, #0
    blgt    OSi_ReadCardRom32
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
    blgt    OSi_ReadCardRom32

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
    blgt    OSi_ReadCardRom32
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
