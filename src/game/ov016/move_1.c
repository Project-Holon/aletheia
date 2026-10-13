/*
 * file:     move_1.c
 * unit:     yes
 * function: func_021C1074, func_021C115C, func_021C117C, func_021C11B8, func_021C11D4
 * address:  0x021C1074
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
 *   func_021C1030  0x021C1030  arm  ov016
 *   func_021C0F20  0x021C0F20  arm  ov016
 *   func_021D3B18  0x021D3B18  arm  ov016
 *   func_021D3D44  0x021D3D44  arm  ov016
 *   OS_Terminate  0x02088234  arm
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE590  0x021DE590  data
 *   g_021DB0B0  0x021DB0B0  data
 *   g_021DE598  0x021DE598  data
 *   func_021C1210  0x021C1210  arm  ov016
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   taskEnd                          0x021C117C  arm
 *   func_021D3BF8  0x021D3BF8  arm  ov016
 *   func_021D7724  0x021D7724  arm  ov016
 */
typedef struct {
	int w[7];
} MovData;

extern void *func_021D6414(unsigned long size, int align);
extern unsigned int func_021C1030(unsigned int *p, unsigned int idx);
extern unsigned char func_021C0F20(void);
extern void func_021D3B18(void *wm, MovData *md);
extern int func_021D3D44(void);
extern void OS_Terminate(void);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021C1210(void *task, void *arg);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void taskEnd(void *task);
extern int func_021D3BF8(void);
extern void func_021D7724(int kind, void *task);
void func_021C1074(void (*callback)(int));
void DWCi_MOVlEnd(void);
void func_021C117C(void *task);
int func_021C11B8(void);
void func_021C11D4(unsigned int v);
extern char *g_021DE590;
extern MovData g_021DB0B0;
extern void *g_021DE598;


/*
 * sdk:      DWCi_MOVlInit (libdwcutil.TWL.HYB.a(move.o))
 */
void func_021C1074(void (*callback)(int))
{
	MovData dat;

	g_021DE590 = func_021D6414(0x1e2a4, 0x20);
	*(void (**)(int))(g_021DE590 + 0x1e298) = callback;
	g_021DE590[0x1e2a0] = 0;
	g_021DE590[0x1e2a1] = 0;
	dat = g_021DB0B0;
	dat.w[1] = (int)func_021C1030(g_021DE598, 0);
	dat.w[2] = (int)func_021C1030(g_021DE598, 1);
	*(unsigned char *)&dat.w[6] = func_021C0F20();
	func_021D3B18(g_021DE590, &dat);
	if (func_021D3D44() == 0)
		OS_Terminate();
	*(void **)(g_021DE590 + 0x1e29c) = func_021D7680(0, func_021C1210, 0, 0x78);
}


void DWCi_MOVlEnd(void)
{
    DWCi_TSKlForm(0, taskEnd, 0, 0x78);
}


/*
 * sdk:      taskEnd (libdwcutil.TWL.HYB.a(move.o))
 */
void func_021C117C(void *task)
{
	if (func_021D3BF8() == 0)
		return;
	g_021DE590[0x1e2a1] = 1;
	func_021D7724(0, task);
}

int func_021C11B8(void)
{
    return *(void **)0x021DE590 == 0;
}

/*
 * Store a word at +0x1e298 of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C11D4.c \
 *       --func func_021C11D4 --addr 0x021C11D4 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C11D4(unsigned int v)
{
    char *p = *(char **)0x021DE590 + 0x1e000;
    unsigned int *q = (unsigned int *)(p + 0x298);
    *q = v;
}
