/*
 * file:     namein_graphic_p02.c
 * unit:     yes
 * function: func_021F1D58, func_021F1E28, func_021F1F7C, func_021F1FB4, func_021F2150, func_021F2190, func_021F21BC, func_021F21FC, func_021F22AC, func_021F22E8, func_021F2328, func_021F233C, func_021F235C, func_021F2394, func_021F23B8, func_021F23E4, func_021F23F4, func_021F23F8, func_021F23FC, func_021F253C, func_021F256C, func_021F25F8, func_021F2608, func_021F2614, func_021F265C, func_021F26E0, func_021F26F0, func_021F2818, func_021F2828, func_021F2884, func_021F28FC, func_021F299C, func_021F2A88, func_021F2BC8, func_021F2F60, func_021F2F68
 * address:  0x021F1D58
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020457B0  0x020457B0  arm
 *   func_021F4DBC  0x021F4DBC  thumb  ov194
 *   func_021F4F50  0x021F4F50  thumb  ov194
 *   func_021F1998  0x021F1998  thumb  ov194
 *   func_020458F8  0x020458F8  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02045A38  0x02045A38  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B95C  0x0204B95C  arm
 *   func_021F4F60 0x021F4F60 thumb ov194
 *   func_021F4DD0 0x021F4DD0 thumb ov194
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045994 0x02045994 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_0204B8C4 0x0204B8C4 arm
 *   GX_GetBankForLCDC 0x02045A98 arm
 *   func_021F4ED8 0x021F4ED8 thumb ov194
 *   func_021F4E18 0x021F4E18 thumb ov194
 *   func_021F4DDC 0x021F4DDC thumb ov194
 *   func_021F4F7C 0x021F4F7C thumb ov194
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_021F4E58 0x021F4E58 thumb ov194
 *   func_021F4E98 0x021F4E98 thumb ov194
 *   func_021F4D94 0x021F4D94 thumb ov194
 *   func_021F2F8C 0x021F2F8C thumb ov194
 *   d_021F555C 0x021F555C data a4
 *   func_021F4DA4 0x021F4DA4 thumb ov194
 *   func_021F4450 0x021F4450 thumb ov194
 *   func_0201D42C 0x0201D42C thumb
 *   func_021F4DA0 0x021F4DA0 thumb ov194
 *   func_021F4D9C 0x021F4D9C thumb ov194
 *   d_021F5544 0x021F5544 data a4
 *   d_021F5550 0x021F5550 data a4
 */
#include "../../matched/include/Obj10806.h"
#include "../../matched/include/Obj00418.h"
#include "../../matched/include/Obj03896.h"
#include "../../matched/include/Obj02909.h"
#include "../../matched/include/Obj01574.h"
#include "../../matched/include/Obj08342.h"
#include "../../matched/include/Obj10807.h"
#include "../../matched/include/Obj05509.h"
#include "../../matched/include/Obj24901.h"
#include "../../matched/include/Obj03897.h"
#include "../../matched/include/Obj14496.h"
#include "../../matched/include/Obj24902.h"
#include "../../matched/include/Obj24903.h"
#include "../../matched/include/Obj14497.h"
#include "../../matched/include/Obj02530.h"
#include "../../matched/include/Obj10808.h"
#include "../../matched/include/Obj14499.h"
#include "../../matched/include/Obj14500.h"
#include "../../matched/include/Obj14501.h"

struct Actor;
struct Cfg;
struct Descriptor;
struct Obj;
struct U16Vec;
struct Vec2;
struct CharBuf;
struct StrObj;
struct Strbuf;
struct PrintSys;
typedef unsigned char u8;

typedef short s16_021F1D58;

typedef s16_021F1D58 fx16;

typedef unsigned short u16;

typedef unsigned int u32_021F1D58;

typedef signed int     s32;

typedef unsigned int u32_021F1E28;

typedef unsigned int u32_021F1F7C;

typedef unsigned u32_021F1FB4;

typedef unsigned int u32;

typedef struct {u8 removedCount,addedCount;u16 removed[4],added[4];} Changes;

typedef unsigned int u32_021F23B8;

typedef signed char s8;

typedef signed short s16_021F23B8;

typedef struct {u8 count,pad;u16 values[4];} Group;

typedef struct {int x,y;} Pair;

typedef unsigned u32_021F26E0;

typedef struct {int x,y,z,w;} Box;

typedef int (*Conv)(Pair *, Pair *);

