#ifndef OV101_COMPATIBLE_IRC_SYS_TYPES_H
#define OV101_COMPATIBLE_IRC_SYS_TYPES_H
/*
 * Types of the infrared compatibility check shared by compatible_irc_sys.c
 * (network session, profile transfer) and irc_compatible.c (screens and score).
 */

#include "../types.h"

/* Profile record exchanged between the two consoles (44 bytes). */
typedef struct IrcCompatibleProfile {
    u32 packedDate;                  /* 0x00 RTC year, month, day, weekday, one byte each */
    u8 birthMonth;                   /* 0x04 owner info */
    u8 birthDay;                     /* 0x05 owner info */
    u16 leadSpecies;                 /* 0x06 first party member, param 5 */
    u8 leadType2;                    /* 0x08 first party member, param 111 */
    u8 leadType1;                    /* 0x09 first party member, param 110 */
    u8 leadNature;                   /* 0x0A first party member, param 76 */
    unsigned char isDay14:4;        /* 0x0B low nibble: RTC day is 14 */
    unsigned char reservedHigh:4;    /* 0x0B high nibble */
    u8 myStatus[32];                 /* 0x0C trainer card copy */
} IrcCompatibleProfile;

struct IrcSys;

/* Request, acknowledge and profile transfer over the command table 0x1000..0x1003 (52 bytes). */
typedef struct IrcProfileSync {
    struct IrcSys *sys;              /* 0x00 owning session */
    int state;                       /* 0x04 profile send step */
    int partnerRequest[2];           /* 0x08 request words received from the partner */
    int ownRequest[2];               /* 0x10 request words sent to the partner */
    int requestReceived;             /* 0x18 */
    int ackReceived;                 /* 0x1C */
    int doneReceived;                /* 0x20 */
    int profileReceived;             /* 0x24 */
    IrcCompatibleProfile *sendProfile;    /* 0x28 */
    IrcCompatibleProfile *selfProfile;    /* 0x2C profile of this console, by aid */
    IrcCompatibleProfile *partnerProfile; /* 0x30 profile of the partner */
} IrcProfileSync;

/* Infrared session object of the compatibility check (140 bytes, heap allocated). */
typedef struct IrcSys {
    void *playerRecords;             /* 0x00 */
    IrcProfileSync profileSync;     /* 0x04 */
    int ownValue;                    /* 0x38 value this console sends */
    int partnerValue;                /* 0x3C value received from the partner */
    int context;                     /* 0x40 */
    int step;                        /* 0x44 state of the running step function */
    int stepWork;                    /* 0x48 */
    int readyMask;                   /* 0x4C bit per ready player */
    int partnerReady;                /* 0x50 */
    int exitDone;                    /* 0x54 */
    u8 reserved58[0x10];             /* 0x58 */
    int receivedValue[2];            /* 0x68 value per aid, parent side */
    int valueAckReceived;            /* 0x70 */
    int sessionReady;                /* 0x74 */
    int offline;                     /* 0x78 nonzero: every network call is skipped */
    u8 reserved7C[6];                /* 0x7C */
    u16 syncCounter;                 /* 0x82 */
    int connecting;                  /* 0x84 */
    u16 heapId;                      /* 0x88 */
    u16 pad8A;                       /* 0x8A */
} IrcSys;

/*
 * Parameter blocks of the compatibility check steps. Each step task receives one
 * and writes its results into the "out" fields; owned here for ov101 to ov106.
 */
typedef struct IrcMenuArgs {
    void *gameSystem;
    IrcSys *view;
    int mode;                /* 0 first entry, 1 normal, 2 back from help */
    int choice;              /* out */
    IrcCompatibleProfile *profile;
} IrcMenuArgs;

typedef struct IrcSecondTestArgs {
    void *gameSystem;
    IrcSys *view;
    IrcCompatibleProfile *profile;
    int result;              /* out */
    u8 score;                /* out */
    u8 penalty;              /* out */
    u8 bonus;                /* out */
    u8 pad13;
} IrcSecondTestArgs;

typedef struct IrcFirstTestArgs {
    void *gameSystem;
    IrcSys *view;
    IrcCompatibleProfile *profile;
    int result;              /* out */
    u8 score;                /* out */
    u8 pad11[3];
    int penalty;             /* out */
} IrcFirstTestArgs;

typedef struct IrcResultArgs {
    void *gameSystem;
    IrcSys *view;
    IrcCompatibleProfile *profile;
    u8 compatibility;
} IrcResultArgs;

typedef struct IrcHelpArgs {
    void *gameSystem;
} IrcHelpArgs;

#endif
