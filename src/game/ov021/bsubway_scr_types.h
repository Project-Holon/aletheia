#ifndef BSUBWAY_SCR_TYPES_H
#define BSUBWAY_SCR_TYPES_H

/*
 * Battle Subway script work (bsubway_scr.c): one 0x7EC-byte object that
 * BSUBWAY_SCR_CreateWork allocates and stores as the game data's bsubway work
 * pointer.  ov010 bsubway_comm.c reads the same object through a partial view
 * with the same field names at every offset it names.  BattleMon,
 * BtlInstTrainer and BtlInstDraw are the ov010 fld_btl_inst_tool.c layouts.
 */

#include "../ov010/fld_btl_inst_tool_shared_types.h"

typedef struct GameData GameData;
typedef struct GameSystem GameSystem;
typedef struct SaveControl SaveControl;
typedef struct BsubwayPlayData BsubwayPlayData;   /* save block 0x39 */
typedef struct BsubwayScoreData BsubwayScoreData; /* save block 0x3A */
typedef struct BsubwayWifiData BsubwayWifiData;   /* save block 0x3B */

/* The MyStatus layout of arm9 config.c (0x20 bytes). */
typedef struct BsubwayPartnerStatus {
    u16 name[8];        /* 0x00 */
    u32 id;             /* 0x10 */
    u32 profileId;      /* 0x14 */
    u8 language;        /* 0x18 */
    u8 version;         /* 0x19 */
    u8 gender;          /* 0x1A */
    u8 avatarId;        /* 0x1B */
    u8 outfit;          /* 0x1C */
    u8 outfitVariant;   /* 0x1D: passed as the union room look (cmd 411/412) */
    u8 reserved1E[2];
} BsubwayPartnerStatus;

typedef struct BsubwayStateBits {
    u16 winMaxReached : 1;  /* latched once the play data round count reaches 7 */
    u16 fixedBpMode : 2;    /* nonzero: fixed battle point award (10, or 30 for super modes) */
    u16 retireSelect : 1;   /* set when the player retires (comm select record) */
    u16 retireExtra : 1;
    u16 partnerNo : 3;      /* index into partners[] (ov010 partnerLook) */
    u16 flag8 : 1;
    u16 commMode : 1;       /* picks the comm table in cmd 400 */
    u16 btlRecState : 2;    /* 0 not checked, 1 checked, 2 a record exists */
    u16 flag12 : 1;
    u16 reserved13 : 3;
} BsubwayStateBits;

typedef struct BsubwayCommInfo {
    u8 myStatus[0x20];          /* 0x00 */
    u8 macAddress[6];           /* 0x20 */
    u16 magic;                  /* 0x26 */
} BsubwayCommInfo;

/* 0x46 bytes, halfword aligned (recvBuf follows at 0x6AE), so no u32 member
 * here; ov010 bsubway_comm.c also reads the first word as one u32 (value). */
typedef union BsubwaySendBuf {
    struct {
        u16 sex;
        u16 monsNo[2];
        u16 stage;
    } player;
    struct {
        u16 retire;
    } select;
    u8 raw[0x46];
} BsubwaySendBuf;

/* ov100 proc parameter (cmd 408/409). */
typedef struct BsubwayWifiProcParam {
    GameData *gameData;         /* 0x00 */
    u8 reserved04[0x18];
    u32 result;                 /* 0x1C: 11 while running, 12/13 when done */
    u8 reserved20[4];
} BsubwayWifiProcParam;

/* ov214 battle record proc parameter (cmd 348). */
typedef struct BsubwayBtlRecProcParam {
    GameData *gameData;         /* 0x00 */
    u32 mode;                   /* 0x04: 1 */
    u32 recordNo;               /* 0x08: 0 */
    u32 subwayFlag;             /* 0x0C: 1 */
    u32 category;               /* 0x10: per play mode table */
    int winCount;               /* 0x14 */
} BsubwayBtlRecProcParam;

