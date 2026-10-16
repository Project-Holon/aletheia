/*
 * function: PLIST_PLATE_DrawHpBar
 * address:  0x021BAE94
 * packet:   pkt_ov091_021BAE94
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   PLIST_PLATE_GetHpBarColor  0x021BB554  thumb  ov091
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BGWINFRM_ScaleRatio  0x0202D01C  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_FillRect  0x02043AF4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj03183.h"
#include "../include/Obj20875.h"
#include "../include/Obj20876.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bmp;
extern int POKELIST_IsItemMode(u32 p);
extern u8 PLIST_PLATE_GetHpBarColor(u8 *s);
extern u32 POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);
extern u8 BGWINFRM_ScaleRatio(u32 a, u32 b, u32 c);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void PLIST_PLATE_DrawHpBar(u8 *a, u8 *s)
{
    u8 r;
    int x;
    int y;
    int h;
    u32 w;

    if (POKELIST_IsItemMode((u32)a) != 0)
        return;
    if (((struct Obj20876 *)(*(u8 * *)&((struct Obj20875 *)a)->f280))->f34 == 6)
        return;
    r = PLIST_PLATE_GetHpBarColor(s);
    h = BGWINFRM_ScaleRatio(((struct Obj03183 *)s)->f6, POKE_TOOL_GetPartyValue((void *)((struct Obj03183 *)s)->f0, 0xa1, 0), 0x30);
    w = (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj03183 *)s)->f20);
    if (r == 2 || r == 3) {
        x = 0xe;
        y = 0xf;
    } else if (r == 1) {
        x = 0xc;
        y = 0xd;
    } else {
        x = 0xa;
        y = 0xb;
    }
    BMP_FillRect((struct Bmp *)w, 0x3d, 0x1b, h, 1, x);
    BMP_FillRect((struct Bmp *)w, 0x3d, 0x1c, h, 1, y);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03183 *)s)->f38, 1);
}
