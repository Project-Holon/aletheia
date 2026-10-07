/*
 * file:     btl_rec_sel_p07.c
 * unit:     yes
 * function: func_021BABF4, func_021BAC3C, func_021BAC58, func_021BAC90, func_021BACCC, func_021BAD08
 * address:  0x021BABF4
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0204989C 0x0204989C arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_02040618 0x02040618 arm
 *   func_02041570 0x02041570 arm
 */
#include "../../matched/include/Obj00182.h"
#include "../../matched/include/Obj25728.h"
#include "../../matched/include/Obj14701.h"
#include "../../matched/include/Obj14702.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049740(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_02049238(void *);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02041B6C(u32);
extern void func_02041EE4(u32,u32,u32);
extern void func_02040618(u32,u32,u32);
extern void func_02041570(int channel, u16 val);
void func_021BABF4(int unused, char *p);
void func_021BAC3C(int unused,u8 *p);
void func_021BAC58(int unused,u8 *p);
void func_021BAC90(int unused,u8 *p);
void func_021BACCC(int unused,u8 *p);
void func_021BAD08(void *a0, char *a1);


void func_021BABF4(int unused, char *p)
{
    void *h = func_020490F4(188, ((struct Obj00182 *)p)->f0);
    func_02049B68(h, 0, 0, 0, 320, ((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f2C0 = func_02049740(h, 1, 2, 0, 0, ((struct Obj00182 *)p)->f0);
    func_02049238(h);
}

void func_021BAC3C(int unused,u8 *p){u32 v=((struct Obj25728 *)p)->f2C0;func_0203FB44(2,(u16)v,(u16)(v>>16));}

void func_021BAC58(int unused,u8 *p){func_0204989C(188,2,2,(u16)(((struct Obj00182 *)p)->f2C0),0,0,((struct Obj00182 *)p)->f0);func_02041B6C(2);func_02041EE4(3,3,0);}

void func_021BAC90(int unused,u8 *p){enum{K=2}k=K;func_0204989C(188,3,k,(u16)(((struct Obj14701 *)p)->f2C0),0,0,((struct Obj14701 *)p)->f0);func_02041B6C(2);k-=10;func_02040618(3,3,k);}

void func_021BACCC(int unused,u8 *p){enum{K=3}k;func_0204989C(188,4,2,(u16)(((struct Obj14702 *)p)->f2C0),0,0,((struct Obj14702 *)p)->f0);func_02041B6C(2);k=K;func_02040618(3,3,k-11);}

void func_021BAD08(void *a0, char *a1){func_02041570(2,0);}
