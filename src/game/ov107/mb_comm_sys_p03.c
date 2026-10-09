/*
 * file:     mb_comm_sys_p03.c
 * unit:     yes
 * function: func_021EF444, func_021EF588, func_021EF74C, func_021EF79C, func_021EF96C, func_021EFA14, func_021EFC10, func_021EFC1C
 * address:  0x021EF444
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021F1B04 0x021F1B04 thumb ov107
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021F6EA0 0x021F6EA0 data a4
 *   func_02012944 0x02012944 thumb
 *   func_02030734 0x02030734 arm
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_021F18D8 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   func_021F1918 0x021F1918 thumb ov107
 *   func_021F1AFC 0x021F1AFC thumb ov107
 *   func_021F1B00 0x021F1B00 thumb ov107
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_020458F8 0x020458F8 arm
 *   func_02045A90 0x02045A90 arm
 *   func_02082A60 0x02082A60 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_020774A0 0x020774A0 arm
 *   func_021F05DC 0x021F05DC thumb ov107
 *   d_021F6E0C 0x021F6E0C data a4
 *   ov014_id 0x0000000E data
 *   func_02034A5C 0x02034A5C arm
 *   func_020307B0 0x020307B0 arm
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_021F0DB4 0x021F0DB4 thumb ov107
 *   func_02179158 0x02179158 thumb ov014
 *   func_021790E4 0x021790E4 thumb ov014
 *   func_02037010 0x02037010 arm
 *   func_02037118 0x02037118 arm
 *   func_020351F8 0x020351F8 arm
 *   func_021F1898 0x021F1898 thumb ov107
 *   func_02012FFC 0x02012FFC thumb
 *   func_021F1704 0x021F1704 thumb ov107
 *   func_021F18EC 0x021F18EC thumb ov107
 *   func_021F17E0 0x021F17E0 thumb ov107
 *   func_021F1B38 0x021F1B38 thumb ov107
 *   func_0204B878 0x0204B878 arm
 *   func_02179570 0x02179570 thumb ov014
 *   func_021EFCA8 0x021EFCA8 thumb ov107
 *   func_0208EE9C 0x0208EE9C arm
 *   func_020370F4 0x020370F4 arm
 *   func_02037154 0x02037154 arm
 *   d_021F6D68 0x021F6D68 data ov107 a4
 *   d_021F6D70 0x021F6D70 data ov107 a4
 *   d_021F6D60 0x021F6D60 data ov107 a4
 *   d_021F6C40 0x021F6C40 data ov107 a4
 *   func_02179024 0x02179024 thumb ov014
 *   func_02082D44 0x02082D44 arm
 *   func_021F0754 0x021F0754 thumb ov107
 *   func_021F080C 0x021F080C thumb ov107
 *   func_021F0D28 0x021F0D28 thumb ov107
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021F0A28 0x021F0A28 thumb ov107
 *   func_021F0A64 0x021F0A64 thumb ov107
 *   func_021F0AE4 0x021F0AE4 thumb ov107
 *   func_021F1B14 0x021F1B14 thumb ov107
 *   func_021F1930 0x021F1930 thumb ov107
 *   func_021F19E4 0x021F19E4 thumb ov107
 *   func_021F19C8 0x021F19C8 thumb ov107
 *   func_021F1A2C 0x021F1A2C thumb ov107
 *   func_02034714 0x02034714 arm
 *   func_021F19B8 0x021F19B8 thumb ov107
 *   func_021F1A24 0x021F1A24 thumb ov107
 *   d_021F6AF8 0x021F6AF8 data a4
 *   d_021F6E08 0x021F6E08 data a4
 *   func_0200C1A4 0x0200C1A4 thumb
 *   func_0200C1B0 0x0200C1B0 thumb
 */
#include "../../matched/include/Obj00979.h"
#include "../../matched/include/Obj00057.h"
#include "../../matched/include/Obj10258.h"
#include "../../matched/include/Obj00072.h"
#include "../../matched/include/Obj22277.h"
#include "../../matched/include/Obj22278.h"
#include "../../matched/include/Obj07994.h"

