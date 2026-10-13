/*
 * function: DWCi_FOCUSlEnd
 * address:  0x021BD404
 * packet:   pkt_ov016_021BD404
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FOCUSlDelete            0x021BD5A8  arm
 *   DWCi_HEAPlFree_              0x021D6438  arm
 *   gFocusWork                   0x021DE550  data
*/

extern void DWCi_FOCUSlDelete(void);
extern void DWCi_HEAPlFree_(void **mem);
extern void *gFocusWork;

void DWCi_FOCUSlEnd(void)
{
    DWCi_FOCUSlDelete();
    DWCi_HEAPlFree_(&gFocusWork);
}
