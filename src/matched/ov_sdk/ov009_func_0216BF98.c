/*
 * function: DWCi_UpdateServersCallback
 * address:  0x0216BF98
 * packet:   pkt_ov009_0216BF98
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_UpdateServersCallback (dwc_main.o)
 *
 * The callback registered at +0x78 is forwarded the two own arguments plus
 * the stored context word at +0x7c (r2 is left as the third argument).
 *
 * symbols:
 *   g_021AA878     0x021AA878  data
 */

extern char g_021AA878[];

void DWCi_UpdateServersCallback(int error, int isChanged)
{
    char *p = *(char **)(g_021AA878 + 4);

    ((void (*)(int, int, int))*(void **)(p + 0x78))(error, isChanged,
        *(int *)(p + 0x7c));
}
