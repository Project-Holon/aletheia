/*
 * file:     zukan_detail_graphic_p03.c
 * unit:     yes
 * function: func_021BD330, func_021BD358, func_021BD35C, func_021BD360, func_021BD368, func_021BD378
 * address:  0x021BD330
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
 *   func_021BD7FC  0x021BD7FC  thumb
 *   func_021BD404 0x021BD404  thumb  ov208
 *   func_021BD814 0x021BD814  thumb  ov208
 */
#include "../../matched/include/Obj18229.h"
#include "../../matched/include/Obj18230.h"

struct Obj;
typedef unsigned int u32;

struct Ov208Mgr_021BD330 {
    u32 f0;
    u32 count;
};

struct Ov208Mgr_021BD360 {
    u32 pad0[4];
    u32 f10;
};

extern void func_021BD7FC(struct Obj **p, unsigned int v);
extern int func_021BD404(int, int);
extern void func_021BD814(char *p, int v);
void ov208_func_021BD330(struct Ov208Mgr_021BD330 *p, int v);
void func_021BD358(char *p, int v);
int func_021BD35C(char *p);
void ov208_func_021BD360(struct Ov208Mgr_021BD360 *p);
void func_021BD368(int a, int b, int c);
void func_021BD378(int a, int b, int c);


void ov208_func_021BD330(struct Ov208Mgr_021BD330 *p, int v)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        func_021BD7FC((void *)((u32)p + 0x28 + i * 0x38), v);
}



/*
 * Stores the second argument at +0xC.
 */
void func_021BD358(char *p, int v)
{
    ((struct Obj18229 *)p)->fC = v;
}



/*
 * Returns the word at +0xC (the two words after it are untraced continuations).
 */
int func_021BD35C(char *p)
{
    return ((struct Obj18230 *)p)->fC;
}


void ov208_func_021BD360(struct Ov208Mgr_021BD360 *p)
{
    p->f10 = 0;
}


void func_021BD368(int a, int b, int c)
{
    func_021BD814((char *)func_021BD404(a, b), c);
}


void func_021BD378(int a, int b, int c)
{
    func_021BD7FC((struct Obj **)func_021BD404(a, b), c);
}
