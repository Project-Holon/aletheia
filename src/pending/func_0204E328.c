/*
 * function: func_0204E328
 * address:  0x0204E328
 * packet:   pkt_0204E130
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   s_textprint_c   0x020A7F80  data
 *   func_0204E180   0x0204E180  arm
 *   func_0204E388   0x0204E388  arm
 *
 * textprint.c's one-shot formatter: carve a 0x200-byte scratch buffer with
 * the three-argument allocator (heap id 0), format into its first 0x100
 * bytes, run the second pass over the caller's argument, then release the
 * buffer.  Argument order at the allocator is (heap, size, align), and the
 * stacked fifth argument is __LINE__ = 0xae.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * 96 of 96 bytes and 3 of 5 relocations resolve; the two sites that stay
 * wildcarded are the calls to 0x0204E180 and 0x0204E388, which are the two
 * OPEN rows of this same packet (pkt_0204E130) and have no branch witness
 * outside this range.  Blocking evidence class: label/matched, no outside
 * witness.  Filing either callee as an EXACT manifest entry promotes this file
 * with no change to the C (it is a `chain` row for exactly those two
 * addresses).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204E328.c \
 *       --func func_0204E328 --addr 0x0204E328 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const char s_textprint_c[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);
extern void  func_0204E180(void *buf, u32 a1);
extern void  func_0204E388(u32 a0, void *buf, u32 a2);
extern void  func_020307B0(void *p);

void func_0204E328(u32 a0, u32 a1)
{
    void *buf = func_02030734(0, 0x200, 0, s_textprint_c, 0xae);

    func_0204E388(a0, buf, 0x100);
    func_0204E180(buf, a1);
    func_020307B0(buf);
}
