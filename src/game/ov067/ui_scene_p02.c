/*
 * file:     ui_scene_p02.c
 * unit:     yes
 * function: func_021B66FC, func_021B6730, func_021B6738, func_021B67F8, func_021B691C, func_021B6934, func_021B69A4, func_021B69B8, func_021B69BC, func_021B69C8, func_021B69D0, func_021B69D4, func_021B69D8, func_021B69F8, func_021B6A10, func_021B6A1C, func_021B6A28, func_021B6A44, func_021B6A68, func_021B6A98, func_021B6AE4, func_021B6B2C, func_021B6C4C, func_021B6C74, func_021B6CCC, func_021B6CE0, func_021B6D70, func_021B6DC0, func_021B709C, func_021B70F4, func_021B72DC, func_021B7378, func_021B76B0, func_021B76C8, func_021B7718, func_021B7754, func_021B796C, func_021B79E4, func_021B7A10, func_021B7A4C, func_021B7A64, func_021B7AB0, func_021B7B7C, func_021B7BE0, func_021B7CF8, func_021B7E70, func_021B806C, func_021B83A0, func_021B8404, func_021B841C, func_021B8434, func_021B8460, func_021B8990, func_021B8A44, func_021B8A88, func_021B8AB8, func_021B8AE4, func_021B8B74, func_021B8C14, func_021B8C4C, func_021B8DF0, func_021B8EA0, func_021B8FA0, func_021B8FE4, func_021B90B8, func_021B9138, func_021B9190, func_021B91BC, func_021B91D0, func_021B9228, func_021B9280, func_021B92F0, func_021B9344, func_021B9394, func_021B9398, func_021B93A4, func_021B93B0, func_021B93B8, func_021B93C0, func_021B93D4, func_021B940C, func_021B941C
 * address:  0x021B66FC
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021B942C     0x021B942C  data  ov067  a4
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B800  0x0204B800  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02030734  0x02030734  arm
 *   d_021B9558     0x021B9558  data  a1
 *   ENV_SetResourceSet  0x020307B0  arm
 *   func_020458F8 0x020458F8 arm
 *   func_02082A7C 0x02082A7C arm
 *   func_02045F50 0x02045F50 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045A90  0x02045A90  arm
 *   d_021B9564     0x021B9564  data  a1
 *   func_020414AC  0x020414AC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_020493D4  0x020493D4  arm
 *   func_0204932C  0x0204932C  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02040588  0x02040588  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021B6208  0x021B6208  thumb  ov067
 *   func_021B629C  0x021B629C  thumb  ov067
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_021B6284  0x021B6284  thumb  ov067
 *   func_020452E8  0x020452E8  arm
 *   func_0204B404  0x0204B404  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020355C4  0x020355C4  arm
 *   d_021B94C4     0x021B94C4  data  a1
 *   func_02035D40  0x02035D40  arm
 *   d_021B94D0     0x021B94D0  data  a2
 *   d_021B94B8  0x021B94B8  data  a1
 *   d_021B94BC  0x021B94BC  data  a1
 *   func_02061CA4  0x02061CA4  arm
 *   d_021B9574     0x021B9574  data  ov067  a1
 *   func_0201C450  0x0201C450  thumb
 *   func_0202E940  0x0202E940  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_02082A90  0x02082A90  arm
 *   func_0202CA0C       0x0202CA0C  thumb
 *   func_0202EA20       0x0202EA20  thumb
 *   func_0201C4C0       0x0201C4C0  thumb
 *   func_02049EF4 0x02049EF4 arm
 *   func_02082A60 0x02082A60 arm
 *   func_0202E9AC 0x0202E9AC thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035CB8  0x02035CB8  arm
 *   func_0202EA40  0x0202EA40  thumb
 *   func_02041EE4  0x02041EE4  arm
 *   func_02035C08  0x02035C08  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02035BA4 0x02035BA4 arm
 *   d_021B94F8 0x021B94F8 data a1
 *   func_0202EDE4  0x0202EDE4  thumb
 *   func_0202EE0C 0x0202EE0C thumb
 *   d_021B94FE     0x021B94FE  data   ov067  a1
 *   func_0202CF8C  0x0202CF8C  thumb
 *   func_02051B0C  0x02051B0C  arm
 *   func_0202CAC4  0x0202CAC4  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_020437D4  0x020437D4  arm
 *   func_0202CF84  0x0202CF84  thumb
 *   func_02041300  0x02041300  arm
 *   func_0202EB04  0x0202EB04  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 */
#include "../../matched/include/Obj20610.h"
#include "../../matched/include/Obj20611.h"
#include "../../matched/include/Obj20612.h"
#include "../../matched/include/Obj20613.h"
#include "../../matched/include/Obj20614.h"
#include "../../matched/include/Obj20615.h"
#include "../../matched/include/Obj05146.h"
#include "../../matched/include/Obj13132.h"
#include "../../matched/include/Obj05378.h"
#include "../../matched/include/Obj07677.h"
#include "../../matched/include/Obj20620.h"
#include "../../matched/include/Obj09863.h"
#include "../../matched/include/Obj20621.h"
#include "../../matched/include/Obj09864.h"
#include "../../matched/include/Obj05147.h"
#include "../../matched/include/Obj20623.h"
#include "../../matched/include/Obj09865.h"

struct Obj_021B66FC;
struct S_021B66FC;
struct Actor;
struct Node;
struct S_021B69A4;
struct StrObj;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
struct ArcFile;
struct NitroFileHeader;
struct CharBuf;
struct Cfg;
struct PrintSys;
struct Ctx;
struct Vec2;
struct WinMgr;
struct CodeIn;
struct Obj0202EA20;
struct Row;
struct Bmp;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16_021B66FC;

typedef struct {
    int kind;
    s16_021B66FC x;
    s16_021B66FC y;
    u16 h8;
    u16 hA;
    u16 hC;
    u16 hE;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 pad16;
    u32 w18;
    u32 w1C;
} Src;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u16 e;
    u16 padA;
    u32 f;
    u32 g;
} Ent_021B66FC;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    void *fC;
    void *f10;
    u32 f14;
    Src src;
} Obj_021B66FC;

typedef struct {
    s16_021B66FC x;
    s16_021B66FC y;
    u16 z;
    u16 pad;
} Pos;

typedef struct S_021B66FC {
    u32 f00;
    u32 f04;
    u32 f08;
    void (*f0c)(struct S_021B66FC *);
    u8 pad10[0x1c - 0x10];
    short f1c;
    short f1e;
    u8 pad20[0x30 - 0x20];
    u32 f30;
    u8 pad34[4];
} S_021B66FC;

struct S_021B69A4 {
    struct Obj_021B69A4 *f0;
    u32 f4;
    u32 f8;
    char pad[0x26 - 0xC];
    u16 f26;
    u16 f28;
    u16 f2a;
};

typedef struct S_021B6A68 {
    void *f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x26 - 0x0c];
    u16 f26;
    u16 f28;
    u16 f2a;
} S_021B6A68;

typedef struct S_021B6A98 {
    void *f00;
    u32 f04;
    u32 f08;
    u8 pad0c[0x26 - 0x0c];
    u16 f26;
    u16 f28;
    u16 f2a;
    u16 f2c;
} S_021B6A98;

typedef short s16_021B69A4;

typedef unsigned int u32_021B6B2C;

typedef unsigned int u32_021B6C4C;

typedef unsigned int u32_021B6C74;

typedef unsigned u32_021B6CE0;

typedef struct { u32_021B6CE0 id,index; } Pair_021B6B2C;

typedef struct { u32_021B6CE0 str,count; void *bank[1]; } Obj_021B69A4;

typedef unsigned int u32_021B6D70;

typedef unsigned int u32_021B6DC0;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
} In;

typedef struct {
    u16 heap;
    u16 _2;
    u32_021B6DC0 f4;
    u32_021B6DC0 f8;
    u32_021B6DC0 fC;
    u32_021B6DC0 f10;
    u8 f14;
    u8 f15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 _1b;
    u32_021B6DC0 f1C;
    u8 f20;
    u8 _21;
    u16 pal[3][16];
    u16 _82;
    u32_021B6DC0 f84;
    int f88;
    int f8c;
    u32_021B6DC0 f90;
    u32_021B6DC0 f94;
    u32_021B6DC0 f98;
    u32_021B6DC0 f9c;
    int arrA0[4];
    u8 fB0[0xc0 - 0xb0];
    u32_021B6DC0 fC0;
    u8 _c4[0xcc - 0xc4];
} S_021B6DC0;

typedef struct {
    u8 _0[0xc];
    u16 (*data)[16];
} Pltt;

typedef signed int     s32;

typedef short s16_021B6B2C;

struct S_021B70F4 {
    u8 _0[0x8];
    u32 f8;
    u32 fC;
    u32 f10;
    u8 f14;
    u8 _15;
    u8 f16;
    u8 f17;
    u8 f18;
    u8 _19[0x1c - 0x19];
    u32 f1C;
    u8 _20[0x22 - 0x20];
    u8 f22[0x88 - 0x22];
    int f88;
    int f8c;
    u32 f90;
    u32 f94;
    u32 f98;
    u32 f9c;
    int arrA0[4];
    u8 _b0[0xc0 - 0xb0];
    u32 fC0;
};

typedef struct {
    u16 x;
    u16 y;
} Pt;

struct S_021B72DC {
    u8 _0[0x14];
    u8 f14;
    u8 _15[0x18 - 0x15];
    u8 f18;
    u8 _19[0x88 - 0x19];
    void *f88;
    void *f8c;
    u8 _90[0x98 - 0x90];
    u32 f98;
    u8 _9c[0xa0 - 0x9c];
    void *arrA0[4];
};

typedef struct { u8 v[12]; } Rect12;

struct Step {
    u16 frame;
    u16 idx;
};

typedef struct S_021B7378 {
    u8 pad00[0x0c];
    int fc;
    u32 f10;
    u8 pad14[0x16 - 0x14];
    u8 f16;
    u8 f17;
    u8 pad18[0x1c - 0x18];
    u32 f1c;
    u8 pad20[0x22 - 0x20];
    u16 f22[1][16];
    u8 pad42[0x88 - 0x42];
    void *f88;
    void *f8c;
    int f90;
    int f94;
    u32 f98;
    int f9c;
    void *fa0[4];
    u8 padb0[0xc0 - 0xb0];
    int fc0;
    u8 fc4;
    u8 padc5;
    u16 fc6;
    u16 fc8;
} S_021B7378;

typedef struct S_021B76B0 {
    u8 pad00[0x98];
    u32 f98;
    int f9c;
} S_021B76B0;

typedef struct { u8 v[2][2]; } T1;

typedef struct { u8 v[4][2]; } T2;

typedef signed char s8;

typedef signed short s16_021B7718;

struct Ent_021B66FC {
    u8 f0;
    u8 pad1[7];
};

typedef struct Tmpl {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 fa;
    u8 padb[0x11 - 0xb];
    u8 f11;
    u8 pad12[0x14 - 0x12];
    u16 f14;
    u16 f16;
    u8 pad18[0x1c - 0x18];
    struct Ent_021B66FC *f1c;
    u32 f20;
    u32 f24;
} Tmpl;

struct Slot {
    u32 w;
    u32 pad;
};

typedef struct S_021B7754 {
    Tmpl t;
    void *f28;
    u32 *f2c;
    void *f30;
    void *f34;
    struct Slot *f38;
    void *f3c;
    void **f40;
    u8 f44;
    u8 f45;
    u8 pad46[0x4a - 0x46];
    s8 f4a;
    u8 pad4b[0x54 - 0x4b];
    int f54;
    int f58;
    u8 pad5c[0x98 - 0x5c];
    u16 f98;
    u8 pad9a[2];
} S_021B7754;

