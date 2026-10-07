/*
 * file:     b_plist_main_p01.c
 * unit:     yes
 * function: func_0220F060, func_0220F138, func_0220F158, func_0220F1A4, func_0220F1F4, func_0220F22C, func_0220F2DC, func_0220F3E8, func_0220F478, func_0220F4E0, func_0220F65C, func_0220F698, func_0220F6C0, func_0220F7C4, func_0220F88C, func_0220F9F8, func_0220FB44, func_0220FCE0, func_0220FDD4, func_0220FED0, func_0220FFCC, func_022100A0, func_022100BC, func_022101AC, func_022101C0, func_022101D4, func_022101E8, func_022101FC, func_02210220, func_02210234, func_02210248, func_0221025C, func_02210290, func_022102A8, func_022102BC, func_0221034C, func_0221039C, func_022103B8, func_02210408, func_02210420, func_022104EC, func_022105E4, func_02210608, func_02210710, func_02210774
 * address:  0x0220F060
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E82C 0x0220E82C thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   sub_0201BD28 0x0201BD28 thumb
 *   d_02211DA0 0x02211DA0 data a4
 *   func_0204B898 0x0204B898 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0202D034 0x0202D034 thumb
 *   func_0204B8D4 0x0204B8D4 arm
 *   func_0220AF6C 0x0220AF6C thumb ov196
 *   func_0220AFDC 0x0220AFDC thumb ov196
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02030734 0x02030734 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_02210EFC 0x02210EFC thumb ov198
 *   d_02212550 0x02212550 data a1
 *   func_02211944 0x02211944 thumb ov198
 *   func_020310C4 0x020310C4 arm
 *   func_0220B7AC 0x0220B7AC thumb ov198
 *   func_0220E22C 0x0220E22C thumb ov198
 *   d_0221221C 0x0221221C data a4
 *   d_04001050 0x04001050 data a2
 *   func_0207D534 0x0207D534 arm
 *   sub_0203101C 0x0203101C arm
 *   func_0220AF40 0x0220AF40 thumb ov196
 *   func_02211034 0x02211034 thumb ov198
 *   func_0221099C 0x0221099C thumb ov198
 *   func_02210D4C 0x02210D4C thumb ov198
 *   func_0220B848 0x0220B848 thumb ov198
 *   func_0220BB94 0x0220BB94 thumb ov198
 *   func_0220E2B4 0x0220E2B4 thumb ov198
 *   func_0220EA68 0x0220EA68 thumb ov198
 *   func_0220BC24 0x0220BC24 thumb ov198
 *   func_0220BE2C 0x0220BE2C thumb ov198
 *   func_0220E25C 0x0220E25C thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   func_02211998 0x02211998 thumb ov198
 *   func_02210BFC 0x02210BFC thumb ov198
 *   func_0202173C 0x0202173C thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02211958 0x02211958 thumb ov198
 *   func_02210A4C 0x02210A4C thumb ov198
 *   func_02211128 0x02211128 thumb ov198
 *   func_02211970 0x02211970 thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 *   func_0220E13C 0x0220E13C thumb ov198
 *   func_0220E1D4 0x0220E1D4 thumb ov198
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02210E20 0x02210E20 thumb ov198
 *   func_02210ED4 0x02210ED4 thumb ov198
 *   func_02211844 0x02211844 thumb ov198
 *   func_022118F4 0x022118F4 thumb ov198
 *   func_02210B30 0x02210B30 thumb ov198
 *   func_02210F1C 0x02210F1C thumb ov198
 *   func_0220D6AC  0x0220D6AC  thumb  ov198
 *   func_02210C88  0x02210C88  thumb  ov198
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02211984  0x02211984  thumb  ov198
 *   func_0201F7A8 0x0201F7A8 thumb
 *   sub_0201C6B4 0x0201C6B4 thumb
 *   sub_0201C6EC 0x0201C6EC thumb
 *   func_020221B8 0x020221B8 thumb
 *   sub_0201CE48 0x0201CE48 thumb
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_0220E74C 0x0220E74C thumb ov198
 *   func_0220BE04 0x0220BE04 thumb ov198
 *   sub_02031140 0x02031140 arm
 *   func_022119E8 0x022119E8 thumb ov198
 *   func_0220AF64 0x0220AF64 thumb ov196
 *   sub_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203FC6C 0x0203FC6C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   sub_02041B6C 0x02041B6C arm
 *   sub_02043598 0x02043598 arm
 *   d_02212144 0x02212144 data a4
 *   d_02212174 0x02212174 data a4
 *   d_022121B4 0x022121B4 data a4
 *   d_02212154 0x02212154 data a4
 *   d_02212194 0x02212194 data a4
 *   func_02043598 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   sub_020490F4 0x020490F4 arm
 *   sub_02049658 0x02049658 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_0220B120 0x0220B120 thumb ov198
 *   func_0220B3B4 0x0220B3B4 thumb ov198
 *   func_02021640 0x02021640 thumb
 *   func_02049238 0x02049238 arm
 *   func_02021728 0x02021728 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../../matched/include/Obj10848.h"
#include "../../matched/include/Obj00172.h"
#include "../../matched/include/Obj02915.h"
#include "../../matched/include/Obj06654.h"
#include "../../matched/include/Obj01006.h"
#include "../../matched/include/Obj25225.h"
#include "../../matched/include/Obj00633.h"
#include "../../matched/include/Obj25226.h"
#include "../../matched/include/Obj25227.h"
#include "../../matched/include/Obj25228.h"
#include "../../matched/include/Obj25229.h"
#include "../../matched/include/Obj25231.h"
#include "../../matched/include/Obj14564.h"
#include "../../matched/include/Obj25232.h"
#include "../../matched/include/Obj04601.h"
#include "../../matched/include/Obj03907.h"
#include "../../matched/include/Obj03908.h"
#include "../../matched/include/Obj03349.h"
#include "../../matched/include/Obj10850.h"
#include "../../matched/include/Obj14565.h"
#include "../../matched/include/Obj08361.h"
#include "../../matched/include/Obj04602.h"
#include "../../matched/include/Obj14566.h"
#include "../../matched/include/Obj10851.h"
#include "../../matched/include/Obj03351.h"
#include "../../matched/include/Obj25233.h"
#include "../../matched/include/Obj25234.h"
#include "../../matched/include/Obj25235.h"
#include "../../matched/include/Obj08362.h"
#include "../../matched/include/Obj25236.h"
#include "../../matched/include/Obj14567.h"
#include "../../matched/include/Obj25237.h"
#include "../../matched/include/Obj25238.h"
#include "../../matched/include/Obj25239.h"
#include "../../matched/include/Obj25240.h"
#include "../../matched/include/Obj25241.h"
#include "../../matched/include/Obj25243.h"
#include "../../matched/include/Obj14568.h"
#include "../../matched/include/Obj25245.h"
#include "../../matched/include/Obj25246.h"
#include "../../matched/include/Obj02535.h"
#include "../../matched/include/Obj25247.h"
#include "../../matched/include/Obj25248.h"
#include "../../matched/include/Obj25249.h"
#include "../../matched/include/Obj25250.h"
#include "../../matched/include/Obj25251.h"
#include "../../matched/include/Obj25252.h"
#include "../../matched/include/Obj25253.h"
#include "../../matched/include/Obj02916.h"
#include "../../matched/include/Obj25254.h"
#include "../../matched/include/Obj25255.h"
#include "../../matched/include/Obj25256.h"
#include "../../matched/include/Obj25257.h"
#include "../../matched/include/Obj25258.h"
#include "../../matched/include/Obj06656.h"

struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Ctx;
struct Node;
struct Tcbl;
struct PrintSys;
struct MsgBank;
struct Sound;
struct Rec;
struct Rec3;
struct S02031140;
struct WinMgr;
struct PalAnmSlot;
struct GfFont;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct 
{
  u8 low : 6;
  u8 bit : 1;
  u8 high : 1;
} Flag_0220F060;

struct Bits { u8 low:3; u8 kind:4; u8 high:1; };

typedef struct {short x,y;} Pair;

typedef struct { u8 low:7; u8 high:1; } Flag_0220F7C4;

typedef signed short   s16;

typedef signed char    s8;

struct S {
    unsigned char pad[0x1eb0];
    int f1eb0;
    int f1eb4;
};

typedef signed int     s32;

struct Flag_0221039C {u8 low:7;u8 bit:1;};

struct BgVramReq {u32 unk00,unk04,unk08,unk0c;};

struct BgTemplate {
    u32 unk00,unk04,bufSize,unk0c;
    u8 unk10,unk11,unk12,unk13;
    u32 unk14;
    u8 unk18,unk19,unk1a,unk1b;
    u32 unk1c;
};

extern int func_022110D4(u8 *, int);
extern void func_0220E82C(char *p, void *obj, int index, int which);
extern void func_0220E7CC(u8 *, u32);
extern u32 sub_0201BD28(u16, u32);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(void *, int);
extern int func_0202D034(unsigned,unsigned);
extern void func_0204B8D4(struct Obj *p, u32 arg);
extern void func_0220AF6C(char *,int,int,int,int),func_0220AFDC(char *,void *);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern struct Node *func_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key);
extern int func_02210EFC(char **p);
extern void func_02211944(u8 **);
extern void func_020310C4(struct Tcbl *p);
extern void func_0220B7AC(u8 *);
extern void func_0220E22C(u8 *);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern struct Tcbl *sub_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u8 *func_0220AF40(u16 v);
extern void func_02211034(u8 *);
extern void func_0221099C(u8 *);
extern void func_02210D4C(u8 *,u32),func_0220B848(u8 *,u32),func_0220BB94(u8 *,u32);
extern void func_0220E2B4(char *),func_0220F060(u8 *),func_0220EA68(char *,u32),func_0220BC24(u8 *);
extern int func_0220BE2C(char *,int);
extern void func_0220E25C(u8 *);
extern u32 func_02210F04(u32,u32);
extern void func_02211998(u8 *,u32,u32),func_02210BFC(u8 *,int);
extern int func_0202173C(void *,u16,u16,short,u8,u8,u16,void *);
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_02021ED8(const char *);
extern u32 func_02211958(u8 **);
extern int func_02210A4C(u8 *);
extern int func_02211128(u8 *,u8 *,u8 *,int);
extern void func_02211970(u8 **,u32);
extern void func_0220B760(u8 *,u32);
extern void func_0220E13C(u8 *);
extern void func_0220E1D4(u8 *);
extern u32 func_02020FE4(void *,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_02025DE8(struct Sound *);
extern int func_02210E20(u8 *);
extern u8 func_02210ED4(u8 *);
extern int func_02211844(u8 *);
extern void func_022118F4(u8 *);
extern u32 func_02210F1C(u8 *p);
extern u8 func_02210B30(u8 *,int,int);
extern void func_0220D6AC(u8 *);
extern int func_02210C88(u8 *p, unsigned mode);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *p);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern void func_02211984(u8 **p, u32 b);
extern u32 sub_0201C6B4(const struct PrintSys *);
extern void sub_0201C6EC(struct PrintSys *);
extern void func_020221B8(void);
extern void sub_0201CE48(struct Rec3 *);
extern void func_0202CA0C(struct WinMgr *obj);
extern void func_0220E74C(char *);
extern void func_0220BE04(u8 *p);
extern void sub_02031140(struct S02031140 *);
extern u32 func_022119E8(u8 *);
extern void func_0220AF64(void *);
extern void sub_02030EAC(struct Node *);
extern u32 func_020307B0(void *p);
extern void func_0203FC6C(const struct BgVramReq *,u32);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void sub_02041B6C(u32);
extern void sub_02043598(u32,u32);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020403F4(u32 i);
extern void *sub_020490F4(u32 id, u32 heap);
extern u32 sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *,u32,u32,void **,u16);
extern void func_0220B120(char *,u16 *);
extern void func_0220B3B4(char *,u16 *);
extern void func_02021640(struct PalAnmSlot *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern int func_02021728(char *,int);
extern void func_02082D44(const void *,void *,u32);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_020216D4(struct PalAnmSlot *,u32,u32,u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_0201C450(u16,u32);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C4C0(struct PrintSys *);
extern void func_02045808(struct U16Vec *);
void func_0220F060(u8 *p);
void func_0220F138(void *a, int b);
int func_0220F158(char *p);
void func_0220F1A4(u8 *p);
void func_0220F1F4(u8 *p);
void func_0220F22C(u8 *p,int a,short delta);
void func_0220F2DC(char *p, int a1, int a2);
void func_0220F3E8(u8 *p);
void func_0220F478(void *task,u8 *p);
int func_0220F4E0(u8 *p);
int func_0220F65C(u8 *p);
int func_0220F698(u8 *p);
int func_0220F6C0(u8 *p);
int func_0220F7C4(u8 *p);
int func_0220F88C(u8 *p);
int func_0220F9F8(u8 *p);
int func_0220FB44(u8 *p);
int func_0220FCE0(u8 *p);
int func_0220FDD4(u8 *p);
int func_0220FED0(u8 *p);
int func_0220FFCC(u8 *p);
u32 func_022100A0(u8 *p);
int func_022100BC(u8 *p);
u32 func_022101AC(u32 a);
u32 func_022101C0(u32 a);
u32 func_022101D4(u32 a);
u32 func_022101E8(u32 a);
int func_022101FC(char *p);
u32 func_02210220(u32 a);
u32 func_02210234(u32 a);
u32 func_02210248(u32 a);
int func_0221025C(u8 *p);
u32 func_02210290(u8 *p);
u32 func_022102A8(u8 *p);
int func_022102BC(struct S *a);
int func_0221034C(char *p);
int func_0221039C(char *p);
int func_022103B8(char *p);
u32 func_02210408(u8 *p);
int func_02210420(struct Node *task,char *p);
void func_022104EC(u8 *p);
void func_022105E4(void);
void func_02210608(char *p);
void func_02210710(char *p);
void func_02210774(u8 *p);
extern u32 d_02211DA0[];
extern const char d_02212550[];
extern volatile u16 d_04001050[];
extern const struct BgVramReq d_02212144;
extern const struct BgTemplate d_02212174,d_022121B4,d_02212154,d_02212194;

void func_0220F060(u8 *p)
{
  u8 *rec;
  u8 *objects;
  int base;
  unsigned long offset;
  int i;
  u8 *entry;
  u8 *b;
  int slot;
  u8 *tmp;
  Flag_0220F060 *tmp1;
  tmp1 = (Flag_0220F060 *) (p + 0x2175);
  rec = (p + 4) + (func_022110D4(p, (*((u8 **) p))[32]) * 76);
  if (tmp1->bit == 0)
  {
    base = 29;
    slot = 12;
  }
  else
  {
    base = 34;
    slot = 17;
  }
  objects = p + (base * 4);
  for (i = 0; i < 4u; i++)
  {
    entry = rec + (i * 8);
    if ((*((u16 *) (entry + 44))) != 0)
    {
      offset = i * 4;
      b = objects + offset;
      func_0220E82C((char *)p, *((void **) (b + 0x1ebc)), slot + i, entry[48]);
      tmp = (u8 *) d_02211DA0;
      func_0220E7CC(*((u8 **) (b + 0x1ebc)), (u32) (tmp + offset));
    }
  }

  if (((*((u16 *) ((*((u8 **) p)) + 38))) != 0) && ((*((u8 **) p))[31] == 4))
  {
    offset = (base + i) * 4;
    b = p + 0x1ebc;
    func_0220E82C((char *)p, *((void **) (b + offset)), slot + i, sub_0201BD28(*((u16 *) ((*((u8 **) p)) + 38)), 0));
    func_0220E7CC(*((u8 **) (b + offset)), (u32) (d_02211DA0 + i));
  }
  ((Flag_0220F060 *) (p + 0x2175))->bit ^= 1;
}


void func_0220F138(void *a, int b)
{
    if (b != func_0204B898(a))
    {
        func_0204B8C4(a, 0);
        func_0204B878(a, b);
    }
}

int func_0220F158(char *p)
{
    u16 a=((struct Obj10848 *)p)->f10;
    if (a==0) return 0;
    if (((struct Bits *)(p+0x17))->kind!=8 && ((struct Bits *)(p+0x17))->kind!=6) return 5;
    if (a==((struct Obj10848 *)p)->f12) return 1;
    switch (func_0202D034(a,((struct Obj10848 *)p)->f12)) {
    case 0: return 2;
    case 1: return 3;
    case 2: return 4;
    }
    return 0;
}

void func_0220F1A4(u8 *p)
{
    u16 i;
    int j;
    for (i=0;i<6;i++) {
        j=func_022110D4(p,i);
        if (*(u16 *)(p+j*0x4c+8)) {
            int k=func_0220F158((char *)p+4+j*0x4c);
            func_0220F138(*(void **)(p+j*4+0x1ed8),k);
            func_0204B8D4(*(void **)(p+j*4+0x1ed8),0x1000);
        }
    }
}

void func_0220F1F4(u8 *p) { func_0220AF6C(*(char * *)&((struct Obj00172 *)p)->f2188,*(int *)&((struct Obj00172 *)p)->f1EB8,((struct Obj00172 *)p)->f2504,((struct Obj00172 *)p)->f251C,((struct Obj00172 *)p)->f2534);func_0220AFDC(*(char * *)&((struct Obj00172 *)p)->f2188,0); }

void func_0220F22C(u8 *p,int a,short delta)
{
    int i=func_022110D4(p,a);
    Pair pair;
    func_0204B454(*(void **)(p+0x1ebc+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1ebc+i*4),(const struct Vec2 *)(&pair),1);
    func_0204B454(*(void **)(p+0x1ed8+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1ed8+i*4),(const struct Vec2 *)(&pair),1);
    func_0204B454(*(void **)(p+0x1ef0+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1ef0+i*4),(const struct Vec2 *)(&pair),1);
    func_0204B454(*(void **)(p+0x1f08+i*4),(struct PtS *)&pair,1);
    pair.x+=delta;
    func_0204B404(*(void **)(p+0x1f08+i*4),(const struct Vec2 *)(&pair),1);
}


void func_0220F2DC(char *p, int a1, int a2)
{
    int i1 = func_022110D4((u8 *)p, a1);
    int i2 = func_022110D4((u8 *)p, a2);
    u32 x;
    u32 y;

    func_0204B454(((void **)(p + 0x1ebc))[i1], (struct PtS *)&x, 1);
    func_0204B454(((void **)(p + 0x1ebc))[i2], (struct PtS *)&y, 1);
    func_0204B404(((void **)(p + 0x1ebc))[i1], (const struct Vec2 *)(&y), 1);
    func_0204B404(((void **)(p + 0x1ebc))[i2], (const struct Vec2 *)(&x), 1);

    func_0204B454(((void **)(p + 0x1ed8))[i1], (struct PtS *)&x, 1);
    func_0204B454(((void **)(p + 0x1ed8))[i2], (struct PtS *)&y, 1);
    func_0204B404(((void **)(p + 0x1ed8))[i1], (const struct Vec2 *)(&y), 1);
    func_0204B404(((void **)(p + 0x1ed8))[i2], (const struct Vec2 *)(&x), 1);

    func_0204B454(((void **)(p + 0x1ef0))[i1], (struct PtS *)&x, 1);
    func_0204B454(((void **)(p + 0x1ef0))[i2], (struct PtS *)&y, 1);
    func_0204B404(((void **)(p + 0x1ef0))[i1], (const struct Vec2 *)(&y), 1);
    func_0204B404(((void **)(p + 0x1ef0))[i2], (const struct Vec2 *)(&x), 1);

    func_0204B454(((void **)(p + 0x1f08))[i1], (struct PtS *)&x, 1);
    func_0204B454(((void **)(p + 0x1f08))[i2], (struct PtS *)&y, 1);
    func_0204B404(((void **)(p + 0x1f08))[i1], (const struct Vec2 *)(&y), 1);
    func_0204B404(((void **)(p + 0x1f08))[i2], (const struct Vec2 *)(&x), 1);
}

void func_0220F3E8(u8 *p)
{
    u8 *q;
    if (p[0x20]>5) p[0x20]=0;
    q=func_02030734(((struct Obj02915 *)p)->f10,0x2544,1,d_02212550,0x130);
    func_02030DA8(((struct Obj02915 *)p)->f28,(unsigned)func_0220F478,(unsigned)q,100);
    *(u8 * *)&((struct Obj06654 *)q)->f0=p;
    if (p[0x1f]!=5) p[0x4b]=0;
    else if (func_02210EFC((char **)((unsigned)q))==1 && p[0x1c]==1) p[0x20]++;
    ((struct Obj06654 *)q)->f1D8=((struct Obj02915 *)p)->f2C;
    ((struct Obj06654 *)q)->f2178=0;
    q[0x2176]=p[0x20];
    ((struct Obj06654 *)q)->f2540=0;
}

extern int (*const d_0221221C[])(u8 *);

void func_0220F478(void *task,u8 *p)
{
    if (((struct Obj25225 *)(*(u8 * *)&((struct Obj01006 *)p)->f0))->f34==1) {
        func_02211944((u8 **)p);
        ((struct Obj01006 *)p)->f2178=33;
    }
    if (((struct Obj01006 *)p)->f2178!=33)
        ((struct Obj01006 *)p)->f2178=d_0221221C[*(int *)(p+0x2178)](p);
    if (((struct Obj01006 *)p)->f2178==33 && func_02210420(task,(char *)p)==1) return;
    func_020310C4(((struct Obj01006 *)p)->f1D4);
    func_0220F1A4(p);
    func_0220B7AC(p);
    func_0220E22C(p);
}

/*
 * volatile: hardware halfword store at 0220F4EC writes display register 04001050.
 */
