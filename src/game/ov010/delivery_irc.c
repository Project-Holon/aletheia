/*
 * file:     delivery_irc.c
 * unit:     yes
 * function: func_02157954, func_02157960, func_02157968, func_0215796C, func_02157980, func_02157998, func_021579A4, func_021579AC, func_021579B0, func_02157A30, func_02157A58, func_02157A78, func_02157AC8, func_02157AF0, func_02157B88, func_02157C48, func_02157D0C, func_02157D68, func_02157D98, func_02157DB8, func_02157DD8, func_02157E08, func_02157E34, func_02157E6C, func_02157E78, func_02157E8C, func_02157E9C, func_02158318, func_02158344, func_02158378, func_0215839C, func_021583CC, func_021583EC, func_0215840C, func_0215841C, func_02158428, func_02158434, func_0215843C, func_02158468, func_021584A4, func_021584F4, func_0215850C, func_02158570, func_02158590, func_021585BC, func_021585E0, func_02158614, func_02158630, func_02158678, func_021586C8, func_0215870C, func_0215874C
 * address:  0x02157954
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Original file delivery_irc.c (IR delivery of mystery gifts): the create
 * function asserts with "delivery_irc.c". It starts in delivery_beacon.c, whose
 * last function 0x02157948 already uses the delivery IR work, and those two
 * pieces merge at cut time.
 *
 * 0x02157E9C..0x0215874C (gift Pokemon builder, then intrude and game comm
 * helpers) have no file anchor. Their rodata (0x02170068, 0x021700A8,
 * 0x021700AC) lies before the script_sys.c rodata, in the run the tool assigns to
 * delivery_irc.c, and no evidence splits them off, so they stay here for now.
 * They may be one or two separate original files placed between delivery_irc.c
 * and script_sys.c.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0203F328  0x0203F328  arm
 *   func_02179D3C 0x02179D3C thumb ov015
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0217998C  0x0217998C  thumb ov015
 *   func_02039C68 0x02039C68 arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0203D1B4 0x0203D1B4 arm
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   func_02030734 0x02030734 arm
 *   d_02172878 0x02172878 data a1
 *   func_0203CBAC 0x0203CBAC arm
 *   d_02172868 0x02172868 data a1
 *   d_02172808 0x02172808 data a1
 *   func_020307B0  0x020307B0  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   POKE_TOOL_SetDefaultMoves  0x02017FA8  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0202F2AC  0x0202F2AC  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   d_02170068     0x02170068  data
 *   d_0209DF08     0x0209DF08  data  a1
 *   d_0209DF0C     0x0209DF0C  data  a1
 *   d_020A7370     0x020A7370  data
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_020127B8   0x020127B8  thumb
 *   func_020127AC   0x020127AC  thumb
 *   func_02012950   0x02012950  thumb
 *   func_02012B80   0x02012B80  thumb
 *   func_0200855C 0x0200855C thumb
 *   func_02012984  0x02012984  thumb
 *   GAME_DATA_GetSlotFlag  0x02012B98  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   d_021700AC 0x021700AC data a2
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   d_021700A8 0x021700A8 data a2
 *   func_02175B14  0x02175B14  thumb
 *   func_02176258  0x02176258  thumb
 *   func_02176230  0x02176230  thumb
 *   func_02008500  0x02008500  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 */
struct Entry;
struct Link;
struct Req;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct DeliveryIrcEntry {
    u32 size;               /* 0x00 */
    void *data;             /* 0x04 */
    u32 id;                 /* 0x08 */
    u32 mask;               /* 0x0C */
} DeliveryIrcEntry;

typedef struct DeliveryIrcWork DeliveryIrcWork;
typedef void (*DeliveryIrcStepFunc)(DeliveryIrcWork *work);

/* 8-byte message (command +1): the parent's encryption key and data CRC */
typedef struct DeliveryIrcKeyMsg {
    u32 cryptKey;           /* 0x00 */
    u16 crc;                /* 0x04 */
} DeliveryIrcKeyMsg;

/* 8-byte message (command +2): the child asks for the gift with this id and mask */
typedef struct DeliveryIrcRequest {
    u32 id;                 /* 0x00 */
    u32 mask;               /* 0x04 */
} DeliveryIrcRequest;

/* 0x7C-byte parameter block copied in by DELIVERY_IRC_Create */
typedef struct DeliveryIrcParam {
    u32 netCommandBase;     /* 0x00: command id high byte and timing sync number */
    u16 reserved;           /* 0x04 */
    u16 heapId;             /* 0x06 */
    DeliveryIrcEntry entries[7]; /* 0x08 */
    u32 entryCount;         /* 0x78 */
} DeliveryIrcParam;

