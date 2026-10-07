/*
 * file:     unit_021CE874.c
 * unit:     yes
 * function: func_021CE874, func_021CE94C, func_021CE984, func_021CE998
 * address:  0x021CE874
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
 *   func_021D5FE8  0x021D5FE8  arm  ov016
 *   func_021D5394  0x021D5394  arm  ov016
 *   func_021D5118  0x021D5118  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021CE9E8  0x021CE9E8  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8B8  0x021DA8B8  data
 *   func_021D7744  0x021D7744  arm  ov016
 *   func_021D4F60  0x021D4F60  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   dat_021DE63C  0x021DE63C  data
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
} SB_021CE874;

typedef struct {
	void *cell;
	int pad[2];
	void *task;
} SB_021CE94C;

typedef unsigned char  u8;

extern void *func_021D6414(unsigned long size, int alignment);
extern void func_021D5FE8(int a, int b, unsigned short *p);
extern void *func_021D5394(int a, int kind, int c);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int prio);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CE9E8(void);
extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D4F60(u8 *p);
extern void func_021D6438(void **mem);
void func_021CE874(int kind, int max, int x, int y, int pos);
void func_021CE94C(void);
u8 func_021CE984(void);
unsigned char func_021CE998(void);
extern SB_021CE874 *g_021DE63C;
extern unsigned char g_021DA8B8[];
extern u8 *dat_021DE63C;


/*
 * sdk:      DWCi_SBlInit (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CE874(int kind, int max, int x, int y, int pos)
{
	g_021DE63C = (SB_021CE874 *)func_021D6414(0x20, 4);
	g_021DE63C->bar = kind;
	g_021DE63C->len = max;
	g_021DE63C->pos = pos;
	func_021D5FE8(x, y, &g_021DE63C->x);
	g_021DE63C->cell = func_021D5394(0, g_021DA8B8[kind], 1);
	func_021D5118(g_021DE63C->cell, -1, x, y + pos);
	func_021D51F0(g_021DE63C->cell, -1, 1);
	g_021DE63C->task = func_021D7680(0, (void (*)(void *))func_021CE9E8, 0, 0x80);
}


/*
 * sdk:      DWCi_SBlEnd (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CE94C(void)
{
	func_021D7744(0, g_021DE63C->task);
	func_021D4F60(g_021DE63C->cell);
	func_021D6438((void **)0x021DE63C);
}


u8 func_021CE984(void)
{
    return dat_021DE63C[0x1a];
}

/*
 * Read the byte at +0x1d of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE998.c \
 *       --func func_021CE998 --addr 0x021CE998 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char func_021CE998(void)
{
    return *(unsigned char *)(*(char **)0x021DE63C + 0x1d);
}
