/*
 * function: func_021BFA08
 * address:  0x021BFA08
 * packet:   pkt_ov114_021BFA08
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AppendDWCGHTTPParam (dwc_ghttp.o)
 *
 * symbols:
 *   DWC_Alloc   0x0205A16C  arm
 *   g_021D3B20  0x021D3B20  data
 */

#include "../include/G_Init.h"

typedef struct {
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
} Param;
typedef struct Entry {
    Param param;
    void *data;
    int unk18;
    struct Entry *next;
} Entry;
typedef struct {
    int count;
    Entry *head;
} Init;
extern struct Init g_021D3B20;
extern void *DWC_Alloc(int name, unsigned long size);

Entry *func_021BFA08(Param *param)
{
    Entry *entry;

    entry = DWC_Alloc(6, 0x20);
    if (entry == 0) {
        return 0;
    }
    entry->param = *param;
    entry->next = 0;
    entry->data = 0;
    if (g_021D3B20.head == 0) {
        g_021D3B20.head = entry;
        return entry;
    }
    entry->next = g_021D3B20.head;
    g_021D3B20.head = entry;
    return entry;
}
