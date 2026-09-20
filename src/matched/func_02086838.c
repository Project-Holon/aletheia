/*
 * function: func_02086838
 * address:  0x02086838
 * packet:   pkt_02086788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Cell {
    struct Cell *prev;
    struct Cell *next;
    u32 size;
};

struct Cell *func_02086838(struct Cell *list, struct Cell *cell)
{
    struct Cell *prev = 0;
    struct Cell *curr = list;
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
