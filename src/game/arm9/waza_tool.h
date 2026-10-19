#ifndef GAME_ARM9_WAZA_TOOL_H
#define GAME_ARM9_WAZA_TOOL_H

/* Public functions of waza_tool.c, prototypes copied from their definitions. */

struct WazaData;

u32 WAZA_TOOL_GetParam(u16 move, u32 param);
u32 WAZA_TOOL_GetDataParam(const struct WazaData *data, u32 param);
u32 WAZA_TOOL_GetFlag(u16 move, u32 flag);
u32 WAZA_TOOL_GetDataFlag(const struct WazaData *data, u32 flag);
s16 WAZA_TOOL_GetSickCont(u16 move);
u8 WAZA_TOOL_GetRankEffectCount(u16 move);
u8 WAZA_TOOL_GetRankEffect(u16 move, u32 index, s32 *value);
u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
u32 WAZA_TOOL_GetWeather(int item);
u32 WAZA_TOOL_GetCategory(u16 move);
u8 WAZA_TOOL_GetType(u16 move);
u16 WAZA_TOOL_GetPower(u16 move);
int WAZA_TOOL_GetDamageType(u16 move);
u32 WAZA_TOOL_IsAlwaysHit(u16 move);
u32 WAZA_TOOL_IsAlwaysCritical(u16 move);
u32 WAZA_TOOL_IsDamaging(u16 move);
void WAZA_TOOL_CreateCache(s32 count, u32 heap);
void WAZA_TOOL_DeleteCache(void);
u32 WAZA_TOOL_IsCacheCreated(void);

#endif
