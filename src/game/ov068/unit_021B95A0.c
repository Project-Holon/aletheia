/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B9768, func_021B980C, func_021B9850, func_021B98E0, func_021B9930, func_021B9944, func_021B9950, func_021B995C, func_021B9964, func_021B996C, func_021B9980, func_021B9B6C, func_021B9BD0, func_021B9BFC, func_021B9C04, func_021B9D58, func_021B9D60, func_021B9D68, func_021B9E28, func_021B9F70, func_021B9FC0, func_021BA010, func_021BA018, func_021BA020, func_021BA024, func_021BA030, func_021BA03C, func_021BA190, func_021BA194, func_021BA1C4, func_021BA254, func_021BA278, func_021BA28C, func_021BA31C, func_021BA37C, func_021BA410, func_021BA448, func_021BA644, func_021BA65C, func_021BA668, func_021BA694, func_021BA6B8, func_021BA730, func_021BA734, func_021BA7B4, func_021BA7C0, func_021BA9C0, func_021BA9DC, func_021BA9E0, func_021BA9F0, func_021BA9FC, func_021BAA0C, func_021BABE0, func_021BAC70, func_021BACF4, func_021BAD14, func_021BAD38, func_021BAD58, func_021BAD60, func_021BADFC, func_021BAE28, func_021BAE90, func_021BAEBC, func_021BAEC4, func_021BAF0C, func_021BAF38, func_021BAF5C, func_021BAF9C, func_021BAFA8, func_021BAFD8, func_021BB000, func_021BB0AC, func_021BB0D0, func_021BB0D8, func_021BB0E4, func_021BB0F8, func_021BB114, func_021BB120, func_021BB134, func_021BB138, func_021BB140, func_021BB148, func_021BB188, func_021BB1C4, func_021BB418, func_021BB4A4, func_021BB4D4, func_021BB508
 * address:  0x021B95A0
 * region:   ov068
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
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02027F60  0x02027F60  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0203101C  0x0203101C  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   ov067_id       0x00000043  data
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02027FD8  0x02027FD8  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_020056A0  0x020056A0  thumb
 *   d_021BB598     0x021BB598  data  a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_0201DD68  0x0201DD68  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049DF4  0x02049DF4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020450F0  0x020450F0  arm
 *   d_021BB540  0x021BB540  data  a4
 *   d_021BB614  0x021BB614  data  a4
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045808  0x02045808  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02045738  0x02045738  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   d_021BB820     0x021BB820  data  ov068  a4
 *   func_020419E4  0x020419E4  arm
 *   d_020A1B38     0x020A1B38  data  a2
 *   func_02061CA4  0x02061CA4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BB704     0x021BB704  data  ov068  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204B908  0x0204B908  arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648 0x0204A648 arm
 *   func_02035D20  0x02035D20  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02028470  0x02028470  thumb
 *   func_02045778  0x02045778  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02028484  0x02028484  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_02012BF8  0x02012BF8  thumb
 *   func_021B6598  0x021B6598  thumb  ov067
 *   d_021BB5D4     0x021BB5D4  data  a4
 *   func_021B639C  0x021B639C  thumb
 *   func_02028148  0x02028148  thumb
 *   func_021BB508  0x021BB508  thumb  ov068
 *   func_02028218  0x02028218  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_021B63D0  0x021B63D0  thumb  ov067
 *   func_021B6470  0x021B6470  thumb  ov067
 *   func_021B6448  0x021B6448  thumb  ov067
 *   func_021B65A8  0x021B65A8  thumb  ov067
 *   func_02012BE0  0x02012BE0  thumb
 *   d_021BB550     0x021BB550  data  a4
 *   func_020061E4_2  0x020061E4  thumb
 *   d_021BB560     0x021BB560  data  ov068  a4
 *   func_02028178  0x02028178  thumb
 *   func_02028230  0x02028230  thumb
 *   func_020282A4  0x020282A4  thumb
 *   func_02027FEC  0x02027FEC  thumb
 *   func_02040804  0x02040804  arm
 *   d_021BB570     0x021BB570  data  a4
 *   func_020413B0  0x020413B0  arm
 *   func_0204B8A0  0x0204B8A0  arm
 *   d_021BB538     0x021BB538  data  a1
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 *   func_02005C28  0x02005C28  thumb
 *   func_02027778  0x02027778  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 *   func_0207D658 0x0207D658 arm
 *   func_02008374  0x02008374  thumb
 *   func_020083AC  0x020083AC  thumb
 *   func_020083C8  0x020083C8  thumb
 *   func_02008390  0x02008390  thumb
 *   func_02008428  0x02008428  thumb
 *   func_0200837C 0x0200837C thumb
 *   func_020083B4 0x020083B4 thumb
 *   func_020083D0 0x020083D0 thumb
 *   func_02008398 0x02008398 thumb
 *   func_02008430 0x02008430 thumb
 *   d_021BB572     0x021BB572  data  a2
 *   d_021BB574     0x021BB574  data  a4
 *   d_021BB708     0x021BB708  data  a4
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020071F0  0x020071F0  thumb
 */
#include "../../matched/include/Obj05149.h"
#include "../../matched/include/Obj13137.h"
#include "../../matched/include/Obj20634.h"
#include "../../matched/include/Obj20635.h"
#include "../../matched/include/Obj13138.h"
#include "../../matched/include/Obj20637.h"
#include "../../matched/include/Obj09869.h"
#include "../../matched/include/Obj05150.h"
#include "../../matched/include/Obj01227.h"
#include "../../matched/include/Obj07683.h"
#include "../../matched/include/Obj00884.h"
#include "../../matched/include/Obj03658.h"
#include "../../matched/include/Obj02762.h"
#include "../../matched/include/Obj20641.h"
#include "../../matched/include/Obj13139.h"
#include "../../matched/include/Obj13140.h"
#include "../../matched/include/Obj06169.h"
#include "../../matched/include/Obj20643.h"
#include "../../matched/include/Obj00103.h"
#include "../../matched/include/Obj20644.h"
#include "../../matched/include/Obj04326.h"
#include "../../matched/include/Obj13141.h"
#include "../../matched/include/Obj20645.h"
#include "../../matched/include/Obj09870.h"
#include "../../matched/include/Obj13142.h"
#include "../../matched/include/Obj20646.h"
#include "../../matched/include/Obj20647.h"
#include "../../matched/include/Obj02763.h"
#include "../../matched/include/Obj09871.h"
#include "../../matched/include/Obj02417.h"
#include "../../matched/include/Obj20648.h"
#include "../../matched/include/Obj13144.h"
#include "../../matched/include/Obj20650.h"
#include "../../matched/include/Obj13145.h"
#include "../../matched/include/Obj13146.h"
#include "../../matched/include/Obj20651.h"
#include "../../matched/include/Obj20652.h"
#include "../../matched/include/Obj09875.h"
#include "../../matched/include/Obj20654.h"
#include "../../matched/include/Obj20655.h"

struct Obj0203159C;
struct Big;
struct Ctx;
struct GfFont;
struct MsgBank;
struct R;
struct Sub02008700Obj;
struct Tcbl;
struct PrintSys;
struct Rec;
struct S02031140;
struct S020315D4;
struct TaskMenuState;
struct DispVram;
struct Node;
struct Blk_021B9980;
struct BgTemplate;
struct DispConfig;
struct Descriptor;
struct Bmp;
struct Cfg;
struct CharBuf;
struct StrObj;
struct U16Vec;
struct Bank;
struct Obj;
struct Rec3;
struct S;
struct Vec2;
struct TaskMenu;
struct TaskMenuTmpl;
struct Sub020071E4Ctrl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 x0;
    u32 x4;
} Args;

typedef struct {
    u8 pad0[0xd4];
    u8 xD4[0x10];
    u8 xE4[0x20];
    u8 x104[0x44];
    u8 x148[0x58];
    u8 x1A0[0x38];
    u8 x1D8[0x70];
    u8 x248[0xc];
    u32 font;
    u32 x258;
    u32 msg;
    u32 x260;
    u32 x264;
    u32 x268;
    Args *args;
} Work;

typedef signed int     s32;

typedef struct {
    u32 id;
    u32 w[8];
    u32 f24;
} Row;

typedef struct {
    u8 pad0[0xC];
    u8 *data;
} PlttData;

typedef signed short   s16;

typedef struct {
    u32 msg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Ent_021B9C04;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    u32 offset;
    u32 value;
    u32 f8;
    u32 fC;
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
} Ent_021BB704;

typedef struct { u32 w[16]; } Tbl;

typedef struct { u32 w[8]; } Req;

typedef struct {
    u8 pad0[8];
    int f8;
    int fC;
    int f10;
    u8 pad14[0x20];
    int f34[2];
    int f3C;
    int f40;
} W;

typedef struct { u32 h; u16 x; u16 pad; u32 idx; } Ent_021B9980;

