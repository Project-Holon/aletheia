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
 *   DWCi_TPlCheck  0x021D68E4  arm  ov016
 *   DWCi_TPlGet  0x021D6B64  arm  ov016
 *   func_021CEC24  0x021CEC24  arm  ov016
 *   func_021CEEE8  0x021CEEE8  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   sScrollbarTable  0x021DAA7C  data
 *   gScrollBar  0x021DE63C  data
 *   sScrollBarStep  0x021DA8BB  data
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
extern int DWCi_TPlCheck(u16 *a);
extern int DWCi_TPlGet(struct tagCOORD *c);
extern void func_021CEC24(int pos);
extern void func_021CEEE8(int pos);
extern void DWCi_SNDlStop();
extern struct tagRECT sScrollbarTable;
extern SB *gScrollBar;
extern unsigned char sScrollBarStep[];

void func_021CEB54(void)
{
	COORD c;
	int pos;
	int s;

	if (DWCi_TPlCheck((u16 *)((char *)&sScrollbarTable))) {
		DWCi_TPlGet((struct tagCOORD *)(&c));
		if (c.x >= gScrollBar->x - 30) {
			pos = gScrollBar->base + (c.y - gScrollBar->off);
			if (pos < 0)
				pos = 0;
			else {
				s = sScrollBarStep[gScrollBar->bar];
				if (pos >= gScrollBar->len - s)
					pos = gScrollBar->len - s;
			}
			func_021CEC24(pos);
			func_021CEEE8(pos);
			gScrollBar->b = 2;
			return;
		}
	}
	DWCi_SNDlStop();
	gScrollBar->a = 0;
	gScrollBar->b = 3;
}
