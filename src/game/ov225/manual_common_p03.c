/*
 * file:     manual_common_p03.c
 * unit:     yes
 * function: func_021BA508, func_021BA644, func_021BA65C, func_021BA740, func_021BA760, func_021BA898, func_021BA9D0, func_021BAA44, func_021BAA50, func_021BAA88
 * address:  0x021BA508
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   d_021BBF14 0x021BBF14 data a4
 *   func_02030734 0x02030734 arm
 *   d_021BC028 0x021BC028 data ov225 a1
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BB074 0x021BB074 thumb ov225
 *   func_021BB258 0x021BB258 thumb ov225
 *   func_0204B404 0x0204B404 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA068 0x021BA068 thumb ov225
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02028178 0x02028178 thumb
 *   func_021BAE2C 0x021BAE2C thumb ov225
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_021BAABC 0x021BAABC thumb ov225
 *   func_021BB034 0x021BB034 thumb ov225
 *   func_02028230 0x02028230 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   d_021BBF8C 0x021BBF8C data ov225 a2
 *   d_021BBF94 0x021BBF94 data ov225 a2
 *   func_020414AC 0x020414AC arm
 *   func_02027F60 0x02027F60 thumb
 *   func_02061CA4 0x02061CA4 arm
 *   func_021BB088 0x021BB088 thumb ov225
 *   func_020355C4 0x020355C4 arm
 *   func_02028218 0x02028218 thumb
 *   sub_02041B6C 0x02041B6C arm
 *   sub_0204B3B4 0x0204B3B4 arm
 *   sub_0204AFD8 0x0204AFD8 arm
 *   sub_0204A8D4 0x0204A8D4 arm
 *   sub_0204ADA4 0x0204ADA4 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02027FD8 0x02027FD8 thumb
 */
#include "../../matched/include/Obj00367.h"
#include "../../matched/include/Obj26178.h"
#include "../../matched/include/Obj00601.h"
#include "../../matched/include/Obj26179.h"
#include "../../matched/include/Obj26180.h"
#include "../../matched/include/Obj26181.h"
#include "../../matched/include/Obj26182.h"
#include "../../matched/include/Obj26183.h"
#include "../../matched/include/Obj26184.h"
#include "../../matched/include/Obj00074.h"
#include "../../matched/include/Obj14804.h"
#include "../../matched/include/Obj14805.h"
#include "../../matched/include/Obj26185.h"
#include "../../matched/include/Obj26186.h"
#include "../../matched/include/Obj26187.h"
#include "../../matched/include/Obj26188.h"
#include "../../matched/include/Obj26189.h"
#include "../../matched/include/Obj26190.h"
#include "../../matched/include/Obj26191.h"
#include "../../matched/include/Obj26192.h"
#include "../../matched/include/Obj26193.h"
#include "../../matched/include/Obj26194.h"
#include "../../matched/include/Obj26195.h"
#include "../../matched/include/Obj26196.h"
#include "../../matched/include/Obj26197.h"
#include "../../matched/include/Obj26198.h"
#include "../../matched/include/Obj26199.h"
#include "../../matched/include/Obj08470.h"
#include "../../matched/include/Obj14806.h"
#include "../../matched/include/Obj26200.h"

struct Obj;
struct Actor;
struct Node;
struct PrintSys;
struct R;
struct Work;
struct TaskMenuState;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021BA508;

struct Entry { u32_021BA508 first; u16 normal,pad6; u8 left,right,top,bottom; u32_021BA508 active,mask,sound,last; };

typedef signed short s16_021BA65C;

typedef unsigned int u32_021BA65C;

struct Vec2
{
  s16_021BA65C x;
  s16_021BA65C y;
};

struct Data
{
  void *owner;
  u16 heap;
  u16 pad6;
  char rest[48];
};

struct Work
{
  char *owner;
  struct Data *data;
  u32_021BA65C field8;
  void *a[8];
  void *b[8];
  u32_021BA65C field4c;
  void *res50;
  void *res54;
  void *res58;
  struct Obj *obj;
  void *arr60[8];
  void *task;
  u32_021BA65C field84;
  u32_021BA65C field88;
  u32_021BA65C field8c;
  signed char field90;
  u8 pad91[3];
  u32_021BA65C field94;
};

typedef unsigned int   u32_021BA740;

typedef unsigned int u32_021BA760;

typedef unsigned u32_021BA898;

struct Quad { short x,y,z,w; };

typedef short s16_021BAA44;

typedef unsigned int u32_021BAA44;

typedef short s16_021BAA50;

typedef unsigned int u32_021BAA50;

typedef short s16_021BAA88;

