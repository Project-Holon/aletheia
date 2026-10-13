#ifndef GAME_ARM9_GAME_BEACON_TYPES_H
#define GAME_ARM9_GAME_BEACON_TYPES_H

/* game_beacon.c: the wireless beacon (C-Gear) information. The ov010
 * game_beacon_search.c file sends and reads the same 0x5C-byte block. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;

struct GameData;

/* Easy chat sentence copied into the beacon. */
typedef struct GameBeaconPms {
    u16 sentenceType;
    u16 sentenceId;
    u16 word[2];
} GameBeaconPms;

/* The broadcast part of a beacon, 0x5C bytes. */
typedef struct GameBeaconInfo {
    u8  versionBit;             /* 0x00: one bit per game version that accepts it */
    u8  nation;                 /* 0x01 */
    u8  area;                   /* 0x02 */
    u8  infoVersion : 7;        /* 0x03 */
    u8  sex : 1;
    u32 thanksCount : 17;       /* 0x04 */
    u32 zoneId : 10;
    u32 language : 5;
    u32 passCount : 17;         /* 0x08 */
    u32 serialNo : 5;           /* bumped on every send */
    u32 townmapRootZoneId : 10;
    u32 pmVersion : 6;          /* 0x0C */
    u32 trainerView : 3;
    u32 researchTeamRank : 3;
    u32 favoriteColor : 4;
    u32 playHours : 10;
    u32 playMinutes : 6;
    u16 trainerId;              /* 0x10 */
    u16 name[7];                /* 0x12 */
    u16 greeting[8];            /* 0x20 */
    u16 action;                 /* 0x30: GAME_BEACON action number */
    u16 actionArg;              /* 0x32: pokemon number for the pokemon actions */
    union {
        u16 value;              /* 0x34: play hours, item number, trainer id */
        u16 nickname[10];       /* 0x34: pokemon nickname */
        u8  byteValue;          /* 0x34: action 0x2C */
        u32 wordValue;          /* 0x34: preset event, actions 0x29, 0x2A */
        u16 text[10];           /* 0x34: thanks player name, free text */
        struct {
            u16 monsNo;             /* 0x34: distributed pokemon (0x19) */
            u16 itemNo;             /* 0x36: distributed item (0x1A) */
            u16 serial;             /* 0x38: distribution serial (0x32) */
            u16 reserved;
            u32 eventKey;           /* 0x3C: distribution actions */
            u16 reserved2[3];
            u16 targetTrainerId;    /* 0x46: action sent to one trainer */
        } special;
    } actionData;
    union {
        u16 word;
        struct {
            u16 detailsType : 8;    /* 0..4 battles, 5 none */
            u16 pmsSentenceType : 3;
            u16 pmsSentenceId : 5;
        } bits;
    } detailsPms;               /* 0x48 */
    u16 pmsWord[2];             /* 0x4A */
    u16 detailsValue;           /* 0x4E: pokemon or trainer of the battle */
    u8  questionnaire[10];      /* 0x50: questionnaire answers */
    u8  reserved[2];
} GameBeaconInfo;


/* A beacon with its local bookkeeping, 0x60 bytes. */
typedef struct GameBeaconRecord {
    GameBeaconInfo info;        /* 0x00 */
    union {
        s16 actionFrames;       /* own beacon: frames the action has been shown */
        u16 receivedFrames;     /* log entry: frames since it was received */
    } elapsed;                  /* 0x5C */
    u8  sendRequest;            /* 0x5E */
    u8  reserved;
} GameBeaconRecord;

/* The 0xBB4-byte work block that GAME_BEACON_Work points to. */
typedef struct GameBeaconWork {
    struct GameData *gameData;      /* 0x000 */
    GameBeaconRecord own;           /* 0x004 */
    GameBeaconRecord log[30];       /* 0x064: ring of received beacons */
    u32 newMask;                    /* 0xBA4: one bit per log entry not yet seen */
    u32 receiveCount;               /* 0xBA8 */
    s8  oldestIndex;                /* 0xBAC */
    s8  newestIndex;                /* 0xBAD */
    s8  logCount;                   /* 0xBAE */
    u8  questionnaireUpdated;       /* 0xBAF */
    u16 lastPlayHours;              /* 0xBB0 */
    u8  reserved[2];
} GameBeaconWork;

#endif
