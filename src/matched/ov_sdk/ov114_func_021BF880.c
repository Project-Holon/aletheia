/*
 * function: DWC_CancelGHTTPRequest
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
 *   ghttpCancelRequest  0x021C22A4  arm  ov114
 *   DWCi_FindDWCGHTTPParamEntryByReq  0x021BFAF0  arm  ov114
 *   DWC_Free       0x0205A1B0  arm
 *   DWCi_RemoveDWCGHTTPParamEntry  0x021BFA70  arm  ov114
 */

typedef struct {
    char pad[0x14];
    void *data;
} Entry;
extern void ghttpCancelRequest(int request);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Node;
extern u8 *DWCi_FindDWCGHTTPParamEntryByReq(u32 key);
extern void DWC_Free(int name, void *ptr, int size);
extern void DWCi_RemoveDWCGHTTPParamEntry(struct Node *x);

void DWC_CancelGHTTPRequest(int req)
{
    Entry *entry;

    ghttpCancelRequest(req);
    entry = (Entry *)DWCi_FindDWCGHTTPParamEntryByReq(req);
    if (entry == 0) {
        return;
    }
    if (entry->data != 0) {
        DWC_Free(6, entry->data, 0);
    }
    DWCi_RemoveDWCGHTTPParamEntry((struct Node *)entry);
}
