/*
 * file:     unit_021DC860_p01.c
 * unit:     yes
 * function: func_021DC860, func_021DC894, func_021DC8A8, func_021DC8B8, func_021DC8D4, func_021DC8E4, func_021DC910, func_021DC924, func_021DC92C, func_021DCA40, func_021DCA7C, func_021DCB70, func_021DCB8C, func_021DCBA4, func_021DCBE8, func_021DCC0C, func_021DCC24, func_021DCC88, func_021DCCC8, func_021DCE28, func_021DCE70, func_021DCEA4, func_021DCF38, func_021DCFA8, func_021DCFD4, func_021DCFF4, func_021DD0E8, func_021DD10C, func_021DD218, func_021DD38C, func_021DD3F4, func_021DD4A4, func_021DD4D0, func_021DD500, func_021DD51C, func_021DD558, func_021DD5A8
 * address:  0x021DC860
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 *   d_02FE0000 0x02FE0000 data a4
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021DEB20 0x021DEB20 data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021DEA50 0x021DEA50 data a4
 *   d_021DEAC0 0x021DEAC0 data a4
 *   d_021DEAA0 0x021DEAA0 data a4
 *   d_021DEB00 0x021DEB00 data a4
 *   d_021DEA60 0x021DEA60 data a4
 *   d_021DEA80 0x021DEA80 data a4
 *   d_021DEAE0 0x021DEAE0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02041090  0x02041090  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_02022004 0x02022004 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02012F68 0x02012F68 thumb
 *   func_0200EC14 0x0200EC14 thumb
 *   func_0200EC98 0x0200EC98 thumb
 *   func_0200EC2C 0x0200EC2C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200725C 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   func_0200ECD0 0x0200ECD0 thumb
 *   func_0200ECC4 0x0200ECC4 thumb
 *   func_0200ED14 0x0200ED14 thumb
 *   func_0200ECF0 0x0200ECF0 thumb
 *   func_020072A4 0x020072A4 thumb
 *   d_021DEB5C 0x021DEB5C data a4
 *   func_021DE030 0x021DE030 thumb ov171
 *   func_021DD8DC 0x021DD8DC thumb ov171
 *   func_02034AC4  0x02034AC4  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_021DD874  0x021DD874  thumb  ov171
 *   func_021DDFE8  0x021DDFE8  thumb  ov171
 *   ov067_id       0x00000043  data
 *   func_021DE014 0x021DE014 thumb ov171
 *   func_021DD8BC 0x021DD8BC thumb ov171
 *   func_02034A5C 0x02034A5C arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_021DE0AC  0x021DE0AC  thumb  ov171
 *   func_021DE8A8 0x021DE8A8 thumb ov171
 *   func_020061E4 0x020061E4 thumb
 *   func_021DE388 0x021DE388 thumb ov171
 *   func_021DD964 0x021DD964 thumb ov171
 *   func_021DDAF0 0x021DDAF0 thumb ov171
 *   func_021DE080 0x021DE080 thumb ov171
 *   func_021DE76C 0x021DE76C thumb ov171
 *   func_021DDC28 0x021DDC28 thumb ov171
 *   func_021DD5D4 0x021DD5D4 thumb ov171
 *   func_021DD620 0x021DD620 thumb ov171
 *   d_021DEB50 0x021DEB50 data a4
 *   func_021DE914 0x021DE914 thumb ov171
 *   func_021DDFBC 0x021DDFBC thumb ov171
 *   func_021DD774 0x021DD774 thumb ov171
 *   func_0202208C 0x0202208C thumb
 *   func_021DE5F4 0x021DE5F4 thumb ov171
 *   func_021DE0E4 0x021DE0E4 thumb ov171
 */
