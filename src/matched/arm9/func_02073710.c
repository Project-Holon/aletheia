/*
 * function: NNSi_SndPlayerHeapDisposeCallback
 * address:  0x02073710
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gSndPlayers  0x0214E464  data
 *   NNS_SndHeapDestroy  0x02074758  arm
 *   NNS_FndRemoveListObject  0x020605B4  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct A { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; };
struct E { u8 p0[0xc]; u8 f0c; u8 pad[0x24 - 0xd]; };
extern struct E gSndPlayers[];
extern void NNS_SndHeapDestroy(void **a0);
struct DList;
extern void NNS_FndRemoveListObject(volatile struct DList *list, void *elem);
void NNSi_SndPlayerHeapDisposeCallback(struct A *a) {
    if (a->f8 == 0) return;
    NNS_SndHeapDestroy((void **)a->f8);
    if (a->fc != 0) { *(u32 *)(a->fc + 8) = 0; return; }
    NNS_FndRemoveListObject((volatile struct DList *)(&gSndPlayers[a->f10].f0c), a);
}
