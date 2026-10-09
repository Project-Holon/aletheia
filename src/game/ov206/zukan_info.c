/*
 * file:     zukan_info.c
 * unit:     yes
 * function: func_021B9DE0, func_021B9E68, func_021BA2CC, func_021BA374, func_021BA4CC, func_021BA4F4, func_021BA550, func_021BA64C, func_021BA6B0, func_021BA7C8, func_021BA814, func_021BA864, func_021BA890, func_021BA934, func_021BA960, func_021BAA08, func_021BAA4C, func_021BACB0, func_021BAF50, func_021BAF7C, func_021BAFC4, func_021BB0E4, func_021BB0FC, func_021BB13C, func_021BB160, func_021BB184, func_021BB214, func_021BB23C, func_021BB2C4, func_021BB2D4, func_021BB304, func_021BB480, func_021BB4E0, func_021BB534, func_021BB79C, func_021BB92C, func_021BB980, func_021BB9E0, func_021BBA7C, func_021BBAB0, func_021BBBD8, func_021BBC04, func_021BBC38, func_021BBC68, func_021BBC9C, func_021BBDA8, func_021BBE34, func_021BBE5C, func_021BC008, func_021BC0AC, func_021BC0B0, func_021BC0B4, func_021BC0B8, func_021BC0CC, func_021BC0E0
 * address:  0x021B9DE0
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F00 0x02017F00 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02041300 0x02041300 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049990 0x02049990 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020493D4 0x020493D4 arm
 *   func_0204932C 0x0204932C arm
 *   func_02062A98 0x02062A98 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0207D658 0x0207D658 arm
 *   func_02040618 0x02040618 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021BC220 0x021BC220 data
 *   func_02030EAC 0x02030EAC arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02006984 0x02006984 thumb
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201AE14 0x0201AE14 thumb
 *   func_0201ADE4 0x0201ADE4 thumb
 *   func_02040588 0x02040588 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204A39C 0x0204A39C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   d_021BC174 0x021BC174 data a1
 *   func_020452E8 0x020452E8 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201AF80 0x0201AF80 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_020A7370 0x020A7370 data
 *   d_021BC110 0x021BC110 data a2
 *   d_021BC11C 0x021BC11C data a2
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204384C  0x0204384C  arm
 *   func_020439A0  0x020439A0  arm
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B604 0x0204B604 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020275E8 0x020275E8 thumb
 *   func_020275EC 0x020275EC thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_0204AA94 0x0204AA94 arm
 *   d_021BC128 0x021BC128 data a2
 *   d_021BC150 0x021BC150 data a1
 *   func_021BC0E4 0x021BC0E4 thumb ov206
 *   tbl_020A1B38 0x020A1B38 data
 *   func_02061CA4 0x02061CA4 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02045B38 0x02045B38 arm
 *   tbl_021BC134 0x021BC134 data
 *   tbl_021BC1C4 0x021BC1C4 data
 *   tbl_021BC184 0x021BC184 data
 *   func_02045C04 0x02045C04 arm
 *   func_02049238 0x02049238 arm
 */
#include "../../matched/include/Obj00022.h"
#include "../../matched/include/Obj25394.h"
#include "../../matched/include/Obj00173.h"
#include "../../matched/include/Obj00316.h"
#include "../../matched/include/Obj14635.h"
#include "../../matched/include/Obj14636.h"
#include "../../matched/include/Obj25395.h"
#include "../../matched/include/Obj25396.h"
#include "../../matched/include/Obj25397.h"
#include "../../matched/include/Obj25398.h"
#include "../../matched/include/Obj00598.h"
#include "../../matched/include/Obj00031.h"
#include "../../matched/include/Obj00551.h"
#include "../../matched/include/Obj08387.h"
#include "../../matched/include/Obj14637.h"
#include "../../matched/include/Obj25402.h"
#include "../../matched/include/Obj08388.h"
#include "../../matched/include/Obj25403.h"
#include "../../matched/include/Obj10886.h"
#include "../../matched/include/Obj00790.h"
#include "../../matched/include/Obj10887.h"
#include "../../matched/include/Obj25404.h"
#include "../../matched/include/Obj14639.h"
#include "../../matched/include/Obj25405.h"
#include "../../matched/include/Obj25407.h"
#include "../../matched/include/Obj02542.h"

#define H(o) (*(unsigned short *)(p + (o)))
#define W(o) (*(int *)(p + (o)))
struct ArcFile;
struct NitroFileHeader;
struct Personal;
struct S;
struct State;
struct Node;
struct PrintSys;
struct Actor;
struct CharBuf;
struct Descriptor;
struct Bmp;
struct StrObj;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct Cfg;
struct Obj020437AC;
struct Obj;
struct Vec2;
struct S_021BB79C;
struct Rec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef short s16;

struct Pt { s16 x; s16 y; };

typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; } State_021BA7C8;

typedef struct { char pad[0x44]; int state; char pad48[4]; unsigned char a,b,c; char pad4f[0x1b4-0x4f]; int delta; } State_021BA814;

struct Tab16 { u8 b[16]; };

typedef enum { ZERO } Zero;

typedef struct {
    unsigned short f0;
    char pad2[0x4d - 2];
    unsigned char f4d;
    char pad4e[0x8c - 0x4e];
    int f8c;
    int f90;
} Ent_021BA934;

typedef struct { short x,y,z,w; } Pos_021BA934;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect_021BA934;

typedef struct {
    unsigned short f0;
    char pad02[0x18 - 2];
    int f18;
    int f1c;
    char pad20[4];
    void *f24;
    char pad28[0xb8 - 0x28];
    int m[2][2];
    void *fc8;
    void *fcc;
    char padd0[0xe0 - 0xd0];
    int fe0;
    int fe4;
    void *a[0x11];
    void *b[0x11];
    unsigned char f170;
    unsigned char f171;
    char pad172[0x1d0 - 0x172];
    void *f1d0;
} Ent_021BB304;

typedef struct {
    short a, b, c;
    unsigned char d, e;
} Rect_021BB534;

typedef struct {
    short x, y;
} Pos_021BB534;

typedef struct {
    short x, y, z, w;
} Rect4;

typedef struct {
    unsigned short f0;
    char pad02[0x18 - 2];
    int f18;
    int f1c;
    char pad20[4];
    void *f24;
    char pad28[0xb8 - 0x28];
    int m[2][2];
    void *fc8;
    void *fcc;
    void *n[2][2];
    int fe0;
    int fe4;
    void *a[0x11];
    void *b[0x11];
    unsigned char f170;
    unsigned char f171;
    char pad172[0x1b4 - 0x172];
    int f1b4;
    char pad1b8[0x1d0 - 0x1b8];
    void *f1d0;
} Ent_021B9DE0;

typedef struct {
    short a, b, c;
    unsigned char d, e;
} Rect;

typedef struct {
    short x, y;
} Pos;

typedef struct {
    unsigned char a, b;
} Tile;

typedef struct {
    char pad[0x14];
    int f14;
} Blob;

typedef struct {
    unsigned short f0;
    char pad02[0x18 - 2];
    int f18;
    int f1c;
    char pad20[4];
    void *f24;
    char pad28[0xb8 - 0x28];
    int m[2][2];
    void *fc8;
    void *fcc;
    void *n[2][2];
    int fe0;
    int fe4;
    void *a[0x11];
    void *b[0x11];
    unsigned char f170;
    unsigned char f171;
    char pad172[0x1b4 - 0x172];
    int f1b4;
    char pad1b8[0x1c4 - 0x1b8];
    void *f1c4;
    char pad1c8[0x1d0 - 0x1c8];
    void *f1d0;
} Ent_021BB79C;

struct State_021BB79C { char pad[0xb8]; int ids[3][2]; void *objects[2][2]; int selected,mode; };

typedef enum Flag { FLAG_ZERO=0,FLAG_ONE=1 } Flag;

struct State_021BB9E0 { u16 heap; char pad2[26]; int flag; char pad20[0x168]; unsigned array[2],index; char pad194[0x44]; unsigned owner; };

typedef short s16_021BB79C;

struct Point {
    s16_021BB79C x;
    s16_021BB79C y;
    u16 f4;
    u8 f6;
    u8 f7;
};

