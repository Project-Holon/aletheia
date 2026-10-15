/*
 * file:     os_protectionregion.c
 * unit:     yes
 * function: OS_SetProtectionRegionParam, OSi_WriteProtectionRegion0, OSi_WriteProtectionRegion1, OSi_WriteProtectionRegion2, OSi_WriteProtectionRegion3, OSi_WriteProtectionRegion4, OSi_WriteProtectionRegion5, OSi_WriteProtectionRegion6, OSi_WriteProtectionRegion7, OSi_ReadProtectionRegion0, OSi_ReadProtectionRegion1, OSi_ReadProtectionRegion2, OSi_ReadProtectionRegion3, OSi_ReadProtectionRegion4, OSi_ReadProtectionRegion5, OSi_ReadProtectionRegion6, OSi_ReadProtectionRegion7, OS_SetProtectionRegionEx
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
asm void OSi_WriteProtectionRegion0(u32 param)
{
    mcr p15, 0, r0, c6, c0, 0
    bx lr
}

/* p15 c6,c1: data protection region 1, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion1(u32 param)
{
    mcr p15, 0, r0, c6, c1, 0
    bx lr
}

/* p15 c6,c2: data protection region 2, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion2(u32 param)
{
    mcr p15, 0, r0, c6, c2, 0
    bx lr
}

/* p15 c6,c3: data protection region 3, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion3(u32 param)
{
    mcr p15, 0, r0, c6, c3, 0
    bx lr
}

/* p15 c6,c4: data protection region 4, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion4(u32 param)
{
    mcr p15, 0, r0, c6, c4, 0
    bx lr
}

/* p15 c6,c5: data protection region 5, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion5(u32 param)
{
    mcr p15, 0, r0, c6, c5, 0
    bx lr
}

/* p15 c6,c6: data protection region 6, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion6(u32 param)
{
    mcr p15, 0, r0, c6, c6, 0
    bx lr
}

/* p15 c6,c7: data protection region 7, write */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm void OSi_WriteProtectionRegion7(u32 param)
{
    mcr p15, 0, r0, c6, c7, 0
    bx lr
}

/* p15 c6,c0: data protection region 0, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion0(void)
{
    mrc p15, 0, r0, c6, c0, 0
    bx lr
}

/* p15 c6,c1: data protection region 1, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion1(void)
{
    mrc p15, 0, r0, c6, c1, 0
    bx lr
}

/* p15 c6,c2: data protection region 2, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion2(void)
{
    mrc p15, 0, r0, c6, c2, 0
    bx lr
}

/* p15 c6,c3: data protection region 3, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion3(void)
{
    mrc p15, 0, r0, c6, c3, 0
    bx lr
}

/* p15 c6,c4: data protection region 4, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion4(void)
{
    mrc p15, 0, r0, c6, c4, 0
    bx lr
}

/* p15 c6,c5: data protection region 5, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion5(void)
{
    mrc p15, 0, r0, c6, c5, 0
    bx lr
}

/* p15 c6,c6: data protection region 6, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion6(void)
{
    mrc p15, 0, r0, c6, c6, 0
    bx lr
}

/* p15 c6,c7: data protection region 7, read */
/* hand-written in the original: CP15 access (mcr p15) for the MPU protection region registers, no C spelling */
asm u32 OSi_ReadProtectionRegion7(void)
{
    mrc p15, 0, r0, c6, c7, 0
    bx lr
}

/*
 * sdk:      OS_SetProtectionRegionEx (os_protectionregion.o)
 */
void OS_SetProtectionRegionEx(int regionNo, u32 address, u32 sizeDef)
{
    OS_SetProtectionRegionParam(regionNo,
        sizeDef | (address & (0xFFFFF000 << ((sizeDef - 0x16) >> 1))) | 1);
}
