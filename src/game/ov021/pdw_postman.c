/*
 * file:     pdw_postman.c
 * unit:     yes
 * function: func_021B7364, func_021B7390, func_021B73B8, func_021B7400, func_021B7494, func_021B74CC, func_021B7574, func_021B7640, func_021B76B4, func_021B76F8, func_021B7740, func_021B7794, func_021B77E4, func_021B7834, func_021B785C, func_021B7864, func_021B7884, func_021B791C, func_021B7934, func_021B7954, func_021B7970, func_021B79AC, func_021B79C4, func_021B79CC, func_021B79D4, func_021B79E4, func_021B79F0, func_021B7A84, func_021B7C04, func_021B7C38, func_021B7C58, func_021B7C90, func_021B7CD8, func_021B7D38, func_021B7D50, func_021B7D68, func_021B7DC0, func_021B7DE0, func_021B7E60, func_021B7ED4, func_021B7EE4, func_021B8028, func_021B8038, func_021B8040, func_021B8048, func_021B8050, func_021B80D8, func_021B80E0, func_021B810C, func_021B821C, func_021B8220, func_021B8224, func_021B8230, func_021B823C, func_021B8248, func_021B824C, func_021B8250, func_021B82F0, func_021B82F4, func_021B82F8, func_021B82FC, func_021B8300, func_021B8304, func_021B8308, func_021B830C, func_021B8314, func_021B8328, func_021B833C, func_021B834C, func_021B835C, func_021B836C, func_021B8378, func_021B83B0, func_021B83FC, func_021B8484, func_021B8514, func_021B854C, func_021B8658, func_021B8674, func_021B868C, func_021B86A4, func_021B87BC, func_021B87C8, func_021B87D8, func_021B87FC, func_021B8820
 * address:  0x021B7364
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb ov010
 *   func_02159AE8  0x02159AE8  thumb ov010
 *   d_021D99E8     0x021D99E8  data  a2
 *   d_021D99D4     0x021D99D4  data  a2
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_021690D0  0x021690D0  thumb  ov010
 *   func_021690E0  0x021690E0  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021D99DE     0x021D99DE  data   ov021  a1
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   d_021DE288     0x021DE288  data   ov021  a1
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02190758  0x02190758  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_02192788  0x02192788  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021927B0  0x021927B0  thumb  ov021
 *   func_0201292C  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02009364  0x02009364  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A104  0x0200A104  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_0200A13C  0x0200A13C  thumb
 *   func_021B9164  0x021B9164  thumb
 *   g_021DE2A0     0x021DE2A0  data  a1
 *   func_021B9464  0x021B9464  thumb  ov021
 *   func_021B91A8  0x021B91A8  thumb ov021
 *   func_021B91AC  0x021B91AC  thumb
 *   func_021B8870  0x021B8870  thumb
 *   func_021B9510  0x021B9510  thumb  ov021
 *   func_021B8848  0x021B8848  thumb  ov021
 *   func_021B88B8  0x021B88B8  thumb  ov021
 *   func_021B9828  0x021B9828  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CAE8  0x0207CAE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   d_021D9A00     0x021D9A00  data   a4
 *   func_021B94C0  0x021B94C0  thumb ov021
 *   func_021B9478  0x021B9478  thumb ov021
 *   func_021B949C  0x021B949C  thumb ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   func_021B9278  0x021B9278  thumb ov021
 *   func_021B9280  0x021B9280  thumb ov021
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021B919C  0x021B919C  thumb  ov021
 *   func_021B91F8  0x021B91F8  thumb  ov021
 *   func_021B9238  0x021B9238  thumb  ov021
 *   func_021B9368  0x021B9368  thumb  ov021
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_021B88DC  0x021B88DC  thumb  ov021
 *   func_021B977C  0x021B977C  thumb  ov021
 *   d_021DE298     0x021DE298  data
 *   func_021B91C8  0x021B91C8  thumb
 *   func_021B95C0  0x021B95C0  thumb
 *   func_021B93D4  0x021B93D4  thumb
 *   func_021B963C  0x021B963C  thumb
 *   func_021B9434  0x021B9434  thumb
 *   func_021B9404  0x021B9404  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021D9A0C     0x021D9A0C  data  a4
 */
#include "../../matched/include/Obj04890.h"
#include "../../matched/include/Obj18099.h"
#include "../../matched/include/Obj18100.h"
#include "../../matched/include/Obj01358.h"
#include "../../matched/include/Obj20053.h"
#include "../../matched/include/Obj20055.h"
#include "../../matched/include/Obj18102.h"
#include "../../matched/include/Obj18103.h"
#include "../../matched/include/Obj18104.h"
#include "../../matched/include/Obj00454.h"
#include "../../matched/include/Obj18105.h"
#include "../../matched/include/Obj18106.h"
#include "../../matched/include/Obj18107.h"
#include "../../matched/include/Obj18108.h"
#include "../../matched/include/Obj18109.h"
#include "../../matched/include/Obj18111.h"
#include "../../matched/include/Obj18112.h"
#include "../../matched/include/Obj18113.h"
#include "../../matched/include/Obj18114.h"
#include "../../matched/include/Obj18115.h"
#include "../../matched/include/Obj18116.h"
#include "../../matched/include/Obj18117.h"
#include "../../matched/include/Obj18118.h"
#include "../../matched/include/Obj18119.h"
#include "../../matched/include/Obj03135.h"
#include "../../matched/include/Obj00010.h"
#include "../../matched/include/Obj02052.h"
#include "../../matched/include/Obj04134.h"
#include "../../matched/include/Obj02659.h"
#include "../../matched/include/G_Elem.h"

struct Fx;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec_021B7494;
struct Descriptor;
struct Cur;
struct G;
struct BigObj;
struct Sub02009210Obj;
struct Ctx;
struct Desc;
struct Work;
struct Big;
struct Sub02009448Obj;
struct Obj_021B7364;
struct Pair;
struct Ent_021B77E4;
struct Sub;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    u16 a;
    u16 b;
} Entry;

typedef struct PostmanList {
    u16 f0;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    int f20;
    Entry *f24;
} PostmanList;

typedef struct Work {
    u32 f0;
    PostmanList *f4;
    u32 *f8;
    u32 fC;
    u16 f10;
} Work;

typedef struct Pair {
    u16 a;
    u16 b;
} Pair;

struct Rec_021B7494 { unsigned short *f0; char pad04[4]; void *f8; char fC[4]; u16 f10; };

struct Ent_021B77E4 { u8 pad00[0xB3]; u8 fB3; };

struct Elem_021B7970 { u16 f0; u16 f2; char pad[0x78]; };

struct Obj_021B7364 {
    u16 f0;
    u16 f2;
    u16 f4;
    char pad06[2];
    struct Elem_021B7970 *f8;
    u32 fC;
    int f10;
    int f14;
    int f18;
    struct Elem_021B7970 *f1C;
    char f20[4];
};

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad[0x78];
} Elem_021B7970;

typedef struct {
    u8 pad[8];
    Elem_021B7970 *arr;
    int count;
} Ctx;

struct Info { char pad00[0x10]; u32 f10; char pad14[0x28]; u32 f3C; };

struct Sub { u16 f0; u16 pad2; struct Info *f4; char pad08[0x1C]; void *f24; };

typedef void (*Cb)(void *);

struct Obj_021B79AC { char pad00[2]; u16 f2; u16 f4; char pad06[0xE]; struct Sub *f14; u32 f18; };

typedef int            fx32;

typedef struct { fx32 x, y, z; } VecFx32_021B7A84;

typedef struct { u16 a, b, c, d; } Rect4_021B7A84;

typedef struct Node {
    u8 pad[0x30];
    VecFx32_021B7A84 pos;
} Node;

typedef int (*HitFn)(int i, u8 *p, VecFx32_021B7A84 *hit, Rect4_021B7A84 *r, VecFx32_021B7A84 *out);

typedef long long s64;

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    u16 h4;
    u16 h6;
} Arg_021B7C58;

