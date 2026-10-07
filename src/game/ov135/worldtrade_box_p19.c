/*
 * file:     worldtrade_box_p19.c
 * unit:     yes
 * function: func_021F75C0, func_021F76BC, func_021F76D8, func_021F777C, func_021F7840, func_021F7878, func_021F7964, func_021F798C, func_021F79EC, func_021F7A18
 * address:  0x021F75C0
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
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02202F64  0x02202F64  data  ov135
 *   g_02202F84  0x02202F84  data  ov135
 *   g_02202F44  0x02202F44  data  ov135
 *   g_02202FA4  0x02202FA4  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049624 0x02049624 arm
 *   func_0204989C 0x0204989C arm
 *   func_02049658 0x02049658 arm
 *   func_02049238 0x02049238 arm
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02200BAC 0x02200BAC thumb ov135
 *   tbl_02202EC0 0x02202EC0 data a2
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B974 0x0204B974 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020457B0 0x020457B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_021F8498 0x021F8498 thumb ov135
 *   func_021F84EC 0x021F84EC thumb ov135
 *   func_021F8990 0x021F8990 thumb ov135
 *   g_02203C00 0x02203C00 data a4
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_021F7538 0x021F7538 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
#include "../../matched/include/Obj14162.h"
#include "../../matched/include/Obj00778.h"
#include "../../matched/include/Obj09229.h"
#include "../../matched/include/Obj05412.h"
#include "../../matched/include/Obj23382.h"
#include "../../matched/include/Obj23383.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj23384.h"
#include "../../matched/include/Obj23385.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct Actor;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021F75C0;

struct DispConfig {
    u32_021F75C0 unk_00;
    u32_021F75C0 unk_04;
    u32_021F75C0 unk_08;
    u32_021F75C0 unk_0c;
};

struct BgTemplate {
    u32_021F75C0 unk_00;
    u32_021F75C0 unk_04;
    u32_021F75C0 bufSize;
    u32_021F75C0 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32_021F75C0 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32_021F75C0 unk_1c;
};

typedef unsigned int   u32_021F76BC;

typedef unsigned u32_021F76D8;

typedef unsigned u32_021F777C;

typedef struct { u8 pad0[0xD40]; void *win; u8 padD44[0xD90-0xD44]; void *wins[6]; } Work;

typedef unsigned int u32_021F7840;

typedef unsigned int u32_021F7878;

typedef struct { u16 x,y,z; u8 a,b; } Pos;

typedef unsigned int u32_021F7964;

typedef signed int s32;

typedef signed short s16;

typedef unsigned u32_021F798C;

typedef unsigned int u32_021F79EC;

typedef signed char s8;

typedef unsigned int u32_021F7A18;

extern u32_021F75C0 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32_021F75C0 a);
extern void func_02043598(u32_021F75C0 mask, u32_021F75C0 enable);
extern void func_020434DC(u32_021F75C0 mask, u32_021F75C0 enable);
extern void func_0203FCA0(u32_021F75C0 bgId, const struct BgTemplate *tmpl, u32_021F75C0 type);
extern void func_020414EC(u32_021F75C0 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32_021F75C0 size, u32_021F75C0 offset, u32_021F75C0 heapId);
extern void func_02041300(u32_021F75C0 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32_021F75C0 layer);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32_021F76BC i);
extern void *func_020490F4(u32_021F76D8 id, u32_021F76D8 heap);
extern void func_02049B40(u32_021F76D8 a, u32_021F76D8 b, u32_021F76D8 c, u32_021F76D8 d, u32_021F76D8 e, u16 f);
extern void func_0201F5BC(u32_021F76D8 a, u32_021F76D8 b, u32_021F76D8 c, u32_021F76D8 d, u16 heap);
extern u32_021F76D8 func_02049624(void *a0, void *a1, void *a2, void *a3, u32_021F76D8 a4, u32_021F76D8 a5, u16 a6);
extern void func_0204989C(u32_021F76D8 a0, u32_021F76D8 a1, u32_021F76D8 a2, u32_021F76D8 a3, u32_021F76D8 a4, u32_021F76D8 a5, u16 flags);
extern u32_021F76D8 func_02049658(void *a, u32_021F76D8 b, u32_021F76D8 c, u32_021F76D8 d, u32_021F76D8 e, u32_021F76D8 f, u16 g);
extern void func_02049238(void *h);
extern void func_02200B34(u8 *p);
extern u32_021F777C func_020450F0(u32_021F777C layer, u32_021F777C a, u32_021F777C b, u32_021F777C tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02200BAC(u8 *p, u32_021F777C k);
extern void func_02202940(struct Obj *p);
extern u32_021F7840 func_020452E8(struct Descriptor *d);
extern void func_02082BCC(void *,u32_021F7878,u32_021F7878);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32_021F7878 v);
extern void func_0204B974(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, u32_021F7878 v);
extern void func_0204B3B4(struct Obj *p);
extern struct U16Vec *func_020457B0(u32_021F798C capacity, u32_021F798C heapId);
extern void *func_02030734(u32_021F798C heapId, u32_021F798C size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32_021F798C value, void *dst, u32_021F798C size);
extern u16 *func_021F8498(u32_021F798C heap, u32_021F798C unused, u32_021F798C *count);
extern u8 *func_021F84EC(u32_021F798C id);
extern void func_021F8990(u8 *p);
extern u32_021F79EC func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
extern u32_021F7A18 func_020221A4(void);
extern void func_021F7538(u8 *p, u32_021F7A18 b, u32_021F7A18 c, u32_021F7A18 d, u32_021F7A18 e);
extern void func_021F4E98(u8 *p, u32_021F7A18 a, u32_021F7A18 b);
void func_021F75C0(void);
void func_021F76BC(void);
void func_021F76D8(void *p);
void func_021F777C(Work *p);
void func_021F7840(char *p);
void func_021F7878(u8 *p);
void func_021F7964(u8 *p);
void func_021F798C(u8 *p);
void func_021F79EC(char *p);
int func_021F7A18(u8 *p);
extern struct BgTemplate g_02202F64;
extern struct BgTemplate g_02202F84;
extern struct BgTemplate g_02202F44;
extern struct BgTemplate g_02202FA4;
extern const u16 tbl_02202EC0[][2];
extern const char g_02203C00[];


/*
 * Four-layer bring-up with no display restore: layer 2 is seeded by the
 * 02041300 tile dump and its 020409B4 redraw before the enable.
 */