typedef signed short s16;

struct Ops {
    void (*fn)(void *a, int b, u8 *c, s16 d, int e);
    void (*f4)(void *obj, int pos, int flag);
    void (*f8)(void *obj, int v);
};

struct Pair {
    u32 a;
    u32 b;
};

struct Elem {
    void *p;
    u8 flag;
    u8 pad[3];
};

struct SceneEnt {
    u8 f0;
    u8 f1;
    u8 pad2[2];
    u32 f4;
};

/* stand-in: f94 is volatile only because func_021B83A0 reloads the counter after the store */
struct Scene {
    u8 f0;
    u8 f1;
    u8 f2;
    s8 f3;
    u8 f4;
    u8 f5;
    u8 _6[0xb - 6];
    u8 fb[6];
    u8 f11;
    u8 f12;
    u8 _13[0x16 - 0x13];
    u16 f16;
    u8 f18;
    u8 f19;
    u16 f1a;
    const struct SceneEnt *f1c;
    struct Ops *f20;
    void *f24;
    struct Pair *f28;
    u8 *f2c;
    void *f30;
    int f34;
    struct Elem *f38;
    void *f3c;
    u16 **f40;
    u8 count;
    u8 f45;
    s8 f46;
    s8 f47;
    u8 f48;
    u8 f49;
    s8 f4a;
    u8 f4b;
    u16 f4c;
    u16 f4e;
    u16 f50;
    u16 f52;
    u32 f54;
    int f58;
    s16 f5c;
    u16 f5e;
    s16 f60;
    s16 f62;
    u16 f64;
    s8 f66;
    s8 f67;
    u8 f68;
    u8 f69;
    u16 f6a;
    u32 f6c;
    u32 f70;
    u8 f74[5];
    u8 _79[0x7c - 0x79];
    u8 f7c;
    u8 f7d;
    u8 f7e;
    u8 f7f;
    int f80;
    u8 f84;
    s8 f85;
    u8 f86 : 5;
    u8 ready : 1;
    u8 drag : 1;
    u8 trigger : 1;
    u8 f87;
    u8 f88;
    u8 f89;
    u16 f8a;
    u32 f8c;
    u32 f90;
    volatile u8 f94;
    u8 f95;
    u8 f96;
};

typedef struct Pair_021B7718 { unsigned first, second; } Pair_021B7718;

typedef signed short s16_021B7CF8;