typedef struct {
    u8 pad[0x18];
    int x18;
    u8 pad1c[8];
    void *x24;
} Inner_021B7C58;

typedef struct {
    u8 pad[0x1C];
    Inner_021B7C58 *x1c;
} Outer_021B7364;

struct Mgr_021B7364 { u8 pad00[0x1C]; u8 *f1C; };

typedef signed int s32;

typedef struct V3 { int x, y, z; } V3;

struct Cam {
    u8 pad00[0x50];
    V3 f50;
    Rect4_021B7A84 f5C;
    u8 pad64[8];
    Rect4_021B7A84 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

struct Mgr_021B7CD8 { u8 pad00[0x1C]; void *f1C; };

struct Mgr_021B7D38 { u8 pad00[0x1C]; void *f1C; };

typedef struct {
    u8 pad[0x18];
    int x18;
} Inner_021B7D50;

typedef struct {
    u8 pad[0x1C];
    Inner_021B7D50 *x1c;
} Outer_021B7D50;

struct Obj_021B7D68 { char pad00[0x14]; struct Sub *f14; char pad18[4]; struct Sub *f1C; };

typedef struct { u16 w, h; } Size16;

typedef struct { u16 a, b; Size16 sz; } Rect4_021B7DC0;

struct Cam_021B7D50 {
    u8 pad00[0x50];
    V3 f50;
    Rect4_021B7DC0 f5C;
    u8 pad64[8];
    Rect4_021B7DC0 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

typedef struct {
    u16 h0;
    u8 b2;
    u8 pad3;
    s16 h4;
    u16 h6;
} Arg_021B7DE0;

typedef struct {
    u16 h0;
    u16 h2;
    u8 pad4[0x10];
    u8 *x14;
} Tbl_021B7DE0;

typedef struct {
    u8 pad[0x1C];
    void *x1c;
    u8 pad20[4];
    Tbl_021B7DE0 *x24;
} Obj_021B7DE0;

struct Cam_021B7DE0 {
    u8 pad00[0x50];
    V3 f50;
    Rect4_021B7A84 f5C;
    u8 pad64[8];
    Rect4_021B7A84 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

typedef struct {
    u32 w[3];
} Triple;

typedef struct { u32 a, b, c; } V3_021B7EE4;

typedef struct { u16 a; u8 t; u8 c; s16 e; u16 d; } Out;

typedef struct Info_021B7EE4 {
    u32 arr[4];
    u32 f10[4];
    u32 f20;
    u8 pad24[0x4c];
} Info_021B7EE4;

typedef struct Rec_021B7EE4 {
    u32 f0;
    u32 f4;
    u8 pad8[0xc];
    u32 f14;
    u8 pad18[0x30];
} Rec_021B7EE4;

typedef struct Tbl_021B7EE4 {
    u8 pad0[0x10];
    Info_021B7EE4 *f10;
    Rec_021B7EE4 *f14;
} Tbl_021B7EE4;

typedef struct Sub_021B7EE4 {
    u16 f0;
    u16 pad2;
    Info_021B7EE4 *f4;
    u16 f8;
    u16 padA;
    int fC;
    u8 pad10[8];
    u32 f18;
    u32 f1C;
    u8 pad20[4];
    Tbl_021B7EE4 *f24;
    u8 pad28[4];
    u8 f2C;
    s8 f2D;
    u16 f2E;
    u16 f30;
    u8 f32;
    u8 f33;
    u8 f34;
    u8 pad35[3];
    V3_021B7EE4 f38;
    V3_021B7EE4 f44;
    u8 pad50[0xc];
    Out f5C;
    Out f64;
} Sub_021B7EE4;

typedef struct { u16 h0; u8 b2; u8 pad3; s16 h4; u16 h6; } Arg_021B8050;

typedef struct { u8 pad[8]; u32 f8; } Info_021B8040;

typedef struct Sub_021B8050 {
    u16 f0;
    u16 pad2;
    Info_021B8040 *f4;
    u16 f8;
    u16 padA;
    s32 fC;
    s32 f10;
    u32 f14;
    u8 pad18[0x60];
    void *f78;
} Sub_021B8050;

typedef struct {
    u8 pad[0x2C];
    u8 b2c;
    u8 b2d;
    u16 h2e;
    u16 h30;
} Obj_021B80E0;

typedef struct { u16 f0; u16 f2; } Owner;

typedef struct Sub_021B810C {
    u16 f0;
    u16 pad2;
    void *f4;
    u16 f8;
    u16 padA;
    s32 fC;
    u8 pad10[0x1C];
    u8 f2C;
    s8 f2D;
    u16 f2E;
    u16 f30;
    u8 f32;
    u8 f33;
    u8 f34;
    u8 pad35[3];
    V3 f38;
    V3 f44;
    u8 pad50[0xc];
    Out f5C;
    Out f64;
    u8 pad6C[8];
    u8 f74;
    u8 pad75[3];
    Owner *f78;
} Sub_021B810C;

typedef struct Tbl_021B810C { u16 f0; u16 f2; u8 pad4[0x10]; u8 *f14; } Tbl_021B810C;

typedef struct Mgr_021B824C {
    u8 pad00[0x20];
    Tbl_021B810C tbl;
    u8 pad38[0x14];
    u32 f4C;
} Mgr_021B824C;

typedef struct {
    u8 pad[0x14];
    void *x14;
} Obj_021B8314;

typedef struct {
    u8 pad[0xC];
    void *xc;
} Obj_021B8328;

struct Ent_021B835C { char pad[0x48]; };

struct Tbl { char pad00[2]; volatile u16 f2; char pad04[0x10]; struct Ent_021B835C *f14; };

struct Obj_021B83FC {
    char pad00[4];
    struct Ent_021B835C *f4;
    char pad08[4];
    s32 fC;
    s32 f10;
    s32 f14;
    char pad18[0xC];
    struct Tbl *f24;
};

typedef struct { u16 a, b, c, d; } Q;

typedef struct {
    u8 b[0x24];
} Elem_021B8820;

typedef struct {
    u16 h0;
    u16 h2;
    u16 n4;
    u16 n6;
    u16 n8;
    u16 na;
    u16 nc;
    u16 he;
    u8 pad10[8];
    Elem_021B8820 *p18;
    Elem_021B8820 *p1c;
    void **p20;
    void **p24;
    void **p28;
} Table;

extern u32 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C54(u8 *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec_021B7494 *rec);
extern int func_02190728(void *a);
extern void func_02190788(u8 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02190758(int a0, int a1, u16 a2, int a3);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_021907C0(u8 *p);
extern u8 func_02045730(struct Descriptor *p);
extern struct G *func_02192788(struct Fx *a);
extern int func_0219077C(u8 *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_021928C0(struct Cur *c, u32 win, u32 col);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern void func_021927B0(u8 *p);
extern void *func_0201292C(const struct BigObj *p);
extern u16 func_02009310(const struct Sub02009210Obj *obj, int i);
extern u8 func_02009330(const struct Sub02009210Obj *obj, int i);
extern int func_02007E3C(void *a, u32 b, u32 c, u32 d);
int func_02007E50(void *saved, int a, int b, int c);
void func_02009364(struct Sub02009210Obj *obj, int i);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_021B7364 *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A104(char *p, unsigned int idx);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_0200A13C(u8 *p, u32 i);
extern void func_021B9164(void *e, void *p, void *o);
extern u16 *func_021B9464(u16 *p);
extern u16 func_021B91A8(u8 *p);
extern int func_021B91AC(u32 a);
extern Cb func_021B8870(void *p, u32 v);
extern u8 *func_021B9510(u16 *p, u8 *q, u32 v);
extern u32 *func_021B8848(u8 *a, u32 b);
extern HitFn func_021B88B8(u8 *a, u32 b);
extern int func_021B9828(VecFx32_021B7A84 *a, VecFx32_021B7A84 *b, VecFx32_021B7A84 *c, VecFx32_021B7A84 *d, VecFx32_021B7A84 *e, VecFx32_021B7A84 *f);
extern void func_0207CA00(const VecFx32_021B7A84 *a, const VecFx32_021B7A84 *b, VecFx32_021B7A84 *ab);
extern void func_0207CAE8(const VecFx32_021B7A84 *a, const VecFx32_021B7A84 *b, VecFx32_021B7A84 *axb);
extern fx32 func_0207CF3C(const VecFx32_021B7A84 *v1, const VecFx32_021B7A84 *v2);
extern int func_021B94C0(u16 *p, u16 v);
extern void func_021B9478(u16 *p, u16 v);
extern void func_021B949C(u16 *p, u16 v);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern int func_021B9278(u8 *, void *, Tbl_021B7DE0 *);
extern int func_021B9280(u8 *a, u32 arg2, u32 arg3, u8 *tbl);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_021B919C(u8 *p, u32 a);
extern void func_021B91F8(Sub_021B7EE4 *p, V3_021B7EE4 *out);
extern void func_021B9238(Sub_021B8050 *p, Arg_021B8050 *out);
extern int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5);
extern void VEC_Subtract(const V3 *a, const V3 *b, V3 *ab);
extern void VEC_Normalize(const V3 *src, V3 *dst);
extern int func_021B88DC(Sub_021B810C *p, int dir, int d);
extern void func_021B977C(u8 *p);
extern void func_021B91C8();
int func_021B95C0(u8 *p, u8 *q, int a3, int a4, u8 *sr, u32 a6);
int func_021B93D4(int dir);
int func_021B963C(u8 *a, u8 *b);
int func_021B9434(int dir);
int func_021B9404(int dir);
extern void func_02082BCC();
extern void func_02082D44(u32 a, u32 b, u32 c);
int func_021B7364(void *a, void *b);
int func_021B7390(u32 a, int b);
int func_021B73B8(u32 a, u32 b);
PostmanList *func_021B7400(u32 a, u32 b, int c);
int func_021B7494(void *a);
void func_021B74CC(PostmanList *p);
int func_021B7574(void *task, int *st, Work *w);
Pair *func_021B7640(u32 a, u32 b, u32 c, int *d);
void func_021B76B4(void *a0, int a1, int a2);
int func_021B76F8(void *p, int key, void *q);
void *func_021B7740(void *p, int key, void *q, int idx);
void *func_021B7794(void *p);
struct Ent_021B77E4 *func_021B77E4(void *a, void *b, struct Ent_021B77E4 *c);
void *func_021B7834(void *a, int *out, void *buf);
void func_021B785C(u8 *p, u32 i);
u8 func_021B7864(void *a);
struct Obj_021B7364 *func_021B7884(u16 heap, u32 n, int a2);
void func_021B791C(void **o);
void func_021B7934(u32 a, u32 b);
u32 func_021B7954(u32 a);
void func_021B7970(Ctx *c);
int func_021B79AC(u32 a, u32 b, u32 c, u32 d);
void func_021B79C4(u32 *p, u32 v);
void func_021B79CC(u32 *p);
void func_021B79D4(void **o, void *out);
void func_021B79E4(unsigned short *p);
int func_021B79F0(struct Obj_021B79AC *o, int flag);
int func_021B7A84(u8 *p, const VecFx32_021B7A84 *pa, const VecFx32_021B7A84 *pb, Rect4_021B7A84 *r, VecFx32_021B7A84 *out);
void func_021B7C04(u8 *o, int k, int flag);
int func_021B7C38(u8 *o);
void func_021B7C58(Outer_021B7364 *o, void *a1, u16 a2, u16 a3, u16 a4, Arg_021B7C58 *out);
int func_021B7C90(struct Mgr_021B7364 *m, void *r, u16 key, void *q);
int func_021B7CD8(struct Mgr_021B7CD8 *m, const Rect4_021B7A84 *r, u8 key, Rect4_021B7A84 *out);
void func_021B7D38(struct Mgr_021B7D38 *m, void *r, void *out);
int func_021B7D50(Outer_021B7D50 *o, void *out);
void func_021B7D68(struct Obj_021B7D68 *o, void *r);
void func_021B7DC0(struct Cam_021B7D50 *c, Rect4_021B7DC0 * __restrict out);
int func_021B7DE0(Obj_021B7DE0 *o, Arg_021B7DE0 *a);
u8 func_021B7E60(struct Cam_021B7DE0 *c, u8 key, Rect4_021B7A84 *out, V3 *pos);
void func_021B7ED4(u8 *o, Triple *out);
void func_021B7EE4(Sub_021B7EE4 *p, const Out *q);
void func_021B8028(u8 *o, Triple *out);
u8 func_021B8038(u8 *p);
u8 func_021B8040(u8 *p);
u8 func_021B8048(u8 *p);
void func_021B8050(Sub_021B8050 *o, s16 *out);
u32 func_021B80D8(u8 *p);
int func_021B80E0(Obj_021B80E0 *o, u16 a, u16 b);
void func_021B810C(Sub_021B810C *o);
u32 func_021B821C(u8 *p);
u32 func_021B8220(u8 *p);
void func_021B8224(u8 *p, u32 a1);
void func_021B8230(u8 *p, u32 a1);
void func_021B823C(u8 *p, int k);
u32 func_021B8248(u8 *p);
u32 func_021B824C(u8 *p);
void func_021B8250(const Mgr_021B824C *m, const Arg_021B8050 *src, Arg_021B8050 *out);
u16 func_021B82F0(u8 *p);
u32 func_021B82F4(u8 *p);
u32 func_021B82F8(u8 *p);
u32 func_021B82FC(u8 *p);
u32 func_021B8300(u8 *p);
u32 func_021B8304(u8 *p);
u32 func_021B8308(u8 *p);
void func_021B830C(void);
void func_021B8314(Obj_021B8314 *o, void *x);
void func_021B8328(Obj_021B8328 *o, void *a, void *b);
u8 *func_021B833C(u8 *p);
u8 *func_021B834C(u8 *p);
void func_021B835C(u8 *p);
void func_021B836C(u8 *p, u8 *q);
int func_021B8378(int x);
int func_021B83B0(const s32 *a, const s32 *b, s32 r);
void func_021B83FC(struct Obj_021B83FC *o, u16 *out0, u16 *out1, u16 *out2);
void func_021B8484(u8 *p, u32 a, u32 b, int c);
u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag);
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7);
void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
int func_021B8674(u8 *p, u32 *q, u32 v);
int func_021B868C(u8 *p, u32 *q, void *v);
void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6);
void func_021B87BC(u32 a);
void func_021B87C8(u32 a, u32 b);
u8 *func_021B87D8(u8 *p, u32 idx);
u8 *func_021B87FC(u8 *p, u32 idx);
Elem_021B8820 *func_021B8820(Table *t, u32 i);
extern u16 d_021D99E8[];
extern u16 d_021D99D4[];
extern u8 d_021D99DE[];
extern u8 d_021DE288[];
extern const char g_021DE2A0[];
extern const VecFx32_021B7A84 d_021D9A00;
extern const u8 d_021DE298[];
extern struct Elem_021B8820 d_021D9A0C;












int func_021B7364(void *a, void *b)
{
    u32 v;
    u16 *p;

    v = func_02159B10(a, b);
    p = func_02159AE8(a, b);
    if (v >= 11) {
        v = 0;
    }
    *p = d_021D99E8[v];
    return 0;
}












int func_021B7390(u32 a, int b)
{
    u32 i;
    u16 k;

    k = (a << 8) | b;
    for (i = 0; i < 5; i++) {
        if (k == d_021D99D4[i]) {
            return 1;
        }
    }
    return 0;
}












/*
 * Addresses are Black-image addresses.
 */
int func_021B73B8(u32 a, u32 b)
{
    u16 *out;
    void *h;
    u32 x;
    int y;

    out = func_02159AE8((void *)a, (void *)b);
    h = func_0215A5E4((void *)b);
    x = func_021690D0((int)h);
    y = func_021690E0((int)h);
    if (func_021B7390(x, y) == 1)
        *out = 10;
    else
        *out = d_021D99DE[y % 10];
    return 0;
}












PostmanList *func_021B7400(u32 a, u32 b, int c)
{
    u32 heap;
    PostmanList *o;
    int line;
    int sz;

    heap = func_02188C84((u8 *)a);
    line = 0x73;
    o = func_02030734(heap, 0x28, 1, (const char *)d_021DE288, line);
    o->f0 = heap;
    o->f4 = a;
    o->f24 = (Entry *)b;
    o->f20 = c;
    line += 0xc8;
    o->f8 = (u32)func_02045B38(0, 3, line, heap);
    o->f14 = (u32)func_0201EC64(heap);
    o->f18 = (u32)func_020457B0(0x80, heap);
    o->f1C = (u32)func_020457B0(0x80, heap);
    sz = (c * 14 + 7) & ~7;
    o->fC = (u32)func_02190708((struct Fx *)func_02188C54((u8 *)a), o->f8, 1, 1, 0x15, (u16)(sz / 8));
    return o;
}












/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B7494(void *a)
{
func_02190788((u8 *)(((struct Obj04890 *)((u8 *)(a)))->fC));
func_02190728((void *)(((struct Obj04890 *)((u8 *)(a)))->fC));
func_020409B4(1);
func_02045808((struct U16Vec *)(((struct Obj04890 *)((u8 *)(a)))->f18));
func_02045808((struct U16Vec *)(((struct Obj04890 *)((u8 *)(a)))->f1C));
func_0201ED04((struct WordSet *)(((struct Obj04890 *)((u8 *)(a)))->f14));
func_02045C04((struct Rec_021B7494 *)(((struct Obj04890 *)((u8 *)(a)))->f8));
return func_020307B0(a);
}











void func_021B74CC(PostmanList *p)
{
    void *msg;
    int i;

    msg = func_02045B38(0, 2, 0x36, (u16)((p->f0 & 0x7fff) | 0x8000));
    for (i = 0; i < p->f20; i++) {
        func_02045CAC((struct MsgBank *)((u32)msg), p->f24[i].a, (void *)p->f18);
        func_02190758(p->fC, 0, i * 14, p->f18);
        func_02045CAC((struct MsgBank *)p->f8, 5, (void *)p->f18);
        func_0201EFA4((struct WordSet *)p->f14, 0, p->f24[i].b, 2, 1, 1);
        func_0201F250((struct WordSet *)p->f14, (void *)p->f1C, (void *)p->f18);
        func_02190758(p->fC, 0x6c, i * 14, p->f1C);
    }
    func_02045C04(msg);
    func_020409B4(func_02045730((struct Descriptor *)func_021907C0((u8 *)p->fC)));
}











/*
 * Addresses are Black-image addresses.
 */
int func_021B7574(void *task, int *st, Work *w)
{
    u16 n;
    u32 h;
    u16 t;

    switch (*st) {
    case 0:
        n = w->fC - w->f10;
        if (n > 7) {
            n = 7;
        }
        w->f4 = func_021B7400(w->f0, (u32)(w->f8 + w->f10), n);
        func_021B74CC(w->f4);
        w->f4->f10 = (u32)func_02192788((struct Fx *)func_02188C54((u8 *)w->f0));
        (*st)++;
        break;
    case 1:
        if (func_0219077C((u8 *)w->f4->fC) == 1) {
            (*st)++;
        }
        break;
    case 2:
        h = func_021907C0((u8 *)w->f4->fC);
        func_021928C0((struct Cur *)w->f4->f10, (u32)func_02045770((struct Descriptor *)h), 15);
        func_02045334((struct Descriptor *)h);
        if (func_020362DC() & 1) {
            func_020061E4(0x547);
            (*st)++;
        }
        break;
    case 3:
        func_021927B0((u8 *)w->f4->f10);
        func_021B7494((void *)w->f4);
        (*st)++;
        break;
    case 4:
        if (w->f10 + 7 >= w->fC) {
            func_020307B0(w->f8);
            return 1;
        }
        w->f10 += 7;
        *st = 0;
        break;
    }
    return 0;
}











Pair *func_021B7640(u32 a, u32 b, u32 c, int *d)
{
    Pair *buf;
    void *h;
    int n;
    int i;
    u16 x;
    u16 y;

    h = func_0201292C((const struct BigObj *)a);
    buf = func_02030734(b, 0x50, 1, (const char *)d_021DE288, 0x14d);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        x = func_02009310((const struct Sub02009210Obj *)c, i);
        y = func_02009330((const struct Sub02009210Obj *)c, i);
        if (x != 0 && func_02007E3C(h, x, y, b) == 1) {
            buf[n].a = x;
            buf[n].b = y;
            n++;
        }
    }
    *d = n;
    return buf;
}