#include "../../matched/include/Obj24047.h"
#include "../../matched/include/Obj24048.h"
#include "../../matched/include/Obj24049.h"
#include "../../matched/include/Obj24050.h"
#include "../../matched/include/Obj08249.h"
#include "../../matched/include/Obj10658.h"
#include "../../matched/include/Obj14284.h"
#include "../../matched/include/Obj03850.h"
#include "../../matched/include/Obj14285.h"
#include "../../matched/include/Obj14286.h"
#include "../../matched/include/Obj14287.h"
#include "../../matched/include/Obj14288.h"
#include "../../matched/include/Obj00347.h"
#include "../../matched/include/Obj24051.h"
#include "../../matched/include/Obj24052.h"
#include "../../matched/include/Obj01420.h"
#include "../../matched/include/Obj10659.h"
#include "../../matched/include/Obj00142.h"
#include "../../matched/include/Obj24053.h"
#include "../../matched/include/Obj24054.h"
#include "../../matched/include/Obj03310.h"

#define PTR(p,n) (*(void **)((p)+(n)))
struct Obj0203159C;
struct S020315D4;
struct S02021D50;
struct DispVram;
struct PalAnmSlot;
struct Obj02021EE4;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct Big;
struct Ctrl;
struct Dst0200EC2C;
struct Out0200EC98;
struct Src0200EC2C;
struct Sub020072A4Ctrl;
struct Sub020073D8Ctrl;
struct P;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig {u32 w[4];};

struct BgTemplate {u32 w[8];};

struct S { void *f0; u16 f4; };

struct Ent { void *a; void *b; u8 pad[0x14]; };

struct Row { struct Ent ents[6]; u8 hdr[0x10]; u16 cnt; u16 cnt2; };

struct P { struct S *s; u8 pad[8]; struct Row rows[15]; u8 pad2[0xC5F - 0xB10]; u8 n; };

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

