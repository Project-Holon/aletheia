/*
 * file:     br_codein_p11.c
 * unit:     yes
 * function: func_021DD3F8, func_021DD440, func_021DD5C8
 * address:  0x021DD3F8
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DDF5C 0x021DDF5C thumb ov183
 *   func_021DDDE8 0x021DDDE8 thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02025588 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021DDCCC 0x021DDCCC thumb ov183
 *   func_021DDFA0 0x021DDFA0 thumb ov183
 *   func_021DD684 0x021DD684 thumb ov183
 *   func_021DD858 0x021DD858 thumb ov183
 *   func_021DDA2C 0x021DDA2C thumb ov183
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_0200DABC 0x0200DABC thumb
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021DE084 0x021DE084 thumb ov183
 *   d_021E3350 0x021E3350 data a4
 */
#include "../../matched/include/Obj06603.h"
#include "../../matched/include/Obj10732.h"
#include "../../matched/include/Obj00363.h"
#include "../../matched/include/Obj00731.h"
#include "../../matched/include/Obj00631.h"
#include "../../matched/include/Obj00632.h"

struct PrintSys;
struct S020315D4;
struct Blk1AC;
typedef unsigned int u32;

struct Pair { int x,y; };

typedef unsigned char  u8;

typedef unsigned short u16;

struct Record { u8 a, b, c, d; int value; };

struct Triple { int a, b, c; };

typedef signed short   s16;

extern void func_021DDF5C(char *, char *);
extern void func_021DDDE8(char *, char *);
extern void func_020409B4(unsigned int);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02025588(void *);
extern void func_020315D4(struct S020315D4 *);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021DDFA0(char *,int,int);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int,int,struct Pair *);
extern void func_021DDCCC(char *,char *);
extern void func_021DDDE8(char *,char *),func_021DD684(char *,char *),func_021DD858(char *,char *),func_021DDA2C(char *,char *);
extern void func_021F9BA0(unsigned *ctx);
extern int func_021FC830(u8 *p);
extern void func_021FD854(char *p);
extern void func_021FD1BC(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern u16 func_0200DABC(struct Blk1AC *p);
extern int func_021FC124(int, int, struct Triple *);
extern void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap);
int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p);
int func_021DD440(void *unused,u32 *state,char *q,char *p);
void func_021DD5C8(char *p, char *q);
extern const struct Record d_021E3350[];

int func_021DD3F8(struct S020315D4 *a, int unused, char *q, char *p)
{
    func_021DDF5C(p, q);
    func_021DDDE8(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FC0C8((char *)(((struct Obj06603 *)q)->f8), 13);
    func_021FD820(*(char * *)&((struct Obj10732 *)p)->f74);
    func_0201C4C0(((struct Obj10732 *)p)->f4);
    func_02025588(((struct Obj10732 *)p)->f0);
    func_020315D4(a);
    return 1;
}

/*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 */
int func_021DD440(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair pair;
 switch(*state){
 case 0:func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) *state=2;break;
 case 2:
  if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
   ((struct Obj00731 *)p)->f78=func_021DDFA0(p,x,y);
   if(((struct Obj00731 *)p)->f78) *state=3;
   if(func_021FB4B4((unsigned int *)(((struct Obj00731 *)p)->f20),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860(*(int *)&((struct Obj00731 *)p)->f74,1,&pair);
    *state=7;
   }
  }break;
 case 3:func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) ++*state;break;
 case 5:
  func_021DDDE8(p,q);
  switch(*(u32 *)&((struct Obj00731 *)p)->f78){
  case 1:func_021DD684(p,q);break;
  case 2:func_021DD858(p,q);break;
  case 3:func_021DDA2C(p,q);break;
  case 4:func_021DDCCC(p,q);break;
  }
  func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) *state=2;break;
 case 7:func_021FE784(*(int *)&((struct Obj00363 *)q)->f0,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int * *)&((struct Obj00363 *)q)->f0)) *state=9;break;
 case 9:func_021F9BA0(((struct Obj00363 *)q)->fC);return 1;
 }
 for(i=0;i<4;i++) if(*(void **)(p+i*4+0x24)) func_021FC830(*(void **)(p+i*4+0x24));
 for(i=0;i<16;i++) if(*(void **)(p+i*4+0x34)) func_021FC830(*(void **)(p+i*4+0x34));
 func_0201C4E4(((struct Obj00731 *)p)->f4);
 if(((struct Obj00731 *)p)->f1C)func_021FD1BC(((struct Obj00731 *)p)->f1C);
 func_021FD854(((struct Obj00731 *)p)->f74);
 return 0;
}

/*
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 */
void func_021DD5C8(char *p, char *q)
{
    int first, second, v;
    struct Triple triple;
    const struct Record *rec;
    u8 a, b, c, d;
    first = func_021FC20C(*(char * *)&((struct Obj00632 *)q)->f8);
    second = func_021FC214(*(char * *)&((struct Obj00632 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00632 *)q)->f8), 14, ((struct Obj00631 *)p)->f7C);
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    ((struct Obj00631 *)p)->f34 = func_021FC6A4(1, a, b, c, d, 14, ((struct Obj00631 *)p)->f4, ((struct Obj00631 *)p)->f7C);
    func_021FC868(((struct Obj00631 *)p)->f34, 0, 1, 0);
    func_021FC754(((struct Obj00631 *)p)->f34, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
    ((struct Obj00631 *)p)->f1C = func_021FD12C(*(int *)&((struct Obj00632 *)q)->f8, (void *)(*(int *)&((struct Obj00631 *)p)->f4), ((struct Obj00631 *)p)->f7C);
    func_021FD170(((struct Obj00631 *)p)->f1C, (char *)(*(int *)&((struct Obj00632 *)q)->f8), (void *)0x86);
    v = func_0200DABC((struct Blk1AC *)(((struct Obj00632 *)q)->f10));
    func_021FC124(*(int *)&((struct Obj00632 *)q)->f8, 13, &triple);
    func_021DE084((void *)(p + 8), (void *)(*(int *)&((struct Obj00632 *)q)->f4), (const char *)(&triple), v, 0x68, 0x58, ((struct Obj00631 *)p)->f7C);
}