struct DeliveryIrcWork {
    DeliveryIrcParam param;     /* 0x000 */
    u8 recvBuffer[0x5E8];       /* 0x07C */
    DeliveryIrcEntry *sendEntry; /* 0x664 */
    u32 cryptKey;               /* 0x668 */
    int notFound;               /* 0x66C */
    u16 ackFlag;                /* 0x670 */
    u16 crc;                    /* 0x672 */
    u8 result;                  /* 0x674 */
    u8 isParent;                /* 0x675 */
    u8 found;                   /* 0x676 */
    u8 foundIndex;              /* 0x677 */
    DeliveryIrcStepFunc step;   /* 0x678 */
    DeliveryIrcRequest request; /* 0x67C */
};

typedef signed char s8;

typedef short s16;

typedef int s32;

typedef unsigned long long u64;

#include "../ov011/intrude_comm_types.h"

/* Opaque here: only the accessors in arm9 game_beacon.c and game_data.c read these. */
typedef struct GameComm GameComm;
struct GameSystem;
struct GameData;
struct MyStatus;
struct PokemonParam;
struct StrBank;
struct EventWork;
struct BattleRecSlot;

/*
 * Mystery gift Pokemon record (0xB4 bytes). The three Pokemon values at
 * 0x46, 0x47 and 0x48 are named by the slot they take in the packed IV word
 * (speed fourth, special attack fifth, special defense sixth).
 */
typedef struct GiftMon {
    u32 otId;               /* 0x00: 0 = the player's own trainer ID */
    u32 originGame;         /* 0x04: 0 = the running game's version */
    u32 pid;                /* 0x08: 0 = derived from pidType */
    u16 ribbons;            /* 0x0C: bit k set = ribbon sGiftRibbonIds[k] */
    u16 ball;               /* 0x0E: 0 or above 0x19 = ball 4 */
    u16 item;               /* 0x10 */
    u16 moves[4];           /* 0x12 */
    u16 species;            /* 0x1A */
    u8 form;                /* 0x1C */
    u8 language;            /* 0x1D: 0 = the running game's language */
    u16 nickname[11];       /* 0x1E: first char 0 = invalid, EOS = default name */
    u8 nature;              /* 0x34: 0xFF = random */
    u8 gender;              /* 0x35: 0xFF = random (stored as 2) */
    u8 abilityKind;         /* 0x36: 0, 1, 2 (hidden), 3, 4 = random */
    u8 pidType;             /* 0x37 */
    u16 eggLocation;        /* 0x38 */
    u16 metLocation;        /* 0x3A */
    u8 ballExtra;           /* 0x3C: nonzero = set as ball extra value */
    u8 contestStats[6];     /* 0x3D: cool, beauty, cute, smart, tough; entry 4 is also stored as sheen, entry 5 is unread */
    u8 ivHp;                /* 0x43 */
    u8 ivAttack;            /* 0x44 */
    u8 ivDefense;           /* 0x45 */
    u8 ivSlot5;             /* 0x46: packed sixth (special defense slot) */
    u8 ivSlot3;             /* 0x47: packed fourth (speed slot) */
    u8 ivSlot4;             /* 0x48: packed fifth (special attack slot) */
    u8 pad49;
    u16 otName[8];          /* 0x4A: first char EOS = the player's name */
    u8 otGender;            /* 0x5A: above 2 = the player's gender */
    u8 level;               /* 0x5B: 0 = random 1 to 100 */
    u8 isEgg;               /* 0x5C */
    u8 pad5D[0xAC - 0x5D];
    s32 receivedDate;       /* 0xAC: year in bits 16 to 31, month in 8 to 15, day in 0 to 7 */
    u8 padB0[3];
    u8 formatVersion;       /* 0xB3: must be 1 */
} GiftMon;