/*
 * Iterates 0x14 slots of a container, matching each non-null entry through a
 * four-argument predicate and releasing the ones it accepts.
 */
void func_021B76B4(void *a0, int a1, int a2)
{
    void *saved = func_0201292C(a0);
    u32 i;

    for (i = 0; i < 0x14; i++) {
        int r6 = func_02009310((const struct Sub02009210Obj *)a2, i);
        int r2 = func_02009330((const struct Sub02009210Obj *)a2, i);
        if (r6 != 0) {
            if (func_02007E50(saved, r6, r2, a1) == 1)
                func_02009364((struct Sub02009210Obj *)a2, i);
        }
    }
}











/*
 * Addresses are Black-image addresses.
 */
int func_021B76F8(void *p, int key, void *q)
{
    void *ctx;
    u32 i;
    int n;
    u32 a;
    int b;

    ctx = func_0201292C(p);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        a = func_02009310(q, i);
        b = func_02009330(q, i);
        if (a != 0) {
            if (func_02007E3C(ctx, a, b, key) == 0)
                n++;
        }
    }
    return n;
}











void *func_021B7740(void *p, int key, void *q, int idx)
{
    void *ctx;
    int i;
    int n;
    u32 a;
    int b;

    ctx = func_0201292C(p);
    i = 0;
    n = 0;
    for (; i < 0x14; i++) {
        a = func_02009310(q, i);
        b = func_02009330(q, i);
        if (a != 0) {
            if (func_02007E3C(ctx, a, b, key) == 0) {
                if (n == idx)
                    return (void *)a;
                n++;
            }
        }
    }
    return 0;
}











