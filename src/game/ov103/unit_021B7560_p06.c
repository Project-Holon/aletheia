/*
 * file:     unit_021B7560_p06.c
 * unit:     yes
 * function: func_021B7C64, func_021B7C68, func_021B7D08, func_021B7D30, func_021B7D44, func_021B7D4C, func_021B7D58, func_021B7DFC, func_021B7EB8, func_021B7F04, func_021B7F4C, func_021B7F50, func_021B7F60, func_021B7F78, func_021B7F7C, func_021B7FC8, func_021B7FF0, func_021B7FFC, func_021B8000, func_021B8004, func_021B8008, func_021B800C
 * address:  0x021B7C64
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021B9228 0x021B9228 data a4
 *   d_021B9234 0x021B9234 data a4
 *   d_021B9240 0x021B9240 data a4
 *   d_021B9218 0x021B9218 data a4
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_020479D8 0x020479D8 arm
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B92B4 0x021B92B4 data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_02046E24 0x02046E24 arm
 *   func_02046F50 0x02046F50 arm
 *   func_02046FF8 0x02046FF8 arm
 *   func_02047400 0x02047400 arm
 *   func_0204755C 0x0204755C arm
 *   func_02047564 0x02047564 arm
 *   func_0204767C 0x0204767C arm
 *   func_020477A4 0x020477A4 arm
 *   func_0206E5EC 0x0206E5EC arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   func_02047738 0x02047738 arm
 *   func_0204762C 0x0204762C arm
 *   func_02047504 0x02047504 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_02047910 0x02047910 arm
 *   func_02047828 0x02047828 arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047804 0x02047804 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B831C 0x021B831C thumb ov103
 *   func_020450F0 0x020450F0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj22180.h"
#include "../../matched/include/Obj22181.h"
#include "../../matched/include/Obj01708.h"
#include "../../matched/include/Obj10241.h"
#include "../../matched/include/Obj10242.h"
#include "../../matched/include/Obj06366.h"
#include "../../matched/include/Obj22183.h"
#include "../../matched/include/Obj10243.h"
#include "../../matched/include/Obj22184.h"
#include "../../matched/include/Obj07982.h"
#include "../../matched/include/Obj22185.h"
#include "../../matched/include/Obj22186.h"
#include "../../matched/include/Obj22187.h"
#include "../../matched/include/Obj22188.h"
#include "../../matched/include/Obj22189.h"

#define D (*(volatile u16 *)0x04000060)
struct Rec;
struct AnmCtl;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Cfg;
struct Descriptor;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct V3 { u32 a, b, c; };

struct Rec { u32 f0; u32 f4; u8 f8; u8 pad9[3]; u32 fC; u16 f10; };

extern void func_02046440(int, int, int, int, int, int, void *);
extern int func_02048A24(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *);
extern void func_02048AC4(void *);
extern void func_02046788(void);
extern void func_02047964(void);
extern void func_02048AD0(void *);
extern void func_020479D8(void);
extern void func_02047970(void);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
extern void func_02082BCC(void *,int,int);
extern void *func_02046E24(int,u16);
extern int func_02046F50(void *,int);
extern void func_02046FF8(void *);
extern void *func_02047400(void *,unsigned,void *);
extern int *func_0204755C(void *);
extern void *func_02047564(void *,const void *,int);
extern void *func_0204767C(void *,void *,int);
extern void func_020477A4(void *,u16);
extern void func_0206E5EC(int,int);
extern void func_0207ADC4(void *);
extern void func_02047738(struct Rec *p);
extern void func_0204762C(int);
extern void func_02047504(int);
extern void func_02046EFC(int);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02047828(int,int,int *);
extern void func_02047A60(int,void *);
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
extern void func_0201DD60(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045C04(void *);
extern void func_0201C4C0(void *);
extern void func_0201D83C(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021B831C(u8 *p);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
u32 func_021B7C64(u32 *p);
void func_021B7C68(u8 *p, int heap);
void func_021B7D08(u8 *p);
void func_021B7D30(u8 *p);
void func_021B7D44(void *a0);
u8 *func_021B7D4C(u8 *p, u16 i);
void func_021B7D58(void);
void func_021B7DFC(u8 *p, int a, const u16 *t, int c, int a4);
void func_021B7EB8(u8 *p);
void func_021B7F04(u8 *p);
u32 func_021B7F4C(u8 *p);
void func_021B7F50(char *p, struct V3 *q);
void func_021B7F60(u8 *p,int n);
u32 func_021B7F78(u8 *p);
void func_021B7F7C(u32 *p, int skip, u32 heap);
void func_021B7FC8(u8 *p);
u32 func_021B7FF0(u8 *p);
int func_021B7FFC(void *p);
int func_021B8000(void *p);
int func_021B8004(void *p);
int func_021B8008(void *p);
void func_021B800C(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g);
extern u8 d_021B9228[];
extern u8 d_021B9234[];
extern u8 d_021B9240[];
extern u8 d_021B9218[];
extern const u8 d_021B92B4[];


/*
 * First-word accessor.
 */
