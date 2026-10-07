/*
 * file:     b_plist_main_p02.c
 * unit:     yes
 * function: func_022107A8, func_0221099C, func_02210A4C, func_02210B00, func_02210B30
 * address:  0x022107A8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_020276C4 0x020276C4 thumb
 *   func_02018544 0x02018544 thumb
 *   func_02018584 0x02018584 thumb
 *   sub_0201C158 0x0201C158 thumb
 *   sub_0201BD28 0x0201BD28 thumb
 *   sub_0201C1F4 0x0201C1F4 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02211970 0x02211970 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F4C 0x02210F4C thumb ov198
 *   func_02210EFC 0x02210EFC thumb ov198
 *   d_02212130 0x02212130 data a1
 */
#include "../../matched/include/Obj04603.h"
#include "../../matched/include/Obj25259.h"
#include "../../matched/include/Obj25260.h"
#include "../../matched/include/Obj25261.h"
#include "../../matched/include/Obj25262.h"
#include "../../matched/include/Obj25263.h"
#include "../../matched/include/Obj25264.h"
#include "../../matched/include/Obj25265.h"
#include "../../matched/include/Obj25266.h"

struct Summary;
struct Sound;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Move {u16 id;u8 pp,up,kind,power,type,accuracy;};

struct Summary {
    void *mon;
    u16 species,hp,attack,defense,speed,stat6,spatk,spdef;
    u8 ability,form;
    u8 level:7,egg:1;
    u8 gender:3,nature:4,flag:1;
    u16 item,unknown;
    u32 exp,lower,upper,personality;
    struct Move moves[4];
};

struct Order {u8 ids[6];};

struct Flags {u8 low:7,high:1;};

extern u32 func_02017E1C(void *,u32,u32);
extern u8 func_02017F00(void *);
extern int func_020276C4(int a0);
extern u32 func_02018544(void *);
extern u32 func_02018584(u16,u16,u16);
extern u8 sub_0201C158(u16,u32);
extern u32 sub_0201BD28(u16,u32);
extern u32 sub_0201C1F4(u16);
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
extern int func_02025DE8(struct Sound *);
extern void func_02211970(u8 **,u32);
extern int func_022110D4(u8 *,int),func_02210F4C(u8 *,int);
extern int func_02210EFC(char **p);
extern int func_022110D4(u8 *,int);
void func_022107A8(void *unused,void *mon,struct Summary *p);
void func_0221099C(u8 *p);
int func_02210A4C(u8 *p);
int func_02210B00(u8 *p,int i);
u8 func_02210B30(u8 *p,int i,int delta);
extern const struct Order d_02212130;

/*
 * lever: write upper experience to the same field in both if/else arms;
 *   one common store or a switch removes the original two-byte branch.
 * 2026-10-04: filed src/matched/arm9/func_02018544.c (EXACT, 8 bytes); needs the label registered by the integrator, then this resolves.
 *   022107A8..0221099C. Ilias-owned ARM9 Thumb tail stub, verified EXACT
 *   (8 bytes, 1/1 relocation resolved) in B9/blocker18544.log:
 *   typedef unsigned int u32;
 *   extern u32 func_0201854C(void *);
 *   u32 func_02018544(void *p) {return func_0201854C(p);}
 * 020276C4's matched legacy C has unused a1/a2/a3 parameters; this caller
 * and the callee body use only a0, so its declaration here has one argument.
 */