void *func_021B7794(void *p)
{
    void *a;
    void *b;
    void *res;
    struct Rec_021B7494 *r;

    a = func_020120F4(p);
    b = func_02009448(func_02012EBC(a));
    res = func_020122C0(p, 0, (void *)func_021B7574, 0x14);
    r = func_020124E8(res);
    r->f0 = func_0201210C(p);
    r->f10 = 0;
    r->f8 = func_021B7640((u32)a, func_02188C84((u8 *)r->f0), (u32)b, (int *)r->fC);
    return res;
}











struct Ent_021B77E4 *func_021B77E4(void *a, void *b, struct Ent_021B77E4 *c)
{
    u8 v;

    if (func_0200A0E4(a, (u32)b) == 0)
        return 0;
    if (func_0200A104(a, (unsigned int)b) == 1)
        return 0;
    if (func_0200A000(a, (int)b, c) == 0)
        return 0;
    v = c->fB3;
    if (v == 0)
        return 0;
    if (v > 3)
        c = 0;
    return c;
}











void *func_021B7834(void *a, int *out, void *buf)
{
    int i;

    for (i = 0; i < 12; i++) {
        if (func_021B77E4(a, (void *)i, buf)) {
            *out = i;
            return buf;
        }
    }
    return 0;
}











void func_021B785C(u8 *p, u32 i)
{
    func_0200A13C(p, i);
}











u8 func_021B7864(void *a)
{
    int idx;
    u8 buf[0xCC];
    u8 *p;

    p = func_021B7834(a, &idx, buf);
    if (p == 0) {
        return 0;
    }
    return p[0xB3];
}











