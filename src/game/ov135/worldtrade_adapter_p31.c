/*
 * file:     worldtrade_adapter_p31.c
 * unit:     yes
 * function: func_02200C0C, func_02200C80, func_02200C94, func_02200CCC, func_02200DB8, func_02200DD0, func_02200E48, func_02200E94, func_02200EB0, func_02200EC8, func_02200ED8, func_02200FF4, func_022010BC, func_02201258, func_02201320, func_022013E4, func_02201414, func_022014B8
 * address:  0x02200C0C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_02040588 0x02040588 arm
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_0202208C 0x0202208C thumb
 *   func_021F9254 0x021F9254 thumb ov135
 *   g_02203E94  0x02203E94  data  ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_021FFD74 0x021FFD74 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020434DC  0x020434DC  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02203A04  0x02203A04  data  ov135
 *   g_02203A14  0x02203A14  data  ov135
 *   g_02203A54  0x02203A54  data  ov135
 *   g_02203A34  0x02203A34  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_02049B40 0x02049B40 arm
 *   func_02043598 0x02043598 arm
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02202940  0x02202940  thumb  ov135
 *   func_021F90A0  0x021F90A0  thumb
 *   func_021F4E98  0x021F4E98  thumb
 *   func_021F4FA4  0x021F4FA4  thumb
 *   str_02203F58  0x02203F58  data  a1
 *   func_02019CE0 0x02019CE0 thumb
 *   func_02025C1C 0x02025C1C thumb
 *   func_02025C30 0x02025C30 thumb
 *   func_020173EC 0x020173EC thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 *   func_021B98F8 0x021B98F8 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_02034714 0x02034714 arm
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0220254C  0x0220254C  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203C968  0x0203C968  arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045808 0x02045808 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0217BC44 0x0217BC44 arm ov009
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0220251C  0x0220251C  thumb  ov135
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_022021F8  0x022021F8  thumb  ov135
 *   func_02008DF0  0x02008DF0  thumb
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 */
#include "../../matched/include/Obj10593.h"
#include "../../matched/include/Obj00137.h"
#include "../../matched/include/Obj10594.h"
#include "../../matched/include/Obj18609.h"
#include "../../matched/include/Obj18610.h"
#include "../../matched/include/Obj18611.h"
#include "../../matched/include/Obj01411.h"
#include "../../matched/include/Obj23442.h"
#include "../../matched/include/Obj06520.h"
#include "../../matched/include/Obj05420.h"
#include "../../matched/include/Obj12231.h"
#include "../../matched/include/Obj02054.h"
#include "../../matched/include/Obj09244.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
struct Obj;
struct U16Vec;
struct RecDC;
struct Sub0200852CObj;
struct Strbuf;
struct MsgBank;
struct Rec;
struct Sub02008C20Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

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

typedef signed char s8;

typedef signed short s16;

typedef struct {
    u8 pad0[0x14];
    u32 x14;
    u8 pad18[0x20 - 0x18];
    int mode;
    u8 pad24[0x28 - 0x24];
    u32 state;
    u8 pad2C[0xB6C - 0x2C];
    void *msg;
    u8 padB70[0xE10 - 0xB70];
    u32 next;
    u8 padE14[0xEB4 - 0xE14];
    u32 xEB4;
    u8 padEB8[0x1328 - 0xEB8];
    u32 x1328;
} Work_02200ED8;

typedef struct {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0x38 - 0x2C];
    int err;
    u8 pad3C[0xE4 - 0x3C];
    u8 mon[0x10E0 - 0xE4];
    void *wm;
    u8 valid;
    u8 pad10E5[3];
    u32 count;
    u8 buf[0x80];
    u8 pad116C[0x1328 - 0x116C];
    u32 done;
} Work_022010BC;