typedef struct { u8 pad[0x1c]; Ent_021B9980 e[2]; } P;

typedef struct Blk_021B9980 { u32 a; u32 b; u32 c; } Blk_021B9980;

typedef struct {
    u32 f0;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Rect;

typedef struct { u16 x; u16 y; } Pt;

typedef signed char   s8;

typedef struct {
    u16 f0;
    u16 cnt;
    u8  list[4];
} Tab;

typedef struct {
    u32 f0;
    u32 f4;
    u32 pad[4];
} Ent_021BAF9C;

typedef void (*Callback)(void *, void *, int);

typedef struct {
    u32 a;
    u8  b;
    u8  pad5[3];
    u32 c;
} Blk_021BB114;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Blk_021BB418;

extern int func_02034AC4(s32 handle);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int a);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32 v);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_020056A0(void (*fn)(void), void *arg, u32 z);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_0203F8F4(u16 heap);
extern void func_02045088(u16 heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8 id);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 a, u32 b, u32 c, u32 d);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *a);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_020307B0(void *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern void func_020403F4(u32 a);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 a);
extern void func_02045808(struct U16Vec *vec);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(u32 a, u32 b, u32 n);
extern u8 func_02045738(struct Descriptor *p);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_020434DC(u32 a, u32 b);
extern void func_02043598(u32 mask, u32 enable);
extern int func_0204ABF0(void *, int, int, int, int);
extern int func_0204A6C8(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204B294(int, int, int, int, Local *, int, int);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_0203CD98(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 a);
extern void func_0204A8D4(u32 a);
extern void func_0204AFD8(u32 a);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204B908(int a0, int a1);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern u32  func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void func_020061E4(u32 id);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02028470(u8 *p, u32 v);
extern u8 func_02045778(struct Descriptor *p);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_020409B4(u32 index);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32  func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                          u32 a7, u16 a8, u16 a9);
extern s32 func_02028484(struct Blk_021B9980 *blk, void *h);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32  func_021B62E0(Req *r, u16 a);
extern int func_02012BF8(int a0, int a1);
extern void func_021B6598(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021B639C(void *a);
extern void func_02028148(u8 *p);
extern int  func_021BB508(int *rect, void *b);
extern void func_020061E4_2(int id);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_0202822C(char *p, int v);
extern void func_021B63D0(struct S *p);
extern int func_021B6470(u8 *p);
extern int func_021B6448(u8 *p);
extern int func_021B65A8(unsigned char *p, int id);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_02028178(u8 *p);
extern u32 func_02028230(u8 *p);
extern void func_020282A4(struct Obj *obj);
extern u32  func_02027FEC(u32 a, u8 *b, u8 c, u32 d, u32 e, u32 f);
extern u32 func_02040804(u32 layer);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_02005C28(u32 a);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void  func_02027974(void *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8    func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_0207D658(u32, int, int);
extern unsigned int func_02008374(int a0);
extern u32 func_020083AC(u32 a);
extern u32 func_020083C8(u32 a);
extern unsigned int func_02008390(char *a0);
extern int func_02008428(unsigned short *p);
extern void func_0200837C(u16 *, unsigned int);
extern void func_020083B4(u16 *, unsigned int);
extern void func_020083D0(u16 *, unsigned int);
extern void func_02008398(u16 *, unsigned int);
extern void func_02008430(u16 *, unsigned int);
extern int func_0203EFC8(const u8 *, const u8 *, u32);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
int func_021B95A0(void *proc, int *seq, Args *args);
int func_021B9768(void *a, u32 b, u32 c, u8 *w);
int func_021B980C(u32 a, u32 b, u32 c, u8 *w);
void func_021B9850(u8 *p, u16 a);
void func_021B98E0(u8 *p);
void func_021B9930(u8 *p);
int func_021B9944(void *p, int i);
int func_021B9950(void *p);
int func_021B995C(int *p, int i);
void func_021B9964(char *p);
void func_021B996C(void *task, char *p);
void func_021B9980(u8 *p, u16 heap);
void func_021B9B6C(u32 *p);
void func_021B9BD0(u8 *p);
int func_021B9BFC(int *p, int i);
void func_021B9C04(u32 *p);
void func_021B9D58(char *p);
void func_021B9D60(char *a0);
void func_021B9D68(u16 *out, u16 *ang, int inc, u32 idx, u8 slot, u16 c0, u16 c1);
void func_021B9E28(int *p, void *res, u32 heap);
void func_021B9F70(u32 *p);
void func_021B9FC0(u8 *p);
void func_021BA010(char *a0);
int func_021BA018(char *p, int i);
int func_021BA020(int *p);
void func_021BA024(void *p, int heap);
void func_021BA030(void *p);
void func_021BA03C(int *p);
int func_021BA190(const int *p);
void func_021BA194(const u8 *p, int which, int *out);
void func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);
void func_021BA254(u8 *p);
void func_021BA278(u8 *p, u32 a, u32 b, u32 c);
void func_021BA28C(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4);
int func_021BA31C(u8 *p);
void func_021BA37C(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3);
void func_021BA410(u8 *p);
void func_021BA448(W *p, void *obj, void *arg);
void func_021BA644(u8 *p);
int func_021BA65C(u8 *p, int *out);
u32 func_021BA668(u8 *p);
void func_021BA694(u8 *p);
void func_021BA6B8(u8 *p, u32 arg);
int func_021BA730(u8 *p);
void func_021BA734(u8 *p, u16 a1, u16 a2, u32 a3, Blk_021B9980 *src, u32 heap);
void func_021BA7B4(void *p);
void func_021BA7C0(u8 *p, void *a1, void *a2, void *a3, void *a4);
void func_021BA9C0(u8 *p, char *q);
int func_021BA9DC(void *p);
void func_021BA9E0(u8 *p, Blk_021B9980 *out);
void func_021BA9F0(u8 *p, int unused);
void func_021BA9FC(u8 *p, u8 v);
void func_021BAA0C(u8 *p, int flag);
void func_021BABE0(u8 *p, int a1, int a2, int a3);
void func_021BAC70(u8 *p, void *b);
void func_021BACF4(u8 *p, u32 a, u32 b);
void func_021BAD14(u8 *p, u32 v);
int func_021BAD38(u8 *p, int *q);
void func_021BAD58(void *p);
void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3);
void func_021BADFC(u8 *p);
void func_021BAE28(u8 *p);
void func_021BAE90(void *p, u32 value);
u16 func_021BAEBC(u8 *p);
void func_021BAEC4(void *a, u32 b, u32 c);
void func_021BAF0C(void *p, u32 id, u32 value);
int func_021BAF38(u8 *p);
void func_021BAF5C(u8 *p, short unsigned int *a);
void func_021BAF9C(void *p);
void func_021BAFA8(u8 *p);
void func_021BAFD8(u8 *p, int i);
void func_021BB000(u8 *p, int i, int delta);
int func_021BB0AC(u8 *p, int i);
u32 func_021BB0D0(void *b);
int func_021BB0D8(void *p);
int func_021BB0E4(const u8 *p, const u8 *q);
void func_021BB0F8(u8 *p, int value, int callback);
void func_021BB114(void *p);
void func_021BB120(u8 *p);
int func_021BB134(void *p);
void func_021BB138(void *p, int v);
void func_021BB140(void *p);
void func_021BB148(void *unused, u32 *p);
void func_021BB188(void *p,u32 *state);
void func_021BB1C4(void *a, u32 *st, u8 *w);
void func_021BB418(void *a0, u32 *st, u8 *base);
void func_021BB4A4(void *a,u32 b,u8 *p);
void func_021BB4D4(void *a,u32 b,u8 *p);
extern u8 ov067_id[];
extern int d_021BB598[];
extern u8 d_021BB540[];
extern Row d_021BB614[];
extern Ent_021B9C04 d_021BB820[];
extern s16  d_020A1B38[];
extern char d_020A1448[];
extern Ent_021BB704 d_021BB704[];
extern Tbl  d_021BB5D4;
extern int d_021BB550[];
extern int d_021BB560[];
extern const u16 d_021BB570[][4];
extern const u8 d_021BB538[];
extern u16 d_021BB572[];
extern u8  d_021BB574[];
extern Ent_021BAF9C d_021BB708[];





