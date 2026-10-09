/*
 * file:     unit_021CE9B8.c
 * unit:     yes
 * function: func_021CE9B8, func_021CE9D0, func_021CE9E8, func_021CEB54, func_021CEC24, func_021CEC9C, func_021CECC8, func_021CED30, func_021CEDC4, func_021CEE10, func_021CEEE8
 * address:  0x021CE9B8
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
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021CFFD0  0x021CFFD0  arm  ov016
 *   func_021D6B64  0x021D6B64  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 *   func_021D68E4  0x021D68E4  arm  ov016
 *   func_021D0014  0x021D0014  arm  ov016
 *   g_021DAA7C  0x021DAA7C  data
 *   g_021DA8BB  0x021DA8BB  data
 *   FX_DivS32  0x0207C958  arm
 *   func_021CFFF0  0x021CFFF0  arm  ov016
 *   func_021D69F4  0x021D69F4  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 *   func_021D5118  0x021D5118  arm  ov016
 */
struct tagCOORD;
typedef struct {
    void *cell;                       /* 0x00 */
    void *obj[2];                     /* 0x04 */
    void *task;                       /* 0x0C */
    unsigned short x;                 /* 0x10 */
    unsigned short y;                 /* 0x12 */
    unsigned short w;                 /* 0x14 */
    unsigned short off;               /* 0x16 */
    unsigned char base;               /* 0x18 */
    unsigned char len;                /* 0x19 */
    unsigned char pos;                /* 0x1A */
    unsigned char bar;                /* 0x1B */
    unsigned char a;                  /* 0x1C */
    unsigned char b;                  /* 0x1D */
    unsigned char disable;            /* 0x1E */
    unsigned char pad;                /* 0x1F */
} MemSbT;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

typedef struct {
	unsigned short x;
	unsigned short y;
} COORD;

typedef unsigned short u16;

extern void func_021CFFAC(unsigned int v);
extern void func_021CFFD0(unsigned int v);
extern int func_021D6B64(struct tagCOORD *c);
extern int func_021D68E4(u16 *a);
extern void func_021D0014();
extern long FX_DivS32(long a, long b);
extern void func_021CFFF0(unsigned int a, unsigned int b);
extern int func_021D69F4(u16 *a);
extern int func_021D696C(u16 *a);
extern void func_021D5118(void *cell, int idx, int x, int y);
void func_021CE9B8(void);
void func_021CE9D0(void);
void func_021CE9E8(void);
void func_021CEB54(void);
void func_021CEC24(int pos);
void func_021CEC9C(int idx);
void func_021CECC8(void);
int func_021CED30(void);
int func_021CEDC4(int a);
void func_021CEE10(int idx, RECT *r);
void func_021CEEE8(int pos);
extern MemSbT *g_021DE63C;
extern struct tagRECT g_021DAA7C;
extern unsigned char g_021DA8BB[];




/*
 * Clear the byte at +0x1e of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE9B8.c \
 *       --func func_021CE9B8 --addr 0x021CE9B8 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CE9B8(void)
{
    g_021DE63C->disable = 0;
}




/*
 * Set the byte at +0x1e of the object behind the global pointer to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE9D0.c \
 *       --func func_021CE9D0 --addr 0x021CE9D0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CE9D0(void)
{
    g_021DE63C->disable = 1;
}




/*
 * sdk:      taskMain (libdwcutil.TWL.HYB.a scrollbar.o)
 */
void func_021CE9E8(void)
{
    g_021DE63C->b = 0;
    switch (g_021DE63C->a) {
    case 0:
        if (g_021DE63C->disable)
            return;
        switch (func_021CED30()) {
        case 1:
            if (g_021DE63C->bar == 0)
                return;
            func_021CFFAC(0x16);
            func_021CFFD0(0);
            g_021DE63C->b = 1;
            func_021D6B64((struct tagCOORD *)(&g_021DE63C->w));
            g_021DE63C->base = g_021DE63C->pos;
            g_021DE63C->a = 1;
            break;
        case 2:
            func_021CEC9C(2);
            break;
        case 3:
            func_021CEC9C(3);
            break;
        case 4:
            func_021CECC8();
            break;
        }
        break;
    case 1:
        func_021CEB54();
        break;
    case 2:
        if (func_021CEDC4(2) != 2) {
            g_021DE63C->b = 5;
            g_021DE63C->a = 0;
        } else if (func_021CED30() == 2) {
            func_021CEC9C(2);
        }
        break;
    case 3:
        if (func_021CEDC4(3) != 3) {
            g_021DE63C->b = 7;
            g_021DE63C->a = 0;
        } else if (func_021CED30() == 3) {
            func_021CEC9C(3);
        }
        break;
    }
}







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






/*
 * sdk:      stepBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CEC9C(int idx)
{
	g_021DE63C->a = idx;
	g_021DE63C->b = (idx == 2) ? 4 : 6;
}






/*
 * sdk:      setBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CECC8(void)
{
	COORD c;
	int pos;
	int s;

	func_021D6B64((struct tagCOORD *)(&c));
	s = g_021DA8BB[g_021DE63C->bar];
	pos = c.y - g_021DE63C->y - ((unsigned)s >> 1);
	if (pos < 0)
		pos = 0;
	else if (pos >= g_021DE63C->len - s)
		pos = g_021DE63C->len - s;
	func_021CEEE8(pos);
	g_021DE63C->b = 3;
}






/*
 * sdk:      isTrigger (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
int func_021CED30(void)
{
	int idx;
	RECT r;

	idx = 1;
	func_021CEE10(idx, &r);
	if (func_021D69F4((u16 *)&r))
		return idx;
	for (idx = 2; idx <= 3; idx++) {
		func_021CEE10(idx, &r);
		if (func_021D69F4((u16 *)&r))
			return idx;
	}
	idx = 4;
	func_021CEE10(idx, &r);
	if (!func_021D696C((u16 *)&r))
		idx = 0;
	return idx;
}




/*
 * sdk:      isTouch (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
int func_021CEDC4(int a)
{
	int idx;
	RECT r;

	for (idx = 2; idx <= 3; idx++) {
		func_021CEE10(idx, &r);
		if (func_021D68E4((u16 *)&r))
			return idx;
	}
	return 0;
}



/*
 * sdk:      calcRect (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CEE10(int idx, RECT *r)
{
	int x = g_021DE63C->x;
	r->l = x;
	r->r = x + 12;
	switch (idx) {
	case 0:
		break;
	case 1:
		r->t = g_021DE63C->y + g_021DE63C->pos;
		r->b = r->t + g_021DA8BB[g_021DE63C->bar];
		break;
	case 2:
		r->t = g_021DE63C->y - 13;
		r->b = g_021DE63C->y;
		break;
	case 3:
		r->t = g_021DE63C->y + g_021DE63C->len;
		r->b = r->t + 13;
		break;
	case 4:
		r->t = g_021DE63C->y;
		r->b = r->t + g_021DE63C->len;
		break;
	}
}



/*
 * sdk:      disp (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CEEE8(int pos)
{
	func_021D5118(g_021DE63C->cell, -1, g_021DE63C->x, pos + g_021DE63C->y);
	g_021DE63C->pos = pos;
}
