/*
 * file:     unit_021D4240.c
 * unit:     yes
 * function: func_021D4240, func_021D4244, func_021D424C, func_021D4384, func_021D44BC, func_021D4590, func_021D45BC, func_021D45E8, func_021D4630, func_021D4644, func_021D46CC, func_021D48D8, func_021D4A64, func_021D4AD4, func_021D4B30, func_021D4B74, func_021D4BDC, func_021D4BF0, func_021D4BF4, func_021D4C50, func_021D4CD8, func_021D4D98, func_021D4FE4, func_021D5004, func_021D503C, func_021D50B4, func_021D50DC, func_021D5110, func_021D5278, func_021D5310, func_021D533C, func_021D5368, func_021D5370, func_021D5514
 * address:  0x021D4240
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D5780 0x021D5780 data a4
 *   d_021D57A0 0x021D57A0 data a4
 *   d_021D57C0 0x021D57C0 data a4
 *   d_021D57E0 0x021D57E0 data a4
 *   d_021D5800 0x021D5800 data a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_02049B40 0x02049B40 arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02041B6C 0x02041B6C arm
 *   data_021D5708 0x021D5708 data a1
 *   data_021D5704 0x021D5704 data a1
 *   data_021D570C 0x021D570C data a1
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   data_021D5870 0x021D5870 data a2
 *   d_021D575C 0x021D575C data a4
 *   d_021D5890 0x021D5890 data a4
 *   d_021D5720 0x021D5720 data a4
 *   d_021D5718 0x021D5718 data a4
 *   d_021D5728 0x021D5728 data a4
 *   func_02051B84 0x02051B84 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02178118 0x02178118 thumb ov014
 *   func_0204BA00 0x0204BA00 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_02158630 0x02158630 thumb ov010
 *   data_021D58E0 0x021D58E0 data a4
 *   func_02158678 0x02158678 thumb ov010
 *   func_021586C8 0x021586C8 thumb ov010
 *   data_021D5714 0x021D5714 data ov122 a4
 *   data_021D5840 0x021D5840 data a4
 *   data_021D5850 0x021D5850 data a4
 *   data_021D5860 0x021D5860 data a4
 *   data_021D5710 0x021D5710 data a4
 *   func_020221A4 0x020221A4 thumb
 *   func_02051C88 0x02051C88 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0203D798 0x0203D798 arm
 *   func_0203CF3C 0x0203CF3C arm
 *   func_0203CF10 0x0203CF10 arm
 *   func_02045994 0x02045994 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_020355D8 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 *   func_02027974 0x02027974 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02040618 0x02040618 arm
 *   func_020121CC 0x020121CC thumb
 *   func_02012204 0x02012204 thumb
 *   func_0202223C 0x0202223C thumb
 */
#include "../../matched/include/Obj01404.h"
#include "../../matched/include/Obj02472.h"
#include "../../matched/include/Obj06456.h"
#include "../../matched/include/Obj00073.h"
#include "../../matched/include/Obj13963.h"
#include "../../matched/include/Obj10431.h"
#include "../../matched/include/Obj13964.h"
#include "../../matched/include/Obj06457.h"
#include "../../matched/include/Obj22930.h"
#include "../../matched/include/Obj05359.h"
#include "../../matched/include/Obj22931.h"
#include "../../matched/include/Obj01405.h"
#include "../../matched/include/Obj00265.h"
#include "../../matched/include/Obj00265.h"
#include "../../matched/include/Obj13965.h"
#include "../../matched/include/Obj22932.h"
#include "../../matched/include/Obj13966.h"
#include "../../matched/include/Obj22933.h"
#include "../../matched/include/Obj00208.h"
#include "../../matched/include/Obj13967.h"
#include "../../matched/include/Obj22934.h"
#include "../../matched/include/Obj22935.h"

struct BgTemplate;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct Obj;
struct Actor;
struct GfFont;
struct U16Vec;
struct Rec;
struct Ctx;
struct Comm;
struct Cmd;
struct WordSet;
struct BigObj;
struct SoundSys;
struct Strbuf;
struct Obj0203159C;
struct DispConfig;
struct DispVram;
struct Bank;
struct R;
struct Tcbl;
struct IcaAnime;
struct PrintSys;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Config { u32 w[8]; } Config;

typedef signed short s16;

typedef struct { int f00, f04, f08, f0c; } Row;

typedef struct { char pad00[0xc]; u16 heap; u16 pad0e; void *f10[11]; int pad3c; void *f40; void *f44; int pad48; void *f4C; int pad50; void *f54; char pad58[0x348-0x58]; int f348; } Object_021D4384;

