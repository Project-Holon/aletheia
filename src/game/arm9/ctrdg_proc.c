/*
 * file:     ctrdg_proc.c
 * function: CTRDG_DummyInit
 * address:  0x020911A0
 * packet:   pkt_020911A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CTRDG_DummyInit (libctrdg.TWL.HYB.a ctrdg_proc.o)
 *
 * symbols:
 *   CTRDGi_InitCommon  0x02090F18  arm
 *   PXI_SetFifoRecvCallback  0x020885A0  arm
 *   CTRDGi_SendtoPxi  0x02091150  arm
 *   MSL_C_LIB_EmptyStub  0x020911D4  arm
 */

#include "../types.h"

#include "ctrdg.h"
#include "pxi_fifo.h"
#include "msl_crt.h"

void CTRDG_DummyInit(void)
{
    CTRDGi_InitCommon();
    PXI_SetFifoRecvCallback(13, 0);
    PXI_SetFifoRecvCallback(13, (void (*)(int,  u32,  BOOL))MSL_C_LIB_EmptyStub);
    CTRDGi_SendtoPxi(1);
}
