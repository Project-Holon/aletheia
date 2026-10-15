/*
 * function: NNS_FndCreateFrmHeap
 * address:  0x020610E0
 * packet:   pkt_020610E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   NNSi_FndInitFrmHeap  0x02060FA4  arm
 *
 * Frame-heap create guard (twin of 0x02060C5C): word-align both ends of the
 * block, refuse anything under 0x30 bytes, else hand (start, end, opt) to
 * NNSi_FndInitFrmHeap.  Two levers closed the old 2-register residue of
 * docs/notes/pkt_020610E0.c.txt: the third parameter is passed straight
 * through in r2 (which is why `end - start` lands in r3), and the end sum is
 * spelled size + mem (`add r1, r1, r0`).
 */

typedef unsigned int u32;
struct Obj;
extern struct Obj *NNSi_FndInitFrmHeap(struct Obj *o, u32 a1, u32 a2);

void *NNS_FndCreateFrmHeap(void *mem, u32 size, u32 opt)
{
    u32 end = (size + (u32)mem) & ~3u;
    u32 start = ((u32)mem + 3) & ~3u;
    if (start > end || end - start < 0x30)
        return 0;
    return NNSi_FndInitFrmHeap((void *)start, end, opt);
}
