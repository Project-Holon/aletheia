/*
 * function: func_021D705C
 * address:  0x021D705C
 * packet:   pkt_ov016_021D705C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OVRlAlloc (libdwcutil.TWL.HYB.a(objvram.o))
 *
 * symbols:
 *   func_021D54C4 0x021D54C4 arm ov016
 *   func_02084998 0x02084998 arm
 *   func_021D6DC4 0x021D6DC4 arm ov016
 *   func_02088234 0x02088234 arm
 *   func_02084968 0x02084968 arm
 *   g_021DE6AC 0x021DE6AC data
 */

typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Ovr {
    struct Ovr *prev;
    struct Ovr *next;
    u16 pos;
    u16 size;
} Ovr;

typedef struct {
    char pad0[0x180];
    Ovr first;
    Ovr last;
    int pad198;
    void *queue;
} Lcd;

typedef struct {
    Lcd lcd[2];
} MemOvr;

extern MemOvr *g_021DE6AC;

extern void *func_021D54C4(void *queue);
extern u32 func_02084998(u32 intr);
extern void func_021D6DC4(void *pos, void *ob);
extern void func_02088234(void);
extern u32 func_02084968(u32 intr);

void *func_021D705C(int lcd, int num, int head, int *name)
{
    Ovr *info;
    Ovr *c;
    Ovr *n;
    int nx;
    u32 irq;
    int nu;

    info = func_021D54C4(g_021DE6AC->lcd[lcd].queue);
    nu = ((num + 3) & ~3) >> 2;
    info->size = nu;
    irq = func_02084998(1);
    if (head) {
        c = &g_021DE6AC->lcd[lcd].first;
        while (c != &g_021DE6AC->lcd[lcd].last) {
            n = c->next;
            nx = c->pos + c->size;
            if (nx + nu <= n->pos) {
                info->pos = nx;
                func_021D6DC4(n, info);
                break;
            }
            c = n;
        }
        if (c == &g_021DE6AC->lcd[lcd].last)
            func_02088234();
    } else {
        c = &g_021DE6AC->lcd[lcd].last;
        while (c != &g_021DE6AC->lcd[lcd].first) {
            n = c->prev;
            nx = c->pos - nu;
            if (nx >= n->pos + n->size) {
                info->pos = nx;
                func_021D6DC4(c, info);
                break;
            }
            c = n;
        }
        if (c == &g_021DE6AC->lcd[lcd].first)
            func_02088234();
    }
    *name = info->pos;
    func_02084968(irq);
    return info;
}
