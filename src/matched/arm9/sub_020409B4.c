/*
 * function: sub_020409B4
 * address:  0x020409B4
 * packet:   pkt_0203FC6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_02146A44  0x02146A44  data
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *
 * Indexes the 0x2c-byte entry array reached through the pointer at
 * 0x02146A44 and tail-calls the worker at 0x020409E0 with three fields of
 * that entry plus the index itself.  The tail call is the usual pool word
 * and `bx ip`; ip rather than r3 is used so all four argument registers
 * survive.
 */

typedef unsigned int u8_unused;
typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry02146A44 {
    u8   pad_00[8];
    u32  unk_08;
    u32  unk_0c;
    u32  unk_10;
    u8   pad_14[0x18];
};

extern struct Entry02146A44 *gUnk_02146A44;
extern void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);

void sub_020409B4(u32 index)
{
    struct Entry02146A44 *e = &gUnk_02146A44[index];

    BG_SYS_PushTileSource(index, (const void *)e->unk_08, e->unk_0c, e->unk_10);
}
