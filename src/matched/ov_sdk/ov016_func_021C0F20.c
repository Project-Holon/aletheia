/*
 * function: func_021C0F20
 * address:  0x021C0F20
 * packet:   pkt_ov016_021C0F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      kDWCi_Language (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   gDwcutilMainWork     0x021DE56C  data
 */

#include "../include/G_UtilState.h"

extern struct UtilState gDwcutilMainWork;

unsigned char func_021C0F20(void)
{
    if ((*(unsigned char *)&gDwcutilMainWork) == 6)
        return 0x38;
    if ((*(unsigned char *)&gDwcutilMainWork) == 1) {
        if (!((*(unsigned int *)((char *)&(*(unsigned char *)&gDwcutilMainWork) + 8) >> 4) & 2))
            return 0x37;
    }
    return (*(unsigned char *)&gDwcutilMainWork) + 0x31;
}
