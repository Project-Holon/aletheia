/*
 * function: DWC_GdbCreateRecordAsync
 * address:  0x021E1464
 * packet:   pkt_ov175_021E1464
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GdbCreateRecordAsync (dwc_gdb.o)
 *
 * symbols:
 *   DWCi_GdbCheckStateForAsyncProcess  0x021E1830  arm  ov175
 *   DWCi_GdbSwitchWork  0x021E214C  arm  ov175
 *   sakeCreateRecord  0x021DD358  arm  ov175
 *   sakeGetStartRequestResult  0x021DD2CC  arm  ov175
 *   DWCi_GdbPrintf  0x021E17D8  arm  ov175
 *   DWCi_GdbHandleStartRequestResult  0x021E1F18  arm  ov175
 *   DWCi_GdbSetAsyncStatus  0x021E212C  arm  ov175
 *   DWCi_GdbSakeRequestCallback  0x021E1948  arm  ov175
 *   gDwcGdbEntity     0x021E5334  data
 *   g_021E534C     0x021E534C  data
 *   sDwcGdbCreateRecordFailed  0x021E45BC  data
 */

#include "../include/G_021E534C.h"

typedef struct {
    void *request;
    void *a;
    void *b;
    void *c;
    void *d;
    char pad[0x24];
} Work;
typedef struct {
    int unk0;
    void *sake;
    int unk8;
    int unkc;
    int unk10;
    int index;
} Tbl;
extern Tbl gDwcGdbEntity;
extern struct G_021E534C g_021E534C[];
extern char sDwcGdbCreateRecordFailed[];
extern int DWCi_GdbCheckStateForAsyncProcess(int *result);
extern void DWCi_GdbSwitchWork(void);
extern void *sakeCreateRecord(void *sake, void *input, void (*callback)(void), void *userData);
typedef unsigned int   u32;
extern u32 sakeGetStartRequestResult(char *obj);
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int DWCi_GdbHandleStartRequestResult(int process, int result);
extern void DWCi_GdbSetAsyncStatus(u32 v);
extern void DWCi_GdbSakeRequestCallback(void *sake, void *request, int result, void *inputData, void *outputData, void *userData);

int DWC_GdbCreateRecordAsync(char *gdb_name, void *fields, int field_num, int *record_id)
{
    int result;
    void *request;
    Work *work;

    if (DWCi_GdbCheckStateForAsyncProcess(&result) != 0) {
        return result;
    }
    DWCi_GdbSwitchWork();
    work = &((Work *)g_021E534C)[gDwcGdbEntity.index];
    work->a = gdb_name;
    work->b = fields;
    work->c = (void *)field_num;
    work->d = record_id;
    request = sakeCreateRecord(gDwcGdbEntity.sake, &work->a, (void (*)(void))DWCi_GdbSakeRequestCallback, 0);
    if (request == 0) {
        int sake_result = sakeGetStartRequestResult(gDwcGdbEntity.sake);
        DWCi_GdbPrintf(0x22f, sDwcGdbCreateRecordFailed, sake_result);
        return DWCi_GdbHandleStartRequestResult(2, sake_result);
    }
    g_021E534C[gDwcGdbEntity.index].request = request;
    DWCi_GdbSetAsyncStatus(2);
    return 0;
}