struct Obj_021B7364 *func_021B7884(u16 heap, u32 n, int a2)
{
    u32 i;
    struct Obj_021B7364 *o;

    o = func_02030734(heap, 0x74, 1, g_021DE2A0, 302);
    o->f0 = heap;
    o->f2 = 0;
    o->f4 = 1;
    o->f10 = a2;
    o->f14 = 0;
    o->f8 = func_02030734(heap, 0x7c * n, 1, g_021DE2A0, 311);
    o->fC = n;
    for (i = 0; i < n; i++)
        func_021B9164(&o->f8[i], o->f20, o);
    o->f1C = func_02030734(heap, 0x7c, 1, g_021DE2A0, 319);
    func_021B9164(o->f1C, o->f20, o);
    o->f1C->f2 = 1;
    return o;
}











void func_021B791C(void **o)
{
    func_020307B0(o[7]);
    func_020307B0(o[2]);
    func_020307B0(o);
}











/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021B7934(u32 a, u32 b)
{
((struct Obj18099 *)((u8 *)(a)))->f2 = 1;
func_021B9464((u16 *)(a + 80));
func_021B87C8((a + 32), b);
}











u32 func_021B7954(u32 a)
{
((struct Obj18100 *)((u8 *)(a)))->f2 = 0;
func_021B87BC((a + 32));
return (u32)func_021B9464((u16 *)(a + 80));
}











void func_021B7970(Ctx *c)
{
    Elem_021B7970 *found = 0;
    int i;

    for (i = 0; i < c->count; i++) {
        if (func_021B91A8((u8 *)(&c->arr[i])) == 0) {
            found = &c->arr[i];
            break;
        }
    }
    found->f2 = 1;
}












/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021B79AC(u32 a, u32 b, u32 c, u32 d)
{
func_021B9164((void *)b, (void *)(a + 32), (void *)a);
((struct Obj01358 *)((u8 *)(b)))->f2 = 0;
return 0;
}












/*
 * Unlabelled leaf: stores v at +0x14 and 1 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021B79C4(u32 *p, u32 v)
{
    p[5] = v;
    p[6] = 1;
}












/*
 * Unlabelled leaf: clears the word at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021B79CC(u32 *p)
{
    p[5] = 0;
}












void func_021B79D4(void **o, void *out)
{
    if (o[5] != 0) {
        func_021B8028((u8 *)o[5], (Triple *)out);
    }
}











void func_021B79E4(unsigned short *p)
{
    if (p[1] == 0)
        return;
    if (p[2])
        return;
}












/*
 * Addresses are Black-image addresses.
 */
int func_021B79F0(struct Obj_021B79AC *o, int flag)
{
    struct Sub *t;
    u32 v;
    Cb cb;

    cb = 0;
    t = o->f14;
    if (o->f2 == 0)
        return 0;
    if (o->f4 == 0)
        return 0;
    if (t == 0)
        return 0;
    if (func_021B91AC((u32)t) == 0)
        return 0;
    if (func_021B8048((u8 *)t) == 0 && o->f18 == 0 && flag == 0)
        return 0;
    switch (t->f0) {
    case 0:
        v = t->f4->f3C;
        if (v == 0xFFFF)
            break;
        cb = func_021B8870(t->f24, *(u32 *)func_021B8820((Table *)t->f24, v));
        break;
    case 1:
        v = t->f4->f10;
        if (v == 0xFFFF)
            break;
        cb = func_021B8870(t->f24, *(u32 *)func_021B8820((Table *)t->f24, v));
        break;
    }
    if (cb)
        cb(o);
    o->f18 = 0;
    return 1;
}












int func_021B7A84(u8 *p, const VecFx32_021B7A84 *pa, const VecFx32_021B7A84 *pb, Rect4_021B7A84 *r, VecFx32_021B7A84 *out)
{
    VecFx32_021B7A84 hit;
    VecFx32_021B7A84 d;
    VecFx32_021B7A84 n;
    VecFx32_021B7A84 up;
    VecFx32_021B7A84 bestPos;
    VecFx32_021B7A84 a;
    VecFx32_021B7A84 b;
    Rect4_021B7A84 bestR;
    int i;
    fx32 best;
    int found;
    u32 *t;
    Node *n0;
    Node *n1;
    u32 *m;
    HitFn f;
    fx32 dist;

    up = d_021D9A00;
    a = *pa;
    b = *pb;
    found = 0;
    for (i = 0; i < ((struct Obj20053 *)p)->f22; i++) {
        t = (u32 *)func_021B9510((u16 *)(p + 0x50), p + 0x20, i);
        if (t == 0) {
            continue;
        }
        n0 = (Node *)func_021B87D8(p + 0x20, t[0]);
        n1 = (Node *)func_021B87D8(p + 0x20, t[1]);
        m = func_021B8848(p + 0x20, t[3]);
        func_0207CA00(&n0->pos, &n1->pos, &d);
        func_0207CAE8(&d, &up, &n);
        if (func_021B9828(&d, &n, &n1->pos, &a, &b, &hit) == 0) {
            continue;
        }
        f = func_021B88B8(p + 0x20, *m);
        if (f == 0) {
            continue;
        }
        if (f(i, p, &hit, r, out) == 0) {
            continue;
        }
        if (!found) {
            bestR = *r;
            bestPos = *out;
            best = func_0207CF3C(&a, out);
            found = 1;
        } else {
            dist = func_0207CF3C(&a, out);
            if (dist < best) {
                bestR = *r;
                bestPos = *out;
                best = dist;
            }
        }
    }
    if (found) {
        *r = bestR;
        *out = bestPos;
    }
    return found;
}












void func_021B7C04(u8 *o, int k, int flag)
{
    if (flag == 0) {
        if (func_021B94C0((u16 *)(o + 0x50), k) == 0) {
            func_021B9478((u16 *)(o + 0x50), k);
        }
    } else {
        func_021B949C((u16 *)(o + 0x50), k);
    }
}










int func_021B7C38(u8 *o)
{
    return (int)(((s64)((struct Obj20055 *)o)->f4C * 0x10000 + 0x800) >> 12);
}









void func_021B7C58(Outer_021B7364 *o, void *a1, u16 a2, u16 a3, u16 a4, Arg_021B7C58 *out)
{
    Inner_021B7C58 *t = o->x1c;

    t->x24 = a1;
    out->h0 = a2;
    out->b2 = 1;
    out->h4 = 0;
    out->h6 = a3;
    func_021B7EE4((Sub_021B7EE4 *)t, (const Out *)out);
    out->h4 = a4 - t->x18 / 16;
    t->x24 = (u8 *)o + 0x20;
}







int func_021B7C90(struct Mgr_021B7364 *m, void *r, u16 key, void *q)
{
    func_021B7EE4((Sub_021B7EE4 *)((Inner_021B7C58 *)m->f1C), (const Out *)((Arg_021B7C58 *)r));
    func_021B80E0((Obj_021B80E0 *)m->f1C, 4, key);
    func_021B810C((Sub_021B810C *)((struct Sub *)m->f1C));
    func_021B8028((u8 *)m->f1C, (Triple *)q);
    if (func_0203EFC8(r, m->f1C + 0x5C, 8) == 0)
        return 0;
    return func_021B7DE0((Obj_021B7DE0 *)m->f1C, (Arg_021B7DE0 *)(m->f1C + 0x5C));
}






int func_021B7CD8(struct Mgr_021B7CD8 *m, const Rect4_021B7A84 *r, u8 key, Rect4_021B7A84 *out)
{
    Rect4_021B7A84 old = *r;

    func_021B7EE4((Sub_021B7EE4 *)((Inner_021B7C58 *)m->f1C), (const Out *)((Arg_021B7C58 *)r));
    func_021B80E0((Obj_021B80E0 *)m->f1C, 4, key);
    func_021B810C((Sub_021B810C *)m->f1C);
    func_021B7DC0((struct Cam_021B7D50 *)m->f1C, (Rect4_021B7DC0 *__restrict)out);
    if (func_0203EFC8((const u8 *)(&old), (const u8 *)out, 8) == 0)
        return 0;
    return func_021B7DE0((Obj_021B7DE0 *)m->f1C, (Arg_021B7DE0 *)out);
}





