/*
 * function: func_021C7768
 * address:  0x021C7768
 * packet:   pkt_ov016_021C7768
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   DWCi_KB10lIsInit  0x021BF730  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   gMemSsea     0x021DE5E4  data
 *   func_021C77F4  0x021C77F4  arm  ov016
 *   func_021C7C74  0x021C7C74  arm  ov016
 *   func_021C79B4  0x021C79B4  arm  ov016
 */

#include "../include/G_MemSsea.h"

typedef struct MemSsea MemSsea;

extern int DWCi_KB10lIsInit();
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_WINlInitEx(int msg, int type, unsigned char dark, int n, int num);
extern void func_021C77F4();
extern void func_021C7C74();
extern void func_021C79B4();
extern struct MemSsea *gMemSsea;

void func_021C7768(void)
{
    int r;

    if (DWCi_KB10lIsInit())
        return;
    r = gMemSsea->result;
    if (r == 0) {
        DWCi_ChangeScene((unsigned int)func_021C77F4);
    } else if (r == 2) {
        DWCi_WINlInitEx(6, 3, 1, -1, 0);
        DWCi_ChangeScene((unsigned int)func_021C7C74);
    } else {
        DWCi_WINlInitEx(0x47, 2, 1, -1, 0);
        DWCi_ChangeScene((unsigned int)func_021C79B4);
    }
}
