/*
 * function: func_020680DC
 * address:  0x020680DC
 * packet:   pkt_02067FE4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * The text renderer's string measurer, and the callee whose two call sites
 * cap src/pending/func_02069818.c at MATCH.
 *
 * It builds a 12-byte cursor record on the stack: the two-word iterator
 * state zeroed at [sp]/[sp+4] and the caller's string handle at [sp+8],
 * and hands the ADDRESS of the handle word (`add r0, sp, #8`) to the
 * decoder function pointer it reads out of the object's +4 slot. The
 * decoder is called through `blx r7` (an interworking indirect call), so
 * the pointer is kept live in a callee-saved register across the whole
 * loop rather than reloaded per iteration.
 *
 * The count starts at 1, not 0: the `mov r6, #1` at 0x02068108 is hoisted
 * above the first call, and the loop only ever adds for a character equal
 * to 0xa, the line break, via `addeq r6, r6, #1`. So `n` is the LINE
 * count, and the return is `n * (pitch + hdr->f01) - pitch`, the total
 * extent of n lines separated by n-1 gaps: the trailing `sub r0, r0, r4`
 * at 0x02068144 is that off-by-one gap, not part of the product.
 *
 * `hdr->f01` is read with `ldrsb` (0x02068138), the signedness tell of
 * docs/idioms/ldrsh-register-offset-is-signedness.md applied to a byte:
 * the leading is a SIGNED char, so a negative value tightens the lines.
 *
 * The decoder is called once before the loop and once at the bottom of it
 * with the `cmp r0, #0xa` test scheduled between the two, which is the
 * do-while shape written out with a leading call, not a `while` head.
 *
 * VERDICT: DIFF 5, at the right 116 bytes and with no relocation sites at
 * all. The whole body matches except one callee-saved PAIR SWAP: the image
 * holds the decoder in r7 and the loop cursor in r5, this compile the other
 * way round (+0020, +0030, +003C, +0044, +004C). Down from the
 * prologue-wide miss the previous lane recorded. The three levers that got
 * it here (zero the record through a cast pointer, a guarded do-while with
 * the cursor in its own local, and the `q, decode, ch, n, cur` declaration
 * order) and the full list of what does NOT move the swap are in
 * docs/notes/func_020680DC.c.txt.
 *
 * The `compiler:` line is NOT a pin row in docs/FRONTEND-PINS.md: that rule
 * wants a compile that reaches EXACT and this is five bytes short. It is
 * recorded here because it is load-bearing for the SIZE. Under dsi/1.1p1
 * -O4,p the two `add rN, sp, #8` materialisations CSE into one hoisted
 * `add r6, sp, #8` and the function comes out 112 bytes; every spelling
 * tried keeps the merge. Under ../2.0/sp2 both are rematerialised, which is
 * the "kept constants" tell.
 */
typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;
typedef int           s32;

struct HDR {
    s8 f00;
    s8 f01;
};

struct OBJ {
    struct HDR *hdr;
    s32 (*decode)(void *cursor);
};

struct CURSOR {
    u32 st0;
    u32 st1;
    u32 handle;
};

s32 func_020680DC(struct OBJ *obj, s32 pitch, u32 handle)
{
    struct CURSOR c;
    u32 *q;
    s32 (*decode)(void *cursor);
    s32 ch;
    s32 n;
    u32 *cur;

    q = (u32 *)&c;
    c.handle = handle;
    q[0] = 0;
    q[1] = 0;

    decode = obj->decode;
    n = 1;

    ch = decode(&c.handle);
    if (ch != 0) {
        cur = &c.handle;
        do {
            if (ch == 0xa)
                n++;
            ch = decode(cur);
        } while (ch != 0);
    }

    return n * (pitch + obj->hdr->f01) - pitch;
}
