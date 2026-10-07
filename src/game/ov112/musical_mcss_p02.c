/*
 * file:     musical_mcss_p02.c
 * unit:     yes
 * function: func_021F44F8, func_021F4684, func_021F46A8, func_021F4748, func_021F4794, func_021F4804, func_021F485C
 * address:  0x021F44F8
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   d_021F8298 0x021F8298 data a4
 *   d_021F82B8 0x021F82B8 data a4
 *   d_021F82D8 0x021F82D8 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../../matched/include/Obj00721.h"
#include "../../matched/include/Obj01147.h"
#include "../../matched/include/Obj01924.h"
#include "../../matched/include/Obj01395.h"
#include "../../matched/include/Obj02167.h"
#include "../../matched/include/Obj06406.h"

struct Bank;
struct Obj;
struct BgTemplate;
struct Descriptor;
struct Cfg;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct CharBuf;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 x,y,z; u8 a,b; } Desc;

typedef signed int     s32;

typedef struct Item { void *data; u16 value; u16 pad; int zero; } Item;

typedef struct Menu { u32 heap; u8 count; u8 pad[3]; Item *items; int zero; u8 a,b,c,d; } Menu;

extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_02043598(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_02027614(void);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049B40(int,int,int,int,int,u16);
extern void func_0201DD68(u32);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0202F038(u8 *);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *p);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
void func_021F44F8(u8 *p);
void func_021F4684(const void *a,u32 b,u32 c);
void func_021F46A8(u8 *p);
void func_021F4748(u8 *p);
void func_021F4794(u8 *p,u32 index);
void func_021F4804(u8 *p,u32 index);
void func_021F485C(u8 *p);
extern const u32 d_021F8298[],d_021F82B8[],d_021F82D8[];

/*
 * ABI: 0204B294 returns an Obj pointer, which the original stores at +88.
 */
