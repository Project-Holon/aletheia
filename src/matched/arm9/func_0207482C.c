/*
 * function: NNS_SndHeapAlloc
 * address:  0x0207482C
 * packet:   pkt_02074770
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_FndAppendListObject  0x020604AC  arm
 *   NNS_FndGetPrevListObject  0x0206062C  arm
 *   NNS_FndAllocFromFrmHeapEx  0x02061124  arm
 */
#include "../include/Obj07066.h"

typedef unsigned char u8; typedef unsigned int u32;

struct DList;
extern unsigned int NNS_FndAllocFromFrmHeapEx(char *p, int n, int v);
extern void *NNS_FndGetPrevListObject(struct DList *list, void *elem);
extern void NNS_FndAppendListObject(u32, u32);

u32 NNS_SndHeapAlloc(u32 *a, u32 b, u32 c, u32 d, u32 e) {
    u32 t;
    u32 r = NNS_FndAllocFromFrmHeapEx((char *)(*a), ((b + 0x1f) & ~0x1fu) + 0x20, 0x20);
    if (r == 0) return 0;
    t = (u32)NNS_FndGetPrevListObject((struct DList *)(a + 1), 0);
    ((struct Obj07066 *)r)->f8 = b;
    ((struct Obj07066 *)r)->fC = c;
    ((struct Obj07066 *)r)->f10 = d;
    ((struct Obj07066 *)r)->f14 = e;
    NNS_FndAppendListObject(t, r);
    return r + 0x20;
}
