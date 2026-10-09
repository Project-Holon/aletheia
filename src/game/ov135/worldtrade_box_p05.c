/*
 * file:     worldtrade_box_p05.c
 * unit:     yes
 * function: func_021F7374, func_021F73DC, func_021F74E4, func_021F74F8, func_021F7538, func_021F75C0, func_021F76BC, func_021F76D8, func_021F777C, func_021F7840, func_021F7878, func_021F7964, func_021F798C, func_021F79EC, func_021F7A18, func_021F7A4C, func_021F7A70, func_021F7A8C, func_021F7B50, func_021F7B9C, func_021F7BC8, func_021F7CB4, func_021F7CDC, func_021F7D00, func_021F7D80, func_021F7DA8, func_021F7DD0, func_021F7E74, func_021F7E9C, func_021F7EC0, func_021F7F14, func_021F7F64, func_021F7F80, func_021F7F9C, func_021F7FD4, func_021F8010, func_021F8078, func_021F8098, func_021F8104, func_021F8154, func_021F8178, func_021F81C8, func_021F8290
 * address:  0x021F7374
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
 *   func_021F7338  0x021F7338  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0220262C  0x0220262C  thumb
 *   func_02007664  0x02007664  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_020185F4  0x020185F4  thumb
 *   func_0200752C  0x0200752C  thumb
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_0202208C 0x0202208C thumb
 *   func_021F9254 0x021F9254 thumb ov135
 *   func_021F8358 0x021F8358 thumb ov135
 *   func_021F9890 0x021F9890 thumb ov135
 *   g_02203BBC  0x02203BBC  data  ov135
 *   func_021F99D0 0x021F99D0 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   sub_02045EC0   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   sub_02045770   0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   sub_02045334   0x02045334  arm
 *   sub_02045374   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   sub_02045808   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
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
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *   func_021F9968  0x021F9968  thumb  ov135
 *   func_021F8950 0x021F8950 thumb ov135
 *   func_02202644 0x02202644 thumb ov135
 *   func_021F875C 0x021F875C thumb ov135
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021F89A8 0x021F89A8 thumb ov135
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F8668 0x021F8668 thumb ov135
 *   func_02202840  0x02202840  thumb  ov135
 *   func_02045EC0  0x02045EC0  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_022028C8  0x022028C8  thumb
 *   tbl_02202EB0   0x02202EB0  data
 *   g_0220301C     0x0220301C  data
 *   g_02202FC4     0x02202FC4  data
 */
#include "../../matched/include/Obj01159.h"
#include "../../matched/include/Obj23379.h"
#include "../../matched/include/Obj23380.h"
#include "../../matched/include/Obj23381.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj14162.h"
#include "../../matched/include/Obj00778.h"
#include "../../matched/include/Obj09229.h"
#include "../../matched/include/Obj05412.h"
#include "../../matched/include/Obj23382.h"
#include "../../matched/include/Obj23383.h"
#include "../../matched/include/Obj23384.h"
#include "../../matched/include/Obj23385.h"
#include "../../matched/include/Obj12199.h"
#include "../../matched/include/Obj12200.h"
#include "../../matched/include/Obj01552.h"
#include "../../matched/include/Obj02855.h"
#include "../../matched/include/Obj23386.h"
#include "../../matched/include/Obj09230.h"
#include "../../matched/include/Obj01553.h"
#include "../../matched/include/Obj03830.h"
#include "../../matched/include/Obj23387.h"
#include "../../matched/include/Obj23388.h"
#include "../../matched/include/Obj09231.h"
#include "../../matched/include/Obj02856.h"
#include "../../matched/include/Obj09232.h"
#include "../../matched/include/Obj01942.h"
#include "../../matched/include/Obj23389.h"
#include "../../matched/include/Obj18563.h"
#include "../../matched/include/Obj10576.h"
#include "../../matched/include/Obj10577.h"
#include "../../matched/include/Obj12201.h"
#include "../../matched/include/G_0220301C.h"
#include "../../matched/include/Obj08180.h"
#include "../../matched/include/Obj08181.h"

