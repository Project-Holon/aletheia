/*
 * file:     demo3d_cmdsys_p05.c
 * unit:     yes
 * function: func_021BF7AC, func_021BF7C0
 * address:  0x021BF7AC
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021BF8E8 0x021BF8E8 thumb ov203
 *   func_021BF964 0x021BF964 thumb ov203
 *   d_021C3D4C 0x021C3D4C data a4
 */
#include "../../matched/include/Obj03917.h"
#include "../../matched/include/Obj25328.h"
#include "../../matched/include/Obj10867.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

struct Q { char pad[6]; unsigned short flag : 1; };

typedef struct {unsigned short heap,alternate;int config;int ended;int done;int previous;int index;char flags[4];char *owner;int task;int text;int assets;int extra;} Context;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021BF8E8(char *p);
extern int func_021BF964(char *p, char *owner, int *index);
int func_021BF7AC(char *p, int v);
Context *func_021BF7C0(char *owner,unsigned heap);
extern const char d_021C3D4C[];


int func_021BF7AC(char *p, int v)
{
    struct Q *q = *(struct Q * *)&((struct Obj25328 *)(*(char * *)&((struct Obj03917 *)p)->f1C))->f74;
    int flag = q->flag;

    if (flag == 1)
        v *= 2;
    return v;
}

Context *func_021BF7C0(char *owner,unsigned heap)
{
    Context *p;
    p=func_02030734(heap,0x30,1,d_021C3D4C,78);
    p->owner=owner;p->heap=heap;p->alternate=(heap&0x7FFF)|0x8000;
    p->config=((struct Obj10867 *)owner)->f78;p->previous=-1;
    func_021BF8E8((char *)p);
    p->ended=func_021BF964((char *)p,owner,&p->index);
    return p;
}
