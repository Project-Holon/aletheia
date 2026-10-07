/*
 * file:     unit_021D6D44.c
 * unit:     yes
 * function: func_021D6D44, func_021D6D70, func_021D6D8C, func_021D6DC4, func_021D6DF4
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
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
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
    void *f0;
    void *f4;
    void *f8;
    void *fc;
} ListCB;

extern void *func_021D6414(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
ListCB *func_021D6D44(void);
void DWCi_LSTlDelete(struct tagLISTCB *list);
void func_021D6D8C(void *ob);
void func_021D6DC4(void *pos, void *ob);
void func_021D6DF4(char *p, void *ob);


/*
 * sdk:      DWCi_LSTlForm (libdwcutil.TWL.HYB.a list.o)
 */
ListCB *func_021D6D44(void)
{
    ListCB *list = func_021D6414(0x10, 4);
    list->f0 = 0;
    list->f4 = &list->f8;
    list->f8 = list;
    list->fc = 0;
    return list;
}


void DWCi_LSTlDelete(struct tagLISTCB *list)
{
	DWCi_HEAPlFree_((void **)&list);
}


/*
 * sdk:      DWCi_LSTlErase (libdwcutil.TWL.HYB.a list.o)
 */
void func_021D6D8C(void *ob)
{
    ListNode *ln = ob;
    unsigned long irq = OS_DisableIrqMask(1);
    ln->next->prev = ln->prev;
    ln->prev->next = ln->next;
    ln->prev = 0;
    ln->next = 0;
    OS_EnableIrqMask(irq);
}


void func_021D6DC4(void *pos, void *ob)
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


void func_021D6DF4(char *p, void *ob)
{
    func_021D6DC4(p + 8, ob);
}
