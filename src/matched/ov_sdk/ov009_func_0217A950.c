/*
 * function: DWC_Netcheck_Destroy
 * address:  0x0217A950
 * packet:   pkt_ov009_0217A950
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Netcheck_Destroy (dwc_netcheck.o)
 *
 * symbols:
 *   DWC_Http_Destroy  0x02179CF4  arm  ov009
 *   DWC_Auth_Destroy  0x02178144  arm  ov009
 *   g_021ACE5C     0x021ACE5C  data
 */

#include "../include/G_G.h"

typedef struct {
    void *http;
    char *nc;
} G;
extern struct G g_021ACE5C;
extern void DWC_Http_Destroy(char *http);
extern void DWC_Auth_Destroy(void);

void DWC_Netcheck_Destroy(void)
{
    void (*free)(unsigned long, void *, long) =
        *(void (**)(unsigned long, void *, long))(g_021ACE5C.nc + 0x110c);

    if (g_021ACE5C.http != 0) {
        DWC_Http_Destroy(g_021ACE5C.http);
        free(0, g_021ACE5C.http, 0);
        g_021ACE5C.http = 0;
    }
    DWC_Auth_Destroy();
    if (g_021ACE5C.nc == 0) {
        return;
    }
    if (*(void **)(g_021ACE5C.nc + 0x1114) != 0) {
        free(0, *(void **)(g_021ACE5C.nc + 0x1114), 0);
        *(void **)(g_021ACE5C.nc + 0x1114) = 0;
    }
    if (*(void **)(g_021ACE5C.nc + 0x1118) != 0) {
        free(0, *(void **)(g_021ACE5C.nc + 0x1118), 0);
        *(void **)(g_021ACE5C.nc + 0x1118) = 0;
    }
    free(0, g_021ACE5C.nc, 0);
    g_021ACE5C.nc = 0;
}
