#ifndef OV137_TYPES_H
#define OV137_TYPES_H

struct Guru2Session;
struct Guru2Comm;
struct BmpMenu;

/* Palette resource as unpacked by NNS_G2dGetUnpackedPaletteData (NitroSystem names). */
#include "../arm9/nns_g2d_res_types.h"

/* One union room member slot of the lobby: this frame and the previous frame. */
struct Guru2LobbyMember {
    void *current;
    void *previous;
};

/*
 * Lobby work (0x4874 bytes) of the receipt proc (guru2_receipt.c), allocated
 * by GURU2_RECEIPT_ProcInit. The records after 0x4822 are reached by raw
 * offset (FrameRecord in guru2_receipt.c).
 */
struct Guru2Lobby {
    int state;                        /* 0x00 proc phase: 0 wipe in, 1 recruit, 2 state table only, 3 wipe out, 4 reset */
    unsigned char pad_04[4];
    unsigned int startConfirmed;      /* 0x08 copied to Guru2Session.startConfirmed */
    struct Guru2Session *session;     /* 0x0C */
    struct Guru2Comm *comm;           /* 0x10 */
    unsigned char pad_14[4];
    unsigned int paletteAnimEnabled;  /* 0x18 first word of the State view in GURU2_RECEIPT_AnimatePalette */
    unsigned int paletteAnimIndex;    /* 0x1C */
    int paletteAnimCounter;           /* 0x20 */
    void *paletteBlock;               /* 0x24 heap block of the member palette file */
    void *paletteData;                /* 0x28 unpacked palette data pointer */
    unsigned char pad_2C[4];
    int vblankTask;                   /* 0x30 main task that runs GURU2_RECEIPT_VBlank */
    int arcHandle;                    /* 0x34 archive handle 32 */
    void *font;                       /* 0x38 */
    void *wordSet;                    /* 0x3C */
    int msgData;                      /* 0x40 message bank */
    void *memberName[5];              /* 0x44 name string buffer per member */
    unsigned char pad_58[4];
    void *messageBuf;                 /* 0x5C text of the message window */
    void *titleBuf;                   /* 0x60 title text */
    unsigned char pad_64[4];
    void *clactUnit;                  /* 0x68 */
    unsigned int paletteId[5];        /* 0x6C CLACT palette id per member */
    unsigned int charId[5];           /* 0x80 CLACT character id per member */
    unsigned int cellAnimId;          /* 0x94 */
    unsigned char pad_98[4];
    void *memberActor[5];             /* 0x9C one actor per member */
    unsigned char pad_B0[32];
    void *memberWindow;               /* 0xD0 member list */
    void *messageWindow;              /* 0xD4 */
    void *cornerWindow;               /* 0xD8 */
    void *titleWindow;                /* 0xDC */
    unsigned char pad_E0[8];
    void *yesNoMenu;                  /* 0xE8 */
    void *printQue;                   /* 0xEC */
    void *printStream;                /* 0xF0 */
    void *tcbl;                       /* 0xF4 */
    void *activeWindow;               /* 0xF8 title window, as Guru2Windows.activeWindow */
    unsigned char printPending;       /* 0xFC */
    unsigned char pad_FD[19];
    void *iconPaletteBlock;           /* 0x110 */
    struct NNSG2dPaletteData *iconPaletteData; /* 0x114 */
    int stateIndex;                   /* 0x118 index into gGuru2LobbyStateTable */
    int nextStateIndex;               /* 0x11C state entered once the message is done */
    unsigned char pad_120[4];
    int delayCounter;                 /* 0x124 frames spent in a delay state */
    unsigned char pad_128[16];
    struct Guru2LobbyMember member[5]; /* 0x138 */
    unsigned int actorState[5];       /* 0x160 0 idle, 1 show, 2 shown, 3 hide */
    unsigned char pad_174[0x4690];
    unsigned int previousMemberCount; /* 0x4804 */
    int recruitClosed;                /* 0x4808 */
    unsigned int syncKey;             /* 0x480C */
    unsigned char answerSent;         /* 0x4810 */
    unsigned char pad_4811[1];
    unsigned char cancelMemberCount;  /* 0x4812 */
    unsigned char startRequestBlocked; /* 0x4813 */
    unsigned int syncToken;           /* 0x4814 */
    int timeoutFrames;                /* 0x4818 */
    unsigned int timeoutMemberCount;  /* 0x481C */
    short answerWaitFrames;           /* 0x4820 */
};

typedef char Guru2LobbySizeCheck[(sizeof(struct Guru2Lobby) == 0x4824) ? 1 : -1];

#endif
