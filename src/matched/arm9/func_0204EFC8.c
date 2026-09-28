/*
 * function: func_0204EFC8
 * address:  0x0204EFC8
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
 *   func_02046DB8   0x02046DB8  arm
 *
 * The second wrapper, one call longer than func_0204EF58: the handle it seats
 * the slot with is func_02046DB8(a1, a2) rather than a1 directly, and the
 * trailing parameters are one word and two bytes rather than two bytes
 * (`ldr` at sp+0x20, `ldrb` at sp+0x24 and sp+0x28).
 *
 * The frame and the scan out-parameter are the same as func_0204EF58's, and
 * the slot base is again re-read for each call.
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
extern u32  func_02046DB8(u32 a, u32 b);

u32 func_0204EFC8(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6)
{
    u32 idx;

    if (func_0204EE0C(desc, &idx) == 1) {
        func_0204EE64(&desc->slots[idx], func_02046DB8(a1, a2));
        func_0204EEC8(&desc->slots[idx], a3, a4, a5, a6);
    }
    return idx;
}
