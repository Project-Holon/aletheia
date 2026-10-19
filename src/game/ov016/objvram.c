/*
 * file:     objvram.c
 * unit:     yes
 * function: DWCi_OVRlInit, DWCi_OVRlAlloc, DWCi_OVRlFree
 * address:  0x021D6F9C
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
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   DWCi_LSTlForm  0x021D6D44  arm  ov016
 *   DWCi_LSTlPushFront  0x021D6E04  arm  ov016
 *   DWCi_LSTlPushBack  0x021D6DF4  arm  ov016
 *   gObjvramWork  0x021DE6AC  data
 *   DWCi_QUElPopBack 0x021D54C4 arm ov016
 *   OS_DisableIrqMask 0x02084998 arm
 *   DWCi_LSTlInsert 0x021D6DC4 arm ov016
 *   OS_Terminate 0x02088234 arm
 *   OS_EnableIrqMask 0x02084968 arm
 *   DWCi_LSTlErase  0x021D6D8C  arm  ov016
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 */
struct ListCB;
typedef struct Ovr {
	struct Ovr *prev;
	struct Ovr *next;
	unsigned short pos;
	unsigned short size;
} Ovr;

typedef struct {
	char pad0[0x180];
	Ovr first;
	Ovr last;
	void *list;
	void *queue;
} Lcd;

typedef struct {
	Lcd lcd[2];
} MemOvr;

#include "../types.h"

#include "heap.h"
#include "deque.h"
#include "list.h"
typedef unsigned int OSIrqMask;
#include "../arm9/os_interrupt.h"
#include "../arm9/os_terminate_processor.h"
void DWCi_OVRlInit(void);
void *DWCi_OVRlAlloc(int lcd, int num, int head, int *name);
void DWCi_OVRlFree(void *ovram);
extern MemOvr *gObjvramWork;

/*
 * sdk:      DWCi_OVRlInit (libdwcutil.TWL.HYB.a(objvram.o))
 */

void DWCi_OVRlInit(void)
{
	int i;

	gObjvramWork = DWCi_HEAPlAllocEx(0x340, 4);
	for (i = 0; i < 2; i++) {
		gObjvramWork->lcd[i].queue = DWCi_QUElFormEx(0x20, &gObjvramWork->lcd[i], 0xc);
		gObjvramWork->lcd[i].list = DWCi_LSTlForm();
		gObjvramWork->lcd[i].first.pos = 0x300;
		gObjvramWork->lcd[i].last.pos = 0x400;
		DWCi_LSTlPushFront(gObjvramWork->lcd[i].list, &gObjvramWork->lcd[i].first);
		DWCi_LSTlPushBack(gObjvramWork->lcd[i].list, &gObjvramWork->lcd[i].last);
	}
}

/*
 * sdk:      DWCi_OVRlAlloc (libdwcutil.TWL.HYB.a(objvram.o))
 */
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

/*
 * sdk:      DWCi_OVRlFree (libdwcutil.TWL.HYB.a(objvram.o))
 */
void DWCi_OVRlFree(void *ovram)
{
	int lcd = 0;

	DWCi_LSTlErase(ovram);
	if ((char *)ovram >= (char *)&gObjvramWork->lcd[1])
		lcd = 1;
	DWCi_QUElPushBack(gObjvramWork->lcd[lcd].queue, ovram);
}
