/*
 * file:     unit_020911A0.c
 * function: func_020911A0
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
 *   CTRDGi_DummyCallback  0x020911D4  arm
 */

typedef unsigned long u32;
typedef int BOOL;

extern void CTRDGi_InitCommon(void);
extern void PXI_SetFifoRecvCallback(int fifotag, void (*callback)(int, u32, BOOL));
extern void CTRDGi_SendtoPxi(u32 data);
extern void CTRDGi_DummyCallback(int tag, u32 data, BOOL err);

void func_020911A0(void)
{
    CTRDGi_InitCommon();
    PXI_SetFifoRecvCallback(13, 0);
    PXI_SetFifoRecvCallback(13, CTRDGi_DummyCallback);
    CTRDGi_SendtoPxi(1);
}
