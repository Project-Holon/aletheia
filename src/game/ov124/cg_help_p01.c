/*
 * file:     cg_help_p01.c
 * unit:     yes
 * function: func_021D4240, func_021D4280, func_021D42A0, func_021D43F0, func_021D43F8, func_021D4504, func_021D4534, func_021D4558
 * address:  0x021D4240
 * region:   ov124
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D46BC 0x021D46BC thumb ov124
 *   func_021D4940 0x021D4940 thumb ov124
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021D485C 0x021D485C thumb ov124
 *   func_021D4698 0x021D4698 thumb ov124
 *   func_021D48A4 0x021D48A4 thumb ov124
 *   func_021D49C8 0x021D49C8 thumb ov124
 *   func_020362DC 0x020362DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204A600 0x0204A600 arm
 *   func_02045334 0x02045334 arm
 *   func_02040618 0x02040618 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   d_021D4CC4 0x021D4CC4 data a4
 *   d_021D4BF4 0x021D4BF4 data a4
 *   d_021D4C44 0x021D4C44 data a4
 *   d_021D4C64 0x021D4C64 data a4
 *   d_021D4C84 0x021D4C84 data a4
 *   d_021D4C24 0x021D4C24 data a4
 *   d_020A1448 0x020A1448 data a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049F78 0x02049F78 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../../matched/include/Obj00068.h"
#include "../../matched/include/Obj00991.h"
#include "../../matched/include/Obj00122.h"

struct Node;
struct Descriptor;
struct Obj;
struct PrintSys;
struct Cfg;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct Bank;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a, b; u8 c, d, e, f; u32 g; u16 h, i, j, k, l, m; } Config;

typedef struct { u16 x, y, z; u8 a, b; } Request;

typedef signed int     s32;

extern void func_021D46BC(char *);
extern void *func_020056A0(void *,void *,int);
extern void func_021D4940(char *,int);
extern void func_0203D34C(unsigned,unsigned);
extern void func_02030EAC(struct Node *);
extern void func_021D485C(char *);
extern void func_021D4698(char *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_02028230(u8 *p);
extern void func_021D48A4(char *);
extern u32 func_020362DC(void);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02028178(u8 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern void func_021D49C8(char *,u32);
extern void func_020282A4(struct Obj *obj);
extern void func_0202843C(u8 *p);
extern void func_02028454(u8 *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A648(void);
extern void func_0204361C(void), func_020434CC(void), func_02043588(void);
extern void func_0202223C(u32, u32);
extern u32 func_02022224(void *);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16), func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_02043598(u32, u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(u32);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021D4240(char *p);
void func_021D4280(char *p);
int func_021D42A0(char *p);
void func_021D43F0(void);
void func_021D43F8(char *p);
void func_021D4504(char *p);
/* 020414AC's legacy asm prototype says void, but its body forwards entry r0. */ void func_021D4534(const struct BgTemplate *p, int layer, int type);
void func_021D4558(char *p);
extern const Config d_020A1448;
extern const u32 d_021D4CC4[], d_021D4BF4[], d_021D4C44[], d_021D4C64[], d_021D4C84[], d_021D4C24[];

void func_021D4240(char *p)
{
    ((struct Obj00068 *)p)->f10 = 0;
    func_021D43F8(p);
    func_021D4558(p);
    func_021D46BC(p);
    ((struct Obj00068 *)p)->f14 = func_020056A0(func_021D43F0,p,8);
    ((struct Obj00068 *)p)->f18 = 0;
    ((struct Obj00068 *)p)->fC = 1;
    func_021D4940(p,((struct Obj00068 *)p)->f18);
    func_0203D34C(0,((struct Obj00068 *)p)->f0);
}

void func_021D4280(char *p) {func_02030EAC(*(struct Node * *)&((struct Obj00991 *)p)->f14);func_021D485C(p);func_021D4698(p);func_021D4504(p);}

/*
 * extent: existing follower 021D43F0 remains in its separately verified file.
 */
