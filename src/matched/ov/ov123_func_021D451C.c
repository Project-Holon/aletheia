/*
 * function: GSYNC_MENU_OnButtonAnimEnd
 * address: 0x021D451C
 * packet: pkt_ov123_021D451C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower 021D45F0 already filed separately.
 * symbols:
 *   CLACT_ResetActorAnimCommand 0x0204BA10 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_02045CAC 0x02045CAC arm
 *   GSYNC_MENU_PrintMessage 0x021D4EF0 thumb ov123
 *   GSYNC_MENU_SetPaletteFade 0x021D4D40 thumb ov123
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 *   GSYNC_MENU_PrintMessageNoStream 0x021D4FAC thumb ov123
 *   GSYNC_MENU_StateWaitTouchAfterMessage 0x021D4AFC thumb ov123
 *   GSYNC_MENU_StateOpenYesNoAfterMessage 0x021D44F4 thumb ov123
 *   GSYNC_MENU_StatePrintConfirmMessage 0x021D4FB8 thumb ov123
 *   GSYNC_MENU_StateStartFadeOut 0x021D4440 thumb ov123
 */
#include "../include/Obj00273.h"
typedef unsigned int u32;
struct Actor;
struct Descriptor;
struct MsgBank;
struct Obj;
extern void CLACT_ResetActorAnimCommand(struct Actor *a);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern int OS_IsRunOnTwl(void);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void GSYNC_MENU_PrintMessage(char *, int, int);
extern void GSYNC_MENU_SetPaletteFade(char *, int);
extern void GSYNC_MENU_ChangeState(char *, void *, int);
extern void GSYNC_MENU_PrintMessageNoStream(char *);
extern void GSYNC_MENU_StateWaitTouchAfterMessage(char *p);
extern void GSYNC_MENU_StateOpenYesNoAfterMessage(char *p);
extern void GSYNC_MENU_StatePrintConfirmMessage(char *p);
extern void GSYNC_MENU_StateStartFadeOut(void);
void GSYNC_MENU_OnButtonAnimEnd(char *p)
{
    CLACT_ResetActorAnimCommand(*(void **)(p + ((struct Obj00273 *)p)->f270 * 4 + 0x2a0));
    CLACT_SetActorAutoAnim(*(void **)(p + ((struct Obj00273 *)p)->f270 * 4 + 0x2a0), 0);
    if (((struct Obj00273 *)p)->f8 == 3) {
        if (((struct Obj00273 *)p)->f224) {
            BMP_WIN_Delete(((struct Obj00273 *)p)->f224);
            ((struct Obj00273 *)p)->f224 = 0;
        }
        if (OS_IsRunOnTwl()) {
            func_02045CAC(((struct Obj00273 *)p)->f28, 0x20, ((struct Obj00273 *)p)->f38);
            GSYNC_MENU_PrintMessage(p, 10, 0);
            GSYNC_MENU_SetPaletteFade(p, 1);
            GSYNC_MENU_ChangeState(p, GSYNC_MENU_StateWaitTouchAfterMessage, 0x1df);
        } else {
            func_02045CAC(((struct Obj00273 *)p)->f24, 7, ((struct Obj00273 *)p)->f38);
            GSYNC_MENU_PrintMessageNoStream(p);
            GSYNC_MENU_SetPaletteFade(p, 1);
            GSYNC_MENU_ChangeState(p, GSYNC_MENU_StateOpenYesNoAfterMessage, 0x1e6);
        }
    } else if (((struct Obj00273 *)p)->f8 == 2 || ((struct Obj00273 *)p)->f8 == 3) {
        GSYNC_MENU_ChangeState(p, GSYNC_MENU_StatePrintConfirmMessage, 0x1f2);
    } else {
        GSYNC_MENU_ChangeState(p, GSYNC_MENU_StateStartFadeOut, 0x1f5);
    }
}
