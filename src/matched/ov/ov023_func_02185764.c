/*
 * function: OEKAKI_StepFinishMenuResult
 * address:  0x02185764
 * packet:   pkt_ov023_02185764
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_PollYesNoMenu  0x02186660  thumb  ov023
 *   OEKAKI_GetMemberCount  0x02186164  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   UNION_APP_Close  0x02184114  thumb  ov022
 *   OEKAKI_SetQuitButtonPressed  0x021852F4  thumb  ov023
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_OpenGroup  0x02184560  thumb  ov023
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 */
#include "../include/Obj05108.h"

typedef unsigned int u32;

extern int OEKAKI_PollYesNoMenu(char *p);
extern int OEKAKI_GetMemberCount(char *p);
typedef unsigned short u16;
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern int UNION_APP_Close(unsigned char *p);
extern void OEKAKI_SetQuitButtonPressed(void *p, int flag);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void OEKAKI_OpenGroup(char *p, int a);
extern void OEKAKI_ApplyRemoteStrokes(char *p);

int OEKAKI_StepFinishMenuResult(char *p, int x)
{
    int m;

    m = OEKAKI_PollYesNoMenu(p);
    if (((struct Obj05108 *)p)->f1AC != OEKAKI_GetMemberCount(p) || ((struct Obj05108 *)p)->f9280 != 0) {
        OEKAKI_ApplyRemoteStrokes(p);
        return x;
    }
    switch (m) {
    case 0:
        OEKAKI_SetNextScene(p, 0x11);
        UNION_APP_Close((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj05108 *)p)->f4));
        break;
    case 1:
        OEKAKI_SetNextScene(p, 4);
        OEKAKI_SetQuitButtonPressed((void *)(((struct Obj05108 *)p)->f100), 0);
        BMP_MENUWORK_DrawWindowBorder((void *)(((struct Obj05108 *)p)->f11C), 2);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            OEKAKI_OpenGroup(p, 1);
            ((struct Obj05108 *)p)->f9E6C = 1;
        }
        break;
    }
    OEKAKI_ApplyRemoteStrokes(p);
    return x;
}