int func_021D42A0(char *p)
{
    switch(((struct Obj00122 *)p)->f10) {
    case 0:
        func_0202208C((void *)4,1,1,0,6,1,((struct Obj00122 *)p)->f0);
        ((struct Obj00122 *)p)->f10=1;
        break;
    case 1:
        if(func_020221A4()==1) ((struct Obj00122 *)p)->f10=4;
        break;
    case 2:
        if(func_02028230(((struct Obj00122 *)p)->f40)==1) {
            func_0202208C((void *)4,0,0,0,6,1,((struct Obj00122 *)p)->f0);
            ((struct Obj00122 *)p)->f10=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if(!((struct Obj00122 *)p)->f1C) func_021D48A4(p);
        if(func_020362DC()&4) func_02041B6C(4);
        break;
    }
    func_0201C4E4(((struct Obj00122 *)p)->f30);
    func_0204A600();
    if(((struct Obj00122 *)p)->f3C) func_02028178(((struct Obj00122 *)p)->f3C);
    if(((struct Obj00122 *)p)->f38) func_02028178(((struct Obj00122 *)p)->f38);
    func_02028178(((struct Obj00122 *)p)->f40);
    if(((struct Obj00122 *)p)->f1C==1 && func_0201C6B4(((struct Obj00122 *)p)->f30)==1 &&
       (func_02028230(((struct Obj00122 *)p)->f3C)==1 || func_02028230(((struct Obj00122 *)p)->f38)==1 || ((struct Obj00122 *)p)->fC==1)) {
        func_02045334(((struct Obj00122 *)p)->f20);
        func_02045334(((struct Obj00122 *)p)->f24);
        ((struct Obj00122 *)p)->f1C=0;
        ((struct Obj00122 *)p)->fC=0;
        func_021D49C8(p,((struct Obj00122 *)p)->f18);
        if(((struct Obj00122 *)p)->f18==11) {
            func_020282A4(((struct Obj00122 *)p)->f3C);
            func_0202843C(((struct Obj00122 *)p)->f3C);
        } else {
            func_02028454(((struct Obj00122 *)p)->f3C);
            func_020282A4(((struct Obj00122 *)p)->f3C);
        }
        if(((struct Obj00122 *)p)->f18==0) {
            func_020282A4(((struct Obj00122 *)p)->f38);
            func_0202843C(((struct Obj00122 *)p)->f38);
        } else {
            func_02028454(((struct Obj00122 *)p)->f38);
            func_020282A4(((struct Obj00122 *)p)->f38);
        }
    }
    func_02040618(7,5,1);
    return 0;
}

/*
 * extent: 8-byte tail stub; labelled function 021D43F8 follows.
 */
void func_021D43F0(void)
{
    func_0204A648();
}

static inline void visible(int plane)
{
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00) | (plane << 8);
}

static inline void subvisible(int plane)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | (plane << 8);
}

/*
 * volatile: display read-modify-writes 021D440E/021D4416, 021D4418/021D441C; POWCNT1 021D443E/021D4444.
 */
void func_021D43F8(char *p)
{
    Config cfg;
    func_0204361C();
    func_020434CC();
    func_02043588();
    visible(0);
    subvisible(0);
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_02022224(0);
    func_02022224((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_020433E0((const struct DispVram *)d_021D4CC4);
    func_0203F8F4(((struct Obj00068 *)p)->f0);
    func_02045088(((struct Obj00068 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021D4BF4);
    func_021D4534((const struct BgTemplate *)d_021D4C44, 4, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C64, 5, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C84, 6, 0);
    func_021D4534((const struct BgTemplate *)d_021D4C24, 7, 0);
    func_0207D63C(0x04001050, 4, 8, 15, 4);
    cfg = d_020A1448;
    cfg.h = 0x40;
    func_0204A48C((const struct Cfg *)(&cfg), (u32)d_021D4CC4, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f4C = func_0204B100(0x30, 0, ((struct Obj00068 *)p)->f0);
    func_0204B270(((struct Obj00068 *)p)->f4C);
    func_02043598(0x10, 1);
}

void func_021D4504(char *p) {func_0204B1CC(*(struct Bank * *)&((struct Obj00991 *)p)->f4C);func_0204A5AC();func_020403F4(4);func_020403F4(5);func_020403F4(6);func_020403F4(7);func_020450C8();func_0203F9B4();}

/* 020414AC's legacy asm prototype says void, but its body forwards entry r0. */
void func_021D4534(const struct BgTemplate *p, int layer, int type) {func_0203FCA0(layer,p,type);func_02040588(layer,1);func_020414AC(layer);func_020409B4(layer);}

void func_021D4558(char *p)
{
    u32 handle;
    Request req;
    handle = (u32)func_020490F4((u32)((void *)0x1d), ((struct Obj00068 *)p)->f0);
    func_02049B68((void *)handle, 1, 4, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 4, 6, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_020498F4((void *)handle, 10, 6, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 4, 7, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_020498F4((void *)handle, 9, 7, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_02049238(handle);
    handle = (u32)func_020490F4((u32)((void *)0x1e), ((struct Obj00068 *)p)->f0);
    if (func_02008550(**(void ** *)&((struct Obj00068 *)p)->f4) == 0)
        ((struct Obj00068 *)p)->f50 = func_0204AC18((void *)handle, 19, 1, 0, 0, 15, ((struct Obj00068 *)p)->f0);
    else
        ((struct Obj00068 *)p)->f50 = func_0204AC18((void *)handle, 12, 1, 0, 0, 15, ((struct Obj00068 *)p)->f0);
    *(int *)&((struct Obj00068 *)p)->f54 = func_0204A6C8((void *)handle, 22, 0, 1, ((struct Obj00068 *)p)->f0);
    *(int *)&((struct Obj00068 *)p)->f58 = func_0204AF28((void *)handle, 21, 20, ((struct Obj00068 *)p)->f0);
    func_02049658((void *)handle, 0, 4, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f44 = func_02049F78((void *)handle, 13, (u32)(p + 0x48), ((struct Obj00068 *)p)->f0);
    func_02049238(handle);
    req.x = 32;
    req.y = 48;
    req.z = 0;
    req.a = 0;
    req.b = 0;
    ((struct Obj00068 *)p)->f5C = func_0204B294(((struct Obj00068 *)p)->f4C, *(u32 *)&((struct Obj00068 *)p)->f50, ((struct Obj00068 *)p)->f54, ((struct Obj00068 *)p)->f58, &req, 1, ((struct Obj00068 *)p)->f0);
    func_0204B3DC(((struct Obj00068 *)p)->f5C, 0);
    func_0204B92C(((struct Obj00068 *)p)->f5C, 1);
}
