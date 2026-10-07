/*
 * file:     br_codein_p15.c
 * unit:     yes
 * function: func_021DE084, func_021DE12C, func_021DE15C, func_021DE1C8, func_021DE234, func_021DE274, func_021DE3E4, func_021DE404, func_021DE55C, func_021DE66C, func_021DE780
 * address:  0x021DE084
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
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B878 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3358 0x021E3358 data a4
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021DE7C0 0x021DE7C0 thumb ov183
 *   func_021DE8FC 0x021DE8FC thumb ov183
 *   func_020409B4 0x020409B4 arm
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02025588 0x02025588 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021DE940 0x021DE940 thumb ov183
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
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   d_021E3574 0x021E3574 data a4
 *   d_021E3664 0x021E3664 data a4
 *   d_021E35D4 0x021E35D4 data a4
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../../matched/include/Obj05472.h"
#include "../../matched/include/Obj14427.h"
#include "../../matched/include/Obj14428.h"
#include "../../matched/include/Obj10737.h"
#include "../../matched/include/Obj24580.h"
#include "../../matched/include/Obj02519.h"
#include "../../matched/include/Obj06604.h"
#include "../../matched/include/Obj10738.h"
#include "../../matched/include/Obj00440.h"
#include "../../matched/include/Obj00785.h"
#include "../../matched/include/Obj14429.h"
#include "../../matched/include/Obj10739.h"
#include "../../matched/include/Obj10740.h"
#include "../../matched/include/Obj10741.h"
#include "../../matched/include/Obj08312.h"
#include "../../matched/include/Obj10742.h"
#include "../../matched/include/Obj10743.h"

struct Obj;
struct Actor;
struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
struct MsgBank;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef struct Position { s16 x, y, z; u8 a, b; } Position;

typedef unsigned int   u32;

struct Pair { int x,y; };

typedef struct Record {u8 a,b,c,d; u32 value;} Record;

typedef u16 Row[3];

extern void func_02082BCC(void *, int, unsigned int);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *func_02025538(unsigned int a0, void *a1);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021DE7C0(char *, char *);
extern void func_021DE8FC(char *, char *);
extern void func_020409B4(u32 index);
extern void func_021FD820(char *r5);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02025588(void *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021DE940(char *,int,int);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021FD860(int,int,struct Pair *);
extern void func_021F9BA0(unsigned *ctx);
extern int func_021FC830(u8 *p);
extern void func_021FD854(char *p);
extern void func_021FD1BC(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern u16 func_0200DFD8(Row *,int,int);
extern void *func_02045EC0(struct MsgBank *,u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_02045808(struct U16Vec *);
extern void func_021FC7C4(char *,void *,void *,u16);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_021FC734(u8 *p);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD15C(void *, int);
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap);
void func_021DE12C(char *p);
void func_021DE15C(char *p, u32 value);
int func_021DE1C8(void *a, int b, char *q);
int func_021DE234(void *a, int b, char *q, char *p);
int func_021DE274(void *unused,u32 *state,char *q,char *p);
void func_021DE3E4(char *p, char *q);
void func_021DE404(char *p,char *q);
void func_021DE55C(char *p,char *q);
void func_021DE66C(char *p,char *q);
void func_021DE780(char *p, char *q);
extern const u32 d_021E3358[];
extern const Record d_021E3574[];
extern const Record d_021E3664[];
extern const Record d_021E35D4[];

/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = x;` before `base = x + 20;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_021DE084(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap)
{
    Position pos;
    int base;
    int i;
    func_02082BCC(p, 0, 0x14);
    func_02082BCC(&pos, 0, 8);
    pos.x = x;
    pos.y = y;
    pos.z = 10;
    ((struct Obj14427 *)p)->f0 = func_0204B294(manager, (unsigned int)((struct Obj05472 *)q)->f4, (unsigned int)((struct Obj05472 *)q)->f8, (unsigned int)((struct Obj05472 *)q)->f0, &pos, 0, heap);
    func_0204B688(((struct Obj14427 *)p)->f0, 1);
    pos.z = 0;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        char *slot;
        pos.x = base + i * 16;
        pos.y = y;
        slot = p + i * 4;
        ((struct Obj14428 *)slot)->f4 = func_0204B294(manager, (unsigned int)((struct Obj05472 *)q)->f4, (unsigned int)((struct Obj05472 *)q)->f8, (unsigned int)((struct Obj05472 *)q)->f0, &pos, 0, heap);
        func_0204B688(((struct Obj14428 *)slot)->f4, 1);
    }
    func_021DE15C(p, value);
}

void func_021DE12C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10737 *)slot)->f4) {
            func_0204B3B4(((struct Obj10737 *)slot)->f4);
            ((struct Obj10737 *)slot)->f4 = 0;
        }
    }
    func_0204B3B4(((struct Obj24580 *)p)->f0);
    func_02082BCC(p, 0, 20);
}

void func_021DE15C(char *p, u32 value)
{
    u8 temp = value;
    int i;
    int j;
    if (temp != 0) {
        for (;;) {
            if (temp == 0) break;
            temp /= 10;
        }
    }
    for (i = 0; i < 4; i++) func_0204B878(*(void **)(p + i * 4 + 4), 0);
    for (j = 0; j < 4; j++)
        func_0204B878(*(void **)(p + (3 - j) * 4 + 4), value % d_021E3358[j + 1] / d_021E3358[j]);
}

int func_021DE1C8(void *a, int b, char *q)
{
    char *p = func_0203159C(a, 0x70, func_021F9B9C(((struct Obj06604 *)q)->fC));
    func_02082BCC(p, 0, 0x70);
    ((struct Obj02519 *)p)->f6C = func_021F9B9C(((struct Obj06604 *)q)->fC);
    ((struct Obj02519 *)p)->f0 = func_02025538(((struct Obj02519 *)p)->f6C, ((struct Obj06604 *)q)->f0);
    ((struct Obj02519 *)p)->f4 = (void *)func_0201C440((void *)(((struct Obj02519 *)p)->f6C));
    ((struct Obj02519 *)p)->f64 = func_021FD760((unsigned int)(((struct Obj06604 *)q)->f0), (char *)(((struct Obj06604 *)q)->f8), 1, ((struct Obj02519 *)p)->f6C);
    func_021DE3E4(p, q);
    func_021DE7C0(p, q);
    return 1;
}

int func_021DE234(void *a, int b, char *q, char *p)
{
    func_021DE780(p, q);
    func_021DE8FC(p, q);
    func_020409B4(4);
    func_020409B4(1);
    func_021FD820(((struct Obj10738 *)p)->f64);
    func_0201C4C0(((struct Obj10738 *)p)->f4);
    func_02025588(((struct Obj10738 *)p)->f0);
    func_020315D4(a);
    return 1;
}

int func_021DE274(void *unused,u32 *state,char *q,char *p)
{
 int x,y,i;
 struct Pair pair;
 switch(*state){
 case 0:func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,3,0);*state=1;break;
 case 1:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) *state=2;break;
 case 2:
  if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
   ((struct Obj00785 *)p)->f68=func_021DE940(p,x,y);
   if(((struct Obj00785 *)p)->f68) *state=3;
   if(func_021FB4B4((unsigned int *)(((struct Obj00785 *)p)->fC),x,y)){
    pair.x=x;pair.y=y;
    func_021FD860(*(int *)&((struct Obj00785 *)p)->f64,1,&pair);
    *state=7;
   }
  }break;
 case 3:func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,1,1);++*state;break;
 case 4:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) ++*state;break;
 case 5:
  func_021DE780(p,q);
  switch(*(u32 *)&((struct Obj00785 *)p)->f68){
  case 1:func_021DE404(p,q);break;
  case 2:func_021DE55C(p,q);break;
  case 3:func_021DE66C(p,q);break;
  }
  func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,1,0);++*state;break;
 case 6:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) *state=2;break;
 case 7:func_021FE784(*(int *)&((struct Obj00440 *)q)->f4,2,3,1);*state=8;break;
 case 8:if(func_021FE7B0(*(int * *)&((struct Obj00440 *)q)->f4)) *state=9;break;
 case 9:func_021F9BA0(((struct Obj00440 *)q)->fC);return 1;
 }
 for(i=0;i<3;i++) if(*(void **)(p+i*4+0x10)) func_021FC830(*(void **)(p+i*4+0x10));
 for(i=0;i<18;i++) if(*(void **)(p+i*4+0x1c)) func_021FC830(*(void **)(p+i*4+0x1c));
 func_0201C4E4(((struct Obj00785 *)p)->f4);
 func_021FD854(((struct Obj00785 *)p)->f64);
 if(((struct Obj00785 *)p)->f8)func_021FD1BC(((struct Obj00785 *)p)->f8);
 return 0;
}

void func_021DE3E4(char *p, char *q)
{
    ((struct Obj02519 *)p)->f8 = func_021FD12C(((struct Obj14429 *)q)->f8, (void *)(*(int *)&((struct Obj02519 *)p)->f4), ((struct Obj02519 *)p)->f6C);
    func_021FD170(((struct Obj02519 *)p)->f8, (char *)(((struct Obj14429 *)q)->f8), (void *)0x86);
}

/*
 * lever: declaring text before i/flag restores the original stack slots.
 */
