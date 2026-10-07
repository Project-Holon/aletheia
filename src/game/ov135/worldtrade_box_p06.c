/*
 * file:     worldtrade_box_p06.c
 * unit:     yes
 * function: func_021F5204, func_021F5250, func_021F5358, func_021F5374, func_021F5420, func_021F577C, func_021F57EC, func_021F5940, func_021F5980
 * address:  0x021F5204
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
 *   func_0207D55C 0x0207D55C arm
 *   func_021FFD74 0x021FFD74 thumb ov135
 *   func_021F59E8 0x021F59E8 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_02202C94  0x02202C94  data  ov135
 *   g_02202CE4  0x02202CE4  data  ov135
 *   g_02202D04  0x02202D04  data  ov135
 *   g_02202CA4  0x02202CA4  data  ov135
 *   g_02202CC4  0x02202CC4  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02200AB4 0x02200AB4 thumb ov135
 *   func_02200B34 0x02200B34 thumb ov135
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B974  0x0204B974  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021F4EA0  0x021F4EA0  thumb
 *   tbl_02202D24   0x02202D24  data  a2
 *   tbl_02202C50   0x02202C50  data  a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_02200BAC  0x02200BAC  thumb
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_021F6E08 0x021F6E08 thumb ov135
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 */
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj14160.h"
#include "../../matched/include/Obj14161.h"
#include "../../matched/include/Obj04526.h"

struct Obj;
struct Actor;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u8 pad10[0x18];
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    u32 f38;
    u32 f3C;
    u32 arrA[30];
    u32 arrB[30];
} Sub;

typedef struct {
    u8 pad0[0xC6];
    u16 idx;
    u8 padC8[0xBC0 - 0xC8];
    Sub sub;
    u32 arrC[6];
    u8 padD08[0xD2C - 0xD08];
    u32 arrD[2];
    u32 fD34;
    u32 fD38;
} Work_021F5420;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    int mode;
    u8 pad24[0xB84 - 0x24];
    void *strs;
    u8 padB88[0xD40 - 0xB88];
    void *win1;
    u8 padD44[0xD4C - 0xD44];
    void *win0;
    u8 padD50[0xD54 - 0xD50];
    void *win3;
    u8 padD58[0xDD0 - 0xD58];
    void *win2;
    u8 padDD4[0xFA0 - 0xDD4];
    u8 g[4];
} Work_021F57EC;