typedef struct {s16 a,b;} Outputs;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C*,u32,u32);
extern void func_02082BCC(void*,u32,u32);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int func_020056A0(void (*)(void), int *, int);
extern int func_02030EAC(int);
extern void func_020419E4(void),func_0204A648(void);
extern void func_02021D50(struct S02021D50*);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void func_020403F4(unsigned),func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(u8 *p);
extern u32 func_0204162C(int a);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02022004(unsigned, unsigned, u16, unsigned, unsigned);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern u32 func_02021ED8(const char*);
extern void func_0207D63C(int, int, int, int, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02012F68(void **h);
extern int func_0200EC14(char *p);
extern void func_0200EC98(const u8 *o, struct Out0200EC98 *out);
extern void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_0200ECD0(char *o, int idx);
extern u32 func_0200ECC4(char *o, u32 n);
extern void func_0200ED14(u8 *o, int idx, void *out);
extern void func_0200ECF0(void *a0, u32 a1, void *a2, void *a3);
extern void func_020072A4(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void func_021DE030(u8*);
extern void func_021DD8DC(char*);
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021DD874(char *p);
extern void func_021DDFE8(u8 *p);
extern void func_021DE014(int *);
extern void func_021DD8BC(int *);
extern void func_02034A5C(int);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_020221A4(void);
extern int func_021DE0AC(int *p, int i);
extern int func_021DE8A8(char *);
extern void func_020061E4(u32 a);
extern void func_021DE388(char *p);
extern void func_021DD964(u8*);
extern void func_021DDAF0(u8*);
extern void func_021DE080(u8 *p, int i, int value);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021DE76C(u8 *p, int mode);
extern void func_021DDC28(u8 *p);
extern u8 func_021DD5D4(char *,s8,int,s8);
extern void func_021DD620(char *p, int step);
extern int func_021DE914(char *);
extern void func_021DDFBC(u8 *p);
extern int func_021DD774(char *);
extern void func_0202208C(void*,u32,u32,u32,u32,u32,u32);
extern int func_021DE5F4(char *);
extern void func_021DE0E4(u8 *,int,s16 *,s16 *);
int func_021DC860(struct Obj0203159C*p,void*unused,u32 n);
int func_021DC894(int a, int b, int c, int d);
int func_021DC8A8(void *p);
void func_021DC8B8(int *p);
int func_021DC8D4(int *p);
void func_021DC8E4(void*unused,const u8*p);
void func_021DC910(void);
void *func_021DC924(void);
void func_021DC92C(void);
void func_021DCA40(void);
void func_021DCA7C(void);
void func_021DCB70(int *p);
void func_021DCB8C(int *p);
void func_021DCBA4(char *p);
int func_021DCBE8(u8*p);
void func_021DCC0C(void);
void func_021DCC24(char *p);
void func_021DCC88(char *p);
void func_021DCCC8(struct P *p);
void func_021DCE28(char *p);
int func_021DCE70(u8*p);
void func_021DCEA4(u8 *p);
int func_021DCF38(int *p);
int func_021DCFA8(u8*p);
u32 func_021DCFD4(char *p);
int func_021DCFF4(char *p);
int func_021DD0E8(u8*p);
int func_021DD10C(char *p);
int func_021DD218(char *p);
int func_021DD38C(char *p);
int func_021DD3F4(char *p);
int func_021DD498(char *p);
int func_021DD4A4(u8*p,int v);
int func_021DD4D0(u8 *p, int value);
int func_021DD500(char *p, int i, int n, int v);
int func_021DD51C(char *p, s8 step);
int func_021DD558(char *p, s8 step);
int func_021DD5A8(u8 *p,int i);
extern u8 d_02FE0000[];
extern char d_021DEB20[];
extern const struct DispConfig d_021DEA50;
extern const struct BgTemplate d_021DEAC0,d_021DEAA0,d_021DEB00,d_021DEA60,d_021DEA80,d_021DEAE0;
extern u8 d_021DEB5C[];
extern u8 ov067_id[];
extern const u8 d_021DEB50[];

int func_021DC860(struct Obj0203159C*p,void*unused,u32 n){u32*q;func_0203064C(1,0x8c,0x60000);q=func_0203159C(p,0xc78,0x8c);func_02082BCC(q,0,0xc78);*q=n;return 1;}


int func_021DC894(int a, int b, int c, int d)
{
    if (func_021DCE70((u8 *)d))
        return 0;
    return 1;
}


int func_021DC8A8(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8c);
    return 1;
}


void func_021DC8B8(int *p)
{
    ((struct Obj24047 *)p)->fB28 = func_020056A0((void (*)(void))func_021DC8E4, p, 0);
}


int func_021DC8D4(int *p)
{
    return func_02030EAC(((struct Obj24048 *)p)->fB28);
}

/*
 * lever: enum address base preserves split pools; halfword offset closes r1/r2 allocation; const input retains reads.
 */
void func_021DC8E4(void*unused,const u8*p){enum Offset{check=0x3ff8};u16 off;enum Base{start=0x02fe0000};enum Base base;func_020419E4();func_0204A648();func_02021D50(*(struct S02021D50*const *)&((struct Obj24049 *)p)->fB30);base=start;off=check;*(u32*)((u32)base+off)|=1;}


void func_021DC910(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)0x021DEB20);
}

void *func_021DC924(void){return d_021DEB20;}

void func_021DC92C(void)
{
    struct DispConfig d;
    struct BgTemplate a,b,c,e,f,g;
    func_0203F8F4(140);
    d=d_021DEA50;func_0203FC28(&d);
    a=d_021DEAC0;func_0203FCA0(0,&a,0);
    b=d_021DEAA0;func_0203FCA0(1,&b,0);
    c=d_021DEB00;func_0203FCA0(2,&c,0);
    e=d_021DEA60;func_0203FCA0(3,&e,0);
    f=d_021DEA80;func_0203FCA0(4,&f,0);
    g=d_021DEAE0;func_0203FCA0(5,&g,0);
    func_020434DC(13,1);func_02043598(3,1);
}

