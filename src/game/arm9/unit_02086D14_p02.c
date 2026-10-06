/*
 * file:     unit_02086D14_p02.c
 * unit:     yes
 * function: func_02086DB0
 * address:  0x02086DB0
 * packet:   pkt_02086DB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_SetProtectionRegionEx (os_protectionregion.o)
 *
 * symbols:
 *   OS_SetProtectionRegionParam  0x02086D14  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

extern void OS_SetProtectionRegionParam(int regionNo, u32 param);

/*
 * sdk:      OS_SetProtectionRegionEx (os_protectionregion.o)
 */
void func_02086DB0(int regionNo, u32 address, u32 sizeDef)
{
    OS_SetProtectionRegionParam(regionNo,
        sizeDef | (address & (0xFFFFF000 << ((sizeDef - 0x16) >> 1))) | 1);
}