struct Sub02007454Entry;
struct Obj;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Descriptor;
struct Actor;
struct Personal;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 pad0[8];
    void *party;
    u32 storage;
} Ctx;

typedef struct {
    Ctx *ctx;
    u8 pad4[0x20 - 4];
    int kind;
    u8 pad24[0xDC - 0x24];
    u32 box;
    u32 slot;
} Obj;

typedef struct { void *a,*b,*obj,*d,*e,*f,*g,*h,*i; u32 j,k,l; } Init;

typedef unsigned short u16;

typedef signed int s32;

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

typedef signed short s16;

typedef unsigned u32_021F798C;

typedef unsigned int u32_021F79EC;

typedef signed char s8;

typedef unsigned int u32_021F7A18;

typedef void (*Fn)(void);

typedef struct { u32 unk; s16 key; s16 val; } Entry;

extern u32 func_021F7338(Obj *p, int kind);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0220262C(u32 a, u32 b);
extern void func_02007664(void *save, u32 box, u32 slot);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void *func_020185F4(void *p);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021F9254(u8 *);
extern void func_021F8358(void *,void *,void **,void *,void *,void *);
extern void *func_021F9890(Init *,u32,u32);
extern void func_021F99D0(u8 *p);
extern void func_022000E4(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021F4EC8(u8 *p);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *sub_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void sub_02045334(struct Descriptor *a);
extern void sub_02045374(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void sub_02045808(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
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
extern void func_021F4E98(u8 *p, u32_021F7A18 a, u32_021F7A18 b);
extern u32 func_020362DC(void);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F9968(u8 *p, int mode);
extern int func_021F8950(void *p, u16 *old);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_0201F868(void *p);
extern void func_02202644(u32 a, int kind);
extern void func_0201F7A8(void *p, unsigned kind);
extern void func_020061E4(unsigned se);
extern void *func_021F875C(void *p, void *dst, void *win, void *bank, void *names, void *obj, void *ctx);
extern int func_021F99F0(void *);
extern void *func_0201ADE4(u32,int,u32);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern void func_021F89A8(u8 *p, int i, u16 a, u16 b);
extern void func_021F882C(u8 *dst, int i, int kind);
extern int func_021F886C(int x, int y, int which);
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F8668(u8 *dst, u8 *p);
extern u32 func_02202840(u8 *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
void func_021F7374(Obj *p);
int func_021F73DC(u8 *p);
void func_021F74E4(u8 *p);
int func_021F74F8(u8 *p);
void func_021F7538(u8 *p, u32 b, u32 c, u32 d, u32 e);
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
int func_021F7A4C(u8 *p);
int func_021F7A70(u8 *p);
int func_021F7A8C(u8 *p);
int func_021F7B50(u8 *p);
int func_021F7B9C(u8 *p, int event);
int func_021F7BC8(u8 *p);
int func_021F7CB4(u8 *p);
int func_021F7CDC(u8 *p);
int func_021F7D00(u8 *p);
int func_021F7D80(u8 *p);
int func_021F7DA8(u8 *p);
int func_021F7DD0(u8 *p);
int func_021F7E74(u8 *p);
int func_021F7E9C(u8 *p);
int func_021F7EC0(u8 *p);
int func_021F7F14(u8 *p);
int func_021F7F64(u8 *p);
u16 func_021F7F80(int mode);
void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);
void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g);
void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);
u16 func_021F8078(int mode, u16 color);
void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);
void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);
void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);
void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);
void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
void func_021F8290(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
extern void *g_02203BBC[];
extern struct BgTemplate g_02202F64;
extern struct BgTemplate g_02202F84;
extern struct BgTemplate g_02202F44;
extern struct BgTemplate g_02202FA4;
extern const u16 tbl_02202EC0[][2];
extern const char g_02203C00[];
extern const u32 tbl_02202EB0[];
extern struct G_0220301C g_0220301C[12];
extern Entry g_02202FC4[11];








/*
 * Fill the slot record for the current kind (+0x20). A +0xDC source of
 * 0xFF copies party member +0xE0 into it (func_0220262C); otherwise the
 * box/slot pair (+0xDC, +0xE0) is looked up in the storage at +0xC of
 * the context and the found entry is written into the record.
 */
void func_021F7374(Obj *p)
{
    u32 e = func_021F7338(p, p->kind);

    if (p->box == 0xff) {
        func_0220262C(e, (u32)func_0201AB28(p->ctx->party, p->slot));
    } else {
        u32 a;
        u32 b;

        a = 0;
        b = 0;
        func_02007664((void *)p->ctx->storage, p->box, p->slot);
        func_020076D0((void *)p->ctx->storage, (int *)(&a), (int *)(&b));
        func_0200752C((void **)p->ctx->storage, a, (const struct Sub02007454Entry *)((u32)func_020185F4((void *)e)));
    }
}







int func_021F73DC(u8 *p)
{
    Init init;
    func_021F798C(p);
    func_021F75C0();
    func_021FFFE8(p,0,0);
    func_021F76D8(p);
    func_021F777C((Work *)p);
    func_021F7878(p);
    func_0202208C((void *)3,1,1,0,6,1,0x48);
    func_021F9254(p);
    func_021F81C8(((struct Obj01159 *)p)->fB6C,((struct Obj01159 *)p)->fB70,(int)(((struct Obj01159 *)p)->fB68),p+0xD90,0,3,-1,p+0xFA0);
    func_021F8358(((struct Obj01159 *)p)->fB6C,((struct Obj01159 *)p)->fB68,(void **)(p+0xD9C),((struct Obj01159 *)p)->fCC,p+0xB4C,p+0xFA0);
    init.a=p+0xD50;
    init.b=p+0xDD4;
    init.obj=((struct Obj01159 *)p)->fBF8;
    init.d=((struct Obj01159 *)p)->fD2C;
    init.e=((struct Obj01159 *)p)->fD30;
    init.f=0;
    init.g=((struct Obj01159 *)p)->fB6C;
    init.h=((struct Obj01159 *)p)->fB70;
    init.i=((struct Obj01159 *)p)->fB7C;
    init.j=((struct Obj23379 *)(*(u8 * *)&((struct Obj01159 *)p)->f0))->f10;
    init.k=((struct Obj23380 *)(*(u8 * *)&((struct Obj01159 *)p)->fE00))->f14;
    init.l=((struct Obj23381 *)(*(u8 * *)&((struct Obj01159 *)p)->f0))->f20;
    ((struct Obj01159 *)p)->fDE4=func_021F9890(&init,2,0);
    ((struct Obj01159 *)p)->f28=0;
    ((struct Obj01159 *)p)->f12E4=0;
    return 1;
}








/*
 * State-table dispatch through the table at 0x02203BBC.
 */
void func_021F74E4(u8 *p)
{
    ((void (*)(u8 *))g_02203BBC[*(u32 *)(p + 0x28)])(p);
}







int func_021F74F8(u8 *p)
{
    func_021F7964(p);
    func_021F99D0(((struct Obj00287 *)p)->fDE4);
    func_021F79EC((char *)p);
    func_021F7840((char *)p);
    func_021F76BC();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(unsigned *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}








/*
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */
void func_021F7538(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    h = ((struct Obj00018 *)p)->fD40;
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}








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







/*
 * Test bit 1 of the callee result; the odd branch re-latches state 2 before state 3.
 */
int func_021F7A4C(u8 *p)
{
    u32 v = func_020362DC();

    if (v & 2) {
        func_021F4EC0(p, 5, 5);
        ((struct Obj12199 *)p)->f28 = 2;
    }
    ((struct Obj12199 *)p)->f28 = 3;
    return 2;
}







/*
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */
int func_021F7A70(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj12200 *)p)->fDE4), 0);
    ((struct Obj12200 *)p)->f28 = 6;
    return 2;
}