void func_021DCA40(void){func_020434DC(15,0);func_02043598(3,0);func_020403F4(5);func_020403F4(4);func_020403F4(3);func_020403F4(2);func_020403F4(1);func_020403F4(0);func_0203F9B4();}


void func_021DCA7C(void)
{
    u8 *p = func_020490F4(0xd5, 0x808c);

    func_02049B68(p, 1, 0, 0, 0x80, 0x8c);
    func_02049B68(p, 6, 4, 0, 0x40, 0x8c);
    func_02049658(p, 0, 0, 0, 0, 1, 0x8c);
    func_02049658(p, 5, 4, 0, 0, 1, 0x8c);
    func_020498F4(p, 2, 0, 0, 0, 1, 0x8c);
    func_020498F4(p, 3, 1, 0, 0, 1, 0x8c);
    func_020498F4(p, 4, 2, 0, 0, 1, 0x8c);
    func_020498F4(p, 7, 4, 0, 0, 1, 0x8c);
    func_02049238(p);
    func_02041090(3, func_0204162C(0) + 0x540, 0, 0x15, 0x20, 3);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x8c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x8c);
}


void func_021DCB70(int *p)
{
    int x = (int)func_02021518(0x8c);

    ((struct Obj24050 *)p)->fB30 = x;
    func_0202155C((struct PalAnmSlot *)x, 2, 0x200, 0x8c);
}


void func_021DCB8C(int *p)
{
    func_020215A0((struct PalAnmSlot *)(((struct Obj08249 *)p)->fB30), 2);
    func_02021540((void *)(((struct Obj08249 *)p)->fB30));
}

void func_021DCBA4(char *p)
{
    unsigned i;
    for (i=0; i<6; i++)
        func_02022004(((struct Obj10658 *)p)->fB30, 2, (1<<i)|(1<<(i+6)), (unsigned char)p[0xb3a+i], 0);
    func_02021EE4((struct Obj02021EE4 *)(((struct Obj10658 *)p)->fB30), 1);
}

int func_021DCBE8(u8*p){if(func_02021ED8(*(char* *)&((struct Obj14284 *)p)->fB30))return 1;func_02021EE4((struct Obj02021EE4 *)(*(u32 *)&((struct Obj14284 *)p)->fB30),0);return 0;}


void func_021DCC0C(void)
{
    func_0207D63C(0x04000050, 6, 0x11, 0x10, 8);
}

void func_021DCC24(char *p)
{
    ((struct Obj03850 *)p)->fB60=func_02045B38(0,2,0x55,0x8c);
    ((struct Obj03850 *)p)->fB58=func_0201D7EC(0x17,0,0,0,0x8c);
    ((struct Obj03850 *)p)->fB5C=func_0201D7EC(0x17,3,0,0,0x8c);
    ((struct Obj03850 *)p)->fB64=func_0201EC64(0x8c);
    ((struct Obj03850 *)p)->fB6C=(void *)func_0201C440((void *)0x8c);
    ((struct Obj03850 *)p)->fB68=func_020457B0(0x400,0x8c);
}

void func_021DCC88(char *p)
{
    func_02045808(PTR(p,0xb68));
    func_0201C4C0(PTR(p,0xb6c));
    func_0201ED04(PTR(p,0xb64));
    func_0201D83C(PTR(p,0xb5c));
    func_0201D83C(PTR(p,0xb58));
    func_02045C04(PTR(p,0xb60));
}