extern s32 func_02061CA4(void *p, u32_021F1D58 a, u32_021F1D58 b, s32 size);
extern void func_02082BCC(void *,unsigned,unsigned);
extern u32_021F1E28 func_020450F0(u32_021F1E28 layer, u32_021F1E28 a, u32_021F1E28 b, u32_021F1E28 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32_021F1E28 index);
extern struct U16Vec *func_020457B0(u32_021F1E28 capacity, u32_021F1E28 heapId);
extern int func_021F4DBC(int a, int b);
extern int func_021F4F50(int a);
extern void *func_021F1998(u8 *p, u32_021F1E28 i);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern void func_02045A38(struct U16Vec *vec, u16 *out, u32_021F1E28 n);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32_021F1E28 v);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021F1E28 which);
extern void func_0204B3DC(struct Obj *p, u32_021F1E28 v);
extern void func_0204B95C(struct Actor *a);
extern void func_021F4F60(void *);
extern void func_021F4DD0(void *);
extern void func_02045808(struct U16Vec *vec);
extern u32_021F1F7C func_020452E8(struct Descriptor *d);
extern void func_0201F41C(const u16 *,u16 *,u32_021F1FB4);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32_021F1FB4 len);
extern u32_021F1FB4 func_0201D304(struct StrObj *s, u32_021F1FB4 a, u32_021F1FB4 b);
extern void func_0201C724(void *owner, u32_021F1FB4 a, u32_021F1FB4 b, u32_021F1FB4 c, u32_021F1FB4 d, u32_021F1FB4 e, u16 f);
extern void func_0201C6FC(struct PrintSys *p, u32_021F1FB4 a, u32_021F1FB4 b, u32_021F1FB4 c, void *s, u32_021F1FB4 e);
extern void func_0204B8C4(struct Obj *p, u32_021F1FB4 value);
extern unsigned int GX_GetBankForLCDC(void);
extern u16 func_021F4ED8(const char *p, const u16 *b);
extern int func_021F4E18(int,int,u16 *,int,u8 *);
extern void func_021F4DDC(const char *p, int i, u16 *dst, u32 n, u8 *count);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern int func_021F4E58(int,int,u16 *,int,u8 *);
extern int func_021F4E98(char *,int,u16 *,unsigned,u8 *);
extern u32_021F23B8 func_021F4D94(const unsigned char *p, u32_021F23B8 i);
extern int func_021F2F8C(Pair *,Pair *);
extern unsigned func_021F4DA4(unsigned char *,unsigned short,unsigned short);
extern int func_021F4450(int *,int *);
extern u32_021F26E0 func_0201D42C(struct StrObj *s, void *font);
extern u16 func_021F4DA0(const u16 *p);
extern u16 func_021F4D9C(const u16 *p);
int func_021F1D58(u16 *out, u16 *phase, u32_021F1D58 step, u32_021F1D58 row, u8 idx, u16 a, u16 b);
void func_021F1E28(u8 *p, int a, u16 b, u16 c, int d, u8 *e, int f);
void func_021F1F7C(u8 *p);
int func_021F1FB4(u8 *p);
int func_021F2150(unsigned char *p);
int func_021F2190(char *p, unsigned short v);
int func_021F21BC(unsigned char *p, unsigned short a, u32 b);
int func_021F21FC(u8 *a,int b);
int func_021F22AC(char *p);
int func_021F22E8(unsigned char *p);
void func_021F2328(char *self, struct Strbuf *dst);
void func_021F233C(char *p);
void func_021F235C(char *p);
void func_021F2394(u8 *p);
void func_021F23B8(char *p,const u16 *q);
int func_021F23E4(char *p);
u32_021F23B8 func_021F23F4(const u8 *p);
u32_021F23B8 func_021F23F8(const u8 *p);
int func_021F23FC(u8 *p,int direction);
int func_021F253C(u8 *p);
void func_021F256C(char *p, unsigned mode, int index, void *table, u32_021F23B8 a4);
void func_021F25F8(int *a, int b, int c);
void func_021F2608(void *p);
unsigned func_021F2614(char *p,int *input,unsigned short *out);
int func_021F265C(const char *p,int *point,Pair *out);
void func_021F26E0(char *a, int b, int c);
void func_021F26F0(char *p,char *target,void *window,void *font,u16 heap);
int func_021F2818(char *a, Pair *b, Box *c);
int func_021F2828(const char *p,int target,Pair *out);
void func_021F2884(Pair *p, int oldmode, int newmode);
int func_021F28FC(const int *p,int *out);
int func_021F299C(Pair *p,Box *out);
void func_021F2A88(int *p,int *delta,u8 *saved);
void func_021F2BC8(int *p,int *delta,unsigned char *s);
int func_021F2F60(const int *p,int *out);
int func_021F2F68(const int *p,int *out);
extern fx16 FX_SinCosTable_[];
extern const unsigned char d_021F555C[];
extern const int d_021F5544[];
extern const int d_021F5550[];