typedef unsigned int u32_021BAA88;

extern u32_021BA508 func_0204B3F4(struct Obj *);
extern u32_021BA508 func_0203633C(void);
extern void func_020355D8(u8);
extern u32_021BA508 func_02035D20(u32_021BA508 *,u32_021BA508 *);
extern void func_0204B878(struct Obj *,u16);
extern void func_020061E4(u32_021BA508);
extern u32_021BA508 func_0204B98C(struct Actor *);
extern void *func_02030734(u32_021BA65C, u32_021BA65C, int, const char *, u16);
extern void func_02041EE4(u32_021BA65C, u32_021BA65C, u32_021BA65C);
extern void func_0204B3DC(struct Obj *, u32_021BA65C);
extern u16 func_021BB074(u16 **);
extern u16 func_021BB258(void *, u16, u16);
extern void func_0204B404(struct Obj *, const struct Vec2 *, u32_021BA65C);
extern void *func_020056A0(u32_021BA65C, u32_021BA65C, u32_021BA65C);
extern void func_021BA068(char *, unsigned);
extern void func_02030EAC(struct Node *n);
extern u32_021BA740 func_020307B0(void *p);
extern u32_021BA760 func_0201C6B4(const struct PrintSys *);
extern void func_02028178(u8 *p);
extern int func_021BAE2C(char *);
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *);
extern unsigned func_021BA154(char *);
extern int func_021BAABC(char *);
extern u16 func_021BB034(u16 **);
extern u32_021BA760 func_02028230(u8 *);
extern void func_02049B68(void *,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u16);
extern u32_021BA898 func_02049658(void *a, u32_021BA898 b, u32_021BA898 c, u32_021BA898 d, u32_021BA898 e, u32_021BA898 f, u16 g);
extern u32_021BA898 func_020499D4(void *,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u16);
extern int func_0204AC18(void *,u32_021BA898,u32_021BA898,u32_021BA898,u16,u16,u16);
extern int func_0204A6C8(void *,u32_021BA898,u32_021BA898,u32_021BA898,u16);
extern int func_0204AF28(void *,u32_021BA898,u32_021BA898,u32_021BA898);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *p, u32_021BA898 v);
extern u32_021BA898 func_021B9A08(const u8 *p);
extern void func_020414AC(unsigned);
extern struct R *func_02027F60(u16, u16, unsigned, unsigned, u16);
extern int func_02061CA4(void *, unsigned, void *, int);
extern void func_021BB088(char *);
extern u8 func_020355C4(void);
extern void func_02028218(struct Obj *, unsigned);
extern void sub_02041B6C(u32_021BAA44);
extern void sub_0204B3B4(struct Obj *);
extern void sub_0204AFD8(u32_021BAA50);
extern void sub_0204A8D4(u32_021BAA50);
extern void sub_0204ADA4(u32_021BAA50);
extern void func_0201C6EC(struct PrintSys *);
extern void func_02028148(u8 *);
extern u32_021BAA88 func_02027FD8(struct TaskMenuState *s);
void func_021BA508(char *p);
void func_021BA644(char *p);
void *func_021BA65C(char *owner, struct Data *data);
void func_021BA740(char *p);
int func_021BA760(char *p);
void func_021BA894(void);
void func_021BA898(char *p);
void func_021BA9D0(char *p);
void func_021BAA44(struct Work *a0);
void func_021BAA50(char *p);
void func_021BAA88(char *p);
extern const struct Entry d_021BBF14[];
extern const char d_021BC028[];
extern const struct Quad d_021BBF8C,d_021BBF94;

void func_021BA508(char *p)
{
 u8 i;
 u32_021BA508 found,x,y;
 const struct Entry *row;
 switch(((struct Obj00367 *)p)->f44) {
 case 0:
  found=0;
  for(i=0;i<2;i++) {
   if(func_0204B3F4(*(struct Obj **)(p+i*4+0x38))) {
    row=&d_021BBF14[i];
    if(func_0203633C()&row->mask) {
     ((struct Obj00367 *)p)->f40=i;
     func_020355D8(0);
     found=1;
     break;
    }
    if(func_02035D20(&x,&y)) {
     if(row->left<=x && x<=row->right && row->top<=y && y<=row->bottom) {
      ((struct Obj00367 *)p)->f40=i;
      found=1;
      func_020355D8(1);
      break;
     }
    }
   }
  }
  if(found) {
   func_0204B878(*(struct Obj **)(p+((struct Obj00367 *)p)->f40*4+0x38),d_021BBF14[*(u8 *)(p+0x40)].active);
   if(d_021BBF14[*(u8 *)(p+0x40)].sound) func_020061E4(d_021BBF14[*(u8 *)(p+0x40)].sound);
   ((struct Obj00367 *)p)->f44=1;
  }
  break;
 case 1: ((struct Obj00367 *)p)->f44=2; break;
 case 2:
  if(!func_0204B98C(*(struct Actor **)(p+((struct Obj00367 *)p)->f40*4+0x38))) {
   func_0204B878(*(struct Obj **)(p+((struct Obj00367 *)p)->f40*4+0x38),d_021BBF14[*(u8 *)(p+0x40)].normal);
   ((struct Obj00367 *)p)->f44=3;
  }
  break;
 case 3: ((struct Obj00367 *)p)->f44=0; ((struct Obj00367 *)p)->f40=255; break;
 }
}