extern int func_0203CD98(void);
extern void func_02082D44(void *, void *, u32);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_0203F328(u16 *p, u32 size, u32 seed);
extern int func_02179D3C(void);
extern int func_0203CEAC(int);
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u32 func_0203D378(void);
extern void func_0217998C(int);
extern void func_02039C68(struct Link *, unsigned int, unsigned int);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_020056EC(u32 range);
extern int func_0203D1B4(void);
extern int GFL_NET_StartChangeoverChild(int a0);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern int func_020307B0();
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern u32 func_02008530(const struct MyStatus *status);
extern const void *func_020084F4(const struct MyStatus *status);
extern void *func_020173F0(u16 species, u16 level, u64 id, int heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct PokemonParam *mon, u16 species, u16 level, unsigned long long id, u32 packedIvs, unsigned long long personalRnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_SetDefaultMoves(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *p, u32 a, u32 b);
extern void *func_020185F0(void *p);
extern void func_020185C4(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u16 func_02045A98(void);
extern void *func_02045EC0(struct StrBank *bank, u32 index);
extern int func_02045808();
extern GameComm *func_02012138(struct GameSystem *gameSystem);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern int func_02012B70(const struct GameData *gameData);
extern u32 func_0202648C(GameComm *comm);
extern IntrudeCommSys *func_02026474(GameComm *comm);
extern u32 func_0200FB24(void);
extern u32 func_02026454(GameComm *comm);
extern u32 func_02026460(GameComm *comm);
extern struct GameData *func_02026478(GameComm *comm);
extern u8 func_02012B58(const struct GameData *gameData);
extern struct BattleRecSlot *func_020127B8(struct GameData *gameData);
extern struct BattleRecSlot *func_020127AC(struct GameData *gameData, u32 netId);
extern struct MyStatus *func_02012950(struct GameData *gameData, u32 netId);
extern u8 func_02012B80(const struct GameData *gameData);
extern u8 func_0200855C(const struct MyStatus *status);
extern u8 func_02008550(const struct MyStatus *status);
extern u8 func_02012984(const struct GameData *gameData);
extern u8 GAME_DATA_GetSlotFlag(const struct GameData *gameData, u32 slot);
extern void *func_02012B38(const struct GameData *gameData);
extern u32 func_0201444C(void *fieldStatus);
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern u32 func_020142E8(struct EventWork *eventWork, int flag);
extern int func_02175B14(IntrudeSession *session);
extern int func_02176258(IntrudeCommSys *work);
extern int func_02176230(IntrudeCommSys *work, IntrudeSession *session);
extern void func_02008500(const struct MyStatus *src, struct MyStatus *dst);
extern int func_0203CDBC(void);
void func_02157954(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line);
void func_02157960(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line);
void func_02157968(void);
void func_0215796C(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work);
void func_02157980(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work);
void func_02157998(int netId, int size, const int *msg, DeliveryIrcWork *work);
u8 *func_021579A4(int netId, DeliveryIrcWork *work);
void func_021579AC(DeliveryIrcWork *work);
void func_021579B0(DeliveryIrcWork *work);
void func_02157A30(DeliveryIrcWork *work);
void func_02157A58(DeliveryIrcWork *work);
void func_02157A78(DeliveryIrcWork *work);
void func_02157AC8(DeliveryIrcWork *work);
void func_02157AF0(DeliveryIrcWork *work);
void func_02157B88(DeliveryIrcWork *work);
void func_02157C48(DeliveryIrcWork *work);
void func_02157D0C(DeliveryIrcWork *work);
void func_02157D68(DeliveryIrcWork *work);
void func_02157D98(DeliveryIrcWork *work);
void func_02157DB8(DeliveryIrcWork *work);
void *func_02157DD8(const DeliveryIrcParam *param);
int func_02157E08(DeliveryIrcWork *work);
int func_02157E34(DeliveryIrcWork *work);
unsigned char func_02157E6C(DeliveryIrcWork *work);
void func_02157E78(DeliveryIrcWork *work);
int func_02157E8C(DeliveryIrcWork *work);
struct PokemonParam *func_02157E9C(const GiftMon *gift, int heapId, struct GameData *gameData);
int func_02158318(struct GameSystem *gameSystem);
IntrudeCommSys *func_02158344(GameComm *comm);
int func_02158378(GameComm *comm);
int func_0215839C(IntrudeCommSys *work, int mask, int unused);
struct BattleRecSlot *func_021583CC(struct GameData *gameData, u32 netId);
struct MyStatus *func_021583EC(struct GameData *gameData, u32 netId);
IntrudeMemberEntry *func_0215840C(IntrudeCommSys *work, int index);
u8 func_0215841C(struct GameData *gameData);
u8 func_02158428(IntrudeCommSys *work);
void *func_02158434(IntrudeCommSys *work);
int func_0215843C(GameComm *comm);
int func_02158468(GameComm *comm);
int func_021584A4(GameComm *comm, struct GameData *gameData, int stepKind);
int func_021584F4(int version, u32 trainerId);
int func_0215850C(GameComm *comm, struct GameData *gameData);
int func_02158570(u16 value);
int func_02158590(struct GameData *gameData);
int func_021585BC(IntrudeCommSys *work);
int func_021585E0(GameComm *comm);
void func_02158614(GameComm *comm);
int func_02158630(GameComm *comm);
int func_02158678(GameComm *comm);
int func_021586C8(GameComm *comm, struct MyStatus *out);
int func_0215870C(GameComm *comm, int unused);
void func_0215874C(GameComm *comm);
extern const char d_02172878[];
extern u8 d_02172868[];
extern u8 d_02172808[];
extern const u32 d_02170068[15];
extern u8 d_0209DF08[];
extern u8 d_0209DF0C[];
extern struct StrBank *d_020A7370;
extern const u16 d_021700AC[61];
extern const u16 d_021700A8[2];


/*
 * Unlabelled leaf setter (hidden in a .word run); filed as a helper because
 * its address is the witness for the tail-call thunk at 0x02157960.
 */
void func_02157954(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line)
{
    work->step = step;
}


void func_02157960(DeliveryIrcWork *work, DeliveryIrcStepFunc step, int line)
{
    func_02157954(work, step, line);
}


void func_02157968(void) {}


void func_0215796C(int netId, int size, const DeliveryIrcKeyMsg *msg, DeliveryIrcWork *work)
{
    work->crc = msg->crc;
    work->cryptKey = msg->cryptKey;
}


void func_02157980(int netId, int size, const DeliveryIrcRequest *msg, DeliveryIrcWork *work)
{
    work->request = *msg;
}


void func_02157998(int netId, int size, const int *msg, DeliveryIrcWork *work)
{
    work->notFound = *msg;
}


u8 *func_021579A4(int netId, DeliveryIrcWork *work)
{
    return work->recvBuffer;
}


/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in func_021579B0.
 */
void func_021579AC(DeliveryIrcWork *work)
{
}


void func_021579B0(DeliveryIrcWork *work)
{
    if (func_0203CD98() != 0)
        return;
    if (work->isParent == 0) {
        if (work->notFound == 1) {
            work->result = 3;
        } else {
            work->result = 1;
            func_02082D44(work->recvBuffer, work->param.entries[0].data, work->param.entries[0].size);
            if (work->crc != func_0203F1FC(work->param.entries[0].data, work->param.entries[0].size))
                work->result = 2;
            func_0203F328(work->param.entries[0].data, work->param.entries[0].size, work->cryptKey);
        }
    } else {
        if (work->found == 1)
            work->result = 1;
        else
            work->result = 3;
    }
    func_02157960(work, func_021579AC, 0xF8);
}


void func_02157A30(DeliveryIrcWork *work)
{
    if (func_02179D3C())
        func_0203CEAC(0);
    func_02157960(work, func_021579B0, 0x102);
}


void func_02157A58(DeliveryIrcWork *work)
{
    func_0203CEAC(0);
    func_02157960(work, func_021579B0, 0x10A);
}


void func_02157A78(DeliveryIrcWork *work)
{
    int k = 0x23;
    void *link = func_020399A8();

    if (func_02039CB4(link, 0x23, (u8)work->param.netCommandBase) != 0) {
        if (func_0203D378() != 0) {
            k = 0x12C;
            func_0217998C(k);
            k -= 0x19;
            func_02157960(work, func_02157A30, k);
            return;
        }
        k += 0xF3;
        func_02157960(work, func_02157A58, k);
    }
}


void func_02157AC8(DeliveryIrcWork *work)
{
    int k = 0x23;
    func_02039C68((struct Link *)func_020399A8(), k, (u8)work->param.netCommandBase);
    func_02157960(work, func_02157A78, k + 0xFC);
}


void func_02157AF0(DeliveryIrcWork *work)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x18, (u8)work->param.netCommandBase) == 0)
        return;
    if (work->isParent != 0) {
        if (work->found == 1) {
            DeliveryIrcEntry *entry = &work->param.entries[work->foundIndex];
            int k = 0xFF;
            if (func_0203D3F8((u32)func_020399A8(), 0xFF, (unsigned)(work->param.netCommandBase << 24) >> 16, entry->size, (u32)entry->data, 0, 0, 1) == 0)
                return;
            func_02157960(work, func_02157AC8, k + 0x2F);
            return;
        }
        func_02157960(work, func_02157AC8, 0x133);
        return;
    }
    func_02157960(work, func_02157AC8, 0x137);
}


