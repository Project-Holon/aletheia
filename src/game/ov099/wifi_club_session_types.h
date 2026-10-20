#ifndef WIFI_CLUB_SESSION_TYPES_H
#define WIFI_CLUB_SESSION_TYPES_H

#include "../types.h"

struct WifiClubPlayerStatus;

/* Session record the work object points to (WifiClubWork.session). */
typedef struct WifiClubSession {
    struct WifiClubPlayerStatus *localStatus;  /* 0x00 */
    void *gameData;                /* 0x04 */
    void *saveData;                /* 0x08 */
    int isFriendMatch;             /* 0x0C: nonzero when the visit started from a friend match */
    int targetFriendIndex;         /* 0x10: friend picked by the network layer when the visit ends */
    void *seatParty[2];            /* 0x14: party snapshot sent for the parent and child seat */
    void *regulation;              /* 0x1C: regulation data copied out when the visit ends */
    u8 ruleOption;                 /* 0x20: option picked in the rule menu (stored as 1 - choice) */
    u8 ruleKind;                   /* 0x21: rule kind picked in the rule menu */
    u8 ruleLevel;                  /* 0x22: rule level picked in the rule menu */
    u8 pad23;
    u8 memberChangeCount[32];      /* 0x24: changeCount last seen for each member slot */
    u8 voiceChat[2];               /* 0x44: voice chat flag per seat (index 0 = local console) */
    u8 ownSeat;                    /* 0x46: seat index of this console (0 or 1) */
    u8 visitedSeat;                /* 0x47: seat copied into WifiClubWork.selectedPlusOne on return */
    u8 regulationId;               /* 0x48: rule set shown in the violation list */
    u8 connectionMode;             /* 0x49 */
} WifiClubSession;

#endif
