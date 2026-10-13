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
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 */
typedef struct Cell Cell;

struct Cell {
    Cell *prev;
    Cell *next;
    long size;
};

extern void func_02087988(void);
extern void func_0208799C(void);

long OS_ReferentSize(int id, void *ptr)
{
    func_02087988();
    func_0208799C();
    return ((Cell *)((char *)ptr - 0x20))->size - 0x20;
}