void func_02157B88(DeliveryIrcWork *work)
{
    if (work->found == 1) {
        DeliveryIrcKeyMsg msg;
        DeliveryIrcEntry *entry = work->sendEntry;
        msg.crc = func_0203F1FC(entry->data, entry->size);
        msg.cryptKey = work->cryptKey;
        if (func_0203D3A8(func_020399A8(), (u16)((work->param.netCommandBase << 8) + 1), (u16)8, (u32)&msg) == 0)
            return;
        func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)work->param.netCommandBase);
        work->ackFlag = 0;
        func_02157960(work, func_02157AF0, 0x152);
        return;
    }
    work->notFound = 1;
    if (func_0203D3A8(func_020399A8(), (u16)((work->param.netCommandBase << 8) + 3), (u16)4, (u32)&work->notFound) == 0)
        return;
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)work->param.netCommandBase);
    work->ackFlag = 0;
    func_02157960(work, func_02157AF0, 0x162);
}


/*
 * levers: the RNG result is the third argument to func_0203F328, kept live
 *   in r2 across its preceding store. The bound is read as p->n in the for
 *   condition rather than through n; expanding that one use changes the
 *   hoisted bound/far-word allocation from r7/r6 to the original r6/r7.
 */
void func_02157C48(DeliveryIrcWork *work)
{
    DeliveryIrcEntry *entry;
    u32 i;
    unsigned long count;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x17, (u8)work->param.netCommandBase) == 0)
        return;
    if (work->isParent != 0) {
        entry = 0;
        work->found = 0;
        count = work->param.entryCount;
        for (i = 0; i < work->param.entryCount; i++) {
            entry = &work->param.entries[i];
            if (entry->id == work->request.id && (entry->mask & work->request.mask)) {
                work->foundIndex = i;
                work->found = 1;
                break;
            }
        }
        func_02157960(work, func_02157B88, 0x188);
        if (work->found == 1) {
            u32 key = func_020056EC(0);
            work->cryptKey = key;
            func_0203F328(entry->data, entry->size, key);
            work->sendEntry = entry;
        }
        return;
    }
    func_02039C68((struct Link *)func_020399A8(), 0x18, (u8)work->param.netCommandBase);
    func_02157960(work, func_02157AF0, 0x193);
}


