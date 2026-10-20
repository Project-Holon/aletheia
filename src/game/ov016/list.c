/*
 * file:     list.c
 * unit:     yes
 * function: DWCi_LSTlForm, DWCi_LSTlDelete, DWCi_LSTlErase, DWCi_LSTlInsert, DWCi_LSTlPushBack, DWCi_LSTlPushFront
 * address:  0x021D6D44
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Tail-call DWCi_LSTlInsert with the pointer held at +0x04.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_LSTlPushFront.c \
 *       --func DWCi_LSTlPushFront --addr 0x021D6E04 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   OS_DisableIrqMask 0x02084998  arm
 *   OS_EnableIrqMask 0x02084968  arm
 */
struct tagLISTCB;
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct ListCB {
    void *headNext;
    void *headPrev;
    void *tailNext;
    void *tailPrev;
} ListCB;

#include "heap.h"
typedef unsigned int OSIrqMask;
#include "../arm9/os_interrupt.h"
ListCB *DWCi_LSTlForm(void);
void DWCi_LSTlDelete(struct tagLISTCB *list);
void DWCi_LSTlErase(void *ob);
void DWCi_LSTlInsert(void *pos, void *ob);
void DWCi_LSTlPushBack(char *p, void *ob);
void DWCi_LSTlPushFront(char *p, void *ob);


/*
 * sdk:      DWCi_LSTlForm (libdwcutil.TWL.HYB.a list.o)
 */

ListCB *DWCi_LSTlForm(void)
{
    ListCB *list = DWCi_HEAPlAllocEx(0x10, 4);
    list->headNext = 0;
    list->headPrev = &list->tailNext;
    list->tailNext = list;
    list->tailPrev = 0;
    return list;
}


void DWCi_LSTlDelete(struct tagLISTCB *list)
{
	DWCi_HEAPlFree_((void **)&list);
}


/*
 * sdk:      DWCi_LSTlErase (libdwcutil.TWL.HYB.a list.o)
 */
void DWCi_LSTlErase(void *ob)
{
    ListNode *ln = ob;
    unsigned long irq = OS_DisableIrqMask(1);
    ln->next->prev = ln->prev;
    ln->prev->next = ln->next;
    ln->prev = 0;
    ln->next = 0;
    OS_EnableIrqMask(irq);
}


void DWCi_LSTlInsert(void *pos, void *ob)
{
    ListNode *tgt = pos;
    ListNode *ln = ob;
    unsigned long irq = OS_DisableIrqMask(1);
    tgt->next->prev = ln;
    ln->next = tgt->next;
    ln->prev = tgt;
    tgt->next = ln;
    OS_EnableIrqMask(irq);
}


void DWCi_LSTlPushBack(char *p, void *ob)
{
    DWCi_LSTlInsert(p + 8, ob);
}


void DWCi_LSTlPushFront(char *p, void *ob)
{
    DWCi_LSTlInsert(*(void **)(p + 4), ob);
}
