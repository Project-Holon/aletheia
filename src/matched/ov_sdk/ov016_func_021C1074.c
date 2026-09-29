/*
 * function: func_021C1074
 * address:  0x021C1074
 * packet:   pkt_ov016_021C1074
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOVlInit (libdwcutil.TWL.HYB.a(move.o))
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
 */

typedef struct {
	int w[7];
} MovData;

extern void *func_021D6414(unsigned long size, int align);
extern unsigned short *func_021C1030(void *msg, int id);
extern unsigned char func_021C0F20(void);
extern void func_021D3B18(void *wm, MovData *md);
extern int func_021D3D44(void);
extern void OS_Terminate(void);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021C1210(void *task, void *arg);
extern char *g_021DE590;
extern MovData g_021DB0B0;
extern void *g_021DE598;

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
