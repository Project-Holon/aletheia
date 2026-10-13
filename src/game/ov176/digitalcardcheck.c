/*
 * file:     digitalcardcheck.c
 * unit:     yes
 * function: func_0217CFE8, func_0217D000, func_0217D010, func_0217D028, func_0217D160, func_0217D174, func_0217D188, func_0217D194, func_0217D1A0, func_0217D1C8, func_0217D224, func_0217D238, func_0217D244, func_0217D290, func_0217D2A4, func_0217D2BC, func_0217D2F0, func_0217D388, func_0217D398, func_0217D410, func_0217D434, func_0217D44C, func_0217D458, func_0217D4FC, func_0217D730, func_0217D964, func_0217DA38, func_0217DB0C, func_0217DBE0, func_0217DC20, func_0217DC28, func_0217DE60
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
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
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
 *   func_0200BAF4 0x0200BAF4 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_020307B0 0x020307B0 arm
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   func_02087C6C  0x02087C6C  arm
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   ov067_id       0x00000043  data
 *   func_02030734 0x02030734 arm
 *   func_021E58A4 0x021E58A4 thumb ov177
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   d_0217E61C 0x0217E61C data a1
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_0201ED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_021E8A80  0x021E8A80  thumb  ov177
 *   func_021E64C0  0x021E64C0  thumb  ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0217DEA4 0x0217DEA4 thumb ov176
 *   func_020362DC 0x020362DC arm
 *   func_0217E000 0x0217E000 thumb ov176
 *   func_0217DFF0 0x0217DFF0 thumb ov176
 *   func_0217DFD0 0x0217DFD0 thumb ov176
 *   func_0217DFE4 0x0217DFE4 thumb ov176
 *   func_0217DEDC 0x0217DEDC thumb ov176
 *   func_0217DFBC 0x0217DFBC thumb ov176
 *   func_0217DFA8 0x0217DFA8 thumb ov176
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_0200BBD8 0x0200BBD8 thumb
 *   func_0200B110 0x0200B110 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_0200E9F4 0x0200E9F4 thumb
 *   func_0200EA00 0x0200EA00 thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   func_021E5D68 0x021E5D68 thumb ov177
 *   func_0200EA08 0x0200EA08 thumb
 *   func_021E5EF8 0x021E5EF8 thumb ov177
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
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
#include "../../matched/include/Obj00053.h"
#include "../../matched/include/Obj06578.h"
#include "../../matched/include/Obj06579.h"
#include "../../matched/include/Obj24427.h"
#include "../../matched/include/Obj24428.h"
#include "../../matched/include/Obj08285.h"
#include "../../matched/include/Obj14366.h"

struct Big;
struct Reg2;
struct Rec1E;
struct RecBig;
struct Reg;
struct Sub0200852CObj;
struct Rec0200E6FC;
struct MsgBank;
struct Rec;
struct WordSet;
struct Rec160;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 image[0x94]; u32 f94, f98; int f9c; u16 fa0, fa2, fa4, fa6, fa8, faa; } Record;

typedef signed int     s32;

typedef struct Work Work;

typedef struct { int mode; int v[7]; } Config;

typedef struct { int a,b,c,d,callback; Config config; unsigned short heap; } Request;

typedef u16 Row[3];

typedef struct {
    u8 data[0x92]; u16 pad92;
    u32 color0, color1; u8 *user;
    u16 a0, a2;
    union { u32 total; struct { u16 a4, a6; } h; } v;
    u16 a8, aa;
} Rec;

extern void func_021E8738(int *p, int a, int b, int c);
extern int func_021E8844(const int *);
extern void func_021E8AA0(int *,int);
extern void func_0217BBD4(int);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
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
extern void func_02082D44(void *, const void *, u32);
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
extern void *func_0200BAF4(int,int);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 func_020307B0(void *p);
extern int MYSTATUS_GetSize(void);
extern void func_02087C6C(void *p);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021E58A4(int unused, int mode, unsigned color);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int func_0201EC74(int,int,int);
extern int *func_021E8A3C(int a, int b, int c);
extern void func_021E8A78(void *p);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_021E8A80(int);
extern int func_021E64C0(unsigned char *, void *);
extern int func_021E8A90(int **p);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void func_0217DEA4(int *, int);
extern u32 func_020362DC(void);
extern void func_0217E000(int *);
extern int func_0217DFF0(int, int);
extern void func_0217DFD0(int *, int, int);
extern int func_0217DFE4(int *);
extern void func_0217DEDC(char *, int);
extern int func_0217DFBC(int *);
extern void func_0217DFA8(int *);
extern void func_021E8AB4(u32, u32);
extern void func_021E8AB8(u32);
extern void func_0200BBD8(struct Obj *p, int v);
extern void func_0200B110(struct Reg2 *p, u32 id, s32 value);
extern int GAME_DATA_SaveStart(int a0);
extern int GAME_DATA_SaveMain(u8 *p);
extern void func_021E8AA8(int);
extern void *func_0200E9F4(void *);
extern int func_0200EA00(int p);
extern u16 BSUBWAY_SAVEDATA_GetStat(Row *, int, int);
extern char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
extern int func_0200EA08(int p);
extern void func_021E5EF8(void *p);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 index);
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
void func_0217D2BC(u8 *p,const void *q);
void func_0217D2F0(u8 *p, u8 *q);
void func_0217D388(int *p, int *q);
Request *func_0217D398(Config *p, int heap);
void func_0217D410(int *p);
void func_0217D434(int *p);
int func_0217D44C(int *p);
void func_0217D458(int a, int unused, char *p);
void func_0217D4FC(int *a, int *state, int *p);
void func_0217D730(int *a, int *state, int *p);
void func_0217D964(int *a, int *state, int *p);
void func_0217DA38(int sys, int *state, int *p);
void func_0217DB0C(int sys, int *state, int *p);
void func_0217DBE0(int a, int *state, int *p);
void func_0217DC20(int a);
void func_0217DC28(int *p);
void func_0217DE60(int *p);
int func_0217DE8C(int *p);
int func_0217DE98(int *p);
extern const char d_0217E61C[];



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
    base = GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8);
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
    func_02082D44(func_0200B074(((struct Obj00053 *)p)->f38), &rec, 0x92);
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
        ((struct Obj00053 *)p)->f18 = func_021E7E3C((int)func_0200BAC8(GAME_DATA_GetSaveControl((struct Big *)(*(int *)&((struct Obj00053 *)p)->f1B8))), a,
            ((struct Obj00053 *)p)->f1B0, ((struct Obj00053 *)p)->f28, *(int *)&((struct Obj00053 *)p)->f1AC, *(int *)&((struct Obj00053 *)p)->f24, ((struct Obj00053 *)p)->f1C8);
    }
}


void func_0217D290(u8 *p) {if(*(char * *)&((struct Obj10703 *)p)->f18) {func_021E82BC(*(char * *)&((struct Obj10703 *)p)->f18);((struct Obj10703 *)p)->f18=0;}}


int func_0217D2A4(u8 *p){return func_021E8338(((struct Obj24425 *)p)->f18);}


int func_0217D2B0(u8 *p){return func_021E8420(((struct Obj24426 *)p)->f18);}





void func_0217D2BC(u8 *p,const void *q) {void *v;v=func_0200BAF4((int)func_0200BAC8(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),((struct Obj00053 *)p)->f1C8);func_02082D44(v,q,POKE_REGULATION_GetDataSize());func_020307B0(v);}






/*
 *           have no witness outside this range. Both are unlabelled Thumb
 *           leaf code in arm9 that disasm.py emitted as `.word` runs
 *           (0200BAC8 is inside a `0x21314B01` word block, 0201A918 inside a
 *           `0x47704800` word block), so they are neither `label` nor
 *           `sole-ref/code` (not a traced func_ start) and no SDK symbol
 *           exists. Nothing to cut: both call sites are inside this function.
 */
