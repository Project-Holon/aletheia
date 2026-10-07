/*
 * file:     beacon_detail_gra_p07.c
 * unit:     yes
 * function: func_021BCAF4, func_021BCAFC, func_021BCB70, func_021BCB90, func_021BCB98, func_021BCBA4, func_021BCC10, func_021BCCBC, func_021BCCC4, func_021BCD00, func_021BCD08, func_021BCD60, func_021BCDC0, func_021BCDDC, func_021BCE04, func_021BCE7C, func_021BCE8C, func_021BCEA4, func_021BCED0, func_021BCF08, func_021BD07C, func_021BD0E4, func_021BD13C, func_021BD174, func_021BD448, func_021BD668, func_021BD6BC, func_021BD6F0, func_021BD6FC, func_021BD73C, func_021BD768, func_021BD7D4, func_021BD854, func_021BD89C, func_021BD8A8, func_021BD948, func_021BDA54, func_021BDAA0
 * address:  0x021BCAF4
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B0F4 0x0204B0F4 arm
 *   func_0204B258 0x0204B258 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021BDBBC 0x021BDBBC data a4
 *   d_021BDC08 0x021BDC08 data a4
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   MI_CpuFill8   0x02082BCC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02165AC4 0x02165AC4 thumb ov010
 *   func_0203D34C 0x0203D34C arm
 *   func_02012204 0x02012204 thumb
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_02165C48  0x02165C48  thumb  ov010
 *   d_021BDDA2 0x021BDDA2 data a1
 *   func_02165DAC 0x02165DAC thumb ov010
 *   func_02165DF0 0x02165DF0 thumb ov010
 *   func_02165DBC 0x02165DBC thumb ov010
 *   func_02165D28 0x02165D28 thumb ov010
 *   func_0204B878  0x0204B878  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B404  0x0204B404  arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0204A9D0 0x0204A9D0 arm
 *   d_021BDD92 0x021BDD92 data a1
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BDD8A 0x021BDD8A data a2
 *   func_02043AF4 0x02043AF4 arm
 *   sub_0204B3DC 0x0204B3DC arm
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   func_0202DCB0 0x0202DCB0 thumb
 *   sub_02040588 0x02040588 arm
 *   func_02040618 0x02040618 arm
 *   func_02165CC0 0x02165CC0 thumb ov010
 *   func_02021F64 0x02021F64 thumb
 *   func_02165C34 0x02165C34 thumb ov010
 *   func_02165C60 0x02165C60 thumb ov010
 *   func_0204581C 0x0204581C arm
 *   func_0201F1C8 0x0201F1C8 thumb
 *   func_02165C78 0x02165C78 thumb ov010
 *   func_0201F198 0x0201F198 thumb
 *   func_02165D10 0x02165D10 thumb ov010
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02165C58 0x02165C58 thumb ov010
 *   func_0201F048 0x0201F048 thumb
 *   func_02165C5C 0x02165C5C thumb ov010
 *   func_0201F094 0x0201F094 thumb
 *   func_02165D40 0x02165D40 thumb ov010
 *   func_02165D48 0x02165D48 thumb ov010
 *   func_0202DCC4 0x0202DCC4 thumb
 *   func_0202DC9C 0x0202DC9C thumb
 *   func_02165C90 0x02165C90 thumb ov010
 *   func_0202DC48 0x0202DC48 thumb
 *   func_02165CE8 0x02165CE8 thumb ov010
 *   func_02025C88 0x02025C88 thumb
 *   func_0202DAA4 0x0202DAA4 thumb
 *   func_02165CB4 0x02165CB4 thumb ov010
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02165D34 0x02165D34 thumb ov010
 *   func_021BBB48 0x021BBB48 thumb ov072
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   func_02031194 0x02031194 arm
 *   func_021B64A8 0x021B64A8 thumb ov067
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   sub_02031194 0x02031194 arm
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_0201C6B4 0x0201C6B4 thumb
 *   d_021BDD88 0x021BDD88 data a1
 *   func_02045770 0x02045770 arm
 *   sub_0201C724 0x0201C724 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_021BDAD8 0x021BDAD8 thumb ov216
 */
#include "../../matched/include/Obj14717.h"
#include "../../matched/include/Obj00051.h"
#include "../../matched/include/Obj05554.h"
#include "../../matched/include/Obj14718.h"
#include "../../matched/include/Obj14719.h"
#include "../../matched/include/Obj08428.h"
#include "../../matched/include/Obj10948.h"
#include "../../matched/include/Obj05555.h"
#include "../../matched/include/Obj03943.h"
#include "../../matched/include/Obj25779.h"
#include "../../matched/include/Obj04637.h"
#include "../../matched/include/Obj10949.h"
#include "../../matched/include/Obj14720.h"
#include "../../matched/include/Obj10950.h"
#include "../../matched/include/Obj03375.h"
#include "../../matched/include/Obj02553.h"
#include "../../matched/include/Obj02927.h"
#include "../../matched/include/Obj05556.h"
#include "../../matched/include/Obj00690.h"
#include "../../matched/include/Obj25787.h"
#include "../../matched/include/Obj25788.h"
#include "../../matched/include/Obj25789.h"
#include "../../matched/include/Obj25790.h"
#include "../../matched/include/Obj25791.h"
#include "../../matched/include/Obj25792.h"
#include "../../matched/include/Obj25793.h"
#include "../../matched/include/Obj25794.h"
#include "../../matched/include/Obj25795.h"
#include "../../matched/include/Obj08427.h"
#include "../../matched/include/Obj14721.h"
#include "../../matched/include/Obj25797.h"

