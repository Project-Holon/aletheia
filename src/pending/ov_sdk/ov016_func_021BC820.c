/*
 * function: func_021BC820
 * address:  0x021BC820
 * packet:   pkt_ov016_021BC820
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_ANIMElInitEx (libdwcutil.TWL.HYB.a(anime.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5368  0x021D5368  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE504  0x021DE504  data
 *   g_021D9FF8  0x021D9FF8  data
 *   func_021BC924  0x021BC924  arm  ov016
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
	u32 w0;
	u16 h4;
} Obj;

typedef struct {
	void *task;
	Obj *obj;
	u8 color;
	u8 cnt;
} Ani;

extern Ani *g_021DE504;
extern u8 g_021D9FF8[];

extern void *func_021D6414(int size, int align);
extern void *func_021D5368(int a, int b);
extern void *func_021D7680(int a, void (*fn)(void), int b, int c);
extern void func_021BC924(void);

void func_021BC820(int color)
{
	u32 pal;
	Obj *o;
	g_021DE504 = func_021D6414(12, 4);
	g_021DE504->color = color;
	g_021DE504->obj = func_021D5368(0, 0x47);
	pal = g_021D9FF8[color];
	g_021DE504->obj->h4 = (g_021DE504->obj->h4 & ~0xc00) | 0x400;
	o = g_021DE504->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	g_021DE504->obj->w0 = (g_021DE504->obj->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
	g_021DE504->task = func_021D7680(1, func_021BC924, 0, 0x78);
}
