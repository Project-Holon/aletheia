/*
 * function: func_02052FC8
 * address:  0x02052FC8
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02053044  0x02053044  arm
 *   func_0205312C  0x0205312C  arm
 *
 * Blocking class: label.  Both callees, 0x02053044 and 0x0205312C, are
 * reached only from the two call sites inside this function, so neither has a
 * witness outside the compared range and all four PC24 fields stay
 * wildcarded (0x02052FC8 is the last function of the packet before them).
 * Every concrete byte matches under the packet's 1.2 pin; both callees are
 * still-open rows of pkt_020526A8, and filing either one EXACT would move
 * this to EXACT through the `matched` class.
 *
 * The two branches are bit 21 and bit 22 of *v, and they must be written as a
 * 21/1/1/9 bitfield struct: the spelled-out `(*v << 10) >> 31` form loads the
 * word into the wrong scratch register (r2 where the image uses r1, and the
 * in-place `lsl r1, r1, #9` of the second test becomes a move), a six-byte
 * residue that the bitfield declaration removes.  See
 * docs/notes/pkt_020526A8.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02052FC8.c \
 *       --func func_02052FC8 --addr 0x02052FC8 --arm --cc ../1.2/sp2
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8  pad0[0x40];
    u32 *f40;
} S02052FC8;

typedef struct {
    unsigned f0   : 21;
    unsigned b21  : 1;
    unsigned b22  : 1;
    unsigned rest : 9;
} B02052FC8;

extern void func_02053044(S02052FC8 *o);
extern void func_0205312C(S02052FC8 *o);

void func_02052FC8(S02052FC8 *o)
{
    B02052FC8 *v = (B02052FC8 *)((u32 **)o->f40[8])[0];

    if (v->b21) {
        func_02053044(o);
        if (v->b22)
            return;
        func_0205312C(o);
        return;
    }
    if (v->b22 == 0)
        func_0205312C(o);
    func_02053044(o);
}