int func_021F7A8C(u8 *p)
{
    switch ((unsigned)func_021F8950(((struct Obj01552 *)p)->fDF4, (u16 *)(p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        func_0202020C(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        func_0201F868(((struct Obj01552 *)p)->fDE8);
        ((struct Obj01552 *)p)->f28 = 5;
        func_020061E4(0x54C);
        break;
    case (unsigned)-2:
        func_0202020C(((struct Obj01552 *)p)->fDF4, (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 6), (u16 *)(*(u8 * *)&((struct Obj01552 *)p)->fE00 + 4));
        func_0201F868(((struct Obj01552 *)p)->fDE8);
        func_02202644((u32)(((struct Obj01552 *)p)->fD50), 0);
        func_0201F7A8(((struct Obj01552 *)p)->fD40, 0);
        func_020452E8(((struct Obj01552 *)p)->fD50);
        func_020452E8(((struct Obj01552 *)p)->fD54);
        func_021F4EC0(p, 5, 5);
        ((struct Obj01552 *)p)->f28 = 2;
        func_020061E4(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}






int func_021F7B50(u8 *p)
{
    ((struct Obj02855 *)p)->fDF4 = func_021F875C(p, p + 0xDE8, ((struct Obj02855 *)p)->fD54, ((struct Obj02855 *)p)->fB6C, ((struct Obj02855 *)p)->fB70, ((struct Obj02855 *)p)->fE00, ((struct Obj23386 *)(*(u8 * *)&((struct Obj02855 *)p)->f0))->f10);
    ((struct Obj02855 *)p)->fBC = 0xFFFF;
    ((struct Obj02855 *)p)->f28 = 6;
    return 2;
}






/*
 * Map the event code to its state byte: 0, 0xfe and 0xff are accepted.
 */
int func_021F7B9C(u8 *p, int event)
{
    switch (event) {
    case 0:
        ((struct Obj09230 *)p)->f2 = 1;
        return 1;
    case 0xfe:
        ((struct Obj09230 *)p)->f2 = 2;
        return 1;
    case 0xff:
        ((struct Obj09230 *)p)->f2 = 3;
        return 1;
    }
    return 0;
}






/*
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 */
int func_021F7BC8(u8 *p)
{
    int result=func_021F99F0(((struct Obj01553 *)p)->fDE4);
    u32 h,v;
    int mode;
    u8 *target;
    switch(result) {
    case (u32)-2:
        func_0201F7A8(((struct Obj01553 *)p)->fD40,0);
        func_021F4EC0(p,5,5);
        ((struct Obj01553 *)p)->f28=2;
        target=*(u8 * *)&((struct Obj01553 *)p)->fE00;
        func_021F89A8(p+0xEEC,((struct Obj03830 *)target)->f6+((struct Obj03830 *)target)->f4,((struct Obj03830 *)target)->fA,((struct Obj03830 *)target)->f8);
        break;
    case (u32)-1:
        break;
    default:
        ((struct Obj01553 *)p)->fB50=result;
        h=(u32)func_0201ADE4((u16)result,0,0x48);
        v=func_0201AE1C((const struct Personal *)h,20);
        func_0201AE14((void *)h);
        ((struct Obj23387 *)(*(u8 * *)&((struct Obj01553 *)p)->fE00))->f20=v;
        if(func_021F7B9C(p+0xB50,((struct Obj23388 *)(*(u8 * *)&((struct Obj01553 *)p)->fE00))->f20)) {
            ((struct Obj01553 *)p)->f28=10;
            mode=((struct Obj01553 *)p)->fB52;
        } else {
            ((struct Obj01553 *)p)->f28=7;
            mode=3;
        }
        func_021F81C8(((struct Obj01553 *)p)->fB6C,((struct Obj01553 *)p)->fB70,(int)(((struct Obj01553 *)p)->fB68),p+0xD90,((struct Obj01553 *)p)->fB50,mode,-1,p+0xFA0);
        target=*(u8 * *)&((struct Obj01553 *)p)->fE00;
        func_021F89A8(p+0xEEC,((struct Obj03830 *)target)->f6+((struct Obj03830 *)target)->f4,((struct Obj03830 *)target)->fA,((struct Obj03830 *)target)->f8);
        break;
    }
    return 2;
}







/*
 * Build through func_021F7538 and publish the 0x10/0x8 pair.
 */
int func_021F7CB4(u8 *p)
{
    func_021F7538(p, 0xa, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0x8);
    return 2;
}







/*
 * Publish the 0xffff sentinel at +0xbc and the u32 at +0xde4, then latch state 9.
 */
int func_021F7CDC(u8 *p)
{
    ((struct Obj09231 *)p)->fBC = 0xffff;
    func_021F9968((u8 *)(((struct Obj09231 *)p)->fDE4), 1);
    ((struct Obj09231 *)p)->f28 = 9;
    return 2;
}






int func_021F7D00(u8 *p)
{
    unsigned result = func_021F99F0(((struct Obj02856 *)p)->fDE4);
    switch (result) {
    case (unsigned)-2:
        func_0201F7A8(((struct Obj02856 *)p)->fD40, 0);
        ((struct Obj02856 *)p)->f28 = 0;
        break;
    case 0: case 1: case 2:
        ((struct Obj02856 *)p)->fB52 = result + 1;
        ((struct Obj02856 *)p)->f28 = 10;
        func_021F81C8(((struct Obj02856 *)p)->fB6C, ((struct Obj02856 *)p)->fB70, (int)(((struct Obj02856 *)p)->fB68), p + 0xD90, ((struct Obj02856 *)p)->fB50, ((struct Obj02856 *)p)->fB52, -1, p + 0xFA0);
        break;
    }
    return 2;
}







int func_021F7D80(u8 *p)
{
    func_021F7538(p, 0xb, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0xb);
    return 2;
}







/*
 * Publish the u32 at +0xde4, the 0xffff sentinel at +0xbc and latch state 0xc.
 */
int func_021F7DA8(u8 *p)
{
    func_021F9968((u8 *)(((struct Obj09232 *)p)->fDE4), 2);
    ((struct Obj09232 *)p)->fBC = 0xffff;
    ((struct Obj09232 *)p)->f28 = 0xc;
    return 2;
}






int func_021F7DD0(u8 *p)
{
    unsigned result = func_021F99F0(((struct Obj01942 *)p)->fDE4);
    switch (result) {
    case 12: case (unsigned)-2:
        func_0201F7A8(((struct Obj01942 *)p)->fD40, 0);
        if (func_021F7B9C(p + 0xB50, ((struct Obj23389 *)(*(u8 * *)&((struct Obj01942 *)p)->fE00))->f20)) {
            ((struct Obj01942 *)p)->f28 = 0;
        } else {
            ((struct Obj01942 *)p)->f28 = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        func_021F882C(p + 0xB50, result, 0);
        ((struct Obj01942 *)p)->f28 = 13;
        result = func_021F886C(((struct Obj01942 *)p)->fB53, ((struct Obj01942 *)p)->fB54, 0);
        func_021F81C8(((struct Obj01942 *)p)->fB6C, ((struct Obj01942 *)p)->fB70, (int)(((struct Obj01942 *)p)->fB68), p + 0xD90, ((struct Obj01942 *)p)->fB50, ((struct Obj01942 *)p)->fB52, result, p + 0xFA0);
        break;
    }
    return 2;
}







int func_021F7E74(u8 *p)
{
    func_021F7538(p, 0x17, 1, 0, 0xf0f);
    func_021F4E98(p, 0x10, 0xe);
    return 2;
}







/*
 * State setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */
int func_021F7E9C(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x126, 0x3, 0x0);
    ((struct Obj18563 *)p)->f28 = 0xf;
    return 2;
}






int func_021F7EC0(u8 *p)
{
    int result;
    result = func_021F4D14((char *)p);
    if (result == 1) {
        func_021F4CE4((char *)p);
        func_021F4EC0(p, 7, 7);
        ((struct Obj10576 *)p)->f28 = 2;
        ((struct Obj10576 *)p)->fEB4 = 1;
        func_021F8668(p + 0xE4, p);
    } else if (result == 2) {
        func_021F4CE4((char *)p);
        func_021F4EC0(p, 5, 5);
        ((struct Obj10576 *)p)->f28 = 2;
    }
    return 2;
}






int func_021F7F14(u8 *p)
{
    if (((struct Obj10577 *)p)->f14 == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        ((struct Obj10577 *)p)->fEB4 = 1;
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj10577 *)p)->f28 = 0;
    return 3;
}







/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_021F7F64(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12201 *)p)->f28 = ((struct Obj12201 *)p)->f2C;
    }
    return 2;
}







/*
 * Mode table: 0 -> 0x14c0, 1 -> 0xc80, anything else 0.
 */
u16 func_021F7F80(int mode)
{
    switch (mode) {
    case 0:
        return 0x53 << 6;
    case 1:
        return 0x32 << 6;
    default:
        return 0;
    }
}







void func_021F7F9C(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, (u32)str, 0, x, y, color, (u32)g);
        func_02045808(str);
    }
}