int func_021B95A0(void *proc, int *seq, Args *args)
{
    Work *w;
    u32 t;

    func_02034AC4((u32)ov067_id);
    func_0203064C(1, 0x1c, 0x21000);
    w = func_0203159C(proc, sizeof(Work), 0x1c);
    func_02082BCC(w, 0, sizeof(Work));
    w->args = args;
    w->args->x0 = 0;
    func_021B9850((u8 *)w, 0x1c);
    w->font = (u32)func_0201D7EC(0x17, 0, 0, 0, 0x1c);
    w->x258 = func_0201C440((void *)0x1c);
    w->x260 = (u32)func_02027F60(0, 0xd, w->font, w->x258, 0x1c);
    w->x264 = (u32)func_02027F60(3, 9, w->font, w->x258, 0x1c);
    w->msg = (u32)func_02045B38(0, 2, 0x1d, 0x1c);
    w->x268 = (u32)func_0203101C(0x1c, 0x1c, 0x20, 0x20);
    func_021BAF5C(w->x248, (short unsigned int *)func_0200873C(func_02012EBC(func_020120F4((const struct Ctx *)w->args->x4))));
    func_021BB0F8(w->xD4, (int)w, (int)func_021BB148);
    t = (u32)func_020120F4((const struct Ctx *)w->args->x4);
    func_021BA37C(w->x104, func_021B9950(w), w->font, w->x258, w->msg, w->x260, t, 0x1c);
    func_021BA734(w->x148, 1, 2, (u32)w, (struct Blk_021B9980 *)w->x248, 0x1c);
    func_021BA024(w->xE4, 0x1c);
    func_021BA1C4(w->x1A0, func_021B995C((int *)w, 0x11), w->font, w->msg, w->x268, w->x258, 0x1c);
    func_021BAD60(w->x1D8, func_021B995C((int *)w, 0x12), w->font, (void *)w->msg, w->x268, w->x264, w->x258, 0x1c);
    return 1;
}





int func_021B9768(void *a, u32 b, u32 c, u8 *w)
{
    func_021BADFC(w + 0x1d8);
    func_021BA254(w + 0x1a0);
    func_021BA030(w + 0xe4);
    func_021BA7B4(w + 0x148);
    func_021BA410(w + 0x104);
    func_021BB114(w + 0xd4);
    func_021BAF9C(w + 0x248);
    func_02031140(((struct Obj05149 *)w)->f268);
    func_02045C04(((struct Obj05149 *)w)->f25C);
    func_02027FD8(((struct Obj05149 *)w)->f264);
    func_02027FD8(((struct Obj05149 *)w)->f260);
    func_0201C4C0(((struct Obj05149 *)w)->f258);
    func_0201D83C(((struct Obj05149 *)w)->f254);
    func_021B98E0(w);
    func_020315D4(a);
    func_020306F0(0x1c);
    func_02034A5C((int)ov067_id);
    return 1;
}





int func_021B980C(u32 a, u32 b, u32 c, u8 *w)
{
    func_021BB120(w + 0xd4);
    func_021B9930(w);
    func_0201C4E4(((struct Obj13137 *)w)->f258);
    func_020310C4(((struct Obj13137 *)w)->f268);
    func_021BA644(w + 0x104);
    if (func_021BB134(w + 0xd4) != 0)
        return 1;
    return 0;
}





void func_021B9850(u8 *p, u16 a)
{
    func_02082BCC(p, 0, 0xd4);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BB598);
    func_0204363C(0);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_0201DD78(0xf, 0xe, 0);
    func_021B9980(p, a);
    func_021B9E28((int *)(p + 0x7c), d_021BB598, a);
    ((struct Obj20634 *)p)->fD0 = func_020056A0((void (*)(void))func_021B996C, p, 0);
}





void func_021B98E0(u8 *p)
{
    func_02030EAC((struct Node *)(((struct Obj20635 *)p)->fD0));
    func_021B9F70((u32 *)(p + 0x7c));
    func_021B9B6C((u32 *)p);
    func_0201DD68();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u32 *)0x04000000 &= 0xffff1fff;
    *(volatile u32 *)0x04001000 &= 0xffff1fff;
    func_02082BCC(p, 0, 0xd4);
}




void func_021B9930(u8 *p)
{
    func_021B9FC0(p + 0x7c);
    func_021B9BD0(p);
}




int func_021B9944(void *p, int i)
{
    int func_021BA018(char *, int);
    return func_021BA018((char *)p + 0x7c, i);
}





int func_021B9950(void *p)
{
    int func_021BA020(int *p);
    return func_021BA020((int *)((char *)p + 0x7c));
}





int func_021B995C(int *p, int i)
{
    int func_021B9BFC(int *, int);
    return func_021B9BFC(p, i);
}





void func_021B9964(char *p)
{
    void func_021B9D58(char *);
    func_021B9D58(p);
}


void func_021B996C(void *task, char *p)
{
    func_021B9D60(p);
    func_021BA010(p + 0x7c);
}








/*
 * note 2026-10-05 (recoup R14): func_02049658 returns u32 (as in ov210 021BC5DC); declared void it
 *   made the build copy the zero from r5 (adds rN,r5,#0) for the register zero arguments after
 *   02049BDC. EXACT in c99 and c with the u32 return.
 */
void func_021B9980(u8 *p, u16 heap)
{
    void *h;
    void *buf;
    PlttData *pd;
    int i;
    u32 id;

    func_02082BCC(p, 0, 0x7c);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021BB540);
    for (i = 0; i < 6; i++) {
        id = d_021BB614[i].id;
        func_0203FCA0((u8)id, (const struct BgTemplate *)(&d_021BB614[i].w[0]), (u8)d_021BB614[i].f24);
        func_020414AC(id);
        func_02040588(id, 1);
    }
    func_02040588(3, 0);
    func_02040C14(4, 0, 1, 0);
    func_02040C14(3, 0, 1, 0);
    h = func_020490F4(0x1b, heap);
    func_02049B68(h, 1, 0, 0, 0, heap);
    func_02049658(h, 0xd, 0, 0, 0, 0, heap);
    func_020498F4(h, 0xe, 0, 0, 0, 0, heap);
    func_02049658(h, 0, 2, 0, 0, 0, heap);
    func_020498F4(h, 2, 2, 0, 0, 0, heap);
    func_02049658(h, 0x10, 3, 1, 0, 0, heap);
    func_02049BDC(h, 8, 0, 0x80, 0x1e0, 0x20, heap);
    *(void **)(p + 0x54) = func_02049DF4(h, 0xf, 0, (u32)(p + 0x58), heap);
    func_02049B68(h, 8, 4, 0, 0, heap);
    func_02049658(h, 7, 5, 0, 0, 0, heap);
    func_020498F4(h, 9, 5, 0, 0, 0, heap);
    func_02049658(h, 0x10, 4, 1, 0, 0, heap);
    func_02049238(h);
    buf = func_02049F34(0x1b, 1, (u32)(&pd), heap);
    func_02082D44(pd->data + 0xe0, p + 0x5c, 0x20);
    func_020307B0(buf);
    *(u32 *)(p + 0x44) = func_020450F0(4, 1, 0x13, 0x1e, 4, 4, 1);
    *(u32 *)(p + 0x48) = func_020450F0(3, 1, 1, 0x1e, 4, 0xf, 1);
    *(u32 *)(p + 0x40) = func_020450F0(0, 0, 0, 0x10, 3, 8, 1);
    func_021B9C04((u32 *)p);
    func_02040588(4, 0);
}











void func_021B9B6C(u32 *p)
{
    int i;

    for (i = 0; i < 19; i++) {
        if (p[i] != 0) {
            func_020452E8((struct Descriptor *)p[i]);
        }
    }
    func_020307B0((void *)p[21]);
    func_02040DA8(4, 1, 0);
    i = 0;
    func_02040DA8(3, 1, 0);
    for (i = 0; i < 6; i++) {
        func_020403F4((u8)d_021BB614[i].id);
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 0x7c);
}











void func_021B9BD0(u8 *p)
{
    func_021B9D68((u16 *)(p + 0x50), (u16 *)(p + 0x4c), 0x400, 7, 1,
                 ((struct Obj13138 *)p)->f72, ((struct Obj13138 *)p)->f74);
}











int func_021B9BFC(int *p, int i)
{
    return p[i];
}












/*
 * The rounded width goes through a u8 local that is both stored to the
 * table row and passed on (the call reloading the field is 4 bytes longer).
 * func_0201D304 takes the string first and the font second.
 */
void func_021B9C04(u32 *p)
{
    u32 font;
    u32 msg;
    u32 str;
    u32 w;
    int i;
    int x;
    Ent_021B9C04 *e;
    u8 wv;

    font = (u32)func_0201D7EC(0x17, 0, 0, 0, 0x1c);
    msg = (u32)func_02045B38(0, 2, 0x1d, 0x1c);
    for (i = 0; i < 16; i++) {
        x = 0;
        switch (i) {
        case 0:
            x = 7;
            break;
        case 1:
            x = 4;
            break;
        case 2:
            x = 2;
            break;
        }
        e = &d_021BB820[i];
        str = (u32)func_02045EC0((struct MsgBank *)msg, d_021BB820[i].msg);
        wv = (x + func_0201D304((struct StrObj *)str, font, 0) + 7) >> 3;
        e->w = wv;
        p[i] = func_020450F0(1, e->x, e->y, wv, e->h, 0, 1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p[i])), 0);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)p[i])), x, 0, (void *)str, (void *)font);
        w = p[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_02045808((struct U16Vec *)str);
    }
    w = *(u32 *)(p[22] + 0x14);
    func_02082A90(w, (u32)func_020437D4((const struct Bmp *)((u32)func_02045770((struct Descriptor *)p[16]))), 0x600);
    str = (u32)func_02045EC0((struct MsgBank *)msg, 0);
    x = func_02045738((struct Descriptor *)p[16]) * 4;
    x -= func_0201D304((struct StrObj *)str, font, 0) >> 1;
    func_0201C7D0((void *)((u32)func_02045770((struct Descriptor *)p[16])), x, 4, (void *)str, (void *)font, 0x3dc1);
    w = p[16];
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_02041B6C(func_02045730((struct Descriptor *)w));
    func_02045808((struct U16Vec *)str);
    func_02045C04((struct Rec *)msg);
    func_0201D83C((void *)font);
}












