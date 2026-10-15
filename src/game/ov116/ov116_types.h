#ifndef ALETHEIA_OV116_TYPES_H
#define ALETHEIA_OV116_TYPES_H

/*
 * Types of the Battle Subway Wi-Fi screen (ov116). wifi_bsubway.c owns the
 * network, save and state-machine logic; wifi_bsubway_graphic.c draws it.
 * The work object is 0x185C bytes: a parent pointer, the graphic context, the
 * trainer record, the trainer status block and the async transfer state.
 */

/* Screen task the work object belongs to. */
struct WifiBsubwayParent {
    unsigned char pad00[4];
    void *proc;   /* 0x04: proc passed to GAMESYSTEM_CallProc */
    int state;    /* 0x08: state the parent drives */
};

/* Trainer record loaded from and stored to the battle subway save data. */
struct WifiBsubwayTrainers {
    int roomReady;                  /* 0x00: room-number request finished */
    int playerReady;                /* 0x04: player-download request finished */
    unsigned short roomNumber;      /* 0x08 */
    unsigned short playerIndex;     /* 0x0A */
    unsigned short downloadResult;  /* 0x0C */
    unsigned char records[7][240];  /* 0x0E: trainer records */
    unsigned char history[30][34];  /* 0x69E: recent trainer history */
    unsigned char padA9A[2];        /* 0xA9A */
};

/* Trainer profile sent to the battle subway server (240 bytes). */
struct WifiBsubwayProfile {
    unsigned char pad00[0xB4];
    unsigned char trainer[16];      /* 0xB4 */
    unsigned char version;          /* 0xC4 */
    unsigned char language;         /* 0xC5 */
    unsigned char unkC6;            /* 0xC6 */
    unsigned char unkC7;            /* 0xC7 */
    unsigned int trainerId;         /* 0xC8 */
    unsigned char record4[8];       /* 0xCC */
    unsigned char flags;            /* 0xD4 */
    unsigned char unkD5;            /* 0xD5 */
    unsigned char records[3][8];    /* 0xD6 */
    unsigned short unkEE;           /* 0xEE */
};

/* Trainer status and HTTP request block (0x21C bytes). */
struct WifiBsubwayStatus {
    int ready;                              /* 0x00 */
    unsigned char trainerInfo[0x64];        /* 0x04: NHTTP_RAP trainer info */
    void *profile;                          /* 0x68 */
    unsigned char pad06C[4];                /* 0x6C */
    struct WifiBsubwayProfile profileData;  /* 0x70 */
    void *saveBlockB;                       /* 0x160 */
    void *saveBlockA;                       /* 0x164 */
    void *http;                             /* 0x168: NHTTP_RAP connection */
    unsigned short recordCount;             /* 0x16C */
    unsigned char recvBuffer[0x80];         /* 0x16E */
    unsigned char pad1EE[2];                /* 0x1EE */
    unsigned short chars[12];               /* 0x1F0: message characters */
    void *wordList;                         /* 0x208 */
    char resultBuf[4];                      /* 0x20C */
    int badWordCount;                       /* 0x210 */
    unsigned short msgId;                   /* 0x214 */
    unsigned char pad216[2];                /* 0x216 */
    void *mystatus;                         /* 0x218 */
};

/* Asynchronous transfer state polled each frame (0x14 bytes). */
struct WifiBsubwayAsync {
    int result;                /* 0x00 */
    unsigned int flag;         /* 0x04 */
    unsigned short timedOut;   /* 0x08 */
    short ticks;               /* 0x0A */
    unsigned int state;        /* 0x0C */
    unsigned int httpCode;     /* 0x10 */
};

/* Per-screen work object (0x185C bytes). */
struct WifiBsubwayWork {
    struct WifiBsubwayParent *parent;       /* 0x0000 */
    unsigned char graphic[0x0B64];          /* 0x0004: graphic context (wifi_bsubway_graphic.c) */
    unsigned short dpwActive;               /* 0x0B68 */
    unsigned short dpwDone;                 /* 0x0B6A */
    unsigned char pad0B6C[8];               /* 0x0B6C */
    struct WifiBsubwayTrainers trainers;    /* 0x0B74 */
    struct WifiBsubwayStatus status;        /* 0x1610 */
    struct WifiBsubwayAsync async;          /* 0x182C */
    void *codeInParam;                      /* 0x1840 */
    void *saveControl;                      /* 0x1844 */
    void *field1848;                        /* 0x1848 */
    void *field184C;                        /* 0x184C */
    void *field1850;                        /* 0x1850 */
    void *saveBlock3B;                      /* 0x1854 */
    void *saveBlock3A;                      /* 0x1858 */
};

#endif
