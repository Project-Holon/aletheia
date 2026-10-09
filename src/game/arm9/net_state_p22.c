/*
 * file:     net_state_p22.c
 * unit:     yes
 * function: func_0203996C, func_020399A8, func_020399B8, func_020399DC, func_020399EC, func_02039A2C, func_02039A5C, func_02039ACC, func_02039B5C, func_02039C2C, func_02039C3C
 * address:  0x0203996C
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
 *   func_0203D788  0x0203D788  arm
 *   func_02039338  0x02039338  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039160  0x02039160  arm
 *   func_020395EC  0x020395EC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02087C6C  0x02087C6C  arm
 *   g_021469D4     0x021469D4  data
 */
#include "../../matched/include/Obj11357.h"
#include "../../matched/include/Obj11358.h"

struct Entry_0;
struct Entry;
typedef unsigned char u8;

typedef signed int    s32;

struct Entry_0 {
    u8 pad_00[0x50];
};

struct Owner {
    u8 pad_00[0x70];
    struct Entry_0 table[9];
};

typedef unsigned short u16;

typedef unsigned int  u32;

struct Entry_1 { u8 bytes[0x50]; };

struct Msg_02039B5C {
    u16 tag;
    u8  mask;
};

struct Votes {
    u16 tag[8];
    u8  mask[8];
    u8  ready[8];
};

struct Msg_02039C2C {
    u16 tag;
};

struct Obj {
    u16 pad[0x44 / 2];
    u16 tag;
};

struct Rec {
    u8  pad_00[0x46];
    u16 tag;
    u8  slot;
    u8  remote;
};

extern void *func_0203D788(void);
extern u16 func_02039338(void);
extern struct Entry_0 *func_0203996C(int idx);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_02039160(u32 mode);
extern int func_020395EC(struct Entry *a);
extern struct Entry *func_020399A8(void);
extern void *func_0203D798(void);
extern void func_02087C6C(void *p);
struct Entry_0 *sub_0203996C(s32 idx);
struct Entry_0 *sub_020399A8(void);
u32 func_020399B8(u8 *p);
int func_020399DC(struct Entry_1 *p);
int func_020399EC(void);
void func_02039A2C(int a);
void func_02039A5C(void);
int func_02039ACC(void);
void func_02039B5C(u32 slot, u32 a1, struct Msg_02039B5C *msg, u32 a3, u32 link);
void func_02039C2C(u32 a0, u32 a1, struct Msg_02039C2C *msg, u32 a3, struct Obj *obj);
void func_02039C3C(struct Rec *p, u16 tag);
extern struct Votes *g_021469D4;




/*
 * Resolves a slot index to one of the nine 0x50-byte entries at +0x70 of
 * func_0203D788()'s record.  0xff is the "own slot" spelling and names entry
 * 8, which is why it is a separate constant add and not a folded index; every
 * other index is bounds-checked against nine and scaled with an `mla`,
 * 0x50 being too awkward for a shift pair.
 *
 * The record's own +0x340 field (see src/matched/sub_02039338.c) is exactly
 * where this table ends: 0x70 + 9 * 0x50.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203996C.c \
 *       --func sub_0203996C --addr 0x0203996C --cc 1.1p1 --arm
 */
struct Entry_0 *sub_0203996C(s32 idx)
{
    struct Owner *owner = func_0203D788();

    if (owner != 0) {
        if (idx == 0xff) {
            return &owner->table[8];
        }
        if (idx < 9) {
            return &owner->table[idx];
        }
    }
    return 0;
}




/*
 * A two-call forwarder: the index func_02039338 returns goes straight to
 * func_0203996C through r0, and that entry is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020399A8.c  *       --func sub_020399A8 --addr 0x020399A8 --cc 1.1p1 --arm
 */
struct Entry_0 *sub_020399A8(void)
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
u32 func_020399B8(u8 *p)
{
    if (p != 0)
        return p[0x4A] == 5;
    else
        return 0;
}



/*
 * Entry accessor: returns byte 0x4A of a 0x50-byte entry, or 8 for null.
 */
