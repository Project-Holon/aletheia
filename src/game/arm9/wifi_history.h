#ifndef GAME_ARM9_WIFI_HISTORY_H
#define GAME_ARM9_WIFI_HISTORY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifi_history.c, prototypes copied from their definitions. */

struct WifiHistory;
struct SaveControl;
struct MyStatus;
struct HistoryEntry;

#include "../types.h"

struct WifiHistory *WIFI_HISTORY_GetBlock(struct SaveControl *saveControl);
void WIFI_HISTORY_InitLanguageRegion(struct WifiHistory *history, struct MyStatus *status, u8 country, u8 region);
u32 WIFI_HISTORY_GetCountryRegionState(const struct WifiHistory *history, int country, int region);
void WIFI_HISTORY_SetCountryRegionState(struct WifiHistory *history, int country, int region, int state);
u8 WIFI_HISTORY_GetMode(const struct WifiHistory *history);
void WIFI_HISTORY_PromoteVisitedStates(struct WifiHistory *history);
u8 WIFI_HISTORY_GetVisitedCountryCount(const struct WifiHistory *history);
u8 WIFI_HISTORY_GetDisplayCount(struct WifiHistory *history, struct MyStatus *status, int flag);
u8 WIFI_HISTORY_GetFirstFreeEntry(const struct WifiHistory *history);
void WIFI_HISTORY_IncrementVisitedCountryCount(struct WifiHistory *history);
void WIFI_HISTORY_SetRatingLevel(struct WifiHistory *history, int value);
u8 WIFI_HISTORY_GetRatingLevel(const struct WifiHistory *history);
void WIFI_HISTORY_SetGreetingSet(struct WifiHistory *history, int value);
u8 WIFI_HISTORY_GetGreetingSet(const struct WifiHistory *history);
u32 WIFI_HISTORY_GetEntryField(const struct WifiHistory *history, u32 index, u32 field);
void WIFI_HISTORY_SetEntryField(struct WifiHistory *history, int index, u32 field, u32 value);
struct HistoryEntry *WIFI_HISTORY_GetEntry(struct WifiHistory *history, int index);
struct HistoryEntry *WIFI_HISTORY_GetEntries(struct WifiHistory *history);
u32 WIFI_HISTORY_MarkCountryVisited(struct WifiHistory *history, u32 country);
u32 WIFI_HISTORY_IsCountryVisited(const struct WifiHistory *history, u32 country);
/* END mkheaders: generated region */

#endif
