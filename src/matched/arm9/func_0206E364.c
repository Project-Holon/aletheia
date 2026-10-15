/*
 * function: NNS_G3dAllocAnmObj
 * address:  0x0206E364
 * packet:   pkt_0206E364
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0010 PC24 GetTaggedPayloadSize           -> unresolved: 02069C14 (arm, from header) has no witness outside 0206E364..0206E388
 *
 * symbols:
 *   GetTaggedPayloadSize    0x02069C14  arm
 *   NNS_G2dCallVtableSlot0    0x02061330  arm
 *
 * Forwards the two tail arguments through GetTaggedPayloadSize and hands the result,
 * with the first argument, to NNS_G2dCallVtableSlot0 -- the argument shuffle is why the
 * first parameter moves into r4 before either call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dAllocAnmObj.c \
 *       --func NNS_G3dAllocAnmObj --addr 0x0206E364 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef unsigned char  u8;
struct Node;
struct Obj02061330;
extern u32 GetTaggedPayloadSize(const u8 *tag, const struct Node *n);
extern void NNS_G2dCallVtableSlot0(struct Obj02061330 *o, u32 x);

void NNS_G3dAllocAnmObj(u32 a, u32 b, u32 c)
{
    NNS_G2dCallVtableSlot0((struct Obj02061330 *)a, GetTaggedPayloadSize((const u8 *)b, (const struct Node *)c));
}
