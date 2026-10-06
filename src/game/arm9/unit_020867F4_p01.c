/*
 * file:     unit_020867F4_p01.c
 * unit:     yes
 * function: func_020867F4, func_02086810, func_02086838
 * address:  0x020867F4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct Node {
    struct Node *prev;
    struct Node *next;
};

typedef unsigned char u8;

typedef unsigned int u32;

struct Cell {
    struct Cell *prev;
    struct Cell *next;
    u32 size;
};





struct Node *func_020867F4(struct Node *r0, struct Node *r1)
{
    r1->next = r0;
    r1->prev = 0;
    if (r0 != 0) {
        r0->prev = r1;
    }
    return r1;
}


struct Node *func_02086810(struct Node *list, struct Node *node)
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
