#ifndef GAME_OV176_BATTLE_CHAMPIONSHIP_FLOW_TYPES_H
#define GAME_OV176_BATTLE_CHAMPIONSHIP_FLOW_TYPES_H

#include "../types.h"
#include "../ov176/livebattlematch_shared_types.h"

/* The caller supplied context (only the fields this file reads). */
typedef struct {
    void *save;          /* 00 save control handed to GAME_DATA_GetSaveControl */
    int mode;            /* 04 selects the first flow handler */
    int state;           /* 08 extra state the menu flow reports back */
    void *battleData;    /* 0C copied into the live match 0x1BC slot */
    void *partyData;     /* 10 copied into the live match 0x1C0 slot */
    void *stateObj;      /* 14 copied into the live match 0x1C4 slot */
} BattleChampionshipFlowContext;

/* The championship flow proc work (0x34 bytes), the object every handler
 * of the first flow (BATTLE_CHAMPIONSHIP_FLOW_Create .. BATTLE_CHAMPIONSHIP_FLOW_CreateText) receives. */
typedef struct {
    u16 heapId;          /* 00 heap the flow runs on (0x4e) */
    u8  pad_2[2];
    struct WifibattlematchCallback *proc; /* 04 sub proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    struct WifibattlematchUtilWork *printSys; /* 08 message window created by WIFIBATTLEMATCH_UTIL_Create */
    struct GfFont *font; /* 0C font created by GF_FONT_Create */
    struct MsgBank *msgBank; /* 10 message bank created by MSGDATA_CreateFromArchive */
    struct PrintQueue *printQue; /* 14 print queue created by PRINTSYS_QUE_Create */
    u8  pad_18[8];
    struct WifiBattleMatchViewAnimState *view; /* 20 view object created by WIFIBATTLEMATCH_VIEW_Create */
    struct WifibattlematchGraphic *graphic; /* 24 graphic object created by WIFIBATTLEMATCH_GRAPHIC_Create */
    BattleChampionshipFlowContext *context; /* 28 the caller supplied context */
    void *flow;          /* 2C the second flow object (menu or live match) */
    int useAltFlow;      /* 30 non zero selects the live battle match flow */
} BattleChampionshipFlowWork;

/* The menu work of the first flow (0x3c bytes), built by BATTLE_CHAMPIONSHIP_FLOW_CreateMenu and
 * driven by the BATTLE_CHAMPIONSHIP_FLOW_MenuMain / BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse / BATTLE_CHAMPIONSHIP_FLOW_MenuExtra state machines. */
typedef struct {
    struct WifibattlematchCallback *proc; /* 00 proc created by WIFIBATTLEMATCH_UTIL_CreateCallback */
    struct WifibattlematchMenu *window; /* 04 window returned by WIFIBATTLEMATCH_UTIL_CreateMenu */
    int index;           /* 08 index last drawn */
    struct MsgBank *msgBank; /* 0C message bank created by MSGDATA_CreateFromArchive */
    int result;          /* 10 menu result read by BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult */
    RequestConfig config; /* 14 copied from the flow work; slot is the phase selected by BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase */
    u16 heapId;          /* 34 heap the menu runs on */
    u8  pad_36[2];
    LivebattlematchRequest *cardCheck; /* 38 digital card check created by DIGITALCARDCHECK_Create */
} BattleChampionshipFlowMenu;

#endif
