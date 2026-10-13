/*
 * function: OEKAKI_HandleEvent
 * address:  0x02185AB0
 * packet:   pkt_ov023_02185AB0
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
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   OEKAKI_SetQuitButtonPressed  0x021852F4  thumb  ov023
 *   OEKAKI_RegisterPlayerName  0x021857F4  thumb  ov023
 *   OEKAKI_ClearMessageWindow  0x021862F4  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_CloseMenuIfOpen  0x02186480  thumb  ov023
 *   OEKAKI_QueueCommand  0x02186860  thumb  ov023
 */
#include "../include/Obj00336.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *a);
typedef unsigned char  u8;
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void OEKAKI_SetQuitButtonPressed(void *p, int flag);
extern void OEKAKI_RegisterPlayerName(char *p, int a, int b);
extern void OEKAKI_ClearMessageWindow(char *p);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_CloseMenuIfOpen(char *p);
extern void OEKAKI_QueueCommand(char *p, int x, int y);

void OEKAKI_HandleEvent(char *p, int msg, int arg)
{
    u32 w;

    switch (msg) {
    case 1:
        if (((struct Obj00336 *)p)->f9288 == 1)
            return;
        if (((struct Obj00336 *)p)->f198 == 6 || ((struct Obj00336 *)p)->f198 == 0x10)
            OEKAKI_CloseMenuIfOpen(p);
        OEKAKI_SetQuitButtonPressed((void *)(((struct Obj00336 *)p)->f100), 0);
        OEKAKI_RegisterPlayerName(p, 0, arg);
        ((struct Obj00336 *)p)->f1B4 = arg;
        ((struct Obj00336 *)p)->f9280 = 0;
        break;
    case 3:
        OEKAKI_ClearMessageWindow(p);
        break;
    case 0xb:
    case 0x12:
        break;
    case 0x18:
        if (((struct Obj00336 *)p)->f9288 == 1)
            return;
        OEKAKI_RegisterPlayerName(p, 0, arg);
        if (arg == GFL_NET_SYSTEM_GetCurrentAid())
            return;
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
            ((struct Obj00336 *)p)->f9280 = ((struct Obj00336 *)p)->f9280 & (arg ^ 0xFFFF);
        if (((struct Obj00336 *)p)->f198 == 6 || ((struct Obj00336 *)p)->f198 == 0x10) {
            OEKAKI_CloseMenuIfOpen(p);
            w = ((struct Obj00336 *)p)->f118;
            BMP_WIN_TransferChars((struct Descriptor *)w);
            BMP_WIN_MakeScreen((struct Cfg *)w);
            func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        }
        OEKAKI_SetQuitButtonPressed((void *)(((struct Obj00336 *)p)->f100), 0);
        break;
    case 9:
        OEKAKI_QueueCommand(p, 0x2907, GFL_NET_SYSTEM_GetCurrentAid());
        break;
    default:
        return;
    }
    OEKAKI_SetNextScene(p, msg);
}
