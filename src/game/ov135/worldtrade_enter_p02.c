/*
 * file:     worldtrade_enter_p02.c
 * unit:     yes
 * function: func_021F8DA4, func_021F8DE4, func_021F8E58, func_021F8E88, func_021F8F5C, func_021F8F68, func_021F8F84, func_021F9024, func_021F9088, func_021F90A0, func_021F90B8, func_021F914C, func_021F91A0, func_021F91DC, func_021F9218, func_021F9254, func_021F9260, func_021F9660, func_021F9890, func_021F9968, func_021F99D0, func_021F99F0, func_021F9A1C, func_021F9A88, func_021F9CB0, func_021F9CDC, func_021F9EEC, func_021F9F00, func_021F9F58, func_021F9FF0, func_021FA15C, func_021FA2B0, func_021FA330, func_021FA394, func_021FA4FC, func_021FA514, func_021FA760
 * address:  0x021F8DA4
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
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02031348 0x02031348 arm
 *   func_0200F7B8 0x0200F7B8 thumb
 *   str_02203C34 0x02203C34 data a1
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   ov115_id 0x00000073 data
 *   func_021F8A74 0x021F8A74 thumb ov135
 *   func_021F8A80 0x021F8A80 thumb ov135
 *   func_021F8AB0 0x021F8AB0 thumb ov135
 *   func_021F8AF4 0x021F8AF4 thumb ov135
 *   func_021F8B0C 0x021F8B0C thumb ov135
 *   func_021F8BBC 0x021F8BBC thumb ov135
 *   func_021F8BE8 0x021F8BE8 thumb ov135
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
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
 *   func_021FB2F0  0x021FB2F0  thumb
 *   func_021FBF04  0x021FBF04  thumb
 *   tbl_02203220   0x02203220  data  a1
 *   tbl_0220320E  0x0220320E  data
 *   tbl_02203250  0x02203250  data  a4
 *   tbl_02203216   0x02203216  data  a1
 *   tbl_0220339C   0x0220339C  data  a1
 *   tbl_02203298   0x02203298  data  a1
 *   func_021FA7C4  0x021FA7C4  thumb
 */
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

struct Ctx;
struct MsgBank;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct WordSet;
struct WinMgr;
struct Obj_021F9024;
struct Menu;
struct Menu;
struct Menu;
#include "worldtrade_types.h"

typedef struct {
    void *save;
    int zero;
    int enabled;
    int pad[2];
    void (*callback)(void);
    void *context;
} Req;

struct Ov135Menu {
    u32 *win;
    u8 pad4[0x4c];
    u32 layer;
};

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

extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, u32, u32);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02031348(void *, u32, void *, void *);
extern u32 func_0200F7B8(u32 a0);
extern int func_021F8A74(void *a0);
extern int func_021F8A80(u8 *);
extern int func_021F8AB0(u8 **);
extern int func_021F8AF4(u8 *);
extern int func_021F8B0C(u8 *);
extern int func_021F8BBC(u8 *);
extern int func_021F8BE8(u8 *);
extern void func_021C8658();
extern void func_021F4FC4(u8 *p);
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
extern void func_0204B878(struct Obj_021F9024 *p, u16 value);
extern void func_0204B92C(struct Obj_021F9024 *p, u32 v);
extern void func_0204B3DC(struct Obj_021F9024 *p, unsigned int v);
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
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0209C0A4(u8 *p, u32 n, u32 m);
extern void func_021FB2F0(Menu *m, int page, int total);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern void func_021FA7C4(Menu *m, int dir);
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
void ov135_func_021F9260(struct Ov135Menu *p, u32 mode);
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
extern char str_02203C34[];
extern u8 tbl_021D654C[];
extern u8 ov115_id[];
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
    Req *r;
    *(Req * *)&((struct Obj04527 *)p)->f10DC = func_02030734(72, 28, 0, str_02203C34, 689);
    func_02082BCC(*(Req * *)&((struct Obj04527 *)p)->f10DC, 0, 28);
    r = *(Req * *)&((struct Obj04527 *)p)->f10DC;
    r->save = func_020120F4(((struct Obj23403 *)(*(u8 * *)&((struct Obj04527 *)p)->f0))->f40);
    r->zero = 0;
    r->enabled = 1;
    r->callback = (void (*)(void))func_021F8F5C;
    r->context = p;
    func_02031348(((struct Obj04527 *)p)->f12F0, (u32)ov115_id, tbl_021D654C, *(Req * *)&((struct Obj04527 *)p)->f10DC);
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
        result = func_021F8BE8(p);
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