void func_021F7FD4(void *win, void *bank, u32 index, u32 y, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_022028C8(win, 0, str, 0, y, 0, color, g);
        func_02045808(str);
    }
}






void func_021F8010(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g)
{
    void *str;

    if (index != 0) {
        str = func_02045EC0(bank, index);
        func_021F91A0(win, (u32)str, 0, x, y, color, (u32)g);
        func_02045808(str);
    } else {
        str = func_02045EC0(bank2, 0xBB);
        func_021F91A0(win, (u32)str, 0, x, y, color, (u32)g);
        func_02045808(str);
    }
}






u16 func_021F8078(int mode, u16 color)
{
    if (mode == 1) {
        return func_021F7F80(0);
    }
    if (mode == 2) {
        color = func_021F7F80(1);
    }
    return color;
}






void func_021F8098(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        if (y > 3) {
            func_021F91A0(win, (u32)str, y, x, 0, func_021F8078(mode, color), (u32)g);
        } else {
            func_021F91A0(win, (u32)str, 0, x, y, func_021F8078(mode, color), (u32)g);
        }
        func_02045808(str);
    }
}






void func_021F8104(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = func_02045EC0(bank, tbl_02202EB0[mode]);
        func_022028C8(win, 0, str, x, y, 0, func_021F8078(mode, color), g);
        func_02045808(str);
    }
}





