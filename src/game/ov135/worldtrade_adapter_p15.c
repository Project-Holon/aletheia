/*
 * file:     worldtrade_adapter_p15.c
 * unit:     yes
 * function: func_021FDB74, func_021FDBCC, func_021FDCE4, func_021FDD00, func_021FDDA8, func_021FDEFC, func_021FDF2C, func_021FE0BC, func_021FE118
 * address:  0x021FDB74
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
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_021FE178 0x021FE178 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_022037F4  0x022037F4  data  ov135
 *   g_02203844  0x02203844  data  ov135
 *   g_02203864  0x02203864  data  ov135
 *   g_02203804  0x02203804  data  ov135
 *   g_02203824  0x02203824  data  ov135
 *   sub_020403F4  0x020403F4  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0203D34C  0x0203D34C  arm
 *   tbl_02203D38   0x02203D38  data  a1
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040C14  0x02040C14  arm
 *   tbl_022037A8   0x022037A8  data  a2
 *   tbl_022037B0   0x022037B0  data  a2
 *   tbl_022037BC   0x022037BC  data  a2
 *   func_02202940 0x02202940 thumb ov135
 *   func_020452E8 0x020452E8 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02030734  0x02030734  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021F84EC  0x021F84EC  thumb
 *   func_021F8990  0x021F8990  thumb
 *   g_02203E18     0x02203E18  data  ov135
 */
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj08189.h"
#include "../../matched/include/Obj14174.h"
#include "../../matched/include/Obj05416.h"
#include "../../matched/include/Obj23412.h"

struct Obj;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

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
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u8 page;
    u8 slot;
} Sel;

typedef struct {
    u16 x;
    u16 y;
    u16 anim;
} CurPos;

typedef struct {
    Sel sel[7];
    CurPos cur[1];
} SelTbl;

typedef struct {
    u8 pad0[0xBC0];
    void *res;
    void *set[3];
    u8 padBD0[0xBE8 - 0xBD0];
    void *set2;
    u8 padBEC[4];
    void *set3;
    void *cursor;
    void *mark;
    u8 padBFC[0xD2C - 0xBFC];
    void *btn[2];
} Obj;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[0xD90 - 0xD44];
    u32 item[6];
    u32 page[3];
    u8 padDB4[0xDD8 - 0xDB4];
    u32 tab[2];
} Menu;