struct Bank;
struct Obj;
struct BgTemplate;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct CharBuf;
struct Cfg;
struct Sub0200852CObj;
struct WordSet;
struct Blk34;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

struct Placement { u16 x,y,z;u8 f6,f7; };

typedef signed int     s32;

typedef signed short s16;

struct Work {
    u16 f0;
    u8 pad_2[6];
    u8 **f8;
    u8 pad_c[0x18];
    u8 f24;
    u8 pad_25;
    u8 f26;
    u8 pad_27;
    u8 f28;
    u8 pad_29[7];
    int f30;
    u8 pad_34[0x1c];
    u16 *f50;
    u16 *f54;
    u8 pad_58[0x10];
    u8 *f68;
};

typedef struct { int a,b; } Pair;

typedef struct { int words[15]; } Config;

struct Counter { u8 f0; u8 f1; u16 f2; u32 f4; int f8; };

extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern unsigned int func_021F1B04(unsigned char *p);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02045808(struct U16Vec *);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern u8 *func_02012944(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_021F1628(void *, int);
extern void func_021F18D8(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_021F1918(unsigned char *a, int b, int c, int d);
extern u32 func_021F1AFC(u8 *p);
extern u32 func_021F1B00(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02082A60(const void *, void *, int);
extern int func_02034AC4(s32 handle);
extern void func_020774A0(int (*callback)(void));
extern int func_021F05DC(void);
extern void func_02034A5C(int);
extern u32 func_020307B0(void *p);
extern int func_02178E4C(void);
extern int func_02178E84(void);
extern int func_02179498(void);
extern void func_021F0DB4(void);
extern void func_02179158(void);
extern int func_021790E4(u32,int,int);
extern void func_02037010(u32,u32,u32,u32);
extern void func_02037118(u32,u32);
extern void func_020351F8(u32 a, u32 b);
extern signed char func_02012FFC(void);
extern void func_021F1704(void *,int,int);
extern void func_021F18EC(void *);
extern void func_021F17E0(void *,int);
extern void func_021F1B38(u8 *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_02179570(void (*cb)(int));
extern int func_0208EE9C(void);
extern u32 func_020370F4(u32);
extern void func_02037154(void);
extern void func_021EFCA8(u8 *p);
extern u16 func_02179024(void);
extern void func_02082D44(const void *,void *,unsigned);
extern void func_021F0754(int,int);
extern void func_021F080C(void *,int);
void func_021EF080(char *p);
void func_021EF0D0(u32 a,u32 b,u32 c);
void func_021EF0F4(u8 *p);
extern u16 func_021F0D28(void);
extern int func_02035C08(const void *);
extern int func_021F0A28(void);
extern int func_021F1B14(void *);
extern int func_021F19C8(unsigned char *a);
extern int func_021F1A2C(void *);
extern u32 func_020362DC(void);
extern void func_0204B92C(struct Obj *,u32);
extern void func_020061E4(u32);
extern void func_021F0A64(void);
extern void func_021F0AE4(void);
extern void func_021F1898(void *);
extern void func_021F1930(char *p, int kind);
extern void func_021F19E4(void *,int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F19B8(unsigned char *a);
extern void func_021F1A24(u8 *p);
extern u8 func_0200C1A4(struct Blk34 *p);
extern void func_0200C1B0(struct Blk34 *p, u32 v);
void func_021EF444(u8 *p);
void func_021EF588(u8 *p);
void func_021EF74C(unsigned char *p);
int func_021EF79C(u8 *p);
void func_021EF96C(u8 *p);
void func_021EFA14(u8 *p);
int func_021EFC10(void);
void func_021EFC1C(u8 *p,int mode);
extern struct Counter d_021F6EA0;
extern const char d_021F6E0C[];
extern u8 ov014_id[];
extern const Pair d_021F6D68,d_021F6D70,d_021F6D60;
extern const Config d_021F6C40;
extern u8 d_021F6AF8[],d_021F6E08[];




/*
 * extent: two bytes of alignment padding follow the return.
 */








/*
 * volatile: MMIO palette halfword stores at 021EF56E and 021EF572.
 */
void func_021EF444(u8 *p) {
 u32 bg,window;
 void *archive,*text;
 struct MsgBank *bank;
 if(!p[0x28]) {*(u32 *)(((u8 *)&d_021F6EA0)+4)=1;bg=4;}
 else {*(u32 *)(((u8 *)&d_021F6EA0)+4)=0;bg=2;}
 func_02040588(bg,0);
 archive=func_020490F4(22,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,4,224,32,((struct Obj00057 *)p)->f0);
 func_02049B68((void *)((u32)archive),0,0,224,32,((struct Obj00057 *)p)->f0);
 func_02049658((void *)((u32)archive),1,bg,0,0,0,((struct Obj00057 *)p)->f0);
 func_020498F4((void *)((u32)archive),2,bg,0,0,0,((struct Obj00057 *)p)->f0);
 func_020413B0(bg,0,0,32,24,7);func_020409B4(bg);func_02049238(archive);
 window=func_020450F0(bg,1,4,30,8,7,1);
 bank=func_02045B38(0,2,0x52,((struct Obj00057 *)p)->f0);
 text=func_02045EC0(bank,1);
 func_02043B5C(func_02045770((struct Descriptor *)window),7);
 func_0201C7D0(func_02045770((struct Descriptor *)window),0,0,text,(void *)func_021F1B04(*(u8 * *)&((struct Obj00057 *)p)->f68),0x1167);
 func_02045334((struct Descriptor *)window);func_02045374((struct Cfg *)window);
 func_020409B4(func_02045730((struct Descriptor *)window));
 func_02045808((struct U16Vec *)text);func_02045C04((struct Rec *)bank);func_020452E8((struct Descriptor *)window);
 *(volatile u16 *)0x05000000=0x7eea;*(volatile u16 *)0x05000400=0x7eea;
}






/*
 * 2026-10-05 (integrator): the fullwidth-to-ASCII constants are plain literals (0xFF29, 0xFF24, 0xFF10..0xFF19, c - 0xFEE0); mwcc derives them from one held value itself, so the earlier `u32 k = 0xFF24` local was not needed. EXACT in c99 and c.
 */
void func_021EF588(u8 *p)
{
    struct Work *w = (struct Work *)p;
    u8 *q;
    struct U16Vec *a;
    struct U16Vec *b;
    void *m;
    u16 la;
    u16 lb;
    int i;
    u16 *dst;
    u16 *src;


    q = func_02012944(w->f8[1]);
    w->f24 = 0;
    w->f26 = 0;
    w->f50 = func_02030734(w->f0, 0x60, 1, d_021F6E0C, 0x553);
    w->f54 = func_02030734(w->f0, 0xC0, 1, d_021F6E0C, 0x554);
    func_021F1628(w->f68, 1);
    func_021F18D8(w->f68);
    func_021F1918(w->f68, 0, func_02008534((const struct Sub0200852CObj *)q), 5);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xC);
    else
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xF);
    a = func_020457B0(0x100, w->f0);
    func_0201F250((struct WordSet *)func_021F1B00(w->f68), a, m);
    func_02045808((struct U16Vec *)m);
    if (w->f28 == 0)
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0xD);
    else
        m = func_02045EC0((struct MsgBank *)func_021F1AFC(w->f68), 0x10);
    b = (struct U16Vec *)m;
    la = (u32)func_020458F8(a);
    lb = (u32)func_020458F8(b);
    dst = w->f50;
    src = func_02045A90(a);
    func_02082A60(src, dst, la * 2);
    dst = w->f54;
    src = func_02045A90(b);
    func_02082A60(src, dst, lb * 2);
    func_02045808(a);
    func_02045808(b);
    w->f50[la] = 0;
    w->f54[lb] = 0;
    for (i = 0; i < 0x60; i++) {
        if (w->f54[i] == 0xFFFE)
            w->f54[i] = 0xA;
    }
    for (i = 0; i < 0x30; i++) {
        u16 c = w->f50[i];
        if (c == 0xFF29)
            w->f50[i] = 0x49;
        else if (c == 0xFF24)
            w->f50[i] = 0x44;
        else if (c >= 0xFF10 && c <= 0xFF19)
            w->f50[i] = c - 0xFEE0;
    }
    w->f30 = 0;
    func_02034AC4((int)ov014_id);
    if (w->f28 == 0) {
        func_02040588(2, 1);
        func_02040588(0, 1);
    } else {
        func_02040588(5, 1);
        func_02040588(4, 1);
    }
    func_020774A0(func_021F05DC);
}





void func_021EF74C(unsigned char *p) {
 func_02034A5C((int)ov014_id);func_020774A0(0);
 func_020307B0(((struct Obj10258 *)p)->f50);func_020307B0(((struct Obj10258 *)p)->f54);
 if(!p[40]) {func_02040588(2,0);func_02040588(0,0);}
 else {func_02040588(5,0);func_02040588(4,0);}
}




int func_021EF79C(u8 *p)
{
 void *q;
 if(func_02178E4C()==9 || func_02178E4C()==10){
  ((struct Obj00072 *)p)->f30=0;((struct Obj00072 *)p)->f14=1;
  if(func_02179498()==1){func_021F0DB4();func_02179158();return 1;}return 0;
 }
 switch(p[0x24]){
 case 0:
  *(int *)(((u8 *)&d_021F6EA0)+8)=0;((struct Obj00072 *)p)->f1C=1;
  func_021790E4(((struct Obj00072 *)p)->f0,(int)func_021EFC10,0);
  func_02037010(240,0,0,((struct Obj00072 *)p)->f0);
  if(p[0x28]==0)func_02037118(0,((struct Obj00072 *)p)->f0);
  else func_02037118(1,((struct Obj00072 *)p)->f0);
  p[0x24]=1;func_020351F8((u32)func_021EFCA8,(u32)p);break;
 case 1:
  if(func_02178E4C()==1 && func_02178E84()==1)p[0x24]=2;break;
 default:break;
 case 2:
  if(func_02178E4C()==7){
   q=func_02012944(((struct Obj22277 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);func_021EF96C(p);
   func_021F1898(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)func_021F1628(((struct Obj00072 *)p)->f68,2);
   else func_021F1628(((struct Obj00072 *)p)->f68,3);
   func_021F18D8(((struct Obj00072 *)p)->f68);func_021F1918(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   if(p[0x28]==0)func_021F1704(((struct Obj00072 *)p)->f68,0,func_02012FFC());
   else func_021F1704(((struct Obj00072 *)p)->f68,20,func_02012FFC());
   func_021F18EC(((struct Obj00072 *)p)->f68);p[0x24]=3;
  }break;
 case 3:func_021EFA14(p);break;
 case 4:
  func_021F1898(((struct Obj00072 *)p)->f68);func_021F1628(((struct Obj00072 *)p)->f68,1);
  if(p[0x28]==0)func_021F17E0(((struct Obj00072 *)p)->f68,1);
  else func_021F17E0(((struct Obj00072 *)p)->f68,21);
  func_021F1B38(((struct Obj00072 *)p)->f68,1);func_0204B878(((struct Obj00072 *)p)->f7C,15);p[0x24]=5;break;
 case 5:((struct Obj00072 *)p)->f30=1;p[0x24]=6;break;
 case 8:p[0x24]=6;break;
 case 6:*(int *)(((u8 *)&d_021F6EA0)+8)=0;func_02179570((void (*)(int))((int (*)(int))func_021EFC10));((struct Obj00072 *)p)->f1C=0;p[0x24]=7;break;
 case 7:if(*(int *)(((u8 *)&d_021F6EA0)+8)==1){func_020351F8(0,0);func_02179158();return 1;}break;
 }
 func_020370F4(3-func_0208EE9C());func_02037154();return 0;
}




void func_021EF96C(u8 *p) {
 Pair a=d_021F6D68,b=d_021F6D70,c=d_021F6D60;
 Config cfg=d_021F6C40;
 int v=func_02179024();
 func_02082D44(&cfg,p+128,60);
 ((struct Obj00072 *)p)->f80=p[40]==0?a.a:a.b;
 ((struct Obj00072 *)p)->f8C=b.b;((struct Obj00072 *)p)->f90=c.b;
 ((struct Obj00072 *)p)->f84=((struct Obj00072 *)p)->f50;((struct Obj00072 *)p)->f88=((struct Obj00072 *)p)->f54;
 func_021F0754(4992,65536);func_021F080C(p+128,v);
}


/*
 * extent: follower 021EFC10 already has its own matched source/shard.
 * ABI: 19E4 keeps the caller's visibly supplied r1. 0AE4 reads no incoming arguments.
 */
void func_021EFA14(u8 *p)
{
 int a;void *q;
 func_021F0D28();
 switch(func_021F0D28()){
 case 2:
  if(p[0x26]==0){
   a=func_02035C08(d_021F6AF8);
   if(func_020362DC()==2 || (a==0 && p[0x28]==0)){
    p[0x26]=1;func_0204B878(((struct Obj00072 *)p)->f7C,9);func_0204B92C(((struct Obj00072 *)p)->f7C,1);func_020061E4(1361);
   }else if(func_021F0A28()){func_021F0A64();}
  }break;
 case 5:p[0x24]=4;break;
 case 7:func_021F0AE4();break;
 case 0:p[0x24]=8;break;
 case 1:case 3:case 4:case 6:default:break;
 }
 switch(p[0x26]){
 case 1:
  func_021F1898(((struct Obj00072 *)p)->f68);func_0204B878(((struct Obj00072 *)p)->f7C,15);
  if(p[0x28]==0){func_021F1628(((struct Obj00072 *)p)->f68,7);func_021F1704(((struct Obj00072 *)p)->f68,9,func_02012FFC());}
  else {func_021F1628(((struct Obj00072 *)p)->f68,5);func_021F1704(((struct Obj00072 *)p)->f68,42,func_02012FFC());}
  p[0x26]=2;break;
 case 2:
  if(func_021F1B14(((struct Obj00072 *)p)->f68)==1){
   if(p[0x28]==0)func_021F1930(((struct Obj00072 *)p)->f68,0);
   else func_021F19E4(((struct Obj00072 *)p)->f68,0);
   p[0x26]=3;
  }break;
 case 3:
  if(p[0x28]==0)a=func_021F19C8(((struct Obj00072 *)p)->f68);
  else a=func_021F1A2C(((struct Obj00072 *)p)->f68);
  if(a==1){
   if(func_021F0D28()!=2)func_02034714((const char *)d_021F6E08,0,(const char *)d_021F6E08);
   func_021EFC1C(p,4);func_021F0AE4();p[0x26]=4;
  }else if(a==2){
   q=func_02012944(((struct Obj22278 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);
   if(p[0x28]==0)func_021F19B8(((struct Obj00072 *)p)->f68);else func_021F1A24(((struct Obj00072 *)p)->f68);
   func_021F1898(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)func_021F1628(((struct Obj00072 *)p)->f68,2);else func_021F1628(((struct Obj00072 *)p)->f68,3);
   func_021F18D8(((struct Obj00072 *)p)->f68);func_021F1918(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   func_0204B878(((struct Obj00072 *)p)->f7C,1);
   if(p[0x28]==0)func_021F1704(((struct Obj00072 *)p)->f68,0,func_02012FFC());else func_021F1704(((struct Obj00072 *)p)->f68,20,func_02012FFC());
   func_021F18EC(((struct Obj00072 *)p)->f68);p[0x26]=0;
  }break;
 }
}


int func_021EFC10(void) { d_021F6EA0.f8=1; return 1; }


void func_021EFC1C(u8 *p,int mode) {
 unsigned cur; int change;
 if(p[40]==0) {
 cur=func_0200C1A4(((struct Obj07994 *)p)->f4C);change=0;
 switch(mode) {
 case 0: if(cur!=1&&cur!=3&&cur!=5) change=1;break;
 case 1: if(cur!=3&&cur!=5) change=1;break;
 case 2: if(cur!=0&&cur!=1&&cur!=3&&cur!=5) change=1;break;
 case 3: change=1;if(((struct Obj07994 *)p)->f3C!=0) mode=5;break;
 case 4: if(cur!=2&&cur!=0&&cur!=1&&cur!=3&&cur!=5) change=1;break;
 }
 if(change==1) func_0200C1B0(((struct Obj07994 *)p)->f4C,mode);
 }
}
