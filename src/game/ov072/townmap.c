/*
 * file:     townmap.c
 * unit:     yes
 * function: func_021B95A0, func_021B9858, func_021B98F8, func_021B991C, func_021B9938, func_021B9944, func_021B9958, func_021B995C, func_021B9964, func_021B996C, func_021B99AC, func_021B99E8, func_021B9E38, func_021B9F20, func_021B9F50, func_021BA028, func_021BA040, func_021BA04C, func_021BA0D8, func_021BA0E4, func_021BA3BC, func_021BA3CC, func_021BA3E8, func_021BA3EC, func_021BA3F4, func_021BA450, func_021BA488, func_021BA48C, func_021BA490, func_021BA570, func_021BA5AC, func_021BA5B0, func_021BA638, func_021BA69C, func_021BA6A8, func_021BA6C8, func_021BA710, func_021BA774, func_021BA7A4, func_021BA7D4, func_021BA7F8, func_021BA834, func_021BA86C, func_021BAA14, func_021BAA30, func_021BAA90, func_021BACB0, func_021BAD10, func_021BAD84, func_021BADBC, func_021BADF4, func_021BAE44, func_021BAE9C, func_021BAF24, func_021BAF3C, func_021BAF74, func_021BAF9C, func_021BAFA8, func_021BB0B4, func_021BB0DC, func_021BB0E0, func_021BB0E4, func_021BB190, func_021BB19C, func_021BB1BC, func_021BB204, func_021BB220, func_021BB3D0, func_021BB3E8, func_021BB42C, func_021BB448, func_021BB49C, func_021BB4B4, func_021BB534, func_021BB548, func_021BB5AC, func_021BB5B4, func_021BB5D4, func_021BB5E0, func_021BB5EC, func_021BB6AC, func_021BB6DC, func_021BB6E4, func_021BB6E8, func_021BB738, func_021BB758, func_021BB764, func_021BB778, func_021BB784, func_021BB790, func_021BB7BC, func_021BB80C, func_021BB820, func_021BB968, func_021BB9B0, func_021BB9B8, func_021BBAB4, func_021BBAFC, func_021BBB04, func_021BBB0C, func_021BBB14, func_021BBB1C, func_021BBB24, func_021BBB34, func_021BBB3C
 * address:  0x021B95A0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id       0x00000043  data
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02040618  0x02040618  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020355C4 0x020355C4 arm
 *   d_021BBB78 0x021BBB78 data ov072 a4
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B974  0x0204B974  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6520  0x021B6520  thumb  ov067
 *   d_021BBB8C     0x021BBB8C  data  a4
 *   func_021B639C 0x021B639C thumb ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_0204B454  0x0204B454  arm
 *   func_02035D20  0x02035D20  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B898  0x0204B898  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B95C  0x0204B95C  arm
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B6498  0x021B6498  thumb  ov067
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_0203630C  0x0203630C  arm
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_020520A4  0x020520A4  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_02030734  0x02030734  arm
 *   d_021BBD60     0x021BBD60  data  ov072
 *   func_020307B0 0x020307B0 arm
 *   func_02166C7C 0x02166C7C thumb ov010
 *   func_02166CD0  0x02166CD0  thumb  ov010
 *   func_0204B570  0x0204B570  arm
 *   func_02051F1C  0x02051F1C  arm
 *   func_0205207C  0x0205207C  arm
 *   func_02051F34  0x02051F34  arm
 *   func_0204B5AC  0x0204B5AC  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_02041FB0  0x02041FB0  arm
 *   func_02041F6C  0x02041F6C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020456F8 0x020456F8 arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   d_021BBD6C     0x021BBD6C  data  ov072  a1
 *   d_021BBBDC     0x021BBBDC  data  ov072
 *   d_021BBC28 0x021BBC28 data a4
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_020434CC  0x020434CC  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021BBBCC     0x021BBBCC  data  a4
 *   func_02040DA8  0x02040DA8  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020419E4  0x020419E4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   d_021BBC0C     0x021BBC0C  data  a4
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648 0x0204A648 arm
 *   func_0204A1BC 0x0204A1BC arm
 */
#include "../../matched/include/Obj00433.h"
#include "../../matched/include/Obj04342.h"
#include "../../matched/include/Obj20772.h"
#include "../../matched/include/Obj13193.h"
#include "../../matched/include/Obj13194.h"
#include "../../matched/include/Obj09905.h"
#include "../../matched/include/Obj09906.h"
#include "../../matched/include/Obj02126.h"
#include "../../matched/include/Obj03179.h"
#include "../../matched/include/Obj13199.h"
#include "../../matched/include/Obj13200.h"
#include "../../matched/include/Obj09909.h"
#include "../../matched/include/Obj03666.h"
#include "../../matched/include/Obj04345.h"
#include "../../matched/include/Obj20782.h"
#include "../../matched/include/Obj20783.h"
#include "../../matched/include/G_Ent.h"

#define W(k) (*(int *)(p+(k)))
#define R(k) ((void *)(p+(k)))
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct GfFont;
struct Obj0203159C;
struct Ctx;
struct MsgBank;
struct Node;
struct Rec;
struct S020315D4;
struct Obj;
struct Actor;
struct S_021B9F20;
struct PtS;
struct Vec2;
struct Out;
struct S12;
struct Vec;
struct Pair;
struct U16Vec;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct StrObj;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Bank;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
} Pos_021B95A0;

typedef struct {
    int f0;
    u8 pad4[4];
    u16 f8;
    u16 fA;
} Arg;

typedef signed int     s32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} W_021BB3E8;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    u8 pad10[8];
    u16 f18;
    u16 f1A;
    u16 f1C;
    u16 f1E;
} W_021BA490;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
} W_021B95A0;

typedef struct W_021BB220 W_021BB220;

typedef struct Callback Callback;

struct Callback { void (*call)(Callback *, int *, int); int state, value, arg; };

typedef long long s64;

typedef struct { int x,y; } Pos_021B9958;

typedef struct { int x,y,z; } Vec;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Rect;

typedef struct { u32 w[16]; } Tbl_021B95A0;

typedef struct {
    u8 *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} Req;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
} W_021BA6C8;

typedef short s16;

typedef struct {
    s16 x, y;
} Pt_021B9F50;

typedef struct S_021B9F20 {
    void *f0;
    void *f4;
    u16 f8;
    u16 fA;
    int pad[3];
} S_021B9F20;

struct Vec3 { int x; int y; int z; };

typedef struct {
    s16 x;
    s16 y;
} Pt_021BA0E4;

typedef struct {
    int obj;
    int f4;
    Pt_021BA0E4 pt;
    int fc;
    int f10;
} Cur;

typedef struct {
    s16 x;
    s16 y;
} Pos;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
} W_021B9F20;

typedef struct {
    u32 f0;
    int f4;
    char *f8;
    u32 fC;
    int f10;
    int f14;
    short f18;
    short f1A;
    u16 f1C;
    u16 f1E;
} W_021BA5B0;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W_021BA488;

typedef struct {
    int obj;
    char *f4;
    int f8;
    int v[8];
    int f2c;
    int f30;
    int f34;
} W_021BAD10;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
    int f14;
    s16 f18;
    s16 f1a;
    s16 f1c;
    s16 f1e;
} W_021BA638;

typedef struct {
    int a;
    int b;
} S_021BA69C;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W_021BA7D4;

typedef struct {
    int obj;
    int f4;
} W_021BAE9C;

typedef struct {
    int f[13];
    int f34;
    int f38;
    int f3c;
    int f40;
} W_021BACB0;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Pos_021BA6C8;

struct Seg {
    struct Vec3 p0;
    struct Vec3 dir;
    u32 pad18;
};

struct Ball {
    struct Vec3 c;
    int r;
};

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W_021BAA90;

typedef struct { s16 x; s16 y; } Pos_021BAD84;

typedef short s16_021BAE9C;

typedef struct {
    s16_021BAE9C x;
    s16_021BAE9C y;
    s16_021BAE9C z;
    s16_021BAE9C w;
} Pos_021BAE9C;

typedef struct { short x,y; } Pt;

typedef struct {
    int x, y;
} Vec_021BAE9C;

typedef struct {
    u16 f00;
    u16 n;
    s16_021BAE9C f04;
    s16_021BAE9C f06;
    s16_021BAE9C f08;
    s16_021BAE9C f0a;
    int done;
    int active;
    int cur;
    int to;
    int from;
    Vec_021BAE9C pos;
    Vec_021BAE9C dst;
    Vec_021BAE9C src;
} Anim_021BAE9C;

typedef struct { unsigned short f00,n; short f04,f06,f08,f0a; int done,active,cur,to,from; Pos_021B9958 pos,dst,src; } Anim_021BB0B4;

typedef enum { OFF, ON } Flag;

typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[2];
    short f4;
    short f6;
    short f8;
    short fA;
    u8 padC[8];
    u32 f14;
    u8 pad18[8];
    int f20;
    int f24;
} W_021BB0B4;

typedef struct {
    int a;
    int b;
} S;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} W_021BB1BC;

typedef signed short s16_021BB220;

struct Pt { u16 x; u16 y; };

struct V { int x; int y; int z; };

struct Obj {
    struct V a;
    struct V b;
    int f18;
    int f1c;
    int f20;
    struct V c;
};

typedef struct {
    u32 res;
    u32 obj[4];
    u32 f14;
    u32 chr;
    u32 cell;
    u32 pal;
} Gfx;

