/*
 * file:     guru2_main_p06.c
 * unit:     yes
 * function: func_021DEAC8, func_021DEAE0, func_021DEB10, func_021DEB1C, func_021DEB40, func_021DEB74, func_021DEC08
 * address:  0x021DEAC8
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
 *   func_021E16D8  0x021E16D8  thumb
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_021E170C 0x021E170C thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 */
#include "../../matched/include/Obj10637.h"
#include "../../matched/include/Obj14220.h"
#include "../../matched/include/Obj01753.h"
#include "../../matched/include/Obj23744.h"
#include "../../matched/include/Obj02496.h"
#include "../../matched/include/Obj23746.h"
#include "../../matched/include/Obj14221.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int func_021E16D8(const char *p);
extern int func_021DCBC4(void *,int,void *,int);
extern int func_021E170C(char *);
extern int func_021841A4(unsigned char *p);
int func_021DEAC8(u8 *p);
int func_021DEAE0(char *p);
void *func_021DEB10(char *p);
int func_021DEB1C(char *p);
int func_021DEB40(char *p);
int func_021DEB74(u8 *p);
int func_021DEC08(char *p);


/*
 * Addresses are Black-image addresses.
 */
int func_021DEAC8(u8 *p)
{
    if (func_021E16D8((const char *)p)) {
        ((struct Obj10637 *)p)->f0 = 3;
        return 1;
    }
    return 0;
}

int func_021DEAE0(char *p) {u16 v=1;if(func_021DCBC4(((struct Obj14220 *)p)->fDC,0x2805,&v,2)==1){((struct Obj14220 *)p)->f0=4;return 1;}return 0;}


/*
 * extent: two trailing bytes of zero alignment padding.
 */
void *func_021DEB10(char *p) {return **(void ** *)&((struct Obj23744 *)(*(char * *)&((struct Obj01753 *)p)->fD8))->f14;}

int func_021DEB1C(char *p) {unsigned v;v=func_021E170C(p)+1;if(v!=func_021841A4(func_021DEB10(p)))return 0;((struct Obj01753 *)p)->f0=5;return 1;}

int func_021DEB40(char *p) {((struct Obj01753 *)p)->f30=func_021E170C(p)+1;if(func_021DCBC4(((struct Obj01753 *)p)->fDC,0x280A,p+48,4)==1){((struct Obj01753 *)p)->f14=0;((struct Obj01753 *)p)->f0=6;}return 0;}

int func_021DEB74(u8 *p)
{
    u16 buf[2];
    int i, count;
    u16 mask;
    if (((struct Obj02496 *)p)->f14 == 0) {
        buf[1] = 0; buf[0] = 0;
        if (func_021DCBC4(((struct Obj02496 *)p)->fDC, 10249, buf, 4) == 1) (((struct Obj02496 *)p)->f14)++;
        return 0;
    }
    i = 1;
    mask = ((struct Obj23746 *)(*(u8 * *)&((struct Obj02496 *)p)->fDC))->f42;
    for (count = 1; i < 5; i++) {
        if (mask & (1 << i)) {
            if (count >= ((struct Obj02496 *)p)->f14) {
                buf[1] = i; buf[0] = ((struct Obj02496 *)p)->f14;
                if (func_021DCBC4(((struct Obj02496 *)p)->fDC, 10249, buf, 4) == 1) (((struct Obj02496 *)p)->f14)++;
                break;
            }
            count++;
        }
    }
    if (((struct Obj02496 *)p)->f14 >= ((struct Obj02496 *)p)->f30) ((struct Obj02496 *)p)->f0 = 7;
    return 0;
}

int func_021DEC08(char *p) {u16 v=8;if(func_021DCBC4(((struct Obj14221 *)p)->fDC,0x2805,&v,2)==1)((struct Obj14221 *)p)->f0=10;return 0;}
