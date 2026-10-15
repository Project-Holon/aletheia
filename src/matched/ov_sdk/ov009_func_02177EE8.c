/*
 * function: DWC_Auth_Create
 * address:  0x02177EE8
 * packet:   pkt_ov009_02177EE8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_Create (libdwcauth.TWL.HYB.a dwc_auth.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   DWCi_Auth_Start  0x021782B4  arm  ov009
 *   DWCi_Auth_StartThread  0x02177FFC  arm  ov009
 *   gDwcAuthGlobal  0x021AB184  data  ov009
 */

#include "../include/G_DWCWFCUtil.h"

typedef struct DWCAuthParam
{
    unsigned short ingamesn[26];
    char gsbrcd[12];
    void *(*alloc)(unsigned long name, long size);
    void (*free)(unsigned long name, void *ptr, long size);
} DWCAuthParam;

typedef struct DWCAuth
{
    char pad0[0x1004];
    int result;
    int error;
    char pad100c[0x11cc - 0x100c];
    DWCAuthParam param;
    char pad1214[0x1314 - 0x1214];
    void *http;
    char pad1318[0x13f4 - 0x1318];
} DWCAuth;

typedef struct DWCWFCUtil DWCWFCUtil;

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int DWCi_Auth_Start(int getwifiinfofromflash);
extern void DWCi_Auth_StartThread(void);

extern struct DWCWFCUtil gDwcAuthGlobal;

int DWC_Auth_Create(DWCAuthParam *param, void *http)
{
    void *(*alloc)(unsigned long, long) = param->alloc;

    if (gDwcAuthGlobal.auth != 0)
        return 2;
    gDwcAuthGlobal.auth = (DWCAuth *)alloc(0, sizeof(DWCAuth));
    if (gDwcAuthGlobal.auth == 0)
        return 2;
    MI_CpuFill8(gDwcAuthGlobal.auth, 0, sizeof(DWCAuth));
    ((DWCAuth *)gDwcAuthGlobal.auth)->http = http;
    gDwcAuthGlobal.state = 0;
    MI_CpuFill8((char *)((DWCAuth *)gDwcAuthGlobal.auth) + 0x1008, 0, 0x1c4);
    ((DWCAuth *)gDwcAuthGlobal.auth)->error = 20100;
    ((DWCAuth *)gDwcAuthGlobal.auth)->param = *param;
    ((DWCAuth *)gDwcAuthGlobal.auth)->param.ingamesn[25] = 0;
    ((DWCAuth *)gDwcAuthGlobal.auth)->param.gsbrcd[11] = 0;
    ((DWCAuth *)gDwcAuthGlobal.auth)->result = DWCi_Auth_Start(1);
    if (((DWCAuth *)gDwcAuthGlobal.auth)->result != 0)
        return ((DWCAuth *)gDwcAuthGlobal.auth)->result;
    gDwcAuthGlobal.f0 = 0;
    DWCi_Auth_StartThread();
    return 0;
}
