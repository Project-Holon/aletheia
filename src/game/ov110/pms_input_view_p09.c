/*
 * file:     pms_input_view_p09.c
 * unit:     yes
 * function: func_021BAC78, func_021BACDC, func_021BAD14, func_021BAD20, func_021BAD2C, func_021BAD68, func_021BADE8, func_021BAE24, func_021BAE94, func_021BAED0, func_021BAEDC, func_021BAF4C
 * address:  0x021BAC78
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_021BFD94 0x021BFD94 thumb ov110
 *   func_021BFE24  0x021BFE24  thumb  ov110
 *   func_021BFE60  0x021BFE60  thumb  ov110
 *   func_020499D4 0x020499D4 arm
 *   d_021C3744 0x021C3744 data ov110 a4
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021BFC20  0x021BFC20  thumb  ov110
 *   func_02030734 0x02030734 arm
 *   func_021BAFE4 0x021BAFE4 thumb ov110
 *   func_021B6C74 0x021B6C74 thumb ov067
 *   func_020457B0 0x020457B0 arm
 *   d_021C3C34 0x021C3C34 data ov110 a1
 *   d_021C3770 0x021C3770 data a2
 *   func_020307B0 0x020307B0 arm
 *   func_021B6CCC 0x021B6CCC thumb ov067
 */
#include "../../matched/include/Obj22344.h"
#include "../../matched/include/Obj22345.h"
#include "../../matched/include/Obj22346.h"
#include "../../matched/include/Obj10273.h"
#include "../../matched/include/Obj07999.h"
#include "../../matched/include/Obj13777.h"
#include "../../matched/include/Obj22347.h"
#include "../../matched/include/Obj22348.h"
#include "../../matched/include/Obj22349.h"
#include "../../matched/include/Obj03239.h"
#include "../../matched/include/Obj02459.h"
#include "../../matched/include/Obj06387.h"
#include "../../matched/include/Obj22352.h"
#include "../../matched/include/Obj03750.h"
#include "../../matched/include/Obj13778.h"

struct Obj;
struct Actor;
struct Vec2;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Cfg;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { short x, y, z; u8 a, b; } Position;

typedef struct { short x,y; } Vec2;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct { u32 values[6]; } Table;

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B954(struct Actor *a, u32 v);
extern u32 func_021BFD94(u8 *p, struct Vec2 *out);
extern void func_021BFE24(u8 *p, int y);
extern unsigned func_021BFE60(u8 *p, unsigned n);
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void func_021BC704(u8 *p, u32 flag);
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *p, int n, int v);
extern void func_021BB658(u8 *,int);
extern u8 func_021BF6DC(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *,unsigned);
extern void func_021BFC20(u8 *p, unsigned visible);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_021BAFE4(u32 p);
extern u32 *func_021B6C74(u32 *src, u32 n, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020307B0(void *p);
extern void func_021B6CCC(int *);
struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode);
int func_021BACDC(u8 *p,int unused,unsigned n);
void func_021BAD14(u8 *p, u32 v);
unsigned func_021BAD20(u8 *p, unsigned n);
void func_021BAD2C(u8 *p,int v);
void func_021BAD68(u8 *p,int index);
void func_021BADE8(u8 *p);
void func_021BAE24(u8 *p, u8 *a1, void *a2);
void func_021BAE94(u8 *p, u8 *q, void *a2);
void func_021BAED0(u8 *p, u8 *a1, void *a2);
u8 *func_021BAEDC(void *p,void *q,u16 heap);
void func_021BAF4C(unsigned p);
extern const Table d_021C3744;
extern const char d_021C3C34[];
extern const u16 d_021C3770[];

/*
 * note 2026-10-05 (wD6 lane14): closed by `if (mode == 2) f = 1; else f = z;`:
 * the zero z merges into the u16 flag only in the else arm, so the narrowing
 * is emitted at the join into its own register (r4), as in the original.
 */
struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode)
{
    Position pos;
    struct Obj *o;
    u16 f;
    int z;
    int s;
    pos.x = x;
    pos.y = y;
    pos.a = a;
    z = 0;
    pos.b = z;
    pos.z = z;
    if (mode == 2)
        f = 1;
    else
        f = z;
    s = OS_DisableInterrupts();
    o = func_0204B294(*(void **)(p + 0x20), r[1], r[0], r[2], &pos, f, 42);
    OS_RestoreInterrupts(s);
    if (o) {
        func_0204B92C(o, 1);
        func_0204B954((struct Actor *)o, 1 << 12);
    }
    return o;
}

