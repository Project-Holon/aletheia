/*
 * file:     net_state_p21.c
 * unit:     yes
 * function: sub_02039594, func_020395E0, func_020395EC, func_02039658, func_0203971C, func_02039764, func_02039834, func_020398B4
 * address:  0x02039594
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   unk_021469D0   0x021469D0  data
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   func_02034714  0x02034714  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203A28C  0x0203A28C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02037BE8  0x02037BE8  arm
 *   func_02030734  0x02030734  arm
 *   file_020A7A68  0x020A7A68  data
 *   g_021469D4     0x021469D4  data
 *   msg_020A7A7C   0x020A7A7C  data
 *   msg_020A7A88   0x020A7A88  data
 *   sub_0203996C   0x0203996C  arm
 */
#include "../../matched/include/Obj08833.h"
#include "../../matched/include/Obj15944.h"
#include "../../matched/include/Obj15945.h"

struct Entry;
typedef unsigned char u8;

struct LinkState {
    u8 pad000[0x1eb];
    u8 unk_1eb;
};

struct Session {
    u8 pad00[0x64];
    u8 unk_64;
    u8 state;
};

typedef unsigned int  u32;

typedef signed int     s32;

typedef unsigned short u16;

struct Entry_02039658 {
    void *obj;
    u8    pad_04[4];
    void *slot[8];
    u8    pad_28[0x16];
    u16   key3e;
    u16   key40;
};

struct Entry_02039764 {
    u8    pad_00[8];
    void *slot[8];
    u8    pad_28[0x1c];
    u16   key44;
    u16   key46;
    u8    pad_48;
    u8    f49;
    u8    f4a;
};

struct Entry {
    u8   pad_00[8];
    void *handle[8];
};

