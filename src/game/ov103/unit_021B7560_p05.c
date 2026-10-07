/*
 * file:     unit_021B7560_p05.c
 * unit:     yes
 * function: func_021B7B3C, func_021B7C08, func_021B7C4C, func_021B7C54, func_021B7C5C
 * address:  0x021B7B3C
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   d_020A1448 0x020A1448 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../../matched/include/Obj07981.h"

struct Cfg;
struct Bank;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32_021B7B3C;

struct State { void *bank; u32 palette, chars, other; void *actors[33]; };

typedef short s16;

typedef signed char s8;

typedef int s32_021B7C4C;

extern void func_02082BCC(void *,u8,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern signed int func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021B7B3C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021B7B3C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *,unsigned int),func_0204B84C(void *,u32),func_0204B92C(struct Obj *,u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(int);
extern void func_0204A8D4(int);
extern void func_0204AFD8(int);
extern int func_0204B1CC(int);
extern void func_0204A5AC(int);
extern void func_0204A600(void);
extern void func_0204A648(void);
void func_021B7B3C(struct State *p,const void *config,u16 heap);
void func_021B7C08(u8 *p);
void func_021B7C4C(void *a0);
void func_021B7C54(void *a0);
u32 func_021B7C5C(u8 *p,u32 i);
extern const char d_020A1448[];

void func_021B7B3C(struct State *p,const void *config,u16 heap)
{
    void *arc;
    int i;
    u16 point[4];
    func_02082BCC(p,0,0x94);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)config,heap);
    p->bank=func_0204B100(128,0,heap);
    func_0204B270(p->bank);
    func_020434DC(16,1);
    func_02043598(16,1);
    arc=func_020490F4(94,heap);
    p->palette=func_0204ABF0((void *)arc,12,1,0,heap);
    p->chars=func_0204A6C8((void *)((u32)arc),11,0,1,heap);
    p->other=func_0204AF28((void *)((u32)arc),10,9,heap);
    func_02049238(arc);
    func_02082BCC(point,0,8);
    for(i=0;i<32;i++) {
        p->actors[i]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
        func_0204B3DC(p->actors[i],0);
        func_0204B84C(p->actors[i],3);
        func_0204B92C(p->actors[i],1);
        func_0204B878(p->actors[i],0);
    }
}

void func_021B7C08(u8 *p) { int i; for(i=0;i<33;i++) { if(*(int *)(p+16+i*4)) func_0204B3B4((struct Obj *)(*(int *)(p+16+i*4))); } func_0204ADA4(((struct Obj07981 *)p)->f4); func_0204A8D4(((struct Obj07981 *)p)->f8); func_0204AFD8(((struct Obj07981 *)p)->fC); func_0204A5AC(func_0204B1CC(((struct Obj07981 *)p)->f0)); func_02082BCC(p,0,0x94); }

void func_021B7C4C(void *a0) { func_0204A600(); }

void func_021B7C54(void *a0) { func_0204A648(); }

u32 func_021B7C5C(u8 *p,u32 i) { return *(u32 *)(p+i*4+16); }
