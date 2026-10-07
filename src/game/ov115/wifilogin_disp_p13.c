/*
 * file:     wifilogin_disp_p13.c
 * unit:     yes
 * function: func_021D5EA8, func_021D5ED8, func_021D5F7C, func_021D5FA0, func_021D5FC4, func_021D5FE8, func_021D603C, func_021D60D4, func_021D6104, func_021D6130, func_021D6134
 * address:  0x021D5EA8
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02027A04 0x02027A04 thumb
 *   func_02034714 0x02034714 arm
 *   d_021D663C 0x021D663C data a1
 *   func_02045CAC 0x02045CAC arm
 *   func_02045874 0x02045874 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   d_021D6544 0x021D6544 data a2
 *   func_0201FDA0 0x0201FDA0 thumb
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D4D38 0x021D4D38 thumb ov115
 *   func_021D5984 0x021D5984 thumb ov115
 *   func_021D6150 0x021D6150 thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_0203D34C 0x0203D34C arm
 *   func_021D5D3C 0x021D5D3C thumb ov115
 *   func_021D5A9C 0x021D5A9C thumb ov115
 *   func_021D4E04 0x021D4E04 thumb ov115
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021D5E48 0x021D5E48 thumb ov115
 *   func_021D4DF4 0x021D4DF4 thumb ov115
 *   func_021D5A88 0x021D5A88 thumb ov115
 *   func_021D613C 0x021D613C thumb ov115
 */
#include "../../matched/include/Obj10335.h"
#include "../../matched/include/Obj01720.h"
#include "../../matched/include/Obj08045.h"
#include "../../matched/include/Obj13854.h"
#include "../../matched/include/Obj03766.h"
#include "../../matched/include/Obj03767.h"
#include "../../matched/include/Obj10336.h"
#include "../../matched/include/Obj22603.h"
#include "../../matched/include/Obj06415.h"
#include "../../matched/include/Obj22604.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Obj0203159C;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef struct { u8 a, b, c, d; u16 e; } Record;

typedef enum { FALSE, TRUE } BOOL;

typedef signed char s8;

typedef int s32;