void func_021BA644(char *p)
{
    int z = 0;
    int m = z - 1;
    *(int *)(p + 0x20) = z;
    *(int *)(p + 0x24) = m;
    *(int *)(p + 0x28) = m;
    *(u8 *)(p + 0x40) = 0xFF;
    *(int *)(p + 0x44) = z;
}

void *func_021BA65C(char *owner, struct Data *data)
{
  struct Work *p;
  struct Vec2 v;
  u8 i;
  u32_021BA65C flag;
  u32_021BA65C state;
  int n;
  s16_021BA65C y;
  int mode;
  p = func_02030734(data->heap, 0x98, 1, d_021BC028, 0xdf);
  p->owner = owner;
  *((u32_021BA65C *) (owner + 0x10)) = 0;
  p->data = data;
  i = 0;
  do
  {
    p->a[i] = 0;
    p->b[i] = 0;
    i++;
  }
  while (i < 8);
  p->field94 = 0;
  func_021BA898((char *)p);
  func_021BAA44(p);
  func_02041EE4(5, 3, 12);
  flag = 0;
  if ((*((u16 *) (p->owner + 4))) > 6)
    flag = 1;
  func_0204B3DC(p->obj, flag);
  n = func_021BB074((u16 **) p);
  n = n + 1;
  y = func_021BB258(p, n, *((u16 *) (p->owner + 0xc)));
  v.x = 240;
  v.y = y;
  func_0204B404(p->obj, &v, 1);
  p->task = func_020056A0((u32_021BA65C) func_021BA894, (u32_021BA65C) p, 1);
  p->field84 = 0;
  p->field88 = 0;
  p->field8c = 0;
  p->field90 = -1;
  mode = *((int *) p->owner);
  state = 2;
  if (mode == 0)
    state = 1;
  else
    if (mode == 1)
    state = 2;
  func_021BA068(*((char **) (((char *) p->data) + 0x34)), state);
  return p;
}


void func_021BA740(char *p)
{
    func_02030EAC(((struct Obj26178 *)p)->f80);
    func_02041EE4(5, 3, 0);
    func_020307B0(p);
}

/*
 * extent: lead 308 bytes; empty callback at 021BA894 and two zero alignment bytes.
 * arity: 02028178 retains original r1 payload despite unused input in its body.
 */