extern void func_0204AFD8(u32);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02082BCC(void *, u32, u32);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u8 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 a);
extern u32 func_020307B0(void *p);
extern struct Obj_021B66FC *func_0204B294(void *a, unsigned int b, unsigned int c, unsigned int d, const void *pos, u16 f, u16 g);
extern void func_0204B92C(struct Obj_021B66FC *obj, u32 v);
extern void func_0204B3B4(struct Obj_021B66FC *p);
extern u32 func_0204B3F4(struct Obj_021B66FC *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj_021B69A4 *p, u16 value);
extern void func_020061E4(u32 a);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0204B3DC(struct Obj_021B69A4 *p, u32 v);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B84C(void *, unsigned int);
extern struct MsgBank *func_02045B38(u32_021B6B2C resident, u32_021B6B2C arcId, u32_021B6B2C fileId, u32_021B6B2C heapId);
extern void *func_0201EC64(u16 heap);
extern void *func_020457B0(u32_021B6B2C size, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32_021B6B2C index);
extern u32_021B6B2C func_0201D304(struct StrObj *s, u32_021B6B2C a, u32_021B6B2C b);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32_021B6B2C i, u32_021B6B2C a, u32_021B6B2C b, u32_021B6B2C c, u32_021B6B2C d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32_021B6B2C func_0201ED04(struct WordSet *p);
extern u32_021B6B2C func_02045C04(struct Rec *rec);
extern void *func_02030734(u32_021B6C74 heapId, u32_021B6C74 size, int clear, const char *site, u16 tag);
extern void ENV_SetResourceSet(void *p);
extern u16 func_020458F8(struct U16Vec *vec);
extern void func_02082A7C(u32_021B6CE0,void *,u32_021B6CE0);
extern u16 func_02045F50(const struct Obj_021B69A4 *o);
extern void func_02045CAC(struct MsgBank *bank, u32_021B6CE0 index, void *dest);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_020414AC(u32_021B6DC0 a);
extern void *func_020490F4(u32_021B6DC0 id, u32_021B6DC0 heap);
extern u32_021B6DC0 func_020493D4(struct ArcFile *arc, u32_021B6DC0 member);
extern void func_0204932C(struct ArcFile *arc, u32_021B6DC0 member, void *dst);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02049B68(void *a, u32_021B6DC0 b, u32_021B6DC0 c, u32_021B6DC0 d, u32_021B6DC0 e, u16 f);
extern u32_021B6DC0 func_02049740(void *a0, u32_021B6DC0 a1, u32_021B6DC0 a2, u32_021B6DC0 a3, u32_021B6DC0 a4, u16 flags);
extern void func_020498F4(void *a, u32_021B6DC0 b, u32_021B6DC0 c, u32_021B6DC0 d, u32_021B6DC0 e, u32_021B6DC0 f, u16 g);
extern void func_02049238(void *h);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B40(u32_021B6DC0 a, u32_021B6DC0 b, u32_021B6DC0 c, u32_021B6DC0 d, u32_021B6DC0 e, u16 f);
extern u32_021B6DC0 func_020450F0(u32_021B6DC0 layer, u32_021B6DC0 a, u32_021B6DC0 b, u32_021B6DC0 tiles, u8 c, u8 d, u8 slot);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021B6208(void *out, In *in, int unused, u16 d);
extern int func_021B629C(void *p, int a, u16 x, u16 y, u8 e, u16 f);
extern void func_020434DC(u32_021B6DC0 mask, u32_021B6DC0 enable);
extern void func_02043598(u32_021B6DC0 mask, u32_021B6DC0 enable);
extern void func_021B6284(unsigned int *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B404(int h, Pt *pt, u16 v);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u8 func_020355C4(void);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void *func_0201C450(u16 n, u32 heap);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern void func_0202CA0C(struct WinMgr *mgr);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02082A60(const void *, void *, int);
extern void func_0202E9AC(struct CodeIn *, u8 *, u32, u32, u32);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern s32 func_0202EA40(struct Row *p);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern int func_02035C08(const void *p);
extern unsigned int func_0203630C(void);
extern int _s32_div_f(int a, int b);
extern int func_02035BA4(const void *p);
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
extern int func_02051B0C(int i);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_0202EB04(struct CodeIn *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
void func_021B66FC(u32 *p);
int func_021B6730(void *p, int i);
void func_021B6738(u32 a0, u32 a1, u32 a2, u32 a3, u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7, u8 k8, u32 k9, u16 k10);
void func_021B67F8(Obj_021B66FC *p, u32 a1, void *a2, Src *src, u32 a4, u16 a5);
void func_021B691C(void **p);
int func_021B6934(S_021B66FC *p);
int func_021B69A4(void **p);
int func_021B69B8(void *p);
void func_021B69BC(void *p, unsigned int v);
int func_021B69C8(void *p, int a);
void func_021B69D0(void *p, int v);
void func_021B69D4(void *p, int v);
void func_021B69D8(struct S_021B69A4 *p, u32 v);
u32 func_021B69F8(u32 p);
void func_021B6A10(void *p, unsigned int v);
void func_021B6A1C(void *p, unsigned int v);
void func_021B6A28(u8 *p);
void func_021B6A44(u8 *p);
void func_021B6A68(S_021B6A68 *p, u32 flag);
void func_021B6A98(S_021B6A98 *p, u32 flag);
void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
void func_021B6B2C(u32_021B6B2C a0, void *a1, u32_021B6B2C a2, u16 a3, u16 a4, u16 a5, u32_021B6B2C a6, u32_021B6B2C a7, u16 heap);
u16 func_021B6C4C(struct StrObj *s, u32_021B6C4C a, u32_021B6C4C mode);
u32_021B6C74 *func_021B6C74(u32_021B6C74 *src, u32_021B6C74 n, u16 heap);
void func_021B6CCC(int *p);
u32_021B6CE0 func_021B6CE0(Obj_021B69A4 *p,u32_021B6CE0 id,u32_021B6CE0 unused,u32_021B6CE0 str,Pair_021B6B2C *out,u32_021B6CE0 max);
int func_021B6D70(u32_021B6D70 a, u32_021B6D70 b, u32_021B6D70 n);
S_021B6DC0 *func_021B6DC0(u16 heap, u32_021B6DC0 a1, u32_021B6DC0 a2, u32_021B6DC0 a3, u8 a4, u32_021B6DC0 a5, u32_021B6DC0 a6, u32_021B6DC0 a7);
void func_021B709C(u8 *p);
void func_021B70F4(struct S_021B70F4 *s, u32 a1, u32 a2);
void func_021B72DC(struct S_021B72DC *s);
void func_021B7378(S_021B7378 *p);
int func_021B76B0(S_021B76B0 *p);
u8 func_021B76C8(u32 a, u32 b, u32 c);
void func_021B7718(int which, int idx, void *data);
S_021B7754 *func_021B7754(Tmpl *tmpl, u32 heap);
void func_021B796C(struct Scene *s);
void func_021B79E4(char *ctx, unsigned first, unsigned second);
void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index);
void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
int func_021B7A64(struct Scene *p);
int func_021B7AB0(struct Scene *p);
void func_021B7B7C(struct Scene *p);
void func_021B7BE0(struct Scene *p, int a1);
int func_021B7CF8(struct Scene *p);
int func_021B7E70(struct Scene *p);
int func_021B806C(struct Scene *s);
void func_021B83A0(struct Scene *p);
u8 func_021B8404(u8 *p, int n);
int func_021B841C(u8 *p, int n);
void func_021B8434(u8 *p, s8 a, u8 b, u16 c, u32 d);
int func_021B8460(struct Scene *s);
void func_021B8990(struct Scene *s, int idx);
u32 func_021B8A44(struct Scene *s);
void func_021B8A88(u8 *p, u8 *a, u8 *b);
int func_021B8AB8(u8 *p);
int func_021B8AE4(struct Scene *s, unsigned int v);
int func_021B8B74(struct Scene *s);
void func_021B8C14(struct Scene *s, int a);
int func_021B8C4C(struct Scene *s);
int func_021B8DF0(struct Scene *s, int a1);
int func_021B8EA0(struct Scene *s);
int func_021B8FA0(int x);
void func_021B8FE4(struct Scene *s, u32 a1, u32 a2);
void func_021B90B8(struct Scene *p, int a1, s8 a2);
void func_021B9138(struct Scene *p, u32 a1, s8 a2);
signed char func_021B9190(const signed char *p, int step);
signed char func_021B91BC(signed char a, signed char limit, int step);
void func_021B91D0(struct Scene *p, int i, s8 a2);
void func_021B9228(struct Scene *p, int i, s8 a2);
void func_021B9280(struct Scene *s, int a, u32 b);
void func_021B92F0(struct Scene *p, u32 a1, u32 a2);
void func_021B9344(struct Scene *s);
unsigned func_021B9394(struct Scene *p);
u32 func_021B9398(struct Scene *p, int index);
int func_021B93A4(struct Scene *p);
int func_021B93B0(struct Scene *p);
int func_021B93B8(struct Scene *p);
int func_021B93C0(struct Scene *p);
void func_021B93D4(struct Scene *s, int v);
void func_021B940C(struct Scene *s);
void func_021B941C(struct Scene *s);
extern Ent_021B66FC d_021B942C[];
extern const char d_021B9558[];
extern const char d_021B9564[];
extern const Rect12 d_021B94C4;
extern const struct Step d_021B94D0[10];
extern const T1 d_021B94B8;
extern const T2 d_021B94BC;
extern const char d_021B9574[];
extern const u8 d_021B94F8[];
extern const u8 d_021B94FE[][6];





void func_021B66FC(u32 *p)
{
    func_0204AFD8(p[2]);
    func_0204A8D4(p[1]);
    func_0204ADA4(p[0]);
    func_0203FB44(p[3], (u16)p[4], (u16)(p[4] >> 16));
    func_02082BCC(p, 0, 0x14);
}





int func_021B6730(void *p, int i)
{
    return ((int *)p)[i];
}






/*
 * Loads a character-data resource, optionally adds a3 to each of its
 * k2 * k3 u16 cells, then (when func_0204162C(a2) allows) copies it into
 * background a2 and loads its palette, and frees the resource.
 * The u8 stack arguments are re-read with ldrb before each call because the
 * callees take them as u8 (widths from func_020410D0.c and
 * func_020413B0.c); with u32 callee parameters k4..k6 stayed in registers
 * and the frame grew (200 bytes against 192). The loop bound is the
 * expression k2 * k3 and the add is `+=` with the uncast a3: a total local,
 * k3 * k2 and `arr[i] + (u16)a3` each cost a copy or swapped the loads.
 */
void func_021B6738(u32 a0, u32 a1, u32 a2, u32 a3,
                   u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7,
                   u8 k8, u32 k9, u16 k10)
{
    void *h;
    u8 *out;
    int i;
    u16 *arr;

    h = func_0204A380((void *)a0, a1, k9, (u16)((k10 & 0x7fff) | 0x8000));
    func_02062B30(h, (void **)(&out));
    if (a3 != 0) {
        if (func_0204169C((u8)a2) == 0) {
            arr = (u16 *)(out + 0xc);
            for (i = 0; i < k2 * k3; i++) {
                arr[i] += a3;
            }
        }
    }
    if ((int)func_0204162C((u8)a2)) {
        func_020410D0(a2, k4, k5, k6, k7, (u32)(out + 0xc), k0, k1, k2, k3);
        func_020413B0(a2, k4, k5, k6, k7, k8);
        func_020409B4(a2);
    }
    func_020307B0(h);
}






void func_021B67F8(Obj_021B66FC *p, u32 a1, void *a2, Src *src, u32 a4, u16 a5)
{
    Pos pos;
    u32 v0;
    u32 v1;
    u32 v2;
    int i;

    func_02082BCC(p, 0, 0x38);
    p->src = *src;
    p->f4 = 1;
    func_02082BCC(&pos, 0, 8);
    pos.x = src->x;
    pos.y = src->y;
    if (src->kind >= 7) {
        v0 = src->h8;
        v1 = src->hA;
        v2 = src->hC;
        p->f14 = 0;
    } else {
        v0 = func_021B6730(a2, 1);
        v1 = func_021B6730(a2, 0);
        v2 = func_021B6730(a2, 2);
        i = src->kind;
        p->src.hE = d_021B942C[i].a;
        p->src.h10 = d_021B942C[i].b;
        p->src.h12 = d_021B942C[i].c;
        p->src.h14 = d_021B942C[i].d;
        p->src.w18 = d_021B942C[i].f;
        p->src.w1C = d_021B942C[i].e;
        p->f14 = d_021B942C[i].g;
    }
    p->f8 = p->src.hE;
    pos.z = p->f8;
    p->f0 = (u32)(struct Obj *)func_0204B294((void *)a1, v0, v1, v2, &pos, a4, a5);
    func_0204B92C((struct Obj_021B66FC *)p->f0, 1);
    switch (p->f14) {
    case 0:
        p->fC = func_021B6A28;
        p->f10 = func_021B6A68;
        break;
    case 1:
        p->fC = func_021B6A44;
        p->f10 = func_021B6A98;
        break;
    }
}





/*
 * extent: trailing two-byte alignment padding at 0x021B6932.
 */
void func_021B691C(void **p)
{
    func_0204B3B4((struct Obj_021B66FC *)(*p));
    func_02082BCC(p, 0, 0x38);
}






int func_021B6934(S_021B66FC *p)
{
    u32 x;
    u32 y;
    int hit = 0;

    if (func_0204B3F4((struct Obj_021B66FC *)p->f00) & p->f04) {
        if (func_02035D20(&x, &y)) {
            if (x - p->f1c <= 0x18 && y - p->f1e <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        }
        if (p->f30 != 0 && (func_020362DC() & p->f30)) {
            func_020355D8(0);
            hit = 1;
        }
        if (hit) {
            p->f0c(p);
            return 1;
        }
    }
    return 0;
}






int func_021B69A4(void **p)
{
    if (func_0204B98C(*p) == 0) return 1;
    return 0;
}







/*
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 */
int func_021B69B8(void *p)
{
    return ((struct Obj20610 *)p)->f18;
}




void func_021B69BC(void *p, unsigned int v)
{
    func_0204B3DC((struct Obj_021B69A4 *)(((struct Obj20611 *)p)->f0), v);
}







int func_021B69C8(void *p, int a)
{
    return (*(int (**)(void *, int))((char *)p + 0x10))(p, a);
}







void func_021B69D0(void *p, int v)
{
    ((struct Obj20612 *)p)->f34 = v;
}







void func_021B69D4(void *p, int v)
{
    ((struct Obj20613 *)p)->f30 = v;
}







void func_021B69D8(struct S_021B69A4 *p, u32 v)
{
    if (v != 0)
        p->f8 = p->f2a;
    else
        p->f8 = p->f26;
    func_0204B878((struct Obj_021B69A4 *)p->f0, (u16)p->f8);
}






u32 func_021B69F8(u32 p) {
    int r = 1;
    if (*(u32 *)(p+8) != *(u16 *)(p+42) && *(u32 *)(p+8) != *(u16 *)(p+44)) r = 0;
    return r;
}




void func_021B6A10(void *p, unsigned int v)
{
    func_0204B800(((struct Obj20614 *)p)->f0, v);
}




/*
 * Two ARM9 tail calls on the pointer loaded from offset 0.
 */
void func_021B6A1C(void *p, unsigned int v)
{
    func_0204B84C(((struct Obj20615 *)p)->f0, v);
}






/*
 * extent: trailing two-byte alignment padding at 0x021B6A42.
 */
void func_021B6A28(u8 *p)
{
    ((struct Obj05146 *)p)->f8 = ((struct Obj05146 *)p)->f2A;
    func_0204B878((struct Obj_021B69A4 *)(((struct Obj05146 *)p)->f0), ((struct Obj05146 *)p)->f8);
    if (((struct Obj05146 *)p)->f34) func_020061E4((u32)(((struct Obj05146 *)p)->f34));
}







void func_021B6A44(u8 *p)
{
    u32 a = func_021B69F8((u32)p);
    int b = 1;

    if (a != 0) {
        b = 0;
    }
    func_021B69D8((struct S_021B69A4 *)p, b);
    if (((struct Obj13132 *)p)->f34 != 0) {
        func_020061E4(((struct Obj13132 *)p)->f34);
    }
}






/*
 * extent: trailing two-byte alignment padding at 0x021B6A96.
 */
void func_021B6A68(S_021B6A68 *p, u32 flag)
{
    p->f04 = flag;
    if (flag) {
        if (p->f08 == p->f2a) p->f08 = p->f26;
        func_0204B878((struct Obj_021B69A4 *)p->f00, p->f08);
    } else {
        func_0204B878((struct Obj_021B69A4 *)p->f00, p->f28);
    }
}







void func_021B6A98(S_021B6A98 *p, u32 flag)
{
    p->f04 = flag;
    if (flag) {
        if (p->f08 == p->f2a) {
            p->f08 = p->f2c;
        } else if (p->f08 == p->f28) {
            p->f08 = p->f26;
        }
        func_0204B878((struct Obj_021B69A4 *)p->f00, p->f08);
    } else {
        if (p->f08 == p->f2c) {
            p->f08 = p->f2a;
        } else if (p->f08 == p->f26) {
            p->f08 = p->f28;
        }
        func_0204B878((struct Obj_021B69A4 *)p->f00, p->f28);
    }
}







/*
 * note:     b and c are u16 as the matched caller ov067_func_021B6B2C passes
 *           them; the difference is written back into the parameter
 *           (`b = b - f()`): a separate u16 local y swapped p and b between
 *           r4/r5, and `b -= f()` truncates the call result first (worse).
 */
void func_021B6AE4(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3)
{
    b = b - func_021B6C4C((struct StrObj *)s0, s1, s3);
    func_0201C724(a, (u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj05378 *)p)->f0), (s16_021B69A4)b, (s16_021B69A4)c, s0, s1, s2);
    p[4] = 1;
}










/*
 * note:     the heap id and a4/a5 are reloaded from their stack slots before
 *           every call because the callees take them as u16 (with u32 callee
 *           parameters they stay in registers: 300 bytes); `a3 = a3 - f()`
 *           (`-=` truncates the call result first).
 */
void func_021B6B2C(u32_021B6B2C a0, void *a1, u32_021B6B2C a2, u16 a3, u16 a4, u16 a5, u32_021B6B2C a6, u32_021B6B2C a7, u16 heap)
{
    void *m;
    void *w;
    void *buf;
    void *s;
    u16 t;

    m = func_02045B38(0, 2, 0xa3, heap);
    w = func_0201EC64(heap);
    buf = func_020457B0(0xa, heap);
    s = func_02045EC0(m, 0);
    t = func_0201D304(s, a2, 0);
    func_021B6AE4((u8 *)a0, a1, a3, a4, (u32_021B6B2C)s, a2, a5, 2);
    a3 = a3 - func_021B6C4C(s, a2, 2);
    func_02045808(s);
    s = func_02045EC0(m, 1);
    func_0201EFA4(w, 0, a6, 8, 0, 1);
    func_0201F250(w, buf, s);
    func_021B6AE4((u8 *)a0, a1, a3, a4, (u32_021B6B2C)buf, a2, a5, 1);
    func_02045808(s);
    s = func_02045EC0(m, 2);
    func_0201EFA4(w, 0, a7, 8, 0, 1);
    func_0201F250(w, buf, s);
    func_021B6AE4((u8 *)a0, a1, a3 + t, a4, (u32_021B6B2C)buf, a2, a5, 0);
    func_02045808(s);
    func_02045808(buf);
    func_0201ED04(w);
    func_02045C04(m);
}









u16 func_021B6C4C(struct StrObj *s, u32_021B6C4C a, u32_021B6C4C mode)
{
    if (mode == 1) return func_0201D304(s, a, 0);
    if (mode == 2) return func_0201D304(s, a, 0) >> 1;
    return 0;
}










u32_021B6C74 *func_021B6C74(u32_021B6C74 *src, u32_021B6C74 n, u16 heap)
{
    u32_021B6C74 size;
    u32_021B6C74 *o;
    u32_021B6C74 i;

    size = n * 4 + 8;
    o = func_02030734(heap, size, 0, d_021B9558, 0x40);
    i = 0;
    func_02082BCC(o, 0, size);
    o[1] = n;
    for (i = 0; i < n; i++) {
        o[2 + i] = src[i];
    }
    o[0] = (u32_021B6C74)func_020457B0(0x80, heap);
    return o;
}










