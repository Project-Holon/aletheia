/*
 * function: DWCi_QUElDelete
 * address:  0x021D5450
 * packet:   pkt_ov016_021D5450
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QUElDelete (libdwcutil.TWL.HYB.a(list.o))
 *
 * symbols:
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 */

struct tagLISTCB;

extern void DWCi_HEAPlFree_(void **mem);

void DWCi_QUElDelete(struct tagLISTCB *list)
{
	DWCi_HEAPlFree_((void **)&list);
}
