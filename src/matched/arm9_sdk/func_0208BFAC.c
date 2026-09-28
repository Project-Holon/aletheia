/*
 * function: func_0208BFAC
 * address:  0x0208BFAC
 * packet:   pkt_0208BFAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/pm.o PM_GetACAdapter.
 *
 * symbols:
 *   OS_IsRunOnTwl          0x02085D3C  arm
 *   PMi_GetACAdapterCore   0x027313AC  arm
 */

int OS_IsRunOnTwl(void);
unsigned int PMi_GetACAdapterCore(void *buf);

unsigned int func_0208BFAC(void *isConnectedBuf)
{
    if (OS_IsRunOnTwl()) {
        return PMi_GetACAdapterCore(isConnectedBuf);
    }
    return 2;
}
