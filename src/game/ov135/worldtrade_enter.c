/*
 * file:     worldtrade_enter.c
 * unit:     yes
 * function: func_021F88B0, func_021F88D8, func_021F8908, func_021F8950, func_021F8990, func_021F89A8, func_021F89B4, func_021F89F0, func_021F8A18, func_021F8A3C, func_021F8A40, func_021F8A44, func_021F8A74, func_021F8A80, func_021F8AB0, func_021F8AF4, func_021F8B0C, func_021F8BBC, func_021F8BE8, func_021F8D10, func_021F8DA4, func_021F8DE4, func_021F8E58, func_021F8E88, func_021F8F5C, func_021F8F68, func_021F8F84, func_021F9024, func_021F9088, func_021F90A0, func_021F90B8, func_021F914C, func_021F91A0, func_021F91DC, func_021F9218, func_021F9254, func_021F9260, func_021F9660, func_021F9890, func_021F9968, func_021F99D0, func_021F99F0, func_021F9A1C, func_021F9A88, func_021F9CB0, func_021F9CDC, func_021F9EEC, func_021F9F00, func_021F9F58, func_021F9FF0, func_021FA15C, func_021FA2B0, func_021FA330, func_021FA394, func_021FA4FC, func_021FA514, func_021FA760, func_021FA7C4, func_021FA85C, func_021FA9C8, func_021FAAD4, func_021FAB70, func_021FAC50, func_021FAC84, func_021FAC8C, func_021FAD08, func_021FAD24, func_021FAD84, func_021FADA8, func_021FADF0, func_021FAE2C, func_021FAE8C, func_021FAEE0, func_021FAFF0, func_021FB164, func_021FB1E4, func_021FB220, func_021FB240, func_021FB26C, func_021FB2F0, func_021FB364, func_021FB3D8, func_021FB510, func_021FB588, func_021FB5E4, func_021FB614, func_021FB674, func_021FB704, func_021FB7A0
 * address:  0x021F88B0
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
 *   d_022030E8 0x022030E8 data a2
 *   tbl_02202F0C  0x02202F0C  data
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   tbl_022030E8 0x022030E8 data a2
 *   func_021F50EC 0x021F50EC thumb ov135
 *   d_02203C1C 0x02203C1C data a4
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135
 *   func_02005D90  0x02005D90  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_02168064  0x02168064  arm
 *   func_02168124 0x02168124 arm ov009
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C7BA0 0x021C7BA0 arm ov114
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_021C7C1C  0x021C7C1C  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021B9B00 0x021B9B00 thumb ov114
 *   func_021C8E18 0x021C8E18 arm ov114
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031348 0x02031348 arm
 *   str_02203C34 0x02203C34 data a1
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 *   func_020307B0 0x020307B0 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   func_021D5B5C 0x021D5B5C thumb ov115
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021C8658 0x021C8658 arm ov114
 *   func_0216AD50 0x0216AD50 arm ov009
 *   func_0205CC20 0x0205CC20 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02202878 0x02202878 thumb ov135
 *   func_02202858 0x02202858 thumb ov135
 *   func_022026C4 0x022026C4 thumb ov135
 *   func_02045738 0x02045738 arm
 *   func_022028C8  0x022028C8  thumb  ov135
 *   tbl_022031EC   0x022031EC  data
 *   func_02040C14  0x02040C14  arm
 *   sub_020450F0   0x020450F0  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   data_02203200  0x02203200  data
 *   data_02203206  0x02203206  data
 *   data_0220322A  0x0220322A  data
 *   data_02203242  0x02203242  data
 *   data_022032AE  0x022032AE  data
 *   func_0202CF98  0x0202CF98  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_02202974  0x02202974  thumb
 *   func_022026D8  0x022026D8  thumb
 *   g_02203CD8     0x02203CD8  data  ov135
 *   func_02202744  0x02202744  thumb  ov135
 *   func_022029D4  0x022029D4  thumb  ov135
 *   tbl_02203C48  0x02203C48  data  a4
 *   func_02202770  0x02202770  thumb
 *   func_022029F8  0x022029F8  thumb
 *   func_02035C08  0x02035C08  arm
 *   tbl_02203370   0x02203370  data  a1
 *   tbl_022033C8   0x022033C8  data  a1
 *   tbl_022032DE   0x022032DE  data  a1
 *   tbl_02203270   0x02203270  data  a1
 *   tbl_022032FE   0x022032FE  data  a1
 *   tbl_02203284   0x02203284  data  a1
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   func_02034714  0x02034714  arm
 *   tbl_02203348   0x02203348  data  a1
 *   tbl_022032C6   0x022032C6  data  a1
 *   tbl_022033FC   0x022033FC  data  a4
 *   tbl_02203260   0x02203260  data  a1
 *   tbl_02203324   0x02203324  data  a4
 *   func_021FBF04  0x021FBF04  thumb
 *   tbl_02203220   0x02203220  data  a1
 *   tbl_0220320E  0x0220320E  data
 *   tbl_02203250  0x02203250  data  a4
 *   tbl_02203216   0x02203216  data  a1
 *   tbl_0220339C   0x0220339C  data  a1
 *   tbl_02203298   0x02203298  data  a1
 *   tbl_02203236   0x02203236  data  a1
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_021FBFB0 0x021FBFB0 thumb ov135
 *   func_021FC014 0x021FC014 thumb ov135
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_021F87E0 0x021F87E0 thumb ov135
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B898 0x0204B898 arm
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FBF6C  0x021FBF6C  thumb
 *   tbl_022033F8   0x022033F8  data
 *   tbl_02203440   0x02203440  data
 *   func_0200D064  0x0200D064  thumb
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   g_022033FC  0x022033FC  data  ov135
 *   func_0201F868 0x0201F868 thumb
 */
#include "../../matched/include/Obj02204.h"
#include "../../matched/include/Obj12203.h"
#include "../../matched/include/Obj12204.h"
#include "../../matched/include/Obj05413.h"
#include "../../matched/include/Obj08184.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj23396.h"
#include "../../matched/include/Obj23397.h"
#include "../../matched/include/Obj23398.h"
#include "../../matched/include/Obj23399.h"
#include "../../matched/include/Obj18565.h"
#include "../../matched/include/Obj04905.h"
#include "../../matched/include/Obj14167.h"
#include "../../matched/include/Obj23400.h"
#include "../../matched/include/Obj03294.h"
#include "../../matched/include/Obj23401.h"
#include "worldtrade_types.h"
#include "../../matched/include/Obj06513.h"
#include "../../matched/include/Obj04527.h"
#include "../../matched/include/Obj23403.h"
#include "../../matched/include/Obj09233.h"
#include "../../matched/include/Obj01743.h"
#include "../../matched/include/Obj12205.h"
#include "../../matched/include/Obj10580.h"
#include "../../matched/include/Obj04528.h"
#include "../../matched/include/Obj02857.h"
#include "../../matched/include/Obj01259.h"
#include "../../matched/include/Obj12206.h"
#include "../../matched/include/Obj01744.h"
#include "../../matched/include/Obj03296.h"
#include "../../matched/include/Obj00474.h"
#include "../../matched/include/Obj01745.h"
#include "../../matched/include/Obj09234.h"
#include "../../matched/include/Obj03297.h"
#include "../../matched/include/Obj07245.h"
#include "../../matched/include/Obj05414.h"
#include "../../matched/include/Obj05415.h"
#include "../../matched/include/Obj00246.h"
#include "../../matched/include/Obj00098.h"
#include "../../matched/include/Obj01160.h"
#include "../../matched/include/Obj00194.h"
#include "../../matched/include/Obj09235.h"
#include "../../matched/include/Obj02490.h"
#include "../../matched/include/Obj02858.h"
#include "../../matched/include/Obj00195.h"
#include "../../matched/include/Obj02859.h"

struct Slot;
struct Obj;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub0200852CObj;
struct Ctx;
struct MsgBank;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct WordSet;
struct WinMgr;
struct Obj;
struct Actor;
struct Blk37;
typedef struct {
    u8 start;
    u8 id;
} Range_021F88B0;

typedef unsigned long long u64;

typedef struct {
    void *handle;
    u32 f4, f8, fc;
    void *f10;
    u32 f14, f18, f1c;
    int (*callback_021F88B0)(void *, u8 *);
    void *user;
} State_p01;

typedef struct {
    void *save;
    int zero;
    int enabled;
    int pad[2];
    u32 (*callback_021F8DA4)(u8 *);
    void *context;
} Req_p02;

typedef struct {
    void **win;
    u8 pad4[0x18 - 4];
    struct WinMgr *f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50;
} Obj_021F9024;

typedef struct {
    u32 w00;
    u32 w04;
    u32 obj;
    u32 w0c;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct {
    u32 w00;
    u32 w04;
    u32 obj;
    u32 w0c;
    u32 w10;
    u32 w14;
    void *frm;
    u32 w24;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w28;
    u8 pad30[4];
    void *ctx;
    u16 h38;
    u16 h3a;
    u16 h3c;
    u16 h3e;
    u8 b40;
    u8 b41;
    u8 pad42[2];
    u32 w44;
    u32 w48;
    u8 pad4c[4];
    u32 a;
    u8 pad54[8];
    u32 b;
    u8 pad60[0x1a];
    u8 b7a;
    u8 pad7b;
    u8 sub[0x13c];
} Menu_021F9024;

typedef struct Obj_021F99F0 Obj_021F99F0;

struct Obj_021F99F0 {
    u8 pad0[0x18];
    void *mgr;
    u8 pad1C[0x34 - 0x1C];
    void *printer;
    u8 pad38[0x48 - 0x38];
    int state;
    u8 pad4C[0x7C - 0x4C];
    u8 g[4];
};

typedef struct {
    u8 up;
    u8 down;
    u8 left;
    u8 right;
} Link;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    int count;
    int f4;
} Layout;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

