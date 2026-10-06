/*
 * file:     unit_02060468_p01.c
 * unit:     yes
 * function: func_02060468, func_02060480
 * address:  0x02060468
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj06998.h"

typedef unsigned short u16;

struct DList {
    void *head;
    void *tail;
    u16   count;
    u16   node_offset;
};

struct DListNode {
    void *prev;
    void *next;
};

void func_02060468(int p0, int p1);


void func_02060468(int p0, int p1){ ((struct Obj06998 *)p0)->f0 = (int)0; ((struct Obj06998 *)p0)->f4 = (int)0; ((struct Obj06998 *)p0)->f8 = (unsigned short)0; ((struct Obj06998 *)p0)->fA = (unsigned short)p1; }


/*
 * DList: seed an empty list with its first element.  The list header is the
 * one src/matched/unit_02060614.c already fixes -- head at +0x00, tail at
 * +0x04, a u16 count at +0x08 and the u16 byte offset of the embedded link
 * pair at +0x0a -- and the node's own pair is prev at +0x00, next at +0x04.
 * Both links are cleared, head and tail both name the new element, and the
 * count goes up by one.  func_020604AC and func_02060500 both call here when
 * the list they were handed is still empty.
 *
 * The `volatile` on the list pointer is load-bearing and is the only lever
 * that moves this function.  Without it mwcc hoists the `ldrh r1, [r0, #8]`
 * of the count above the two head/tail stores, which frees r1 (the element
 * argument, dead after the stores) for the counter and the whole tail of the
 * function shifts by one register.  The image reads the count last, in source
 * order, and reuses r1 for it.  The permuter names the same mutation
 * (`volatile-add(list)`) as the single change from the plain spelling, whose
 * residue is exactly one register substitution r1 -> r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060480.c \
 *       --func func_02060480 --addr 0x02060480 --cc 1.1p1 --arm
 */
void func_02060480(volatile struct DList *list, void *elem)
{
    struct DListNode *node = (struct DListNode *)((char *)elem + list->node_offset);

    node->next = 0;
    node->prev = 0;
    list->head = elem;
    list->tail = elem;
    list->count = list->count + 1;
}
