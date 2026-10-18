/*
 * file:     os_reset.c
 * unit:     yes
 * function: OSi_VerifyStaticSegmentHash, OSi_VerifyStaticSegments, OSi_DoResetSystem, OSi_DoBoot, OSi_CpuClear32, OSi_ReloadRomData, OSi_ReadCardRom32
 * address:  0x01FF82A8
 * packet:   pkt_01FF82A8
 * region:   arm9_autoload0_ITCM
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OSi_VerifyStaticSegmentHash    0x01FF82A8  thumb
 *   OS_IsResetOccurred        0x02084A28  arm
 *   OS_IsRunOnTwl             0x02085D3C  arm
 *   OSi_ReloadRomData         0x01FF8540  arm
 *   OSi_VerifyStaticSegments  0x01FF836C  arm
 *   OSi_DoBoot                0x01FF8460  arm
 *   OSi_CpuClear32     0x01FF852C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;
typedef volatile u8 vu8;
typedef volatile u32 vu32;

/* hand-written in the original: Thumb hash loop with hand register use, one SDK line-table row per instruction */
asm BOOL OSi_VerifyStaticSegmentHash(const u8 *src, u32 len, const void *digest)
{
    PUSH    {R3, R4, R5, R6, R7, LR}
    SUB     SP, #0xB8
    MOV     R4, R1
    MOV     R5, R0
    MOV     R7, R2
    ADD     R0, SP, #0x54
    MOV     R3, #0x60
    ADD     R3, R0
    MOV     R2, #0
    STR     R2, [R3]
    SWI     0x24
    LDR     R0, =0x01FF8328
    ADD     R1, SP, #0x14
    MOV     R2, #0x0
    MOV     R3, #0x36
@0:
    LDRB    R6, [R0, R2]
    EOR     R6, R3
    STRB    R6, [R1, R2]
    ADD     R2, R2, #0x1
    CMP     R2, #0x40
    BLT     @0
    ADD     R0, SP, #0x54
    SWI     0x25
    ADD     R0, SP, #0x54
    MOV     R1, R5
    MOV     R2, R4
    SWI     0x25
    ADD     R0, SP, #0x0
    ADD     R1, SP, #0x54
    SWI     0x26
    ADD     R0, SP, #0x54
    MOV     R3, #0x60
    ADD     R3, R0
    MOV     R2, #0
    STR     R2, [R3]
    SWI     0x24
    LDR     R0, =0x01FF8328
    ADD     R1, SP, #0x14
    MOV     R2, #0x0
    MOV     R3, #0x5C
@1:
    LDRB    R6, [R0, R2]
    EOR     R6, R3
    STRB    R6, [R1, R2]
    ADD     R2, R2, #0x1
    CMP     R2, #0x40
    BLT     @1
    ADD     R0, SP, #0x54
    SWI     0x25
    ADD     R0, SP, #0x54
    ADD     R1, SP, #0x0
    MOV     R2, #0x14
    SWI     0x25
    ADD     R0, SP, #0x0
    ADD     R1, SP, #0x54
    SWI     0x26
    ADD     R0, SP, #0x0
    MOV     R1, R7
    SWI     0x28
    CMP     R0, #0x0
    BEQ     @2
    MOV     R0, #0x1
@2:
    ADD     SP, #0xB8
    POP     {R3, R4, R5, R6, R7, PC}
    NOP
    dcd 0xDEC00621
    dcd 0x3FCE98BA
    dcd 0x9DE392A6
    dcd 0x01EDF246
    dcd 0x08CCE376
    dcd 0xFA632356
    dcd 0xDFECD4CA
    dcd 0x3478629A
    dcd 0x3C636D8F
    dcd 0x92CA22FE
    dcd 0x23978820
    dcd 0xC2AECFD2
    dcd 0xFE8D6732
    dcd 0x986483CA
    dcd 0x373EFDAC
    dcd 0x24584687
}

#pragma thumb off

extern BOOL OSi_VerifyStaticSegmentHash(const u8 *src, u32 len, const void *digest);
extern int OS_IsResetOccurred(void);
extern int OS_IsRunOnTwl(void);
extern void OSi_ReloadRomData(int);
extern void OSi_VerifyStaticSegments(void);
extern void OSi_DoBoot(void);
void OSi_DoResetSystem(void);
asm void OSi_CpuClear32(u32 data, void *destp, u32 size);
void OSi_ReadCardRom32(u32 src, void *dst, int len);

