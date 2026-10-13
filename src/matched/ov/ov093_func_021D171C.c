/*
 * function: BTL_CLIENT_StepShowEndSpeech
 * address: 0x021D171C
 * packet: pkt_ov093_021D171C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 * symbols:
 *   BTL_CLIENT_GetOutcomeForClient 0x021D13A4 thumb ov093
 *   BTL_MAIN_SetOutcomeIfUnset 0x021B916C thumb ov093
 *   BTL_MAIN_GetWinBgm 0x021B86DC thumb ov093
 *   func_021F878C 0x021F878C thumb ov094
 *   BTL_MAIN_GetOwnOpponentClient 0x021B904C thumb ov093
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   BTL_CLIENT_ShowEndSpeech 0x021D185C thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   BTLV_CORE_PrintMessageBuffer 0x021EA600 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 */
#include "../include/Obj00066.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;
extern u32 BTL_CLIENT_GetOutcomeForClient(void *);
extern void BTL_MAIN_SetOutcomeIfUnset(u8 *p, u32 x);
extern u16 BTL_MAIN_GetWinBgm(void **p);
extern void func_021F878C(u32 a);
extern u8 BTL_MAIN_GetOwnOpponentClient(u8 *p, int k);
extern unsigned short BTL_MAIN_GetTrainerType(char *p, int i);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021F7998(u32 a);
extern void BTL_CLIENT_ShowEndSpeech(void *, int, int);
extern int func_021F7EB4(void);
extern void BTLV_CORE_PrintMessageBuffer(char *p);
extern int BTLV_CORE_WaitMessage(u32 *p);
int BTL_CLIENT_StepShowEndSpeech(u8 *p, int *state, void *a2)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0) return 1;
        mode = BTL_CLIENT_GetOutcomeForClient(p);
        BTL_MAIN_SetOutcomeIfUnset(((struct Obj00066 *)p)->f0, mode);
        if (mode == 1) func_021F878C(BTL_MAIN_GetWinBgm(((struct Obj00066 *)p)->f0));
        if (mode <= 1) {
            idx = BTL_MAIN_GetOwnOpponentClient(((struct Obj00066 *)p)->f0, 0);
            func_021F7F58(BTL_MAIN_GetTrainerType(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            BTL_CLIENT_ShowEndSpeech(p, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            BTLV_CORE_PrintMessageBuffer(((struct Obj00066 *)p)->f54);
            *state = 2;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(((struct Obj00066 *)p)->f54) != 0) {
            idx = BTL_MAIN_GetOwnOpponentClient(((struct Obj00066 *)p)->f0, 0);
            if (idx == BTL_MAIN_GetOwnOpponentClient(((struct Obj00066 *)p)->f0, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = BTL_CLIENT_GetOutcomeForClient(p);
            idx = BTL_MAIN_GetOwnOpponentClient(((struct Obj00066 *)p)->f0, 1);
            func_021F7F58(BTL_MAIN_GetTrainerType(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            BTL_CLIENT_ShowEndSpeech(p, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            BTLV_CORE_PrintMessageBuffer(((struct Obj00066 *)p)->f54);
            *state = 5;
        }
        break;
    case 5:
        if (BTLV_CORE_WaitMessage(((struct Obj00066 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}
