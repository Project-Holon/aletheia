/*
 * file:     zukan_detail_graphic_p10.c
 * unit:     yes
 * function: func_021BD74C, func_021BD764, func_021BD7E4, func_021BD7F8, func_021BD7FC, func_021BD808, func_021BD814
 * address:  0x021BD74C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 */
#include "../../matched/include/Obj18236.h"
#include "../../matched/include/Obj03928.h"
#include "../../matched/include/Obj18238.h"
#include "../../matched/include/Obj03065.h"

struct Obj;
struct Actor;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(char *, int, int);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021BD74C(char *p);
int func_021BD764(char *p);
int func_021BD7E4(int *p);
int func_021BD7F8(char *p);
void func_021BD7FC(struct Obj **p, unsigned int v);
void func_021BD808(int *p);
void func_021BD814(char *p, int v);


/*
 * Releases +0 and clears 0x38 bytes of the object.
 */
void func_021BD74C(char *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18236 *)p)->f0));
    func_02082BCC(p, 0, 0x38);
}

int func_021BD764(char *p)
{
    unsigned x,y;
    int hit=0;
    if(func_0204B3F4(((struct Obj03928 *)p)->f0)&((struct Obj03928 *)p)->f4) {
        if(func_02035D20(&x,&y) && x-((struct Obj03928 *)p)->f18<=((struct Obj03928 *)p)->f1C && y-((struct Obj03928 *)p)->f1A<=24) {
            hit=1;
            func_020355D8(1);
        }
        if(((struct Obj03928 *)p)->f2C && (func_020362DC()&((struct Obj03928 *)p)->f2C)) {
            func_020355D8(0);
            hit=1;
        }
        if(((struct Obj03928 *)p)->f34) {
            func_020355D8(0);
            hit=1;
        }
        if(hit) {
            (*(void (**)(char *))(p+0xc))(p);
            return 1;
        }
    }
    return 0;
}


/*
 * Returns 1 when the ARM9 call at 0x0204B98C on the word at [p] comes back zero.
 */
int func_021BD7E4(int *p)
{
    return func_0204B98C((struct Actor *)(*p)) == 0;
}



int func_021BD7F8(char *p)
{
    return ((struct Obj18238 *)p)->f14;
}


/*
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it and
 * the second argument.
 */
void func_021BD7FC(struct Obj **p, unsigned int v)
{
    func_0204B3DC(*p, v);
}


void func_021BD808(int *p)
{
    func_0204B3F4((struct Obj *)(*p));
}


void func_021BD814(char *p, int v)
{
    ((struct Obj03065 *)p)->f4 = v;
    if (v != 0) {
        if (((struct Obj03065 *)p)->f8 == ((struct Obj03065 *)p)->f28)
            ((struct Obj03065 *)p)->f8 = ((struct Obj03065 *)p)->f24;
        func_0204B878((struct Obj *)(((struct Obj03065 *)p)->f0), (unsigned short)((struct Obj03065 *)p)->f8);
    } else {
        func_0204B878((struct Obj *)(((struct Obj03065 *)p)->f0), ((struct Obj03065 *)p)->f26);
    }
}