extern void func_021FFFE8(u8 *,u32,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021FFD44(char *p);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021F9254(u8 *);
extern int func_0207D55C(volatile u16 *reg);
extern void func_021FFD74(char *p);
extern void func_022000E4(char *p);
extern void func_021F4EC8(u8 *);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32, u32, u32, u32, u16);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021F4FA4(u8 *p);
extern void func_02019CE0(const struct RecDC *, struct RecDC *);
extern u32 func_02025C1C(u32, u32, u32);
extern u32 func_02025C30(u32, u32, u32);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u32 func_020173EC(void);
extern u8 *func_021B9800(int, int, int);
extern void func_021B98A0(u8 *, int, int, int);
extern void func_021B98D8(u8 *, int, int);
extern int func_021B98F8(u8 *);
extern int func_021B9748(u8 *);
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern u8 *func_021B97F4(u8 *p);
extern void func_021B9774(u8 *p);
extern void func_021B99B8(u8 *p);
extern void func_021B9838(u8 *p);
extern int func_021B99F0(u8 *p);
extern u32 func_021B99F4(u32 p, u32 i);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern void func_0200FB4C(u32 id);
extern u32 func_0200F7B8(u32 a0);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_0220254C(void *mon, u32 heap);
extern u32 func_0200FBB0(void);
extern void func_0203CA04(void);
extern void func_0200FBA0(void);
extern void func_0203C968(void);
extern void func_02045994(struct Strbuf *,const u16 *,u32);
extern u16 *func_02045A90(struct U16Vec *);
extern u16 func_020458F8(struct U16Vec *);
extern u16 func_02045A98(void);
extern void func_02082BCC(void *, int, u32);
extern int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
extern int func_0217BC90(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021C86B8(u8 *dst, u8 *src, u32 n);
extern void func_0220251C(u8 *p, u16 a, u16 b);
extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_022021F8(u8 *p, int flag);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_021C8770(u8 *p);
int func_02200C0C(u8 *p);
void func_02200C80(u8 *p);
int func_02200C94(u8 *p);
void func_02200CCC(void);
void func_02200DB8(void);
void func_02200DD0(u8 *p);
void func_02200E48(u8 *p);
void func_02200E94(u8 *p);
void func_02200EB0(u8 *p);
void func_02200EC8(u8 *p);
int func_02200ED8(Work_02200ED8 *p);
int func_02200FF4(u8 *p);
int func_022010BC(Work_022010BC *p);
int func_02201258(u8 *p);
int func_02201320(u8 *p);
int func_022013E4(u8 *p);
int func_02201414(u8 *p);
int func_022014B8(u8 *p);
extern void *g_02203E94[];
extern struct DispConfig g_02203A04;
extern struct BgTemplate g_02203A14;
extern struct BgTemplate g_02203A54;
extern struct BgTemplate g_02203A34;
extern const char str_02203F58[];

int func_02200C0C(u8 *p) { func_02200EB0(p); func_02200CCC(); func_021FFFE8(p,0,0); if(((struct Obj10593 *)p)->f20==11) { func_02040588(4,0); func_02040588(6,0); } func_02200DD0(p); func_02200E48(p); func_021FFD44((char *)p); func_0202208C((void *)3,1,1,0,6,1,72); func_021F9254(p); ((struct Obj10593 *)p)->f28=0; ((struct Obj10593 *)p)->f12E4=0; return 1; }


/*
 * State-table dispatch through the table at 0x02203E94.
 */
void func_02200C80(u8 *p)
{
    ((void (*)(u8 *))g_02203E94[*(u32 *)(p + 0x28)])(p);
}

int func_02200C94(u8 *p) { if(func_0207D55C((u16 *)0x0400106c)) func_021FFD74((char *)p); func_02200EC8(p); func_02200E94(p); func_02200DB8(); func_022000E4((char *)p); func_021F4EC8(p); return 0; }


/*
 * Three-layer bring-up with all three layers 020414EC'd, tilemap clears for
 * layers 0 and 1 and plane 0x10 toggled.
 */
void func_02200CCC(void)
{
    struct DispConfig c = g_02203A04;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203A14;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203A54;
        func_0203FCA0(1, &t, 0);
    }
    func_020414EC(1);
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02203A34;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(1, 0x20, 0, 0x48);
    func_020434DC(0x10, 1);
}


/*
 * Poke channels 2, 1 and 0 in that order.
 */
void func_02200DB8(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
}

void func_02200DD0(u8 *p)
{
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    if (((struct Obj00137 *)p)->fE18 == 0) {
        func_02040588(4, 0);
        func_02040588(5, 0);
        func_02043598(0x10, 0);
    }
    if (((struct Obj00137 *)p)->f1C == 9) {
        func_02200AB4(p);
        func_02200B34(p);
    }
}

/*
 * tail: 02200E92..02200E94 two zero alignment bytes.
 */
void func_02200E48(u8 *p)
{
    u32 w;
    ((struct Obj10594 *)p)->fD40 = func_020450F0(0, 2, 0x13, 0x1b, 4, 0xd, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj10594 *)p)->fD40)), 0);
    w = ((struct Obj10594 *)p)->fD40;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
}


