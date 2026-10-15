/*
 * function: BTL_MAIN_ProcExit
 * address: 0x021B6500
 * packet: pkt_ov093_021B6500
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: ov093 leaf shards 021EF980, 021D4D5C, 021EEA54 and the 021D8058/021D805C unit resolve all four former wildcards.
 * lever: cache each re-read fade value for the comparison and setter; associate callback integer offsets before adding the base.
 * volatile: fade field re-read at 021B6584 and 021B659C across hardware-brightness calls.
 * symbols:
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   BTL_FIELD_Delete 0x021EF980 thumb ov093
 *   BTL_NET_FreeRelayPacket 0x021D4D5C thumb ov093
 *   BTL_CALC_Exit 0x021D7894 thumb ov093
 *   BTL_MAIN_FreeParties 0x021BA0CC thumb ov093
 *   BTL_MAIN_FreeTrainerSlotsAndVoices 0x021B9DE8 thumb ov093
 *   BTL_MAIN_StartCleanupTask 0x021B6804 thumb ov093
 *   BTL_ADAPTER_NoOp 0x021EEA54 thumb ov093
 *   BTL_NET_Exit 0x021D4254 thumb ov093
 *   BTL_CALC_NoOp 0x021D8058 thumb ov093
 *   BTLV_CORE_UnloadOverlays 0x021E8DF8 thumb ov093
 *   BTLV_CORE_UnloadDsiOverlay 0x021E88F8 thumb ov093
 *   GFL_USE_SetPlayersAudible  0x02005CA4  thumb  arm9
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   RINGTONE_SYS_RegisterSleepCallbacks  0x02029F6C  thumb  arm9
 */
#include "../include/Obj01370.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 low:5; u8 flag5:1; u8 flag6:1; u8 flag7:1; } Flags;
typedef struct { int (*first)(u32 *, void *); int (*second)(u32 *, void *); void *object; u32 state; } Callback;
typedef struct { u8 pad[0x460]; volatile int fade; } Fade;
struct S;
struct Proc;
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern int GXx_GetMasterBrightness_(volatile u16 *);
extern void GXx_SetMasterBrightness_(volatile u16 *, int);
extern void BTL_FIELD_Delete(void *);
extern u32 func_020307B0(void *p);
extern void BTL_NET_FreeRelayPacket(void *);
extern void BTL_CALC_Exit(void);
extern void BTL_MAIN_FreeParties(struct S *);
extern void BTL_MAIN_FreeTrainerSlotsAndVoices(char *);
extern void BTL_MAIN_StartCleanupTask(Callback *, u8 *, u8 *);
extern void BTL_ADAPTER_NoOp(void);
extern void BTL_NET_Exit(void);
extern void BTL_CALC_NoOp(void);
extern void BTLV_CORE_UnloadOverlays(void);
extern void GFL_USE_SetPlayersAudible(int, u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern void RINGTONE_SYS_RegisterSleepCallbacks(void);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void BTLV_CORE_UnloadDsiOverlay(void);
static inline int poll(u8 *p, u32 offset)
{
    typedef int (*Fn)(u32 *, void *);
    if (*(Fn *)(p + offset)) {
        if ((*(Fn *)(p + offset))((u32 *)(p + (offset + 12)), *(void **)(p + (offset + 8)))) {
            *(Fn *)(p + offset) = 0; *(u32 *)(p + (offset + 12)) = 0;
        }
        return 0;
    }
    if (*(Fn *)(p + (offset + 4))) {
        if ((*(Fn *)(p + (offset + 4)))((u32 *)(p + (offset + 12)), *(void **)(p + (offset + 8)))) *(Fn *)(p + (offset + 4)) = 0;
        else return 0;
    }
    return 1;
}
int BTL_MAIN_ProcExit(int handle, u32 *state, int unused, u8 *p)
{
    switch (*state) {
    case 0:
        if (!((Flags *)p)->flag5) GFL_USE_FadeOutBgm(30);
        ((Fade *)p)->fade = 0;
        if (GXx_GetMasterBrightness_((volatile u16 *)0x0400006c) != 0) {
            ((Fade *)p)->fade = -16;
            GXx_SetMasterBrightness_((volatile u16 *)0x0400006c, -16);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106c, -16);
            *state += 2;
        } else *state += 1;
        break;
    case 1: {
        int v;
        v = ((Fade *)p)->fade;
        if (v > -16) {
            ((Fade *)p)->fade = v - 1;
            if (GXx_GetMasterBrightness_((volatile u16 *)0x0400006c) > (v = ((Fade *)p)->fade))
                GXx_SetMasterBrightness_((volatile u16 *)0x0400006c, v);
            if (GXx_GetMasterBrightness_((volatile u16 *)0x0400106c) > (v = ((Fade *)p)->fade))
                GXx_SetMasterBrightness_((volatile u16 *)0x0400106c, v);
        } else *state += 1;
        break;
    }
    case 2:
        if (!((Flags *)p)->flag5) {
            if (GFL_USE_IsBgmFading() == 0) { GFL_USE_CancelChangeAndStopBgm(); *state += 1; }
        } else *state += 1;
        break;
    case 3:
        if (((struct Obj01370 *)p)->f2BC) { BTL_FIELD_Delete(((struct Obj01370 *)p)->f2BC); ((struct Obj01370 *)p)->f2BC = 0; }
        if (((struct Obj01370 *)p)->f2C0) { func_020307B0(((struct Obj01370 *)p)->f2C0); ((struct Obj01370 *)p)->f2C0 = 0; }
        if (((struct Obj01370 *)p)->f2C4) { BTL_NET_FreeRelayPacket(((struct Obj01370 *)p)->f2C4); ((struct Obj01370 *)p)->f2C4 = 0; }
        BTL_CALC_Exit();
        BTL_MAIN_FreeParties((struct S *)p);
        BTL_MAIN_FreeTrainerSlotsAndVoices((char *)p);
        BTL_MAIN_StartCleanupTask((Callback *)(p + 0x450), p, *(u8 * *)&((struct Obj01370 *)p)->f0);
        *state += 1;
        break;
    case 4:
        if (poll(p, 0x450)) {
            BTL_ADAPTER_NoOp(); BTL_NET_Exit(); BTL_CALC_NoOp();
            *state += 1;
        }
        break;
    case 5:
        BTLV_CORE_UnloadOverlays();
        GFL_USE_SetPlayersAudible(1, 62);
        PM_VOICE_ResetMasterVolume();
        if (((Flags *)p)->flag7) { RINGTONE_SYS_RegisterSleepCallbacks(); ((Flags *)p)->flag7 = 0; }
        func_020315D4((struct Proc *)handle);
        GFL_HEAP_DeleteChecked(19);
        GFL_HEAP_DeleteChecked(20);
        GFL_HEAP_DeleteChecked(18);
        BTLV_CORE_UnloadDsiOverlay();
        return 1;
    }
    return 0;
}
