/*
 * function: DWCi_MOV_WH_StateInEndParent
 * address:  0x021784F0
 * packet:   pkt_ov014_021784F0
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   PENDING
 *
 * symbols:
 *   WM_EndParent                 0x0208F654  arm
 *   func_0217814C                0x0217814C  thumb
*/

extern int WM_EndParent(void *);
extern void func_0217814C(void);

int DWCi_MOV_WH_StateInEndParent(void)
{
	if (WM_EndParent((void *)0x0217850D) == 2)
		return 1;
	func_0217814C();
	return 0;
}

