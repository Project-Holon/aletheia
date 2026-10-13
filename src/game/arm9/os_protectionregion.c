/*
 * file:     os_protectionregion.c
 * unit:     yes
 * function: OS_SetProtectionRegionParam, func_02086D30, func_02086D38, func_02086D40, func_02086D48, func_02086D50, func_02086D58, func_02086D60, func_02086D68, func_02086D70, func_02086D78, func_02086D80, func_02086D88, func_02086D90, func_02086D98, func_02086DA0, func_02086DA8, func_02086DB0
 * address:  0x02086D14
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_SetProtectionRegionEx (os_protectionregion.o)
 *
 * symbols:
 *   g_020A86B4 0x020A86B4 data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern void (*g_020A86B4[8])(u32);

/* Dispatches through the table at g_020A86B4 (the first eight stubs below:
 * data protection region 0..7 parameter writes). */
void OS_SetProtectionRegionParam(int regionNo, u32 param)
{
    g_020A86B4[regionNo](param);
}

/* p15 c6,c0: data protection region 0, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D30(u32 param)
{
    mcr p15, 0, r0, c6, c0, 0
    bx lr
}

/* p15 c6,c1: data protection region 1, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D38(u32 param)
{
    mcr p15, 0, r0, c6, c1, 0
    bx lr
}

/* p15 c6,c2: data protection region 2, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D40(u32 param)
{
    mcr p15, 0, r0, c6, c2, 0
    bx lr
}

/* p15 c6,c3: data protection region 3, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D48(u32 param)
{
    mcr p15, 0, r0, c6, c3, 0
    bx lr
}

/* p15 c6,c4: data protection region 4, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D50(u32 param)
{
    mcr p15, 0, r0, c6, c4, 0
    bx lr
}

/* p15 c6,c5: data protection region 5, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D58(u32 param)
{
    mcr p15, 0, r0, c6, c5, 0
    bx lr
}

/* p15 c6,c6: data protection region 6, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D60(u32 param)
{
    mcr p15, 0, r0, c6, c6, 0
    bx lr
}

/* p15 c6,c7: data protection region 7, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void func_02086D68(u32 param)
{
    mcr p15, 0, r0, c6, c7, 0
    bx lr
}

/* p15 c6,c0: data protection region 0, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086D70(void)
{
    mrc p15, 0, r0, c6, c0, 0
    bx lr
}

/* p15 c6,c1: data protection region 1, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086D78(void)
{
    mrc p15, 0, r0, c6, c1, 0
    bx lr
}

/* p15 c6,c2: data protection region 2, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086D80(void)
{
    mrc p15, 0, r0, c6, c2, 0
    bx lr
}

/* p15 c6,c3: data protection region 3, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086D88(void)
{
    mrc p15, 0, r0, c6, c3, 0
    bx lr
}

/* p15 c6,c4: data protection region 4, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086D90(void)
{
    mrc p15, 0, r0, c6, c4, 0
    bx lr
}

/* p15 c6,c5: data protection region 5, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086D98(void)
{
    mrc p15, 0, r0, c6, c5, 0
    bx lr
}

/* p15 c6,c6: data protection region 6, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086DA0(void)
{
    mrc p15, 0, r0, c6, c6, 0
    bx lr
}

/* p15 c6,c7: data protection region 7, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 func_02086DA8(void)
{
    mrc p15, 0, r0, c6, c7, 0
    bx lr
}

/*
 * sdk:      OS_SetProtectionRegionEx (os_protectionregion.o)
 */
void func_02086DB0(int regionNo, u32 address, u32 sizeDef)
{
    OS_SetProtectionRegionParam(regionNo,
        sizeDef | (address & (0xFFFFF000 << ((sizeDef - 0x16) >> 1))) | 1);
}