void func_021B9D58(char *p)
{
    ((struct Obj20637 *)p)->f4C = 0;
}











void func_021B9D60(char *a0)
{
    void func_020419E4(void);
    func_020419E4();
}












/*
 * BGR555 cross-fade of one palette entry: advance the u16 phase at *ang by
 * inc (wrapping at 0x10000), take f = (table[phase >> 4 pair, second entry]
 * + 0x1000) / 2 as an s16 from the table at 0x020A1B38, blend each channel
 * of c0 toward c1 by f >> 12, store to *out and hand it to func_02061CA4.
 * Twin: arm9 func_0202EA40 (blink_palanm.c).  What closed it: all six
 * channels as u8 locals extracted in mask-then-shift form, the blended
 * channels as s32 with a u8 cast, and the pack `(b << 10) | (r | (g << 5))`
 * (the channel ORed last is evaluated first: blue, red, green).  Shift-then-
 * mask extraction, or the unnested pack, compiles 184 bytes.
 */
void func_021B9D68(u16 *out, u16 *ang, int inc, u32 idx, u8 slot, u16 c0, u16 c1)
{
    int t;
    s16 f;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, b;

    t = *ang + inc;
    if (t >= 0x10000) {
        *ang = t - 0x10000;
    } else {
        *ang = t;
    }
    f = (d_020A1B38[((*ang >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = c0 & 0x1f;
    g0 = (c0 & 0x3e0) >> 5;
    b0 = (c0 & 0x7c00) >> 10;
    r1 = c1 & 0x1f;
    g1 = (c1 & 0x3e0) >> 5;
    b1 = (c1 & 0x7c00) >> 10;
    b = (u8)(b0 + (((b1 - b0) * f) >> 12));
    r = (u8)(r0 + (((r1 - r0) * f) >> 12));
    g = (u8)(g0 + (((g1 - g0) * f) >> 12));
    *out = (u16)((b << 10) | (r | (g << 5)));
    func_02061CA4((void *)15, idx * 32 + slot * 2, (u32)out, 2);
}












void func_021B9E28(int *p, void *res, u32 heap)
{
    Local s;
    void *h;
    int i;

    func_02082BCC(p, 0, 0x54);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)res, heap);
    p[0] = (int)func_0204B100(0x80, 0, heap);
    func_0204B270((struct Bank *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    h = func_020490F4(0x1b, heap);
    p[1] = func_0204ABF0(h, 6, 0, 0, heap);
    p[2] = func_0204A6C8(h, 5, 0, 0, heap);
    p[3] = func_0204AF28(h, 4, 3, heap);
    p[4] = func_0204A6C8(h, 0xc, 0, 0, heap);
    p[5] = func_0204AF28(h, 0xb, 0xa, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    s.e = 2;
    s.d = 2;
    for (i = 2; i < 13; i++) {
        s.a = d_021BB704[i - 2].f8;
        s.b = d_021BB704[i - 2].fC;
        p[6 + i] = func_0204B294(p[0], p[2], p[1], p[3], &s, 0, heap);
        func_0204B92C((struct Obj *)p[6 + i], 0);
    }
    func_02082BCC(&s, 0, 8);
    s.a = 0x80;
    s.b = 0x60;
    s.e = 2;
    s.d = 1;
    p[7] = func_0204B294(p[0], p[4], p[1], p[5], &s, 0, heap);
    func_0204B6F4((struct Obj *)p[7], 6, 1);
    if (func_0203CD98())
        func_0203D34C(1, heap);
}












void func_021B9F70(u32 *p)
{
    int i;

    for (i = 0; i < 14; i++) {
        if (p[i + 6] != 0) {
            func_0204B3B4((struct Obj *)p[i + 6]);
        }
    }
    func_0204ADA4(p[1]);
    func_0204A8D4(p[2]);
    func_0204AFD8(p[3]);
    func_0204A8D4(p[4]);
    func_0204AFD8(p[5]);
    func_0204B1CC((struct Bank *)p[0]);
    func_0204A5AC();
    func_02082BCC(p, 0, 0x54);
}












void func_021B9FC0(u8 *p)
{
    int i;
    u16 t;

    t = (((struct Obj09869 *)p)->f50)++;
    if (t > 0x60) {
        ((struct Obj09869 *)p)->f50 = 0;
    }
    for (i = 2; i < 13; i++) {
        func_0204B908(*(u32 *)(p + i * 4 + 0x18), (u16)(((struct Obj09869 *)p)->f50 / 12));
    }
    func_0204A600();
}











void func_021BA010(char *a0) { func_0204A648(); }










int func_021BA018(char *p, int i)
{
    return *(int *)(p + (i << 2) + 0x18);
}










int func_021BA020(int *p)
{
    return *p;
}










/*
 * Two identical wrappers around func_02082BCC(p, 0, 0x20).
 */
void func_021BA024(void *p, int heap)
{
    void func_02082BCC(void *, u32, u32);
    func_02082BCC(p, 0, 0x20);
}











void func_021BA030(void *p)
{
    void func_02082BCC(void *, u32, u32);
    func_02082BCC(p, 0, 0x20);
}











/*
 * Touch and key input to a command code in p[0].
 */
void func_021BA03C(int *p)
{
    int x;
    int y;
    u32 trg;
    u32 cont;
    int d;

    p[0] = 0;
    if (func_02035D20((u32 *)(&x), (u32 *)(&y))) {
        p[0] = 3;
        p[1] = x;
        p[2] = y;
        p[5] = x;
        p[6] = y;
        p[7] = 1;
    } else if (func_02035CB8((u32 *)(&x), (u32 *)(&y)) && p[7] != 0) {
        d = y - p[2];
        if (d < 0)
            d = -d;
        if (d >= 1) {
            p[0] = 1;
            p[3] = x - p[5];
            p[4] = y - p[6];
            p[5] = x;
            p[6] = y;
        }
    } else {
        p[7] = 0;
    }
    trg = func_020362DC();
    cont = func_0203630C();
    if (trg != 0 && func_020355C4() == 1 && (trg & 0xc02) == 0) {
        func_020355D8(0);
        p[0] = 0xe;
        func_020061E4(0x548);
        return;
    }
    if (trg & 0x40) {
        p[0] = 4;
        return;
    }
    if (trg & 0x80) {
        p[0] = 5;
        return;
    }
    if (trg & 0x20) {
        p[0] = 7;
        return;
    }
    if (trg & 0x10) {
        p[0] = 6;
        return;
    }
    if (cont & 0x40) {
        p[0] = 0xa;
        return;
    }
    if (cont & 0x80) {
        p[0] = 0xb;
        return;
    }
    if (trg & 1) {
        p[0] = 8;
        return;
    }
    if (trg & 2) {
        func_020355D8(0);
        p[0] = 9;
        return;
    }
    if (trg & 0x800) {
        func_020355D8(0);
        p[0] = 0xc;
        return;
    }
    if (trg & 0x400) {
        func_020355D8(0);
        p[0] = 0xd;
    }
}










int func_021BA190(const int *p) { return *p; }












void func_021BA194(const u8 *p, int which, int *out)
{
    if (out == 0)
        return;
    switch (which) {
    case 0:
        out[0] = *(const int *)&((struct Obj05150 *)p)->f4;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f8;
        break;
    case 1:
        out[0] = *(const int *)&((struct Obj05150 *)p)->fC;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f10;
        break;
    case 2:
        out[0] = *(const int *)&((struct Obj05150 *)p)->f14;
        out[1] = *(const int *)&((struct Obj05150 *)p)->f18;
        break;
    }
}












void func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2)
{
    u32 w;

    func_02082BCC(p, 0, 0x38);
    ((struct Obj01227 *)p)->f18 = 4;
    ((struct Obj01227 *)p)->f10 = a1;
    ((struct Obj01227 *)p)->f1A = s2;
    ((struct Obj01227 *)p)->f4 = a2;
    ((struct Obj01227 *)p)->f0 = a3;
    ((struct Obj01227 *)p)->f14 = (u32)func_020457B0(0xff, s2);
    ((struct Obj01227 *)p)->fC = s0;
    ((struct Obj01227 *)p)->f8 = 0;
    ((struct Obj01227 *)p)->f24 = s1;
    ((struct Obj01227 *)p)->f28 = 0;
    func_02028470(p + 0x2c, 0x406);
    func_0201F73C((void *)(((struct Obj01227 *)p)->f10), 2, 1, func_02045778((struct Descriptor *)a1));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01227 *)p)->f10)), (u8)((struct Obj01227 *)p)->f18);
    w = ((struct Obj01227 *)p)->f10;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    ((struct Obj01227 *)p)->f1C = ((struct Obj01227 *)p)->f10;
    p[0x20] = 0;
}