void func_022107A8(void *unused,void *mon,struct Summary *p)
{
    u32 exp;
    unsigned i;
    struct Move *move;
    struct Move *moves;
    p->mon=mon;
    if(mon==0) {
        p->species=0;
        return;
    }
    p->species=func_02017E1C(mon,5,0);
    if(p->species==0) return;
    p->hp=func_02017E1C(p->mon,0xa2,0);
    p->attack=func_02017E1C(p->mon,0xa3,0);
    p->defense=func_02017E1C(p->mon,0xa4,0);
    p->speed=func_02017E1C(p->mon,0xa5,0);
    p->stat6=func_02017E1C(p->mon,0xa6,0);
    p->spatk=func_02017E1C(p->mon,0xa0,0);
    p->spdef=func_02017E1C(p->mon,0xa1,0);
    p->ability=func_02017E1C(p->mon,0xae,0);
    p->form=func_02017E1C(p->mon,0xaf,0);
    p->level=(u8)func_02017E1C(p->mon,0x9e,0);
    if(func_02017E1C(p->mon,0xad,0)==1) p->egg=0;
    else p->egg=1;
    p->gender=func_02017F00(p->mon);
    p->nature=(u8)func_020276C4((int)p->mon);
    p->flag=(u8)func_02017E1C(p->mon,0x4c,0);
    p->item=func_02017E1C(p->mon,10,0);
    p->unknown=func_02017E1C(p->mon,6,0);
    p->personality=func_02017E1C(p->mon,0x6f,0);
    p->exp=func_02017E1C(p->mon,8,0);
    exp=func_02018544(p->mon);
    p->lower=exp;
    if(p->level==100) p->upper=p->lower;
    else p->upper=func_02018584(p->species,(u16)p->personality,(u16)(p->level+1));
    i=0;
    moves=p->moves;
    for(;i<4;i++) {
        move=&moves[i];
        moves[i].id=func_02017E1C(p->mon,i+0x36,0);
        if(moves[i].id==0) continue;
        move->pp=func_02017E1C(p->mon,i+0x3a,0);
        move->up=func_02017E1C(p->mon,i+0x3e,0);
        move->up=sub_0201C158(move->id,move->up);
        move->kind=sub_0201BD28(move->id,0);
        move->power=sub_0201BD28(move->id,2);
        if(sub_0201C1F4(move->id)==1) move->type=0;
        else move->type=sub_0201BD28(move->id,4);
        move->accuracy=sub_0201BD28(move->id,3);
    }
}

/*
 * remainder: two-byte alignment padding at 02210A4A.
 */
void func_0221099C(u8 *p)
{
    unsigned i;
    if (((struct Obj25259 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f18==0) {
        for (i=0;i<6;i++) {
            if (i<func_0201AA18(((struct Obj25260 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                func_022107A8(p,func_0201AB28(((struct Obj25261 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else func_022107A8(p,0,(struct Summary *)(p+4+i*76));
        }
    } else {
        for (i=0;i<3;i++) {
            if (i<func_0201AA18(((struct Obj25262 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                func_022107A8(p,func_0201AB28(((struct Obj25263 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else func_022107A8(p,0,(struct Summary *)(p+4+i*76));
            if (i<func_0201AA18(((struct Obj25264 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8))
                func_022107A8(p,func_0201AB28(((struct Obj25265 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8,i),(struct Summary *)(p+4+(i+3)*76));
            else func_022107A8(p,0,(struct Summary *)(p+4+(i+3)*76));
        }
    }
}

int func_02210A4C(u8 *p)
{
    u32 sel=func_02025DE8(*(struct Sound * *)&((struct Obj25266 *)p)->f2184);
    switch(sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if(func_02210B00(p,sel)) {
            (*(u8 **)p)[32]=sel;
            return 1;
        }
        break;
    case 6:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-2:
        (*(u8 **)p)[32]=6;
        return 1;
    case (u32)-3: case (u32)-4:
        func_02211970((u8 **)p,1352);
        break;
    case (u32)-1: case (u32)-5: case (u32)-6: case (u32)-7: case (u32)-8:
        break;
    }
    return 0;
}

int func_02210B00(u8 *p,int i) { if(!*(u16 *)(p+func_022110D4(p,i)*76+8))return 0;if(func_02210F4C(p,i)==1)return 1;return 2; }

u8 func_02210B30(u8 *p,int i,int delta)
{
    int current=i;
    if(func_02210EFC((char **)((unsigned)p))==1) {
        struct Order order=d_02212130;
        u8 selected;
        for(i=0;i<6;i++) if(current==order.ids[i]) break;
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            selected=order.ids[i];
            if(current==selected) break;
            if(!func_02210B00(p,selected)) continue;
            if(((struct Flags *)(p+func_022110D4(p,selected)*0x4c+0x1b))->high) continue;
            return selected;
        }
    } else {
        for(;;) {
            i+=delta;
            if(i<0) i=5;
            else if(i>=6) i=0;
            if(current==i) break;
            if(!func_02210B00(p,i)) continue;
            if(((struct Flags *)(p+func_022110D4(p,i)*0x4c+0x1b))->high) continue;
            return i;
        }
    }
    return 255;
}