typedef struct {
    int first;
    int count;
} Range_021FA7C4;

extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern s32 func_020200CC(struct Obj *o);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern void func_020061E4(u32 id);
extern void func_021F50EC(u8 *);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);
extern void func_02005D90(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_02168064(void);
extern int func_02168124(void);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_02009CC0(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_021C7BA0(u32 a, u32 b, u32 c, int d);
extern void func_021C8DA0(u8 *p);
extern void *func_021C7C1C();
extern u32 func_021C866C();
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_021B9B00(u8 *,int);
extern void func_021C8E18(u8 *,u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 value, u32 size);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02031348(void *h, u32 id, const void *a, void *b);
extern u32 func_0200F7B8(u32 a0);
extern u32 func_020307B0(void *p);
extern void func_021C8658();
extern void func_021D5B5C(char *p, struct MsgBank *a, int b);
extern int func_021D5C70(u8 *p);
extern void func_0216AD50(void);
extern void func_0205CC20(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0201F73C(void *, int, int, int);
extern void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern int func_022026C4(u32 *p, u32 b, u32 a, u32 c);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_022028C8(u8 *p, u32 z, u32 b, u32 r, u32 d, u32 z2, u16 f, u32 g);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32  sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02040DA8(u32, u32, u32);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_02202974(u32 a, u32 b, u32 c, u32 heap);
extern void func_022026D8(void *ctx, u32 arg);
extern void func_02202744(u8 *p);
extern void func_022029D4(u8 *p);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_02202770(void *g);
extern void func_022029F8(void *printer);
extern int func_02035C08(const void *p);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0209C0A4(u8 *p, u32 n, u32 m);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern int func_021FBFB0(void *, int);
extern int func_021FC014(void *, int);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern int func_021F87E0(void **, void *, int);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern u16 func_0204B898(struct Obj *p);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FBF6C(Menu *m, u32 idx);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern u32 func_0201F868(void *p);
void func_021F88B0(u8 *p,u32 n);
int func_021F88D8(u32 id, u32 *start);
int func_021F8908(void **menu, void *msg, int id);
int func_021F8950(void *p, u16 *old);
void func_021F8990(u8 *p);
void func_021F89A8(u8 *p, int i, u16 a, u16 b);
int func_021F89B4(u8 *p);
int func_021F89F0(u8 *p);
u32 func_021F8A18(u8 *p);
void func_021F8A3C(void *a0);
void func_021F8A40(void);
int func_021F8A44(Work *p);
int func_021F8A74(void *a0);
int func_021F8A80(u8 *a0);
int func_021F8AB0(u8 **p);
int func_021F8AF4(u8 *p);
int func_021F8B0C(u8 *p);
int func_021F8BBC(u8 *p);
int func_021F8BE8(Work *p);
int func_021F8D10(u8 *p);
int func_021F8DA4(u8 *p);
int func_021F8DE4(u8 *p);
int func_021F8E58(u8 *p);
int func_021F8E88(void *dialog, u8 *p);
u32 func_021F8F5C(u8 *p);
int func_021F8F68(u8 *p);
int func_021F8F84(u8 *p, void *dialog);
int func_021F9024(u8 *p, void *dialog);
void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021F90B8(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow);
int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx);
int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
void func_021F9218(void *win, void *bank, int idx, void *g);
void func_021F9254(u8 *a0);
void ov135_func_021F9260(Menu *p, u32 mode);
void func_021F9660(Obj_021F9024 *p, int mode);
Menu_021F9024 *func_021F9890(Init *init, u32 a, u32 b);
void func_021F9968(u8 *p, int mode);
void func_021F99D0(u8 *p);
int func_021F99F0(Obj_021F99F0 *p);
int func_021F9A1C(void *p, int mode);
int func_021F9A88(Menu *p, u8 *enable);
int func_021F9CB0(Menu *p, int v);
int func_021F9CDC(Menu *p, int base);
u32 func_021F9EEC(u8 *p, u32 n);
int func_021F9F00(Menu *m, int key);
void func_021F9F58(Menu *m, int dir);
int func_021F9FF0(Menu *m);
int func_021FA15C(Menu *p);
void func_021FA2B0(Menu *m, int dir);
int func_021FA330(Menu *m, int key);
int func_021FA394(Menu *m);
int func_021FA4FC(int unused, int mode);
int func_021FA514(Menu *p, u8 *enable);
int func_021FA760(Menu *m, int key);
void func_021FA7C4(Menu *m, int dir);
int func_021FA85C(Menu *m);
void func_021FA9C8(u8 *p, int mode, int pos);
void func_021FAAD4(u8 *p);
void func_021FAB70(u8 *p);
void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
int func_021FAC84(void);
int func_021FAC8C(u8 *p);
int func_021FAD08(u8 *p);
int func_021FAD24(u8 *p);
int func_021FAD84(u8 *p);
int func_021FADA8(u8 *p);
void func_021FADF0(u8 *p);
int func_021FAE2C(u8 *p);
int func_021FAE8C(u8 *p);
int func_021FAEE0(u8 *p);
int func_021FAFF0(Menu *m);
int func_021FB164(u8 *p);
int func_021FB1E4(u8 *p);
int func_021FB220(u8 *p);
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
int func_021FB26C(Item **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);
void func_021FB2F0(Menu *m, int page, int total);
void func_021FB364(Menu *m, int page, int total);
int func_021FB3D8(Menu *p);
int func_021FB510(u8 *p);
int func_021FB588(u8 *p);
int func_021FB5E4(u8 *p);
int func_021FB614(u8 *p);
int func_021FB674(u8 *p);
int func_021FB704(u8 *p);
int func_021FB7A0(u8 *p);
extern const u16 d_022030E8[];
extern const Range_021F88B0 tbl_02202F0C[];
extern u16 tbl_022030E8[];
extern const char str_02203C34[], ov115_id[];
extern const u32 d_021D6338[];
extern u8 tbl_021D654C[];
extern const u32 tbl_022031EC[];
extern const u8 data_02203200[3][2];
extern const u8 data_02203206[4][2];
extern const u8 data_0220322A[4][3];
extern const u8 data_02203242[5][2];
extern const u8 data_022032AE[9][2];
extern u8 g_02203CD8[];
extern u8 tbl_02203370[];
extern u8 tbl_022033C8[];
extern u8 tbl_022032DE[];
extern u8 tbl_02203270[];
extern u8 tbl_022032FE[];
extern u8 tbl_02203284[];
extern const Link tbl_02203348[];
extern const Cell tbl_022032C6[];
extern const Layout tbl_022033FC[];
extern const Link tbl_02203260[];
extern u8 *const tbl_02203324[];
extern const CurPos tbl_02203220[];
extern const Cell tbl_0220320E[];
extern const int tbl_02203250[];
extern const CurPos tbl_02203216[];
extern const Link tbl_0220339C[];
extern const Cell tbl_02203298[];
extern const CurPos tbl_02203236[];
extern const Range_021FA7C4 tbl_022033F8[];
extern const u32 tbl_02203440[];
extern u8 g_022033FC[];





void func_021F88B0(u8 *p,u32 n) { if(n==0){((struct Obj02204 *)p)->fF84=0;return;}n--;if(n<130)((struct Obj02204 *)p)->fF84=d_022030E8[n]; }





int func_021F88D8(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}





#pragma opt_common_subs off





/*
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of func_0201F878 (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 */
int func_021F8908(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = func_021F88D8(id, &start);
    *menu = func_0201F81C(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        func_0201F878(*menu, (u32)msg, tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}





#pragma opt_common_subs reset





int func_021F8950(void *p, u16 *old)
{
    u16 current;
    int result;
    result = func_020200CC(p);
    func_020202EC(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) func_020061E4(0x548);
        *old = current;
    }
    return result;
}





/*
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */
void func_021F8990(u8 *p)
{
    int i;
    u16 z = 0;

    for (i = 0; i < 10; i++) {
        *(u16 *)(p + i * 2 + 4) = z;
        *(u16 *)(p + i * 2 + 0x18) = z;
    }
    ((struct Obj12203 *)p)->f0 = z;
    ((struct Obj12203 *)p)->f2 = z;
}





/*
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
void func_021F89A8(u8 *p, int i, u16 a, u16 b)
{
    u8 *q = p + i * 2;

    ((struct Obj12204 *)q)->f4 = a;
    ((struct Obj12204 *)q)->f18 = b;
}





/*
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 */
int func_021F89B4(u8 *p) {func_021F50EC(p);func_021F8A3C(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(((struct Obj05413 *)p)->f20){case 19:case 21:((struct Obj05413 *)p)->f28=2;break;case 20:((struct Obj05413 *)p)->f28=4;break;}return 1;}





extern int (*const d_02203C1C[])(void *);





int func_021F89F0(u8 *p) { int state,r;state=((struct Obj08184 *)p)->f28;r=d_02203C1C[state](p);if(state!=((struct Obj08184 *)p)->f28){((struct Obj08184 *)p)->fF88=0;((struct Obj08184 *)p)->fF8A=0;}return r; }





/*
 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
u32 func_021F8A18(u8 *p)
{
    func_021F8A40();
    func_021F5074(p);
    func_021F4EC8(p);
    if (((struct Obj00287 *)p)->f10 == 0) {
        return 4;
    }
    return 0;
}





/*
 * Empty stub.
 */
void func_021F8A3C(void *a0)
{
}





void func_021F8A40(void)
{
}





int func_021F8A44(Work *p)
{
    func_02005D90(0x486, 0xFFFF);
    p->state = 1;
    p->xEB2 = 1;
    p->x30 = 0;
    func_021F4EC0((u8 *)p, 1, 0);
    return 2;
}





/*
 * Call func_02168064 and report success.
 */
int func_021F8A74(void *a0)
{
    func_02168064();
    return 1;
}





/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021F8A80(u8 *a0) { switch(func_02168124()) {case 3:return 1;case 0:case 4:case 5:return 2;default:return 0;} }





/*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 */
int func_021F8AB0(u8 **p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = func_02009860(((struct Obj23396 *)(*p))->f14);
    func_02008540(((struct Obj23397 *)(*p))->f1C, func_02009CC0(((struct Obj23398 *)(*p))->f14));
    id = func_0200853C(((struct Obj23399 *)(*p))->f1C);
    key = func_0205994C(handle);
    func_021C7BA0(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}





/*
 * Hand the object over, clear the +0xf8c slot and latch 1.
 */
int func_021F8AF4(u8 *p)
{
    func_021C8DA0(p);
    ((struct Obj18565 *)p)->fF8C = 0;
    return 1;
}





/*
 * 18-slot switch on the 0x021C86A8 index (case value = index + 15, bound 17):
 * index 14 returns 1, and four separate case groups (15, 13+16, 0+3, 1+12)
 * each call func_021F4FC4 and archive n at +0x38 before returning 2; the
 * remaining indexes fall through to the shared tail (one more func_021F4FC4)
 * and the function returns 0.  func_021C7C1C(p) runs first, unconditionally.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_021F8B0C(u8 *p)
{
    s32 n;

    if (func_021C866C(func_021C7C1C(p)) != 0) {
        n = func_021C86A8();
        ((struct Obj04905 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            return 1;
        case 16:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 14:
        case 17:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 0:
        case 3:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 1:
        case 13:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        }
        func_021F4FC4(p);
        func_021F513C(p);
    } else {
        if (++((struct Obj04905 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 0;
}





int func_021F8BBC(u8 *p) { func_021B9B00(p+0xf18,((struct Obj23400 *)(*(u8 * *)&((struct Obj14167 *)p)->f0))->f1C);func_021C8E18(p+0xf18,(u32)(p+0xf7c));((struct Obj14167 *)p)->fF8C=0;return 1; }





/*
 * note: 2026-10-05 wave P19: the sub switch exit (state 0, sub out of range) is a cross-jumped copy of the tail, `b 0x021F8CEC` in the image. Written as `func_021F513C(p); goto done;` after the sub switch, with `done: return 0;` at the end. EXACT in c99 and c (296 bytes). Idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
 */
int func_021F8BE8(Work *p)
{
    int code;

    func_021C7C1C();
    if (func_021C866C() != 0) {
        code = func_021C86A8();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state_iF7C) {
            case 0:
                switch (p->sub_i) {
                case 0:
                    func_021F4EC0((u8 *)p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                func_021F513C((u8 *)p);
                goto done;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                func_021F4FC4((u8 *)p);
                break;
            }
            break;
        case 1:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        default:
            func_021F4FC4((u8 *)p);
            break;
        }
        func_021F513C((u8 *)p);
    } else if (++p->wait == 0xE10) {
        func_021F513C((u8 *)p);
    }
done:
    return 0;
}





/*
 * lever: ov115 data hint is witnessed by this function loading ov115 via func_02031348; no hint remains MATCH.
 */
int func_021F8D10(u8 *p)
{
    State_p01 *s;
    *(State_p01 * *)&((struct Obj03294 *)p)->f10DC = func_02030734(0x48, sizeof(State_p01), 0, str_02203C34, 0x263);
    func_02082BCC(*(State_p01 * *)&((struct Obj03294 *)p)->f10DC, 0, sizeof(State_p01));
    s = *(State_p01 * *)&((struct Obj03294 *)p)->f10DC;
    s->handle = func_020120F4(((struct Obj23401 *)(*(u8 * *)&((struct Obj03294 *)p)->f0))->f40);
    s->f4 = 0;
    s->f8 = 1;
    s->f10 = p + 0x116C;
    s->fc = 30;
    s->callback_021F88B0 = func_021F8E88;
    s->user = p;
    ((struct Obj03294 *)p)->f12EC = 0;
    if (((struct Obj03294 *)p)->f20 == 21) s->f14 = 1;
    else s->f14 = 0;
    func_02031348(((struct Obj03294 *)p)->f12F0, (u32)ov115_id, d_021D6338, *(State_p01 **)(p + 0x10DC));
    func_0200F7B8(0);
    ((struct Obj03294 *)p)->f28 = 3;
    return 2;
}





int func_021F8DA4(u8 *p)
{
    u32 *state = *(u32 * *)&((struct Obj06513 *)p)->f10DC;
    if (((struct Obj06513 *)p)->f12F4 == 0) {
        switch (state[7]) {
        case 0: ((struct Obj06513 *)p)->f28 = 0; break;
        case 1:
            func_021F4EC0(p, 0, 0);
            ((struct Obj06513 *)p)->f28 = 1;
            break;
        }
        func_020307B0(((struct Obj06513 *)p)->f10DC);
    }
    return 2;
}





int func_021F8DE4(u8 *p)
{
    Req_p02 *r;
    *(Req_p02 * *)&((struct Obj04527 *)p)->f10DC = func_02030734(72, 28, 0, str_02203C34, 689);
    func_02082BCC(*(Req_p02 * *)&((struct Obj04527 *)p)->f10DC, 0, 28);
    r = *(Req_p02 * *)&((struct Obj04527 *)p)->f10DC;
    r->save = func_020120F4(((struct Obj23403 *)(*(u8 * *)&((struct Obj04527 *)p)->f0))->f40);
    r->zero = 0;
    r->enabled = 1;
    r->callback_021F8DA4 = func_021F8F5C;
    r->context = p;
    func_02031348(((struct Obj04527 *)p)->f12F0, (u32)ov115_id, tbl_021D654C, *(Req_p02 * *)&((struct Obj04527 *)p)->f10DC);
    ((struct Obj04527 *)p)->f28 = 5;
    func_0200F7B8(0);
    return 2;
}





int func_021F8E58(u8 *p)
{
    if (((struct Obj09233 *)p)->f12F4 == 0) {
        func_020307B0((void *)(((struct Obj09233 *)p)->f10DC));
        func_021F4EC0(p, 0, 0);
        ((struct Obj09233 *)p)->f28 = 1;
    }
    return 2;
}





int func_021F8E88(void *dialog, u8 *p)
{
    int result;
    switch (((struct Obj01743 *)p)->f12EC) {
    case 0:
        if (func_021F8A74(p))
            (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 1:
        result = func_021F8A80(p);
        switch (result) {
        case 1: (((struct Obj01743 *)p)->f12EC)++; break;
        case 2: ((struct Obj01743 *)p)->f12EC = 9; break;
        }
        break;
    case 2:
        if (func_021F8AB0((u8 **)p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 3:
        if (func_021F8AF4(p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 4:
        result = func_021F8B0C(p);
        switch (result) {
        case 1: (((struct Obj01743 *)p)->f12EC)++; break;
        case 2: ((struct Obj01743 *)p)->f12EC = 7; break;
        }
        break;
    case 5:
        if (func_021F8BBC(p)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 6:
        result = func_021F8BE8((Work *)p);
        switch (result) {
        case 1: ((struct Obj01743 *)p)->f12EC = 0; return 0;
        case 2: ((struct Obj01743 *)p)->f12EC = 7; break;
        }
        break;
    case 7:
        if (func_021F8F84(p, dialog)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 8:
        if (func_021F9024(p, dialog)) (((struct Obj01743 *)p)->f12EC)++;
        break;
    case 9:
        ((struct Obj01743 *)p)->f12EC = 0;
        return 1;
    }
    return 2;
}





/*
 * Every concrete byte is reproduced.  The one wildcard is the BLX at +0002 to
 * func_021C8658, which has no independent witness outside 021F8F5C..021F8F66;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Same blocker as func_02201FDC
 * and func_021FEB84/func_02201C88: naming one of those eight regions would be
 * a guess, so the site stays parked until the region that owns 0x021C8658 is
 * established.
 */
u32 func_021F8F5C(u8 *p)
{
    func_021C8658(p);
    return 0;
}





/*
 * Reset the object, latch state 0 and set the +0xeb4 slot to 1.
 */
int func_021F8F68(u8 *p)
{
    func_021F4FC4(p);
    ((struct Obj12205 *)p)->f28 = 0;
    ((struct Obj12205 *)p)->fEB4 = 1;
    return 3;
}





int func_021F8F84(u8 *p, void *dialog)
{
    int text;
    switch (((struct Obj10580 *)p)->f38) {
    case 1: text = 166; break;
    case 2: text = 167; break;
    case -1: text = 157; break;
    case -2: text = 169; break;
    case -3: text = 162; break;
    case -4: text = 164; break;
    case -5: text = 163; break;
    case -6: text = 27; break;
    case -7: text = 28; break;
    case -8: text = 29; break;
    case -9: text = 30; break;
    case -10: text = 31; break;
    case -11: text = 32; break;
    case -12: text = 160; break;
    case -13: text = 165; break;
    case -14: text = 170; break;
    case -15: text = 161; break;
    default: text = 159; break;
    }
    func_021D5B5C(dialog, ((struct Obj10580 *)p)->fB6C, text);
    ((struct Obj10580 *)p)->fF88 = 0;
    return 1;
}





int func_021F9024(u8 *p, void *dialog)
{
    switch (((struct Obj04528 *)p)->fF88) {
    case 0:
        (((struct Obj04528 *)p)->fF88)++;
        break;
    case 1:
        if (func_021D5C70(dialog)) (((struct Obj04528 *)p)->fF88)++;
        break;
    case 2:
        (((struct Obj04528 *)p)->fF88)++;
        break;
    case 3:
        func_021C8658();
        func_0216AD50();
        func_0205CC20();
        (((struct Obj04528 *)p)->fF88)++;
        break;
    default:
        (((struct Obj04528 *)p)->fF8A)++;
        if (((struct Obj04528 *)p)->fF8A > 60) return 1;
        break;
    }
    return 0;
}





/*
 * Forward the u16 stack argument to func_021F90B8 with mode 1.
 */
void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((u8 *)a, (void *)b, c, d, e, 1);
}





/*
 * Forward the u16 stack argument to func_021F90B8 with mode 0.
 */
void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((u8 *)a, (void *)b, c, d, e, 0);
}





void func_021F90B8(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = func_02045EC0(bank, index);
    func_0201F250(((struct Obj02857 *)p)->fB68, ((struct Obj02857 *)p)->fB88, str);
    func_02045808(str);
    func_02043B5C(func_02045770(((struct Obj02857 *)p)->fD40), 15);
    func_02045334(((struct Obj02857 *)p)->fD40);
    func_0201F73C(((struct Obj02857 *)p)->fD40, 0, 1, 14);
    if (slow)
        func_02202878(((struct Obj02857 *)p)->fD40, 0, (unsigned int)(((struct Obj02857 *)p)->fB88), 0, 0, p + 0xfa0);
    else
        func_02202858(((struct Obj02857 *)p)->fD40, 0, ((struct Obj02857 *)p)->fB88, 0, 0, p + 0xfa0);
    ((struct Obj02857 *)p)->fDFC = 0;
}





/*
 * lever: unused fifth argument leaves font and context in stack slots +4/+8.
 */
int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx)
{
    int width;
    switch (align) {
    case 1:
        width = func_022026C4(ctx, (u8)font, (u32)str, (int)0);
        x = (func_02045738(win) * 8 - width) / 2;
        break;
    case 2:
        width = func_022026C4(ctx, (u8)font, (u32)str, (int)0);
        x = func_02045738(win) * 8 - width;
        break;
    }
    return x;
}





/*
 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */
int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = func_021F914C(p, (void *)b, c, e, f, 0, (void *)g);

    return func_022028C8(p, 0, b, r, d, 0, f, g);
}





int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = func_021F914C(p, (void *)b, c, e, f, 0, (void *)g);

    return func_022028C8(p, 0, b, r, d, 0, f, g);
}





void func_021F9218(void *win, void *bank, int idx, void *g)
{
    void *str;

    str = func_02045EC0(bank, tbl_022031EC[idx]);
    func_021F91A0(win, (u32)str, 0, 0, 0, 0x440, (u32)g);
    func_02045808(str);
}





/*
 * Tail call into func_0203D34C with the fixed 0/0x48 pair.
 */
void func_021F9254(u8 *a0)
{
    func_0203D34C(0, 0x48);
}





void ov135_func_021F9260(Menu *p, u32 mode)
{
    int i;

    func_02040C14(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 5:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        p->wins[0] = (void *)sub_020450F0((u8)p->layer, 2, 2, 3, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[0])), 7);
        for (i = 1; i < 4; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 0:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)sub_020450F0((u8)p->layer, 5, 14, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[4])), 8);
        break;
    case 6:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[15] = (void *)sub_020450F0((u8)p->layer, 1, 2, 9, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[15])), 10);
        break;
    case 3:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 24, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 5; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[5] = (void *)sub_020450F0((u8)p->layer, 14, 16, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[5])), 10);
        break;
    case 1:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 3; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 2:
        p->wins[14] = (void *)sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)sub_020450F0((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)sub_020450F0((u8)p->layer, 5, 14, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->wins[4])), 8);
        break;
    }
}





