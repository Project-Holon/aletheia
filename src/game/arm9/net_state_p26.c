/*
 * file:     net_state_p26.c
 * unit:     yes
 * function: func_0203996C, func_020399A8, func_020399B8, func_020399DC, func_020399EC
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
 */
struct Entry_0;
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

extern void *func_0203D788(void);
extern u16 func_02039338(void);
extern struct Entry_0 *func_0203996C(int idx);
struct Entry_0 *sub_0203996C(s32 idx);
struct Entry_0 *sub_020399A8(void);
u32 func_020399B8(u8 *p);
int func_020399DC(struct Entry_1 *p);



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
