#ifndef OV132_TYPES_H
#define OV132_TYPES_H

#include "../arm9/mystatus_types.h"
#include "../arm9/nns_fnd_types.h"
#include "../arm9/snd_bank.h"
#include "../ov112/sta_act_types.h"
#include "../ov112/mus_poke_draw_shared_types.h"

/* Object layouts for the ov132 sources, merged from the per-function views. */

/* One 0x30-byte player row inside ActingHost at +0x60 (also viewed as
   Context.rec in mus_comm_func.c). */
struct StaActRecord {
    int statusReceived;           /* 0x00 set when the player's status block arrived */
    int partyReceived;            /* 0x04 set when the party record block arrived */
    int boxReceived;              /* 0x08 set when the box data arrived */
    int used;                     /* 0x0C a pick value is waiting to be broadcast */
    unsigned char value;          /* 0x10 pick value, default 10 */
    unsigned char state;          /* 0x11 broadcast pick value, default 10 */
    unsigned char key;            /* 0x12 player index */
    unsigned char items[2];       /* 0x13 chosen item bytes, 0xFF when empty */
    unsigned char pad_15[3];
    unsigned int orderValue;      /* 0x18 per-player order nibble */
    char *partyBuffer;            /* 0x1C party block */
    void *fanPoints;              /* 0x20 start of the box buffer */
    void *myStatus;               /* 0x24 MyStatus inside the box buffer */
    void *boxParam;               /* 0x28 box parameters inside the box buffer */
    void *boxBuffer;              /* 0x2C fan points + MyStatus + box parameters */
};

/* Musical communication work (0x1AC bytes, allocated by MUS_COMM_FUNC_Create). */
struct ActingHost {
    unsigned short heapId;
    unsigned char pad_2[2];
    int hasError;
    int isInitialized;
    int useExistingSession;        /* 1: skip GFL_NET_StartSession */
    int netReady;                  /* set by the GFL_NET_StartSession callback */
    unsigned int word14;           /* 0x14 cleared by the init */
    unsigned int startFlag;        /* 0x18 set by packet 0 */
    unsigned char byte1C;          /* 0x1C cleared by the init */
    unsigned char pad_1D[3];
    struct MyStatus ownStatus;     /* 0x20 copy of the local player's status */
    unsigned char macAddress[6];   /* 0x40 */
    unsigned short sessionId;      /* 0x46, follows the MAC address at +0x40 */
    int role;                      /* 1 parent, 2 child */
    int state;                     /* MUS_COMM_FUNC_Update state machine */
    void * comm;
    void * icaCtx;
    void * gameData;
    void * myStatus;               /* 0x5C */
    struct StaActRecord rec[4];
    uptr statusSource;             /* 0x120 source of the status block (state 18), an address */
    void * statusSendBuf;
    void * partyRecordBuf;         /* 4 party blocks */
    unsigned short fanPoints;
    unsigned char pad_12E[2];
    void * myStatusSrc;
    void * boxParamSrc;
    void * myStatusSendBuf;
    void * boxRecvBuf;             /* 4 box buffers */
    union {
        int s;
        void * p;
    } hostEntry;                   /* 0x140 HostEntry being transferred */
    union {
        int s;
        unsigned int u;
    } pairValueA;
    union {
        int s;
        unsigned int u;
    } pairValueB;
    unsigned char chunkIndex;
    unsigned char pad_14D[3];
    int transferActive;
    int chunkSending;
    int boxesReceived;
    unsigned int recordsReceived;
    unsigned int word160;          /* 0x160 cleared by the init */
    unsigned int kind4Received;
    unsigned int kind5Received;
    unsigned int kind6Received;
    unsigned int slot1Done;
    unsigned int slot2Done;
    unsigned int slot3Done;
    int transferState;
    unsigned char chosenPlayer;
    unsigned char pad_181[3];
    int orderSendPending;          /* 0x184 the player order nibbles must be broadcast */
    int pickSendPending;           /* 0x188 the pick commands must be broadcast */
    unsigned int pickCommand[8];   /* 0x18C pick commands to broadcast, 0xFFFF when sent */
};