typedef struct { u32 w[8]; } BgTemplate;

typedef struct { u32 w[7]; } Tbl_021BB820;

extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020120F4(const struct Ctx *p);
extern void func_0201DD78(u32 a, u32 b, u32 c);
extern void func_0201DD68(void);
extern void func_02040618(u32 a, u32 b, u32 c);
extern int func_0203CD98(void);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_020056A0(void (*cb)(void *, void *), void *arg, int pri);
extern void func_02030EAC(struct Node *n);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(s32 handle);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
extern void func_020061E4(u32);
extern u8 func_020355C4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B974(struct Actor *a);
extern u32 func_021B62E0(Req *r, int heap);
extern void func_021B6520(u8 *p, u32 v);
extern void func_021B639C(unsigned char *);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_021B63D0(struct S_021B9F20 *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B95C(struct Actor *a);
extern int func_021B6448(unsigned char *);
int func_021B6498(unsigned char *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B84C(int obj, int v);
extern void func_0204B800(struct Node *node, u32 val);
extern unsigned int func_0203630C(void);
extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b, struct Vec3 *d);
extern int VEC_Mag(const struct Vec3 *v);
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *d);
extern void func_0204B9A0(struct Actor *a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02166C7C(void *a, u32 b);
extern int func_02166CD0(void *a, u32 msg);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_02051F1C(struct Ball *dst, struct Vec *src, unsigned radius);
extern void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v);
extern u32 func_02051F34(struct Seg *seg, struct Ball *b, struct Out *out);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_02041EE4(u32, u32, u32);
extern void func_02041FB0(u32, u32, u16);
extern void func_02041F6C(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_02013E4C(u32 id);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C7A4(void *x, s16_021BB220 y, s16_021BB220 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0207CA00(struct V *a, struct V *b, struct V *c);
extern int func_0207CBD0(struct V *a);
extern void func_0204335C(u32 a);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 a);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_0201DD60(void);
extern void func_0203F8F4(u16 heap);
extern void func_02045088(u16 heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020414AC(u8 a);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204ABF0(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(int);
extern void func_0204A648(void);
extern int func_0204A1BC(int,int,int,int);
int func_021B95A0(void *a, void *b, Arg *c);
int func_021B9858(void *a, int b, int c, u8 *o);
int func_021B98F8(int a, int b, int c, char *p);
void func_021B991C(int *p, int a, int b);
void func_021B9938(void *p);
void func_021B9944(Callback *p);
int func_021B9958(int *p);
void func_021B995C(int *p, int x);
void func_021B9964(int *p);
void func_021B996C(int a, int *b);
void func_021B99AC(int *p, int *state);
int func_021B99E8(int *a,int unused,char *p);
void func_021B9E38(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap);
void func_021B9F20(unsigned *p);
void func_021B9F50(u32 *p, void *q);
int func_021BA028(char *p);
int func_021BA040(int *p);
void func_021BA04C(S_021B9F20 *p, void *a, void *b, int heap);
void func_021BA0D8(void *p);
void func_021BA0E4(Cur *c, void *q);
void func_021BA3BC(char *p, int *q);
void func_021BA3CC(char *p, int *q);
int func_021BA3E8(int *p);
int func_021BA3EC(char *p);
void func_021BA3F4(int *p, int a, int *b);
void func_021BA450(int *p, int *b);
int func_021BA488(int *p);
void func_021BA48C(int *p, int x);
void func_021BA490(W_021BA490 *p, u16 x, u16 y, int a, u32 b, u32 c, u16 heap, int flag);
void func_021BA570(char *p);
void func_021BA5AC(void *a0);
void func_021BA5B0(W_021BA5B0 *p, u32 s, const int *v);
void func_021BA638(W_021BA638 *p, int *in);
void func_021BA69C(char *p, int *o);
void func_021BA6A8(char *p, const int *in);
char *func_021BA6C8(W_021BA6C8 *p, int a);
char *func_021BA710(W_021BA6C8 *p, int a);
int func_021BA774(char *p, int i);
void func_021BA7A4(char *p, void *selected);
void func_021BA7D4(char *p);
void *func_021BA7F8(char *p, u32 b, int y);
int func_021BA834(char *p);
void func_021BA86C(W_021BA7D4 *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5);
void func_021BAA14(unsigned int *p);
void func_021BAA30(W_021BA7D4 *p, int a);
u32 func_021BAA90(W_021BAA90 *p, int *a, int *b);
int func_021BACB0(W_021BACB0 *p, int *c, int *o, u32 *out);
void func_021BAD10(W_021BAD10 *p, int s, int *r);
void func_021BAD84(int *p, int *b);
void func_021BADBC(char *p, int v);
void func_021BADF4(W_021BAA90 *p);
void func_021BAE44(W_021BAA90 *p);
void func_021BAE9C(W_021BAE9C *p, int a, int b, int c, int s0, int s1, u16 s2);
void func_021BAF24(unsigned int *p);
void func_021BAF3C(u32 *p,const u32 *v);
void func_021BAF74(u8 *p, u32 a, u32 b, int heap);
void func_021BAF9C(void *p);
void func_021BAFA8(Anim_021BAE9C *p, void *arg);
void func_021BB0B4(Anim_021BB0B4 *p,int v,const Pos_021B9958 *a,const Pos_021B9958 *b);
int func_021BB0DC(void *p);
int func_021BB0E0(void *p);
void func_021BB0E4(W_021BB0B4 *p, const int *v);
void func_021BB190(char *p, int *o);
void func_021BB19C(u32 *p,const u32 *v);
void func_021BB1BC(W_021BB1BC *p, int a, int b, int c, int d, u16 e);
void func_021BB204(void **p);
void func_021BB220(u32 *p, W_021BB220 *w);
void func_021BB3D0(void **p);
void func_021BB3E8(W_021BB3E8 *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4);
void func_021BB42C(void **p);
void func_021BB448(u32 *p, u32 a, int x, int y);
void func_021BB49C(void **p);
void func_021BB4B4(u32 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021BB534(void *p);
void func_021BB548(u32 *p);
void func_021BB5AC(int *p, int x);
void func_021BB5B4(u32 *p,u32 v);
void func_021BB5D4(void *p, int heap);
void func_021BB5E0(void *p);
void func_021BB5EC(struct Obj *p);
int func_021BB6AC(u32 *p,Vec *v,u32 *out);
void func_021BB6DC(int *p);
void func_021BB6E4(void *a, void *b);
u32 *func_021BB6E8(u16 heap);
void func_021BB738(u32 *p);
void func_021BB758(char *p);
u8 func_021BB764(int unused, u32 i);
unsigned int func_021BB778(char *p, int n);
unsigned int func_021BB784(char *p, int n);
void func_021BB790(char *p,int *a,int *b,int *c);
void func_021BB7BC(void);
void func_021BB80C(void *unused, void *p);
void func_021BB820(void *p, u16 heap);
void func_021BB968(void *p);
void func_021BB9B0(void *a0);
void func_021BB9B8(Gfx *o, u32 mode, u16 heap);
void func_021BBAB4(u32 *p);
void func_021BBAFC(int x);
void func_021BBB04(void *p);
unsigned int func_021BBB0C(void *p, int n);
unsigned int func_021BBB14(void *p, int n);
int func_021BBB1C(char *p, int i);
int func_021BBB24(int a);
void func_021BBB34(void *p);
unsigned short func_021BBB3C(char *p, int a, int b);
extern char ov067_id[];
extern const Pos_021B9958 d_021BBB78;
extern Tbl_021B95A0 d_021BBB8C;
extern char d_021BBD60[];
extern char d_021BBD6C[];
extern char d_021BBBDC[];
extern struct Ent d_021BBC28[];
extern char d_021BBBCC;
extern const Tbl_021BB820 d_021BBC0C;








int func_021B95A0(void *a, void *b, Arg *c)
{
    Pos_021B95A0 pt;
    Pos_021B95A0 org;
    u8 *o;
    u32 v;
    int flag;
    int e;

    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x44, 0x60000);
    o = func_0203159C(a, 0x144, 0x44);
    func_02082BCC(o, 0, 0x144);
    *(Arg * *)&((struct Obj00433 *)o)->f130 = c;
    flag = (*(Arg * *)&((struct Obj00433 *)o)->f130)->f0 == 2;
    ((struct Obj00433 *)o)->f124 = func_0201D7EC(0x17, 0, 0, 0, 0x44);
    ((struct Obj00433 *)o)->f128 = (int)func_02045B38(0, 2, 0x59, 0x44);
    ((struct Obj00433 *)o)->f12C = (int)func_02045B38(0, 2, 0xb9, 0x44);
    *(u32 * *)&((struct Obj00433 *)o)->f0 = func_021BB6E8(0x44);
    ((struct Obj00433 *)o)->f34 = func_021BBB24(0x44);
    func_021B991C((int *)(o + 4), (int)o, (int)func_021B996C);
    v = (u32)func_020120F4((const struct Ctx *)((*(u32 **)(o + 0x130))[5]));
    if ((*(Arg * *)&((struct Obj00433 *)o)->f130)->f0 != 1) {
        func_021BB3E8((W_021BB3E8 *)(o + 0xc4), func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 1), *(int *)&((struct Obj00433 *)o)->f124, ((struct Obj00433 *)o)->f12C, 0, 0x15, 0x18, 3, 0x44);
        func_0201DD78(0xf, 1, 0);
        func_021BB448((u32 *)(o + 0xc4), 0, 0x10, 0);
        func_0201DD68();
    }
    func_021B9E38((u32 *)(o + 0x14), (*(Arg * *)&((struct Obj00433 *)o)->f130)->f0, func_021BB778((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 0), func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 0), 0xf, 8, v, 0x44);
    func_021BB4B4((u32 *)(o + 0xd4), func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 1), *(int *)&((struct Obj00433 *)o)->f124, ((struct Obj00433 *)o)->f128, func_021BB784((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 0), 0x44);
    func_02040618(func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 1), 3, -4);
    func_021BA490((W_021BA490 *)(o + 0x50), c->f8, c->fA, ((struct Obj00433 *)o)->f34, *(u32 *)&((struct Obj00433 *)o)->f0, (u32)func_020120F4((const struct Ctx *)((*(u32 **)(o + 0x130))[5])), (u16)0x44, flag);
    func_021BA04C((struct S_021B9F20 *)(o + 0x38), (void *)func_021BB784((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 1), (void *)func_021BB784((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 2), 0x44);
    e = (int)func_021BA7F8((char *)(o + 0x50), c->f8, c->fA);
    if (e != 0) {
        pt.x = func_021BA774((char *)e, 4);
        pt.y = func_021BA774((char *)e, 5);
    } else {
        pt.x = 0x80;
        pt.y = 0x60;
    }
    func_021BA3CC((char *)(o + 0x38), (int *)(&pt));
    func_021BAF74(o + 0x78, func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 3), func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 2), 0x44);
    func_021BB1BC((void *)(o + 0xb0), func_021BB764(*(u32 *)&((struct Obj00433 *)o)->f0, 5), *(int *)&((struct Obj00433 *)o)->f124, ((struct Obj00433 *)o)->f128, ((struct Obj00433 *)o)->f12C, 0x44);
    func_021BB5D4(o + 0xf4, 0x44);
    e = (int)func_021BA6C8((W_021BA6C8 *)((W_021B95A0 *)(o + 0x50)), (int)(o + 0x38));
    if (e != 0) {
        func_021BB5AC((int *)(o + 0xd4), e);
        func_021BB220((u32 *)(o + 0xb0), (W_021BB220 *)e);
        ((struct Obj00433 *)o)->f134 = e;
        func_021BA69C((char *)(o + 0x50), (int *)(&org));
        func_021BA3F4((int *)(o + 0x38), e, (int *)(&org));
    }
    if (func_0203CD98()) {
        func_0203D34C(1, 0x44);
    }
    ((struct Obj00433 *)o)->f13C = func_020056A0(func_021BB6E4, o, 0);
    return 1;
}








int func_021B9858(void *a, int b, int c, u8 *o)
{
    func_02030EAC(((struct Obj04342 *)o)->f13C);
    func_021BB5E0(o + 0xf4);
    func_021BB204((void **)(o + 0xb0));
    func_021BAF9C(o + 0x78);
    func_021BA570((char *)(o + 0x50));
    func_021BA0D8(o + 0x38);
    func_021BB534(o + 0xd4);
    if (**(int * *)&((struct Obj04342 *)o)->f130 != 1) {
        func_021BB42C((void **)(o + 0xc4));
    }
    func_021B9F20((unsigned int *)(o + 0x14));
    func_021B9938(o + 4);
    func_021BBB34(((struct Obj04342 *)o)->f34);
    func_021BB738(((struct Obj04342 *)o)->f0);
    func_02045C04(((struct Obj04342 *)o)->f12C);
    func_02045C04(((struct Obj04342 *)o)->f128);
    func_0201D83C(((struct Obj04342 *)o)->f124);
    func_020315D4(a);
    func_020306F0(0x44);
    func_02034A5C((u32)ov067_id);
    return 1;
}







int func_021B98F8(int a, int b, int c, char *p) {
    func_021B9944((Callback *)(p + 4));
    func_021BB758(*(char * *)&((struct Obj20772 *)p)->f0);
    return func_021B9958((int *)(p + 4)) != 0;
}







void func_021B991C(int *p, int a, int b) {
    func_02082BCC(p, 0, 16);
    p[3] = a;
    func_021B995C(p, b);
}








void func_021B9938(void *p)
{
    func_02082BCC(p, 0, 0x10);
}







void func_021B9944(Callback *p) {
    if (p->state == 0) p->call(p, &p->value, p->arg);
}






int func_021B9958(int *p)
{
    return p[1];
}






void func_021B995C(int *p, int x)
{
    p[0] = x;
    p[2] = 0;
}






void func_021B9964(int *p)
{
    p[1] = 1;
}







void func_021B996C(int a, int *b)
{
    switch (b[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        b[0] = 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            b[0] = 2;
        }
        break;
    case 2:
        func_021B995C((int *)a, (int)func_021B99E8);
        break;
    }
}






/*
 * note: trailing two-byte alignment padding.
 */
void func_021B99AC(int *p, int *state) {
    switch (*state) {
    case 0: func_0204E720(3,0,16,0); *state = 1; break;
    case 1: if (func_0204E804() == 0) *state = 2; break;
    case 2: func_021B9964(p); break;
    }
}






int func_021B99E8(int *a,int unused,char *p)
{
    u8 moved;
    int w,mask,t;
    moved=0;
    if (func_021BA040((int *)R(0x14)) == 0) {
        if (W(0x138)!=0 && func_021BB0E0(R(0x78))==0) {
            Vec v;
            Pos_021B9958 pos,delta={0,0};
            u32 out;
            Pos_021B9958 o1,o2;
            func_021BA3BC(R(0x38),&pos.x);
            mask=func_021BA3EC(R(0x38));
            if (pos.y<16 && (mask&0x40)) { delta.y-=4; moved=1; }
            if (pos.y<=168 && pos.y>136 && (mask&0x80)) { delta.y+=4; moved=1; }
            if (pos.x<16 && (mask&0x20)) { delta.x-=4; moved=1; }
            if (pos.x>240 && (mask&0x10)) { delta.x+=4; moved=1; }
            if (func_021BB0E0(R(0x78))==0 && func_021BB6AC(R(0xf4),&v,&out)) {
                delta.x=-(int)(((s64)v.x*4096+2048)>>12)>>12;
                delta.y=-(int)(((s64)v.y*4096+2048)>>12)>>12;
                func_021BB6DC(R(0xf4)); moved=1;
            }
            if (moved != 0) {
                func_021BA69C(R(0x50),&o1.x);
                func_021BB19C(R(0x78),(const u32 *)&delta);
                delta.x*=-1; delta.y*=-1;
                func_021BA6A8(R(0x50),&delta.x);
                func_021BA69C(R(0x50),&o2.x);
                func_021BA450(R(0x38),&o2.x);
            }
        }
        if (moved==0 && func_021BB0E0(R(0x78))==0) {
            if (*(int *)W(0x130)==0 || *(int *)W(0x130)==2) {
                w=func_021BA488(R(0x38));
                t=(int)func_021BA6C8((W_021BA6C8 *)((W_021B95A0 *)(R(0x50))), (int)(R(0x38)));
                if (w!=0 && w==t && func_021BA3E8(R(0x38))!=0 && func_021BA774((char *)w,12)!=0) {
                    *(int *)(W(0x130)+4)=2;
                    *(unsigned short *)(W(0x130)+8)=func_021BA774((char *)w,0);
                    *(int *)(W(0x130)+12)=func_021BA774((char *)w,13);
                    *(int *)(W(0x130)+16)=func_021BA774((char *)w,14);
                    func_020061E4(0x54c); func_021B995C(a,(int)func_021B99AC);
                }
            }
            if (func_020355C4()==0) t=1; else t=func_021BA3E8(R(0x38));
            if (t != 0) {
                w=(int)func_021BA6C8((W_021BA6C8 *)((W_021B95A0 *)(R(0x50))), (int)(R(0x38)));
                if (w!=W(0x134) && w!=0) {
                    Pos_021B9958 o3;
                    func_020061E4(0x548);
                    func_021BB220(R(0xb0), (W_021BB220 *)((void *)w)); func_021BA7A4(R(0x50),(void *)w);
                    W(0x134)=w; func_021BA69C(R(0x50),&o3.x);
                    func_021BA3F4(R(0x38),w,(int *)(&o3));
                    if (W(0x138)==0) func_021BB5AC(R(0xd4),w);
                } else if (w==0 && W(0x134)!=0) {
                    func_021BB3D0(R(0xb0)); func_021BB5B4(R(0xd4),0); func_021BA7D4(R(0x50));
                    func_021BA3F4(R(0x38),0,0); W(0x134)=0;
                }
            }
        }
        if (W(0x138)!=0) func_021BB5B4(R(0xd4),0);
        func_021BA48C(R(0x38),moved ? 0 : 1);
    }
    func_021B9F50(R(0x14),R(0x78));
    if (func_021BB0E0(R(0x78))==0) func_021BA0E4(R(0x38),R(0x50));
    func_021BA5AC(R(0x50)); func_021BAFA8(R(0x78),R(0x50));
    func_021BB548(R(0xd4)); func_021BB5EC(R(0xf4));
    switch (func_021BA028(R(0x14))) {
    case 0:
        *(int *)(W(0x130)+4)=1; func_021B995C(a,(int)func_021B99AC); break;
    case 1:
        *(int *)(W(0x130)+4)=0; func_021B995C(a,(int)func_021B99AC); break;
    case 7:
        if (W(0x138)==0 && func_021BB0E0(R(0x78))==0) {
            Pos_021B9958 o4;
            func_021BA3BC(R(0x38),&o4.x);
            func_021BB0B4(R(0x78),8192,&d_021BBB78,&o4);
            func_020061E4(0x648);
            if (W(0x134)!=0) {
                func_021BB3D0(R(0xb0)); func_021BB5B4(R(0xd4),0); func_021BA7D4(R(0x50));
                func_021BA3F4(R(0x38),0,0); W(0x134)=0;
            }
            W(0x138)=1;
        } else if (W(0x138)==1 && func_021BB0E0(R(0x78))==0) {
            Pos_021B9958 o5;
            func_021BB190(R(0x78),&o5.x); o5.x+=128; o5.y+=96;
            func_021BB0B4(R(0x78),4096,&o5,&d_021BBB78);
            func_020061E4(0x649);
            if (W(0x134)!=0) {
                func_021BB3D0(R(0xb0)); func_021BB5B4(R(0xd4),0); func_021BA7D4(R(0x50));
                func_021BA3F4(R(0x38),0,0); W(0x134)=0;
            }
            W(0x138)=0;
        }
        break;
    }
    return func_021BB0DC(R(0x78));
}







void func_021B9E38(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap)
{
    Req r;
    Tbl_021B95A0 t;
    Rect s;
    void *h;

    func_02082BCC(o, 0, 0x20);
    o[4] = s2;
    h = func_020490F4(0x55, heap);
    o[0] = func_0204AC18(h, 2, 0, 0, 0, 4, heap);
    o[1] = (s32)func_0204A6C8(h, 8, 0, 0, (u32)heap);
    o[2] = func_0204AF28(h, 0xc, 0x13, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    s.a = 0xa8;
    s.b = 0xa8;
    s.c = 7;
    o[5] = (u32)func_0204B294((void *)a2, o[1], o[0], o[2], &s, 0, heap);
    func_0204B92C((struct Obj *)o[5], 1);
    func_0204B974((struct Actor *)o[5]);
    t = d_021BBB8C;
    func_02082BCC(&r, 0, 0x20);
    r.f0 = (u8 *)&t;
    r.f4 = 2;
    r.f8 = a2;
    r.fC = a3;
    r.f10 = s0;
    r.f14 = s1 + 4;
    r.f18 = 2;
    o[3] = func_021B62E0(&r, heap);
    func_021B6520((u8 *)o[3], 10);
}








void func_021B9F20(unsigned *p) {
    func_021B639C((unsigned char *)p[3]);
    func_0204B3B4((struct Obj *)p[5]); func_0204AFD8(p[2]);
    func_0204A8D4(p[1]); func_0204ADA4(p[0]);
    func_02082BCC(p,0,32);
}









/*
 * EXACT*: the unlabelled follower at 0x021BA028 (push {r4,lr}; getter
 * over func_021B6448) is outside the handed 216-byte extent.
 * Lever: each sprite-animation pick written as if/else of two calls
 * (tail-merged, h load hoisted over the bne), and func_0204B878's second
 * parameter int here (no truncation before the blx).
 */
void func_021B9F50(u32 *p, void *q)
{
    u32 x;
    u32 y;
    Pt_021B9F50 pt;
    int hit;

    func_021B63D0((struct S_021B9F20 *)((void *)p[3]));
    p[6] = -1;
    switch (p[7]) {
    case 0:
        hit = 0;
        func_0204B454((void *)p[5], (struct PtS *)&pt, 0);
        if (func_02035D20(&x, &y)) {
            if (x - pt.x <= 0x18 && y - pt.y <= 0x18) {
                hit = 1;
                func_020355D8(1);
            }
        } else if (func_020362DC() & 4) {
            func_020355D8(hit);
            hit = 1;
        }
        if (hit && func_0204B98C((void *)p[5]) == 0 && func_021BB0E0(q) == 0) {
            if (func_0204B898((void *)p[5]) == 7)
                func_0204B878((void *)p[5], 9);
            else
                func_0204B878((void *)p[5], 10);
            func_0204B95C((void *)p[5]);
            p[6] = 7;
            p[7] = 1;
        }
        break;
    case 1:
        if (func_0204B98C((void *)p[5]) == 0) {
            if (func_0204B898((void *)p[5]) == 9)
                func_0204B878((void *)p[5], 8);
            else
                func_0204B878((void *)p[5], 7);
            p[7] = 0;
        }
        break;
    }
}








int func_021BA028(char *p) {
    int n;
    n = func_021B6448(*(unsigned char * *)&((struct Obj13193 *)p)->fC);
    if (n == -1) n = ((struct Obj13193 *)p)->f18;
    return n;
}









int func_021BA040(int *p)
{
    return func_021B6498((unsigned char *)p[3]);
}









void func_021BA04C(S_021B9F20 *p, void *a, void *b, int heap)
{
    int z = 0;
    int one;

    func_02082BCC(p, 0, 0x18);
    p->f0 = a;
    p->f4 = b;
    p->f8 = 0x80;
    p->fA = 0x60;
    func_0204B404(a, (const struct Vec2 *)(&p->f8), 0);
    func_0204B404(p->f4, (const struct Vec2 *)(&p->f8), 0);
    func_0204B3DC(p->f0, 1);
    one = 1;
    func_0204B3DC(p->f4, 0);
    func_0204B84C((int)p->f0, 0);
    func_0204B800(p->f0, 0);
    func_0204B84C((int)p->f4, 2);
    func_0204B800(p->f4, 3);
    func_0204B92C(p->f4, 1);
    if (func_020355C4() == 0) {
        func_0204B3DC(p->f0, one);
    } else {
        func_0204B3DC(p->f0, z);
    }
}









void func_021BA0D8(void *p)
{
    func_02082BCC(p, 0, 0x18);
}









void func_021BA0E4(Cur *c, void *q)
{
    struct Vec3 dir = { 0, 0, 0 };
    struct Vec3 v = { 0, 0, 0 };
    struct Vec3 a;
    struct Vec3 b;
    int o[2];
    u32 tx;
    u32 ty;
    int moved;
    char *w;
    int dx;
    int dy;
    s16 t;

    moved = 0;
    c->fc = 0;
    if (func_0203630C() & 0x40) {
        func_020355D8(0);
        dir.y -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x80) {
        func_020355D8(0);
        dir.y += 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x20) {
        func_020355D8(0);
        dir.x -= 0x1000;
        moved = 1;
    }
    if (func_0203630C() & 0x10) {
        func_020355D8(0);
        dir.x += 0x1000;
        moved = 1;
    }
    if (c->f10 != 0 && func_020355C4() == 0 && (w = func_021BA710((W_021BA6C8 *)((W_021B9F20 *)q), (int)c)) != 0) {
        func_021BA69C(q, o);
        a.x = FX_F32_TO_FX32(o[0] + func_021BA774(w, 4));
        a.y = FX_F32_TO_FX32(o[1] + func_021BA774(w, 5));
        a.z = 0;
        b.x = FX_F32_TO_FX32(c->pt.x);
        b.y = FX_F32_TO_FX32(c->pt.y);
        b.z = 0;
        VEC_Subtract(&a, &b, &v);
        if (VEC_Mag(&v) > 0x1000) {
            VEC_Normalize(&v, &v);
            func_020520A4(&v, 0x1000, &v);
        }
        moved = 1;
    }
    if (moved) {
        VEC_Normalize(&dir, &dir);
        dx = v.x + dir.x * 3;
        dy = v.y + dir.y * 3;
        if (dx > 0 && dx < 0x1000)
            dx = 0x1000;
        else if (dx > -0x1000 && dx < 0)
            dx = -0x1000;
        if (dy > 0 && dy < 0x1000)
            dy = 0x1000;
        else if (dy > -0x1000 && dy < 0)
            dy = -0x1000;
        c->pt.x += (s16)(dx >> 12);
        c->pt.y += (s16)(dy >> 12);
        t = c->pt.x;
        if (t > 0xf8)
            t = 0xf8;
        else if (t < 0)
            t = 0;
        c->pt.x = t;
        t = c->pt.y;
        if (t > 0xa8)
            t = 0xa8;
        else if (t < 8)
            t = 8;
        c->pt.y = t;
        func_0204B404((struct Obj *)c->obj, (const struct Vec2 *)(&c->pt), 0);
    }
    if (func_020362DC() & 1) {
        func_020355D8(0);
        c->fc = 1;
    }
    if (func_02035D20(&tx, &ty)) {
        func_020355D8(1);
        if (tx <= 0xf8 && ty - 8 <= 0xa0) {
            c->fc = 1;
            c->pt.x = tx;
            c->pt.y = ty;
        }
    }
    if (func_020355C4() == 0)
        func_0204B3DC((struct Obj *)c->obj, 1);
    else
        func_0204B3DC((struct Obj *)c->obj, 0);
}








void func_021BA3BC(char *p, int *q) {
    q[0] = ((struct Obj13194 *)p)->f8;
    q[1] = ((struct Obj13194 *)p)->fA;
}








void func_021BA3CC(char *p, int *q) {
    ((struct Obj09905 *)p)->f8 = q[0];
    ((struct Obj09905 *)p)->fA = q[1];
    func_0204B404(((struct Obj09905 *)p)->f0, (const struct Vec2 *)(p + 8), 0);
}








int func_021BA3E8(int *p)
{
    return p[3];
}









int func_021BA3EC(char *p)
{
    return func_0203630C();
}









void func_021BA3F4(int *p, int a, int *b)
{
    Pos pos;

    if (a == 0) {
        func_0204B3DC((struct Obj *)p[1], 0);
        p[5] = 0;
        return;
    }
    if (p[5] != a) {
        pos.x = b[0] + func_021BA774((char *)a, 4);
        pos.y = b[1] + func_021BA774((char *)a, 5);
        func_0204B404((struct Obj *)p[1], (const struct Vec2 *)(&pos), 0);
        func_0204B3DC((struct Obj *)p[1], 1);
        func_0204B9A0((struct Actor *)p[1]);
        p[5] = a;
    }
}








void func_021BA450(int *p, int *b) { Pos pos; if(p[5]) { pos.x=b[0]+func_021BA774((void *)p[5],4); pos.y=b[1]+func_021BA774((void *)p[5],5); func_0204B404((struct Obj *)p[1],(const struct Vec2 *)(&pos),0); } }








int func_021BA488(int *p)
{
    return p[5];
}








void func_021BA48C(int *p, int x)
{
    p[4] = x;
}









void func_021BA490(W_021BA490 *p, u16 x, u16 y, int a, u32 b, u32 c, u16 heap, int flag)
{
    u32 i;
    u32 n;
    int s0, s1, s2;
    int t0, t1, t2;
    int e;

    i = 0;
    n = func_021BB778((char *)b, 0);
    func_02082BCC(p, 0, 0x28);
    p->fC = 0x3d;
    p->f0 = c;
    p->f8 = func_02030734(heap, p->fC * 0x44, 0, d_021BBD60, 0x8C5);
    func_02082BCC(p->f8, 0, p->fC * 0x44);
    func_021BB790((char *)b, &s0, &s1, &s2);
    for (; i < p->fC; i++) {
        func_021BA86C((W_021BA7D4 *)((W_021BA488 *)(p->f8 + i * 0x44)), a, i, n, s0, s1, s2, (void *)c, heap, flag);
    }
    e = (int)func_021BA7F8((char *)p, x, y);
    func_021BB790((char *)b, &t0, &t1, &t2);
    func_021BAE9C((W_021BAE9C *)((char *)p + 0x20), e, n, t0, t1, t2, heap);
    p->f18 = 0;
    p->f1A = 0;
    p->f1C = 0;
    p->f1E = 0;
    func_021BA7D4((char *)p);
}








void func_021BA570(char *p) { u32 i; func_021BAF24((unsigned int *)(p+32)); for(i=0;i<((struct Obj09906 *)p)->fC;i++) func_021BAA14((void *)(*(u32 *)&((struct Obj09906 *)p)->f8+i*0x44)); func_020307B0(((struct Obj09906 *)p)->f8); func_02082BCC(p,0,40); }








/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void func_021BA5AC(void *a0)
{
}









void func_021BA5B0(W_021BA5B0 *p, u32 s, const int *v)
{
    u32 i;
    int t[2];

    if (s == 0x1000) {
        p->f18 = 0;
        p->f1A = 0;
        p->f1C = 0;
        p->f1E = 0;
    } else {
        p->f18 = -0x48;
        p->f1A = -0x80;
        p->f1C = 0x80;
        p->f1E = 0x60;
    }
    t[0] = -v[0];
    t[1] = -v[1];
    func_021BA638((W_021BA638 *)p, t);
    for (i = 0; i < p->fC; i++) {
        func_021BAD10((W_021BAD10 *)(p->f8 + i * 0x44), s, (int *)&d_021BBB78);
        func_021BAD84((int *)(p->f8 + i * 0x44), &p->f10);
    }
    func_021BAF3C((u32 *)((char *)p + 0x20), (const u32 *)((int *)&p->f10));
}







void func_021BA638(W_021BA638 *p, int *in)
{
    u32 i;
    int x;
    int y;

    x = p->f1c;
    if (in[0] <= x) {
        x = p->f1a;
        if (in[0] >= x) {
            x = in[0];
        }
    }
    p->f10 = x;
    y = p->f1e;
    if (in[1] <= y) {
        y = p->f18;
        if (in[1] >= y) {
            y = in[1];
        }
    }
    p->f14 = y;
    for (i = 0; i < p->fc; i++) {
        func_021BAD84((int *)(p->f8 + i * 0x44), &p->f10);
    }
    func_021BAF3C((u32 *)((char *)p + 0x20), (const u32 *)(&p->f10));
}







/*
 * note:     listing extent (12) runs 2 bytes past the compiled function (10);
 *           trailing alignment padding, no byte difference.  A two-word copy
 *           at a nonzero offset is a struct assignment (hoists both loads and
 *           allocates r2/r0); two locals let the stores reorder and diff.
 */
void func_021BA69C(char *p, int *o)
{
    *(S_021BA69C *)o = *(S_021BA69C *)(p + 0x10);
}






void func_021BA6A8(char *p, const int *in) { ((struct Obj02126 *)p)->f10 = in[0] + ((struct Obj02126 *)p)->f10; ((struct Obj02126 *)p)->f14 = ((struct Obj02126 *)p)->f14 + in[1]; func_021BA638((W_021BA638 *)p, (int *)(p+16)); }









char *func_021BA6C8(W_021BA6C8 *p, int a)
{
    int pt[2];
    u32 i;

    func_021BA3BC((char *)a, pt);
    for (i = 0; i < p->fc; i++) {
        if (func_021BAA90((W_021BAA90 *)(p->f8 + i * 0x44), pt, &p->f10) != 0) {
            return p->f8 + i * 0x44;
        }
    }
    return 0;
}









char *func_021BA710(W_021BA6C8 *p, int a)
{
    int pt[2];
    u32 i;
    u32 best;
    u32 d;
    int idx;

    func_021BA3BC((char *)a, pt);
    idx = -1;
    best = -1;
    for (i = 0; i < p->fc; i++) {
        if (func_021BACB0((W_021BACB0 *)(p->f8 + i * 0x44), pt, &p->f10, &d) != 0 && best > d) {
            idx = i;
            best = d;
        }
    }
    if (idx == -1) {
        return 0;
    }
    return p->f8 + idx * 0x44;
}








/*
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
int func_021BA774(char *p, int i) {
 if (i>=2 && i<=10) return *(int *)((unsigned int)p+(i-2)*4+12);
 if (i==12) return ((struct Obj03179 *)p)->f3C;
 return func_021BBB3C(*(char * *)&((struct Obj03179 *)p)->f4,(u16)(((struct Obj03179 *)p)->f8),i);
}








void func_021BA7A4(char *p, void *selected) { u32 i; void *q; for(i=0;i<((struct Obj13199 *)p)->fC;i++) { q=(void *)(((struct Obj13199 *)p)->f8+i*0x44); if(q==selected) func_021BADF4((W_021BAA90 *)q); else func_021BAE44((W_021BAA90 *)q); } }








void func_021BA7D4(char *p) { u32 i; for(i=0;i<((struct Obj13200 *)p)->fC;i++) func_021BAE44((W_021BAA90 *)((void *)(((struct Obj13200 *)p)->f8+i*0x44))); }








void *func_021BA7F8(char *p, u32 b, int y) { u32 i; u32 v; void *q; v=func_02166C7C(((struct Obj09909 *)p)->f0,b); for(i=0;i<((struct Obj09909 *)p)->fC;i++) { q=(void *)(((struct Obj09909 *)p)->f8+i*0x44); if(v==func_021BA774(q,0)) return q; } return 0; }








int func_021BA834(char *p) { int v; v=func_021BBB3C(*(char * *)&((struct Obj03179 *)p)->f4,(u16)(((struct Obj03179 *)p)->f8),15); if((v!=65535 && ((struct Obj03179 *)p)->f38!=0 && ((struct Obj03179 *)p)->f40==0) || v==65535) return 1; return 0; }









void func_021BA86C(W_021BA7D4 *p, int a, int b, int c, int s0, int s1, int s2, void *s3, u16 s4, int s5)
{
    Pos_021BA6C8 pos;
    u32 r;
    int i;

    func_02082BCC(p, 0, 0x44);
    p->f34 = 0x1000;
    p->f4 = a;
    p->f8[0] = b;
    r = func_021BBB3C((char *)a, (u16)b, 15);
    if (r != 0xFFFF)
        p->f38 = func_02166CD0(s3, r);
    else
        p->f38 = 0;
    if (s5)
        p->f38 = 1;
    for (i = 0; i < 9; i++)
        p->f8[i + 1] = func_021BBB3C((char *)p->f4, (u16)p->f8[0], i + 2);
    if (s5)
        p->f3c = 1;
    else
        p->f3c = p->f38 && func_021BBB3C((char *)p->f4, (u16)p->f8[0], 12);
    r = func_021BBB3C((char *)p->f4, (u16)p->f8[0], 16);
    if (r != 0xFFFF)
        p->f40 = func_02166CD0(s3, r) == 0;
    else
        p->f40 = 0;
    if (s5)
        p->f40 = 0;
    switch (func_021BA774((char *)p, 11)) {
    case 0:
        p->f31 = 2;
        p->f30 = 1;
        break;
    case 2:
        p->f31 = 3;
        p->f30 = 0xff;
        break;
    case 1:
        p->f31 = 0xff;
        p->f30 = 0xff;
        break;
    case 3:
        p->f31 = 3;
        p->f30 = 0xd;
        break;
    case 4:
        p->f31 = 0xf;
        p->f30 = 0xe;
        break;
    case 5:
        p->f31 = 0x12;
        if (p->f38)
            p->f30 = 0x11;
        else
            p->f30 = 0x10;
        break;
    }
    if (func_021BA774((char *)p, 11) != 1) {
        func_02082BCC(&pos, 0, 8);
        pos.x = func_021BA774((char *)p, 2);
        pos.y = func_021BA774((char *)p, 3);
        p->obj = (int)func_0204B294((void *)c, s0, s2, s1, &pos, 0, s4);
        func_0204B570((struct Actor *)p->obj, 2);
        func_0204B84C(p->obj, 2);
        func_0204B800((struct Node *)p->obj, 4);
    }
    func_021BAE44((W_021BAA90 *)p);
}








void func_021BAA14(unsigned int *p) { if (*p) func_0204B3B4((struct Obj *)(*p)); func_02082BCC(p,0,0x44); }









void func_021BAA30(W_021BA7D4 *p, int a)
{
    if (p->obj == 0 || p->f32 == 0xff) {
        return;
    }
    if (p->f40 != 0) {
        func_0204B3DC((struct Obj *)p->obj, 0);
        return;
    }
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        func_021BADBC((char *)p, p->f30);
        func_0204B3DC((struct Obj *)p->obj, 1);
    } else {
        func_0204B3DC((struct Obj *)p->obj, a);
    }
}







u32 func_021BAA90(W_021BAA90 *p, int *a, int *b)
{
    struct Ball ball;
    struct Seg seg;
    struct Vec3 v0;
    struct Vec3 v1;

    v0.x = FX_F32_TO_FX32(a[0]);
    v0.y = FX_F32_TO_FX32(a[1]);
    v0.z = 0;
    func_02051F1C(&ball, (struct Vec *)(&v0), 0);
    v0.x = FX_F32_TO_FX32(b[0] + func_021BA774((char *)p, 6));
    v0.y = FX_F32_TO_FX32(b[1] + func_021BA774((char *)p, 7));
    v0.z = 0;
    v1.x = FX_F32_TO_FX32(b[0] + func_021BA774((char *)p, 8));
    v1.y = FX_F32_TO_FX32(b[1] + func_021BA774((char *)p, 9));
    v1.z = 0;
    func_0205207C((char *)(&seg), (struct S12 *)(&v0), (struct S12 *)(&v1), FX_F32_TO_FX32(func_021BA774((char *)p, 10)));
    if (p->f40 != 0)
        return 0;
    return func_02051F34(&seg, &ball, 0);
}







int func_021BACB0(W_021BACB0 *p, int *c, int *o, u32 *out)
{
    int x;
    int y;
    int dx;
    int dy;
    int a;
    int lim;

    x = o[0] + func_021BA774((char *)p, 4);
    y = o[1] + func_021BA774((char *)p, 5);
    dx = x - c[0];
    dx = dx * dx;
    dy = y - c[1];
    dy = dy * dy;
    if (p->f40 != 0) {
        return 0;
    }
    a = p->f34;
    if (a < 0) {
        a = -a;
    }
    lim = (a * 0x90) >> 12;
    if ((u32)(dx + dy) < lim) {
        if (out != 0) {
            *out = dx + dy;
        }
        return 1;
    }
    return 0;
}







void func_021BAD10(W_021BAD10 *p, int s, int *r)
{
    int i;
    int base;
    int d;
    int t[2];

    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            base = r[0];
        } else {
            base = r[1];
        }
        d = func_021BBB3C(p->f4, (u16)p->f8, i + 2) - base;
        d = d * s >> 12;
        p->v[i] = d + base;
    }
    p->f2c = s * func_021BBB3C(p->f4, (u16)p->f8, 10) >> 12;
    p->f34 = s;
    if (p->obj != 0) {
        t[0] = s;
        t[1] = s;
        func_0204B5AC((struct Obj *)p->obj, (struct Pair *)t);
    }
}





void func_021BAD84(int *p, int *b) { Pos_021BAD84 pos; pos.x=b[0]+func_021BA774((char *)p,2); pos.y=b[1]+func_021BA774((char *)p,3); if(p[0]) func_0204B404((struct Obj *)p[0],(const struct Vec2 *)(&pos),0); }





void func_021BADBC(char *p, int v) { ((struct Obj03666 *)p)->f32=v; if(((struct Obj03666 *)p)->f32!=255) { if(((struct Obj03666 *)p)->f0) { func_0204B3DC((struct Obj *)((struct Obj03666 *)p)->f0,1); func_0204B878((struct Obj *)(((struct Obj03666 *)p)->f0),((struct Obj03666 *)p)->f32); } } else { if(((struct Obj03666 *)p)->f0) func_0204B3DC((struct Obj *)((struct Obj03666 *)p)->f0,0); } }






void func_021BADF4(W_021BAA90 *p)
{
    int r;

    r = 0;
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        r = 1;
        if (p->f40 != 0) {
            r = 0;
        }
    }
    if (p->f38 != 0 || r != 0) {
        func_021BAA30((W_021BA7D4 *)p, 1);
        func_021BADBC((char *)p, p->f31);
    } else {
        func_021BAA30((W_021BA7D4 *)p, 0);
    }
}






void func_021BAE44(W_021BAA90 *p)
{
    int r;

    r = 0;
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        r = 1;
        if (p->f40 != 0) {
            r = 0;
        }
    }
    if (p->f38 != 0 || r != 0) {
        if (p->obj != 0) {
            func_021BAA30((W_021BA7D4 *)p, 1);
            func_021BADBC((char *)p, p->f30);
        }
    } else {
        func_021BAA30((W_021BA7D4 *)p, 0);
    }
}









void func_021BAE9C(W_021BAE9C *p, int a, int b, int c, int s0, int s1, u16 s2)
{
    Pos_021BAE9C pos;

    func_02082BCC(p, 0, 8);
    p->f4 = a;
    func_02082BCC(&pos, 0, 8);
    if (a != 0) {
        pos.x = func_021BA774((char *)a, 2);
        pos.y = func_021BA774((char *)a, 3);
    }
    p->obj = (int)func_0204B294((void *)b, c, s1, s0, &pos, 0, s2);
    func_0204B84C(p->obj, 2);
    func_0204B800((struct Node *)p->obj, 2);
    func_0204B878((struct Obj *)p->obj, 6);
    func_0204B92C((struct Obj *)p->obj, 1);
    if (a == 0) {
        func_0204B3DC((struct Obj *)p->obj, 0);
    }
}








void func_021BAF24(unsigned int *p) { func_0204B3B4((struct Obj *)(*p)); func_02082BCC(p,0,8); }








void func_021BAF3C(u32 *p,const u32 *v) { Pt t; if(p[1]!=0) { t.x=v[0]+func_021BA774((char *)p[1],2); t.y=v[1]+func_021BA774((char *)p[1],3); } func_0204B404((void *)p[0],(const struct Vec2 *)(&t),0); }








void func_021BAF74(u8 *p, u32 a, u32 b, int heap) { u16 z=0; func_02082BCC(p,0,0x38); p[0]=a; p[1]=b; ((struct Obj04345 *)p)->f14=0x1000; ((struct Obj04345 *)p)->f4=z; ((struct Obj04345 *)p)->f6=z; ((struct Obj04345 *)p)->f8=z; ((struct Obj04345 *)p)->fA=z; }









void func_021BAF9C(void *p)
{
    func_02082BCC(p, 0, 0x38);
}









void func_021BAFA8(Anim_021BAE9C *p, void *arg)
{
    int dy;
    int dx;
    int step;

    p->done = 0;
    if (p->active == 0)
        return;
    step = (p->to - p->from) / 10;
    p->cur = p->from + step * p->n;
    dy = (p->dst.y - p->src.y) << 12;
    dx = (p->dst.x - p->src.x) << 12;
    p->pos.x = p->src.x + ((dx * p->n) / 10 >> 12);
    p->pos.y = p->src.y + ((dy * p->n) / 10 >> 12);
    if (p->to == 0x1000) {
        p->f04 = -96 - (-96 - 0) / 10 * p->n;
        p->f0a = 72 - (72 - 0) / 10 * p->n;
        p->f06 = -128 - (-128 - 0) / 10 * p->n;
        p->f08 = 128 - (128 - 0) / 10 * p->n;
    } else {
        p->f04 = 0 + (-96 - 0) / 10 * p->n;
        p->f0a = 0 + (72 - 0) / 10 * p->n;
        p->f06 = 0 + (-128 - 0) / 10 * p->n;
        p->f08 = 0 + (128 - 0) / 10 * p->n;
    }
    if (p->n++ >= 10) {
        p->n = 0;
        p->active = 0;
        p->cur = p->to;
        p->pos = p->dst;
        if (p->to == 0x1000) {
            p->f04 = 0;
            p->f06 = 0;
            p->f08 = 0;
            p->f0a = 0;
        } else {
            p->f04 = -0x60;
            p->f06 = -0x80;
            p->f08 = 0x80;
            p->f0a = 0x48;
        }
        p->done = 1;
    }
    func_021BA5B0((W_021BA5B0 *)arg, (u32)p->cur, (int *)&p->pos);
    func_021BB0E4((W_021BB0B4 *)p, (const int *)(&p->pos));
}








void func_021BB0B4(Anim_021BB0B4 *p,int v,const Pos_021B9958 *a,const Pos_021B9958 *b) { int x; Flag one; p->to=v; p->from=p->cur; one=ON; x=a->x; p->active=one; p->src.x=x-0x80; p->src.y=a->y-0x60; p->dst.x=b->x-0x80; p->dst.y=b->y-0x60; }









/*
 * two int getters at +c, +10.
 */
int func_021BB0DC(void *p)
{
    return ((struct Obj20782 *)p)->fC;
}









int func_021BB0E0(void *p)
{
    return ((struct Obj20783 *)p)->f10;
}









void func_021BB0E4(W_021BB0B4 *p, const int *v)
{
    p->f20 = (v[0] > p->f8) ? p->f8 : ((v[0] < p->f6) ? p->f6 : v[0]);
    p->f24 = (v[1] > p->fA) ? p->fA : ((v[1] < p->f4) ? p->f4 : v[1]);

    func_02041EE4(p->f0, 0, p->f20);
    func_02041EE4(p->f0, 3, p->f24);
    func_02041FB0(p->f0, 9, 0x80);
    func_02041FB0(p->f0, 12, 0x60);
    func_02041F6C(p->f0, 3, p->f14);
    func_02041F6C(p->f0, 6, p->f14);
    func_02041EE4(p->f1, 0, p->f20);
    func_02041EE4(p->f1, 3, p->f24);
    func_02041FB0(p->f1, 9, 0x80);
    func_02041FB0(p->f1, 12, 0x60);
    func_02041F6C(p->f1, 3, p->f14);
    func_02041F6C(p->f1, 6, p->f14);
}








void func_021BB190(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x20);
}







void func_021BB19C(u32 *p,const u32 *v) { p[8]=v[0]+p[8]; p[9]+=v[1]; func_021BB0E4((W_021BB0B4 *)p, (const int *)(p+8)); }








void func_021BB1BC(W_021BB1BC *p, int a, int b, int c, int d, u16 e)
{
    func_02082BCC(p, 0, 0x14);
    p->f8 = b;
    p->f10 = d;
    p->fc = c;
    p->f0 = func_020450F0(a, 0, 0, 0x20, 0x18, 0xe, 0);
    p->f4 = (int)func_020457B0(0xff, e);
}







void func_021BB204(void **p) { func_02045808(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x14); }







void func_021BB220(u32 *p, W_021BB220 *w)
{
    u32 win;
    s16_021BB220 cx;
    s16_021BB220 hw;
    u16 id;
    u32 h;

    win = (u32)func_02045770((struct Descriptor *)p[0]);
    func_02043B5C((struct CharBuf *)win, 0);
    if (w != 0) {
        func_02045CAC((struct MsgBank *)p[3], func_02013E4C((u16)func_021BA774((char *)w, 0)), (void *)p[1]);
        cx = ((u32)func_02045738((struct Descriptor *)p[0]) << 3) / 2;
        hw = func_0201D304((struct StrObj *)p[1], p[2], 0) >> 1;
        cx = cx - hw;
        func_0201C7A4((void *)win, cx, 0x30, (void *)p[1], (void *)p[2]);
        id = func_021BA774((char *)w, 0x11);
        if (id != 0xFFFF) {
            func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
            func_0201C7A4((void *)win, 0x1c, 0x50, (void *)p[1], (void *)p[2]);
        }
        if (func_021BA834((char *)w)) {
            id = func_021BA774((char *)w, 0x12);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x13);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x14);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x10, 0xa0, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x15);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0x80, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x16);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0x90, (void *)p[1], (void *)p[2]);
            }
            id = func_021BA774((char *)w, 0x17);
            if (id != 0xFFFF) {
                func_02045CAC((struct MsgBank *)p[4], id, (void *)p[1]);
                func_0201C7A4((void *)win, 0x88, 0xa0, (void *)p[1], (void *)p[2]);
            }
        }
    }
    h = p[0];
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_02041B6C(func_02045730((struct Descriptor *)h));
}






