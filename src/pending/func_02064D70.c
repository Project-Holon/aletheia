/*
 * function: func_02064D70
 * address:  0x02064D70
 * packet:   pkt_020648E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:  (none: the only branch out is the indirect callback)
 *
 * Calls a user callback once per node of the multi-cell bank, in the same two
 * layouts the other walks use: kind 1 indexes the 0x5C-stride node array by a
 * byte pulled out of the high half of the descriptor's halfword at +6, and
 * anything else passes the pointer stored in the 0x28-stride cell array.
 *
 * The callback is `cb(arg, &hdr->descs[i], node, i)` and returning 0 stops the
 * walk.  The descriptor stride of 8 bytes and the count at header +0 are read
 * the same way in both arms, which is why the count is hoisted into a
 * callee-saved register and never reloaded.
 *
 * Residue, four bytes, one instruction: the pre-loop register split.  The
 * original holds hdr in r8, the count in sb and the counter in r7; this C
 * holds hdr in r6, the count in r8 and the counter in sb.  Six declaration
 * orders were compiled, all 200/204.  Two things recovered on the way and
 * pinned by the comparison: the descriptor's index is an 8-bit bitfield at bit
 * 8 of the halfword at +6 (the original masks with `and #0xff00` before the
 * shift, so a plain `>> 8` on the halfword -- which compiles to `asr` -- is
 * wrong), and the loop counter is a u16, hence the `lsl #16`/`lsr #16` pair
 * per iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02064D70.c \
 *       --func func_02064D70 --addr 0x02064D70 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj02064D70 {
    void *hdr;      /* +0x00 */
    u32   unk_04;
    u32   kind;     /* +0x08 */
    void *base;     /* +0x0C */
};

typedef int (*Cb02064D70)(void *arg, void *desc, void *node, u32 idx);

struct Desc02064D70 {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 lo  : 8;
    u16 idx : 8;
};

void func_02064D70(struct Obj02064D70 *x, Cb02064D70 cb, void *arg)
{
    void *hdr = x->hdr;
    u16 n = *(u16 *)hdr;
    u16 i;

    if (x->kind == 1) {
        u8 *base = x->base;

        for (i = 0; i < n; i++) {
            struct Desc02064D70 *desc = (struct Desc02064D70 *)((u8 *)hdr + 4 + i * 8);
            u32 idx = desc->idx;

            if (cb(arg, desc, base + idx * 0x5c, i) == 0) {
                return;
            }
        }
    } else {
        u8 *base = x->base;

        for (i = 0; i < n; i++) {
            struct Desc02064D70 *desc = (struct Desc02064D70 *)((u8 *)hdr + 4 + i * 8);

            if (cb(arg, desc, *(void **)(base + i * 0x28), i) == 0) {
                return;
            }
        }
    }
}
