/*
 * file:     gtsnego_disp_p15.c
 * unit:     yes
 * function: func_021D5C60, func_021D5D74, func_021D5E30, func_021D5E88, func_021D5F98, func_021D5FC4, func_021D60FC, func_021D6100, func_021D6328, func_021D63F4, func_021D6530, func_021D6568, func_021D6810, func_021D6814, func_021D68C4, func_021D692C, func_021D6988, func_021D698C, func_021D69A0, func_021D69F4
 * address:  0x021D5C60
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D7724 0x021D7724 thumb ov120
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021D88EC 0x021D88EC data a4
 *   func_0200F7E8 0x0200F7E8 thumb
 *   func_0203D34C 0x0203D34C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 *   func_0200FB24 0x0200FB24 thumb
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_02028178 0x02028178 thumb
 *   func_02027974 0x02027974 thumb
 *   func_021D7858 0x021D7858 thumb ov120
 *   func_02157170 0x02157170 thumb ov009
 *   func_021D5BEC 0x021D5BEC thumb ov120
 *   func_0202223C 0x0202223C thumb
 *   func_0200F7DC 0x0200F7DC thumb
 *   func_0200F7F4 0x0200F7F4 thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_02028148 0x02028148 thumb
 *   func_02027858 0x02027858 thumb
 *   func_021D7898 0x021D7898 thumb ov120
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02030734 0x02030734 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_020056A0 0x020056A0 thumb
 *   d_021D8BC8 0x021D8BC8 data a1
 *   ov_id 0x00000043 data
 *   d_021D8B98 0x021D8B98 data a4
 *   d_021D8974 0x021D8974 data a4
 *   d_021D8B60 0x021D8B60 data a4
 *   func_0204A600 0x0204A600 arm
 *   func_0202EA40 0x0202EA40 thumb
 *   func_021D75F4 0x021D75F4 thumb ov120
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021D6ED8 0x021D6ED8 thumb ov120
 *   func_021D6C64 0x021D6C64 thumb ov120
 *   func_020307B0 0x020307B0 arm
 *   func_021D6B5C 0x021D6B5C thumb ov120
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0202EA20 0x0202EA20 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   d_021D89B0      0x021D89B0  data
 *   func_0203FCA0   0x0203FCA0  arm
 *   func_020414AC   0x020414AC  arm
 *   func_020409B4   0x020409B4  arm
 *   func_02040C14   0x02040C14  arm
 *   func_02041300   0x02041300  arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02082D44 0x02082D44 arm
 *   d_021D8920 0x021D8920 data a4
 *   d_021D891C 0x021D891C data a4
 *   d_021D8918 0x021D8918 data a4
 *   d_021D895C 0x021D895C data a4
 *   d_021D896C 0x021D896C data a4
 *   d_021D894C 0x021D894C data a4
 *   d_021D8954 0x021D8954 data a4
 *   d_021D8944 0x021D8944 data a4
 *   d_021D8964 0x021D8964 data a4
 *   func_0204A648 0x0204A648 arm
 *   func_02040618 0x02040618 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0202E940 0x0202E940 thumb
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_02049238 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D6AF0 0x021D6AF0 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   d_021D8990 0x021D8990 data a4
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   func_021B639C  0x021B639C  thumb  ov067
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   d_021D8B70 0x021D8B70 data a1
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_02028218 0x02028218 thumb
 */
#include "../../matched/include/Obj01401.h"
#include "../../matched/include/Obj06435.h"
#include "../../matched/include/Obj22836.h"
#include "../../matched/include/Obj01056.h"
#include "../../matched/include/Obj22837.h"
#include "../../matched/include/Obj05348.h"
#include "../../matched/include/Obj00987.h"
#include "../../matched/include/Obj04488.h"
#include "../../matched/include/Obj00199.h"
#include "../../matched/include/Obj22838.h"
#include "../../matched/include/Obj13934.h"
#include "../../matched/include/Obj05350.h"
#include "../../matched/include/Obj08078.h"
#include "../../matched/include/Obj00218.h"
#include "../../matched/include/Obj06436.h"
#include "../../matched/include/Obj10391.h"
#include "../../matched/include/Obj22839.h"
#include "../../matched/include/Obj10392.h"
#include "../../matched/include/Obj06437.h"

