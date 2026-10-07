/*
 * file:     guru2_main_p02.c
 * unit:     yes
 * function: func_021DD5AC, func_021DD638, func_021DD700, func_021DD760, func_021DD79C, func_021DD7E4, func_021DD80C
 * address:  0x021DD5AC
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021DE248 0x021DE248 thumb ov137
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_02039338 0x02039338 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   func_021841A4 0x021841A4 thumb ov022
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 *   func_021DE220 0x021DE220 thumb ov137
 *   func_021DE350 0x021DE350 thumb ov137
 *   func_021DE7F4 0x021DE7F4 thumb ov137
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_02184114 0x02184114 thumb ov022
 *   func_02184134 0x02184134 thumb ov022
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj14208.h"
#include "../../matched/include/Obj00170.h"
#include "../../matched/include/Obj05425.h"
#include "../../matched/include/Obj06534.h"
#include "../../matched/include/Obj08211.h"
#include "../../matched/include/Obj23713.h"
#include "../../matched/include/Obj23714.h"

struct Obj;
struct CharBuf;
struct Descriptor;
struct StrObj;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_02045088(u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021DE248(void *,int,u16,void *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_0201FEF4(u8 *o);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern u16 func_02039338(void);
extern void func_0203D7B0(unsigned char a0);
extern void *func_021DCF50(u8 *p);
extern int func_021841A4(unsigned char *p);
extern void func_021DE4B4(char *, int, int);
extern void func_021DD93C(char *, int);
extern int func_021DE220(void *);
extern void func_021DE350(char *);
extern unsigned func_021DE7F4(void);
extern int func_021DE354(void *p);
extern int func_02184114(unsigned char *p);
extern void func_02184134(u8 *p);
extern void func_020061E4(u32 a);
void func_021DD5AC(u8 *p);
void func_021DD638(u8 *p);
void func_021DD700(void *p, void *text, void *font);
void func_021DD760(u8 *p);
int func_021DD79C(char *p, int state);
int func_021DD7E4(char *p,int a);
void func_021DD80C(char *p);
extern const u16 d_021E1B08[];

/*
 * func_0204B294 0x0204B294 arm
 * func_0204B92C 0x0204B92C arm
 * func_0204B878 0x0204B878 arm
 * func_0204B3DC 0x0204B3DC arm
 * func_020434DC 0x020434DC arm
 * func_02043598 0x02043598 arm
 * d_021E1B08 0x021E1B08 data a2
 */
void func_021DD5AC(u8 *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=d_021E1B08[i*2+2]; s.b=d_021E1B08[i*2+3];
        *(u32 *)(p+i*4+156)=(u32)func_0204B294((void *)((struct Obj14208 *)p)->f68,*(u32 *)(p+i*4+128),*(u32 *)(p+i*4+108),((struct Obj14208 *)p)->f94,&s,0,114);
        func_0204B92C((struct Obj *)*(u32 *)(p+i*4+156),1);
        func_0204B878((struct Obj *)(*(u32 *)(p+i*4+156)),0);
        func_0204B3DC((struct Obj *)*(u32 *)(p+i*4+156),0);
    }
    func_020434DC(16,1); func_02043598(16,0);
}

/*
 * extent: Two-byte alignment padding at 0x021DD6FE.
 */
void func_021DD638(u8 *p) {
    func_02045088(0x72);
    *(u32 *)&((struct Obj00170 *)p)->fD8=func_020450F0(5,26,20,6,2,13,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD8),0);
    *(u32 *)&((struct Obj00170 *)p)->fD4=func_020450F0(0,2,19,27,4,13,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD4),15);
    *(u32 *)&((struct Obj00170 *)p)->fDC=func_020450F0(0,3,1,26,2,15,1);
    func_021DD700(((struct Obj00170 *)p)->fDC,((struct Obj00170 *)p)->f60,((struct Obj00170 *)p)->f38);
    *(u32 *)&((struct Obj00170 *)p)->fD0=func_020450F0(0,2,6,16,11,15,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD0),0);
    func_021DE248(((struct Obj00170 *)p)->fD0,0,0x480,p);
    ((struct Obj00170 *)p)->fF8=((struct Obj00170 *)p)->fDC;
    ((struct Obj00170 *)p)->fFC=0;
}

void func_021DD700(void *p, void *text, void *font) {
    int width;
    width = func_0201D304(text, (u32)font, 0);
    func_02043B5C(func_02045770(p), 0);
    func_0201C7D0(func_02045770(p), (208-width)/2, 1, text, font, 0x480);
    func_02045334(p);
    func_02045374(p);
    func_020409B4((u32)func_02045730(p));
}

void func_021DD760(u8 *p) {if(((struct Obj05425 *)p)->fE8!=0)func_0201FEF4(((struct Obj05425 *)p)->fE8);func_020452E8(((struct Obj05425 *)p)->fD0);func_020452E8(((struct Obj05425 *)p)->fDC);func_020452E8(((struct Obj05425 *)p)->fD8);func_020452E8(((struct Obj05425 *)p)->fD4);func_020450C8();}

int func_021DD79C(char *p, int state) {
    if (func_02039338() == 0) {
        int zero = 0;
        func_0203D7B0(0);
        if ((unsigned)func_021841A4(func_021DCF50((u8 *)p)) >= 2)
            func_021DE4B4(p, 2, zero);
    } else {
        func_0203D7B0(1);
        func_021DE4B4(p, 8, 0);
    }
    func_021DD93C(p, 3);
    return state;
}

/*
 * Lever: nested explicit empty then/else-call plus outer else-call preserves the b-to-next at +0x1c; goto spelling DIFF12/38B.
 * abi: 021DD802 visibly reloads p into r0 for 021DE350; retain that argument despite its empty matched body.
 */
int func_021DD7E4(char *p,int a) {func_021DD80C(p);if(func_02039338()==0) {if(func_021DE220(p)==1) {} else func_021DE350(p);}else func_021DE350(p);return a;}

void func_021DD80C(char *p) {
    char *q;
    if (func_021DE7F4()&1) {
        if (func_02039338()==0) {
            q=*(char * *)&((struct Obj06534 *)p)->f10;
            if (((struct Obj08211 *)q)->f2C==func_021DE354(p) && ((struct Obj08211 *)q)->f30==0) {
                if (func_02184114(func_021DCF50((u8 *)p))) {
                    func_020061E4(0x54c);
                    func_021DE4B4(p,3,0);
                    func_021DD93C(p,22);
                }
            } else func_020061E4(0x548);
        }
    } else if (func_021DE7F4()&2) {
        if (func_02039338()!=0) {
            if (((struct Obj23713 *)(*(char * *)&((struct Obj06534 *)p)->f10))->f28==0) {
                func_021DE4B4(p,4,0);
                func_021DD93C(p,4);
            } else func_020061E4(0x548);
        } else {
            q=*(char * *)&((struct Obj06534 *)p)->f10;
            if (((struct Obj08211 *)q)->f2C==func_021841A4(func_021DCF50((u8 *)p)) && ((struct Obj08211 *)q)->f30==0) {
                if (func_02184114(func_021DCF50((u8 *)p))) {
                    func_021DE4B4(p,4,0);
                    func_021DD93C(p,4);
                    func_020061E4(0x551);
                }
            } else func_020061E4(0x548);
        }
    } else {
        if (((struct Obj06534 *)p)->f4808==0 && func_02039338()==0 &&
            ((struct Obj23714 *)(*(char * *)&((struct Obj06534 *)p)->f10))->f2C==func_021841A4(func_021DCF50((u8 *)p)))
            func_02184134(func_021DCF50((u8 *)p));
    }
}
