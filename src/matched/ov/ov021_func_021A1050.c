/*
 * function: FIELD_SUBSCREEN_InitCGearWithCallback
 * address:  0x021A1050
 * packet:   pkt_ov021_021A1050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 *   func_02034AC4  0x02034AC4  arm
 *   C_GEAR_Open  0x021F27D8  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern unsigned char abs_id_1d[];
struct Big;
struct Ctx;
struct Sub02009210Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void func_02009200(u32, u32);
struct Ctx;
extern u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *p);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void GAMESYSTEM_ClearNetOffBySleep(struct Ctx *p);
extern int func_02034AC4(int);
extern char *C_GEAR_Open(int a0, int a1, int a2, void (*cb)(int), int arg, int flag);

void FIELD_SUBSCREEN_InitCGearWithCallback(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)FIELDMAP_GetGameSystem((void *)p[5]);
    b = (u32)GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)a));
    func_02034AC4((int)abs_id_1d);
    c = GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)a);
    d = (u32)func_02009210((void *)b);
    p[8] = (u32)C_GEAR_Open(d, (int)p, (int)FIELDMAP_GetGameSystem((void *)p[5]), (void (*)(int))p[6], p[7], c);
    func_02009200(d, c);
    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)a) != 0)
        GAMESYSTEM_ClearNetOffBySleep((struct Ctx *)a);
    p[0] = 0;
    p[1] = 0;
}