typedef struct S_021BBAB0 {
    u16 id;
    char pad2[0x1a];
    int f1c;
    char pad20[4];
    u32 f24;
    char pad28[0x174 - 0x28];
    u32 a174[2];
    u32 f17c;
    u32 f180;
    u32 f184;
    u32 a188[2];
    char pad190[0x1b4 - 0x190];
    u32 f1b4;
    char pad1b8[0x1d8 - 0x1b8];
    u32 f1d8;
    u32 f1dc;
} S_021BBAB0;

typedef struct S_021BBBD8 {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S_021BBBD8;

typedef struct S_021BB79C {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S_021BB79C;

typedef struct S_021BBC38 {
    char pad0[8];
    int f8;
    u16 fc;
    u16 fe;
    char pad10[0xd0];
    int fe0;
    char pad[0x190 - 0xe4];
} S_021BBC38;

typedef struct S_021BBC9C {
    char pad0[0x1c];
    int f1c;
    char pad20[0x194 - 0x20];
    u16 phase;
    u16 pal[5];
    u16 a[5];
    u16 b[5];
} S_021BBC9C;

struct State {
    char pad[0xb8]; int ids[3][2]; void *objects[2][2]; int selected,mode;
    char padE8[0x44]; void *other[17]; u8 a,b; char pad172[0x16]; void *last[2]; int index;
};

typedef struct S_021BBE34 {
    char pad0[8];
    int f8;
    char pad0c[0xac - 0xc];
    void *last[2];
    int index;
} S_021BBE34;

typedef struct S_021BBE5C {
    u16 id;
    char pad2[0xa];
    u16 fc;
    u16 fe;
    char pad10[0x1b8 - 0x10];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S_021BBE5C;

typedef struct S {
    char pad0[0x1b8];
    void *g[3];
    void *w[7];
    void *objs[35];
    void *x;
    void *a[16];
} S;

typedef signed char s8;

typedef signed short s16_021BC008;

extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern u8 func_02017F00(void *);
extern unsigned func_02017EAC(void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_0201C440(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204932C(struct ArcFile *arc, u32 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern u32 func_020307B0(void *p);
extern void *func_020056A0(void (*cb)(int, char *), void *arg, int pri);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020409B4(u32 layer);
extern void func_02030EAC(struct Node *n);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_02006984(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_0204B53C(const struct Actor *actor, struct Pt *out);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern void func_0201AE14(void *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u32 c, u32 d, u32 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern unsigned int func_020452E8(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern unsigned int func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern int func_0202D81C(int,int,int,int,int,int,int,int,int,unsigned short);
extern int func_0202D7D8(int,int,int,int,int,int,int,int,unsigned short,unsigned short);
extern int func_0202D898(int,int,int,int,int,int,int,int,unsigned short);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_020275E8(void);
extern u8 func_020275EC(int i);
extern u32 func_020275F8(u32 a);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(void *, Pos_021BB534 *, unsigned short);
extern void *func_02049DF4(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned short a4);
extern void func_0204AA94(int a, void *b, unsigned int c, int d, int e);
extern u32 func_021BC0E4(u32 a, u32 b);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern u32 func_020275E4(void);
extern int func_0202D7C8(int a0);
extern void *func_020490F4(u32 id, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02049238(void *);
void *func_021B9DE0(u16 heap,void *mon,unsigned a2,unsigned a3,unsigned a4,unsigned a5,u8 a6,unsigned a7,unsigned a8,unsigned a9,unsigned a10,unsigned a11,unsigned a12);
void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);
void func_021BA2CC(char *p);
void func_021BA374(char *p);
void func_021BA4CC(char *p);
void func_021BA4F4(char *p);
void func_021BA514(char *p);
void func_021BA51C(char *p);
int func_021BA524(char *p);
int func_021BA534(char *p);
void func_021BA544(char *p);
void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
void func_021BA64C(char *p,int mode);
void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
void func_021BA7C8(State_021BA7C8 *p);
void func_021BA814(State_021BA814 *p);
void func_021BA864(int unused, char *p);
void func_021BA890(char *p);
void func_021BA934(char *p);
void func_021BA960(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion);
void func_021BAA08(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion);
void func_021BAA4C(char *p);
void func_021BACB0(char *p, int idx);
void func_021BAF50(char *p);
void func_021BAF7C(char *p);
void func_021BAFC4(Ent_021BA934 *e);
void func_021BB0E4(char *p);
void func_021BB0FC(void *obj);
void func_021BB13C(void *a0, void *a1, void *a2, void *a3);
void func_021BB160(char *p, int i);
void func_021BB184(char *p,int index);
void func_021BB214(char *p, int i);
void func_021BB23C(char *p,int x,int y,int index);
void func_021BB2C4(char *p, int i);
void func_021BB2D4(char *p);
void func_021BB304(Ent_021BB304 *p);
void func_021BB480(char *p);
void func_021BB4E0(char *p,int mode,int which);
void func_021BB534(Ent_021B9DE0 *p, unsigned x, unsigned y, int row);
void func_021BB79C(Ent_021BB79C *p, unsigned x, unsigned y, int z, int row);
void func_021BB92C(char *p, int index);
void func_021BB980(struct State_021BB79C *p);
void func_021BB9E0(struct State_021BB9E0 *p);
void func_021BBA7C(char *p);
void func_021BBAB0(S_021BBAB0 *p, u32 a, u32 b, u32 idx);
void func_021BBBD8(S_021BBBD8 *p, int i);
void func_021BBC04(S_021BB79C *p);
void func_021BBC38(S_021BBC38 *p);
void func_021BBC68(S_021BBC38 *p, int v);
s32 func_021BBC9C(S_021BBC9C *p);
void func_021BBDA8(struct State *p, int v);
void func_021BBE34(S_021BBE34 *p, int v);
void func_021BBE5C(S_021BBE5C *p);
void func_021BC008(S *p);
u32 func_021BC0AC(void);
int func_021BC0B0(int v);
int func_021BC0B4(int a0);
int func_021BC0B8(int v);
int func_021BC0CC(int v);
u32 func_021BC0E0(void);
extern const char d_021BC220[];
extern const struct Tab16 d_021BC174;
extern void *d_020A7370;
extern const unsigned short d_021BC110[];
extern const unsigned short d_021BC11C[];
extern const unsigned short d_021BC128[];
extern const Tile d_021BC150[];
extern s16_021BB79C tbl_020A1B38[];
extern u32 tbl_021BC134[];
extern u16 tbl_021BC1C4[];
extern u32 tbl_021BC184[];



void *func_021B9DE0(u16 heap,void *mon,unsigned a2,unsigned a3,unsigned a4,unsigned a5,u8 a6,unsigned a7,unsigned a8,unsigned a9,unsigned a10,unsigned a11,unsigned a12)
{
    u16 species,form,move;
    u8 gender;
    species=(u16)func_02017E1C(mon,5,0);
    form=(u16)func_02017E1C(mon,111,0);
    gender=func_02017F00(mon);
    move=(u16)func_02017EAC(mon);
    return func_021B9E68(heap,species,form,gender,move,func_02017E1C(mon,0,0),a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);
}






static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    *(volatile u16 *)0x04000040 = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    *(volatile u16 *)0x04000044 = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}






static inline void G2_SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04000048 = (u16)tmp;
}






static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}






/*
 * note: a3 is u16 here (u16 field, strh); the matched caller ov206_func_021B9DE0 declares it unsigned.
 */
void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9,
                    u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16)
{
    char *p;
    void *h;
    void *buf;
    void *res;
    char *data;
    u8 i;
    u8 k;
    int x;
    int y;
    u32 hh;

    p = func_02030734(heap, 0x2b4, 0, d_021BC220, 0x42f);
    func_02082BCC(p, 0, 0x2b4);
    ((struct Obj00022 *)p)->f0 = heap;
    ((struct Obj00022 *)p)->fC = a1;
    ((struct Obj00022 *)p)->fE = a2;
    ((struct Obj00022 *)p)->f10 = a3;
    ((struct Obj00022 *)p)->f12 = a4;
    ((struct Obj00022 *)p)->f14 = a5;
    ((struct Obj00022 *)p)->f4 = a6;
    ((struct Obj00022 *)p)->f8 = a7;
    ((struct Obj00022 *)p)->f18 = a8;
    ((struct Obj00022 *)p)->f1C = a9;
    ((struct Obj00022 *)p)->f20 = a10;
    ((struct Obj00022 *)p)->f24 = a11;
    ((struct Obj00022 *)p)->f28 = a12;
    ((struct Obj00022 *)p)->f2C = (void *)func_0201C440((void *)(((struct Obj00022 *)p)->f0));
    *(u32 *)&((struct Obj00022 *)p)->f1B8 = a14;
    *(u32 *)&((struct Obj00022 *)p)->f1BC = a15;
    *(u32 *)&((struct Obj00022 *)p)->f1C0 = a16;
    if (((struct Obj00022 *)p)->f1C == 0) {
        ((struct Obj00022 *)p)->f48 = 0;
        ((struct Obj00022 *)p)->f4C = 3;
        ((struct Obj00022 *)p)->f4D = 2;
        ((struct Obj00022 *)p)->f4E = 0;
    } else {
        ((struct Obj00022 *)p)->f48 = 4;
        ((struct Obj00022 *)p)->f4C = 7;
        ((struct Obj00022 *)p)->f4D = 6;
        ((struct Obj00022 *)p)->f4E = 4;
    }
    func_0204047C(((struct Obj00022 *)p)->f4C, ((struct Obj00022 *)p)->f20);
    func_0204047C(((struct Obj00022 *)p)->f4D, (u8)(((struct Obj00022 *)p)->f20 + 1));
    func_0204047C(((struct Obj00022 *)p)->f4E, (u8)(((struct Obj00022 *)p)->f20 + 2));
    ((struct Obj00022 *)p)->f38 = 0;
    ((struct Obj00022 *)p)->f39 = 0;
    switch (((struct Obj00022 *)p)->f18) {
    case 0:
        ((struct Obj00022 *)p)->f54 = 0;
        break;
    case 1:
        ((struct Obj00022 *)p)->f54 = 5;
        break;
    case 2:
        ((struct Obj00022 *)p)->f54 = 7;
        break;
    }
    ((struct Obj00022 *)p)->f58 = 0;
    ((struct Obj00022 *)p)->f5C = 0;
    ((struct Obj00022 *)p)->f60 = 0;
    ((struct Obj00022 *)p)->f64 = 0;
    ((struct Obj00022 *)p)->f194 = 0;
    if (((struct Obj00022 *)p)->f18 == 2 && ((struct Obj00022 *)p)->f1C == 0) {
        ((struct Obj00022 *)p)->f1B4 = -0x18;
    } else {
        ((struct Obj00022 *)p)->f1B4 = 0;
    }
    func_021BBE5C((S_021BBE5C *)((struct S *)p));
    hh = (u16)func_0201AE1C(((struct Obj00022 *)p)->f26C, 0x20);
    if (((struct Obj00022 *)p)->fE >= hh) ((struct Obj00022 *)p)->fE = 0;
    h = ((struct Obj00022 *)p)->f1C4;
    func_02049B68(h, 9, ((struct Obj00022 *)p)->f48, 0, 0x60, ((struct Obj00022 *)p)->f0);
    ((struct Obj00022 *)p)->f30 = func_02049740(h, 0x19, ((struct Obj00022 *)p)->f4D, 0x1000, 0, ((struct Obj00022 *)p)->f0);
    func_020498F4(h, 0x28, ((struct Obj00022 *)p)->f4D, (u16)((struct Obj00022 *)p)->f30, 0x800, 0, ((struct Obj00022 *)p)->f0);
    ((struct Obj00022 *)p)->f34 = func_02049740(h, 0x19, ((struct Obj00022 *)p)->f4E, 0x1000, 0, ((struct Obj00022 *)p)->f0);
    func_020498F4(h, 0x1f, ((struct Obj00022 *)p)->f4E, (u16)((struct Obj00022 *)p)->f34, 0x800, 0, ((struct Obj00022 *)p)->f0);
    ((struct Obj00022 *)p)->f40 = 0;
    ((struct Obj00022 *)p)->f44 = 0;
    if (((struct Obj00022 *)p)->f18 == 2 && ((struct Obj00022 *)p)->f1C == 1) {
        func_02041300(((struct Obj00022 *)p)->f4D, 0, 0, 0, 0x20, 3, 0x11);
        h = ((struct Obj00022 *)p)->f1C4;
        func_02049BDC(h, 2, ((struct Obj00022 *)p)->f48, 0, 0x80, 0x40, ((struct Obj00022 *)p)->f0);
        ((struct Obj00022 *)p)->f3C = func_02049740(h, 0xc, ((struct Obj00022 *)p)->f4E, 0x2000, 0, ((struct Obj00022 *)p)->f0);
        ((struct Obj00022 *)p)->f40 = 1;
        func_02049990(h, 0x24, ((struct Obj00022 *)p)->f4E, 0x400, (u16)((struct Obj00022 *)p)->f3C, 0x800, 0, ((struct Obj00022 *)p)->f0);
        func_020413B0(((struct Obj00022 *)p)->f4E, 0, 0x20, 0x20, 0x15, 4);
        func_020413B0(((struct Obj00022 *)p)->f4E, 0, 0x35, 0x20, 3, 5);
    }
    h = ((struct Obj00022 *)p)->f1C4;
    buf = func_02030734(((struct Obj00022 *)p)->f0, func_020493D4(h, 9), 0, d_021BC220, 0x4f7);
    func_0204932C(h, 9, buf);
    func_02062A98(buf, &res);
    data = *(char * *)&((struct Obj25394 *)res)->fC;
    for (i = 0; i < 5; i++) {
        *(u16 *)(p + i * 2 + 0x1a0) = *(u16 *)(data + i * 2 + 0x22);
        *(u16 *)(p + i * 2 + 0x1aa) = *(u16 *)(data + i * 2 + 0x42);
    }
    func_020307B0(buf);
    func_021BAFC4((Ent_021BA934 *)p);
    func_021BB0FC(p);
    ((struct Obj00022 *)p)->f50 = func_020056A0(func_021BA864, p, 1);
    func_021BB304((Ent_021BB304 *)p);
    func_021BB9E0((struct State_021BB9E0 *)((struct State *)p));
    if (((struct Obj00022 *)p)->f18 == 0 || ((struct Obj00022 *)p)->f18 == 2) {
        func_021BA890(p);
        func_021BBC38((S_021BBC38 *)((struct S *)p));
    }
    for (k = 0; k < 2; k++) {
        *(int *)(p + k * 4 + 0xac) = 0;
    }
    ((struct Obj00022 *)p)->fB4 = 0;
    switch (((struct Obj00022 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + ((struct Obj00022 *)p)->f1B4)), (void *)(((struct Obj00022 *)p)->fB4));
    if (((struct Obj00022 *)p)->f18 == 0) {
        ((struct Obj00022 *)p)->f68 = 0x88;
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x2000;
        G2_SetWnd0Position(0, 8, 100, ((struct Obj00022 *)p)->f68);
        G2_SetWnd0InsidePlane(0x1f, 1);
        G2_SetWndOutsidePlane(0x1f, 0);
        func_0207D658((u32)((volatile u16 *)0x04000050), 0x10, -0x10);
    }
    func_02040618(((struct Obj00022 *)p)->f4D, 3, -((struct Obj00022 *)p)->f1B4);
    func_02040618(((struct Obj00022 *)p)->f4E, 3, -((struct Obj00022 *)p)->f1B4);
    func_02040618(((struct Obj00022 *)p)->f4C, 3, -((struct Obj00022 *)p)->f1B4);
    func_020409B4(((struct Obj00022 *)p)->f4D);
    func_020409B4(((struct Obj00022 *)p)->f4E);
    return p;
}






void func_021BA2CC(char *p)
{
    u8 i;
    func_021BA814((State_021BA814 *)p);
    ((struct Obj00173 *)p)->f44=0;
    for(i=0;i<2;i++) func_021BB160(p,i);
    if(((struct Obj00173 *)p)->f18==2) func_021BA4CC(p);
    func_021BBA7C(p);
    func_021BB480(p);
    func_02030EAC(((struct Obj00173 *)p)->f50);
    func_021BB0E4(p);
    if(((struct Obj00173 *)p)->f40!=0) {
        func_0203FB44(((struct Obj00173 *)p)->f4E,(u16)((struct Obj00173 *)p)->f3C,(u16)(((struct Obj00173 *)p)->f3C>>16));
        ((struct Obj00173 *)p)->f40=0;
    }
    func_0203FB44(((struct Obj00173 *)p)->f4E,(u16)((struct Obj00173 *)p)->f34,(u16)(((struct Obj00173 *)p)->f34>>16));
    func_0203FB44(((struct Obj00173 *)p)->f4D,(u16)((struct Obj00173 *)p)->f30,(u16)(((struct Obj00173 *)p)->f30>>16));
    func_021BC008((struct S *)p);
    func_0201C6EC(((struct Obj00173 *)p)->f2C);
    func_0201C4C0(((struct Obj00173 *)p)->f2C);
    func_020307B0(p);
}






void func_021BA374(char *p)
{
    if (((struct Obj00316 *)p)->f18 == 0) func_021BBC9C((S_021BBC9C *)((struct S *)p));
    ((struct Obj00316 *)p)->f64 += 1;
    if (((struct Obj00316 *)p)->f64 == 4) {
        ((struct Obj00316 *)p)->f39 |= 1;
        ((struct Obj00316 *)p)->f64 = 0;
    }
    switch (((struct Obj00316 *)p)->f54) {
    case 0: case 6: case 7: break;
    case 1:
        ((struct Obj00316 *)p)->f60 += 1;
        if (((struct Obj00316 *)p)->f60 == 15) ((struct Obj00316 *)p)->f54 = 2;
        break;
    case 2: {
        int v = ((struct Obj00316 *)p)->f68 - 1;
        ((struct Obj00316 *)p)->f68 = v;
        *(volatile u16 *)0x04000040 = 100;
        *(volatile u16 *)0x04000044 = (u16)(((8 << 8) & 0xFF00) | (v & 0xFF));
        if (((struct Obj00316 *)p)->f68 == 16) {
            *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
            func_0207D658((u32)((volatile u16 *)0x04000050), 0x10, 0);
            func_02006984(((struct Obj00316 *)p)->fC, ((struct Obj00316 *)p)->fE, 0x40, 0, 0, 0, 0, 0);
            ((struct Obj00316 *)p)->f54 = 3;
        }
        break;
    }
    case 3:
        if (((struct Obj00316 *)p)->f58 != 0) ((struct Obj00316 *)p)->f54 = 4;
        break;
    case 4: {
        struct Pt pt;
        int fx = 0;
        int fy = 0;
        void *obj = *(void **)(p + ((struct Obj00316 *)p)->fB4 * 4 + 0xac);
        func_0204B53C(obj, &pt);
        pt.x += 1;
        pt.y += 1;
        if (pt.x > 0x80) { pt.x = 0x80; fx = 1; }
        if (pt.y > 0x48) { pt.y = 0x48; fy = 1; }
        func_0204B528(*(void **)(p + ((struct Obj00316 *)p)->fB4 * 4 + 0xac), &pt);
        if (fx && fy) ((struct Obj00316 *)p)->f54 = 6;
        break;
    }
    case 5:
        if (((struct Obj00316 *)p)->f5C != 0) {
            func_02006984(((struct Obj00316 *)p)->fC, ((struct Obj00316 *)p)->fE, 0x40, 0, 0, 0, 0, 0);
            ((struct Obj00316 *)p)->f54 = 6;
        }
        break;
    }
    if (((struct Obj00316 *)p)->f18 == 0 || ((struct Obj00316 *)p)->f18 == 2) func_021BAF7C(p);
    func_0201C4E4(((struct Obj00316 *)p)->f2C);
}






void func_021BA4CC(char *p)
{
    func_021BAF50(p);
    func_021BA934(p);
    func_021BBBD8((S_021BBBD8 *)((struct S *)p), ((struct Obj00173 *)p)->f190);
    func_021BB92C(p,((struct Obj00173 *)p)->fE0);
}






void func_021BA4F4(char *p)
{
    func_021BAF50(p);
    func_021BBBD8((S_021BBBD8 *)((struct S *)p), ((struct Obj14635 *)p)->f190);
    func_021BB92C(p,((struct Obj14635 *)p)->fE0);
}






void func_021BA514(char *p)
{
    ((struct Obj25395 *)p)->f58=1;
}






void func_021BA51C(char *p)
{
    ((struct Obj25396 *)p)->f5C=1;
}






int func_021BA524(char *p)
{
    int result=0;
    if(((struct Obj25397 *)p)->f54==4) result=1;
    return result;
}






int func_021BA534(char *p)
{
    int result=0;
    if(((struct Obj25398 *)p)->f54==6) result=1;
    return result;
}






void func_021BA544(char *p)
{
    if(((struct Obj14636 *)p)->f54==0) ((struct Obj14636 *)p)->f54=1;
}





void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6)
{
    int x;
    u32 h;
    int y;
    if (((struct Obj00598 *)p)->f26C != 0) func_0201AE14(((struct Obj00598 *)p)->f26C);
    ((struct Obj00598 *)p)->f26C = func_0201ADE4(a1, a2, ((struct Obj00598 *)p)->f0);
    if (((struct Obj00598 *)p)->fB4 != 0) ((struct Obj00598 *)p)->fB4 = 0; else ((struct Obj00598 *)p)->fB4 = 1;
    if (((struct Obj00598 *)p)->fE0 != 0) ((struct Obj00598 *)p)->fE0 = 0; else ((struct Obj00598 *)p)->fE0 = 1;
    if (((struct Obj00598 *)p)->f190 != 0) ((struct Obj00598 *)p)->f190 = 0; else ((struct Obj00598 *)p)->f190 = 1;
    func_021BB160(p, ((struct Obj00598 *)p)->fB4);
    func_021BA4F4(p);
    ((struct Obj00598 *)p)->fC = a1;
    ((struct Obj00598 *)p)->fE = a2;
    ((struct Obj00598 *)p)->f10 = a3;
    ((struct Obj00598 *)p)->f12 = a4;
    ((struct Obj00598 *)p)->f14 = a5;
    ((struct Obj00598 *)p)->f8 = a6;
    h = (u16)func_0201AE1C(((struct Obj00598 *)p)->f26C, 0x20);
    if (((struct Obj00598 *)p)->fE >= h) ((struct Obj00598 *)p)->fE = 0;
    func_021BB0FC(p);
    func_021BBC38((S_021BBC38 *)((struct S *)p));
    switch (((struct Obj00598 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + ((struct Obj00598 *)p)->f1B4)), (void *)(((struct Obj00598 *)p)->fB4));
    func_021BBE34((S_021BBE34 *)((struct S *)p), (((struct Obj00598 *)p)->f44 != 0) ? 0 : 1);
}





void func_021BA64C(char *p,int mode)
{
    if (((struct Obj00031 *)p)->fE0) ((struct Obj00031 *)p)->fE0=0;
    else ((struct Obj00031 *)p)->fE0=1;
    func_021BAF50(p);
    func_021BB92C(p,((struct Obj00031 *)p)->fE0);
    func_021BB4E0(p,mode,((struct Obj00031 *)p)->fE0);
    func_021BBDA8((struct State *)p,((struct Obj00031 *)p)->f8);
    if(mode==6 || ((struct Obj00031 *)p)->fC>493) func_021BAA4C(p);
    else func_021BACB0(p,mode);
}





void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7)
{
    int x;
    u32 h;
    int y;
    if (((struct Obj00551 *)p)->f26C != 0) func_0201AE14(((struct Obj00551 *)p)->f26C);
    ((struct Obj00551 *)p)->f26C = func_0201ADE4(a1, a2, ((struct Obj00551 *)p)->f0);
    if (((struct Obj00551 *)p)->fB4 != 0) ((struct Obj00551 *)p)->fB4 = 0; else ((struct Obj00551 *)p)->fB4 = 1;
    if (((struct Obj00551 *)p)->fE0 != 0) ((struct Obj00551 *)p)->fE0 = 0; else ((struct Obj00551 *)p)->fE0 = 1;
    if (((struct Obj00551 *)p)->f190 != 0) ((struct Obj00551 *)p)->f190 = 0; else ((struct Obj00551 *)p)->f190 = 1;
    func_021BB160(p, ((struct Obj00551 *)p)->fB4);
    func_021BA4F4(p);
    ((struct Obj00551 *)p)->fC = a1;
    ((struct Obj00551 *)p)->fE = a2;
    ((struct Obj00551 *)p)->f10 = a3;
    ((struct Obj00551 *)p)->f12 = a4;
    ((struct Obj00551 *)p)->f14 = a5;
    ((struct Obj00551 *)p)->f8 = a6;
    h = (u16)func_0201AE1C(((struct Obj00551 *)p)->f26C, 0x20);
    if (((struct Obj00551 *)p)->fE >= h) ((struct Obj00551 *)p)->fE = 0;
    func_021BB0FC(p);
    if (a7 == 6 || ((struct Obj00551 *)p)->fC > 0x1ed) func_021BBC38((S_021BBC38 *)((struct S *)p));
    else func_021BBC68((S_021BBC38 *)((struct S *)p), a7);
    switch (((struct Obj00551 *)p)->f18) {
    case 0:
    case 2:
        x = 0x32;
        y = 0x48;
        break;
    case 1:
        x = 0x80;
        y = 0x48;
        break;
    }
    func_021BB13C(p, (void *)x, (void *)((u16)(y + ((struct Obj00551 *)p)->f1B4)), (void *)(((struct Obj00551 *)p)->fB4));
    func_021BBE34((S_021BBE34 *)((struct S *)p), (((struct Obj00551 *)p)->f44 != 0) ? 0 : 1);
}





void func_021BA7C8(State_021BA7C8 *p)
{
    if (!p->state) {
        p->state = 1;
        func_02040588(p->a, 0);
        func_02040588(p->b, 0);
        func_02041EE4(p->c, 3, -256);
        func_021BBE34((S_021BBE34 *)((struct S *)p), p->state == 0);
    }
}





void func_021BA814(State_021BA814 *p)
{
    if (p->state) {
        p->state = 0;
        func_02040588(p->a, 1);
        func_02040588(p->b, 1);
        func_02041EE4(p->c, 3, -p->delta);
        func_021BBE34((S_021BBE34 *)((struct S *)p), p->state == 0);
    }
}






void func_021BA864(int unused, char *p)
{
    if (((struct Obj08387 *)p)->f39 & 1)
    {
        func_02041EE4(((struct Obj08387 *)p)->f4E, 1, 1);
    }
    ((struct Obj08387 *)p)->f38 = 0;
    ((struct Obj08387 *)p)->f39 = 0;
}





void func_021BA890(char *p)
{
    struct Tab16 tab;
    int out;
    int r6;
    int i;
    ((struct Obj00022 *)p)->f2B0 = (int)func_0204A39C(((struct Obj00022 *)p)->f1C8, 0, 0, ((struct Obj00022 *)p)->f0, (u32 *)(&out));
    r6 = 0;
    if (*(int *)&((struct Obj00022 *)p)->f1C != 0) r6 = 4;
    func_02049B68(((struct Obj00022 *)p)->f1CC, 5, r6, 0x60, 0x20, ((struct Obj00022 *)p)->f0);
    tab = d_021BC174;
    for (i = 0; i < 4; i++) {
        *(void **)(p+i*4+0x6c) = (void *)func_020450F0(((struct Obj00022 *)p)->f4C, tab.b[i*4], tab.b[i*4+1], tab.b[i*4+2], tab.b[i*4+3], 3, 1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770(*(void **)(p+i*4+0x6c))), 0);
    }
    for (i = 0; i < 4; i++) {
        *(int *)(p+i*4+0x7c) = 1;
    }
}







void func_021BA934(char *p)
{
    int i;
    func_0201C6EC(((struct Obj00173 *)p)->f2C);
    for(i=0;i<4;i++){
        *(int *)(p+i*4+124)=1;
        func_020452E8(*(void **)(p+i*4+108));
    }
    func_020307B0(((struct Obj00173 *)p)->f2B0);
}







void func_021BA960(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int buffer=(int)func_02045770((struct Descriptor *)window);
    unsigned short x;
    int text;
    if(expansion) {
        text=(int)func_020457B0(128,heap);
        func_0201F250((struct WordSet *)expansion,(void *)text,(void *)input);
    } else text=input;
    switch(alignment) {
    case 0: x=right; break;
    case 1: {
        unsigned short width=func_0201D304((struct StrObj *)text,font,0);
        x=right-width;
        break;
    }
    case 2: {
        unsigned short width=func_0201D304((struct StrObj *)text,font,0);
        x=(func_020437DC((const struct Bmp *)buffer)-width)/2;
        break;
    }
    }
    func_0201C724(printer,(int)buffer,(short)x,(short)y,(int)text,(int)font,color);
    if(expansion) func_02045808((struct U16Vec *)text);
}







void func_021BAA08(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int text=(int)func_02045EC0(bank,message);
    func_021BA960(heap,window,printer,font,text,x,y,color,alignment,expansion);
    func_02045808((struct U16Vec *)text);
}







/*
 * note: *(p+0x1e0) is read first into a local, so 0x1e0 is the first constant built and the
 *   0x1e4..0x1f0 and 0x2b0 offsets derive from it. The last loop stores the constant 0 (a copy of k's 0).
 */
void func_021BAA4C(char *p)
{
    int l2c = ((struct Obj00031 *)p)->f1E0;
    int l28 = ((struct Obj00031 *)p)->f1E4;
    int l24 = ((struct Obj00031 *)p)->f1E8;
    int l20 = ((struct Obj00031 *)p)->f1EC;
    int l1c = ((struct Obj00031 *)p)->f1F0;
    u16 t = ((struct Obj00031 *)p)->fC;
    u16 i = 0;
    u32 h2;
    u16 r7;
    u16 r6;
    u16 m;
    void *name;
    u8 k;
    if (((struct Obj00031 *)p)->fE != 0) {
        u16 *arr = *(u16 * *)&((struct Obj00031 *)p)->f2B0;
        do {
            t = arr[t];
            if (t == 0) break;
            i = (u16)(i + 1);
        } while (i != ((struct Obj00031 *)p)->fE);
    }
    if (t == 0) t = ((struct Obj00031 *)p)->fC;
    if (((struct Obj00031 *)p)->f18 != 2) {
        func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f6C, (struct MsgBank *)l2c, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, 0x90, 0, 5, 0x3c40, 2, 0);
    }
    r7 = ((struct Obj00031 *)p)->fC;
    if (((struct Obj00031 *)p)->f4 == 0) {
        u16 *tab = func_0201AF80(((struct Obj00031 *)p)->f0, 0);
        r7 = tab[((struct Obj00031 *)p)->fC];
        func_020307B0(tab);
    }
    if (r7 != 0x3e7) {
        h2 = (u32)func_0201EC64(((struct Obj00031 *)p)->f0);
        func_0201EFA4((struct WordSet *)h2, 0, r7, 3, 2, 1);
        func_021BA960(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f270, 8, 5, 0x3e7 + 0x59, 0, h2);
        func_0201ED04((struct WordSet *)h2);
    } else {
        func_021BA960(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f274, 8, 5, 0x3e7 + 0x59, 0, 0);
    }
    name = func_02045EC0(d_020A7370, ((struct Obj00031 *)p)->fC);
    func_0201C724((void *)(((struct Obj00031 *)p)->f2C), (u32)func_02045770(((struct Obj00031 *)p)->f70), 0x30, 5, (u32)name, ((struct Obj00031 *)p)->f28, 0x440);
    func_02045808(name);
    m = 0;
    if (((struct Obj00031 *)p)->f8 != 0) m = ((struct Obj00031 *)p)->fC;
    func_021BAA08(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (struct MsgBank *)l28, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, m, 0, 0x16, 0x440, 2, 0);
    func_021BA960(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f278, 0, 4, 0x440, 0, 0);
    func_021BA960(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f27C, 0, 0x14, 0x440, 0, 0);
    r6 = 0;
    if (((struct Obj00031 *)p)->f8 != 0) r6 = t;
    func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (struct MsgBank *)l24, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, r6, 0x65, 4, 0x440, 1, 0);
    r6 = 0;
    if (((struct Obj00031 *)p)->f8 != 0) r6 = t;
    func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (struct MsgBank *)l20, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, r6, 0x66, 0x14, 0x440, 1, 0);
    t = 0;
    if (((struct Obj00031 *)p)->f8 != 0) t = ((struct Obj00031 *)p)->fC;
    func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f78, (struct MsgBank *)l1c, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, t, 4, 5, 0x3c40, 0, 0);
    for (k = 0; k < 4; k++) {
        *(int *)(p + k * 4 + 0x7c) = 0;
    }
    func_021BAF7C(p);
}