void func_021BA254(u8 *p)
{
    if (((struct Obj07683 *)p)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj07683 *)p)->f8));
        ((struct Obj07683 *)p)->f8 = 0;
    }
    func_02045808((struct U16Vec *)(((struct Obj07683 *)p)->f14));
    func_02082BCC(p, 0, 0x38);
}











void func_021BA278(u8 *p, u32 a, u32 b, u32 c)
{
    func_021BA28C(p, ((struct Obj00884 *)p)->f0, a, b, c);
}












void func_021BA28C(u8 *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 t;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00884 *)p)->f10)), (u8)((struct Obj00884 *)p)->f18);
    func_02045CAC((struct MsgBank *)a1, a2, (void *)(((struct Obj00884 *)p)->f14));
    if (((struct Obj00884 *)p)->f8 != 0) {
        func_0201CE48((struct Rec3 *)(((struct Obj00884 *)p)->f8));
        ((struct Obj00884 *)p)->f8 = 0;
    }
    if (a4 == 0) {
        t = ((struct Obj00884 *)p)->f24;
        func_0201C6FC((struct PrintSys *)t, (u32)func_02045770((struct Descriptor *)((struct Obj00884 *)p)->f1C), 0, 0,
                      (void *)(((struct Obj00884 *)p)->f14), ((struct Obj00884 *)p)->f4);
        p[0x20] = 1;
        ((struct Obj00884 *)p)->f28 = 2;
        return;
    }
    ((struct Obj00884 *)p)->f8 = func_0201CCE4(((struct Obj00884 *)p)->f10, 0, 0, ((struct Obj00884 *)p)->f14,
                                    ((struct Obj00884 *)p)->f4, a3, ((struct Obj00884 *)p)->fC, 0,
                                    ((struct Obj00884 *)p)->f1A, ((struct Obj00884 *)p)->f18);
    ((struct Obj00884 *)p)->f28 = 1;
}












int func_021BA31C(u8 *p)
{
    u32 t;

    switch (((struct Obj03658 *)p)->f28) {
    case 0:
    default:
        return 1;
    case 2:
        t = ((struct Obj03658 *)p)->f24;
        if (p[0x20] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj03658 *)p)->f1C))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj03658 *)p)->f1C);
                p[0x20] = 0;
            }
        }
        if (p[0x20] == 0) {
            return 1;
        }
        return 0;
    case 1:
        return func_02028484((struct Blk_021B9980 *)(p + 0x2c), (void *)(((struct Obj03658 *)p)->f8));
    }
}












void func_021BA37C(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u16 s3)
{
    Tbl t;
    Req r;

    func_02082BCC(p, 0, 0x44);
    ((struct Obj02762 *)p)->fC = 3;
    ((struct Obj02762 *)p)->f0 = a2;
    ((struct Obj02762 *)p)->f14 = s1;
    ((struct Obj02762 *)p)->f18 = s0;
    ((struct Obj02762 *)p)->f4 = a3;
    ((struct Obj02762 *)p)->f3C = s2;
    t = d_021BB5D4;
    func_02082BCC(&r, 0, 0x20);
    r.w[0] = (u32)&t;
    r.w[1] = 2;
    r.w[2] = a1;
    r.w[5] = 8;
    r.w[7] = 1;
    r.w[6] = 2;
    ((struct Obj02762 *)p)->f8 = func_021B62E0(&r, s3);
    func_021BA6B8(p, s3);
    if (func_02012BF8(((struct Obj02762 *)p)->f3C, 0x18) != 0) {
        func_021B6598((unsigned char *)(((struct Obj02762 *)p)->f8), 6, 1);
    } else {
        func_021B6598((unsigned char *)(((struct Obj02762 *)p)->f8), 6, 0);
    }
}










void func_021BA410(u8 *p)
{
    int i;

    func_021B639C(((struct Obj20641 *)p)->f8);
    for (i = 0; i < 2; i++) {
        func_02045808((struct U16Vec *)(*(u32 *)(p + i * 0xc + 0x1c)));
        func_02028148((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
    }
    func_02082BCC(p, 0, 0x44);
}







void func_021BA448(W *p, void *obj, void *arg)
{
    int cmd;
    int flag;
    int v;
    int r;
    int pt[2];

    flag = 0;
    p->f40 = 0;
    if (p->f10 != 0)
        cmd = 0;
    else
        cmd = func_021BA190(obj);
    v = func_021BA9DC(arg);
    switch (cmd) {
    case 0:
    case 1:
    case 2:
    case 12:
    case 13:
        break;
    case 14:
        return;
    case 3:
        func_021BA194(obj, 0, pt);
        if (func_021BB508(d_021BB550, pt) && p->fC != 0) {
            func_02040588(4, 0);
            func_020061E4(0x54c);
            p->fC = 0;
            p->f10 = 1;
            p->f40 = 1;
            if (func_020355C4() == 0)
                func_020355D8(1);
        } else if (func_021BB508(d_021BB560, pt) && p->fC != 1) {
            func_02040588(4, 0);
            func_020061E4(0x551);
            p->fC = 1;
            p->f10 = 1;
            p->f40 = 1;
            if (func_020355C4() == 0)
                func_020355D8(1);
        } else if (p->fC != 3) {
            p->fC = 3;
        }
        flag = 1;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
        switch (v) {
        case 5:
            p->fC = 0;
            break;
        case 6:
            p->fC = 1;
            break;
        default:
            p->fC = 3;
            break;
        }
        flag = 1;
        break;
    case 8:
        if (p->fC != 3) {
            func_020061E4_2(p->fC == 1 ? 0x551 : 0x54c);
        } else {
            p->fC = 0;
            func_020061E4(0x54c);
        }
        flag = 1;
        p->f10 = 1;
        break;
    case 9:
        func_020061E4(0x551);
        flag = 1;
        p->fC = 1;
        p->f10 = 1;
        break;
    }
    if (flag) {
        if (p->fC == 3) {
            func_02028218((struct Obj *)p->f34[0], 0);
            func_02028218((struct Obj *)p->f34[1], 0);
        } else if (p->f10 != 0) {
            func_02028218((struct Obj *)p->f34[p->fC], 0);
            func_0202822C((char *)p->f34[p->fC], 1);
            func_02028218((struct Obj *)p->f34[p->fC ^ 1], 0);
        } else {
            func_02028218((struct Obj *)p->f34[p->fC], 1);
            func_02028218((struct Obj *)p->f34[p->fC ^ 1], 0);
        }
    }
    if (p->f10 == 0) {
        func_021B63D0((struct S *)p->f8);
        r = func_021B6470((u8 *)p->f8);
        if (r != 0) {
            if (r == 6 && func_020355C4() == 1)
                p->f40 = 1;
        } else {
            if (func_020355C4() == 1)
                p->f40 = 1;
        }
        r = func_021B6448((u8 *)p->f8);
        if (r != 0) {
            if (r == 6) {
                if (func_021B65A8((unsigned char *)p->f8, 6))
                    func_02012BE0((void *)p->f3C, 0x18, 1);
                else
                    func_02012BE0((void *)p->f3C, 0x18, 0);
                p->fC = 3;
            }
        } else {
            p->fC = 2;
            p->f10 = 1;
        }
    }
}









void func_021BA644(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_02028178((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
    }
}










int func_021BA65C(u8 *p, int *out)
{
    if (out != 0)
        *out = ((struct Obj13139 *)p)->fC;
    return ((struct Obj13139 *)p)->f10;
}










u32 func_021BA668(u8 *p)
{
    u32 r = 0;

    if (((struct Obj13140 *)p)->f10 != 0) {
        u32 t = ((struct Obj13140 *)p)->fC;

        if (t != 3) {
            r = func_02028230((u8 *)(*(u32 *)(p + t * 4 + 0x34)));
            if (r != 0) {
                func_021BA694(p);
            }
        }
    }
    return r;
}










void func_021BA694(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_020282A4((struct Obj *)(*(u32 *)(p + i * 4 + 0x34)));
        func_02028218((struct Obj *)(*(u32 *)(p + i * 4 + 0x34)), 0);
    }
}










/*
 * The stores through a 12-byte element struct (P/Ent_021B9980) versus the byte-offset
 * reads keep two separate i*12 multiplies, as in the original.
 */
/*
 * The stores through a 12-byte element struct (P/Ent) versus the byte-offset
 * reads keep two separate i*12 multiplies, as in the original.
 */
void func_021BA6B8(u8 *p, u32 arg)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 12 + 0x1c) != 0) {
            func_02045808((struct U16Vec *)(*(u32 *)(p + i * 12 + 0x1c)));
        }
        ((P *)p)->e[i].h = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06169 *)p)->f18), i + 8);
        ((P *)p)->e[i].x = 0x39e3;
        ((P *)p)->e[i].idx = i;
        if (*(u32 *)(p + i * 4 + 0x34) != 0) {
            func_02028148((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
        }
        *(u32 *)(p + i * 4 + 0x34) =
            func_02027FEC(((struct Obj06169 *)p)->f14, p + 0x1c + i * 12, i * 9 + 14, 0x15, 9, arg);
    }
}










