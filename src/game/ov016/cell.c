/*
 * file:     cell.c
 * unit:     yes
 * function: DWCi_CELLlInit, DWCi_CELLlEnd, DWCi_CELLlForm, DWCi_CELLlDelete, DWCi_CELLlGetObj, DWCi_CELLlGetState, DWCi_CELLlSetEffect, DWCi_CELLlSetPalette, DWCi_CELLlSetPosition, DWCi_CELLlSetPriority, DWCi_CELLlGetPosition
 * address:  0x021D4CF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Byte at +0x0c of the argument.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_CELLlGetState.c \
 *       --func DWCi_CELLlGetState --addr 0x021D4FEC --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021d6414  arm  ov016
 *   DWCi_QUElFormEx  0x021d5410  arm  ov016
 *   DWCi_LSTlForm  0x021d6d44  arm  ov016
 *   DWCi_OBJlGetOam  0x021d6f84  arm  ov016
 *   DWCi_LSTlPushFront  0x021d6e04  arm  ov016
 *   DWCi_LSTlPushBack  0x021d6df4  arm  ov016
 *   gCellWork  0x021de670  data
 *   DWCi_LSTlDelete  0x021d6d70  arm  ov016
 *   DWCi_QUElDelete  0x021d5450  arm  ov016
 *   DWCi_HEAPlFree_  0x021d6438  arm  ov016
 *   gMemCell  0x021DE670  data
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   OS_DisableIrqMask  0x02084998  arm
 *   DWCi_LSTlInsert  0x021D6DC4  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   OS_EnableIrqMask  0x02084968  arm
 *   DWCi_LSTlErase  0x021D6D8C  arm
 *   DWCi_QUElPushBack  0x021D546C  arm
 */
struct ListCB;

#include "../types.h"

#include "gx_oam_types.h"

/* A DWC GUI cell list node (cell.o): doubly linked between its neighbours and
 * carrying the base OAM entry plus the number of OAM entries it owns. */
typedef struct CellInfo {
    struct CellInfo *prev;
    struct CellInfo *next;
    GXOamAttr *obj;
    unsigned char num;
} CellInfo;

typedef struct tagCELLPRM {
    CellInfo info[32];
    CellInfo head;
    CellInfo tail;
    void *list;
    void *queue;
} CELLPRM;

typedef struct tagMEMCELL {
    CELLPRM c[2];
} MEMCELL;

#include "heap.h"
#include "deque.h"
#include "list.h"
#include "obj.h"
struct tagLISTCB;
#include "../arm9/os_interrupt.h"
#include "../arm9/os_terminate_processor.h"
void DWCi_CELLlInit(void);
void DWCi_CELLlEnd(void);
void *DWCi_CELLlForm(int lcd, int num, int head);
void DWCi_CELLlDelete(CellInfo *p);
GXOamAttr *DWCi_CELLlGetObj(CellInfo *p, unsigned int i);
unsigned char DWCi_CELLlGetState(CellInfo *cell);
void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine);
void DWCi_CELLlSetPalette(u8 *obj, int idx, u32 v, u32 w);
void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y);
extern MEMCELL *gCellWork;
extern MEMCELL *gMemCell;

/*
 * sdk:      DWCi_CELLlInit (libdwcutil.TWL.HYB.a(cell.o))
 */

void DWCi_CELLlInit(void)
{
    int i;

    gCellWork = (MEMCELL *)DWCi_HEAPlAllocEx(sizeof(*gCellWork), 4);
    for (i = 0; i < 2; i++) {
        gCellWork->c[i].queue = DWCi_QUElFormEx(0x20, &gCellWork->c[i], 0x10);
        gCellWork->c[i].list = DWCi_LSTlForm();
        gCellWork->c[i].head.obj = (union GXOamAttr *)DWCi_OBJlGetOam(i, 0x40);
        gCellWork->c[i].tail.obj = (union GXOamAttr *)DWCi_OBJlGetOam(i, 0x7F) + 1;
        DWCi_LSTlPushFront(gCellWork->c[i].list, &gCellWork->c[i].head);
        DWCi_LSTlPushBack(gCellWork->c[i].list, &gCellWork->c[i].tail);
    }
}

/*
 * sdk:      DWCi_CELLlEnd (libdwcutil.TWL.HYB.a(cell.o))
 */
void DWCi_CELLlEnd(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        DWCi_LSTlDelete(gCellWork->c[i].list);
        DWCi_QUElDelete(gCellWork->c[i].queue);
    }
    DWCi_HEAPlFree_((void **)&gMemCell);
}

/*
 * sdk:      DWCi_CELLlForm (libdwcutil.TWL.HYB.a cell.o)
 */
void *DWCi_CELLlForm(int lcd, int num, int head)
{
    CellInfo *cell;
    CellInfo *c;
    CellInfo *n;
    GXOamAttr *obj;
    unsigned long irq;

    cell = DWCi_QUElPopBack(gCellWork->c[lcd].queue);
    irq = OS_DisableIrqMask(1);
    if (head) {
        for (c = &gCellWork->c[lcd].head; c != &gCellWork->c[lcd].tail; c = n) {
            n = c->next;
            obj = c->obj + c->num;
            if (obj + num <= n->obj) {
                cell->obj = obj;
                DWCi_LSTlInsert(n, cell);
                break;
            }
        }
        if (c == &gCellWork->c[lcd].tail)
            OS_Terminate();
    } else {
        for (c = &gCellWork->c[lcd].tail; c != &gCellWork->c[lcd].head; c = n) {
            n = c->prev;
            obj = c->obj - num;
            if (obj >= n->obj + n->num) {
                cell->obj = obj;
                DWCi_LSTlInsert(c, cell);
                break;
            }
        }
        if (c == &gCellWork->c[lcd].head)
            OS_Terminate();
    }
    OS_EnableIrqMask(irq);
    cell->num = num;
    return cell;
}

