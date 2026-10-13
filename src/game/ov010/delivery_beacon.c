/*
 * file:     delivery_beacon.c
 * unit:     yes
 * function: func_0215766C, func_021576A8, func_021576AC, func_021576B8, func_021576C4, func_021576CC, func_021576D0, func_02157700, func_02157724, func_02157760, func_02157818, func_02157870, func_0215788C, func_021578A0, func_021578F0, func_02157910, func_02157928, func_02157938, func_02157948
 * address:  0x0215766C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   gDeliveryBeaconAllocSite  0x021727F4  data
 *   func_02034714 0x02034714 arm
 *   gDeliveryBeaconAssertText 0x021727F0 data a4
 *   func_02177B2C  0x02177B2C  thumb  ov014
 *   func_02177BAC  0x02177BAC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_021780C4  0x021780C4  thumb  ov014
 *   func_02177BCC  0x02177BCC  thumb  ov014
 *   func_0203F328  0x0203F328  arm
 *   func_0203D010 0x0203D010 arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   gDeliveryBeaconNetInit  0x02172780  data  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_0203CEAC  0x0203CEAC  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#include "../arm9/net_types.h"

#define DELIVERY_BEACON_SLOTS_PER_PAGE 18
#define DELIVERY_BEACON_PAGE_MAX 7
#define DELIVERY_BEACON_PIECE_SIZE 0x54
#define DELIVERY_BEACON_NO_SENDER 0xFF

typedef enum { DELIVERY_BEACON_COUNT_ZERO = 0 } DeliveryBeaconCount;

struct DeliveryBeacon;
typedef void (*DeliveryBeaconStepFunc)(struct DeliveryBeacon *work);

/* One received piece: the same 100 bytes as the beacon entry it was copied from. */
typedef struct DeliveryBeaconSlot {
    u16 checksum;                         /* 00: CRC of data */
    u8  reserved02[2];
    u32 seed;                             /* 04: seed for the data cipher */
    u8  data[DELIVERY_BEACON_PIECE_SIZE]; /* 08 */
    u8  pieceNumber;                      /* 5C: 1-based index of this piece, 0 = empty */
    u8  pieceCount;                       /* 5D: number of pieces in the whole delivery */
    u8  senderId;                         /* 5E */
    u8  gameVersion;                      /* 5F */
    u32 requiredMask;                     /* 60: receiver must have one of these bits */
} DeliveryBeaconSlot;

/* The caller's 0x7C-byte setup block; Create copies it to the start of the work. */
typedef struct DeliveryBeaconParam {
    u32 gameKind;                         /* 00: written to the net init block */
    u16 reserved04;
    u16 heapId;                           /* 06 */
    int destSize;                         /* 08: size of dest, at least 18 pieces */
    u8 *dest;                             /* 0C: receives the decoded pieces */
    u32 gameVersion;                      /* 10: pieces must carry this version */
    u32 acceptMask;                       /* 14: tested against requiredMask */
    u8  reserved18[0x60];
    u32 pageCount;                        /* 78 */
} DeliveryBeaconParam;

typedef struct DeliveryBeacon {
    DeliveryBeaconParam param;            /* 000 */
    DeliveryBeaconSlot slots[DELIVERY_BEACON_PAGE_MAX][DELIVERY_BEACON_SLOTS_PER_PAGE]; /* 07C */
    int cursor;                           /* 31B4: next slot, page * 18 + index */
    u8  lockedSender;                     /* 31B8: sender of the first accepted piece */
    u8  reserved31B9[3];
    DeliveryBeaconStepFunc step;          /* 31BC */
} DeliveryBeacon;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082D44(void *src, void *dst, u32 size);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern DeliveryBeaconSlot *func_02177B2C(int index);
extern void func_02177BAC(u32 index);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_021780C4(u32 index);
extern void func_02177BCC(void);
extern void func_0203F328(u16 *data, u32 size, u32 seed);
extern void func_0203D010(void);
extern int func_0203CD98(void);
extern void func_0203CBAC(GFLNetInitializeStruct *init, u32 transportArg, u32 userArg);
extern u32 func_020307B0(void *ptr);
extern int func_0203CEAC(int arg);
DeliveryBeaconSlot *func_0215766C(DeliveryBeacon *work);
void func_021576B8(DeliveryBeacon *work, DeliveryBeaconStepFunc step);
void func_021576C4(DeliveryBeacon *work, DeliveryBeaconStepFunc step, int line);
void func_021576CC(DeliveryBeacon *work);
DeliveryBeacon *func_021576D0(DeliveryBeaconParam *param);
void func_02157700(DeliveryBeacon *work);
int func_02157724(DeliveryBeacon *work);
void func_02157760(DeliveryBeacon *work);
void func_02157818(DeliveryBeacon *work);
void func_02157870(DeliveryBeacon *work);
void func_0215788C(DeliveryBeacon *work);
int func_021578A0(DeliveryBeacon *work);
int func_021578F0(DeliveryBeacon *work);
int func_02157910(DeliveryBeacon *work);
void func_02157928(DeliveryBeacon *work);
int func_02157938(DeliveryBeacon *work);
extern const char gDeliveryBeaconAllocSite[];
extern char gDeliveryBeaconAssertText[];
extern GFLNetInitializeStruct gDeliveryBeaconNetInit;