/*
 * Redraw the text windows of layout `mode` (0..6): clear and refresh the
 * first n windows of the window table, and when the second brightness
 * byte read by func_0202CF98 is 0x10 reset the two BG2 screen blocks
 * (func_02041300) and commit them; then refresh window 14 (and 15 for
 * layout 6) and schedule the +0x50 screen.
 */
void func_021F9660(Obj_021F9024 *p, int mode)
{
    s8 bright[2];
    int i = 0;

    func_0202CF98(p->f18, 0, &bright[1], &bright[0]);
    switch (mode) {
    case 4:
        for (i = 0; i < 9; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        break;
    case 0:
        for (i = 0; i < 5; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        break;
    case 6:
        for (i = 0; i < 9; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        func_020452E8(p->win[14]);
        func_020452E8(p->win[15]);
        break;
    case 3:
        for (i = 0; i < 6; i++) {
            func_02043B5C(func_02045770(p->win[i]), 10);
            func_02045334(p->win[i]);
            func_020452E8(p->win[i]);
        }
        func_020452E8(p->win[14]);
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            func_020452E8(p->win[i]);
        }
        func_020452E8(p->win[14]);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            func_020452E8(p->win[i]);
        }
        func_020452E8(p->win[14]);
        break;
    }
    func_02040DA8(p->f50, 1, 0);
}





Menu_021F9024 *func_021F9890(Init *init, u32 a, u32 b)
{
    Menu_021F9024 *m;

    m = func_02030734(0x48, 0x1b8, 0, (const char *)g_02203CD8, 0x336);
    m->w00 = init->w00;
    m->w04 = init->w04;
    m->obj = init->obj;
    m->w0c = init->w0c;
    m->w10 = init->w10;
    m->w14 = init->w14;
    m->w18 = init->w18;
    m->w1c = init->w1c;
    m->w20 = init->w20;
    m->w24 = init->w24;
    m->w28 = init->w28;
    m->a = a;
    m->b = b;
    m->h38 = 0;
    m->h3a = 0;
    m->h3c = 0;
    m->h3e = 0;
    m->b40 = 0;
    m->b41 = 0;
    m->w44 = 0;
    m->b7a = 0;
    m->w48 = 0;
    m->frm = func_0202C9B4(2, 1, 0x48);
    func_0202CA3C(m->frm, 0, 2, 0x20, 0x14);
    func_021F4FF4(m->obj, 0x90, 0x28);
    func_0204B878((struct Obj *)m->obj, 4);
    func_0204B92C((struct Obj *)m->obj, 1);
    func_0204B3DC((struct Obj *)m->obj, 0);
    m->ctx = func_02202974(0xf, 0xe, 2, 0x48);
    func_022026D8(m->sub, init->arg);
    return m;
}





/*
 * trailing: two-byte zero alignment padding at 0x021F99CE.
 */
void func_021F9968(u8 *p, int mode)
{
    ((struct Obj01259 *)p)->f54 = mode;
    switch (mode) {
    case 0:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f38 = 0;
        ((struct Obj01259 *)p)->f3A = 0;
        ((struct Obj01259 *)p)->f48 = 6;
        return;
    case 3:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f38 = 0;
        ((struct Obj01259 *)p)->f3A = 0;
        ((struct Obj01259 *)p)->f48 = 18;
        return;
    case 1:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f48 = 30;
        return;
    case 2:
        p[122] = 0;
        ((struct Obj01259 *)p)->f44 = 0;
        ((struct Obj01259 *)p)->f48 = 33;
        break;
    }
}





/*
 * Tear the object down: sub-object at +0x7c, buffer at +0x34, then the object.
 */
void func_021F99D0(u8 *p)
{
    func_02202744(p + 0x7c);
    func_022029D4(*(u8 * *)&((struct Obj12206 *)p)->f34);
    func_0202CA0C(*(struct WinMgr * *)&((struct Obj12206 *)p)->f18);
    func_020307B0((void *)((u32)p));
}





extern int (*const tbl_02203C48[])(Obj_021F99F0 *p);





int func_021F99F0(Obj_021F99F0 *p)
{
    int r = tbl_02203C48[p->state](p);

    func_0202CD94(p->mgr);
    func_02202770(p->g);
    func_022029F8(p->printer);
    return r;
}





/*
 * Touch hit test against the rectangle table of screen mode `mode`
 * (0..7; modes 0/2 and 5/7 share a table). Any other mode falls off the
 * end and hands back the first argument still in r0.
 */
int func_021F9A1C(void *p, int mode)
{
    switch (mode) {
    case 4:
        return func_02035C08(tbl_02203370);
    case 6:
        return func_02035C08(tbl_022033C8);
    case 0:
    case 2:
        return func_02035C08(tbl_022032DE);
    case 1:
        return func_02035C08(tbl_02203270);
    case 3:
        return func_02035C08(tbl_022032FE);
    case 5:
    case 7:
        return func_02035C08(tbl_02203284);
    }
}





/*
 * Cursor input for the ten-entry mode-4 menu: the mode-6 grid of nine
 * entries with one button (9). Returns the entry, -2 for cancel (B or
 * the button), -1 for nothing or an entry `enable` marks off. A grid
 * position past 9 under A reports through func_02034714 (raw address
 * 0x02203CEC, a plain constant as in func_02202B20).
 */
int func_021F9A88(Menu *p, u8 *enable)
{
    int old = p->pos;
    int r;
    int ret;

    if (old < 9) {
        p->last = old;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        p->pos = tbl_02203348[p->pos].up;
    } else if (func_0203633C() & 0x80) {
        p->pos = tbl_02203348[p->pos].down;
    } else if (func_0203633C() & 0x20) {
        p->pos = tbl_02203348[p->pos].left;
    } else if (func_0203633C() & 0x10) {
        p->pos = tbl_02203348[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (func_0203633C() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (func_0203633C() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
        if (p->pos == 9) {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 0x12);
        }
    }
    ret = -1;
    r = func_021F9A1C(p, 4);
    if (r != ret) {
        func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
        if (r == 9) {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            p->pos = r;
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 0x12);
        }
        if (r == 9) {
            func_020061E4(0x551);
            ret = -2;
        } else if (enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
            ret = r;
        }
        if (ret == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 0);
        }
        func_020355D8(1);
        return ret;
    }
    if (func_020362DC() & 1) {
        if (p->pos == 9) {
            func_020061E4(0x551);
            return -2;
        }
        if (p->pos >= 9) {
            func_02034714((void *)0x02203CEC, 0, (void *)0x02203CEC);
        }
        if (enable == 0 || enable[p->pos] != 0) {
            func_020061E4(0x54C);
            return p->pos;
        }
    } else if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}





/*
 * Validate a touched entry index: 3 maps to -2; for layouts 0..8 (+0x38)
 * an index at or past the layout's entry count (first word of its 8-byte
 * row) maps to -1; anything else is returned unchanged.
 */
int func_021F9CB0(Menu *p, int v)
{
    if (v != 3) {
        if (p->layout <= 8) {
            if (v >= tbl_022033FC[p->layout].count) {
                v = -1;
            }
            return v;
        }
        return v;
    }
    return -2;
}





/*
 * Cursor input for the five-entry mode-5 menu: the d-pad walks the link
 * table (entry 3 is the fixed bottom button, leaving it restores the last
 * grid entry from +0x7A), a touch (func_021F9A1C) or A selects. Returns
 * the selected entry, -2 for cancel (B or the button), -1 for nothing or
 * for an entry the per-layout enable row marks unavailable at `base`.
 */
int func_021F9CDC(Menu *p, int base)
{
    int old = p->pos;
    int r;

    if (old < 3) {
        p->last = old;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        p->pos = tbl_02203260[p->pos].up;
    } else if (func_0203633C() & 0x80) {
        p->pos = tbl_02203260[p->pos].down;
    } else if (func_0203633C() & 0x20) {
        p->pos = tbl_02203260[p->pos].left;
    } else if (func_0203633C() & 0x10) {
        p->pos = tbl_02203260[p->pos].right;
    }
    if (old == 3 && p->pos < 3) {
        p->pos = p->last;
    }
    if (old != p->pos) {
        func_020061E4(0x548);
        if (p->pos == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 4);
        }
    }
    r = func_021F9A1C(p, 5);
    if (r != -1) {
        if (r == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            p->pos = r;
            func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 4);
        }
        r = func_021F9CB0((Menu *)p, r);
        if (r == -2) {
            func_020061E4(0x551);
        } else if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            func_020061E4(0x54C);
        } else {
            r = -1;
            if (func_020355C4() == 0) {
                func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 0);
            }
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        r = func_021F9CB0((Menu *)p, p->pos);
        if (r == -1) {
            return r;
        }
        if (r == -2) {
            func_020061E4(0x551);
            return r;
        }
        if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            func_020061E4(0x54C);
            return r;
        }
    } else if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}





