/*
 * function: DWCi_Ndi_initLockGlobal
 * address:  0x021C78C4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Hands the 0x021D3C38 block to the DSP/buffer flusher, then reports success.
 *
 * symbols:
 *   OS_InitMutex  0x02086004  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void OS_InitMutex(void *);

int DWCi_Ndi_initLockGlobal(void)
{
    OS_InitMutex((void *)0x021D3C38);
    return 1;
}
