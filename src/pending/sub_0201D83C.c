/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_0201D83C
 * address:  0x0201D83C
 * packet:   pkt_0201D7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0201DADC  0x0201DADC  thumb
 *   func_0201D9C8  0x0201D9C8  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * gf_font.c's destructor: tear the format down, release the three buffers the
 * constructor hung off the object, then free the object itself.  Twenty-four
 * bytes, three calls, nothing else.
 *
 * Every concrete byte is reproduced.  func_0201D9C8 resolves on the `matched`
 * class from src/matched/unit_0201D9C8.c; func_0201DADC does not, and cannot.
 * This is its only call site in the image, so the `label` class has no witness
 * outside the compared range, and the `matched` class needs func_0201DADC to
 * be EXACT, which it is not and will not be while its dispatch table has no
 * second reference (src/pending/sub_0201DADC.c).  Folding the two into one
 * unit is not possible either, the functions are not contiguous:
 * func_0201D854 and func_0201DA00/func_0201DA24 sit between them.
 *
 * MATCH*, not MATCH: the compiled body is 22 bytes and the inferred extent is
 * 24, the difference being the alignment padding in front of func_0201D854.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0201D83C.c \
 *       --func func_0201D83C --addr 0x0201D83C --cc 1.1p1 --thumb
 */

struct Font;

extern void func_0201DADC(struct Font *f);
extern void func_0201D9C8(struct Font *f);
extern void func_020307B0(void *p);

void func_0201D83C(struct Font *f)
{
    func_0201DADC(f);
    func_0201D9C8(f);
    func_020307B0(f);
}