/*
 * Step one byte short of the end, or report 1 when there is no buffer.
 */
u32 func_021F9EEC(u8 *p, u32 n)
{
    u32 m;

    if (p == 0) {
        return 1;
    }
    m = n - 1;
    return func_0209C0A4(p + m, n, m);
}





int func_021F9F00(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 4:
        return -2;
    case 5:
        func_021F9F58((Menu *)m, -1);
        return -1;
    case 6:
        func_021F9F58((Menu *)m, 1);
        return -1;
    }
    idx = key + m->page * 4;
    if (idx < m->total) {
        func_020061E4(0x54C);
        return m->items[idx].val;
    }
    return -1;
}





void func_021F9F58(Menu *m, int dir)
{
    int last;

    last = func_021F9EEC((u8 *)m->total, 4) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)((struct Obj *)m->down), 1);
        func_0204B878((struct Obj *)((struct Obj *)m->down), 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = last;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)((struct Obj *)m->up), 1);
        func_0204B878((struct Obj *)((struct Obj *)m->up), 0x26);
        if (m->page < last) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB2F0((Menu *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[4], m->page, func_021F9EEC((u8 *)m->total, 4));
}





int func_021F9FF0(Menu *m)
{
    int old;
    int r;

    old = m->pos;
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)((struct Obj *)m->cursor), 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        if (m->pos != 0) {
            m->pos = m->pos - 1;
        } else {
            m->pos = 4;
        }
    } else if (func_0203633C() & 0x80) {
        if (m->pos != 4) {
            m->pos = m->pos + 1;
        } else {
            m->pos = 0;
        }
    } else if (func_0203633C() & 0x20) {
        func_021F9F58((Menu *)m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021F9F58((Menu *)m, 1);
    }
    if (old != m->pos) {
        func_020061E4(0x548);
        func_021F4FF4(m->cursor, tbl_02203220[m->pos].x, tbl_02203220[m->pos].y);
        if (m->pos == 4) {
            func_0204B878((struct Obj *)((struct Obj *)m->cursor), 5);
        } else {
            func_0204B878((struct Obj *)((struct Obj *)m->cursor), 6);
        }
    }
    r = func_021F9A1C(m, 0);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203220[r].x, tbl_02203220[r].y);
            if (r == 4) {
                func_0204B878((struct Obj *)((struct Obj *)m->cursor), 5);
            } else {
                m->pos = r;
                func_0204B878((struct Obj *)((struct Obj *)m->cursor), 6);
            }
        }
        r = func_021F9F00((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)((struct Obj *)m->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021F9F00((Menu *)m, m->pos);
    }
    if (func_020362DC() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)((struct Obj *)m->cursor), 5);
        func_020061E4(0x551);
        return -2;
    }
    return -1;
}





