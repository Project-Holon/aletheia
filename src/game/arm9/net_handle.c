/*
 * file:     net_handle.c
 * unit:     yes
 * function: func_020395EC, func_02039658, func_0203971C, func_02039764, func_02039834, func_020398B4, func_0203996C, func_020399A8, func_020399B8, func_020399DC, func_020399EC, func_02039A2C, func_02039A5C, func_02039ACC, func_02039B5C, func_02039C2C, func_02039C3C, func_02039C68, func_02039CA0, func_02039CB4, func_02039CD8, func_02039D94, func_0203A020, func_0203A118, func_0203A150, func_0203A27C, func_0203A28C, func_0203A2F0, func_0203A338, func_0203A388, func_0203A424, func_0203A458
 * address:  0x020395EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x020395EC (__FILE__ anchor boundary).
 *
 * symbols:
 *   func_02030734            0x02030734  arm
 *   func_02082BCC            0x02082BCC  arm
 *   func_02039548            0x02039548  arm
 *   func_02034714            0x02034714  arm
 *   MI_CpuCopy8              0x02082D44  arm
 *   func_020307B0            0x020307B0  arm
 *   func_02039338            0x02039338  arm
 *   func_020393A8            0x020393A8  arm
 *   func_020393D0            0x020393D0  arm
 *   func_020399A8            0x020399A8  arm
 *   func_02039594            0x02039594  arm
 *   func_0203996C            0x0203996C  arm
 *   _FileName                0x020A7A68  data
 *   _AssertZero              0x020A7A78  data
 *   _pBaseWork               0x021469D4  data
 *   _AssertNotBaseWork       0x020A7A7C  data
 *   _AssertBaseWork          0x020A7A88  data
 *   OS_GetMacAddress         0x02087C6C  arm
 *   _AssertTimingSend        0x020A7A94  data
 *   func_020395E0            0x020395E0  arm
 *   func_0203EFC8            0x0203EFC8  arm
 *   _AssertNetIDNotServer    0x020A7AB0  data
 *   _AssertNetIDInRange      0x020A7ACC  data
 *   func_02039578            0x02039578  arm
 *   func_02039560            0x02039560  arm
 *   func_0203D378            0x0203D378  arm
 *   func_0203D394            0x0203D394  arm
 *   func_0203D3A8            0x0203D3A8  arm
 *   func_0203D3F8            0x0203D3F8  arm
 *   func_0203D4D0            0x0203D4D0  arm
 *   func_0203D650            0x0203D650  arm
 *   func_0203D788            0x0203D788  arm
 *   func_0203D798            0x0203D798  arm
 *   func_0203DAC4            0x0203DAC4  arm
 */

typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

#include "net_types.h"
typedef signed int     s32;

/* Typed timing-sync state hung off _pBaseWork (0x20 bytes, allocated by func_02039834). */
struct NetBaseWork {
    u16 timingNo[8];         /* timing number each member asked for */
    u8  timingSend[8];       /* mask of members that voted for it */
    u8  timingSendReady[8];  /* 1 once every member voted the same */
};

/* Timing vote message: timing number and the voter's mask (3 bytes). */
struct NetTimingVoteMsg {
    u16 timingNo;
    u8  mask;
};

/* Timing number the sender wants us to remember. */
struct NetTimingNoMsg {
    u16 timingNo;
};

/* Negotiation message: sender MAC, its netID and its game kind / link flags. */
struct NetNegotiationMsg {
    u8 mac[6];
    u8 netID;
    u8 gameKind;
    u8 linkFlags;
    u8 reserved09[3];
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *func_02082BCC(void *dst, int val, u32 size);

extern void func_02039548(void);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u32 func_020307B0(void *p);

extern u16 func_02039338(void);

extern int   func_020393A8(void);

extern int  func_020393D0(void);

extern GFLNetHandle *func_020399A8(void);

extern int    func_02039594(void);

extern GFLNetHandle *func_0203996C(s32 idx);

extern void OS_GetMacAddress(void *p);

extern int func_020395E0(int slot);

extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);

extern void func_0203C00C(void);

extern void func_020394DC(u8 v);

extern void func_02039578(void);

extern void func_02039560(void);

int func_02037288(u32 a0, u32 heap, u32 c);

void func_02037BE8(u32 a);

int func_02039160(u32 mode);

u16 func_02039338(void);

int func_020393A8(void);

int func_020393D0(void);

void func_020394DC(u8 v);

void func_02039548(void);

void func_02039560(void);

void func_02039578(void);

int func_02039594(void);

int func_020395E0(int slot);

int func_020395EC(GFLNetHandle *a);

void func_02039658(GFLNetHandle *e, u32 idx);

void func_0203971C(GFLNetHandle *handle, u32 netID);

GFLNetHandle *func_02039764(u32 idx);

void func_02039834(GFLNetSession *unused);

void func_020398B4(GFLNetSession *unused);

GFLNetHandle *func_0203996C(s32 idx);

GFLNetHandle *func_020399A8(void);

u32 func_020399B8(GFLNetHandle *handle);

int func_020399DC(GFLNetHandle *p);

int func_020399EC(void);

void func_02039A2C(int a);

void func_02039A5C(void);

int func_02039ACC(void);

void func_02039B5C(u32 netID, u32 size, struct NetTimingVoteMsg *msg, u32 work, GFLNetHandle *handle);

void func_02039C2C(u32 netID, u32 size, struct NetTimingNoMsg *msg, u32 work, GFLNetHandle *handle);

void func_02039C3C(GFLNetHandle *p, u16 tag);

void func_02039C68(GFLNetHandle *p, u32 lo, u32 hi);

u32 func_02039CA0(GFLNetHandle *p, u32 key);

u32 func_02039CB4(GFLNetHandle *p, u32 lo, u32 hi);

int func_02039CD8(GFLNetHandle *p);

void func_02039D94(void);

void func_0203A020(u32 netID, u32 size, const struct NetNegotiationMsg *msg, u32 work, GFLNetHandle *handle);

