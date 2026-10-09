/*
 * file:     unit_021D4CF4.c
 * unit:     yes
 * function: func_021D4CF4, func_021D4DC8, func_021D4E1C, func_021D4F60, func_021D4FE0
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
 * symbols:
 *   func_021D6414  0x021d6414  arm  ov016
 *   func_021D5410  0x021d5410  arm  ov016
 *   func_021D6D44  0x021d6d44  arm  ov016
 *   func_021D6F84  0x021d6f84  arm  ov016
 *   func_021D6E04  0x021d6e04  arm  ov016
 *   func_021D6DF4  0x021d6df4  arm  ov016
 *   g_021DE670  0x021de670  data
 *   func_021D6D70  0x021d6d70  arm  ov016
 *   func_021D5450  0x021d5450  arm  ov016
 *   func_021D6438  0x021d6438  arm  ov016
 *   g_021DE670_free  0x021DE670  data
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_02084998  0x02084998  arm
 *   func_021D6DC4  0x021D6DC4  arm  ov016
 *   func_02088234  0x02088234  arm
 *   func_02084968  0x02084968  arm
 *   func_021D6D8C  0x021D6D8C  arm
 *   func_021D546C  0x021D546C  arm
 */
struct ListCB;
typedef struct { unsigned long attr01; unsigned long attr23; } GXOamAttr;

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

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5410(long size, void *data, long dataSize);
extern struct ListCB *func_021D6D44(void);
extern GXOamAttr *func_021D6F84(int lcd, int idx);
extern void func_021D6E04(char *p, void *ob);
extern void func_021D6DF4(char *p, void *ob);
extern void func_021D6D70(void *list);
extern void func_021D5450(void *queue);
extern void func_021D6438(void **mem);
extern void *func_021D54C4(void *queue);
extern unsigned long func_02084998(unsigned long intr);
extern void func_021D6DC4(void *pos, void *ob);
extern void func_02088234(void);
extern unsigned long func_02084968(unsigned long intr);
extern void func_021D6D8C(void *p);
extern void func_021D546C(void *queue, void *data);
void func_021D4CF4(void);
void func_021D4DC8(void);
void *func_021D4E1C(int lcd, int num, int head);
void func_021D4F60(CellInfo *p);
GXOamAttr *func_021D4FE0(CellInfo *p, unsigned int i);
extern MEMCELL *g_021DE670;
extern MEMCELL *g_021DE670_free;




/*
 * sdk:      DWCi_CELLlInit (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D4CF4(void)
{
    int i;

    g_021DE670 = (MEMCELL *)func_021D6414(0x450, 4);
    for (i = 0; i < 2; i++) {
        g_021DE670->c[i].queue = func_021D5410(0x20, &g_021DE670->c[i], 0x10);
        g_021DE670->c[i].list = func_021D6D44();
        g_021DE670->c[i].head.obj = func_021D6F84(i, 0x40);
        g_021DE670->c[i].tail.obj = func_021D6F84(i, 0x7F) + 1;
        func_021D6E04(g_021DE670->c[i].list, &g_021DE670->c[i].head);
        func_021D6DF4(g_021DE670->c[i].list, &g_021DE670->c[i].tail);
    }
}




/*
 * sdk:      DWCi_CELLlEnd (libdwcutil.TWL.HYB.a(cell.o))
 */
void func_021D4DC8(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_021D6D70(g_021DE670->c[i].list);
        func_021D5450(g_021DE670->c[i].queue);
    }
    func_021D6438((void **)&g_021DE670_free);
}



/*
 * sdk:      DWCi_CELLlForm (libdwcutil.TWL.HYB.a cell.o)
 */
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



void func_021D4F60(CellInfo *p)
{
    GXOamAttr *obj;
    int i;
    int sel = 0;

    obj = p->obj;
    for (i = 0; i < p->num; i++) {
        obj->attr01 = (obj->attr01 & 0xC1FFFCFF) | 0x200;
        obj++;
    }
    func_021D6D8C(p);
    if (p >= (CellInfo *)&g_021DE670->c[1])
        sel = 1;
    func_021D546C(g_021DE670->c[sel].queue, p);
}


/*
 * Index into the i-th 8-byte record of the table at p+8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021D4FE0.c  *       --func func_021D4FE0 --addr 0x021D4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */
GXOamAttr *func_021D4FE0(CellInfo *p, unsigned int i)
{
    return p->obj + i;
}
