/*
 * unit: yes
 * function: BTL_CLIENT_StepRemote, BTL_CLIENT_ResetSendWord
 * address: 0x021CDC0C
 * packet: pkt_ov093_021CDC0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 * symbols:
 *   BTL_CLIENT_TickCounter 0x021D3FDC thumb ov093
 *   BTL_CLIENT_IsCounterReplayDone 0x021D3F98 thumb ov093
 *   BTL_ADAPTER_GetRecvCommand 0x021EEBE8 thumb ov093
 *   BTL_CLIENT_FindCommandStepFn 0x021CDD50 thumb ov093
 *   BTL_CLIENT_ResetSendWord 0x021CDD34 thumb ov093
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   BTLV_CORE_ClearWaitWindow 0x021EAE24 thumb ov093
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   BTLV_EFFECT_SetSeSuppressed 0x021F88BC thumb ov094
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   BTLV_EFFECT_GetWorkPtr 0x021F8678 thumb ov094
 *   BTL_ADAPTER_SetRecvTarget 0x021EEC4C thumb ov093
 *   BTLV_CORE_GetWaitState 0x021EAE34 thumb ov093
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   BTL_CLIENT_GetCounterTarget 0x021D3FA8 thumb ov093
 *   BTLV_CORE_SetCounterDisplay 0x021EAE74 thumb ov093
 *   BTL_MAIN_StartClientMainSteps 0x021BA7F8 thumb ov093
 */
#include "../include/Obj00818.h"
#include "../include/Obj09986.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *,int *);
struct Q;
extern void BTL_CLIENT_TickCounter(u8 *p, struct Q *q);
extern int BTL_CLIENT_IsCounterReplayDone(u8 *);
extern u8 BTL_ADAPTER_GetRecvCommand(void *);
extern Callback BTL_CLIENT_FindCommandStepFn(u8 *,u32,int *);
extern void BTL_CLIENT_ResetSendWord(u8 *);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void BTLV_CORE_ClearWaitWindow(u8 *p);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void BTLV_EFFECT_SetSeSuppressed(int);
extern void PM_VOICE_ResetMasterVolume(void);
extern void *BTLV_EFFECT_GetWorkPtr(void);
extern int BTL_ADAPTER_SetRecvTarget(void *,void *,u32);
extern int BTLV_CORE_GetWaitState(u8 *p);
extern int GFL_USE_IsBgmFading(void);
extern u16 BTL_CLIENT_GetCounterTarget(u8 *p);
extern void BTLV_CORE_SetCounterDisplay(char *p, u32 a, u32 b);
extern void BTL_MAIN_StartClientMainSteps(char *p);
int BTL_CLIENT_StepRemote(u8 *p)
{
    u32 id;
    u16 n;
    int zero;
    BTL_CLIENT_TickCounter(p,(struct Q *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        p[0x1a8] = 1;
    case 1:
        if (!BTL_CLIENT_IsCounterReplayDone(p+0x18)) {
            id = BTL_ADAPTER_GetRecvCommand(((struct Obj00818 *)p)->f50);
            if (id) {
                zero = 0;
                *(Callback *)&((struct Obj00818 *)p)->fC8 = BTL_CLIENT_FindCommandStepFn(p,id,0);
                if (*(Callback *)&((struct Obj00818 *)p)->fC8) {
                    p[0x1a8] = 2;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
                else {
                    BTL_CLIENT_ResetSendWord(p);
                    p[0x1a8] = 3;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
            }
        } else {
            if (((struct Obj00818 *)p)->f54) {
                GFL_USE_SetPlayersAudible(1,1);
                BTLV_CORE_ClearWaitWindow(((struct Obj00818 *)p)->f54);
                GFL_USE_FadeInBgmFull(30);
                BTLV_EFFECT_SetSeSuppressed(0);
                PM_VOICE_ResetMasterVolume();
            }
            p[0x1a8] = 4;
        }
        break;
    case 2:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            p[0x1a8] = 3;
            ((struct Obj00818 *)p)->fCC = 0;
            if (BTLV_EFFECT_GetWorkPtr()) BTLV_EFFECT_SetSeSuppressed(1);
        }
        break;
    case 3:
        if (BTL_ADAPTER_SetRecvTarget(((struct Obj00818 *)p)->f50,((struct Obj00818 *)p)->fD8,((struct Obj00818 *)p)->fDC)) p[0x1a8] = 1;
        break;
    case 4:
        if (((struct Obj00818 *)p)->f54) {
            if (BTLV_CORE_GetWaitState(((struct Obj00818 *)p)->f54)) {
                if (!GFL_USE_IsBgmFading()) {
                    n = (int)BTL_CLIENT_GetCounterTarget(p+0x18);
                    BTLV_CORE_SetCounterDisplay(((struct Obj00818 *)p)->f54,n,n);
                    BTL_MAIN_StartClientMainSteps(((struct Obj00818 *)p)->f0);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}
void BTL_CLIENT_ResetSendWord(u8 *p)
{
    ((struct Obj09986 *)p)->fE0 = 0;
    *(u8 * *)&((struct Obj09986 *)p)->fD8 = p+0xe0;
    ((struct Obj09986 *)p)->fDC = 4;
}