int func_021BA760(char *p)
{
 u8 i;
 int result=0;
 unsigned selected;
 if(!func_0201C6B4(*(const struct PrintSys * *)&((struct Obj26179 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f14)) return 0;
 if(((struct Obj00601 *)p)->f90==0) result=1;
 else if(((struct Obj00601 *)p)->f90>0) {
  if(((struct Obj00601 *)p)->f90==1) func_021BAA50(p);
  (((struct Obj00601 *)p)->f90)--;
 }
 if(((struct Obj00601 *)p)->f84!=1) {
  for(i=0;i<8;i++) {
   if(*(u8 **)(p+i*4+0xc) && *(void **)(p+i*4+0x2c))
    func_02028178(*(u8 **)(p+i*4+0xc));
  }
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==2) {
  if(func_021BAE2C(p)) ((struct Obj00601 *)p)->f84=2;
  else ((struct Obj00601 *)p)->f84=0;
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==3) {
  func_021B9FBC(*(char * *)&((struct Obj26180 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34);
  if(((struct Obj00601 *)p)->f84==0) {
   if(func_021BA158(*(char * *)&((struct Obj26181 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34)!=(unsigned)-1) ((struct Obj00601 *)p)->f84=3;
  } else {
   selected=func_021BA154(*(char * *)&((struct Obj26182 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34);
   if(selected!=(unsigned)-1) {
    if(selected==1) ((struct Obj26183 *)(*(char * *)&((struct Obj00601 *)p)->f0))->f10=0;
    ((struct Obj00601 *)p)->f84=1;
    ((struct Obj00601 *)p)->f90=1;
   }
  }
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==4) {
  if(((struct Obj00601 *)p)->f84==0) {
   if(func_021BAABC(p)) ((struct Obj00601 *)p)->f84=4;
  } else {
   if(func_02028230(*(u8 **)(p+func_021BB034((u16 **)p)*4+0xc))) {
    ((struct Obj26184 *)(*(char * *)&((struct Obj00601 *)p)->f0))->f10=1;
    ((struct Obj00601 *)p)->f84=1;
    ((struct Obj00601 *)p)->f90=1;
   }
  }
 }
 return result;
}


void func_021BA894(void) {}

/*
 * Lever: index before 0x60 keeps field offset in immediate; distinct loop
 * parent local restores r7 parent / r6 destination allocation.
 */
void func_021BA898(char *p)
{
    struct Quad q[2];
    u8 i;
    char *parent;
    func_02049B68(((struct Obj26185 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,0,4,0,0x40,((struct Obj26186 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    func_02049658(((struct Obj26187 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,2,4,0,0,0,((struct Obj26188 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    func_020499D4(((struct Obj26189 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,5,4,0,0,0,0,((struct Obj26190 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f54=func_0204AC18(((struct Obj26191 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,1,1,0,0,1,((struct Obj26192 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f50=func_0204A6C8(((struct Obj26193 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,3,0,1,((struct Obj26194 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f58=func_0204AF28(((struct Obj26195 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,7,8,((struct Obj26196 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    q[1]=d_021BBF8C;
    parent=*(char * *)&((struct Obj00074 *)p)->f4;
    ((struct Obj00074 *)p)->f5C=func_0204B294((void *)func_021B9A08(((struct Obj14804 *)parent)->f8),((struct Obj00074 *)p)->f50,((struct Obj00074 *)p)->f54,((struct Obj00074 *)p)->f58,&q[1],1,((struct Obj14804 *)parent)->f4);
    func_0204B3DC(((struct Obj00074 *)p)->f5C,0);
    func_0204B92C(((struct Obj00074 *)p)->f5C,1);
    q[0]=d_021BBF94;
    for(i=0;i<8;i++) {
        char *loopparent;
        q[0].y=i*24-8;
        loopparent=*(char * *)&((struct Obj00074 *)p)->f4;
        *(void **)(p+i*4+0x60)=func_0204B294((void *)func_021B9A08(((struct Obj14805 *)loopparent)->f8),((struct Obj00074 *)p)->f50,((struct Obj00074 *)p)->f54,((struct Obj00074 *)p)->f58,&q[0],1,((struct Obj14805 *)loopparent)->f4);
        func_0204B3DC(*(void **)(p+i*4+0x60),0);
        func_0204B92C(*(void **)(p+i*4+0x60),1);
    }
    func_021BA9D0(p);
}

void func_021BA9D0(char *p)
{
    func_020414AC(5);
    *(struct R * *)&((struct Obj00074 *)p)->f8 = func_02027F60(5, 4, ((struct Obj26197 *)(*(char * *)&((struct Obj00074 *)p)->f4))->fC, ((struct Obj26198 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f14, ((struct Obj26199 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    ((struct Obj00074 *)p)->f4C = 0x1ce7;
    func_02061CA4((void *)31, 154, p + 0x4c, 2);
    func_02061CA4((void *)31, 186, p + 0x4c, 2);
    func_021BB088(p);
    if (func_020355C4() == 0) {
        func_02028218(*(struct Obj **)(p + func_021BB034((u16 **)p) * 4 + 0xc), 1);
        ((struct Obj00074 *)p)->f8C = 0;
    }
}


void func_021BAA44(struct Work *a0) { sub_02041B6C(4); }

void func_021BAA50(char *p) { u8 i; func_021BAA88(p); for(i=0;i<8;i++) sub_0204B3B4(*(struct Obj **)(p+i*4+0x60)); sub_0204B3B4(*(struct Obj * *)&((struct Obj08470 *)p)->f5C); sub_0204AFD8(((struct Obj08470 *)p)->f58); sub_0204A8D4(((struct Obj08470 *)p)->f50); sub_0204ADA4(((struct Obj08470 *)p)->f54); }

void func_021BAA88(char *p) { u8 i; func_0201C6EC(*(struct PrintSys * *)&((struct Obj26200 *)(*(char * *)&((struct Obj14806 *)p)->f4))->f14); for(i=0;i<8;i++) if(*(u8 **)(p+i*4+12)) func_02028148(*(u8 **)(p+i*4+12)); func_02027FD8(*(struct TaskMenuState * *)&((struct Obj14806 *)p)->f8); sub_02041B6C(5); }