void func_021BACB0(char *p, int idx)
{
    int t0 = W(0x1e0);
    int a30 = ((int *)(p + (idx + 5) * 4))[0x78];
    int a2c = ((int *)(p + (idx + 0xb) * 4))[0x78];
    int a28 = ((int *)(p + (idx + 0x11) * 4))[0x78];
    int a24 = ((int *)(p + (idx + 0x17) * 4))[0x78];
    int a20 = ((int *)(p + (idx + 0x1d) * 4))[0x78];
    unsigned short cur = H(0xc);
    unsigned short c;
    int h;
    int fl;
    unsigned char i;

    if (cur == 0x1e7 && H(0xe) != 0) {
        cur = 0x1ee;
    } else if (cur == 0x1ec && H(0xe) != 0) {
        cur = 0x1ef;
    }
    if (W(0x18) != 2) {
        func_021BAA08(H(0), W(0x6c), (struct MsgBank *)t0, (void *)W(0x2c), W(0x28), 0x90, 0, 5, 0x3c40, 2, 0);
    }
    c = H(0xc);
    if (W(4) == 0) {
        unsigned short *tab = func_0201AF80(H(0), 0);
        c = tab[H(0xc)];
        func_020307B0(tab);
    }
    if (c != 0x3e7) {
        h = (int)func_0201EC64(H(0));
        if (idx == 0) {
            func_0201EFA4((struct WordSet *)h, 0, c, 3, 2, 0);
        } else {
            func_0201EFA4((struct WordSet *)h, 0, c, 3, 2, 1);
        }
        func_021BA960(H(0), W(0x70), (void *)W(0x2c), W(0x28), W(0x270), 8, 5, 0x440, 0, h);
        func_0201ED04((struct WordSet *)h);
    } else {
        func_021BA960(H(0), W(0x70), (void *)W(0x2c), W(0x28), W(0x274), 8, 5, 0x440, 0, 0);
    }
    c = 0;
    func_021BAA08(H(0), W(0x70), (struct MsgBank *)a20, (void *)W(0x2c), W(0x28), H(0xc), 0x30, 5, 0x440, 0, 0);
    if (W(8) != 0) c = H(0xc);
    func_021BAA08(H(0), W(0x70), (struct MsgBank *)a30, (void *)W(0x2c), W(0x28), c, 0, 0x16, 0x440, 2, 0);
    func_021BA960(H(0), W(0x74), (void *)W(0x2c), W(0x28), ((int *)(p + (idx + 4) * 4))[0x9c], 0, 4, 0x440, 0, 0);
    func_021BA960(H(0), W(0x74), (void *)W(0x2c), W(0x28), ((int *)(p + (idx + 0xa) * 4))[0x9c], 0, 0x14, 0x440, 0, 0);
    c = 0;
    if (W(8) != 0) c = cur;
    func_021BAA08(H(0), W(0x74), (struct MsgBank *)a2c, (void *)W(0x2c), W(0x28), c, d_021BC110[idx], 4, 0x440, 1, 0);
    c = 0;
    if (W(8) != 0) c = cur;
    func_021BAA08(H(0), W(0x74), (struct MsgBank *)a28, (void *)W(0x2c), W(0x28), c, d_021BC11C[idx], 0x14, 0x440, 1, 0);
    c = 0;
    if (W(8) != 0) c = H(0xc);
    func_021BAA08(H(0), W(0x78), (struct MsgBank *)a24, (void *)W(0x2c), W(0x28), c, 4, 5, 0x3c40, 0, 0);
    for (i = 0; i < 4; i++) {
        ((int *)(p + i * 4))[0x1f] = 0;
    }
    func_021BAF7C(p);
}







