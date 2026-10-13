/*
 * function: acFree
 * address:  0x021CD570
 * packet:   pkt_ov016_021CD570
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_HEAPlFree2              0x021D647C  arm
*/

extern void DWCi_HEAPlFree2(void *mem);

void acFree(void *unused, void *ptr)
{
    DWCi_HEAPlFree2(ptr);
}
