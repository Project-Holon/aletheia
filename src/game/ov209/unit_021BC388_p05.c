/*
 * file:     unit_021BC388_p05.c
 * unit:     yes
 * function: func_021BDBA8, func_021BDC08, func_021BDD40, func_021BDD5C, func_021BDD7C
 * address:  0x021BDBA8
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B100 0x0204B100 arm
 *   func_021C940C 0x021C940C thumb ov212
 *   func_0204BA20 0x0204BA20 arm
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_0200CA54 0x0200CA54 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   d_021BE9F0 0x021BE9F0 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   d_021BE9BC 0x021BE9BC data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0200CC40 0x0200CC40 thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0200D288 0x0200D288 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0204B604 0x0204B604 arm
 *   func_020216D4 0x020216D4 thumb
 */
#include "../../matched/include/Obj04617.h"
#include "../../matched/include/Obj25570.h"
#include "../../matched/include/Obj25571.h"
#include "../../matched/include/Obj25572.h"
#include "../../matched/include/Obj25573.h"
#include "../../matched/include/Obj25575.h"
#include "../../matched/include/Obj08410.h"
#include "../../matched/include/Obj25576.h"
#include "../../matched/include/Obj25577.h"

struct Actor;
struct Bank;
struct Blk37;
struct Obj;
struct PalAnmSlot;
struct Personal;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Template_021BDC08 { u32 w0, w4, w8, wC, w10; u16 h14, h16; } Template_021BDC08;

typedef struct Template_021BDD7C { u32 w0,w4,w8,wC,w10; u16 h14,h16; } Template_021BDD7C;

typedef struct Flags { u16 side:1; u16 rest:15; } Flags;

typedef signed int     s32;

extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_021BD8D8(char *p, u32 idx, u32 value);
extern void func_021BD890(char *, int, int);
extern u32 func_0200CA54(struct Blk37 *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern int func_02012BF8(int, int);
extern void func_0204B3B4(struct Obj *);
extern void func_0204B1CC(struct Bank *);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern int func_0202D7C8(int a0);
extern u32 func_0200D288(struct Blk37 *p, u32 which);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D7D8(int,int,int,int,int,int,int,int,u16,u16);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void func_021BDBA8(char *p);
void func_021BDC08(char *p);
void func_021BDD40(char *p,u32 idx);
void func_021BDD5C(char *p);
void func_021BDD7C(char *p,u16 species);
extern const Template_021BDC08 d_021BE9F0[10];
extern const Template_021BDD7C d_021BE9BC;

void func_021BDBA8(char *p)
{
    unsigned i;
    for(i=0;i<36;i++)if(*(unsigned *)(p+i*4+0xb64)!=-1)func_0204A8D4(*(unsigned *)(p+i*4+0xb64));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xbf4)!=-1)func_0204ADA4(*(unsigned *)(p+i*4+0xbf4));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xc0c)!=-1)func_0204AFD8(*(unsigned *)(p+i*4+0xc0c));
}