void func_02157D0C(DeliveryIrcWork *work)
{
    if (work->isParent == 0) {
        work->request.id = work->param.entries[0].id;
        work->request.mask = work->param.entries[0].mask;
        if (func_0203D3A8(func_020399A8(), (u16)((work->param.netCommandBase << 8) + 2), (u16)8, (u32)&work->request) == 0)
            return;
        func_02157960(work, func_02157C48, 0x1A2);
        return;
    }
    func_02157960(work, func_02157C48, 0x1A6);
}


void func_02157D68(DeliveryIrcWork *work)
{
    if (func_0203D1B4() > 1) {
        func_02039C68((struct Link *)func_020399A8(), 0x17, (u8)work->param.netCommandBase);
        func_02157960(work, func_02157D0C, 0x1AF);
    }
}


void func_02157D98(DeliveryIrcWork *work)
{
    GFL_NET_StartChangeoverChild(0);
    func_02157960(work, func_02157D68, 0x1B7);
}


void func_02157DB8(DeliveryIrcWork *work)
{
    if (func_0203CD98() == 1)
        func_02157960(work, func_02157D98, 0x1BE);
}


void *func_02157DD8(const DeliveryIrcParam *param)
{
    void *work = func_02030734(param->heapId, 0x684, 1, d_02172878, 0x1CD);
    func_02082D44((void *)param, work, 0x7C);
    return work;
}


int func_02157E08(DeliveryIrcWork *work)
{
    if (func_0203CD98() != 0)
        return 0;
    d_02172868[7] = work->param.netCommandBase;
    func_0203CBAC((struct Req *)d_02172808, 0, (u32)work);
    return 1;
}


int func_02157E34(DeliveryIrcWork *work)
{
    int started = func_02157E08(work);
    work->isParent = 0;
    work->found = 0;
    work->foundIndex = 0;
    work->notFound = 0;
    func_02157960(work, func_02157DB8, 0x231);
    return started;
}


/*
 * extent: Accessor ends at 02157E78, followed by labelled callback function.
 */
unsigned char func_02157E6C(DeliveryIrcWork *work)
{
    return work->result;
}


void func_02157E78(DeliveryIrcWork *work)
{
    DeliveryIrcStepFunc step = work->step;
    if (step != 0)
        step(work);
}


int func_02157E8C(DeliveryIrcWork *work)
{
    func_020307B0(work);
    return func_0203CEAC(0);
}


/*
 * Builds a Pokemon from a mystery gift record, or returns 0 when the record
 * is invalid (wrong format version, species above 649, level above 100, item
 * above 626, bad ability kind, empty nickname or OT name) or the finished
 * Pokemon fails its final value check. The Pokemon is allocated in heap
 * heapId. A random value is taken for every field the record leaves open.
 *
 * Lever: gender is a u8 local, loaded from GiftMon.gender and remapped from
 * 0xFF to 2; the form argument of the personality call is cast to u8.
 */
struct PokemonParam *func_02157E9C(const GiftMon *gift, int heapId, struct GameData *gameData)
{
    u16 moves[4];
    u8 ivValues[6];
    u32 month;
    u32 abilityKind;
    u8 gender;
    u64 personalRnd;
    u32 species;
    u32 otId;
    u64 otId64;
    u16 level;
    u32 abilitySlot;
    struct PokemonParam *result;
    u32 packedIvs;
    int i;
    u32 ribbonBit;
    u16 move;
    struct PokemonParam *mon;
    void *eggName;
    u32 nature;
    u8 day;
    u16 year;
    u32 metLocation;

    level = gift->level;
    otId = gift->otId;
    species = gift->species;
    gender = gift->gender;
    abilityKind = gift->abilityKind;
    ivValues[0] = gift->ivHp;
    ivValues[1] = gift->ivAttack;
    ivValues[2] = gift->ivDefense;
    ivValues[3] = gift->ivSlot3;
    ivValues[4] = gift->ivSlot4;
    ivValues[5] = gift->ivSlot5;
    moves[0] = gift->moves[0];
    moves[1] = gift->moves[1];
    moves[2] = gift->moves[2];
    moves[3] = gift->moves[3];

    if (gift->formatVersion != 1) {
        result = 0;
        goto out;
    }
    if (species > 649) {
        result = 0;
        goto out;
    }
    if (species == 0) {
        result = 0;
        goto out;
    }
    if (level > 100) {
        result = 0;
        goto out;
    }
    if (gift->item > 626) {
        result = 0;
        goto out;
    }

    if (level == 0)
        level = func_020056EC(100) + 1;
    if (gift->otId == 0)
        otId = func_02008530(func_02012944(gameData));
    if (gender == 0xFF)
        gender = 2;
    for (i = 0; i < 6; i++) {
        if (ivValues[i] == 0xFF)
            ivValues[i] = func_020056EC(32);
    }

