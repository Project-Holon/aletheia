/*
 * function: func_02087EA8
 * address:  0x02087EA8
 * packet:   pkt_02087EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_InitVramExclusive (os_vramexclusive.o)
 *
 * symbols:
 *   OSi_vramExclusive  0x0215136C  data
 *   OSi_vramLockId     0x02151370  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

typedef long s32;

extern u32 OSi_vramExclusive;
extern u16 OSi_vramLockId[9];

void func_02087EA8(void)
{
    s32 i;

    OSi_vramExclusive = 0;
    for (i = 0; i < 9; i++) {
        OSi_vramLockId[i] = 0;
    }
}
