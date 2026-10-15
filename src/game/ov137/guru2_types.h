#ifndef GURU2_TYPES_H
#define GURU2_TYPES_H

/*
 * Owner header for the Guru2 (union room spinning-disc trade game) objects.
 * One struct per real object, sizes from the allocation calls:
 *   Guru2Entry    36 bytes, allocated by the entry proc init
 *   Guru2Session  36 bytes, allocated by Guru2Session_Create
 *   Guru2Comm     88 bytes (two 0x1BE4-byte buffers hang off it)
 * The game work (0xDAC bytes) is struct Guru2Game; the lobby work (0x4874
 * bytes) is still described by the Guru2MainCtx views in ov137_types.h.
 */

#include "guru2_shared_types.h"

struct Guru2Session;

/* Parameter block passed to the entry proc by the caller (union room). */
struct Guru2Param {
    void *unionApp;      /* 0x00 */
    void *gameData;      /* 0x04 */
    unsigned char unknown_08[8];
    void *playerInfo;    /* 0x10 */
    int resultFlag;      /* 0x14 */
};

/* Parameter block of the party list proc (external struct, partly known). */
struct Guru2PartyListParam {
    void *party;                      /* 0x00 */
    void *playerData;                 /* 0x04 */
    unsigned int unknown_08[11];      /* 0x08 */
    int listType;                     /* 0x34 */
    unsigned int initialMode;         /* 0x38 */
    int cursor;                       /* 0x3C */
    unsigned int result;              /* 0x40 */
    unsigned int unknown_44[21];      /* 0x44 */
};

/* Parameter block of the pokemon status proc (external struct, partly known). */
struct Guru2StatusParam {
    void *party;                      /* 0x00 */
    unsigned char unknown_04[4];      /* 0x04 */
    void *gameData;                   /* 0x08 */
    unsigned char flag0C;             /* 0x0C */
    unsigned char flag0D;             /* 0x0D */
    unsigned char partyCount;         /* 0x0E */
    unsigned char cursor;             /* 0x0F */
    unsigned char unknown_10;         /* 0x10 */
    unsigned char unknown_11[3];      /* 0x11 */
    unsigned short unknown_14;        /* 0x14 */
    unsigned char unknown_16[2];      /* 0x16 */
    unsigned int nationalDex;         /* 0x18 */
    unsigned char unknown_1C[12];     /* 0x1C */
};

struct Guru2Entry {
    unsigned int state;               /* 0x00 index into the entry state table */
    unsigned int selectedSlot;        /* 0x04 party slot chosen in the list */
    struct Guru2Param *param;         /* 0x08 */
    struct Guru2Session *session;     /* 0x0C */
    void *gameData;                   /* 0x10 */
    unsigned char unused_14[4];       /* 0x14 */
    struct Guru2PartyListParam *partyListParam;     /* 0x18 */
    struct Guru2StatusParam *statusParam;         /* 0x1C */
    void *procHandle;                 /* 0x20 */
};

struct Guru2Comm;

struct Guru2Session {
    unsigned int state;               /* 0x00 */
    unsigned int selectedSlot;        /* 0x04 sent with command 0x280B */
    int playerCount;                  /* 0x08 */
    unsigned int memberMask;          /* 0x0C bit i set: player i takes part */
    unsigned int startConfirmed;      /* 0x10 copied from the lobby work */
    struct Guru2Param *param;         /* 0x14 */
    struct Guru2Comm *comm;           /* 0x18 */
    void *gameWork;                   /* 0x1C */
    void *lobbyWork;                  /* 0x20 */
};

struct Guru2Comm {
    struct Guru2Session *session;     /* 0x00 */
    unsigned int sendTag;             /* 0x04 */
    unsigned char sendData[24];       /* 0x08 outgoing payload, see GURU2_COMM_SendWithHeader */
    unsigned int acceptingJoins;      /* 0x20 */
    unsigned int sessionClosed;       /* 0x24 */
    unsigned char unknown_28[4];      /* 0x28 */
    unsigned int expectedMemberCount; /* 0x2C */
    unsigned int joinedMask;          /* 0x30 */
    int memberCountAck;               /* 0x34 */
    unsigned short acceptedCount;     /* 0x38 */
    unsigned char unknown_3A[2];      /* 0x3A */
    int unknown_3C;                   /* 0x3C */
    unsigned short statusFlags;       /* 0x40 */
    unsigned short ackMask;           /* 0x42 */
    unsigned char unknown_44[2];      /* 0x44 */
    short partyReceivedMask;          /* 0x46 */
    unsigned short abortMask;         /* 0x48 */
    unsigned short continueMask;      /* 0x4A */
    unsigned char *recvBuffer;        /* 0x4C 5 * 0x594 bytes */
    unsigned char *partyCopies;       /* 0x50 5 * 0x594 bytes */
    unsigned char unknown_54[4];      /* 0x54 */
};

