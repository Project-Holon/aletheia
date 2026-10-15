/*
 * function: DWC_LoginAsync
 * address:  0x0216B0E0
 * packet:   pkt_ov009_0216B0E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   DWCi_IsError  0x02059F38  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   DWCi_WStrLen  0x021686E0  arm  ov009
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DWC_GetInetStatus  0x0205CA20  arm
 *   DWCi_StopLogin  0x0216A3B8  arm  ov009
 *   DWCi_SetState  0x0216BC84  arm  ov009
 *   GSIStartAvailableCheckA  0x0217C750  arm  ov009
 *   gDwcGlobalState     0x021AA878  data
 */

#include "../include/G_DwcGlobal.h"

typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0x24];
    int state;
    char pad28[8];
    u16 ingamesn[0x1a];
    char pad64[4];
    char *gamename;
    char pad6c[4];
    void (*callback)(int, int, void *);
    void *param;
} Ctl;

extern struct DwcGlobal gDwcGlobalState;

extern int DWCi_IsError(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int DWCi_WStrLen(unsigned short *p);
extern void MIi_CpuCopy16(void *srcp, void *destp, u32 size);
extern int DWC_GetInetStatus(void);
extern void DWCi_StopLogin(int error, int errorCode);
extern void DWCi_SetState(int state);
extern void GSIStartAvailableCheckA(char *gamename);

int DWC_LoginAsync(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param)
{
    u32 len;

    if (!ingamesn)
        return 0;
    if (DWCi_IsError() || ((Ctl *)gDwcGlobalState.st)->state != 0)
        return 0;
    ((Ctl *)gDwcGlobalState.st)->callback = callback;
    ((Ctl *)gDwcGlobalState.st)->param = param;
    if (!ingamesn || ingamesn[0] == 0) {
        len = 0;
    } else {
        MIi_CpuClear16(0, ((Ctl *)gDwcGlobalState.st)->ingamesn, 0x34);
        len = (u32)DWCi_WStrLen(ingamesn) > 25 ? 25 : (u32)DWCi_WStrLen(ingamesn);
        MIi_CpuCopy16(ingamesn, ((Ctl *)gDwcGlobalState.st)->ingamesn, len * 2);
    }
    ((Ctl *)gDwcGlobalState.st)->ingamesn[len] = 0;
    if (DWC_GetInetStatus() != 4) {
        DWCi_StopLogin(2, -60010);
        return 0;
    }
    DWCi_SetState(1);
    GSIStartAvailableCheckA(((Ctl *)gDwcGlobalState.st)->gamename);
    return 1;
}
