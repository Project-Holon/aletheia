/*
 * function: DWCi_SBlEnd
 * address:  0x021CE94C
 * packet:   pkt_ov016_021CE94C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SBlEnd (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   DWCi_CELLlDelete  0x021D4F60  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gScrollBar  0x021DE63C  data
 */

typedef struct {
	void *cell;
	int pad[2];
	void *task;
} SB;

typedef unsigned char  u8;
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void DWCi_CELLlDelete(u8 *p);
extern void DWCi_HEAPlFree_(void **mem);
extern SB *gScrollBar;

void DWCi_SBlEnd(void)
{
	DWCi_TSKlDeleteByIndex(0, gScrollBar->task);
	DWCi_CELLlDelete(gScrollBar->cell);
	DWCi_HEAPlFree_((void **)0x021DE63C);
}
