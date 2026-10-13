/*
 * file:     dwc_auth_interface_3.c
 * function: func_02178DB4
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
 *   func_021781DC  0x021781DC  arm  ov009
 *   func_02178224  0x02178224  arm  ov009
 *   func_02178144  0x02178144  arm  ov009
 *   func_02178CE0  0x02178CE0  arm  ov009
 *   func_02177EE8  0x02177EE8  arm  ov009
 *   g_021AB1C0     0x021AB1C0  data
 *   g_021AB208     0x021AB208  data
 *   g_021AB1A4     0x021AB1A4  data
 */

#include "../../matched/include/G_DWCAuthState.h"
#include "../../matched/include/G_DWCAuthParam.h"

typedef struct {
    int code;
    char pad[0x1c0];
} AuthResult;

extern struct DWCAuthParam g_021AB1C0;
extern char g_021AB208[];
extern struct DWCAuthState g_021AB1A4;
extern int func_021781DC(void);
struct DWCAuthParam;
extern void func_02178224(int *result);
extern void func_02178144(void);
extern void func_02178CE0(void);
extern int func_02177EE8(struct DWCAuthParam *param, void *http);

void func_02178DB4(void)
{
    int authError;
    int returnCode;

    authError = func_021781DC();
    if (authError == 0x15) {
        AuthResult result;
        func_02178224((int *)(&result));
        if (result.code == 0x4e22) {
            func_02178144();
            func_02178CE0();
            if (func_02177EE8((struct DWCAuthParam *)((char *)&g_021AB1C0), g_021AB208) == 0) {
                return;
            }
            returnCode = -20100;
        } else {
            g_021AB1A4.s_finished = 1;
            g_021AB1A4.state = 1;
            return;
        }
    } else {
        AuthResult result;
        if (authError == 0) {
            return;
        }
        func_02178224((int *)(&result));
        func_02178144();
        returnCode = result.code;
    }
    g_021AB1A4.s_finished = 1;
    g_021AB1A4.state = 0;
    g_021AB1A4.returnCode = returnCode;
}