/*
 * 2026-10-04 (wD1 lane18): control flow and registers match (r6=p, r7=row offset, p+0xC
 * temp hoisted after the guard). Residue: stack slot order of the spilled locals.
 * Original frame: temp d@0, i@4, o@8, c@0xc, j@0x10; compiled: c@0, o@4, i@8, d@0xc, j@0x10.
 * Declaration order did not change the slot order. Also the p+0xB4 operand: original
 * computes (p+0xB4) fresh then +r; compiled adds r first. Spelling p+0xB4+r hoists p+0xB4
 * into a spill (worse). Callee prototypes guessed (all thumb except func_020457B0).
 * 2026-10-04 (wD2 lane19): original temps by slot (low to high): d(p+0xC+r) @0, e(p+i*0xBC) @4, o @8, c @0xc, j @0x10.
 *   Declaring j,c,o,e,d,i,k at function scope reorders e/o/c but the d temp stays at 0xC; hoisting d before the k loop or
 *   `(u8*)((u32)(p+0xB4)+(u32)r)` grows the frame to 0x18 (worse). Residue: d temp slot and (p+0xB4)+r operand order.
 * 2026-10-05 (wD4 lane 08): DIFF, size now right (352 bytes), 49 diff lines. Found: the inner k loop has an explicit
 *   guard `if (count != 0) { for (...) ...; p[0xC5F]++; }` (original cmp r0,#0; beq past the ++, then the for guard).
 *   Residue: (1) stack slots (original d@0 i@4 o@8 c@0xc j@0x10, draft c@0 o@4 i@8 d@0xc); (2) the original forms
 *   (p+0xB4)+r and (p+0xC)+r (d computed once after the guard), the draft forms p+r first; p+0xB4+r spelling hoists both
 *   out of the j loop (364 bytes); (3) the original loads the 0xC5F pool word once for the ++, the draft twice.
 *   Tried: a Row struct array at p+0xC (stride 0xBC; ents[6] of 0x1c, hdr at +0xA8, cnt +0xB8): one pool load for the
 *   ++ but j*0xBC is computed twice (364 bytes); all accesses through the Row struct is worse (171 lines).
 * 2026-10-05 (wD5 lane 11): MATCH, all 352 bytes equal. Fix: a real struct (Row array at p+0xC, stride 0xBC:
 *   ents[6] of 0x1c, hdr[0x10] at +0xA8, cnt/cnt2 u16 at +0xB8/+0xBA; count byte at 0xC5F). &p->rows[j].hdr gives
 *   (p+0xB4)+r, &p->rows[j].ents[k] gives the hoisted (p+0xC)+r temp in the lowest slot, and locals j,c,o,i,k
 *   in that order give the frame. Only residue: func_0200ED14 (arm9, thumb) had no label. It is now filed EXACT
 *   as src/matched/arm9/func_0200ED14.c; once its shard exists this file should verify EXACT.
 */
void func_021DCCC8(struct P *p)
{
    u16 j;
    void *c;
    void *o;
    u16 i;
    u16 k;
    struct S *s;
    for (i = 0; i < 15; i++) {
        for (k = 0; k < 6; k++) {
            p->rows[i].ents[k].a = func_020457B0(0x20, 0x8c);
            p->rows[i].ents[k].b = func_020457B0(0x20, 0x8c);
        }
    }
    s = p->s;
    if (s->f4 == 0) {
        void *h = func_02012F68(s->f0);
        p->rows[0].cnt = func_0200EC14(h);
        func_0200EC98(h, (struct Out0200EC98 *)p->rows[0].hdr);
        for (k = 0; k < p->rows[0].cnt; k++)
            func_0200EC2C(h, k, (struct Dst0200EC2C *)(&p->rows[0].ents[k]));
        p->n = 1;
    } else {
        u32 id;
        c = func_02012EBC(s->f0);
        id = 8;
        if (func_0200725C(c, id, 0x8c) == 1) {
            o = func_020073D8(c, id, 0);
            if (o) {
                for (j = 0; j < 15; j++) {
                    p->rows[j].cnt = func_0200ECD0(o, j);
                    p->rows[j].cnt2 = func_0200ECC4(o, j);
                    func_0200ED14(o, j, p->rows[j].hdr);
                    if (p->rows[j].cnt != 0) {
                        for (k = 0; k < p->rows[j].cnt; k++)
                            func_0200ECF0(o, j, (void *)k, &p->rows[j].ents[k]);
                        p->n++;
                    }
                }
            }
        }
        func_020072A4(c, id);
    }
}