/*
 * SDK: OSi_VerifyStaticSegments, TwlSDK/lib/ARM9-TS/Rom/libos.TWL.HYB.a
 * (os_reset.o), definition at build/libraries/os/common/src/os_reset.c:339.
 * The Rom object is ARM and is byte-identical to this 168-byte extent: its
 * .itcm section for OSi_VerifyStaticSegments is 0xA8 bytes, its
 * DW_AT_decl_line is 339, and the relocation-free code is
 * e92d40f8 e24dd020 e59f7094 e3a04001 e5d7001c ... a4: 0x02ffe000.
 *
 * Built with SDK_OS_RESET_COMPACT, so the HMAC-SHA1 is a call out to
 * OSi_VerifyStaticSegmentHash (0x01FF82A8) rather than the inline
 * SVC_HMACSHA1 sequence.  DWARF decl_file/line inside the subprogram:
 * result 341 (r4), i 345 (r0), table 356 (fbreg 16), compareDigests 357
 * (fbreg 0), address 381, size 382, and a 0x8-byte `struct Segment` with
 * `address` at +0 and `size` at +4 -- the shape the ldm {r0,r1} at +0x74
 * loads.  Decoded line map over this extent:
 *   +0x00 340  result = TRUE
 *   +0x0c 341  header = (const CARDRomHeaderTWL *)HW_TWL_ROM_HEADER_BUF
 *   +0x08 343  if (((const u8 *)header)[0x1C] & 1)
 *   +0x1c-0x28 358-361  table[0..3] = &ntr.main_ram_address,
 *                            &ntr.sub_ram_address, &main_ltd_ram_address,
 *                            &sub_ltd_ram_address  (0x28, 0x38, 0x1C8,
 *                            0x1D8)
 *   +0x2c-0x38 362-365  compareDigests[0..3] = &((const u8*)header)[0x3A0],
 *                            sub_static_digest 0x314,
 *                            main_ltd_static_digest 0x350,
 *                            sub_ltd_static_digest 0x364
 *   +0x5c 366  for (i = 0; i < SEGMENT_TOTAL; ++i)
 *   +0x64 381  address = table[i]->address
 *   +0x70 383  if (i == 0)
 *   +0x78 385  address += 0x4000
 *   +0x7c 386  size -= 0x4000
 *   +0x80 394  result &= OSi_VerifyStaticSegmentHash(address, size, ...)
 *   +0x94 399  while (result == FALSE) -- the fail-stop spin
 */
void OSi_VerifyStaticSegments(void)
{
    BOOL result = 1;
    const u8 *header = (const u8 *)0x02FFE000;
    if ((header[0x1C] & 0x01) != 0)
    {
        int i;
        struct Segment { const u8 *address; u32 size; } *(table[4]);
        const void *(compareDigests[4]);

        table[0] = (struct Segment *)&header[0x28];
        table[1] = (struct Segment *)&header[0x38];
        table[2] = (struct Segment *)&header[0x1C8];
        table[3] = (struct Segment *)&header[0x1D8];

        compareDigests[0] = &header[0x3A0];
        compareDigests[1] = &header[0x314];
        compareDigests[2] = &header[0x350];
        compareDigests[3] = &header[0x364];

        for (i = 0; i < 4; ++i)
        {
            const u8 *address = table[i]->address;
            u32 size = table[i]->size;
            if (i == 0)
            {
                address += 0x4000;
                size -= 0x4000;
            }
            result &= OSi_VerifyStaticSegmentHash(address, size, compareDigests[i]);
        }
    }
    while (result == 0)
    {
    }
}

void OSi_DoResetSystem(void)
{
    while (!OS_IsResetOccurred()) {
    }
    *(volatile u16 *)0x04000208 = 0;
    if (OS_IsRunOnTwl() == 1) {
        OSi_ReloadRomData(1);
        OSi_VerifyStaticSegments();
    } else {
        OSi_ReloadRomData(0);
    }
    OSi_DoBoot();
}

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

/* hand-written in the original: boot jump with mcr p15 and no stack, one SDK line-table row per instruction */
asm void OSi_DoBoot(void)
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
    bl      OSi_CpuClear32

    str     r4, [r3]

    ldr     r1, =HW_PXI_SIGNAL_PARAM_ARM9
    mov     r2, #0x18
    bl      OSi_CpuClear32

    ldr     r1, =HW_WM_RSSI_POOL
    strh    r0, [r1]

    ldr     r1, =HW_COMPONENT_PARAM
    mov     r2, #0x64
    bl      OSi_CpuClear32

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

/* hand-written in the original: SDK inline-asm stm fill loop (os_reset.o) */
asm void OSi_CpuClear32(u32 data, void *destp, u32 size)
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
 * hand-written in the original: ldm/stm and mcr p15 sequence, one SDK line-table row per instruction
 */
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

void OSi_ReadCardRom32(u32 src, void *dst, int len)
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

#pragma thumb reset