void func_021B6CCC(int *p)
{
    func_02045808((struct U16Vec *)p[0]);
    ENV_SetResourceSet(p);
}









/*
 * lever: struct bank array; explicit top-of-loop break preserves both guards.
 * ownership: Wave37 B7 conditional leaf cleared by parent after source/unit/SDK audit.
 * extent: two zero alignment bytes at 0x021B6D6E precede labelled 0x021B6D70.
 * residency: ov110 initializer 021C0134 loads 67; 021BAEDC creates caller+78 through ov067 021B6C74.
 */
u32_021B6CE0 func_021B6CE0(Obj_021B69A4 *p,u32_021B6CE0 id,u32_021B6CE0 unused,u32_021B6CE0 str,Pair_021B6B2C *out,u32_021B6CE0 max)
{
    u32_021B6CE0 count;
    u32_021B6CE0 n;
    void *bank;
    u32_021B6CE0 i,j,length;
    count=0;
    length=func_020458F8((void *)str);
    func_02082A7C(-1,out,max*8);
    if(length) {
        n=func_02045F50((const struct Obj_021B69A4 *)(p->bank[id]));
        bank=p->bank[id];
        i=0;
        j=0;
        for(;;i++) {
            if(i>=n) break;
            if(j>=max) break;
            func_02045CAC(bank,i,(void *)p->str);
            if(func_021B6D70(str,p->str,func_020458F8((void *)str))) {
                if(j<max) {
                    out[j].id=id;
                    out[j].index=i;
                    j++;
                }
                count++;
            }
        }
    }
    return count;
}










int func_021B6D70(u32_021B6D70 a, u32_021B6D70 b, u32_021B6D70 n)
{
    u16 *pa;
    u16 *pb;
    u32_021B6D70 i;

    if (func_020458F8((struct U16Vec *)a) < n) {
        return 0;
    }
    if (func_020458F8((struct U16Vec *)b) < n) {
        return 0;
    }
    pa = func_02045A90((struct U16Vec *)a);
    pb = func_02045A90((struct U16Vec *)b);
    for (i = 0; i < n; i++) {
        if (*pa++ != *pb++) {
            return 0;
        }
    }
    return 1;
}










S_021B6DC0 *func_021B6DC0(u16 heap, u32_021B6DC0 a1, u32_021B6DC0 a2, u32_021B6DC0 a3, u8 a4, u32_021B6DC0 a5, u32_021B6DC0 a6, u32_021B6DC0 a7)
{
    In in;
    Pltt *pl;
    void *q;
    void *h;
    void *buf;
    u32_021B6DC0 mode;
    S_021B6DC0 *p;
    u16 *src;
    u8 i;
    u8 j;
    u32_021B6DC0 flag;

    p = func_02030734(heap, 0xcc, 0, d_021B9564, 0xd3);
    mode = 0;
    func_02082BCC(p, 0, 0xcc);
    p->heap = heap;
    p->f4 = a5;
    p->f8 = a6;
    p->fC = a7;
    if (a1 > 3)
        mode = 4;
    p->f10 = mode;
    p->f14 = a1 + 1;
    p->f18 = a1;
    p->f15 = a2 + 1;
    p->f19 = a2;
    p->f16 = a3;
    p->f17 = a3 + 1;
    p->f1A = a3 + 2;
    flag = 0;
    if (a1 > 3)
        flag = 1;
    p->f1C = flag;
    p->f20 = a4;
    func_020414AC(p->f14);
    func_020414AC(p->f18);
    p->f98 = 0;
    p->f9c = 2;
    p->fC0 = 0;
    h = func_020490F4(0x53, p->heap);
    buf = func_02030734(p->heap, func_020493D4(h, 0xa3), 0, d_021B9564, 0x10d);
    func_0204932C(h, 0xa3, buf);
    func_02062A98(buf, (void **)(&pl));
    src = (u16 *)pl->data;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 16; j++) {
            p->pal[i][j] = src[(i + 1) * 16 + j];
        }
    }
    func_020307B0(buf);
    func_02049B68(h, 0xa3, p->f10, p->f16 << 5, 0x40, p->heap);
    p->f84 = func_02049740(h, 0xa4, p->f14, 0x1a0, 0, p->heap);
    func_020498F4(h, 0xa5, p->f14, (u16)p->f84, 0x600, 0, p->heap);
    func_020413B0(p->f14, 0, 0, 0x20, 0xb, p->f16);
    func_020413B0(p->f14, 0, 0xb, 0x20, 0xd, p->f17);
    func_020409B4(p->f14);
    func_02049238(h);
    func_021B7718(p->f10, p->f16, p->pal);
    func_021B7718(p->f10, p->f17, p->pal);
    func_02040588(p->f14, 0);
    func_02049B40(0x17, 5, p->f10, p->f1A << 5, 0x20, p->heap);
    p->f88 = func_020450F0(p->f18, 0, 5, 0x20, 6, p->f1A, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f88)), 0);
    p->f8c = func_020450F0(p->f18, 0, 0xb, 0x20, 6, p->f1A, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p->f8c)), 0);
    func_02040588(p->f18, 0);
    in.f0 = p->f1C;
    in.f4 = 0;
    in.f8 = 0xb;
    in.fC = 0x74;
    in.f10 = 0x77;
    in.f14 = 0x78;
    in.f18 = 0x79;
    in.b1c = p->f20;
    in.b1d = 0;
    in.b1e = 5;
    func_021B6208(p->fB0, &in, p->f4, p->heap);
    q = p->fB0;
    for (i = 0; i < 4; i++) {
        p->arrA0[i] = func_021B629C(q, p->f4, func_021B76C8(p->fC0, i, 0),
                                    func_021B76C8(p->fC0, i, 1), i, p->heap);
        func_0204B84C((void *)(p->arrA0[i]), p->f19);
        func_0204B3DC((struct Obj_021B69A4 *)p->arrA0[i], 0);
        func_0204B92C((struct Obj_021B66FC *)((struct Obj_021B69A4 *)p->arrA0[i]), 0);
    }
    if (p->f1C == 0)
        func_020434DC(0x10, 1);
    else
        func_02043598(0x10, 1);
    return p;
}










void func_021B709C(u8 *p)
{
    u8 i;
    u32 v;

    for (i = 0; i < 4; i++) {
        func_0204B3B4((struct Obj_021B66FC *)((struct Obj_021B69A4 *)(*(u32 *)(p + i * 4 + 0xa0))));
    }
    func_021B6284((unsigned int *)(p + 0xb0));
    func_020452E8((struct Descriptor *)(((struct Obj07677 *)p)->f88));
    func_020452E8((struct Descriptor *)(((struct Obj07677 *)p)->f8C));
    v = ((struct Obj07677 *)p)->f84;
    func_0203FB44(p[0x14], (u16)v, (u16)(v >> 16));
    func_020307B0(p);
}










void func_021B70F4(struct S_021B70F4 *s, u32 a1, u32 a2)
{
    Pt pt;
    u8 i;
    u32 t;
    int p;

    s->f98 = 1;
    s->f9c = 2;
    s->fC0 = 0;
    for (i = 0; i < 4; i++) {
        pt.x = func_021B76C8(s->fC0, i, 0);
        pt.y = func_021B76C8(s->fC0, i, 1);
        func_0204B404(s->arrA0[i], &pt, s->f1C);
    }
    func_021B7718(s->f10, s->f16, s->f22);
    func_021B7718(s->f10, s->f17, s->f22);
    func_02040588(s->f14, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f88)), 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f8c)), 0);
    t = func_0201D304((struct StrObj *)a1, s->f8, 0);
    func_0201C724((void *)s->fC, (int)func_02045770((struct Descriptor *)s->f88), (s16_021B6B2C)((u16)((0x100 - t) / 2)), (s16_021B6B2C)0x10, a1, s->f8, 0x3c40);
    t = func_0201D304((struct StrObj *)a2, s->f8, 0);
    func_0201C724((void *)s->fC, (int)func_02045770((struct Descriptor *)s->f8c), (s16_021B6B2C)((u16)((0x100 - t) / 2)), (s16_021B6B2C)0x10, a2, s->f8, 0x3c40);
    s->f90 = 0;
    s->f94 = 0;
    func_02040588(s->f18, 1);
    if (s->f90 == 0 && func_0201C6C4((struct PrintSys *)s->fC, (void *)((int)func_02045770((struct Descriptor *)s->f88))) == 0) {
        p = s->f88;
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        s->f90 = 1;
    }
    if (s->f94 == 0 && func_0201C6C4((struct PrintSys *)s->fC, (void *)((int)func_02045770((struct Descriptor *)s->f8c))) == 0) {
        p = s->f8c;
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        s->f94 = 1;
    }
    if (func_020355C4() == 0) {
        for (i = 0; i < 4; i++) {
            func_0204B3DC((struct Obj_021B69A4 *)s->arrA0[i], 1);
            func_0204B92C((struct Obj_021B66FC *)((struct Obj_021B69A4 *)s->arrA0[i]), 1);
        }
    }
}










void func_021B72DC(struct S_021B72DC *s)
{
    int p;
    u8 i;

    func_02040588(s->f14, 0);
    func_02040588(s->f18, 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f88)), 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->f8c)), 0);
    p = (int)s->f88;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    p = (int)s->f8c;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
    for (i = 0; i < 4; i++) {
        func_0204B3DC((struct Obj_021B69A4 *)s->arrA0[i], 0);
        func_0204B92C((struct Obj_021B66FC *)(s->arrA0[i]), 0);
    }
    s->f98 = 0;
}









