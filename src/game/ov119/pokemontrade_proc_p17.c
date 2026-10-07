/*
 * file:     pokemontrade_proc_p17.c
 * unit:     yes
 * function: func_021DC428, func_021DC458, func_021DC484, func_021DC494, func_021DC500, func_021DC538, func_021DC5D0
 * address:  0x021DC428
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_021E53F8 0x021E53F8 thumb ov119
 *   func_021E5430 0x021E5430 thumb ov119
 *   func_021E5680 0x021E5680 thumb ov119
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_021E4068 0x021E4068 thumb ov119
 *   func_02049B40 0x02049B40 arm
 *   func_021DF904 0x021DF904 thumb ov119
 *   func_021E58A0 0x021E58A0 thumb ov119
 *   func_021E467C 0x021E467C thumb ov119
 *   func_021E3F74 0x021E3F74 thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_0204A648 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_0201293C 0x0201293C thumb
 *   func_02012944 0x02012944 thumb
 *   func_02012934 0x02012934 thumb
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_02039338 0x02039338 arm
 *   func_02012950 0x02012950 thumb
 *   d_021E80B0 0x021E80B0 data a4
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22734.h"
#include "../../matched/include/Obj10356.h"
#include "../../matched/include/Obj08059.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_021E36D8(void *, int);
extern void func_02014BA8(u8 *a0);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_0203F8F4(u16 heapId);
extern void func_02045088(unsigned short);
extern void func_021E53F8(char *p);
extern void func_021E5430(void *);
extern void func_021E5680(char *p);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_021E4068(char *p);
extern void func_02049B40(int,int,int,int,int,int);
extern void func_021DF904(void *);
extern void func_021E58A0(void *);
extern void func_021E467C(void *);
extern void func_021E3F74(void *);
extern void func_021E3E80(void *);
extern void func_021E4420(void *);
extern void func_021E4E64(int,void *,int);
extern void func_0204A648(void);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern unsigned func_020173EC(void);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern int func_0201293C(void *);
extern int func_02012944(void *);
extern void *func_02012934(void *p);
extern int func_021D8A24(void *);
extern int func_02039338(void);
extern int func_02012950(void *,int);
extern u32 func_020307B0(void *p);
void func_021DC428(char *p);
void func_021DC458(char *p);
void func_021DC484(void *a0);
void func_021DC494(char *p);
void func_021DC500(int a, char *p);
void func_021DC538(char *p,void *q);
void func_021DC5D0(char *p, int a1);
extern char d_021E80B0[];

void func_021DC428(char *p)
{
    func_021E36D8(p, 0);
    func_021E36D8(p, 1);
    func_02014BA8(((struct Obj00001 *)p)->f840);
    ((struct Obj00001 *)p)->f840 = 0;
    func_02048AC4(((struct Obj00001 *)p)->f810);
    func_02046788();
}

void func_021DC458(char *p)
{
    func_0203F8F4(0x91);
    func_02045088(((struct Obj22734 *)p)->f5F4);
    func_021E53F8(p);
    func_021E5430(p);
    func_021E5680(p);
}

void func_021DC484(void *a0)
{
    func_0204A5AC();
    func_020450C8();
    func_0203F9B4();
}

void func_021DC494(char *p) {func_021E4068(p);func_02049B40(23,5,4,448,32,((struct Obj10356 *)p)->f5F4);func_021DF904(p);if(((struct Obj10356 *)p)->f118C<4)func_021E58A0(p);func_021E467C(p);func_021E3F74(p);func_021E3E80(p);func_021E4420(p);func_021E4E64(((struct Obj10356 *)p)->f828,p,0);}

void func_021DC500(int a, char *p)
{
    func_0204A648();
    if (((struct Obj08059 *)p)->f1084) {
        func_02040618(7, 0, ((struct Obj08059 *)p)->f108C);
        func_02040618(5, 0, ((struct Obj08059 *)p)->f108C);
        ((struct Obj08059 *)p)->f1084 = 0;
    }
}

void func_021DC538(char *p,void *q) {unsigned i;for(i=0;i<3;i++)*(int *)(p+0x1064+i*4)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0xfde);if(q){((struct Obj00001 *)p)->f82C=q;*(int *)&((struct Obj00001 *)p)->f828=func_0201293C(q);*(int *)&((struct Obj00001 *)p)->f830=func_02012944(q);((struct Obj00001 *)p)->f838=func_02012934(q);if(*(int *)&((struct Obj00001 *)p)->f834==0){if(func_021D8A24(p)){*(int *)&((struct Obj00001 *)p)->f834=func_02012950(q,1-func_02039338());return;}*(int *)&((struct Obj00001 *)p)->f834=func_02012950(q,1);}}}

void func_021DC5D0(char *p, int a1)
{
    unsigned i;
    for (i = 0; i < 3; i++)
        func_020307B0((void *)(*(int *)(p + i * 4 + 0x1064)));
}
