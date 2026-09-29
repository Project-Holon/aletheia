/*
 * function: func_021BC924
 * address:  0x021BC924
 * packet:   pkt_ov016_021BC924
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskAnime (libdwcutil.TWL.HYB.a(anime.o))
 *
 * symbols:
 *   func_0207C994  0x0207C994  arm
 *   func_0207C958  0x0207C958  arm
 *   func_021D52D4  0x021D52D4  arm  ov016
 *   g_021DE504  0x021DE504  data
 *   g_021D9FF8  0x021D9FF8  data
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

extern int func_0207C994(int a, int b);
extern int func_0207C958(int a, int b);
extern void func_021D52D4(int a, int b, void *obj);

void func_021BC924(void)
{
	int name;
	u32 pal;
	Obj *o;
	g_021DE504->cnt = func_0207C994(g_021DE504->cnt + 1, 40);
	name = func_0207C958(g_021DE504->cnt, 5) + 0x47;
	func_021D52D4(0, name, g_021DE504->obj);
	g_021DE504->obj->h4 = (g_021DE504->obj->h4 & ~0xc00) | 0x400;
	pal = g_021D9FF8[g_021DE504->color];
	o = g_021DE504->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	g_021DE504->obj->w0 = (g_021DE504->obj->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
}