void func_021BB3D0(void **p) { void *q = *p; func_020456F8(q); func_02041B6C(func_02045730(q)); }







void func_021BB3E8(W_021BB3E8 *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4)
{
    func_02082BCC(p, 0, 0x10);
    p->f8 = b;
    p->fc = c;
    p->f0 = func_020450F0(a, s0, s1, s2, s3, 0xe, 0);
    p->f4 = (int)func_020457B0(0xff, s4);
}






void func_021BB42C(void **p) { func_02045808(p[1]); func_020452E8(p[0]); func_02082BCC(p,0,0x10); }







void func_021BB448(u32 *p, u32 a, int x, int y)
{
    u32 w;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[0])), 0);
    func_02045CAC((struct MsgBank *)p[3], a, (void *)p[1]);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)p[0])), x, y, (void *)p[1], (void *)p[2]);
    w = p[0];
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_02045730((struct Descriptor *)w));
}






void func_021BB49C(void **p) { void *q = *p; func_020456F8(q); func_02041B6C(func_02045730(q)); }






void func_021BB4B4(u32 *p, u32 a, u32 b, u32 c, u32 d, u16 e)
{
    struct Pt pt;

    func_02082BCC(p, 0, 0x20);
    p[4] = d;
    func_021BB3E8((W_021BB3E8 *)p, (int)a, (int)b, (int)c, 0, 0, 0x18, 3, e);
    pt.x = 0x80;
    pt.y = 0x60;
    func_0204B404((void *)p[4], (const struct Vec2 *)(&pt), 0);
    func_0204B84C((int)((void *)p[4]), (int)1);
    func_0204B800((void *)p[4], 1);
    func_0204B3DC((void *)p[4], 1);
    func_0204B878((void *)p[4], 0);
    func_0204B92C((void *)p[4], 1);
    func_0204B974((void *)p[4]);
}





