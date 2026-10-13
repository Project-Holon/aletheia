/*
 * function: DWCi_MOV_WH_StateInEndScan
 * address:  0x02178964
 * packet:   pkt_ov014_02178964
 * region:   ov014
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_WH_StateInEndScan (libdwcutil.TWL.HYB.thumb.a(dwc_mov_wh.o))
 *
 * symbols:
 *   WM_EndScan                       0x0208F808  arm
 *   DWCi_MOV_WH_SetError             0x0217814C  thumb
 */

extern int WM_EndScan(void *);
extern void DWCi_MOV_WH_SetError(int code);

static int DWCi_MOV_WH_StateInEndScan(void)
{
	int result;

	result = WM_EndScan((void *)0x02178981);
	if (result != 2)
	{
		DWCi_MOV_WH_SetError(result);
		return 0;
	}
	return 1;
}
