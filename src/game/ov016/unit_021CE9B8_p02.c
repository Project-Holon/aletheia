/*
 * file:     unit_021CE9B8_p02.c
 * unit:     yes
 * function: func_021CEB54, func_021CEC24
 * address:  0x021CEB54
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
 *   func_021D68E4  0x021D68E4  arm  ov016
 *   func_021D6B64  0x021D6B64  arm  ov016
 *   func_021CEEE8  0x021CEEE8  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   g_021DAA7C  0x021DAA7C  data
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8BB  0x021DA8BB  data
 *   FX_DivS32  0x0207C958  arm
 *   func_021CFFD0  0x021CFFD0  arm  ov016
 *   func_021CFFF0  0x021CFFF0  arm  ov016
 */
#include "../../matched/include/G_tagRECT.h"

struct tagCOORD;
typedef struct {
	void *cell;
	int pad0[2];
	void *task;
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short off;
	unsigned char base;
	unsigned char len;
	unsigned char pos;
	unsigned char bar;
	unsigned char a;
	unsigned char b;
} SB_021CEB54;

typedef struct {
	unsigned short x;
	unsigned short y;
} COORD;

typedef unsigned short u16;

typedef struct {
	void *cell;
	int pad0[2];
	void *task;
	unsigned short x;
	unsigned short y;
	char pad1[5];
	unsigned char len;
	unsigned char pos;
	unsigned char bar;
	unsigned char a;
	unsigned char b;
} SB_021CEC24;

extern int func_021D68E4(u16 *a);
extern int func_021D6B64(struct tagCOORD *c);
extern void func_021CEEE8(int pos);
extern void func_021D0014();
extern long FX_DivS32(long a, long b);
extern void func_021CFFD0(unsigned int v);
extern void func_021CFFF0(unsigned int a, unsigned int b);
void func_021CEB54(void);
void func_021CEC24(int pos);
extern struct tagRECT g_021DAA7C;
extern SB_021CEB54 *g_021DE63C;
extern unsigned char g_021DA8BB[];


/*
 * sdk:      moveBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CEB54(void)
{
	COORD c;
	int pos;
	int s;

	if (func_021D68E4((u16 *)((char *)&g_021DAA7C))) {
		func_021D6B64((struct tagCOORD *)(&c));
		if (c.x >= g_021DE63C->x - 30) {
			pos = g_021DE63C->base + (c.y - g_021DE63C->off);
			if (pos < 0)
				pos = 0;
			else {
				s = g_021DA8BB[g_021DE63C->bar];
				if (pos >= g_021DE63C->len - s)
					pos = g_021DE63C->len - s;
			}
			func_021CEC24(pos);
			func_021CEEE8(pos);
			g_021DE63C->b = 2;
			return;
		}
	}
	func_021D0014();
	g_021DE63C->a = 0;
	g_021DE63C->b = 3;
}


/*
 * sdk:      playSound (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CEC24(int pos)
{
	int d;
	int vol;
	int pit;

	d = g_021DE63C->pos - pos;
	if (d < 0)
		d = -d;
	if (d < 2)
		vol = 0;
	else if (d >= 6)
		vol = 0x7f;
	else
		vol = FX_DivS32(0x7f, 6 - d);
	func_021CFFD0(vol);
	if (d < 2)
		pit = -0x100;
	else if (d >= 6)
		pit = 0x100;
	else
		pit = FX_DivS32(0x200, 6 - d) - 0x100;
	func_021CFFF0(0xffff, pit);
}