void func_021BAF50(char *p)
{
    int i;
    func_0201C6EC((struct PrintSys *)(((struct Obj25402 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        ((struct Obj14637 *)slot)->f7C = 1;
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj14637 *)slot)->f6C)), 0);
    }
}







void func_021BAF7C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj08388 *)slot)->f7C == 0 && func_0201C6C4((struct PrintSys *)(((struct Obj25403 *)p)->f2C), (void *)func_02045770((struct Descriptor *)((struct Obj08388 *)slot)->f6C)) == 0) {
            int window = ((struct Obj08388 *)slot)->f6C;
            func_02045334((struct Descriptor *)window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730((struct Descriptor *)window));
            ((struct Obj08388 *)slot)->f7C = 1;
        }
    }
}








void func_021BAFC4(Ent_021BA934 *e)
{
    Zero z = ZERO;
    int s = (int)func_0204384C(0x9f, 0x19, z, e->f0);
    int q;

    e->f8c = func_020450F0(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f8c);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 8, 0, z, z, 0x20, 0x18, z);

    e->f90 = func_020450F0(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0xa8, 8, z, z, 0x20, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0xf8, 8, z, 8, 8, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0x28, 0x10, 8, 8, 0x18, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0x80, z, 0, 0x10, 8, 8, 0);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0x58, 0x10, 8, 0x10, 0x18, 8, z);

    func_020437AC((struct Obj020437AC *)s);
}







