/*
 * function: DWCi_SBlInit
 * address:  0x021CE874
 * packet:   pkt_ov016_021CE874
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SBlInit (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_InputCoord  0x021D5FE8  arm  ov016
 *   DWCi_CEINlSetExCell  0x021D5394  arm  ov016
 *   DWCi_CELLlSetPosition  0x021D5118  arm  ov016
 *   DWCi_CELLlSetPriority  0x021D51F0  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   func_021CE9E8  0x021CE9E8  arm  ov016
 *   gScrollBar  0x021DE63C  data
 *   sScrollBarCellIds  0x021DA8B8  data
 */

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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_InputCoord(int a, int b, unsigned short *p);
extern void *DWCi_CEINlSetExCell(int a, int kind, int c);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int prio);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CE9E8(void);
extern SB *gScrollBar;
extern unsigned char sScrollBarCellIds[];

void DWCi_SBlInit(int kind, int max, int x, int y, int pos)
{
	gScrollBar = (SB *)DWCi_HEAPlAllocEx(0x20, 4);
	gScrollBar->bar = kind;
	gScrollBar->len = max;
	gScrollBar->pos = pos;
	DWCi_InputCoord(x, y, &gScrollBar->x);
	gScrollBar->cell = DWCi_CEINlSetExCell(0, sScrollBarCellIds[kind], 1);
	DWCi_CELLlSetPosition(gScrollBar->cell, -1, x, y + pos);
	DWCi_CELLlSetPriority(gScrollBar->cell, -1, 1);
	gScrollBar->task = DWCi_TSKlForm(0, (void (*)(void *))func_021CE9E8, 0, 0x80);
}