void func_021DCE28(char *p)
{
    unsigned short i, j;
    char *row;
    char *cell;
    for(i=0;i<15;i++) {
        row=p+i*0xbc;
        for(j=0;j<6;j++) {
            cell=row+j*0x1c;
            func_02045808(((struct Obj14285 *)cell)->fC);
            func_02045808(((struct Obj14285 *)cell)->f10);
        }
    }
}

int func_021DCE70(u8*p){typedef int(*Fn)(u8*);((struct Obj14286 *)p)->fC6C=(*(Fn*)((u32)d_021DEB5C+*(u32*)(p+0xc6c)*4))(p);if(((struct Obj14286 *)p)->fC6C==11)return 0;func_021DE030(p);func_021DD8DC((char*)p);return 1;}


void func_021DCEA4(u8 *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(0);
    func_0207D534((void *)0x0400006c, -0x10);
    func_0207D534((void *)0x0400106c, -0x10);
    func_021DCCC8((struct P *)p);
    func_021DC910();
    func_021DC92C();
    func_021DCA7C();
    func_021DCB70((int *)p);
    func_021DCC24((char *)p);
    func_021DD874((char *)p);
    func_021DDFE8(p);
    func_021DD0E8(p);
    func_021DCC0C();
    func_0203D34C(1, 0x8c);
    func_021DC8B8((int *)p);
    func_021DD4A4(p, 4);
}

