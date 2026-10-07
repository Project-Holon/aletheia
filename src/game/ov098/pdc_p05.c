/*
 * file:     pdc_p05.c
 * unit:     yes
 * function: func_021B6A00, func_021B6A3C, func_021B6B5C, func_021B6B68, func_021B6B74
 * address:  0x021B6A00
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6148 0x021B6148 thumb ov098
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6B8C 0x021B6B8C thumb ov098
 *   func_02045808 0x02045808 arm
 *   func_021B6C90 0x021B6C90 thumb ov098
 *   func_021B6CDC 0x021B6CDC thumb ov098
 *   func_0201CE20 0x0201CE20 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021B6C60  0x021B6C60  thumb  ov098
 */
#include "../../matched/include/Obj07936.h"
#include "../../matched/include/Obj00466.h"

struct MsgBank;
struct Rec3;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_021B6148(u8 *);
extern void func_0201F02C(void *,u32,void *);
extern void func_0201F250(void *,void *,void *);
extern void func_021B6B8C(int,int);
extern void func_02045808(void *);
extern void func_021B6C90(char *, int);
extern int func_021B6CDC(u8 *);
extern void func_0201CE20(void *);
extern u32 func_0201CE30(void *);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *);
extern void func_0201DD68(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021B6C60(char *p);
void func_021B6A00(u8 *p,u8 *q);
int func_021B6A3C(u8 *p);
void func_021B6B5C(char *p);
int func_021B6B68(char *p);
int func_021B6B74(unsigned char *p);

void func_021B6A00(u8 *p,u8 *q) { void *r; u32 t; r=func_02045EC0(((struct Obj07936 *)p)->f20,4); t=func_021B6148(q); func_0201F02C(((struct Obj07936 *)p)->f30,0,(void *)t); func_0201F250(((struct Obj07936 *)p)->f30,((struct Obj07936 *)p)->f2C,r); func_021B6B8C((int)p,80); func_02045808(r); }

int func_021B6A3C(u8 *p)
{
    switch (p[0x39]) {
    case 0:
        func_021B6C90((char *)p + 4, p[0x38]);
        p[0x39]++;
    case 1:
        if (!func_021B6CDC(p + 4)) break;
        if (p[0x38]) {
            p[0x39] = 6;
            break;
        }
        if (((struct Obj00466 *)p)->f0) func_0201CE20(((struct Obj00466 *)p)->f0);
        p[0x39]++;
    case 2:
        if (((struct Obj00466 *)p)->f0) {
            ((struct Obj00466 *)p)->f3C = func_0201CE30(((struct Obj00466 *)p)->f0);
            if (((struct Obj00466 *)p)->f3C) {
                p[0x39] = 3;
                if (((struct Obj00466 *)p)->f3C == 2) p[0x3a] = 1;
            }
        } else return 1;
        break;
    case 3:
        if ((func_020362DC() & 3) || func_02035C60()) ((struct Obj00466 *)p)->f40 = 0;
        if (((struct Obj00466 *)p)->f40) (((struct Obj00466 *)p)->f40)--;
        else p[0x39] = 5;
        break;
    case 4:
        if (((struct Obj00466 *)p)->f40) (((struct Obj00466 *)p)->f40)--;
        else p[0x39] = 5;
        break;
    case 5:
        if (((struct Obj00466 *)p)->f3C == 2) {
            func_0201DD68();
            func_0201CE48(*(struct Rec3 * *)&((struct Obj00466 *)p)->f0);
            ((struct Obj00466 *)p)->f0 = 0;
            p[0x39] = 6;
            return 1;
        } else {
            func_0201CE38(((struct Obj00466 *)p)->f0);
            p[0x39] = 2;
            ((struct Obj00466 *)p)->f40 = ((struct Obj00466 *)p)->f42;
        }
        break;
    case 6:
        return 1;
    }
    return 0;
}


void func_021B6B5C(char *p)
{
    func_021B6C60(p + 4);
}


int func_021B6B68(char *p)
{
    return func_021B6CDC((u8 *)(p + 4));
}

/*
 * notes:    test and clear flag byte at +0x3a, returns 1 if it was set. Witness for the call in ov098 func_021B6578 (2026-10-05, lane W-B).
 */
int func_021B6B74(unsigned char *p)
{
    if (p[0x3a]) {
        p[0x3a] = 0;
        return 1;
    }
    return 0;
}
