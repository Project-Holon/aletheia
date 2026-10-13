/*
 * function: SCRCMD_PROC_FLD_PrintUniqueItemEntry
 * address:  0x021B45A0
 * packet:   pkt_ov021_021B45A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 *
 * symbols:
 *   BMP_MENULIST_GetUserData 0x02020D0C thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_GetWidth 0x020437DC arm
 *   SCRCMD_PROC_FLD_PrintListText 0x021B44CC thumb ov021
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
#include "../include/Obj00810.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 id;
    u16 pad;
    u32 v;
} Ent;

struct Bmp;
struct StrObj;
struct WordSet;
extern u32 BMP_MENULIST_GetUserData(u8 *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern void SCRCMD_PROC_FLD_PrintListText(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void SCRCMD_PROC_FLD_PrintUniqueItemEntry(u32 ctx, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)BMP_MENULIST_GetUserData((void *)ctx);
    if (a != -2) {
        if (func_02007F68((u8 *)(((struct Obj00810 *)w)->f10), ((Ent *)(w + 0x20))[a].id, 1, ((struct Obj00810 *)w)->f4) != 0) {
            lo = func_0201D304((struct StrObj *)(((struct Obj00810 *)w)->f1A0), ((struct Obj00810 *)w)->f8, 0);
            hi = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00810 *)w)->f16C)));
            SCRCMD_PROC_FLD_PrintListText((void *)(((struct Obj00810 *)w)->f1B0), (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00810 *)w)->f16C), hi - lo, b,
                          ((struct Obj00810 *)w)->f1A0, ((struct Obj00810 *)w)->f8, 0x31A0);
        } else {
            func_0201EFA4((struct WordSet *)(((struct Obj00810 *)w)->f190), 1, ((Ent *)(w + 0x20))[a].v, 5, 1, 1);
            func_0201F250((struct WordSet *)(((struct Obj00810 *)w)->f190), (void *)(((struct Obj00810 *)w)->f198), (void *)(((struct Obj00810 *)w)->f194));
            lo = func_0201D304((struct StrObj *)(((struct Obj00810 *)w)->f198), ((struct Obj00810 *)w)->f8, 0);
            hi = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00810 *)w)->f16C)));
            SCRCMD_PROC_FLD_PrintListText((void *)(((struct Obj00810 *)w)->f1B0), (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00810 *)w)->f16C), hi - lo, b,
                          ((struct Obj00810 *)w)->f198, ((struct Obj00810 *)w)->f8, 0x31A0);
        }
    }
}