void func_021BB0E4(char *p)
{
    func_020452E8(((struct Obj00173 *)p)->f8C);
    func_020452E8(((struct Obj00173 *)p)->f90);
}








void func_021BB0FC(void *obj)
{
    int p;

    if (((struct Obj10886 *)obj)->f8 != 0) {
        p = ((struct Obj10886 *)obj)->f8C;
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        return;
    }
    p = ((struct Obj10886 *)obj)->f90;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
}








void func_021BB13C(void *a0, void *a1, void *a2, void *a3)
{
    func_021BB184(a0, (int)a3);
    func_021BB23C(a0, (int)a1, (int)a2, (int)a3);
    func_021BB2D4(a0);
}







void func_021BB160(char *p, int i)
{
    void **slot = (void **)(p + 0xac) + i;
    if (*slot != 0) {
        func_021BB2C4(p, i);
        func_021BB214(p, i);
        *slot = 0;
    }
}







void func_021BB184(char *p,int index)
{
    int flag=0;
    int handle;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    handle=((struct Obj00790 *)p)->f1D4;
    *(int *)(p+0x94+index*4)=func_0202D81C(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,((struct Obj00790 *)p)->f14,flag,((struct Obj00790 *)p)->f0);
    *(int *)(p+0x9c+index*4)=func_0202D7D8(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,flag,index<<5,((struct Obj00790 *)p)->f0);
    *(int *)(p+0xa4+index*4)=func_0202D898(((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,2,flag,((struct Obj00790 *)p)->f0);
}







void func_021BB214(char *p, int i)
{
    char *s = p + i * 4;
    func_0204ADA4((u32)(((struct Obj10887 *)s)->f9C));
    func_0204A8D4((u32)(((struct Obj10887 *)s)->f94));
    func_0204AFD8((u32)(((struct Obj10887 *)s)->fA4));
}







void func_021BB23C(char *p,int x,int y,int index)
{
    int flag=0;
    Pos_021BA934 pos;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    func_02082BCC(&pos,0,8);
    pos.x=x;
    pos.y=y;
    *(int *)(p+0xac+index*4)=(int)func_0204B294((void *)((struct Obj00790 *)p)->f24,*(int *)(p+0x94+index*4),*(int *)(p+0x9c+index*4),*(int *)(p+0xa4+index*4),&pos,flag,((struct Obj00790 *)p)->f0);
    func_0204B800((struct Node *)(*(int *)(p+0xac+index*4)),0);
    if(((struct Obj00790 *)p)->f18==2) func_0204B688((struct Actor *)(*(int *)(p+0xac+index*4)),1);
    if(func_0201AE1C((const struct Personal *)(((struct Obj00790 *)p)->f26C),34)==0) func_0204B604((struct Actor *)(*(int *)(p+0xac+index*4)),1,1);
}







void func_021BB2C4(char *p, int i)
{
    func_0204B3B4(*(void **)(p + i * 4 + 0xac));
}







void func_021BB2D4(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        if (i != ((struct Obj25404 *)p)->fB4 && *(void **)(p + i * 4 + 0xac) != 0) {
            func_0204B3DC(*(void **)(p + i * 4 + 0xac), 0);
        }
    }
}







void func_021BB304(Ent_021BB304 *p)
{
    unsigned char a, b, i;
    int flag;
    int sh;
    void *u;
    void *arc;
    Rect_021BA934 r;

    u = (void *)p->f1c;
    flag = (int)u == 0 ? B_FALSE : B_TRUE;
    sh = 0;
    if (u != 0) sh = 1;
    arc = p->f1d0;
    for (a = 0; a < 2; a++) {
        for (b = 0; b < 2; b++) {
            p->m[a][b] = -1;
        }
    }
    p->fe0 = 0;
    p->fc8 = (void *)func_0204AC18(arc, func_020275E8(), flag, 0x40, 0, 3, p->f0);
    p->fcc = (void *)func_0204AF28(arc, func_020275FC(2), func_02027600(2), p->f0);
    if (p->f18 == 2 && p->f1c == 0) {
        r.a = 0; r.b = 0; r.c = 0; r.d = 0; r.e = 0;
        p->fe4 = 1;
        p->f170 = 0x11;
        p->f171 = 0x11;
        for (i = 0; i < 0x11; i++) {
            p->a[i] = (void *)func_0204A6C8(arc, func_020275F8(i), 0, flag, p->f0);
            p->b[i] = func_0204B294(p->f24, (unsigned int)p->a[i], (unsigned int)p->fc8, (unsigned int)p->fcc, &r, sh, p->f0);
            func_0204B6F4(p->b[i], func_020275EC(i), 1);
            func_0204B800(p->b[i], 2);
            func_0204B688(p->b[i], 1);
            func_0204B3DC(p->b[i], 0);
        }
    } else {
        p->fe4 = 0;
    }
}






void func_021BB480(char *p)
{
    unsigned char i;
    for(i=0;i<2;i++) func_021BB92C(p,i);
    if(((struct Obj00173 *)p)->fE4) {
        for(i=0;i<17;i++) {
            char *slot=p+i*4;
            func_0204B3B4((struct Obj *)(((struct Obj14639 *)slot)->f12C));
            func_0204A8D4(((struct Obj14639 *)slot)->fE8);
        }
        ((struct Obj00173 *)p)->fE4=0;
    }
    func_0204AFD8(((struct Obj00173 *)p)->fCC);
    func_0204ADA4(((struct Obj00173 *)p)->fC8);
}




void func_021BB4E0(char *p,int mode,int which)
{
    int mon=((struct Obj25405 *)p)->f26C;
    unsigned char first=func_0201AE1C((const struct Personal *)mon,6);
    unsigned char second=func_0201AE1C((const struct Personal *)mon,7);
    if(first==second) second=17;
    if(mode==6) func_021BB534((Ent_021B9DE0 *)p, first, second, which);
    else func_021BB79C((Ent_021BB79C *)p, first, second, mode, which);
    func_021BB980((struct State_021BB79C *)((struct State *)p));
}




void func_021BB534(Ent_021B9DE0 *p, unsigned x, unsigned y, int row)
{
    Rect4 rr[2];
    Pos_021BB534 pos[2];
    unsigned char sel[2];
    int ifv;
    int tern;
    short v;
    int j;
    void *arc;
    short *zp;

    if (p->fe4 != 0) {
        ifv = 0;
        if (p->f1c != 0) ifv = 1;
        pos[0].x = 0xa8;
        v = p->f1b4 + 0x54;
        pos[0].y = v;
        pos[1].x = 0xd0;
        pos[1].y = v;
        if (p->f170 != 0x11) {
            if (p->f170 != x && p->f170 != y) {
                func_0204B3DC(p->b[p->f170], 0);
                p->f170 = 0x11;
            } else {
                if (p->f170 == y) {
                    func_0204B404(p->b[p->f170], (Pos_021BB534 *)(&pos[1]), ifv);
                }
                func_0204B3DC(p->b[p->f170], 1);
            }
        }
        if (p->f171 != 0x11) {
            if (p->f171 != x && p->f171 != y) {
                func_0204B3DC(p->b[p->f171], 0);
                p->f171 = 0x11;
            } else {
                if (p->f171 == x) {
                    func_0204B404(p->b[p->f171], (Pos_021BB534 *)(&pos[0]), ifv);
                }
                func_0204B3DC(p->b[p->f171], 1);
            }
        }
        if (x != 0x11) {
            p->f170 = x;
            func_0204B3DC(p->b[p->f170], 1);
            func_0204B404(p->b[p->f170], (Pos_021BB534 *)(&pos[0]), ifv);
        }
        if (y != 0x11) {
            p->f171 = y;
            func_0204B3DC(p->b[p->f171], 1);
            func_0204B404(p->b[p->f171], (Pos_021BB534 *)(&pos[1]), ifv);
        }
    } else {
        zp = (short *)rr;
        zp[0] = 0;
        zp[1] = 0;
        zp[2] = 0;
        zp[3] = 0;
        zp[4] = 0;
        zp[5] = 0;
        zp[6] = 0;
        zp[7] = 0;
        ifv = 0;
        if (p->f1c != 0) ifv = 1;
        tern = p->f1c == 0 ? B_FALSE : B_TRUE;
        sel[0] = x;
        sel[1] = y;
        rr[0].x = 0xa8;
        v = p->f1b4 + 0x54;
        rr[0].y = v;
        rr[1].x = 0xd0;
        rr[1].y = v;
        arc = p->f1d0;
        for (j = 0; j < 2; j++) {
            p->m[row][j] = -1;
            if (sel[j] != 0x11) {
                p->m[row][j] = (int)func_0204A6C8(arc, func_020275F8(sel[j]), 0, ifv, p->f0);
            }
        }
        for (j = 0; j < 2; j++) {
            if (p->m[row][j] != -1) {
                p->n[row][j] = func_0204B294(p->f24, p->m[row][j], (unsigned int)p->fc8, (unsigned int)p->fcc, &rr[j], (unsigned short)tern, p->f0);
                func_0204B6F4(p->n[row][j], func_020275EC(sel[j]), 1);
                func_0204B800(p->n[row][j], 2);
                func_0204B688(p->n[row][j], 1);
            }
        }
    }
}









void func_021BB79C(Ent_021BB79C *p, unsigned x, unsigned y, int z, int row)
{
    Rect4 rr[2];
    Pos pos[2];
    unsigned char sel[2];
    void *arc;
    void *handle;
    int data;
    int ta;
    int tb;
    unsigned char id;
    int ifv;
    int tern;
    short v;
    int j;
    short *zp;
    Blob *blob;

    zp = (short *)rr;
    zp[0] = 0;
    zp[1] = 0;
    zp[2] = 0;
    zp[3] = 0;
    zp[4] = 0;
    zp[5] = 0;
    zp[6] = 0;
    zp[7] = 0;
    ifv = 0;
    if (p->f1c != 0) ifv = 1;
    tern = p->f1c == 0 ? B_FALSE : B_TRUE;
    sel[0] = x;
    sel[1] = y;
    rr[0].x = 0xa8;
    v = p->f1b4 + 0x54;
    rr[0].y = v;
    rr[1].x = 0xd0;
    rr[1].y = v;
    arc = p->f1d0;
    handle = func_02049DF4(p->f1c4, d_021BC128[z], 0, (unsigned int)(&blob), p->f0);
    data = blob->f14;
    for (j = 0; j < 2; j++) {
        p->m[row][j] = -1;
        id = sel[j];
        if (id != 0x11) {
            p->m[row][j] = (int)func_0204A6C8(arc, func_020275F8(id), 0, ifv, p->f0);
            ta = d_021BC150[id].b << 7;
            tb = d_021BC150[id].a << 11;
            func_0204AA94((int)((void *)p->m[row][j]), (void *)(data + (tb + ta)), 0x80, 0, ifv);
            func_0204AA94((int)((void *)p->m[row][j]), (void *)(data + ((tb + (1 << 10)) + ta)), 0x80, 0x80, ifv);
        }
    }
    func_020307B0(handle);
    for (j = 0; j < 2; j++) {
        if (p->m[row][j] != -1) {
            p->n[row][j] = func_0204B294(p->f24, (u32)p->m[row][j], (u32)p->fc8, (u32)p->fcc, &rr[j], (unsigned short)tern, p->f0);
            func_0204B6F4(p->n[row][j], func_020275EC(sel[j]), 1);
            func_0204B800(p->n[row][j], 2);
            func_0204B688(p->n[row][j], 1);
        }
    }
}








void func_021BB92C(char *p, int index)
{
    int i;
    if (((struct Obj25407 *)p)->fE4 == 0) {
        for (i = 0; i < 2; i++) {
            if (*(int *)(p + index * 8 + i * 4 + 0xb8) != -1)
                func_0204B3B4((struct Obj *)(*(int *)(p + index * 8 + i * 4 + 0xd0)));
        }
        for (i = 0; i < 2; i++) {
            if (*(int *)(p + index * 8 + i * 4 + 0xb8) != -1) {
                func_0204A8D4(*(int *)(p + index * 8 + i * 4 + 0xb8));
                *(int *)(p + index * 8 + i * 4 + 0xb8) = -1;
            }
        }
    }
}








/*
 * tail: zero alignment halfword at 0x021BB9DE before 0x021BB9E0.
 * lever: two-dimensional arrays as struct fields avoid hoisted raw-offset bases.
 */
void func_021BB980(struct State_021BB79C *p)
{
    u8 i,j;
    if (p->mode==0) {
        for(i=0;i<2;i++) {
            if(i != p->selected) {
                for(j=0;j<2;j++) {
                    if(p->ids[i][j]!=-1)
                        func_0204B3DC(p->objects[i][j],0);
                }
            }
        }
    }
}








void func_021BB9E0(struct State_021BB9E0 *p)
{
    u8 i;
    int flag;
    unsigned owner;
    i=0;
    for(;i<2;i++) p->array[i]=0;
    p->index=0;
    flag=0;
    if(p->flag) flag=1;
    owner=p->owner;
    ((struct Obj02542 *)p)->f17C=func_0204AC18((void *)owner,func_021BC0B4(p->flag),flag,160,0,1,p->heap);
    ((struct Obj02542 *)p)->f180=func_0204AF28((void *)owner,func_021BC0B8(0),func_021BC0CC(0),p->heap);
    ((struct Obj02542 *)p)->f184=func_0204AF28((void *)owner,func_021BC0B8(494),func_021BC0CC(494),p->heap);
}








void func_021BBA7C(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        func_021BBBD8((S_021BBBD8 *)((struct S_021BB79C *)p), i);
    }
    func_0204AFD8((u32)(((struct Obj00173 *)p)->f184));
    func_0204AFD8((u32)(((struct Obj00173 *)p)->f180));
    func_0204ADA4((u32)(((struct Obj00173 *)p)->f17C));
}







