/*
 * function: func_0217C104
 * address:  0x0217C104
 * packet:   pkt_ov009_0217C104
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Svl_Cleanup (dwc_svl.o)
 *
 * symbols:
 *   func_02179CF4  0x02179CF4  arm  ov009
 *   g_021ACEF4     0x021ACEF4  data
 */

#include "../../../matched/include/G_Svl.h"

typedef struct {
    int unk0;
    void (*free)(unsigned long, void *, long);
} Svl;
extern struct Svl *g_021ACEF4;
extern void func_02179CF4(char *http);

void func_0217C104(void)
{
    if (g_021ACEF4 == 0) {
        return;
    }
    func_02179CF4((char *)g_021ACEF4 + 8);
    g_021ACEF4->free(0, g_021ACEF4, 0);
    g_021ACEF4 = 0;
}