int func_0220F4E0(u8 *p)
{
    d_04001050[0]=0;
    func_0207D534((u16 *)((u32)d_04001050+28),-16);
    ((struct Obj00633 *)p)->f1D4=sub_0203101C(((struct Obj25226 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,((struct Obj25227 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,1,4);
    if((*(u8 **)p)[31]==4) p[0x2180]=6;
    else if((*(u8 **)p)[31]==5) p[0x2180]=4;
    else p[0x2180]=0;
    ((struct Obj00633 *)p)->f2188=func_0220AF40(((struct Obj25228 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10);
    func_02211034(p);func_0221099C(p);func_022104EC(p);func_02210608((char *)p);func_02210710((char *)p);
    func_02210D4C(p,p[0x2180]);func_0220B848(p,p[0x2180]);func_0220BB94(p,p[0x2180]);
    func_0220E2B4((char *)p);
    if((*(u8 **)p)[31]==5) func_0220F060(p);
    func_0220EA68((char *)p,p[0x2180]);func_0220BC24(p);func_0220BE2C((char *)p,p[0x2180]);func_0220E25C(p);
    if(**(u8 * *)&((struct Obj25229 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f44==1) *(u32 *)&((struct Obj00633 *)p)->f218C=1;
    else *(u32 *)&((struct Obj00633 *)p)->f218C=0;
    func_0220AFDC((char *)(*(u8 * *)&((struct Obj00633 *)p)->f2188),((struct Obj00633 *)p)->f218C);
    if(p[0x2180]==0) {
        if(func_02210F04((u32)p,func_022110D4(p,0))==1) (*(u8 **)p)[32]=1;
        func_02211998(p,p[0x2180],(*(u8 **)p)[32]);
    } else if((*(u8 **)p)[31]==5) func_02211998(p,p[0x2180],(*(u8 **)p)[75]);
    else func_02211998(p,p[0x2180],0);
    func_02210BFC(p,p[0x2180]);
    func_0202173C(((struct Obj00633 *)p)->f1D8,10,65535,0,16,0,0,((struct Obj25231 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f28);
    ((struct Obj00633 *)p)->f2540=1;
    return 1;
}

int func_0220F65C(u8 *p) { if(func_0201C6B4(*(const struct PrintSys * *)&((struct Obj14564 *)p)->f1EAC)==1){func_0202208C((void *)4,1,1,0,6,1,((struct Obj25232 *)(*(u8 * *)&((struct Obj14564 *)p)->f0))->f10);return 2;}return 1; }

int func_0220F698(u8 *p) { if(func_020221A4()==1) { if((*(u8 **)p)[31]==4)return 25; if((*(u8 **)p)[31]==5)return 30; return 3; } return 2; }

int func_0220F6C0(u8 *p)
{
    u8 pair[2];
    if(func_02021ED8(*(char * *)&((struct Obj04601 *)p)->f1D8)!=0) return 3;
    if(func_02211958((u8 **)p)==1) return 31;
    if(func_02210A4C(p)==1) {
        if((*(u8 **)p)[32]==6) {
            if((*(u8 **)p)[31]==2) {
                if(func_02211128(p,pair+1,pair,1)==1) {
                    if(pair[1]<pair[0]) (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[1])[72]=255;
                    else (*(u8 * *)&((struct Obj04601 *)p)->f0+pair[0])[72]=255;
                    p[0x2499]=pair[1];
                    p[0x249a]=pair[0];
                    p[0x1e98]=0;
                    func_02211970((u8 **)p,1362);
                    return 9;
                }
            } else if((*(u8 **)p)[31]!=1) {
                func_02211970((u8 **)p,1362);
                func_0220B760(p,6);
                func_02211944((u8 **)p);
                return 31;
            }
        } else {
            func_02211970((u8 **)p,1357);
            func_0220B760(p,(*(u8 **)p)[32]);
            if((*(u8 **)p)[31]==3) return func_0220F7C4(p);
            ((struct Obj04601 *)p)->f217C=12;
            return 29;
        }
    }
    return 3;
}

int func_0220F7C4(u8 *p)
{
    u8 *q = *(u8 **)p;
    if (((Flag_0220F7C4 *)(p+func_022110D4(p,q[32])*76))[27].high != 0) {
        func_02045CAC(*(void **)(p+0x1ea0),91,*(void **)(p+0x1ea8));
        func_0220E13C(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        func_02211944((u8 **)p);
        return 23;
    }
    if ((q+func_022110D4(p,q[32]))[56] != 0) {
        func_0220E1D4(p);
        func_0220E13C(p);
        (*(u8 **)p)[32] = 6;
        *(u32 *)(p+0x217c) = 31;
        func_02211944((u8 **)p);
        return 23;
    }
    if (func_02020FE4((void *)*(u16 *)(q+36),39,*(u16 *)(q+16)) != 0 &&
        func_02020FE4((void *)*(u16 *)(q+36),40,*(u16 *)(q+16)) == 0) {
        *(u32 *)(p+0x217c) = 18;
        return 29;
    }
    q[72] = func_022110D4(p,q[32]);
    return 31;
}

int func_0220F88C(u8 *p)
{
    u32 sel;
    u8 *q;
    if(func_02211958((u8 **)p)==1) return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj03907 *)p)->f2184);
    switch(sel) {
    case 0:
        func_02211970((u8 **)p,1357);
        func_0220B760(p,7);
        if(func_02210E20(p)==1) {
            q=*(u8 * *)&((struct Obj03907 *)p)->f0;
            if(q[31]!=2) {
                (q+q[33])[72]=func_022110D4(p,q[32]);
                return 31;
            }
            if(func_02211844(p)==0) {func_022118F4(p);return 31;}
            ((struct Obj03907 *)p)->f217C=19;return 29;
        }
        ((struct Obj03907 *)p)->f217C=21;return 29;
    case 1:
        if(func_02210ED4(p)==1) break;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,8);
        ((struct Obj03907 *)p)->f217C=13;return 29;
    case 2:
        if(func_02210ED4(p)==1) break;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,10);
        ((struct Obj03907 *)p)->f217C=14;return 29;
    case 3:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj03907 *)p)->f217C=11;return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 4;
}

int func_0220F9F8(u8 *p)
{
    u32 sel;
    u8 next;
    if(func_02211958((u8 **)p)==1)return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj03908 *)p)->f2184);
    switch(sel){
    case 0:
        next=func_02210B30(p,(*(u8 **)p)[0x20],-1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            func_02211970((u8 **)p,1357);
            func_0220B760(p,12);
            ((struct Obj03908 *)p)->f217C=20;
            return 29;
        }
        break;
    case 1:
        next=func_02210B30(p,(*(u8 **)p)[0x20],1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            func_02211970((u8 **)p,1357);
            func_0220B760(p,13);
            ((struct Obj03908 *)p)->f217C=20;
            return 29;
        }
        break;
    case 2:
        func_02211970((u8 **)p,1357);
        func_0220B760(p,11);
        ((struct Obj03908 *)p)->f217C=14;
        return 29;
    case 3:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        p[0x2190]=1;
        ((struct Obj03908 *)p)->f217C=12;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        p[0x2190]=1;
        ((struct Obj03908 *)p)->f217C=12;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 5;
}

/*
 * Width: original narrows state to u8 before 0220B760; extern preserves caller truncation despite owner u32 state.
 */
int func_0220FB44(u8 *p)
{
    u32 sel;
    int row;
    u8 next;
    if(func_02211958((u8 **)p)==1)return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj03349 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        row=(u32)p+func_022110D4(p,(*(u8 **)p)[0x20])*0x4C;
        if(*(u16 *)(row+sel*8+0x30)!=0){
            func_02211970((u8 **)p,1357);
            func_0220B760(p,(u8)(sel+14));
            (*(u8 **)p)[0x4B]=sel;
            ((struct Obj03349 *)p)->f217C=15;
            return 29;
        }
        break;
    case 4:
        next=func_02210B30(p,(*(u8 **)p)[0x20],-1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            func_02211970((u8 **)p,1357);
            func_0220B760(p,(u8)12);
            ((struct Obj03349 *)p)->f217C=20;
            return 29;
        }
        break;
    case 5:
        next=func_02210B30(p,(*(u8 **)p)[0x20],1);
        if(next!=255){
            (*(u8 **)p)[0x20]=next;
            func_02211970((u8 **)p,1357);
            func_0220B760(p,(u8)13);
            ((struct Obj03349 *)p)->f217C=20;
            return 29;
        }
        break;
    case 6:
        func_02211970((u8 **)p,1357);
        func_0220B760(p,(u8)9);
        ((struct Obj03349 *)p)->f217C=13;
        return 29;
    case 7:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,(u8)6);
        p[0x2190]=2;
        ((struct Obj03349 *)p)->f217C=12;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,(u8)6);
        p[0x2190]=2;
        ((struct Obj03349 *)p)->f217C=12;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 6;
}

int func_0220FCE0(u8 *p)
{
    u32 sel;
    int row;
    if(func_02211958((u8 **)p)==1)return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj10850 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        if((*(u8 **)p)[0x4B]!=sel){
            row=(u32)p+func_022110D4(p,(*(u8 **)p)[0x20])*0x4C;
            if(*(u16 *)(row+sel*8+0x30)!=0){
                func_02211970((u8 **)p,1357);
                (*(u8 **)p)[0x4B]=sel;
                return 15;
            }
        }
        break;
    case 4:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj10850 *)p)->f217C=14;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj10850 *)p)->f217C=14;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 7;
}

