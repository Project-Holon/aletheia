/*
 * function: DWCi_CELLlForm
 * address:  0x021D4E1C
 * packet:   pkt_ov016_021D4E1C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CELLlForm (libdwcutil.TWL.HYB.a cell.o)
 *
 * symbols:
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   OS_DisableIrqMask  0x02084998  arm
 *   DWCi_LSTlInsert  0x021D6DC4  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   OS_EnableIrqMask  0x02084968  arm
 *   gCellWork  0x021DE670  data
 */

typedef struct { unsigned long attr01; unsigned long attr23; } GXOamAttr;
typedef struct CellInfo {
    struct CellInfo *prev;
    struct CellInfo *next;
    GXOamAttr *obj;
    unsigned char num;
} CellInfo;
typedef struct {
    CellInfo info[32];
    CellInfo head;
    CellInfo tail;
    void *pad;
    void *queue;
} CellPrm;
typedef struct { CellPrm c[2]; } MemCellT;

extern void *DWCi_QUElPopBack(void *queue);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern void DWCi_LSTlInsert(void *pos, void *ob);
extern void OS_Terminate(void);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern MemCellT *gCellWork;

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
