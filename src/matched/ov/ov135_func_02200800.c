/*
 * function: WORLDTRADE_TITLE_StateConfirmYesNoInput
 * address: 0x02200800
 * packet: pkt_ov135_02200800
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: if/else dispatch retains the compare after the first full arm.
 * symbols:
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj00045.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WORLDTRADE_UpdateTaskMenuYesNo(char *p);
extern void WORLDTRADE_CloseTaskMenu(char *p);
extern void WORLDTRADE_SetStateAndReturn(u8 *p, u32 a, u32 b);
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
int WORLDTRADE_TITLE_StateConfirmYesNoInput(u8 *p)
{
    u32 w;
    u32 state;
    state = WORLDTRADE_UpdateTaskMenuYesNo((char *)p);
    if (state == 1) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        w = ((struct Obj00045 *)p)->fDE0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        func_02040588(6, 0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00045 *)p)->fD38, 0);
        WORLDTRADE_SetStateAndReturn(p, 0, 0x14);
        ((struct Obj00045 *)p)->f28 = 7;
    } else if (state == 2) {
        WORLDTRADE_CloseTaskMenu((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00045 *)p)->fBF4, 1);
        ((struct Obj00045 *)p)->f28 = 5;
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00045 *)p)->fBF4, 1);
    }
    return 2;
}