DeliveryBeaconSlot *func_0215766C(DeliveryBeacon *work)
{
    int v = work->cursor;
    int rem = v % DELIVERY_BEACON_SLOTS_PER_PAGE;
    u32 page = v / DELIVERY_BEACON_SLOTS_PER_PAGE;

    if (page >= work->param.pageCount) {
        page = 0;
        work->cursor = 0;
    }
    return &work->slots[page][rem];
}


int func_021576A8(void) { return 100; }

int func_021576AC(int lhs, int rhs) { return lhs == rhs; }


/*
 * Recursive MATCH unblocker: matched so the ABS32 site in
 * ov010_func_021576C4 attests as `matched`.
 */
void func_021576B8(DeliveryBeacon *work, DeliveryBeaconStepFunc step)
{
    work->step = step;
}


/*
 * Unblocked by matching func_021576B8 (ov010, EXACT). The ABS32 site +0004 now
 * attests as `matched`.
 * The listing extent is now 8 bytes, so the verdict is plain EXACT.
 *
 * `line`: every caller loads r2 with a constant, but the callee never
 * reads it, so the thunk takes it and drops it.
 */
void func_021576C4(DeliveryBeacon *work, DeliveryBeaconStepFunc step, int line)
{
    func_021576B8(work, step);
}


/*
 * Unlabelled empty callback (bx lr) hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 */
void func_021576CC(DeliveryBeacon *work)
{
}


DeliveryBeacon *func_021576D0(DeliveryBeaconParam *param)
{
    DeliveryBeacon *work;

    work = func_02030734(param->heapId, 0x31C0, 1, gDeliveryBeaconAllocSite, 0x127);
    func_02082D44(param, work, sizeof(DeliveryBeaconParam));
    return work;
}


void func_02157700(DeliveryBeacon *work)
{
    if (work->param.destSize != 0 && work->param.destSize >= DELIVERY_BEACON_SLOTS_PER_PAGE * DELIVERY_BEACON_PIECE_SIZE)
        func_02034714(gDeliveryBeaconAssertText, 0, gDeliveryBeaconAssertText);
}


/*
 * extent: 58-byte body followed by 2-byte alignment padding.
 * lever: enum bound preserves the entry guard; declare index before bound.
 */
int func_02157724(DeliveryBeacon *work)
{
    int i;
    DeliveryBeaconCount count;

    count = work->slots[0][0].pieceCount;
    if (count == 0)
        return 0;
    for (i = 0; i < count; i++) {
        if (count != work->slots[0][i].pieceCount)
            return 0;
    }
    return 1;
}


