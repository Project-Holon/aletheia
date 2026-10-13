/*
 * function: DWC_GdbGetRecordsAsync
 * address:  0x021E16F0
 * packet:   pkt_ov175_021E16F0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GdbGetRecordsAsync (dwc_gdb.o)
 *
 * symbols:
 *   DWCi_GdbCheckStateForAsyncProcess  0x021E1830  arm  ov175
 *   DWCi_GdbSwitchWork  0x021E214C  arm  ov175
 *   sakeGetSpecificRecords  0x021DD3D0  arm  ov175
 *   sakeGetStartRequestResult  0x021DD2CC  arm  ov175
 *   DWCi_GdbPrintf  0x021E17D8  arm  ov175
 *   DWCi_GdbHandleStartRequestResult  0x021E1F18  arm  ov175
 *   DWCi_GdbSetAsyncStatus  0x021E212C  arm  ov175
 *   DWCi_GdbSakeRequestCallback  0x021E1948  arm  ov175
 *   gDwcGdbEntity     0x021E5334  data
 *   g_021E534C     0x021E534C  data
 *   sDwcGdbGetSpecificRecordsFailed  0x021E461C  data
 */

#include "../include/G_021E534C.h"

typedef struct {
    void *request;
    void *a;
    void *b;
    void *c;
    void *d;
    void *e;
    void *f;
    char pad[0x1c];
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
extern char sDwcGdbGetSpecificRecordsFailed[];
extern int DWCi_GdbCheckStateForAsyncProcess(int *result);
extern void DWCi_GdbSwitchWork(void);
extern void *sakeGetSpecificRecords(void *sake, void *input, void (*callback)(void), void *userData);
typedef unsigned int   u32;
extern u32 sakeGetStartRequestResult(char *obj);
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int DWCi_GdbHandleStartRequestResult(int process, int result);
extern void DWCi_GdbSetAsyncStatus(u32 v);
extern void DWCi_GdbSakeRequestCallback(void *sake, void *request, int result, void *inputData, void *outputData, void *userData);

int DWC_GdbGetRecordsAsync(char *gdb_name, int *record_ids, int record_num, char **field_names, int field_num, void (*callback)(int, void **, void *), void *user_param)
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
    work->b = record_ids;
    work->c = (void *)record_num;
    work->d = field_names;
    work->e = (void *)field_num;
    work->f = callback;
    request = sakeGetSpecificRecords(gDwcGdbEntity.sake, &work->a, (void (*)(void))DWCi_GdbSakeRequestCallback, user_param);
    if (request == 0) {
        int sake_result = sakeGetStartRequestResult(gDwcGdbEntity.sake);
        DWCi_GdbPrintf(0x3ca, sDwcGdbGetSpecificRecordsFailed, sake_result);
        return DWCi_GdbHandleStartRequestResult(9, sake_result);
    }
    g_021E534C[gDwcGdbEntity.index].request = request;
    DWCi_GdbSetAsyncStatus(9);
    return 0;
}
