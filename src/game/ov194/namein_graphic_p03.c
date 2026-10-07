/*
 * file:     namein_graphic_p03.c
 * unit:     yes
 * function: func_021F1D58, func_021F1E28, func_021F1F7C, func_021F1FB4, func_021F2150
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
 *   func_021F22E8 0x021F22E8 thumb ov194
 */
#include "../../matched/include/Obj10806.h"
#include "../../matched/include/Obj00418.h"
#include "../../matched/include/Obj03896.h"

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

typedef short s16;

typedef s16 fx16;

typedef unsigned short u16;

typedef unsigned int u32_021F1D58;

typedef signed int     s32;

typedef unsigned int u32_021F1E28;

typedef unsigned int u32_021F1F7C;

typedef unsigned u32_021F1FB4;

extern s32 func_02061CA4(void *p, u32_021F1D58 a, u32_021F1D58 b, s32 size);
extern void func_02082BCC(void *p, int v, int n);
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
extern int func_021F22E8(u8 *);
int func_021F1D58(u16 *out, u16 *phase, u32_021F1D58 step, u32_021F1D58 row, u8 idx, u16 a, u16 b);
void func_021F1E28(u8 *p, int a, u16 b, u16 c, int d, u8 *e, int f);
void func_021F1F7C(u8 *p);
int func_021F1FB4(u8 *p);
int func_021F2150(unsigned char *p);
extern fx16 FX_SinCosTable_[];

static inline fx16 FX_CosIdx(int idx) { return FX_SinCosTable_[((idx >> 4) << 1) + 1]; }

/*
 * note 2026-10-05 (wD9r lane18): closed by the NitroSDK FX_CosIdx inline for the table read
 *   (earlier drafts wrote the raw tbl[(*phase >> 4) * 2 + 1] expression) and the ov105 021B8734
 *   lerp body (u8 r, g, blue; int dr, dg, db) with g before the cosine and an s16 t.
 */
int func_021F1D58(u16 *out, u16 *phase, u32_021F1D58 step, u32_021F1D58 row, u8 idx, u16 a, u16 b)
{
    u8 r, g, blue; int dr, dg, db; s16 t;
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