void ov135_func_021F9260(struct Ov135Menu *p, u32 mode)
{
    int i;

    func_02040C14(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 9; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 5:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        p->win[0] = sub_020450F0((u8)p->layer, 2, 2, 3, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[0])), 7);
        for (i = 1; i < 4; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 0:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 4; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[4] = sub_020450F0((u8)p->layer, 5, 14, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[4])), 8);
        break;
    case 6:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 9; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[15] = sub_020450F0((u8)p->layer, 1, 2, 9, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[15])), 10);
        break;
    case 3:
        p->win[14] = sub_020450F0((u8)p->layer, 24, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 5; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[5] = sub_020450F0((u8)p->layer, 14, 16, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[5])), 10);
        break;
    case 1:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 3; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        break;
    case 2:
        p->win[14] = sub_020450F0((u8)p->layer, 9, 17, 6, 2, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[14])), 10);
        for (i = 0; i < 4; i++) {
            p->win[i] = sub_020450F0((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 10);
        }
        p->win[4] = sub_020450F0((u8)p->layer, 5, 14, 5, 1, 1, 1);
        sub_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[4])), 8);
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
    func_0204B878((struct Obj_021F9024 *)m->obj, 4);
    func_0204B92C((struct Obj_021F9024 *)m->obj, 1);
    func_0204B3DC((struct Obj_021F9024 *)m->obj, 0);
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
        func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 1);
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
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        } else {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0x12);
        }
    }
    ret = -1;
    r = func_021F9A1C(p, 4);
    if (r != ret) {
        func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
        if (r == 9) {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        } else {
            p->pos = r;
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0x12);
        }
        if (r == 9) {
            func_020061E4(0x551);
            ret = -2;
        } else if (enable == 0 || enable[r] != 0) {
            func_020061E4(0x54C);
            ret = r;
        }
        if (ret == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0);
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
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
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
        func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 1);
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
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        } else {
            func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 4);
        }
    }
    r = func_021F9A1C(p, 5);
    if (r != -1) {
        if (r == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        } else {
            p->pos = r;
            func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 4);
        }
        r = func_021F9CB0((Menu *)p, r);
        if (r == -2) {
            func_020061E4(0x551);
        } else if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            func_020061E4(0x54C);
        } else {
            r = -1;
            if (func_020355C4() == 0) {
                func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0);
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
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
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
        func_0204B92C((struct Obj_021F9024 *)((struct Menu *)m->down), 1);
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->down), 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = last;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj_021F9024 *)((struct Menu *)m->up), 1);
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->up), 0x26);
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
        func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)m->cursor), 1);
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
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 5);
        } else {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 6);
        }
    }
    r = func_021F9A1C(m, 0);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203220[r].x, tbl_02203220[r].y);
            if (r == 4) {
                func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 5);
            } else {
                m->pos = r;
                func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 6);
            }
        }
        r = func_021F9F00((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)m->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021F9F00((Menu *)m, m->pos);
    }
    if (func_020362DC() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 5);
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
        func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 1);
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
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        } else {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 6);
        }
    }
    r = func_021F9A1C(p, 1);
    if (r != -1) {
        func_020355D8(1);
        func_021F4FF4(p->cursor, tbl_0220320E[r].x, tbl_0220320E[r].y);
        if (r == 3) {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        } else {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 6);
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
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
        return -2;
    }
    return -1;
}





void func_021FA2B0(Menu *m, int dir)
{
    if (dir < 0) {
        func_020061E4(0x548);
        func_0204B92C((struct Obj_021F9024 *)((struct Menu *)m->down), 1);
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->down), 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = 2;
        }
    } else {
        func_020061E4(0x548);
        func_0204B92C((struct Obj_021F9024 *)((struct Menu *)m->up), 1);
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->up), 0x26);
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
        func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)m->cursor), 1);
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
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 5);
        } else {
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 6);
        }
    }
    r = func_021F9A1C(m, 2);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203216[r].x, tbl_02203216[r].y);
            if (r == 4) {
                func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 5);
            } else {
                m->pos = r;
                func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 6);
            }
        }
        r = func_021FA330((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)m->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (func_020362DC() & 1) {
        return func_021FA330((Menu *)m, m->pos);
    }
    if (func_020362DC() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)m->cursor), 5);
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
        func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 1);
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
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
            break;
        case 10:
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 6);
            break;
        default:
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0x12);
            break;
        }
    }
    r = func_021F9A1C(p, 6);
    if (r != -1) {
        func_021F4FF4(p->cursor, (tbl_02203298[r].x + 0x10) * 8, tbl_02203298[r].y * 8);
        switch (r) {
        case 9:
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
            break;
        case 10:
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 6);
            break;
        default:
            func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0x12);
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
            func_0204B3DC((struct Obj_021F9024 *)((struct Menu *)p->cursor), 0);
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
        func_0204B878((struct Obj_021F9024 *)((struct Menu *)p->cursor), 5);
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