int func_021FA15C(Menu *p)
{
    int old = p->pos;
    int r;

    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        if (p->pos != 0) {
            p->pos = p->pos - 1;
        } else {
            p->pos = 3;
        }
    } else if (func_0203633C() & 0x80) {
        if (p->pos != 3) {
            p->pos = p->pos + 1;
        } else {
            p->pos = 0;
        }
    }
    if (old != p->pos) {
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, tbl_0220320E[p->pos].x, tbl_0220320E[p->pos].y);
        if (p->pos == 3) {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 6);
        }
    }
    r = func_021F9A1C(p, 1);
    if (r != -1) {
        func_020355D8(1);
        func_021F4FF4(p->cursor, tbl_0220320E[r].x, tbl_0220320E[r].y);
        if (r == 3) {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 6);
        }
        r = tbl_02203250[r];
        if (r == -2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return r;
    }
    if (func_020362DC() & 1) {
        if (tbl_02203250[p->pos] == -2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return tbl_02203250[p->pos];
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        return -2;
    }
    return -1;
}





void func_021FA2B0(Menu *m, int dir)
{
    if (dir < 0) {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)((struct Obj *)m->down), 1);
        func_0204B878((struct Obj *)((struct Obj *)m->down), 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = 2;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)((struct Obj *)m->up), 1);
        func_0204B878((struct Obj *)((struct Obj *)m->up), 0x26);
        if (m->page < 2) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB2F0((Menu *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[4], m->page, func_021F9EEC((u8 *)m->total, 4));
}





int func_021FA330(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 4:
        func_020061E4(0x551);
        return -2;
    case 5:
        func_021FA2B0((Menu *)m, -1);
        return -1;
    case 6:
        func_021FA2B0((Menu *)m, 1);
        return -1;
    }
    idx = key + m->page * 4;
    if (idx < m->total) {
        func_020061E4(0x54C);
        return m->items[key].val;
    }
    return -1;
}





