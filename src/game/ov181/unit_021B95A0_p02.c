/*
 * file:     unit_021B95A0_p02.c
 * unit:     yes
 * function: func_021B9DCC, func_021B9DDC, func_021B9E14
 * address:  0x021B9DCC
 * region:   ov181
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045334 0x02045334 arm
 *   func_02046440 0x02046440 arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02047E88 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0204044C 0x0204044C arm
 *   func_021B9F9C 0x021B9F9C thumb ov181
 *   func_020434DC 0x020434DC arm
 *   func_0207D658 0x0207D658 arm
 *   d_021BAB50 0x021BAB50 data a4
 *   d_021BAB38 0x021BAB38 data a4
 *   d_021BAC68 0x021BAC68 data a4
 *   d_021BACE4 0x021BACE4 data a4
 *   d_021BACF0 0x021BACF0 data a4
 *   d_020A1E38 0x020A1E38 data a2
 */
#include "../../matched/include/Obj24505.h"
#include "../../matched/include/Obj06587.h"

struct Descriptor;
struct Util;
struct Setup;
struct LightSet;
struct LightSlot;
struct Light;
struct G3dSys;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct { u32 x,y,z; } Vec3;

extern void func_02045334(struct Descriptor *);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct Util *func_02047CFC(u16,u16,u16);
extern u16 func_02047E88(struct Util *,const struct Setup *);
extern u32 func_02048A18(u8 *,int);
extern int func_0204779C(int *);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern struct LightSlot *func_02048BC4(const struct LightSet *,u32);
extern void func_02048C58(struct LightSlot *);
extern u32 *func_02048A24(u32,u32,u32,u32,u32,u32,u32,u32,Vec3 *,Vec3 *,Vec3 *,u16);
extern void func_02048AD0(struct Light *);
extern void func_0204044C(u32);
extern void func_021B9F9C(u8 *p);
extern void func_020434DC(u32,u32);
extern void func_0207D658(u32,int,int);
void func_021B9DCC(char *p, u32 v);
void func_021B9DDC(char *p);
void func_021B9E14(char *p);
extern const struct Setup d_021BAB50;
extern const struct LightSet d_021BAB38;
extern const Vec3 d_021BAC68;
extern Vec3 d_021BACE4,d_021BACF0;
extern const u8 d_020A1E38[];


void func_021B9DCC(char *p, u32 v)
{
    ((struct Obj24505 *)p)->f2CC |= (u8)v;
}

/*
 * Tail: two zero alignment bytes at 0x021B9E12.
 */
void func_021B9DDC(char *p){if(((struct Obj06587 *)p)->f2CC&1)func_02045334((struct Descriptor *)((struct Obj06587 *)p)->f2BC);if(((struct Obj06587 *)p)->f2CC&2)func_02045334((struct Descriptor *)((struct Obj06587 *)p)->f2C4);((struct Obj06587 *)p)->f2CC=0;}

static inline void AntiAlias(int enable) {
    u32 tmp=*(volatile u16 *)0x04000060 & ~0x3000;
    if(enable) tmp|=0x10;
    else tmp&=~0x10;
    *(volatile u16 *)0x04000060=(u16)tmp;
}

void func_021B9E14(char *p) {
    Vec3 v;
    u32 i;
    func_02046440(0,2,0,2,4096,142,0);
    *(struct Util **)(p+8)=func_02047CFC(3,1,142);
    *(u16 *)(p+0x18)=func_02047E88(*(struct Util **)(p+8),&d_021BAB50);
    *(u32 *)(p+0x20)=func_02048A18(*(u8 **)(p+8),*(u16 *)(p+0x18));
    *(u32 *)(p+0x24)=func_0204779C(*(int **)(p+0x20));
    for(i=0;i<*(u32 *)(p+0x24);i++) func_020477A4(*(struct G3dSys **)(p+0x20),(u16)i);
    *(struct LightSlot **)(p+0x10)=func_02048BC4(&d_021BAB38,142);
    func_02048C58(*(struct LightSlot **)(p+0x10));
    v=d_021BAC68;
    *(u32 **)(p+0xc)=func_02048A24(0,*(s16 *)(d_020A1E38+0x8c),*(s16 *)(d_020A1E38+0x8e),0x1555,
        0,4096,0x400000,0,&d_021BACE4,&v,&d_021BACF0,142);
    func_02048AD0(*(struct Light **)(p+0xc));
    AntiAlias(1);
    func_0204044C(2);
    func_021B9F9C((u8 *)(p+0x28));
    func_020434DC(1,0);
    func_0207D658(0x04000050,1,-16);
}