extern void *func_0203D798(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_0203D788(void);
extern struct Entry *func_0203996C(s32 idx);
extern u16 func_0203A28C(u16 mask, u32 idx, u32 set);
extern u32 func_020307B0(void *p);
extern void *func_02082BCC(void *dst, int val, u32 size);
extern void func_02037BE8(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Entry *sub_0203996C(s32 idx);
int sub_02039594(void);
int sub_020395E0(int slot);
int func_020395EC(struct Entry *a);
void func_02039658(struct Entry_02039658 *e, u32 idx);
void func_0203971C(unsigned char *a, u32 b);
struct Entry_02039764 *func_02039764(u32 idx);
void func_02039834(void);
void func_020398B4(void);
extern struct LinkState *unk_021469D0;
extern const u8 str_020A7A68[];
extern const u8 str_020A7A78[];
extern const char file_020A7A68[];
extern void *g_021469D4;
extern const char msg_020A7A7C[];
extern const char msg_020A7A88[];



/*
 * May the caller proceed?  With no link state, or with the +0x64 byte of the
 * session record set, the answer is an unconditional yes; in the two session
 * states 0 and 5 it is whatever the +0x1eb byte of the link state says; any
 * other state is a yes.
 *
 * The `state == 0 || state == 5` pair is one `cmp` / `cmpne` chain feeding a
 * single `eq` block, so it has to be written as one disjunction: as two
 * `if`s the shared block is duplicated.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039594.c \n *       --func sub_02039594 --addr 0x02039594 --cc 1.1p1 --arm
 */
int sub_02039594(void)
{
    struct Session *s;

    if (unk_021469D0 == 0) {
        goto yes;
    }

    s = func_0203D798();
    if (s->unk_64 != 0) {
        goto yes;
    }
    if (s->state == 0 || s->state == 5) {
        return unk_021469D0->unk_1eb;
    }
yes:
    return 1;
}



/*
 * Clamp a slot index to the sentinel: anything from 8 up becomes 0xff, and
 * everything below passes through untouched.  Twelve bytes, no prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020395E0.c \n *       --func sub_020395E0 --addr 0x020395E0 --cc 1.1p1 --arm
 */
int sub_020395E0(int slot)
{
    if (slot >= 8) {
        slot = 0xFF;
    }
    return slot;
}




/*
 *           0x020A7A68 ends at 0x020A7A75; the 3-byte gap kills the `string`
 *           class, so 0x020A7A78 has no witness outside 020395EC..02039658.
 *           Every concrete byte of the body reproduces.
 */
int func_020395EC(struct Entry *a)
{
    struct Entry *v;
    int i;

    func_0203D788();
    v = func_0203996C(0xff);
    if (v == a) {
        return 0xff;
    }
    for (i = 0; i < 9; i++) {
        v = func_0203996C(i);
        if (v == a) {
            return i;
        }
    }
    func_02034714((const char *)str_020A7A68, 0x6e, (const char *)str_020A7A78);
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
 * is also the family's own table size (sub_0203996C resolves nine 0x50-byte
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
void func_02039658(struct Entry_02039658 *e, u32 idx)
{
    void *saved[9];
    int i;

    if (idx != 0xff) {
        u16 h = e->key40;
        e->key3e = 0;
        e->key40 = func_0203A28C(h, idx, 0);
    }

    for (i = 0; i < 8; i++) {
        if (e->slot[i] != 0)
            func_02082BCC(e->slot[i], 0, 0x10);
        saved[i] = e->slot[i];
    }

    if (e->obj != 0) {
        func_020307B0(e->obj);
        e->obj = 0;
    }

    func_02082BCC(e, 0, 0x50);

    for (i = 0; i < 8; i++)
        e->slot[i] = saved[i];

    func_02037BE8(idx);
}



/*
 * Clears the slot's `0x3e` field, refreshes its `0x40` field from the
 * selector, then clears the 0x10-byte record its indexed pointer names.
 * The early `popeq` is the null test written as an early return.
 */
void func_0203971C(unsigned char *a, u32 b)
{
    if (b != 0xFF) {
        u16 h = ((struct Obj08833 *)a)->f40;
        ((struct Obj08833 *)a)->f3E = 0;
        ((struct Obj08833 *)a)->f40 = (u16)func_0203A28C(h, b, 0);
    }
    {
        void *p = *(void **)(a + b * 4 + 8);
        if (p == 0)
            return;
        func_02082BCC(p, 0, 0x10);
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
 * DECLARATION ORDER: `struct Entry *e;` before `u8 *g;`.  The other way
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
struct Entry_02039764 *func_02039764(u32 idx)
{
    struct Entry_02039764 *e;
    u8 *g;
    int i;

    g = func_0203D798();
    func_0203D788();
    e = (struct Entry_02039764 *)func_0203996C(idx);

    if (idx == 0xff) {
        for (i = 0; i < 8; i++) {
            if (e->slot[i] != 0)
                func_020307B0(e->slot[i]);
        }
    }

    i = 0;
    func_02082BCC(e, 0, 0x50);

    if (idx == 0xff) {
        for (; i < 8; i++)
            e->slot[i] = func_02030734(((struct Obj15944 *)g)->f56, 0x10, 1, file_020A7A68, 0xc7);
    }

    e->f4a = 0;
    e->key44 = 0xff;
    e->key46 = 0xff;
    e->f49 = 0;
    return e;
}



/*
 * Module bring-up, the twin of func_020398B4's teardown: reset all eight
 * peer slots through func_02039764, reset the own slot (0xFF) too, assert
 * that the module handle g_021469D4 is NOT already live, then allocate the
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
 * ASSERT POLARITY: the guard is `g_021469D4 != 0`, not `== 0`.  The image
 * skips the report with `beq`, so the report runs on the NON-null handle:
 * bringing a module up twice is the error, where func_020398B4's matching
 * assert at line 0x100 fires on the null handle because tearing down a dead
 * module is the error there.  Getting it backwards is a one-byte diff
 * (the condition field of a single branch) and nothing else.
 *
 * The note's second finding is now stale: func_02039764's only branch sites
 * image-wide are this function's own two calls, so `label` still refuses it,
 * but `sole-ref/code` carries it (0x02039764 is a traced function start), and
 * msg_020A7A7C resolves through `sole-ref` the same way.  This file is EXACT,
 * not the MATCH the note predicted.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039834.c \
 *       --func func_02039834 --addr 0x02039834 --cc 1.1p1 --arm
 */
void func_02039834(void)
{
    int i;
    u8 *p;

    p = func_0203D798();
    for (i = 0; i < 8; i++) {
        func_02039764(i);
    }
    func_02039764(0xff);

    if (g_021469D4 != 0) {
        func_02034714(file_020A7A68, 0xe3, msg_020A7A7C);
    }
    g_021469D4 = func_02030734(((struct Obj15945 *)p)->f56, 0x20, 1, file_020A7A68, 0xe5);
}


/*
 * The teardown twin of func_02039834: clear every one of the eight peer slots
 * (func_02039658 on each slot's entry), release the eight resource handles the
 * own-slot entry parks at +8..+0x24, clear the own slot too, then assert the
 * module handle g_021469D4 is live and free it.
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
void func_020398B4(void)
{
    struct Entry *own;
    int i;
    u32 key;

    for (i = 0; i < 8; i++) {
        func_02039658((struct Entry_02039658 *)(sub_0203996C(i)), i);
    }

    own = sub_0203996C(0xff);

    for (i = 0; i < 8; i++) {
        if (own->handle[i] != 0) {
            func_020307B0(own->handle[i]);
            own->handle[i] = 0;
        }
    }

    key = 0xff;
    func_02039658((struct Entry_02039658 *)(sub_0203996C(key)), key);

    if (g_021469D4 == 0) {
        func_02034714(file_020A7A68, 0x100, msg_020A7A88);
    }
    func_020307B0(g_021469D4);
    g_021469D4 = 0;
}