void func_021BB534(void *p) { func_021BB42C(p); func_02082BCC(p,0,0x20); }






void func_021BB548(u32 *p)
{
    if (p[7] != 0) {
        p[7] = 0;
        func_0204B878((void *)p[4], 0);
        func_0204B95C((void *)p[4]);
        func_0204B3DC((void *)p[4], 1);
        func_021BB49C((void **)p);
        p[6] = 1;
    }
    if (p[6] != 0 && func_0204B98C((struct Actor *)p[4]) == 0) {
        func_021BB448(p, func_02013E4C((u16)func_021BA774((char *)p[5], 0)), 0x10, 2);
        func_0204B974((void *)p[4]);
        p[6] = 0;
    }
}





void func_021BB5AC(int *p, int x)
{
    p[7] = 1;
    p[5] = x;
}





void func_021BB5B4(u32 *p,u32 v) { func_0204B3DC((void *)p[4],v); if(v==0) { p[7]=0; p[6]=0; func_021BB49C((void **)p); } }






void func_021BB5D4(void *p, int heap)
{
    func_02082BCC(p, 0, 0x30);
}






void func_021BB5E0(void *p)
{
    func_02082BCC(p, 0, 0x30);
}





void func_021BB5EC(struct Obj *p)
{
    u32 y;
    u32 x;

    p->f1c = 0;
    if (func_02035D20(&y, &x)) {
        if (x <= 0xA8) {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
        return;
    }
    if (func_02035CB8(&y, &x)) {
        if (x <= 0xA8) {
            if (p->f20 != 0) {
                p->a = p->b;
                p->f20 = 0;
            }
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
            func_0207CA00(&p->b, &p->a, &p->c);
            if (func_0207CBD0(&p->c) >= 0x1000) {
                p->f1c = 1;
            }
        } else {
            p->a.x = y << 12;
            p->a.y = x << 12;
            p->a.z = 0;
            p->b.x = y << 12;
            p->b.y = x << 12;
            p->b.z = 0;
        }
    }
}




int func_021BB6AC(u32 *p,Vec *v,u32 *out) { if(p[7]!=0) { if(v!=0) *v=*(Vec *)(p+9); if(out!=0) *out=p[6]; return 1; } return 0; }




/*
 * note:     listing extent (12) runs past the compiled function (6) into an
 *           unlabelled Thumb leaf (a `bx lr` at 0x021BB6E4), no byte
 *           difference.
 */
void func_021BB6DC(int *p)
{
    p[8] = 1;
}




/*
 * Unlabelled empty task callback (a lone `bx lr`) whose address
 * func_021B95A0 passes to func_020056A0 through its pool word 0x021BB6E5.
 */
void func_021BB6E4(void *a, void *b)
{
}





u32 *func_021BB6E8(u16 heap)
{
    u32 *p;

    p = func_02030734(heap, 0x2C, 0, d_021BBD6C, 0xEC);
    func_02082BCC(p, 0, 0x2C);
    func_021BB7BC();
    func_021BB820(p, heap);
    func_021BB9B8((Gfx *)(p + 1), (u32)d_021BBBDC, heap);
    p[10] = func_020056A0(func_021BB80C, p, 1);
    return p;
}




void func_021BB738(u32 *p) { func_02030EAC((void *)p[10]); func_021BBAB4(p+1); func_021BB968(p); func_020307B0(p); }





/*
 * bx r3` veneer followed by its own pool) in ov072, so no `label` branch and
 * no `sole-ref/code` function start attests it; the only pool word naming it
 * is this function's own. All 12 bytes and the relocation field are right.
 *
 * UNBLOCKED: func_021BBAFC is now an EXACT entry in layout/matched/ov072;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void func_021BB758(char *p)
{
    func_021BBAFC((int)(p + 4));
}




u8 func_021BB764(int unused, u32 i) { return d_021BBC28[i].id; }





unsigned int func_021BB778(char *p, int n)
{
    return func_021BBB14(p + 4, n);
}





unsigned int func_021BB784(char *p, int n)
{
    return func_021BBB0C(p + 4, n);
}




void func_021BB790(char *p,int *a,int *b,int *c) { *a=func_021BBB1C(p+4,0); *b=func_021BBB1C(p+4,1); *c=func_021BBB1C(p+4,2); }





void func_021BB7BC(void)
{
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BBBDC);
    func_0204363C(0);
    func_0204361C();
    func_020434CC();
    func_0201DD60();
}




void func_021BB80C(void *unused, void *p) { func_021BBB04((char *)p + 4); func_021BB9B0(p); }



/*
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition
 *   tail-returns sub_0204968C). With the void declaration the later register zeros were
 *   copied from the pooled zero web; with the real return type they are fresh movs. EXACT
 *   in c99 and c.
 * checks: 1 own 0203F8F4/45088 one, 3FC28 one, 3FCA0 three, 40588 two, 490F4 two, 49B68 six, 49658/498F4 seven, 49B40 six, 40C14 four; SDK82BCC three and49238 one confirmed by matched ov0729E38 caller; 2 same-region/sibling graphics callers refreshed; 3 enum register-zero prototype variants and unsigned-long u32 each compile328/68 flat; 4 enum-zero and sub-word parameter idioms read, no fresh improving lever; 5 full idiom directory and matched neighbours refreshed. Prior permuter300 remains spent. Next hypothesis: genuine palette request storage type for the tail zero web.
 * retry: Wave76 R18 final retry, three fixed one runs; original best328/68 retained, all22 relocations resolved.
 *
 * Residual (328/328 bytes, 35 lines, all relocations resolve): from the
 * sixth handle call on (func_02049658(h, 6, 5, 0, 0, 0, heap)) the original
 * ends the callee-saved zero (r6, which feeds only the stack-argument zeros)
 * at the [sp+4] store of func_020498F4(h, 0xf, ...), then puts 0x1C0 in r6
 * and 0x20 in r7 for both func_02049B40 calls and materialises every later
 * register-argument zero with movs. Ours keeps the zero web in r6 to the
 * end (r3 of the 0xf call, r2 of the first B40, r1/r3 of C14 are copies of
 * r6), so 0x20 is rematerialised per call and the heap store of the (6,5)
 * call is scheduled last instead of first. Everything before +0xE2 is
 * byte-identical. Next thing to try: a spelling that ends the zero's live
 * range at the (0xf,5) call (the stack zeros of the last three handle calls
 * as a separate value), which no type change above reached.
 *
 * renewed: Wave75 R29, 3 iteration + 2 check runs. Enum stack-zero72 bytes and enum palette-size74 worse; loop-init after first call flat68. Const BG table CCERR repaired with readonly callee prototype, then flat68. Own arm9 unit_02049B40 and sub_02049658/498F4 re-read (6/7 args, u16 final heap); fresh ov070/071 callers and idioms. Earlier permuter300 remains consumed; best C retained.
 * Graphics init; the seven 0x28-byte BG entries at d_021BBC28 are the
 * ones func_021BB968 tears down.
 *
 * note 2026-10-05 (wave P7 lane V1): no matched twin exists (ov021 02192FA4, ov218 021B9964,
 * ov173 021B66BC, ov091 021B71E4 share only the 02049B40/02049658 call forms). Prototypes now
 * follow the matched house forms (void *h, u16 heap, u16 final argument): still 328 B, 68 differ,
 * same residue (zero web in r6 copied into r3/r2/r1 for the 0xf, B40 and C14 calls; 0x1c0/0x20
 * land in r7/rematerialised). Tried, all flat at 68: each of opt_lifetimes, opt_propagation
 * (288), opt_common_subs (269), opt_dead_assignments, scheduling, peephole off; e parameter u16;
 * e parameter void *; d parameter void * on 0xf call; zero as local z; heap param u16 with u16
 * callees; tail pair and C14 in a static inline. Residue: the original treats the stack zeros
 * and the register zeros as different values, no human source form found.
 *
 * recoup 2026-10-05 (lane R7): all flat at 328 B / 68 differ: scratch t = 0 then t = 0x1c0 with
 * t as the stack zeros of calls 5..0xf; the same with t in only the (6,5) and 0xf calls, in a
 * block; z in all three zero slots of (6,5) or of 0xf; u32 heap with u32 callee heap (340 B, 200
 * worse). Probe: with the B40 r2 zero and the C14 zeros changed to non-zero values, 0x20 and
 * 0x1c0 land in r7/r6 as in the original, so only two residues are left: (a) at the 0xf call r3
 * is `adds r3,r6,#0` where the original has `movs r3,#0`, (b) the heap store of the (6,5) call
 * comes last instead of first. Every named zero is constant-propagated, so t/z do not make a
 * separate value. Twin search: grep -l func_02049B40 src/matched/ov (ov111 021C72FC, ov209
 * 021BC574, ov210 021BC5DC, ov018 0217D720, ov219 021849A4 share the call forms, none has the
 * 6,5 / 0xf / B40 / C14 run); callees 02049658/020498F4 read in arm9 (no truncation of e, f).
 */
void func_021BB820(void *p, u16 heap)
{
    int i;
    u32 id;
    void *h;

    i = 0;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)(&d_021BBBCC));
    for (; i < 7; i++) {
        id = d_021BBC28[i].id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)(&d_021BBC28[i].tmpl_w), (u8)d_021BBC28[i].mode);
        func_02040588(id, 1);
    }
    h = func_020490F4(0x55, heap);
    func_02049B68(h, 0, 2, 0x6000, 0x2000, heap);
    func_02049B68(h, 0, 2, 0x4000, 0x2000, heap);
    func_02049658(h, 5, 2, 0, 0x10000, 0, heap);
    func_02049658(h, 7, 3, 0, 0x10000, 0, heap);
    func_020498F4(h, 0x11, 2, 0, 0x800, 0, heap);
    func_020498F4(h, 0x10, 3, 0, 0x800, 0, heap);
    func_02049B68(h, 1, 4, 0, 0, heap);
    func_02049658(h, 6, 5, 0, 0, 0, heap);
    func_020498F4(h, 0xf, 5, 0, 0, 0, heap);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, heap);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, heap);
    func_02040C14((int)1, (int)0, (int)1, (int)0);
    func_02049238(h);
}






