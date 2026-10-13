/*
 * function: FIELD_SUBSCREEN_InitCGear
 * address:  0x021A0FE8
 * packet:   pkt_ov021_021A0FE8
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
 *   func_02009208  0x02009208  thumb
 *   func_02009200  0x02009200  thumb
 *   GAMESYSTEM_GetAlwaysNetFlag  0x0201214C  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   GAMESYSTEM_ClearNetOffBySleep  0x02012210  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   C_GEAR_Create  0x021F279C  thumb  ov029
 *   abs_id_1d      0x0000001D  data
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern unsigned char abs_id_1d[];
typedef unsigned char  u8;
struct Big;
struct Ctx;
struct Sub020090B0Obj;
struct Sub02009210Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern u8 func_02009208(const struct Sub020090B0Obj *obj);
extern void func_02009200(u32, u32);
struct Ctx;
extern u32 GAMESYSTEM_GetAlwaysNetFlag(const struct Ctx *);
extern u32 GAMESYSTEM_IsNetOffBySleep(const struct Ctx *p);
extern void GAMESYSTEM_ClearNetOffBySleep(struct Ctx *p);
extern int func_02034AC4(int);
extern void *C_GEAR_Create(int a, int b, int c, int d);

void FIELD_SUBSCREEN_InitCGear(u32 *p)
{
    u32 a, b, c, d;
    a = (u32)FIELDMAP_GetGameSystem((void *)p[5]);
    b = (u32)func_02009210(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData((const struct Ctx *)a)));
    func_02034AC4((int)abs_id_1d);
    c = func_02009208((const struct Sub020090B0Obj *)b);
    d = GAMESYSTEM_GetAlwaysNetFlag((const struct Ctx *)a);
    p[8] = (u32)C_GEAR_Create(b, (int)p, a, d == 1 && c == 0);
    func_02009200(b, d);
    if (GAMESYSTEM_IsNetOffBySleep((const struct Ctx *)a) != 0)
        GAMESYSTEM_ClearNetOffBySleep((struct Ctx *)a);
}