int func_020399DC(struct Entry_1 *p)
{
    if (p) return p->bytes[0x4a];
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
    int c;

    if (func_0203D788() != 0) {
        c = 0;
        for (i = 0; i < 8; i++) {
            if (func_020399B8((u8 *)func_0203996C(i)) != 0)
                c++;
        }
    } else {
        c = 0;
    }
    return c;
}


void func_02039A2C(int a)
{
    char *q;
    if (func_02039338())
        return;
    q = (char *)func_0203996C(0xff) + a * 2;
    q[0x2c] = (char)a;
    q[0x2d] = 1;
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
    u8 *p;
    int i;
    int off;

    if (func_02039338() != 0) {
        return;
    }
    p = (u8 *)func_0203996C(0xff);
    for (i = 0; i < 8; i++) {
        off = i * 2;
        if (*(u8 *)(p + 0x2d + i * 2) != 0) {
            if (func_0203D3A8((struct Entry *)p, 5, 2, (u32)(p + 0x2c + i * 2)) != 0) {
                *(u8 *)(p + 0x2d + off) = 0;
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
    u8 buf[12];
    u8 *p;
    u8 v;
    u8 *q;
    u32 f;

    p = (u8 *)func_020399A8();
    v = (u8)func_020395EC((struct Entry *)p);
    func_0203D788();
    q = func_0203D798();
    if (func_02039160(func_02039338()) != 0) {
        f = ((struct Obj11357 *)p)->f4A;
        if (f == 2) {
            func_02087C6C(buf);
            buf[6] = v;
            buf[7] = ((struct Obj11358 *)q)->f67;
            buf[8] = ((struct Obj11358 *)q)->f6E;
            return func_0203D3A8((struct Entry *)p, 3, 9, (u32)buf);
        }
        if (f < 2)
            ((struct Obj11357 *)p)->f4A = f + 1;
    }
    return 0;
}



/*
 * Record one peer's vote and raise the "everyone agreed" flag when the last
 * one lands.  The 3-byte message at `msg` is a u16 tag plus a u8 mask; the
 * sender's slot is `slot`, and the vote is only taken when func_020395EC says
 * the link is still the own link (0xff) and the slot is a real one.
 *
 * Both halves of the vote table hang off the one module global g_021469D4:
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
void func_02039B5C(u32 slot, u32 a1, struct Msg_02039B5C *msg, u32 a3, u32 link)
{
    u16 tag = msg->tag;
    u8  mask = msg->mask;
    int i;
    u32 one;

    if (func_020395EC((void *)link) != 0xff) {
        return;
    }
    if (slot == 0xff) {
        return;
    }

    g_021469D4->tag[slot] = tag;
    g_021469D4->mask[slot] = mask;

    i = 0;
    one = 1;

    for (; i < 8; i++) {
        if (func_020399B8((u8 *)sub_0203996C(i)) != 0) {
            if (mask == g_021469D4->mask[i]) {
                if (tag != g_021469D4->tag[i]) {
                    return;
                }
            } else if ((mask & (one << i)) != 0) {
                return;
            }
        } else if (func_02039160((u16)i) == 1) {
            return;
        }
    }

    g_021469D4->ready[slot] = 1;
}



/*
 * A message handler from the dispatch table at 0x020A0870, sharing the
 * five-argument shape of its table neighbour func_02039B5C: the first four
 * arguments arrive in r0-r3 and the fifth, the receiver object, on the
 * stack.  This one copies the message's 16-bit tag into the receiver's
 * 0x44 field and ignores everything else.
 */
void func_02039C2C(u32 a0, u32 a1, struct Msg_02039C2C *msg, u32 a3, struct Obj *obj)
{
    obj->tag = msg->tag;
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
 * `p->remote = (... != 0xff)` or as a ternary, 1.1p1 emits `movne r0,#1`
 * first and is 4 bytes out; the explicit if/else with the `== 0xff` arm first
 * puts `moveq r0,#0` first, as the image has it
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039C3C.c \
 *       --func func_02039C3C --addr 0x02039C3C --cc 1.1p1 --arm
 */
void func_02039C3C(struct Rec *p, u16 tag)
{
    p->tag = tag;
    p->slot = 0xff;
    if (func_020395EC((struct Entry *)p) == 0xff) {
        p->remote = 0;
    } else {
        p->remote = 1;
    }
}
