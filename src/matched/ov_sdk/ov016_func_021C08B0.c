/*
 * function: DWCi_AOSSlEnd
 * address:  0x021C08B0
 * packet:   pkt_ov016_021C08B0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AOSSlEnd (libdwcutil.TWL.HYB.a libaoss.o)
 *
 * symbols:
 *   AOSSi_EndLocal 0x021B85A8  thumb  ov016
 *   DWCi_SETTINGlSetAoss  0x021CFABC  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gLibaossBlock1     0x021DE564  data
 *   gLibaossBlock2     0x021DE568  data
 */

#include "../include/G_AossCtl.h"

typedef struct AossWork {
    unsigned char pad0[0x116];
    unsigned char state;
    unsigned char area[1];
} AossWork;

typedef struct AossCtl AossCtl;

extern int AOSSi_EndLocal();
extern void DWCi_SETTINGlSetAoss(void *area);
extern void DWCi_HEAPlFree_(void **mem);
extern struct AossCtl gLibaossBlock1;
extern void *gLibaossBlock2;

void DWCi_AOSSlEnd(int a)
{
    AOSSi_EndLocal();
    if (a) {
        if (((AossWork *)gLibaossBlock1.work)->state == 0 && gLibaossBlock1.status == 1)
            DWCi_SETTINGlSetAoss(((AossWork *)gLibaossBlock1.work)->area);
    }
    DWCi_HEAPlFree_(&gLibaossBlock2);
}
