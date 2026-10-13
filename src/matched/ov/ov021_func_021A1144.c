/*
 * function: FIELD_SUBSCREEN_InitNoGear
 * address:  0x021A1144
 * packet:   pkt_ov021_021A1144
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   NO_GEAR_Create  0x021F00C8  thumb  ov030
 *   abs_id_1e      0x0000001E  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_1e[];
extern int func_02034AC4(signed int);
struct Big;
struct Ctx;
struct Sub02009210Obj;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern char *NO_GEAR_Create(u32 a, u32 *b, u32 c);

void FIELD_SUBSCREEN_InitNoGear(u32 *p)
{
    u32 x;
    func_02034AC4((int)abs_id_1e);
    x = (u32)func_02009210(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p[5]))));
    p[8] = (u32)NO_GEAR_Create(x, p, (u32)FIELDMAP_GetGameSystem((void *)p[5]));
}