void func_0217D2F0(u8 *p, u8 *q)
{
    u8 *r = *(u8 * *)&((struct Obj06579 *)q)->f1B8;
    u32 x;
    u32 a;

    ((struct Obj06578 *)p)->f44 = 0x64;
    x = (u32)func_02012944(r);
    func_02082D44((void *)x, p, MYSTATUS_GetSize());
    func_02087C6C(p + 0x20);
    func_0200E6FC(func_0200E6E8((u32)GAME_DATA_GetSaveControl((struct Big *)r)), 0, (struct Rec0200E6FC *)(p + 0x38));
    a = (u32)func_0200BAF4((int)func_0200BAC8(GAME_DATA_GetSaveControl((struct Big *)r)), 0x8056);
    func_02082D44((void *)a, p + 0xd4, POKE_REGULATION_GetDataSize());
    func_020307B0((void *)a);
    ((struct Obj06578 *)p)->f28 = func_0200E918((const u8 *)(((struct Obj06579 *)q)->f34), 1);
    ((struct Obj06578 *)p)->f2C = func_0200E918((const u8 *)(((struct Obj06579 *)q)->f34), 2);
    ((struct Obj06578 *)p)->f30 = func_0200E918((const u8 *)(((struct Obj06579 *)q)->f34), 0);
    ((struct Obj06578 *)p)->f40 = func_0200B078((struct Reg2 *)(((struct Obj06579 *)q)->f38), 2);
}