struct Obj0203159C;
struct Big;
struct BigObj;
struct Sub0200852CObj;
struct S020315D4;
struct TaskMenu;
struct DispVram;
struct Bank;
struct Cfg;
struct Row;
struct Node;
struct Obj;
struct Obj0202EA20;
struct Chan02021FD8;
struct PalAnmSlot;
struct CodeIn;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig { u32 a,b,c,d; };

typedef signed int     s32;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct Pair { int a,b; } Pair;

typedef struct Word { int a; } Word;

typedef struct Data { u32 w[8]; } Data;

typedef struct Config { Data *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } Config;

typedef struct Record { u16 x, y, z; u8 a, b; } Record;

typedef signed short s16;

typedef struct Entry { u8 code, x, y, other; } Entry;

typedef struct Vec { s16 x, y; } Vec;

extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern char *func_021D7724(u32 heap, u32 n);
extern void func_0202223C(u32, u32);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201283C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_0203CD98(void);
extern void func_0203A574(u32, u32, u32, u32);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_02005D90(u32, u32);
extern void func_0203D34C(u32, u32);
extern void func_0200F7E8(u32 value);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D588C(u8 *);
extern u32 func_0200FB24(void);
extern int func_021B6498(u8 *p);
extern void func_02028178(u8 *p);
extern void func_02027974(void *);
extern void func_021D7858(u8 *p);
extern int func_02157170(int a0, int a1);
extern void func_021D5BEC(u8 *);
extern void func_0200F7DC(void);
extern void func_0200F7F4(void);
extern unsigned int func_020221A4(void);
extern void func_0203A5E4(unsigned int);
extern void func_02028148(u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D7898(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern int func_02034AC4(int);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32 swap);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020433E0(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *);
extern void *func_020056A0(void (*)(void *,u8 *),void *,int);
extern void func_0204A600(void);
extern s32 func_0202EA40(struct Row *p);
extern void func_021D75F4(char *p);
extern void func_0204B3B4(struct Obj *p);
extern void func_021D6ED8(u8 *);
extern void func_021D6C64(u8 *);
extern u32 func_020307B0(void *p);
extern void func_021D6B5C(u8 *);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(u32,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern void func_02034A5C(int handle);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02021518(u32);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *,int);
extern void func_020862F0(void *,unsigned long);
extern void func_0207E5D0(void *,int,int);
extern void func_0207E468(void *,int,int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02082D44(const void *,void *,unsigned int);
extern void func_0204A648(void);
extern void func_02040618(u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049740(void *,u32,u32,u32,u32,u16);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern void func_02049238(void *);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D6AF0(u8 *, u16, u16, int);
extern void func_02041B6C(u32);
extern void *func_021B62E0(Config *, int);
extern void func_021B639C(u8 *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_02028218(struct Obj *obj, u32 a);
int func_021D5C60(void *a, int unused, u8 *q);
int func_021D5D74(int a, int b, int c, u8 *p);
int func_021D5E30(void *p, int a, int b, u8 *q);
u8 *func_021D5E88(u32 heap,void *arg);
void func_021D5F98(u8 *p);
void func_021D5FC4(u8 *p);
u32 func_021D60FC(u8 *p);
void func_021D6100(u8 *a0);
void func_021D6328(u8 *p,int bank,int *offset,int *size,int count);
void func_021D63F4(u8 *p,int flag,int mode);
void func_021D6530(void *unused,u8 *p);
void func_021D6568(u8 *p);
void func_021D6810(u8 *a0, int a1);
void func_021D6814(u8 *p);
void func_021D68C4(u8 *p);
void func_021D692C(u8 *p, int n);
u32 func_021D6988(u8 *p);
void func_021D698C(u8 *p);
void func_021D69A0(u8 *p);
void func_021D69F4(u8 *p, void *q, u32 n);
extern const u32 d_021D88EC[];
extern const char d_021D8BC8[];
extern const u8 ov_id[];
extern const struct DispVram d_021D8B98;
extern const u32 d_021D8974[];
extern struct DispConfig d_021D8B60;
extern const struct BgTemplate d_021D89B0[8];
extern const Word d_021D8920,d_021D891C,d_021D8918;
extern const Pair d_021D895C,d_021D896C,d_021D894C,d_021D8954,d_021D8944,d_021D8964;
extern const Data d_021D8990;
extern const Entry d_021D8B70[];

/*
 * volatile: hardware halfword registers written at 0x021D5C78 and 0x021D5C7E.
 * prototype: 0203064C r2 explicitly loaded despite two-arg definition;
 * 0203159C r0 allocation result used despite void matched definition.
 */
int func_021D5C60(void *a, int unused, u8 *q)
{
    u8 *p;
    int zero = 0;
    func_0203064C(1, 0x1f, 0x38000);
    *(volatile u16 *)0x04000050 = zero;
    *(volatile u16 *)0x04001050 = zero;
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    p = func_0203159C(a, 0x1b8, 0x1f);
    func_02082BCC(p, 0, 0x1b8);
    ((struct Obj01401 *)p)->fC = 0x1f;
    *(u8 * *)&((struct Obj01401 *)p)->f48 = q;
    ((struct Obj01401 *)p)->f3C = func_021D5E88(((struct Obj01401 *)p)->fC, ((struct Obj06435 *)q)->f0);
    ((struct Obj01401 *)p)->f40 = func_021D7724(((struct Obj01401 *)p)->fC, 0x28);
    ((struct Obj01401 *)p)->f2C = ((struct Obj06435 *)q)->f0;
    ((struct Obj01401 *)p)->f30 = func_02012EBC(((struct Obj06435 *)q)->f0);
    ((struct Obj01401 *)p)->f44 = func_0201283C(((struct Obj06435 *)q)->f0);
    ((struct Obj22836 *)(*(u8 * *)&((struct Obj01401 *)p)->f48))->f1B0 = 1;
    ((struct Obj01401 *)p)->f15C = zero;
    ((struct Obj01401 *)p)->f160 = 2;
    ((struct Obj01401 *)p)->f164 = 6;
    ((struct Obj01401 *)p)->f14C = func_02008530((const struct Sub0200852CObj *)func_02012944(((struct Obj06435 *)q)->f0));
    if (func_0203CD98())
        func_0203A574(0x2200, (u32)d_021D88EC, 3, (u32)p);
    func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj01401 *)p)->fC);
    func_02005D90(0x486, 0xffff);
    func_0203D34C(1, ((struct Obj01401 *)p)->fC);
    func_0200F7E8(1);
    func_021D4244((int *)p, (int)func_021D588C, 0x96a);
    return 1;
}

int func_021D5D74(int a, int b, int c, u8 *p)
{
    void (*callback)(u8 *) = *(void (**)(u8 *))p;
    int result = 1;
    if (callback) {
        if (func_0200FB24() == 0)
            callback(p);
        result = 0;
    }
    if (((struct Obj01056 *)p)->f34) {
        void *q = (void *)func_021D6988(((struct Obj01056 *)p)->f3C);
        if (q == 0 || func_021B6498(q) == 0)
            func_02028178(((struct Obj01056 *)p)->f34);
    }
    if (((struct Obj01056 *)p)->f38)
        func_02027974(((struct Obj01056 *)p)->f38);
    func_021D5F98(((struct Obj01056 *)p)->f3C);
    func_021D7858(((struct Obj01056 *)p)->f40);
    if (func_0203CD98()) {
        if (func_0200FB24()) {
            switch (func_02157170(1, 1)) {
            case 0: break;
            case 1:
            case 4:
                func_021D5BEC(p);
                break;
            case 2:
                ((struct Obj22837 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 = 0;
                result = 1;
                func_0202223C(0, 0);
                func_0202223C(1, 0);
                break;
            case 3:
                func_0200F7DC();
                break;
            }
        }
    } else if (func_0200FB24()) {
        result = 1;
    }
    return result;
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D5E86.
 */
int func_021D5E30(void *p, int a, int b, u8 *q)
{
    func_0200F7F4();
    if (!func_020221A4()) return 0;
    if (func_0203CD98()) func_0203A5E4(0x2200);
    if (((struct Obj05348 *)q)->f34) func_02028148(((struct Obj05348 *)q)->f34);
    if (((struct Obj05348 *)q)->f38) func_02027858(((struct Obj05348 *)q)->f38);
    func_021D7898(((struct Obj05348 *)q)->f40);
    func_021D5FC4(((struct Obj05348 *)q)->f3C);
    func_020315D4(p);
    func_020306F0(31);
    return 1;
}

/*
 * interface: arg is a full-word pointer, as matched caller 021D5C60 supplies.
 * interface: 021D6100 gets p explicitly loaded despite its legacy void(void).
 * volatile: hardware 0x04001000 read/written at 0x021D5EC4/0x021D5ECA.
 */
u8 *func_021D5E88(u32 heap,void *arg)
{
    u8 *p;
    p=func_02030734(heap,0x164,1,d_021D8BC8,258);
    ((struct Obj00987 *)p)->fF4=heap;
    ((struct Obj00987 *)p)->f118=arg;
    func_02034AC4((int)ov_id);
    func_02043534(0);
    func_020435F4(0);
    func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj00987 *)p)->fF4);
    func_0204A48C((const struct Cfg *)d_021D8974,(u32)(&d_021D8B98),((struct Obj00987 *)p)->fF4);
    ((struct Obj00987 *)p)->f10=func_0204B100(64,0,((struct Obj00987 *)p)->fF4);
    func_020433E0(&d_021D8B98);
    func_0203FC28(&d_021D8B60);
    func_021D6100(p);
    func_021D6568(p);
    ((struct Obj00987 *)p)->f14=func_020056A0(func_021D6530,p,0);
    ((struct Obj00987 *)p)->f124=func_02030734(((struct Obj00987 *)p)->fF4,0x200,0,d_021D8BC8,280);
    ((struct Obj00987 *)p)->f128=func_02030734(((struct Obj00987 *)p)->fF4,0x200,0,d_021D8BC8,281);
    func_021D69A0(p);
    func_021D692C(p,0);
    func_020435F4(31);
    func_02043534(31);
    return p;
}

void func_021D5F98(u8 *p){func_0204A600();if(((struct Obj04488 *)p)->fF8)func_0202EA40(((struct Obj04488 *)p)->fF8);if(((struct Obj04488 *)p)->fFC)func_0202EA40(((struct Obj04488 *)p)->fFC);func_021D75F4((char *)p);}

void func_021D5FC4(u8 *p)
{
    int i;
    func_0204B3B4(((struct Obj00199 *)p)->f134);
    func_021D698C(p);
    func_021D6ED8(p);
    func_021D6C64(p);
    func_020307B0(((struct Obj00199 *)p)->f124);
    func_020307B0(((struct Obj00199 *)p)->f128);
    func_021D6B5C(p);
    func_0204ADA4((u32)(((struct Obj00199 *)p)->f18));
    func_0204ADA4((u32)(((struct Obj00199 *)p)->f1C));
    func_0204A8D4((u32)(((struct Obj00199 *)p)->f28));
    func_0204A8D4((u32)(((struct Obj00199 *)p)->f2C));
    func_0204AFD8((u32)(((struct Obj00199 *)p)->f74));
    func_0204AFD8((u32)(((struct Obj00199 *)p)->f78));
    func_0204ADA4((u32)(((struct Obj00199 *)p)->f24));
    func_0204A8D4((u32)(((struct Obj00199 *)p)->f70));
    func_0204AFD8((u32)(((struct Obj00199 *)p)->fBC));
    func_0204ADA4((u32)(((struct Obj00199 *)p)->f20));
    for(i=0;i<16;i++) {
        func_0204A8D4((u32)(*(void **)(p+i*4+0x30)));
        func_0204AFD8((u32)(*(void **)(p+i*4+0x7c)));
    }
    func_02030EAC(((struct Obj00199 *)p)->f14);
    func_0204B1CC(((struct Obj00199 *)p)->f10);
    func_0204A5AC();
    func_0202EA20(((struct Obj00199 *)p)->fF8);
    func_0202EA20(((struct Obj00199 *)p)->fFC);
    func_0203FB44(7,(u16)(((struct Obj00199 *)p)->f8),(u16)(((struct Obj00199 *)p)->f8>>16));
    func_0203FB44(4,(u16)(((struct Obj00199 *)p)->f0),(u16)(((struct Obj00199 *)p)->f0>>16));
    func_0203FB44(0,(u16)(((struct Obj00199 *)p)->f4),(u16)(((struct Obj00199 *)p)->f4>>16));
    func_02040DA8(1,1,0);
    func_02040DA8(5,1,0);
    func_02040DA8(6,1,0);
    func_02040588(5,0);
    for(i=0;i<=7;i++) func_020403F4((u8)i);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}


u32 func_021D60FC(u8 *p){return ((struct Obj22838 *)p)->f10;}


/*
 * BG-layer init: eight copies of the const template table at 0x021D89B0
 * (index order 0,5,1,2,3,4,6,7) passed to func_0203FCA0, each followed by
 * its layer enable / fill sequence.  The local array is written high-to-low
 * (b[7] first) because the original places the first-used slot at the top of
 * the frame.
 */
void func_021D6100(u8 *a0)
{
    struct BgTemplate b[8];

    b[7] = d_021D89B0[0];
    func_0203FCA0(0, &b[7], 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 1);

    b[6] = d_021D89B0[5];
    func_0203FCA0(1, &b[6], 0);
    func_02040588(1, 1);
    func_02040C14(1, 0, 1, 0);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(1);

    b[5] = d_021D89B0[1];
    func_0203FCA0(2, &b[5], 0);
    func_02040588(2, 1);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);

    b[4] = d_021D89B0[2];
    func_0203FCA0(3, &b[4], 0);
    func_02040588(3, 1);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(3);

    b[3] = d_021D89B0[3];
    func_0203FCA0(4, &b[3], 0);
    func_02040588(4, 1);
    func_020409B4(4);

    b[2] = d_021D89B0[4];
    func_0203FCA0(5, &b[2], 0);
    func_02040588(5, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(5);

    b[1] = d_021D89B0[6];
    func_0203FCA0(6, &b[1], 0);
    func_02040588(6, 1);
    func_02040C14(6, 0, 1, 0);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(6);

    b[0] = d_021D89B0[7];
    func_0203FCA0(7, &b[0], 0);
    func_02040588(7, 1);
    func_020409B4(7);
}

void func_021D6328(u8 *p,int bank,int *offset,int *size,int count)
{
    int i;
    void *obj;
    u8 *buffer;
    obj=func_02021518(((struct Obj13934 *)p)->fF4);
    func_0202155C(obj,bank,0x200,((struct Obj13934 *)p)->fF4);
    func_020216D4(obj,bank,0,0x200);
    func_02021FD8(obj,bank,0,0x100,6,0);
    buffer=(u8 *)func_02021730(obj,bank);
    for(i=0;i<count;i++) {
        switch(bank) {
        case 3:
            func_020862F0(buffer+offset[i]*32,size[i]*32);
            func_0207E5D0(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        case 1:
            func_020862F0(buffer+offset[i]*32,size[i]*32);
            func_0207E468(buffer+offset[i]*32,offset[i]*32,size[i]*32);
            break;
        }
    }
    func_020215A0(obj,bank);
    func_02021540(obj);
}

/*
 * lever: one-word aggregate locals preserve the early address setup and merge.
 */
void func_021D63F4(u8 *p,int flag,int mode)
{
    if(flag) {
        func_02082D44((void *)0x05000600,((struct Obj05350 *)p)->f124,0x200);
        func_02082D44((void *)0x05000400,((struct Obj05350 *)p)->f128,0x200);
        switch(mode) {
        case 2: {
            Word a={0};
            Word b=d_021D8920;
            func_021D6328(p,3,&a.a,&b.a,1);
            break;
        }
        case 0: {
            Word a=d_021D891C;
            Word b=d_021D8918;
            func_021D6328(p,3,&a.a,&b.a,1);
            break;
        }
        case 1: {
            Pair a=d_021D895C;
            Pair b=d_021D896C;
            func_021D6328(p,3,&a.a,&b.a,2);
            break;
        }
        }
        switch(mode) {
        case 0: case 2: {
            Pair a=d_021D894C;
            Pair b=d_021D8954;
            func_021D6328(p,1,&a.a,&b.a,2);
            break;
        }
        case 1: {
            Pair a=d_021D8944;
            Pair b=d_021D8964;
            func_021D6328(p,1,&a.a,&b.a,2);
            break;
        }
        }
    } else {
        func_020862F0(((struct Obj05350 *)p)->f124,0x200);
        func_0207E5D0(((struct Obj05350 *)p)->f124,0,0x200);
        func_020862F0(((struct Obj05350 *)p)->f128,0x200);
        func_0207E468(((struct Obj05350 *)p)->f128,0,0x200);
    }
}

/*
 * extent: two-byte zero alignment padding follows.
 */
void func_021D6530(void *unused,u8 *p){func_0204A648();if(((struct Obj08078 *)p)->f100){func_02040618(4,3,((struct Obj08078 *)p)->f104+72);func_02040618(6,3,((struct Obj08078 *)p)->f104+72);((struct Obj08078 *)p)->f100=0;}}

void func_021D6568(u8 *p)
{
    int i;
    void *t;
    t=func_020490F4((u32)((void *)144),((struct Obj00218 *)p)->fF4);
    func_02049B68(t,3,4,0,192,((struct Obj00218 *)p)->fF4);
    func_02049B68(t,1,4,0,64,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f8=func_02049740(t,6,7,0,0,((struct Obj00218 *)p)->fF4);
    func_02049990(t,17,7,0,(u16)(((struct Obj00218 *)p)->f8),0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f0=func_02049740(t,8,4,0,0,((struct Obj00218 *)p)->fF4);
    func_02049990(t,18,4,0,(u16)(((struct Obj00218 *)p)->f0),0,0,((struct Obj00218 *)p)->fF4);
    func_02049B68(t,1,0,0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f4=func_02049740(t,6,0,0,0,((struct Obj00218 *)p)->fF4);
    func_02049990(t,12,0,0,(u16)(((struct Obj00218 *)p)->f4),0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f70=(void *)func_0204A6C8(t,5,0,1,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f24=(void *)func_0204AC18(t,0,1,320,0,1,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->fBC=(void *)func_0204AF28(t,10,22,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f28=(void *)func_0204A6C8(t,7,0,1,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f18=(void *)func_0204AC18(t,2,1,256,0,8,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f74=(void *)func_0204AF28(t,11,23,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f2C=(void *)func_0204A6C8(t,7,0,0,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f1C=(void *)func_0204AC18(t,2,0,0,0,8,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->f78=(void *)func_0204AF28(t,11,23,((struct Obj00218 *)p)->fF4);
    ((struct Obj00218 *)p)->fF8=func_0202E940(0,16,0,((struct Obj00218 *)p)->fF4);
    func_0202E9AC(((struct Obj00218 *)p)->fF8,t,1,0,16);
    ((struct Obj00218 *)p)->fFC=func_0202E940(0,16,7,((struct Obj00218 *)p)->fF4);
    func_0202E9AC(((struct Obj00218 *)p)->fFC,t,1,0,16);
    func_02049238(t);
    t=func_020490F4((u32)((void *)32),((struct Obj00218 *)p)->fF4);
    for(i=0;i<16;i++) {
        *(void **)(p+i*4+0x30)=(void *)func_0204A6C8(t,i+1,0,1,((struct Obj00218 *)p)->fF4);
        *(void **)(p+i*4+0x7c)=(void *)func_0204AF28(t,i*2+17,i*2+18,((struct Obj00218 *)p)->fF4);
    }
    ((struct Obj00218 *)p)->f20=(void *)func_0204AC18(t,0,1,0,0,8,((struct Obj00218 *)p)->fF4);
    func_02049238(t);
    func_0207D63C((void *)0x04001050,5,24,15,9);
}


void func_021D6810(u8 *a0, int a1){}

void func_021D6814(u8 *p)
{
    void *t;
    func_021D6810(p, 0);
    t = func_020490F4(144, ((struct Obj06436 *)p)->fF4);
    func_02049990(t, 19, 4, 0, (u16)(((struct Obj06436 *)p)->f0), 0, 0, ((struct Obj06436 *)p)->fF4);
    func_02049990(t, 20, 4, 0, (u16)(((struct Obj06436 *)p)->f0), 192, 0, ((struct Obj06436 *)p)->fF4);
    func_02049238(t);
    func_021D6AF0(p, 96, 56, 0);
    func_021D6AF0(p, 240, 56, 1);
    func_021D6AF0(p, 120, 96, 0);
    func_021D6AF0(p, 240, 96, 1);
    func_021D6AF0(p, 120, 136, 0);
    func_021D6AF0(p, 240, 136, 1);
}

/*
 * trailing: 2-byte zero alignment padding at 0x021D692A.
 */
void func_021D68C4(u8 *p)
{
    void *t = func_020490F4(144, ((struct Obj10391 *)p)->fF4);
    func_021D6B5C(p);
    func_02041300(6, 0, 0, 0, 32, 32, 17);
    func_02041B6C(6);
    func_02049990(t, 18, 4, 0, (u16)(((struct Obj10391 *)p)->f0), 0, 0, ((struct Obj10391 *)p)->fF4);
    func_02041B6C(4);
    func_02049238(t);
}

void func_021D692C(u8 *p, int n)
{
    Data data = d_021D8990;
    Config c;
    func_02082BCC(&c, 0, 32);
    c.f0 = &data;
    c.f4 = 1;
    c.f8 = *(u32 *)&((struct Obj00199 *)p)->f10;
    c.fC = 7;
    c.f10 = 15;
    c.f18 = 2;
    c.f1c = 0;
    c.f14 = n;
    ((struct Obj00199 *)p)->fC = func_021B62E0(&c, ((struct Obj00199 *)p)->fF4);
}


u32 func_021D6988(u8 *p){return ((struct Obj22839 *)p)->fC;}


void func_021D698C(u8 *p)
{
    if (((struct Obj10392 *)p)->fC) {
        func_021B639C(((struct Obj10392 *)p)->fC);
        *(u32 *)&((struct Obj10392 *)p)->fC = 0;
    }
}

void func_021D69A0(u8 *p)
{
    Record r;
    r.x = 0; r.y = 0; r.z = 0; r.a = 0; r.b = 2;
    ((struct Obj00987 *)p)->f134 = func_0204B294((void *)*(u32 *)&((struct Obj00987 *)p)->f10, ((struct Obj00987 *)p)->f28, ((struct Obj00987 *)p)->f18, ((struct Obj00987 *)p)->f74, &r, 1, ((struct Obj00987 *)p)->fF4);
    func_0204B92C(((struct Obj00987 *)p)->f134, 1);
    func_0204B3DC(((struct Obj00987 *)p)->f134, 0);
    func_0204B688(((struct Obj00987 *)p)->f134, 1);
}

void func_021D69F4(u8 *p, void *q, u32 n)
{
    Vec v;
    switch (n) {
    case 9:
        func_0204B3DC(((struct Obj06437 *)p)->f134, 0);
        return;
    case 5:
        func_0204B3DC(((struct Obj06437 *)p)->f134, 0);
        if (q) func_02028218(q, 1);
        return;
    case 2: case 3: case 4: case 6: case 7: case 8:
        if (q) func_02028218(q, 0);
        break;
    case 0: case 1: default: break;
    }
    v.x = d_021D8B70[n].x;
    v.y = d_021D8B70[n].y;
    func_0204B404(((struct Obj06437 *)p)->f134, (const struct Vec2 *)(&v), 1);
    func_0204B878(((struct Obj06437 *)p)->f134, d_021D8B70[n].code);
    func_0204B3DC(((struct Obj06437 *)p)->f134, 1);
}
