/*
 * file:     psel_graphic_p02.c
 * unit:     yes
 * function: func_021BB964, func_021BB974, func_021BB9A4, func_021BB9E0, func_021BBA78, func_021BBADC
 * address:  0x021BB964
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB630  0x021BB630  thumb  ov223
 *   func_021BB844  0x021BB844  thumb  ov223
 *   func_02082D44 0x02082D44 arm
 *   func_021BC3F0 0x021BC3F0 thumb ov223
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9740 0x021B9740 thumb ov223
 *   func_021B9830 0x021B9830 thumb ov223
 *   func_021BAAB8 0x021BAAB8 thumb ov223
 *   func_021BAE00 0x021BAE00 thumb ov223
 *   func_021BB38C 0x021BB38C thumb ov223
 *   func_02040EBC 0x02040EBC arm
 *   func_021B9854 0x021B9854 thumb ov223
 *   func_021BAB78 0x021BAB78 thumb ov223
 *   func_021BAC0C 0x021BAC0C thumb ov223
 *   func_021BB2A4 0x021BB2A4 thumb ov223
 *   func_0207D63C 0x0207D63C arm
 *   func_021B9914 0x021B9914 thumb ov223
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 */
#include "../../matched/include/Obj00084.h"
#include "../../matched/include/Obj00739.h"
#include "../../matched/include/Obj06729.h"
#include "../../matched/include/Obj01594.h"

struct GfFont;
typedef unsigned short u16;

typedef unsigned char  u8;

extern void func_021BB630(void *);
extern void func_021BB844(char *p);
extern void func_02082D44(const void *,void *,unsigned);
extern void *func_021BC3F0(int, int);
extern struct GfFont *func_0201D7EC(int, int, int, int, unsigned);
extern unsigned func_0201C440(void *);
extern void func_0204047C(int, u16);
extern void *func_020056A0(void (*)(void *, char *), void *, int);
extern void func_021B9740(void *, char *);
extern void func_021B9830(char *);
extern void func_021BAAB8(u16 *p);
extern void func_021BAE00(char *p);
extern void func_021BB38C(char *p);
extern void func_02040EBC(unsigned, unsigned);
extern void func_021B9854(u8 *p);
extern void func_021BAB78(u16 *p);
extern void func_021BAC0C(unsigned short *);
extern void func_021BB2A4(char *p);
extern void func_0207D63C(void *, unsigned, unsigned, unsigned, unsigned);
extern void func_021B9914(char *p);
extern void func_0204E720(unsigned, int, int, int);
extern int func_0204E804(void);
void func_021BB964(char *p);
void func_021BB974(unsigned char *p,unsigned index,int cmd);
void func_021BB9A4(unsigned char *p,int value);
int func_021BB9DC(void);
int func_021BB9E0(char *p);
int func_021BBA78(char *p);
int func_021BBADC(char *p, int *state);


void func_021BB964(char *p)
{
    func_021BB630(p);
    func_021BB844(p);
}

void func_021BB974(unsigned char *p,unsigned index,int cmd){switch(cmd){case 0:if(*(unsigned short *)((unsigned)p+212+index*148)!=0)*(unsigned short *)((unsigned)p+212+index*148)=3;break;case 2:if(*(unsigned short *)((unsigned)p+212+index*148)!=2)*(unsigned short *)((unsigned)p+212+index*148)=1;break;}}

/*
 * extent: copy helper followed by unlabelled return-one stub at 021BB9DC.
 */
void func_021BB9A4(unsigned char *p,int value){if(p[2161]!=value){((struct Obj00084 *)p)->f86C=1;p[2160]=0;p[2161]=value;func_02082D44(p+1898,p+1642,256);}}

int func_021BB9DC(void){return 1;}

int func_021BB9E0(char *p)
{
    ((struct Obj00739 *)p)->f14 = func_021BC3F0(1, ((struct Obj00739 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00739 *)p)->f18 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00739 *)p)->f0);
    ((struct Obj00739 *)p)->f1C = func_0201C440((void *)(unsigned)((struct Obj00739 *)p)->f0);
    func_0204047C(0, 2);
    func_0204047C(1, 3);
    func_0204047C(2, 1);
    func_0204047C(3, 0);
    func_0204047C(4, 3);
    func_0204047C(5, 2);
    func_0204047C(6, 1);
    func_0204047C(7, 0);
    ((struct Obj00739 *)p)->f20 = func_020056A0(func_021B9740, p, 1);
    ((struct Obj00739 *)p)->f24 = 0;
    func_021B9830(p);
    func_021BAAB8((u16 *)p);
    func_021BAE00(p);
    func_021BB38C(p);
    return 2;
}

int func_021BBA78(char *p)
{
    func_02040EBC(0, 0x2F3B);
    func_02040EBC(4, 0x2F3B);
    func_021B9854((u8 *)p);
    func_021BAB78((u16 *)p);
    func_021BAC0C((unsigned short *)p);
    func_021BB2A4(p);
    ((struct Obj06729 *)p)->f24 |= 2;
    ((struct Obj06729 *)p)->f268 = 0;
    func_0207D63C((void *)0x04000050, 5, 63,
                 ((struct Obj06729 *)p)->f268, 16 - ((struct Obj06729 *)p)->f268);
    ((struct Obj06729 *)p)->f10 = 0;
    return 3;
}

int func_021BBADC(char *p, int *state)
{
    if (*(unsigned *)&((struct Obj01594 *)p)->f10 >= 1)
        func_021B9914(p);
    switch (*state) {
    case 0:
        func_0204E720(3, 16, 0, 0);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0) {
            ((struct Obj01594 *)p)->f10 = 0;
            return 4;
        }
        break;
    }
    (((struct Obj01594 *)p)->f10)++;
    return 3;
}
