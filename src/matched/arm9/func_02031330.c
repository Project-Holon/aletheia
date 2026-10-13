/*
 * function: PROCSYS_Main
 * address:  0x02031330
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_MainInternal  0x020313EC  arm
 */

extern unsigned int PROCSYS_MainInternal(void *p);

unsigned int PROCSYS_Main(void *p)
{
    return PROCSYS_MainInternal(p);
}