void func_021F75C0(void)
{
    {
        struct BgTemplate t = g_02202F64;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02202F84;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02202F44;
        func_0203FCA0(2, &t, 0);
    }
    func_02041300(2, 0, 0, 0, 0x20, 0x18, 0);
    func_020409B4(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02202FA4;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}


/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void func_021F76BC(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}

void func_021F76D8(void *p)
{
    void *h = func_020490F4(0x60, 0x48);
    func_02049B40(0x60, 0, 0, 0, 0x40, 0x48);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x48);
    func_0201F5BC(0, 1, 14, 0, 0x48);
    func_0201F5BC(0, 31, 11, 0, 0x48);
    func_02049624((void *)0x60, (void *)9, (void *)1, 0, 0, 1, 0x48);
    func_0204989C(0x60, 20, 1, 0, 0x600, 1, 0x48);
    func_02049658(h, 12, 2, 0, 0, 1, 0x48);
    func_02200B34(p);
    func_02049238(h);
}

void func_021F777C(Work *p)
{
    void *w;
    int i;
    p->win = (void *)func_020450F0(0, (u8)2, (u8)21, (u8)27, 2, 13, (u16)1);
    func_02043B5C(func_02045770(p->win), 0);
    w = p->win;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));
    for (i = 0; i < 6; i++) {
        p->wins[i] = (void *)func_020450F0(3, (u8)tbl_02202EC0[i][0], (u8)tbl_02202EC0[i][1], (u8)12, 2, 13, (u16)1);
        func_02043B5C(func_02045770(p->wins[i]), 0);
        w = p->wins[i];
        func_02045334(w);
        func_02045374(w);
        func_020409B4(func_02045730(w));
    }
    func_02200BAC((u8 *)p, 3);
}