void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g)
{
    func_021F8178(win, bank, idx, e, 0, y, color, alt, (u32)g);
}





void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g)
{
    Entry *tab;
    void *str;

    if (idx != -1) {
        tab = ((Entry *)g_0220301C);
        if (alt != 0) {
            tab = g_02202FC4;
        }
        str = func_02045EC0(bank, tab[idx].unk);
        func_021F91A0(win, (u32)str, x, y, e, color, g);
        func_02045808(str);
    }
}


void func_021F81C8(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g)
{
    int i;
    void *str;
    int show = 1;
    str = func_02045EC0(bank, 0x6b);
    func_021F91A0(((struct Obj08180 *)win)->f0, (u32)str, 1, 0, 0, 0x440, (u32)g);
    for (i = 1; i < 3; i++)
        func_02043B5C(func_02045770(*(void **)(win + i * 4)), 0);
    func_021F7F9C(((struct Obj08180 *)win)->f4, names, index, 0, 0, 0x440, g);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            func_021F8098(((struct Obj08180 *)win)->f4, bank, mode, 0, 0, 70, 0x440, g);
    }
    func_021F8154(((struct Obj08180 *)win)->f8, bank, place, 2, 0, 0x440, 0, g);
    func_02045808(str);
}

void func_021F8290(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g)
{
    int i;
    void *str;
    int show = 1;
    str = func_02045EC0(bank, 0x6b);
    func_021F91A0(((struct Obj08181 *)win)->f0, (u32)str, 0, 0, 0, 0x440, (u32)g);
    for (i = 1; i < 3; i++)
        func_02043B5C(func_02045770(*(void **)(win + i * 4)), 0);
    func_021F7F9C(((struct Obj08181 *)win)->f4, names, index, 0, 0, 0x440, g);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            func_021F8098(((struct Obj08181 *)win)->f4, bank, mode, 0, 0, 70, 0x440, g);
    }
    func_021F8154(((struct Obj08181 *)win)->f8, bank, place, 0, 0, 0x440, 0, g);
    func_02045808(str);
}