typedef struct { char pad00[0x10]; void *f10[11]; } Object_021D44BC;

typedef int (*Fn)(int,u32 *);

typedef struct { u8 v[3]; } Triple;

typedef struct { u16 f00, f02, f04; u8 f06, f07; } Request;

typedef signed int     s32;

typedef struct Pair { int a, b; } Pair;

typedef struct { u16 f00; char *f04; void (*f08)(void); } Params;

typedef struct { char pad00[0x10]; void *f10[11]; } Object_021D4240;

typedef struct { char f00[8]; u16 f08, f0a; } Entry;

typedef struct { char pad00[0x64]; Entry f64[16]; } Object_021D50DC;

typedef struct { u32 v[4]; } Display;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *, unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02051C6C(void *);
extern void func_02041B6C(u32);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
extern void func_0201DD68(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_020221A4(void);
extern unsigned int func_02012138(const struct Ctx *p);
extern u32 func_02026454(void *obj);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_02178118(u32 callback, u32 value);
extern void func_02026400(struct Comm *p);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void func_0204B9A0(struct Actor *a);
extern int func_02158630(int a);
extern void func_020061E4(u32 a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02026CA0(int *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_02158678(void *p);
extern int func_021586C8(int, int);
extern int func_02051C88(void *);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_0203D798(void);
extern void *func_0203CF3C(u32);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_020107FC(void *);
extern u32 func_0203CF10(u32 a);
extern u16 *func_0202E930(void *);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0204B3F4(struct Obj *p);
extern unsigned int func_02012A30(const struct BigObj *);
extern void func_02028A64(struct SoundSys *sys);
extern void func_02028A70(struct SoundSys *sys);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_0204A648(void);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern void func_0204363C(u32);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020056A0(u32, void *, u32);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_0203D34C(u32, u32);
extern int func_0203CD98(void);
extern void func_020355D8(u8);
extern void func_02027974(void *);
extern void func_0204A600(void);
extern u32 func_0201058C(void *);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02040618(u32, u32, u32);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(u32, u32);
void func_021D4240(u32 *p,u32 a);
void func_021D4244(void *p, u32 a, int a2);
void func_021D424C(void *a0);
void func_021D4384(int count, int *values, Object_021D4384 *p, Row *rows, const int *xs, const int *ys);
void func_021D44BC(int i, Object_021D44BC *p, Row *row, const int *xs, const int *ys);
void func_021D4590(u32 i,u32 p);
void func_021D45BC(u32 i,u32 p);
void func_021D45E8(char *p);
void func_021D4630(int a,int b,u32 *p);
void func_021D4644(u16 *p, const u16 *add, int count);
void func_021D46CC(char *p);
void func_021D48D8(char *p);
void func_021D4A64(char *p);
void func_021D4AD4(char *p);
void func_021D4B30(char *p);
void func_021D4B74(char *p);
void func_021D4BDC(char *p);
void func_021D4BF0(void);
void func_021D4BF4(char *p);
int func_021D4C50(int value, char *p);
void func_021D4CD8(int i, int value, int force, int mode, Object_021D4240 *p);
void func_021D4D98(char *p);
void func_021D4FE4(char *p);
void func_021D5004(char *p);
void func_021D503C(char *p);
void func_021D50B4(char *p,u32 n);
void func_021D50DC(char *p);
void func_021D5110(char *p);
void func_021D5278(Object_021D50DC *p, const char *data, int value, int tag);
void func_021D5310(u8 *p);
u32 func_021D533C(u8 *p);
void func_021D5368(void);
int func_021D5370(void *owner, void *unused, char *args);
int func_021D5514(void *a, void *b, void *c, char *p);
extern const Config d_021D5780, d_021D57A0, d_021D57C0, d_021D57E0, d_021D5800;
extern const Triple data_021D5708, data_021D5704, data_021D570C;
extern u16 data_021D5870[];
extern const Pair d_021D575C;
extern int d_021D5890[], d_021D5720[], d_021D5718[], d_021D5728[];
extern Row data_021D58E0[];
extern int data_021D5714[], data_021D5710[];
extern Row data_021D5840, data_021D5850, data_021D5860;
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;







void func_021D4240(u32 *p,u32 a) {*p=a;}







void func_021D4244(void *p, u32 a, int a2) {func_021D4240(p,a);}







void func_021D424C(void *a0)
{
    Config a, b, c, d, e;
    a = d_021D5780;
    func_0203FCA0(0, (const struct BgTemplate *)(&a), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b = d_021D57A0;
    func_0203FCA0(4, (const struct BgTemplate *)(&b), 0);
    func_02040588(4, 1);
    func_020409B4(4);
    c = d_021D57C0;
    func_0203FCA0(5, (const struct BgTemplate *)(&c), 0);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    d = d_021D57E0;
    func_0203FCA0(6, (const struct BgTemplate *)(&d), 0);
    func_02040588(6, 1);
    func_020409B4(6);
    e = d_021D5800;
    func_0203FCA0(7, (const struct BgTemplate *)(&e), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}







void func_021D4384(int count, int *values, Object_021D4384 *p, Row *rows, const int *xs, const int *ys)
{
    int i, x, y;
    p->f348 = count;
    func_02049B40(23, 5, 4, 384, 32, p->heap);
    for (i = 0; i < 11; i++) {
        if (p->f10[i]) {
            func_020456F8(p->f10[i]);
            func_0201F7A8(p->f10[i], 2);
            func_020452E8(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    for (i = 0; i < count; i++) {
        p->f10[i] = (void *)func_020450F0(7, (u8)rows[i].f00, (u8)rows[i].f04, (u8)rows[i].f08, rows[i].f0c, 13, 0);
        func_02043B5C(func_02045770(p->f10[i]), 0);
        func_02045CAC(p->f44, (int)values[i], p->f54);
        if (xs) x = xs[i] - (func_0201D304(p->f54, (u32)p->f4C, 0) >> 1);
        else x = 0;
        if (ys) y = ys[i] - (func_0201D42C(p->f54, p->f4C) >> 1);
        else y = 0;
        func_0201C7D0(func_02045770(p->f10[i]), x, y, p->f54, p->f4C, 0x39e3);
        func_02045334(p->f10[i]);
        func_02045374(p->f10[i]);
    }
    if (p->f40) func_02051C6C(p->f40);
    p->f40 = 0;
    func_02041B6C(7);
}







/*
 * lever: x initialized after construction lets its zero share the outgoing stack argument.
 */
void func_021D44BC(int i, Object_021D44BC *p, Row *row, const int *xs, const int *ys)
{
    int x, y;
    if (p->f10[i]) {
        func_020456F8(p->f10[i]);
        func_0201F7A8(p->f10[i], 2);
        func_020452E8(p->f10[i]);
        p->f10[i] = 0;
    }
    p->f10[i] = (void *)func_020450F0(7, (u8)row->f00, (u8)row->f04, (u8)row->f08, row->f0c, 13, 0);
    x = 0;
    func_02043B5C(func_02045770(p->f10[i]), 0);
    if (xs) x = xs[i] - (func_0201D304(((struct Obj01404 *)p)->f54, *(u32 *)&((struct Obj01404 *)p)->f4C, 0) >> 1);
    if (ys) y = ys[i] - (func_0201D42C(((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C) >> 1);
    else y = 0;
    func_0201C7D0(func_02045770(p->f10[i]), x, y, ((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C, 0x39e3);
    func_02045334(p->f10[i]);
    func_02045374(p->f10[i]);
    func_02041B6C(7);
}







void func_021D4590(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {func_020456F8(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);func_020452E8(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(5);}







void func_021D45BC(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {func_020456F8(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);func_020452E8(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(7);}







/*
 * extent: Two zero padding bytes after the return, next function 021D4630.
 */
void func_021D45E8(char *p)
{
    int i;
    char *q;
    if (((struct Obj02472 *)p)->f40) func_02051C6C(((struct Obj02472 *)p)->f40);
    *(int *)&((struct Obj02472 *)p)->f40 = 0;
    for (i = 0; i < 11; i++) {
        q = p + i * 4;
        if (((struct Obj06456 *)q)->f10) {
            func_020456F8(((struct Obj06456 *)q)->f10);
            func_02041B6C(5);
            func_0201F7A8(((struct Obj06456 *)q)->f10, 2);
            func_020452E8(((struct Obj06456 *)q)->f10);
        }
        *(int *)&((struct Obj06456 *)q)->f10 = 0;
    }
    ((struct Obj02472 *)p)->f348 = 0;
}







void func_021D4630(int a,int b,u32 *p) {if(b==0 && p[1]!=0) {if(((Fn)p[1])(a,p)==0)return;}}







void func_021D4644(u16 *p, const u16 *add, int count)
{
    int i, j;
    for (i = 0; i < count; i++) {
        u16 *q = p + i * 16;
        for (j = 0; j < 16; j++) {
            u16 color = q[j];
            u16 r = color & 31;
            u16 g = (color & 0x3e0) >> 5;
            u16 b = (color & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            q[j] = r + (g << 5) + (b << 10);
        }
    }
}







void func_021D46CC(char *p)
{
    Triple x = data_021D5708;
    Triple y = data_021D5704;
    Triple z = data_021D570C;
    Request req;
    int i, a, b, c, d, e, f, g;
    i = 0;
    a = 0x37c;
    b = 0x378;
    c = 0x380;
    d = 0x390;
    e = 0x390;
    f = 0x390;
    g = 0x390;
    for (; i < 3; i++) {
        char *q;
        req.f00 = x.v[i]; req.f02 = y.v[i]; req.f04 = z.v[i];
        req.f06 = 1; req.f07 = 2;
        q = p + 4 * i;
        *(void **)(q + d) = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, *(u32 *)(p + a), *(u32 *)(p + b), *(u32 *)(p + c), &req, 1, ((struct Obj00073 *)p)->fC);
        func_0204B92C(*(void **)(q + e), 0);
        func_0204B3DC(*(void **)(q + f), 1);
        func_0204B688(*(void **)(q + g), 1);
    }
    req.f00 = 128; req.f02 = 96; req.f04 = 15; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f39C = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f39C, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f39C, 1);
    func_0204B688(((struct Obj00073 *)p)->f39C, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 18; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A0 = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f3A0, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f3A0, 0);
    func_0204B688(((struct Obj00073 *)p)->f3A0, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 25; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A4 = func_0204B294((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    func_0204B92C(((struct Obj00073 *)p)->f3A4, 1);
    func_0204B3DC(((struct Obj00073 *)p)->f3A4, 0);
    func_0204B688(((struct Obj00073 *)p)->f3A4, 1);
}







/*
 * ABI: 02049990 argument 5 is u16: original truncates the value at 021D49B4/49D2.
 */
void func_021D48D8(char *p)
{
    u32 arc;
    void *resource;
    char *palette;
    ((struct Obj00073 *)p)->f54 = func_020457B0(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f58 = func_020457B0(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f50 = func_020457B0(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f3C = (void *)func_020450F0(5, 16, 10, 10, 2, 13, 0);
    ((struct Obj00073 *)p)->f4C = func_0201D7EC(23, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f44 = func_02045B38(0, 2, 23, ((struct Obj00073 *)p)->fC);
    arc = (u32)func_020490F4(29, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 0, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 1, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    resource = func_02049F78((void *)arc, 1, (u32)&palette, ((struct Obj00073 *)p)->fC);
    func_02082D44(((struct Obj13963 *)palette)->fC, p + 0x12c, 0xe0);
    func_02082D44(((struct Obj13963 *)palette)->fC, p + 0x20c, 0xe0);
    func_021D4644((u16 *)(p + 0x20c), data_021D5870, 7);
    func_020307B0(resource);
    ((struct Obj00073 *)p)->f60 = func_02049740((void *)arc, 4, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049990((void *)arc, 9, 4, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049990((void *)arc, 15, 6, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f37C = func_0204A6C8((void *)arc, 5, 0, 1, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f378 = func_0204AC18((void *)arc, 3, 1, 0, 0, 10, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f380 = func_0204AF28((void *)arc, 7, 16, ((struct Obj00073 *)p)->fC);
    func_02049238(arc);
    ((struct Obj00073 *)p)->f5C = func_0201F5DC((void *)5, 11, 0, ((struct Obj00073 *)p)->fC);
    func_02049B40(23, 5, 4, 384, 32, ((struct Obj00073 *)p)->fC);
    func_021D46CC(p);
}







void func_021D4A64(char *p)
{
    Pair pair = d_021D575C;
    func_021D4384(2, (int *)&pair, (Object_021D4384 *)p, (Row *)d_021D5890, (const int *)d_021D5720, (const int *)d_021D5718);
    ((struct Obj10431 *)p)->f40 = func_02051B84((u8 *)d_021D5728, (int)func_021D4630, (int)p, ((struct Obj10431 *)p)->fC);
    ((struct Obj10431 *)p)->f4 = func_021D4C50;
    func_021D5004(p);
    func_021D4244(p, (u32)func_021D4FE4, 0x31b);
}







void func_021D4AD4(char *p)
{
    unsigned ranges;
    func_0201DD68();
    func_021D45E8(p);
    func_02040DA8(5, 1, 0);
    ranges = ((struct Obj02472 *)p)->f5C;
    func_0203FB44(5, (u16)ranges, (u16)(ranges >> 16));
    func_020403F4(5);
    func_020403F4(4);
    func_02045C04(((struct Obj02472 *)p)->f44);
    func_0201D83C(((struct Obj02472 *)p)->f4C);
    func_02045808(((struct Obj02472 *)p)->f54);
    func_02045808(((struct Obj02472 *)p)->f50);
    func_02045808(((struct Obj02472 *)p)->f58);
    func_020452E8(((struct Obj02472 *)p)->f3C);
}







void func_021D4B30(char *p)
{
    if (func_020221A4()) {
        if (((struct Obj13964 *)p)->f8 == 1) {
            if (!func_02026454((void *)func_02012138(((struct Obj13964 *)p)->f354)))
                func_021D4244(p, 0, 0x341);
        } else {
            func_021D4244(p, 0, 0x345);
        }
    }
}







/*
 * evidence: unlabelled ov014 Thumb setter 0x02178118 is filed separately.
 * extent: unit includes tail-call stub 0x021D4BDC and return stub 0x021D4BF0;
 *   two zero padding bytes at 0x021D4BF2 follow the intended code.
 */
void func_021D4B74(char *p)
{
    ((struct Obj06457 *)p)->f38C = 1;
    func_0202208C(0, 0, 0, 0, 6, 1, ((struct Obj06457 *)p)->fC);
    func_02178118(0, 0);
    if (((struct Obj06457 *)p)->f8 == 1 && func_02026454((void *)func_02012138(((struct Obj06457 *)p)->f354)))
        func_02026400((struct Comm *)func_02012138(((struct Obj06457 *)p)->f354));
    func_021D4244(p, (u32)func_021D4B30, 0x35e);
}







void func_021D4BDC(char *p)
{
    func_021D4244(p, (u32)func_021D4B74, 0x36f);
}







void func_021D4BF0(void)
{
}






void func_021D4BF4(char *p)
{
    int i;
    Params args;
    void **base;
    i = ((struct Obj22930 *)p)->f35C;
    args.f00 = 0;
    args.f04 = p;
    args.f08 = (void (*)(void))func_021D4BDC;
    if (i == 3) i = 0;
    else if (i == 4) i = 1;
    base = (void **)(p + 0x390);
    func_0204B92C(base[i], 1);
    func_0204BA00(base[i], (const struct Cmd *)(&args));
    func_0204B9A0(base[i]);
    func_021D4244(p, (u32)func_021D4BF0, 0x390);
}






int func_021D4C50(int value, char *p)
{
    void *obj;
    obj = (void *)func_02012138(((struct Obj05359 *)p)->f354);
    ((struct Obj05359 *)p)->f35C = value;
    switch (value) {
    case 0:
    case 3:
        ((struct Obj22931 *)(*(char * *)&((struct Obj05359 *)p)->f344))->f28 = func_02158630((int)obj);
        ((struct Obj05359 *)p)->f8 = 0;
        func_020061E4(0x73b);
        func_021D4244(p, (u32)func_021D4BF4, 0x3c4);
        break;
    case 1:
    case 4:
        ((struct Obj05359 *)p)->f8 = 1;
        func_020061E4(0x73b);
        func_021D4244(p, (u32)func_021D4BF4, 0x3cd);
        break;
    case 2:
        func_020061E4(0x73c);
        ((struct Obj05359 *)p)->f8 = 2;
        func_021D4244(p, (u32)func_021D4BF4, 0x3d3);
        break;
    }
    return 1;
}




void func_021D4CD8(int i, int value, int force, int mode, Object_021D4240 *p)
{
    if (p->f10[i] && !force) return;
    if (!p->f10[i])
        p->f10[i] = (void *)func_020450F0((int)7, (u8)data_021D58E0[i].f00, (u8)data_021D58E0[i].f04,
            (u8)data_021D58E0[i].f08, data_021D58E0[i].f0c, (int)13, (int)0);
    func_02043B5C(func_02045770(p->f10[i]), 0);
    if (mode) {
        func_02045CAC(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f50);
        func_0201F250(((struct Obj01405 *)p)->f48, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f50);
    } else {
        func_02045CAC(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f54);
    }
    func_0201C7D0(func_02045770(p->f10[i]), 0, 0, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f4C, 0x39e3);
    func_02045334(p->f10[i]);
    func_02045374(p->f10[i]);
}



/*
 * lever: explicit if/else calls preserve the shared stack home and call ordering.
 * tables: original pool maps y=5714, x=5710, rows=5840/5860, extra=5850.
 */
void func_021D4D98(char *p)
{
    int force = 0;
    int scratch = 0;
    int object, mode, count;
    object = func_02012138(((struct Obj00265 *)p)->f354);
    mode = func_02158630(object);
    if (!((struct Obj00265 *)p)->f374) {
        scratch = 0;
        if (func_02026CA0(&scratch) != 30) ((struct Obj00265 *)p)->f374 = 1;
    }
    if (((struct Obj00265 *)p)->f36C != ((struct Obj00265 *)p)->f370) force = 1;
    if (((struct Obj00265 *)p)->f368 != ((struct Obj00265 *)p)->f364) force = 1;
    func_021D4CD8(4, 2, 0, 0, (Object_021D4240 *)p);
    func_021D4CD8(6, 4, 0, 0, (Object_021D4240 *)p);
    func_021D4CD8(8, 12, 0, 0, (Object_021D4240 *)p);
    if (mode == 0) {
        func_0201EFA4(((struct Obj00265 *)p)->f48, 0, ((struct Obj00265 *)p)->f36C, 2, 0, 1);
        func_021D4CD8(5, 3, force, 1, (Object_021D4240 *)p);
        if (((struct Obj00265 *)p)->f364 & 32) func_021D4CD8(7, 5, force, 1, (Object_021D4240 *)p);
        else func_021D4CD8(7, 6, force, 1, (Object_021D4240 *)p);
        if (((struct Obj00265 *)p)->f374) func_021D4CD8(9, 5, force, 1, (Object_021D4240 *)p);
        else func_021D4CD8(9, 6, force, 1, (Object_021D4240 *)p);
    } else {
        func_021D4590(5, (u32)p); func_021D4590(7, (u32)p); func_021D4590(9, (u32)p);
    }
    if (mode == 2 && ((struct Obj00265 *)p)->f128 != func_02158678((void *)object)) ((struct Obj00265 *)p)->f124 = 0;
    if (((struct Obj00265 *)p)->f124 != mode) {
        switch (mode) {
        case 0:
            func_0204B3DC(((struct Obj00265 *)p)->f3A4, 0);
            func_021D45BC(10, (u32)p);
            func_02045CAC(((struct Obj00265 *)p)->f44, 0, ((struct Obj00265 *)p)->f54);
            func_021D44BC(0, (Object_021D44BC *)p, &data_021D5840, data_021D5710, data_021D5714);
            break;
        case 1:
            func_0204B3DC(((struct Obj00265 *)p)->f3A4, 0);
            func_021D45BC(10, (u32)p);
            func_02045CAC(((struct Obj00265 *)p)->f44, 15, ((struct Obj00265 *)p)->f54);
            func_021D44BC(0, (Object_021D44BC *)p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 2:
            count = func_02158678((void *)object);
            ((struct Obj00265 *)p)->f128 = count;
            func_0204B3DC(((struct Obj00265 *)p)->f3A4, 0);
            func_021D45BC(10, (u32)p);
            func_0201EFA4(((struct Obj00265 *)p)->f48, 0, count, 1, 0, 1);
            func_02045CAC(((struct Obj00265 *)p)->f44, 16, ((struct Obj00265 *)p)->f50);
            func_0201F250(((struct Obj00265 *)p)->f48, ((struct Obj00265 *)p)->f54, ((struct Obj00265 *)p)->f50);
            func_021D44BC(0, (Object_021D44BC *)p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 3:
            func_02045CAC(((struct Obj00265 *)p)->f44, 17, ((struct Obj00265 *)p)->f54);
            func_021D44BC(0, (Object_021D44BC *)p, &data_021D5860, data_021D5710, data_021D5714);
            if (func_021586C8(object, *(int *)&((struct Obj00265 *)p)->f54)) {
                func_021D44BC(10, (Object_021D44BC *)p, &data_021D5850, 0, 0);
                func_0204B3DC(((struct Obj00265 *)p)->f3A4, 1);
            }
            break;
        }
        ((struct Obj00265 *)p)->f124 = mode;
    }
    func_02041B6C(7);
}



void func_021D4FE4(char *p) {if(func_020221A4())func_02051C88(((struct Obj00265 *)p)->f40);func_021D503C(p);func_021D4D98(p);}



/*
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
void func_021D5004(char *p) {void *t;t=func_020457B0(100,*(u16 *)(p+12));*(void **)(p+0x328)=t;func_02045CAC(*(void **)(p+0x44),9,t);*(u16 *)(p+0x32c)=0x39e3;*(u32 *)(p+0x330)=1;func_02045808(*(void **)(p+0x328));}



/*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 */
void func_021D503C(char *p)
{
    switch (func_02158630(func_02012138(((struct Obj00265 *)p)->f354))) {
    case 0:
    case 1:
        if (func_0204B898(((struct Obj00265 *)p)->f390) == 20) {
            func_0204B92C(((struct Obj00265 *)p)->f390, 0);
            func_0204B878(((struct Obj00265 *)p)->f390, 12);
        }
        break;
    case 2:
    case 3:
        if (func_0204B898(((struct Obj00265 *)p)->f390) == 12) {
            func_0204B92C(((struct Obj00265 *)p)->f390, 1);
            func_0204B878(((struct Obj00265 *)p)->f390, 20);
        }
        break;
    }
}



void func_021D50B4(char *p,u32 n) {void *q;func_0203D798();q=func_0203CF3C(n);((struct Obj22932 *)(*(char * *)&((struct Obj13965 *)p)->f344))->f10=2;func_02082D44(q,*(char * *)&((struct Obj13965 *)p)->f344+20,6);}


void func_021D50DC(char *p) {u8 buf[6]={0};func_0203D798();((struct Obj22933 *)(*(char * *)&((struct Obj13966 *)p)->f344))->f10=1;func_02082D44(buf,*(char * *)&((struct Obj13966 *)p)->f344+20,6);}


void func_021D5110(char *p)
{
    int index;
    void *record, *text;
    index = func_020107FC((void *)func_0201283C(((struct Obj00208 *)p)->f350));
    if (index != -1) {
        record = (void *)func_0203CF10(index);
        text = func_020457B0(200, ((struct Obj00208 *)p)->fC);
        func_02045994(text, func_0202E930(record), 8);
        if (!func_0204B3F4(((struct Obj00208 *)p)->f3A0)) {
            func_02045994(((struct Obj00208 *)p)->f58, func_0202E930(record), 8);
            func_02043B5C(func_02045770(((struct Obj00208 *)p)->f3C), 0);
            func_0201C7D0(func_02045770(((struct Obj00208 *)p)->f3C), 0, 0, ((struct Obj00208 *)p)->f58, ((struct Obj00208 *)p)->f4C, 0x39e3);
            func_02045334(((struct Obj00208 *)p)->f3C);
            func_02045374(((struct Obj00208 *)p)->f3C);
            func_0204B3DC(((struct Obj00208 *)p)->f3A0, 1);
            func_02041B6C(5);
            func_021D50B4(p, index);
        }
        func_02045808(text);
        func_02028A64((struct SoundSys *)func_02012A30(((struct Obj00208 *)p)->f350));
        if (func_0204B898(((struct Obj00208 *)p)->f39C) == 15)
            func_0204B878(((struct Obj00208 *)p)->f39C, 16);
        if (func_0204B898(((struct Obj00208 *)p)->f394) == 11) {
            func_0204B92C(((struct Obj00208 *)p)->f394, 1);
            func_0204B878(((struct Obj00208 *)p)->f394, 19);
        }
    } else {
        func_02028A70((struct SoundSys *)func_02012A30(((struct Obj00208 *)p)->f350));
        func_0204B3DC(((struct Obj00208 *)p)->f3A0, 0);
        func_02043B5C(func_02045770(((struct Obj00208 *)p)->f3C), 0);
        func_02045334(((struct Obj00208 *)p)->f3C);
        func_021D50DC(p);
        if (func_0204B898(((struct Obj00208 *)p)->f394) == 19) {
            func_0204B92C(((struct Obj00208 *)p)->f394, 0);
            func_0204B878(((struct Obj00208 *)p)->f394, 11);
        }
        if (func_0204B898(((struct Obj00208 *)p)->f39C) == 16)
            func_0204B878(((struct Obj00208 *)p)->f39C, 15);
    }
}


/*
 * extent: zero padding at 0x021D530E; next function at 0x021D5310.
 */
void func_021D5278(Object_021D50DC *p, const char *data, int value, int tag)
{
    int i;
    if (value >= 20 && value <= 27) {
        for (i = 0; i < 16; i++) {
            if (p->f64[i].f08 && !func_0203EFC8((const u8 *)p->f64[i].f00, (const u8 *)(data + 4), 6)) {
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
        for (i = 0; i < 16; i++) {
            if (!p->f64[i].f08) {
                func_02082D44(data + 4, p->f64[i].f00, 6);
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
    }
}


void func_021D5310(u8 *p) { int i; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) --*(u16 *)(p+i*12+108); }


u32 func_021D533C(u8 *p) { int i; int sum; sum=0; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) sum+=*(u16 *)(p+i*12+110); return sum; }


/*
 * leaf: root-claimed sole callback witness for func_021D5370.
 */
void func_021D5368(void)
{
    func_0204A648();
}


/*
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 */
int func_021D5370(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    func_0203064C(1, 31, 0x18000);
    p = func_0203159C(owner, 0x3a8, 31);
    func_02082BCC(p, 0, 0x3a8);
    ((struct Obj00073 *)p)->fC = 31;
    ((struct Obj00073 *)p)->f350 = ((struct Obj13967 *)args)->f4;
    ((struct Obj00073 *)p)->f354 = ((struct Obj13967 *)args)->f0;
    func_0204363C(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj00073 *)p)->fC);
    func_02045088(((struct Obj00073 *)p)->fC);
    func_0201DD60();
    func_020433E0((const struct DispVram *)data_021D58B0);
    display = data_021D5770;
    func_0203FC28((struct DispConfig *)(&display));
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct Cfg *)data_021D5740, (u32)data_021D58B0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f30C = func_0204B100(40, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f310 = func_020056A0((u32)func_021D5368, p, 0);
    func_021D424C(p);
    func_021D48D8(p);
    ((struct Obj00073 *)p)->f48 = func_0201EC74(11, 200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f31C = func_0203101C(((struct Obj00073 *)p)->fC, ((struct Obj00073 *)p)->fC, 1, 0);
    ((struct Obj00073 *)p)->f320 = func_0201C440((void *)(((struct Obj00073 *)p)->fC));
    ((struct Obj00073 *)p)->f340 = func_02027F60(5, 13, *(u32 *)&((struct Obj00073 *)p)->f4C, ((struct Obj00073 *)p)->f320, ((struct Obj00073 *)p)->fC);
    func_0207D63C((void *)0x04001050, 4, 1, 15, 4);
    func_0202208C((void *)4, 1, 1, 0, 6, 1, ((struct Obj00073 *)p)->fC);
    func_020435F4(31);
    func_021D4244(p, (u32)func_021D4A64, 0x6cb);
    *(char * *)&((struct Obj00073 *)p)->f344 = args;
    func_0203D798();
    ((struct Obj22934 *)(*(char * *)&((struct Obj00073 *)p)->f344))->f10 = 1;
    ((struct Obj22935 *)(*(char * *)&((struct Obj00073 *)p)->f344))->fC = ((struct Obj00073 *)p)->f350;
    func_0203D34C(0, ((struct Obj00073 *)p)->fC);
    if (func_0203CD98()) func_02178118((u32)func_021D5278, (u32)p);
    func_020355D8(1);
    return 1;
}


/*
 * extent: two-byte zero alignment at 021D55FA, then next labelled function.
 */
int func_021D5514(void *a, void *b, void *c, char *p)
{
    int result = 1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result = 0;
    }
    if (((struct Obj00208 *)p)->f324) func_02027974(((struct Obj00208 *)p)->f324);
    if (((struct Obj00208 *)p)->f8 != 1) func_021D5110(p);
    func_021D5310((unsigned char *)p);
    func_0204A600();
    if (func_0203CD98()) {
        ((struct Obj00208 *)p)->f368 = ((struct Obj00208 *)p)->f364;
        ((struct Obj00208 *)p)->f364 = func_0201058C((void *)func_0201283C(((struct Obj00208 *)p)->f350));
        ((struct Obj00208 *)p)->f370 = ((struct Obj00208 *)p)->f36C;
        ((struct Obj00208 *)p)->f36C = func_021D533C((u8 *)p);
    }
    func_020310C4(((struct Obj00208 *)p)->f31C);
    func_0201C4E4(((struct Obj00208 *)p)->f320);
    func_02040618(4, 3, ((struct Obj00208 *)p)->f358);
    ((struct Obj00208 *)p)->f358 = ((struct Obj00208 *)p)->f358 - 1;
    if (func_020221A4() && ((struct Obj00208 *)p)->f38C == 0) func_020121CC(((struct Obj00208 *)p)->f354);
    if (func_020221A4() && func_02012204(((struct Obj00208 *)p)->f354)) {
        ((struct Obj00208 *)p)->f8 = 2;
        result = 1;
        func_0202223C(0, 0);
        func_0202223C(1, 0);
    }
    return result;
}
