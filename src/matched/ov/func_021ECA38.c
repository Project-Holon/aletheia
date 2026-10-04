/*
 * function: func_021ECA38
 * address:  0x021ECA38
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * func_0204B5AC.c, shard pkt_0204B5AC), so the call at +0022 attests as
 * `matched`.  Every concrete byte matches; the extent ran long because the
 * follower has no func_ label.
 */

typedef unsigned int   u32;
struct Actor;
struct Pt;
extern void func_0204B588(struct Actor *actor, const struct Pt *src);
extern void func_0204B5AC(int, int *);
extern void func_0204B570(struct Actor *actor, u32 value);
void func_021ECA38(int *p)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    func_0204B588((struct Actor *)(*p), (const struct Pt *)s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    func_0204B5AC(*p, s.b);
    func_0204B570((struct Actor *)(*p), 0);
}