void func_021BBAB0(S_021BBAB0 *p, u32 a, u32 b, u32 idx)
{
    u32 flag;
    u32 w;
    u32 v;
    Bool flag2;
    struct Point pt;

    flag = 0;
    if (p->f1c != 0)
        flag = 1;
    flag2 = p->f1c == 0 ? B_FALSE : B_TRUE;
    v = func_021BC0E4(a, b);
    if (v == 0xFFFF) {
        w = p->f1d8;
        p->a174[idx] = func_0204A6C8((void *)w, func_021BC0B0(a), 1, flag, p->id);
    } else {
        p->a174[idx] = func_0204A6C8((void *)p->f1dc, v, 1, flag, p->id);
    }
    pt.x = 0x78;
    pt.y = p->f1b4 + 0x58;
    pt.f4 = 0;
    pt.f6 = 1;
    pt.f7 = 0;
    if (a <= 0x1ED && v != 0xFFFF)
        p->a188[idx] = (u32)func_0204B294((void *)p->f24, p->a174[idx], p->f17c, p->f180, &pt, flag2, p->id);
    else
        p->a188[idx] = (u32)func_0204B294((void *)p->f24, p->a174[idx], p->f17c, p->f184, &pt, flag2, p->id);
    func_0204B800((void *)p->a188[idx], 1);
    func_0204B688((void *)p->a188[idx], 1);
    func_021BBC04((S_021BB79C *)p);
}







