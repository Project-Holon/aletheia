#ifndef ALETHEIA_OV010_FIELD_EVENT_TYPES_H
#define ALETHEIA_OV010_FIELD_EVENT_TYPES_H

/*
 * Records shared by the field event files of ov010 (event_field_proclink.c,
 * event_poke_status.c, fld_btl_inst_tool.c, report_event.c,
 * trcard_sys.c) and their callers in other overlays. Pointers to types that
 * the including file declares itself use struct tags, so this header needs no
 * other include. */

/* Five words copied between the proc link work and the party list parameter. */
typedef struct ProcLinkCarry {
    unsigned int words[5];
} ProcLinkCarry;

/* Request record behind ProcLinkWork.context: the field that started the link and what it asks for. */
typedef struct ProcLinkContext {
    struct GameSystem *gameSystem;     /* 0x00 */
    void *fieldObject;          /* 0x04 */
    unsigned char reserved08[4];
    unsigned int originKind;             /* 0x0C: which menu or script started the link */
    unsigned char reserved10[0x18];
    unsigned int command;                /* 0x28: field command chosen in the app (also the sub-mode) */
    unsigned int partySlot;              /* 0x2C */
    unsigned int warpZoneId;             /* 0x30 */
    unsigned int warpX;                  /* 0x34 */
    unsigned int warpZ;                  /* 0x38 */
    unsigned int warpY;                  /* 0x3C */
} ProcLinkContext;

/* Work of the proc link event that launches one app and reads its result back. */
typedef struct ProcLinkWork {
    unsigned short eventKind;              /* 0x00 */
    unsigned char reserved02[6];
    unsigned int childResult;            /* 0x08 */
    unsigned int nextState;              /* 0x0C */
    unsigned int resultFlag;             /* 0x10 */
    struct GameEvent *event;           /* 0x14 */
    ProcLinkContext *context;   /* 0x18 */
    unsigned char reserved1C[0x18];
    unsigned char bagItemCheck[0x18];      /* 0x34 */
    ProcLinkCarry carry;        /* 0x4C */
    unsigned char resultSlot;              /* 0x60 */
    unsigned char reserved61;
    unsigned short resultValue;            /* 0x62 */
    unsigned int resultParam;            /* 0x64 */
    unsigned int purpose;                /* 0x68: why the party list or app was opened */
    unsigned int linkMode;               /* 0x6C */
} ProcLinkWork;

/* Party list screen parameter (0x98 bytes); the same record carries the result back. */
typedef struct PokeListParam {
    struct Party *party;        /* 0x00 */
    void *myItem;               /* 0x04 */
    void *mailBox;              /* 0x08 */
    void *playerSaveBlock;      /* 0x0C */
    unsigned char reserved10[4];
    struct Regulation *regulation; /* 0x14: set by the battle facility party pick */
    void *zukanSave;            /* 0x18 */
    ProcLinkCarry carry;        /* 0x1C */
    unsigned short zoneId;                 /* 0x30 */
    unsigned char reserved32[2];
    unsigned int listMode;               /* 0x34 */
    unsigned int listArg;                /* 0x38: item or move id */
    unsigned int selectedSlot;           /* 0x3C */
    unsigned int command;                /* 0x40: what the player chose, set by the screen */
    unsigned short argValue;               /* 0x44 */
    unsigned short argValue2;              /* 0x46 */
    unsigned char argByte;                 /* 0x48 */
    unsigned char selectOrder[6];          /* 0x49: slot numbers (1 based) in the order the player chose them */
    unsigned char reserved4F;
    unsigned int resultParam;            /* 0x50 */
    unsigned char reserved54[0xA];
    unsigned char fieldIndex;              /* 0x5E */
    unsigned char season;                  /* 0x5F */
    unsigned char reserved60[0x38];
} PokeListParam;

/* Work record of the save-report event; 0x1C bytes, allocated by the field object event that starts it. */
typedef struct ReportEventWork {
    struct SaveControl *saveControl;       /* 0x00 */
    struct GameSystem *gameSystem;         /* 0x04 */
    struct FieldMap *fieldMap;             /* 0x08 */
    struct FieldMsgBg *msgContext;         /* 0x0C */
    unsigned short heapId;                     /* 0x10 */
    unsigned char pad12[2];
    unsigned int *resultOut;                 /* 0x14 */
    struct ReportEventRes *res;            /* 0x18 */
} ReportEventWork;

typedef struct TrainerCardProfile {
    unsigned char formatVersion;            /* 0x00 */
    unsigned char pad01[2];
    unsigned char starCount;             /* 0x03 */
    unsigned char isLinkMode : 1;          /* 0x04 */
    unsigned char outfitVariant : 1;
    unsigned char hasEventFlag2402 : 1;
    unsigned char hasSignature : 1;
    unsigned char signatureStyle : 1;
    unsigned char reservedBit5 : 1;
    unsigned char flagFromParam : 1;
    unsigned char isEditing : 1;
    unsigned char pad05;
    unsigned char outfit;             /* 0x06 */
    unsigned char pad07;
    unsigned short badgeMask;            /* 0x08 */
    unsigned short name[8];        /* 0x0A */
    unsigned char pad1A[2];
    void *playTimeSource;            /* 0x1C */
    unsigned int money;                 /* 0x20 */
    unsigned int pokedexCount;            /* 0x24 */
    unsigned short trainerId;            /* 0x28 */
    unsigned short playHours;            /* 0x2A */
    unsigned short clearHour;          /* 0x2C */
    unsigned char playMinutes;             /* 0x2E */
    unsigned char startYear;           /* 0x2F */
    unsigned char startMonth;          /* 0x30 */
    unsigned char startDay;            /* 0x31 */
    unsigned char clearYear;           /* 0x32 */
    unsigned char clearMonth;          /* 0x33 */
    unsigned char clearDay;            /* 0x34 */
    unsigned char clearMinute;         /* 0x35 */
    unsigned char pad36[2];
    unsigned int recordSum0;            /* 0x38 */
    unsigned int recordSum1;            /* 0x3C */
    unsigned int recordSum2;            /* 0x40 */
    unsigned int recordSum3;            /* 0x44 */
    unsigned int signatureColor;            /* 0x48 */
    unsigned int recordSum4;            /* 0x4C */
    unsigned int recordSum5;            /* 0x50 */
    unsigned int recordSum6;            /* 0x54 */
    unsigned int badgeTotal;            /* 0x58 */
    unsigned short recordSum7;            /* 0x5C */
    unsigned short visitedSpotCount;            /* 0x5E */
    unsigned short recordSum8;            /* 0x60 */
    unsigned short badgeExtraCount;            /* 0x62 */
    unsigned short recordTopValue;            /* 0x64 */
    unsigned short recordTopFlag;            /* 0x66 */
    unsigned int isGameCleared : 1;        /* 0x68 */
    unsigned int hasBattleRecord : 1;
    unsigned int hasRecordSum8 : 1;
    unsigned int hasRecordFlag78 : 1;
    unsigned int hasRecordFlag79 : 1;
    unsigned short beaconRecord[4];        /* 0x6C */
    unsigned char signatureBitmap[0x600];      /* 0x74 */
} TrainerCardProfile;

#endif
