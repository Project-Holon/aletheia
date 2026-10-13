/*
 * function: OEKAKI_Main
 * address:  0x02184674
 * packet:   pkt_ov023_02184674
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The step-table callbacks take (p, *state): the switch value, reused as
 * their second argument, is what keeps it live in r1 through the dispatch
 * (a one-argument callback puts the whole dispatch in r0). OEKAKI_ApplySceneChange
 * is void but leaves r0 = p; no hidden argument here.
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_ApplySceneChange  0x0218644C  thumb  ov023
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   UNION_APP_SetCallbacks  0x021840FC  thumb  ov022
 *   OEKAKI_OnMemberJoined  0x021848A8  thumb  ov023
 *   OEKAKI_OnMemberLeft  0x021848CC  thumb  ov023
 *   OEKAKI_OpenGroup  0x02184560  thumb  ov023
 *   OEKAKI_RefreshNamePlates  0x02185F74  thumb  ov023
 *   OEKAKI_UpdateMembers  0x02186324  thumb  ov023
 *   OEKAKI_AnimatePalette  0x02185F10  thumb  ov023
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   UNION_APP_RequestReset  0x02184174  thumb  ov022
 *   UNION_APP_IsResetDone  0x0218417C  thumb  ov022
 *   OEKAKI_SendPendingCommand  0x021867C4  thumb  ov023
 *   CLACT_DrawSystem  0x0204A600  arm
 *   TCBL_Main  0x020310C4  arm
 *   OEKAKI_UpdatePrintJobs  0x02186708  thumb  ov023
 *   func_0200FB24  0x0200FB24  thumb
 *   gOekakiSceneTable     0x02186E80  data   a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00460.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Step {
    int (*fn)(char *p, int state);
    void *f4;
} Step;

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int OEKAKI_GetJoinedBits(char *p);
extern void OEKAKI_ApplySceneChange(char *p, int state);
extern u32 WIPE_SYS_EndCheck(void);
extern void UNION_APP_SetCallbacks(u32 obj, void (*a)(void), void (*b)(void), char *arg);
struct Tcbl;
extern void OEKAKI_OnMemberJoined(int a, int unused, char *p);
extern void OEKAKI_OnMemberLeft(void);
extern void OEKAKI_OpenGroup(char *p, int a);
extern void OEKAKI_RefreshNamePlates(void *win, int color, char *p);
extern int OEKAKI_UpdateMembers(u8 *p);
extern void OEKAKI_AnimatePalette(u16 *p);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void UNION_APP_RequestReset(u8 *p);
extern u32 UNION_APP_IsResetDone(u8 *p);
extern void OEKAKI_SendPendingCommand(char *p);
extern void CLACT_DrawSystem(void);
extern void TCBL_Main(struct Tcbl *p);
extern void OEKAKI_UpdatePrintJobs(char *p);
extern u32 func_0200FB24(void);
extern Step gOekakiSceneTable[];

int OEKAKI_Main(void *task, int *state, int a2, char *p)
{
    int (*fn)(char *p, int state);
    int r;

    if (GFL_NET_SYSTEM_GetCurrentAid() == 0 && ((struct Obj00460 *)p)->f9280 != 0) {
        ((struct Obj00460 *)p)->f9280 = OEKAKI_GetJoinedBits(p) & ((struct Obj00460 *)p)->f9280;
    }
    ((struct Obj00460 *)p)->f194 = *state;
    OEKAKI_ApplySceneChange(p, *state);
    switch (*state) {
    case 0:
        if (WIPE_SYS_EndCheck() != 0) {
            UNION_APP_SetCallbacks(**(u32 * *)&((struct Obj00460 *)p)->f4, (void (*)(void))OEKAKI_OnMemberJoined, OEKAKI_OnMemberLeft, p);
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                OEKAKI_OpenGroup(p, 1);
            }
            *state = 1;
        }
        break;
    case 1:
        fn = gOekakiSceneTable[*(int *)(p + 0x198)].fn;
        if (fn != 0) {
            *state = fn(p, *state);
        }
        OEKAKI_RefreshNamePlates(p + 0x104, 0x44f, p);
        if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
            r = OEKAKI_UpdateMembers((u8 *)p);
            if (*state == 1) {
                *state = r;
            }
        }
        OEKAKI_AnimatePalette((u16 *)(p + 0x4208));
        break;
    case 2:
        fn = gOekakiSceneTable[*(int *)(p + 0x198)].fn;
        if (fn != 0 && gOekakiSceneTable[*(int *)(p + 0x198)].f4 != 0) {
            *state = fn(p, *state);
        }
        break;
    case 3:
        if (WIPE_SYS_EndCheck() != 0) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2900);
            UNION_APP_RequestReset((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4));
            *state = 4;
        }
        break;
    case 4:
        if (UNION_APP_IsResetDone((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4)) != 0) {
            return 1;
        }
        break;
    }
    OEKAKI_SendPendingCommand(p);
    CLACT_DrawSystem();
    TCBL_Main((struct Tcbl *)(((struct Obj00460 *)p)->f170));
    OEKAKI_UpdatePrintJobs(p);
    if (WIPE_SYS_EndCheck() != 0 && func_0200FB24() != 0) {
        return 1;
    }
    return 0;
}
