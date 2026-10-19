/*
 * function: FIELDMAP_ApplyPlayerFormRequest
 * address:  0x02188BF8
 * packet:   pkt_ov021_02188BF8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
struct Sub02008C20Obj;
extern int FIELD_PLAYER_StepFormChange(u8 *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);

u32 FIELDMAP_ApplyPlayerFormRequest(u8 *a)
{
    u32 r = 0;
    u32 t = FIELD_PLAYER_GetFormCode((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C));

    if (t == 1) {
        r = 1;
        FIELD_PLAYER_StartFormChange((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C), 1);
    } else if (t == 0) {
        r = 1;
        GFL_USE_PlaySeDefaultVolume(0x55F);
        FIELD_PLAYER_StartFormChange((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C), 2);
        func_02008DF0(GAME_DATA_GetTrainerRecord((int *)(*(u32 *)&((struct Obj00020 *)a)->f8)), 3);
    }
    if (r == 1)
        FIELD_PLAYER_StepFormChange((u8 *)(*(u32 *)&((struct Obj00020 *)a)->f8C));
    return r;
}