int func_021FA394(Menu *m)
{
    int old;
    int r;

    old = m->pos;
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)((struct Obj *)m->cursor), 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        if (m->pos != 0) {
            m->pos = m->pos - 1;
        } else {
            m->pos = 4;
        }
    } else if (func_0203633C() & 0x80) {
        if (m->pos != 4) {
            m->pos = m->pos + 1;
        } else {
            m->pos = 0;
        }
    } else if (func_0203633C() & 0x20) {
        func_021FA2B0((Menu *)m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021FA2B0((Menu *)m, 1);
    }
    if (old != m->pos) {
        func_020061E4(0x548);
        func_021F4FF4(m->cursor, tbl_02203216[m->pos].x, tbl_02203216[m->pos].y);
        if (m->pos == 4) {
            func_0204B878((struct Obj *)((struct Obj *)m->cursor), 5);
        } else {
            func_0204B878((struct Obj *)((struct Obj *)m->cursor), 6);
        }
    }
    r = func_021F9A1C(m, 2);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203216[r].x, tbl_02203216[r].y);
            if (r == 4) {
                func_0204B878((struct Obj *)((struct Obj *)m->cursor), 5);
            } else {
                m->pos = r;
                func_0204B878((struct Obj *)((struct Obj *)m->cursor), 6);
            }
        }
        r = func_021FA330((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)((struct Obj *)m->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021FA330((Menu *)m, m->pos);
    }
    if (func_020362DC() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)((struct Obj *)m->cursor), 5);
        func_020061E4(0x551);
        return -2;
    }
    return -1;
}





/*
 * Map a mode value: 9 and 10 have fixed answers, everything else passes through.
 */
int func_021FA4FC(int unused, int mode)
{
    switch (mode) {
    case 9:
        return ~1;
    case 10:
        return 10;
    default:
        return mode;
    }
}





/*
 * Cursor input for the eleven-entry mode-6 menu: a 3-column grid of nine
 * entries plus two buttons (9, 10). Leaving a button with up or down
 * returns to the last grid entry (+0x7A) moved to the bottom or top row.
 * A touch (func_021F9A1C) or A selects. Returns the entry, -2 for cancel
 * (B or entry 9), -1 for nothing or a grid entry `enable` marks off.
 */
int func_021FA514(Menu *p, u8 *enable)
{
    int old = p->pos;
    int r;

    if (old < 9) {
        p->last = old;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        p->pos = tbl_0220339C[p->pos].up;
    } else if (func_0203633C() & 0x80) {
        p->pos = tbl_0220339C[p->pos].down;
    } else if (func_0203633C() & 0x20) {
        p->pos = tbl_0220339C[p->pos].left;
    } else if (func_0203633C() & 0x10) {
        p->pos = tbl_0220339C[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (func_0203633C() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (func_0203633C() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, (tbl_02203298[p->pos].x + 0x10) * 8, tbl_02203298[p->pos].y * 8);
        switch (p->pos) {
        case 9:
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
            break;
        case 10:
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 6);
            break;
        default:
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 0x12);
            break;
        }
    }
    r = func_021F9A1C(p, 6);
    if (r != -1) {
        func_021F4FF4(p->cursor, (tbl_02203298[r].x + 0x10) * 8, tbl_02203298[r].y * 8);
        switch (r) {
        case 9:
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
            break;
        case 10:
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 6);
            break;
        default:
            func_0204B878((struct Obj *)((struct Obj *)p->cursor), 0x12);
            p->pos = r;
            break;
        }
        r = func_021FA4FC((int)p, r);
        if (r == -2) {
            func_020061E4(0x551);
        } else if (r == 10 || enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
        } else {
            r = -1;
        }
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)((struct Obj *)p->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        r = func_021FA4FC((int)p, p->pos);
        if (r == -2) {
            func_020061E4(0x551);
            return r;
        }
        if (r == 10 || enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
            return r;
        }
    } else if (func_020362DC() & 2) {
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)((struct Obj *)p->cursor), 5);
        func_020061E4(0x551);
        return -2;
    }
    return -1;
}





int func_021FA760(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 5:
        func_020061E4(0x551);
        return -2;
    case 6:
        func_021FA7C4(m, -1);
        return -1;
    case 7:
        func_021FA7C4(m, 1);
        return -1;
    }
    idx = key + m->page * 5;
    if (idx < m->total) {
        func_020061E4(0x54C);
        return m->items[idx].val;
    }
    return -1;
}




void func_021FA7C4(Menu *m, int dir)
{
    int last;

    last = func_021F9EEC((u8 *)m->total, 5) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)m->down, 1);
        func_0204B878((struct Obj *)m->down, 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = last;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj *)m->up, 1);
        func_0204B878((struct Obj *)m->up, 0x26);
        if (m->page < last) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB364((Menu *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[5], m->page, func_021F9EEC((u8 *)m->total, 5));
}




int func_021FA85C(Menu *m)
{
    int old;
    int r;

    old = m->pos;
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)m->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return -1;
    }
    if (func_0203633C() & 0x40) {
        if (m->pos != 0) {
            m->pos = m->pos - 1;
        } else {
            m->pos = 5;
        }
    } else if (func_0203633C() & 0x80) {
        if (m->pos != 5) {
            m->pos = m->pos + 1;
        } else {
            m->pos = 0;
        }
    } else if (func_0203633C() & 0x20) {
        func_021FA7C4((Menu *)m, -1);
    } else if (func_0203633C() & 0x10) {
        func_021FA7C4((Menu *)m, 1);
    }
    if (old != m->pos) {
        func_020061E4(0x548);
        func_021F4FF4(m->cursor, tbl_02203236[m->pos].x, tbl_02203236[m->pos].y);
        if (m->pos == 5) {
            func_0204B878((struct Obj *)m->cursor, 5);
        } else {
            func_0204B878((struct Obj *)m->cursor, 7);
        }
    }
    r = func_021F9A1C(m, 3);
    if (r != -1) {
        if ((u32)r < 6) {
            func_021F4FF4(m->cursor, tbl_02203236[r].x, tbl_02203236[r].y);
            if (r == 5) {
                func_0204B878((struct Obj *)m->cursor, 5);
            } else {
                m->pos = r;
                func_0204B878((struct Obj *)m->cursor, 7);
            }
        }
        r = func_021FA760((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021FA760((Menu *)m, m->pos);
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj *)m->cursor, 5);
        return -2;
    }
    return -1;
}




