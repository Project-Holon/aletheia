#ifndef BTL_SERVER_TYPES_H
#define BTL_SERVER_TYPES_H
/* ov093 battle server: types shared by every part of btl_server.c. */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/* One word describing an action; the two views share the first three fields. */
typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, z:1, rest:21; } small;
    u32 w;
} Action;

typedef struct {
    u8 *pokeParam;  /* 0x0: BTL_POKEPARAM of the acting poke */
    Action action;  /* 0x4 */
    u32 orderKey;   /* 0x8: bits 0-12 speed, 13-15 speed order, 16-21 move priority, 22-24 action class */
    u8 clientId;    /* 0xc */
    u8 done;        /* 0xd */
    u8 flag;        /* 0xe: pursuit mark while ProcPursuitBeforeSwitch runs */
    u8 pad;         /* 0xf */
} Entry;

/* A flag word passed by value to the entry checks. */
typedef union {
    u32 word;
    struct { u32 a:1; u32 b:1; u32 rest:30; } bits;
} CallFlags;

/* A one-word status value passed by value; the views overlap. */
union Slot {
    u32 raw;
    struct { u32 kind:3; u32 rest:29; } k;
};


/* Types shared by several parts. */
typedef struct { u16 v; } W_021C312C;

typedef struct {
    u32 wpos;
    u32 rpos;
    u8 buf[3000];
} Buf_021CC768;
typedef struct { unsigned low:10, size:9, high:13; } QueueA;
typedef struct { unsigned low:13, size:10, high:9; } QueueB;
typedef struct { unsigned low:28, a:1, b:1, c:1, d:1; } Word_021CC768;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

struct Copy24 { int x[6]; };

struct Unk021BD1E0 {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

struct Q { u16 h0; u8 pad[6]; u32 w8; };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

struct State_p06 { u8 pad[5]; u8 a:1; u8 b:1; };

typedef struct { u16 v; u16 idx:5, b:4, pad:4, c:1, pad2:1, flag:1; } Rec_td;

typedef struct { u8 pad0[2]; u8 n; u8 pad3[1]; Rec_td r[1]; } List_td;

struct Unk021D62A8 { u8 pad[0x1c]; union Slot e[6]; };

struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

enum Kind { K0, K1, K10 = 10 };

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 mid : 10; u32 fl : 1; u32 top : 8;
    u16 h4; u8 b6; u8 b7; u16 h8; u16 ha;
} Ent_021C8D2C;

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

/*
 * Random number generator state: the same 24 bytes as BtlRngState in
 * btl_calc_types.h, as plain words so that files which do not include that
 * header still build.
 */
typedef struct {
    s32 word[6];
} BtlServerRngState;

struct BtlMain;
struct BtlServer;
typedef struct BtlServer BtlServer;

/* One step of the server state machine; step counts the calls of the current handler. */
typedef int (*BtlServerHandler)(BtlServer *server, int *step);

/* One network client slot of the server: up to four per battle. */
typedef struct {
    void *adapter;          /* 0x0: command link to the client */
    void *party;            /* 0x4 */
    u8 partyCount;          /* 0x8 */
    u8 battleSlots;         /* 0x9 */
    u8 adapterBorrowed;     /* 0xA: the adapter belongs to the caller, not to the server */
    u8 clientId;            /* 0xB: 0xFF when the slot is unused */
} BtlServerClient;

/* One reply word; the copy loops need the struct wrapper to match. */
typedef struct {
    u32 value;
} BtlServerWord;

/* Reply words of one client. */
typedef struct {
    BtlServerWord word[3];
} BtlServerReply;

/* Result message sent to the clients at the end of the battle. */
typedef struct {
    u16 playerClientId;
    u16 result;
} BtlServerResult;

typedef struct {
    u32 first;
    u32 second;
} BtlWordPair;

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
    BtlServerRngState rngState;     /* 0x50 */
    u8 recorder[0x40];              /* 0x68 */
    BtlServerResult result;         /* 0xA8 */
    void *nameBuf;                  /* 0xAC */
    BtlWordPair *finalData;           /* 0xB0 */
    BtlServerReply reply[4];        /* 0xB4 */
    u8 replyCount[4];               /* 0xE4 */
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

/* Four action words per client followed by one byte per client; the home of this table is unknown. */
typedef struct {
    Action action[4][3];            /* 0x0 */
    u8 value[4];                    /* 0x30 */
} BtlServerActionTable;

#endif
