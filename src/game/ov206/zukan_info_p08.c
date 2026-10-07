/*
 * file:     zukan_info_p08.c
 * unit:     yes
 * function: func_021BB9E0, func_021BBA7C
 * address:  0x021BB9E0
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC0B4 0x021BC0B4 thumb ov206
 *   func_021BC0B8 0x021BC0B8 thumb ov206
 *   func_021BC0CC 0x021BC0CC thumb ov206
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_021BBBD8 0x021BBBD8 thumb
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../../matched/include/Obj02542.h"
#include "../../matched/include/Obj00173.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef enum Flag { FLAG_ZERO=0,FLAG_ONE=1 } Flag;

struct State { u16 heap; char pad2[26]; int flag; char pad20[0x168]; unsigned array[2],index; char pad194[0x44]; unsigned owner; };

typedef signed int     s32;

typedef unsigned int   u32;

extern int func_021BC0B4(int);
extern int func_021BC0B8(int);
extern int func_021BC0CC(int);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_021BBBD8(struct S *p, int i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
void func_021BB9E0(struct State *p);
void func_021BBA7C(char *p);

void func_021BB9E0(struct State *p)
{
    u8 i;
    int flag;
    unsigned owner;
    i=0;
    for(;i<2;i++) p->array[i]=0;
    p->index=0;
    flag=0;
    if(p->flag) flag=1;
    owner=p->owner;
    ((struct Obj02542 *)p)->f17C=func_0204AC18((void *)owner,func_021BC0B4(p->flag),flag,160,0,1,p->heap);
    ((struct Obj02542 *)p)->f180=func_0204AF28((void *)owner,func_021BC0B8(0),func_021BC0CC(0),p->heap);
    ((struct Obj02542 *)p)->f184=func_0204AF28((void *)owner,func_021BC0B8(494),func_021BC0CC(494),p->heap);
}

void func_021BBA7C(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        func_021BBBD8((struct S *)p, i);
    }
    func_0204AFD8((u32)(((struct Obj00173 *)p)->f184));
    func_0204AFD8((u32)(((struct Obj00173 *)p)->f180));
    func_0204ADA4((u32)(((struct Obj00173 *)p)->f17C));
}
