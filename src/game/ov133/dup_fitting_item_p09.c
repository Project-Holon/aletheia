/*
 * file:     dup_fitting_item_p09.c
 * unit:     yes
 * function: func_021B9784, func_021B9818, func_021B987C
 * address:  0x021B9784
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021B9C90 0x021B9C90 thumb ov133
 */
#include "../../matched/include/Obj06500.h"
#include "../../matched/include/Obj03826.h"
#include "../../matched/include/Obj00228.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef short s16;

typedef struct {s16 x,y;} Pos;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021B9C90(unsigned char *);
void func_021B9784(u8 *p);
void func_021B9818(u8 *p);
void func_021B987C(unsigned char *p);

void func_021B9784(u8 *p)
{
    Pos pos;
    u8 pal;
    pos.x=32;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    func_0204B404(((struct Obj06500 *)p)->f184C,(const struct Vec2 *)(&pos),0);
    pos.x=224;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    func_0204B404(((struct Obj06500 *)p)->f1850,(const struct Vec2 *)(&pos),0);
    pal=p[0x18c0]*24/60+4;
    if(pal>=11) pal=3;
    func_020413B0(2,10,44,12,12,pal);
    func_02041B6C(2);
}

void func_021B9818(u8 *p)
{
    unsigned i;
    ((struct Obj03826 *)p)->f183C=1;
    ((struct Obj03826 *)p)->f1844=0;
    p[0x1846]=1;
    i=5;
    do {
        if(*(int *)(*(u8 **)(p+(unsigned)i*4+0x1434)+12)!=1) break;
        i=(u16)(i+1);
        if(i==((struct Obj03826 *)p)->fA8) i=0;
    } while(i!=5);
    if(i==0) p[0x1847]=((struct Obj03826 *)p)->fA8-1;
    else p[0x1847]=i-1;
    ((struct Obj03826 *)p)->fC=0;
}

void func_021B987C(unsigned char *p) {((struct Obj00228 *)p)->f183C=0;((struct Obj00228 *)p)->fC=1;func_0204B3DC(((struct Obj00228 *)p)->f1854,0);func_021B9C90(p);}
