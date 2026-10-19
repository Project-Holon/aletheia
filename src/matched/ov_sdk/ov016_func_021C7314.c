/*
 * function: procInit1
 * address:  0x021C7314
 * packet:   pkt_ov016_021C7314
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_KB10lInit  0x021BF390  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_KB10lSetErase  0x021BF6F4  arm  ov016
 *   func_021C7690  0x021C7690  arm  ov016
 *   DWCi_KB10lSetInput  0x021BF708  arm  ov016
 *   DWCi_KB10lSetShift  0x021BF71C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gMemSsea     0x021DE5E4  data
 *   func_021C73A0  0x021C73A0  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern int DWCi_EFFlCheck();
extern void DWCi_KB10lInit();
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_KB10lSetErase(unsigned char v);
extern int func_021C7690(int val);
extern void DWCi_KB10lSetInput(unsigned char v);
extern void DWCi_KB10lSetShift(unsigned char v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C73A0();
extern struct MemSsea *gMemSsea;

void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_KB10lInit();
    DWCi_SNDlPlay(0x14);
    if (gMemSsea->pos == 0) {
        DWCi_KB10lSetErase(0);
        DWCi_KB10lSetShift(0);
    } else {
        if (func_021C7690(0x1A))
            DWCi_KB10lSetInput(0);
        DWCi_KB10lSetShift(0);
    }
    DWCi_ChangeScene((unsigned int)func_021C73A0);
}