void func_0203A118(GFLNetHandle *handle);

void func_0203A150(int senderID, int size, NetMemberRec *msg, int localNetID, GFLNetHandle *peer);

void func_0203A27C(u32 netID, u32 size, u8 *data, u32 work, u32 handle);

u16 func_0203A28C(u16 bitMask, u32 netID, u32 enable);

u32 func_0203A2F0(u32 bitMask, u32 netID);

void func_0203A338(u32 netID);

void func_0203A388(int netID, u32 size, const void *data, u32 work, GFLNetHandle *handle);

void func_0203A424(GFLNetHandle *handle, int timingLow, int timingHigh, int netID);

void func_0203A458(GFLNetHandle *handle, u32 timing);

void func_0203C00C(void);

u32 func_0203D378(void);

u32 func_0203D394(GFLNetHandle *e);

int func_0203D3A8(GFLNetHandle *a, u32 b, u32 c, const void *d);

u32 func_0203D3F8(void *entry, u32 sendID, u32 c, u32 d, const void *e, u32 f, u32 g, u32 h);

u32 func_0203D4D0(void *entry, u32 mask, u32 c, u32 d, const void *e, u32 f, u32 g, u32 h);

u32 func_0203D650(void);

GFLNetSession *func_0203D788(void);

GFLNetSession *func_0203D798(void);

void func_0203DAC4(const u8 *mac);






extern const char _FileName[];

extern const char _AssertZero[];

extern struct NetBaseWork *_pBaseWork;

extern const char _AssertNotBaseWork[];

extern const char _AssertBaseWork[];

extern const char _AssertTimingSend[];

extern const char _AssertNetIDNotServer[];

extern const char _AssertNetIDInRange[];


/*
 *           0x020A7A68 ends at 0x020A7A75; the 3-byte gap kills the `string`
 *           class, so 0x020A7A78 has no witness outside 020395EC..02039658.
 *           Every concrete byte of the body reproduces.
 */
int func_020395EC(GFLNetHandle *handle)
{
    GFLNetHandle *cur;
    int netID;

    func_0203D788();
    cur = func_0203996C(0xff);
    if (cur == handle) {
        return 0xff;
    }
    for (netID = 0; netID < 9; netID++) {
        cur = func_0203996C(netID);
        if (cur == handle) {
            return netID;
        }
    }
    func_02034714(_FileName, 0x6e, _AssertZero);
    return -1;
}






























/*
 * Reset one slot entry while KEEPING its eight resource pointers.  The eight
 * pointers at +8 are stashed on the stack, each live one's 0x10-byte record
 * is zeroed in place, the entry's own object at +0 is released, the whole
 * 0x50-byte entry is wiped, and the eight pointers are written straight back
 * -- so the resource objects survive the reset and only the entry's state
 * does not.  A real slot index (anything but the 0xFF own-slot spelling)
 * first has its bit cleared out of the +0x40 mask through func_0203A28C and
 * its +0x3E companion zeroed.  func_02039834 and func_020398B4 both drive
 * this in a loop over the nine slots.
 *
 * THE STACK BUFFER HOLDS NINE POINTERS, NOT EIGHT, AND ONLY EIGHT ARE USED.
 * Declared `void *saved[8]` the function is byte-identical but for its frame:
 * `sub sp, sp, #0x20` with r3 in the push, against the image's
 * `sub sp, sp, #0x24` with a seven-register push.  The ninth word is what
 * takes the frame to 0x24 and lets the prologue drop the r3 home slot; the
 * unused slot is not padding the compiler inserted but a declared one.  Nine
 * is also the family's own table size (func_0203996C resolves nine 0x50-byte
 * entries, eight peers plus the own slot), so the buffer was almost
 * certainly spelled with the same manifest constant as the table and the
 * loop simply stops at the eight peers.  tools/permuter.py exhausted hill
 * mode (206 single mutations, none better) on the eight-element version:
 * the array's own size is outside its mutation set.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039658.c \
 *       --func func_02039658 --addr 0x02039658 --cc 1.1p1 --arm
 */
void func_02039658(GFLNetHandle *handle, u32 netID)
{
    void *savedRec[9];
    int i;
    if (netID != 0xff) {
        u16 mask = handle->memberMask;
        handle->notifiedMask = 0;
        handle->memberMask = func_0203A28C(mask, netID, 0);
    }
    for (i = 0; i < 8; i++) {
        if (handle->memberRec[i] != 0)
            func_02082BCC(handle->memberRec[i], 0, 0x10);
        savedRec[i] = handle->memberRec[i];
    }
    if (handle->workBuf != 0) {
        func_020307B0(handle->workBuf);
        handle->workBuf = 0;
    }
    func_02082BCC(handle, 0, 0x50);
    for (i = 0; i < 8; i++)
        handle->memberRec[i] = savedRec[i];
    func_02037BE8(netID);
}






























/*
 * Clears the slot's `0x3e` field, refreshes its `0x40` field from the
 * selector, then clears the 0x10-byte record its indexed pointer names.
 * The early `popeq` is the null test written as an early return.
 */
void func_0203971C(GFLNetHandle *handle, u32 netID)
{
    if (netID != 0xFF) {
        u16 mask = handle->memberMask;
        handle->notifiedMask = 0;
        handle->memberMask = (u16)func_0203A28C(mask, netID, 0);
    }
    {
        NetMemberRec *rec = handle->memberRec[netID];
        if (rec == 0)
            return;
        func_02082BCC(rec, 0, 0x10);
    }
}






























