/*
 * function: func_020869E8
 * address:  0x020869E8
 * packet:   pkt_02086788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02086810  0x02086810  arm
 *   func_02086838  0x02086838  arm
 *   addr_0215126C  0x0215126C  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Cell {
    struct Cell *prev;
    struct Cell *next;
    int size;
};

struct HeapDesc {
    int unk0;
    struct Cell *freeList;
    struct Cell *allocatedList;
};

struct ArenaInfo {
    int currentHeap;
    char pad[0xc];
    struct HeapDesc *heapArray;
};

extern struct ArenaInfo *addr_0215126C[];
extern int func_02087988(void);
extern void func_0208799C(int);
extern struct Cell *func_02086810(struct Cell *list, struct Cell *cell);
extern struct Cell *func_02086838(struct Cell *list, struct Cell *cell);

void func_020869E8(int id, int heap, void *ptr)
{
    struct ArenaInfo *info;
    struct HeapDesc *hd;
    struct Cell *cell;
    int enabled;

    enabled = func_02087988();
    info = addr_0215126C[id];

    if (heap < 0) {
        heap = info->currentHeap;
    }

    hd = &info->heapArray[heap];
    cell = (struct Cell *)((u8 *)ptr - 0x20);

    hd->allocatedList = func_02086810(hd->allocatedList, cell);
    hd->freeList = func_02086838(hd->freeList, cell);

    func_0208799C(enabled);
}
