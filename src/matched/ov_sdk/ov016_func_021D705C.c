/*
 * function: DWCi_OVRlAlloc
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
 *   DWCi_QUElPopBack 0x021D54C4 arm ov016
 *   OS_DisableIrqMask 0x02084998 arm
 *   DWCi_LSTlInsert 0x021D6DC4 arm ov016
 *   OS_Terminate 0x02088234 arm
 *   OS_EnableIrqMask 0x02084968 arm
 *   gObjvramWork 0x021DE6AC data
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

extern MemOvr *gObjvramWork;

extern void *DWCi_QUElPopBack(void *queue);
extern u32 OS_DisableIrqMask(u32 intr);
extern void DWCi_LSTlInsert(void *pos, void *ob);
extern void OS_Terminate(void);
extern u32 OS_EnableIrqMask(u32 intr);

void *DWCi_OVRlAlloc(int lcd, int num, int head, int *name)
{
    Ovr *info;
    Ovr *c;
    Ovr *n;
    int nx;
    u32 irq;
    int nu;

    info = DWCi_QUElPopBack(gObjvramWork->lcd[lcd].queue);
    nu = ((num + 3) & ~3) >> 2;
    info->size = nu;
    irq = OS_DisableIrqMask(1);
    if (head) {
        c = &gObjvramWork->lcd[lcd].first;
        while (c != &gObjvramWork->lcd[lcd].last) {
            n = c->next;
            nx = c->pos + c->size;
            if (nx + nu <= n->pos) {
                info->pos = nx;
                DWCi_LSTlInsert(n, info);
                break;
            }
            c = n;
        }
        if (c == &gObjvramWork->lcd[lcd].last)
            OS_Terminate();
    } else {
        c = &gObjvramWork->lcd[lcd].last;
        while (c != &gObjvramWork->lcd[lcd].first) {
            n = c->prev;
            nx = c->pos - nu;
            if (nx >= n->pos + n->size) {
                info->pos = nx;
                DWCi_LSTlInsert(c, info);
                break;
            }
            c = n;
        }
        if (c == &gObjvramWork->lcd[lcd].first)
            OS_Terminate();
    }
    *name = info->pos;
    OS_EnableIrqMask(irq);
    return info;
}