/*
 * (Re)initialise one slot entry and hand it back.  The entry is wiped to
 * 0x50 zero bytes, its packed key at +0x44/+0x46 is set to the 0xFF
 * sentinel and its +0x49/+0x4A state bytes cleared.  Only the OWN slot
 * (index 0xFF) owns the eight 0x10-byte resource records at +8: for it the
 * old eight are released before the wipe and eight fresh ones allocated
 * after it out of the heap named by the record's +0x56 halfword (line 0xC7);
 * a peer slot keeps a null array on both sides of the wipe.
 *
 * This is func_02039834's per-slot worker and the constructive twin of
 * func_02039658 (which keeps the resource pointers rather than
 * reallocating them).
 *
 * TWO LEVERS, and only one of them is an allocation tie.
 *
 * IT RETURNS THE ENTRY.  The image's `mov r0, r8` at +0xBC, between the
 * +0x46 store and the +0x49 store, is the return value: both callers
 * (func_02039834, func_020398B4) discard it, so nothing downstream forces
 * it, but written `void` the function is four bytes short and that `mov` is
 * simply missing.  A dead-looking `mov r0, <callee-saved>` just before the
 * epilogue of a function whose callers ignore the result is the tell.
 *
 * DECLARATION ORDER: `GFLNetHandle *e;` before `u8 *g;`.  The other way
 * round the two swap colours -- the record goes to r8 and the entry to sb,
 * against the image's sb and r8 -- for ten `mov`/`ldr` operands and no size
 * change (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * tools/permuter.py --explain reports this residue as exactly one swapped
 * pair (r8 <-> sb), which is what says to reach for declaration order rather
 * than for the body.
 *
 * The allocation loop's counter is a SECOND variable from the release
 * loop's, zeroed before the wipe call rather than at the loop head: that is
 * the `mov sl, #0` at +0x50 sitting above `bl func_02082BCC`, where reusing
 * `i` would re-zero it after the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039764.c \
 *       --func func_02039764 --addr 0x02039764 --cc 1.1p1 --arm
 */
GFLNetHandle *func_02039764(u32 netID)
{
    GFLNetHandle *handle;
    GFLNetSession *session;
    int i;
    session = func_0203D798();
    func_0203D788();
    handle = (GFLNetHandle *)func_0203996C(netID);
    if (netID == 0xff) {
        for (i = 0; i < 8; i++) {
            if (handle->memberRec[i] != 0)
                func_020307B0(handle->memberRec[i]);
        }
    }
    i = 0;
    func_02082BCC(handle, 0, 0x50);
    if (netID == 0xff) {
        for (; i < 8; i++)
            handle->memberRec[i] = func_02030734(session->init.heapId, 0x10, 1, _FileName, 0xc7);
    }
    handle->state = 0;
    handle->connectFlags = 0xff;
    handle->tag = 0xff;
    handle->isRemote = 0;
    return handle;
}






























/*
 * Module bring-up, the twin of func_020398B4's teardown: reset all eight
 * peer slots through func_02039764, reset the own slot (0xFF) too, assert
 * that the module handle _pBaseWork is NOT already live, then allocate the
 * 0x20-byte handle for it out of the heap named by the record's +0x56
 * halfword (line 0xE5; the assert is line 0xE3).
 *
 * TWO LEVERS, both of which the note in docs/notes/pkt_02039764.c.txt was
 * one step short of.
 *
 * DECLARATION ORDER: `int i;` before `u8 *p;`.  With `p` declared first the
 * allocator colours the object pointer r4 and the reset index r5, which is
 * the swap of the image's r5/r4 the note recorded; swapping the two
 * declarations swaps the colours back
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The note tried this "and it does not move it" only because the remaining
 * residue below masked the result.
 *
 * ASSERT POLARITY: the guard is `_pBaseWork != 0`, not `== 0`.  The image
 * skips the report with `beq`, so the report runs on the NON-null handle:
 * bringing a module up twice is the error, where func_020398B4's matching
 * assert at line 0x100 fires on the null handle because tearing down a dead
 * module is the error there.  Getting it backwards is a one-byte diff
 * (the condition field of a single branch) and nothing else.
 *
 * The note's second finding is now stale: func_02039764's only branch sites
 * image-wide are this function's own two calls, so `label` still refuses it,
 * but `sole-ref/code` carries it (0x02039764 is a traced function start), and
 * _AssertNotBaseWork resolves through `sole-ref` the same way.  This file is EXACT,
 * not the MATCH the note predicted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039834.c \
 *       --func func_02039834 --addr 0x02039834 --cc 1.1p1 --arm
 */
void func_02039834(GFLNetSession *unused)
{
    int i;
    GFLNetSession *session;
    session = func_0203D798();
    for (i = 0; i < 8; i++) {
        func_02039764(i);
    }
    func_02039764(0xff);
    if (_pBaseWork != 0) {
        func_02034714(_FileName, 0xe3, _AssertNotBaseWork);
    }
    _pBaseWork = func_02030734(session->init.heapId, 0x20, 1, _FileName, 0xe5);
}





























/*
 * The teardown twin of func_02039834: clear every one of the eight peer slots
 * (func_02039658 on each slot's entry), release the eight resource handles the
 * own-slot entry parks at +8..+0x24, clear the own slot too, then assert the
 * module handle _pBaseWork is live and free it.
 *
 * The own-slot entry is taken once, before the release loop, and the address
 * of each handle word is recomputed per iteration rather than kept in a
 * cursor: func_020307B0 is an ordinary extern, so the store after it needs a
 * fresh `add r0, r5, r6, lsl #2`
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The two `mov` of the slot key 0xff share one register with the clear loop's
 * counter, which is why the tail spells the key as `mov r4, #0xff`.
 *
 * The __FILE__ argument is "net_handle.c" at 0x020A7A68, line 0x100.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020398B4.c \
 *       --func func_020398B4 --addr 0x020398B4 --cc 1.1p1 --arm
 */
void func_020398B4(GFLNetSession *unused)
{
    GFLNetHandle *ownHandle;
    int i;
    u32 ownID;
    for (i = 0; i < 8; i++) {
        func_02039658((GFLNetHandle *)(func_0203996C(i)), i);
    }
    ownHandle = func_0203996C(0xff);
    for (i = 0; i < 8; i++) {
        if (ownHandle->memberRec[i] != 0) {
            func_020307B0(ownHandle->memberRec[i]);
            ownHandle->memberRec[i] = 0;
        }
    }
    ownID = 0xff;
    func_02039658((GFLNetHandle *)(func_0203996C(ownID)), ownID);
    if (_pBaseWork == 0) {
        func_02034714(_FileName, 0x100, _AssertBaseWork);
    }
    func_020307B0(_pBaseWork);
    _pBaseWork = 0;
}































