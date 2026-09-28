/*
 * function: OS_SetIrqStackChecker
 * address:  0x020849F4
 * packet:   pkt_020849F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT* (listing extent runs on into an unlabelled 12-byte leaf at 0x02084A28)
 *
 * TwlSDK libos os_interrupt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   SDK_AUTOLOAD_DTCM_START        0x02FE0000  data
 *   SDK_IRQ_STACKSIZE              0x00000800  data
 */

typedef unsigned long u32;

extern char SDK_AUTOLOAD_DTCM_START[];
extern char SDK_IRQ_STACKSIZE[];

#define OSi_IRQ_STACK_TOP ((u32)SDK_AUTOLOAD_DTCM_START + 0x3F80)

void OS_SetIrqStackChecker(void)
{
    *(u32 *)(OSi_IRQ_STACK_TOP - sizeof(u32)) = 0xFDDB597D;
    *(u32 *)(OSi_IRQ_STACK_TOP - (u32)SDK_IRQ_STACKSIZE) = 0x7BF9DD5B;
}
