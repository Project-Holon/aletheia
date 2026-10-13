/*
 * function: FIELD_GIMMICK_GATE_GetSave
 * address: 0x021F37A4
 * packet: pkt_ov048_021F37A4
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb  arm9
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Big;
struct Ctx;
struct Rec94;
extern void *FIELDMAP_GetGameSystem(void *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
u8 *FIELD_GIMMICK_GATE_GetSave(u32 a) { u32 p; p=(u32)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))); return (u8 *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)p,func_0200B3AC((struct Rec94 *)p)); }
