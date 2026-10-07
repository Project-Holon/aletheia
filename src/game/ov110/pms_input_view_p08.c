/*
 * file:     pms_input_view_p08.c
 * unit:     yes
 * function: func_021BA958, func_021BA974, func_021BA998, func_021BA9B4, func_021BA9D0, func_021BAA0C, func_021BAA3C, func_021BAA8C, func_021BAAF0, func_021BAB0C, func_021BAB70, func_021BABAC, func_021BABE8, func_021BABF4, func_021BAC00, func_021BAC0C, func_021BAC30, func_021BAC3C, func_021BAC40, func_021BAC44, func_021BAC4C, func_021BAC50, func_021BAC64
 * address:  0x021BA958
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
 *   func_021BF714 0x021BF714 thumb ov110
 *   func_021BC72C 0x021BC72C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 *   func_021BF71C 0x021BF71C thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 *   func_021BF784 0x021BF784 thumb ov110
 *   func_021BFC64 0x021BFC64 thumb ov110
 *   func_021BF7A0 0x021BF7A0 thumb ov110
 *   func_021BFCA4 0x021BFCA4 thumb ov110
 *   func_021BFD60 0x021BFD60 thumb ov110
 *   func_021BCFBC 0x021BCFBC thumb ov110
 *   func_021BC6F8 0x021BC6F8 thumb ov110
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BCD80 0x021BCD80 thumb ov110
 *   func_021BB958 0x021BB958 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BF7AC 0x021BF7AC thumb ov110
 *   func_021BFA40 0x021BFA40 thumb ov110
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BF72C 0x021BF72C thumb ov110
 *   func_021BBB84 0x021BBB84 thumb ov110
 *   func_021BBC10 0x021BBC10 thumb ov110
 *   func_021C00AC 0x021C00AC thumb ov110
 *   func_021C00FC 0x021C00FC thumb ov110
 *   func_021BC6DC  0x021BC6DC  thumb  ov110
 *   func_021BC6E0  0x021BC6E0  thumb  ov110
 *   func_021BC320  0x021BC320  thumb  ov110
 *   func_021BCFF0 0x021BCFF0 thumb ov110
 *   func_021BCF18 0x021BCF18 thumb ov110
 */
#include "../../matched/include/Obj00135.h"
#include "../../matched/include/Obj13770.h"
#include "../../matched/include/Obj13771.h"
#include "../../matched/include/Obj13772.h"
#include "../../matched/include/Obj13773.h"
#include "../../matched/include/Obj10266.h"
#include "../../matched/include/Obj10267.h"
#include "../../matched/include/Obj22334.h"
#include "../../matched/include/Obj13774.h"
#include "../../matched/include/Obj06386.h"
#include "../../matched/include/Obj07998.h"
#include "../../matched/include/Obj13775.h"
#include "../../matched/include/Obj04443.h"
#include "../../matched/include/Obj10268.h"
#include "../../matched/include/Obj10269.h"
#include "../../matched/include/Obj10270.h"
#include "../../matched/include/Obj10271.h"
#include "../../matched/include/Obj10272.h"
#include "../../matched/include/Obj22336.h"
#include "../../matched/include/Obj22337.h"
#include "../../matched/include/Obj22338.h"
#include "../../matched/include/Obj13776.h"
#include "../../matched/include/Obj22339.h"
#include "../../matched/include/Obj22340.h"
#include "../../matched/include/Obj22341.h"
#include "../../matched/include/Obj22342.h"
#include "../../matched/include/Obj22343.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

struct V3 { u32 a, b, c; };

typedef struct { unsigned a,b,c; } Triple;