void func_021B7D38(struct Mgr_021B7D38 *m, void *r, void *out)
{
    func_021B7EE4((Sub_021B7EE4 *)m->f1C, (const Out *)r);
    func_021B8028((u8 *)m->f1C, (Triple *)out);
}











int func_021B7D50(Outer_021B7D50 *o, void *out)
{
    func_021B7EE4((Sub_021B7EE4 *)o->x1c, (const Out *)out);
    return o->x1c->x18 / 16;
}












/*
 * Addresses are Black-image addresses.
 */
void func_021B7D68(struct Obj_021B7D68 *o, void *r)
{
    Cb cb;
    struct Sub *keep;
    struct Sub *t;
    u32 v;

    cb = 0;
    func_021B7EE4((Sub_021B7EE4 *)((Inner_021B7D50 *)o->f1C), (const Out *)r);
    keep = o->f14;
    t = o->f1C;
    o->f14 = t;
    switch (t->f0) {
    case 0:
        v = t->f4->f3C;
        if (v == 0xFFFF)
            break;
        cb = func_021B8870(t->f24, *(u32 *)func_021B8820((Table *)t->f24, v));
        break;
    case 1:
        v = t->f4->f10;
        if (v == 0xFFFF)
            break;
        cb = func_021B8870(t->f24, *(u32 *)func_021B8820((Table *)t->f24, v));
        break;
    }
    if (cb)
        cb(o);
    o->f14 = keep;
}












/*
 * The out parameter is __restrict: it lets the scheduler pair the last two
 * halfword loads ahead of their stores (see docs/idioms/a-restrict-table-parameter-
 * hoists-a-load-above-a-store-only-at-a-different-offset.md).
 *
 * Addresses are Black-image addresses.
 */
void func_021B7DC0(struct Cam_021B7D50 *c, Rect4_021B7DC0 * __restrict out)
{
    *out = c->f5C;
}











int func_021B7DE0(Obj_021B7DE0 *o, Arg_021B7DE0 *a)
{
    Tbl_021B7DE0 *t;
    u8 *base;
    int off;
    int x;
    int y;
    int v;
    int w;
    int pad;

    if (a->b2 == 0) {
        if (a->h0 >= o->x24->h0) {
            return 0;
        }
    } else {
        t = o->x24;
        if (a->h0 >= t->h2) {
            return 0;
        }
        base = t->x14;
        off = a->h0 * 0x48;
        pad = 0;
        x = a->h6 << 4;
        y = a->h4 << 4;

        v = func_021B9278(base + (off + pad), o->x1c, t);
        w = func_021B9280(base + off, x, v, (u8 *)o->x24);
        if (-w > y || y > w) {
            return 0;
        }
        if (x > v || x < 0) {
            return 0;
        }
    }
    return 1;
}











u8 func_021B7E60(struct Cam_021B7DE0 *c, u8 key, Rect4_021B7A84 *out, V3 *pos)
{
    if (c->f74 == 0 || key != c->f76) {
        c->f75 = func_021B7CD8((struct Mgr_021B7CD8 *)c->f78, (const Rect4_021B7A84 *)(&c->f5C), key, &c->f6C);
        func_021B7D38((struct Mgr_021B7D38 *)c->f78, &c->f6C, &c->f50);
        c->f74 = 1;
        c->f76 = key;
    }
    if (out != 0)
        MI_CpuCopy8(&c->f6C, out, 8);
    if (pos != 0)
        *pos = c->f50;
    return c->f75;
}











void func_021B7ED4(u8 *o, Triple *out)
{
    *out = *(Triple *)(o + 0x44);
}










void func_021B7EE4(Sub_021B7EE4 *p, const Out *q)
{
    Rec_021B7EE4 *o;
    int i;
    u32 m;
    u32 d;
    u32 e;
    u32 c;
    u32 v;

    o = 0;
    func_021B919C((u8 *)p, (u32)p->f24);
    if (q->t == 0) {
        p->f0 = 0;
        p->f4 = &p->f24->f10[q->a];
        p->f18 = p->f4->f20;
        for (i = 0; i < 4; i++) {
            if (p->f4->arr[i] != 0xFFFF && o == 0) {
                o = &p->f24->f14[p->f4->arr[i]];
                if (o->f0 == q->a) {
                    d = 0;
                    e = 0;
                    c = p->f4->f10[i];
                } else if (o->f4 == q->a) {
                    d = func_021B9278((u8 *)o, (void *)p->f1C, (Tbl_021B7DE0 *)p->f24);
                    e = 0;
                    c = p->f4->f10[i];
                }
            }
        }
    } else {
        o = &p->f24->f14[q->a];
        v = q->d;
        if (v >= o->f14) {
            v--;
        }
        d = v << 4;
        e = q->e << 4;
        c = q->c;
    }
    m = func_021B9278((u8 *)o, (void *)p->f1C, (Tbl_021B7DE0 *)p->f24);
    func_021B8658((u8 *)p, (u32)o, c, d, e, m, func_021B9280((u8 *)o, d, m, (u8 *)p->f24));
    p->f33 = 1;
    p->f32 = c;
    p->f8 = 1;
    func_021B91F8(p, &p->f38);
    p->f5C = *q;
    p->f64 = *q;
    p->f44 = p->f38;
}










void func_021B8028(u8 *o, Triple *out)
{
    *out = *(Triple *)(o + 0x38);
}










/*
 * Loads the byte at byte +0x32 of the object.
 */
u8 func_021B8038(u8 *p)
{
    return ((struct Obj18102 *)p)->f32;
}









u8 func_021B8040(u8 *p)
{
    return ((struct Obj18103 *)p)->f2C;
}









/*
 * Loads the byte at byte +0x34 of the object.
 */
u8 func_021B8048(u8 *p)
{
    return ((struct Obj18104 *)p)->f34;
}









static inline void set3(s16 *d, int x, int y, int z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}









void func_021B8050(Sub_021B8050 *o, s16 *out)
{
    V3 a;
    V3 b;
    Arg_021B8050 q;
    s32 cur;
    s32 lim;
    s32 end;
    u32 save;

    save = o->f14;
    o->f14 = 0;
    func_021B91F8((Sub_021B7EE4 *)o, (V3_021B7EE4 *)&a);
    cur = o->fC;
    o->f14 = save;
    lim = o->f10;
    end = cur + 0x10;
    if (end < lim) {
        o->fC += 0x10;
        o->f14 = 0;
        func_021B91F8((Sub_021B7EE4 *)o, (V3_021B7EE4 *)&b);
        o->f14 = save;
        o->fC = cur;
    } else {
        func_021B9238(o, &q);
        q.h4 = 0;
        func_021B9368(o->f78, (u32)(&q), o->f4->f8, end - lim, (u32)(&b));
    }
    VEC_Subtract(&b, &a, &b);
    VEC_Normalize(&b, &b);
    set3(out, b.x, b.y, b.z);
}









u32 func_021B80D8(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj00454 *)p)->f4;

    return ((struct Obj18105 *)q)->f8;
}









int func_021B80E0(Obj_021B80E0 *o, u16 a, u16 b)
{
    if (o->b2c == 0) {
        o->b2c = 1;
        o->b2d = 0;
        o->h2e = b;
        o->h30 = a;
        return 1;
    }
    return 0;
}









/*
 * The table byte is also func_021B88DC's third argument: the callee's
 * matched prototype is (p, dir, d), and the image leaves the ldrb value in
 * r2 untouched up to the call. That extra use keeps the byte live across
 * the f2D update, so its sign extension lands in a fresh register (r3).
 * See docs/idioms/a-byte-kept-live-into-a-call-argument-register-pushes-its-sign-extension-to-a-fresh-register.md.
 */