#define REC1(w, j, i) ((struct Rec *)((char *)(w) + (j) * 0x80 + (i) * 16))
#define HANDLE(p, k) (*(int *)((p) + (k)))
#define ARG(p, k) (*(int *)((p) + (k) + 0xC))
#define CALLS(r) do { void *d = (r)->d; func_02045334(d); func_02045374(d); func_020409B4(func_02045730(d)); } while (0)
struct Cfg;
struct Bank;
struct Obj;
struct Actor;
struct Queue;
struct Rec;
struct Ctx;
struct Bits;
struct WordSet;
struct Vec2;
struct MsgBank;
struct Sub0204A9D0;
struct Descriptor;
struct CharBuf;
struct Bmp;
struct Obj0202DCC4;
struct Obj0202DC98;
struct U16Vec;
struct S;
struct R;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
struct PrintSys;
struct Block { unsigned w[8]; };

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Object { unsigned char bytes[0x124]; void *menu; };

struct Four_021BCF08 { unsigned short a; unsigned char b, c; };

struct Rec { void *d; int h; int u, v; };

struct Rec32 { void *d; int h; char pad[24]; };

struct Win { struct Rec a[4]; struct Rec32 b; struct Rec32 c; };

struct Four_021BD07C { unsigned short a; unsigned char b,c; };

enum Index { IndexZero=0 };

struct Pair { u16 a,b; };

struct Quad { u16 a,b,c,d; };

struct Rgb555 { u16 r:5,g:5,b:5,pad:1; };

typedef signed short s16;

typedef signed char s8;

typedef void (*TcblFunc)(struct TcblNode *,void *);

typedef struct Work{int arg;u8 *owner;int *counter;} Work;

