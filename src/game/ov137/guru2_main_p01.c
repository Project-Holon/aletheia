/*
 * file:     guru2_main_p01.c
 * unit:     yes
 * function: func_021DD3B0, func_021DD3D8, func_021DD4A8, func_021DD570
 * address:  0x021DD3B0
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
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 */
#include "../../matched/include/Obj10616.h"
#include "../../matched/include/Obj14207.h"

struct Bank;
struct Cfg;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed short s16;

typedef unsigned short u16;

extern void func_020403F4(u32);
extern void func_0203F9B4(void);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32,u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u8 *func_02012944(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021DD3B0(u32 a0);
void func_021DD3D8(void *p,void *arc);
void func_021DD4A8(const u8 *p);
void func_021DD570(u8 *p);
extern const u32 d_020A1448[],d_021E1B40[],d_021E1B20[],d_021E1B30[],d_021E1B38[];

void func_021DD3B0(u32 a0) {func_020403F4(6);func_020403F4(5);func_020403F4(4);func_020403F4(1);func_020403F4(0);func_0203F9B4();}

/*
 * single-function C below is EXACT (52 bytes) at fixed flags, blocker49624.log.
 * typedef unsigned short u16; typedef unsigned int u32;
 * extern u32 func_0204A1BC(void *,void *,u32,u16);
 * extern u32 func_0204968C(u32,void *,void *,u32,u32);
 * u32 func_02049624(void *a,void *b,void *c,void *d,u32 e,u32 f,u16 g) {
 *     u32 r=func_0204A1BC(a,b,f,g); return func_0204968C(r,c,d,e,f);
 * }
 * Blocker symbols: func_0204A1BC 0x0204A1BC arm; func_0204968C 0x0204968C arm.
 * func_02049B68 0x02049B68 arm
 * func_02049658 0x02049658 arm
 * func_020498F4 0x020498F4 arm
 * func_02049B40 0x02049B40 arm
 * func_02049624 0x02049624 arm
 * func_0204989C 0x0204989C arm
 * func_02040588 0x02040588 arm
 * func_0201F5BC 0x0201F5BC thumb
 */
void func_021DD3D8(void *p,void *arc)
{
    func_02049B68(arc,1,0,0,512,114);
    func_02049658(arc,7,1,0,8192,0,114);
    func_020498F4(arc,13,1,0,1536,0,114);
    func_02049B40(23,5,0,416,32,114);
    func_02049B40(30,13,4,0,352,114);
    func_02049624((void *)30,(void *)14,(void *)6,0,0,0,114);
    func_0204989C(30,3,6,0,0,0,114);
    func_0201F5BC(0,1,10,0,114);
    func_0201F5BC(0,31,11,0,114);
    func_02040588(0,1);
    func_02040588(1,1);
    func_02040588(6,1);
}

/*
 * note: 2026-10-05 wave P13 B4: the older draft was DIFF 2/200 (v in r4 instead
 *   of r5). `i = 0;` assigned before `table = ...` (so the counter web starts
 *   while v is live) and `for (; i < 5; ...)` gives EXACT in c99 and c. v is a
 *   plain u8 (the enum local is not needed). Callees: 02008550 returns u8-range
 *   index, 0204B100 returns a pointer, others as in matched callers.
 * func_02012944 0x02012944 thumb
 * func_02008550 0x02008550 thumb
 * func_020490F4 0x020490F4 arm
 * func_0204A48C 0x0204A48C arm
 * func_0204B100 0x0204B100 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AC18 0x0204AC18 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * d_020A1448 0x020A1448 data a4
 * d_021E1B40 0x021E1B40 data a4
 * d_021E1B20 0x021E1B20 data a4
 * d_021E1B30 0x021E1B30 data a4
 * d_021E1B38 0x021E1B38 data a4
 */
void func_021DD4A8(const u8 *p)
{
    u8 v;
    long i;
    u32 a,b;
    const u32 *table;
    void *arc;
    v=func_02008550((const struct Sub0200852CObj *)func_02012944(*(void **)(*(u8 **)(*(u8 **)(p+12)+20)+4)));
    arc=func_020490F4(31,114);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021E1B40,114);
    *(void **)(p+104)=func_0204B100(30,1,114);
    i=0;
    table=d_021E1B20+v;
    a=table[0]; b=table[2];
    for(;i<5;i++) {
        *(int *)(p+i*4+128)=func_0204A6C8(arc,a,0,0,114);
        *(int *)(p+i*4+108)=func_0204AC18(arc,b,0,(u16)(i*32),0,1,114);
    }
    *(int *)(p+148)=func_0204AF28(arc,d_021E1B30[v],d_021E1B38[v],114);
    func_02049238(arc);
    *(void **)(p+52)=func_020490F4(32,114);
}

void func_021DD570(u8 *p) {int i;u8 *q;func_02049238(((struct Obj10616 *)p)->f34);for(i=0;i<5;i++) {q=(u8 *)((u32)p+i*4);func_0204A8D4(((struct Obj14207 *)q)->f6C);func_0204ADA4(((struct Obj14207 *)q)->f80);}func_0204AFD8(((struct Obj10616 *)p)->f94);func_0204B1CC(((struct Obj10616 *)p)->f68);func_0204A5AC();}