void func_021FA9C8(u8 *p, int mode, int pos)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    func_0202CAE4(((struct Obj01744 *)p)->f18, 0, 96, mode == 6 ? 27 : 28, 1);
    func_0202CF84(((struct Obj01744 *)p)->f18, 0);
    func_021F9260(p, mode);
    func_021FBEB8(((struct Obj01744 *)p)->f18, ((struct Obj01744 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_02082BCC(p + 96, 1, 26);
    g = p;
    g += 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(((struct Obj01744 *)p)->f20, i + 116);
        if (mode == 4) {
            if (func_021FBFB0(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        } else {
            if (func_021FC014(p, i) == 1) {
                color = 0x3dc2;
                p[i + 96] = 1;
            } else {
                color = 0x2122;
                p[i + 96] = 0;
            }
        }
        func_021FAC50(((struct Obj01744 *)p)->f18, (*(void ***)p)[i], str, 2, color, g);
        func_02045808(str);
    }
    if (mode == 6) {
        str = func_02045EC0(((struct Obj01744 *)p)->f20, 188);
        func_021FAC50(((struct Obj01744 *)p)->f18, (*(void ***)p)[15], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_0202CB4C(((struct Obj01744 *)p)->f18, 0, pos, 0);
    func_0202CC58(((struct Obj01744 *)p)->f18, 0);
}




void func_021FAAD4(u8 *p)
{
    int i;
    void *str;
    func_0202CAE4(((struct Obj03296 *)p)->f18, 0, 96, 25, 1);
    func_0202CF84(((struct Obj03296 *)p)->f18, 0);
    func_021F9260(p, 1);
    for (i = 0; i < 3; i++) {
        str = func_02045EC0(((struct Obj03296 *)p)->f20, i + 130);
        func_021FAC50(((struct Obj03296 *)p)->f18, (*(void ***)p)[i], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_021FBEB8(((struct Obj03296 *)p)->f18, ((struct Obj03296 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(((struct Obj03296 *)p)->f18, 0, 32, 0);
    func_0202CC58(((struct Obj03296 *)p)->f18, 0);
    func_0202CD64(((struct Obj03296 *)p)->f18, 0, -4, 0, 4);
}




void func_021FAB70(u8 *p)
{
    func_0202CAE4(((struct Obj00474 *)p)->f18, 0, 96, 29, 1);
    func_0202CF84(((struct Obj00474 *)p)->f18, 0);
    func_021F9260(p, 2);
    if (((struct Obj00474 *)p)->f5C == 1)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 1);
    else if (((struct Obj00474 *)p)->f5C == 0)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 0);
    func_021FB2F0((Menu *)p, 0, ((struct Obj00474 *)p)->f58);
    ((struct Obj00474 *)p)->f56 = 0;
    func_021FBF04(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f34, (*(void ***)p)[4], ((struct Obj00474 *)p)->f56, func_021F9EEC((u8 *)(((struct Obj00474 *)p)->f58), 4));
    func_021FBEB8(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(((struct Obj00474 *)p)->f18, 0, 32, 0);
    func_0204B878((struct Obj *)(((struct Obj00474 *)p)->f8), 6);
    ((struct Obj00474 *)p)->f7A = 0;
    *(int *)&((struct Obj00474 *)p)->f44 = 0;
    func_021F4FF4(((struct Obj00474 *)p)->f8, tbl_02203220[*(int *)(p + 68)].x, tbl_02203220[*(int *)(p + 68)].y);
    func_0202CC58(((struct Obj00474 *)p)->f18, 0);
    func_0202CD64(((struct Obj00474 *)p)->f18, 0, -4, 0, 4);
    *(int *)&((struct Obj00474 *)p)->f48 = 34;
}




void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g)
{
    func_022028C8((u8 *)win, 0, (u32)str, x, 0, 0, color, (u32)g);
    func_02045334((struct Descriptor *)win);
    func_0202CEBC((struct WinMgr *)mgr, 0, win);
}




int func_021FAC84(void)
{
    return -1;
}




/*
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 */
int func_021FAC8C(u8 *p)
{
    if (!func_0202CE40(*(struct WinMgr * *)&((struct Obj01745 *)p)->f18, 0)) {
        if (func_020355C4() == 1)
            func_0204B3DC(((struct Obj01745 *)p)->f8, 0);
        else
            func_0204B3DC(((struct Obj01745 *)p)->f8, 1);
        if (((struct Obj01745 *)p)->f54 == 2) {
            func_0204B92C(((struct Obj01745 *)p)->fC, 0);
            func_0204B92C(((struct Obj01745 *)p)->f10, 0);
            func_0204B878(((struct Obj01745 *)p)->fC, 38);
            func_0204B878(((struct Obj01745 *)p)->f10, 39);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->fC, 228, 120);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->f10, 154, 120);
            func_0204B3DC(((struct Obj01745 *)p)->fC, 1);
            func_0204B3DC(((struct Obj01745 *)p)->f10, 1);
        }
        ((struct Obj01745 *)p)->f48 = ((struct Obj01745 *)p)->f4C;
    }
    return -1;
}




/*
 * Flush the queued value when the probe reports empty, then answer -1.
 */
int func_021FAD08(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj09234 *)p)->f18, 0) == 0) {
        ((struct Obj09234 *)p)->f48 = ((struct Obj09234 *)p)->f4C;
    }
    return -1;
}




/*
 * trailing: two-byte zero alignment padding at 0x021FAD82.
 */
int func_021FAD24(u8 *p)
{
    if (func_0204B98C(((struct Obj03297 *)p)->f8)) return -1;
    func_0204B3DC(((struct Obj03297 *)p)->f8, 0);
    func_0204B3DC(((struct Obj03297 *)p)->fC, 0);
    func_0204B3DC(((struct Obj03297 *)p)->f10, 0);
    if (((struct Obj03297 *)p)->f54 == 3 && ((struct Obj03297 *)p)->f4C == 28)
        func_0202CD64(((struct Obj03297 *)p)->f18, 0, 6, 0, 6);
    else
        func_0202CD64(((struct Obj03297 *)p)->f18, 0, 4, 0, 4);
    ((struct Obj03297 *)p)->f48 = 4;
    return -1;
}




/*
 * Drain the queue then flush the shadowed value, always answering -1.
 */
int func_021FAD84(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0) == 0) {
        func_0202CC70(*(struct WinMgr * *)&((struct Obj07245 *)p)->f18, 0);
        ((struct Obj07245 *)p)->f48 = ((struct Obj07245 *)p)->f4C;
    }
    return -1;
}




int func_021FADA8(u8 *p)
{
    if (func_0204B98C(((struct Obj05414 *)p)->f8)) return -1;
    func_0204B3DC(((struct Obj05414 *)p)->f8, 0);
    func_0204B3DC(((struct Obj05414 *)p)->fC, 0);
    func_0204B3DC(((struct Obj05414 *)p)->f10, 0);
    func_0202CD64(((struct Obj05414 *)p)->f18, 0, 4, 0, 4);
    ((struct Obj05414 *)p)->f48 = 2;
    return -1;
}




void func_021FADF0(u8 *p) {func_021FA9C8(p,4,32);func_0204B878(((struct Obj05415 *)p)->f8,18);func_021F4FF4(*(u32 *)&((struct Obj05415 *)p)->f8,144,40);func_0202CD64(((struct Obj05415 *)p)->f18,0,-4,0,4);((struct Obj05415 *)p)->f48=1;((struct Obj05415 *)p)->f4C=7;((struct Obj05415 *)p)->f38=-1;}




int func_021FAE2C(u8 *p)
{
    u32 sel = func_021F9A88((Menu *)p, p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            func_0204B3DC(((struct Obj00246 *)p)->f8, 1);
            func_0204B878(((struct Obj00246 *)p)->f8, 19);
            ((struct Obj00246 *)p)->f48 = 8;
            ((struct Obj00246 *)p)->f38 = sel;
        }
    } else {
        func_0204B3DC(((struct Obj00246 *)p)->f8, 1);
        func_0204B878(((struct Obj00246 *)p)->f8, func_0204B898(((struct Obj00246 *)p)->f8) + 9);
        ((struct Obj00246 *)p)->f48 = 3;
        ((struct Obj00246 *)p)->f4C = 8;
        ((struct Obj00246 *)p)->f38 = -1;
    }
    return -1;
}




int func_021FAE8C(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8)) return -1;
    func_021F9660((Obj_021F9024 *)p, 4);
    func_0204B3DC(((struct Obj00098 *)p)->f8, 0);
    if (((struct Obj00098 *)p)->f38 >= 0) {
        if (tbl_022033FC[((struct Obj00098 *)p)->f38].count != 1)
            ((struct Obj00098 *)p)->f48 = 10;
        else {
            ((struct Obj00098 *)p)->f3A = 0;
            ((struct Obj00098 *)p)->f48 = 14;
        }
    } else return -2;
    return -1;
}




int func_021FAEE0(u8 *p)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    func_0202CAE4(((struct Obj01160 *)p)->f18, 0, 96, 28, 1);
    func_0202CF84(((struct Obj01160 *)p)->f18, 0);
    func_021F9260(p, 4);
    func_021FBEB8(((struct Obj01160 *)p)->f18, ((struct Obj01160 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_02082BCC(p + 96, 1, 26);
    g = p + 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(((struct Obj01160 *)p)->f20, i + 116);
        if (func_021FBFB0(p, i) == 1) {
            color = 0x3dc2;
            p[i + 96] = 1;
        } else {
            color = 0x2122;
            p[i + 96] = 0;
        }
        func_021FAC50(((struct Obj01160 *)p)->f18, (*(void ***)p)[i], str, 2, color, g);
        func_02045808(str);
    }
    func_0202CB4C(((struct Obj01160 *)p)->f18, 0, 16, 0);
    func_0202CC58(((struct Obj01160 *)p)->f18, 0);
    func_0204B878((struct Obj *)(((struct Obj01160 *)p)->f8), 18);
    func_021F4FF4(((struct Obj01160 *)p)->f8, (tbl_022032C6[*(s16 *)(p + 56)].x + 16) * 8, tbl_022032C6[*(s16 *)(p + 56)].y * 8);
    ((struct Obj01160 *)p)->f44 = ((struct Obj01160 *)p)->f38;
    func_0204B3DC((struct Obj *)((struct Obj01160 *)p)->f8, 1);
    ((struct Obj01160 *)p)->f48 = 7;
    if (func_020355C4() == 1)
        func_0204B3DC((struct Obj *)((struct Obj01160 *)p)->f8, 0);
    else
        func_0204B3DC((struct Obj *)((struct Obj01160 *)p)->f8, 1);
    return -1;
}




int func_021FAFF0(Menu *m)
{
    int i;
    u16 color;

    i = 1;
    func_0202CAE4(m->mgr, 0, 0x60, 0x1A, 1);
    func_0202CF84(m->mgr, 0);
    ov135_func_021F9260(m, 5);
    func_02082BCC(m->flags, 1, 0x1A);
    func_021FBE84(m->mgr, m->bank, m->wins[0], m->layout + 0x74, 2, 0x3DC2, m->g);
    for (i = 1; i < tbl_022033F8[m->layout].count + 1; i++) {
        if (func_021FBF6C(m, (int)tbl_02203324[m->layout] + i - 1) > 0) {
            color = 0x3DC2;
            m->flags[(int)tbl_02203324[m->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            m->flags[(int)tbl_02203324[m->layout] + i - 1] = 0;
        }
        func_021FBE84(m->mgr, m->bank, m->wins[i], tbl_02203440[i + tbl_022033F8[m->layout].first - 1], 5, color, m->g);
    }
    func_021FBEB8(m->mgr, m->bank, m->wins[14], 0x4A, m->g);
    func_0202CB4C(m->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)m->cursor, 4);
    if (m->start < 0) {
        m->pos = 0;
    } else {
        m->pos = m->start;
    }
    func_021F4FF4(m->cursor, (tbl_022032C6[m->pos].x + 0x10) * 8, tbl_022032C6[m->pos].y * 8);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)m->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)m->cursor, 1);
    }
    m->state = 0xB;
    return -1;
}