int func_021DCF38(int *p)
{
    func_021DC8D4(p);
    func_021DE014(p);
    func_021DD8BC(p);
    func_021DCC88((char *)p);
    func_021DCB8C(p);
    func_021DCA40();
    func_021DCE28((char *)p);
    func_0207D534((void *)0x0400006c, -16);
    func_0207D534((void *)0x0400106c, -16);
    *(unsigned short *)0x04000050 = 0;
    *(unsigned short *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_02034A5C((int)ov067_id);
    return 11;
}

int func_021DCFA8(u8*p){if(func_0201C6B4(*(void* *)&((struct Obj14287 *)p)->fB6C)==1 && func_020221A4()==1)return ((struct Obj14287 *)p)->fC74;return 2;}


u32 func_021DCFD4(char *p)
{
    if (func_021DE0AC((int *)p, ((struct Obj14288 *)p)->fC64) == 0)
        return ((struct Obj14288 *)p)->fC68;
    return 3;
}

int func_021DCFF4(char *p) {
    int choice;
    if (!func_0201C6B4(((struct Obj00347 *)p)->fB6C)) return 4;
    choice=func_021DE8A8(p);
    switch(choice) {
    case 0:
        if (func_021DD51C(p,-1)==1) {
            func_020061E4(0x54b);
            return func_021DD500(p,12,12,5);
        }
        break;
    case 1:
        if (func_021DD51C(p,1)==1) {
            func_020061E4(0x54b);
            return func_021DD500(p,13,13,5);
        }
        break;
    case 2:
        func_020061E4(0x556);
        ((struct Obj24051 *)(*(char * *)&((struct Obj00347 *)p)->f0))->f6=1;
        return func_021DD500(p,14,8,10);
    case 3:
        func_020061E4(0x551);
        ((struct Obj24052 *)(*(char * *)&((struct Obj00347 *)p)->f0))->f6=0;
        return func_021DD500(p,15,9,10);
    case 4:
        func_020061E4(0x54c);
        ((struct Obj00347 *)p)->fC5D=((struct Obj00347 *)p)->fC5C;
        return 6;
    case 5: case 6: case 7: case 8: case 9: case 10:
        ((struct Obj00347 *)p)->fC5D=choice-5;
        func_020061E4(0x54c);
        return 6;
    }
    return 4;
}

int func_021DD0E8(u8*p){p[0xc5c]=0;func_021DE388((char *)p);func_021DD964(p);func_021DDAF0(p);return 4;}

int func_021DD10C(char *p) {
    s8 old;
    switch (((struct Obj01420 *)p)->fC70) {
    case 0:
        func_021DE080((u8 *)p,12,18);
        func_021DE080((u8 *)p,13,19);
        func_021DE080((u8 *)p,14,14);
        func_020434DC(2,1);
        func_021DE76C((u8 *)p,1);
        func_021DCBA4(p);
        (((struct Obj01420 *)p)->fC70)++;
        break;
    case 1:
        if (!func_021DCBE8((u8 *)p)) {
            ((struct Obj01420 *)p)->fC70=0;
            old=((struct Obj01420 *)p)->fC5C;
            if (((struct Obj01420 *)p)->fC5D==old) {
                ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
                func_021DDC28((u8 *)p);
                return 7;
            }
            ((struct Obj01420 *)p)->fC5C=((struct Obj01420 *)p)->fC5D;
            if (func_021DD5A8((u8 *)p,((struct Obj01420 *)p)->fC5D)==1) {
                ((struct Obj01420 *)p)->fC61=-d_021DEB50[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                func_021DD620(p,(s8)(-func_021DD5D4(p,old,((struct Obj01420 *)p)->fC5D,1)));
            } else {
                ((struct Obj01420 *)p)->fC61=d_021DEB50[*(u16 *)(p+((struct Obj01420 *)p)->fC5E*0xbc+0xc4)-1];
                func_021DD620(p,(s8)func_021DD5D4(p,old,((struct Obj01420 *)p)->fC5D,-1));
            }
            func_020061E4(0x57b);
            return 9;
        }
        break;
    }
    return 6;
}

int func_021DD218(char *p) {
    int choice;
    s8 old;
    if (!func_0201C6B4(((struct Obj00347 *)p)->fB6C)) return 7;
    choice = func_021DE914(p);
    switch (choice) {
    case 0:
        if (func_021DD558(p, 1) == 1) {
            ((struct Obj00347 *)p)->fC61 = -d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)(-1));
            func_020061E4(0x57b);
            return 9;
        }
        break;
    case 1:
        if (func_021DD558(p, -1) == 1) {
            ((struct Obj00347 *)p)->fC61 = d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)1);
            func_020061E4(0x57b);
            return 9;
        }
        break;
    case 3:
        func_020061E4(0x551);
        return func_021DD500(p, 15, 9, 8);
    case 5: case 6: case 7: case 8: case 9: case 10:
        old = ((struct Obj00347 *)p)->fC5C;
        if (choice - 5 == old) break;
        ((struct Obj00347 *)p)->fC5C = choice - 5;
        if (func_021DD5A8((u8 *)p, choice - 5) == 1) {
            ((struct Obj00347 *)p)->fC61 = -d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)(-func_021DD5D4(p, old, (s8)(choice - 5), 1)));
        } else {
            ((struct Obj00347 *)p)->fC61 = d_021DEB50[*(u16 *)(p + ((struct Obj00347 *)p)->fC5E * 0xbc + 0xc4) - 1];
            func_021DD620(p, (s8)func_021DD5D4(p, old, (s8)(choice - 5), -1));
        }
        func_020061E4(0x57b);
        return 9;
    }
    return 7;
}

int func_021DD38C(char *p)
{
    switch (((struct Obj10659 *)p)->fC70) {
    case 0:
        func_021DE76C((unsigned char *)p, 0);
        func_021DCBA4(p);
        func_020434DC(2, 0);
        ++((struct Obj10659 *)p)->fC70;
        break;
    case 1:
        if (!func_021DCBE8((unsigned char *)p)) {
            func_021DE080((u8 *)p, 12, 4);
            func_021DE080((u8 *)p, 13, 5);
            func_021DE080((u8 *)p, 14, 0);
            func_021DDFBC((u8 *)p);
            ((struct Obj10659 *)p)->fC70 = 0;
            return 4;
        }
        break;
    }
    return 8;
}