/*
 * Unlabelled leaf before func_021BA734; func_021BB1C4 tests its result.
 */
int func_021BA730(u8 *p)
{
    return ((struct Obj20643 *)p)->f40;
}








/*
 * a1/a2 are u16 parameters (stored with strh); as u32 the strh of a1 is
 * scheduled after the struct-copy source load.
 */
void func_021BA734(u8 *p, u16 a1, u16 a2, u32 a3, Blk_021B9980 *src, u32 heap)
{
    int i;

    func_02082BCC(p, 0, 0x58);
    ((struct Obj00103 *)p)->f0 = a1;
    ((struct Obj00103 *)p)->f2 = a2;
    ((struct Obj00103 *)p)->f34 = 0x10;
    *(Blk_021B9980 *)(p + 0x44) = *src;
    for (i = 0; i < 11; i++) {
        *(u32 *)(p + i * 4 + 8) = func_021B9944((void *)a3, i + 2);
    }
    func_021BABE0(p, -8, -192, 192);
    if (func_020355C4() == 1) {
        ((struct Obj00103 *)p)->f4 = -1;
        func_021BAA0C(p, 0);
        *(u32 *)&((struct Obj00103 *)p)->f50 = 0;
    } else {
        *(u32 *)&((struct Obj00103 *)p)->f4 = 0;
        func_021BAA0C(p, 1);
        *(u32 *)&((struct Obj00103 *)p)->f50 = 1;
    }
}








void func_021BA7B4(void *p)
{
    void func_02082BCC(void *, u32, u32);
    func_02082BCC(p, 0, 0x58);
}










/*
 * The 0/1/2 test on func_021BB0D8's result is a switch with three empty
 * labels: `r == 0 || r == 1 || r == 2` folds to one unsigned `cmp #2`.
 */
void func_021BA7C0(u8 *p, void *a1, void *a2, void *a3, void *a4)
{
    int pos[2];
    int r;
    int s;
    u32 t;

    r = func_021BA190(a1);
    func_02040804(((struct Obj00103 *)p)->f2);
    switch (r) {
    case 14:
        ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        func_021BAA0C(p, 1);
        ((struct Obj00103 *)p)->f50 = 1;
        break;
    case 10:
        if ((((struct Obj00103 *)p)->f38)++ < 10)
            break;
    case 4:
        ((struct Obj00103 *)p)->f38 = 0;
        ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 == 0 ? 6 : ((struct Obj00103 *)p)->f4 - 1;
        ((struct Obj00103 *)p)->f50 = 1;
        func_020061E4(0x548);
        func_021BAA0C(p, 1);
        func_021B9964(a3);
        break;
    case 11:
        if ((((struct Obj00103 *)p)->f38)++ < 10)
            break;
    case 5:
        ((struct Obj00103 *)p)->f38 = 0;
        if (((struct Obj00103 *)p)->f4 == 6)
            ((struct Obj00103 *)p)->f4 = 0;
        else
            (((struct Obj00103 *)p)->f4)++;
        ((struct Obj00103 *)p)->f50 = 1;
        func_020061E4(0x548);
        func_021BAA0C(p, 1);
        func_021B9964(a3);
        break;
    case 3:
        func_021BA194(a1, 0, pos);
        if (pos[1] < 0x18 || pos[1] > 0xA8)
            break;
        ((struct Obj00103 *)p)->f4 = func_021BAD38(p, pos);
        func_021BAC70(p, pos);
        func_021BAA0C(p, 0);
        func_021B9964(a3);
        ((struct Obj00103 *)p)->f50 = 1;
        if (func_020355C4() == 0)
            func_020355D8(1);
        break;
    case 6:
        if (((struct Obj00103 *)p)->f4 < 5) {
            func_020061E4(0x548);
            func_021BAD14(p, 1);
            func_021BAA0C(p, 1);
            func_021B9964(a3);
        } else if (((struct Obj00103 *)p)->f4 == 5) {
            (((struct Obj00103 *)p)->f4)++;
            func_020061E4(0x548);
            ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        }
        break;
    case 7:
        if (((struct Obj00103 *)p)->f4 < 5) {
            func_020061E4(0x548);
            func_021BAD14(p, -1);
            func_021BAA0C(p, 1);
            func_021B9964(a3);
        } else if (((struct Obj00103 *)p)->f4 == 6) {
            (((struct Obj00103 *)p)->f4)--;
            func_020061E4(0x548);
            ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        }
        break;
    case 12:
        func_021BAA0C(p, 1);
        break;
    case 8:
    case 9:
        func_021BAA0C(p, 0);
        break;
    }
    switch (func_021BB0D8(p + 0x44)) {
    case 0:
    case 1:
    case 2:
        ((struct Obj00103 *)p)->f50 = 1;
        break;
    }
    if (((struct Obj00103 *)p)->f50) {
        if (((struct Obj00103 *)p)->f4 >= 0 && ((struct Obj00103 *)p)->f4 < 5) {
            if (((struct Obj00103 *)p)->f4 == 0) {
                s = 1;
                t = func_021BB0D0(p + 0x44);
            } else {
                s = 0;
                t = 0;
            }
            func_02040588(4, 1);
            func_021BA278(a2, d_021BB570[((struct Obj00103 *)p)->f4][0], t, s);
        } else {
            func_02040588(4, 0);
        }
        ((struct Obj00103 *)p)->f50 = 0;
    }
    func_021BA31C(a2);
    func_021BAD58(p);
}









void func_021BA9C0(u8 *p, char *q)
{
    func_021BAA0C(p, 0);
    func_02040588(4, 0);
    func_021B9964(q);
}










/*
 * Integer getter at offset 0x4.
 */
int func_021BA9DC(void *p)
{
    return ((struct Obj20644 *)p)->f4;
}









void func_021BA9E0(u8 *p, Blk_021B9980 *out)
{
    *out = *(Blk_021B9980 *)(p + 0x44);
}









/*
 * Unlabelled tail-call stub after func_021BA9E0: redraws through
 * func_021BAA0C with the stored +0x54 flag.  func_021BB1C4 passes a second
 * argument (0 or 1) in r1 that this body never reads.
 */
void func_021BA9F0(u8 *p, int unused)
{
    func_021BAA0C(p, ((struct Obj00103 *)p)->f54);
}









void func_021BA9FC(u8 *p, u8 v)
{
    p[0x48] = v;
    func_021BAA0C(p, ((struct Obj00103 *)p)->f54);
}









void func_021BAA0C(u8 *p, int flag)
{
    int base;
    u32 k;
    int i;

    if (((struct Obj00103 *)p)->f4 >= 5)
        flag = 0;
    ((struct Obj00103 *)p)->f54 = flag;
    base = ((int)func_02040804(((struct Obj00103 *)p)->f2) + 0x14) / 0x18;
    func_020413B0((u8)(((struct Obj00103 *)p)->f2), 0, 0, 0x20, 0x20, 5);
    i = 0;
    for (k = 0; k < 5; k++)
        func_020413B0((u8)(((struct Obj00103 *)p)->f2), i, (base + k) * 3 + 2, 0x20, 3, d_021BB538[k]);
    for (i = 0; i < 11; i++) {
        if (((struct Obj00103 *)p)->f4 == d_021BB704[i].offset && flag) {
            if (func_021BB0AC(p + 0x44, i))
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 7);
            else
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0xC);
        } else {
            if (func_021BB0AC(p + 0x44, i))
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0);
            else
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 3);
        }
    }
    for (i = 11; i < 16; i++) {
        if (i - 11 == ((struct Obj00103 *)p)->f4 && flag)
            func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 7);
        else
            func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0);
    }
    if (flag)
        func_020413B0((u8)(((struct Obj00103 *)p)->f2), 0, ((struct Obj00103 *)p)->f4 * 3 + 2, 0x20, 3, 7);
    func_02041B6C((u8)(((struct Obj00103 *)p)->f2));
    func_02041B6C((u8)(((struct Obj00103 *)p)->f0));
    for (i = 0; i < 11; i++) {
        if (((struct Obj00103 *)p)->f4 == d_021BB704[i].offset && flag) {
            if (func_021BB0AC(p + 0x44, i))
                func_0204B8A0(*(void **)(p + i * 4 + 8), 3);
            else
                func_0204B8A0(*(void **)(p + i * 4 + 8), 2);
        } else {
            if (func_021BB0AC(p + 0x44, i))
                func_0204B8A0(*(void **)(p + i * 4 + 8), 0);
            else
                func_0204B8A0(*(void **)(p + i * 4 + 8), 1);
        }
    }
}