int func_021FB164(u8 *p)
{
    int r;
    r = func_021F9CDC((Menu *)p, (int)(p + 0x60));
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 12;
        ((struct Obj00194 *)p)->f3A = r;
        break;
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 12;
        ((struct Obj00194 *)p)->f3A = -1;
        break;
    }
    return -1;
}




int func_021FB1E4(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660((Obj_021F9024 *)p, 5);if(((struct Obj00098 *)p)->f3A>=0)*(u32 *)&((struct Obj00098 *)p)->f48=14;else *(u32 *)&((struct Obj00098 *)p)->f48=9;return -1; }




/*
 * State select before the notify call.
 */
int func_021FB220(u8 *p)
{
    u32 v;
    int n;

    if (func_020355C4() == 1) {
        v = ((struct Obj09235 *)p)->f8;
        n = 0;
    } else {
        v = ((struct Obj09235 *)p)->f8;
        n = 1;
    }
    func_0204B3DC((struct Obj *)v, n);
    ((struct Obj09235 *)p)->f48 = 0xa;
    return -1;
}



/*
 * Count the entries of a u16 table that the query accepts.
 */
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end)
{
    int i;
    int n = 0;

    for (i = start; i < end; i++) {
        if (func_0200D064((struct Blk37 *)item, list[i]) != 0) {
            n++;
        }
    }
    return n;
}



int func_021FB26C(Item **menu, void *msg, void *bank, u32 x, u32 kind, void *bag)
{
    u32 count;
    int start;
    int end;
    int n;
    int i;
    u16 *list;

    list = func_021F8498(0x48, 0, &count);
    func_021F84BC(kind, &start, &end);
    count = end - start;
    n = func_021FB240(x, (u32)bag, count, list, start, end);
    *menu = func_0201F81C(n + 1, 0x48);
    for (i = start; i < end; i++) {
        if (func_0200D064(bag, list[i]) != 0) {
            func_0201F878((struct Slot *)*menu, (u32)msg, list[i], list[i], 0x48);
        }
    }
    func_020307B0(list);
    return n;
}



void func_021FB2F0(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02043B5C(func_02045770(m->wins[i]), 0xA);
        if (i + page * 4 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 4 + i].str, 0, 0x3DC2, m->g);
        } else {
            func_02045334(m->wins[i]);
            func_0202CEBC(m->mgr, 0, m->wins[i]);
        }
    }
}



void func_021FB364(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_02043B5C(func_02045770(m->wins[i]), 0xA);
        if (i + page * 5 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 5 + i].str, 0, 0x3DC2, m->g);
        } else {
            func_02045334(m->wins[i]);
            func_0202CEBC(m->mgr, 0, m->wins[i]);
        }
    }
}



int func_021FB3D8(Menu *p)
{
    u8 pages;

    func_0202CAE4(p->mgr, 0, 0x60, 0x1D, 1);
    func_0202CF84(p->mgr, 0);
    func_021F9260(p, 0);
    p->total = func_021FB26C(&p->items, p->msg, p->bank, p->x2c, (int)tbl_02203324[p->layout] + p->start, p->bag);
    p->page = 0;
    func_021FB2F0((Menu *)p, 0, p->total);
    pages = func_021F9EEC((u8 *)p->total, 4);
    func_021FBF04(p->mgr, p->num, p->wins[4], p->page, pages);
    func_021FBEB8(p->mgr, p->bank, p->wins[14], 0x4A, p->g);
    func_0202CB4C(p->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)p->cursor, 6);
    p->pos = 0;
    func_021F4FF4(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    func_021F4FF4(p->up, 0xE4, 0x78);
    func_021F4FF4(p->down, 0x9A, 0x78);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)p->cursor, 1);
    }
    if (pages == 1) {
        func_0204B878((struct Obj *)p->up, 0x3D);
        func_0204B878((struct Obj *)p->down, 0x3E);
    } else {
        func_0204B878((struct Obj *)p->up, 0x26);
        func_0204B878((struct Obj *)p->down, 0x27);
    }
    func_0204B92C((struct Obj *)p->up, 0);
    func_0204B92C((struct Obj *)p->down, 0);
    func_0204B3DC((struct Obj *)p->up, 1);
    func_0204B3DC((struct Obj *)p->down, 1);
    p->state = 0xF;
    return -1;
}



int func_021FB510(u8 *p)
{
    int r;
    r = func_021F9FF0((Menu *)p);
    switch (r) {
    case -2:
        func_020061E4(0x551);
        func_0204B3DC((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02490 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 16;
        ((struct Obj02490 *)p)->f3C = -1;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj02490 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj02490 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj02490 *)p)->f8)) + 9);
        ((struct Obj02490 *)p)->f48 = 3;
        ((struct Obj02490 *)p)->f4C = 17;
        ((struct Obj02490 *)p)->f3C = r;
        break;
    }
    return -1;
}



/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0xd/0x9 code from the table.
 */
int func_021FB588(u8 *p)
{
    if (func_0204B98C((struct Actor *)(*(u32 *)&((struct Obj00098 *)p)->f8)) != 0) {
        return -1;
    }
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->fC, 0);
    func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f10, 0);
    func_021F9660((Obj_021F9024 *)p, 0x0);
    func_0201F868((void *)(*(u32 *)&((struct Obj00098 *)p)->f30));
    *(u32 *)&((struct Obj00098 *)p)->f48 = (*(s32 *)(g_022033FC + ((struct Obj00098 *)p)->f38 * 8) != 1) ? 0xd : 0x9;
    return -1;
}



int func_021FB5E4(u8 *p) { if(func_0204B98C(((struct Obj00098 *)p)->f8))return -1;func_0204B3DC(((struct Obj00098 *)p)->f8,0);func_021F9660((Obj_021F9024 *)p, 0);func_0201F868(((struct Obj00098 *)p)->f30);return ((struct Obj00098 *)p)->f3C; }



int func_021FB614(u8 *p)
{
    func_021FA9C8(p, 6, 0x20);
    func_0204B878((struct Obj *)(((struct Obj02858 *)p)->f8), 18);
    func_0202CD64(((struct Obj02858 *)p)->f18, 0, -4, 0, 4);
    ((struct Obj02858 *)p)->f48 = 1;
    ((struct Obj02858 *)p)->f4C = 19;
    ((struct Obj02858 *)p)->f44 = 10;
    ((struct Obj02858 *)p)->f38 = -1;
    func_021F4FF4(((struct Obj02858 *)p)->f8, (tbl_02203298[((struct Obj02858 *)p)->f44].x + 16) * 8, tbl_02203298[((struct Obj02858 *)p)->f44].y * 8);
    func_0204B878((struct Obj *)(((struct Obj02858 *)p)->f8), 6);
    return -1;
}



int func_021FB674(u8 *p)
{
    int r;
    r = func_021FA514((Menu *)p, p + 0x60);
    switch ((u32)r) {
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -1;
        break;
    case 10:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), func_0204B898((struct Obj *)(((struct Obj00195 *)p)->f8)) + 9);
        ((struct Obj00195 *)p)->f48 = 3;
        ((struct Obj00195 *)p)->f4C = 20;
        ((struct Obj00195 *)p)->f38 = -2;
        break;
    case -1: break;
    default:
        func_0204B3DC((struct Obj *)((struct Obj00195 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00195 *)p)->f8), 19);
        ((struct Obj00195 *)p)->f38 = r;
        ((struct Obj00195 *)p)->f48 = 20;
        break;
    }
    return -1;
}



int func_021FB704(u8 *p)
{
    if (func_0204B98C(((struct Obj00098 *)p)->f8) != 0) return -1;
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00098 *)p)->f8, 0);
    func_021F9660((Obj_021F9024 *)p, 6);
    if (((struct Obj00098 *)p)->f38 < 0) {
        if (((struct Obj00098 *)p)->f38 == -1) return -2;
        else if (((struct Obj00098 *)p)->f38 == -2) return 0;
    } else {
        if (tbl_022033FC[((struct Obj00098 *)p)->f38].count != 1) {
            ((struct Obj00098 *)p)->f48 = 22;
        } else {
            ((struct Obj00098 *)p)->f3A = 0;
            func_0202CD64(((struct Obj00098 *)p)->f18, 0, -4, 0, 3);
            if (((struct Obj00098 *)p)->f14 != 0) func_0204B3DC((struct Obj *)((struct Obj00098 *)p)->f14, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00098 *)p)->f8), 7);
            ((struct Obj00098 *)p)->f48 = 2;
            func_0202CAE4(((struct Obj00098 *)p)->f18, 0, 0x60, 0x18, 1);
            ((struct Obj00098 *)p)->f4C = 26;
        }
    }
    return -1;
}



int func_021FB7A0(u8 *p)
{
    func_021FA9C8(p, 6, 0x10);
    func_0204B878((struct Obj *)(((struct Obj02859 *)p)->f8), 18);
    func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f44 = ((struct Obj02859 *)p)->f38;
    func_021F4FF4(((struct Obj02859 *)p)->f8, (tbl_02203298[((struct Obj02859 *)p)->f44].x + 16) * 8, tbl_02203298[((struct Obj02859 *)p)->f44].y * 8);
    if (func_020355C4() == 1) func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 0);
    else func_0204B3DC((struct Obj *)((struct Obj02859 *)p)->f8, 1);
    ((struct Obj02859 *)p)->f48 = 19;
    return -1;
}
