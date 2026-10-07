/*
 * file:     br_codein_p14.c
 * unit:     yes
 * function: func_021DDE2C, func_021DDF5C, func_021DDFA0, func_021DE000, func_021DE02C, func_021DE058
 * address:  0x021DDE2C
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
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E336C 0x021E336C data a4
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   d_021E3440 0x021E3440 data a4
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_0200DBA0 0x0200DBA0 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 */
#include "../../matched/include/Obj00631.h"
#include "../../matched/include/Obj00632.h"
#include "../../matched/include/Obj14426.h"
#include "../../matched/include/Obj06603.h"
#include "../../matched/include/Obj10735.h"
#include "../../matched/include/Obj10736.h"
#include "../../matched/include/Obj00731.h"

struct Blk1AC;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

struct Position { short x,y,z;u8 a,b; };

struct Triple { int a,b,c; };

struct Record { u8 a,b,c,d;int value; };

typedef unsigned int u32;

typedef struct Rect { u32 x0, y0, x1, y1; } Rect;

typedef unsigned long long u64;

typedef signed int     s32;

extern void func_021FBE54(char *,unsigned,unsigned);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void *func_02082BCC(void *,int,unsigned);
extern int func_021FC124(int,int,struct Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD860(int, int, int *);
extern void func_020061E4(u32 a);
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *,int);
void func_021DDE2C(char *p,char *q);
void func_021DDF5C(char *p, char *q);
int func_021DDFA0(char *p, int x, int y);
int func_021DE000(void *p,char *q);
int func_021DE02C(void *p, void *q);
int func_021DE058(void *p, void *q);
extern const struct Record d_021E336C[];
extern const Rect d_021E3440[];

void func_021DDE2C(char *p,char *q)
{
 int first,second,i,id;
 struct Triple triple;
 struct Position pos;
 const struct Record *rec;
 char *slot;
 func_021FBE54(*(char * *)&((struct Obj00632 *)q)->f8,6,((struct Obj00631 *)p)->f7C);
 func_021FB964((void *)(*(int *)&((struct Obj00632 *)q)->f8),9,((struct Obj00631 *)p)->f7C);
 first=func_021FC20C(*(char * *)&((struct Obj00632 *)q)->f8);
 second=func_021FC214(*(char * *)&((struct Obj00632 *)q)->f8);
 func_02082BCC(&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 func_021FC124(*(int *)&((struct Obj00632 *)q)->f8,6,&triple);
 ((struct Obj00631 *)p)->f20=func_021FB378(&pos,4,0x60,1,*(int *)&((struct Obj00632 *)q)->f4,*(int *)&((struct Obj00631 *)p)->f0,first,second,&triple,((struct Obj00631 *)p)->f7C);
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];slot=p+i*4;
  ((struct Obj14426 *)slot)->f24=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00631 *)p)->f4,((struct Obj00631 *)p)->f7C);
  switch(i){
   case 0: if(func_021DE000((void *)(((struct Obj00632 *)q)->f10),(char *)(((struct Obj00632 *)q)->f14))) id=0x83;else id=0x7e;break;
   case 1: if(func_021DE02C((void *)(((struct Obj00632 *)q)->f10),(void *)(((struct Obj00632 *)q)->f14))) id=0x84;else id=0x7f;break;
   case 2: if(func_021DE058((void *)(((struct Obj00632 *)q)->f10),(void *)(((struct Obj00632 *)q)->f14))) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  func_021FC754(((struct Obj14426 *)slot)->f24,(void *)second,(void *)id,(void *)first,0x3da0);
 }
}

void func_021DDF5C(char *p, char *q)
{
    int i;
    char *slot;
    for (i = 0; i < 4; i++) {
        slot = p + i * 4;
        if (((struct Obj10736 *)slot)->f24) {
            func_021FC734(((struct Obj10736 *)slot)->f24);
            *(int *)&((struct Obj10736 *)slot)->f24 = 0;
        }
    }
    if (((struct Obj10735 *)p)->f20) {
        func_021FB494(((struct Obj10735 *)p)->f20);
        *(int *)&((struct Obj10735 *)p)->f20 = 0;
    }
    func_021FC0C8((char *)(((struct Obj06603 *)q)->f8), 6);
    func_021FBDA4(((struct Obj06603 *)q)->f8, 9);
}

int func_021DDFA0(char *p, int x, int y)
{
    int skip = ((struct Obj00731 *)p)->f78;
    int i;
    for (i = 0; i < 5; i++) {
        if (i != skip && (u32)(x - d_021E3440[i].x0) <= d_021E3440[i].x1 - d_021E3440[i].x0 &&
            (u32)(y - d_021E3440[i].y0) <= d_021E3440[i].y1 - d_021E3440[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            func_021FD860(*(int *)&((struct Obj00731 *)p)->f74, 1, args);
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}

int func_021DE000(void *p,char *q) { u32 a,b; a=func_0200DBA0(p,4,0); b=func_020142E8((void *)func_0201296C((const struct BigObj *)q),0x960); if(a && b) return 1; return 0; }

int func_021DE02C(void *p, void *q)
{
    int a = func_0200DBA0(p, 5, 0);
    unsigned b = func_020142E8((void *)func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}

int func_021DE058(void *p, void *q)
{
    int a = func_0200DBA0(p, 6, 0);
    unsigned b = func_020142E8((void *)func_0201296C(q), 0x960);
    if (a && b) return 1;
    return 0;
}