/*
 * The clamp of the +0x34 field is a nested ternary (if/else-if reallocates
 * registers); the first call result goes through a local so the sum is
 * `adds r7, r0, r1`.
 */
void func_021BABE0(u8 *p, int a1, int a2, int a3)
{
    int i;
    int v;
    int t;
    Pt pt;

    t = func_02040804(((struct Obj04326 *)p)->f2);
    v = t + a1;
    if (v > a3) {
        v = a3;
    } else if (v < a2) {
        v = a2;
    }
    func_02041EE4((u8)((struct Obj04326 *)p)->f0, 3, v + 0x14);
    func_02041EE4((u8)((struct Obj04326 *)p)->f2, 3, v);
    t = ((struct Obj04326 *)p)->f34 - a1;
    ((struct Obj04326 *)p)->f34 = t;
    ((struct Obj04326 *)p)->f34 = t > 0x10 - a2 ? 0x10 - a2 : (t < 0x10 - a3 ? 0x10 - a3 : t);
    for (i = 0; i < 11; i++) {
        pt.x = d_021BB704[i].f8;
        pt.y = ((struct Obj04326 *)p)->f34 + d_021BB704[i].fC;
        func_0204B404((struct Obj *)(*(u32 *)(p + i * 4 + 8)), (const struct Vec2 *)(&pt), 0);
    }
}









void func_021BAC70(u8 *p, void *b)
{
    int i;
    int r[4];
    int x;
    int y;

    for (i = 0; i < 11; i++) {
        Ent_021BB704 *e = &d_021BB704[i];

        y = ((struct Obj13141 *)p)->f34 + e->f12;
        x = e->f10;
        r[1] = y;
        r[0] = x;
        r[3] = y + e->f16;
        r[2] = x + e->f14;
        if (y >= 0x18 && y <= 0xa8 && r[3] >= 0x18 && r[3] <= 0xa8) {
            if (func_021BB508(r, b)) {
                func_020061E4(0x548);
                func_021BAFD8(p + 0x44, i);
                func_021BACF4(p, ((struct Obj13141 *)p)->f47, 0);
                return;
            }
        }
    }
}









void func_021BACF4(u8 *p, u32 a, u32 b)
{
    if (((struct Obj20645 *)p)->f4 == 3 || b == 1) {
        if (a == 0) {
            func_02005C28(1);
        } else {
            func_02005C28(0);
        }
    }
}









void func_021BAD14(u8 *p, u32 v)
{
    if (((struct Obj09870 *)p)->f4 < 5) {
        func_021BB000(p + 0x44, ((struct Obj09870 *)p)->f4, v);
        func_021BACF4(p, *(s8 *)(p + 0x44 + ((struct Obj09870 *)p)->f4), 0);
    }
}








/*
 * Lever: name the call result before addition (commutative operand idiom).
 * Arithmetic: unsigned word addition/subtraction wraps before signed division.
 */
int func_021BAD38(u8 *p, int *q)
{
    int n;
    n = func_02040804(((struct Obj13142 *)p)->f2);
    n = (int)((u32)n + ((struct Obj20646 *)q)->f4 - 16u) / 24;
    if ((u32)n >= 5) n = ((struct Obj13142 *)p)->f4;
    return n;
}









void func_021BAD58(void *p)
{
    ((struct Obj20647 *)p)->f3C <<= 1;
}









void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3)
{
    int i;

    func_02082BCC(p, 0, 0x70);
    ((struct Obj02763 *)p)->f54 = 0;
    ((struct Obj02763 *)p)->f6C = s1;
    func_021BA1C4(p, a, b, (u32)c, s0, s2, s3);
    for (i = 0; i < 2; i++) {
        u8 *e = p + i * 12;

        ((struct Obj09871 *)e)->f3C = func_02045EC0(c, i + 0x22);
        ((struct Obj09871 *)e)->f40 = 0x39E3;
        ((struct Obj09871 *)e)->f44 = 0;
    }
    ((struct Obj02763 *)p)->f58 = s3;
    ((struct Obj02763 *)p)->f5C = 2;
    *(u8 * *)&((struct Obj02763 *)p)->f60 = p + 0x3c;
    ((struct Obj02763 *)p)->f64 = 1;
    ((struct Obj02763 *)p)->f68 = 0x20;
    ((struct Obj02763 *)p)->f69 = 0xc;
    ((struct Obj02763 *)p)->f6A = 0xd;
    ((struct Obj02763 *)p)->f6B = 3;
}








void func_021BADFC(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) func_02045808((struct U16Vec *)(*(u32 *)(p + i * 12 + 60)));
    func_021BA254(p);
    func_02082BCC(p, 0, 112);
}









void func_021BAE28(u8 *p)
{
    switch (((struct Obj02417 *)p)->f56) {
    case 0:
        if (func_021BA31C(p) != 0) {
            ((struct Obj02417 *)p)->f56 = 1;
        }
        break;
    case 1:
        ((struct Obj02417 *)p)->f38 = func_02027778((struct TaskMenuTmpl *)(p + 0x58), ((struct Obj02417 *)p)->f6C);
        ((struct Obj02417 *)p)->f56 = 2;
        break;
    case 2:
        func_02027974(((struct Obj02417 *)p)->f38);
        if (func_020279E8(((struct Obj02417 *)p)->f38) != 0) {
            ((struct Obj02417 *)p)->f54 = func_02027A04(*(u8 * *)&((struct Obj02417 *)p)->f38) + 1;
            ((struct Obj02417 *)p)->f56 = 3;
            func_02027858(((struct Obj02417 *)p)->f38);
        }
        break;
    }
}








void func_021BAE90(void *p, u32 value)
{
    func_0207D658(0x04000050, 23, 8);
    func_02040588(3, 1);
    func_021BA278(p, 33, value, 0);
}









/*
 * Unlabelled leaf (halfword getter) found while matching func_021BB418.
 */
u16 func_021BAEBC(u8 *p)
{
    return ((struct Obj20648 *)p)->f54;
}









void func_021BAEC4(void *a, u32 b, u32 c)
{
    void *h;

    func_0207D658((u32)((void *)0x04000050), 0x17, 8);
    func_02040588(3, 1);
    h = func_02045B38(0, 3, 0x9e, 0x801C);
    func_021BA28C(a, (u32)h, b, c, 1);
    func_02045C04(h);
}








/*
 * Interface: full-width r1 is forwarded through 021BA278 to 021BA28C;
 * the legacy u16 extern has no caller truncation witness here.
 */
void func_021BAF0C(void *p, u32 id, u32 value)
{
    func_0207D658(0x04000050, 23, 8);
    func_02040588(3, 1);
    func_021BA278(p, id, value, 1);
}






int func_021BAF38(u8 *p)
{
    if (func_021BA31C(p)) {
        *(volatile unsigned short *)0x04000050 = 0;
        func_02040588(3, 0);
        return 1;
    }
    return 0;
}






/*
 * Byte-correct; blocked by two unwitnessed arm9 leaves (the integrator's):
 *   func_020083AC (bitfield read, verified EXACT: typedef struct { unsigned short a:7; unsigned short b:1; } S;
 *                  unsigned func_020083AC(S *p){ return p->b; })
 *   func_020083C8 (same with a:6, b:1; disasm ldrh; lsls #0x19; lsrs #0x1f)
 *
 * 2026-10-05: body byte-correct. Leaves 020083AC and 020083C8 are now filed
 * EXACT in src/matched/arm9/. Needs shard seeding by the integrator.
 */
void func_021BAF5C(u8 *p, short unsigned int *a)
{
    func_02082BCC(p, 0, 12);
    p[5] = 11;
    *(u32 *)(p + 8) = (u32)a;
    p[0] = func_02008374((int)a);
    p[1] = func_020083AC((u32)a);
    p[2] = func_020083C8((u32)a);
    p[3] = func_02008390((char *)a);
    p[4] = func_02008428(a);
}





void func_021BAF9C(void *p)
{
    void func_02082BCC(void *, u32, u32);
    func_02082BCC(p, 0, 0xc);
}






void func_021BAFA8(u8 *p)
{
    func_0200837C(*(u16 **)(p + 8), p[0]);
    func_020083B4(*(u16 **)(p + 8), p[1]);
    func_020083D0(*(u16 **)(p + 8), p[2]);
    func_02008398(*(u16 **)(p + 8), p[3]);
    func_02008430(*(u16 **)(p + 8), p[4]);
}






