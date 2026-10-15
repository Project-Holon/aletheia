/*
 * function: NNSi_FndAllocFoundMBlock
 * address:  0x020612C8
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   NNSi_FndAllocBlockFromHeap   0x0206123C  arm
 *
 * The tail `bl NNSi_FndAllocBlockFromHeap` at 0x020612E0 was the file's only MATCH site:
 * 0x0206123C had no `label` witness, because this call is the only branch to
 * it in the image.  Now that src/matched/NNSi_FndAllocBlockFromHeap.c is an EXACT entry,
 * the site resolves as `matched` and the file is EXACT (with a trailing `*`
 * for the unlabelled follower at 0x0206127C).
 *
 * The guard is an unsigned compare (`cmp r1, r2` / `movhi r0, #0` / `pophi`),
 * so the second parameter is `u32`, and the loaded field is passed on as r0:
 * `return NNSi_FndAllocBlockFromHeap(p);` -- the value handed back is the callee's own
 * result, which is why the call is not a tail call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNSi_FndAllocFoundMBlock.c \
 *       --func NNSi_FndAllocFoundMBlock --addr 0x020612C8 --arm --cc 1.1p1
 *   MATCH, 32 bytes, 1 relocation site, 0 resolved.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Inner020612C8 {
    u32 w[10];
    u32 unk28;
};

struct Obj020612C8 {
    u32 unk0;
    struct Inner020612C8 *inner;
};

struct Big0206123C;
extern void *NNSi_FndAllocBlockFromHeap(struct Big0206123C *o);

int NNSi_FndAllocFoundMBlock(struct Obj020612C8 *o, u32 i)
{
    struct Inner020612C8 *p = o->inner;

    if (i > p->unk28) {
        return 0;
    }
    return (int)NNSi_FndAllocBlockFromHeap((struct Big0206123C *)p);
}