/* Script command ids of the Battle Subway command function (case labels). */
typedef enum BsubwayScrCmd {
    BSUBWAY_SCR_CMD_GET_TRAIN_INDEX = 0,
    BSUBWAY_SCR_CMD_RESET_SYSTEM = 1,
    BSUBWAY_SCR_CMD_CLEAR_PLAY_DATA = 2,
    BSUBWAY_SCR_CMD_GET_PLAY_DATA_STATE = 3,
    BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_AT_PLAYER = 4,
    BSUBWAY_SCR_CMD_CLEAR_RETURN_LOCATION_FLAG = 5,
    BSUBWAY_SCR_CMD_GET_RECORD_WIN_COUNT = 6,
    BSUBWAY_SCR_CMD_BEGIN_PLAY_GET_MODE = 7,
    BSUBWAY_SCR_CMD_GET_NEXT_ROUND_FROM_SAVE = 8,
    BSUBWAY_SCR_CMD_GET_NEXT_ROUND = 11,
    BSUBWAY_SCR_CMD_GET_PLAYER_LOOK = 12,
    BSUBWAY_SCR_CMD_SET_NPC_DIRECTION = 13,
    BSUBWAY_SCR_CMD_GET_SCORE_FLAG = 14,
    BSUBWAY_SCR_CMD_SET_SCORE_FLAG = 15,
    BSUBWAY_SCR_CMD_GET_SCORE_FLAG_CLEAR = 16,
    BSUBWAY_SCR_CMD_SET_SCORE_FLAG_CLEAR = 17,
    BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_TABLE = 18,
    BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE = 19,
    BSUBWAY_SCR_CMD_SET_TRAIN_DOOR_STATE_OTHER = 20,
    BSUBWAY_SCR_CMD_GET_SAVED_PLAY_MODE = 21,
    BSUBWAY_SCR_CMD_IS_MULTI_PLAY_MODE = 22,
    BSUBWAY_SCR_CMD_SET_NPC_HEIGHT_AND_LOCK = 23,
    BSUBWAY_SCR_CMD_UNLOCK_NPC = 24,
    BSUBWAY_SCR_CMD_IS_NPC_PRESENT = 25,
    BSUBWAY_SCR_CMD_GET_NPC_TRAIN_STATE = 26,
    BSUBWAY_SCR_CMD_GET_RANK = 27,
    BSUBWAY_SCR_CMD_LOWER_RANK = 28,
    BSUBWAY_SCR_CMD_RAISE_RANK = 29,
    BSUBWAY_SCR_CMD_GET_SCORE_ROUND_VALUE = 30,
    BSUBWAY_SCR_CMD_GET_PARTNER_LOOK = 31,
    BSUBWAY_SCR_CMD_IS_BATTLE_REC_SAVED = 32,
    BSUBWAY_SCR_CMD_RESULT_FALSE_A = 33,
    BSUBWAY_SCR_CMD_SET_TRAIN_SIGN_DEFAULT = 34,
    BSUBWAY_SCR_CMD_SET_NPC_ANIMATION = 35,
    BSUBWAY_SCR_CMD_RESET_NPC_ANIMATION = 36,
    BSUBWAY_SCR_CMD_START_NPC_TASK = 37,
    BSUBWAY_SCR_CMD_GET_MODE_CLEARED = 38,
    BSUBWAY_SCR_CMD_IS_NPC_AVAILABLE = 39,
    BSUBWAY_SCR_CMD_GET_NPC_INFO_FIRST = 40,
    BSUBWAY_SCR_CMD_GET_NPC_INFO_SECOND = 41,
    BSUBWAY_SCR_CMD_GET_NPC_INFO_THIRD = 42,
    BSUBWAY_SCR_CMD_GET_WIFI_RECORD_COUNT = 43,
    BSUBWAY_SCR_CMD_START_SCREEN_TASK = 44,
    BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_TABLE = 45,
    BSUBWAY_SCR_CMD_SET_SCORE_FLAG_FIRST = 100,
    BSUBWAY_SCR_CMD_GET_SCORE_FLAG_FIRST = 101,
    BSUBWAY_SCR_CMD_NOP_A = 102,
    BSUBWAY_SCR_CMD_START_OV007_PROC_A = 103,
    BSUBWAY_SCR_CMD_START_OV007_PROC_B = 104,
    BSUBWAY_SCR_CMD_START_OV007_PROC_C = 105,
    BSUBWAY_SCR_CMD_GET_WIFI_FIELD_101 = 106,
    BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FE = 107,
    BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_11 = 108,
    BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_11 = 109,
    BSUBWAY_SCR_CMD_GET_WIFI_FIELD_FF = 110,
    BSUBWAY_SCR_CMD_START_PARTY_TASK = 111,
    BSUBWAY_SCR_CMD_GET_WIFI_FIELD_103 = 112,
    BSUBWAY_SCR_CMD_GET_WIFI_FIELD_102 = 113,
    BSUBWAY_SCR_CMD_RESULT_FALSE_B = 200,
    BSUBWAY_SCR_CMD_NOP_B = 201,
    BSUBWAY_SCR_CMD_NOP_C = 202,
    BSUBWAY_SCR_CMD_RESULT_FALSE_C = 203,
    BSUBWAY_SCR_CMD_START_PARTY_SELECT = 300,
    BSUBWAY_SCR_CMD_SET_SELECTED_MEMBERS = 301,
    BSUBWAY_SCR_CMD_RESULT_FALSE_D = 302,
    BSUBWAY_SCR_CMD_IS_WIN_MAX = 303,
    BSUBWAY_SCR_CMD_SET_LOSE_SCORE = 304,
    BSUBWAY_SCR_CMD_SET_CLEAR_SCORE = 305,
    BSUBWAY_SCR_CMD_SAVE_REST_PLAY_DATA = 306,
    BSUBWAY_SCR_CMD_CREATE_ROUND_TRAINERS = 307,
    BSUBWAY_SCR_CMD_GET_TRAINER_OBJ_CODE = 308,
    BSUBWAY_SCR_CMD_START_ENCOUNTER_TASK = 309,
    BSUBWAY_SCR_CMD_GET_PLAY_MODE = 310,
    BSUBWAY_SCR_CMD_SET_FIXED_BP_MODE = 311,
    BSUBWAY_SCR_CMD_GET_FIXED_BP_MODE = 312,
    BSUBWAY_SCR_CMD_GET_BATTLE_POINTS = 313,
    BSUBWAY_SCR_CMD_SET_PARTNER_NO = 314,
    BSUBWAY_SCR_CMD_GET_PARTNER_NO = 315,
    BSUBWAY_SCR_CMD_DRAW_TRAINER_NOS = 316,
    BSUBWAY_SCR_CMD_GET_MEMBER_INDEX = 317,
    BSUBWAY_SCR_CMD_CLEAR_RECV_BUF = 319,
    BSUBWAY_SCR_CMD_START_PARTNER_TASK_A = 320,
    BSUBWAY_SCR_CMD_SAVE_PLAY_DATA_MEMBERS = 321,
    BSUBWAY_SCR_CMD_SET_RETURN_LOCATION_FROM_MODE = 322,
    BSUBWAY_SCR_CMD_LOAD_MEMBERS = 323,
    BSUBWAY_SCR_CMD_SET_PLAY_DATA_BYTE_10 = 324,
    BSUBWAY_SCR_CMD_CHANGE_COMM_MULTI_MODE = 325,
    BSUBWAY_SCR_CMD_IS_UPPER_PLAY_MODE = 326,
    BSUBWAY_SCR_CMD_SPAWN_FIELD_OBJECTS = 329,
    BSUBWAY_SCR_CMD_SET_STATE_FLAG8 = 330,
    BSUBWAY_SCR_CMD_GET_STATE_FLAG8 = 331,
    BSUBWAY_SCR_CMD_IS_BATTLE_WON = 332,
    BSUBWAY_SCR_CMD_CLEAR_STATE_BITS = 333,
    BSUBWAY_SCR_CMD_SET_PROGRESS_RECORDS = 334,
    BSUBWAY_SCR_CMD_CREATE_PARTNERS = 335,
    BSUBWAY_SCR_CMD_GET_MEMBER_MONS_NO = 336,
    BSUBWAY_SCR_CMD_SET_COMM_MODE = 337,
    BSUBWAY_SCR_CMD_GET_COMM_MODE = 338,
    BSUBWAY_SCR_CMD_CHECK_PARTY_REGULATION = 339,
    BSUBWAY_SCR_CMD_LOAD_PARTY_COPY = 340,
    BSUBWAY_SCR_CMD_GET_REGULATION_NO = 341,
    BSUBWAY_SCR_CMD_GET_MEMBER_NUM = 342,
    BSUBWAY_SCR_CMD_CHECK_BATTLE_REC_SLOT = 343,
    BSUBWAY_SCR_CMD_GET_BATTLE_REC_EXISTS = 344,
    BSUBWAY_SCR_CMD_SAVE_BATTLE_REC_FROM_SETUP = 345,
    BSUBWAY_SCR_CMD_START_RESULT_MESSAGE = 346,
    BSUBWAY_SCR_CMD_FREE_BATTLE_SETUP = 347,
    BSUBWAY_SCR_CMD_START_BATTLE_REC_PROC = 348,
    BSUBWAY_SCR_CMD_COMMIT_MODE_CLEAR = 349,
    BSUBWAY_SCR_CMD_RELEASE_TRAIN_SIGN = 350,
    BSUBWAY_SCR_CMD_GET_TRAINER_NO = 351,
    BSUBWAY_SCR_CMD_START_PARTNER_TASK_B = 352,
    BSUBWAY_SCR_CMD_ADD_BATTLE_TALLY = 353,
    BSUBWAY_SCR_CMD_SET_STATE_FLAG12 = 354,
    BSUBWAY_SCR_CMD_GET_STATE_FLAG12 = 355,
    BSUBWAY_SCR_CMD_GET_PLAY_DATA_BYTE_10 = 356,
    BSUBWAY_SCR_CMD_NEXT_ROUND_GET_WIN_COUNT = 357,
    BSUBWAY_SCR_CMD_GET_WIN_COUNT = 358,
    BSUBWAY_SCR_CMD_COMMIT_FIRST_CLEAR = 359,
    BSUBWAY_SCR_CMD_START_COMM_SESSION = 400,
    BSUBWAY_SCR_CMD_START_COMM_CLOSE_TASK = 401,
    BSUBWAY_SCR_CMD_START_TIMING_SYNC = 402,
    BSUBWAY_SCR_CMD_START_COMM_CHECK_A = 403,
    BSUBWAY_SCR_CMD_START_COMM_CHECK_B = 404,
    BSUBWAY_SCR_CMD_SEND_COMM_COMMAND = 405,
    BSUBWAY_SCR_CMD_START_COMM_RECEIVE = 406,
    BSUBWAY_SCR_CMD_GET_COMM_PLAYER_ID = 407,
    BSUBWAY_SCR_CMD_START_WIFI_PROC = 408,
    BSUBWAY_SCR_CMD_GET_WIFI_PROC_RESULT = 409,
    BSUBWAY_SCR_CMD_SET_PARTNER_PROFILE_ID = 410,
    BSUBWAY_SCR_CMD_GET_LOOK_FIRST = 411,
    BSUBWAY_SCR_CMD_GET_LOOK_SECOND = 412,
    BSUBWAY_SCR_CMD_CLEAR_SYSTEM_FLAG = 413,
    BSUBWAY_SCR_CMD_SET_SYSTEM_MODE = 414,
    BSUBWAY_SCR_CMD_IS_SYSTEM_FLAG_SET = 415,
    BSUBWAY_SCR_CMD_IS_BATTLE_REC_PLAYABLE = 416,
    BSUBWAY_SCR_CMD_NOP_END = 501,
} BsubwayScrCmd;

