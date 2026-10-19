/*
 * file:     crt0.c
 * unit:     yes
 * function: _start, INITi_CpuClear32, INITi_InitCoprocessor, INITi_InitRegion, INITi_DoAutoload, INITi_ShelterStaticInitializer, INITi_CallStaticInitializers, MIi_UncompressBackward, _start_AutoloadDoneCallback, NitroStartUp, OSi_ReferSymbol, INITi_IsRunOnTwl, INITi_Copy32, INITi_Fill32
 * address:  0x02004800
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    crt0.HYB.TWL.o of the TwlSDK (its DWARF names the source crt0.FLX.c).
 *           Code and data in the order of the original source: the module
 *           parameters and the microcode tables first (DWARF lines 88-182), then
 *           the functions (lines 212-1084).  mwccarm puts the tables in one
 *           .rodata that the link places right after the crt0 text
 *           (0x02004F7C..0x02005030).  The build record _start_BuildParams (line 103)
 *           and the middleware .version strings that follow it at
 *           0x02005030..0x02005124 are units of their own: crt0_build.c and
 *           sdk_version_*.c.
 *           Most functions are inline asm in the original too
 *           (no C runtime yet when they run).  The microcode words come from
 *           the user's ROM: tools/gendata.py writes build/gen/microcode_*.inc
 *           (gitignored); run it before a build.
 *
 * symbols:
 *   _start_LtdModuleParams          0x02004F7C  data
 *   microcode_WaitAgreement         0x02004F94  data
 *   _start_ModuleParams             0x02004FB0  data
 *   microcode_ShakeHand             0x02004FD4  data
 *   microcode_SwitchCpuClock        0x02004FFC  data
 *   SDK_LTDAUTOLOAD_LIST            0x02432DA4  data
 *   SDK_LTDAUTOLOAD_LIST_END        0x02432DB4  data
 *   SDK_LTDAUTOLOAD_START           0x02400004  data
 *   SDK_LTDCOMPRESSED_END           0x02412F24  data
 *   SDK_AUTOLOAD_LIST               0x020AA780  data
 *   SDK_AUTOLOAD_LIST_END           0x020AA7C0  data
 *   SDK_AUTOLOAD_START              0x020A9E80  data
 *   SDK_STATIC_BSS_START            0x020A9E80  data
 *   SDK_STATIC_BSS_END              0x021542C0  data
 *   SDK_COMPRESSED_STATIC_END       0x02073898  data
 *   SDK_AUTOLOAD_DTCM_START         0x02FE0000  data
 *   _fp_init                        0x0209D724  arm
 *   __call_static_initializers      0x0209D820  arm
 */

extern char SDK_LTDAUTOLOAD_LIST[], SDK_LTDAUTOLOAD_LIST_END[], SDK_LTDAUTOLOAD_START[], SDK_LTDCOMPRESSED_END[];
extern char SDK_AUTOLOAD_LIST[], SDK_AUTOLOAD_LIST_END[], SDK_AUTOLOAD_START[];
extern char SDK_STATIC_BSS_START[], SDK_STATIC_BSS_END[], SDK_COMPRESSED_STATIC_END[];
extern char SDK_AUTOLOAD_DTCM_START[];

void _start(void);
static void INITi_CpuClear32(unsigned long data, void *destp, unsigned long size);
static void INITi_InitCoprocessor(void);
static void INITi_InitRegion(void);
static void INITi_DoAutoload(void);
static void INITi_ShelterStaticInitializer(void *ptr);
static void INITi_CallStaticInitializers(void);
void MIi_UncompressBackward(void *bottom);
void _start_AutoloadDoneCallback(void *argv[]);
void NitroStartUp(void);
void OSi_ReferSymbol(void *symbol);
static int INITi_IsRunOnTwl(void);
static void *INITi_Copy32(void *dst, const void *src, unsigned long size);
static void *INITi_Fill32(void *dst, unsigned long value, unsigned long size);
extern void _fp_init(void);
extern void __call_static_initializers(void);