void func_021B810C(Sub_021B810C *o)
{
    int res;
    u16 prev;
    u16 k;
    u8 d;
    s32 rem;

    if (o->f78->f2 == 0)
        return;
    if (o->f8 == 0)
        return;
    if (func_021B91AC((u32)o) == 0)
        return;
    res = 0;
    o->f34 = 0;
    if (o->f2C == 0)
        return;
    prev = o->f0;
    k = o->f2E;
    d = d_021DE298[o->f30];
    o->f2D += (s8)d;
    if (prev == 1)
        res = func_021B88DC(o, k, d);
    if (res != 0) {
        o->f32 = res;
        o->f33 = o->f30;
        o->f34 = 1;
        func_021B91F8((Sub_021B7EE4 *)o, (V3_021B7EE4 *)(&o->f38));
    }
    if (prev != o->f0)
        func_021B977C((u8 *)o);
    if (o->f2D < 0x10 && res != 0)
        return;
    o->f2C = 0;
    o->f74 = 0;
    o->f64 = o->f5C;
    func_021B9238((Sub_021B8050 *)o, (Arg_021B8050 *)(&o->f5C));
    o->f44 = o->f38;
    rem = o->fC % 16;
    if (rem == 0)
        return;
    if (rem > 8)
        o->fC = o->fC + (16 - rem);
    else
        o->fC = o->fC - rem;
}









/*
 * Loads the 32-bit word at byte +0x10 of the object.
 */
u32 func_021B821C(u8 *p)
{
    return ((struct Obj18106 *)p)->f10;
}









u32 func_021B8220(u8 *p)
{
    return ((struct Obj18107 *)p)->f14;
}









/*
 * Tail-call thunk on the object 0x20 bytes in.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8224(u8 *p, u32 a1)
{
    func_021B87D8(p + 0x20, a1);
}









void func_021B8230(u8 *p, u32 a1)
{
    func_021B87FC(p + 0x20, a1);
}









void func_021B823C(u8 *p, int k)
{
    func_021B8848(p + 0x20, k);
}









/*
 * Loads the 32-bit word at byte +0x4c of the object.
 */
u32 func_021B8248(u8 *p)
{
    return ((struct Obj18108 *)p)->f4C;
}









u32 func_021B824C(u8 *p)
{
    return ((struct Obj18109 *)p)->f1C;
}









/*
 * Twin of func_021B7DE0. The first call adds a zero-valued local to off,
 * which gives the early multiply, the spilled offset and the
 * `adds r0,r3,#0` copy. `const Mgr_021B824C *m` lets the base load schedule into the
 * struct copy (`ldr r7,[r6,#0x34]` between the stores to a).
 */
void func_021B8250(const Mgr_021B824C *m, const Arg_021B8050 *src, Arg_021B8050 *out)
{
    Arg_021B8050 a;
    u8 *base;
    s32 off;
    s32 x;
    s32 y;
    s32 v;
    s32 w;
    s32 pad;

    a = *src;
    base = m->tbl.f14;
    *out = a;
    off = a.h0 * 0x48;
    pad = 0;
    y = a.h6 << 4;
    x = a.h4 << 4;
    v = func_021B9278(base + (off + pad), (void *)m->f4C, (Tbl_021B7DE0 *)(&m->tbl));
    w = func_021B9280(base + off, y, v, (u8 *)(&m->tbl));
    if (y >= v)
        out->h6 = (v - 1) / 16;
    if ((x < 0 ? -x : x) > w) {
        if (x > 0)
            out->h4 = w / 16;
        else
            out->h4 = -w / 16;
    }
}









u16 func_021B82F0(u8 *p)
{
    return ((struct Obj18111 *)p)->f0;
}









/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021B82F4(u8 *p)
{
    return ((struct Obj18112 *)p)->f4;
}









/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_021B82F8(u8 *p)
{
    return ((struct Obj18113 *)p)->fC;
}









u32 func_021B82FC(u8 *p)
{
    return ((struct Obj18114 *)p)->f10;
}









/*
 * Loads the 32-bit word at byte +0x14 of the object.
 */
u32 func_021B8300(u8 *p)
{
    return ((struct Obj18115 *)p)->f14;
}









u32 func_021B8304(u8 *p)
{
    return ((struct Obj18116 *)p)->f18;
}









u32 func_021B8308(u8 *p)
{
    return ((struct Obj18117 *)p)->f1C;
}







/*
 * Tail-call thunk: forwards to func_021B91C8 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021B830C(void)
{
    func_021B91C8();
}







void func_021B8314(Obj_021B8314 *o, void *x)
{
    void *save = o->x14;

    o->x14 = 0;
    func_021B91F8((Sub_021B7EE4 *)o, (V3_021B7EE4 *)x);
    o->x14 = save;
}






void func_021B8328(Obj_021B8328 *o, void *a, void *b)
{
    void *save = o->xc;

    o->xc = a;
    func_021B91F8((Sub_021B7EE4 *)o, (V3_021B7EE4 *)b);
    o->xc = save;
}






u8 *func_021B833C(u8 *p)
{
    return func_021B87D8((u8 *)(*(u32 *)&((struct Obj00454 *)p)->f24), *(u32 *)*(u32 *)&((struct Obj00454 *)p)->f4);
}






/*
 * Tail call with two object fields.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_021B834C(u8 *p)
{
    return func_021B87D8((u8 *)(*(u32 *)&((struct Obj00454 *)p)->f24), *(u32 *)(*(u32 *)&((struct Obj00454 *)p)->f4 + 4));
}





void func_021B835C(u8 *p)
{
    func_021B8848((u8 *)(*(u32 *)&((struct Obj00454 *)p)->f24), *(u32 *)(*(u32 *)&((struct Obj00454 *)p)->f4 + 0xc));
}





/*
 * Tail call with a field of each argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021B836C(u8 *p, u8 *q)
{
    (u32 *)func_021B8820((Table *)((void *)(((struct Obj18118 *)p)->f24)), ((struct Obj18119 *)q)->f3C);
}





int func_021B8378(int x)
{
    u32 ax = x < 0 ? -x : x;

    if ((ax & 15) >= 8) {
        if (x >= 0) {
            return x / 16 + 1;
        } else {
            return x / 16 - 1;
        }
    }
    return x / 16;
}





/*
 * Addresses are Black-image addresses.
 */
int func_021B83B0(const s32 *a, const s32 *b, s32 r)
{
    s32 dx, dz, dy, rr, d2, r2;

    dx = (a[0] >> 12) - (b[0] >> 12);
    dz = (a[2] >> 12) - (b[2] >> 12);
    d2 = dx * dx + dz * dz;
    dy = a[1] - b[1];
    if (dy < 0)
        dy = -dy;
    rr = (r >> 12) * 2;
    r2 = rr * rr;
    if (dy < 0x8000 && d2 < r2)
        return 1;
    return 0;
}





/*
 * note: Tbl.f2 is volatile: the original re-reads the count on every pass and the
 *       loop names o->f24 directly (no local for it).
 *
 * Addresses are Black-image addresses.
 */
void func_021B83FC(struct Obj_021B83FC *o, u16 *out0, u16 *out1, u16 *out2)
{
    s32 idx, i, m, n;

    m = func_021B9280((u8 *)o->f4, 0, o->f10, (u8 *)o->f24);
    n = func_021B9280((u8 *)o->f4, o->f10, o->f10, (u8 *)o->f24);
    if (m < n)
        m = n;
    idx = 0;
    for (i = 0; i < o->f24->f2; i++) {
        if (o->f4 == o->f24->f14 + i)
            idx = i;
    }
    *out0 = idx;
    *out1 = o->fC / 16;
    *out2 = o->f14 / 16 + m / 16;
}





