/*
 * function: DWCi_OBJlEnd
 * address:  0x021D6EEC
 * packet:   pkt_ov016_021D6EEC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OBJlEnd (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   DWCi_TSKlDeleteEx  0x021D7744  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gObjWork  0x021DE6A8  data
 */

extern void DWCi_TSKlDeleteEx(unsigned int idx, void *r4);
extern void DWCi_HEAPlFree_(void **mem);
extern char *gObjWork;

void DWCi_OBJlEnd(void)
{
	DWCi_TSKlDeleteEx(1, *(void **)(gObjWork + 0x808));
	DWCi_HEAPlFree_((void *)0x021DE6A8);
}
