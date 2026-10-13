/*
 * function: OEKAKI_StepQuitMenuResult
 * address:  0x02185454
 * packet:   pkt_ov023_02185454
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   APP_TASKMENU_TransWinAfterPrint  0x020278F4  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   OEKAKI_SetQuitButtonPressed  0x021852F4  thumb  ov023
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 *   OEKAKI_PrintMessage  0x021861C4  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_IsQuitTouched  0x021864A8  thumb  ov023
 *   OEKAKI_PollYesNoMenu  0x02186660  thumb  ov023
 *   OEKAKI_OpenGroup  0x02184560  thumb  ov023
 */
#include "../include/Obj02741.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Bits;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *a);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void APP_TASKMENU_TransWinAfterPrint(u8 *p);
extern void func_020061E4(u32 a);
extern void func_0201F7A8(void *desc, u32 kind);
extern void OEKAKI_SetQuitButtonPressed(void *p, int flag);
extern void OEKAKI_ApplyRemoteStrokes(char *p);
extern void OEKAKI_PrintMessage(u8 *w, u32 msg, int mode);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern int  OEKAKI_IsQuitTouched(char *p);
extern int  OEKAKI_PollYesNoMenu(char *p);
extern void OEKAKI_OpenGroup(char *p, int a);

int OEKAKI_StepQuitMenuResult(char *p, int x)
{
    u32 w;

    ((Bits *)(p + 0x4210))->mid = 0;
    if (((struct Obj02741 *)p)->f4217 == 2 && GFL_NET_SYSTEM_GetCurrentAid() != 0) {
        OEKAKI_ApplyRemoteStrokes(p);
        APP_TASKMENU_TransWinAfterPrint(((struct Obj02741 *)p)->f178);
        if (OEKAKI_IsQuitTouched(p))
            func_020061E4(0x54b);
        return x;
    }
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && ((struct Obj02741 *)p)->f9280 != 0) {
        OEKAKI_ApplyRemoteStrokes(p);
        APP_TASKMENU_TransWinAfterPrint(((struct Obj02741 *)p)->f178);
        return x;
    }
    switch (OEKAKI_PollYesNoMenu(p)) {
    case 0:
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            OEKAKI_SetNextScene(p, 0xf);
            OEKAKI_PrintMessage((u8 *)p, 4, 1);
        } else {
            OEKAKI_SetNextScene(p, 8);
            func_0201F7A8((void *)(((struct Obj02741 *)p)->f11C), 2);
        }
        w = ((struct Obj02741 *)p)->f118;
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        break;
    case 1:
        OEKAKI_SetNextScene(p, 4);
        OEKAKI_SetQuitButtonPressed((void *)(((struct Obj02741 *)p)->f100), 0);
        func_0201F7A8((void *)(((struct Obj02741 *)p)->f11C), 2);
        w = ((struct Obj02741 *)p)->f118;
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            OEKAKI_OpenGroup(p, 1);
            ((struct Obj02741 *)p)->f9E6C = 1;
        }
        break;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return x;
}
