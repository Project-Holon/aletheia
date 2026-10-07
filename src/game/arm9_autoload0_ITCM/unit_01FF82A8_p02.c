/*
 * file:     unit_01FF82A8_p02.c
 * unit:     yes
 * function: func_01FF8460, func_01FF852C, func_01FF8540, func_01FF8700
 * address:  0x01FF8460
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
 *   MIi_CpuClear32     0x01FF852C  arm
 *   OSi_DoBoot         0x01FF8460  arm
 *   OSi_ReloadRomData  0x01FF8540  arm
 */
#define HW_REG_BASE                  0x04000000
#define REG_IME_OFFSET               0x208
#define OSi_HW_DTCM                  0x02FE0000
#define HW_DTCM_SYSRV_OFS_INTR_VECTOR 0x3c
#define REG_SUBPINTF_ADDR             0x04000180
#define HW_EXCP_VECTOR_MAIN           0x02FFFD9C
#define HW_BIOS_EXCP_STACK_MAIN       0x02FFFD80
#define HW_PXI_SIGNAL_PARAM_ARM9      0x02FFFF80
#define HW_WM_RSSI_POOL               0x02FFFF98
#define HW_COMPONENT_PARAM            0x02FFFF9C
#define HW_ROM_HEADER_BUF             0x02FFFE00
#define TRUE 1
#define FALSE 0
#define HW_BOOT_SYNC_PHASE        0x02FFFC28
#define HW_BOOT_SHAKEHAND_9       0x02FFFC24
#define HW_BOOT_SHAKEHAND_7       0x02FFFC26
#define HW_ROM_BASE_OFFSET_BUF    0x02FFFC2C
#define HW_TWL_ROM_HEADER_BUF     0x02FFE000
#define HW_CACHE_LINE_SIZE        32
#define HW_DCACHE_SIZE            0x1000
#define HW_C7_CACHE_SET_NO_SHIFT  30
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef int BOOL;

typedef volatile u8 vu8;

typedef volatile u32 vu32;

asm void func_01FF8460(void);
asm void func_01FF852C(u32 data, void *destp, u32 size);
asm void func_01FF8540(BOOL ontwl);
void func_01FF8700(u32 src, void *dst, int len);


asm void func_01FF8460(void)
{
    mov     r12, #HW_REG_BASE
    str     r12, [r12, #REG_IME_OFFSET]

    ldr     r1, =OSi_HW_DTCM
    add     r1, r1, #0x3fc0
    add     r1, r1, #HW_DTCM_SYSRV_OFS_INTR_VECTOR
    mov     r0, #0
    str     r0, [r1]

    ldr     r1, =REG_SUBPINTF_ADDR
@1:
    ldrh    r0, [r1]
    and     r0, r0, #0x000f
    cmp     r0, #0x0001
    bne     @1
    mov     r0, #0x0100
    strh    r0, [r1]

    mov     r0, #0
    ldr     r3, =HW_EXCP_VECTOR_MAIN
    ldr     r4, [r3]

    ldr     r1, =HW_BIOS_EXCP_STACK_MAIN
    mov     r2, #0x80
    bl      func_01FF852C

    str     r4, [r3]

    ldr     r1, =HW_PXI_SIGNAL_PARAM_ARM9
    mov     r2, #0x18
    bl      func_01FF852C

    ldr     r1, =HW_WM_RSSI_POOL
    strh    r0, [r1]

    ldr     r1, =HW_COMPONENT_PARAM
    mov     r2, #0x64
    bl      func_01FF852C

    ldr     r1, =REG_SUBPINTF_ADDR
@2:
    ldrh    r0, [r1]
    and     r0, r0, #0x000f
    cmp     r0, #0x0001
    beq     @2
    mov     r0, #0
    strh    r0, [r1]

    ldr     r3, =HW_ROM_HEADER_BUF
    ldr     r12, [r3, #0x24]
    mov     lr, r12

    ldr     r11, =HW_PXI_SIGNAL_PARAM_ARM9
    ldmia   r11, {r0-r10}
    mov     r11, #0

    bx      r12
}


asm void func_01FF852C(u32 data, void *destp, u32 size)
{
    add ip, r1, r2
_loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt _loop
    bx lr
}


/*
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
 */
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


void func_01FF8700(u32 src, void *dst, int len)
{
    vu8  *const reg_CARD_MASTERCNT = (vu8 *)(0x04000000 + 0x1a1);
    vu8  *const reg_CARD_CMD = (vu8 *)(0x04000000 + 0x1a8);
    vu32 *const reg_CARD_CNT = (vu32 *)(0x04000000 + 0x1a4);
    vu32 *const reg_CARD_DATA = (vu32 *)(0x04000000 + 0x100010);
    vu32 *const hdr_GAME_BUF = (vu32 *)(0x02FFFE00 + 0x60);

    const u32 ctrl_start = (u32)((*hdr_GAME_BUF & ~0x07000000)
                                 | (0x01000000 | 0x00000000
                                    | 0x80000000 | 0x20000000));

    int pos = -(int)(src & (512 - 1));

    while ((*reg_CARD_CNT & 0x80000000) != 0)
    {
    }
    *reg_CARD_MASTERCNT = (u32)(0x00 | 0x80);

    for (src = (u32)(src + pos); pos < len; src += 512)
    {
        reg_CARD_CMD[0] = (u8)(0xb7);
        reg_CARD_CMD[1] = (u8)(src >> 24);
        reg_CARD_CMD[2] = (u8)(src >> 16);
        reg_CARD_CMD[3] = (u8)(src >> 8);
        reg_CARD_CMD[4] = (u8)(src >> 0);
        reg_CARD_CMD[5] = (u8)(0);
        reg_CARD_CMD[6] = (u8)(0);
        reg_CARD_CMD[7] = (u8)(0);

        *reg_CARD_CNT = ctrl_start;
        for (;;)
        {
            u32 ctrl = *reg_CARD_CNT;

            if ((ctrl & 0x00800000) != 0)
            {
                const u32 data = *reg_CARD_DATA;

                if ((pos >= 0) && (pos < len))
                {
                    *(u32 *)((u32)dst + pos) = data;
                }

                pos += sizeof(u32);
            }

            if (!(ctrl & 0x80000000))
            {
                break;
            }
        }
    }
}
