/*
 * file:     unit_021C6180_p05.c
 * unit:     yes
 * function: func_021C7460, func_021C74C4, func_021C7500, func_021C7558, func_021C7600, func_021C7674
 * address:  0x021C7460
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021CA58A 0x021CA58A data a1
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021CA154 0x021CA154 thumb ov128
 *   func_021CA184 0x021CA184 thumb ov128
 *   func_020355D8 0x020355D8 arm
 *   func_021C6438 0x021C6438 thumb ov128
 *   d_021CA51C 0x021CA51C data a4
 *   func_021C734C 0x021C734C thumb ov128
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045808 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 *   func_02035C60 0x02035C60 arm
 *   func_0203630C 0x0203630C arm
 *   func_020362DC 0x020362DC arm
 */
#include "../../matched/include/Obj23075.h"
#include "../../matched/include/Obj03280.h"
#include "../../matched/include/Obj05379.h"
#include "../../matched/include/Obj23077.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
struct Rec;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int     s32;

extern int func_02035C08(const void *p);
extern void func_020061E4(u32 a);
extern void func_021CA154(u8 *,int);
extern void func_021CA184(u8 *,int,int);
extern void func_020355D8(u8 v);
extern void func_021C6438(u8 *,u8,u8);
extern int func_021C734C(u32 *,int *,u8 *);
extern void func_021C6B38(u8 *);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
extern void func_02041B6C(unsigned);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201CE48(struct Rec3 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045808(struct U16Vec *vec);
extern void func_021CA3E8(int);
extern u32 func_0201CE30(void *p);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201CE38(void *);
extern int func_02035C60(void);
extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
int func_021C7460(int *p,int *q,u8 *ctx);
int func_021C74C4(int *p,int *q,u8 *r);
void func_021C74E8(u32 *p,u8 *q);
void func_021C7500(u8 *p,u8 *q);
void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap);
int func_021C7600(void *p, int *q);
int func_021C7674(void *p,int *q,u8 *r);
extern const char d_021CA58A[];
extern const u8 d_021CA51C[];

int func_021C7460(int *p,int *q,u8 *ctx)
{
    int v;
    v=func_02035C08(d_021CA58A);
    if(v!=-1) {
        if(v==3) {
            func_020061E4(1361);
            func_021CA154(ctx,*p);
        } else if(v==4) {
            func_020061E4(1366);
            func_021CA154(ctx,*p);
        } else {
            func_020061E4(1356);
            func_021CA184(ctx,v,*p);
        }
        *p=v;
        func_020355D8(1);
        *q=1;
    }
    return v;
}

int func_021C74C4(int *p,int *q,u8 *r) {if(func_021C7460(p,q,r)!=-1) return 1;return func_021C734C((u32 *)p,q,r);}

void func_021C74E8(u32 *p,u8 *q) {func_021C6438(q,d_021CA51C[*p],0);}

void func_021C7500(u8 *p,u8 *q)
{
    void *obj;
    func_021C6B38(q);
    func_02041300(2,0,0,0,32,24,16);
    func_02041B6C(2);
    func_02041300(3,0,0,0,32,24,16);
    func_02041B6C(3);
    obj=((struct Obj23075 *)p)->fC;
    func_020456F8(obj);
    func_02041B6C(func_02045730(obj));
}

void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap)
{
    void *buf;
    void *obj;
    int font;
    if(((struct Obj03280 *)ctx)->f2C) {
        func_0201CE48(((struct Obj03280 *)ctx)->f2C);
        ((struct Obj03280 *)ctx)->f2C=0;
    }
    buf=func_020457B0(128,heap);
    func_02043B5C(func_02045770(((struct Obj05379 *)p)->f1C),15);
    func_02045CAC(((struct Obj03280 *)ctx)->f4,v,buf);
    func_0201F250(((struct Obj03280 *)ctx)->f0,((struct Obj05379 *)p)->f2C,buf);
    font=func_02012FFC();
    ((struct Obj03280 *)ctx)->f2C=func_0201CCE4(((struct Obj05379 *)p)->f1C,0,0,((struct Obj05379 *)p)->f2C,((struct Obj03280 *)ctx)->f17C,font,((struct Obj03280 *)ctx)->f28,10,((struct Obj03280 *)ctx)->f180,0);
    func_0201F73C(((struct Obj05379 *)p)->f1C,2,70,11);
    obj=((struct Obj05379 *)p)->f1C;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
    func_02045808(buf);
    func_021CA3E8(0);
}

int func_021C7600(void *p, int *q)
{
    switch (func_0201CE30(p)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3)) func_0201CE5C(p, 0);
        *q = 0;
        break;
    case 1:
        if (*q == 0 && (func_02035C60() == 1 || (func_020362DC() & 3))) {
            func_020061E4(0x547);
            func_0201CE38(p);
            *q = 1;
        }
        break;
    case 2:
        func_0201CE48(p);
        *q = 0;
        return 0;
    }
    return 1;
}

int func_021C7674(void *p,int *q,u8 *r) {if(func_021C7600(((struct Obj23077 *)r)->f2C,(int *)(r+48))==0) {*q=0;return 1;}return 0;}