void func_021BDC08(char *p)
{
    unsigned i;
    Template_021BDC08 t;
    ((struct Obj04617 *)p)->fA70 = func_0204B100(60, 0, 0x6b);
    for (i = 0; i < 60; i++)
        *(unsigned *)(p + i * 4 + 0xa74) = 0;
    for (i = 0; i <= 9; i++) {
        t = d_021BE9F0[i];
        t.w8 = *(u32 *)(p + t.w8 * 4 + 0xb64);
        t.wC = *(u32 *)(p + t.wC * 4 + 0xbf4);
        t.w10 = *(u32 *)(p + t.w10 * 4 + 0xc0c);
        *(void **)(p + i * 4 + 0xa74) = func_021C940C((u32)(((struct Obj04617 *)p)->fA70), (const u8 *)(&t), 0x6b);
        func_0204BA20(*(void **)(p + i * 4 + 0xa74), 0);
    }
    if (((struct Obj25570 *)(*(char * *)&((struct Obj04617 *)p)->f0))->fA <= 7) {
        func_021BD8D8(p, 0, 0);
        func_021BD8D8(p, 1, 0);
    }
    if (func_0200CA54(((struct Obj25571 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        func_021BD8D8(p, 9, 0);
    if (func_0200CA38(((struct Obj25572 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        func_021BD8D8(p, 8, 0);
    if (((struct Obj25573 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f8 == 1) {
        func_021BD8D8(p, 8, 0);
        func_021BD8D8(p, 5, 0);
    } else if (func_02012BF8(**(int * *)&((struct Obj04617 *)p)->f0, 15) == 1)
        func_021BD890(p, 5, 7);
}

void func_021BDD40(char *p,u32 idx) {char *base;u32 offset;offset=idx*4;base=p+0xa74;if(*(struct Obj **)(base+offset)) {func_0204B3B4(*(struct Obj **)(base+offset));*(struct Obj **)(base+offset)=0;}}

void func_021BDD5C(char *p) {u32 i;for(i=0;i<60;i++) func_021BDD40(p,i);func_0204B1CC(*(struct Bank * *)&((struct Obj25575 *)p)->fA70);}

void func_021BDD7C(char *p,u16 species)
{
    Template_021BDD7C t;
    unsigned out1,outForm,out2;
    unsigned other,index,base;
    void *personal;
    t=d_021BE9BC;
    if (((Flags *)(p+0xc24))->side==0) {
        other=59; index=58; base=0x160;
    } else {
        other=58; index=59;
        t.w8=33; t.wC=3; t.w10=3;
        base=0x180;
    }
    if (*(unsigned *)(p+0xa74+index*4)!=0) {
        func_021BDD40(p,index);
        if (*(unsigned *)(p+t.w8*4+0xb64)!=(unsigned)-1)
            func_0204A8D4(*(unsigned *)(p+t.w8*4+0xb64));
        if (*(unsigned *)(p+t.wC*4+0xbf4)!=(unsigned)-1)
            func_0204ADA4(*(unsigned *)(p+t.wC*4+0xbf4));
        if (*(unsigned *)(p+t.w10*4+0xc0c)!=(unsigned)-1)
            func_0204AFD8(*(unsigned *)(p+t.w10*4+0xc0c));
    }
    if (species==0) {
        void *arc;
        arc=func_020490F4(0x9f,0x806b);
        *(unsigned *)(p+t.w8*4+0xb64)=func_0204A6C8(arc,0x36,0,0,0x6b);
        *(unsigned *)(p+t.wC*4+0xbf4)=func_0204AC18(arc,0x32,0,(u16)base,0,1,0x6b);
        *(unsigned *)(p+t.w10*4+0xc0c)=func_0204AF28(arc,0x3c,0x46,0x6b);
        func_02049238(arc);
        func_021BD8D8(p,2,0);
    } else {
        void *arc;
        unsigned personality;
        func_0200CC40(*(u8 * *)&((struct Obj25576 *)(*(char * *)&((struct Obj08410 *)p)->f0))->f4,species,&out1,&out2,&outForm,0x806b);
        arc=(void *)func_0202D7C8(0x806b);
        personality=species==0x147?func_0200D288(((struct Obj25577 *)(*(char * *)&((struct Obj08410 *)p)->f0))->f4,0):0;
        *(unsigned *)(p+t.w8*4+0xb64)=func_0202D81C((u32)arc,species,outForm,out1,out2,0,0,personality,0,0x6b);
        *(unsigned *)(p+t.wC*4+0xbf4)=func_0202D7D8((int)arc,species,outForm,out1,out2,0,0,0,base,0x6b);
        *(unsigned *)(p+t.w10*4+0xc0c)=func_0202D898(species,outForm,out1,out2,0,0,2,0,0x6b);
        func_02049238(arc);
        func_021BD8D8(p,2,1);
    }
    t.w8=*(unsigned *)(p+t.w8*4+0xb64);
    t.wC=*(unsigned *)(p+t.wC*4+0xbf4);
    t.w10=*(unsigned *)(p+t.w10*4+0xc0c);
    *(void **)(p+0xa74+index*4)=func_021C940C((u32)(((struct Obj08410 *)p)->fA70),(const u8 *)(&t),0x6b);
    func_0204BA20(*(void **)(p+0xa74+index*4),0);
    personal=func_0201ADE4(species,(u16)outForm,0x806b);
    if (species!=0 && func_0201AE1C(personal,0x22)==0)
        func_0204B604(*(void **)(p+0xa74+index*4),1,1);
    func_0201AE14(personal);
    func_021BD8D8(p,other,0);
    func_020216D4(((struct Obj08410 *)p)->fC,2,(u16)((base>>5)<<4),0x20);
    ((Flags *)(p+0xc24))->side^=1;
}
