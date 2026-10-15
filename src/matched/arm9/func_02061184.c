/*
 * function: NNS_FndRecordStateForFrmHeap
 * address:  0x02061184
 * packet:   pkt_02061184
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndAllocFromFrmHeapHead  0x02060FEC  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Node {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct Heap {
    u32          cur;    /* +0x00 */
    u32          limit;  /* +0x04 */
    struct Node *head;   /* +0x08 */
};

struct H {
    u8          pad_00[0x24];
    struct Heap h24;     /* +0x24 */
};

extern u32 NNSi_FndAllocFromFrmHeapHead(struct Heap *h, u32 size, u32 align);

int NNS_FndRecordStateForFrmHeap(struct H *h, u32 a1)
{
    struct Node *p;
    u32 saved = h->h24.cur;

    p = (struct Node *)NNSi_FndAllocFromFrmHeapHead(&h->h24, 0x10, 4);
    if (p == 0) {
        return 0;
    }

    p->unk_00 = a1;
    p->unk_04 = saved;
    p->unk_08 = h->h24.limit;
    p->unk_0c = (u32)h->h24.head;
    h->h24.head = p;
    return 1;
}