/*
 * Tear down the +0xfa0 sub-object, then release the +0xd40 resource.
 */
void func_02200E94(u8 *p)
{
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8((struct Descriptor *)(((struct Obj18609 *)p)->fD40));
}


/*
 * Claim the 0xb4/0x48 resource and park it at +0xb88.
 */
void func_02200EB0(u8 *p)
{
    ((struct Obj18610 *)p)->fB88 = (u32)func_020457B0(0xb4, 0x48);
}


/*
 * Tail call into func_02045808 with the pointer held at +0xb88.
 */
void func_02200EC8(u8 *p)
{
    func_02045808((struct U16Vec *)(((struct Obj18611 *)p)->fB88));
}


int func_02200ED8(Work_02200ED8 *p)
{
    switch (p->mode) {
    case 7:
        func_021F90A0((u32)p, (u32)p->msg, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 2);
        p->x1328 = 0;
        p->next = 6;
        break;
    case 8:
        func_021F90A0((u32)p, (u32)p->msg, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 0xB);
        break;
    case 9:
        func_021F90A0((u32)p, (u32)p->msg, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 2);
        p->x1328 = 0;
        p->next = 0x10;
        break;
    case 10:
        func_021F90A0((u32)p, (u32)p->msg, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 0x16);
        p->xEB4 = 1;
        break;
    case 11:
        func_021F90A0((u32)p, (u32)p->msg, 0x18, 1, 0xF0F);
        func_021F4E98((u8 *)p, 0x29, 0x1C);
        break;
    case 12:
        func_021F90A0((u32)p, (u32)p->msg, 0x9A, 1, 0xF0F);
        p->state = 0x21;
        p->x14 = 1;
        func_0203D34C(1, 0x48);
        break;
    default:
        func_02034714(str_02203F58, 0, str_02203F58);
        break;
    }
    func_021F4FA4((u8 *)p);
    return 2;
}

int func_02200FF4(u8 *p)
{
    u8 *mon=p+0xE4;
    int ready;
    func_02019CE0((const struct RecDC *)mon, *(struct RecDC * *)&((struct Obj01411 *)p)->fEA8);
    p[0x204]=func_02025C1C(p[0x204],p[0x205],p[0x209]);
    p[0x205]=func_02025C30(p[0x204],p[0x205],p[0x209]);
    *(u8 * *)&((struct Obj01411 *)p)->f10E0=func_021B9800(0x48,func_0200853C(((struct Obj23442 *)(*(u8 * *)&((struct Obj01411 *)p)->f0))->f1C),(int)(p+0x116C));
    func_021B98A0(*(u8 * *)&((struct Obj01411 *)p)->f10E0,0x48,func_020173EC(),1);
    func_021B98D8(*(u8 * *)&((struct Obj01411 *)p)->f10E0,(int)mon,func_020173EC());
    if(func_021B98F8(*(u8 * *)&((struct Obj01411 *)p)->f10E0)==0) func_02034714(str_02203F58,0,str_02203F58);
    ready=func_021B9748(*(u8 **)(p+0x10E0))==0;
    if(ready==0) func_02034714(str_02203F58,0,str_02203F58);
    ((struct Obj01411 *)p)->f28=3;
    return 2;
}


/*
 * relocation stays wildcarded (requested in docs/sessions/2026-09-27/arm9_requests.md).
 * The four ov114 targets 0x021B97F4, 0x021B99F0, 0x021B99F4, 0x021B9A14 were seeded
 * by tree_ov135_4. Every other byte is identical. Labelling 0x0200FB4C makes this EXACT.
 */