    otId64 = otId;
    mon = func_020173F0(species, level, otId64, heapId);
    packedIvs = (ivValues[0] & 0x1F) | ((ivValues[1] & 0x1F) << 5) | ((ivValues[2] & 0x1F) << 10)
        | ((ivValues[3] & 0x1F) << 15) | ((ivValues[4] & 0x1F) << 20) | ((ivValues[5] & 0x1F) << 25);

    if (abilityKind == 4)
        abilityKind = (u8)func_020056EC(3);
    switch (abilityKind) {
    case 0:
        abilitySlot = 0;
        break;
    case 1:
        abilitySlot = 1;
        break;
    case 2:
        abilitySlot = 0;
        break;
    case 3:
        abilitySlot = 2;
        break;
    default:
        result = 0;
        goto out;
    }

    if (gift->pid != 0) {
        personalRnd = gift->pid;
    } else if (gift->pidType == 0) {
        personalRnd = func_020186C8(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 0);
    } else if (gift->pidType == 1) {
        personalRnd = func_020186C8(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 2);
    } else if (gift->pidType == 2) {
        personalRnd = func_020186C8(otId, (u16)species, (u8)gift->form, gender, abilitySlot, 1);
    }

    func_02017588(mon, gift->species, level, otId64, packedIvs, personalRnd);
    func_02017E40(mon, 6, gift->item);
    POKE_TOOL_SetDefaultMoves(mon);
    for (i = 0; i < 4; i++) {
        move = moves[i];
        if (move != 0 && move < 0x230) {
            if (func_0201808C(mon, move) == 0xFFFF)
                func_020180F4(mon, move);
        }
    }
    if (gift->pid == 0 && abilityKind == 2)
        func_02018A00(mon, species, gift->form);
    func_02017E40(mon, 0x6F, gift->form);
    if (gift->ball != 0 && gift->ball <= 0x19)
        func_02017E40(mon, 0x98, gift->ball);
    else
        func_02017E40(mon, 0x98, 4);
    if (gift->ballExtra != 0)
        func_02017E40(mon, 0x99, gift->ballExtra);
    func_02017E40(mon, 0x13, gift->contestStats[0]);
    func_02017E40(mon, 0x14, gift->contestStats[1]);
    func_02017E40(mon, 0x15, gift->contestStats[2]);
    func_02017E40(mon, 0x16, gift->contestStats[3]);
    func_02017E40(mon, 0x17, gift->contestStats[4]);
    func_02017E40(mon, 0x18, gift->contestStats[4]);
    for (ribbonBit = 0; ribbonBit < 15; ribbonBit++) {
        if (gift->ribbons & (1 << ribbonBit))
            func_02017E40(mon, d_02170068[ribbonBit], 1);
    }
    if (gift->originGame == 0)
        func_02017E40(mon, 0x77, d_0209DF08[0]);
    else
        func_02017E40(mon, 0x77, gift->originGame);
    if (gift->language == 0)
        func_02017E40(mon, 0xC, d_0209DF0C[0]);
    else
        func_02017E40(mon, 0xC, gift->language);
    if (gift->nickname[0] == 0) {
        func_020307B0(mon);
        result = 0;
        goto out;
    }
    if (gift->nickname[0] != func_02045A98())
        func_02017E40(mon, 0x74, (u32)gift->nickname);
    nature = gift->nature;
    if (nature == 0xFF)
        nature = (u8)func_020056EC(25);
    func_02017E40(mon, 0x70, nature);
    func_02017E40(mon, 0x95, gift->eggLocation);
    func_02017E40(mon, 0x96, gift->metLocation);
    if (gift->otName[0] == 0) {
        func_020307B0(mon);
        result = 0;
        goto out;
    }
    if (gift->otName[0] == func_02045A98())
        func_02017E40(mon, 0x8E, (u32)func_020084F4(func_02012944(gameData)));
    else
        func_02017E40(mon, 0x8E, (u32)gift->otName);
    if (gift->otGender <= 2)
        func_02017E40(mon, 0x9A, gift->otGender);
    else
        func_02017E40(mon, 0x9A, func_02008550(func_02012944(gameData)));
    if (gift->isEgg) {
        func_02017E40(mon, 0x4C, 1);
        eggName = func_02045EC0(d_020A7370, 0x28A);
        func_02017E40(mon, 0x73, (u32)eggName);
        func_02045808(eggName);
        func_02017E40(mon, 9, 10);
    }
    year = gift->receivedDate >> 16;
    month = (u8)(gift->receivedDate >> 8);
    day = gift->receivedDate;
    metLocation = gift->isEgg ? gift->eggLocation : gift->metLocation;
    func_0202F2AC(func_020185F0(mon), metLocation, year - 2000, month, day);
    func_020185C4(mon);
    result = 0;
    if (func_02017E1C(mon, 3, 0) != 0)
        func_020307B0(mon);
    else
        result = mon;
out:
    return result;
}


