/*
 * function: func_02048258
 * address:  0x02048258
 * packet:   pkt_02047E88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02046E24   0x02046E24  arm
 *
 * Build one row of the array the slot record at `owner + index * 8`
 * describes: the u16 at +0x18 is the element count and the u16 at +0x16 is
 * the row's first index, and each element is the result of func_02046E24
 * on the corresponding 0xc-byte record's +4 halfword, with the caller's
 * fifth argument forwarded as its first.
 *
 * The count is signed in the original (`cmp` plus `pople` for the empty
 * row, `blt` on the back edge), and the destination is written through the
 * owner's own +0 pointer, re-read once per iteration because the callee may
 * store it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048258.c \
 *       --func func_02048258 --addr 0x02048258 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8  pad_00[0x16];
    u16 unk_16;
    u16 unk_18;
};

struct Rec {
    u8  pad_00[4];
    u16 unk_04;
    u8  pad_06[6];
};

struct Owner {
    u32  unk_00;
    u32  unk_04;
};

struct Holder {
    struct Rec *unk_00;
};

extern void *func_02046E24(u32 a0, u32 a1);

void func_02048258(struct Owner *owner, u32 index, struct Holder *p, u32 a4,
                   u32 a5)
{
    struct Slot *slot = (struct Slot *)((u8 *)owner + index * 8);
    u16 count = slot->unk_18;
    u16 base = slot->unk_16;
    int i;

    for (i = 0; i < count; i++) {
        ((u32 *)owner->unk_00)[base + i] =
            (u32)func_02046E24(a5, p->unk_00[i].unk_04);
    }
}