int func_021DD3F4(char *p)
{
    unsigned i;
    if (!func_021DD774(p)) {
        for (i = 0; i < *(u16 *)(p + ((struct Obj00142 *)p)->fC5E * 0xbc + 0xc4); ++i)
            *(u8 *)(p + i + 0xb34) = *(u8 *)(p + i + 0xb40);
        func_021DCBE8((u8 *)p);
        func_021DDC28((u8 *)p);
        return 7;
    } else {
        for (i = 0; i < *(u16 *)(p + ((struct Obj00142 *)p)->fC5E * 0xbc + 0xc4); ++i) {
            if (*(u8 *)(p + i + 0xb3a) > *(u8 *)(p + i + 0xb40))
                --*(u8 *)(p + i + 0xb3a);
            else if (*(u8 *)(p + i + 0xb3a) < *(u8 *)(p + i + 0xb40))
                ++*(u8 *)(p + i + 0xb3a);
        }
        func_021DCBA4(p);
        return 9;
    }
}

int func_021DD498(char *p)
{
    return func_021DD4D0((u8 *)p, 1);
}

int func_021DD4A4(u8*p,int v){func_0202208C(0,1,1,0,6,1,0x8c);((struct Obj24053 *)p)->fC74=v;return 2;}

int func_021DD4D0(u8 *p, int value)
{
    func_0202208C(0,0,0,0,6,1,140);
    ((struct Obj24054 *)p)->fC74=value;
    return 2;
}

/*
 * trailing: larger followers 0x021DD51C and 0x021DD558 have separate files.
 */
int func_021DD500(char *p, int i, int n, int v)
{
    func_021DE080((u8 *)p, i, n);
    ((struct Obj00347 *)p)->fC64 = i;
    ((struct Obj00347 *)p)->fC68 = v;
    return 3;
}

/*
 * lever: signed byte step avoids an extra truncation before the addition.
 */
int func_021DD51C(char *p, s8 step)
{
    int old;
    old = ((struct Obj00347 *)p)->fC5E;
    ((struct Obj00347 *)p)->fC5E += step;
    if (((struct Obj00347 *)p)->fC5E < 0)
        ((struct Obj00347 *)p)->fC5E = ((struct Obj00347 *)p)->fC5F - 1;
    else if (((struct Obj00347 *)p)->fC5E >= ((struct Obj00347 *)p)->fC5F)
        ((struct Obj00347 *)p)->fC5E = 0;
    if (((struct Obj00347 *)p)->fC5E != old)
        return 1;
    return 0;
}

int func_021DD558(char *p, s8 step)
{
    int old;
    old = ((struct Obj03310 *)p)->fC5C;
    ((struct Obj03310 *)p)->fC5C += step;
    if (((struct Obj03310 *)p)->fC5C < 0)
        ((struct Obj03310 *)p)->fC5C = *(u16 *)(p + ((struct Obj03310 *)p)->fC5E * 0xbc + 0xc4) - 1;
    else if (((struct Obj03310 *)p)->fC5C >= *(u16 *)(p + ((struct Obj03310 *)p)->fC5E * 0xbc + 0xc4))
        ((struct Obj03310 *)p)->fC5C = 0;
    if (((struct Obj03310 *)p)->fC5C != old)
        return 1;
    return 0;
}

int func_021DD5A8(u8 *p,int i)
{
    Outputs out;
    func_021DE0E4(p,(int)((u32)i+(u32)func_021DE5F4((char *)p)), &out.b, &out.a);
    if(out.b<128)return 1;
    return 0;
}
