/*
 * function: func_021CEB54
 * address:  0x021CEB54
 * packet:   pkt_ov016_021CEB54
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      moveBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021D68E4  0x021D68E4  arm  ov016
 *   func_021D6B64  0x021D6B64  arm  ov016
 *   func_021CEC24  0x021CEC24  arm  ov016
 *   func_021CEEE8  0x021CEEE8  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   g_021DAA7C  0x021DAA7C  data
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8BB  0x021DA8BB  data
 */

#include "../include/G_tagRECT.h"

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
} SB;

typedef struct {
	unsigned short x;
	unsigned short y;
} COORD;

typedef unsigned short u16;
struct tagCOORD;
extern int func_021D68E4(u16 *a);
extern int func_021D6B64(struct tagCOORD *c);
extern void func_021CEC24(int pos);
extern void func_021CEEE8(int pos);
extern void func_021D0014();
extern struct tagRECT g_021DAA7C;
extern SB *g_021DE63C;
extern unsigned char g_021DA8BB[];

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