extern u8 func_02027A04(const u8 *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *d);
extern void *func_0201FDA0(const Record *, u16, u8, u8, u16);
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern u8 *func_021D4D38(u16 heap, u32 mode, int a2);
extern u8 *func_021D5984(u32 heap, u32 bank, u32 mode);
extern void func_021D6150(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_02005D90(int,int);
extern void func_0203D34C(u32 a, u32 b);
extern void func_021D5D3C(u8 *p);
extern void func_021D5A9C(u8 *);
extern void func_021D4E04(u8 *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
extern void func_021D5E48(u8 *p);
extern void func_021D4DF4(u8 *p);
extern void func_021D5A88(u8 *p);
extern int func_021D613C(u8 *);
u8 func_021D5EA8(u8 *p);
void func_021D5ED8(u8 *p,u32 n);
void func_021D5F7C(u8 *p);
u32 func_021D5FA0(u32 a);
u32 func_021D5FC4(u32 a);
void *func_021D5FE8(u8 *p, int mode, int n);
int func_021D603C(void *ctx,int unused,u8 *q);
int func_021D60D4(void *a,int b,u8 *c,u8 *p);
int func_021D6104(int a,int b,int c,u8 *p);
void func_021D6130(int *p, int v);
void func_021D6134(void *a0, int a1, int a2);
extern const char d_021D663C[];
extern const Record d_021D6544;

u8 func_021D5EA8(u8 *p) { switch(((struct Obj10335 *)p)->f0) { case 0: return func_02027A04(*(const u8 * *)&((struct Obj10335 *)p)->f20); case 1: return (u8)((struct Obj10335 *)p)->f28; default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }

void func_021D5ED8(u8 *p,u32 n) {
    void *w;
    void *s;
    func_02045CAC(((struct Obj01720 *)p)->f1C,n,((struct Obj01720 *)p)->f28);
    s=func_02045874(((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f4C);
    func_0201F250(((struct Obj01720 *)p)->f20,((struct Obj01720 *)p)->f28,s);
    if (((struct Obj01720 *)p)->f30==0) ((struct Obj01720 *)p)->f30=(void *)func_020450F0(func_021D5FC4(((struct Obj01720 *)p)->f50),1,1,30,16,11,1);
    w=((struct Obj01720 *)p)->f30;
    func_02043B5C(func_02045770(w),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(w),0,0,((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f24);
    func_0201F73C(w,(u32)1,(u16)(((struct Obj01720 *)p)->f4),(u32)12);
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(func_021D5FC4(((struct Obj01720 *)p)->f50));
    func_02045808(s);
}

void func_021D5F7C(u8 *p) { if(((struct Obj08045 *)p)->f30){func_0201F7A8(((struct Obj08045 *)p)->f30,2);func_020456F8(((struct Obj08045 *)p)->f30);func_02041B6C(func_021D5FC4(((struct Obj08045 *)p)->f50));} }

u32 func_021D5FA0(u32 a) { switch(a){case 1:return 1;case 0:return 5;default:func_02034714(d_021D663C,0,d_021D663C);return 0;} }

u32 func_021D5FC4(u32 a) { switch(a){case 1:return 2;case 0:return 5;default:func_02034714(d_021D663C,0,d_021D663C);return 0;} }

void *func_021D5FE8(u8 *p, int mode, int n) {
    Record r = d_021D6544;
    r.e = ((struct Obj13854 *)p)->f0;
    switch (mode) {
    case 0: r.b = 24; r.c = 13; break;
    case 1: r.b = 24; r.c = 19; break;
    }
    return func_0201FDA0(&r, r.e, 12, n, ((struct Obj13854 *)p)->f4C);
}

int func_021D603C(void *ctx,int unused,u8 *q) {
    u8 *p;
    BOOL flag;
    func_0203064C(1,121,0x18000);
    p=func_0203159C(ctx,32,121);
    func_02082BCC(p,0,32);
    *(u8 * *)&((struct Obj03766 *)p)->f10=q;
    ((struct Obj03766 *)p)->f14=121;
    if(((struct Obj03767 *)q)->f10==0) ((struct Obj03767 *)q)->f10=6;
    ((struct Obj03766 *)p)->f4=func_021D4D38(((struct Obj03766 *)p)->f14,*(int *)&((struct Obj03767 *)q)->f4,((struct Obj03767 *)q)->f8);
    ((struct Obj03766 *)p)->f8=func_021D5984(((struct Obj03766 *)p)->f14,232,((struct Obj03767 *)q)->f8);
    func_021D6134(p,(int)((void (*)(void))func_021D6150),173);
    if(((struct Obj03767 *)q)->f4==0) {
        func_021D5CCC(((struct Obj03766 *)p)->f8,36);
        if(((struct Obj03767 *)q)->fC==0) func_02005D90(1153,65535);
    }
    if(*(u32 *)&((struct Obj03767 *)q)->f8==0) flag=FALSE; else flag=TRUE;
    func_0203D34C(flag,((struct Obj03766 *)p)->f14);
    return 1;
}

int func_021D60D4(void *a,int b,u8 *c,u8 *p) { if(!((struct Obj22603 *)c)->f4)func_021D5D3C(((struct Obj10336 *)p)->f8);func_021D5A9C(*(u8 * *)&((struct Obj10336 *)p)->f8);func_021D4E04(*(u8 * *)&((struct Obj10336 *)p)->f4);func_020315D4(a);func_020306F0(121);return 1; }

int func_021D6104(int a,int b,int c,u8 *p) { int result;if(((struct Obj06415 *)p)->f0)func_021D5E48(((struct Obj06415 *)p)->f0);func_021D4DF4(((struct Obj06415 *)p)->f4);func_021D5A88(((struct Obj06415 *)p)->f8);result=0;if(func_021D613C(p))result=1;return result; }


void func_021D6130(int *p, int v)
{
    ((struct Obj22604 *)p)->fC = v;
}

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_021D6130          -> unresolved: 021D6130 (arm, from name) has no witness outside 021D6134..021D613C; 9 overlays overlap this address (ov016, ov021, ov093, ov115, ov118, ov120, ov123, ov131, ov175), none resolvable without a region hint on the symbols: line
 */
void func_021D6134(void *a0, int a1, int a2) { func_021D6130(a0, a1); }
