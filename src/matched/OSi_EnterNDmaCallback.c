/*
 * function: OSi_EnterNDmaCallback
 * address:  0x020848EC
 * packet:   pkt_020848EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os_interrupt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OSi_EnterNDmaCallback_ltdmain  0x0273126C  arm
 */

typedef unsigned long u32;

extern void OSi_EnterNDmaCallback_ltdmain(u32 dmaNo, void (*callback)(void *), void *arg);

void OSi_EnterNDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg)
{
    OSi_EnterNDmaCallback_ltdmain(dmaNo, callback, arg);
}