void func_021B7378(S_021B7378 *p)
{
    Rect12 rect;
    u32 x;
    u32 y;
    u16 pt[2];
    int update;
    int touch;
    int handled;
    u32 keys;
    int changed;
    u8 i;
    void *o;

    update = 0;
    keys = func_020362DC();
    touch = func_02035D20(&x, &y);
    switch (p->f98) {
    case 0:
        break;
    case 1:
        p->f98 = 2;
        break;
    case 2:
        handled = 0;
        if (keys & 2) {
            func_020061E4(0x552);
            p->f9c = 0;
            handled = 1;
            func_020355D8(0);
        }
        if (!handled && func_020355C4() == 0 && keys != 0) {
            changed = 0;
            if (keys & 1) {
                if (p->fc0 == 0) {
                    func_020061E4(0x54d);
                    p->f9c = 1;
                } else {
                    func_020061E4(0x552);
                    p->f9c = 0;
                }
                handled = 1;
            } else if (keys & 0x40) {
                if (p->fc0 != 0) {
                    p->fc0 = 0;
                    changed = 1;
                }
            } else if (keys & 0x80) {
                if (p->fc0 != 1) {
                    p->fc0 = 1;
                    changed = 1;
                }
            }
            if (changed) {
                for (i = 0; i < 4; i++) {
                    pt[0] = func_021B76C8(p->fc0, i, 0);
                    pt[1] = func_021B76C8(p->fc0, i, 1);
                    func_0204B404((int)(p->fa0[i]), (Pt *)((const struct Vec2 *)pt), (u16)p->f1c);
                }
                func_020061E4(0x548);
            }
        }
        if (!handled && touch != 0) {
            int res;
            rect = d_021B94C4;
            res = (int)func_02035D40((struct Ctx *)(&rect), x, y);
            if (res != -1) {
                if (res == 0) {
                    func_020061E4(0x54d);
                    p->f9c = 1;
                } else if (res == 1) {
                    func_020061E4(0x552);
                    p->f9c = 0;
                }
                handled = 1;
                func_020355D8(1);
            }
        }
        if (!handled && func_020355C4() == 1 && keys != 0) {
            for (i = 0; i < 4; i++) {
                func_0204B3DC((struct Obj_021B69A4 *)(p->fa0[i]), 1);
                func_0204B92C((struct Obj_021B66FC *)(p->fa0[i]), 1);
            }
            func_020061E4(0x548);
            func_020355D8(0);
        }
        if (handled) {
            for (i = 0; i < 4; i++) {
                func_0204B3DC((struct Obj_021B69A4 *)(p->fa0[i]), 0);
                func_0204B92C((struct Obj_021B66FC *)(p->fa0[i]), 0);
            }
            p->f98 = 3;
            p->fc4 = 0;
            p->fc8 = 1;
            p->fc6 = 1;
        }
        break;
    case 3:
        if (p->fc6 < 10) {
            if (p->fc8 == d_021B94D0[p->fc6].frame) {
                p->fc4 = d_021B94D0[p->fc6].idx;
                update = 1;
                p->fc6++;
            }
            p->fc8++;
        } else {
            p->f98 = 4;
        }
        break;
    case 4:
        break;
    }
    if (p->f98 != 0) {
        if (p->f90 == 0 && func_0201C6C4((struct PrintSys *)p->fc, (void *)((int)func_02045770(p->f88))) == 0) {
            o = p->f88;
            func_02045334(o);
            func_02045374(o);
            func_02041B6C(func_02045730(o));
            p->f90 = 1;
        }
        if (p->f94 == 0 && func_0201C6C4((struct PrintSys *)p->fc, (void *)((int)func_02045770(p->f8c))) == 0) {
            o = p->f8c;
            func_02045334(o);
            func_02045374(o);
            func_02041B6C(func_02045730(o));
            p->f94 = 1;
        }
    }
    if (update) {
        func_021B7718((u32)p->f10, (u8)(p->f9c == 1 ? p->f16 : p->f17), p->f22[p->fc4]);
    }
}









/*
 * Unlabelled leaf after func_021B7378's pool (inside its handed extent).
 */
int func_021B76B0(S_021B76B0 *p)
{
    if (p->f98 != 0 && p->f98 != 4)
        return 2;
    return p->f9c;
}









u8 func_021B76C8(u32 a, u32 b, u32 c)
{
    T1 t1 = d_021B94B8;
    T2 t2 = d_021B94BC;
    return t1.v[a][c] + t2.v[b][c];
}








/*
 * The handed 596-byte extent also holds the unlabelled follower
 * 0x021B7754 (filed separately).
 */
void func_021B7718(int which, int idx, void *data)
{
    int type;

    switch (which) {
    case 0:
        type = 0xf;
        break;
    case 1:
        type = 0xe;
        break;
    case 4:
        type = 0x1f;
        break;
    case 5:
        type = 0x1e;
        break;
    case 2:
    case 3:
        return;
    default:
        return;
    }
    func_02061CA4((void *)type, idx << 5, (u32)data, 0x20);
}








/*
 * Unlabelled follower inside func_021B7718's handed 596-byte extent: a
 * 0x9c-byte object constructor (the listing gives it no label).  The f4a
 * loop is the compound `-=`: it keeps &p->f4a in a register for the body's
 * load and store, while the test reloads through p.
 */
S_021B7754 *func_021B7754(Tmpl *tmpl, u32 heap)
{
    S_021B7754 *p;
    u32 i;
    u32 n;

    p = func_02030734(heap, sizeof(S_021B7754), 1, d_021B9574, 0xf5);
    p->t = *tmpl;
    p->f98 = heap;
    p->f54 = -1;
    p->f58 = -1;
    p->f34 = func_0201C450(0x800, heap);
    p->f30 = func_0202E940(p->t.f11 << 4, 0x10, p->t.f0, p->f98);
    p->f28 = func_02030734(p->f98, p->t.f14 * 8, 1, d_021B9574, 0x104);
    if (p->t.f16 != 0) {
        p->f40 = func_02030734(p->f98, p->t.f16 * 4, 0, d_021B9574, 0x109);
        for (i = 0; i < p->t.f16; i++)
            p->f40[i] = func_02030734(p->f98, p->t.f4 * p->t.f5 * 2, 0, d_021B9574, 0x10b);
    }
    p->f44 = 0x18 / p->t.f5 + 2;
    p->f45 = p->f44;
    if (p->t.f1 != 0xff)
        p->f44 = p->f44 * 2;
    p->f3c = func_0202C9B4(2, p->f44, p->f98);
    p->f38 = func_02030734(p->f98, p->f44 * 8, 0, d_021B9574, 0x117);
    for (i = 0; i < p->f44; i++) {
        if (p->t.f1 != 0xff && p->f45 <= i) {
            func_0202CA3C(p->f3c, i, p->t.f1, p->t.f4, p->t.f5);
            p->f38[i].w = func_020450F0(p->t.f1, p->t.f6, p->t.f7, p->t.f8, p->t.f9, p->t.fa, 1);
        } else {
            func_0202CA3C(p->f3c, i, p->t.f0, p->t.f4, p->t.f5);
            p->f38[i].w = func_020450F0(p->t.f0, p->t.f6, p->t.f7, p->t.f8, p->t.f9, p->t.fa, 1);
        }
    }
    p->f4a = 0x18;
    do {
        p->f4a -= (s8)p->t.f5;
    } while (p->f4a > 0);
    if (p->t.f1c != 0) {
        n = 0;
        for (;;) {
            if (p->t.f1c[n].f0 == 0xff)
                break;
            n++;
        }
        p->f2c = func_02030734(p->f98, (n + 1) * 4, 0, d_021B9574, 0x13e);
        for (i = 0; i < n + 1; i++)
            func_02082A90(&p->t.f1c[i], &p->f2c[i], 4);
    }
    return p;
}








void func_021B796C(struct Scene *s)
{
    u32 i;

    ENV_SetResourceSet(s->f2c);
    for (i = 0; i < s->count; i++)
        func_020452E8((struct Descriptor *)((int)s->f38[i].p));
    ENV_SetResourceSet(s->f38);
    func_0202CA0C(s->f3c);
    if (s->f16 != 0) {
        for (i = 0; i < s->f16; i++)
            ENV_SetResourceSet(s->f40[i]);
        ENV_SetResourceSet(s->f40);
    }
    ENV_SetResourceSet(s->f28);
    func_0202EA20((struct Obj0202EA20 *)((int)s->f30));
    func_0201C4C0((struct PrintSys *)((int)s->f34));
    ENV_SetResourceSet(s);
}







void func_021B79E4(char *ctx, unsigned first, unsigned second)
{
    (*(Pair_021B7718 **)(ctx + 0x28))[*(unsigned short *)(ctx + 0x4c)].first = first;
    (*(Pair_021B7718 **)(ctx + 0x28))[*(unsigned short *)(ctx + 0x4c)].second = second;
    (((struct Obj20620 *)ctx)->f4C)++;
}







/*
 * prototype: 02049EF4 preserves r3 in r5 and forwards it unchanged to
 * 02062B30, which writes through it; use a pointer for the full-word payload.
 */
void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index)
{
    void *out;
    void *handle;
    handle = func_02049EF4((void *)a, b, c, &out, ((struct Obj09863 *)p)->f98);
    func_02082A60((u8 *)out + 0xc, (*(void ***)(p + 0x40))[index], p[4] * p[5] * 2);
    func_020307B0(handle);
}







/*
 * extent: trailing two-byte alignment padding at 0x021B7A62.
 */
void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    func_0202E9AC(*(struct CodeIn * *)&((struct Obj20621 *)p)->f30, a, b, c << 4, d << 4);
}








int func_021B7A64(struct Scene *p)
{
    switch (p->f4e) {
    case 0:
        func_021B7B7C(p);
        func_021B7BE0(p, 0);
        p->f4e = p->f4e + 1;
        break;
    case 1:
        if (func_0201C6B4((const struct PrintSys *)p->f34) == 1) {
            p->f4e = 0;
            return 0;
        }
        break;
    }
    func_021B9344(p);
    return 1;
}







int func_021B7AB0(struct Scene *p)
{
    int buf;
    int ret = -1;

    if (func_02035CB8((u32 *)(&buf), (u32 *)(&p->f54)) == 0) {
        p->f54 = -1;
        p->ready = 0;
    }
    switch (p->f4e) {
    case 0:
        ret = func_021B806C(p);
        break;
    case 1:
        if (func_021B8460(p) == 1)
            ret = -10;
        break;
    case 2:
        if (func_021B8B74(p) == 1)
            ret = -9;
        break;
    case 3:
        if (func_021B8C4C(p) == 1)
            ret = -8;
        break;
    case 4:
        if (func_020355C4() == 0 && (func_020362DC() & 1))
            ret = p->f5c;
        if (p->f96 == 0)
            p->f4e = 0;
        else
            p->f96--;
        break;
    }
    p->f58 = p->f54;
    func_0202EA40(p->f30);
    func_021B9344(p);
    return ret;
}







void func_021B7B7C(struct Scene *p)
{
    if (p->f19 > p->f4c) {
        p->f5e = p->f4c;
    } else {
        p->f5e = p->f19;
    }
    if (p->f4c < p->f19) {
        p->f64 = 0;
    } else {
        p->f64 = p->f4c - p->f19;
    }
    if (p->f18 > p->f5e || p->f1a > p->f64) {
        p->f5c = 0;
        p->f62 = 0;
    } else {
        p->f5c = p->f18;
        p->f62 = p->f1a;
    }
}







/*
 * f5 is a u8 read as (s8) in every loop step; the one uncast read in the
 * second window's start (`f3 + 0x18 - f5`) is what makes the original load
 * it with ldrb and sign-extend the CSE'd copy for the loop.  All four loops
 * are `for (;;) { if (!cond) break; ... }` (top test, unconditional b back).
 */
void func_021B7BE0(struct Scene *p, int a1)
{
    s16_021B6B2C i;
    s8 j;

    func_02041EE4(p->f0, 3, 0);
    p->f66 = 0;
    i = p->f62;
    j = p->f3;
    for (;;) {
        if (i == 0 || j <= 0)
            break;
        i = i - 1;
        j = j - (s8)p->f5;
    }
    p->f46 = 0;
    for (;;) {
        if (j >= 0x18)
            break;
        func_021B91D0(p, i, j);
        p->f46++;
        i = i + 1;
        j = j + (s8)p->f5;
    }
    p->f48 = p->f46;
    if (p->f1 == 0xff)
        return;
    func_02041EE4(p->f1, 3, 0);
    j = p->f3 + 0x18 - p->f5;
    i = p->f62 - 1;
    for (;;) {
        if (j <= 0)
            break;
        i = i - 1;
        j = j - (s8)p->f5;
    }
    p->f47 = 0;
    for (;;) {
        if (j >= 0x18)
            break;
        func_021B9228(p, i, j);
        p->f47++;
        i = i + 1;
        j = j + (s8)p->f5;
    }
    p->f49 = p->f47;
    func_021B92F0(p, (u16)p->f5c, 0xff);
    p->f20->f4(p->f24, p->f5c + p->f62, a1);
}







/*
 * The case-8 arm is laid out first in the original (the jump table's last
 * entry is its smallest displacement), so it is written first in the switch.
 */