u32 func_021B7C64(u32 *p)
{
    return *p;
}


void func_021B7C68(u8 *p, int heap)
{
    void *arc;
    func_02046440(0, 1, 0, 1, 0, heap, (void *)func_021B7D58);
    *(int *)p = func_02048A24(2, 6 << 14, 0xFFFE8000, 0xFFFE0000, 1 << 17, 1 << 12, 250 << 14, 0,
                              d_021B9228, d_021B9234, d_021B9240, heap);
    arc = func_020490F4(0x5e, heap);
    func_021B7DFC(p + 4, (int)arc, (const u16 *)d_021B9218, 1, heap);
    func_021B7DFC(p + 0x64, (int)arc, (const u16 *)d_021B9218, 2, heap);
    func_02049238(arc);
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void func_021B7D08(u8 *p) { int i; for(i=0;i<2;i++)func_021B7EB8(p+4+i*0x60); func_02048AC4(((struct Obj22180 *)p)->f0); func_02046788(); }

void func_021B7D30(u8 *p) {func_02047964(); func_02048AD0(((struct Obj22181 *)p)->f0); func_020479D8();}

void func_021B7D44(void *a0) { func_02047970(); }


u8 *func_021B7D4C(u8 *p, u16 i) { return p + 4 + i * 0x60; }

/*
 * note: Full u16 cast around the BG0 priority update preserves the full complement and bics.
 * volatile: DISP3DCNT re-read at 021B7D72, 021B7D7E, 021B7D88, 021B7D92, 021B7D9E.
 */
void func_021B7D58(void) {
 unsigned i;
 func_020434DC(1,1);
 *(volatile u16 *)0x04000008 = (u16)(*(volatile u16 *)0x04000008 & ~3);
 D=(D & ~0x3002)|2;
 D &= (u16)~0x3010;
 D &= (u16)~0x3004;
 D=(D & ~0x3000)|8;
 D &= (u16)~0x3020;
 func_0207DC44(0,0,0,0);
 func_0207DD24(0,0,0x7fff,63,0);
 *(volatile unsigned *)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)func_02046A94((u8)i,(void *)(d_021B92B4+i*8));
 func_02046BE0(1,0);
}

void func_021B7DFC(u8 *p, int a, const u16 *t, int c, int a4) {int i,j; void *d=0; int *q; u8 *e; func_02082BCC(p,0,0x60); ((struct Obj01708 *)p)->f0=func_02046E24(a,t[0]); if(func_02046F50(((struct Obj01708 *)p)->f0,2)){d=((struct Obj01708 *)p)->f0; func_02046FF8(d);} if(func_02046F50(((struct Obj01708 *)p)->f0,1)) { i=0; ((struct Obj01708 *)p)->fC=func_02047400(((struct Obj01708 *)p)->f0,0,d); q=func_0204755C(((struct Obj01708 *)p)->fC); for(;i<2;i++) {e=p+i*4; ((struct Obj10241 *)e)->f4=func_02046E24(a,t[i+1]); ((struct Obj10241 *)e)->f14=func_02047564(((struct Obj01708 *)p)->fC,((struct Obj10241 *)e)->f4,0);} ((struct Obj01708 *)p)->f10=func_0204767C(((struct Obj01708 *)p)->fC,p+20,2); for(j=0;j<2;j++)func_020477A4(((struct Obj01708 *)p)->f10,j); func_0206E5EC(q[1],c); } func_0207ADC4(p+0x34); ((struct Obj01708 *)p)->f28=4096; ((struct Obj01708 *)p)->f2C=4096; ((struct Obj01708 *)p)->f30=4096; }

