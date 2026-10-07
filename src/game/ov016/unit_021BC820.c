/*
 * file:     unit_021BC820.c
 * unit:     yes
 * function: func_021BC820, func_021BC8EC, func_021BC924
 * address:  0x021BC820
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
 *   func_021D5368  0x021D5368  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE504  0x021DE504  data
 *   g_021D9FF8  0x021D9FF8  data
 *   dat_021DE504    0x021DE504  data
 *   func_021D7744   0x021D7744  arm
 *   func_021D6F38   0x021D6F38  arm
 *   func_021D6438   0x021D6438  arm
 *   func_0207C994  0x0207C994  arm
 *   func_0207C958  0x0207C958  arm
 *   func_021D52D4  0x021D52D4  arm  ov016
 */
#include "../../matched/include/G_Ani.h"

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

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5368(int a, int b);
extern void *func_021D7680(int a, void (*fn)(void), int b, int c);
extern void func_021D7744(unsigned int idx, void *r4);
extern void func_021D6F38(unsigned int *obj);
extern void func_021D6438(void **mem);
extern int func_0207C994(int a, int b);
extern int func_0207C958(int a, int b);
extern void func_021D52D4(int a, int b, void *obj);
void func_021BC820(int color);
void func_021BC8EC(void);
void func_021BC924(void);
extern struct Ani *g_021DE504;
extern const u8 g_021D9FF8[];
extern unsigned char dat_021DE504[];


void func_021BC820(int color)
{
	u32 pal;
	Obj *o;
	g_021DE504 = func_021D6414(12, 4);
	g_021DE504->color = color;
	g_021DE504->obj = func_021D5368(0, 0x47);
	pal = g_021D9FF8[color];
	((Obj *)g_021DE504->obj)->h4 = (((Obj *)g_021DE504->obj)->h4 & ~0xc00) | 0x400;
	o = g_021DE504->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	((Obj *)g_021DE504->obj)->w0 = (((Obj *)g_021DE504->obj)->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
	g_021DE504->task = func_021D7680(1, func_021BC924, 0, 0x78);
}


void func_021BC8EC(void)
{
    unsigned char *g = (unsigned char *)0x021DE504;

    func_021D7744(1, (void *)(**(int **)g));
    func_021D6F38((unsigned int *)(*(int *)(*(int *)g + 4)));
    func_021D6438((void **)((int)dat_021DE504));
}


void func_021BC924(void)
{
	int name;
	u32 pal;
	Obj *o;
	g_021DE504->cnt = func_0207C994(g_021DE504->cnt + 1, 40);
	name = func_0207C958(g_021DE504->cnt, 5) + 0x47;
	func_021D52D4(0, name, g_021DE504->obj);
	((Obj *)g_021DE504->obj)->h4 = (((Obj *)g_021DE504->obj)->h4 & ~0xc00) | 0x400;
	pal = g_021D9FF8[g_021DE504->color];
	o = g_021DE504->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	((Obj *)g_021DE504->obj)->w0 = (((Obj *)g_021DE504->obj)->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
}
