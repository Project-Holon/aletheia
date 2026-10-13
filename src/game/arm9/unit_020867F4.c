/*
 * file:     unit_020867F4.c
 * unit:     yes
 * function: func_020867F4, func_02086810, func_02086838, func_020868E0, func_020869E8, func_02086A50, func_02086AF8, func_02086B98, func_02086C54, func_02086C70, func_02086CBC
 * address:  0x020867F4
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OSiHeapInfo           0x0215126C  data
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   g_020A86AC            0x020A86AC  data
 */
#define OSi_ROUND(n, a)     (((u32)(n) + (a) - 1) & ~((a) - 1))
#define OSi_TRUNC(n, a)     (((u32)(n)) & ~((a) - 1))
typedef unsigned char u8;

typedef struct Cell Cell;

struct Cell {
    Cell *prev;
    Cell *next;
    long size;
};

typedef struct HeapDesc {
    long size;
    Cell *free;
    Cell *allocated;
} HeapDesc;

typedef struct OSHeapInfo {
    volatile int currentHeap;
    int numHeaps;
    void *arenaStart;
    void *arenaEnd;
    HeapDesc *heapArray;
} OSHeapInfo;

typedef unsigned long u32;

typedef long s32;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef enum OSArenaId {
    OS_ARENA_MAIN = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX = 2,
    OS_ARENA_ITCM = 3,
    OS_ARENA_DTCM = 4,
    OS_ARENA_SHARED = 5,
    OS_ARENA_WRAM_MAIN = 6,
    OS_ARENA_WRAM_SUB = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX = 9
} OSArenaId;

/* os_alloc.o .data from 0x020A86AC, addressed from one pool word. */
typedef struct OsAllocData {
    int OSi_ExtraHeapHandle;
    OSArenaId OSi_ExtraHeapArenaId;
} OsAllocData;

extern unsigned int OS_DisableInterrupts(void);
extern unsigned int OS_RestoreInterrupts(unsigned int state);
extern BOOL OS_IsRunOnTwl(void);
extern void func_02087988(void);
extern void func_0208799C(void);
Cell *func_020867F4(Cell *r0, Cell *r1);
Cell *func_02086810(Cell *list, Cell *node);
Cell *func_02086838(Cell *list, Cell *cell);
void *func_020868E0(int id, int heap, int size);
void func_020869E8(int id, int heap, void *ptr);
void *func_02086A50(OSArenaId id, void *arenaStart, void *arenaEnd, int maxHeaps);
int func_02086AF8(OSArenaId id, void *start, void *end);
int func_02086B98(OSArenaId id);
long OS_ReferentSize(int id, void *ptr);
BOOL func_02086C70(void *ptr);
int func_02086CBC(void *ptr);
extern OSHeapInfo *OSiHeapInfo[9];
extern OsAllocData g_020A86AC;







Cell *func_020867F4(Cell *r0, Cell *r1)
{
    r1->next = r0;
    r1->prev = 0;
    if (r0 != 0) {
        r0->prev = r1;
    }
    return r1;
}




Cell *func_02086810(Cell *list, Cell *node)
{
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev == 0) {
        list = node->next;
    } else {
        node->prev->next = node->next;
    }
    return list;
}




Cell *func_02086838(Cell *list, Cell *cell)
{
    Cell *prev = 0;
    Cell *curr = list;
    while (curr != 0) {
        if (cell <= curr) break;
        prev = curr;
        curr = curr->next;
    }
    cell->prev = prev;
    cell->next = curr;
    if (curr != 0) {
        curr->prev = cell;
        if ((u8 *)cell + cell->size == (u8 *)curr) {
            cell->size += curr->size;
            curr = curr->next;
            cell->next = curr;
            if (curr != 0) curr->prev = cell;
        }
    }
    if (prev != 0) {
        prev->next = cell;
        if ((u8 *)prev + prev->size == (u8 *)cell) {
            prev->size += cell->size;
            prev->next = curr;
            if (curr != 0) curr->prev = prev;
            return list;
        }
        return list;
    }
    return cell;
}




void *func_020868E0(int id, int heap, int size)
{
    
    OSHeapInfo *info;
    HeapDesc *hd;
    Cell *cell;
    int enabled;
    int leftover;

    enabled = OS_DisableInterrupts();
    info = OSiHeapInfo[id];

    if (info == 0) {
        (void)OS_RestoreInterrupts(enabled);
        return 0;
    }

    if (heap < 0) {
        heap = info->currentHeap;
    }

    hd = &info->heapArray[heap];
    cell = hd->free;
    size = (size + 0x3f) & ~0x1f;

    while (cell != 0) {
        if (size <= cell->size) {
            break;
        }
        cell = cell->next;
    }

    if (cell == 0) {
        (void)OS_RestoreInterrupts(enabled);
        return 0;
    }

    leftover = cell->size - size;
    if ((u32)leftover < 0x40) {
        hd->free = func_02086810(hd->free, cell);
    } else {
        Cell *newCell;
        cell->size = size;
        newCell = (Cell *)((u8 *)cell + size);
        newCell->size = leftover;
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != 0) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != 0) {
            newCell->prev->next = newCell;
        } else {
            hd->free = newCell;
        }
    }

    hd->allocated = func_020867F4(hd->allocated, cell);
    (void)OS_RestoreInterrupts(enabled);
    return (void *)((u8 *)cell + 0x20);

}