int func_021B7CF8(struct Scene *p)
{
    int idx;
    u8 save;

    if (p->f2c == 0)
        return 14;
    idx = func_02035C08(p->f2c);
    if (idx == -1)
        return 14;
    save = func_020355C4();
    func_020355D8(1);
    switch (p->f1c[idx].f4) {
    case 8:
        if (idx >= p->f5e)
            return 13;
        p->f60 = p->f5c;
        p->f5c = idx;
        return 12;
    case 0:
        if (idx >= p->f5e)
            return 13;
        p->f60 = p->f5c;
        p->f5c = idx;
        return 11;
    case 1:
        if (p->f4c > p->f5e) {
            p->f7c = idx;
            p->f60 = p->f5c;
            return 10;
        }
        func_020355D8(save);
        break;
    case 2:
        if (p->f62 != 0) {
            p->f95 = 0;
            return 2;
        }
        break;
    case 3:
        if (p->f62 < p->f64) {
            p->f95 = 0;
            return 3;
        }
        break;
    case 4:
        if (p->f62 != 0)
            return 4;
        if (p->f5c != 0) {
            p->f60 = p->f5c;
            p->f5c = 0;
            return 6;
        }
        break;
    case 5:
        if (p->f62 < p->f64)
            return 5;
        if (p->f5c < p->f5e - 1) {
            p->f60 = p->f5c;
            p->f5c = p->f5e - 1;
            return 7;
        }
        break;
    case 6:
        if (p->f5c != 0 || p->f62 != 0)
            return 8;
        break;
    case 7:
        if (p->f5c != p->f5e - 1 || p->f62 != p->f64)
            return 9;
        break;
    }
    return 14;
}







/*
 * The 0x40/0x80 arms re-read f5c after the f60 store (`p->f5c--`/`++`);
 * the 0x80 arm loads f5e before f5c and still compares f5c on the left,
 * which only the named bound `n = p->f5e - 1` gives.
 */
int func_021B7E70(struct Scene *p)
{
    int n;

    if ((func_020362DC() & 0x3f1) && func_020355C4() == 1) {
        func_020355D8(0);
        p->f60 = 0xff;
        p->f96 = 8;
        return 0;
    }
    if (func_0203630C() == 0) {
        p->f94 = 0;
        p->f95 = 6;
    }
    if (func_0203630C() & 0x40) {
        func_020355D8(0);
        if (p->f5c != 0) {
            p->f60 = p->f5c;
            p->f5c--;
            p->f96 = 8;
            return 1;
        }
        if (p->f62 != 0) {
            p->f96 = 0;
            func_021B83A0(p);
            return 2;
        }
        return 14;
    }
    if (func_0203630C() & 0x80) {
        func_020355D8(0);
        n = p->f5e - 1;
        if (p->f5c < n) {
            p->f60 = p->f5c;
            p->f5c++;
            p->f96 = 8;
            return 1;
        }
        if (p->f62 < p->f64) {
            p->f96 = 0;
            func_021B83A0(p);
            return 3;
        }
        return 14;
    }
    if (func_0203630C() & 0x20) {
        func_020355D8(0);
        if (p->f62 != 0) {
            p->f96 = 4;
            return 4;
        }
        if (p->f5c != 0) {
            p->f60 = p->f5c;
            p->f5c = 0;
            p->f96 = 4;
            return 6;
        }
        return 14;
    }
    if (func_0203630C() & 0x10) {
        func_020355D8(0);
        if (p->f62 < p->f64) {
            p->f96 = 4;
            return 5;
        }
        if (p->f5c < p->f5e - 1) {
            p->f60 = p->f5c;
            p->f5c = p->f5e - 1;
            p->f96 = 4;
            return 7;
        }
        return 14;
    }
    if (func_020362DC() & 1)
        return 12;
    if (func_020362DC() & 0x200) {
        func_020355D8(0);
        if (p->f5c != 0 || p->f62 != 0)
            return 8;
        return 14;
    }
    if (func_020362DC() & 0x100) {
        func_020355D8(0);
        if (p->f5c != p->f5e - 1 || p->f62 != p->f64)
            return 9;
        return 14;
    }
    return 14;
}






int func_021B806C(struct Scene *s)
{
    int r;
    s16_021B7CF8 v;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return -1;
    r = func_021B7CF8(s);
    if (r == 14)
        r = func_021B7E70(s);
    switch (r) {
    case 0:
        func_020061E4(0x548);
        func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -12;
    case 1:
        func_020061E4(0x548);
        func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -11;
    case 2:
        func_021B8434((u8 *)s, (s8)(-s->fb[s->f95]), 1, 4, 1);
        return -10;
    case 3:
        func_021B8434((u8 *)s, (s8)s->fb[s->f95], 1, 4, 1);
        return -10;
    case 4:
        v = s->f5e;
        s->f60 = s->f5c;
        if (s->f62 - v < 0) {
            s->f5c = 0;
            v = s->f62;
        }
        func_021B92F0(s, (u16)0xff, (u16)s->f60);
        func_021B8434((u8 *)s, (s8)(-s->fb[0]), v, 4, 0);
        func_020061E4(0x548);
        return -7;
    case 5:
        v = s->f5e;
        s->f60 = s->f5c;
        if (s->f62 + v > s->f64) {
            s->f5c = s->f5e - 1;
            v = s->f64 - s->f62;
        }
        func_021B92F0(s, (u16)0xff, (u16)s->f60);
        func_021B8434((u8 *)s, (s8)s->fb[0], v, 4, 0);
        func_020061E4(0x548);
        return -6;
    case 6:
        func_020061E4(0x548);
        func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -5;
    case 7:
        func_020061E4(0x548);
        func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        s->f4e = 4;
        return -4;
    case 8:
        s->f5c = 0;
        s->f62 = 0;
        func_021B7BE0(s, 1);
        func_020061E4(0x548);
        return -3;
    case 9:
        s->f5c = s->f5e - 1;
        s->f62 = s->f64;
        func_021B7BE0(s, 1);
        func_020061E4(0x548);
        return -2;
    case 10:
        func_021B92F0(s, (u16)0xff, (u16)s->f60);
        func_021B8990(s, s->f7c);
        func_020061E4(0x645);
        return -9;
    case 11:
        func_021B92F0(s, (u16)0xff, (u16)s->f60);
        s->f20->f4(s->f24, s->f5c + s->f62, 1);
        func_021B8C14(s, s->f5c);
        func_020061E4(0x645);
        return -8;
    case 12:
        if (func_020355C4() == 1) {
            func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
            s->f20->f4(s->f24, s->f5c + s->f62, 1);
        }
        return s->f5c;
    case 13:
    case 14:
        break;
    }
    return -1;
}






void func_021B83A0(struct Scene *p)
{
    u8 v;
    if (p->f94 < 20) {
        p->f94 = p->f94 + 1;
    }
    v = p->f94;
    if (v == 20) {
        p->f95 = 0;
    } else if (v >= 16) {
        p->f95 = 1;
    } else if (v >= 12) {
        p->f95 = 2;
    } else if (v >= 8) {
        p->f95 = 3;
    } else if (v >= 4) {
        p->f95 = 4;
    } else {
        p->f95 = 5;
    }
}





/*
 * extent: trailing two-byte alignment padding at 0x021B841A.
 * Zero divisors remain admitted; call the ROM runtime helper directly.
 */
u8 func_021B8404(u8 *p, int n)
{
    if (n < 0) n = (int)(0u - (unsigned int)n);
    return _s32_div_f(p[5] << 3, n);
}





int func_021B841C(u8 *p, int n)
{
    if (n < 0) return ((struct Obj09864 *)p)->f62;
    return ((struct Obj09864 *)p)->f64 - ((struct Obj09864 *)p)->f62;
}






void func_021B8434(u8 *p, s8 a, u8 b, u16 c, u32 d)
{
    p[0x67] = a;
    p[0x68] = b;
    p[0x69] = 0;
    ((struct Obj05147 *)p)->f50 = c;
    ((struct Obj05147 *)p)->f4E = 1;
    ((struct Obj05147 *)p)->f6C = d;
}





#pragma opt_propagation off





/*
 * 2026-10-05 (wD9r P4): 5 bytes differ, size equal (1328), 27 of 27 relocations resolved. Residue: the
 *   second f1c table read (offsets 0134..013A, the `r != -1 && table[r].f4 == 0 && ready == 1 && table[r].f4 == 0`
 *   test) is `ldr r0,[f1c]; lsls r1,r4,#3; adds r0,r0,#4; ldr r1,[r0,r1]` in the original (base+4 added
 *   first, register-offset load); we emit `ldr r1,[f1c]; lsls r0,r4,#3; adds r0,r1,r0; ldr r1,[r0,#4]`.
 *   The earlier draft (docs/notes/pkt_ov067_021B8460.c.txt) used an inline `second()` helper and
 *   `count += (u8)1`; both were dropped here (plain `s->f1c[r].f4` and `count++` give the same 5 bytes).
 *   Tried (25 compiles): plain f1c[r].f4 twice; struct Ent_021B83A0 pointer at +4; header struct with Ent_021B83A0 e[1];
 *   integer base `(u32)f1c + 4 + r*8` and `+ r*8 + 4`; u8 * base; `&f1c->f4 + r*8` and
 *   `(&f1c->f4)[r*2]`; u8 * field type; a local q = f1c+4 set before the test (gives the original
 *   `adds #4` + register-offset form, but q is hoisted above the `r != -1` compare, so 15 bytes differ),
 *   q set in a comma expression (propagated, 5), q set under `if (r != -1)` (966, q takes r6);
 *   all six per-function pragmas (lifetimes, propagation, dead_assignments, scheduling, peephole: 5;
 *   common_subs: 971); --lang c (5). Idioms checked: indexed-field-stays-inline-or-base-and-index-swap
 *   (5), pointer-sum-with-a-far-offset-associates-differently (5), a-loop-indexes-the-base-and-leaves-
 *   the-field-offset-in-place (5), an-integer-table-base-multiplies-into-a-copy-of-the-index (5),
 *   a-far-offset-before-the-index-keeps-base-and-index-separate-across-calls (5).
 * 2026-10-05 (wD9r P4b, 25 more compiles, all still 5 bytes unless noted): the differing read at 0134 is the ONLY
 *   table read in this block; the original reuses r1 for the second `cmp r1,#0` at 014E, so the two tests share one
 *   load (our CSE does the same). Tried: u32 (*f1c)[2] with f1c[r][1]; static inline IsFree(t,r) for one or both
 *   tests; (&f1c->f4)[r*2] and ((u32 *)f1c + 1 + r*2) on both tests (5), on one test only (915, second read not
 *   CSE'd); inline F4(const u32 *p,int r){return p[r*2];} on &f1c->f4 for both/one test; a second struct Ent2 at
 *   f1c+4 indexed [r].a through a cast or an inline helper; u32 local `t` assigned in the condition
 *   `(t = ...) == 0 && ready == 1 && t == 0`; the condition split into two nested ifs with a `goto fail` into the
 *   else block; f1c without const (5); volatile f4 (996, and a stand-in). Observation: with the pointer-sum form on a
 *   single uncached read, the base/index registers match (r0/r1) but the add is `adds r1,r0,r1; ldr [r1,#4]`;
 *   with a CSE'd read they swap (r1/r0). The original has base+4 as a separate node plus the shifted index.
 *   Open: a source where base+4 is a value live only inside the block after the `r != -1` branch
 *   (a local read twice would stay unpropagated) without being live across later blocks.
 *
 * recoup 2026-10-05 (R12, 15 compiles, all still 5 bytes unless noted): levers 1-2 n/a (callees and widths
 *   already from matched callers; f4 is a plain u32). Lever 3 n/a (no spill slots, r is r4 in both). Lever 4:
 *   table pointer local `t = s->f1c` set right after the call (10 bytes, ldr hoisted above the -1 compare);
 *   `q = &f1c->f4` set in a comma expression, with opt_propagation / opt_lifetimes / opt_dead_assignments off
 *   (15 each, q hoisted above the compare). Lever 5/6: `p = &f1c[r].f4` read once and reused (5);
 *   `*(u32 *)((u8 *)f1c + (r<<3) + 4)`, `4 + (u8 *)f1c + r*8`, `(*(u32 (*)[2])(f1c+r))[1]` (5 each);
 *   `((u32 *)f1c)[r*2+1]` on both tests (1332 B, lsls/adds/lsls form); q scoped inside `if(r!=-1)` with the
 *   success path reached by goto (1328 B, 163 differ, still folds `adds r0,r1,r0; ldr [r0,#4]`).
 *   Finding: every form that keeps base+4 as a tree node is folded into the load offset; every form that
 *   keeps it unfolded (a named local) is hoisted above the `r != -1` compare. Residue unchanged.
 *   Idioms checked this pass: none new beyond the five listed above.
 *
 *   round 2 (27 more compiles, 37 total, 5 bytes unless noted): different spellings on the two tests (995 off, 1332 B);
 *   `(r<<1)+1` / `r<<1|1` / `r*2+1` u32 index forms (1332-1336 B, 1000 off); `q=(u8 *)f1c+4` assigned inside the first
 *   test and reused (5); a DEAD `q=(u8 *)f1c+4` in the first test with the second test spelled
 *   `*(u32 *)((u8 *)f1c + 4 + r*8)` gives 3 bytes (registers and lsls order match, only `adds r0,#4; ldr [r0,r1]`
 *   vs `adds r0,r0,r1; ldr [r0,#4]` differs) but the dead q is a stand-in, not filed; off=r*8 local (5, 11 when set
 *   before the -1 test); `(&f1c[r].f0)[1]`, `((const Ent_021B83A0 *)((u8 *)f1c + r*8))->f4`, `*(&f1c->f4 + r*2)` (5);
 *   static inline Rd(base,off) with the +4 in the caller or the callee, Fld() returning f1c+4, Free(const Ent_021B83A0 *),
 *   Free(const u32 *) (5 each); `*(const Ent_021B83A0 *const *)&f1c` (5); u32 `f1c` field with `[r*2+1]` (1336 B); pragmas
 *   opt_loop_invariants off and opt_strength_reduction off (5). Asm grep for `adds rN,#4; ldr [rN,rM]` with any shift
 *   finds only this function (other hits are folded constant offsets). The original needs base+4 as an unfolded node;
 *   mwcc folds a constant into the load offset unless the sum has another use, and no use of f1c+4 exists in this block.
 *
 * pass 2 2026-10-06 P2L07: EXACT. Closed with `#pragma opt_propagation off` and two named locals set in
 *   the second test after the `r != -1` compare: a byte offset `o = r*8` assigned first, then a byte pointer
 *   `q = (const u8 *)s->f1c + 4`, and both reads spelled `*(u32 *)(q + o)`. The named pointer keeps base+4 as
 *   its own value (register-offset load); assigning the offset first gives the original `lsls` before `adds #4`.
 *   Without the offset local (q only) 3 bytes differ (adds/lsls order swapped). EXACT in --lang c99 and --lang c.
 */
