/*
 * function: STRBUF_IsEqual
 * address:  0x0204589C
 * packet:   pkt_0204589C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sStrbufEnd      0x020A7E7C  data
 *
 * Halfword-string equality with the buffer module's terminator stamp: the
 * first element is compared directly, then the loop walks both strings while
 * they agree, succeeding as soon as either side meets the global terminator
 * (0xFFFF) rather than the other buffer.
 *
 * Two shapes are load-bearing:
 *  - `int i = 0;` at its declaration puts the `mov ip, #0` ahead of the
 *    guard's compare; assigning i after the guard lands it after the
 *    terminator pool load instead.
 *  - The guard must NOT be a bare `if (..) return 0;`: mwcc predicates that
 *    into `movne r0, ip; popne {r3, pc}`.  Folding it into one shared exit
 *    (the `if (a->w[0] == b->w[0])` arm holding the loop, a single
 *    `return 0;` after it) makes the guard a real `bne` to that exit, which
 *    is what the image has.  The identical `goto fail` spelling compiles to
 *    the same bytes.
 *
 * The 0x020A7E7C ABS32 sits in this function's own pool (0x020458F4, inside
 * the compared range) and resolves off the `literal` class: the same word is
 * in the pools of the already-matched STRBUF_SetString, STRBUF_SetStringN and
 * STRBUF_SetEosChar.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/STRBUF_IsEqual.c \
 *       --func STRBUF_IsEqual --addr 0x0204589C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Buf {
    u8  pad00[8];
    u16 w[0];
};

extern u16 sStrbufEnd;

int STRBUF_IsEqual(struct Buf *a, struct Buf *b)
{
    int i = 0;

    if (a->w[0] == b->w[0]) {
        do {
            if (a->w[i] == sStrbufEnd) {
                return 1;
            }
            i++;
        } while (a->w[i] == b->w[i]);
    }

    return 0;
}
