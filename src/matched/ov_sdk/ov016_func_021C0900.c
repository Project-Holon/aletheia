/*
 * function: func_021C0900
 * address:  0x021C0900
 * packet:   pkt_ov016_021C0900
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AOSSlStart (libdwcutil.TWL.HYB.a libaoss.o)
 *
 * symbols:
 *   AOSSi_Init     0x021B61D0  thumb  ov016
 *   g_021DE564     0x021DE564  data
 */

#include "../include/G_AossCtl.h"

typedef struct AossWork {
    unsigned char pad0[0x116];
    unsigned char state;
} AossWork;

typedef struct AossCtl AossCtl;

extern int AOSSi_Init(AossWork *work);
extern struct AossCtl g_021DE564;

int func_021C0900(void)
{
    if (AOSSi_Init(g_021DE564.work) == 0) {
        g_021DE564.status = 1;
        return 1;
    }
    if (((AossWork *)g_021DE564.work)->state == 1 || (unsigned char)(((AossWork *)g_021DE564.work)->state + 0xFD) <= 2)
        return 0;
    return 2;
}