extern void func_020419E4(void);
extern void func_02082BCC(void *,int,int);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B0F4(struct Actor *a0, int a1);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B084(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void MI_CpuFill8(void *, int, int);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern int func_02165AC4(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern void func_0203D34C(u32 a, u32 b);
extern int func_021B6470(unsigned char *);
extern u32 func_020362DC(void);
extern unsigned func_02012204(const struct Ctx *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32 a);
extern void func_020862F0(void *,unsigned);
extern void func_0207E3D0(void *,unsigned,unsigned);
extern void func_0207E468(void *,unsigned,unsigned);
extern void func_0207E51C(void *,unsigned,unsigned);
extern void func_0207E5D0(void *,unsigned,unsigned);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern unsigned int func_02165C48(void *a0);
extern unsigned func_02165DAC(const char *);
extern unsigned short func_02165DF0(const char *);
extern unsigned short func_02165DBC(const char *);
extern unsigned short func_02165D28(const struct Bits *);
extern u32 func_02013E4C(u32 id);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F104(struct WordSet *p, u32 i, u32 a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_02045CAC(struct MsgBank*,u32,void*);
extern void func_0201F250(struct WordSet*,void*,void*);
extern void func_0204A9D0(int,struct Sub0204A9D0*);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned int);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void sub_0204B3DC(struct Obj *, u32);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *, u32);
extern void func_0202DCB0(struct Obj0202DC98 *, int, u32);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void func_02040618(u32,u32,u32);
extern void func_02165CC0(int a0, int a1);
extern void func_02021F64(u16 *,u16 *,u32,int,u16);
extern void func_02165C34(struct Rec *,void *);
extern int func_02165C60(int a0);
extern void func_0204581C(struct U16Vec *);
extern void func_0201F1C8(struct WordSet *,u32,u32);
extern int func_02165C78(int a0);
extern void func_0201F198(struct WordSet *,u32,u32);
extern void func_02165D10(const struct S *p, u16 *a, u16 *b);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern u8 func_02165C58(const u8 *p);
extern void func_0201F048(struct WordSet *,u32,u32);
extern u8 func_02165C5C(const u8 *p);
extern void func_0201F094(struct WordSet *,u32,u32,u32);
extern u32 func_02165D40(const struct S *p);
extern u32 func_02165D48(const struct S *p);
extern u32 func_0202DCC4(const struct Obj0202DCC4 *,u32);
extern void func_0202DC9C(struct Obj0202DC98 *,int,u32);
extern void func_02165C90(const struct R *p, struct Quad *q);
extern void func_0202DC48(u32,u32,u32,u32);
extern u8 func_02165CE8(struct S *);
extern u32 func_02025C88(u32);
extern void func_0202DAA4(void *set, u32 id, void *dstA, void *dstB, volatile u16 which);
extern u8 func_02165CB4(void *);
extern void func_0204B3DC(struct Obj *,u32);
extern unsigned short func_02165D34(const struct Bits *p);
extern int func_021BBB48(int,int);
extern u16 func_021BBB3C(char *,int,int);
extern struct TcblNode *sub_020311B8(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *sub_02031290(struct S02030FB4 *);
extern void func_02031194(struct TcblNode*);
extern void func_021B64A8(u8 *, u32);
extern int func_02035C60(void);
extern void sub_02031194(struct TcblNode *);
extern int func_021B6448(u8 *);
extern u32 func_0201C6B4(const struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void sub_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern struct TcblNode *func_020311B8(struct Tcbl *,TcblFunc,u32,u32);
extern void *func_02031290(struct S02030FB4 *);
extern void func_021BDAD8(int,int **);
void func_021BCAF4(void *a0);
void func_021BCAFC(void **p,void *a,int heap);
void func_021BCB70(char *p);
void func_021BCB90(void *a0);
void func_021BCB98(void *a0);
u32 func_021BCBA0(u32*p);
void func_021BCBA4(unsigned char *p);
int func_021BCC10(unsigned char *p);
void func_021BCCBC(u8*p);
int func_021BCCC4(u8*p);
void func_021BCD00(int a);
void func_021BCD08(void *p,unsigned mode,unsigned a,unsigned b);
void func_021BCD60(unsigned char *p);
int func_021BCDC0(void *a0);
const u8*func_021BCDDC(u32 n);
void func_021BCE04(void *p,void *q);
void func_021BCE7C(void *p, unsigned short value);
void func_021BCE8C(void *a0, short a1, short a2, int a3);
void func_021BCEA4(u8*p, u8 n);
void func_021BCED0(u8*p,u32 n);
void func_021BCF08(char *p);
void func_021BD07C(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e);
void func_021BD0E4(char *p, u8 index, u32 enable);
void func_021BD13C(u8*p,int a);
void func_021BD174(char *p,void *record,u16 unused,u8 slot);
void func_021BD448(char *p);
void func_021BD668(char *owner, int direction, int *counter);
void func_021BD6BC(struct TcblNode*task,u8*p);
void func_021BD6F0(char*p);
void func_021BD6FC(char *owner, int *counter);
int func_021BD73C(char *p);
void func_021BD768(struct TcblNode *task, void *data);
void func_021BD7D4(char *owner, u8 index, int position, u8 direction, int *counter);
void func_021BD854(struct TcblNode *task, char *p);
void func_021BD89C(char*p,int a);
void func_021BD8A8(char *owner, int direction, int *counter);
void func_021BD948(struct TcblNode *task,char *work);
void func_021BDA54(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
void func_021BDAA0(u8 *p,int arg,int *counter);
extern const unsigned d_021BDBBC[];
extern const struct Block d_021BDC08;
extern const u8 d_021BDDA2[];
extern const u8 d_021BDD92[];
extern const struct Four_021BCF08 d_021BDD8A[];
extern const u8 d_021BDD88[];

void func_021BCAF4(void *a0){func_020419E4();}

void func_021BCAFC(void **p,void *a,int heap)
{
    struct Block b;
    func_02082BCC(p,0,8);
    func_0204A48C((const struct Cfg *)d_021BDBBC,(unsigned int)a,heap);
    p[0]=func_0204B100(128,0,heap);
    b=d_021BDC08;
    p[1]=func_0204B034((u8 *)(&b),2,heap);
    func_0204B0F4(p[1],1);
    func_0204B258(p[0],p[1]);
    func_020434DC(16,1);
    func_02043598(16,1);
}


void func_021BCB70(char *p)
{
    func_0204B084(((struct Obj14717 *)p)->f4);
    func_0204B1CC(((struct Obj14717 *)p)->f0);
    func_0204A5AC();
    MI_CpuFill8(p, 0, 8);
}

void func_021BCB90(void *a0){func_0204A600();}

void func_021BCB98(void *a0){func_0204A648();}

u32 func_021BCBA0(u32*p){return *p;}

void func_021BCBA4(unsigned char *p)
{
    func_021BCF08((char *)p);
    func_02165AC4(((struct Obj00051 *)p)->f24,((struct Obj00051 *)p)->f28,(u16 *)(p+0x2c),*(p+p[0x30]+0x31));
    func_021BD174((char *)p,((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f2C,p[0x2e]);
    func_021BD0E4((char *)p,p[0x2e],1);
    func_021BD0E4((char *)p,p[0x2e]^1,0);
    func_021BD448((char *)p); func_021BCD60(p);
    func_0203D34C(0,((struct Obj00051 *)p)->f2);
}

int func_021BCC10(unsigned char *p)
{
    int state=func_021B6470(((struct Obj05554 *)p)->f124);
    unsigned keys=func_020362DC();
    if(func_02012204((const struct Ctx *)**(void ** *)&((struct Obj05554 *)p)->f14)) { (*(unsigned char **)(p+0x14))[9]=1; return 4; }
    if(state==1) { (*(unsigned char **)(p+0x14))[9]=0; return 4; }
    if(state==3 && p[0x30]) { func_021BD89C((char *)p,1); return 3; }
    if(state==2 && p[0x30]<p[0x2f]-1) { func_021BD89C((char *)p,0); return 3; }
    if(!p[0x260]) return 2;
    if(func_021BCCC4(p) || (keys&1)) { func_021BCD00(1356); func_021BD6F0((char *)p); return 3; }
    return 2;
}

void func_021BCCBC(u8*p){func_021BCD60(p);}

int func_021BCCC4(u8*p){u32 x,y;if(func_02035D20(&x,&y)){if((u32)(x-(((struct Obj14718 *)p)->f25C-12))<=24 && (u32)(y-(((struct Obj14718 *)p)->f25E-16))<=32)return 1;}return 0;}

void func_021BCD00(int a){func_020061E4(a);}

void func_021BCD08(void *p,unsigned mode,unsigned a,unsigned b)
{
    unsigned x=a*2,y=b*2;
    func_020862F0(p,y);
    switch(mode) {
    case 0: func_0207E3D0(p,x,y); break;
    case 1: func_0207E468(p,x,y); break;
    case 2: func_0207E51C(p,x,y); break;
    case 3: func_0207E5D0(p,x,y); break;
    }
}

void func_021BCD60(unsigned char *p)
{
    func_021B6548(((struct Object *)p)->menu,1,1);
    if(p[0x30]) func_021B6548(((struct Object *)p)->menu,3,1);
    else func_021B6548(((struct Object *)p)->menu,3,0);
    if(p[0x30]<p[0x2f]-1) func_021B6548(((struct Object *)p)->menu,2,1);
    else func_021B6548(((struct Object *)p)->menu,2,0);
}


/*
 * Unblocked by matching func_02165C48 (ov010, EXACT): the +0002 call site now
 * attests as `matched`.  ov009 holds ARM code at that address; ov010 is the
 * coherent Thumb leaf, so the correct hint is ov010 (the earlier ov009 hint
 * was wrong).
 *
 * The original selects case 0x15 before 0x14: reversing the two source
 * case labels flips the fall-through to put the default arm last, which is
 * the only shape that reproduces the image's three-exit if-chain.
 *
 * Addresses are Black-image addresses.
 */
int func_021BCDC0(void *a0)
{
    switch (func_02165C48(a0)) {
    case 0x15:
        return 0;
    case 0x14:
        return 1;
    default:
        return 2;
    }
}

const u8*func_021BCDDC(u32 n){u32 i;for(i=0;i<6;i++){if(n==d_021BDDA2[i*3])return d_021BDDA2+i*3;}return d_021BDDA2;}

void func_021BCE04(void *p,void *q)
{
    switch(func_02165DAC(p)) {
    case 0: case 1:
        func_0201EE60(q,0,func_02165DF0(p)); break;
    case 2: {
        unsigned a=func_02165DBC(p);
        func_0201F104(q,0,a); func_0201F134(q,1,a); break;
    }
    case 3: case 4: break;
    default: {
        unsigned a=func_02165D28(p);
        if(a>=427) a=317;
        func_0201F158(q,0,func_02013E4C(a)); break;
    }
    }
}


void func_021BCE7C(void *p, unsigned short value)
{
    func_0204B878(p, value);
    func_0204B9A0(p);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021BCE8C(void *a0, short a1, short a2, int a3)
{
    u16 tmp[2];
    tmp[0] = a1;
    tmp[1] = a2;
    func_0204B404(a0, (const struct Vec2 *)tmp, a3);
}

/*
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void func_020495F4(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void func_0204581C(void *dest);
 * extern void func_02045A00(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void func_02046110(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 *
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *
 *     func_02046180(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         func_020495F4(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, g_020A7E8C, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream, size, buf);
 *             func_02045A00(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     func_02045E04(dest, index);
 * }
 */
void func_021BCEA4(u8*p, u8 n){func_02045CAC(*(struct MsgBank**)(p+0x130),n,*(void**)(p+0x13c));func_0201F250(*(struct WordSet**)(p+0x138),*(void**)(p+0x140),*(void**)(p+0x13c));}

void func_021BCED0(u8*p,u32 n){func_0204A9D0(((struct Obj14719 *)p)->f84,*(struct Sub0204A9D0**)((u32)p+n*8+0x8c));func_021BCD08((u8*)*(void* *)&((struct Obj14719 *)p)->f110+(d_021BDD92[n]&15)*32,2,160,16);}


#pragma opt_lifetimes off

#pragma opt_propagation off

/*
 * note: final push 2026-10-05 G5L8. EXACT 372 B (c99 and c). Closed by: opt_propagation off with named locals b, a,
 *   rec and off (b, the row offset i*16 and a set in that order in loop 1 before the j loop), do-while loops (with
 *   propagation off a for loop gets an entry guard), x and j as separate counters, j = 0 set only before loop 3
 *   (set before loop 2 it was loaded from x's slot), record address as off + (u32)&w[j] for the add order.
 */
void func_021BCF08(char *p)
{
    struct Win *w3;
    struct Win *w2;
    struct Win *w;
    int i, j;
    u8 b;
    u16 a;
    struct Rec *rec;
    int off;
    int x;

    i = 0;
    w = (struct Win *)(p + 0x15C);

    do {
        func_02045CAC((struct MsgBank *)HANDLE(p, 0x130), i, (void *)ARG(p, 0x130));
        b = d_021BDD8A[i % 2].b;
        off = i * 16;
        a = d_021BDD8A[i % 2].a;
        j = 0;
        do {
            rec = (struct Rec *)(off + (u32)&w[j]);
            func_02043B5C((struct CharBuf *)rec->h, b);
            func_021BDA54(p, (char *)rec, 0, 0, ARG(p, 0x130), a);
            CALLS(rec);
            j++;
        } while (j < 2);
        i++;
    } while (i < 4);
    func_02045CAC((struct MsgBank *)HANDLE(p, 0x130), 7, (void *)ARG(p, 0x130));
    w2 = (struct Win *)(p + 0x130 + 0x2C);

    x = 0;
    do {
        func_02043B5C((struct CharBuf *)w2[x].b.h, 3);
        func_021BDA54(p, (char *)&w2[x].b, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w2[x].b);
        x++;
    } while (x < 2);
    func_02045CAC((struct MsgBank *)HANDLE(p, 0x130), 9, (void *)ARG(p, 0x130));
    w3 = (struct Win *)(p + 0x130 + 0x2C);
    j = 0;
    do {
        func_02043B5C((struct CharBuf *)w3[j].c.h, 3);
        func_021BDA54(p, (char *)&w3[j].c, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w3[j].c);
        j++;
    } while (j < 2);
}

#pragma opt_propagation reset

#pragma opt_lifetimes reset

void func_021BD07C(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e)
{
    void *x;
    func_02043AF4(q[1],(short)(a*8),0,(unsigned short)(c*8),(unsigned short)(d*8),d_021BDD8A[e].b);
    func_021BDA54(p,(char *)q,b,0,v,d_021BDD8A[e].a);
    x=q[0];
    func_02045334(x); func_02045374(x); func_020409B4(func_02045730(x));
}

void func_021BD0E4(char *p, u8 index, u32 enable)
{
    char *entry;
    entry = p + 0x15c + index * 128;
    sub_0204B3DC(*(struct Obj * *)&((struct Obj08428 *)entry)->f78, enable);
    if (((struct Obj08428 *)entry)->f7D != 0)
        sub_0204B3DC(*(struct Obj * *)&((struct Obj08428 *)entry)->f74, enable);
    if (sub_0202DCC4(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158, index) != 0)
        func_0202DCB0(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158, index, enable);
    sub_02040588(((struct Obj08428 *)entry)->f7E, (u8)enable);
}

/*
 * prototype: 021BCE8C coordinate parameters are signed short: original uses asrs #16 before each call; same-overlay matched caller 021BD448 declares s16.
 */
void func_021BD13C(u8*p,int a){func_02040618(p[0x7e],3,-a);func_021BCE8C(*(void* *)&((struct Obj10948 *)p)->f78,220,a+44,1);func_021BCE8C(*(void* *)&((struct Obj10948 *)p)->f74,200,a+80,1);}

void func_021BD174(char *p,void *record,u16 unused,u8 slot)
{
    struct Pair colors;
    struct Quad data;
    struct Pair counts;
    char *q=(char *)p+0x15c+slot*128;
    u32 subtype;
    u16 value;
    int position;
    int index;
    func_02165CC0((int)(&colors.a),(int)record);
    func_02021F64(&colors.a,&colors.b,1,3,0);
    position=slot*16;
    func_021BCD08(&colors,1,(u16)(position+1),2);
    func_021BCD08(*(char * *)&((struct Obj00051 *)p)->f11C+func_021BCDC0(record)*32,1,(u16)(position+10),2);
    func_02165C34(record,((struct Obj00051 *)p)->f13C);
    func_021BD07C((char *)p,(void **)q,*(int *)&((struct Obj00051 *)p)->f13C,6,48,13,2,0);
    subtype=func_02165C60((int)record);
    if(subtype==255) func_0204581C(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {func_0201F1C8(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);func_021BCEA4((u8 *)p,5);}
    func_021BD07C((char *)p,(void **)(q+16),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    subtype=func_02165C78((int)record);
    if(subtype==255) func_0204581C(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {func_0201F198(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);func_021BCEA4((u8 *)p,4);}
    func_021BD07C((char *)p,(void **)(q+32),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,0);
    func_02165D10(record,&counts.b,&counts.a);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,2,counts.b,3,0,1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,3,counts.a,2,2,1);
    func_021BCEA4((u8 *)p,6);
    func_021BD07C((char *)p,(void **)(q+48),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    value=(unsigned)func_02165C58(record);
    func_0201F048(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,value);
    func_0201F094(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,value,func_02165C5C(record));
    func_021BCEA4((u8 *)p,8);
    func_021BD07C((char *)p,(void **)(q+80),*(int *)&((struct Obj00051 *)p)->f140,0,0,28,4,0);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,func_02165D40(record),5,1,1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,func_02165D48(record),5,1,1);
    func_021BCEA4((u8 *)p,10);
    func_021BD07C((char *)p,(void **)(q+96),*(int *)&((struct Obj00051 *)p)->f140,21,0,6,4,0);
    if(func_0202DCC4(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158,slot)!=0) func_0202DC9C(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158,slot,1);
    func_02165C90(record,&data);
    func_0202DC48(*(u32 *)&((struct Obj00051 *)p)->f158,((struct Obj05555 *)q)->f70,(u32)&data,slot);
    ((struct Obj05555 *)q)->f7C=func_02165CE8(record);
    index=slot*12;
    func_0202DAA4(((struct Obj00051 *)p)->f58,func_02025C88(((struct Obj05555 *)q)->f7C),*(void **)((u32)p+0x6c+(u32)index),*(void **)((u32)p+0x68+(u32)index),((struct Obj00051 *)p)->f2);
    subtype=func_02165CB4(record);
    if(subtype==0) {func_0204B3DC(*(struct Obj * *)&((struct Obj05555 *)q)->f74,0);return;}
    func_021BCE7C(((struct Obj05555 *)q)->f74,(u8)(subtype+1));
    func_0204B3DC(*(struct Obj * *)&((struct Obj05555 *)q)->f74,1);
}

void func_021BD448(char *p)
{
    const u8 *type;
    u32 value;
    int index,high;
    struct Descriptor *d;
    func_02165AC4(*(struct Queue * *)&((struct Obj00051 *)p)->f24,*(struct Rec * *)&((struct Obj00051 *)p)->f28,(u16 *)(p+44),*(u8 *)((u32)p+((struct Obj00051 *)p)->f30+49));
    type=func_021BCDDC(func_02165DAC(*(const char * *)&((struct Obj00051 *)p)->f28));
    func_021BCED0((u8 *)p,func_02165CE8(*(struct S * *)&((struct Obj00051 *)p)->f28));
    value=func_02165D28(*(struct Bits * *)&((struct Obj00051 *)p)->f28);
    index=func_021BBB48(*(int *)&((struct Obj00051 *)p)->f1C,func_02165D34((const struct Bits *)(*(const char * *)&((struct Obj00051 *)p)->f28)));
    if(index==0xffff || func_021BBB3C(*(char * *)&((struct Obj00051 *)p)->f1C,index,16)!=0xffff || value>=427) {
        ((struct Obj00051 *)p)->f260=0;
        *(volatile s16 *)&((struct Obj00051 *)p)->f25E=0;
        ((struct Obj00051 *)p)->f25C=*(volatile s16 *)&((struct Obj00051 *)p)->f25E;
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f264,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f268,0);
    } else {
        ((struct Obj00051 *)p)->f260=1;
        ((struct Obj00051 *)p)->f25C=func_021BBB3C(*(char * *)&((struct Obj00051 *)p)->f1C,index,2);
        ((struct Obj00051 *)p)->f25E=func_021BBB3C(*(char * *)&((struct Obj00051 *)p)->f1C,index,3)-16;
        if(((struct Obj00051 *)p)->f25E<32) ((struct Obj00051 *)p)->f25E=32;
        else if(((struct Obj00051 *)p)->f25E>152) ((struct Obj00051 *)p)->f25E=152;
        if(((struct Obj00051 *)p)->f25C<16) ((struct Obj00051 *)p)->f25C=16;
        else if(((struct Obj00051 *)p)->f25C>240) ((struct Obj00051 *)p)->f25C=240;
        func_021BCE8C(((struct Obj00051 *)p)->f264,((struct Obj00051 *)p)->f25C,((struct Obj00051 *)p)->f25E,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f264,1);
        if(type[2]!=0) {
            func_021BCE8C(((struct Obj00051 *)p)->f268,((struct Obj00051 *)p)->f25C-24,((struct Obj00051 *)p)->f25E,0);
            func_021BCE7C(((struct Obj00051 *)p)->f268,(u8)(type[2]-1));
        }
        func_0204B3DC(*(struct Obj * *)&((struct Obj00051 *)p)->f268,type[2]!=0);
    }
    func_02043B5C(*(struct CharBuf * *)&((struct Obj00051 *)p)->f14C,15);
    high=(u8)(((struct Obj00051 *)p)->f2C>>8);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,high,2,0,1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,(u8)((struct Obj00051 *)p)->f2C,2,2,1);
    func_021BCEA4((u8 *)p,(high/12)+13);
    func_021BDA54(p,p+0x148,0,0,*(u32 *)&((struct Obj00051 *)p)->f140,0x1d0f);
    func_021BCE04(((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f138);
    func_021BCEA4((u8 *)p,type[1]);
    func_021BDA54(p,p+0x148,0,16,*(u32 *)&((struct Obj00051 *)p)->f140,0x1d0f);
    d=*(struct Descriptor * *)&((struct Obj00051 *)p)->f148;
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_020409B4(func_02045730(d));
}

/*
 * lever: the signed byte step derives -8 from live 64 with subs #72; u8 emits movs #248.
 */
void func_021BD668(char *owner, int direction, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl * *)&((struct Obj25779 *)owner)->f18, (void (*)(struct TcblNode *, void *))func_021BD6BC, 12, 0));
    MI_CpuFill8(work, 0, 12);
    ((struct Obj03943 *)work)->f0 = direction;
    if (((struct Obj03943 *)work)->f0 == 0) {
        ((struct Obj03943 *)work)->f3 = 0;
        ((struct Obj03943 *)work)->f4 = 8;
    } else {
        ((struct Obj03943 *)work)->f3 = 64;
        ((struct Obj03943 *)work)->f4 = -8;
    }
    ((struct Obj03943 *)work)->f1 = 8;
    func_021BCD00(1357);
    *(int * *)&((struct Obj03943 *)work)->f8 = counter;
    ++*counter;
}

void func_021BD6BC(struct TcblNode*task,u8*p){u32 old=p[2]++;if(old<p[1]){((struct Obj04637 *)p)->f3=((struct Obj04637 *)p)->f3+((struct Obj04637 *)p)->f4;func_02040618(1,3,((struct Obj04637 *)p)->f3);}else{--**(u32* *)&((struct Obj04637 *)p)->f8;func_02031194(task);}}

void func_021BD6F0(char*p){func_021BD6FC(p,(int*)(p+12));}

/*
 * region evidence: ov067 labels 021B64A8; its filed/full body reads the supplied object in r0 and enable in r1.
 */
void func_021BD6FC(char *owner, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl * *)&((struct Obj14720 *)owner)->f18, func_021BD768, 16, 0));
    MI_CpuFill8(work, 0, 16);
    *(char * *)&((struct Obj10949 *)work)->f8 = owner;
    ((struct Obj10949 *)work)->f1 = 150;
    func_021B64A8(*(u8 * *)&((struct Obj14720 *)owner)->f124, 0);
    *(int * *)&((struct Obj10949 *)work)->fC = counter;
    ++*counter;
}


int func_021BD73C(char *p)
{
    unsigned char c;
    if (func_02035C60() != 0 || (func_020362DC() & 1) != 0)
    {
        ((struct Obj10950 *)p)->f1 = 0;
        return 0;
    }
    c = ((struct Obj10950 *)p)->f1;
    ((struct Obj10950 *)p)->f1 = c - 1;
    if (c != 0)
    {
        return 1;
    }
    return 0;
}

void func_021BD768(struct TcblNode *task, void *data)
{
    char *p = data;
    switch (((struct Obj03375 *)p)->f0) {
    case 0:
        func_021BD668(((struct Obj03375 *)p)->f8, 0, (int *)(p + 4));
        ++((struct Obj03375 *)p)->f0;
        break;
    case 1:
        if (((struct Obj03375 *)p)->f4 == 0)
            ++((struct Obj03375 *)p)->f0;
        break;
    case 2:
        if (func_021BD73C(p) == 0) {
            func_021BD668(((struct Obj03375 *)p)->f8, 1, (int *)(p + 4));
            ++((struct Obj03375 *)p)->f0;
        }
        break;
    case 3:
        if (((struct Obj03375 *)p)->f4 != 0)
            break;
    default:
        --**(int * *)&((struct Obj03375 *)p)->fC;
        sub_02031194(task);
        break;
    }
}

/*
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 */
void func_021BD7D4(char *owner, u8 index, int position, u8 direction, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl * *)&((struct Obj00051 *)owner)->f18, (void (*)(struct TcblNode *, void *))func_021BD854, 24, 0));
    MI_CpuFill8(work, 0, 24);
    *(char * *)&((struct Obj02553 *)work)->fC = owner + 0x15c + index * 128;
    ((struct Obj02553 *)work)->f0 = index;
    ((struct Obj02553 *)work)->f4 = (1 - position) * -192;
    if (direction == 0)
        ((struct Obj02553 *)work)->f6 -= 8;
    else
        ((struct Obj02553 *)work)->f6 += 8;
    ((struct Obj02553 *)work)->f1 = 24;
    func_021BD13C(((struct Obj02553 *)work)->fC, ((struct Obj02553 *)work)->f4);
    if (position != 1)
        func_021BD0E4(owner, ((struct Obj02553 *)work)->f0, 1);
    *(char * *)&((struct Obj02553 *)work)->f10 = owner;
    *(int * *)&((struct Obj02553 *)work)->f14 = counter;
    ++*counter;
}

