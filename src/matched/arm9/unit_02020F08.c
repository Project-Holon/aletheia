/*
 * unit:     yes
 * function: func_02020F08
 * address:  0x02020F08
 * packet:   pkt_02020E60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *
 * Five unlabelled leaf accessors of the item archive block, none of which
 * saves lr and none of which therefore carries a `func_` label in the
 * listing (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md):
 * they print as a `.byte` run between func_02020E60's literal pool and
 * func_02020F34.
 *
 * This unit is the code-side attestation of the item archive's identity.
 * The archive id in this image is the decimal spelling of the a/X/Y/Z
 * path, so:
 *   - func_02020F14 opens archive id 0x18 = 24 = a/0/2/4 as a persistent
 *     0x50-byte handle (func_020490F4 takes the archive id in r0), and
 *     func_02020F20 reads member `item` out of that same handle after
 *     clamping the item id to 626, the last of a/0/2/4's 627 members.
 *   - func_02020F08 answers archive id 0x19 = 25 = a/0/2/5, the item
 *     graphics archive func_02020F34 reads icon members out of.
 *
 * func_02020F0C and func_02020F10 are constant 1 / constant 0 answers in
 * the same block; the value they stand for is not attested here, only the
 * constant.
 *
 * Cut out of the natural 0x02020E60..0x02020F84 unit
 * (src/pending/unit_02020E60.c) on `tu --suggest-split`'s advice: the two
 * functions left out both carry relocations to data symbols with no
 * witness outside that range, while this piece's two relocations are both
 * label-attested from elsewhere in the image.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02020F08.c \
 *       --addr 0x02020F08 --thumb
 */

typedef unsigned int u32;

extern void *func_020490F4(u32 archive_id, u32 heap);
extern u32   func_02049250(void *handle, u32 member, u32 arg);

u32 func_02020F08(void)
{
    return 0x19;
}

u32 func_02020F0C(void)
{
    return 1;
}

u32 func_02020F10(void)
{
    return 0;
}

void *func_02020F14(u32 heap)
{
    return func_020490F4(0x18, heap);
}

u32 func_02020F20(void *handle, u32 item, u32 arg)
{
    if (item > 626) {
        item = 0;
    }

    return func_02049250(handle, item, arg);
}