void func_021B8484(u8 *p, u32 a, u32 b, int c)
{
    Q q;

    func_021B7DC0((struct Cam_021B7D50 *)p, (Rect4_021B7DC0 *__restrict)&q);
    q.a = a;
    q.c = 0;
    q.d = b;
    func_021B7EE4((Sub_021B7EE4 *)p, (const Out *)&q);
    q.c = c - ((struct Obj03135 *)p)->f18 / 16;
    func_021B91F8((Sub_021B7EE4 *)p, (V3_021B7EE4 *)((V3 *)(p + 0x38)));
    ((struct Obj03135 *)p)->f5C = q.a;
    ((struct Obj03135 *)p)->f5E = q.b;
    ((struct Obj03135 *)p)->f60 = q.c;
    ((struct Obj03135 *)p)->f62 = q.d;
    ((struct Obj03135 *)p)->f64 = q.a;
    ((struct Obj03135 *)p)->f66 = q.b;
    ((struct Obj03135 *)p)->f68 = q.c;
    ((struct Obj03135 *)p)->f6A = q.d;
    *(V3 *)(p + 0x44) = *(V3 *)(p + 0x38);
}





u8 *func_021B8514(u8 *p, u32 v, u8 *q, u16 *r, int flag)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (v == ((u32 *)p)[i + 4]) {
            if (flag)
                return func_021B9510(r, q, ((u32 *)p)[i]);
            return func_021B87FC(q, ((u32 *)p)[i]);
        }
    }
    return 0;
}





/*
 * closed 2026-09-27 (tree_ov018): the early exit is one guard,
 * if (arg4 < arg6 && arg4 >= 0) goto tail; ahead of a plain if/else for the
 * two row lookups, and arg6 is reassigned in place of a separate m local.
 * Addresses are Black-image addresses.
 */
int func_021B854C(u8 *p, u8 *a, u32 arg3, int arg4, int arg5, int arg6, int arg7)
{
    int res;

    if (func_021B95C0(*(u8 * *)&((struct Obj00010 *)p)->f28, a, arg4, arg5,
                      *(u8 * *)&((struct Obj00010 *)p)->f24, *(u32 *)&((struct Obj00010 *)p)->f1C) == 0)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > arg7)
        return 0;
    if (arg4 < arg6 && arg4 >= 0)
        goto tail;
    if (arg4 >= arg6) {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f4);
        res = (int)func_021B8514(row, ((struct Obj02052 *)a)->f8,
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    } else {
        u8 *row = func_021B87D8(*(u8 * *)&((struct Obj00010 *)p)->f24, ((struct Obj02052 *)a)->f0);
        res = (int)func_021B8514(row, func_021B93D4(((struct Obj02052 *)a)->f8),
                                  *(u8 * *)&((struct Obj00010 *)p)->f24, *(u16 * *)&((struct Obj00010 *)p)->f28, 1);
    }
    if (res == 0) {
        if (arg4 > arg6)
            return 0;
        goto tail;
    }
    a = (u8 *)res;
    if (arg4 >= arg6) {
        arg4 -= arg6;
        arg6 = func_021B9278((u8 *)res, (void *)(*(u32 *)&((struct Obj00010 *)p)->f1C), (Tbl_021B7DE0 *)(*(u32 *)&((struct Obj00010 *)p)->f24));
        arg7 = (u32)func_021B9280((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    } else if (arg4 < 0) {
        arg6 = func_021B9278((u8 *)res, (void *)(*(u32 *)&((struct Obj00010 *)p)->f1C), (Tbl_021B7DE0 *)(*(u32 *)&((struct Obj00010 *)p)->f24));
        arg4 += arg6;
        arg7 = (u32)func_021B9280((u8 *)res, arg4, arg6, *(u8 * *)&((struct Obj00010 *)p)->f24);
    }
    if (arg4 >= arg6)
        return 0;
    if ((arg5 < 0 ? -arg5 : arg5) > (int)arg7)
        return 0;
tail:
    func_021B8658(p, (u32)a, arg3, arg4, arg5, arg6, (int)arg7);
    func_021B963C(a, *(u8 * *)&((struct Obj00010 *)p)->f24);
    return arg3;
}





void func_021B8658(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    ((struct Obj04134 *)p)->f0 = 1;
    ((struct Obj04134 *)p)->f4 = a;
    ((struct Obj04134 *)p)->f14 = d;
    ((struct Obj04134 *)p)->f10 = e;
    ((struct Obj04134 *)p)->f20 = b;
    ((struct Obj04134 *)p)->fC = c;
    ((struct Obj04134 *)p)->f18 = f;
}





int func_021B8674(u8 *p, u32 *q, u32 v)
{
    return func_021B87D8(p, *q) == (u8 *)v;
}





int func_021B868C(u8 *p, u32 *q, void *v)
{
    return func_021B87D8(p, q[1]) == (u8 *)v;
}



/*
 * Scores three neighbouring cells (row from func_021B87D8, then one
 * func_021B8514 lookup per direction) against the start cell q.
 * q is read through a const pointer: with a plain `u32 *q` the outgoing
 * flag store `str r6, [sp]` lands before `adds r2, r5` in the first two
 * func_021B8514 calls (8 bytes).  Declaration order of row/best1 sets their
 * stack slots (best1 at sp+0xc, row at sp+0x10).
 *
 * Addresses are Black-image addresses.
 */
void func_021B86A4(u8 *t, const u32 *q, int *out1, int *out2, u16 *a5, u32 a6)
{
    u32 *row;
    int best1;
    u32 *res1;
    u32 *res2;
    u32 *res3;
    int best2;
    int m;
    int r;

    best1 = 0;
    row = (u32 *)func_021B87D8(t, q[0]);
    res1 = (u32 *)func_021B8514((u8 *)row, func_021B93D4(q[2]), t, a5, 1);
    res2 = (u32 *)func_021B8514((u8 *)row, func_021B9434(q[2]), t, a5, 1);
    res3 = (u32 *)func_021B8514((u8 *)row, func_021B9404(q[2]), t, a5, 1);
    best2 = func_021B9280((u8 *)q, 0, func_021B9278((u8 *)q, (void *)a6, (Tbl_021B7DE0 *)t), t);
    if (res1) {
        m = func_021B9278((u8 *)res1, (void *)a6, (Tbl_021B7DE0 *)t);
        r = func_021B9280((u8 *)res1, m, m, t);
        if (r > best2)
            best2 = r;
    }
    if (res2) {
        m = func_021B9278((u8 *)res2, (void *)a6, (Tbl_021B7DE0 *)t);
        if (func_021B8674(t, res2, (u32)row))
            r = func_021B9280((u8 *)res2, 0, m, t);
        else
            r = func_021B9280((u8 *)res2, m, m, t);
        if (r > best1)
            best1 = r;
    }
    if (res3) {
        m = func_021B9278((u8 *)res3, (void *)a6, (Tbl_021B7DE0 *)t);
        if (func_021B8674(t, res3, (u32)row))
            r = func_021B9280((u8 *)res3, 0, m, t);
        else
            r = func_021B9280((u8 *)res3, m, m, t);
        if (r > best1)
            best1 = r;
    }
    *out1 = best1;
    *out2 = best2;
}



void func_021B87BC(u32 a)
{
    func_02082BCC(a, 0, 48);
}



void func_021B87C8(u32 a, u32 b)
{
    func_02082D44(b, a, 0x30);
}



/*
 * Addresses are Black-image addresses.
 */
u8 *func_021B87D8(u8 *p, u32 idx)
{
    if (((struct Obj02659 *)p)->f0 > idx)
        return *(u8 * *)&((struct Obj02659 *)p)->f10 + idx * 0x70;
    if (idx == 0xFFFF)
        return 0;
    return *(u8 * *)&((struct Obj02659 *)p)->f10;
}



u8 *func_021B87FC(u8 *p, u32 idx)
{
    if (((struct Obj02659 *)p)->f2 > idx)
        return *(u8 * *)&((struct Obj02659 *)p)->f14 + idx * 0x48;
    if (idx == 0xFFFF)
        return 0;
    return *(u8 * *)&((struct Obj02659 *)p)->f14;
}



Elem_021B8820 *func_021B8820(Table *t, u32 i)
{
    if (t->n4 > i) {
        return &t->p18[i];
    }
    if (i == 0xFFFF) {
        return 0;
    }
    return ((Elem_021B8820 *)&d_021D9A0C);
}