typedef struct BsubwayScrWork {
    u32 magic;                      /* 0x000: 0x12345678 */
    u32 heapId;                     /* 0x004 */
    u8 memberNum;                   /* 0x008 */
    u8 playMode;                    /* 0x009 */
    u8 romCode;                     /* 0x00A */
    u8 partnerSex;                  /* 0x00B */
    BsubwayStateBits stateBits;     /* 0x00C */
    u16 winCount;                   /* 0x00E */
    u16 msgNumber;                  /* 0x010 */
    u16 sendCommand;                /* 0x012 */
    u8 reserved14[4];
    u16 partnerStage;               /* 0x018 */
    u16 partnerMonsNo[2];           /* 0x01A */
    u8 memberIndex[4];              /* 0x01E */
    u16 memberMonsNo[4];            /* 0x022 */
    u16 memberItemNo[4];            /* 0x02A */
    u16 trainerNo[14];              /* 0x032 */
    u8 reserved4E[0x6C - 0x4E];
    GameData *gameData;             /* 0x06C */
    BsubwayPlayData *playData;      /* 0x070 */
    BsubwayScoreData *scoreData;    /* 0x074 */
    BsubwayWifiData *wifiData;      /* 0x078 */
    u8 selectPos[4];                /* 0x07C */
    u8 reserved80[2];
    u16 selectMode;                 /* 0x082 */
    u16 selectCancel;               /* 0x084 */
    u8 reserved86[2];
    BtlInstTrainer trainers[2];     /* 0x088 */
    BtlInstTrainer partners[3];     /* 0x2C8 */
    BtlInstDraw partnerDraws[3];    /* 0x628 */
    u8 partnerResult[3];            /* 0x664 */
    u8 reserved667;
    BsubwaySendBuf sendBuf;         /* 0x668 */
    u8 recvBuf[0x46];               /* 0x6AE */
    BsubwayCommInfo commInfo;       /* 0x6F4 */
    void *commTask;                 /* 0x71C */
    u16 *commResultDst;             /* 0x720 */
    u8 recvCount;                   /* 0x724 */
    u8 recvMode;                    /* 0x725 */
    u8 reserved726;
    u8 timingNo;                    /* 0x727 */
    u16 recvResult;                 /* 0x728 */
    u16 resultWorkId;               /* 0x72A */
    BsubwayPartnerStatus partnerMyStatus; /* 0x72C */
    u8 reserved74C[0x7A4 - 0x74C];
    BsubwayWifiProcParam wifiProcParam;   /* 0x7A4 */
    void *partyCopy;                /* 0x7C8 */
    struct BattleSetupParam *btlSetup;             /* 0x7CC */
    BsubwayBtlRecProcParam btlRecProcParam; /* 0x7D0 */
    u16 msgState;                   /* 0x7E8 */
    u16 msgSubState;                /* 0x7EA */
} BsubwayScrWork;

#endif