/*
 * Wave 75: ov014 leaves 0x021780C4 and 0x02177BCC filed and verified;
 *   all six relocations resolve. 0x02177BAC was already matched.
 * levers (lane R1): the old 3-slot frame miss was the `sel`/`sel2` locals, which
 *   copy-propagate into one; the original writes lockedSender directly and the two stack
 *   slots are the loop-hoisted 0x31B8 address. `(e+0x60) & (q+0x14)` operand order,
 *   and the CRC result in a named local for `cmp r0, r1`.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = q;` before `base = q + 0x7C;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_02157760(DeliveryBeacon *work)
{
    int i;
    DeliveryBeaconSlot *entry;
    int pieceIndex;
    u32 crc;

    for (i = 0; i < 16; i++) {
        entry = func_02177B2C(i);
        if (entry == 0)
            continue;
        if (entry->gameVersion != work->param.gameVersion) {
            func_02177BAC(i);
        } else if ((entry->requiredMask & work->param.acceptMask) == 0) {
            func_02177BAC(i);
        } else if (entry->senderId != work->lockedSender && work->lockedSender != DELIVERY_BEACON_NO_SENDER) {
            func_02177BAC(i);
        } else {
            pieceIndex = entry->pieceNumber - 1;
            if (pieceIndex >= DELIVERY_BEACON_SLOTS_PER_PAGE)
                continue;
            if (work->slots[0][pieceIndex].pieceNumber != 0)
                continue;
            crc = func_0203F1FC(entry->data, DELIVERY_BEACON_PIECE_SIZE);
            if (crc != entry->checksum) {
                func_02177BAC(i);
            } else {
                if (work->lockedSender == DELIVERY_BEACON_NO_SENDER)
                    work->lockedSender = entry->senderId;
                func_021780C4(i);
                func_02082D44(entry, &work->slots[0][pieceIndex], sizeof(DeliveryBeaconSlot));
                func_02177BCC();
            }
        }
    }
}


void func_02157818(DeliveryBeacon *work)
{
    int i;
    DeliveryBeaconSlot *slot;

    for (i = 0; i < DELIVERY_BEACON_SLOTS_PER_PAGE; i++) {
        u32 off = i * DELIVERY_BEACON_PIECE_SIZE;
        u32 n;

        slot = &work->slots[0][i];
        func_0203F328((u16 *)slot->data, DELIVERY_BEACON_PIECE_SIZE, slot->seed);
        n = (u16)off;
        if (work->param.destSize > (int)(n + DELIVERY_BEACON_PIECE_SIZE))
            func_02082D44(slot->data, work->param.dest + off, DELIVERY_BEACON_PIECE_SIZE);
        else
            func_02082D44(slot->data, work->param.dest + off, work->param.destSize - n);
    }
}


/*
 * extent: 28-byte lead followed by existing matched ov010_func_0215788C.c.
 */
void func_02157870(DeliveryBeacon *work) { func_0203D010(); func_021576C4(work, func_02157760, 0x1d7); }


/*
 * Unlabelled tail-call thunk hidden in a .word run; witness for the
 * function pointer taken in func_021578A0.
 */
void func_0215788C(DeliveryBeacon *work)
{
    func_021576C4(work, func_02157870, 0x1DD);
}


int func_021578A0(DeliveryBeacon *work)
{
    if (func_0203CD98() != 0)
        return 0;
    gDeliveryBeaconNetInit.gameKind = work->param.gameKind;
    work->lockedSender = DELIVERY_BEACON_NO_SENDER;
    func_02157700(work);
    func_0203CBAC(&gDeliveryBeaconNetInit, (u32)func_0215788C, (u32)work);
    func_021576C4(work, func_021576CC, 0x1F2);
    return 1;
}


/*
 * Unlabelled leaf, blocker of ov021 func_021D0C58: whether any of 18 slots (stride 100) has its flag byte set.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
int func_021578F0(DeliveryBeacon *work)
{
    int i;

    for (i = 0; i < DELIVERY_BEACON_SLOTS_PER_PAGE; i++) {
        if (work->slots[0][i].pieceCount != 0) {
            return 1;
        }
    }
    return 0;
}


/*
 * extent: 22 bytes of code followed by 2-byte alignment padding.
 */
int func_02157910(DeliveryBeacon *work) { int r; r = func_02157724(work); if (r) func_02157818(work); return r; }


void func_02157928(DeliveryBeacon *work) { work->step(work); }


int func_02157938(DeliveryBeacon *work)
{
    int result;

    func_020307B0(work);
    result = func_0203CEAC(0);
    return result;
}


/* Misplaced: sets a field of the delivery_irc work (see script_work.c, neighbours at 0x676). */
typedef struct DeliveryIrcAckView {
    u8  reserved00[0x670];
    u16 ackFlag;                          /* 670 */
} DeliveryIrcAckView;

void func_02157948(DeliveryIrcAckView *work)
{
    work->ackFlag = 1;
}