void func_021BAFD8(u8 *p, int i)
{
    if (p[d_021BB704[i].offset] != d_021BB704[i].value) {
        p[d_021BB704[i].offset] = d_021BB704[i].value;
        p[5] = i;
        func_021BAFA8(p);
    }
}







/*
 * The three 0x021BB57x pool words and the two 0x021BB70x words are separate
 * pool entries in the original, so each is its own extern.
 */
void func_021BB000(u8 *p, int i, int delta)
{
    int j;
    int k;
    int n;
    Tab *t;
    int off = i << 3;
    s8 idx;
    int t2;
    int v = -1;

    n = *(u16 *)((u8 *)d_021BB572 + off);
    j = 0;
    if (n > 0) {
        do {
            u8 cur;
            u32 f;

            t = (Tab *)((u8 *)d_021BB570 + off);
            cur = p[i];

            v = t->list[j];
            f = d_021BB704[v].value;
            if (f == cur) {
                break;
            }
            j++;
        } while (j < t->cnt);
    }
    t2 = (s8)(v - d_021BB574[(u32)i << 3]);
    t2 = (s8)(t2 + delta);
    idx = (s8)(t2 > n - 1 ? n - 1 : (t2 < 0 ? 0 : t2));
    k = (d_021BB574 + off)[idx];
    if (p[i] != d_021BB708[k].f0) {
        p[i] = d_021BB708[k].f0;
        p[5] = k;
        func_021BAFA8(p);
    }
}






int func_021BB0AC(u8 *p, int i)
{
    if (p[d_021BB704[i].offset] == d_021BB704[i].value) return 1;
    return 0;
}







/*
 * ARM9 tail call then a byte read-modify-write.
 */
u32 func_021BB0D0(void *b)
{
    signed char func_02012FFC(void);
    func_02012FFC();
}







int func_021BB0D8(void *p)
{
    unsigned char old = ((struct Obj13144 *)p)->f5;
    ((struct Obj13144 *)p)->f5 = 0xb;
    return old;
}





int func_021BB0E4(const u8 *p, const u8 *q)
{
    if (func_0203EFC8(p, q, 5) == 0) return 1;
    return 0;
}





void func_021BB0F8(u8 *p, int value, int callback)
{
    func_02082BCC(p, 0, 16);
    ((struct Obj20650 *)p)->fC = value;
    func_021BB138(p, callback);
}






/*
 * Tail call to func_02082BCC(p, 0, 0x10).
 */
void func_021BB114(void *p)
{
    void func_02082BCC(void *, u32, u32);
    func_02082BCC(p, 0, 0x10);
}






void func_021BB120(u8 *p)
{
    if (((struct Obj13145 *)p)->f4 == 0)
        (*(Callback *)p)(p, p + 8, ((struct Obj13145 *)p)->fC);
}







int func_021BB134(void *p)
{
    return ((struct Obj20651 *)p)->f4;
}







/*
 * Getter and two small setters.
 */
void func_021BB138(void *p, int v)
{
    ((struct Obj13146 *)p)->f0 = v;
    ((struct Obj13146 *)p)->f8 = 0;
}







void func_021BB140(void *p)
{
    ((struct Obj20652 *)p)->f4 = 1;
}







void func_021BB148(void *unused, u32 *p)
{
    switch (*p) {
    case 0:
        func_0204E720(3, 16, 0, 0);
        *p = 1;
        break;
    case 1:
        if (func_0204E804() == 0) {
            *p = 2;
        }
        break;
    case 2:
        func_021BB138(unused, (int)func_021BB1C4);
        break;
    }
}






void func_021BB188(void *p,u32 *state) { switch(*state) { case 0: func_0204E720(3,0,16,0); *state=1; break; case 1: if(func_0204E804()==0) *state=2; break; case 2: func_021BB140(p); break; } }







void func_021BB1C4(void *a, u32 *st, u8 *w)
{
    Blk_021BB114 b50;
    Blk_021BB114 b44;
    Blk_021BB114 b38;
    Blk_021BB114 b2C;
    Blk_021BB114 b20;
    Blk_021BB114 b14;
    Blk_021BB114 b8;
    int k;
    int r;

    if (func_0201C6B4((const struct PrintSys *)(((struct Obj09875 *)w)->f258)) == 0)
        return;
    switch (*st) {
    case 0:
        func_021BA03C((int *)(w + 0xE4));
        if (func_021BA65C(w + 0x104, 0) == 0)
            func_021BA7C0(w + 0x148, w + 0xE4, w + 0x1A0, w, w + 0x104);
        func_021BA448((W *)(w + 0x104), w + 0xE4, w + 0x148);
        if (func_021BA730(w + 0x104))
            func_021BA9C0(w + 0x148, (char *)w);
        if (func_021BA65C(w + 0x104, &k)) {
            switch (k) {
            case 0:
                if (func_021BA668(w + 0x104))
                    func_021BB138(a, (int)func_021BB4D4);
                break;
            case 2:
                **(int * *)&((struct Obj09875 *)w)->f26C = 1;
                func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b50));
                if (func_021BB0E4(w + 0x248, (const u8 *)(&b50))) {
                    func_021BB138(a, (int)func_021BB4A4);
                } else {
                    func_021BA694(w + 0x104);
                    func_021BB138(a, (int)func_021BB418);
                }
                break;
            case 1:
                if (func_021BA668(w + 0x104)) {
                    func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b44));
                    if (func_021BB0E4(w + 0x248, (const u8 *)(&b44))) {
                        func_021BB138(a, (int)func_021BB4A4);
                    } else {
                        func_021BA694(w + 0x104);
                        func_021BB138(a, (int)func_021BB418);
                    }
                }
                break;
            }
        }
        r = func_020071F0(func_02012EBC(func_020120F4((const struct Ctx *)(((struct Obj20654 *)(*(u8 * *)&((struct Obj09875 *)w)->f26C))->f4))));
        func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b38));
        if (b38.b == 0 && r != 0)
            *st = 1;
        break;
    case 1:
        func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b2C));
        func_021BAF0C(w + 0x1D8, 0x20, func_021BB0D0(&b2C));
        func_021BA9FC(w + 0x148, 1);
        *st = 5;
        break;
    case 2:
        func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b20));
        func_021BAEC4(w + 0x1D8, 0x16, func_021BB0D0(&b20));
        func_021BA9F0(w + 0x148, 0);
        *st = 5;
        break;
    case 3:
        func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b14));
        func_021BAEC4(w + 0x1D8, 0x16, func_021BB0D0(&b14));
        func_021BA9F0(w + 0x148, 0);
        *st = 5;
        break;
    case 4:
        func_021BA9E0(w + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b8));
        func_021BAF0C(w + 0x1D8, 0x24, func_021BB0D0(&b8));
        func_021BA9F0(w + 0x148, 1);
        *st = 5;
        break;
    case 5:
        if (func_021BAF38(w + 0x1D8))
            *st = 0;
        break;
    }
}





void func_021BB418(void *a0, u32 *st, u8 *base)
{
    Blk_021BB418 b;
    u16 r;

    switch (*st) {
    case 0:
        func_021BA9E0(base + 0x148, (Blk_021B9980 *)((Blk_021BB114 *)&b));
        func_021BAE90(base + 0x1d8, func_021BB0D0(&b));
        func_02040588(4, 0);
        *st = 1;
        break;
    case 1:
        r = func_021BAEBC(base + 0x1d8);
        switch (r) {
        case 1:
            *st = 2;
            break;
        case 2:
            *st = 3;
            break;
        }
        break;
    case 2:
        func_021BB138(a0, (int)func_021BB4D4);
        break;
    case 3:
        func_021BB138(a0, (int)func_021BB4A4);
        break;
    }
    func_021BAE28(base + 0x1d8);
}




void func_021BB4A4(void *a,u32 b,u8 *p) { func_021BAFA8(p+0x248); func_021BACF4(p+0x148,((struct Obj20655 *)p)->f24B,1); func_021BB138(a,(int)func_021BB188); }




void func_021BB4D4(void *a,u32 b,u8 *p) { Blk_021BB114 t; func_021BA9E0(p+0x148, (Blk_021B9980 *)((Blk_021BB114 *)&t)); func_021BAFA8((u8 *)&t); func_020061E4(0x558); func_021BB138(a,(int)func_021BB188); }

typedef struct {
    u32 x0;
    u32 y0;
    u32 x1;
    u32 y1;
} Box_021BB508;

typedef struct {
    u32 x;
    u32 y;
} Pt_021BB508;

int func_021BB508(int *rect, void *pt)
{
    const Box_021BB508 *b = (const Box_021BB508 *)rect;
    const Pt_021BB508 *p = (const Pt_021BB508 *)pt;
    u32 inx = (p->x - b->x0) <= (b->x1 - b->x0);
    u32 iny = (p->y - b->y0) <= (b->y1 - b->y0);
    return inx & iny;
}

