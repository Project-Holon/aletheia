/*
 * function: NNSi_G3dGeSendDLDone
 * address:  0x0206DBF4
 * packet:   pkt_0206DC00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem G3D gecom.c: the GX-command DMA completion callback that
 * NNS_G3dGeSendDL (NNS_G3dGeSendDL) passes to the async DMA start; it clears
 * the in-flight word it is handed (&gNnsG3dGeState.busy).  A 12-byte leaf with
 * no lr save, so disasm.py folds it into NNS_G3dGeWaitSendDL's listing extent;
 * filed as the witness that clears NNS_G3dGeSendDL's ABS32 site once
 * 0x0206DBF4 is seeded in layout/function_starts.txt.
 */

typedef unsigned int u32;

void NNSi_G3dGeSendDLDone(void *arg)
{
    *(volatile u32 *)arg = 0;
}
