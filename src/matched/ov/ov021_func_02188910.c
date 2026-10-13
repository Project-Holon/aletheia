/*
 * function: FIELDMAP_SeqUpdateTop
 * address:  0x02188910
 * packet:   pkt_ov021_02188910
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_ResetWalkCount  0x020129F0  thumb
 *   FIELD_G3D_MAPPER_StepBlocks  0x0218CC34  thumb
 *   FIELD_SUBSCREEN_MainNoTransition  0x021A0E58  thumb
 *   FIELD_MSGBG_Main  0x021903E0  thumb
 *   FIELD_PLACE_NAME_Draw  0x021BC4F0  thumb
 *   FIELDMAP_DrawEnd  0x021890AC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04193.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 GAME_DATA_IsSaving(const u8 *o);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct BigObj;
extern void GAME_DATA_ResetWalkCount(struct BigObj *p);
extern void FIELD_G3D_MAPPER_StepBlocks(u32 a);
extern void FIELD_SUBSCREEN_MainNoTransition(u32 *a);
struct Obj;
extern void FIELD_MSGBG_Main(struct Obj *p);
extern void FIELD_PLACE_NAME_Draw(int a);
extern void FIELDMAP_DrawEnd(unsigned char *p);

u32 FIELDMAP_SeqUpdateTop(void *a, u8 *b)
{
    if (GAME_DATA_IsSaving((const u8 *)(((struct Obj04193 *)b)->f8)) != 0) {
        GAME_DATA_ResetWalkCount(GAMESYSTEM_GetGameData(a));
        return 0;
    }
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELD_G3D_MAPPER_StepBlocks(((struct Obj04193 *)b)->f48);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    FIELD_SUBSCREEN_MainNoTransition((u32 *)(((struct Obj04193 *)b)->f24));
    if (((struct Obj04193 *)b)->f28 != 0)
        FIELD_MSGBG_Main((struct Obj *)((struct Obj04193 *)b)->f28);
    if (((struct Obj04193 *)b)->f30 != 0)
        FIELD_PLACE_NAME_Draw((int)((struct Obj04193 *)b)->f30);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
    FIELDMAP_DrawEnd(b);
    *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    GAME_DATA_ResetWalkCount(GAMESYSTEM_GetGameData(a));
    return 0;
}
