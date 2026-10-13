/*
 * function: ISS_3DS_SYS_ResetSources
 * address:  0x0202BA24
 * packet:   pkt_0202BA24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * iss_3ds_sys.c: resets the 0x10 entries (record +0x24 stride 0x1c) and the
 * two parallel word arrays at +0x1e4 and +0x224.  EXACT* (the listing extent
 * runs on into the unlabelled 28-byte follower at 0x0202BA60).
 *
 * Two facts closed it after thirteen loop spellings had failed
 * (docs/notes/pkt_0202B9F0.c.txt): the counter is an enum, which keeps the
 * unfolded `cmp r4, #0x10; bge` entry guard with a plain increment
 * (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md), and the
 * three word stores write 0, not i: r3 is a copy of the counter taken once in
 * the preheader, when both are zero, and never incremented.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_ResetSources.c \
 *       --func ISS_3DS_SYS_ResetSources --addr 0x0202BA24 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef enum { SLOT_0, SLOT_MAX = 16 } Slot;

void ISS_3DS_SYS_ResetSources(u8 *p)
{
    Slot i;
    for (i = 0; i < 0x10; i++) {
        *(u32 *)(p + i * 0x1c + 0x24) = 0;
        *(u32 *)(p + i * 0x1c + 0x38) = 0x7f;
        *(u16 *)(p + i * 0x1c + 0x3c) = 1 << i;
        *(u32 *)(p + i * 4 + 0x1e4) = 0;
        *(u32 *)(p + i * 4 + 0x224) = 0;
    }
}
