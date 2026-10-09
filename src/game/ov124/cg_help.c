/*
 * file:     cg_help.c
 * unit:     yes
 * function: func_021D4240, func_021D4280, func_021D42A0, func_021D43F0, func_021D43F8, func_021D4504, func_021D4534, func_021D4558, func_021D4698, func_021D46BC, func_021D485C, func_021D48A4, func_021D4940, func_021D49C8, func_021D4B14, func_021D4B84
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
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
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
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   d_021D4BE4 0x021D4BE4 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_0202822C 0x0202822C thumb
 *   func_02012204 0x02012204 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02030734 0x02030734 arm
 *   func_02041090 0x02041090 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B908 0x0204B908 arm
 *   d_021D4CF4 0x021D4CF4 data a4
 *   d_021D4CA4 0x021D4CA4 data a4
 *   d_021D4D4C 0x021D4D4C data a1
 *   d_021D4C04 0x021D4C04 data a4
 *   d_021D4BE0 0x021D4BE0 data a2
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_0203630C 0x0203630C arm
 *   func_0200854C 0x0200854C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../../matched/include/Obj00068.h"
#include "../../matched/include/Obj00991.h"
#include "../../matched/include/Obj00122.h"
#include "../../matched/include/Obj22992.h"
#include "../../matched/include/Obj22993.h"

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
struct CharBuf;
struct GfFont;
struct MsgBank;
struct R;
struct U16Vec;
struct Rec;
struct TaskMenuState;
struct Ctx;
struct Vec2;
struct Obj0203159C;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 a, b; u8 c, d, e, f; u32 g; u16 h, i, j, k, l, m; } Config;

typedef struct { u16 x, y, z; u8 a, b; } Request_021D4240;

typedef signed int     s32;

typedef struct { u32 text; u16 color; u16 pad; u32 flag; } Request_021D4698;

typedef struct { u8 bytes[16]; } Table16;

typedef short s16;

typedef struct { s16 x, y; } Vec;

extern void *func_020056A0(void *,void *,int);
extern void func_0203D34C(unsigned,unsigned);
extern void func_02030EAC(struct Node *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern u32 func_02028230(u8 *p);
extern u32 func_020362DC(void);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02028178(u8 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
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
extern u32 func_020307B0(void *p);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0201DD78(u32, u32, u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern u8 func_0201F548(int);
extern void func_0201DD68(void);
extern u32 func_0201C440(void *);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *, int, int, int);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02027FEC(u32, u32, u32, u32, u8, u16);
extern void func_02045808(struct U16Vec *vec);
extern void func_02028148(u8 *p);
extern unsigned int func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern int func_02035C08(const void *p);
extern void func_0202822C(char *p, int v);
extern void func_020061E4(u32 a);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_02061CA4(void *, u32, u32, int);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B908(int a0, int a1);
extern void func_0203064C(unsigned int,unsigned int,unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *func_0200846C(int a0);
extern unsigned int func_0203630C(void);
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
void func_021D4240(char *p);
void func_021D4280(char *p);
int func_021D42A0(char *p);
void func_021D43F0(void);
void func_021D43F8(char *p);
void func_021D4504(char *p);
void func_021D4534(const struct BgTemplate *p, int layer, int type);
void func_021D4558(char *p);
void func_021D4698(char *p);
void func_021D46BC(char *p);
void func_021D485C(char *p);
void func_021D48A4(char *p);
void func_021D4940(char *p,int n);
void func_021D49C8(char *p, u32 n);
int func_021D4B14(void *a,int b,void *c);
int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p);
extern const Config d_020A1448;
extern const u32 d_021D4CC4[], d_021D4BF4[], d_021D4C44[], d_021D4C64[], d_021D4C84[], d_021D4C24[];
extern const Table16 d_021D4BE4;
extern const u32 d_021D4CF4[], d_021D4CA4[], d_021D4C04[];
extern const char d_021D4D4C[];
extern const Vec d_021D4BE0;



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
    Request_021D4240 req;
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



void func_021D4698(char *p) {func_020307B0(((struct Obj00991 *)p)->f44);func_0204B3B4(*(struct Obj * *)&((struct Obj00991 *)p)->f5C);func_0204ADA4(((struct Obj00991 *)p)->f50);func_0204A8D4(((struct Obj00991 *)p)->f54);func_0204AFD8(((struct Obj00991 *)p)->f58);}



void func_021D46BC(char *p)
{
    Request_021D4698 req;
    ((struct Obj00068 *)p)->f28 = func_0201D7EC(23, 0, 0, 0, ((struct Obj00068 *)p)->f0);
    func_0201DD78(15, 2, 0);
    ((struct Obj00068 *)p)->f2C = func_02045B38(0, 2, 21, ((struct Obj00068 *)p)->f0);
    func_02049B40(23, 5, 4, 480, 32, ((struct Obj00068 *)p)->f0);
    func_0201F5BC(5, 1, 13, 0, ((struct Obj00068 *)p)->f0);
    func_02049B40(5, func_0201F548(0), 4, 416, 64, ((struct Obj00068 *)p)->f0);
    func_0201DD68();
    *(u32 *)&((struct Obj00068 *)p)->f30 = func_0201C440((void *)(u32)((struct Obj00068 *)p)->f0);
    ((struct Obj00068 *)p)->f34 = func_02027F60(4, 11, *(u32 *)&((struct Obj00068 *)p)->f28, *(u32 *)&((struct Obj00068 *)p)->f30, ((struct Obj00068 *)p)->f0);
    *(u32 *)&((struct Obj00068 *)p)->f24 = func_020450F0(5, 2, 4, 28, 4, 15, 1);
    *(u32 *)&((struct Obj00068 *)p)->f20 = func_020450F0(5, 2, 9, 28, 12, 15, 1);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f24), 1);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f24);
    func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f24));
    func_0201F73C(((struct Obj00068 *)p)->f24, 1, 1, 14);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f20), 0);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj00068 *)p)->f20);
    func_02045374((struct Cfg *)(*(u32 *)&((struct Obj00068 *)p)->f20));
    func_020409B4(5);
    func_020409B4(4);
    ((struct Obj00068 *)p)->f1C = 0;
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 24);
    req.color = 0x39e3;
    req.flag = 0;
    ((struct Obj00068 *)p)->f3C = func_02027FEC(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 11, 21, 11, ((struct Obj00068 *)p)->f0);
    func_02045808((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 26);
    *(u32 *)&((struct Obj00068 *)p)->f38 = func_02027FEC(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 0, 21, 11, ((struct Obj00068 *)p)->f0);
    func_02045808((void *)req.text);
    req.text = (u32)func_02045EC0(((struct Obj00068 *)p)->f2C, 25);
    req.flag = 1;
    ((struct Obj00068 *)p)->f40 = func_02027FEC(*(u32 *)&((struct Obj00068 *)p)->f34, (u32)&req, 22, 21, 10, ((struct Obj00068 *)p)->f0);
    func_02045808((void *)req.text);
    func_0202843C(*(u8 * *)&((struct Obj00068 *)p)->f38);
    *(u16 *)0x050005e2 = 0;
}



void func_021D485C(char *p)
{
    if (((struct Obj00991 *)p)->f3C) func_02028148(((struct Obj00991 *)p)->f3C);
    if (((struct Obj00991 *)p)->f38) func_02028148(((struct Obj00991 *)p)->f38);
    func_02028148(((struct Obj00991 *)p)->f40);
    func_02027FD8(((struct Obj00991 *)p)->f34);
    func_0201C4C0(((struct Obj00991 *)p)->f30);
    func_020452E8(((struct Obj00991 *)p)->f20);
    func_020452E8(((struct Obj00991 *)p)->f24);
    func_02045C04(((struct Obj00991 *)p)->f2C);
    func_0201D83C(((struct Obj00991 *)p)->f28);
    func_0201DD68();
}



void func_021D48A4(char *p)
{
    Table16 table;
    table = d_021D4BE4;
    switch (func_02035C08(&table)) {
    case 0:
        if (((struct Obj00122 *)p)->f18 != 0) {
            (((struct Obj00122 *)p)->f18)--;
            func_021D4940(p,((struct Obj00122 *)p)->f18);
            func_0202822C(((struct Obj00122 *)p)->f38,1);
            func_020061E4(0x54c);
        }
        break;
    case 1:
        if (((struct Obj00122 *)p)->f18 < 11) {
            (((struct Obj00122 *)p)->f18)++;
            func_021D4940(p,((struct Obj00122 *)p)->f18);
            func_0202822C(((struct Obj00122 *)p)->f3C,1);
            func_020061E4(0x54c);
        }
        break;
    case 2:
        func_0202822C(((struct Obj00122 *)p)->f40,1);
        *(int *)&((struct Obj00122 *)p)->f10 = 2;
        func_020061E4(0x551);
        break;
    }
    if (func_02012204(((struct Obj22992 *)(*(char * *)&((struct Obj00122 *)p)->f4))->f4) == 1) {
        func_0202822C(((struct Obj00122 *)p)->f40,1);
        *(int *)&((struct Obj00122 *)p)->f10 = 2;
    }
}



void func_021D4940(char *p,int n)
{
    void *q;
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f24),1);
    func_02043B5C(func_02045770(((struct Obj00068 *)p)->f20),0);
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    func_0201C724(((struct Obj00068 *)p)->f30,(u32)func_02045770(((struct Obj00068 *)p)->f24),40,8,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    func_02045808(q);
    n += 12;
    q = func_02045EC0(((struct Obj00068 *)p)->f2C,n);
    func_0201C724(((struct Obj00068 *)p)->f30,(u32)func_02045770(((struct Obj00068 *)p)->f20),0,0,(u32)q,(u32)(((struct Obj00068 *)p)->f28),0x3c40);
    func_02045808(q);
    ((struct Obj00068 *)p)->f1C = 1;
}



/*
 * lever: the two-halfword delta is a struct assignment; field stores differ by 13 bytes.
 */
