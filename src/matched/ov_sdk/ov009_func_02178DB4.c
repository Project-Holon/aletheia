/*
 * function: DWCi_Auth_ProcessAuthentication
 * address:  0x02178DB4
 * packet:   pkt_ov009_02178DB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_ProcessAuthentication (dwc_auth_interface.o)
 *
 * symbols:
 *   DWC_Auth_GetError  0x021781DC  arm  ov009
 *   DWC_Auth_GetResult  0x02178224  arm  ov009
 *   DWC_Auth_Destroy  0x02178144  arm  ov009
 *   DWCi_Auth_InitAdapterParam  0x02178CE0  arm  ov009
 *   DWC_Auth_Create  0x02177EE8  arm  ov009
 *   gDwcAuthParam     0x021AB1C0  data
 *   gDwcAuthResultBuf     0x021AB208  data
 *   gDwcAuthState     0x021AB1A4  data
 */

#include "../include/G_DWCAuthState.h"
#include "../include/G_DWCAuthParam.h"

typedef struct {
    int code;
    char pad[0x1c0];
} AuthResult;

extern struct DWCAuthParam gDwcAuthParam;
extern char gDwcAuthResultBuf[];
extern struct DWCAuthState gDwcAuthState;
extern int DWC_Auth_GetError(void);
struct DWCAuthParam;
extern void DWC_Auth_GetResult(int *result);
extern void DWC_Auth_Destroy(void);
extern void DWCi_Auth_InitAdapterParam(void);
extern int DWC_Auth_Create(struct DWCAuthParam *param, void *http);

void DWCi_Auth_ProcessAuthentication(void)
{
    int authError;
    int returnCode;

    authError = DWC_Auth_GetError();
    if (authError == 0x15) {
        AuthResult result;
        DWC_Auth_GetResult((int *)(&result));
        if (result.code == 0x4e22) {
            DWC_Auth_Destroy();
            DWCi_Auth_InitAdapterParam();
            if (DWC_Auth_Create((struct DWCAuthParam *)((char *)&gDwcAuthParam), gDwcAuthResultBuf) == 0) {
                return;
            }
            returnCode = -20100;
        } else {
            gDwcAuthState.s_finished = 1;
            gDwcAuthState.state = 1;
            return;
        }
    } else {
        AuthResult result;
        if (authError == 0) {
            return;
        }
        DWC_Auth_GetResult((int *)(&result));
        DWC_Auth_Destroy();
        returnCode = result.code;
    }
    gDwcAuthState.s_finished = 1;
    gDwcAuthState.state = 0;
    gDwcAuthState.returnCode = returnCode;
}
