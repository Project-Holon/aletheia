/*
 * file:     digitalcardcheck_p01.c
 * unit:     yes
 * function: func_0217CFE8, func_0217D000, func_0217D010, func_0217D028, func_0217D160, func_0217D174, func_0217D188, func_0217D194, func_0217D1A0, func_0217D1C8, func_0217D224, func_0217D238, func_0217D244, func_0217D290, func_0217D2A4
 * address:  0x0217CFE8
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E8738  0x021E8738  thumb  ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217BBD4 0x0217BBD4 thumb ov176
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B204 0x0200B204 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_0200E918 0x0200E918 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200B074 0x0200B074 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200B078 0x0200B078 thumb
 *   func_021E6118 0x021E6118 thumb ov177
 *   func_021E62A0  0x021E62A0  thumb  ov177
 *   func_021E64C8 0x021E64C8 thumb ov177
 *   func_021E65FC 0x021E65FC thumb ov177
 *   func_021E62CC 0x021E62CC thumb ov177
 *   func_021E7520 0x021E7520 thumb ov177
 *   func_021E7710 0x021E7710 thumb ov177
 *   func_021E777C 0x021E777C thumb ov177
 *   func_021E7E3C 0x021E7E3C thumb ov177
 *   func_021E82BC 0x021E82BC thumb ov177
 *   func_021E8338 0x021E8338 thumb ov177
 *   func_021E8420 0x021E8420 thumb ov177
 */
#include "../../matched/include/Obj14364.h"
#include "../../matched/include/Obj24422.h"
#include "../../matched/include/Obj14365.h"
#include "../../matched/include/Obj00053.h"
#include "../../matched/include/Obj10701.h"
#include "../../matched/include/Obj02889.h"
#include "../../matched/include/Obj10702.h"
#include "../../matched/include/Obj24424.h"
#include "../../matched/include/Obj10703.h"
#include "../../matched/include/Obj24425.h"
#include "../../matched/include/Obj24426.h"

struct Big;
struct Reg2;
struct Rec1E;
struct RecBig;
struct Reg;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 image[0x94]; u32 f94, f98; int f9c; u16 fa0, fa2, fa4, fa6, fa8, faa; } Record;

typedef signed int     s32;

typedef struct Work Work;

extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *);
extern void func_021E8AA0(int *,int);
extern void func_0217BBD4(int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern int func_0200AE14(void *);
extern void *func_0200B358(void *);
extern struct Rec1E *func_0200B204(struct RecBig *p, u32 index);
extern u8 *func_02012944(void *p);
extern int func_021E5548(int *);
extern void func_02082BCC(void *, int, u32);
extern u8 func_0200E918(const u8 *, u32);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 *func_0200B074(struct Reg2 *p);
extern void func_02082D44(int, void *, u32);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
extern void func_021E62A0(void *p);
extern int func_021E64C8(void *);
extern int func_021E65FC(Work *);
extern void func_021E62CC(char *,int,void *,void *,int,u32);
extern int func_021E7520(int,int,int,int,int,int,int,int,int,int,unsigned short);
extern void func_021E7710(char *);
extern int func_021E777C(void *);
extern int func_021E7E3C(int,int,int,int,int,int,unsigned short);
extern void func_021E82BC(char *);
extern int func_021E8338(void *);
extern int func_021E8420(void *);
void func_0217CFE8(void *obj, int a, int b);
int func_0217D000(u8 *p);
void func_0217D010(u8 *p,int v);
void func_0217D028(u8 *p);
void func_0217D160(int *p);
void func_0217D174(int *p);
int func_0217D188(u8 *p);
int func_0217D194(int *p);
void func_0217D1A0(u8 *p,int mode);
void func_0217D1C8(char *p, int value);
void func_0217D224(int *p);
int func_0217D238(u8 *p);
void func_0217D244(char *p);
void func_0217D290(u8 *p);
int func_0217D2A4(u8 *p);
int func_0217D2B0(u8 *p);


void func_0217CFE8(void *obj, int a, int b)
{
    func_021E8738((int *)(((struct Obj14364 *)obj)->f1A4), ((struct Obj14364 *)obj)->f20, a, b);
}

int func_0217D000(u8 *p){return func_021E8844(*(int * *)&((struct Obj24422 *)p)->f1A4);}

void func_0217D010(u8 *p,int v){((struct Obj14365 *)p)->f19C=v;func_021E8AA0(*(int * *)&((struct Obj14365 *)p)->f0,(int)func_0217BBD4);}

/*
 * extent: two zero alignment bytes at 0217D15E before existing 0217D160.
 * ABI: 0200AE14 is an empty void callee leaving its supplied pointer in r0; caller reads it.
 */
void func_0217D028(u8 *p)
{
    Record rec;
    void *base;
    int box, aux, x, table, a, b, c, d;
    if (*(int *)&((struct Obj00053 *)p)->f10) return;
    base = func_02012EBC(((struct Obj00053 *)p)->f1B8);
    func_0200BAC8(base);
    box = func_0200AE14(((struct Obj00053 *)p)->f38);
    aux = (int)func_0200B204(func_0200B358(base), 1);
    x = (int)func_02012944(((struct Obj00053 *)p)->f1B8);
    table = func_021E5548(*(int * *)&((struct Obj00053 *)p)->f1B4);
    func_02082BCC(&rec, 0, 0xAC);
    rec.fa0 = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 1);
    rec.fa2 = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 2);
    rec.fa4 = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 0);
    rec.fa6 = func_0200AE54((struct Reg *)box, 0x16);
    rec.f9c = func_02008554((const struct Sub0200852CObj *)x);
    func_02082D44((int)func_0200B074(((struct Obj00053 *)p)->f38), &rec, 0x92);
    a = func_0200B078(((struct Obj00053 *)p)->f38, 6);
    b = func_0200B078(((struct Obj00053 *)p)->f38, 5);
    c = func_0200B078(((struct Obj00053 *)p)->f38, 4);
    rec.f94 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    a = func_0200B078(((struct Obj00053 *)p)->f38, 9);
    b = func_0200B078(((struct Obj00053 *)p)->f38, 8);
    c = func_0200B078(((struct Obj00053 *)p)->f38, 7);
    rec.f98 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    rec.fa8 = func_0200B078(((struct Obj00053 *)p)->f38, 11);
    *(int *)&((struct Obj00053 *)p)->f10 = (int)func_021E6118((char *)(&rec), (void *)x, (void *)table, (void *)(((struct Obj00053 *)p)->f1B0), ((struct Obj00053 *)p)->f1A8, (void *)(*(int *)&((struct Obj00053 *)p)->f1AC), (void *)(*(int *)&((struct Obj00053 *)p)->f24), (void *)(((struct Obj00053 *)p)->f2C), (void *)aux, 0, ((struct Obj00053 *)p)->f1C8);
}