/*
 * Resolves a slot index to one of the nine 0x50-byte entries at +0x70 of
 * func_0203D788()'s record.  0xff is the "own slot" spelling and names entry
 * 8, which is why it is a separate constant add and not a folded index; every
 * other index is bounds-checked against nine and scaled with an `mla`,
 * 0x50 being too awkward for a shift pair.
 *
 * The record's own +0x340 field (see src/matched/func_02039338.c) is exactly
 * where this table ends: 0x70 + 9 * 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203996C.c \
 *       --func func_0203996C --addr 0x0203996C --cc 1.1p1 --arm
 */
GFLNetHandle *func_0203996C(s32 netID)
{
    GFLNetSession *session = func_0203D788();
    if (session != 0) {
        if (netID == 0xff) {
            return &session->handle[8];
        }
        if (netID < 9) {
            return &session->handle[netID];
        }
    }
    return 0;
}































/*
 * A two-call forwarder: the index func_02039338 returns goes straight to
 * func_0203996C through r0, and that entry is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020399A8.c  *       --func func_020399A8 --addr 0x020399A8 --cc 1.1p1 --arm
 */
GFLNetHandle *func_020399A8(void)
{
    return func_0203996C(func_02039338());
}































/*
 * A null-tolerant predicate on a slot's +0x4A state.  This is the if/else
 * spelling rather than if-return-then-return: the null arm branches to an
 * epilogue of its own at the end, and the tested arm is the fall-through, so
 * the source condition is the `!= 0` one.  The `? ==5 : 0` shape is the
 * `moveq r0, #1` / `movne r0, #0` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020399B8.c \
 *       --func func_020399B8 --addr 0x020399B8 --cc 1.1p1 --arm
 */
u32 func_020399B8(GFLNetHandle *handle)
{
    if (handle != 0)
        return handle->state == 5;
    else
        return 0;
}






























/*
 * Entry accessor: returns byte 0x4A of a 0x50-byte entry, or 8 for null.
 */
int func_020399DC(GFLNetHandle *handle)
{
    if (handle) return handle->state;
    return 8;
}






























/*
 * Count how many of the eight slots answer non-zero to the probe: when
 * func_0203D788() is null the count is zero, otherwise every slot is asked
 * through func_0203996C(i) and func_020399B8(), and each non-zero answer bumps
 * the counter (the `addne r5, r5, #1` after the loop's `add r4, r4, #1`).
 *
 * The counter is left uninitialised at its declaration and assigned `0` in
 * BOTH arms of the guard.  That is what puts `mov r5, #0` between the guard's
 * `cmp` and its `beq`, and what keeps the exit a single shared epilogue
 * instead of the predicated `moveq r0, r5; popeq` pair.  Declaring
 * `int c = 0;` up front instead hoists the zero above the call (4 bytes of
 * different scheduling), and `if (f() == 0) return c;` predicates the whole
 * early exit and grows the body to 68 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020399EC.c \
 *       --func func_020399EC --addr 0x020399EC --cc 1.1p1 --arm
 */
int func_020399EC(void)
{
    int i;
    int count;
    if (func_0203D788() != 0) {
        count = 0;
        for (i = 0; i < 8; i++) {
            if (func_020399B8(func_0203996C(i)) != 0)
                count++;
        }
    } else {
        count = 0;
    }
    return count;
}





























void func_02039A2C(int timingNo)
{
    GFLNetHandle *handle;
    if (func_02039338())
        return;
    handle = func_0203996C(0xff);
    handle->timingReq[timingNo].timingNo = (char)timingNo;
    handle->timingReq[timingNo].armed = 1;
}






























/*
 * Retire every armed two-byte slot of the own-slot entry: early-out when
 * func_02039338() reports busy, otherwise take the 0xFF entry and, for each
 * of the eight slot pairs at +0x2C, clear the +0x2D flag byte once
 * func_0203D3A8(entry, 5, 2, &pair) accepts it.
 *
 * THE LAST STORE'S OFFSET IS A NAMED LOCAL, THE OTHER TWO ARE NOT.  Written
 * with `i * 2` spelled at all three uses, the whole function comes out
 * shifted one register up (r5/r6 for entry/index against the image's r4/r5,
 * with an extra callee-saved in the push) and 4 bytes short.  Binding
 * `off = i * 2` at the top of the loop body and using it ONLY at the final
 * `strb` gives that store its own value number: the predicated arm then has
 * to re-materialise the field address as `addne r0, r4, r5, lsl #1` followed
 * by `strbne r6, [r0, #0x2d]`, which is exactly the image's shape, where a
 * shared offset lets the compiler fold 0x2D into a second base register and
 * index off it.  Substituting `off` at the other two uses as well loses it
 * again, and so does declaring `off` inside the loop body rather than beside
 * `p` and `i` (declaration order is stack and colouring order,
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * Found by tools/permuter.py (mode hill, 148 compiles, mutation
 * `temp(tmp=i * 2)`); the note in docs/notes/pkt_02039A5C.c.txt had ruled out
 * the three hand spellings that keep every offset an expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039A5C.c \
 *       --func func_02039A5C --addr 0x02039A5C --cc 1.1p1 --arm
 */
void func_02039A5C(void)
{
    GFLNetHandle *ownHandle;
    int i;
    int off;
    if (func_02039338() != 0) {
        return;
    }
    ownHandle = func_0203996C(0xff);
    for (i = 0; i < 8; i++) {
        off = i;
        if (ownHandle->timingReq[i].armed != 0) {
            if (func_0203D3A8(ownHandle, 5, 2, &ownHandle->timingReq[i]) != 0) {
                ownHandle->timingReq[off].armed = 0;
            }
        }
    }
}






























