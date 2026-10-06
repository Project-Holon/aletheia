/*
 * function: func_021F15B0
 * address: 0x021F15B0
 * packet: pkt_ov107_021F15B0
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_02028484 0x02028484 thumb
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045334 0x02045334 arm
 *   func_0202EE8C 0x0202EE8C thumb
 *   func_02027974 0x02027974 thumb
 */
#include "../include/Obj22302.h"
typedef unsigned short u16;
struct Descriptor;
struct Ctx;
struct Rec3;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045334(struct Descriptor *);
extern void func_02027974(void *);
typedef signed int     s32;
struct Blk;
struct PrintSys;
extern s32 func_02028484(struct Blk *blk, void *h);
extern unsigned int func_0201C4E4(struct PrintSys *ps);
extern unsigned int func_0201C6B4(const struct PrintSys *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *func_0202EE8C(u32 a, void *b, u8 c, u8 d, u16 e);
#define P(k) (*(void **)(p+(k)))
#define I(k) (*(int *)(p+(k)))
void func_021F15B0(char *p)
{
    int done;
    func_020310C4(P(12));
    if(P(0x18)){
        done=func_02028484((struct Blk *)(p+0x28),P(0x18));
        func_020286C4(P(0x44),P(0x18),P(0x10));
        if(done==1){func_0201CE48(P(0x18));P(0x18)=0;}
    }
    func_0201C4E4(P(0x30));
    if(I(0x34)==1 && func_0201C6B4(P(0x30))==1){
        func_02045334(P(0x10));I(0x34)=0;
        if(I(0x58)==1){I(0x58)=0;P(0x5C)=func_0202EE8C((u32)P(12),P(0x10),15,16,((struct Obj22302 *)p)->f0);}
    }
    if(P(0x3C))func_02027974(P(0x3C));
}