void func_0217D160(int *p)
{
    func_0217D028((u8 *)p);
    while (func_0217D188((u8 *)p) == 0)
        ;
}


void func_0217D174(int *p)
{
    if (((struct Obj10701 *)p)->f10) {
        func_021E62A0((void *)(((struct Obj10701 *)p)->f10));
        ((struct Obj10701 *)p)->f10 = 0;
    }
}

int func_0217D188(u8 *p) {return func_021E64C8(((struct Obj00053 *)p)->f10);}

/*
 * extent: 12-byte tail stub before labelled 0217D1A0.
 */
int func_0217D194(int *p)
{
    return func_021E65FC((Work *)p[4]);
}

/*
 * calls: 021E62CC own source has five inputs, but this caller visibly
 *   stores the sixth at 0217D1B6; retain the zero-extended halfword payload.
 */
void func_0217D1A0(u8 *p,int mode) {func_021E62CC(*(char * *)&((struct Obj00053 *)p)->f10,mode,((struct Obj00053 *)p)->f24,((struct Obj00053 *)p)->f1AC,((struct Obj00053 *)p)->f1A8,((struct Obj00053 *)p)->f1C8);}

/*
 * extent: two bytes of zero alignment padding follow.
 */
void func_0217D1C8(char *p, int value)
{
    int a;
    int b;
    if (((struct Obj02889 *)p)->f14 == 0) {
        a = func_021E5548((int *)(((struct Obj02889 *)p)->f1B4));
        b = func_0200B078((struct Reg2 *)(((struct Obj02889 *)p)->f38), 11);
        ((struct Obj02889 *)p)->f14 = func_021E7520(value, a, ((struct Obj02889 *)p)->f1B0, ((struct Obj02889 *)p)->f1A8,
            ((struct Obj02889 *)p)->f1AC, ((struct Obj02889 *)p)->f24, ((struct Obj02889 *)p)->f2C, 1, 0, b, ((struct Obj02889 *)p)->f1C8);
    }
}

void func_0217D224(int *p) {if(*(char * *)&((struct Obj10702 *)p)->f14) {func_021E7710(*(char * *)&((struct Obj10702 *)p)->f14);((struct Obj10702 *)p)->f14=0;}}

int func_0217D238(u8 *p){return func_021E777C(((struct Obj24424 *)p)->f14);}

void func_0217D244(char *p)
{
    int a;
    if (((struct Obj00053 *)p)->f18 == 0) {
        a = func_021E5548((int *)(*(int *)&((struct Obj00053 *)p)->f1B4));
        ((struct Obj00053 *)p)->f18 = func_021E7E3C((int)func_0200BAC8(func_02012EBC((struct Big *)(*(int *)&((struct Obj00053 *)p)->f1B8))), a,
            ((struct Obj00053 *)p)->f1B0, ((struct Obj00053 *)p)->f28, *(int *)&((struct Obj00053 *)p)->f1AC, *(int *)&((struct Obj00053 *)p)->f24, ((struct Obj00053 *)p)->f1C8);
    }
}

void func_0217D290(u8 *p) {if(*(char * *)&((struct Obj10703 *)p)->f18) {func_021E82BC(*(char * *)&((struct Obj10703 *)p)->f18);((struct Obj10703 *)p)->f18=0;}}

int func_0217D2A4(u8 *p){return func_021E8338(((struct Obj24425 *)p)->f18);}

int func_0217D2B0(u8 *p){return func_021E8420(((struct Obj24426 *)p)->f18);}