/*
 * Seeds the current record's +0x4a state byte: state 2 re-arms the eight-slot
 * table through func_0203D3A8 with a 3-byte payload built in a 12-byte stack
 * buffer, any state below 2 is stepped up by one, anything else is left alone.
 * The early `beq` on func_02039160() is the R4 shared-tail lever: the first
 * exit branches to the function's last `return 0` instead of predicating
 * `moveq r0, #0` / `popeq` (which cost 12 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039ACC.c \
 *       --func func_02039ACC --addr 0x02039ACC --cc 1.1p1 --arm
 */
int func_02039ACC(void)
{
    struct NetNegotiationMsg msg;
    GFLNetHandle *handle;
    u8 selfID;
    GFLNetSession *session;
    u32 state;
    handle = func_020399A8();
    selfID = (u8)func_020395EC(handle);
    func_0203D788();
    session = func_0203D798();
    if (func_02039160(func_02039338()) != 0) {
        state = handle->state;
        if (state == 2) {
            OS_GetMacAddress(&msg);
            msg.netID = selfID;
            msg.gameKind = session->init.gameKind;
            msg.linkFlags = session->init.linkExtraFlags;
            return func_0203D3A8(handle, 3, 9, &msg);
        }
        if (state < 2)
            handle->state = state + 1;
    }
    return 0;
}






























/*
 * Record one peer's vote and raise the "everyone agreed" flag when the last
 * one lands.  The 3-byte message at `msg` is a u16 tag plus a u8 mask; the
 * sender's slot is `slot`, and the vote is only taken when func_020395EC says
 * the link is still the own link (0xff) and the slot is a real one.
 *
 * Both halves of the vote table hang off the one module global _pBaseWork:
 * the u16 tags are the array at +0, the masks the bytes at +0x10 and the
 * ready flags the bytes at +0x18.  The global is re-read after each store and
 * inside the scan because every callee here is an ordinary extern.
 *
 * The scan then walks all eight slots: an ACTIVE slot must have voted the same
 * mask and the same tag, and must NOT carry that slot's own bit in its mask,
 * or the function returns without raising the flag; an INACTIVE slot is only allowed
 * through when func_02039160 says it is not merely late.  `1 << i` is kept
 * live in sb across the whole loop, which is what puts `mov sb, #1` above the
 * loop head rather than a rematerialised constant in the arm
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * EXACT* only: the inferred extent runs 20 bytes long because the unlabelled
 * leaf at 0x02039C2C (`ldrh r1,[r2] / ldr r0,[sp] / strh r1,[r0,#0x44] / bx lr`,
 * 16 bytes, saves no lr so disasm.py never labels it) follows this function's
 * own pool word at 0x02039C28.  Never a byte difference; 0x02039C2C wants
 * seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039B5C.c \
 *       --func func_02039B5C --addr 0x02039B5C --cc 1.1p1 --arm
 */
void func_02039B5C(u32 netID, u32 size, struct NetTimingVoteMsg *msg, u32 work, GFLNetHandle *handle)
{
    u16 timingNo = msg->timingNo;
    u8  mask = msg->mask;
    int i;
    u32 one;
    if (func_020395EC(handle) != 0xff) {
        return;
    }
    if (netID == 0xff) {
        return;
    }
    _pBaseWork->timingNo[netID] = timingNo;
    _pBaseWork->timingSend[netID] = mask;
    i = 0;
    one = 1;
    for (; i < 8; i++) {
        if (func_020399B8(func_0203996C(i)) != 0) {
            if (mask == _pBaseWork->timingSend[i]) {
                if (timingNo != _pBaseWork->timingNo[i]) {
                    return;
                }
            } else if ((mask & (one << i)) != 0) {
                return;
            }
        } else if (func_02039160((u16)i) == 1) {
            return;
        }
    }
    _pBaseWork->timingSendReady[netID] = 1;
}






























/*
 * A message handler from the dispatch table at 0x020A0870, sharing the
 * five-argument shape of its table neighbour func_02039B5C: the first four
 * arguments arrive in r0-r3 and the fifth, the receiver object, on the
 * stack.  This one copies the message's 16-bit tag into the receiver's
 * 0x44 field and ignores everything else.
 */
void func_02039C2C(u32 netID, u32 size, struct NetTimingNoMsg *msg, u32 work, GFLNetHandle *handle)
{
    handle->connectFlags = msg->timingNo;
}






























/*
 * Arm one pending vote on the record at `p`: park the tag at +0x46, mark the
 * slot unresolved with 0xff at +0x48, and record at +0x49 whether the record
 * is NOT the own link -- func_020395EC returning 0xff is the own link, which
 * is the one case that stores zero.
 *
 * The record pointer is copied to r4 before the two stores because the call
 * clobbers r0; the boolean is built with the `moveq`/`movne` pair rather than
 * a branch, which is 1.1p1's normal shape for a comparison stored straight to
 * memory.  The pair's ORDER is the source order of the arms: written as
 * `p->isRemote = (... != 0xff)` or as a ternary, 1.1p1 emits `movne r0,#1`
 * first and is 4 bytes out; the explicit if/else with the `== 0xff` arm first
 * puts `moveq r0,#0` first, as the image has it
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039C3C.c \
 *       --func func_02039C3C --addr 0x02039C3C --cc 1.1p1 --arm
 */
void func_02039C3C(GFLNetHandle *handle, u16 timingNo)
{
    handle->tag = timingNo;
    handle->netID = 0xff;
    if (func_020395EC(handle) == 0xff) {
        handle->isRemote = 0;
    } else {
        handle->isRemote = 1;
    }
}






























/*
 * A whole translation unit, matched as one byte range.
 *
 * The setter and the two matchers for the packed 16-bit key at +0x44/+0x46
 * of the link record: the key is always assembled as `lo + (hi << 8)` from a
 * pair of separate arguments rather than passed whole.
 *
 * func_02039CA0 has no label in the listing: it is a leaf that saves nothing,
 * so disasm.py prints it inside func_02039C68's extent (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  Keeping the
 * three in one unit is what reproduces its bytes at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02039C68.c \
 *       --addr 0x02039C68 --arm
 */
