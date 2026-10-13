/*
 * function: BILLBOARD_ReleaseImageVramIfUsed
 * address:  0x0204F1A0
 * packet:   pkt_0204F1A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8144  0x020A8144  data
 *   g_020A814C  0x020A814C  data
 *
 * Release one record of the 0x28-byte array hanging off the object's +0x04
 * field: when the record's first word is set, hand its +0x20 and +0x24
 * pointers to the two callbacks installed in 0x020A8144 / 0x020A814C, then
 * clear the first word.  The record's state word at +0x14 is stamped 5
 * whether or not the release ran.
 *
 * The record size is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces a multiply whose constant is a power of two.
 * The object field is re-read for every statement after the first, because
 * the two indirect calls may write it, so the tail reloads +0x04 instead of
 * reusing the pointer computed for the guard.
 *
 * Address arithmetic: every access spells the base as `(char *)a0->f04`.
 * The cast is load-bearing - with the field left as `u8 *` the front end
 * schedules `base + off` for the first call argument ABOVE the guard branch
 * (a different 7-instruction block, 18 bytes of DIFF); spelled through a
 * `char *` the sum stays inside the guarded block.  See
 * docs/idioms/a-char-cast-on-the-base-pins-the-base-plus-index-sum.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ReleaseImageVramIfUsed.c \
 *       --func BILLBOARD_ReleaseImageVramIfUsed --addr 0x0204F1A0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef void (*Fn0204F1A0)(u32);

typedef struct Obj0204F1A0 {
    u8  pad00[4];
    u8 *f04;
} Obj0204F1A0;

extern Fn0204F1A0 g_020A8144;
extern Fn0204F1A0 g_020A814C;

void BILLBOARD_ReleaseImageVramIfUsed(Obj0204F1A0 *a0, u32 a1)
{
    u32 off = a1 * 0x28;

    if (*(u32 *)(a0->f04 + off) != 0) {
        g_020A8144(*(u32 *)((char *)a0->f04 + off + 0x20));
        g_020A814C(*(u32 *)((char *)a0->f04 + off + 0x24));
        *(u32 *)((char *)a0->f04 + off) = 0;
    }
    *(u32 *)((char *)a0->f04 + off + 0x14) = 5;
}
