/*
 * file:     unit_021B7560_p02.c
 * unit:     yes
 * function: func_021B78EC, func_021B78F4, func_021B78FC, func_021B7908, func_021B7A60, func_021B7AAC, func_021B7AB4, func_021B7BC0
 * address:  0x021B78EC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7C14  0x021B7C14  thumb  ov102
 *   func_021B7C1C 0x021B7C1C thumb ov102
 */
#include "../../matched/include/Obj07973.h"

struct BgTemplate;
struct DispConfig;
struct Node;
struct Cfg;
struct Bank;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

struct State { void *bank; u32 palette, chars, other; void *actors[32]; };

extern u32 func_021B7C14(u8 *p, int i);
extern unsigned func_021B7C1C(unsigned *);
extern void func_021B7C0C(void *);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern u32 func_020056A0(void (*)(void),void *,u32);
extern void func_02030EAC(struct Node *n);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(unsigned,unsigned,unsigned);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_02082BCC(void *,int,u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32,u32),func_02043598(u32,u32);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B3DC(struct Obj *,unsigned int),func_0204B84C(void *,u32),func_0204B92C(struct Obj *,u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204AFD8(unsigned);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
u32 func_021B78EC(void *p, int i);
unsigned func_021B78F4(unsigned *p);
void func_021B78FC(unsigned a,void *p);
void func_021B7908(u32 *p,u16 heap);
void func_021B7A60(unsigned *p);
void func_021B7AAC(void);
void func_021B7AB4(struct State *p,const void *config,u16 heap);
void func_021B7BC0(void *p);
extern u32 d_021B8AC4[], d_021B8AEC[], d_021B8B0C[];
extern const u32 d_021B8B5C[][8];
extern unsigned d_021B8AEC[];
extern char d_020A1448[];

u32 func_021B78EC(void *p, int i) { return func_021B7C14(p, i); }

unsigned func_021B78F4(unsigned *p) { return func_021B7C1C(p); }

/*
 * func_021B7C0C 0x021B7C0C thumb ov102
 */
void func_021B78FC(unsigned a,void *p) { func_021B7C0C(p); }

void func_021B7908(u32 *p,u16 heap)
{
    int i;
    u32 layer;
    void *arc;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021B8AC4);
    for(i=0;i<8;i++) {
        layer=d_021B8AEC[i];
        func_0203FCA0((u8)layer,(const struct BgTemplate *)d_021B8B5C[i],(u8)d_021B8B0C[i]);
        func_020414AC(layer);
        func_02040588(layer,1);
    }
    arc=func_020490F4(94,heap);
    func_02049B68(arc,1,0,0,0,heap);
    func_02049B68(arc,1,4,0,0,heap);
    func_02049658(arc,0,3,0,0,0,heap);
    func_02049658(arc,0,6,0,0,0,heap);
    func_02049658(arc,48,4,0,0,0,heap);
    func_02049658(arc,42,2,0,0,0,heap);
    func_020498F4(arc,4,3,0,0,0,heap);
    func_020498F4(arc,4,6,0,0,0,heap);
    func_020498F4(arc,44,4,0,0,0,heap);
    func_020498F4(arc,43,2,0,0,0,heap);
    func_02040C14(5,0,1,0);
    p[0]=func_02049740(arc,49,5,0,0,heap);
    func_02049238(arc);
    p[1]=func_020056A0(func_021B7AAC,p,0);
}

/*
 * note: Packed word supplies low/high halfwords, not duplicate low halves. Includes tail-call follower 021B7AAC.
 * func_02030EAC 0x02030EAC arm
 * func_0203FB44 0x0203FB44 arm
 * func_02040DA8 0x02040DA8 arm
 * func_020403F4 0x020403F4 arm
 * func_020450C8 0x020450C8 arm
 * func_0203F9B4 0x0203F9B4 arm
 * func_020419E4 0x020419E4 arm
 * d_021B8AEC 0x021B8AEC data a4
 */
void func_021B7A60(unsigned *p) {
 int i;
 unsigned q;
 func_02030EAC((struct Node *)p[1]);
 q=p[0];
 func_0203FB44(5,(u16)q,(u16)(q>>16));
 func_02040DA8(5,1,0);
 for(i=0;i<8;i++) func_020403F4((u8)d_021B8AEC[i]);
 func_020450C8();
 func_0203F9B4();
}

void func_021B7AAC(void) { func_020419E4(); }

/*
 * declaration: 0204ABF0 forwards the live result of int-returning 0204AC18; 0204B294 forwards the pointer result of 0204CFDC. Its fifth word is copied unchanged as 0204CFDC's request pointer.
 * func_02082BCC 0x02082BCC arm
 * func_0204A48C 0x0204A48C arm
 * func_0204B100 0x0204B100 arm
 * func_0204B270 0x0204B270 arm
 * func_020434DC 0x020434DC arm
 * func_02043598 0x02043598 arm
 * func_020490F4 0x020490F4 arm
 * func_0204ABF0 0x0204ABF0 arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * func_0204B294 0x0204B294 arm
 * func_0204B3DC 0x0204B3DC arm
 * func_0204B84C 0x0204B84C arm
 * func_0204B92C 0x0204B92C arm
 * d_020A1448 0x020A1448 data a4
 */
void func_021B7AB4(struct State *p,const void *config,u16 heap)
{
    void *arc;
    int i;
    u16 point[4];
    func_02082BCC(p,0,0x90);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)config,heap);
    p->bank=func_0204B100(128,0,heap);
    func_0204B270(p->bank);
    func_020434DC(16,1);
    func_02043598(16,1);
    arc=func_020490F4(94,heap);
    p->palette=func_0204ABF0(arc,12,1,0,heap);
    p->chars=func_0204A6C8(arc,11,0,1,heap);
    p->other=func_0204AF28(arc,10,9,heap);
    func_02049238(arc);
    func_02082BCC(point,0,8);
    for(i=0;i<30;i++) {
        p->actors[i]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
        func_0204B3DC(p->actors[i],0);
        func_0204B84C(p->actors[i],3);
        func_0204B92C(p->actors[i],1);
    }
    point[0]=129; point[1]=104; point[2]=15;
    p->actors[31]=func_0204B294(p->bank,p->chars,p->palette,p->other,point,1,heap);
    func_0204B3DC(p->actors[31],1);
    func_0204B84C(p->actors[31],2);
    func_0204B92C(p->actors[31],0);
}

void func_021B7BC0(void *p) {
 int i;
 for(i=0;i<32;i++) {
  if(*(void **)((char *)p+16+i*4)) func_0204B3B4(*(void **)((char *)p+16+i*4));
 }
 func_0204ADA4(((struct Obj07973 *)p)->f4);
 func_0204A8D4(((struct Obj07973 *)p)->f8);
 func_0204AFD8(((struct Obj07973 *)p)->fC);
 func_0204B1CC(((struct Obj07973 *)p)->f0);
 func_0204A5AC();
 func_02082BCC(p,0,0x90);
}
