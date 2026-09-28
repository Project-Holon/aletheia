/*
 * unit:     no
 * function: sub_020461B8
 * address:  0x020461B8
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020461E4  0x020461E4  arm
 *
 * Clamp sub_020461E4's answer to the count the header keeps at +0: past the
 * end wraps back to entry zero.  The comparison is signed (`movge`), so the
 * count is read as a halfword but compared as an int.
 *
 * The verdict is EXACT*, not EXACT: the next function, the one-byte global
 * setter at 0x020461D4, saves nothing, so disasm.py folds it into this
 * function's extent and the inferred range runs sixteen bytes long.  It is
 * decompiled separately in src/matched/sub_020461D4.c and wants seeding
 * into layout/function_starts.txt, which is the integrator's file.
 *
 * `movge r0, #0` in place of a branch is the whole `if` body: one
 * conditional instruction, no shared exit block to reason about, because
 * both arms fall into the same `pop`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020461B8.c \
 *       --func sub_020461B8 --addr 0x020461B8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef signed int     s32;

struct Header {
    u16 count;
};

extern s32 sub_020461E4(struct Header *h);

s32 sub_020461B8(struct Header *h)
{
    s32 index = sub_020461E4(h);

    if (index >= h->count) {
        index = 0;
    }
    return index;
}
