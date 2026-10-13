/*
 * file:     objvram.c
 * unit:     yes
 * function: func_021D6F9C, func_021D705C, func_021D71C0
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_021D6D44  0x021D6D44  arm  ov016
 *   func_021D6E04  0x021D6E04  arm  ov016
 *   func_021D6DF4  0x021D6DF4  arm  ov016
 *   g_021DE6AC  0x021DE6AC  data
 *   func_021D54C4 0x021D54C4 arm ov016
 *   func_02084998 0x02084998 arm
 *   func_021D6DC4 0x021D6DC4 arm ov016
 *   func_02088234 0x02088234 arm
 *   func_02084968 0x02084968 arm
 *   func_021D6D8C  0x021D6D8C  arm  ov016
 *   func_021D546C  0x021D546C  arm  ov016
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

typedef unsigned short u16;

typedef unsigned long u32;

extern void *func_021D6414(unsigned long size, int align);
extern void *func_021D5410(long size, void *data, long dsize);
extern struct ListCB *func_021D6D44(void);
extern void func_021D6E04(char *p, void *ob);
extern void func_021D6DF4(char *p, void *ob);
extern void *func_021D54C4(void *queue);
extern u32 func_02084998(u32 intr);
extern void func_021D6DC4(void *pos, void *ob);
extern void func_02088234(void);
extern u32 func_02084968(u32 intr);
extern void func_021D6D8C(void *ob);
extern void func_021D546C(void *que, void *data);
void func_021D6F9C(void);
void *func_021D705C(int lcd, int num, int head, int *name);
void func_021D71C0(void *ovram);
extern MemOvr *g_021DE6AC;



/*
 * sdk:      DWCi_OVRlInit (libdwcutil.TWL.HYB.a(objvram.o))
 */
void func_021D6F9C(void)
{
	int i;

	g_021DE6AC = func_021D6414(0x340, 4);
	for (i = 0; i < 2; i++) {
		g_021DE6AC->lcd[i].queue = func_021D5410(0x20, &g_021DE6AC->lcd[i], 0xc);
		g_021DE6AC->lcd[i].list = func_021D6D44();
		g_021DE6AC->lcd[i].first.pos = 0x300;
		g_021DE6AC->lcd[i].last.pos = 0x400;
		func_021D6E04(g_021DE6AC->lcd[i].list, &g_021DE6AC->lcd[i].first);
		func_021D6DF4(g_021DE6AC->lcd[i].list, &g_021DE6AC->lcd[i].last);
	}
}



/*
 * sdk:      DWCi_OVRlAlloc (libdwcutil.TWL.HYB.a(objvram.o))
 */
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


/*
 * sdk:      DWCi_OVRlFree (libdwcutil.TWL.HYB.a(objvram.o))
 */
void func_021D71C0(void *ovram)
{
	int lcd = 0;

	func_021D6D8C(ovram);
	if ((char *)ovram >= (char *)&g_021DE6AC->lcd[1])
		lcd = 1;
	func_021D546C(g_021DE6AC->lcd[lcd].queue, ovram);
}
