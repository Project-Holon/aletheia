/*
 * file:     br_codein_p33.c
 * unit:     yes
 * function: func_021E2C2C, func_021E2E30, func_021E2E48, func_021E2E60, func_021E2E70, func_021E2F54
 * address:  0x021E2C2C
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
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021D7540 0x021D7540 thumb ov125
 *   func_02082BCC 0x02082BCC arm
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   d_021E3910 0x021E3910 data a4
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3928 0x021E3928 data a4
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 */
#include "../../matched/include/Obj14443.h"
#include "../../matched/include/Obj14444.h"
#include "../../matched/include/Obj10762.h"
#include "../../matched/include/Obj14445.h"

struct Pair;
struct PrintSys;
struct U16Vec;
struct WordSet;
struct MsgBank;
typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct Pair_021E2C2C {int x,y;} Pair_021E2C2C;

typedef union Config {u64 wide;Pair_021E2C2C pair;} Config;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct Pair_021E2E60 {int a,b;} Pair_021E2E60;

typedef struct Table {int head[4];Pair_021E2E60 pair;} Table;

extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD860(int,int,Pair_021E2C2C *);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c);
extern void func_02082BCC(void *,int,unsigned);
extern u8 *func_0200B928(void);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32 a);
extern void func_021FD15C(void *,int);
extern int func_021FD744(int *a);
extern int func_021FC21C(char *);
extern int func_021FC214(char *);
extern unsigned func_021FC20C(char *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021FD19C(char *p, void *q, void *text);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(u16, unsigned, u16, u16, unsigned char, unsigned char, void *, u16);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
extern void func_021FC734(u8 *p);
extern void func_020409B4(u32 index);
extern void func_021FBDA4(int a, unsigned mode);
void func_021E2C2C(int *task,unsigned *state,char *p);
void func_021E2E30(char *p, int a1, int a2);
void func_021E2E48(char *p,int a,int b);
void func_021E2E60(Pair_021E2E60 *p);
void func_021E2E70(char *p, const char *q);
void func_021E2F54(char *p,char *q);
extern const Table d_021E3910;
extern const unsigned char d_021E3928[];

/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * lever: Write the zero halfwords in source order p+0x40 then p+0x42; the reversed spelling exchanged those two store addresses.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *     int i;
 *     u16 v;
 *     switch(selector) {
 *     case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *     case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *     case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *     case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *     case 4: return *(u64 *)(p+0x38);
 *     case 5: return *(u8 *)(p+0x2a);
 *     case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *     case 7: return *(u8 *)(p+0x2b);
 *     default:return 0;
 *     }
 * }
 */
void func_021E2C2C(int *task,unsigned *state,char *p)
{
    Pair_021E2C2C initial;
    Config cfg;
    int x,y;
    Pair_021E2C2C pair;
    int r;
    switch(*state) {
    case 0:
        if(!*(void **)(p+8)) *(void **)(p+8)=func_021FD12C(*(int *)(*(char **)(p+0x3c)+8),(void *)(*(int *)(p+4)),*(u16 *)(p+0x38));
        func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x13d);
        initial.x=0x80;initial.y=0x60;
        func_021FD860(*(int *)(p+0x30),4,&initial);
        func_021FE784(**(int **)(p+0x3c),2,3,0);++*state;break;
    case 1:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 2:
        *(int *)(p+0x44)=0;
        *(u16 *)(p+0x40)=0;*(u16 *)(p+0x42)=0;
        ++*state;break;
    case 3:
        r=func_021D7540((void *)(*(int *)(*(char **)(p+0x3c)+0x14)),*(int *)(p+0x10)+1,(unsigned char)(*(int *)(*(char **)(p+0x3c)+0x24)),(u16 *)(p+0x40),(u16 *)(p+0x42),*(u16 *)(p+0x38));
        if((unsigned)(r-2)<=1) {
            *(int *)(*(char **)(p+0x3c)+0x28)=1;
            *(int *)(*(char **)(p+0x3c)+0x2c)=*(int *)(p+0x10)+1;
            ++*state;
        }
        ++*(int *)(p+0x44);break;
    case 4:
        func_02082BCC(&cfg,0,8);
        cfg.wide=func_0200B98C(func_0200B928(),4,0);
        func_021FF54C(*(char **)(*(char **)(p+0x3c)+12),8,(const int *)(&cfg));
        func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x13f);
        *(int *)(p+0x48)=0;++*(int *)(p+0x44);++*state;break;
    case 5:
        ++*(unsigned *)(p+0x44);++*(unsigned *)(p+0x48);
        if(func_021FF648(*(char **)(*(char **)(p+0x3c)+12)) && *(unsigned *)(p+0x44)>0x60 && *(unsigned *)(p+0x48)>0x3c) {
            func_021FD860(*(int *)(p+0x30),0,0);
            func_021FD170(*(void **)(p+8),(char *)(*(int *)(*(char **)(p+0x3c)+8)),(void *)0x140);
            ++*state;
        }break;
    case 6:
        if(func_02035C60()) {
            func_02035D20((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            func_021FD860(*(int *)(p+0x34),1,&pair);
            func_020061E4((int)0x703);++*state;
        }break;
    case 7:func_021FE784(**(int **)(p+0x3c),2,3,1);++*state;break;
    case 8:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 9:
        if(*(void **)(p+8)) {func_021FD15C(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8));*(int *)(p+8)=0;}
        func_021FD744(task);break;
    }
}