/* Input block of STA_ACTING_Create: the comm host (0 offline), the four player
   records, the program and the resource block. */
struct ActingRecord;
struct ActingPartB;
struct ActingInput {
    void * comm;                       /* 0x00 comm host, 0 offline */
    struct ActingRecord * players[4];  /* 0x04 player records */
    void * program;                    /* 0x14 */
    struct ActingPartB * resources;    /* 0x18 */
};

struct ActingPartA {
    unsigned char pad_0[20];
    void * program;
    void * resources;
};

struct ActingPartB {
    unsigned char pad_0[8];
    void * messages;
    unsigned int charAnims;
    unsigned char pad_10[4];
    void *seqAddr;                  /* 0x14 */
    void *bankAddr;                 /* 0x18 */
    SNDWaveArc *srcWaveArc;         /* 0x1C */
};

/* One outfit slot of a player record (6 bytes). */
struct ActingItemSlot {
    unsigned short id;
    short rotation;
    unsigned char flag;
    unsigned char pad_5;
};

struct ActingRecord {
    int state;                     /* 2 when the player performs */
    unsigned char pad_4[0x10];
    union {
        struct ActingItemSlot slots[9]; /* 0x14 */
        struct {
            unsigned char pad_14[0x2A];
            unsigned short leftActorId;    /* 0x3E, 255 when none */
            unsigned char pad_40[4];
            unsigned short rightActorId;   /* 0x44, 255 when none */
            unsigned char pad_46[4];
            unsigned short score;          /* 0x4A */
        };
    };
    unsigned char pad_4C[8];
    int actionDone[9];             /* 0x54 */
    unsigned short actionTiming;   /* 0x78, frames; 0xFFFD..0xFFFF select random timing */
};

/* Musical scene work (0x1F0 bytes, allocated by STA_ACTING_Create). */
struct ActingScene {
    unsigned short heapId;
    unsigned short introTimer;
    unsigned short scrollX;
    unsigned short scrollTargetX;
    unsigned short scrollY;
    unsigned char localPlayer;
    unsigned char pad_B[1];
    int cameraHoldIntro;
    int cameraHoldScore;
    unsigned int cameraHoldScript;
    union {
        unsigned int u;
        void * p;
    } arcHandle;
    unsigned int phase;
    void * vblankTask;
    union {
        int s;
        unsigned int u;
    } bgmBuffersInstalled;
    union {
        int s;
        unsigned int u;
    } seqPlaying;
    union {
        int s;
        unsigned int u;
    } bgmPlaying;
    struct ActingInput * input;
    MusPokeDrawScene * mcssRender;
    void * actorPool;
    void * model;
    StaActBillboardImage * actorSystem;
    void * actors[4];
    void * actObj;
    void * objSlots[5];
    void * effectSystem;
    void * animSlots[8];
    void * charSystem;
    void * charSlots[4];
    void * button;
    void * camera;
    union {
        unsigned int u;
        void * p;
    } billboard;
    void * scriptSystem;
    union {
        unsigned int u;
        void * p;
    } charAnimTable;
    void * audience;
    void * animHandle;
    unsigned char pad_C0[12];
    union {
        unsigned int u;
        void * p;
    } textTcbl;
    union {
        unsigned int u;
        void * p;
    } bmpWin;
    union {
        unsigned int u;
        void * p;
    } font;
    union {
        unsigned int u;
        void * p;
    } printStream;
    union {
        unsigned int u;
        void * p;
    } msgData;
    union {
        unsigned int u;
        void * p;
    } strBuf;
    union {
        int s;
        unsigned int u;
    } queuePending;
    union {
        unsigned int u;
        void * p;
    } printQueue;
    int selectionDirty;
    unsigned char forcedSelection;
    unsigned char selectedPlayer;
    unsigned char highlightActor;
    unsigned char rank[4];
    unsigned char bonus[4];
    unsigned char pad_FB[1];
    int actionRequest[4];
    int actionValue[4];
    unsigned char lastActor;
    unsigned char lastAction;
    unsigned short actionDelay;
    int scoreOnFinish;
    unsigned short actionTimer[4];
    int pendingAction[4];
    int actionUsed[8];
    int netActionPending;
    int netActionValue;
    unsigned int abortRequested;
    unsigned char fadeWork[116];
    void *seqAddr;
    void *bankAddr;
    SNDWaveArc *srcWaveArc;
    unsigned int elapsedTicks;
    union {
        int s;
        unsigned int u;
    } lastTick;
};

