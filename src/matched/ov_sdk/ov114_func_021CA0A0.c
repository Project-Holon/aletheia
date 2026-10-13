/*
 * function: DWCi_EncSessionProcess
 * address:  0x021CA0A0
 * packet:   pkt_ov114_021CA0A0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The ProgressCallback pointer 0x021C9B60 (DWCi_EncSessionProgressCallback) was the
 * last blocker; it now has a catalog row and a matched body (w3_tools, 2026-09-29).
 *
 * sdk:      DWCi_EncSessionProcess (dwc_encsession.o)
 *
 * symbols:
 *   DWC_GetGHTTPDataEx  0x021BF6C4  arm  ov114
 *   DWC_ProcessGHTTP  0x021BF5B8  arm  ov114
 *   DWCi_EncSetError  0x021CA06C  arm  ov114
 *   DWCi_EncSessionCompleteCallback  0x021C9B64  arm  ov114
 *   DWCi_EncSessionProgressCallback  0x021C9B60  arm  ov114
 *   gDwcEncSession     0x021CF7AC  data
 */

#include "../include/G_Session.h"

typedef struct {
    int state;
    int active;
    int result;
    char pad0[0x48];
    char *buf;
} Session;
extern struct Session gDwcEncSession;
extern int DWC_GetGHTTPDataEx(char *url, int bufferlen, int buffer_clear, void (*progress)(void), void (*completed)(void), void *param);
extern int DWC_ProcessGHTTP(void);
extern void DWCi_EncSetError(void);
extern void DWCi_EncSessionCompleteCallback(char *buf, int len, int result);
extern void DWCi_EncSessionProgressCallback(void);

int DWCi_EncSessionProcess(void)
{
    switch (gDwcEncSession.state) {
    case 1:
        DWCi_EncSetError();
        break;
    case 4:
        gDwcEncSession.reqid = DWC_GetGHTTPDataEx(gDwcEncSession.request, 0, 0, DWCi_EncSessionProgressCallback, (void (*)(void))DWCi_EncSessionCompleteCallback, 0);
        if (gDwcEncSession.reqid >= 0) {
            gDwcEncSession.state = 5;
        } else {
            DWCi_EncSetError();
        }
        break;
    case 5:
        if (DWC_ProcessGHTTP() == 0) {
            DWCi_EncSetError();
        }
        break;
    case 6:
        gDwcEncSession.reqid = DWC_GetGHTTPDataEx(gDwcEncSession.request, 0, 0, DWCi_EncSessionProgressCallback, (void (*)(void))DWCi_EncSessionCompleteCallback, 0);
        if (gDwcEncSession.reqid >= 0) {
            gDwcEncSession.state = 7;
        } else {
            DWCi_EncSetError();
        }
        break;
    case 7:
        if (DWC_ProcessGHTTP() == 0) {
            DWCi_EncSetError();
        }
        break;
    case 8:
        break;
    }
    return gDwcEncSession.state;
}
