/*
 * function: func_02012088
 * address:  0x02012088
 * packet:   pkt_02012088
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203133C  0x0203133C  arm
 *   func_02011F90  0x02011F90  thumb
 *   python tools/match.py one --src src/matched/func_02012088.c \
 *   --func func_02012088 --addr 0x02012088 --cc 1.1p1 --thumb
 *
 * The tail of the packet's small table walkers: two loads off the
 * g_02146228 pair and one store, 18 bytes, every relocation a label outside
 * the range.  It re-verified EXACT after func_02010F50 and func_02010EEC were
 * filed in pkt_02010EEC (the same two tables), so the entry is a chain payoff.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012088.c \
 *       --func func_02012088 --addr 0x02012088 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f08;            /* +0x08 */
};

struct S020314B8;
extern void func_0203133C(struct S020314B8 *p);
extern void func_02011F90(u32 *p);

void func_02012088(struct IcaAnime *p)
{
    func_0203133C((struct S020314B8 *)p->f08);
    func_02011F90((u32 *)p);
}
