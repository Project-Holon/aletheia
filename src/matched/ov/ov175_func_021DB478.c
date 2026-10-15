/*
 * function: WIFIBATTLEMATCH_NET_GdbGetMyRecords
 * address:  0x021DB478
 * packet:   pkt_021DB478
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_GdbInitialize         0x021E10CC  arm
 *   DWC_GdbGetMyRecordsAsync  0x021E1618  arm
 *   DWC_GdbGetRecordsAsync    0x021E16F0  arm
 *   DWC_GdbProcess            0x021E1414  arm
 *   DWC_GdbGetState           0x021E1434  arm
 *   DWC_GdbGetAsyncResult     0x021E1454  arm
 *   DWC_GdbCancelRequest      0x021E11F0  arm
 *   WIFIBATTLEMATCH_NET_SetErrorA             0x021DCE08  thumb
 *   WIFIBATTLEMATCH_NET_SetResultA             0x021DCE40  thumb
 *   WIFIBATTLEMATCH_NET_SetResultB             0x021DCE48  thumb
 *   WIFIBATTLEMATCH_NET_SetResultC             0x021DCE50  thumb
 *   WIFIBATTLEMATCH_NET_GdbShutdown             0x021DB6A0  thumb
 *   WIFIBATTLEMATCH_NET_GdbSortByName             0x021DB72C  thumb
 *   func_02034714             0x02034714  arm
 *   d_021E2EF8                0x021E2EF8  data
 *   d_021E2F1C                0x021E2F1C  data
 *
 * Storage-server record download step (state at +0x12c): initialises the database client, requests our records (or the one record id at +0x1b0), polls with a 3600-tick timeout, collects the result and shuts the client down; returns 1 when done, 2 on error (the error and its source line go to +0x18), 0 while running.
 */
#include "../include/Obj00840.h"

typedef unsigned long u32;

extern int DWC_GdbInitialize(u32 gameId, u32 user, int ssl);
extern int DWC_GdbGetMyRecordsAsync(const char *table, void *fields, int nfields, void *cb, void *param);
extern int DWC_GdbGetRecordsAsync(const char *table, int *ids, int nids, void *fields, int nfields, void *cb, void *param);
extern void DWC_GdbProcess(void);
extern int DWC_GdbGetState(void);
extern int DWC_GdbGetAsyncResult(void);
extern int DWC_GdbCancelRequest(void);
extern void WIFIBATTLEMATCH_NET_SetErrorA(char *ctx, u32 v, int line);
extern void WIFIBATTLEMATCH_NET_SetResultA(char *ctx, u32 v, int line);
extern void WIFIBATTLEMATCH_NET_SetResultB(char *ctx, u32 v, int line);
extern void WIFIBATTLEMATCH_NET_SetResultC(char *ctx, u32 v, int line);
extern void WIFIBATTLEMATCH_NET_GdbShutdown(char *obj);
struct Field;
extern void WIFIBATTLEMATCH_NET_GdbSortByName(int count, struct Field **recs, char *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[];
extern const char d_021E2F1C[];

int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *obj)
{
    int r;

    switch (((struct Obj00840 *)obj)->f12C) {
    case 0:
        r = DWC_GdbInitialize(0xb5f, ((struct Obj00840 *)obj)->f0, 0);
        if (r != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(obj + 0x18, r, 0xdef);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        ((struct Obj00840 *)obj)->f12C = 1;
        break;
    case 1:
        if (((struct Obj00840 *)obj)->f198 >= 0x26)
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
        if (((struct Obj00840 *)obj)->f1B0 == -1)
            r = DWC_GdbGetMyRecordsAsync(d_021E2F1C, ((struct Obj00840 *)obj)->f194, ((struct Obj00840 *)obj)->f198, WIFIBATTLEMATCH_NET_GdbSortByName, obj);
        else
            r = DWC_GdbGetRecordsAsync(d_021E2F1C, (int *)(obj + 0x1b0), 1, ((struct Obj00840 *)obj)->f194, ((struct Obj00840 *)obj)->f198, WIFIBATTLEMATCH_NET_GdbSortByName, obj);
        if (r != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(obj + 0x18, r, 0xe0a);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        ((struct Obj00840 *)obj)->f12C = 2;
        ((struct Obj00840 *)obj)->f1A0 = 0;
        break;
    case 2:
        if ((((struct Obj00840 *)obj)->f1A0)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(obj + 0x18, 1, 0xe17);
            ((struct Obj00840 *)obj)->f12C = 6;
            break;
        }
        DWC_GdbProcess();
        r = DWC_GdbGetState();
        if (r == 0 || r == 4) {
            WIFIBATTLEMATCH_NET_SetResultB(obj + 0x18, r, 0xe26);
            ((struct Obj00840 *)obj)->f12C = 6;
        } else if (r == 1) {
            ((struct Obj00840 *)obj)->f12C = 3;
        }
        break;
    case 3:
        r = DWC_GdbGetAsyncResult();
        if (r == 0) {
            WIFIBATTLEMATCH_NET_SetResultC(obj + 0x18, r, 0xe39);
            ((struct Obj00840 *)obj)->f12C = 6;
        } else if (r != 1) {
            WIFIBATTLEMATCH_NET_SetResultC(obj + 0x18, r, 0xe3f);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        } else {
            ((struct Obj00840 *)obj)->f12C = 4;
        }
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(obj);
        ((struct Obj00840 *)obj)->f12C = 5;
        break;
    case 5:
        return 1;
    case 6:
        r = DWC_GdbCancelRequest();
        if (r == 0) {
            ((struct Obj00840 *)obj)->f1A0 = 0;
            ((struct Obj00840 *)obj)->f12C = 7;
        } else {
            WIFIBATTLEMATCH_NET_SetResultA(obj + 0x18, r, 0xe5e);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        break;
    case 7:
        if ((((struct Obj00840 *)obj)->f1A0)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(obj + 0x18, 1, 0xe6a);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        DWC_GdbProcess();
        r = DWC_GdbGetState();
        if (r == 0 || r == 4) {
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        if (r == 1)
            ((struct Obj00840 *)obj)->f12C = 8;
        break;
    case 8:
        WIFIBATTLEMATCH_NET_GdbShutdown(obj);
        return 2;
    }
    return 0;
}
