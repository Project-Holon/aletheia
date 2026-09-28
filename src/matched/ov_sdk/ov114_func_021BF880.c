/*
 * function: func_021BF880
 * address:  0x021BF880
 * packet:   pkt_ov114_021BF880
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_CancelGHTTPRequest (dwc_ghttp.o)
 *
 * symbols:
 *   func_021C22A4  0x021C22A4  arm  ov114
 *   func_021BFAF0  0x021BFAF0  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   func_021BFA70  0x021BFA70  arm  ov114
 */

typedef struct {
    char pad[0x14];
    void *data;
} Entry;
extern void func_021C22A4(int request);
extern Entry *func_021BFAF0(int req);
extern void DWC_Free(int name, void *ptr, int size);
extern void func_021BFA70(Entry *entry);

void func_021BF880(int req)
{
    Entry *entry;

    func_021C22A4(req);
    entry = func_021BFAF0(req);
    if (entry == 0) {
        return;
    }
    if (entry->data != 0) {
        DWC_Free(6, entry->data, 0);
    }
    func_021BFA70(entry);
}
