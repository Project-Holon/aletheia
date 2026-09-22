/*
 * function: func_02075404
 * address:  0x02075404
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0208A46C  0x0208A46C  arm
 *   func_0208A48C  0x0208A48C  arm
 *   func_0207533C  0x0207533C  arm
 *
 * "Load every bank this sequence needs for one group": open an iterator over
 * the sequence (func_0208A46C), copy it to a working cursor, then step it
 * (func_0208A48C) and, for every record of kind 1 whose group id matches the
 * caller's, pull the bank in with func_0207533C.  Any failed load answers 0;
 * a run to exhaustion answers 1.  The null-sequence guard answers 0 and is
 * emitted AFTER the iterator open, which is why it shares the mid-function
 * epilogue rather than the entry.
 *
 * THE FRAME IS THE EVIDENCE FOR BOTH STRUCT SIZES, and it took two levers:
 *
 *  - DECLARATION ORDER IS STACK ORDER, reversed
 *    (docs/idioms/local-declaration-order-is-stack-order.md).  The image puts
 *    the freshly-opened iterator at sp+0, the working cursor at sp+8 and the
 *    record at sp+0x10; declaring them in that order lays them out backwards
 *    (record at sp+0) and costs 17 bytes.  Declared `Rec r; Iter it; Iter it0;`
 *    the offsets line up.
 *
 *  - THE RECORD IS 12 BYTES, NOT 8.  With an 8-byte Rec every offset is right
 *    but the frame is `push {r4..sl, lr}` / `sub sp, #0x18`; the image is
 *    `push {r3, r4..sl, lr}` / `sub sp, #0x1c`, i.e. eight bytes more of
 *    locals.  Only the first four bytes of the tail are ever read
 *    (`ldrb [sp,#0x10]`, `ldrh [sp,#0x12]`, `ldrheq [sp,#0x14]`), so the
 *    +6..+11 members are sized by the frame alone and their split is not
 *    constrained: `u16 h6; u32 w8;`, `u16 h6; u16 h8;` and a bare `u32 w8;`
 *    all give the same 192 bytes, 0 mismatches.  Recorded as the three-member
 *    form; a later caller of func_0208A48C can settle the split.
 *
 * PIN ../2.0/sp2, the cluster pin.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075404.c \
 *       --func func_02075404 --addr 0x02075404 --arm --cc ../2.0/sp2
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct { u32 a; u32 b; } Iter;
typedef struct { u8 kind; u8 p1; u16 h2; u16 h4; u16 h6; u32 w8; } Rec;

extern void func_0208A46C(Iter *it, u32 a, u32 b, u32 c);
extern u32  func_0208A48C(u32 seq, Rec *r, Iter *it);
extern u32  func_0207533C(u32 o, u32 i, u32 h, u32 *heap);

u32 func_02075404(u32 o, u32 seq, u32 want, u32 h, u32 *heap)
{
    Rec r;
    Iter it;
    Iter it0;

    func_0208A46C(&it0, seq, want, h);
    it = it0;
    if (seq == 0) return 0;
    if (func_0208A48C(seq, &r, &it) != 0) {
        do {
            if (r.kind == 1 && want == r.h4) {
                if (func_0207533C(o, r.h2, h, heap) == 0) return 0;
            }
        } while (func_0208A48C(seq, &r, &it) != 0);
    }
    return 1;
}