void func_021E2E30(char *p, int a1, int a2)
{
    if (((struct Obj14443 *)p)->f0 != 0) {
        ((void (*)(int, int)) * (void **)p)(a1, a2);
        *(int *)&((struct Obj14443 *)p)->f0 = 0;
    }
}


void func_021E2E48(char *p,int a,int b) { void (*f)(int,int);f=*(void (**)(int,int))(p+4);if(f){f(a,b);*(int *)&((struct Obj14444 *)p)->f4=0;} }

void func_021E2E60(Pair_021E2E60 *p)
{
    *p=d_021E3910.pair;
}

/*
 * lever: Bounded permuter split the scaled index and delayed the base load, then introduced store-address temporaries after the constructor. Fixed one validated its behavior-preserving winning C.
 */
void func_021E2E70(char *p, const char *q)
{
  void *a;
  void *s;
  void *b;
  int h;
  int c;
  int i;
  const unsigned char *r;
  unsigned base;
  unsigned index;
  void **tmp;
  void **tmp1;
  char *tmp2;
  if (!(*((void **) (p + 8))))
    *((void **) (p + 8)) = func_021FD12C(*((int *) (q + 8)), (void *)(*((int *) (p + 4))), *((u16 *) (p + 0x38)));
  a = (void *) func_021FC21C(*((char **) (q + 8)));
  s = func_02045EC0((struct MsgBank *)func_021FC214(*((char **) (q + 8))), 0x141);
  b = func_020457B0(0x80, *((u16 *) (p + 0x38)));
  index = *((unsigned *) (p + 0x10));
  index = index * 4;
  base = *((unsigned *) (q + 0x18));
  func_0201EE0C(a, 0, (const void *)(*((unsigned *) ((base + index) + 0x14))), *((unsigned *) ((((unsigned) base) + index) + 0x24)), 1, 2);
  func_0201F250(a, b, s);
  func_021FD19C(*((void **) (p + 8)), (void *)(*((int *) (q + 8))), b);
  func_02045808(b);
  func_02045808(s);
  func_021FB964((void *)(*((int *) (q + 8))), 0x1e, *((u16 *) (p + 0x38)));
  h = func_021FC20C(*((char **) (q + 8)));
  c = func_021FC214(*((char **) (q + 8)));
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    tmp2 = p + 4;
    *((void **) ((p + (i * 4)) + 0x28)) = func_021FC6A4(4, r[0], r[1], r[2], r[3], 14, *((void **) tmp2), *((u16 *) (p + 0x38)));
    tmp1 = (void **) (0x28 + (p + (i * 4)));
    tmp = tmp1;
    func_021FC754(*tmp, (void *)c, (void *)(*((int *) (r + 4))), (void *)h, 0x3da0);
  }

}

void func_021E2F54(char *p,char *q)
{
    int i;
    for (i=0;i<2;i++) {
        if (*(void **)(p+i*4+0x28)) {
            func_021FC734(*(void **)(p+i*4+0x28));
            *(int *)(p+i*4+0x28)=0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(((struct Obj14445 *)q)->f8,0x1e);
    if (((struct Obj10762 *)p)->f8) {
        func_021FD15C(((struct Obj10762 *)p)->f8,((struct Obj14445 *)q)->f8);
        *(int *)&((struct Obj10762 *)p)->f8=0;
    }
}
