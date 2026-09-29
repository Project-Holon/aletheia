/*
 * function: func_021D4E1C
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
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_02084998  0x02084998  arm
 *   func_021D6DC4  0x021D6DC4  arm  ov016
 *   func_02088234  0x02088234  arm
 *   func_02084968  0x02084968  arm
 *   g_021DE670  0x021DE670  data
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

extern void *func_021D54C4(void *queue);
extern unsigned long func_02084998(unsigned long intr);
extern void func_021D6DC4(void *pos, void *ob);
extern void func_02088234(void);
extern unsigned long func_02084968(unsigned long intr);
extern MemCellT *g_021DE670;

void *func_021D4E1C(int lcd, int num, int head)
{
    CellInfo *cell;
    CellInfo *c;
    CellInfo *n;
    GXOamAttr *obj;
    unsigned long irq;

    cell = func_021D54C4(g_021DE670->c[lcd].queue);
    irq = func_02084998(1);
    if (head) {
        for (c = &g_021DE670->c[lcd].head; c != &g_021DE670->c[lcd].tail; c = n) {
            n = c->next;
            obj = c->obj + c->num;
            if (obj + num <= n->obj) {
                cell->obj = obj;
                func_021D6DC4(n, cell);
                break;
            }
        }
        if (c == &g_021DE670->c[lcd].tail)
            func_02088234();
    } else {
        for (c = &g_021DE670->c[lcd].tail; c != &g_021DE670->c[lcd].head; c = n) {
            n = c->prev;
            obj = c->obj - num;
            if (obj >= n->obj + n->num) {
                cell->obj = obj;
                func_021D6DC4(c, cell);
                break;
            }
        }
        if (c == &g_021DE670->c[lcd].head)
            func_02088234();
    }
    func_02084968(irq);
    cell->num = num;
    return cell;
}