void func_021DE404(char *p,char *q)
{
    int font, bank, words;
    struct U16Vec *text;
    int i, flag;
    const Record *rec;
    char *slot;
    void *base;
    font=func_021FC20C(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct Obj00440 *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct Obj00440 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00440 *)q)->f8),16,((struct Obj00785 *)p)->f6C);
    for(i=0;i<12;i++) {
        flag=1;
        rec=&d_021E3574[i];
        slot=p+i*4;
        ((struct Obj10739 *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        func_021FC868(((struct Obj10739 *)slot)->f1C,0,1,0);
        switch(i) {
        case 0: func_0201F02C((struct WordSet *)words,0,func_02012944(((struct Obj00440 *)q)->f10)); break;
        case 7: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,5,0),4,1,1); break;
        case 8: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,6,0),4,1,1); break;
        case 9: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,7,0),4,1,1); break;
        case 10: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,8,0),4,1,1); break;
        case 11: func_0201EFA4((struct WordSet *)words,0,func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,9,0),4,1,1); break;
        default: text=func_02045EC0((struct MsgBank *)bank,rec->value); flag=0; break;
        }
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=func_020457B0(128,((struct Obj00785 *)p)->f6C);
            func_0201F250((struct WordSet *)words,text,base);
            func_02045808(base);
        }
        func_021FC7C4(*(char * *)&((struct Obj10739 *)slot)->f1C,text,(void *)font,0x3da0);
        func_02045808(text);
    }
}

