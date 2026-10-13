/*
 * function: DWCi_SNDlEnd
 * address:  0x021CFF80
 * packet:   pkt_ov016_021CFF80
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SNDlEnd (libdwcutil.TWL.HYB.a(sound.o))
 *
 * symbols:
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gSoundWork  0x021DE648  data
 */

#include "../include/G_SND.h"

typedef struct {
	char pad[0xa8];
	void *task;
} SND;

extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_HEAPlFree_(void **mem);
extern struct SND *gSoundWork;

void DWCi_SNDlEnd(void)
{
	DWCi_TSKlDelete(0, gSoundWork->task);
	DWCi_HEAPlFree_((void **)0x021DE648);
}
