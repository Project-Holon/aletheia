#ifndef BTL_SERVER_TYPES_H
#define BTL_SERVER_TYPES_H
/* ov093 battle server: types shared by every part of btl_server.c. */

#include "../types.h"
#include "../ov093/btl_pokeparam_types.h"
#include "../ov093/btl_calc_types.h"
#include "../ov093/btl_rec_types.h"

typedef struct {
    struct BtlPokeParam *pokeParam;  /* 0x0: BTL_POKEPARAM of the acting poke */
    union BtlAction action;  /* 0x4 */
    u32 orderKey;   /* 0x8: bits 0-12 speed, 13-15 speed order, 16-21 move priority, 22-24 action class */
    u8 clientId;    /* 0xc */
    u8 done;        /* 0xd */
    u8 flag;        /* 0xe: pursuit mark while ProcPursuitBeforeSwitch runs */
    u8 pad;         /* 0xf */
} BtlServerEntry;

/* A flag word passed by value to the entry checks. */
typedef union {
    u32 word;
    struct { u32 a:1; u32 b:1; u32 rest:30; } bits;
} CallFlags;


/* Types shared by several parts. */

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[3000];
} BtlServerCmdBuffer;
typedef struct { unsigned low:10, size:9, high:13; } QueueA;
typedef struct { unsigned low:13, size:10, high:9; } QueueB;
typedef struct { unsigned low:28, a:1, b:1, c:1, d:1; } BtlHandExScopeWord;

typedef enum { FALSE = 0, TRUE = 1 } BtlBool;

struct Copy24 { int x[6]; };

struct Unk021BD1E0 {
    u16 moveId;
    u8 userPos;
    u8 targetPos;
    u8 doneFlag;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

/* The parameters of the move being used (0x14 bytes): filled by BTL_SERVER_FLOW_GetMoveParam
   from the move data and the event handlers, then read by every step of the move. */
struct BtlMoveParam {
    u16 moveId;         /* 0x00 */
    u16 origMoveId;     /* 0x02: the move as chosen, before a handler replaced it */
    u16 typePair;       /* 0x04: types of the user */
    u8 type;            /* 0x06: type of the move after the type events */
    u8 pad07;           /* 0x07 */
    u32 damageType;     /* 0x08: physical, special or status */
    u32 range;          /* 0x0C: target range kind of the move */
    union {
        u32 flags;      /* 0x10: bit 0 deferred use, bit 2 replaced move */
        struct { u32 deferred : 1; u32 rest : 31; } bits;
    } u;
};

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

struct State_p06 { u8 pad[5]; u8 a:1; u8 b:1; };

typedef struct { u16 v; u16 idx:5, b:4, pad:4, c:1, pad2:1, flag:1; } Rec_td;

typedef struct { u8 pad0[2]; u8 n; u8 pad3[1]; Rec_td r[1]; } List_td;

struct Unk021D62A8 { u8 pad[0x1c]; union SickCont e[6]; };


enum BtlServerStatKind { K0, K1, K10 = 10 };

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} BtlServerCmdRecoverHp;

typedef struct {
    u32 a : 10;
    u32 b : 9;
    u32 c : 9;
    u32 d : 1;
    u32 e : 1;
    u32 f : 1;
    u32 g : 1;
} Bf_td;

typedef struct {
    u8 pad0[0x68];
    u8 rd[0x4c];      /* 0x68 */
    u32 tab[4][3];    /* 0xb4 */
    u8 cnt[4];        /* 0xe4 */
} Obj_td;

/* ---- BtlServer: the battle server object (lane L189a) ---- */


struct BtlMain;
struct BtlClientSet;
struct BtlSideSlot;
struct BtlServer;
typedef struct BtlServer BtlServer;

/* One step of the server state machine; step counts the calls of the current handler. */
typedef int (*BtlServerHandler)(BtlServer *server, int *step);

/* One network client slot of the server: up to four per battle. */
typedef struct {
    void *adapter;          /* 0x0: command link to the client */
    struct BtlSideSlot *party;  /* 0x4 */
    u8 partyCount;          /* 0x8 */
    u8 battleSlots;         /* 0x9 */
    u8 adapterBorrowed;     /* 0xA: the adapter belongs to the caller, not to the server */
    u8 clientId;            /* 0xB: 0xFF when the slot is unused */
} BtlServerClient;

/* Result message sent to the clients at the end of the battle. */
typedef struct {
    u16 playerClientId;
    u16 result;
} BtlServerResult;

/* The actions each client sent for the turn (up to three each) and how many it sent. */
typedef struct {
    union BtlAction action[4][3];   /* 0x0 */
    u8 count[4];                    /* 0x30 */
} BtlServerActionTable;

struct BtlServer {
    BtlServerHandler handler;       /* 0x0 */
    int step;                       /* 0x4 */
    u32 pad08;                      /* 0x8 */
    struct BtlMain *main;           /* 0xC */
    void *partyTable;               /* 0x10 */
    BtlServerClient clients[4];     /* 0x14 */
    void *flow;                     /* 0x44 */
    int flowResult;                 /* 0x48 */
    int flowParam;                  /* 0x4C */
    BtlRngState rngState;     /* 0x50 */
    BtlRecPacket recorder;          /* 0x68 */
    BtlServerResult result;         /* 0xA8 */
    void *nameBuf;                  /* 0xAC */
    struct BtlClientSet *finalData;  /* 0xB0: clients that escaped, from the flow */
    BtlServerActionTable replies;   /* 0xB4 */
    u8 padE8[4];                    /* 0xE8 */
    u8 shiftPromptMon;              /* 0xEC */
    u8 quitState;                   /* 0xED */
    u8 padEE[2];                    /* 0xEE */
    u8 sendBufStorage[0xBC0];       /* 0xF0 */
    void *sendBuf;                  /* 0xCB0 */
    u8 changeClients[6];            /* 0xCB4 */
    u8 changeCount;                 /* 0xCBA */
    u8 padCBB[4];                   /* 0xCBB */
    u8 changeLock;                  /* 0xCBF */
    u16 heapId;                     /* 0xCC0 */
    u8 padCC2[2];                   /* 0xCC2 */
};

/* One row of gEffortValueStatTable (ov093 0x021EFDC0): the personal parameter
   and the party parameter of one effort value, and the item that boosts it.
   Shared by btl_client.c and btl_server_flow.c. */
typedef struct {
    u8 personalParam;               /* 0x0 personal parameter read by POKE_TOOL_GetPersonalParam */
    u8 pad;                         /* 0x1 */
    u16 partyParam;                 /* 0x2 party parameter read or written by POKE_TOOL_GetPartyValue */
    u16 boosterItem;                /* 0x4 item id that doubles this effort value */
} BtlEffortValueStat;

#endif
