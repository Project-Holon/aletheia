/*
 * file:     pmsiv_wordwin_p09.c
 * unit:     yes
 * function: func_021BFE60, func_021BFED0, func_021BFF60
 * address:  0x021BFE60
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BFD94 0x021BFD94 thumb ov110
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 *   func_02040618 0x02040618 arm
 */
#include "../../matched/include/Obj06392.h"
#include "../../matched/include/Obj02166.h"

struct Vec2;
struct Descriptor;
struct Bmp;
typedef unsigned char u8;

typedef signed short s16;

typedef struct { s16 x, y; } Vec2;

typedef unsigned int   u32;

typedef unsigned short u16;

extern u32 func_021BFD94(u8 *p, struct Vec2 *out);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02040618(u32,u32,u32);
unsigned func_021BFE60(u8 *p, unsigned n);
void func_021BFED0(u8 *p,int amount);
void func_021BFF60(u8 *p);

unsigned func_021BFE60(u8 *p, unsigned n)
{
    int i;
    unsigned result;
    Vec2 pos;
    s16 y;
    func_021BFD94(p, (struct Vec2 *)(&pos));
    if (n == 0) goto zero;
    else {
        y = pos.y;
        do {
            if (y == 18) { result = 0; goto end; }
            else if (y == 149) result = n;
            else {
                for (i = 0; i <= n; i = (s16)(i + 1)) {
                    s16 lo, hi;
                    lo = 132 * (unsigned)i / (n + 1) + 18;
                    hi = 132 * (unsigned)(i + 1) / (n + 1) + 17;
                    if (lo > hi) hi = lo;
                    if (lo <= y && y <= hi) { result = (int)i; break; }
                }
            }
            goto end;
        } while (0);
        goto zero;
    }
    goto end;
zero: result = 0;
end:
    return result;
}

void func_021BFED0(u8 *p,int amount) {
    int start,end;
    if(amount>0) {
        start=(u8)(((struct Obj06392 *)p)->f94+192);
        end=(u8)(start+24*amount);
    } else {
        end=((struct Obj06392 *)p)->f94;
        start=(u8)(end+24*amount);
    }
    if(start<end) {
        func_02043AF4(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)start,(u16)208,(u16)(end-start),(u8)0);
    } else {
        func_02043AF4(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)start,(u16)208,(u16)(256-start),(u8)0);
        func_02043AF4(func_02045770((struct Descriptor *)((struct Obj06392 *)p)->fC),(s16)0,(s16)0,(u16)208,(u16)end,(u8)0);
    }
}

void func_021BFF60(u8 *p) { ((struct Obj02166 *)p)->f94=0; ((struct Obj02166 *)p)->f98=0; func_02040618(2,3,8); }
