/*
 * function: BOX2_SEQ_StateSwapConfirm
 * address: 0x021E3568
 * packet: pkt_ov170_021E3568
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_StateWaitInput 0x021E2094 thumb ov170
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23894.h"
struct WinMgr;
extern int BOX2_SEQ_StateWaitInput(char *);
typedef unsigned int   u32;
struct Sound;
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
extern void BOX2_SEQ_ShowWindowObject(char *, int);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_UI_ShowWindowB(char *);
#define W(p) (*(char **)((p) + 0x2C))
int BOX2_SEQ_StateSwapConfirm(unsigned char *p)
{
    int n;
    if (BOX2_SEQ_StateWaitInput((char *)p) == 6)
        return 0x18;
    if (CURSOR_MOVE_GetState(*(void **)(W(p) + 0x70)) == 1)
        BOX2_SEQ_SetActorDrawEnable(W(p), 4, 1);
    if ((unsigned char)W(p)[0xA173] == 5)
        n = 0x1B;
    else
        n = 0x18;
    BOX2_SEQ_ShowWindowObject(W(p), n);
    BOX2_MAIN_RefreshCursorBox((char *)p);
    if (((struct Obj23894 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24 == 2) {
        if (BOX2_UI_IsInfoBarOpen(*(struct WinMgr **)(W(p) + 0x74)) == 1)
            BOX2_UI_ShowWindowA(W(p));
        else
            BOX2_UI_ShowWindowB(W(p));
    }
    W(p)[0xA173] = 0;
    return ((struct Obj00000 *)p)->f28;
}
