/*
 * function: FIELD_SUBSCREEN_UpdateCGear
 * address:  0x021A10E0
 * packet:   pkt_ov021_021A10E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02009200  0x02009200  thumb
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   GAMESYSTEM_ClearNetOffBySleep  0x02012210  thumb
 *   C_GEAR_Restart  0x021F2994  thumb  ov029
 *   C_GEAR_Update  0x021F2848  thumb  ov029
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_02009200(struct Sub020090B0Obj *obj, u8 value);
struct Ctx;
extern u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void GAMESYSTEM_ClearNetOffBySleep(struct Ctx *p);
extern int C_GEAR_Restart(int *p);
extern u32 C_GEAR_Update(u32, u32);

u32 FIELD_SUBSCREEN_UpdateCGear(u32 *p, u32 x)
{
    u32 a, b;
    if (x != 0) {
        a = (u32)FIELDMAP_GetGameSystem((void *)p[5]);
        b = (u32)func_02009210(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)a)));
        if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)a) != 0) {
            if (GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)a) != 0) {
                GAMESYSTEM_ClearNetOffBySleep((struct Ctx *)a);
            } else if (C_GEAR_Restart((int *)p[8]) != 0) {
                func_02009200((struct Sub020090B0Obj *)b, 0);
                GAMESYSTEM_ClearNetOffBySleep((struct Ctx *)a);
            }
        }
    }
    return C_GEAR_Update(p[8], x);
}