static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }




/*
 * note 2026-10-05 (wD9r lane18): closed by the NitroSDK FX_CosIdx inline for the table read
 *   (earlier drafts wrote the raw tbl[(*phase >> 4) * 2 + 1] expression) and the ov105 021B8734
 *   lerp body (u8 r, g, blue; int dr, dg, db) with g before the cosine and an s16_021F1D58 t.
 */
int func_021F1D58(u16 *out, u16 *phase, u32_021F1D58 step, u32_021F1D58 row, u8 idx, u16 a, u16 b)
{
    u8 r, g, blue; int dr, dg, db; s16_021F1D58 t;
    int ph = *phase + step;
    if (ph >= 0x10000) *phase = ph - 0x10000;
    else *phase = ph;
    g = (a & 0x3E0) >> 5;
    t = (FX_CosIdx(*phase) + 0x1000) / 2;
    r = a & 31;
    blue = (a & 0x7C00) >> 10;
    db = ((u8)((b & 0x7C00) >> 10) - blue) * t >> 12;
    dr = ((u8)(b & 31) - r) * t >> 12;
    dg = ((u8)((b & 0x3E0) >> 5) - g) * t >> 12;
    *out = (u8)(r + dr) | ((u8)(g + dg) << 5) | ((u8)(blue + db) << 10);
    func_02061CA4((void *)0xF, row * 32 + idx * 2, (u32_021F1D58)out, 2);
    return *out == b;
}




/*
 * note 2026-10-05 (wD7 lane05): the entry spill order (b before a) follows the type of the
 *   fourth parameter: c as u16 closes it (as int the compiler spills a, b, c).
 */
