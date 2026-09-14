/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202EA20
 * packet:   pkt_0202E770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202EA20
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * A four-call destructor: three owned pointers and then the object
 * itself, freed in the order unk04, unk00, unk08, self. The order is the
 * source's, because this compiler does not reorder calls, so the object's
 * second field is whatever the constructor allocated first.
 *
 * Matched as a one-function unit because the two bytes of `00 00` after
 * its last instruction are the linker's inter-section fill, so `one`
 * reports EXACT* for a padding gap rather than for an unlabelled
 * follower; `tu` compares the section as laid out.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202EA20.c 
 *       --addr 0x0202EA20 --thumb
 */

struct Obj0202EA20 {
    void *unk00;
    void *unk04;
    void *unk08;
};

extern void func_020307B0(void *p);

void sub_0202EA20(struct Obj0202EA20 *p)
{
    func_020307B0(p->unk04);
    func_020307B0(p->unk00);
    func_020307B0(p->unk08);
    func_020307B0(p);
}
