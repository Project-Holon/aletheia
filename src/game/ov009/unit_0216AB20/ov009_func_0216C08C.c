/*
 * function: DWCi_GPErrorCallback
 * address:  0x0216C08C
 * packet:   pkt_ov009_0216C08C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GPErrorCallback (dwc_main.o)
 *
 * The GP error argument arrives in r1 (the callback's second parameter).
 *
 * symbols:
 *   func_0216BD04  0x0216BD04  arm  ov009
 */

extern int func_0216BD04(int result);

void DWCi_GPErrorCallback(void *connection, int *arg)
{
    int v = arg[1];

    if (v == 0x603 || v == 0x901 || v == 0xb01) return;
    func_0216BD04(3);
}
