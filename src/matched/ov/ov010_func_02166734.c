/*
 * function: SYMBOL_MAP_ScrCmdGetEventStateValue
 * address:  0x02166734
 * packet:   pkt_ov010_02166734
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The five unlabelled leaf callees are filed as their own shards
 * (matched witnesses): SYMBOL_MAP_GetEventStateEntryValue.c, ov021_func_021C87A0.c,
 * ov021_func_021C87AC.c, ov021_func_021C87B8.c, ov021_func_021C87C8.c.
 * (ov128_func_021C87A0.c is a different overlay's function at that
 * address; ov010 runs with ov021 loaded.)
 * lever (wave 82 R8): each arm writes the store `*(u16 *)a = ...` out
 *   itself, case 8 included (`if (...) *a = 1; else *a = 0;`). Cross-jumping
 *   then leaves cases 5-8 branching onto case 4's `b` and case 8's else as a
 *   dead `b` onto default. A shared `v` stored after the switch is 170 B
 *   (36 bytes out); with case 8's `else v = 0;` it is 172 B but DIFF21
 *   (a/p colours swapped, direct branches). An inline switch helper is the
 *   same DIFF21.
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb ov010
 *   VM_GetU16  0x02011330  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb ov010
 *   SYMBOL_MAP_GetEventStateEntryValue  0x02166658  thumb ov010
 *   PLEASURE_BOAT_GetPassengerParam  0x021C87A0  thumb ov021
 *   PLEASURE_BOAT_GetPassengerType  0x021C87AC  thumb ov021
 *   PLEASURE_BOAT_GetPassengerExtra  0x021C87B8  thumb ov021
 *   PLEASURE_BOAT_GetPassengerOccupied  0x021C87C8  thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
struct Big;
struct Stream;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetEventState(struct Big *p);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern u16 VM_GetU16(struct Stream *s);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 SYMBOL_MAP_GetEventStateEntryValue(void *p, u32 i);
extern u32 PLEASURE_BOAT_GetPassengerParam(void *p, u32 i);
extern u32 PLEASURE_BOAT_GetPassengerType(void *p, u32 i);
extern u32 PLEASURE_BOAT_GetPassengerExtra(void *p, u32 i, u32 j);
extern u32 PLEASURE_BOAT_GetPassengerOccupied(void *p, u32 i);

int SYMBOL_MAP_ScrCmdGetEventStateValue(void *a, void *b)
{
    u8 *p;
    u32 x;
    u16 k;
    u32 y;

    SCRCMD_WORK_GetScriptWork(b);
    p = GAME_DATA_GetEventState((struct Big *)GAMESYSTEM_GetGameData((const struct Ctx *)SCRCMD_WORK_GetGameSystem(b)));
    x = SCRIPT_WORK_ReadWorkValue(a, b);
    k = VM_GetU16((struct Stream *)a);
    y = SCRIPT_WORK_ReadWorkValue(a, b);
    a = SCRIPT_WORK_ReadWorkPointer(a, b);
    switch (k) {
    case 4:
        *(u16 *)a = SYMBOL_MAP_GetEventStateEntryValue(*(void **)p, x);
        break;
    case 5:
        *(u16 *)a = PLEASURE_BOAT_GetPassengerParam(*(void **)p, x);
        break;
    case 6:
        *(u16 *)a = PLEASURE_BOAT_GetPassengerType(*(void **)p, x);
        break;
    case 7:
        *(u16 *)a = PLEASURE_BOAT_GetPassengerExtra(*(void **)p, x, y);
        break;
    case 8:
        if (PLEASURE_BOAT_GetPassengerOccupied(*(void **)p, x) != 0)
            *(u16 *)a = 1;
        else
            *(u16 *)a = 0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    default:
        *(u16 *)a = 0;
        break;
    }
    return 0;
}