/*
 * note: 2-byte zero padding before the next labelled function.
 */
void func_021B7EB8(u8 *p) { int i; func_02047738((struct Rec *)(((struct Obj10242 *)p)->f10)); for(i=0;i<2;i++) {if(*(int *)(p+20+i*4))func_0204762C(*(int *)(p+20+i*4));} func_02047504(((struct Obj10242 *)p)->fC); for(i=0;i<2;i++)func_02046EFC(*(int *)(p+4+i*4)); func_02046EFC(((struct Obj10242 *)p)->f0); func_02082BCC(p,0,0x60); }

/*
 * note: Verified against the ov103 Thumb image.
 */
void func_021B7F04(u8 *p) { int i,x,y; if(((struct Obj06366 *)p)->f58) { for(i=0;i<2;i++) func_02047910((void *)(((struct Obj06366 *)p)->f10),(u16)i,4096); func_02047828(((struct Obj06366 *)p)->f10,0,&x); y=0; if(x==0)y=1; ((struct Obj06366 *)p)->f5C=y; func_02047A60(((struct Obj06366 *)p)->f10,p+0x1c); } }


u32 func_021B7F4C(u8 *p) { return ((struct Obj22183 *)p)->f5C; }

void func_021B7F50(char *p, struct V3 *q)
{
    *(struct V3 *)(p + 0x1c) = *q;
}

void func_021B7F60(u8 *p,int n) {if(((struct Obj10243 *)p)->f58!=n) {func_02047804(((struct Obj10243 *)p)->f10,0); ((struct Obj10243 *)p)->f58=n;}}


u32 func_021B7F78(u8 *p) { return ((struct Obj22184 *)p)->f58; }

void func_021B7F7C(u32 *p, int skip, u32 heap)
{
    func_02082BCC(p, 0, 16);
    func_0201DD60();
    if (skip == 0)
        p[0] = (u32)func_0201D7EC(23, 0, 0, 0, heap);
    p[2] = func_0201C440((void *)heap);
    p[1] = (u32)func_02045B38(0, 2, 47, heap);
    p[3] = (u32)func_0201EC64(heap);
}

void func_021B7FC8(u8 *p) {func_0201ED04(((struct Obj07982 *)p)->fC);func_02045C04(((struct Obj07982 *)p)->f4);func_0201C4C0(((struct Obj07982 *)p)->f8);func_0201D83C(((struct Obj07982 *)p)->f0);func_02082BCC(p,0,16);}

u32 func_021B7FF0(u8 *p) { return func_0201C4E4((struct PrintSys *)(((struct Obj22185 *)p)->f8)); }


/*
 * four int getters at +0, +8, +4, +c.
 */
int func_021B7FFC(void *p)
{
    return ((struct Obj22186 *)p)->f0;
}


int func_021B8000(void *p)
{
    return ((struct Obj22187 *)p)->f8;
}


int func_021B8004(void *p)
{
    return ((struct Obj22188 *)p)->f4;
}


int func_021B8008(void *p)
{
    return ((struct Obj22189 *)p)->fC;
}

void func_021B800C(struct Rec *p, int a, int b, u8 c, u8 d, u8 e, u8 f, u16 g)
{
    int q;
    func_02082BCC(p, 0, 20);
    p->f10 = 15;
    p->f0 = func_020450F0(a, b, c, d, e, f, 1);
    p->fC = (u32)func_020457B0(255, g);
    p->f4 = p->f0;
    p->f8 = 0;
    func_021B831C((u8 *)p);
    q = p->f0;
    func_02045334((void *)q);
    func_02045374((struct Cfg *)q);
    func_020409B4(func_02045730((struct Descriptor *)q));
}