/*
 * Returns 0 while the game data has exactly one visit count and the
 * game comm counter is nonzero, else 1.
 */
int func_02158318(struct GameSystem *gameSystem)
{
    GameComm *comm = func_02012138(gameSystem);
    struct GameData *gameData = func_020120F4(gameSystem);

    if (func_02012B70(gameData) == 1 && func_0202648C(comm) != 0)
        return 0;
    return 1;
}


/*
 * The intrude comm work of the game comm, or 0 unless the game comm runs
 * kind 2 outside a transition from kind 1 and the work exists.
 */
IntrudeCommSys *func_02158344(GameComm *comm)
{
    IntrudeCommSys *work = func_02026474(comm);

    if (func_0200FB24() != 0 || func_02026454(comm) != 2 || func_02026460(comm) == 1 || work == 0)
        return 0;
    return work;
}


int func_02158378(GameComm *comm)
{
    IntrudeCommSys *work = func_02158344(comm);

    if (work == 0) {
        return func_02012B58(func_02026478(comm));
    }
    return work->ownNetId;
}


/*
 * When one of the mask bits is set in the 2-bit peer flags, flips the low
 * bit of the flags and answers 1.
 */
int func_0215839C(IntrudeCommSys *work, int mask, int unused)
{
    u8 flags = work->peerFlags;

    if (mask & flags) {
        work->peerFlags ^= 1;
        return 1;
    }
    return 0;
}


/*
 * The battle record slot of a net ID: the last-battle slot for the own net
 * ID, the per-ID slot for any other.
 */
struct BattleRecSlot *func_021583CC(struct GameData *gameData, u32 netId)
{
    if (func_02012B58(gameData) == netId)
        return func_020127B8(gameData);

    return func_020127AC(gameData, netId);
}


/*
 * The MyStatus of a net ID: the own status for the own net ID, the player
 * status of the net ID for any other.
 */
struct MyStatus *func_021583EC(struct GameData *gameData, u32 netId)
{
    if (func_02012B58(gameData) == netId)
        return func_02012944(gameData);

    return func_02012950(gameData, netId);
}


/*
 * Address of the member entry (0x28 bytes) of the session at index.
 */
IntrudeMemberEntry *func_0215840C(IntrudeCommSys *work, int index)
{
    return &work->session.members[index];
}


/*
 * The net ID of the player whose area is visited, as a byte.
 */
u8 func_0215841C(struct GameData *gameData)
{
    return (u8)(unsigned)func_02012B80(gameData);
}


/*
 * Unlabelled leaf (no lr save, so disasm.py prints it inside the extent of
 * func_0215841C); sole blocker of ov018 func_0217D1C0. Followed by another
 * unlabelled leaf at 0x02158434.
 */
u8 func_02158428(IntrudeCommSys *work)
{
    return work->unionInfoReceived;
}


/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 func_021870C4.
 */
void *func_02158434(IntrudeCommSys *work)
{
    return work->returnSlots;
}


/*
 * Version code (20 or 21) of the owner of the visited area. Answers 21
 * when no visit is running.
 *
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 */
int func_0215843C(GameComm *comm)
{
    struct GameData *gameData = func_02026478(comm);
    u8 areaOwnerId;

    if (func_02012B70(gameData) == 0)
        return 21;
    areaOwnerId = (int)func_02012B80(gameData);
    return func_0200855C(func_021583EC(gameData, areaOwnerId));
}


/*
 * The season of the game data when no visit runs or the visited area is the
 * own one, else the slot flag of the visited area's owner.
 */
int func_02158468(GameComm *comm)
{
    struct GameData *gameData = func_02026478(comm);
    u8 areaOwnerId;

    if (func_02012B70(gameData) == 0) {
        return func_02012984(gameData);
    }
    areaOwnerId = func_0215841C(gameData);
    if (areaOwnerId == func_02012B58(gameData)) {
        return func_02012984(gameData);
    }
    return GAME_DATA_GetSlotFlag(gameData, areaOwnerId);
}


/*
 * Whether stepping the local area owner ID one place back (stepKind 2) or
 * forward, wrapping at the highest net ID, lands on the own net ID. Answers 1
 * when no visit work exists.
 */
int func_021584A4(GameComm *comm, struct GameData *gameData, int stepKind)
{
    IntrudeCommSys *work = func_02158344(comm);
    int next;
    int current;

    if (work == 0)
        return 1;
    current = work->localPeer.intrudeId;
    if (stepKind == 2) {
        next = current - 1;
        if (next < 0)
            next = work->lastAreaIndex;
    } else {
        next = current + 1;
        if (next >= work->lastAreaIndex + 1)
            next = 0;
    }
    if (next == func_02012B58(gameData))
        return 1;
    return 0;
}


/*
 * Normalizes a version code to 20 or 21: other codes become 20 when bit 16
 * of the trainer ID is set, else 21.
 */
