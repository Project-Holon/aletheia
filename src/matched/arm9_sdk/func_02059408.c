/*
 * function: DWCi_Acc_U64ToString32
 * address:  0x02059408
 * packet:   pkt_02059408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Acc_U64ToString32 (libdwcaccount.TWL.HYB.a(dwc_account.o))
 *
 * symbols:
 *   g_020A7FF4                       0x020A7FF4 data
 */

extern const char g_020A7FF4[];

void DWCi_Acc_U64ToString32(unsigned long long num, int bitnum, char *result)
{
    int i;
    int loopnum;
    const char *sStringTable;

    sStringTable = g_020A7FF4;
    loopnum = (bitnum + 4) / 5;
    for (i = 0; i < loopnum; i++) {
        *(result + loopnum - 1 - i) = sStringTable[num & 0x1f];
        num >>= 5;
    }
    result[loopnum] = 0;
}
