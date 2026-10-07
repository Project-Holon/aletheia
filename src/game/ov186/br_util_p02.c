/*
 * file:     br_util_p02.c
 * unit:     yes
 * function: func_021FC868, func_021FC870
 * address:  0x021FC868
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 */
#include "../../matched/include/Obj10792.h"

struct Bmp;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {int x,y;} Pair;

extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
void func_021FC868(u8*p,u32 a,u32 b,u32 c);
void func_021FC870(int mode,Pair *base,const void *bmp,void *text,void *font,Pair *out);


void func_021FC868(u8*p,u32 a,u32 b,u32 c){((struct Obj10792 *)p)->f18=c;((struct Obj10792 *)p)->f1C=a;((struct Obj10792 *)p)->f20=b;}

/*
 * extent: two zero alignment bytes follow the 86-byte function.
 */
void func_021FC870(int mode,Pair *base,const void *bmp,void *text,void *font,Pair *out)
{
    unsigned x,y;
    switch(mode) {
    case 0:*out=*base;break;
    case 1:
        x=(unsigned)func_020437DC(bmp)>>1;y=(unsigned)func_020437E4(bmp)>>1;
        x-=func_0201D304(text,(unsigned)font,0)>>1;
        y-=func_0201D42C(text,font)>>1;
        out->x=x+base->x;out->y=y+base->y;break;
    }
}
