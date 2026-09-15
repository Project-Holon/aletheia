/*
 * function: sub_0204AC18
 * address:  0x0204AC18
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * PARKED AT MATCH.  Every concrete byte is right, all 212 of them.  One of
 * the four relocation sites has no witness: 0x0204DD08, whose only `bl`
 * anywhere in the image is the one at +0xB8 in this function, so `label`
 * has nothing outside the compared range to offer.  A split cannot create
 * one either, since the single call site is inside the only function that
 * needs it, so `--suggest-split` has no cut to propose on a one-function
 * file.  It unsticks the moment 0x0204DD08 itself becomes an EXACT
 * manifest entry, which is the neighbouring display-object lane's ground,
 * not this packet's.  The short-form wrapper that reaches this function,
 * src/matched/sub_0204ABF0.c, is EXACT and does not help: it calls this
 * function, not 0x0204DD08.
 *
 * symbols:
 *   func_02049250  0x02049250  arm
 *   func_0204DD08  0x0204DD08  arm
 *   func_020307B0  0x020307B0  arm
 *   unk_02146A74   0x02146A74  data
 *
 * The second-table twin of sub_0204A6C8: claim the first entry of the
 * 0x18-byte table marked pending (top bit of +0x14), build the object for
 * it, publish it through func_0204DD08, and return the index.  -1 means
 * nothing was waiting.
 *
 * The owner block at +0x104 carries both tables side by side, the 0x40-byte
 * one at +0x08 with its count at +0x14 and this 0x18-byte one at +0x0C with
 * its count at +0x16, which is why the two functions read almost the same
 * addresses with different offsets.
 *
 * Both counts are `volatile`.  That is not decoration: the loop re-reads the
 * count from memory on every iteration (`ldrh r3, [ip, #0x16]` inside the
 * loop body, after the entry test already read it) while the table pointer
 * beside it is hoisted once.  Without `volatile` the compiler hoists the
 * count too and the loop is four bytes short.  Some other agent on the same
 * object writes these counts, so the reload is real.
 *
 * The `i = -1` on the not-found path is reached by falling out of the loop,
 * not by a second comparison, so the exit from the loop body is a `goto`
 * past that assignment rather than a `break`.  Writing it as
 * `break` plus `if (i >= count) i = -1;` costs an extra count read here,
 * exactly the read `volatile` now refuses to fold away.
 *
 * 0x7FFF is rematerialised as `add r2, r2, #0x8000` off the -1 the
 * not-found comparison left behind, since it is not an ARM rotated
 * immediate.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204AC18.c \
 *       --func sub_0204AC18 --addr 0x0204AC18 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Slot {
    u8  pad_00[0x24];
    u32 unk_24;
    u8  pad_28[0x14];
    u32 unk_3c;
};

struct Slot2 {
    u8  pad_00[0x14];
    u32 unk_14;
};

struct Owner {
    u8            pad_00[8];
    struct Slot  *slots;
    struct Slot2 *slots2;
    u8            pad_10[4];
    volatile u16  count;
    volatile u16  count2;
};

struct Sys {
    u8           pad_00[0x104];
    struct Owner owner;
};

extern struct Sys *unk_02146A74;

extern u32  func_02049250(u32 a, u32 b, u16 flags);
extern void func_0204DD08(struct Owner *owner, u32 idx, u32 handle, u32 c,
                          u32 d, u16 e, u16 f);
extern void func_020307B0(u32 handle);

s32 sub_0204AC18(u32 a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g)
{
    struct Owner *owner;
    u32 i;
    u32 handle;

    owner = &unk_02146A74->owner;

    for (i = 0; i < owner->count2; i++) {
        if ((owner->slots2[i].unk_14 >> 31) != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i == (u32)-1) {
        return i;
    }

    handle = func_02049250(a, b, (u16)((g & 0x7fff) | 0x8000));

    func_0204DD08(&unk_02146A74->owner, i, handle, c, d, e, f);
    func_020307B0(handle);

    return i;
}

