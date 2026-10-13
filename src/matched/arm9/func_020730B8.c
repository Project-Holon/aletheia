/*
 * function: func_020730B8
 * address:  0x020730B8
 * packet:   pkt_02073098
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Guarded two-store setter through a handle whose one field is re-read at
 * every use (the `volatile` pointer of docs/families/cluster_02073098.h
 * section 2, the same struct the EXACT sibling NNS_SndHandleSetSweep uses).
 *
 * The wall recorded in docs/notes/pkt_02072F5C.func_020730B8.c.txt was the
 * if-conversion of an early return: `if (o->p == 0) return;` followed by two
 * stores predicates under every front end.  Written as a WRAPPING if around
 * the two stores and compiled with ../2.0/sp2, the image's `bxeq lr` early
 * exit and the three separate loads come out exactly.  (1.1p1 on the same
 * source: 32 bytes, predicated.)
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020730B8.c \
 *       --func func_020730B8 --addr 0x020730B8 --arm --cc ../2.0/sp2
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Sub {
    u8  pad00[0x34];
    u16 h34;
    u16 h36;
    u16 h38;
    u16 h3a;
};
struct Obj { struct Sub * volatile p; };

void func_020730B8(struct Obj *o, u16 v)
{
    if (o->p != 0) {
        o->p->h34 = 1;
        o->p->h38 = v;
    }
}
