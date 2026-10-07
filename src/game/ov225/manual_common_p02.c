/*
 * file:     manual_common_p02.c
 * unit:     yes
 * function: func_021BA1C4, func_021BA218, func_021BA240, func_021BA28C, func_021BA2B0, func_021BA30C, func_021BA368, func_021BA41C, func_021BA4D8
 * address:  0x021BA1C4
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021BBF00 0x021BBF00 data a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027614 0x02027614 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_02027618 0x02027618 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BBF14 0x021BBF14 data a4
 *   sub_0204B3B4 0x0204B3B4 arm
 *   sub_0204AFD8 0x0204AFD8 arm
 *   sub_0204A8D4 0x0204A8D4 arm
 *   sub_0204ADA4 0x0204ADA4 arm
 */
#include "../../matched/include/Obj26149.h"
#include "../../matched/include/Obj26150.h"
#include "../../matched/include/Obj26151.h"
#include "../../matched/include/Obj26152.h"
#include "../../matched/include/Obj08469.h"
#include "../../matched/include/Obj26153.h"
#include "../../matched/include/Obj04652.h"
#include "../../matched/include/Obj26154.h"
#include "../../matched/include/Obj26155.h"
#include "../../matched/include/Obj26156.h"
#include "../../matched/include/Obj26157.h"
#include "../../matched/include/Obj04653.h"
#include "../../matched/include/Obj26158.h"
#include "../../matched/include/Obj26159.h"
#include "../../matched/include/Obj26160.h"
#include "../../matched/include/Obj26161.h"
#include "../../matched/include/Obj02561.h"
#include "../../matched/include/Obj26162.h"
#include "../../matched/include/Obj26163.h"
#include "../../matched/include/Obj26164.h"
#include "../../matched/include/Obj26165.h"
#include "../../matched/include/Obj26166.h"
#include "../../matched/include/Obj26167.h"
#include "../../matched/include/Obj02562.h"
#include "../../matched/include/Obj10983.h"
#include "../../matched/include/Obj14803.h"
#include "../../matched/include/Obj26168.h"
#include "../../matched/include/Obj26169.h"
#include "../../matched/include/Obj26170.h"
#include "../../matched/include/Obj26171.h"
#include "../../matched/include/Obj10984.h"

struct Descriptor;
struct CharBuf;
struct PrintSys;
struct Cfg;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Obj;
typedef unsigned char u8;

struct Entry {u8 a,b,c,d,e,f,g,h,i;};

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef short s16;

extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045334(struct Descriptor *);
extern void func_0201C6EC(struct PrintSys *),func_020452E8(struct Descriptor *);
extern unsigned func_0201C6C4(struct PrintSys *,void *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern void func_0201C724(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02045808(struct U16Vec *);
extern struct WordSet *func_0201EC64(u32);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_020275E4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02027614(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_02027618(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern u32 func_021B9A08(const u8 *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void sub_0204B3B4(struct Obj *);
extern void sub_0204AFD8(u32);
extern void sub_0204A8D4(u32);
extern void sub_0204ADA4(u32);
void func_021BA1C4(char *p);
void func_021BA218(char *p);
void func_021BA240(char *p);
void func_021BA28C(char *p);
void func_021BA2B0(char *p);
void func_021BA30C(char *p);
void func_021BA368(char *p);
void func_021BA41C(char *p);
void func_021BA4D8(char *p);
extern const struct Entry d_021BBF00[];
extern const u8 d_021BBF14[];

void func_021BA1C4(char *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        const struct Entry *t=&d_021BBF00[i];
        *(unsigned *)(p+i*4+0x10)=func_020450F0(t->a,t->b,t->c,t->d,t->e,t->f,t->g);
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*4+0x10)),0);
        func_02045334(*(struct Descriptor **)(p+i*4+0x10));
        *(unsigned *)(p+i*4+0x18)=0;
    }
}

void func_021BA218(char *p){unsigned char i;func_0201C6EC(*(struct PrintSys * *)&((struct Obj26150 *)(*(char * *)&((struct Obj26149 *)p)->f0))->f18);for(i=0;i<2;i++){*(unsigned *)((unsigned)p+i*4+24)=0;func_020452E8(*(struct Descriptor **)((unsigned)p+i*4+16));}}

void func_021BA240(char *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(unsigned *)(p+i*4+0x18)!=0) {
            if(func_0201C6C4(*(struct PrintSys * *)&((struct Obj26152 *)(*(char * *)&((struct Obj26151 *)p)->f0))->f18,func_02045770(*(struct Descriptor **)(p+i*4+0x10)))==0) {
                struct Descriptor *d=*(struct Descriptor **)(p+i*4+0x10);
                func_02045334(d);func_02045374((struct Cfg *)d);
                func_02041B6C(func_02045730(d));
                *(unsigned *)(p+i*4+0x18)=0;
            }
        }
    }
}