void func_0217D388(int *p, int *q)
{
    ((struct Obj24427 *)p)->f40 = func_0200B078((struct Reg2 *)(((struct Obj24428 *)q)->f38), 2);
}





Request *func_0217D398(Config *p, int heap)
{
    Request *r;
    r = func_02030734(heap, 0x38, 0, d_0217E61C, 0x9A);
    func_02082BCC(r, 0, 0x38);
    r->config = *p;
    r->heap = heap;
    func_021E58A4(r->config.v[4], 3, heap);
    r->a = (int)func_02045B38(0, 2, 0xD2, heap);
    r->b = func_0201EC74(8, 0x40, heap);
    r->callback = (int)func_021E8A3C((int)r, (int)func_0217D458, heap);
    return r;
}




void func_0217D410(int *p) {func_021E8A78((void *)p[4]);func_0217DE60(p);func_0201ED04((struct WordSet *)p[1]);MSGDATA_Delete((struct Rec *)p[0]);func_020307B0(p);}





/*
 *   func_021E64C0 (0x021E64C0) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_0217D434(int *p)
{
    func_021E8A80(((struct Obj08285 *)p)->f10);
    if (((struct Obj08285 *)p)->f8)
        func_021E64C0((unsigned char *)((struct Obj08285 *)p)->f8, (void *)((struct Obj08285 *)p)->f24);
}




int func_0217D44C(int *p) {return func_021E8A90((int **)p[4]);}




void func_0217D458(int a, int unused, char *p)
{
    void *m;
    unsigned x;
    unsigned y;
    m = func_0200B1D4(func_0200B358(GAME_DATA_GetSaveControl(((struct Obj14366 *)p)->f30)), ((struct Obj14366 *)p)->f14);
    x = func_0200B078(m, 2);
    y = func_0200B078(m, 10);
    if (x && y == 1) {
        func_021E8AA0((int *)a, (int)func_0217D4FC);
        return;
    }
    if (x && y == 2) {
        func_021E8AA0((int *)a, (int)func_0217D730);
        return;
    }
    if (x && y == 3) {
        func_021E8AA0((int *)a, (int)func_0217D964);
        return;
    }
    if (x && y == 4) {
        func_021E8AA0((int *)a, (int)func_0217DA38);
        return;
    }
    if (x && y == 5) {
        func_021E8AA0((int *)a, (int)func_0217DB0C);
        return;
    }
    func_021E8AA0((int *)a, (int)func_0217DBE0);
}



void func_0217D4FC(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4(p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x67, 1);
        *state = 19; func_021E8AB4((u32)a, 4); break;
    case 4: func_0217DEDC((char *)p, 2); *state = 5; break;
    case 5:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: func_0217DFD0(p, 0x71, 1); *state = 19; func_021E8AB4((u32)a, 7); break;
    case 7: func_0217DEDC((char *)p, 0); *state = 8; break;
    case 8:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: func_0217DFD0(p, 0x72, 1); *state = 19; func_021E8AB4((u32)a, 10); break;
    case 10: func_0217DEDC((char *)p, 0); *state = 11; break;
    case 11:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: func_0217DFD0(p, 0x6B, 2); *state = 19; func_021E8AB4((u32)a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p[12]);
        record = func_0200B1D4(func_0200B358(base), p[5]);
        base = func_0200BAC8(base);
        func_0200BBD8(base, p[5] == 0 ? 1 : 2);
        func_0200B110(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart((int)((void *)p[12])); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: func_0217DFD0(p, 0x73, 1); *state = 19; func_021E8AB4((u32)a, 17); break;
    case 17: if (func_0217DE98(p)) *state = 18; break;
    case 18: func_021E8AA0(a, (int)func_0217DC20); break;
    case 19: if (func_0217DFE4(p)) func_021E8AB8((u32)a); break;
    }
}



void func_0217D730(int *a, int *state, int *p)
{
    int result;
    void *base, *record;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4(p, 0); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x68, 1);
        *state = 19; func_021E8AB4((u32)a, 4); break;
    case 4: func_0217DEDC((char *)p, 2); *state = 5; break;
    case 5:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 6; else if (result == 1) *state = 17; }
        break;
    case 6: func_0217DFD0(p, 0x69, 1); *state = 19; func_021E8AB4((u32)a, 7); break;
    case 7: func_0217DEDC((char *)p, 0); *state = 8; break;
    case 8:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 9; else if (result == 1) *state = 17; }
        break;
    case 9: func_0217DFD0(p, 0x72, 1); *state = 19; func_021E8AB4((u32)a, 10); break;
    case 10: func_0217DEDC((char *)p, 0); *state = 11; break;
    case 11:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 12; else if (result == 1) *state = 17; }
        break;
    case 12: func_0217DFD0(p, 0x6B, 2); *state = 19; func_021E8AB4((u32)a, 13); break;
    case 13:
        base = GAME_DATA_GetSaveControl((void *)p[12]);
        record = func_0200B1D4(func_0200B358(base), p[5]);
        base = func_0200BAC8(base);
        func_0200BBD8(base, p[5] == 0 ? 1 : 2);
        func_0200B110(record, 10, 4); *state = 14; break;
    case 14: GAME_DATA_SaveStart((int)((void *)p[12])); *state = 15; break;
    case 15:
        result = GAME_DATA_SaveMain((void *)p[12]);
        if (result == 2) *state = 16;
        else if (result == 3) *state = 16;
        break;
    case 16: func_0217DFD0(p, 0x6C, 1); *state = 19; func_021E8AB4((u32)a, 17); break;
    case 17: if (func_0217DE98(p)) *state = 18; break;
    case 18: func_021E8AA0(a, (int)func_0217DC20); break;
    case 19: if (func_0217DFE4(p)) func_021E8AB8((u32)a); break;
    }
}



void func_0217D964(int *a, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4((int *)p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3: func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x6D, 1); *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) {
            func_0217DFA8(p);
            if (result == 0) *state = 7;
        }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0(a, (int)func_0217DC20); break;
    }
}



/*
 * DFF0 receives the context in r0 even though its forwarding body ignores it.
 */