int func_0220FDD4(u8 *p)
{
    u32 sel;
    int row;
    if(func_02021ED8(*(const char * *)&((struct Obj14565 *)p)->f1D8)!=0)return 30;
    if(func_02211958((u8 **)p)==1)return 31;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj14565 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3:
        if((*(u8 **)p)[0x4B]!=sel){
            row=(u32)p+func_022110D4(p,(*(u8 **)p)[0x20])*0x4C;
            if(*(u16 *)(row+sel*8+0x30)!=0){
                func_02211970((u8 **)p,1357);
                (*(u8 **)p)[0x4B]=sel;
                return 15;
            }
        }
        break;
    case 4:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        return 31;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        return 31;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 30;
}

int func_0220FED0(u8 *p)
{
    u32 sel;
    u8 value;
    if(func_02021ED8(*(const char * *)&((struct Obj08361 *)p)->f1D8)!=0)return 25;
    sel=func_02025DE8(*(struct Sound * *)&((struct Obj08361 *)p)->f2184);
    switch(sel){
    case 0: case 1: case 2: case 3: case 4:
        value=sel;
        (*(u8 **)p)[0x4B]=value;
        p[0x2191]=value;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,(u8)(sel+22));
        ((struct Obj08361 *)p)->f217C=17;
        return 29;
    case 5:
        func_02211970((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        func_0220B760(p,(u8)6);
        return 31;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        (*(u8 **)p)[0x4B]=4;
        func_0220B760(p,(u8)6);
        return 31;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 25;
}

int func_0220FFCC(u8 *p)
{
    u32 sel=func_02025DE8(*(struct Sound * *)&((struct Obj04602 *)p)->f2184);
    switch(sel){
    case 0:
        func_02211970((u8 **)p,1357);
        func_0220B760(p,27);
        if(func_02210F1C(p)==0)((struct Obj04602 *)p)->f217C=31;
        else ((struct Obj04602 *)p)->f217C=27;
        return 29;
    case 1:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        p[0x2192]=0;
        ((struct Obj04602 *)p)->f217C=16;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        p[0x2192]=0;
        ((struct Obj04602 *)p)->f217C=16;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 26;
}


/*
 * Addresses are Black-image addresses.
 */
u32 func_022100A0(u8 *p)
{
    func_0220D6AC(p);
    ((struct Obj14566 *)p)->f2193 = 1;
    ((struct Obj14566 *)p)->f217C = 0x1a;
    return 0x17;
}

/*
 * lever: bounded permuter expanded row use, cast the row/column sum to u32,
 *   and captured the byte selection in tmp before calling func_022110D4.
 * Caller truncates the selection+18 argument to u8 before func_0220B760.
 */
int func_022100BC(u8 *p)
{
    u32 selection=func_02025DE8(*(struct Sound * *)&((struct Obj10851 *)p)->f2184);
    u8 tmp;
    switch(selection) {
    case 0: case 1: case 2: case 3: {
        unsigned idx;
        u8 *row;
        tmp=(*(u8 **)p)[0x20];
        idx=func_022110D4(p,tmp);
        row=(u8 *)((u32)p+idx*0x4c);
        if(*(u16 *)((u32)((u32)((u8 *)((u32)p+idx*0x4c))+selection*8)+0x30)==0) break;
        (*(u8 **)p)[0x4b]=selection;
        (*(u8 **)p)[0x48]=idx;
        func_02211970((u8 **)p,1357);
        func_0220B760(p,(u8)(selection+18));
        return 31;
    }
    case 4:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj10851 *)p)->f217C=11;
        return 29;
    case (u32)-2:
        func_02211970((u8 **)p,1362);
        func_0220B760(p,6);
        ((struct Obj10851 *)p)->f217C=11;
        return 29;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5:
    case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 28;
}


u32 func_022101AC(u32 a)
{
    if (func_02210C88((u8 *)a, 0) == 0) {
        return 0xb;
    }
    return 0x3;
}


u32 func_022101C0(u32 a)
{
    if (func_02210C88((u8 *)a, 1) == 0) {
        return 0xc;
    }
    return 0x4;
}


u32 func_022101D4(u32 a)
{
    if (func_02210C88((u8 *)a, 2) == 0) {
        return 0xd;
    }
    return 0x5;
}


u32 func_022101E8(u32 a)
{
    if (func_02210C88((u8 *)a, 3) == 0) {
        return 0xe;
    }
    return 0x6;
}


int func_022101FC(char *p)
{
    if (func_02210C88((u8 *)p, 4) == 0)
    {
        return 0xf;
    }
    if (((struct Obj25233 *)((char *)((struct Obj03351 *)p)->f0))->f1F == 5)
    {
        return 0x1e;
    }
    return 7;
}


u32 func_02210220(u32 a)
{
    if (func_02210C88((u8 *)a, 6) == 0) {
        return 0x10;
    }
    return 0x19;
}


u32 func_02210234(u32 a)
{
    if (func_02210C88((u8 *)a, 7) == 0) {
        return 0x11;
    }
    return 0x1a;
}


u32 func_02210248(u32 a)
{
    if (func_02210C88((u8 *)a, 5) == 0) {
        return 0x12;
    }
    return 0x1c;
}

int func_0221025C(u8 *p) { func_0220EA68((char *)p,p[0x2180]);func_0220BE2C((char *)p,p[0x2180]);func_0220B848(p,p[0x2180]);func_02210BFC(p,p[0x2180]);if(p[0x2180]==2)return 5;return 6; }


u32 func_02210290(u8 *p)
{
    func_0220E13C(p);
    ((struct Obj25234 *)p)->f217C = 0x16;
    return 0x17;
}


u32 func_022102A8(u8 *p)
{
    func_0201F7A8((void *)(((struct Obj25235 *)p)->f1F68), 0);
    return 4;
}


int func_022102BC(struct S *a)
{
    switch (func_0201CE30((void *)a->f1eb0)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C((struct Rec *)a->f1eb0, 0);
        a->f1eb4 = 0;
        break;
    case 1:
        if (a->f1eb4 != 0)
            break;
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            func_02211984((u8 **)a, 0x547);
            func_0201CE38((void *)a->f1eb0);
            a->f1eb4 = 1;
        }
        break;
    case 2:
        func_0201CE48((struct Rec3 *)a->f1eb0);
        a->f1eb0 = 0;
        a->f1eb4 = 0;
        return 0x18;
    }
    return 0x17;
}

/*
 * remainder: separate conditional follower ov198_func_0221039C.c (28 bytes).
 */
int func_0221034C(char *p)
{
    if (func_02211958((u8 **)p)==1) return 0x1f;
    if ((func_020362DC()&3)!=0 || func_02035C60()==1) {
        if (((struct Obj08362 *)p)->f2193==1) {
            func_0201F7A8(((struct Obj08362 *)p)->f1F68,0);
            ((struct Obj08362 *)p)->f2193=0;
        }
        return ((struct Obj08362 *)p)->f217C;
    }
    return 0x18;
}

int func_0221039C(char *p)
{
    if (((struct Flag_0221039C *)(p+0x1e9b))->bit==0) return ((struct Obj25236 *)p)->f217C;
    return 0x1d;
}

int func_022103B8(char *p)
{
    if (func_02210EFC((char **)((unsigned)p))==1 && (*(u8 **)p)[0x20]!=6)
        (*(u8 **)p)[0x20]/=2u;
    func_0202173C(((struct Obj14567 *)p)->f1D8,10,0xffff,0,0,0x10,0,((struct Obj25237 *)(*(char * *)&((struct Obj14567 *)p)->f0))->f28);
    return 0x20;
}


u32 func_02210408(u8 *p)
{
    if (func_02021ED8((const char *)(((struct Obj25238 *)p)->f1D8)) == 0) {
        return 0x21;
    }
    return 0x20;
}

int func_02210420(struct Node *task,char *p)
{
    if(((struct Obj01006 *)p)->f2540==1) {
        if(sub_0201C6B4(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC)==0) {
            if(((struct Obj25239 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) sub_0201C6EC(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC);
            else return 0;
        }
        if(func_020221A4()==0) {
            if(((struct Obj25240 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) func_020221B8();
            else return 0;
        }
        if(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0) sub_0201CE48(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0);
        if(*(struct Obj * *)&((struct Obj01006 *)p)->f2194) func_0202CA0C((struct WinMgr *)(*(struct Obj * *)&((struct Obj01006 *)p)->f2194));
        func_02210774((u8 *)p);
        func_0220E74C(p);
        func_0220BE04((u8 *)p);
        func_022105E4();
        sub_02031140(*(struct S02031140 * *)&((struct Obj01006 *)p)->f1D4);
        func_022119E8((u8 *)p);
        func_0220AF64(((struct Obj01006 *)p)->f2188);
        if(((struct Obj01006 *)p)->f218C==1) **(u8 * *)&((struct Obj25241 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=1;
        else **(u8 * *)&((struct Obj25243 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=0;
    }
    (*(u8 **)p)[0x4c]=1;
    sub_02030EAC(task);
    func_020307B0(p);
    return 1;
}

void func_022104EC(u8 *p)
{
    struct BgVramReq req=d_02212144;
    struct BgTemplate cfg7,cfg6,cfg5,cfg4;
    func_0203FC6C(&req,1);
    cfg7=d_02212174;
    func_0203FCA0(7,&cfg7,0);
    cfg6=d_022121B4;
    func_0203FCA0(6,&cfg6,0);
    cfg5=d_02212154;
    func_0203FCA0(5,&cfg5,0);
    func_020414EC(5);
    cfg4=d_02212194;
    func_0203FCA0(4,&cfg4,0);
    func_020414EC(4);
    func_02040B94(5,32,0,((struct Obj25245 *)(*(u8 * *)&((struct Obj14568 *)p)->f0))->f10);
    func_02040B94(4,32,0,((struct Obj25246 *)(*(u8 * *)&((struct Obj14568 *)p)->f0))->f10);
    sub_02041B6C(5);
    sub_02041B6C(4);
    sub_02043598(15,1);
}


void func_022105E4(void)
{
    func_02043598(0x1f, 0);
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}

void func_02210608(char *p)
{
    void *owner=sub_020490F4(100,(u16)((((struct Obj25247 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10&0x7fff)|0x8000));
    void *handle;
    char *data;
    sub_02049658(owner,18,7,0,0,1,((struct Obj25248 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    handle=func_02049EF4(owner,16,1,(void **)&data,((struct Obj25249 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    func_0220B120(p,(u16 *)(data+12));
    func_020307B0(handle);
    handle=func_02049EF4(owner,17,1,(void **)&data,((struct Obj25250 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    func_0220B3B4(p,(u16 *)(data+12));
    func_020307B0(handle);
    func_02021640(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,100,19,((struct Obj25251 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,0x1e0,0);
    func_02049238(owner);
    func_02082D44((void *)(func_02021728(*(char * *)&((struct Obj02535 *)p)->f1D8,1)+0x180),p+0x1e78,32);
    func_0201F5BC(4,1,14,0,((struct Obj25252 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10);
    func_020216D4(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,1,0xe0,32);
    func_02021640(*(struct PalAnmSlot * *)&((struct Obj02535 *)p)->f1D8,23,5,((struct Obj25253 *)(*(char * *)&((struct Obj02535 *)p)->f0))->f10,1,32,0xd0);
}

void func_02210710(char *p)
{
    ((struct Obj02916 *)p)->f1EA0=func_02045B38(0,2,0x12,((struct Obj25254 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1E9C=func_0201D7EC(0x17,3,0,0,((struct Obj25255 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EA4=func_0201EC64(((struct Obj25256 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EAC=func_0201C450(0x800,((struct Obj25257 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
    ((struct Obj02916 *)p)->f1EA8=func_020457B0(0x200,((struct Obj25258 *)(*(char * *)&((struct Obj02916 *)p)->f0))->f10);
}

void func_02210774(u8 *p) { func_02045C04(*(struct Rec * *)&((struct Obj06656 *)p)->f1EA0);func_0201D83C(((struct Obj06656 *)p)->f1E9C);func_0201ED04(*(struct WordSet * *)&((struct Obj06656 *)p)->f1EA4);func_0201C4C0(*(struct PrintSys * *)&((struct Obj06656 *)p)->f1EAC);func_02045808(*(struct U16Vec * *)&((struct Obj06656 *)p)->f1EA8); }