/* Transfer buffers announced by the host (kinds 4 to 7). */
struct HostEntry {
    unsigned char pad_0[4];
    void * slotBuffer[3];           /* 0x04 buffers of kinds 4, 5, 6 */
    void * chunkBuffer;             /* 0x10 chunked transfer data */
    void * body;
    void * section2;
    void * section3;
    unsigned int slotSize[3];       /* 0x20 sizes of the kind 4, 5, 6 buffers */
    unsigned int chunkSize;         /* 0x2C */
};

/* One 8-byte audience member record in STA_ACT_AUDIENCE's +0x204 array. */
struct AudienceRecord {
    unsigned char actorIndex;   /* 0x00, 0xff when the slot is empty */
    unsigned char timer;        /* 0x01, countdown to the next update */
    unsigned char tileIndex;    /* 0x02, index into d_021FDC16 */
    unsigned char pad_3;
    unsigned short value;       /* 0x04, set to 0xffff when hidden */
    unsigned char state;        /* 0x06, 0..5 selects the tile row */
    unsigned char rowOffset;    /* 0x07 */
};

/* The first two words of a received host chunk buffer (HostEntry.f10). */
struct StaNetChunkHeader {
    unsigned int size;          /* 0x00 */
    unsigned int offset;        /* 0x04 */
};

/* A status/record block whose payload pointer sits at +0x04. */
struct MusCommBlockHeader {
    unsigned char pad_0[4];
    void * payload;             /* 0x04 */
};

/* Audience work (0x3E4 bytes, allocated by STA_ACT_AUDIENCE_Create). */
struct ActAudience {
    unsigned short heapId;
    unsigned char pad_2[0x1E6];
    void * scene;                   /* 0x1E8 */
    int choices[4];                 /* 0x1EC per-player highlight flags */
    unsigned char highlight;        /* 0x1FC actor index, 0xFF when none */
    unsigned char pad_1FD[3];
    int dirty;                      /* 0x200 records need new targets */
    struct AudienceRecord records[60]; /* 0x204 */
};

/* Script entry (0x1C bytes) allocated by STA_ACT_SCRIPT_AddScript; also the VM user context. */
struct ScriptCtx {
    union {
        void * p;
        unsigned short h;
    } system;
    union {
        int s;
        void * p;
    } vm;
    unsigned char pad_8[8];
    unsigned int elapsed;
    unsigned short waitFrames;
    unsigned short flags;
    unsigned char actorMask;
};

struct ScriptEntry {
    void * system;
    void * vm;
    void * script;
    void * table;
    int elapsed;
    unsigned short waitFrames;
    unsigned short flags;          /* 1 done, 2 blocking, 4 paused, 8 owns table */
    unsigned char actorMask;
    unsigned char slotIndex;
};

/* Script system object created by STA_ACT_SCRIPT_Create (0x44 bytes). */
struct ScriptSystem {
    unsigned short heapId;     /* +0x00 */
    unsigned char pad_2[2];
    void * tcb;                /* +0x04 scene context */
    void * tcbBuffer;          /* +0x08 node */
    void * scripts[10];        /* +0x0C script slots */
    void * scene;              /* +0x34 scene owner */
    NNSFndList taskList;       /* +0x38 NNS list head */
};

/* 16-byte task list node created by STA_ACT_SCRIPT_AddTask. */
struct ScriptTaskNode {
    unsigned char pad_0[8];
    void * arg;                /* +0x08 task argument */
    void * task;               /* +0x0C task handle */
};

/* The script system seen from the commands, with one element of the scene's per-player action arrays. */
struct ScriptOwner {
    unsigned short heapId;
    unsigned char pad_2[2];
    void * tcb;
    unsigned int tcbBuffer;
    void * scripts[10];
    void * scene;
    unsigned char pad_38[196];
    int actionRequest;
    unsigned char pad_100[12];
    int actionValue;
};

