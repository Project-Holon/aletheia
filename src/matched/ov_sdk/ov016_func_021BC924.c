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
 *   FX_ModS32  0x0207C994  arm
 *   FX_DivS32  0x0207C958  arm
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 *   gAnimeWork  0x021DE504  data
 *   sAnimePaletteByColor  0x021D9FF8  data
 */

#include "../include/G_Ani.h"

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

extern struct Ani *gAnimeWork;
extern u8 sAnimePaletteByColor[];

extern int FX_ModS32(int a, int b);
extern int FX_DivS32(int a, int b);
extern void DWCi_CEINlSet(int a, int b, void *obj);

void func_021BC924(void)
{
	int name;
	u32 pal;
	Obj *o;
	gAnimeWork->cnt = FX_ModS32(gAnimeWork->cnt + 1, 40);
	name = FX_DivS32(gAnimeWork->cnt, 5) + 0x47;
	DWCi_CEINlSet(0, name, gAnimeWork->obj);
	((Obj *)gAnimeWork->obj)->h4 = (((Obj *)gAnimeWork->obj)->h4 & ~0xc00) | 0x400;
	pal = sAnimePaletteByColor[gAnimeWork->color];
	o = gAnimeWork->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	((Obj *)gAnimeWork->obj)->w0 = (((Obj *)gAnimeWork->obj)->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
}