int func_021BACDC(u8 *p,int unused,unsigned n) { Vec2 pos; if(func_021BFD94(*(u8 * *)&((struct Obj22344 *)p)->f5C,(struct Vec2 *)(&pos))==0) return 3; if(n<(unsigned)pos.y) return 1; if(n>(unsigned)pos.y) return 2; if(n==(unsigned)pos.y) return 0; return 3; }

void func_021BAD14(u8 *p, u32 v) { func_021BFE24((u8 *)(((struct Obj22345 *)p)->f5C), v); }

unsigned func_021BAD20(u8 *p, unsigned n) { return func_021BFE60(*(u8 * *)&((struct Obj22346 *)p)->f5C, n); }

void func_021BAD2C(u8 *p,int v) { int id,x; if(v) { id=29; x=96; } else { id=28; x=0; } func_020499D4(((struct Obj10273 *)p)->f8C,id,3,0,x,0,0,42); ((struct Obj10273 *)p)->f84=1; ((struct Obj10273 *)p)->f88=v; }

void func_021BAD68(u8 *p,int index) {
    Table table;
    void *bank,*str;
    u8 *q;
    table=d_021C3744;
    func_02043B5C(func_02045770((struct Descriptor *)((struct Obj22347 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f6C),7);
    bank=func_02045B38(0,2,146,42);
    str=func_02045EC0(bank,table.values[index]);
    q=*(u8 * *)&((struct Obj07999 *)p)->f0;
    func_0201C724(((struct Obj22348 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f7C,(u32)func_02045770((struct Descriptor *)((struct Obj13777 *)q)->f6C),2,4,(u32)str,((struct Obj13777 *)q)->f80,0x39e7);
    ((struct Obj22349 *)(*(u8 * *)&((struct Obj07999 *)p)->f0))->f70=1;
    func_02045808(str);
    func_02045C04(bank);
}

void func_021BADE8(u8 *p) { struct Descriptor *q; if(((struct Obj03239 *)p)->f70!=0 && func_0201C6C4((struct PrintSys *)(*(unsigned *)&((struct Obj03239 *)p)->f7C),(void *)((unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj03239 *)p)->f6C)))==0) { q=*(struct Descriptor * *)&((struct Obj03239 *)p)->f6C; func_02045334(q);func_02045374((struct Cfg *)q);func_02041B6C(func_02045730(q));((struct Obj03239 *)p)->f70=0; } }

/*
 * extent: trailing two-byte zero padding
 */
void func_021BAE24(u8 *p, u8 *a1, void *a2) {
    if(**(u32 * *)&((struct Obj02459 *)p)->f78==1) {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    } else if(p[0x74]==1) {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,0);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),1);
    } else {
        func_021BC704(*(u8 * *)&((struct Obj02459 *)p)->f54,1);
        func_021BCF7C(*(u8 * *)&((struct Obj02459 *)p)->f64,(u8)func_021BF71C(*(u8 * *)&((struct Obj02459 *)p)->f18),0);
    }
}

void func_021BAE94(u8 *p, u8 *q, void *a2) { func_021BB658(*(u8 * *)&((struct Obj06387 *)p)->f58,1); if(**(int * *)&((struct Obj06387 *)p)->f78==1) { if(func_021BF6DC(q)==1) func_021BCF7C(*(u8 * *)&((struct Obj06387 *)p)->f64,0,0); } else func_021BB6A0(*(u8 * *)&((struct Obj06387 *)p)->f58,func_021BF724(*(u8 * *)&((struct Obj06387 *)p)->f18)); }

void func_021BAED0(u8 *p, u8 *a1, void *a2) { func_021BFC20((u8 *)(((struct Obj22352 *)p)->f5C), 1); }

u8 *func_021BAEDC(void *p,void *q,u16 heap) {
    int i;
    u8 *result;
    result=func_02030734(heap,0xaf4,1,d_021C3C34,137);
    ((struct Obj03750 *)result)->f0=p;
    ((struct Obj03750 *)result)->f4=q;
    ((struct Obj03750 *)result)->f8=heap;
    func_021BAFE4((u32)result);
    for(i=0;i<27;i++) *(void **)(result+12+i*4)=func_02045B38(1,2,d_021C3770[i],heap);
    ((struct Obj03750 *)result)->f78=func_021B6C74((u32 *)(result+12),27,((struct Obj03750 *)result)->f8);
    ((struct Obj03750 *)result)->fAD0=func_020457B0(27,heap);
    return result;
}

void func_021BAF4C(unsigned p) { int i; func_02045808(((struct Obj13778 *)p)->fAD0);func_021B6CCC(*(int * *)&((struct Obj13778 *)p)->f78);for(i=0;i<27;i++)func_02045C04(*(void **)(p+i*4+0xc));func_020307B0((void *)p); }