void func_021BD854(struct TcblNode *task, char *p)
{
    u8 count;
    count = ((struct Obj02927 *)p)->f1;
    ((struct Obj02927 *)p)->f1 = count - 1;
    if (count != 0) {
        ((struct Obj02927 *)p)->f4 += ((struct Obj02927 *)p)->f6;
        func_021BD13C(((struct Obj02927 *)p)->fC, ((struct Obj02927 *)p)->f4);
        return;
    }
    if (((struct Obj02927 *)p)->f4 != 0)
        func_021BD0E4(((struct Obj02927 *)p)->f10, ((struct Obj02927 *)p)->f0, 0);
    --**(int * *)&((struct Obj02927 *)p)->f14;
    sub_02031194(task);
}

void func_021BD89C(char*p,int a){func_021BD8A8(p,a,(int*)(p+12));}

void func_021BD8A8(char *owner, int direction, int *counter)
{
    char *work;
    work = sub_02031290((struct S02030FB4 *)sub_020311B8(*(struct Tcbl * *)&((struct Obj00051 *)owner)->f18, (void (*)(struct TcblNode *, void *))func_021BD948, 24, 0));
    MI_CpuFill8(work, 0, 24);
    ((struct Obj05556 *)work)->f4 = direction;
    if (direction == 0) {
        ((struct Obj05556 *)work)->f3 = ((struct Obj00051 *)owner)->f30 + 1;
        func_021B6548(((struct Obj00051 *)owner)->f124, 3, 0);
    } else {
        ((struct Obj05556 *)work)->f3 = ((struct Obj00051 *)owner)->f30 - 1;
        func_021B6548(((struct Obj00051 *)owner)->f124, 2, 0);
    }
    func_021B6548(((struct Obj00051 *)owner)->f124, 1, 0);
    func_02165AC4(*(struct Queue * *)&((struct Obj00051 *)owner)->f24, *(struct Rec * *)&((struct Obj00051 *)owner)->f28, (u16 *)(owner + 0x2c), *(u8 *)(owner + 0x31 + ((struct Obj05556 *)work)->f3));
    func_021BD174(owner, ((struct Obj00051 *)owner)->f28, ((struct Obj00051 *)owner)->f2C, ((struct Obj00051 *)owner)->f2E ^ 1);
    *(char * *)&((struct Obj05556 *)work)->f10 = owner;
    *(int * *)&((struct Obj05556 *)work)->f14 = counter;
    ++*counter;
}

