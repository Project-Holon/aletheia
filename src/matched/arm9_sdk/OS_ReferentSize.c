/*
 * function: OS_ReferentSize
 * address:  0x02086C54
 * packet:   pkt_02086C54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 */
typedef struct Cell Cell;

struct Cell {
    Cell *prev;
    Cell *next;
    long size;
};

extern void OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(void);

long OS_ReferentSize(int id, void *ptr)
{
    OS_DisableInterrupts();
    OS_RestoreInterrupts();
    return ((Cell *)((char *)ptr - 0x20))->size - 0x20;
}