int func_021B8460(struct Scene *s)
{
 int r,n,v,a; s8 w; const u8 *q; int o;
 if((int)func_0201C6B4((const struct PrintSys *)s->f34)==0) return 1;
 if(s->f50==3 && s->f70==1) {
  r=func_02035BA4(s->f2c);
  if(s->drag==1) {
   if(s->trigger==0) {
    if(r==-1) {
     s->f85=s->f90-s->f8c;
     a=s->f85;
     if(a<0) a=-a;
     if(a>=16) { s->f86=0; s->drag=0; s->trigger=1; }
    } else if(s->f86!=3) {
     s->f8c=s->f54;
     s->f86++;
    }
   }
  } else if(r!=-1 && s->f1c[r].f4==0) {
   s->f5c=r;
   s->drag=1;
   s->f86=0;
   s->f8c=s->f54;
   s->f90=s->f54;
  }
 }
 if(s->f69==0) {
  if(s->f68==0) {
   r=func_02035BA4(s->f2c);
   if(r!=-1 && (o=r*8, q=(const u8 *)s->f1c+4, *(u32 *)(q+o)==0) && s->ready==1 && *(u32 *)(q+o)==0 &&
     ((s->f85<0 && s->f87<r)||(s->f85>0 && s->f87>r))) {
    s->ready=0;
    n=func_021B841C((u8 *)s,s->f67);
    if(n!=0) {
     v=s->f87-r;
     if(v<0) v=-v;
     s->f68=v;
     if(s->f68>(u32)n) s->f68=n;
     s->f87=r;
    } else {
     s->f8c=s->f54;
     s->f90=s->f54;
     s->drag=0;
     func_021B92F0(s, (u16)s->f5c, 255);
     s->f4e=s->f50;
     return 0;
    }
   } else {
    s->f8c=s->f54;
    s->f90=s->f54;
    s->ready=0;
    s->drag=0;
    func_021B92F0(s, (u16)s->f5c, 255);
    s->f4e=s->f50;
    return 0;
   }
  }
  func_021B92F0(s, 255, (u16)s->f5c);
  if(s->f50==3) {
   if(s->f70==0) {
    if(s->f67<0) s->f5c++;
    else s->f5c--;
   } else {
    if(s->trigger==1) {
     if(func_021B8EA0(s)==1) s->f86=0;
     s->trigger=0;
    }
    if(s->drag==1 && s->f86==3) {
     r=func_02035BA4(s->f2c);
     if(r!=-1 && s->f1c[r].f4==0) s->f5c=r;
     s->f70=0;
     s->f87=s->f5c;
     s->drag=0;
     s->f86=0;
     s->f8c=s->f54;
     s->f90=s->f54;
     s->f20->f4(s->f24,s->f5c+s->f62,1);
     s->f4e=s->f50;
     return 0;
    }
    if(s->f68==1) {
     n=func_021B841C((u8 *)s,s->f67);
     s->f89++;
     if(s->f89!=6) {
      if(s->f67<0) s->f67=-*((u8 *)s+s->f89+11);
      else s->f67=*((u8 *)s+s->f89+11);
      s->f68=d_021B94F8[s->f89];
     }
     if(s->f68>(u32)n) s->f68=n;
    }
   }
  }
  s->f69=func_021B8404((u8 *)s,s->f67);
  s->f68--;
  if(s->f67<0) {
   s->f62--;
   w=func_021B9190((s8 *)s,-1);
   func_021B91D0(s, s->f62, w);
   s->f46=func_021B91BC(s->f46,s->f48,-1);
   w=func_021B9190((s8 *)s,-1);
   func_021B9228(s, s->f62-s->f49, s->f4a+w);
   s->f47=func_021B91BC(s->f47,s->f49,-1);
  } else {
   s->f62++;
   w=func_021B9190((s8 *)s,1);
   func_021B91D0(s, s->f62+(s->f48-1), w);
   s->f46=func_021B91BC(s->f46,s->f48,1);
   w=func_021B9190((s8 *)s,1);
   func_021B9228(s, s->f62-1, s->f4a+w);
   s->f47=func_021B91BC(s->f47,s->f49,1);
  }
  s->f20->f4(s->f24,s->f5c+s->f62,1);
  if(s->f6c==1) {
   if((u16)(s->f50+0xfffe)<=1) func_020061E4(0x645);
   else func_020061E4(0x548);
  }
 }
 s->f66=s->f66+s->f67;
 func_02041EE4(s->f0,3,(int)s->f66);
 if(s->f1!=255) func_02041EE4(s->f1,3,(int)s->f66);
 s->f20->f8(s->f24,s->f67);
 s->f69--;
 return 1;
}





#pragma opt_propagation reset






void func_021B8990(struct Scene *s, int idx)
{
    int buf;
    u8 *e;
    int t;
    unsigned u;

    s->f7d = s->f2c[idx * 4];
    e = s->f2c + idx * 4;
    s->f7e = e[1];
    s->f74[0] = s->f2c[idx * 4];
    s->f74[1] = e[1];
    s->f74[2] = e[2];
    s->f74[3] = e[3];
    u = s->f74[0];
    if (u >= 0x20)
        u -= 0x20;
    else
        u = 0;
    s->f74[0] = u;
    t = s->f74[1] + 0x20;
    if (t <= 0xbf)
        s->f74[1] = t;
    else
        s->f74[1] = 0xbf;
    u = s->f74[2];
    if (u < 0)
        u = 0;
    s->f74[2] = u;
    t = s->f74[3];
    if (t <= 0xff)
        s->f74[3] = t;
    else
        s->f74[3] = 0xff;
    s->f74[4] = 0xff;
    if (func_02035CB8((u32 *)(&buf), (u32 *)(&s->f80)) == 0)
        s->f80 = -1;
    s->f7f = 1;
    s->f4e = 2;
}






u32 func_021B8A44(struct Scene *s)
{
    int a;
    int b;

    if (func_02035CB8((u32 *)(&a), (u32 *)(&b)) == 0)
        b = s->f80;
    s->f80 = -1;
    return func_0202EDE4(s->f64, b, s->f7d, s->f7e, s->f12);
}




void func_021B8A88(u8 *p, u8 *a, u8 *b)
{
    u8 i;
    struct SceneEnt *entries;
    u8 value;
    entries = *(struct SceneEnt * *)&((struct Obj20623 *)p)->f1C;
    for (i = 0; ; i++) {
        value = entries[i].f0;
        if (value == 0xff) break;
        if (entries[i].f4 == 1) {
            *a = value;
            *b = (*(struct SceneEnt **)(p + 0x1c))[i].f1;
            return;
        }
    }
}




int func_021B8AB8(u8 *p)
{
    u8 b, a;
    func_021B8A88(p, &b, &a);
    return func_0202EE0C(((struct Obj09865 *)p)->f64, ((struct Obj09865 *)p)->f62, b, a, p[0x12]);
}





int func_021B8AE4(struct Scene *s, unsigned int v)
{
    u8 b, a;
    int o1, o2;
    unsigned int lo, hi;

    if (s->f7f == 1) {
        if (func_02035BA4(&s->f74) != -1) {
            func_02035CB8((u32 *)(&o1), (u32 *)(&o2));
            return o2;
        }
        return v;
    }
    func_021B8A88((u8 *)s, &b, &a);
    lo = func_0202EE0C(s->f64, s->f62, b, a, s->f12);
    if (s->f64 == s->f62)
        hi = a;
    else
        hi = func_0202EE0C(s->f64, s->f62 + 1, b, a, s->f12);
    if (v >= lo && v < hi)
        return v;
    return lo;
}





int func_021B8B74(struct Scene *s)
{
    u32 x;
    u32 d;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return 1;
    if (func_02035BA4(&s->f74) == -1 && s->f80 == -1) {
        s->f7f = 0;
        s->f4e = 0;
        return 0;
    }
    x = func_021B8A44(s);
    d = s->f62 - x;
    if ((int)d < 0)
        d = -d;
    if (d > s->f48)
        d = s->f48;
    if (s->f62 > x) {
        s->f62 = x + d;
        func_021B8434((u8 *)s, (s8)(-s->fb[0]), d, 2, 1);
    } else if (s->f62 < x) {
        s->f62 = x - d;
        func_021B8434((u8 *)s, (s8)s->fb[0], d, 2, 1);
    }
    return 1;
}





