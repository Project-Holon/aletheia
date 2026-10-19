/*
 * file:     anime.c
 * unit:     yes
 * function: DWCi_ANIMElInitEx, DWCi_ANIMElEnd, taskAnime
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
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CEINlSetExObj  0x021D5368  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gAnimeWork  0x021DE504  data
 *   sAnimePaletteByColor  0x021D9FF8  data
 *   gAnimeWorkSlot    0x021DE504  data
 *   DWCi_TSKlDeleteByIndex   0x021D7744  arm
 *   DWCi_OBJlDelete   0x021D6F38  arm
 *   DWCi_HEAPlFree_   0x021D6438  arm
 *   FX_ModS32  0x0207C994  arm
 *   FX_DivS32  0x0207C958  arm
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
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

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_CEINlSetExObj(int a, int b);
struct TCB;
extern struct TCB *DWCi_TSKlForm(int kind, void (*fn)(void), void *work, u8 prio);
extern void DWCi_TSKlDeleteByIndex(u32 taskIdx, struct TCB *task);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_HEAPlFree_(void **mem);
extern int FX_ModS32(int a, int b);
extern int FX_DivS32(int a, int b);
extern void DWCi_CEINlSet(int a, int b, void *obj);
void DWCi_ANIMElInitEx(int color);
void DWCi_ANIMElEnd(void);
extern struct Ani *gAnimeWork;
extern unsigned char gAnimeWorkSlot[];
extern const u8 sAnimePaletteByColor[];

static void taskAnime(void);


void DWCi_ANIMElInitEx(int color)
{
	u32 pal;
	Obj *o;
	gAnimeWork = DWCi_HEAPlAllocEx(12, 4);
	gAnimeWork->color = color;
	gAnimeWork->obj = DWCi_CEINlSetExObj(0, 0x47);
	pal = sAnimePaletteByColor[color];
	((Obj *)gAnimeWork->obj)->h4 = (((Obj *)gAnimeWork->obj)->h4 & ~0xc00) | 0x400;
	o = gAnimeWork->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	((Obj *)gAnimeWork->obj)->w0 = (((Obj *)gAnimeWork->obj)->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
	gAnimeWork->task = DWCi_TSKlForm(1, taskAnime, 0, 0x78);
}


void DWCi_ANIMElEnd(void)
{
    unsigned char *g = (unsigned char *)0x021DE504;

    DWCi_TSKlDeleteByIndex(1, (void *)(**(int **)g));
    DWCi_OBJlDelete((unsigned int *)(*(int *)(*(int *)g + 4)));
    DWCi_HEAPlFree_((void **)((int)gAnimeWorkSlot));
}


static void taskAnime(void)
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