void *const _start_ModuleParams[9] = {
    SDK_AUTOLOAD_LIST, SDK_AUTOLOAD_LIST_END, SDK_AUTOLOAD_START,
    SDK_STATIC_BSS_START, SDK_STATIC_BSS_END, SDK_COMPRESSED_STATIC_END,
    (void *)0x0503757C, (void *)0xDEC00621, (void *)0x2106C0DE,
};

void *const _start_LtdModuleParams[6] = {
    SDK_LTDAUTOLOAD_LIST, SDK_LTDAUTOLOAD_LIST_END, SDK_LTDAUTOLOAD_START, SDK_LTDCOMPRESSED_END,
    (void *)0xDEC01463, (void *)0x6314C0DE,
};

static const unsigned long microcode_ShakeHand[10] = {
#include "../version.h"
#include "../../../build/gen/microcode_02004FD4.inc"
};

static const unsigned long microcode_WaitAgreement[7] = {
#include "../../../build/gen/microcode_02004F94.inc"
};

static const unsigned long microcode_SwitchCpuClock[13] = {
#include "../../../build/gen/microcode_02004FFC.inc"
};

/* hand-written in the original: startup code with mcr/mrs and no stack, one SDK line-table row per instruction */
asm void _start(void)
{
    mov r12, #0x4000000
    str r12, [r12, #0x208]

    bl INITi_InitCoprocessor

    mov r0, #0
    ldr r1, =0x02FFFF80
    ldr r2, =0x00000068
    bl INITi_CpuClear32
    mov r0, #0
    ldr r1, =0x02FFFFF0
    ldr r2, =0x00000010
    bl INITi_CpuClear32

    ldr r1, =0x02FFFC40
    ldrh r2, [r1]
    cmp r2, #0
    moveq r2, #1
    streqh r2, [r1]

    ldr r1, =microcode_ShakeHand
    ldr r2, =0x01FF8000
    add r3, r2, #0x28
_001:
    ldr r0, [r1], #4
    str r0, [r2], #4
    cmp r2, r3
    blt _001

    ldr r0, =0x02FFFC28
    mov r1, #1
    strh r1, [r0]
    ldr r0, =0x02FFFC24
    ldr r1, =0x02FFFC26
    ldr r2, =0x01FF8000
    blx r2

    ldr r1, =microcode_WaitAgreement
    ldr r2, =0x01FF8000
    add r3, r2, #0x1c
_002:
    ldr r0, [r1], #4
    str r0, [r2], #4
    cmp r2, r3
    blt _002

    ldr r0, =0x02FFFC28
    mov r1, #4
    ldr r2, =0x01FF8000
    blx r2

    bl INITi_IsRunOnTwl
    bne _020

    ldr r1, =microcode_SwitchCpuClock
    ldr r2, =0x01FF8000
    add r2, r2, #0x1c
    mov r3, #0x34
_011:
    subs r3, r3, #4
    ldr r0, [r1, r3]
    str r0, [r2, r3]
    bgt _011
    mov r0, #1
    mov r1, #8
    blx r2

_020:
    bl INITi_InitRegion

    mov r0, #0x13
    msr cpsr_c, r0
    ldr r1, =0x02FE0000
    add r1, r1, #0x4000
    sub sp, r1, #0x40
    sub r1, sp, #0x40
    mov r0, #0x12
    msr cpsr_c, r0
    sub sp, r1, #4
    tst sp, #4
    subeq sp, sp, #4
    ldr r0, =0x00000800
    sub r1, r1, r0
    mov r0, #0x1f
    msr cpsr_fsxc, r0
    sub sp, r1, #4
    tst sp, #4
    subne sp, sp, #4

    mov r0, #0
    ldr r1, =0x02FE0000
    mov r2, #0x4000
    bl INITi_CpuClear32

    mov r1, #0
    ldr r0, =0x05000000
    mov r2, #0x400
    bl INITi_Fill32
    ldr r0, =0x07000000
    mov r2, #0x400
    bl INITi_Fill32

    bl INITi_DoAutoload

    mov r1, #0
    ldr r3, =_start_ModuleParams
    ldr r0, [r3, #0xc]
    ldr r2, [r3, #0x10]
    subs r2, r2, r0
    blgt INITi_Fill32

    ldr r1, =0x02FE0000
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    ldr r0, =0x01FF80F0
    str r0, [r1]

    bl _fp_init
    bl NitroStartUp
    bl __call_static_initializers
    bl INITi_CallStaticInitializers

    ldr r1, =0x04000006
_022:
    ldrh r0, [r1]
    cmp r0, #0
    bne _022

    ldr r1, =0x02005125
    ldr lr, =0xFFFF0000
    bx r1
}


/* hand-written in the original: SDK crt0 routine (inline asm in the SDK source) */
static asm void INITi_CpuClear32(unsigned long data, void *destp, unsigned long size)
{
    add r12, r1, r2
_loop:
    cmp r1, r12
    strlt r0, [r1], #4
    blt _loop
    bx lr
}

/* hand-written in the original: mcr/mrc p15 setup, one SDK line-table row per instruction */
static asm void INITi_InitCoprocessor(void)
{
    mrc p15, 0, r0, c1, c0, 0

    tst r0, #1
    beq _010
    tst r0, #4
    beq _003

    mov r1, #0
_001:
    mov r2, #0
_002:
    orr r3, r1, r2
    mcr p15, 0, r3, c7, c10, 2
    add r2, r2, #0x20
    cmp r2, #0x400
    blt _002
    adds r1, r1, #0x40000000
    bne _001

_003:
    mov r1, #0
    mcr p15, 0, r1, c7, c10, 4

_010:
    ldr r1, =0x000f9005
    bic r0, r0, r1
    ldr r1, =0x00002078
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0

    mov r1, #0x20
    mcr p15, 0, r1, c9, c1, 1
    ldr r1, =0x02fe0000
    orr r1, r1, #0xa
    mcr p15, 0, r1, c9, c1, 0

    mov r1, #0x50000
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0

    bx lr
}

/* hand-written in the original: mcr p15 protection region setup, one SDK line-table row per instruction */
static asm void INITi_InitRegion(void)
{
    mov r12, lr

    ldr r0, =0x04000033
    mcr p15, 0, r0, c6, c0, 0

    ldr r0, =0x02FE0000
    orr r0, r0, #0x1b
    mcr p15, 0, r0, c6, c4, 0

    ldr r0, =0x0100002F
    mcr p15, 0, r0, c6, c5, 0

    ldr r0, =0xFFFF001D
    mcr p15, 0, r0, c6, c6, 0

    bl INITi_IsRunOnTwl
    bne _002

_001:
    ldr r0, =0x02000031
    mcr p15, 0, r0, c6, c1, 0

    ldr r0, =0x02F80025
    mcr p15, 0, r0, c6, c2, 0

    ldr r0, =0x08000035
    mcr p15, 0, r0, c6, c3, 0

    ldr r0, =0x02FFC01B
    mcr p15, 0, r0, c6, c7, 0

    mov r0, #0x4a
    mcr p15, 0, r0, c2, c0, 1

    mov r0, #0x4a
    mcr p15, 0, r0, c2, c0, 0

    mov r0, #0xa
    mcr p15, 0, r0, c3, c0, 0

    ldr r0, =0x05101011
    mcr p15, 0, r0, c5, c0, 3

    ldr r0, =0x15111011
    mcr p15, 0, r0, c5, c0, 2

    b _003

_002:
    ldr r0, =0x02000031
    mcr p15, 0, r0, c6, c1, 0

    ldr r0, =0x027FF017
    mcr p15, 0, r0, c6, c2, 0

    ldr r0, =0x08000035
    mcr p15, 0, r0, c6, c3, 0

    ldr r0, =0x02FFF017
    mcr p15, 0, r0, c6, c7, 0

    mov r0, #0x42
    mcr p15, 0, r0, c2, c0, 1

    mov r0, #0x42
    mcr p15, 0, r0, c2, c0, 0

    mov r0, #2
    mcr p15, 0, r0, c3, c0, 0

    ldr r0, =0x05101011
    mcr p15, 0, r0, c5, c0, 3

    ldr r0, =0x15111111
    mcr p15, 0, r0, c5, c0, 2

_003:
    mrc p15, 0, r0, c1, c0, 0
    ldr r1, =0x00005005
    orr r0, r0, r1
    mcr p15, 0, r0, c1, c0, 0

    mov r1, #0
    mcr p15, 0, r1, c7, c6, 0
    mcr p15, 0, r1, c7, c5, 0

    bx r12
}

/* hand-written in the original: runs before the C runtime exists (fixed-register stack use around its calls, mcr p15 cache ops) */
static asm void INITi_DoAutoload(void)
{
    stmdb sp!, {lr}
    ldr r1, =_start_ModuleParams
    ldr r0, [r1, #20]
    bl MIi_UncompressBackward
    ldr r0, =_start_ModuleParams
    ldr r12, [r0, #0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]
_s_loop:
    cmp r12, r3
    bge _s_end
    stmdb sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmdb sp!, {r0}
    bl INITi_Copy32
    stmdb sp!, {r0, r1}
    ldr r0, [r12], #4
    stmdb sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmia sp!, {r12}
    ldmia sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmia sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt _s_next
    ldr r3, =SDK_AUTOLOAD_DTCM_START
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt _s_next
    bic r2, r2, #0x1f
_s_flush:
    cmp r2, r0
    bge _s_next
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b _s_flush
_s_next:
    ldmia sp!, {r3}
    b _s_loop
_s_end:
    bl INITi_IsRunOnTwl
    bne _done
    ldr r1, =0x02FFE1CC
    ldr r0, [r1]
    cmp r0, #0
    beq _done
    ldr r1, =_start_LtdModuleParams
    ldr r0, [r1, #12]
    bl MIi_UncompressBackward
    ldr r0, =_start_LtdModuleParams
    ldr r12, [r0, #0]
    ldr r3, [r0, #4]
    ldr r1, [r0, #8]
_l_loop:
    cmp r12, r3
    bge _l_end
    stmdb sp!, {r3}
    ldr r0, [r12], #4
    ldr r2, [r12], #4
    stmdb sp!, {r0}
    bl INITi_Copy32
    stmdb sp!, {r0, r1}
    ldr r0, [r12], #4
    stmdb sp!, {r12}
    bl INITi_ShelterStaticInitializer
    ldmia sp!, {r12}
    ldmia sp!, {r0}
    mov r1, #0
    ldr r2, [r12], #4
    bl INITi_Fill32
    ldmia sp!, {r1, r2}
    mov r3, #0x1000000
    cmp r2, r3
    movge r3, #0x2000000
    cmpge r3, r2
    bgt _l_next
    ldr r3, =SDK_AUTOLOAD_DTCM_START
    cmp r2, r3
    addge r3, r3, #0x4000
    cmpge r3, r2
    bgt _l_next
    bic r2, r2, #0x1f
_l_flush:
    cmp r2, r0
    bge _l_next
    mcr p15, 0, r2, c7, c14, 1
    mcr p15, 0, r2, c7, c5, 1
    add r2, r2, #0x20
    b _l_flush
_l_next:
    ldmia sp!, {r3}
    b _l_loop
_l_end:
_done:
    mov r0, #0
    mcr p15, 0, r0, c7, c10, 4
    ldr r0, =_start_ModuleParams
    ldr r1, =_start_LtdModuleParams
    ldmia sp!, {lr}
    b _start_AutoloadDoneCallback
}

/* hand-written in the original: SDK crt0 routine (inline asm in the SDK source) */
static asm void INITi_ShelterStaticInitializer(void *ptr)
{
    cmp r0, #0
    bxeq lr
    ldr r1, =0x02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x00000800
    sub r1, r1, r2
    add r1, r1, #4
_scan:
    ldr r2, [r1]
    cmp r2, #0
    addne r1, r1, #4
    bne _scan
_copy:
    ldr r2, [r0], #4
    str r2, [r1], #4
    cmp r2, #0
    bne _copy
    bx lr
}

/* hand-written in the original: SDK crt0 routine; saves only r1 around blx, which mwccarm never emits */
static asm void INITi_CallStaticInitializers(void)
{
    stmfd sp!, {lr}
    ldr r1, =0x02fe0000
    add r1, r1, #0x4000
    sub r1, r1, #0x40
    sub r1, r1, #0x40
    ldr r2, =0x00000800
    sub r1, r1, r2
    add r1, r1, #4
_loop:
    ldr r0, [r1]
    cmp r0, #0
    beq _end
    stmfd sp!, {r1}
    blx r0
    ldmfd sp!, {r1}
    mov r0, #0
    str r0, [r1], #4
    b _loop
_end:
    ldmfd sp!, {lr}
    bx lr
}

/* hand-written in the original: hand register allocation, one SDK line-table row per instruction */
asm void MIi_UncompressBackward(void *bottom)
{
    cmp r0, #0
    beq _exit
    stmfd sp!, {r4-r8}
    ldmdb r0, {r1, r2}
    add r2, r0, r2
    sub r3, r0, r1, lsr #24
    bic r1, r1, #0xff000000
    sub r1, r0, r1
    mov r4, r2

_loop:
    cmp r3, r1
    ble _end_loop
    ldrb r5, [r3, #-1]!
    mov r6, #8

_loop8:
    subs r6, r6, #1
    blt _loop
    tst r5, #0x80
    bne _blockcopy
    ldrb r0, [r3, #-1]!
    ldrb r8, [r2, #-1]
    strb r0, [r2, #-1]!
    b _joinhere

_blockcopy:
    ldrb r12, [r3, #-1]!
    ldrb r7, [r3, #-1]!
    orr r7, r7, r12, lsl #8
    bic r7, r7, #0xf000
    add r7, r7, #2
    add r12, r12, #0x20

_patterncopy:
    ldrb r0, [r2, r7]
    ldrb r8, [r2, #-1]
    strb r0, [r2, #-1]!
    subs r12, r12, #0x10
    bge _patterncopy

_joinhere:
    cmp r3, r1
    mov r5, r5, lsl #1
    bgt _loop8

_end_loop:
    mov r0, #0
    bic r3, r1, #0x1f

_cacheflush:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r3, c7, c5, 1
    mcr p15, 0, r3, c7, c14, 1
    add r3, r3, #0x20
    cmp r3, r4
    blt _cacheflush
    ldmfd sp!, {r4-r8}

_exit:
    bx lr
}

/* _start_AutoloadDoneCallback: INITi_DoAutoload ends with a branch here (crt0 relocation PC24 at +0x188) */
void _start_AutoloadDoneCallback(void *argv[])
{
}

void NitroStartUp(void)
{
}

void OSi_ReferSymbol(void *symbol)
{
}

static int INITi_IsRunOnTwl(void)
{
    return (*(volatile unsigned char *)0x04004000 & 3) == 1;
}

/* hand-written in the original: ldm/stm copy loop, one SDK line-table row per instruction */
static asm void *INITi_Copy32(void *dst, const void *src, unsigned long size)
{
    stmfd sp!, {r3-r11}
    bics r3, r2, #0x1f
    beq _next
    add r3, r0, r3
_loop:
    ldmia r1!, {r4, r5, r6, r7, r8, r9, r10, r11}
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt _loop
_next:
    tst r2, #0x10
    ldmneia r1!, {r4, r5, r6, r7}
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    ldmneia r1!, {r4, r5}
    stmneia r0!, {r4, r5}
    tst r2, #4
    ldmneia r1!, {r4}
    stmneia r0!, {r4}
    ldmfd sp!, {r3-r11}
    bx lr
}

/* hand-written in the original: stm fill loop, one SDK line-table row per instruction */
static asm void *INITi_Fill32(void *dst, unsigned long value, unsigned long size)
{
    stmfd sp!, {r3-r11}
    mov r4, r1
    mov r5, r1
    mov r6, r1
    mov r7, r1
    mov r8, r1
    mov r9, r1
    mov r10, r1
    mov r11, r1
    bics r3, r2, #0x1f
    beq _next
    add r3, r0, r3
_loop:
    stmia r0!, {r4, r5, r6, r7, r8, r9, r10, r11}
    cmp r3, r0
    bgt _loop
_next:
    tst r2, #0x10
    stmneia r0!, {r4, r5, r6, r7}
    tst r2, #8
    stmneia r0!, {r4, r5}
    tst r2, #4
    stmneia r0!, {r4}
    ldmfd sp!, {r3-r11}
    bx lr
}
