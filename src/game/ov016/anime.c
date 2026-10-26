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
 *   DWCi_TSKlDeleteEx   0x021D7744  arm
 *   DWCi_OBJlDelete   0x021D6F38  arm
 *   DWCi_HEAPlFree_   0x021D6438  arm
 *   FX_ModS32  0x0207C994  arm
 *   FX_DivS32  0x0207C958  arm
 *   DWCi_CEINlSet  0x021D52D4  arm  ov016
 */
#include "task.h"

#include "../types.h"

typedef struct {
	u32 w0;
	u16 h4;
} AnimeObj;

typedef struct Ani {
	TCB *task;
	void *obj;
	u8 color;
	u8 cnt;
} Ani;

#include "heap.h"
union GXOamAttr;
#include "cellinfo.h"
struct TCB;
#include "obj.h"
#include "../arm9/fx_cp.h"
void DWCi_ANIMElInitEx(int color);
void DWCi_ANIMElEnd(void);
extern struct Ani *gAnimeWork;
extern unsigned char gAnimeWorkSlot[];
extern const u8 sAnimePaletteByColor[];

static void taskAnime(void * unused0, void * unused1);

void DWCi_ANIMElInitEx(int color)
{
	u32 pal;
	AnimeObj *o;
	gAnimeWork = DWCi_HEAPlAllocEx(sizeof(*gAnimeWork), 4);
	gAnimeWork->color = color;
	gAnimeWork->obj = DWCi_CEINlSetExObj(0, 0x47);
	pal = sAnimePaletteByColor[color];
	((AnimeObj *)gAnimeWork->obj)->h4 = (((AnimeObj *)gAnimeWork->obj)->h4 & ~0xc00) | 0x400;
	o = gAnimeWork->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	((AnimeObj *)gAnimeWork->obj)->w0 = (((AnimeObj *)gAnimeWork->obj)->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
	gAnimeWork->task = DWCi_TSKlForm(1, taskAnime, 0, 0x78);
}

void DWCi_ANIMElEnd(void)
{
    DWCi_TSKlDeleteEx(1, gAnimeWork->task);
    DWCi_OBJlDelete((unsigned int *)gAnimeWork->obj);
    DWCi_HEAPlFree_((void **)(gAnimeWorkSlot));
}

static void taskAnime(void * unused0, void * unused1)
{
	int name;
	u32 pal;
	AnimeObj *o;
	gAnimeWork->cnt = FX_ModS32(gAnimeWork->cnt + 1, 40);
	name = FX_DivS32(gAnimeWork->cnt, 5) + 0x47;
	DWCi_CEINlSet(0, name, gAnimeWork->obj);
	((AnimeObj *)gAnimeWork->obj)->h4 = (((AnimeObj *)gAnimeWork->obj)->h4 & ~0xc00) | 0x400;
	pal = sAnimePaletteByColor[gAnimeWork->color];
	o = gAnimeWork->obj;
	o->w0 &= ~0xc00;
	o->h4 = (o->h4 & ~0xf000) | (pal << 12);
	((AnimeObj *)gAnimeWork->obj)->w0 = (((AnimeObj *)gAnimeWork->obj)->w0 & 0xfe00ff00) | 0x8b | 0xe60000;
}