#define GURU2_PARTY_ENTRY_SIZE 0x594

typedef char Guru2EntrySizeCheck[(sizeof(struct Guru2Entry) == 36) ? 1 : -1];
typedef char Guru2SessionSizeCheck[(sizeof(struct Guru2Session) == 36) ? 1 : -1];
typedef char Guru2CommSizeCheck[(sizeof(struct Guru2Comm) == 88) ? 1 : -1];
typedef char Guru2StatusParamSizeCheck[(sizeof(struct Guru2StatusParam) == 40) ? 1 : -1];

/* ---- Game work (0xDAC bytes), allocated by the game proc init ---- */

struct Guru2Vec3 {
    int x;
    int y;
    int z;
};

/* Rotating disc anchor, embedded at Guru2Game.spinner (0xC0 bytes). */
struct Guru2Spinner {
    struct Guru2Vec3 anchor;          /* 0x00 */
    struct Guru2Vec3 pos;             /* 0x0C anchor + offsets */
    struct Guru2Vec3 scale;           /* 0x18 */
    struct Guru2Vec3 shakeOffset;     /* 0x24 */
    struct Guru2Vec3 offset;          /* 0x30 */
    int angle;                        /* 0x3C 20.12 fixed point degrees */
    int speed;                        /* 0x40 */
    int speedDelta;                   /* 0x44 */
    int unknown_48;                   /* 0x48 */
    unsigned short rotX;              /* 0x4C */
    short rotY;                       /* 0x4E */
    unsigned short rotZ;              /* 0x50 */
    unsigned char unknown_52[0x6A];   /* 0x52 */
    int g3dUnit;                      /* 0xBC */
};

/* Per-player disc piece, array of 5 at Guru2Game.players (0xB4 bytes each). */
struct Guru2Player {
    int active;                       /* 0x00 */
    int visible;                      /* 0x04 */
    int ready;                        /* 0x08 1 once the piece has settled */
    int aid;                          /* 0x0C network id of the player */
    int slot;                         /* 0x10 seat index */
    int order;                        /* 0x14 */
    int slotCopy;                     /* 0x18 */
    int angle;                        /* 0x1C 20.12 fixed point degrees */
    int speed;                        /* 0x20 */
    unsigned short rotX;              /* 0x24 */
    unsigned short rotY;              /* 0x26 */
    unsigned short rotZ;              /* 0x28 */
    unsigned char unknown_2A[2];      /* 0x2A */
    int rotXFixed;                    /* 0x2C */
    int rotYFixed;                    /* 0x30 */
    int rotZFixed;                    /* 0x34 */
    struct Guru2Vec3 scale;           /* 0x38 */
    struct Guru2Vec3 pos;             /* 0x44 */
    struct Guru2Vec3 basePos;         /* 0x50 */
    unsigned char unknown_5C[0x58];   /* 0x5C */
};

/* Shadow of a player piece, array of 5 at Guru2Game.shadows (0x7C bytes each). */
struct Guru2Shadow {
    int active;                       /* 0x00 */
    unsigned short rotX;              /* 0x04 */
    unsigned short rotY;              /* 0x06 */
    unsigned short rotZ;              /* 0x08 */
    unsigned char unknown_0A[2];      /* 0x0A */
    struct Guru2Vec3 scale;           /* 0x0C */
    struct Guru2Vec3 pos;             /* 0x18 */
    unsigned char unknown_24[0x54];   /* 0x24 */
    struct Guru2Player *owner;        /* 0x78 */
};

/* Marker of a player piece, array of 5 at Guru2Game.markers (0x68 bytes each). */
struct Guru2Marker {
    int active;                       /* 0x00 */
    struct Guru2Vec3 pos;             /* 0x04 */
    unsigned char unknown_10[0x54];   /* 0x10 */
    struct Guru2Player *owner;        /* 0x64 */
};

/* Work record at Guru2Game.seatInit, filled while the seats are assigned. */
struct Guru2SeatInit {
    int placed;                       /* 0x00 number of pieces placed */
    int seatAngle;                    /* 0x04 */
    unsigned char unknown_08[8];      /* 0x08 */
    int nextSlot;                     /* 0x10 */
    int playerCount;                  /* 0x14 */
    unsigned char unknown_18[8];      /* 0x18 */
};

struct Guru2WindowSlot {
    void *window;
    unsigned char printed;
};

/* Text windows at Guru2Game.windows (0x60 bytes). */
struct Guru2Windows {
    int count;                        /* 0x00 */
    void *font;                       /* 0x04 */
    void *msgData;                    /* 0x08 */
    void *wordSet;                    /* 0x0C */
    void *mainWindow;                 /* 0x10 */
    void *window[5];                  /* 0x14 */
    void *activeWindow;               /* 0x28 */
    unsigned char printPending;       /* 0x2C */
    struct Guru2WindowSlot slot[5];   /* 0x30 */
    void *printQueue;                 /* 0x58 */
    void *textBuf;                    /* 0x5C */
};

