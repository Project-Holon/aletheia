/*
 * function: func_021BDD7C
 * address: 0x021BDD7C
 * packet: pkt_ov209_021BDD7C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: write the template's two 3 values before assigning base=0x180; mwcc derives that base from the live 3 with lsls #7.
 * prototype: D7C8 only reads/forwards a0; stale trailing args omitted. D81C/D898 tail scalars occupy their exact word slots; both full bodies read only low halfword of final heap slot, never padding.
 * symbols:
 *   d_021BE9BC 0x021BE9BC data a4
 *   func_021BDD40 0x021BDD40 thumb ov209
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   func_0200CC40 0x0200CC40 thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0200D288 0x0200D288 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_021C940C 0x021C940C thumb ov212
 *   func_0204BA20 0x0204BA20 arm
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0204B604 0x0204B604 arm
 *   func_020216D4 0x020216D4 thumb
 */
#include "../include/Obj08410.h"
#include "../include/Obj25576.h"
#include "../include/Obj25577.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Template { u32 w0,w4,w8,wC,w10; u16 h14,h16; } Template;
typedef struct Flags { u16 side:1; u16 rest:15; } Flags;
extern const Template d_021BE9BC;
extern void func_021BDD40(char *,unsigned);
extern void func_0204A8D4(u32),func_0204ADA4(u32),func_0204AFD8(u32);
extern void *func_020490F4(u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
typedef signed int     s32;
struct PalAnmSlot;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
struct Actor;
struct Blk37;
struct Personal;
extern void func_021BD8D8(char *p, u32 idx, u32 value);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern int func_0202D7C8(int a0);
extern u32 func_0200D288(struct Blk37 *p, u32 which);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D7D8(int,int,int,int,int,int,int,int,u16,u16);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void *func_021C940C(void *,const Template *,u32);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void func_021BDD7C(char *p,u16 species)
{
    Template t;
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
    *(void **)(p+0xa74+index*4)=func_021C940C(((struct Obj08410 *)p)->fA70,&t,0x6b);
    func_0204BA20(*(void **)(p+0xa74+index*4),0);
    personal=func_0201ADE4(species,(u16)outForm,0x806b);
    if (species!=0 && func_0201AE1C(personal,0x22)==0)
        func_0204B604(*(void **)(p+0xa74+index*4),1,1);
    func_0201AE14(personal);
    func_021BD8D8(p,other,0);
    func_020216D4(((struct Obj08410 *)p)->fC,2,(u16)((base>>5)<<4),0x20);
    ((Flags *)(p+0xc24))->side^=1;
}
