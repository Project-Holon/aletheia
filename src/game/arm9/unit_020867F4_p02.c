/*
 * file:     unit_020867F4_p02.c
 * unit:     yes
 * function: func_020868E0, func_020869E8
 * address:  0x020868E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02086810  0x02086810  arm
 *   func_020867F4  0x020867F4  arm
 *   addr_0215126C  0x0215126C  data
 *   func_02086838  0x02086838  arm
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

extern int func_02087988(void);
extern void func_0208799C(int);
extern struct Cell *func_02086810(struct Cell *list, struct Cell *cell);
extern struct Cell *func_020867F4(struct Cell *list, struct Cell *cell);
extern struct Cell *func_02086838(struct Cell *list, struct Cell *cell);
void *func_020868E0(int id, int heap, int size);
void func_020869E8(int id, int heap, void *ptr);
extern struct ArenaInfo *addr_0215126C[];


void *func_020868E0(int id, int heap, int size)
{
    
    struct ArenaInfo *info;
    struct HeapDesc *hd;
    struct Cell *cell;
    int enabled;
    int leftover;

    enabled = func_02087988();
    info = addr_0215126C[id];

    if (info == 0) {
        func_0208799C(enabled);
        return 0;
    }

    if (heap < 0) {
        heap = info->currentHeap;
    }

    hd = &info->heapArray[heap];
    cell = hd->freeList;
    size = (size + 0x3f) & ~0x1f;

    while (cell != 0) {
        if (size <= cell->size) {
            break;
        }
        cell = cell->next;
    }

    if (cell == 0) {
        func_0208799C(enabled);
        return 0;
    }

    leftover = cell->size - size;
    if ((u32)leftover < 0x40) {
        hd->freeList = func_02086810(hd->freeList, cell);
    } else {
        struct Cell *newCell;
        cell->size = size;
        newCell = (struct Cell *)((u8 *)cell + size);
        newCell->size = leftover;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != 0) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != 0) {
            newCell->prev->next = newCell;
        } else {
            hd->freeList = newCell;
        }
    }

    hd->allocatedList = func_020867F4(hd->allocatedList, cell);
    func_0208799C(enabled);
    return (void *)((u8 *)cell + 0x20);

}


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
