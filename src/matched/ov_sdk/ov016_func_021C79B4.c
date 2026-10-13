/*
 * function: func_021C79B4
 * address:  0x021C79B4
 * packet:   pkt_ov016_021C79B4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWin (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   DWCi_WINlGet  0x021D1568  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_WINlEnd  0x021D1524  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gMemSsea     0x021DE5E4  data
 *   func_021C7A0C  0x021C7A0C  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern signed char DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlEnd();
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C7A0C();
extern struct MemSsea *gMemSsea;

void func_021C79B4(void)
{
    gMemSsea->result = DWCi_WINlGet();
    switch (gMemSsea->result) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(0xE);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene((unsigned int)func_021C7A0C);
}
