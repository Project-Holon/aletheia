/*
 * Object layouts of the Wi-Fi club event (ov006): the event work and the
 * parameter blocks it hands to the overlays it launches.
 */
#ifndef EVENT_WIFICLUB_TYPES_H
#define EVENT_WIFICLUB_TYPES_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct GameSystem;
struct GameEvent;
struct GameData;
struct SaveControl;

/* Request read by the evolution demo overlay (ov195), 0x14 bytes. */
typedef struct EvolutionRequest {
    struct GameData *gameData;
    void *party;
    u16 partyIndex;
    u8  reserved;
    u8  evolveCondition;
    u32 fromTrade;
    u32 reserved2;
} EvolutionRequest;

/* Parameter block read by the Wi-Fi login overlay (ov115), 0x20 bytes. */
typedef struct WifiLoginParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
    u32 result;
} WifiLoginParam;

/* Short parameter block of the second ov115 call (session confirm), 0x1C bytes. */
typedef struct WifiConfirmParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
} WifiConfirmParam;

/* Parameter block read by the Pokemon trade overlay (ov119), 0x30 bytes. */
typedef struct ClubTradeParam {
    u32 reserved[2];
    u32 result;
    u32 partyIndex;
    u32 evolveCondition;
    struct GameData *gameData;
    void *reserved3;
    void *party;
    EvolutionRequest *evolutionRequest;
    u32 reserved4[2];
    u16 ruleId;
    u16 reserved5;
} ClubTradeParam;

/* Parameter block read by the camera overlay (ov172), 8 bytes. */
typedef struct ClubViewParam {
    struct GameData *gameData;
    u32 mode;
} ClubViewParam;

/* Heap blocks and selection state of one club session, 0x4C bytes. */
typedef struct WifiClubSession {
    void *scratchBuffer;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    u32 menuChoice;
    u32 reserved10;
    void *party[2];
    void *regulation;
    u8  isActive;
    u8  reserved21[0x25];
    u8  rulesLoaded;
    u8  ruleId;
    u8  useAltRule;
    u8  rematch;
    u8  reserved4A[2];
} WifiClubSession;

/* Entry of the battle start list, one per side (0x10 bytes). */
typedef struct ClubBattleSide {
    void *party;
    void *playerStatus;
    u8 reserved[8];
} ClubBattleSide;

/* Battle description built from the session (ov134 reads it), 0x28 bytes. */
typedef struct ClubBattleEntry {
    void *regulation;
    void *ownParty;
    void *partnerInfo;
    u8  partnerGender;
    void *partnerParty;
    void *gameData;
    u8  reserved18;
    void *battleParty;
    void *partyA;
    void *partyB;
} ClubBattleEntry;

/* Parameter block read by the battle start overlay (ov008), 0x18 bytes. */
typedef struct ClubBattleStartParam {
    struct GameData *gameData;
    void *battleSetup;
    ClubBattleSide *sides;
    u32 battleKind;
    u32 reserved;
    u32 enabled;
} ClubBattleStartParam;

/* Work of the Wi-Fi club event (0x174 bytes). */
typedef struct WifiClubEventWork {
    struct GameEvent *event;
    struct GameSystem *gameSystem;
    int fieldMap;
    struct WifiClubEventWork *self;
    u32 reserved10;
    u32 hideFieldObjects;
    u32 reserved18;
    void *loginTask;
    ClubBattleEntry battleEntry;
    u32 battleResult;
    ClubViewParam viewParam;
    u8  reserved54[8];
    WifiClubSession *session;
    ClubTradeParam tradeParam;
    struct GameData *paramGameData;
    u32 battleRecord;
    WifiLoginParam login;
    u8  reservedB8[8];
    WifiConfirmParam confirm;
    void *battleSetup;
    ClubBattleSide sides[2];
    u8  reserved100[0x20];
    u32 matchOutcome;
    u32 matchActive;
    u8  reserved128[0xC];
    void *trainerRecord;
    ClubBattleStartParam startParam;
    u8  reserved150[0x18];
    void *battleParty;
    u32 reserved16C;
    u16 savedBgmNo;
    u8  menuSelection;
    u8  reserved173;
} WifiClubEventWork;

#endif