void func_021D49C8(char *p, u32 n)
{
    u16 *q;
    u8 i, j;
    Vec delta;
    func_0204B878(((struct Obj00122 *)p)->f5C, d_021D4CF4[n]);
    func_0204B3DC(((struct Obj00122 *)p)->f5C, 1);
    if (n <= 7) {
        func_02061CA4((void *)31, 320, (u32)(*(char * *)&((struct Obj22993 *)(*(char * *)&((struct Obj00122 *)p)->f48))->fC + d_021D4CA4[n] * 32), 32);
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2ac);
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i * 4 + j] = j + d_021D4C04[n] + i * 32 + 0xa000;
            }
        }
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    } else {
        q = func_02030734(((struct Obj00122 *)p)->f0, 32, 1, d_021D4D4C, 0x2bb);
        func_02041090(4, (u32)q, 2, 4, 4, 4);
        func_020307B0(q);
    }
    func_020409B4(4);
    delta = d_021D4BE0;
    func_0204B404(((struct Obj00122 *)p)->f5C, (const struct Vec2 *)(&delta), 1);
    if (n == 10) {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 0);
        func_0204B908((int)(((struct Obj00122 *)p)->f5C), 1);
    } else if (n == 11) {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 0);
        func_0204B908((int)(((struct Obj00122 *)p)->f5C), 0);
    } else {
        func_0204B92C(((struct Obj00122 *)p)->f5C, 1);
    }
}



int func_021D4B14(void *a,int b,void *c)
{
    char *p;
    void **q;
    func_0203064C(1,0x8a,0x60000);
    p = func_0203159C(a,0x60,0x8a);
    q = c;
    if (!q) {
        q = func_02030734(0x8a,8,1,d_021D4D4C,0x2f3);
        *q = func_0200846C(0x8a);
        if (func_0203630C() & 0x100) func_0200854C(*q,1);
        else func_0200854C(*q,0);
    }
    ((struct Obj00068 *)p)->f4 = q;
    ((struct Obj00068 *)p)->f0 = 0x8a;
    func_021D4240(p);
    return 1;
}



int func_021D4B84(struct S020315D4 *task,int b,int keep,char *p) {func_021D4280(p);if(keep==0){func_020307B0(**(void ** *)&((struct Obj00991 *)p)->f4);func_020307B0(((struct Obj00991 *)p)->f4);}func_020315D4(task);func_020306F0(0x8a);return 1;}
