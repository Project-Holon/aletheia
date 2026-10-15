/*
 * function: FNDHEAP_Finalize
 * address:  0x0206074C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndFindListContainHeap   0x020606A8  arm
 *   NNS_FndRemoveListObject   0x020605B4  arm
 *
 * Original (24 bytes):
 *   push {r4, lr}
 *   mov  r4, r0
 *   bl   #0x020606A8
 *   mov  r1, r4
 *   bl   #0x020605B4
 *   pop  {r4, pc}
 *
 * The first call keeps the incoming r0.
 */

typedef unsigned int   u32;
extern void *NNSi_FndFindListContainHeap(u32 a);
struct DList;
extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);

void FNDHEAP_Finalize(void *p)
{
    NNS_FndRemoveListObject(NNSi_FndFindListContainHeap((u32)p), p);
}