extern void func_021F99D0(u8 *p);
extern void func_021FE178(char *p);
extern void func_022000E4(char *p);
extern void func_021F4EC8(u8 *p);
extern void func_0204B3DC(struct Obj *, unsigned int);
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
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, int v, int n);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B84C(void *o, int v);
extern u8 func_020355C4(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02040C14(u32 a, u32 b, u32 c, u32 d);
extern void func_02202940(struct Obj *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern u8 *func_021F84EC(u32 id);
extern void func_021F8990(u8 *p);
int func_021FDB74(unsigned char *p);
void func_021FDBCC(void);
void func_021FDCE4(void);
void func_021FDD00(void *p);
void func_021FDDA8(Obj *p);
void func_021FDEFC(char *p);
void func_021FDF2C(Menu *p);
void func_021FE0BC(unsigned char *p);
void func_021FE118(u8 *p);
extern struct DispConfig g_022037F4;
extern struct BgTemplate g_02203844;
extern struct BgTemplate g_02203864;
extern struct BgTemplate g_02203804;
extern struct BgTemplate g_02203824;
extern const SelTbl tbl_02203D38;
extern const Pos tbl_022037A8[];
extern const Pos tbl_022037B0[];
extern const Pos tbl_022037BC[];
extern u8 g_02203E18[];

int func_021FDB74(unsigned char *p)
{
    ((struct Obj00287 *)p)->fEC0 = 0;
    func_021F99D0(((struct Obj00287 *)p)->fDE4);
    func_021FDEFC((char *)p);
    func_021FE178((char *)p);
    func_021FE0BC(p);
    func_021FDCE4();
    if (*(int *)&((struct Obj00287 *)p)->f14 == 1)
        *(int *)&((struct Obj00287 *)p)->f12E4 = 1;
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}


/*
 * Four-layer bring-up, every layer 020414EC'd, with the tilemap clears for
 * layers 2, 0 and 3 in that order.
 */
void func_021FDBCC(void)
{
    struct DispConfig c = g_022037F4;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203844;
        func_0203FCA0(0, &t, 0);
    }
    func_020414EC(0);
    func_02040588(0, 1);
    {
        struct BgTemplate t = g_02203864;
        func_0203FCA0(1, &t, 0);
    }
    func_020414EC(1);
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_02203804;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02203824;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_02040B94(0, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}


/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void func_021FDCE4(void)
{
    sub_020403F4(2);
    sub_020403F4(1);
    sub_020403F4(0);
    sub_020403F4(3);
}


/*
 * The parameterless member: handle open, the B68 and B40 window calls, two
 * F5BC text calls, three 49658/498F4 draws and the second B40 pair, then
 * the 49238 release.  Contents 166 of 168 bytes (pool pad).
 */
void func_021FDD00(void *p)
{
    void *h = func_020490F4(0x60, 0x48);

    func_02049B68(h, 2, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    func_0201F5BC(0, 1, 0xe, 0, 0x48);
    func_0201F5BC(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xb, 1, 0, 0, 1, 0x48);
    func_020498F4(h, 0x17, 1, 0, 0, 1, 0x48);
    func_02049658(h, 0xc, 2, 0, 0, 1, 0x48);
    func_02049B40(0x17, 5, 4, 0x20, 0x20, 0x48);
    func_02049238(h);
}


void func_021FDDA8(Obj *p)
{
    ObjPos pos;

    func_02082BCC(&pos, 0, sizeof(pos));
    pos.x = tbl_02203D38.cur[0].x;
    pos.y = tbl_02203D38.cur[0].y;
    p->cursor = func_0204B294(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    func_0204B92C(p->cursor, 1);
    func_0204B878(p->cursor, tbl_02203D38.cur[0].anim);
    func_0204B84C(p->cursor, 1);
    if (func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 0);
    } else {
        func_0204B3DC(p->cursor, 1);
    }
    pos.x = 0xA0;
    pos.y = 0x20;
    p->mark = func_0204B294(p->res, (u32)p->set2, (u32)p->set[1], (u32)p->set3, &pos, 0, 0x48);
    func_0204B878(p->mark, 4);
    func_0204B3DC(p->mark, 0);
    pos.x = 0xE4;
    pos.y = 0x75;
    p->btn[0] = func_0204B294(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    func_0204B878(p->btn[0], 0x26);
    func_0204B3DC(p->btn[0], 0);
    pos.x = 0x8C;
    p->btn[1] = func_0204B294(p->res, (u32)p->set[0], (u32)p->set[1], (u32)p->set[2], &pos, 0, 0x48);
    func_0204B878(p->btn[1], 0x27);
    func_0204B3DC(p->btn[1], 0);
    func_0203D34C(0, 0x48);
}

void func_021FDEFC(char *p) {func_0204B3B4(*(struct Obj * *)&((struct Obj08189 *)p)->fBF4);func_0204B3B4(*(struct Obj * *)&((struct Obj08189 *)p)->fBF8);func_0204B3B4(*(struct Obj * *)&((struct Obj08189 *)p)->fD2C);func_0204B3B4(*(struct Obj * *)&((struct Obj08189 *)p)->fD30);}


void func_021FDF2C(Menu *p)
{
    int i;
    u32 v;

    p->frame = func_020450F0(0, (u8)2, (u8)0x15, (u8)0x1b, 2, 0xd, (u16)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)), 0);
    v = p->frame;
    func_02045334((struct Descriptor *)v);
    func_02045374((struct Cfg *)v);
    func_020409B4(func_02045730((struct Descriptor *)v));
    func_02040C14(3, 0, 1, 0);
    for (i = 0; i < 6; i++) {
        p->item[i] = func_020450F0(3, (u8)tbl_022037BC[i].x, (u8)tbl_022037BC[i].y, (u8)0xb, 2, 0xd, (u16)0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item[i])), 0);
        v = p->item[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
    for (i = 0; i < 2; i++) {
        p->tab[i] = func_020450F0(3, (u8)tbl_022037A8[i].x, (u8)tbl_022037A8[i].y, (u8)0x1c, 2, 0xd, (u16)0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->tab[i])), 0);
        v = p->tab[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
    for (i = 0; i < 3; i++) {
        p->page[i] = func_020450F0(3, (u8)tbl_022037B0[i].x, (u8)tbl_022037B0[i].y, (u8)0xa, 2, 0xd, (u16)0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->page[i])), 0);
        v = p->page[i];
        func_02045334((struct Descriptor *)v);
        func_02045374((struct Cfg *)v);
        func_020409B4(func_02045730((struct Descriptor *)v));
    }
}

void func_021FE0BC(unsigned char *p)
{
    int i;
    func_02202940((struct Obj *)(p + 0xfa0));
    func_020452E8(((struct Obj14174 *)p)->fDE0);
    func_020452E8(((struct Obj14174 *)p)->fD40);
    for (i = 0; i < 9; ++i)
        func_020452E8(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        func_020452E8(*(void **)(p + i * 4 + 0xdd8));
    func_02040DA8(3, 1, 0);
}


void func_021FE118(u8 *p)
{
    ((struct Obj05416 *)p)->fB88 = func_020457B0(0xb4, 0x48);
    ((struct Obj05416 *)p)->fB8C = func_02045EC0(((struct Obj05416 *)p)->fB6C, 0x30);
    ((struct Obj05416 *)p)->fE00 = func_02030734(0x48, 0x30, 0, (const char *)g_02203E18, 0x351);
    func_02082AC0(0, ((struct Obj05416 *)p)->fE00, 0x30);
    *(u8 * *)&((struct Obj23412 *)(*(u8 * *)&((struct Obj05416 *)p)->fE00))->f14 = func_021F84EC(0x48);
    func_021F8990(p + 0xeec);
}
