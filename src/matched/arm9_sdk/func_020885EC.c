/*
 * function: func_020885EC
 * address:  0x020885EC
 * packet:   pkt_020885EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PXI_IsCallbackReady (libpxi.TWL.HYB.a pxi_fifo.o)
 */

typedef unsigned long u32;
typedef int BOOL;

typedef struct OSSystemWork {
    unsigned char pad[0x388];
    u32 pxiHandleChecker[2];
} OSSystemWork;

static inline OSSystemWork *OS_GetSystemWork(void)
{
    return (OSSystemWork *)0x02FFFC00;
}

BOOL func_020885EC(int fifotag, int proc)
{
    OSSystemWork *w = OS_GetSystemWork();

    return (w->pxiHandleChecker[proc] & (1UL << fifotag)) ? 1 : 0;
}
