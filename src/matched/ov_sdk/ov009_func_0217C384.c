/*
 * function: func_0217C384
 * address:  0x0217C384
 * packet:   pkt_ov009_0217C384
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Svl_Process (dwc_svl.o)
 *
 * symbols:
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   func_0217C448          0x0217C448  arm  ov009
 *   DWC_Http_Destroy          0x02179CF4  arm  ov009
 *   DWCi_SetError          0x02059F54  arm
 *   g_021ACEF4             0x021ACEF4  data
 */

#include "../include/G_Svl.h"

typedef struct {
    int unk0;
    void (*free)(unsigned long, void *, long);
} Svl;
extern struct Svl *g_021ACEF4;
extern int OS_IsThreadTerminated(void *thread);
extern int func_0217C448(void);
extern void DWC_Http_Destroy(char *http);
extern void DWCi_SetError(int error, int code);

int func_0217C384(void)
{
    if (g_021ACEF4 == 0) {
        return 0;
    }
    if (*(int *)((char *)g_021ACEF4 + 0x1be8) == 0) {
        return 1;
    }
    if (OS_IsThreadTerminated((char *)g_021ACEF4 + 0x1b7c) == 1) {
        switch (*(int *)((char *)g_021ACEF4 + 0x1028)) {
        case 8:
            if (func_0217C448() == 0) {
                DWC_Http_Destroy((char *)g_021ACEF4 + 8);
                return 4;
            }
            DWC_Http_Destroy((char *)g_021ACEF4 + 8);
            return 3;
        case 7:
            DWC_Http_Destroy((char *)g_021ACEF4 + 8);
            return 5;
        default:
            DWC_Http_Destroy((char *)g_021ACEF4 + 8);
            DWCi_SetError(0x10, -24101);
            return 4;
        }
    }
    return 2;
}
