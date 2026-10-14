/*
 * function: DWCi_ICONlEnd
 * address:  0x021BD7F4
 * packet:   pkt_ov016_021BD7F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ICONlEnd (libdwcutil.TWL.HYB.a(icon.o))
 *
 * symbols:
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   DWCi_OBJlDelete  0x021D6F38  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gIconWork  0x021DE558  data
 *   gMemIcon  0x021DE558  data
 */

#include "../include/G_MemIcon.h"

typedef struct MemIcon MemIcon;

extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_HEAPlFree_(void **mem);
extern struct MemIcon *gIconWork;
extern struct MemIcon *gMemIcon;

void DWCi_ICONlEnd(void)
{
    if (gIconWork == 0)
        return;
    DWCi_TSKlDeleteByIndex(0, gIconWork->task);
    DWCi_OBJlDelete(gIconWork->obj);
    DWCi_HEAPlFree_((void **)(&gMemIcon));
}
