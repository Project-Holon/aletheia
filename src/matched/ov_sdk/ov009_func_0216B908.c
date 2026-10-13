/*
 * function: DWC_GetAIDBitmap
 * address:  0x0216B908
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWC_GetAIDBitmap: the bitmap of every aid in the current node list.
 *
 * symbols:
 *   g_021AA878  0x021AA878  data
 *   DWCi_IsGetAIDValid  0x0216C82C  arm  ov009
 *   DWC_GetAIDList  0x0216B880  arm  ov009
 *   DWCi_GetAIDBitmapFromList  0x0216BCD0  arm  ov009
 */

#include "../include/G_DwcGlobal.h"

extern struct DwcGlobal g_021AA878;
extern int DWCi_IsGetAIDValid(void);
extern int DWC_GetAIDList(unsigned char **out);
extern int DWCi_GetAIDBitmapFromList(unsigned char *p, int n);

int DWC_GetAIDBitmap(void)
{
    unsigned char *list;
    int n;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0;
    }
    n = DWC_GetAIDList(&list);
    return DWCi_GetAIDBitmapFromList(list, n);
}