/* Vector interpolation seen by STA_ACT_SCRIPT_StepTaskVec; it starts at +0x04 of a move task. */
struct ScriptVecTask {
    void * owner;               /* +0x00, the scene field of the move task */
    int start[3];
    int end[3];
    int step[3];
    unsigned short duration;
    unsigned short counter;
};

/* Head shared by timed tasks stepped by STA_ACT_SCRIPT_TickSlot. */
struct ScriptTickTask {
    void * scene;
    unsigned int counter;
    unsigned int interval;
    unsigned int remaining;
};

/* 56-byte effect move task created by SCRIPT_COMMAND_CmdMoveEffect. */
struct ScriptEffectTask {
    void * scene;
    unsigned int counter;
    unsigned int interval;
    unsigned int remaining;
    void * effectSystem;
    unsigned int baseX;
    unsigned int baseY;
    unsigned int baseZ;
    unsigned int rangeX;
    unsigned int rangeY;
    unsigned int rangeZ;
    unsigned short effectIndex;
    unsigned short pad_2E;
    void * system;
    void * node;
};

/* 56-byte move task shared by the actor, entry and char move commands. */
struct ScriptSlot {
    void * target;
    void * scene;
    unsigned int start[3];
    unsigned int end[3];
    int step[3];
    unsigned short duration;
    unsigned short counter;
    void * system;
    void * node;
};

/* 24-byte actor step view used by STA_ACT_SCRIPT_StepTaskActor. It sits at
   offset 0x08 of the 48-byte char follow task. */
struct ScriptFollowStep {
    void * scene;             /* +0x00 owner scene, char follow +0x08 */
    void * actor;             /* +0x04 actor object, char follow +0x0C */
    unsigned int dx;          /* +0x08 */
    unsigned int dy;          /* +0x0C */
    unsigned int dz;          /* +0x10 */
    unsigned short duration;  /* +0x14 */
    unsigned short counter;   /* +0x16 */
};

/* 48-byte char-follow task created by SCRIPT_COMMAND_CmdCharFollowActor. */
struct ScriptCharFollowTask {
    unsigned char index;          /* +0x00 actor index */
    unsigned char pad_1[3];
    void * target;                /* +0x04 char slot */
    struct ScriptFollowStep step; /* +0x08 actor step view */
    unsigned char pad_20[8];
    void * owner;                 /* +0x28 script system */
    void * task;                  /* +0x2C task node */
};

struct ScriptTask {
    void * scene;
    union {
        int s;
        unsigned int u;
        void * p;
    } start;
    union {
        int s;
        unsigned int u;
    } end;
    unsigned short duration;
    unsigned short counter;
    void * system;
    void * node;
    void * actor;
    void * rotateSystem;
    void * rotateNode;
};

/* Button manager (0x60 bytes) created by STA_ACT_BUTTON_Create. */
struct StaActTaskObj {
    unsigned short heapId;
    unsigned char pad_2[2];
    void * scene;
    void * playerRecord;
    union {
        int s;
        unsigned int u;
    } enabled;
    int actionPending;
    int pressedIndex;              /* 2 when no button is pressed */
    void * clactUnit;
    union {
        unsigned int u;
        void * p;
    } framePalette;
    union {
        unsigned int u;
        void * p;
    } iconPalette;
    union {
        unsigned int u;
        void * p;
    } pressPalette;
    union {
        unsigned int u;
        void * p;
    } frameCharacter;
    union {
        unsigned int u;
        void * p;
    } iconCharacter;
    union {
        unsigned int u;
        void * p;
    } pressCharacter;
    union {
        unsigned int u;
        void * p;
    } frameCellAnim;
    union {
        unsigned int u;
        void * p;
    } iconCellAnim;
    union {
        unsigned int u;
        void * p;
    } pressCellAnim;
    int pressed[2];
    unsigned short actorIds[2];
    void * frameActors[2];
    void * iconActors[2];
    void * pressActor;
};

#endif
