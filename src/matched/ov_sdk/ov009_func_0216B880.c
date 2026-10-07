/*
 * function: func_0216B880
 * address:  0x0216B880
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetAIDList: fills the static aid list from the node list and returns the node count.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   g_021AA880  0x021AA880  data
 *   func_0216C82C  0x0216C82C  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern unsigned char g_021AA880[];
extern int func_0216C82C(void);
extern void MI_CpuFill8(void *p, int v, int n);
extern int func_0217603C(void);
extern unsigned char *func_0217637C(int index);

int func_0216B880(unsigned char **out)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0;
    }
    MI_CpuFill8(g_021AA880, 0, 0x20);
    for (i = 0; i < func_0217603C(); i++) {
        g_021AA880[i] = func_0217637C(i)[0x16];
    }
    *out = g_021AA880;
    return func_0217603C();
}
