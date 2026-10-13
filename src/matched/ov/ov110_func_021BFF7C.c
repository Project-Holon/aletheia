/*
 * function: func_021BFF7C
 * address: 0x021BFF7C
 * packet: pkt_ov110_021BFF7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: retain scaled actor index and wrapped blit x across calls.
 * symbols:
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BF734 0x021BF734 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   CLACT_SetActorPos 0x0204B528 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF758 0x021BF758 thumb ov110
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_Blit 0x020439A0 arm
 */
#include "../include/Obj01533.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Pt { u16 x, y; };
struct Actor;
struct Obj;
struct Descriptor;
struct CharBuf;
struct Bmp;
extern u32 func_021BAC44(u8 *);
extern u32 func_021BF734(u8 *);
extern u8 func_021BF6DC(u8 *);
extern u16 func_021BF724(u8 *);
extern void CLACT_SetActorPos(struct Actor *, const struct Pt *);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_021BF758(u8 *p, u32 a, int b);
extern void GF_FONT_SetDefaultTextColor(void);
extern void *func_02045770(struct Descriptor *);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void BMP_Blit(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
void func_021BFF7C(u8 *p, u32 n, u32 y)
{
    u32 font;
    struct Pt pos;
    u32 wrap, x;
    struct Bmp *dest;
    font = func_021BAC44(*(u8 * *)&((struct Obj01533 *)p)->f0);
    if (n < 2 || n >= func_021BF734(*(u8 * *)&((struct Obj01533 *)p)->f4)) return;
    if (!func_021BF6DC(*(u8 * *)&((struct Obj01533 *)p)->f4) && func_021BF724(*(u8 * *)&((struct Obj01533 *)p)->f4) == 11) {
        x = 24 + 112 * ((n - 2) & 1);
        n = (n - 2) * 4;
        pos.x = x;
        pos.y = y - 8;
        p += 32;
        CLACT_SetActorPos(*(struct Actor **)(p + n), &pos);
        func_0204B3DC(*(struct Obj **)(p + n), 1);
        return;
    }
    func_021BF758(*(u8 * *)&((struct Obj01533 *)p)->f4, n - 2, (int)(((struct Obj01533 *)p)->f48));
    GF_FONT_SetDefaultTextColor();
    if (y <= 240) {
        PRINTSYS_Print(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 112 * ((n - 2) & 1), y, ((struct Obj01533 *)p)->f48, (void *)font);
    } else {
        wrap = 256 - y;
        BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10), 0);
        PRINTSYS_Print(func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10), 0, 0, ((struct Obj01533 *)p)->f48, (void *)font);
        n = 112 * ((n - 2) & 1);
        dest = func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10);
        BMP_Blit(dest, func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 0, 0, n, y, 96, wrap, 65535);
        dest = func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->f10);
        BMP_Blit(dest, func_02045770(*(struct Descriptor * *)&((struct Obj01533 *)p)->fC), 0, wrap, n, 0, 96, 16 - wrap, 65535);
    }
}