void func_021F1E28(u8 *p, int a, u16 b, u16 c, int d, u8 *e, int f)
{
    u16 pos[2];
    int i;
    int h;
    int base;
    func_02082BCC(p, 0, 0x94);
    i = 0;
    *(int *)(p + 0x34) = c;
    *(u16 *)(p + 0x22) = b;
    *(int *)(p + 0x38) = d;
    h = func_020450F0(0, 8, 2, 0x18, 2, 15, 1);
    *(int *)(p + 0x40) = h;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
    *(int *)(p + 0x2c) = *(int *)(p + 0x40);
    *(u8 *)(p + 0x30) = i;
    *(int *)(p + 0x3c) = (int)func_020457B0(0xe, f);
    for (i = 0; i < 3; i++) {
        *(int *)(p + i * 4 + 0x84) = func_021F4DBC(i, f);
    }
    *(int *)(p + 0x90) = func_021F4F50(f);
    for (i = 0; i < 16; i++) {
        *(int *)(p + i * 4 + 0x44) = (int)func_021F1998(e, i);
    }
    if (func_020458F8((struct U16Vec *)a) == 0) {
        *(u16 *)p = func_02045A98();
    } else {
        func_02045A38((struct U16Vec *)a, (u16 *)p, b + 1);
        *(u16 *)(p + 0x1e) = func_020458F8((struct U16Vec *)a);
    }
    pos[1] = 0x25;
    base = 0x40 - (*(u16 *)(p + 0x22) * 14) / 2;
    if (base < 0) {
        base = 0;
    }
    base += 0x40;
    for (i = 0; i < 16; i++) {
        pos[0] = base + i * 14;
        func_0204B878((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
        func_0204B92C((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
        func_0204B404((struct Obj *)(*(int *)(p + i * 4 + 0x44)), (const struct Vec2 *)pos, 0);
        func_0204B3DC((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 1);
    }
    for (i = *(u16 *)(p + 0x22); i < 16; i++) {
        func_0204B3DC((struct Obj *)(*(int *)(p + i * 4 + 0x44)), 0);
    }
    func_0204B95C((struct Actor *)(*(int *)(p + *(u16 *)(p + 0x1e) * 4 + 0x44)));
    *(int *)(p + 0x28) = 1;
    func_021F1FB4(p);
}




void func_021F1F7C(u8 *p) { int i;func_021F4F60(((struct Obj10806 *)p)->f90);for(i=0;i<3;i++)func_021F4DD0(*(void **)((u32_021F1F7C)p+(u32_021F1F7C)i*4+132));func_02045808(((struct Obj10806 *)p)->f3C);func_020452E8((struct Descriptor *)(((struct Obj10806 *)p)->f40));func_02082BCC(p,0,148); }




/*
 * lever: load window in each print arm; p+i*4+0x44 preserves per-element bases and constant registers.
 */
int func_021F1FB4(u8 *p)
{
 u16 table[14];
 u16 pair[2];
 int i,x;
 void *window;
 if(((struct Obj00418 *)p)->f28){
  if(((struct Obj00418 *)p)->f1E)func_0201F41C((u16 *)p,table,((struct Obj00418 *)p)->f1E+1);
  if(((struct Obj00418 *)p)->f20)func_0201F41C((u16 *)(p+0x16),table+((struct Obj00418 *)p)->f1E,((struct Obj00418 *)p)->f20+1);
  if(((struct Obj00418 *)p)->f1E+((struct Obj00418 *)p)->f20>0){
   func_02043B5C(func_02045770(((struct Obj00418 *)p)->f40),0);
   for(i=0;i<((struct Obj00418 *)p)->f1E+((struct Obj00418 *)p)->f20;i++){
    pair[0]=table[i];pair[1]=func_02045A98();
    func_02045994(((struct Obj00418 *)p)->f3C,pair,2);
    x=64-(((struct Obj00418 *)p)->f22*14)/2;if(x<0)x=0;
    x+=i*14+7;
    x-=func_0201D304(((struct Obj00418 *)p)->f3C,((struct Obj00418 *)p)->f34,0)/2;
    if(i>=((struct Obj00418 *)p)->f1E){window=((struct Obj00418 *)p)->f38;func_0201C724(window,(u32_021F1FB4)func_02045770(((struct Obj00418 *)p)->f2C),(short)x,0,(u32_021F1FB4)(((struct Obj00418 *)p)->f3C),((struct Obj00418 *)p)->f34,0xc80);}
    else {window=((struct Obj00418 *)p)->f38;func_0201C6FC(window,(u32_021F1FB4)func_02045770(((struct Obj00418 *)p)->f2C),(short)x,0,((struct Obj00418 *)p)->f3C,((struct Obj00418 *)p)->f34);}
    p[0x30]=1;
   }
  }else{
   func_02043B5C(func_02045770(((struct Obj00418 *)p)->f40),0);
   func_02045334(((struct Obj00418 *)p)->f40);
  }
  for(i=0;i<((struct Obj00418 *)p)->f22;i++){
   func_0204B8C4(*(void **)(p+i*4+0x44),0);
   func_0204B878(*(void **)(p+i*4+0x44),1);
   func_0204B3DC(*(void **)(p+i*4+0x44),1);
  }
  for(;i<16;i++){
   func_0204B8C4(*(void **)(p+i*4+0x44),0);
   func_0204B878(*(void **)(p+i*4+0x44),1);
   func_0204B3DC(*(void **)(p+i*4+0x44),0);
  }
  for(i=0;i<=((struct Obj00418 *)p)->f1E && i<((struct Obj00418 *)p)->f22;i++)func_0204B3DC(*(void **)(p+i*4+0x44),1);
  func_0204B878(*(void **)(p+0x44+((struct Obj00418 *)p)->f1E*4),0);
  ((struct Obj00418 *)p)->f28=0;
 }
 return func_021F22E8(p);
}





int func_021F2150(unsigned char *p)
{
    if (((struct Obj03896 *)p)->f20 != 0) {
        ((struct Obj03896 *)p)->f20 -= 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj03896 *)p)->f20 * 2) =
            func_02045A98();
        ((struct Obj03896 *)p)->f28 = 1;
        return 1;
    }
    if (((struct Obj03896 *)p)->f1E != 0) {
        ((struct Obj03896 *)p)->f1E -= 1;
        *(unsigned short *)(p + ((struct Obj03896 *)p)->f1E * 2) =
            func_02045A98();
        ((struct Obj03896 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}





int func_021F2190(char *p, unsigned short v)
{
    if (((struct Obj02909 *)p)->f1E < ((struct Obj02909 *)p)->f22)
    {
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = v;
        ((struct Obj02909 *)p)->f1E += 1;
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = GX_GetBankForLCDC();
        ((struct Obj02909 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}





int func_021F21BC(unsigned char *p, unsigned short a, u32 b)
{
    if (((struct Obj01574 *)p)->f1E < ((struct Obj01574 *)p)->f22 &&
        ((struct Obj01574 *)p)->f20 < 3) {
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) = a;
        ((struct Obj01574 *)p)->f20 += 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) =
            func_02045A98();
        func_021F23FC(p, b);
        ((struct Obj01574 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}




/*
 * lever: shared failure label retains one exit; byte-offset cast +10 inside the loop
 * materialises the added-array base after the entry guard, unlike change.added.
 */
int func_021F21FC(u8 *a,int b)
{
    void *p;
    u16 v;
    Changes change;
    int i;
    u16 *tab;
    switch(b) {
    case 0: p=((struct Obj08342 *)a)->f84; break;
    case 1: p=((struct Obj08342 *)a)->f88; break;
    default:return 0;
    }
    if (((struct Obj08342 *)a)->f1E==0) goto fail;
    v=func_021F4ED8(p,(u16 *)(a+(((struct Obj08342 *)a)->f1E-1)*2));
    if(v==65535) goto fail;
    if(!func_021F4E18((int)p,v,change.added,4,&change.addedCount)) goto fail;
    func_021F4DDC(p,v,change.removed,4,&change.removedCount);
    for(i=0;i<change.removedCount;i++) func_021F2150(a);
    for(i=0;i<change.addedCount;i++) {
        tab=(u16 *)((u8 *)&change+10);
        func_021F2190((char *)a,tab[i]);
    }
    return 1;
fail:
    return 0;
}




int func_021F22AC(char *p) { u16 v;if(((struct Obj10807 *)p)->f1E!=0 && func_021F4F7C(*(char * *)&((struct Obj10807 *)p)->f90,(u16 *)((u32)p+(((struct Obj10807 *)p)->f1E-1)*2),&v)) { func_021F2150((u8 *)p);func_021F2190(p,v);return 1; }return 0; }





int func_021F22E8(unsigned char *p)
{
    int c = p[0x30];
    int r4 = ((struct Obj05509 *)p)->f38;

    if (c != 0) {
        if (func_0201C6C4((struct PrintSys *)r4, (void *)((int)func_02045770((struct Descriptor *)((struct Obj05509 *)p)->f2C))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj05509 *)p)->f2C);
            p[0x30] = 0;
        }
    }
    return p[0x30] == 0;
}





void func_021F2328(char *self, struct Strbuf *dst)
{
    func_02045994(dst, (const u16 *)self,
                 ((struct Obj24901 *)self)->f1E + 1);
}





void func_021F233C(char *p)
{
    if (((struct Obj03897 *)p)->f20 != 0)
    {
        unsigned int v;
        ((struct Obj03897 *)p)->f20 = 0;
        v = GX_GetBankForLCDC();
        *(unsigned short *)(p + 0x16 + (((struct Obj03897 *)p)->f20 << 1)) = v;
        ((struct Obj03897 *)p)->f28 = 1;
    }
}




void func_021F235C(char *p) { int i; for(i=0;i<((struct Obj02909 *)p)->f20;i++)func_021F2190(p,*(u16 *)((u32)p+(u32)i*2+22));((struct Obj02909 *)p)->f20=0;*(u16 *)((u32)p+((struct Obj02909 *)p)->f20*2+22)=func_02045A98();((struct Obj02909 *)p)->f28=1; }




void func_021F2394(u8 *p) {if(((struct Obj03897 *)p)->f1E) {((struct Obj03897 *)p)->f1E=0;*(u16 *)(p+((struct Obj03897 *)p)->f1E*2)=func_02045A98();((struct Obj03897 *)p)->f28=1;}func_021F233C((char *)p);}





void func_021F23B8(char *p,const u16 *q) {while(*q!=func_02045A98()) {if(!func_021F2190(p,*q)) break;q++;}}






int func_021F23E4(char *p)
{
    return ((struct Obj14496 *)p)->f1E == ((struct Obj14496 *)p)->f22;
}





u32_021F23B8 func_021F23F4(const u8 *p) {return ((struct Obj24902 *)p)->f1E;}





u32_021F23B8 func_021F23F8(const u8 *p) {return ((struct Obj24903 *)p)->f20;}





/*
 * lever: read Group values through ((u16 *)((char *)&group+2))[i] to hoist its member base.
 */
int func_021F23FC(u8 *p,int direction)
{
 Group group;
 int (*pick)(int,int,u16 *,int,u8 *);
 int i,j;
 u16 index;
 pick=direction?func_021F4E58:func_021F4E18;
 for(i=0;i<((struct Obj01574 *)p)->f20;i++){
  index=func_021F4ED8(((struct Obj01574 *)p)->f8C,(u16 *)(p+0x16+i*2));
  if(index==0xffff)continue;
  for(j=0;j<i;j++)func_021F2190((char *)p,*(u16 *)(p+0x16+j*2));
  for(j=0;j<i;j++)func_021F2150(p);
  if(pick(*(int *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count)){
   for(i=0;i<group.count;i++)func_021F2190((char *)p,*((u16 *)((char *)&group+2)+i));
   func_021F4DDC(((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++)func_021F2150(p);
   func_021F4E98(*(char * *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++){
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=*((u16 *)((char *)&group+2)+i);
    ((struct Obj01574 *)p)->f20+=1;
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=func_02045A98();
   }
   return 1;
  }
 }
 return 0;
}





int func_021F253C(u8 *p) {int i,spaces,n;n=*(volatile u16 *)&((struct Obj14497 *)p)->f1E;if(!n) return 0;spaces=0;i=0;while(i<n) {if(*(u16 *)(p+i*2)==32) spaces++;n=*(volatile u16 *)&((struct Obj14497 *)p)->f1E;i++;}return i!=spaces;}





void func_021F256C(char *p, unsigned mode, int index, void *table, u32_021F23B8 a4) {
 int i;
 func_02082BCC(p,0,36);((struct Obj02530 *)p)->f0=(void *)func_021F4D94(table,index);
 switch(mode) {
 case 3:
 ((struct Obj02530 *)p)->f20=11;((struct Obj02530 *)p)->f22=4;
 ((struct Obj02530 *)p)->f14=func_021F299C;((struct Obj02530 *)p)->f18=func_021F2BC8;((struct Obj02530 *)p)->f1C=func_021F2F8C;break;
 case 0:case 1:case 2:
 ((struct Obj02530 *)p)->f20=13;((struct Obj02530 *)p)->f22=6;
 ((struct Obj02530 *)p)->f14=func_021F28FC;((struct Obj02530 *)p)->f18=func_021F2A88;((struct Obj02530 *)p)->f1C=func_021F2F68;break;
 }
 for(i=0;i<13;i++)*(unsigned char *)(p+4+i)=d_021F555C[i];
}






void func_021F25F8(int *a, int b, int c)
{
    *a = func_021F4D94((const u8 *)c, b);
}





void func_021F2608(void *p) {func_02082BCC(p,0,36);}





unsigned func_021F2614(char *p,int *input,unsigned short *out) {
 int xy[2]; unsigned result;
 result=((unsigned (*)(int *,int *))*(void **)(p+0x1C))(input,xy);
 if(result==1 || result==10 || result==11) {
  if(out) *out=func_021F4DA4(*(unsigned char * *)&((struct Obj10808 *)p)->f0,xy[0],xy[1]);
 } else if(result==9) {if(out) *out=32;}
 return result;
}





int func_021F265C(const char *p,int *point,Pair *out) {
 Pair xy; int rect[4];
 for(xy.y=0;xy.y<*(const unsigned short *)&((struct Obj14499 *)p)->f22;xy.y++) {
 for(xy.x=0;xy.x<*(const unsigned short *)&((struct Obj14499 *)p)->f20;xy.x++) {
 if(func_021F2818((char *)p,(Pair *)&xy.x,(Box *)rect)) {
 rect[0]*=8;rect[1]*=8;rect[2]*=8;rect[3]*=8;
 if(func_021F4450(rect,point)) {*out=xy;return 1;}
 }
 }} return 0;
}




void func_021F26E0(char *a, int b, int c)
{
    ((void (*)(int, int, char *))(*(void **)(a + 0x18)))(b, c, a + 4);
}




void func_021F26F0(char *p,char *target,void *window,void *font,u16 heap)
{
 Box box;
 Pair xy;
 u16 codes[3];
 void *text;
 u16 x,y;
 unsigned kind;
 text=func_020457B0(2,heap);
 for(xy.y=0;xy.y<func_021F4DA0(((struct Obj10808 *)p)->f0);xy.y++){
  for(xy.x=0;xy.x<func_021F4D9C(((struct Obj10808 *)p)->f0);xy.x++){
   if(func_021F2818((char *)p, (Pair *)&xy, (Box *)&box)){
    kind=func_021F2614(p,(int *)&xy,codes);
    if(kind==1 || kind==10 || kind==11){
     codes[1]=codes[0];codes[2]=func_02045A98();
     func_02045994(text,codes+1,2);
     box.x*=8;box.y*=8;box.z*=8;box.w*=8;
     x=box.x+(box.z-box.x)/2-24;
     y=box.y+(box.w-box.y)/2-40;
     x-=(u16)(func_0201D304(text,(u32_021F26E0)font,0)/2);
     y-=(u16)(func_0201D42C(text,font)/2);
     func_0201C6FC(window,(u32_021F26E0)func_02045770(((struct Obj14500 *)target)->f0),(short)(x-1),(short)y,text,(u32_021F26E0)font);
     target[4]=1;
    }
   }
  }
 }
 func_02045808(text);
}



int func_021F2818(char *a, Pair *b, Box *c)
{
    return ((int (*)(Pair *, Box *))(*(void **)(a + 0x14)))(b, c);
}



int func_021F2828(const char *p,int target,Pair *out) {
 Pair xy;
 for(xy.y=0;xy.y<=*(const unsigned short *)&((struct Obj14501 *)p)->f22;xy.y++)
 for(xy.x=0;xy.x<=*(const unsigned short *)&((struct Obj14501 *)p)->f20;xy.x++)
 if(((int (*)(int *,int *))*(void *const *)(p+0x1C))(&xy.x,0)==target) {*out=xy;return 1;}
 return 0;
}



/*
 * note: the original has no else arm: when neither mode is 3 it falls into
 *   the call with r2 (= newmode), r4, r5 and [sp,#4] never assigned
 *   (021F289A bne -> 021F28A6 skips the height store). The C leaves from/to/
 *   width/height unassigned on that path exactly as the image does; the
 *   earlier `else return;` spelling was a guard the original lacks.
 */
void func_021F2884(Pair *p, int oldmode, int newmode)
{
    Conv from;
    Conv to;
    int width, height, result;
    Pair xy;
    if (oldmode == 3) {
        from = func_021F2F8C;
        to = (Conv)func_021F2F60;
        width = 13;
        height = 5;
    } else if (newmode == 3) {
        from = (Conv)func_021F2F60;
        to = func_021F2F8C;
        width = 11;
        height = 4;
    }
    result = from(p, 0);
    for (xy.y = 0; xy.y <= height; xy.y++)
        for (xy.x = 0; xy.x <= width; xy.x++)
            if (to(&xy, 0) == result) {
                *p = xy;
                return;
            }
}



int func_021F28FC(const int *p,int *out) {
 int xy[2];enum { X_LEFT=15,X_RIGHT=22 } x;int y;
 switch(func_021F2F60(p,xy)) {
 case 1:case 10:case 11:
 x=xy[0]*2+3;out[0]=x;y=xy[1]*3+5;out[1]=y;out[2]=x+2;out[3]=y+3;break;
 case 2:case 3:case 4:case 5:
 x=(p[0]+1)*3;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+3;out[3]=y+3;break;
 case 6:x=15;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 7:x=22;out[0]=x;y=p[1]*3+5;out[1]=y;out[2]=x+7;out[3]=y+3;break;
 case 0:return 0;
 case 8:case 9:break;
 }
 if(p[1]==5 && p[0]>6)return 0;return 1;
}



/*
 * lever: case 0 follows case 9; repeated stores in each case-8 arm preserve backward tail sharing.
 */
int func_021F299C(Pair *p,Box *out)
{
 Pair xy;
 switch((unsigned)func_021F2F8C(p,&xy)) {
 case 1:out->x=d_021F5544[xy.y]+xy.x*2;out->y=d_021F5550[xy.y];out->z=out->x+2;out->w=out->y+3;break;
 case 2:case 3:case 4:case 5:out->x=(p->x+1)*3;out->y=20;out->z=out->x+3;out->w=out->y+3;break;
 case 6:out->x=25;out->y=8;out->z=out->x+4;out->w=out->y+3;break;
 case 7:out->x=24;out->y=12;out->z=out->x+5;out->w=out->y+3;break;
 case 8:if(p->x==0){out->x=3;out->y=16;out->z=out->x+4;out->w=out->y+3;}else {out->x=23;out->y=16;out->z=out->x+4;out->w=out->y+3;}break;
 case 9:out->x=15;out->y=20;out->z=out->x+12;out->w=out->y+3;break;
 case 0:return 0;
 }
 switch(p->y) {
 case 1:if(p->x>9)return 0;break;
 case 2:if(p->x>9)return 0;break;
 case 3:if(p->x>4)return 0;break;
 }
 return 1;
}



/*
 * tail: 320-byte lead including padding, followed by existing matched 920-byte ov194_func_021F2BC8.
 */
void func_021F2A88(int *p,int *delta,u8 *saved)
{
 int enter,leave,x,y,index;
 enter=0;leave=0;
 switch(p[1]){
 case 0:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y==5)enter=1;
 break;
 case 4:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y==5)enter=1;
 break;
 case 5:
 x=p[0]+=delta[0];if(x<0)x=5;else if(x>5)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 if(y!=5)leave=1;
 break;
 default:
 x=p[0]+=delta[0];if(x<0)x=12;else if(x>12)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=5;else if(y>5)y=0;p[1]=y;
 break;
 }
 if(enter){
  x=p[0];
  if(x>=6 && x<=9){saved[4]=x;p[0]=4;}
  else if(x>=10 && x<=12){saved[5]=x;p[0]=5;}
  else if(x>=0 && x<=5){index=x*2/3;saved[index]=x;p[0]=index;}
 }
 if(leave){
  x=p[0];
  if(x==4)p[0]=saved[4];
  else if(x==5)p[0]=saved[5];
  else if(x>=0 && x<=3)p[0]=saved[x];
 }
}



/*
 * extent: 920 bytes through return at 021F2F5E; no calls or followers.
 */
void func_021F2BC8(int *p,int *delta,unsigned char *s) {
 int x,y;
 switch((unsigned)p[1]) {
 case 0:
 x=p[0]+=delta[0];if(x<0)x=10;else if(x>10)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==3) {
 switch((unsigned)p[0]) {
 case 8:case 9:s[8]=p[0];s[12]=p[0];s[11]=8;break;
 case 4:case 5:case 6:case 7:s[12]=p[0];s[11]=p[0];break;
 case 10:s[12]=10;s[11]=9;break;
 case 0:case 1:case 2:case 3:break;
 }
 switch(p[0]) {case 0:p[0]=s[6];break;case 1:case 2:p[0]++;break;default:p[0]=4;break;}
 } else {
 if(y!=1) {default:break;}
 switch((unsigned)p[0]) {
 case 8:case 9:s[8]=p[0];s[12]=p[0];x=p[0];if(x>9)x=9;else if(x<4)x=4;s[11]=x;break;
 case 4:case 5:case 6:case 7:case 10:s[12]=p[0];x=p[0];if(x>9)x=9;else if(x<4)x=4;s[11]=x;break;
 case 0:case 1:case 2:case 3:break;
 }
 switch(p[0]) {case 8:case 9:p[0]=8;break;case 10:p[0]=9;break;}
 }break;
 case 1:
 x=p[0]+=delta[0];if(x<0)x=9;else if(x>9)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==0) {
 switch(p[0]) {case 7:case 8:s[9]=p[0];break;}
 switch(p[0]) {case 8:p[0]=s[8];break;case 9:p[0]=10;break;}
 }else if(y==2) {
 switch(p[0]) {case 7:case 8:s[9]=p[0];break;}
 switch((unsigned)p[0]) {case 0:p[0]=s[7];break;case 7:case 8:p[0]=8;break;case 9:p[0]=9;break;default:p[0]++;break;}
 }break;
 case 2:
 x=p[0]+=delta[0];if(x<0)x=9;else if(x>9)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==1) {
 switch((unsigned)p[0]) {case 0:case 1:s[7]=p[0];break;case 4:case 5:case 6:case 7:case 8:case 9:s[11]=p[0];s[12]=p[0];break;case 2:case 3:break;}
 switch(p[0]) {case 0:case 1:p[0]=0;break;case 8:p[0]=s[9];break;case 9:p[0]=9;break;default:p[0]--;break;}
 }else if(y==3) {
 switch((unsigned)p[0]) {case 0:case 1:s[7]=p[0];break;case 4:case 5:case 6:case 7:case 8:s[11]=p[0];s[12]=p[0];break;case 9:s[11]=9;s[12]=10;break;case 2:case 3:break;}
 switch((unsigned)p[0]) {case 0:p[0]=s[10];break;case 1:case 2:case 3:break;default:p[0]=4;break;}
 }break;
 case 3:
 x=p[0]+=delta[0];if(x<0)x=4;else if(x>4)x=0;p[0]=x;
 y=p[1]+=delta[1];if(y<0)y=3;else if(y>3)y=0;p[1]=y;
 if(y==2) {
 switch(p[0]) {case 0:case 1:s[10]=p[0];s[6]=p[0];break;}
 switch((unsigned)p[0]) {case 0:case 1:case 2:case 3:break;case 4:p[0]=s[11];break;}
 }else if(y==0) {
 switch(p[0]) {case 0:case 1:s[10]=p[0];s[6]=p[0];break;}
 switch((unsigned)p[0]) {case 0:case 1:p[0]=0;break;case 2:case 3:p[0]--;break;case 4:p[0]=s[12];break;}
 }break;
 }
}



int func_021F2F60(const int *p,int *out) {return func_021F2F68(p,out);}



int func_021F2F68(const int *p,int *out) {
 if(p[1]<5) {if(out) {out[1]=p[1];out[0]=p[0];}return 1;}
 if(p[0]<=5)return p[0]+2;
 return 0;
}
