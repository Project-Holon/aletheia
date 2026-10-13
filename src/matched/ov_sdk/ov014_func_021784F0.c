/*
 * function: DWCi_MOV_WH_StateInEndParent
 * address:  0x021784F0
 * packet:   pkt_ov014_021784F0
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Closed 2026-09-28: the guard was written as the positive test with the true
 * arm first; mwcc places the true arm last and branches to it, so inverting to
 * `if (x != 2) { f(); return 0; } return 1;` reproduced the original's beq.
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md)
 *
 * symbols:
 *   WM_EndParent                 0x0208F654  arm
 *   WIH_SetError                0x0217814C  thumb
*/

extern int WM_EndParent(void *);
extern void WIH_SetError(void);

int DWCi_MOV_WH_StateInEndParent(void)
{
	if (WM_EndParent((void *)0x0217850D) != 2)
	{
		WIH_SetError();
		return 0;
	}
	return 1;
}