extern int func_0207D55C(volatile u16 *reg);
extern void func_021FFD74(char *p);
extern void func_021F59E8(char *p);
extern void func_022000E4(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021F4EC8(u8 *);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
extern void func_02200AB4(u8 *);
extern void func_02200B34(u8 *);
extern void func_02082BCC(void *, int, int);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0204B84C(u32, int);
extern void func_0204B974(struct Actor *a);
extern void func_021F4EA0(u32, u16, u16);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern void func_02200BAC(u8 *p, u32 k);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_021F6E08(u8 *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_021F5204(u8 *p);
void func_021F5250(void);
void func_021F5358(void);
void func_021F5374(u8 *p);
void func_021F5420(Work_021F5420 *p);
void func_021F577C(u8 *p);
void func_021F57EC(Work_021F57EC *p);
void func_021F5940(u8 *p);
void func_021F5980(u8 *p);
extern struct DispConfig g_02202C94;
extern struct BgTemplate g_02202CE4;
extern struct BgTemplate g_02202D04;
extern struct BgTemplate g_02202CA4;
extern struct BgTemplate g_02202CC4;
extern const Pos tbl_02202D24[];
extern const Pos tbl_02202C50[];
extern const char str_02203B54[];

int func_021F5204(u8 *p)
{
    if (func_0207D55C((u16 *)0x0400106c)) {
        func_021FFD74((char *)p);
    }
    func_021F577C(p);
    func_021F59E8((char *)p);
    func_021F5940(p);
    func_021F5358();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}


/*
 * Five-layer bring-up: the saved display config, then layers 0, 2 and 3
 * through 020414EC and layers 0 and 3 cleared through 02040B94.
 */
void func_021F5250(void)
{
    struct DispConfig c = g_02202C94;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02202CE4;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02202D04;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02202CA4;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02202CC4;
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
void func_021F5358(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}

void func_021F5374(u8 *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 1, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xa, 1, 0, 0xa00, 1, 0x48);
    func_020498F4(h, 0x15, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    func_02049238(h);
    func_02200AB4(p);
    func_02200B34(p);
}


void func_021F5420(Work_021F5420 *p)
{
    Local s;
    int i;

    func_02082BCC(&s, 0, 8);
    s.a = tbl_02202D24[p->idx].x;
    s.b = tbl_02202D24[p->idx].y;
    p->sub.f34 = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
    func_0204B92C((struct Obj *)p->sub.f34, 1);
    func_0204B878((struct Obj *)p->sub.f34, 4);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->sub.f34, 0);
    } else {
        func_0204B3DC((struct Obj *)p->sub.f34, 1);
    }
    if (p->idx == 0x1f || p->idx <= 5) {
        func_0204B84C(p->sub.f34, 0);
    } else {
        func_0204B84C(p->sub.f34, 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y;
        s.d = 30 - i % 6;
        p->sub.arrA[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->sub.arrA[i], i + 6);
        func_0204B84C(p->sub.arrA[i], 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->sub.arrB[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->sub.arrB[i], 0x28);
        func_0204B84C(p->sub.arrB[i], 1);
    }

    for (i = 0; i < 6; i++) {
        s.a = tbl_02202D24[i].x + 8;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->arrC[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->arrC[i], 0x2a);
        func_0204B84C(p->arrC[i], 1);
    }

    for (i = 0; i < 2; i++) {
        s.a = tbl_02202C50[i].x;
        s.b = tbl_02202C50[i].y;
        p->arrD[i] = (u32)func_0204B294((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        func_0204B878((struct Obj *)p->arrD[i], i + 0x26);
        func_0204B84C(p->arrD[i], 1);
    }

    s.a = 0xef;
    s.b = 0x88;
    s.d = 100;
    s.e = 1;
    p->sub.f3C = (u32)func_0204B294((void *)p->sub.f0, p->sub.f28, p->sub.f8, p->sub.f30, &s, 0, 0x48);
    func_0204B878((struct Obj *)p->sub.f3C, 0xc);
    func_0204B92C((struct Obj *)p->sub.f3C, 1);
    func_0204B974((struct Actor *)p->sub.f3C);
    func_0204B3DC((struct Obj *)p->sub.f3C, 0);
    func_0204B3DC((struct Obj *)p->fD38, 1);
    func_021F4EA0(p->fD38, 0x37, 0xa8);
}

void func_021F577C(u8 *p)
{
    int i;
    u8 *q;
    func_0204B3B4((struct Obj *)(((struct Obj14160 *)p)->fBFC));
    for (i = 0; i < 2; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xd2c + i * 4)));
    }
    func_0204B3B4((struct Obj *)(((struct Obj14160 *)p)->fBF4));
    for (i = 0; i < 30; i++) {
        q = p + i * 4;
        func_0204B3B4((struct Obj *)(((struct Obj14161 *)q)->fC00));
        func_0204B3B4((struct Obj *)(((struct Obj14161 *)q)->fC78));
    }
    for (i = 0; i < 6; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xcf0 + i * 4)));
    }
}


void func_021F57EC(Work_021F57EC *p)
{
    void *w;

    p->win0 = (void *)func_020450F0(3, 4, 0, 0xD, 3, 0xD, 1);
    func_02043B5C(func_02045770(p->win0), 0);
    w = p->win0;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win1 = (void *)func_020450F0(0, 2, 0x15, 0x1B, 2, 0xD, 1);
    func_02043B5C(func_02045770(p->win1), 0);
    w = p->win1;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win2 = (void *)func_020450F0(0, 2, 0x13, 0x1B, 4, 0xD, 1);
    func_02043B5C(func_02045770(p->win2), 0);
    w = p->win1;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    p->win3 = (void *)func_020450F0(1, 0x18, 0x10, 6, 2, 0, 1);
    func_02043B5C(func_02045770(p->win3), 4);
    w = p->win3;
    func_02045334(w);
    func_02045374(w);
    func_020409B4(func_02045730(w));

    func_021F91A0(p->win3, (u32)p->strs, 0, 1, 1, 0x3DC4, (u32)p->g);
    if (p->mode == 5) {
        func_02200BAC((u8 *)p, 3);
    } else {
        func_02200BAC((u8 *)p, 1);
    }
}

void func_021F5940(u8 *p)
{
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8(((struct Obj00287 *)p)->fDE0);
    func_020452E8(((struct Obj00287 *)p)->fDD0);
    func_020452E8(((struct Obj00287 *)p)->fD54);
    func_020452E8(((struct Obj00287 *)p)->fD40);
    func_020452E8(((struct Obj00287 *)p)->fD4C);
}

void func_021F5980(u8 *p)
{
    func_021F6E08(p);
    ((struct Obj04526 *)p)->fB80 = func_020457B0(0x12, 0x48);
    ((struct Obj04526 *)p)->fB88 = func_020457B0(0xb4, 0x48);
    ((struct Obj04526 *)p)->fB84 = func_02045EC0(((struct Obj04526 *)p)->fB6C, 0x73);
    if (((struct Obj04526 *)p)->fC6 == 0x1e) {
        ((struct Obj04526 *)p)->fC6 = 0;
    }
    ((struct Obj04526 *)p)->fEAC = func_02030734(0x48, 0x78, 0, str_02203B54, 0x344);
}