void func_02039C68(GFLNetHandle *handle, u32 timingLow, u32 timingHigh)
{
    if (handle == 0) {
        return;
    }
    handle->tag = timingLow + (timingHigh << 8);
    handle->netID = 0xff;
    if (func_020395EC(handle) == 0xff) {
        handle->isRemote = 0;
    } else {
        handle->isRemote = 1;
    }
}




























u32 func_02039CA0(GFLNetHandle *handle, u32 timingNo)
{
    return handle->connectFlags == timingNo;
}




























u32 func_02039CB4(GFLNetHandle *handle, u32 timingLow, u32 timingHigh)
{
    if (handle == 0) {
        return 1;
    }
    return handle->connectFlags == timingLow + (timingHigh << 8);
}





























/*
 * Sweep the eight slot pointers at +0x8.  A slot that is still marked in use
 * (+0xd non-zero) and whose bit is not set in the key word at +0x3e is torn
 * down through the eight-argument delegate; a delegate failure aborts the
 * whole sweep with 0, otherwise the key's bit is set.  Falling off the end
 * clears the key word and reports success.
 *
 * The eight-argument call's first stack slot is the slot pointer itself and
 * the remaining three are the constants 1, 0, 1 (r5 is the object, 0xff/4/
 * 0x10 are the register arguments).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039CD8.c \
 *       --func func_02039CD8 --addr 0x02039CD8 --cc 1.1p1 --arm
 */
int func_02039CD8(GFLNetHandle *handle)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (handle->memberRec[i]->active == 0)
            continue;
        if (func_0203A2F0(handle->notifiedMask, i) != 0)
            continue;
        if (func_0203D3F8(handle, 0xff, 4, 0x10, handle->memberRec[i], 1, 0, 1) != 0)
            func_0203A28C(handle->notifiedMask, i, 1);
        else
            return 0;
    }
    handle->notifiedMask = 0;
    return 1;
}





























/*
 * The net_handle.c tick (docs/families/net_handle.h).  Closed from the
 * 652-byte / 14-out source of docs/notes/pkt_02039D94.c.txt with two
 * changes:
 *   1. The two owner callbacks at g+0x14 / g+0x10 each TAKE func_0203D650's
 *      result as their argument: `a = g->get_a(func_0203D650())`.  That is
 *      why the image calls through r1 (`ldr r1, [r4, #0x14]; blx r1`):
 *      r0 is holding the argument.  Called with no argument the compile
 *      goes through r0 (4 bytes out).
 *   2. Phases 2 and 4 reuse the entry pointer `e` for the own entry
 *      (func_0203996C(0xff)); there is no separate `own` local.  With a
 *      separate local the own pointer and the loop index swap sb/sl in
 *      phase 2 (or r6/r7 in phase 4).
 */
void func_02039D94(void)
{
    GFLNetHandle *ownHandle;
    GFLNetSession *session;
    int i;
    for (i = 0; i < 8; i++) {
        u32 slot = func_020395E0(i);
        ownHandle = func_0203996C(slot);
        if (func_02039160((u16)slot) == 0)
            func_020399B8(ownHandle);
    }
    func_02039A5C();
    if (func_0203D378() != 0) {
        ownHandle = func_0203996C(0xff);
        for (i = 0; i < 9; i++) {
            if (_pBaseWork->timingSendReady[i] != 1)
                continue;
            if (func_0203D4D0(ownHandle, _pBaseWork->timingSend[i], 8, 2,
                              &_pBaseWork->timingNo[i], 0, 0, 0) == 0)
                continue;
            if (_pBaseWork->timingSend[i] == 0)
                func_02034714(_FileName, 0x29a, _AssertTimingSend);
            _pBaseWork->timingSendReady[i] = 0;
        }
    }
    for (i = 0; i < 9; i++) {
        GFLNetHandle *handle;
        handle = func_0203996C(func_020395E0(i));
        if (func_0203D394(handle) == 0)
            continue;
        if (handle->isRemote == 0)
            continue;
        if (func_020395EC(handle) == 0xff)
            continue;
        if (func_0203D3A8(handle, (u16)7, (u16)4, &handle->tag) != 0)
            handle->isRemote = 0;
    }
    if (func_02039338() == 0) {
        ownHandle = func_0203996C(0xff);
        if (ownHandle != 0) {
            for (i = 0; i < 8; i++) {
                NetMemberRec *rec = ownHandle->memberRec[i];
                if (rec == 0 || rec->active == 0)
                    continue;
                if (func_0203A2F0(ownHandle->memberMask, i) != 0)
                    continue;
                if (func_02039CD8(ownHandle) != 0)
                    ownHandle->memberMask =
                        func_0203A28C(ownHandle->memberMask, i, 1);
            }
        }
    }
    session = func_0203D798();
    if (session->init.bNetType == 4)
        return;
    ownHandle = func_020399A8();
    if (ownHandle->joinPhase != 1)
        return;
    if (session->init.negotiationFunc != 0 && session->init.beaconSizeFunc != 0) {
        u32 negotiationSize;
        u32 negotiationData;
        negotiationSize = (session->init.beaconSizeFunc)(func_0203D650());
        negotiationData = (session->init.negotiationFunc)(func_0203D650());
        if (func_0203D3A8(ownHandle, (u16)0xa, (u16)negotiationSize, ((void *)negotiationData)) != 0)
            ownHandle->joinPhase = 0;
    } else {
        ownHandle->joinPhase = 0;
    }
}




