extern u16 func_021BF714(u8 *);
extern void func_021BC72C(char *p, int i);
extern void func_021B9CBC(u8 *);
extern u16 func_021BF71C(u8 *);
extern void func_021BCF7C(u8 *p, int n, int v);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *, u32);
extern u32 func_021BF784(u8 *);
extern void func_021BFC64(u8 *, u32);
extern int func_021BF7A0(u8 *);
extern void func_021BFCA4(u8 *, int);
extern int func_021BFD60(u8 *);
extern void func_021BCFBC(char *p, u32 index, int value);
extern void func_021BC6F8(void *);
extern u8 func_021BF7FC(u8 *p);
extern void func_021BCD80(u8 *);
extern void func_021BB958(char *p);
extern void func_021BB9C0(u8 *,int);
extern int func_021BBB0C(u8 *,int);
extern unsigned func_021BF7AC(u8 *);
extern void func_021BFA40(u8 *,unsigned);
extern void func_021BCEE4(char *p, u32 mode);
extern int func_021BCF38(char *p, u32 mode);
extern u16 func_021BF72C(u8 *);
extern void func_021BBB84(u8 *,unsigned);
extern int func_021BBC10(u8 *);
extern void func_021C00AC(u8 *,unsigned);
extern int func_021C00FC(u8 *);
extern unsigned int func_021BC6DC(void *p);
extern u16 func_021BC6E0(u8 *p, int i);
extern void func_021BC320(void *a, u8 *b, int n);
extern u32 func_021BCFF0(char *p, u32 index);
extern void func_021BCF18(void *,int);
void func_021BA958(void *unused, u8 *p);
void func_021BA974(void *unused, u8 *p);
void func_021BA998(void *unused, u8 *p);
void func_021BA9B4(void *unused, u8 *p);
void func_021BA9D0(void *unused, u8 *p);
void func_021BAA0C(int a,u8 *p);
void func_021BAA30(int a,u8 *p);
void func_021BAA3C(void *unused,u8 *p);
void func_021BAA5C(void *unused,u8 *p);
void func_021BAA68(void *unused,u8 *p);
void func_021BAA74(void *unused,u8 *p);
void func_021BAA80(void *unused,u8 *p);
void func_021BAA8C(void *unused,u8 *p);
void func_021BAAF0(int a,u8 *p);
void func_021BAB0C(void *unused,u8 *p);
void func_021BAB70(int a,u8 *p);
void func_021BABAC(int a,u8 *p);
int func_021BABE8(u8 *p);
int func_021BABF4(u8 *p, int i);
void func_021BAC00(u8 *p, u8 *b, u8 n);
int func_021BAC0C(u8 *p);
void func_021BAC30(u8 *p,int mode);
u32 func_021BAC3C(u8 *p);
u32 func_021BAC40(u8 *p);
u32 func_021BAC44(u8 *p);
u32 func_021BAC4C(u8 *p);
void func_021BAC50(char *p, struct V3 *out, int i);
void func_021BAC64(unsigned p, Triple *out,unsigned i);

void func_021BA958(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BC72C((char *)(*(u8 * *)&((struct Obj13770 *)q)->f54), func_021BF714(*(u8 * *)&((struct Obj13770 *)q)->f18));
    func_021B9CBC(p);
}

/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021BA974(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BCF7C(*(u8 * *)&((struct Obj13771 *)q)->f64, (u8)func_021BF71C(*(u8 * *)&((struct Obj13771 *)q)->f18), 1);
    func_021B9CBC(p);
}

void func_021BA998(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BB6A0(*(u8 * *)&((struct Obj13772 *)q)->f58, func_021BF724(*(u8 * *)&((struct Obj13772 *)q)->f18));
    func_021B9CBC(p);
}

void func_021BA9B4(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj00135 *)p)->f0;
    func_021BFC64(*(u8 * *)&((struct Obj13773 *)q)->f5C, func_021BF784(*(u8 * *)&((struct Obj13773 *)q)->f18));
    func_021B9CBC(p);
}

void func_021BA9D0(void *unused, u8 *p)
{
    u8 *q;
    q = *(u8 * *)&((struct Obj10266 *)p)->f0;
    switch (((struct Obj10266 *)p)->f14) {
    case 0:
        func_021BFCA4(*(u8 * *)&((struct Obj10267 *)q)->f5C, func_021BF7A0(*(u8 * *)&((struct Obj10267 *)q)->f18));
        (((struct Obj10266 *)p)->f14)++;
        break;
    case 1:
        if (func_021BFD60(*(u8 * *)&((struct Obj10267 *)q)->f5C)) func_021B9CBC(p);
        break;
    }
}

void func_021BAA0C(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; func_021BCFBC((char *)(*(u8 * *)&((struct Obj22334 *)q)->f64),(u8)func_021BF71C(*(u8 * *)&((struct Obj00135 *)p)->f4),1); func_021B9CBC(p); }

void func_021BAA30(int a,u8 *p) { func_021B9CBC(p); }

void func_021BAA3C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj00135 *)p)->f0;
    if(q[0x74]!=1) func_021BC6F8(((struct Obj13774 *)q)->f54);
    func_021B9CBC(p);
}

void func_021BAA5C(void *unused,u8 *p) { func_021B9CBC(p); }

void func_021BAA68(void *unused,u8 *p) { func_021B9CBC(p); }

void func_021BAA74(void *unused,u8 *p) { func_021B9CBC(p); }

void func_021BAA80(void *unused,u8 *p) { func_021B9CBC(p); }

