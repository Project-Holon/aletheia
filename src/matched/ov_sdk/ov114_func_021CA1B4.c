/*
 * function: func_021CA1B4
 * address:  0x021CA1B4
 * packet:   pkt_ov114_021CA1B4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_EncSessionShutdown (dwc_encsession.o)
 *
 * symbols:
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_GsFree    0x0205A29C  arm
 *   func_021BF57C  0x021BF57C  arm  ov114
 *   g_021CF7AC     0x021CF7AC  data
 */

#include "../include/G_Session.h"

typedef struct {
    int state;
    int active;
    char pad0[0x4c];
    void *buf;
    char pad1[8];
    void *gs;
    void *gs2;
} Session;
extern struct Session g_021CF7AC;
extern void DWC_Free(int name, void *ptr, int size);
extern void DWCi_GsFree(void *ptr);
extern int func_021BF57C(void);

void func_021CA1B4(void)
{
    if (g_021CF7AC.isinitialized == 0) {
        return;
    }
    if (g_021CF7AC.request != 0) {
        DWC_Free(8, g_021CF7AC.request, 0);
        g_021CF7AC.request = 0;
    }
    if (g_021CF7AC.resbuf != 0) {
        DWCi_GsFree(g_021CF7AC.resbuf);
        g_021CF7AC.resbuflen = 0;
        g_021CF7AC.resbuf = 0;
    }
    func_021BF57C();
    g_021CF7AC.state = 2;
    g_021CF7AC.isinitialized = 0;
}
