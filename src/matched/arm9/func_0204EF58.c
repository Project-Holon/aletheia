/*
 * function: func_0204EF58
 * address:  0x0204EF58
 * packet:   pkt_0204EE0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204EE0C   0x0204EE0C  arm
 *   func_0204EE64   0x0204EE64  arm
 *   func_0204EEC8   0x0204EEC8  arm
 *
 * The first of the two "insert and publish" wrappers over the 0x28-byte slot
 * table: scan for a free slot with func_0204EE0C, seat it with func_0204EE64
 * and hand it to func_0204EEC8.
 *
 * The scan index is an out-parameter on the caller's own frame (`add r1,
 * sp, #4`), which is where the 8-byte frame comes from, and the same word is
 * the return value whether or not the scan succeeded, so the local is
 * deliberately left uninitialised: func_0204EE0C writes it on both paths.
 *
 * The two trailing parameters are `u8`: a byte-typed parameter that arrives on
 * the stack is read with `ldrb` where a 32-bit one would be `ldr`, and that is
 * the only thing that distinguishes this prototype from func_0204EFC8's
 * (a word, a byte, a byte).
 *
 * `&desc->slots[idx]` is spelled as an index, not as byte arithmetic: the
 * element stride has to be a declared sizeof, because that is what emits the
 * `mov r6, #0x28` / `mla` pair the image has (an `idx * 0x28` on a byte
 * pointer comes out as `mul` plus `add`).
 *
 * The slot base is re-read for the second call, because the first one may
 * have changed it.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8  pad_00[4];
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8  pad_18[8];
    u32 unk_20;
    u32 unk_24;
};

struct Desc {
    u8           pad_00[4];
    struct Slot *slots;
    u32          unk_08;
    int          count;
};

extern int  func_0204EE0C(struct Desc *desc, u32 *out);
extern void func_0204EE64(struct Slot *slot, u32 handle);
extern void func_0204EEC8(struct Slot *slot, u32 a1, u32 a2, u32 a3, u32 a4);

u32 func_0204EF58(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    u32 idx;

    if (func_0204EE0C(desc, &idx) == 1) {
        func_0204EE64(&desc->slots[idx], a1);
        func_0204EEC8(&desc->slots[idx], a2, a3, a4, a5);
    }
    return idx;
}
