/*
 * function: sub_0201C724
 * address:  0x0201C724
 * packet:   pkt_0201C6FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0214655C     0x0214655C  data
 *   sub_0201C808   0x0201C808  thumb
 *   sub_0201C8A4   0x0201C8A4  thumb
 *   sub_0201C758   0x0201C758  thumb
 *
 * Seven-argument front door of the move-data layer (worklist guesses
 * waza_tool.c for this packet): fill the shared scratch object at
 * 0x0214655C from the caller's four middle arguments, stamp the u16 from
 * the last argument on it, then hand it plus the owner to sub_0201C758.
 *
 * 0x0214655C is passed by address, not dereferenced, so it is the object
 * itself and not a pointer to one.  It is live across all three calls,
 * which is what buys it r7.
 *
 * The last argument is read as `add r1, sp, #0x18` then `ldrh r1, [r1, #8]`
 * rather than a single sp-relative load: Thumb `ldrh` cannot use sp as a
 * base at all, so reaching an incoming halfword argument always costs the
 * extra `add` (docs/idioms/thumb-immediate-reach-costs-an-adds.md).  The
 * `push {r3, ...}` reserves the one outgoing stack word that sub_0201C808's
 * fifth argument needs; the `str r3, [sp]` that fills it is the original r3
 * being forwarded, not a spill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201C724.c \
 *       --func sub_0201C724 --addr 0x0201C724 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Scratch {
    u8 unk_00[1];
};

extern struct Scratch g_0214655C;

extern void sub_0201C808(struct Scratch *s, u32 e, u32 a, u32 b, u32 c);
struct Rec2;
extern void sub_0201C8A4(struct Rec2 *p, u16 v);
struct PrintCtx;
struct PrintSys;
extern void sub_0201C758(struct PrintSys *p, struct PrintCtx *c, void *s);

void sub_0201C724(void *owner, u32 a, short b, u32 c, u32 d, u32 e, u16 f)
{
    sub_0201C808(&g_0214655C, e, a, b, c);
    sub_0201C8A4((struct Rec2 *)(&g_0214655C), f);
    sub_0201C758(owner, (struct PrintCtx *)(&g_0214655C), (void *)d);
}
