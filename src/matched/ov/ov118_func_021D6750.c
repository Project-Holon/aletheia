/*
 * function: POKETRADE_DEMO_DOWN_StepStartPlayback
 * address:  0x021D6750
 * packet:   pkt_ov118_021D6750
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_3D_FadeTexturePalette  0x021E3BB0  thumb  ov119
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_DEMO_DOWN_CompareSideMon  0x021D6544  thumb  ov118
 *   POKETRADE_DEMO_DOWN_StepWaitSync  0x021D67D4  thumb  ov118
 *   POKETRADE_DEMO_COMMON_StepBeginPlayback  0x021D67F8  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;
typedef unsigned char u8;

extern void POKETRADE_3D_FadeTexturePalette(char *p);
extern void POKETRADE_3D_RemoveCurrentUnit(void *p);
extern int POKETRADE_PROC_IsNetSession(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_DEMO_DOWN_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern void POKETRADE_DEMO_DOWN_StepWaitSync(u8 *p);
extern void POKETRADE_DEMO_COMMON_StepBeginPlayback(u8 *p);

void POKETRADE_DEMO_DOWN_StepStartPlayback(u8 *p)
{
    POKETRADE_3D_FadeTexturePalette((char *)p);
    if (((struct Obj00001 *)p)->f854 == 1) {
        POKETRADE_DEMO_DOWN_CompareSideMon(p, p + 0x11ED, p + 0x11EF, ((struct Obj00001 *)p)->f834, 1);
        POKETRADE_DEMO_DOWN_CompareSideMon(p, p + 0x11EE, p + 0x11F0, ((struct Obj00001 *)p)->f830, 0);
        POKETRADE_3D_RemoveCurrentUnit(p);
        if (POKETRADE_PROC_IsNetSession(p) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepWaitSync);
        } else {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepBeginPlayback);
        }
    }
}