void func_021F44F8(u8 *p)
{
    Desc d;
    void *t;
    u32 v;
    u32 w;
    func_021F4684(d_021F8298,4,0);
    func_021F4684(d_021F82B8,6,0);
    func_021F4684(d_021F82D8,7,0);
    ((struct Obj00721 *)p)->f48=func_0204B100(8,0,((struct Obj00721 *)p)->f0);
    func_0204B270(((struct Obj00721 *)p)->f48);
    func_02043598(16,1);
    t=func_020490F4((unsigned int)46,((struct Obj00721 *)p)->f0);
    func_02049B68((void *)((u32)t),4,4,0,0,((struct Obj00721 *)p)->f0);
    func_02049658((void *)((u32)t),7,7,0,0,0,((struct Obj00721 *)p)->f0);
    func_020498F4((void *)((u32)t),12,7,0,0,0,((struct Obj00721 *)p)->f0);
    func_02049238(t);
    if (((struct Obj00721 *)p)->fC==0) {
        t=func_020490F4((unsigned int)func_020275E4(),((struct Obj00721 *)p)->f0);
        func_02049B68((void *)((u32)t),func_02027624(),4,288,32,((struct Obj00721 *)p)->f0);
        func_02049658((void *)((u32)t),func_02027628(),6,0,0,0,((struct Obj00721 *)p)->f0);
        func_020498F4((void *)((u32)t),func_0202762C(),6,0,0,0,((struct Obj00721 *)p)->f0);
        func_020413B0(6,0,21,32,3,9);
        func_020409B4(6);
        ((struct Obj00721 *)p)->f4C=func_0204AC18((void *)((u32)t),func_02027614(),1,0,0,3,((struct Obj00721 *)p)->f0);
        ((struct Obj00721 *)p)->f50=func_0204A6C8((void *)((u32)t),func_02027618(),0,1,((struct Obj00721 *)p)->f0);
        v=func_0202761C(0);
        w=func_02027620(0);
        ((struct Obj00721 *)p)->f54=func_0204AF28((void *)((u32)t),v,w,((struct Obj00721 *)p)->f0);
        func_02049238(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        ((struct Obj00721 *)p)->f58=func_0204B294((void *)*(u32 *)&((struct Obj00721 *)p)->f48,((struct Obj00721 *)p)->f50,((struct Obj00721 *)p)->f4C,((struct Obj00721 *)p)->f54,&d,1,((struct Obj00721 *)p)->f0);
    }
}

void func_021F4684(const void *a,u32 b,u32 c) { func_0203FCA0(b,a,c); func_02040588(b,1); func_020414AC(b); func_020409B4(b); }

void func_021F46A8(u8 *p)
{
    int zero;
    ((struct Obj01147 *)p)->f1C=func_020450F0(4,1,1,30,4,10,1);
    func_02045334((struct Descriptor *)((struct Obj01147 *)p)->f1C);
    func_02045374((struct Cfg *)(((struct Obj01147 *)p)->f1C));
    func_020409B4(4);
    zero=0;
    ((struct Obj01147 *)p)->f20=(u32)func_0201D7EC(23,0,0,0,((struct Obj01147 *)p)->f0);
    ((struct Obj01147 *)p)->f28=(u32)func_02045B38(0,2,78,((struct Obj01147 *)p)->f0);
    func_0201F5BC(4,1,11,0,((struct Obj01147 *)p)->f0);
    func_0201DD68(func_02049B40(23,5,4,320,32,((struct Obj01147 *)p)->f0));
    ((struct Obj01147 *)p)->f18=(u32)func_0203101C(((struct Obj01147 *)p)->f0,((struct Obj01147 *)p)->f0,3,256);
    ((struct Obj01147 *)p)->f24=zero;
    ((struct Obj01147 *)p)->f2C=zero;
    ((struct Obj01147 *)p)->f30=zero;
    ((struct Obj01147 *)p)->f34=zero;
    ((struct Obj01147 *)p)->f38=func_0201C440((void *)(((struct Obj01147 *)p)->f0));
}

void func_021F4748(u8 *p)
{
    func_0201C6EC((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    func_0201C4C0((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    if (*(u8 * *)&((struct Obj01924 *)p)->f34) {
        func_0202F038(*(u8 * *)&((struct Obj01924 *)p)->f34);
        *(u32 *)&((struct Obj01924 *)p)->f34=0;
    }
    if (((struct Obj01924 *)p)->f24) func_0201CE48(((struct Obj01924 *)p)->f24);
    if (((struct Obj01924 *)p)->f2C) func_02045808(((struct Obj01924 *)p)->f2C);
    func_02045C04(((struct Obj01924 *)p)->f28);
    func_020452E8(((struct Obj01924 *)p)->f1C);
    func_0201D83C(((struct Obj01924 *)p)->f20);
    func_02031140(((struct Obj01924 *)p)->f18);
}

void func_021F4794(u8 *p,u32 index)
{
    u32 t;
    if (((struct Obj01395 *)p)->f24) {
        func_0201CE48(((struct Obj01395 *)p)->f24);
        *(u32 *)&((struct Obj01395 *)p)->f24=0;
    }
    if (((struct Obj01395 *)p)->f2C) {
        func_02045808(((struct Obj01395 *)p)->f2C);
        *(u32 *)&((struct Obj01395 *)p)->f2C=0;
    }
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj01395 *)p)->f1C)),15);
    ((struct Obj01395 *)p)->f2C=func_02045EC0((struct MsgBank *)(((struct Obj01395 *)p)->f28),index);
    t=func_02012FFC();
    *(u32 *)&((struct Obj01395 *)p)->f24=func_0201CCE4(*(u32 *)&((struct Obj01395 *)p)->f1C,0,0,*(u32 *)&((struct Obj01395 *)p)->f2C,((struct Obj01395 *)p)->f20,t,((struct Obj01395 *)p)->f18,2,((struct Obj01395 *)p)->f0,0);
    func_0201F73C(((struct Obj01395 *)p)->f1C,1,1,11);
}

void func_021F4804(u8 *p,u32 index)
{
    u32 win;
    if (((struct Obj02167 *)p)->f2C) {
        func_02045808(((struct Obj02167 *)p)->f2C);
        *(u32 *)&((struct Obj02167 *)p)->f2C=0;
    }
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj02167 *)p)->f1C)),15);
    ((struct Obj02167 *)p)->f2C=func_02045EC0((struct MsgBank *)(((struct Obj02167 *)p)->f28),index);
    win=(u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj02167 *)p)->f1C);
    func_0201C6FC((struct PrintSys *)(((struct Obj02167 *)p)->f38),win,0,0,((struct Obj02167 *)p)->f2C,((struct Obj02167 *)p)->f20);
    ((struct Obj02167 *)p)->f30=1;
    func_0201F73C(((struct Obj02167 *)p)->f1C,1,1,11);
}

void func_021F485C(u8 *p)
{
    Item items[2];
    Menu menu;
    items[0].data=func_02045EC0((struct MsgBank *)(((struct Obj06406 *)p)->f28),4);
    items[1].data=func_02045EC0((struct MsgBank *)(((struct Obj06406 *)p)->f28),5);
    items[0].value=0x39e0;
    items[1].value=0x39e0;
    items[0].zero=0;
    items[1].zero=0;
    menu.heap=((struct Obj06406 *)p)->f0;
    menu.count=2;
    menu.items=items;
    menu.zero=0;
    menu.a=24;
    menu.b=6;
    menu.c=8;
    menu.d=3;
    ((struct Obj06406 *)p)->f3C=func_02027778((struct TaskMenuTmpl *)(&menu),(void *)(((struct Obj06406 *)p)->f40));
    func_02045808(items[0].data);
    func_02045808(items[1].data);
}