struct Guru2RecvEntry {
    unsigned short seat;              /* 0x00 */
    unsigned short aid;               /* 0x02 */
};

struct Guru2Game {
    int state;                        /* 0x00 index into the game state table */
    int unknown_04;                   /* 0x04 */
    int frameCounter;                 /* 0x08 */
    int timer;                        /* 0x0C */
    int waitCount;                    /* 0x10 */
    int sendCount;                    /* 0x14 */
    int modeFlag;                     /* 0x18 */
    unsigned int resultMask;          /* 0x1C */
    int unknown_20;                   /* 0x20 */
    void *party;                      /* 0x24 party handle of the game data */
    struct Guru2Player *current;      /* 0x28 */
    int seat;                         /* 0x2C own seat index */
    int playerCount;                  /* 0x30 */
    int unknown_34;                   /* 0x34 */
    int unknown_38;                   /* 0x38 */
    int unknown_3C;                   /* 0x3C */
    int received;                     /* 0x40 set when a result packet arrived */
    int partySlot[5];                 /* 0x44 */
    int turnAngle;                    /* 0x58 */
    int turnSpeed;                    /* 0x5C */
    unsigned short angle[5];          /* 0x60 */
    unsigned char unknown_6A[2];      /* 0x6A */
    unsigned short recvBuf[8];        /* 0x6C */
    struct Guru2RecvEntry recvEntry[5]; /* 0x7C */
    void *memberEntry[5];             /* 0x90 */
    void *nameBuf[5];                 /* 0xA4 */
    struct Guru2SeatInit seatInit;    /* 0xB8 */
    struct Guru2Session *session;     /* 0xD8 */
    struct Guru2Comm *comm;           /* 0xDC */
    struct Guru2Spinner spinner;      /* 0xE0 */
    unsigned char unknown_1A0[0x140]; /* 0x1A0 */
    struct Guru2Player players[5];    /* 0x2E0 */
    struct Guru2Shadow shadows[5];    /* 0x664 */
    struct Guru2Marker markers[5];    /* 0x8D0 */
    int shadowUnit;                   /* 0xAD8 */
    int markerUnit;                   /* 0xADC */
    int playerUnit[5];                /* 0xAE0 */
    void *g3dUtil;                    /* 0xAF4 */
    int fx0[5][8];                    /* 0xAF8 */
    int fx1[5][5];                    /* 0xB98 */
    int fx2[5][6];                    /* 0xBFC */
    unsigned int fx3[5];              /* 0xC74 */
    unsigned short fx4State;          /* 0xC88 */
    unsigned short fx4Flag;           /* 0xC8A */
    int fx4Count;                     /* 0xC8C */
    int fx5[5][4];                    /* 0xC90 */
    struct Guru2Windows windows;      /* 0xCE0 */
    unsigned char unknown_D40[0x14];  /* 0xD40 */
    void *light;                      /* 0xD54 */
    void *arcHandle;                  /* 0xD58 */
    void *res5C;                      /* 0xD5C */
    void *res60;                      /* 0xD60 */
    void *res64;                      /* 0xD64 */
    void *clactUnit;                  /* 0xD68 */
    int clactChar;                    /* 0xD6C */
    int clactPal;                     /* 0xD70 */
    int clactCell;                    /* 0xD74 */
    void *palAnm;                     /* 0xD78 */
    void *taskFx0;                    /* 0xD7C */
    void *taskFx1;                    /* 0xD80 */
    void *taskFx2;                    /* 0xD84 */
    void *taskFx3;                    /* 0xD88 */
    void *taskFx4;                    /* 0xD8C */
    void *taskFx5;                    /* 0xD90 */
    void *taskCtx;                    /* 0xD94 */
    void *taskMgr;                    /* 0xD98 */
    void *taskMain;                   /* 0xD9C */
    void *errScreen;                  /* 0xDA0 */
    int skyUnit;                      /* 0xDA4 */
    void *timeIcon;                   /* 0xDA8 */
};

typedef char Guru2SpinnerSizeCheck[(sizeof(struct Guru2Spinner) == 0xC0) ? 1 : -1];
typedef char Guru2PlayerSizeCheck[(sizeof(struct Guru2Player) == 0xB4) ? 1 : -1];
typedef char Guru2ShadowSizeCheck[(sizeof(struct Guru2Shadow) == 0x7C) ? 1 : -1];
typedef char Guru2MarkerSizeCheck[(sizeof(struct Guru2Marker) == 0x68) ? 1 : -1];
typedef char Guru2SeatInitSizeCheck[(sizeof(struct Guru2SeatInit) == 0x20) ? 1 : -1];
typedef char Guru2WindowsSizeCheck[(sizeof(struct Guru2Windows) == 0x60) ? 1 : -1];
typedef char Guru2GameSizeCheck[(sizeof(struct Guru2Game) == 0xDAC) ? 1 : -1];

#endif
