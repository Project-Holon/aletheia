/*
 * function: WORLDTRADE_ENTER_RunDialog
 * address: 0x021F8E88
 * packet: pkt_ov135_021F8E88
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ENTER_StateStartServerCheck 0x021F8A74 thumb ov135
 *   WORLDTRADE_ENTER_StatePollServerCheck 0x021F8A80 thumb ov135
 *   WORLDTRADE_ENTER_InitDwcTrade 0x021F8AB0 thumb ov135
 *   WORLDTRADE_ENTER_StateStartConnect 0x021F8AF4 thumb ov135
 *   WORLDTRADE_ENTER_WaitServerCheck 0x021F8B0C thumb ov135
 *   WORLDTRADE_ENTER_SendProfile 0x021F8BBC thumb ov135
 *   WORLDTRADE_ENTER_WaitProfileResult 0x021F8BE8 thumb ov135
 *   WORLDTRADE_ENTER_ShowErrorMessage 0x021F8F84 thumb ov135
 *   WORLDTRADE_ENTER_ShutdownDwcStep 0x021F9024 thumb ov135
 */
#include "../include/Obj01743.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WORLDTRADE_ENTER_StateStartServerCheck(void *a0);
extern int WORLDTRADE_ENTER_StatePollServerCheck(u8 *);
extern int WORLDTRADE_ENTER_InitDwcTrade(u8 **);
extern int WORLDTRADE_ENTER_StateStartConnect(u8 *);
extern int WORLDTRADE_ENTER_WaitServerCheck(u8 *);
extern int WORLDTRADE_ENTER_SendProfile(u8 *);
extern int WORLDTRADE_ENTER_WaitProfileResult(u8 *);
extern int WORLDTRADE_ENTER_ShowErrorMessage(u8 *, void *);
extern int WORLDTRADE_ENTER_ShutdownDwcStep(u8 *, void *);
int WORLDTRADE_ENTER_RunDialog(void *dialog, u8 *p)
{
    int result;
    switch (((struct Obj01743 *)p)->f12EC) {
    case 0:
        if (WORLDTRADE_ENTER_StateStartServerCheck(p))
            (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 1:
        result = WORLDTRADE_ENTER_StatePollServerCheck(p);
        switch (result) {
        case 1: (((struct Obj01743 *)p)->f12EC)++; break;
        case 2: ((struct Obj01743 *)p)->f12EC = 9; break;
        }
        break;
    case 2:
        if (WORLDTRADE_ENTER_InitDwcTrade((u8 **)p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 3:
        if (WORLDTRADE_ENTER_StateStartConnect(p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 4:
        result = WORLDTRADE_ENTER_WaitServerCheck(p);
        switch (result) {
        case 1: (((struct Obj01743 *)p)->f12EC)++; break;
        case 2: ((struct Obj01743 *)p)->f12EC = 7; break;
        }
        break;
    case 5:
        if (WORLDTRADE_ENTER_SendProfile(p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 6:
        result = WORLDTRADE_ENTER_WaitProfileResult(p);
        switch (result) {
        case 1: ((struct Obj01743 *)p)->f12EC = 0; return 0;
        case 2: ((struct Obj01743 *)p)->f12EC = 7; break;
        }
        break;
    case 7:
        if (WORLDTRADE_ENTER_ShowErrorMessage(p, dialog)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 8:
        if (WORLDTRADE_ENTER_ShutdownDwcStep(p, dialog)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 9:
        ((struct Obj01743 *)p)->f12EC = 0;
        return 1;
    }
    return 2;
}
