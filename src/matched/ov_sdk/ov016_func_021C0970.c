/*
 * function: DWC_StartUtility
 * address:  0x021C0970
 * packet:   pkt_ov016_021C0970
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_StartUtility (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021C0A2C  0x021C0A2C  arm  ov016
 *   func_02177ED8  0x02177ED8  arm  ov009
 *   DWC_Auth_SetCustomNas  0x02177EC8  arm  ov009
 *   func_021C0AA8  0x021C0AA8  arm  ov016
 *   func_021C0B7C  0x021C0B7C  arm  ov016
 *   DWCi_SNDlInit  0x021CFEBC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_IPTlUpdate  0x021D656C  arm  ov016
 *   DWCi_TSKlAct  0x021D75D0  arm  ov016
 *   DWCi_IPTlCheckFold  0x021D6BC8  arm  ov016
 *   DWCi_SetLedWireless  0x021D7448  arm  ov016
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   func_021C0DE8  0x021C0DE8  arm  ov016
 *   DWCi_SceneInit  0x021C16F4  arm  ov016
 *   gDwcutilMainWork     0x021DE56C  data
 *   sDwcutilMainTable     0x021DB04C  data
 */

#include "../include/G_UtilState.h"

typedef struct UtilState UtilState;

extern int OS_IsRunOnTwl(void);
extern int func_021C0A2C(int lang, unsigned int param);
extern char *func_02177ED8(void);
extern void DWC_Auth_SetCustomNas(int v);
extern void func_021C0AA8(void);
extern void func_021C0B7C(void);
extern void DWCi_SNDlInit(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_IPTlUpdate();
extern void DWCi_TSKlAct(int kind);
extern void DWCi_IPTlCheckFold(void);
extern void DWCi_SetLedWireless(void);
extern void OS_WaitVBlankIntr(void);
extern void func_021C0DE8(void);
extern void DWCi_SceneInit(void);
extern struct UtilState gDwcutilMainWork;
extern char sDwcutilMainTable[];

int DWC_StartUtility(void *work, int language, int param)
{
    char *tempNasUrl;
    int result;
    if (OS_IsRunOnTwl())
        return -2;
    gDwcutilMainWork.work = work;
    if (!func_021C0A2C(language, param))
        return -1;
    tempNasUrl = func_02177ED8();
    DWC_Auth_SetCustomNas((int)sDwcutilMainTable);
    gDwcutilMainWork.end = 0;
    func_021C0AA8();
    func_021C0B7C();
    DWCi_SNDlInit();
    DWCi_ChangeScene((unsigned int)DWCi_SceneInit);
    result = 0;
    do {
        DWCi_IPTlUpdate();
        gDwcutilMainWork.scene();
        DWCi_TSKlAct(result);
        DWCi_IPTlCheckFold();
        DWCi_SetLedWireless();
        OS_WaitVBlankIntr();
    } while (!gDwcutilMainWork.end);
    func_021C0DE8();
    DWC_Auth_SetCustomNas((int)tempNasUrl);
    return result;
}
