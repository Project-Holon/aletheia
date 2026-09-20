/*
 * function: sub_0204AC18
 * address:  0x0204AC18
 * packet:   pkt_0204AC18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_02049250  0x02049250  arm
 *   func_0204DD08  0x0204DD08  arm
 *   func_020307B0  0x020307B0  arm
 *   unk_02146A74   0x02146A74  data
  *
 * blocker:  label - 0x0204DD08 has exactly one branch in the image and it is
 *           the call inside this function, so `label` has no outside witness
 *           and no manifest entry covers it yet.  File 0x0204DD08 first and
 *           this graduates with no change to its C.
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
extern void func_0204DD08(struct Owner *owner, u32 idx, u32 handle, u32 c, u32 d, u16 e, u16 f);
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