void DWCi_CELLlDelete(CellInfo *p)
{
    GXOamAttr *obj;
    int i;
    int sel = 0;

    obj = p->obj;
    for (i = 0; i < p->num; i++) {
        obj->attr01 = (obj->attr01 & 0xC1FFFCFF) | 0x200;
        obj++;
    }
    DWCi_LSTlErase(p);
    if (p >= (CellInfo *)&gCellWork->c[1])
        sel = 1;
    DWCi_QUElPushBack(gCellWork->c[sel].queue, p);
}

/*
 * Index into the i-th 8-byte record of the table at p+8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_CELLlGetObj.c  *       --func DWCi_CELLlGetObj --addr 0x021D4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */
GXOamAttr *DWCi_CELLlGetObj(CellInfo *p, unsigned int i)
{
    return p->obj + i;
}

unsigned char DWCi_CELLlGetState(CellInfo *cell)
{
    return cell->num;
}

void DWCi_CELLlSetEffect(void *cell, int idx, int effect, int affine)
{
    CellInfo *c = (CellInfo *)cell;
    GXOamAttr *oam = c->obj;
    int i;

    if (idx >= 0) {
        if (effect != 0x100 && effect != 0x300)
            { oam[idx].attr01 &= 0xC1FFFCFF; oam[idx].attr01 |= effect; }
        else
            { oam[idx].attr01 &= 0xC1FFFCFF; oam[idx].attr01 |= effect; oam[idx].attr01 |= (u32)affine << 25; }
    } else {
        for (i = 0; i < c->num; i++) {
            if (effect != 0x100 && effect != 0x300)
                { oam[i].attr01 &= 0xC1FFFCFF; oam[i].attr01 |= effect; }
            else
                { oam[i].attr01 &= 0xC1FFFCFF; oam[i].attr01 |= effect; oam[i].attr01 |= (u32)affine << 25; }
        }
    }
}

void DWCi_CELLlSetPalette(u8 *obj, int idx, u32 v, u32 w)
{
    GXOamAttr *arr = *(GXOamAttr **)(obj + 8);

    if (idx >= 0) {
        arr[idx].attr01 = (arr[idx].attr01 & ~0xC00u) | (v << 10);
        arr[idx].attr2 = (arr[idx].attr2 & ~0xF000u) | (w << 12);
    } else {
        int i = 0;
        while (i < *(u8 *)(obj + 0xC)) {
            arr[i].attr01 = (arr[i].attr01 & ~0xC00u) | (v << 10);
            arr[i].attr2 = (arr[i].attr2 & ~0xF000u) | (w << 12);
            i++;
        }
    }
}

static inline void G2_GetOBJPosition(const GXOamAttr *oam, unsigned long *x, unsigned long *y)
{
    *x = (oam->attr01 & 0x01FF0000) >> 16;
    *y = (oam->attr01 & 0x000000FF) >> 0;
}

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

/*
 * sdk:      DWCi_CELLlSetPosition (libdwcutil.TWL.HYB.a(cell.o))
 */
void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y)
{
    CellInfo *c = (CellInfo *)cell;
    GXOamAttr *oam;
    int i;
    int x0, y0, x1, y1, dx, dy;

    oam = c->obj;
    if (idx >= 0) {
        G2_SetOBJPosition(&oam[idx], x, y);
    } else {
        G2_GetOBJPosition(&oam[0], (unsigned long *)&x0, (unsigned long *)&y0);
        G2_SetOBJPosition(&oam[0], x, y);
        dx = x - x0;
        dy = y - y0;
        for (i = 1; i < c->num; i++) {
            G2_GetOBJPosition(&oam[i], (unsigned long *)&x1, (unsigned long *)&y1);
            G2_SetOBJPosition(&oam[i], x1 + dx, y1 + dy);
        }
    }
}

/*
 * sdk:      DWCi_CELLlSetPriority (libdwcutil.TWL.HYB.a(cell.o))
 */
void DWCi_CELLlSetPriority(void *cell, int idx, int priority)
{
    CellInfo *c = (CellInfo *)cell;
    GXOamAttr *oam = c->obj;
    int i;

    if (idx >= 0) {
        oam[idx].attr2 = (oam[idx].attr2 & ~0xC00) | (priority << 10);
    } else {
        for (i = 0; i < c->num; i++)
            oam[i].attr2 = (oam[i].attr2 & ~0xC00) | (priority << 10);
    }
}

/*
 * sdk:      DWCi_CELLlGetPosition (libdwcutil.TWL.HYB.a(cell.o))
 */
void DWCi_CELLlGetPosition(void *cell, int idx, int *x, int *y)
{
    GXOamAttr *oam = ((CellInfo *)cell)->obj;
    *x = (oam[idx].attr01 & 0x01ff0000) >> 16;
    *y = oam[idx].attr01 & 0xff;
}
