/*
 * function: DWCi_ANIMElEnd
 * address:  0x021BC8EC
 * packet:   pkt_021BC8EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_ANIMElEnd   0x021BC8EC  arm
 *   gAnimeWork    0x021DE504  data
 *   DWCi_TSKlDeleteEx   0x021D7744  arm
 *   DWCi_OBJlDelete   0x021D6F38  arm
 *   DWCi_HEAPlFree_   0x021D6438  arm
 *
 * Push the shared record's word and its +4 neighbour through the setters, then hand the record off.
 * Addresses are Black-image addresses.
 */

extern void DWCi_TSKlDeleteEx(unsigned int idx, void *r4);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_HEAPlFree_(void **mem);
extern unsigned char gAnimeWork[];

void DWCi_ANIMElEnd(void)
{
    unsigned char *g = (unsigned char *)0x021DE504;

    DWCi_TSKlDeleteEx(1, (void *)(**(int **)g));
    DWCi_OBJlDelete((unsigned int *)(*(int *)(*(int *)g + 4)));
    DWCi_HEAPlFree_((void **)((int)gAnimeWork));
}