void func_0217DA38(int sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4((int *)p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x6e, 1);
        *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 7; }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0((int *)sys, (int)func_0217DC20); break;
    }
}



void func_0217DB0C(int sys, int *state, int *p)
{
    int result;
    switch (*state) {
    case 0: func_0217DC28(p); func_0217DEA4((int *)p, 1); *state = 1; break;
    case 1: if (func_0217DE8C(p)) *state = 2; break;
    case 2: if (func_020362DC() & 3) *state = 3; break;
    case 3:
        func_0217E000(p); func_0217DFF0((int)p, 1); func_0217DFD0(p, 0x70, 1);
        *state = 4; break;
    case 4: if (func_0217DFE4(p)) *state = 5; break;
    case 5: func_0217DEDC((char *)p, 1); *state = 6; break;
    case 6:
        result = func_0217DFBC(p);
        if (result != -1) { func_0217DFA8(p); if (result == 0) *state = 7; }
        break;
    case 7: if (func_0217DE98(p)) *state = 8; break;
    case 8: func_021E8AA0((int *)sys, (int)func_0217DC20); break;
    }
}



void func_0217DBE0(int a, int *state, int *p)
{
    switch (*state) {
    case 0:
        func_0217DFD0(p, 0x6F, 1);
        *state = 1;
        break;
    case 1:
        if (func_0217DFE4(p))
            *state = 2;
        break;
    case 2:
        func_021E8AA0((int *)a, (int)func_0217DC20);
        break;
    }
}



