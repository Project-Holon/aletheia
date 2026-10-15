/*
 * function: WIFILOGIN_DISP_StepCancel
 * address: 0x021D4310
 * packet: pkt_ov115_021D4310
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_COMMON_IsCancelInput 0x021D4240 thumb ov115
 *   WIFILOGIN_MSG_RedrawBorder 0x021D5F7C thumb ov115
 *   WIFILOGIN_MSG_ShowMessage 0x021D5CCC thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_DISP_HandleNetError 0x021D4644 thumb ov115
 *   WIFILOGIN_DISP_StepBeginToken 0x021D4BB4 thumb ov115
 *   WIFILOGIN_DISP_StepCallSync 0x021D4AB0 thumb ov115
 */
#include "../include/Obj08038.h"
#include "../include/Obj22586.h"
#include "../include/Obj22587.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFILOGIN_COMMON_IsCancelInput(u8 *);
extern void WIFILOGIN_MSG_RedrawBorder(u8 *p);
extern void WIFILOGIN_MSG_ShowMessage(u8 *p, u32 n);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *, u32);
extern int WIFILOGIN_DISP_HandleNetError(u8 *);
extern void WIFILOGIN_DISP_StepBeginToken(u8 *p);
extern void WIFILOGIN_DISP_StepCallSync(unsigned char *a);
void WIFILOGIN_DISP_StepCancel(u8 *p)
{
    if (WIFILOGIN_COMMON_IsCancelInput(p)) {
        WIFILOGIN_MSG_RedrawBorder((u8 *)(((struct Obj08038 *)p)->f38));
        if (((struct Obj22586 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f4 == 0)
            WIFILOGIN_MSG_ShowMessage((u8 *)(((struct Obj08038 *)p)->f38), 0x23);
        if (((struct Obj22587 *)(*(u8 * *)&((struct Obj08038 *)p)->f40))->f10 != 0)
            WIFILOGIN_COMMON_SetStateHandler(p, (u32)WIFILOGIN_DISP_StepBeginToken);
        else
            WIFILOGIN_COMMON_SetStateHandler(p, (u32)WIFILOGIN_DISP_StepCallSync);
    } else {
        WIFILOGIN_DISP_HandleNetError(p);
    }
}
