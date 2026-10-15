/*
 * unit:     no
 * function: ARC_UTIL_RegisterObjChar
 * address:  0x0204979C
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   BG_SYS_CreateTileRun  0x02040B58  arm
 *
 * Registers a loaded graphics buffer and answers a packed handle: the slot
 * index in the low halfword and the size the caller asked for (or the
 * object's own size at +0x10, when the caller passed zero) in the high one.
 * A failed lookup and a -1 from the allocator both return a plain 0.
 *
 * The two failure paths share one `mov r0, #0` / `pop` block at 0x020497F8.
 * Statements sit between the two guards, so only an explicit `goto` to a
 * trailing `return 0` reproduces that; written as two plain `return 0`
 * statements mwcc predicates both epilogues instead and 53 of 100 bytes move
 * (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *
 * The packed result is written `((u16)a2 << 16) | (u16)slot`, not the other
 * way round: the accumulator of a commutative chain is its second operand
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md),
 * and only this order leaves the low half in r0 and folds the high half in as
 * `orr r0, r0, r1, lsl #16`.
 *
 * NNS_G2dGetUnpackedCharacterDataEx fills a caller-owned pointer through its second argument, so
 * the local is read back twice, once inside the `a2 == 0` arm and once for
 * the unconditional `+0x14` field. That is why the pair of `ldr` from `[sp]`
 * straddles the predicated `ldreq`: the conditional read cannot be shared
 * with the unconditional one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_RegisterObjChar.c \
 *       --func ARC_UTIL_RegisterObjChar --addr 0x0204979C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Res {
    u8 pad_00[0x10];
    u32 unk_10;
    u32 unk_14;
};

struct NitroFileHeader;
extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
extern u32 BG_SYS_CreateTileRun(u32 index, const void *src, u32 size);

u32 ARC_UTIL_RegisterObjChar(void *buf, u32 a1, u32 a2)
{
    struct Res *res;
    s32 slot;

    if (NNS_G2dGetUnpackedCharacterDataEx(buf, (void **)(&res)) == 0) {
        goto fail;
    }

    if (a2 == 0) {
        a2 = res->unk_10;
    }

    slot = BG_SYS_CreateTileRun(a1, (const void *)res->unk_14, a2);
    if (slot == -1) {
        goto fail;
    }

    return ((u16)a2 << 16) | (u16)slot;

fail:
    return 0;
}