void func_0217DC20(int a) { func_021E8AA8(a); }



/*
 * Note 2026-10-04 (wD2 lane12): byte-correct. Unresolved: func_0200EA00 and func_0200EA08 (witness). Filed src/matched/arm9/func_0200EA00.c and func_0200EA08.c (EXACT) this wave; they need a manifest/shard, then this file re-verifies as EXACT with no C change.
 * blockers: ARM9 0200EA00 and 0200EA08 have no outside witness; the integrator owns filing.
 *   unsigned char *func_0200EA00(unsigned char *p) { return p + 0x5a; }
 *   unsigned char *func_0200EA08(unsigned char *p) { return p; }
 * Lever: explicit unsigned left/right shifts pack the low bytes in 568 bytes;
 * byte casts followed by placement shifts compile to 584 bytes.
 * AE14's empty body leaves its incoming pointer in r0; caller saves it.
 */
void func_0217DC28(int *p)
{
    void *save, *stats;
    struct Rec160 *base;
    struct Reg2 *obj;
    struct Rec1E *sub;
    struct Reg *reg;
    u8 *win;
    int flag;
    if (p[2] == 0) {
        save = GAME_DATA_GetSaveControl((struct Big *)p[12]);
        base = func_0200B358(GAME_DATA_GetSaveControl((struct Big *)p[12]));
        obj = (struct Reg2 *)func_0200B1D4(base, p[5]);
        sub = func_0200B204((struct RecBig *)base, p[5]);
        reg = (struct Reg *)func_0200AE14(obj);
        stats = func_0200E9F4(save);
        win = func_02012944((void *)p[12]);
        flag = func_021E5548((int *)p[11]);
        if (p[5] == 0) {
            Rec rec;
            Row *table;
            int total, a, b, c, d;
            func_02082BCC(&rec, 0, 0xac);
            func_02082D44(func_0200B074(obj), &rec, 0x92);
            table = (u16 (*)[3])func_0200EA00((int)stats);
            rec.a0 = BSUBWAY_SAVEDATA_GetStat(table, 10, 0);
            total = BSUBWAY_SAVEDATA_GetStat(table, 10, 1);
            rec.v.total = total + BSUBWAY_SAVEDATA_GetStat(table, 10, 2);
            rec.user = (u8 *)func_02008554((const struct Sub0200852CObj *)win);
            a = func_0200B078(obj, 6); b = func_0200B078(obj, 5); c = func_0200B078(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = func_0200B078(obj, 9); b = func_0200B078(obj, 8); d = func_0200B078(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.aa = func_0200B078(obj, 11);
            p[2] = (int)func_021E5D68((char *)(&rec), 0, win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        } else {
            Rec rec;
            const u8 *table;
            int a, b, c, d;
            func_02082BCC(&rec, 0, 0xac);
            func_02082D44(func_0200B074(obj), &rec, 0x92);
            table = (const u8 *)func_0200EA08((int)stats);
            rec.a0 = func_0200E918(table, 1); rec.a2 = func_0200E918(table, 2);
            rec.v.h.a4 = func_0200E918(table, 0);
            rec.v.h.a6 = func_0200AE54(reg, 22);
            rec.user = (u8 *)func_02008554((const struct Sub0200852CObj *)win);
            a = func_0200B078(obj, 6); b = func_0200B078(obj, 5); c = func_0200B078(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = func_0200B078(obj, 9); b = func_0200B078(obj, 8); d = func_0200B078(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.a8 = func_0200B078(obj, 11);
            p[2] = (int)func_021E6118((char *)(&rec), win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        }
        func_0217DFF0((int)p, 0);
    }
}



void func_0217DE60(int *p)
{
    if (p[2]) {
        if (p[5] == 0)
            func_021E5EF8((void *)p[2]);
        else
            func_021E62A0((void *)p[2]);
        p[2] = 0;
    }
    func_020414EC(1);
    func_020409B4(1);
}



int func_0217DE8C(int *p) { return func_021E64C8((void *)p[2]); }



int func_0217DE98(int *p) { return func_021E65FC((Work *)p[2]); }
