/*
 * function: ITEMMENU_UpdateSideButtons
 * address:  0x021BB3F4
 * packet:   pkt_ov070_021BB3F4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ITEMMENU_PocketToSortFlag  0x021BB368  thumb  ov070
 *   ITEMMENU_UpdateInputGuardAnim  0x021BB5A4  thumb  ov070
 *   ITEMMENU_SetBackButtonAnim  0x021BB580  thumb  ov070
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   func_020056BC  0x020056BC  thumb
 *   PALANM_RequestFade  0x0202173C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern int ITEMMENU_PocketToSortFlag(int);
struct Obj;
struct PalAnmSlot;
extern void ITEMMENU_UpdateInputGuardAnim(char *p);
extern void ITEMMENU_SetBackButtonAnim(char *p, int v);
extern int GAME_DATA_ContainsRecentId(int, int);
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(int p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, u32 ctx);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

void ITEMMENU_UpdateSideButtons(int p, int mode)
{
    int r;

    if (((struct Obj00002 *)p)->f858 == mode) {
        return;
    }
    ((struct Obj00002 *)p)->f858 = mode;
    r = GAME_DATA_ContainsRecentId(*(int *)&((struct Obj00002 *)p)->f0, ITEMMENU_PocketToSortFlag(((struct Obj00002 *)p)->f80C));
    if (mode == 1) {
        PALANM_RequestFade(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        PALANM_RequestFade(((struct Obj00002 *)p)->f854, 1, 1, 0, 0, 0, 0, func_020056BC());
        G2x_SetBlendBrightness_(0x04000050, 6, 0);
        ITEMMENU_UpdateInputGuardAnim((char *)p);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f710), 4);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f714), 5);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f71C), 0);
        if (r == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 7);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 6);
        }
        ITEMMENU_SetBackButtonAnim((char *)p, 1);
    } else {
        PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)(((struct Obj00002 *)p)->f854), 2, 0, 0x200);
        PALANM_RequestFade(((struct Obj00002 *)p)->f854, 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        PALANM_RequestFade(((struct Obj00002 *)p)->f854, 1, 1, 0, 8, 8, 0, func_020056BC());
        if (((struct Obj00002 *)p)->f10 == 4 && CLACT_GetActorDrawEnable((struct Obj *)(((struct Obj00002 *)p)->f710)) == 0) {
            G2x_SetBlendBrightness_(0x04000050, 2, -8);
        } else {
            G2x_SetBlendBrightness_(0x04000050, 6, -8);
        }
        CLACT_SetActorAnimSeq((struct Obj *)(*(int *)&((struct Obj00002 *)p)->f72C), 4);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f710), 0x12);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f714), 0x13);
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f71C), 0xE);
        if (r == 1) {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 0x16);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00002 *)p)->f718), 0x15);
        }
    }
}
