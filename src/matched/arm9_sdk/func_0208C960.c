/*
 * function: func_0208C960
 * address:  0x0208C960
 * packet:   pkt_0208C960
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SCFG_Init (libscfg.TWL.HYB.a scfg_proc.o)
 *
 * symbols:
 *   PXI_SetFifoRecvCallback        0x020885A0  arm
 *   SCFGi_CommonCallback           0x0208C9C4  arm
 *   SCFGi_FuseInfo                 0x02153040  data
 */

typedef unsigned long u32;

typedef struct SCFGFuseInfo {
    volatile int ready;
} SCFGFuseInfo;

extern SCFGFuseInfo SCFGi_FuseInfo;

void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int tag, u32 data, int err));
void SCFGi_CommonCallback(int tag, u32 data, int err);

void func_0208C960(void)
{
    PXI_SetFifoRecvCallback(0x17, SCFGi_CommonCallback);
    SCFGi_FuseInfo.ready = 0;
}