void func_021DE55C(char *p,char *q)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=func_021FC20C(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct Obj00440 *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct Obj00440 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00440 *)q)->f8),17,((struct Obj00785 *)p)->f6C);
    for(i=0;i<18;i++) {
        rec=&d_021E3664[i];
        slot=p+i*4;
        ((struct Obj10740 *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        func_021FC868(((struct Obj10740 *)slot)->f1C,0,1,0);
        if(i>=8 && i<=12) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-3,1);flag=1;}
        else if(i>=13 && i<=17) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-8,2);flag=1;}
        else {text=func_02045EC0((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=func_020457B0(128,((struct Obj00785 *)p)->f6C);
            func_0201EFA4((struct WordSet *)words,0,value,5,1,1);
            func_0201F250((struct WordSet *)words,text,base);
            func_02045808(base);
        }
        func_021FC7C4(*(char * *)&((struct Obj10740 *)slot)->f1C,text,(void *)font,0x3da0);
        func_02045808(text);
    }
}

void func_021DE66C(char *p,char *q)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=func_021FC20C(*(char * *)&((struct Obj00440 *)q)->f8);
    bank=func_021FC214(*(char * *)&((struct Obj00440 *)q)->f8);
    words=func_021FC21C(*(char * *)&((struct Obj00440 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj00440 *)q)->f8),17,((struct Obj00785 *)p)->f6C);
    for(i=0;i<18;i++) {
        rec=&d_021E35D4[i];
        slot=p+i*4;
        ((struct Obj10741 *)slot)->f1C=func_021FC6A4(1,rec->a,rec->b,rec->c,rec->d,14,((struct Obj00785 *)p)->f4,((struct Obj00785 *)p)->f6C);
        func_021FC868(((struct Obj10741 *)slot)->f1C,0,1,0);
        if(i>=8 && i<=12) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-8,1);flag=1;}
        else if(i>=13 && i<=17) {value=func_0200DFD8(*(Row * *)&((struct Obj00440 *)q)->f14,i-13,2);flag=1;}
        else {text=func_02045EC0((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=func_02045EC0((struct MsgBank *)bank,rec->value);
            text=func_020457B0(128,((struct Obj00785 *)p)->f6C);
            func_0201EFA4((struct WordSet *)words,0,value,5,1,1);
            func_0201F250((struct WordSet *)words,text,base);
            func_02045808(base);
        }
        func_021FC7C4(*(char * *)&((struct Obj10741 *)slot)->f1C,text,(void *)font,0x3da0);
        func_02045808(text);
    }
}

/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 */
void func_021DE780(char *p, char *q)
{
    int i;
    for (i = 0; i < 18; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10743 *)slot)->f1C != 0) {
            func_021FC734(((struct Obj10743 *)slot)->f1C);
            ((struct Obj10743 *)slot)->f1C = 0;
        }
    }
    func_021FBDA4(((struct Obj08312 *)q)->f8, 17);
    if (((struct Obj10742 *)p)->f8 != 0) {
        func_021FD15C(((struct Obj10742 *)p)->f8, ((struct Obj08312 *)q)->f8);
        ((struct Obj10742 *)p)->f8 = 0;
    }
}