void func_021BAA8C(void *unused,u8 *p) {
    u8 *q;
    u32 x;
    q=*(u8 * *)&((struct Obj06386 *)p)->f0;
    x=func_021BF7FC(*(u8 * *)&((struct Obj06386 *)p)->f4);
    switch(((struct Obj06386 *)p)->f14) {
    case 0:
        func_021BCD80(*(u8 * *)&((struct Obj07998 *)q)->f64);
        func_021BB958((char *)(*(u8 * *)&((struct Obj07998 *)q)->f58));
        func_021BB9C0(*(u8 * *)&((struct Obj07998 *)q)->f58,x!=0);
        ++((struct Obj06386 *)p)->f14;
        break;
    case 1:
        if(func_021BBB0C(*(u8 * *)&((struct Obj07998 *)q)->f58,x!=0)) ++((struct Obj06386 *)p)->f14;
        break;
    case 2: func_021B9CBC(p); break;
    }
}

void func_021BAAF0(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj00135 *)p)->f0; func_021BFA40(*(u8 * *)&((struct Obj13775 *)q)->f5C,func_021BF7AC(*(u8 * *)&((struct Obj13775 *)q)->f18)); func_021B9CBC(p); }

void func_021BAB0C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj10268 *)p)->f0;
    switch(((struct Obj10268 *)p)->f14) {
    case 0:
        func_021BCEE4((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2);
        ++((struct Obj10268 *)p)->f14;
        break;
    case 1:
        if(func_021BCF38((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2)) {
            if(**(u32 * *)&((struct Obj04443 *)q)->f78==0 && func_021BF724(*(u8 * *)&((struct Obj04443 *)q)->f18)==253 && func_021BF72C(*(u8 * *)&((struct Obj04443 *)q)->f18)==253)
                func_021BCF7C(*(u8 * *)&((struct Obj04443 *)q)->f64,1,1);
            else func_021BCF7C(*(u8 * *)&((struct Obj04443 *)q)->f64,0,0);
            func_021B9CBC(p);
        }
        break;
    }
}

void func_021BAB70(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10269 *)p)->f0; switch(((struct Obj10269 *)p)->f14) { case 0: func_021BBB84(*(u8 * *)&((struct Obj10270 *)q)->f58,func_021BF724(*(u8 * *)&((struct Obj10270 *)q)->f18)); (((struct Obj10269 *)p)->f14)++; break; case 1: if(func_021BBC10(*(u8 * *)&((struct Obj10270 *)q)->f58)) func_021B9CBC(p); break; } }

void func_021BABAC(int a,u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj10271 *)p)->f0; switch(((struct Obj10271 *)p)->f14) { case 0: func_021C00AC(*(u8 * *)&((struct Obj10272 *)q)->f5C,func_021BF784(*(u8 * *)&((struct Obj10272 *)q)->f18)); (((struct Obj10271 *)p)->f14)++; break; case 1: if(func_021C00FC(*(u8 * *)&((struct Obj10272 *)q)->f5C)) func_021B9CBC(p); break; } }

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BC6DC          -> unresolved: 021BC6DC (arm, from name) has no witness outside 021BABE8..021BABF4; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 *
 * UNBLOCKED: func_021BC6DC is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
int func_021BABE8(u8 *p) { return func_021BC6DC((void *)(((struct Obj22336 *)p)->f54)); }

int func_021BABF4(u8 *p, int i) { return func_021BC6E0(*(u8 * *)&((struct Obj22337 *)p)->f54, i); }

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0008 ABS32 func_021BC320          -> unresolved: 021BC320 (arm, from name) has no witness outside 021BAC00..021BAC0C; 16 overlays overlap this address (ov016, ov021, ov088, ov091, ov093, ov099, ov110, ov114, ov172, ov208, ov209, ov210, ov211, ov216, ov217, ov223), none resolvable without a region hint on the symbols: line
 *
 * UNBLOCKED: func_021BC320 is now an EXACT entry in layout/matched/ov110;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BAC00(u8 *p, u8 *b, u8 n) { func_021BC320(((struct Obj22338 *)p)->f54, b, n); }

int func_021BAC0C(u8 *p) { if((int)func_021BCFF0((char *)(*(u8 * *)&((struct Obj13776 *)p)->f64),(u8)func_021BF71C(*(u8 * *)&((struct Obj13776 *)p)->f18))) return 1; return -1; }

void func_021BAC30(u8 *p,int mode)
{
    func_021BCF18(((struct Obj22339 *)p)->f64,mode);
}


u32 func_021BAC3C(u8 *p) { return ((struct Obj22340 *)p)->f64; }


u32 func_021BAC40(u8 *p) { return ((struct Obj22341 *)p)->f20; }


u32 func_021BAC44(u8 *p) { return ((struct Obj22342 *)p)->f80; }


u32 func_021BAC4C(u8 *p) { return ((struct Obj22343 *)p)->f7C; }

void func_021BAC50(char *p, struct V3 *out, int i)
{
    *out = *(struct V3 *)(p + i * 12 + 0x3c);
}

void func_021BAC64(unsigned p, Triple *out,unsigned i) { *out=*(Triple *)(p+i*12+0x24); }