void func_021BA28C(char *p){func_0201C6EC(*(struct PrintSys * *)&((struct Obj26153 *)(*(char * *)&((struct Obj08469 *)p)->f0))->f18);func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj08469 *)p)->f14),0);func_02045334(*(struct Descriptor * *)&((struct Obj08469 *)p)->f14);((struct Obj08469 *)p)->f1C=0;}

void func_021BA2B0(char *p)
{
    void *s;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj26154 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26155 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f1C,2);
    func_0201C724(((struct Obj26156 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18,(unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0,4,(unsigned)s,((struct Obj26157 *)(*(char * *)&((struct Obj04652 *)p)->f0))->fC,0x3c40);
    func_02045808(s);((struct Obj04652 *)p)->f1C=1;func_021BA240(p);
}

void func_021BA30C(char *p)
{
    void *s;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj26158 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f18);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj04653 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26159 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f1C,3);
    func_0201C724(((struct Obj26160 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f18,(unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj04653 *)p)->f14),0,4,(unsigned)s,((struct Obj26161 *)(*(char * *)&((struct Obj04653 *)p)->f0))->fC,0x3c40);
    func_02045808(s);((struct Obj04653 *)p)->f1C=1;func_021BA240(p);
}

/*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 */
void func_021BA368(char *p)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj26162 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f18);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj02561 *)p)->f14),0);
    words=func_0201EC64(((struct Obj26163 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f4);
    slot=func_02045EC0(*(struct MsgBank * *)&((struct Obj26164 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f1C,4);
    str=func_020457B0(16,((struct Obj26165 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f4);
    func_0201EFA4(words,0,((struct Obj02561 *)p)->fD+1,1,0,1);
    func_0201EFA4(words,1,((struct Obj02561 *)p)->fC,1,0,1);
    func_0201F250(words,str,slot);
    func_0201C724(((struct Obj26166 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f18,(u32)func_02045770(*(struct Descriptor * *)&((struct Obj02561 *)p)->f14),32,4,(u32)str,((struct Obj26167 *)(*(char * *)&((struct Obj02561 *)p)->f0))->fC,0x3c40);
    func_02045808(str);func_02045808(slot);func_0201ED04(words);
    ((struct Obj02561 *)p)->f1C=1;func_021BA240(p);
}

void func_021BA41C(char *p)
{
    u8 i;
    void *loader;
    u32 first;
    loader=func_020490F4(func_020275E4(),((struct Obj26168 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    *(int *)&((struct Obj02562 *)p)->f30=func_0204AC18((void *)((u32)loader),func_02027614(),1,128,0,3,((struct Obj26169 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    *(int *)&((struct Obj02562 *)p)->f2C=func_0204A6C8((void *)((u32)loader),func_02027618(),0,1,((struct Obj26170 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    first=func_0202761C(0);
    *(int *)&((struct Obj02562 *)p)->f34=func_0204AF28((void *)((u32)loader),first,func_02027620(0),((struct Obj26171 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    func_02049238(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char * *)&((struct Obj02562 *)p)->f0;
        char *dest=p+i*4;
        *(struct Obj * *)&((struct Obj10983 *)dest)->f38=func_0204B294((void *)func_021B9A08(((struct Obj14803 *)parent)->f8),((struct Obj02562 *)p)->f2C,((struct Obj02562 *)p)->f30,((struct Obj02562 *)p)->f34,&d_021BBF14[i*28],1,((struct Obj14803 *)parent)->f4);
        func_0204B3DC(*(struct Obj * *)&((struct Obj10983 *)dest)->f38,0);
        func_0204B92C(*(struct Obj * *)&((struct Obj10983 *)dest)->f38,1);
    }
}

void func_021BA4D8(char *p) { u8 i; for(i=0;i<2;i++) sub_0204B3B4(*(struct Obj **)(p+i*4+0x38)); sub_0204AFD8(((struct Obj10984 *)p)->f34); sub_0204A8D4(((struct Obj10984 *)p)->f2C); sub_0204ADA4(((struct Obj10984 *)p)->f30); }