/*
 * net_handle.c: claim a connection slot for the message a2 (MAC copy,
 * id bytes, OS_GetMacAddress) when this machine owns the table, else mark
 * the table dirty.
 *
 * The 11-byte residue of docs/notes/pkt_02039CD8.c.txt and
 * pkt_02039D94.c.txt (the in-use `strb` scheduled after the MI_CpuCopy8
 * argument setup, the `1` in r3) was the message parameter's pointee
 * qualifier: `const u8 *a2`.  With a2 const-qualified the store to p[0xd]
 * no longer has to be ordered against the reads of a2 that feed the call.
 * A top-level `u8 * const a2` does nothing.  `volatile` on the owner
 * record stays load-bearing (the zero arm's load order).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A020.c  *       --func func_0203A020 --addr 0x0203A020 --arm --cc 1.1p1
 */
void func_0203A020(u32 netID, u32 size, const struct NetNegotiationMsg *msg, u32 work, GFLNetHandle *handle)
{
  GFLNetSession *session = func_0203D798();
  NetMemberRec *rec;
  GFLNetHandle *ownHandle;
  ownHandle = func_0203996C(0xff);
  if (ownHandle != handle)
    goto notOwnHandle;
  rec = handle->memberRec[netID];
  if (rec->active != 0)
    return;
  rec->active = 1;
  MI_CpuCopy8(msg, rec->peerMac, 6);
  rec->netID = msg->netID;
  OS_GetMacAddress(rec);
  if (msg->linkFlags == 0)
    goto linkFlagsZero;
  if ((msg->netID != 0) && (msg->gameKind != *(volatile u8 *)&session->init.gameKind))
  {
    if (session->init.linkExtraFlags == msg->linkFlags)
    {
      rec->ownKey = session->init.linkExtraFlags;
      rec->peerKey = session->init.linkExtraFlags;
      return;
    }
  }
  if (((msg->netID == 0) && (msg->gameKind == *(volatile u8 *)&session->init.gameKind)) && (session->init.linkExtraFlags == msg->linkFlags))
  {
    rec->ownKey = session->init.linkExtraFlags;
    rec->peerKey = session->init.linkExtraFlags;
  }
  else
  {
    rec->ownKey = 0xff;
    rec->peerKey = 0;
  }
  return;
  linkFlagsZero:
  {
    u8 ownGameKind = *(volatile u8 *)&session->init.gameKind;
    u8 peerGameKind = msg->gameKind;
    rec->ownKey = ownGameKind;
    rec->peerKey = peerGameKind;
  }
  return;
  notOwnHandle:
  handle->joinPhase = 1;
}
































/*
 * Conditional state repair: when the context's +0x352 flag is clear the
 * object's +0x4A state is only pushed to 7 if it is not already 5, otherwise
 * 7 is stored unconditionally.  The `!= 0` arm is the branch and the `== 0`
 * arm is the fall-through, so that polarity is the source order; the inner
 * store is the conditional `movne`/`strbne` pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A118.c \
 *       --func func_0203A118 --addr 0x0203A118 --cc 1.1p1 --arm
 */
void func_0203A118(GFLNetHandle *handle)
{
    if (func_0203D788()->errorCheckEnabled == 0) {
        if (handle->state != 5)
            handle->state = 7;
    } else {
        handle->state = 7;
    }
}
































void func_0203A150(int senderID, int size, NetMemberRec *msg, int localNetID, GFLNetHandle *peer)
{
    GFLNetSession *session;
    u8 ownMac[8];
    u32 peerID;
    session = func_0203D798();
    peerID = func_020395EC(peer);
    if (peerID == 0xff)
    {
        peer->state = 5;
        return;
    }
    if (session->init.linkExtraFlags != 0)
    {
        if (session->init.linkExtraFlags != msg->ownKey)
            func_0203A118(peer);
        if (session->init.linkExtraFlags != msg->peerKey)
            func_0203A118(peer);
    }
    else
    {
        if (session->init.gameKind != msg->ownKey)
            func_0203A118(peer);
        if (session->init.gameKind != msg->peerKey)
            func_0203A118(peer);
    }
    OS_GetMacAddress(ownMac);
    if (func_0203EFC8(msg->peerMac, ownMac, 6) == 0)
    {
        if (msg->netID != func_020395EC(peer))
            func_0203A118(peer);
    }
    if (peer->state == 7)
        return;
    func_0203996C(msg->netID)->state = 5;
    if (session->init.disconnectFunc != 0)
        session->init.disconnectFunc(localNetID, msg->netID);
    func_0203DAC4(msg->peerMac);
    func_0203DAC4(msg->ownMac);
}

































/*
 * A message-table handler that forwards to func_0203A338 with the message's
 * first byte as its only argument.  The five-argument table shape puts the
 * message pointer in r2, so the whole body is `ldrb r0,[r2]` followed by the
 * tail call, which one section per function forces to be a pool word and a
 * `bx ip` rather than a displacement branch
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The remaining
 * parameters are leftovers and are not passed
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A27C.c \
 *       --func func_0203A27C --addr 0x0203A27C --cc 1.1p1 --arm
 */
void func_0203A27C(u32 netID, u32 size, u8 *data, u32 work, u32 handle)
{
    func_0203A338(*data);
}

































/*
 * Set or clear one bit of the 16-bit slot mask, reporting at line 0x391 (913)
 * when the bit index is the 0xFF sentinel.  This is the write half of
 * func_0203A2F0's read (line 0x3AB), sharing its file/message pair.
 *
 * The mask is a u16 throughout, which is what the `lsl #0x10` / `lsr #16`
 * pairs around every store of it are: `1 << idx` is built in a word, narrowed
 * to 16 bits for the OR, and the complement for the clear arm is narrowed
 * THREE times: `~` widens back to int, the AND is done in int, and the result
 * is narrowed once more on the way to the variable.  Writing the clear arm as
 * the compound `mask &= (u16)~(u16)(1 << idx)` is 8 bytes short (one
 * `lsl`/`lsr` pair missing); the narrowing has to be spelled on the whole
 * assignment, `mask = (u16)((u16)mask & (u16)~(u16)(1 << idx))`.  The
 * set arm is the `orrne` and the clear arm the `mvneq` chain, so the source
 * polarity is `set != 0` first (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A28C.c \
 *       --func func_0203A28C --addr 0x0203A28C --cc 1.1p1 --arm
 */
