/*
 * function: BTLV_SCU_RunTrainerIntroTwo
 * address: 0x021EC0DC
 * packet: pkt_ov093_021EC0DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetTrainerType 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   BTLV_SCU_StartMsgWinFadeOut 0x021ED798 thumb ov093
 *   BTLV_SCU_UpdateMsgWinFade 0x021ED814 thumb ov093
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   BTLV_SCU_StartBrightnessFade 0x021EB584 thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTLV_SCU_GetBallStates 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   BTLV_SCU_StartMessage 0x021ECEB8 thumb ov093
 *   BTLV_SCU_UpdateMessage 0x021ECF68 thumb ov093
 */
#include "../include/Obj00027.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern u16 BTL_MAIN_GetTrainerType(char *, int);
extern void func_021F7F58(int, u32, u32, u32, u32);
struct T;
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *);
extern void func_021F7A28(int, u32);
extern void BTLV_SCU_StartBrightnessFade(int);
extern int func_021F7EB4(void);
extern void *BTL_MAIN_GetCompetitor(void ***);
extern void BTLV_SCU_GetBallStates(u8 *p, u32 *out, u32 a, u32 b, u32 flag);
extern void func_021F823C(u32 *);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern void BTLV_SCU_StartMessage(u8 *, u32, u16, u32);
extern int BTLV_SCU_UpdateMessage(struct T *p);
int BTLV_SCU_RunTrainerIntroTwo(u8 *p, int *state, u16 i, u16 j)
{
    u8 *b = p + 0xf0;
    int msg;
    u32 buf[7];
    switch (*state) {
    case 0:
        b[0] = 11;
        b[1] = 13;
        func_021F7F58(BTL_MAIN_GetTrainerType(*(char * *)&((struct Obj00027 *)p)->f134, i), b[0], 0, 0, 0);
        func_021F7F58(BTL_MAIN_GetTrainerType(*(char * *)&((struct Obj00027 *)p)->f134, j), b[1], 0, 0, 0);
        BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154))) {
            func_021F7A28(b[0], 0x237);
            BTLV_SCU_StartBrightnessFade(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            if ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00027 *)p)->f134) != 3) msg = 9;
            else msg = 10;
            BTLV_SCU_GetBallStates(p, buf, i, j, 1);
            func_021F823C(buf);
            BTL_MSG_FormatArgs(((struct Obj00027 *)p)->f34, msg, 2, i, j);
            BTLV_SCU_StartMessage(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (BTLV_SCU_UpdateMessage((struct T *)p)) {
            func_021F7A28(b[0], 0x238);
            BTLV_SCU_StartMsgWinFadeOut((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(p + 0x154)) && !func_021F7EB4()) return 1;
        break;
    }
    return 0;
}