void func_021BBBD8(S_021BBBD8 *p, int i)
{
    if (p->b[i] != 0) {
        func_0204B3B4(p->b[i]);
        func_0204A8D4((u32)p->a[i]);
        p->b[i] = 0;
    }
}





void func_021BBC04(S_021BB79C *p)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (i != p->sel && p->b[i] != 0)
            func_0204B3DC(p->b[i], 0);
    }
}





void func_021BBC38(S_021BBC38 *p)
{
    func_021BB4E0((char *)p, 6, p->fe0);
    func_021BBAB0((S_021BBAB0 *)p, p->fc, p->fe, ((struct Obj00031 *)p)->f190);
    func_021BBDA8((struct State *)p, p->f8);
    func_021BAA4C((char *)p);
}





void func_021BBC68(S_021BBC38 *p, int v)
{
    func_021BB4E0((char *)p, v, p->fe0);
    func_021BBAB0((S_021BBAB0 *)p, p->fc, p->fe, ((struct Obj00031 *)p)->f190);
    func_021BBDA8((struct State *)p, p->f8);
    func_021BACB0((char *)p, v);
}




s32 func_021BBC9C(S_021BBC9C *p)
{
    s16_021BB79C f;
    u8 i;

    if (p->phase + 0x400 >= 0x10000)
        p->phase = p->phase + 0x400 - 0x10000;
    else
        p->phase += 0x400;
    f = (tbl_020A1B38[(p->phase >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < 5; i++) {
        u16 a = p->a[i];
        u16 b = p->b[i];
        u8 a1 = a & 0x1f;
        u8 a2 = (a & 0x3e0) >> 5;
        u8 a3 = (a & 0x7c00) >> 10;
        u8 b1 = b & 0x1f;
        u8 b2 = (b & 0x3e0) >> 5;
        u8 b3 = (b & 0x7c00) >> 10;
        u8 c1 = a1 + (((b1 - a1) * f) >> 12);
        u8 c2 = a2 + (((b2 - a2) * f) >> 12);
        u8 c3 = a3 + (((b3 - a3) * f) >> 12);
        p->pal[i] = c1 | (c2 << 5) | (c3 << 10);
    }
    return func_02061CA4((void *)(p->f1c == 0 ? 0xf : 0x1f), 0x22, (u32)p->pal, 0xa);
}




void func_021BBDA8(struct State *p, int v)
{
    u8 i;
    func_0204B3DC(p->last[p->index],v);
    if(p->mode) {
        if(p->a!=17) func_0204B3DC(p->other[p->a],v);
        if(p->b!=17) func_0204B3DC(p->other[p->b],v);
    } else {
        for(i=0;i<2;i++) {
            if(p->ids[p->selected][i]!=-1)
                func_0204B3DC(p->objects[p->selected][i],v);
        }
    }
}




void func_021BBE34(S_021BBE34 *p, int v)
{
    func_0204B3DC(p->last[p->index], v);
    if (p->f8 == 0)
        v = 0;
    func_021BBDA8((struct State *)p, v);
}




void func_021BBE5C(S_021BBE5C *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        switch (i) {
        case 3:
            p->w[i] = func_020490F4(func_020275E4(), p->id);
            break;
        case 4:
            p->w[i] = (void *)func_0202D7C8(p->id);
            break;
        case 5:
            p->w[i] = func_020490F4(func_021BC0AC(), p->id);
            break;
        case 6:
            p->w[i] = func_020490F4(func_021BC0E0(), p->id);
            break;
        default:
            p->w[i] = func_020490F4(tbl_021BC134[i], p->id);
            break;
        }
    }
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] != 0)
                p->objs[i] = p->g[0];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        case 2:
            if (p->g[1] != 0)
                p->objs[i] = p->g[1];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        case 3:
            if (p->g[2] != 0)
                p->objs[i] = p->g[2];
            else
                p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        default:
            p->objs[i] = func_02045B38(0, 2, tbl_021BC1C4[i], p->id);
            break;
        }
    }
    p->x = func_0201ADE4(p->fc, p->fe, p->id);
    for (i = 0; i < 16; i++)
        p->a[i] = func_02045EC0(p->objs[0], tbl_021BC184[i]);
}



void func_021BC008(S *p)
{
    u8 i;
    for (i = 0; i < 16; i++)
        func_02045808(p->a[i]);
    if (p->x != 0)
        func_0201AE14(p->x);
    for (i = 0; i < 35; i++) {
        switch (i) {
        case 1:
            if (p->g[0] == 0)
                func_02045C04(p->objs[i]);
            break;
        case 2:
            if (p->g[1] == 0)
                func_02045C04(p->objs[i]);
            break;
        case 3:
            if (p->g[2] == 0)
                func_02045C04(p->objs[i]);
            break;
        default:
            func_02045C04(p->objs[i]);
            break;
        }
    }
    for (i = 0; i < 7; i++)
        func_02049238(p->w[i]);
}



u32 func_021BC0AC(void)
{
    return 0xa7;
}



int func_021BC0B0(int v)
{
    return v + 5;
}



int func_021BC0B4(int a0)
{
    return 0;
}




int func_021BC0B8(int v)
{
    if (v <= 0x1ED)
        return 2;
    else
        return 4;
}




int func_021BC0CC(int v)
{
    if (v <= 0x1ED)
        return 1;
    else
        return 3;
}



u32 func_021BC0E0(void)
{
    return 0xe9;
}