u16 func_0203A28C(u16 bitMask, u32 netID, u32 enable)
{
    if (netID == 0xFF)
        func_02034714(_FileName, 0x391, _AssertNetIDNotServer);
    if (enable != 0)
        bitMask |= (u16)(1 << netID);
    else
        bitMask = (u16)((u16)bitMask & (u16)~(u16)(1 << netID));
    return bitMask;
}

































/*
 * Tests one bit of a channel mask, the 0xFF argument being a non-fatal
 * report at line 0x3AB (939).  The mask is truncated to a byte before the
 * `tst`, which is the `(u8)` cast in the shift expression, and the result is
 * materialised as 1/0 in r0 rather than left as the `tst` flags.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A2F0.c \
 *       --func func_0203A2F0 --addr 0x0203A2F0 --cc 1.1p1 --arm
 */
u32 func_0203A2F0(u32 bitMask, u32 netID)
{
    if (netID == 0xFF)
        func_02034714(_FileName, 0x3AB, _AssertNetIDNotServer);
    return (bitMask & (u8)(1 << netID)) != 0;
}

































/*
 * Promoted from src/pending/ on lane 1: every concrete byte is right (80 of
 * 80).  The one open site was the `bl` to 0x0203971C, whose only branch site
 * image-wide is this one, so `label` had no outside witness.  With
 * src/matched/func_0203971C.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Pushes a slot's identity into both halves of the table, reporting at line
 * 0x3BE (958) when the identity is the 0xFF sentinel.  Each half is
 * `record((GFLNetHandle *)func_0203996C(selector), id)` with the selector's result already in
 * r0, so the second call's first argument is the first call's return value
 * and no local is needed to hold it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A338.c \
 *       --func func_0203A338 --addr 0x0203A338 --cc 1.1p1 --arm
 */
void func_0203A338(u32 netID)
{
    if (netID == 0xFF)
        func_02034714(_FileName, 0x3BE, _AssertNetIDNotServer);
    func_02039658((GFLNetHandle *)func_0203996C(netID), netID);
    func_0203971C((GFLNetHandle *)func_0203996C(0xFF), netID);
}

































/*
 * Install a payload into slot `id`: bail out when the receiver is the own
 * link (func_020395EC returning 0xFF), report at line 0x3D1 (977) when the
 * slot index is out of range, free whatever the slot already holds, allocate
 * `len` bytes out of the heap named by the record's +0x56 halfword (line
 * 0x3D8), publish the buffer and its length together, and copy the payload
 * in.
 *
 * THIS FUNCTION TAKES FIVE PARAMETERS, NOT FOUR.  That is the whole of what
 * docs/notes/pkt_0203A388.c.txt diagnosed as a register-colouring residue.
 * The prologue is `push {r3, r4, r5, r6, r7, lr}`, six registers and so 0x18
 * bytes of frame, which makes the `ldr r0, [sp, #0x18]` at +0x18 a read
 * ABOVE the frame -- the caller's fifth argument -- and not the r3 home slot
 * the note read it as.  r3 is a dead fourth argument, the table-handler shape
 * this family uses throughout (func_0203A150, func_02039B5C, func_0203A27C).
 * Written with four parameters the compiler has to keep the receiver in a
 * register across func_0203D798, which costs r8, an extra callee-saved and a
 * spill slot: 172 bytes against 156.  With the fifth parameter the body is
 * size-exact and two bytes out, both of them trivial:
 *
 *   - the slot bound is SIGNED (`int id`, `id >= 9`).  The image's `blt`
 *     becomes `blo` the moment the index is unsigned.
 *   - the allocator's name argument is the file string 0x020A7A68, the same
 *     word the assert's first argument uses, NOT the message 0x020A7ACC.
 *     Both are pool words at nearly the same displacement, so the wrong one
 *     costs exactly one byte of `ldr` offset.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A388.c \
 *       --func func_0203A388 --addr 0x0203A388 --cc 1.1p1 --arm
 */
void func_0203A388(int netID, u32 size, const void *data, u32 work, GFLNetHandle *handle)
{
    GFLNetSession *session;
    GFLNetHandle *target;
    session = func_0203D798();
    if (func_020395EC(handle) == 0xff)
        return;
    if (netID >= 9)
        func_02034714(_FileName, 0x3D1, _AssertNetIDInRange);
    target = func_0203996C(netID);
    if (target->workBuf != 0)
        func_020307B0(target->workBuf);
    target->workBuf = func_02030734(session->init.heapId, size, 1, _FileName, 0x3D8);
    target->workSize = size;
    MI_CpuCopy8(data, target->workBuf, size);
}
































void func_0203A424(GFLNetHandle *handle, int timingLow, int timingHigh, int netID)
{
    if (handle == 0)
        return;
    handle->tag = (unsigned short)(timingLow + (timingHigh << 8));
    handle->netID = (char)netID;
    if (func_020395EC(handle) == 0xff)
        handle->isRemote = 0;
    else
        handle->isRemote = 1;
}

































/*
 * Broadcasts a byte value to the +0xE and +0xF bytes of all nine channel
 * records at ((u32 *)arg0)[i + 2], skipping the ones whose +0xD flag is
 * clear.  The argument truncation is written at both stores and the compiler
 * hoists the single `and r1, r1, #0xff` out of the loop into the argument
 * register itself, after the loop counter has been initialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A458.c \
 *       --func func_0203A458 --addr 0x0203A458 --cc 1.1p1 --arm
 */
void func_0203A458(GFLNetHandle *handle, u32 timing)
{
    int i;
    if (handle == 0)
        return;
    for (i = 0; i < 9; i++) {
        NetMemberRec *rec = handle->memberRec[i];
        if (rec != 0 && rec->active != 0) {
            rec->peerKey = (u8)timing;
            rec->ownKey = (u8)timing;
        }
    }
}
































