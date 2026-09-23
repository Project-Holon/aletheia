/*
 * function: func_0206DBF4
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
 * NNS_G3dGeSendDL (func_0206DC00) passes to the async DMA start; it clears
 * the in-flight word it is handed (&g_0214BAB4.busy).  A 12-byte leaf with
 * no lr save, so disasm.py folds it into func_0206DBDC's listing extent;
 * filed as the witness that clears func_0206DC00's ABS32 site once
 * 0x0206DBF4 is seeded in layout/function_starts.txt.
 */

typedef unsigned int u32;

void func_0206DBF4(void *arg)
{
    *(volatile u32 *)arg = 0;
}
