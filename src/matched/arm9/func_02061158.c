/*
 * unit:     no
 * function: NNS_FndFreeToFrmHeap
 * address:  0x02061158
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndResetFrmHeapHead  0x020610A0  arm
 *   NNSi_FndResetFrmHeapState  0x020610B4  arm
 */

extern void NNSi_FndResetFrmHeapHead(void *p);
extern void NNSi_FndResetFrmHeapState(int *p);
void NNS_FndFreeToFrmHeap(void *p, int flags)
{
    if (flags & 1)
        NNSi_FndResetFrmHeapHead(p);
    if (flags & 2)
        NNSi_FndResetFrmHeapState(p);
}
