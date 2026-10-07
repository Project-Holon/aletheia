/*
 * file:     unit_021F8480_p06.c
 * unit:     yes
 * function: func_021F8EE8, func_021F8EFC, func_021F8F58, func_021F8F88, func_021F8FB0, func_021F8FC8, func_021F9008
 * address:  0x021F8EE8
 * region:   ov185
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FD640  0x021FD640  thumb  ov186
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD860   0x021FD860  thumb
 *   func_020061E4   0x020061E4  thumb
 */
#include "../../matched/include/Obj10772.h"
#include "../../matched/include/Obj00278.h"
#include "../../matched/include/Obj04584.h"
#include "../../matched/include/Obj24759.h"
#include "../../matched/include/Obj06624.h"
#include "../../matched/include/Obj14448.h"
#include "../../matched/include/Obj10773.h"
#include "../../matched/include/Obj24760.h"
#include "../../matched/include/Obj24761.h"
#include "../../matched/include/Obj24762.h"

struct Pair;
struct PrintSys;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021FD640(int *p);
extern u32 func_021FC4DC(u8 *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void *func_0200CA1C(void *a);
extern char *func_021FFBD4(void *owner, void *table, int a, int b, int c, int d, int e, unsigned short heap);
extern void func_021FFE5C(char *);
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern void func_020409B4(unsigned);
extern void func_021FD15C(void *,int);
extern void func_021FD860(int, int, int *);
extern void func_020061E4(u32 a);
void func_021F8EE8(char *p, int *a1);
void func_021F8EFC(char *p,int *source);
void func_021F8F58(char *p,char *q);
void func_021F8F88(char *p, int *q);
void func_021F8FB0(char *p, char *a1);
int func_021F8FC8(int a, int b, int c);
int func_021F9008(int a, int b, int c);


void func_021F8EE8(char *p, int *a1)
{
    if (((struct Obj10772 *)p)->f10 != 0) {
        func_021FD640((int *)(((struct Obj10772 *)p)->f10));
        ((struct Obj10772 *)p)->f10 = 0;
    }
}

void func_021F8EFC(char *p,int *source)
{
    if(*(int *)&((struct Obj00278 *)p)->f0==0) {
        int c=func_021FC4DC((u8 *)source[2]);
        char *result;
        if(*(int *)&((struct Obj00278 *)p)->f4==0)
            ((struct Obj00278 *)p)->f4=func_021FD12C((int)((void *)source[3]),(void *)(*(int *)&((struct Obj00278 *)p)->f2C),((struct Obj00278 *)p)->f30);
        func_021FD170(((struct Obj00278 *)p)->f4,(void *)source[3],(void *)0x2c);
        result=func_021FFBD4(func_0200CA1C((void *)source[6]),(void *)source[3],c,*(int *)&((struct Obj00278 *)p)->f28,source[0],((struct Obj00278 *)p)->f38,((struct Obj00278 *)p)->f3C,((struct Obj00278 *)p)->f30);
        *(char * *)&((struct Obj00278 *)p)->f0=result;
        func_021FFE5C(result);
    }
}

void func_021F8F58(char *p,char *q) { if(((struct Obj04584 *)p)->f0){func_021FFE70(((struct Obj04584 *)p)->f0);func_021FFC6C(((struct Obj04584 *)p)->f0);((struct Obj04584 *)p)->f0=0;func_020409B4(4);if(((struct Obj04584 *)p)->f4){func_021FD15C(((struct Obj04584 *)p)->f4,((struct Obj24759 *)q)->fC);((struct Obj04584 *)p)->f4=0;}} }

void func_021F8F88(char *p, int *q) { if(!((struct Obj06624 *)p)->f4)((struct Obj06624 *)p)->f4=func_021FD12C((int)(((struct Obj14448 *)q)->fC),(void *)(((struct Obj06624 *)p)->f2C),((struct Obj06624 *)p)->f30);func_021FD170(((struct Obj06624 *)p)->f4,((struct Obj14448 *)q)->fC,(void *)0x146); }


void func_021F8FB0(char *p, char *a1)
{
    if (((struct Obj10773 *)p)->f4 != 0) {
        func_021FD15C((void *)(((struct Obj10773 *)p)->f4), ((struct Obj24760 *)a1)->fC);
        ((struct Obj10773 *)p)->f4 = 0;
    }
}


/*
 * Range-gate the pair then hand them to 0x21FD860 as a two-word record.
 */
int func_021F8FC8(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x40) <= 0x78) & ((unsigned)(c - 0x10) <= 0x20);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        func_021FD860(((struct Obj24761 *)a)->f3C, 1, buf);
        func_020061E4(0x703);
    }
    return ok;
}


int func_021F9008(int a, int b, int c)
{
    int ok = ((unsigned)(b - 0x18) <= 0x28) & ((unsigned)(c - 0x40) <= 0x28);
    if (ok) {
        int buf[2];
        buf[0] = b;
        buf[1] = c;
        func_021FD860(((struct Obj24762 *)a)->f3C, 1, buf);
        func_020061E4(0x703);
    }
    return ok;
}