int func_021584F4(int version, u32 trainerId)
{
    if (version == 21)
        return version;
    if (version == 20)
        return version;
    if (trainerId & 0x10000)
        return 20;
    return 21;
}


/*
 * Version class of the visited area's owner: 0 for the own area or when the
 * field status is not map mode 1, 1 for version 20, 2 for version 21, 3 for
 * any other. The work of the comm is fetched first and not used.
 */
int func_0215850C(GameComm *comm, struct GameData *gameData)
{
    u8 areaOwnerId;
    struct MyStatus *status;
    int version;

    func_02158344(comm);
    if (func_0201444C(func_02012B38(gameData)) != 1)
        return 0;
    areaOwnerId = func_0215841C(gameData);
    if (areaOwnerId == func_02012B58(gameData))
        return 0;
    status = func_02012950(gameData, areaOwnerId);
    version = func_021584F4(func_0200855C(status), func_02008530(status));
    switch (version) {
    case 20:
        return 1;
    case 21:
        return 2;
    default:
        return 3;
    }
}


/*
 * Whether value is one of the 61 ids of the table.
 *
 * lever: The ternary loop condition preserves the branch to the bottom test.
 */
int func_02158570(u16 value)
{
    unsigned int i;

    for (i = 0; (i < 61) ? 1 : 0; i++) {
        if (value == d_021700AC[i])
            return 1;
    }
    return 0;
}


/*
 * Whether both event flags of the table are set.
 */
int func_02158590(struct GameData *gameData)
{
    struct EventWork *eventWork = func_0201296C(gameData);
    unsigned int i;

    for (i = 0; i < 2; i++) {
        if (func_020142E8(eventWork, d_021700A8[i]) == 0)
            return 0;
    }
    return 1;
}


/*
 * 1 when the session has been warned but no request is active.
 */
int func_021585BC(IntrudeCommSys *work)
{
    if (work->warned != 0 && func_02175B14(&work->session) == 0)
        return 1;
    return 0;
}


/*
 * Progress of the visit: 0 without work, 3 once the gear reported flag is set,
 * else 2 or 1 from the state of func_02158630 (3 gives 2).
 *
 * Callee 02158344 consumes incoming r0.
 */
int func_021585E0(GameComm *comm)
{
    IntrudeCommSys *work = func_02158344(comm);

    if (work == 0)
        return 0;
    if (work->gearReported == 0) {
        if (func_02158630(comm) == 3)
            return 2;
        return 1;
    }
    return 3;
}


/*
 * Sets the gear reported flag of the work.
 *
 * The callee reads its incoming r0; legacy void prototypes omit it.
 */
void func_02158614(GameComm *comm)
{
    IntrudeCommSys *work = func_02158344(comm);

    if (work != 0)
        work->gearReported = 1;
}


/*
 * State of the active request: 0 without work, 1 without an active
 * session, 2 when the request is the player's own, else 1 or 3 by the
 * event flags (3 when both are set).
 */
int func_02158630(GameComm *comm)
{
    IntrudeCommSys *work = func_02158344(comm);

    if (work == 0)
        return 0;
    if (func_02175B14(&work->session) == 1) {
        if (func_02176258(work) == 1)
            return 2;
        if (func_02158590(func_02026478(comm)) == 0)
            return 1;
        return 3;
    }
    return 1;
}


/*
 * Number of peers with the event flag set (at least 1) while a session is
 * active, else 0.
 */
int func_02158678(GameComm *comm)
{
    int count = 0;
    u8 i;
    IntrudeCommSys *work = func_02158344(comm);

    if (work == 0)
        return count;
    if (func_02175B14(&work->session) == 0)
        return count;
    for (i = 0; i < 3; i++) {
        if (work->peers[i].eventJoined == 1)
            count++;
    }
    if (count == 0)
        count = 1;
    return count;
}


/*
 * Copies the status of the requester of the active session to out. Answers 0
 * when no work or no active session exists.
 */
int func_021586C8(GameComm *comm, struct MyStatus *out)
{
    IntrudeCommSys *work = func_02158344(comm);
    struct GameData *gameData = func_02026478(comm);

    if (work == 0 || func_02175B14(&work->session) == 0)
        return 0;
    func_02008500(func_02012950(gameData, func_02176230(work, &work->session)), out);
    return 1;
}


/*
 * Three guards (kind == 2, a non-null work, session-ended bit set) then a
 * predicate whose one result is inverted.
 */
int func_0215870C(GameComm *comm, int unused)
{
    IntrudeCommSys *work;

    if (func_02026454(comm) != 2)
        return 0;
    work = func_02026474(comm);
    if (work == 0)
        return 0;
    if (work->sessionEnded == 0)
        return 0;
    if (func_0203CDBC() == 1)
        return 0;
    return 1;
}


/*
 * Clears the 2-bit zone check of the work.
 */
void func_0215874C(GameComm *comm)
{
    IntrudeCommSys *work = func_02158344(comm);

    if (work != 0)
        work->zoneCheck = 0;
}