void func_020869E8(int id, int heap, void *ptr)
{
    OSHeapInfo *info;
    HeapDesc *hd;
    Cell *cell;
    int enabled;

    enabled = OS_DisableInterrupts();
    info = OSiHeapInfo[id];

    if (heap < 0) {
        heap = info->currentHeap;
    }

    hd = &info->heapArray[heap];
    cell = (Cell *)((u8 *)ptr - 0x20);

    hd->allocated = func_02086810(hd->allocated, cell);
    hd->free = func_02086838(hd->free, cell);

    (void)OS_RestoreInterrupts(enabled);
}



/*
 * sdk:      OS_InitAlloc (os_alloc.o)
 */
void *func_02086A50(OSArenaId id, void *arenaStart, void *arenaEnd, int maxHeaps)
{
    OSHeapInfo *heapInfo;
    u32 arraySize;
    int i;
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();

    heapInfo = (OSHeapInfo *)arenaStart;
    OSiHeapInfo[id] = heapInfo;

    arraySize = sizeof(HeapDesc) * maxHeaps;
    heapInfo->heapArray = (HeapDesc *)((u32)arenaStart + sizeof(OSHeapInfo));
    heapInfo->numHeaps = maxHeaps;

    for (i = 0; i < heapInfo->numHeaps; i++) {
        HeapDesc *hd = &heapInfo->heapArray[i];

        hd->size = -1;
        hd->free = hd->allocated = 0;
    }

    heapInfo->currentHeap = -1;

    arenaStart = (void *)((u32)heapInfo->heapArray + arraySize);
    heapInfo->arenaStart = (void *)OSi_ROUND(arenaStart, 32);
    heapInfo->arenaEnd = (void *)OSi_TRUNC(arenaEnd, 32);

    (void)OS_RestoreInterrupts(enabled);
    return heapInfo->arenaStart;
}



/*
 * sdk:      OS_CreateHeap (os_alloc.o)
 */
int func_02086AF8(OSArenaId id, void *start, void *end)
{
    OSIntrMode enabled;
    OSHeapInfo *heapInfo;
    int heap;
    HeapDesc *hd;
    Cell *cell;

    enabled = OS_DisableInterrupts();
    heapInfo = OSiHeapInfo[id];

    start = (void *)OSi_ROUND(start, 32);
    end = (void *)OSi_TRUNC(end, 32);

    for (heap = 0; heap < heapInfo->numHeaps; heap++) {
        hd = &heapInfo->heapArray[heap];
        if (hd->size < 0) {
            hd->size = (u8 *)end - (u8 *)start;

            cell = (Cell *)start;
            cell->prev = 0;
            cell->next = 0;
            cell->size = hd->size;

            hd->free = cell;
            hd->allocated = 0;

            (void)OS_RestoreInterrupts(enabled);
            return heap;
        }
    }

    (void)OS_RestoreInterrupts(enabled);
    return -1;
}



/*
 * sdk:      OS_CreateExtraHeap (os_alloc.o)
 */
int func_02086B98(OSArenaId id)
{
    OSHeapInfo *heapInfo;
    int heap;
    HeapDesc *hd;
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();
    heapInfo = OSiHeapInfo[id];

    if (!OS_IsRunOnTwl() && g_020A86AC.OSi_ExtraHeapHandle < 0) {
        for (heap = 0; heap < heapInfo->numHeaps; heap++) {
            hd = &heapInfo->heapArray[heap];
            if (hd->size < 0) {
                Cell *cell = (Cell *)0x02000000;

                hd->size = 0x4000;
                cell->prev = 0;
                cell->next = 0;
                cell->size = 0x4000;
                hd->free = cell;
                hd->allocated = 0;

                g_020A86AC.OSi_ExtraHeapHandle = heap;
                g_020A86AC.OSi_ExtraHeapArenaId = id;

                (void)OS_RestoreInterrupts(enabled);
                return heap;
            }
        }
    }

    (void)OS_RestoreInterrupts(enabled);
    return -1;
}



long OS_ReferentSize(int id, void *ptr)
{
    func_02087988();
    func_0208799C();
    return ((Cell *)((char *)ptr - 0x20))->size - 0x20;
}



/*
 * sdk:      OS_IsOnExtendedMainMemory (os_alloc.o)
 */
BOOL func_02086C70(void *ptr)
{
    if (OS_IsRunOnTwl()) {
        if (0x0D000000 <= (u32)ptr && (u32)ptr < 0x0E000000) {
            return 1;
        }
        return 0;
    } else {
        if (0x02400000 <= (u32)ptr && (u32)ptr < 0x02800000) {
            return 1;
        }
        return 0;
    }
}


/*
 * note:     os_alloc.o OS_IsOnVram.
 */
int func_02086CBC(void *ptr)
{
    unsigned int p = (unsigned int)ptr;

    if (p >= 0x05000000u && p < 0x07000800u) {
        return 1;
    }
    return 0;
}