/*
 * Lever: explicit case 3 plus default preserves four switch arms; BD7D4 u8 index preserves the original XOR truncation pair, own int index notwithstanding.
 */
void func_021BD948(struct TcblNode *task,char *work)
{
    if(((struct Obj00690 *)work)->f5==0) {
        if(func_021B6448(*(u8 * *)&((struct Obj25787 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f124)!=-1)
            ((struct Obj00690 *)work)->f5=1;
    }
    if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj25788 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f12C)==0) return;
    switch(((struct Obj00690 *)work)->f0) {
    case 0:
        if(((struct Obj00690 *)work)->f5==0) break;
        func_021B64A8(*(u8 * *)&((struct Obj25789 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f124,0);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 1:
        func_021BD7D4(*(char * *)&((struct Obj00690 *)work)->f10,((struct Obj25790 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E,1,((struct Obj00690 *)work)->f4,(int *)(work+8));
        func_021BD7D4(*(char * *)&((struct Obj00690 *)work)->f10,((struct Obj25791 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E^1,d_021BDD88[((struct Obj00690 *)work)->f4],((struct Obj00690 *)work)->f4,(int *)(work+8));
        func_0204B3DC(*(struct Obj * *)&((struct Obj25792 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f264,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj25793 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f268,0);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 2:
        if(((struct Obj00690 *)work)->f8!=0) break;
        ((struct Obj25794 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E^=1;
        ((struct Obj25795 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f30=((struct Obj00690 *)work)->f3;
        func_021BD448(((struct Obj00690 *)work)->f10);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 3:
    default:
        --**(int * *)&((struct Obj00690 *)work)->f14;
        func_02031194(task);
        break;
    }
}

/*
 * lever: u16 c moves its r3 spill before the handle load and restores call setup; u32 leaves 24 concrete bytes different.
 */
void func_021BDA54(char *owner, char *record, u32 b, u16 c, u32 d, u16 f)
{
    void *handle;
    handle = ((struct Obj14721 *)owner)->f12C;
    sub_0201C724(handle, (u32)func_02045770((struct Descriptor *)((struct Obj08427 *)record)->f8), b, c, d, ((struct Obj14721 *)owner)->f128, f);
    ((struct Obj08427 *)record)->fC = 1;
    func_021BDAA0((u8 *)owner, (int)record, (int *)(owner + 12));
}

void func_021BDAA0(u8 *p,int arg,int *counter)
{
    Work *work;
    work=func_02031290((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj25797 *)p)->f18,(TcblFunc)func_021BDAD8,12,0));
    func_02082BCC(work,0,12);
    work->owner=p;
    work->arg=arg;
    if(counter!=0){work->counter=counter;++*counter;}
}