void func_021F7840(char *p) { int i; func_02202940((struct Obj *)(p+0xfa0)); func_020452E8(((struct Obj14162 *)p)->fDE0); for(i=0;i<6;i++) func_020452E8(*(void **)((u32_021F7840)p+(u32_021F7840)i*4+0xd90)); func_020452E8(((struct Obj14162 *)p)->fD40); }

/*
 * func_0204B294 returns the object consumed by the subsequent calls and stores.
 * Matched ov135 neighbours prove its pointer request in the fifth slot.
 */
void func_021F7878(u8 *p)
{
    Pos pos;
    func_02082BCC(&pos,0,8);
    pos.x=0xA0;
    pos.y=0x20;
    ((struct Obj00778 *)p)->fBF8=func_0204B294(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBE8,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBF0,&pos,0,0x48);
    func_0204B878(((struct Obj00778 *)p)->fBF8,12);
    func_0204B92C(((struct Obj00778 *)p)->fBF8,1);
    func_0204B974(((struct Obj00778 *)p)->fBF8);
    func_0204B3DC(((struct Obj00778 *)p)->fBF8,0);
    pos.x=0xE4;
    pos.y=0x75;
    ((struct Obj00778 *)p)->fD2C=func_0204B294(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBC4,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBCC,&pos,0,0x48);
    func_0204B878(((struct Obj00778 *)p)->fD2C,0x26);
    func_0204B3DC(((struct Obj00778 *)p)->fD2C,0);
    pos.x=0x8C;
    ((struct Obj00778 *)p)->fD30=func_0204B294(((struct Obj00778 *)p)->fBC0,(unsigned int)((struct Obj00778 *)p)->fBC4,(unsigned int)((struct Obj00778 *)p)->fBC8,(unsigned int)((struct Obj00778 *)p)->fBCC,&pos,0,0x48);
    func_0204B878(((struct Obj00778 *)p)->fD30,0x27);
    func_0204B3DC(((struct Obj00778 *)p)->fD30,0);
}


/*
 * Release the +0xbf8, +0xd2c and +0xd30 handles.
 */
void func_021F7964(u8 *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj09229 *)p)->fBF8));
    func_0204B3B4((struct Obj *)(((struct Obj09229 *)p)->fD2C));
    func_0204B3B4((struct Obj *)(((struct Obj09229 *)p)->fD30));
}

void func_021F798C(u8 *p)
{
    ((struct Obj05412 *)p)->fB88 = func_020457B0(0xB4, 0x48);
    ((struct Obj05412 *)p)->fE00 = func_02030734(0x48, 0x30, 0, g_02203C00, 0x2B4);
    func_02082AC0(0, ((struct Obj05412 *)p)->fE00, 0x30);
    *(u16 * *)&((struct Obj23382 *)(*(u8 * *)&((struct Obj05412 *)p)->fE00))->f18 = func_021F8498(0x48, 0, (u32_021F798C *)(*(u8 * *)&((struct Obj05412 *)p)->fE00 + 0x1C));
    *(u8 * *)&((struct Obj23383 *)(*(u8 * *)&((struct Obj05412 *)p)->fE00))->f14 = func_021F84EC(0x48);
    func_021F8990(p + 0xEEC);
}

void func_021F79EC(char *p) { func_020307B0(((struct Obj23384 *)(*(char * *)&((struct Obj00287 *)p)->fE00))->f14); func_020307B0(((struct Obj23385 *)(*(char * *)&((struct Obj00287 *)p)->fE00))->f18); func_020307B0(((struct Obj00287 *)p)->fE00); func_02045808(((struct Obj00287 *)p)->fB88); }

int func_021F7A18(u8 *p) { if(func_020221A4()){func_021F7538(p,9,1,0,0xf0f);func_021F4E98(p,16,1);}return 2; }
