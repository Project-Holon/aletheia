/*
 * function: DWCi_RemoveAllDWCGHTTPParamEntry
 * address:  0x021BFB20
 * packet:   pkt_ov114_021BFB20
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RemoveAllDWCGHTTPParamEntry (dwc_ghttp.o)
 *
 * symbols:
 *   DWC_Free    0x0205A1B0  arm
 *   gDwcGhttpParamList  0x021D3B20  data
 */

#include "../include/G_Init.h"

typedef struct Entry {
    char pad[0x14];
    void *data;
    int unk18;
    struct Entry *next;
} Entry;
typedef struct {
    int count;
    Entry *head;
} Init;
extern struct Init gDwcGhttpParamList;
extern void DWC_Free(int name, void *ptr, int size);

void DWCi_RemoveAllDWCGHTTPParamEntry(void)
{
    Entry *cursor;
    Entry *target;

    cursor = gDwcGhttpParamList.head;
    while (cursor != 0) {
        target = cursor;
        cursor = cursor->next;
        if (target->data != 0) {
            DWC_Free(6, target->data, 0);
        }
        DWC_Free(6, target, 0);
    }
    gDwcGhttpParamList.head = 0;
}
