/*
 * function: DWCi_ShutdownTransport
 * address:  0x0217772C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at the state object, then tail calls its initialiser.
 *
 * symbols:
 *   gDwcTransInfo  0x021AB180  data
 *   DWCi_CleanupReliableQueue  0x02176B80  arm  ov009
 */

extern char gDwcTransInfo[];
extern void DWCi_CleanupReliableQueue(char *p);

void DWCi_ShutdownTransport(void)
{
    *(int *)gDwcTransInfo = 0;

    DWCi_CleanupReliableQueue(gDwcTransInfo);
}

