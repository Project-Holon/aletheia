/*
 * function: DWCi_ANIMElInitEx
 * address:  0x021BC820
 * packet:   pkt_ov016_021BC820
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * EXACT at 204 bytes, 6/6 relocations.  The park's 73-byte residue (one
 * register too many: image `push {r4,r5,r6,lr}` with
 * `pal = sAnimePaletteByColor[color]` read into lr at +0040, the parked source
 * `push {r3,r4,r5,r6,r7,lr}` with the pal load sunk past the w0 store) closes
 * on the table's qualifier: with `extern const u8 sAnimePaletteByColor[]` the pal load
 * is hoisted above the obj stores, which frees the seventh register and the
 * whole body colours.  Body unchanged.
 *
 * sdk:      DWCi_ANIMElInitEx (libdwcutil.TWL.HYB.a(anime.o))
 *
 * T6: size-exact, 204 B both sides, 73 concrete diffs. First diff +0000:
 * object `push {r4,r5,r6,lr} / mov r6,r0 (color) / mov r4,#0`, this build
 * `push {r3,r4,r5,r6,r7,lr} / mov r4,r0 / mov r7,#0` - one register too many.
 * Consequence: the object reads pal = sAnimePaletteByColor[color] early (into lr, right
 * after the obj store, +0040) and this build sinks it past the w0 store. That
 * early pal load is what frees the extra register. Tried: declaration order
 * swapped, pal assigned before the obj call and right after the color store,
 * all four obj accesses through `gAnimeWork->obj` with no `o` local, `o`
 * cached from the obj assignment: 73 to 133 concrete diffs, size stays 204,
 * and all nine pins give 73.
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CEINlSetExObj  0x021D5368  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gAnimeWork  0x021DE504  data
 *   sAnimePaletteByColor  0x021D9FF8  data
 *   func_021BC924  0x021BC924  arm  ov016
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
extern const u8 sAnimePaletteByColor[];

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_CEINlSetExObj(int a, int b);
extern void *DWCi_TSKlForm(int a, void (*fn)(void), int b, int c);
extern void func_021BC924(void);

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
	gAnimeWork->task = DWCi_TSKlForm(1, func_021BC924, 0, 0x78);
}
