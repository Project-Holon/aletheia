/*
 * function: GSYNC_STATE_StateSaveErrorExit
 * address: 0x021D8B0C
 * packet: pkt_ov123_021D8B0C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DISP_UpdateProgressPosition 0x021D66D0 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateShowCompletionMessage 0x021D8A9C thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   GFL_NET_STATE_SetErrorMode 0x0203C938 arm
 *   GAME_DATA_SaveMain  0x02012DD0  thumb  arm9
 */
#include "../include/Obj03272.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void GSYNC_DISP_UpdateProgressPosition(u8 *p, int n);
extern int GAME_DATA_SaveMain(u8 *p);
extern u32 func_020307B0(void *p);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern u32 GFL_NET_STATE_SetErrorMode(u8 mode);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateShowCompletionMessage(char *p);
void GSYNC_STATE_StateSaveErrorExit(char *p)
{
    if (((struct Obj03272 *)p)->f70<100) ++((struct Obj03272 *)p)->f70;
    GSYNC_DISP_UpdateProgressPosition(((struct Obj03272 *)p)->f14,((struct Obj03272 *)p)->f70);
    switch (GAME_DATA_SaveMain(((struct Obj03272 *)p)->f2C)) {
    case 1:
        if (((struct Obj03272 *)p)->f34) {
            func_020307B0(((struct Obj03272 *)p)->f34);
            ((struct Obj03272 *)p)->f34=0;
        }
        break;
    case 3:
        GFL_NET_STATE_SetError(0,0,0,0x3f3);
        GFL_NET_STATE_SetErrorMode(0);
        break;
    case 2:
        p[0xad]=0;
        GSYNC_STATE_ChangeState((u8 *)p,(int)GSYNC_STATE_StateShowCompletionMessage,0x8e6);
        break;
    }
}