void func_021B8C14(struct Scene *s, int a)
{
    u32 v;

    s->f84 = 0;
    s->f87 = a;
    s->f86 = 0;
    v = s->f54;
    s->f70 = 0;
    s->f8c = v;
    s->f90 = v;
    s->f4e = 3;
}





int func_021B8C4C(struct Scene *s)
{
    int r;

    if (func_0201C6B4((const struct PrintSys *)s->f34) == 0)
        return 1;
    r = func_02035BA4(s->f2c);
    switch (s->f84) {
    case 0:
        if (r == -1) {
            if (s->f8c != -1 && s->f90 != -1) {
                s->f85 = s->f90 - s->f8c;
                s->f86 = 0;
                if (func_021B8EA0(s) == 1)
                    break;
            }
            s->f70 = 0;
            s->f4e = 0;
            return 0;
        }
        if (s->f1c[r].f4 != 0) {
            if (s->f8c != -1 && s->f90 != -1) {
                s->f85 = s->f90 - s->f8c;
                s->f86 = 0;
                if (func_021B8EA0(s) == 1)
                    break;
            }
            s->f70 = 0;
            s->f4e = 0;
            return 0;
        }
        if (s->f87 != r) {
            s->f88 = r;
            s->f85 = s->f87 - r;
            s->f86 = 0;
            s->f84 = 1;
        }
        s->f90 = s->f8c;
        s->f8c = s->f54;
        break;
    case 1:
        if (r == -1) {
            s->f84 = 0;
            return func_021B8EA0(s);
        }
        if (s->f1c[r].f4 != 0) {
            s->f84 = 0;
            return func_021B8EA0(s);
        }
        if (s->f86 == 5) {
            s->f86 = 0;
            s->f84 = 0;
            if (func_021B8DF0(s, r) == 1)
                s->ready = 1;
        } else {
            s->f88 = r;
            s->f8c = s->f54;
            s->f86++;
        }
        break;
    }
    return 1;
}



/*
 * Note: the second parameter of func_021B8434 is declared int here (its own
 * file has u8): the original passes the muls result untruncated.
 */
int func_021B8DF0(struct Scene *s, int a1)
{
    int d;
    s8 v;
    u32 lim;

    d = s->f87 - a1;
    if ((d < 0 && s->f85 > 0) || (d > 0 && s->f85 < 0))
        return 0;
    if ((s->f85 < 0 && s->f62 == 0) || (s->f85 > 0 && s->f62 == s->f64))
        return 0;
    if (d < 0)
        d = -d;
    if (d == 0)
        return 0;
    if (d == 1)
        v = (s8)s->fb[3];
    else if (d == 2)
        v = (s8)s->fb[2];
    else if (d == 3)
        v = (s8)s->fb[1];
    else
        v = (s8)s->fb[0];
    if (a1 > s->f87)
        v *= -1;
    lim = func_021B841C((u8 *)s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        func_021B8434((u8 *)s, v, d, 3, 1);
        s->f87 = a1;
        return 1;
    }
    return 0;
}






/*
 * pass 2 2026-10-06 P2L28: EXACT (was DIFF 14/256 in X8 and G4L7). The fix is the callee
 *   declaration that the matched ov067 callers 021B8B74 and 021B806C use: func_021B8434 takes
 *   `s8 a`, and v is an s8 local. With `int a` the 1 for the stack argument was placed after
 *   the u8 narrowing of d; with s8 it is stored first, as in the image. EXACT in c99 and c.
 */
int func_021B8EA0(struct Scene *s)
{
    u32 d;
    s8 v;
    int lim;

    if ((s->f85 < 0 && s->f90 > s->f8c) || (s->f85 > 0 && s->f90 < s->f8c))
        return 0;
    d = s->f90 - s->f8c;
    if ((int)d < 0)
        d = -d;
    if (d == 0)
        return 0;
    for (s->f89 = 0; s->f89 < 6; s->f89++) {
        if (d >= d_021B94FE[s->f86][s->f89]) {
            v = (s8)s->fb[s->f89];
            d = d_021B94F8[s->f89];
            break;
        }
    }
    if (s->f89 == 6)
        return 0;
    if (s->f8c > s->f90)
        v *= -1;
    lim = func_021B841C((u8 *)s, v);
    if (lim != 0) {
        if (lim < d)
            d = lim;
        func_021B8434((u8 *)s, v, d, 3, 1);
        s->f70 = 1;
        return 1;
    }
    return 0;
}





int func_021B8FA0(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (x == 2)
        return 2;
    if (x == 3)
        return 3;
    if (x == 4)
        return 4;
    if (x == 5)
        return 5;
    if (x == 6)
        return 6;
    if (x == 7)
        return 7;
    return 0;
}






void func_021B8FE4(struct Scene *s, u32 a1, u32 a2)
{
    u8 *gfx;
    int vram;
    void *res;
    u16 *map;
    u8 stride;
    u8 w;
    u8 h;
    u8 x0;
    u8 y0;
    u8 i;
    u8 j;

    res = s->f38[a2].p;
    map = s->f40[s->f28[a1].a];
    vram = func_02051B0C(func_021B8FA0(func_0202CF8C(s->f3c, a2)));
    func_0202CAC4(s->f3c, a2, map);
    func_0202CEBC(s->f3c, a2, res);
    stride = s->f4;
    w = func_02045748(res);
    h = func_02045750(res);
    x0 = func_02045758(res);
    y0 = func_02045760(res);
    gfx = func_020437D4(func_02045770(res));
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            func_02082A90((u8 *)vram + (map[x0 + j + (i + y0) * stride] & 0x3ff) * 32,
                          gfx + (j + i * w) * 32, 0x20);
        }
    }
}






void func_021B90B8(struct Scene *p, int a1, s8 a2)
{
    u32 t;
    u32 id;
    u16 j;

    t = func_0202CF84(p->f3c, a1);
    id = func_0202CF8C(p->f3c, a1);
    for (j = 0; j < p->f5; j++) {
        if (a2 < 0)
            a2 += 0x20;
        else if (a2 >= 0x20)
            a2 -= 0x20;
        func_020410D0(id, p->f2, (u8)a2, p->f4, 1, t, 0, j, p->f4, p->f5);
        a2++;
    }
    func_02041B6C((u8)id);
}






void func_021B9138(struct Scene *p, u32 a1, s8 a2)
{
    u32 j;

    for (j = 0; j < p->f5; j++) {
        if (a2 < 0)
            a2 += 0x20;
        else if (a2 >= 0x20)
            a2 -= 0x20;
        func_02041300(a1, 0, p->f2, (u8)a2, p->f4, 1, 0);
        a2++;
    }
    func_02041B6C(a1);
}





signed char func_021B9190(const signed char *p, int step)
{
    signed char value, delta;
    value = p[3];
    delta = (unsigned int)(unsigned char)p[5] * (unsigned int)step;
    do { value += delta; } while (value >= 0 && value < 24);
    return value + p[0x66] / 8;
}



signed char func_021B91BC(signed char a, signed char limit, int step)
{
    a = (signed char)((unsigned int)a + (unsigned int)step);
    if (a < 0) return limit;
    if (a > limit) return 0;
    return a;
}


void func_021B91D0(struct Scene *p, int i, s8 a2)
{
    if (i >= 0 && i < p->f4c) {
        func_021B8FE4(p, i, p->f46);
        func_021B90B8(p, p->f46, a2);
        p->f20->fn(p->f24, i, (u8 *)p->f38 + p->f46 * 8, a2 * 8 - p->f66, 1);
    } else {
        func_021B9138(p, p->f0, a2);
    }
}




void func_021B9228(struct Scene *p, int i, s8 a2)
{
    int k;

    if (p->f1 != 0xff) {
        if (i >= 0) {
            k = p->f47 + p->f45;
            func_021B8FE4(p, i, k);
            func_021B90B8(p, k, a2);
            p->f20->fn(p->f24, i, (u8 *)p->f38 + k * 8, a2 * 8 - p->f66, 0);
        } else {
            func_021B9138(p, p->f1, a2);
        }
    }
}



void func_021B9280(struct Scene *s, int a, u32 b)
{
    s16 pos = s->f66 / 8 + (s->f3 + a * s->f5);
    u16 i = 0;
    for (; i < s->f5; i++) {
        if (pos < 0) pos += 32;
        else if (pos >= 32) pos -= 32;
        func_020413B0(s->f0, s->f2, (u8)pos, s->f4, 1, (u8)b);
        pos++;
    }
    func_02041B6C(s->f0);
}




void func_021B92F0(struct Scene *p, u32 a1, u32 a2)
{
    if (a2 < p->f5e)
        func_021B9280(p, a2, (u16)(p->f40[p->f28[p->f62 + a2].a][0] >> 12));
    if (a1 < p->f5e && func_020355C4() == 0) {
        func_0202EB04(p->f30);
        func_021B9280(p, a1, p->f11);
    }
}




void func_021B9344(struct Scene *s)
{
    u32 i;

    func_0201C4E4((struct PrintSys *)s->f34);
    for (i = 0; i < s->count; i++) {
        struct Elem *e = &s->f38[i];
        int a = s->f34;

        if (e->flag != 0) {
            if (func_0201C6C4((struct PrintSys *)a, (void *)((int)func_02045770((struct Descriptor *)e->p))) == 0) {
                func_02045334((struct Descriptor *)e->p);
                e->flag = 0;
            }
        }
    }
}


/*
 * extent: four-byte getter; next leaf 021B9398 belongs to S27, not this file.
 */
unsigned func_021B9394(struct Scene *p)
{
    return p->f34;
}


/*
 * trailing: 2-byte alignment padding; separate existing functions follow
 */
u32 func_021B9398(struct Scene *p, int index)
{
    return p->f28[index].b;
}


/*
 * Caller ov209 021BCE98 reads the signed sum. ov067 is loaded by
 * ov209 021BCC94 and unloaded by 021BCD48. Following code starts at 021B93B0.
 */
int func_021B93A4(struct Scene *p)
{
    return p->f5c + p->f62;
}



/*
 * Unlabelled leaf in ov067, printed as a .word run; signed halfword getter.
 * Blocker target of ov210's func_021BF728 (pkt_021BF728), reached across the
 * ov210/ov067 overlay pair.
 */
int func_021B93B0(struct Scene *p)
{
    return p->f5c;
}



int func_021B93B8(struct Scene *p)
{
    return p->f62;
}



/*
 * Unlabelled leaf in ov067, printed as a .word run: true when the signed
 * halfword at +0x62 is below the unsigned halfword at +0x64.  Blocker target
 * of ov210's func_021BF728 (pkt_021BF728), across the ov210/ov067 pair.
 */
int func_021B93C0(struct Scene *p)
{
    return p->f62 < p->f64;
}



void func_021B93D4(struct Scene *s, int v)
{
    s->f60 = s->f5c;
    s->f5c = v;
    func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
    s->f20->f4(s->f24, s->f5c + s->f62, 1);
}



void func_021B940C(struct Scene *s)
{
    func_021B92F0(s, (u16)s->f5c, (u16)0xff);
}



/*
 * The handed 460-byte extent is this 56-byte function, two unlabelled
 * 16-byte tail-call stubs into func_021B92F0 (0x021B940C, 0x021B941C), and
 * rodata from 0x021B942C on. tu reproduces 0x021B93D4..0x021B942C.
 */
void func_021B941C(struct Scene *s)
{
    func_021B92F0(s, (u16)0xff, (u16)s->f5c);
}
