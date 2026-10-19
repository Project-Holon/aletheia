/*
 * function: DWCi_MoveTaskEnd
 * address:  0x021C117C
 * packet:   pkt_ov016_021C117C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskEnd (libdwcutil.TWL.HYB.a(move.o))
 *
 * symbols:
 *   DWCi_MOVFinalize  0x021D3BF8  arm  ov016
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   gMoveWork  0x021DE590  data
 */

extern int DWCi_MOVFinalize(void);
extern void DWCi_TSKlDelete(int kind, void *task);
extern char *gMoveWork;

void DWCi_MoveTaskEnd(void *task)
{
	if (DWCi_MOVFinalize() == 0)
		return;
	gMoveWork[0x1e2a1] = 1;
	DWCi_TSKlDelete(0, task);
}
