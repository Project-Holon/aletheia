/*
 * function: func_021C08B0
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
 *   func_021CFABC  0x021CFABC  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DE564     0x021DE564  data
 *   g_021DE568     0x021DE568  data
 */

#include "../include/G_AossCtl.h"

typedef struct AossWork {
    unsigned char pad0[0x116];
    unsigned char state;
    unsigned char area[1];
} AossWork;

typedef struct AossCtl AossCtl;

extern int AOSSi_EndLocal();
extern void func_021CFABC(void *area);
extern void func_021D6438(void **mem);
extern struct AossCtl g_021DE564;
extern void *g_021DE568;

void func_021C08B0(int a)
{
    AOSSi_EndLocal();
    if (a) {
        if (((AossWork *)g_021DE564.work)->state == 0 && g_021DE564.status == 1)
            func_021CFABC(((AossWork *)g_021DE564.work)->area);
    }
    func_021D6438(&g_021DE568);
}