void func_021BB968(void *p)
{
    int i;
    u32 id;

    func_02040DA8(1, 1, 0);
    for (i = 0; i < 7; i++) {
        id = d_021BBC28[i].id;
        func_020414AC(id);
        func_020403F4((u8)id);
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}






void func_021BB9B0(void *a0)
{
    func_020419E4();
}






void func_021BB9B8(Gfx *o, u32 mode, u16 heap)
{
    int i;
    void *h;
    Tbl_021BB820 t;
    Rect s;

    i = 0;
    func_02082BCC(o, 0, 0x24);
    t = d_021BBC0C;
    func_0204A48C((const struct Cfg *)(&t), mode, heap);
    o->res = (u32)func_0204B100(0x80, 0, heap);
    func_0204B270((struct Bank *)o->res);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    h = func_020490F4(0x55, heap);
    o->pal = func_0204ABF0(h, 2, 0, 0, heap);
    o->chr = func_0204A6C8(h, 8, 0, 0, heap);
    o->cell = func_0204AF28(h, 0xc, 0x13, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    for (; i < 4; i++) {
        o->obj[i] = (u32)func_0204B294((void *)o->res, o->chr, o->pal, o->cell, &s, 1, heap);
    }
    func_0204B878((struct Obj *)o->obj[0], 0);
    func_0204B878((struct Obj *)o->obj[1], 4);
    func_0204B878((struct Obj *)o->obj[2], 5);
    func_0204B878((struct Obj *)o->obj[3], 6);
    for (i = 0; i < 4; i++) {
        func_0204B3DC((struct Obj *)o->obj[i], 0);
    }
}






void func_021BBAB4(u32 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (p[i + 1] != 0) {
            func_0204B3B4((struct Obj *)p[i + 1]);
        }
    }
    func_0204AFD8(p[7]);
    func_0204A8D4(p[6]);
    func_0204ADA4(p[8]);
    if (p[0] != 0) {
        func_0204B1CC((struct Bank *)p[0]);
    }
    func_0204A5AC();
    func_02082BCC(p, 0, 0x24);
}






/*
 * Thumb long-branch veneer in a .word run:
 *   ldr r3,[pc,#0]; bx r3; .word 0x0204A600
 * Declared as an ordinary tail-call extern at the veneer address.
 */
void func_021BBAFC(int x)
{
    func_0204A600(x);
}




void func_021BBB04(void *p) { func_0204A648(); }




unsigned int func_021BBB0C(void *p, int n)
{
    return *(unsigned int *)((char *)p + n * 4 + 4);
}




/*
 * Unlabelled Thumb leaf in a .word run:
 *   lsls r1,r1,#2; ldr r0,[r0,r1]; bx lr
 * Word at p + n*4.
 */
unsigned int func_021BBB14(void *p, int n)
{
    return *(unsigned int *)((char *)p + n * 4);
}




int func_021BBB1C(char *p, int i)
{
    return *(int *)(p + i * 4 + 0x18);
}




int func_021BBB24(int a) { return func_0204A1BC(0x56,0,0,a); }





void func_021BBB34(void *p)
{
    func_020307B0(p);
}




unsigned short func_021BBB3C(char *p, int a, int b)
{
    return *(unsigned short *)(p + a * 0x36 + b * 2);
}