int func_022010BC(Work_022010BC *p)
{
    int st;
    int r;
    void *rec;

    st = func_021B99DC(p->wm);
    r = func_021B9790(p->wm);
    if (r == 0) {
        rec = func_021B97F4(p->wm);
        switch (st) {
        case 400:
            func_0200FB4C(0x41);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        case 401:
            func_0200FB4C(0x42);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        case 408:
            func_0200FB4C(0x44);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        default:
            func_0200FB4C(0x43);
            func_0200F7B8(0);
            func_021B9774(p->wm);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            p->state = 0x2C;
            return 2;
        case 200:
            p->valid = func_021B99F0(rec);
            p->count = func_021B99F4((u32)rec, 0);
            func_02082D44(func_021B9A14(rec, 1), p->buf, 0x80);
            func_021B99B8(p->wm);
            func_021B9838(p->wm);
            if (p->valid == 0) {
                if (p->count == 0) {
                    p->state = 4;
                } else if (p->done == 0) {
                    p->done++;
                    p->state = 2;
                    func_0220254C(p->mon, 0x48);
                } else {
                    p->err = -7;
                    p->state = 0x2D;
                }
            } else if (p->done == 0) {
                p->done++;
                p->state = 2;
                func_0220254C(p->mon, 0x48);
            } else {
                p->err = -7;
                p->state = 0x2D;
            }
            break;
        }
    } else if (r != 0xF) {
        p->err = -15;
        p->state = 0x2B;
        func_021B99B8(p->wm);
        func_021B9838(p->wm);
        func_0200FBB0();
        func_0203CA04();
        func_0200FBA0();
        func_0203C968();
    }
    return 2;
}

int func_02201258(u8 *p)
{
    struct U16Vec *s;
    u16 *text;
    u32 i;
    u16 c;
    s=func_020457B0(8,0x48);
    func_02045994((struct Strbuf *)s,(u16 *)(p+0x1F4),8);
    func_02082BCC(p+0x1300,0,0x28);
    ((struct Obj06520 *)p)->f1324=0x48;
    text=func_02045A90(s);
    for(i=0;i<func_020458F8(s)+1;i++) {
        c=*(u16 *)((u32)text+i*2);
        if(c==func_02045A98()) *(u16 *)((u32)p+i*2+0x1300)=0;
        else *(u16 *)((u32)p+i*2+0x1300)=c;
    }
    ((struct Obj06520 *)p)->f1318=(u32)(p+0x1300);
    ((struct Obj06520 *)p)->f1320=0;
    func_0217BC44((short unsigned int **)(p+0x1318),1,0,0,(char *)(p+0x131C),(int *)(p+0x1320),0x80);
    func_02045808(s);
    ((struct Obj06520 *)p)->f28=5;
    ((struct Obj06520 *)p)->fF8C=0;
    return 2;
}

int func_02201320(u8 *p)
{
    int done;
    int positive;
    u16 *dst;
    void *bank;
    void *str;
    u16 *text;
    int i;
    done = func_0217BC90() == 2;
    if (done) positive = ((struct Obj05420 *)p)->f1320 > 0;
    if (done) {
        if (positive) {
            dst = (u16 *)(p + 0x1f4);
            bank = func_02045B38(0, 2, 0x51, 0x48);
            str = func_02045EC0(bank, 0xf);
            func_02045C04(bank);
            text = func_02045A90(str);
            for (i = 0; i < 7 && (u32)i < func_020458F8(str); i++) dst[i] = text[i];
            dst[i] = func_02045A98();
            func_02045808(str);
        }
        ((struct Obj05420 *)p)->f28 = ((struct Obj05420 *)p)->fE10;
    } else {
        if ((((struct Obj05420 *)p)->fF8C)++ == 0xe10) {
            ((struct Obj05420 *)p)->f38 = -5;
            ((struct Obj05420 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
        }
    }
    return 2;
}


/*
 * Move 0x80 bytes between the +0xe4 and +0x10ec sub-objects, latch state 7 and publish the 8/0xa pair.
 */
int func_022013E4(u8 *p)
{
    func_021C86B8(p + 0xe4, p + 0x10ec, 0x80);
    ((struct Obj12231 *)p)->f28 = 7;
    ((struct Obj12231 *)p)->fF8C = 0;
    func_0220251C(p, 8, 0xa);
    return 2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state
 * 0x22 with the 0x022021F8/0x02008DF0 pair, state 0x2b with the four
 * middleware calls, state 0x2d alone, or a plain func_021F513C redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201414(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj02054 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            func_022021F8(p, 1);
            func_02008DF0((struct Sub02008C20Obj *)(*(u32 *)(((struct Obj02054 *)p)->f0 + 0x24)), 0x1c);
            ((struct Obj02054 *)p)->f28 = 0x22;
            break;
        case 14:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2d;
            break;
        case 3:
        case 11:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj02054 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * State 9 with the slot cleared and the u16 at +0x32 set.
 */
int func_022014B8(u8 *p)
{
    func_021C8770(p);
    ((struct Obj09244 *)p)->f28 = 9;
    ((struct Obj09244 *)p)->fF8C = 0;
    ((struct Obj09244 *)p)->f32 = 1;
    return 2;
}
