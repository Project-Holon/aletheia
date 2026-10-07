/*
 * file:     guru2_main_p07.c
 * unit:     yes
 * function: func_021DEC38, func_021DEC64, func_021DEC84, func_021DECB0, func_021DECCC, func_021DECF4, func_021DED3C
 * address:  0x021DEC38
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_021E170C 0x021E170C thumb ov137
 *   func_021E16C4 0x021E16C4 thumb ov137
 *   func_020399A8 0x020399A8 arm
 *   func_0202F038 0x0202F038 thumb
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_021841A0 0x021841A0 thumb ov022
 *   func_0203D4D0 0x0203D4D0 arm
 *   func_021E17EC 0x021E17EC thumb ov137
 *   func_021E1910 0x021E1910 thumb ov137
 */
#include "../../matched/include/Obj10618.h"
#include "../../matched/include/Obj01753.h"
#include "../../matched/include/Obj10619.h"
#include "../../matched/include/Obj23747.h"
#include "../../matched/include/Obj10620.h"
#include "../../matched/include/Obj03304.h"

struct Entry;
struct Link;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern int func_021DCBC4(void *,int,void *,int);
extern int func_021E170C(char *);
extern int func_021E16C4(char *,int);
extern struct Entry *func_020399A8(void);
extern void func_0202F038(u8 *p);
extern void func_02039C68(struct Link *p, u32 lo, u32 hi);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern void *func_021DEB10(char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int func_021E17EC(char *p);
extern int func_021E1910(char *p);
int func_021DEC38(char *p);
int func_021DEC64(char *p);
int func_021DEC84(char *p);
int func_021DECB0(char *p);
int func_021DECCC(char *p);
int func_021DECF4(u8 *p);
int func_021DED3C(u8 *p);

int func_021DEC38(char *p) {if(func_021DCBC4(((struct Obj10618 *)p)->fDC,0x2806,0,0)==1){((struct Obj10618 *)p)->f0=9;((struct Obj10618 *)p)->f10=0;return 0;}return 0;}

int func_021DEC64(char *p) {if(func_021E16C4(p,8)==1){((struct Obj01753 *)p)->f30=func_021E170C(p)+1;((struct Obj01753 *)p)->f0=10;}return 0;}

int func_021DEC84(char *p) {void *v;v=func_020399A8();func_0202F038(((struct Obj10619 *)p)->fDA8);((struct Obj10619 *)p)->fDA8=0;func_02039C68(v,202,40);((struct Obj10619 *)p)->f0=11;return 0;}

int func_021DECB0(char *p) {if(func_02039CB4((struct Link *)func_020399A8(),202,40))((struct Obj23747 *)p)->f0=12;return 0;}

int func_021DECCC(char *p) {if(func_021DCBC4(((struct Obj10620 *)p)->fDC,0x280B,*(char * *)&((struct Obj10620 *)p)->fD8+4,4))((struct Obj10620 *)p)->f0=13;return 0;}

int func_021DECF4(u8 *p)
{
    void *q;
    q = func_020399A8();
    if ((int)func_0203D4D0((u32)q, (u8)((int)func_021841A0(func_021DEB10((char *)p))), (int)10255, (int)1428, (u32)(((struct Obj01753 *)p)->f24), (int)1, (int)1, (int)1))
        ((struct Obj01753 *)p)->f0 = 14;
    return 0;
}

int func_021DED3C(u8 *p)
{
    if (((struct Obj03304 *)p)->f30 == func_021E17EC((char *)p)) {
        if (func_021E1910((char *)p) == 1) {
            func_021DCBC4(((struct Obj03304 *)p)->fDC, 10253, 0, 0);
            ((struct Obj03304 *)p)->f0 = 45;
        } else {
            func_021DCBC4(((struct Obj03304 *)p)->fDC, 10254, 0, 0);
            ((struct Obj03304 *)p)->f0 = 15;
        }
    }
    return 0;
}
