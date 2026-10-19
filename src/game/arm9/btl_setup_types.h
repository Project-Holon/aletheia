#ifndef GAME_ARM9_BTL_SETUP_TYPES_H
#define GAME_ARM9_BTL_SETUP_TYPES_H

/*
 * Objects of game_data.c and btl_setup.c.
 *
 * GameData is the 0x6B0-byte object that GAME_DATA_Create allocates (anchor
 * game_data.c) and GAME_DATA_Delete frees. The offsets come from that
 * constructor and from the accessors in btl_setup.c; names are inferred
 * from what each constructor call creates and what each accessor is used
 * for, so the thin ones can still be refined.
 *
 * BattleSetupParam is the 0xF0-byte object that BTL_SETUP_Create allocates
 * (anchor btl_setup.c) and the builders BTL_SETUP_SetupWild..BTL_SETUP_SetupCommRotation fill.
 */

/* A map position kept by the game data object (0x1C bytes). */
struct Location {
    unsigned int words[7];
};

/* World position of a player (three fixed-point words). */
struct PlayerPosition {
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

/* Rail position: copied as four halfwords, cleared field by field. */
struct RailLocationWords {
    unsigned short words[4];
};

union RailLocation {
    struct RailLocationWords all;
    struct {
        unsigned short lineIndex;
        unsigned char  type;
        unsigned char  key;
        unsigned short frontGrid;
        unsigned short sideGrid;
    } part;
};

/*
 * Status block of a player (0x20 bytes). GAME_DATA returns its address as
 * the player's status (GAME_DATA_GetMyStatus, GAME_DATA_GetPlayerStatus); the player work
 * constructor clears id, gender and romCode.
 */
struct PlayerStatus {
    unsigned short name[8];
    unsigned int   id;
    unsigned char  profile[6];
    unsigned char  gender;
    unsigned char  regionCode;
    unsigned char  trainerView;
    unsigned char  romCode;
    unsigned char  language[2];
};

/* One player's position record (0x44 bytes, five in GameData). */
struct PlayerWork {
    unsigned short       zoneId;
    unsigned short       railZoneId;
    struct PlayerPosition position;
    union RailLocation   rail;
    unsigned short       direction;
    unsigned char        posType;
    unsigned char        moveForm;
    unsigned short       palaceZoneId;
    unsigned char        pad1E[2];
    struct PlayerStatus  status;
    unsigned int         objectCode;
};

struct PlayTime;
struct Party;
struct Config;
struct SaveControl;

struct GameData {
    struct SaveControl *saveControl;
    struct PlayerWork playerWork[5];
    void            *eventData;
    unsigned int     situation;
    struct Location *startLocation;
    struct Location *entranceLocation;
    struct Location *specialLocation;
    struct Location *escapeLocation;
    struct Location  warpLocation;
    unsigned int     mapMatrix;
    void            *myItem;
    void            *myParty;
    struct Config   *config;
    unsigned int     boxManager;
    unsigned int     wifiList;
    unsigned int     bagCursor;
    void            *occupyInfo;
    void            *eventWork;
    unsigned int     fieldWork;
    unsigned int     bgmInfo;
    void            *moveModelSys;
    unsigned int     fieldMode;
    unsigned int     saveStatus;
    unsigned char    season;
    unsigned char    subscreenMode;
    unsigned char    subscreenType;
    unsigned char    fieldMenuCursor;
    unsigned char    walkCount;
    unsigned char    walkCountEnabled;
    unsigned char    enterMode;
    unsigned char    ownNetId;
    unsigned char    intrudeCount;
    unsigned char    intrudeId;
    unsigned char    isSaving;
    unsigned char    symbolMapFlag;
    unsigned char    slotFlags[4];
    unsigned char    battleRecSlot[4][0x10];
    unsigned char    unionInfo[2][0x1E8];
    unsigned int     fieldGimmick;
    unsigned char    rtcWork[4];
    unsigned char    fieldSave[0x94];
    unsigned int     eventState;
    int              pmsWork;
    void            *currentEvent;
    unsigned int     itemUseWork;
    unsigned int     musicalWork;
    unsigned char    saveSyncBlock[0x10];
    unsigned int     listCursor;
    void            *externalWork;
    struct PlayTime *playTime;
};

/* Battle field conditions (0x10 bytes at BattleSetupParam+0x08). */
struct FieldSituation {
    int            bgType;
    int            bgAttr;
    unsigned char  weather;
    unsigned char  season;
    unsigned short zoneId;
    unsigned char  hour;
    unsigned char  minute;
};

/* Random number generator state of a battle (24 bytes, copied by value). */
struct BattleRngState {
    unsigned int words[6];
};

/* Trainer slot of a battle (0x28 bytes, BTL_SETUP_CreateTrainerData). */
struct BattleTrainerData {
    unsigned int  trainerId;
    unsigned int  trainerType;
    unsigned int  aiFlags;
    unsigned short itemIds[4];
    void         *name;
    union { unsigned char winWord[8]; unsigned short winWords[4]; };
    union { unsigned char loseWord[8]; unsigned short loseWords[4]; };
};

/*
 * The battle reads this object and writes its results back. Fields that
 * btl_setup.c never touches between +0x86 and +0xF0 are named as result
 * areas (inferred); padding is named pad only where alignment needs it.
 */
struct BattleSetupParam {
    unsigned int             competitor;
    unsigned int             rule;
    struct FieldSituation    fieldSituation;
    unsigned short           bgmBattle;
    unsigned short           bgmWin;
    unsigned int             netHandle;
    unsigned char            commPos;
    unsigned char            netId;
    unsigned char            multiMode;
    unsigned char            ownsSlots;
    struct Party            *party[4];
    void                    *playerStatus[4];
    unsigned char            voiceFlags[4];
    struct BattleTrainerData *trainerData[4];
    struct GameData         *gameData;
    struct Config           *config;
    void                    *myItem;
    unsigned int             mapMatrix;
    void                    *zukanWork;
    void                    *trainerRecord;
    int                      pmsWork;
    unsigned short           limitTimeGame;
    unsigned short           limitTimeCommand;
    unsigned char            regulationRules[7];
    unsigned char            recordEnabled;
    unsigned char            badgeCount;
    unsigned char            pad81;
    unsigned short           statusFlags;
    unsigned short           levelCap;
    unsigned short           resultCount;
    int                      moneyDelta;
    unsigned int             moneyRate;
    unsigned char            resultValue[4];
    void                    *recordBuffer;
    unsigned int             recordSize;
    struct BattleRngState    rng;
    unsigned short           hpSum;
    unsigned char            turnCount;
    unsigned char            stats[6];
    unsigned char            won;
    unsigned char            enemyFainted;
    unsigned char            ownFainted;
    unsigned char            moveUseTotal;
    union {
        unsigned char            bitFlags;
        struct {
            unsigned char recordInvalid : 1;
            unsigned char recordComplete : 1;
            unsigned char hidePlayerNames : 1;
            unsigned char flagsRest : 5;
        } bits;
    };
    unsigned char            resultFlags[6];
    unsigned char            memberStatus[4][6];
    unsigned int             hpPercent[4];
};

#endif
