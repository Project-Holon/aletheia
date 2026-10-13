/*
 * function: NNS_G3dTexLoad
 * address:  0x0206A00C
 * packet:   pkt_02069FF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_BeginLoadTex  0x0207F7A0  arm
 *   GX_LoadTex       0x0207F7FC  arm
 *   GX_EndLoadTex    0x0207F9B4  arm
 *
 * The ATTACH half of the upload descriptor whose DETACH half is
 * src/matched/NNS_G3dTexReleaseTexKey.c: push this descriptor's texture slot and its
 * palette slot into texture VRAM and mark each uploaded.  `wrap` asks for the
 * GX_BeginLoadTex / GX_EndLoadTex bracket to be opened and closed here; a
 * caller uploading several descriptors in a row passes 0 and brackets the run
 * itself.  The SDK names are the ones docs/families/cluster_020637F4.h already
 * fixed for 0x0207F7A0 / 0x0207F7FC / 0x0207F9B4.
 *
 * THE PALETTE SLOT IS UPLOADED TWICE, and that is not a transcription error:
 * 0x0206A07C and 0x0206A0A0 are two GX_LoadTex calls from two different source
 * pointers (+0x24 and +0x28) to two different VRAM offsets, the second being
 * the first remapped into the second palette bank at half the size.  The
 * remap, read off 0x0206A080..0x0206A098 with the pool word 0x0001FFFF at
 * 0x0206A0C0, is
 *
 *     ((off & 0x1FFFF) >> 1) + 0x20000 + ((off & 0x40000) >> 2)
 *
 * with the length halved: the low 17 bits of the offset are scaled to 4-bit
 * palettes, bit 18 (the bank select) is moved down two places, and 0x20000 is
 * the second bank's base.
 *
 * FOUR THINGS THE BYTES FORCED, in the order they cost time:
 *
 *   1. +0x08 AND +0x18 ARE `u32` FIELDS, NOT `u16`.  The image loads each with
 *      a full-word `ldr` and then narrows with the UNEQUAL shift pair
 *      `lsl #0x10` / `lsr #0xd`, which is
 *      docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md:
 *      a 16-bit truncation folded with the `<< 3` that scales it.  Declaring
 *      them `u16` gives `ldrh` and a separate `lsl #3` and is 125 concrete
 *      bytes out; the cast `(u32)(u16)f << 3` on a u32 field does not fold
 *      either and comes out 4 bytes long.  Only the shift pair written out as
 *      `(u->f08 << 16) >> 13` reproduces the image.
 *
 *   2. `hi` (the `<< 16` result) MUST SURVIVE as its own value.  The image
 *      keeps it in r4 across both calls and re-derives the remap's operand
 *      from it with `and r0, r0, r4, lsr #13` rather than from the already
 *      computed offset.  Writing the remap in terms of `off` instead of
 *      `hi >> 13` is 8 bytes out even with everything else right.
 *
 *   3. +0x28 IS READ INTO A NAMED LOCAL BEFORE THE FIRST CALL.  The image has
 *      `ldr r5, [sb, #0x28]` at 0x0206A078, one instruction ahead of the first
 *      GX_LoadTex, because the value has to be live across it; reading
 *      `u->f28` at the second call site instead leaves the function one
 *      callee-saved register short, so it pushes six registers where the image
 *      pushes eight and 51 concrete bytes differ.  This is
 *      docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md
 *      read in the other direction: here the extra register is what the image
 *      spends, so the local is required rather than forbidden.
 *
 *   4. THE TWO BLOCKS DO NOT SHARE A SIZE LOCAL.  `m` (the texture length) and
 *      `n` (the palette length) are separate locals even though the second
 *      assignment would kill the first; reusing one costs a register colour
 *      and is 6 bytes out.
 *
 * CLOSED BY THE PERMUTER, and worth recording as a clean case of it.  With all
 * four of the above right the residue was 5 concrete bytes and purely a
 * colouring tie -- `--explain` printed a three-way rotation (r6->r7, r7->r5,
 * r5->r6) with every instruction and relocation already correct.  Hand
 * respelling could not move it: five permutations of the declaration list all
 * gave the same 5 bytes, because these locals are coloured in first-definition
 * order rather than declaration order.  `--mode hill --budget 800 --jobs 8
 * --types` exhausted 253 singles at the same point; `--mode anneal --budget
 * 2000 --jobs 8 --types` reached EXACT and named its mutations as
 * `decl-order(d2<->n) ; block(if1,2) ; selfassign(n)`.  Only the FIRST of the
 * three is real: applied on its own to the readable source -- declaring `d2`
 * before `n` so `d2` takes r5 and `n` takes r6 -- it is byte-exact, and the
 * permuter's `if (1) { }` wrapper and its `n = n;` dead self-assignment are
 * search artefacts that this file does not carry.  Re-verified with match.py
 * one after the transfer.
 *
 * Both callers agree with the two-argument signature (0x02047080 and
 * 0x02047238, via src/matched/G3D_SYSTEM_TransVramTexture.c), and the sibling's callers
 * agree with the three-argument one (src/matched/G3D_SYSTEM_FreeVramTexture.c calls
 * NNS_G3dTexReleaseTexKey(r, &x, &y)).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dTexLoad.c \
 *       --func NNS_G3dTexLoad --addr 0x0206A00C --arm --cc 1.1p1
 *   -> EXACT, compiled 184 = original 184, 4 of 4 sites resolved
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Up {
    u32 pad00[2];
    u32 f08;
    u16 f0c;
    u16 pad0e;
    u16 f10;
    u16 pad12;
    u32 f14;
    u32 f18;
    u16 f1c;
    u16 pad1e;
    u16 f20;
    u16 pad22;
    u32 f24;
    u32 f28;
};

extern void GX_BeginLoadTex(void);
extern void GX_LoadTex(void *src, u32 off, u32 n);
extern void GX_EndLoadTex(void);

void NNS_G3dTexLoad(struct Up *u, u32 wrap)
{
    u32 m;
    u32 d2;
    u32 hi;
    u32 off;
    u32 n;

    if (wrap != 0) {
        GX_BeginLoadTex();
    }
    m = u->f0c << 3;
    if (m != 0) {
        GX_LoadTex((u8 *)u + u->f14, (u->f08 << 16) >> 13, m);
        u->f10 = (u16)(u->f10 | 1);
    }
    n = u->f1c << 3;
    if (n != 0) {
        hi = u->f18 << 16;
        off = hi >> 13;
        d2 = u->f28;
        GX_LoadTex((u8 *)u + u->f24, off, n);
        GX_LoadTex((u8 *)u + d2,
                   (((hi >> 13) & 0x1FFFF) >> 1) + 0x20000
                       + ((off & 0x40000) >> 2),
                   n >> 1);
        u->f20 = (u16)(u->f20 | 1);
    }
    if (wrap != 0) {
        GX_EndLoadTex();
    }
}
