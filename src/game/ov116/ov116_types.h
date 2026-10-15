#ifndef ALETHEIA_OV116_TYPES_H
#define ALETHEIA_OV116_TYPES_H

/*
 * Types of the Battle Subway Wi-Fi screen (ov116). wifi_bsubway.c owns the
 * network, save and state-machine logic; wifi_bsubway_graphic.c draws it.
 * The work object is 0x185C bytes: a parent pointer, the embedded graphic
 * context, the save/retry argument blocks, the trainer record, the trainer
 * status block and the async transfer state.
 */

/* Screen task the work object belongs to. */
struct WifiBsubwayParent {
    unsigned char pad00[4];
    void *proc;   /* 0x04: proc passed to GAMESYSTEM_CallProc */
    int state;    /* 0x08: state the parent drives */
};

/* Embedded graphic context (0x9AC bytes at work+4). Every field is reached
 * both as work+4+off (the screen functions) and, for the two animation
 * fields, through the anim view at work+0x10. */
struct WifiBsubwayGraphic {
    int active;                      /* 0x000: window/context created */
    unsigned short heapId;           /* 0x004: heap the context was built on */
    unsigned char pad006[2];         /* 0x006 */
    void *bg;                        /* 0x008: BG/draw object (WifiBsubwayBg) */
    void *animCallback;              /* 0x00C: callback handle for the palette anim */
    unsigned int animEnabled;        /* 0x010: palette anim running */
    unsigned char pad014[0x1E0];     /* 0x014: blend source rows */
    unsigned char palette[0x780];    /* 0x1F4: palette/blend buffer */
    short frame;                     /* 0x974: palette frame index (0..59) */
    unsigned char pad976[1];         /* 0x976 */
    unsigned char animToggle;        /* 0x977: toggles each frame */
    unsigned char animPhase;         /* 0x978: two-phase draw select */
    unsigned char pad979[3];         /* 0x979 */
    void *window;                    /* 0x97C: BMP window */
    void *yesNoMenu;                 /* 0x980: BMP yes/no menu */
    unsigned int frameGfxA;          /* 0x984: loaded frame gfx handle A */
    unsigned int frameGfxB;          /* 0x988: loaded frame gfx handle B */
    void *timeIcon;                  /* 0x98C: TIME_ICON handle */
    void *msgBank;                   /* 0x990: MSGDATA bank */
    void *wordSet;                   /* 0x994: WORD SET */
    void *font;                      /* 0x998: GF_FONT */
    void *strbufA;                   /* 0x99C: code-in strbuf */
    void *strbufB;                   /* 0x9A0: message strbuf */
    void *printStream;               /* 0x9A4: PRINTSYS stream */
    void *tcbl;                      /* 0x9A8: TCBL text control */
};

/* Palette animation view. The callback context handed to func_020056A0 is
 * work+0x10, that is graphic+0xC, so this view starts at animCallback. */
struct WifiBsubwayAnim {
    void *callback;                  /* 0x000 (graphic 0x00C) */
    unsigned int enabled;            /* 0x004 (graphic 0x010) */
    unsigned char pad008[0x1E8];     /* 0x008 (graphic 0x014) */
    unsigned char palette[0x778];    /* 0x1F0 (graphic 0x1FC) */
    short frame;                     /* 0x968 (graphic 0x974) */
    unsigned char pad96A[1];         /* 0x96A (graphic 0x976) */
    unsigned char toggle;            /* 0x96B (graphic 0x977) */
    unsigned char phase;             /* 0x96C (graphic 0x978) */
};

/* BG/draw object allocated by WIFI_BSUBWAY_GRAPHIC_Create (0x1BC bytes). */
struct WifiBsubwayBg {
    unsigned int visible;            /* 0x000 */
    unsigned char pad004[8];         /* 0x004 */
    void *redrawCallback;            /* 0x00C: OnRedraw callback handle */
    unsigned char pad010[0x1AC];     /* 0x010 */
};

/* Code-in parameter object returned by CODEIN_PARAM_Create. */
struct WifiBsubwayCodeInParam {
    unsigned char pad00[0x20];
    void *strbuf;                    /* 0x20: strbuf holding the digits */
};

/* Entry of the d_021D83F0 BG layer table (0x2C bytes each). */
struct WifiBsubwayBgLayer {
    unsigned int layer;              /* 0x00: BG layer id */
    unsigned char templateData[0x20];/* 0x04: BgTemplate */
    unsigned int type;               /* 0x24: template type */
    unsigned int slot;               /* 0x28: slot / value */
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
    struct WifiBsubwayGraphic graphic;      /* 0x0004 (0x9AC bytes) */
    unsigned int saveControl0;              /* 0x09B0: GAME_DATA save arg block */
    unsigned int saveValue0;                /* 0x09B4 */
    unsigned int saveValue1;                /* 0x09B8 */
    unsigned int saveSize;                  /* 0x09BC */
    void *saveBuffer;                       /* 0x09C0: &work+0x9F4 */
    unsigned int pad09C4;                   /* 0x09C4 */
    unsigned int saveFlag;                  /* 0x09C8 */
    int saveState;                          /* 0x09CC */
    unsigned char pad09D0[8];               /* 0x09D0 */
    unsigned int retryControl0;             /* 0x09D8: GAME_DATA retry arg block */
    unsigned int retryValue0;               /* 0x09DC */
    unsigned int retryValue1;               /* 0x09E0 */
    unsigned int retryValue2;               /* 0x09E4 */
    unsigned char pad09E8[12];              /* 0x09E8 */
    unsigned char saveData[44];             /* 0x09F4: save payload buffer */
    unsigned char pad0A20[0x148];           /* 0x0A20 */
    unsigned short dpwActive;               /* 0x0B68 */
    unsigned short dpwDone;                 /* 0x0B6A */
    unsigned int state;                     /* 0x0B6C */
    unsigned int codeInValue;               /* 0x0B70 */
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
