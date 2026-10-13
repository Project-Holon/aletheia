/*
 * function: OEKAKI_StepStart
 * address:  0x02185378
 * packet:   pkt_ov023_02185378
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_PrintMessage  0x021861C4  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_CloseMenuIfOpen  0x02186480  thumb  ov023
 *   func_020061E4  0x020061E4  thumb
 *   func_0207D658  0x0207D658  arm
 *   OEKAKI_ApplyRemoteStrokes  0x02185354  thumb  ov023
 */
#include "../include/Obj00336.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
typedef unsigned char  u8;
extern void OEKAKI_PrintMessage(u8 *w, u32 msg, int mode);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_CloseMenuIfOpen(char *p);
extern void func_020061E4(u32 a);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void OEKAKI_ApplyRemoteStrokes(char *p);

int OEKAKI_StepStart(char *p, int x)
{
    if (((struct Obj00336 *)p)->f1B4 == GFL_NET_SYSTEM_GetCurrentAid())
        OEKAKI_PrintMessage((u8 *)p, 0xd, 0);
    else
        OEKAKI_PrintMessage((u8 *)p, 0, 0);
    OEKAKI_SetNextScene(p, 2);
    OEKAKI_CloseMenuIfOpen(p);
    func_020061E4(0x54c);
    func_0207D658(0x04000050, 14, -6);
    OEKAKI_ApplyRemoteStrokes(p);
    return x;
}
