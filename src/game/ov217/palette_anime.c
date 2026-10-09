/*
 * file:     palette_anime.c
 * unit:     yes
 * function: func_021C0EF4, func_021C0F48, func_021C0F5C, func_021C0F78, func_021C0FF8, func_021C1038, func_021C1090, func_021C10C8, func_021C10D8, func_021C10E8, func_021C1124, func_021C112C, func_021C1154, func_021C1160, func_021C116C, func_021C1178, func_021C1184, func_021C118C, func_021C1194, func_021C11A4, func_021C11C8, func_021C11D0, func_021C11DC, func_021C11E8, func_021C11F4, func_021C11FC, func_021C1224, func_021C124C, func_021C13E8, func_021C14DC, func_021C15B8, func_021C1610, func_021C1628, func_021C1638, func_021C1648, func_021C1658, func_021C1670, func_021C1680, func_021C16C4, func_021C16DC, func_021C16E8, func_021C16FC, func_021C1704, func_021C1720, func_021C17C4, func_021C1850, func_021C18C4, func_021C18F8, func_021C1A58, func_021C1A5C, func_021C1A64, func_021C1A84, func_021C1AB4, func_021C1AC0, func_021C1AD4, func_021C1AFC, func_021C1B28, func_021C1B4C, func_021C1B60, func_021C1B74, func_021C1D24, func_021C1D28, func_021C1D64, func_021C1D74, func_021C1D7C, func_021C1DBC, func_021C1DE8, func_021C1DF0, func_021C1E00, func_021C1E0C, func_021C1F44, func_021C2070, func_021C209C, func_021C20B4, func_021C20C4, func_021C20CC, func_021C20D8, func_021C20EC, func_021C2118, func_021C211C, func_021C2188, func_021C218C, func_021C2194, func_021C21C4, func_021C2250, func_021C2260, func_021C2288, func_021C253C, func_021C2550, func_021C256C, func_021C25A8, func_021C25B0, func_021C25C4, func_021C25D0, func_021C2614, func_021C2630, func_021C2644, func_021C2654, func_021C2664, func_021C2674, func_021C2684, func_021C26AC, func_021C26E8, func_021C270C, func_021C271C, func_021C272C, func_021C2740, func_021C2748, func_021C278C, func_021C2888, func_021C288C, func_021C2894, func_021C28A4, func_021C28BC, func_021C28CC, func_021C28DC, func_021C28EC, func_021C28FC, func_021C2914, func_021C291C, func_021C2934, func_021C2950, func_021C2958, func_021C295C, func_021C299C, func_021C29B4, func_021C29C8, func_021C29D8, func_021C29E8, func_021C29F0, func_021C29F8, func_021C2A00, func_021C2A08, func_021C2A10, func_021C2A18, func_021C2A28, func_021C2A30, func_021C2AA0, func_021C2B10, func_021C2B80, func_021C2BF0, func_021C2C30, func_021C2C70, func_021C2CB0, func_021C2CF0, func_021C2D28, func_021C2D68, func_021C2D88, func_021C2D9C, func_021C2DA0, func_021C2DC4, func_021C2DCC, func_021C2DE0
 * address:  0x021C0EF4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020450F0 0x020450F0 arm
 *   d_021C4058 0x021C4058 data a1
 *   d_021C4064 0x021C4064 data a1
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045798 0x02045798 arm
 *   func_02045758 0x02045758 arm
 *   func_02045760 0x02045760 arm
 *   func_02045748 0x02045748 arm
 *   func_02045750 0x02045750 arm
 *   func_020413B0 0x020413B0 arm
 *   _fflt  0x0209BDBC  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 *   func_02045738  0x02045738  arm
 *   func_0201D304  0x0201D304  thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_02148D8C  0x02148D8C  data  a4
 *   d_02148D98  0x02148D98  data  a4
 *   d_02148DA4  0x02148DA4  data  a4
 *   d_02148B98  0x02148B98  data  a4
 *   d_02148BCC  0x02148BCC  data  a4
 *   d_02148B54  0x02148B54  data  a4
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_0207D760  0x0207D760  arm
 *   func_0206A700  0x0206A700  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_0207C554  0x0207C554  arm
 *   func_0206A854  0x0206A854  arm
 *   func_021C0E64  0x021C0E64  thumb  ov217
 *   func_021C0E4C  0x021C0E4C  thumb  ov217
 *   func_021C0E54  0x021C0E54  thumb  ov217
 *   func_021C0E5C  0x021C0E5C  thumb  ov217
 *   func_0207CA30 0x0207CA30 arm
 *   _ffltu  0x0209BE04  arm
 *   _ffixu  0x0209C4C8  arm
 *   _fsub 0x0209CB8C arm
 *   _fadd 0x0209C95C arm
 *   _fdiv 0x0209CE10 arm
 *   _fgr 0x0209BBB0 arm
 *   _f2d 0x0209BD38 arm
 *   _d2f 0x0209B64C arm
 *   cos 0x0209A390 arm
 *   sin 0x0209AA08 arm
 *   func_021C0E08  0x021C0E08  thumb  ov217
 *   func_021C0E3C  0x021C0E3C  thumb  ov217
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B9C4 0x0204B9C4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 *   func_0204B95C 0x0204B95C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   func_021C2E20  0x021C2E20  thumb  ov217
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02021F64 0x02021F64 thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021C408C 0x021C408C data ov217 a1
 */
#include "../../matched/include/Obj26004.h"
#include "../../matched/include/Obj26005.h"
#include "../../matched/include/Obj06716.h"
#include "../../matched/include/Obj03954.h"
#include "../../matched/include/Obj14757.h"
#include "../../matched/include/Obj26006.h"
#include "../../matched/include/Obj14758.h"
#include "../../matched/include/G_Glb.h"
#include "../../matched/include/Obj04640.h"
#include "../../matched/include/Obj26010.h"
#include "../../matched/include/Obj04641.h"
#include "../../matched/include/Obj26011.h"
#include "../../matched/include/Obj00554.h"
#include "../../matched/include/Obj03955.h"
#include "../../matched/include/Obj14759.h"
#include "../../matched/include/Obj03377.h"
#include "../../matched/include/Obj03956.h"
#include "../../matched/include/Obj26017.h"
#include "../../matched/include/Obj02555.h"
#include "../../matched/include/Obj14762.h"
#include "../../matched/include/Obj06717.h"
#include "../../matched/include/Obj06718.h"
#include "../../matched/include/Obj14763.h"
#include "../../matched/include/Obj26020.h"
#include "../../matched/include/Obj06719.h"
#include "../../matched/include/Obj06720.h"
#include "../../matched/include/Obj26021.h"
#include "../../matched/include/Obj04642.h"
#include "../../matched/include/Obj03378.h"
#include "../../matched/include/Obj04643.h"
#include "../../matched/include/Obj26022.h"
#include "../../matched/include/Obj08444.h"
#include "../../matched/include/Obj08445.h"
#include "../../matched/include/Obj03957.h"
#include "../../matched/include/Obj03958.h"
#include "../../matched/include/Obj26023.h"
#include "../../matched/include/Obj26024.h"
#include "../../matched/include/Obj26025.h"
#include "../../matched/include/Obj26026.h"
#include "../../matched/include/Obj10967.h"
#include "../../matched/include/Obj26033.h"
#include "../../matched/include/Obj08446.h"
#include "../../matched/include/Obj14767.h"
#include "../../matched/include/Obj08447.h"
#include "../../matched/include/Obj26035.h"
#include "../../matched/include/Obj00115.h"
#include "../../matched/include/Obj00115.h"
#include "../../matched/include/Obj10968.h"
#include "../../matched/include/Obj26037.h"
#include "../../matched/include/Obj14768.h"
#include "../../matched/include/Obj06721.h"

#define FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))
#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct Cfg;
struct CharBuf;
struct StrObj;
struct Big;
struct Pos_021C0EF4;
struct Ring;
struct Obj;
struct Actor;
struct Bank;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Config { u8 a,b,c,d,e,f,g,h; u32 i,j; };

struct Record { struct Config config; u32 a,b,handle,active; };

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef short s16_021C11A4;

struct Pos_021C0EF4 {
    s16_021C11A4 a;
    s16_021C11A4 b;
    s16_021C11A4 c;
};

typedef signed short   s16_021C11D0;

typedef signed short   s16_021C11DC;

typedef signed short   s16_021C11E8;

typedef signed short   s16_021C11FC;

typedef signed short   s16_021C1224;

typedef signed short s16_021C124C;

typedef enum { GX_POLYGONMODE_MODULATE=0 } GXPolygonMode;

typedef enum { GX_CULL_NONE=3 } GXCull;

typedef enum { GX_BEGIN_TRIANGLES=0 } GXBegin;

typedef short s16_021C13E8;

struct Ent { s16_021C13E8 x, y, z; };

struct Cam {
    u8 cnt;
    u8 pad1[7];
    s16_021C13E8 x, y, z;
    struct Ent t[4];
};

struct Big { u8 pad[0x1AC]; struct Cam c; };

typedef struct { int x, y, z; } V;

typedef struct { u32 w0,w4,type,wc,counter; } Rec_021C0EF4;

typedef signed short   s16_021C1610;

typedef signed short   s16_021C1628;

typedef struct {
    u32 w0;
    u32 w4;
    u32 type;
    u32 wc;
    u32 counter;
} Rec_021C1638;

typedef signed short   s16_021C16E8;

typedef signed short   s16_021C1704;

typedef signed short   s16_021C1720;

typedef struct {
    u32 f0;
    u32 f1;
    u32 f2;
    u32 f3;
    u32 f4;
} Rec_021C17C4;

struct Ent_021C18C4 {
    u8 pad0[8];
    u8 len;
    u8 start;
    u8 end;
    u8 pad1[9];
};

typedef signed short s16_021C18F8;

enum Counter { ZERO=0 };

struct Range_021C0EF4 {u8 max,min;u16 x,y,z;};

typedef struct {
    u32 w;
    u32 a;
} Rec_021C1A58;

typedef struct {
    u32 w[5];
    u32 flag;
    u32 value;
} Rec_021C1A5C;

typedef short s16_021C1A64;

struct Pos_021C16C4 { s16_021C1A64 x; s16_021C1A64 y; s16_021C1A64 z; };

struct Ent_021C1A84 {
    u8 pad0[0x1C];
};

typedef signed short   s16_021C1AC0;

struct Range_021C1B4C { u8 max, min; };

typedef struct {
    u32 a;
    u32 b;
    u32 type;
} Rec_v0EF4;

typedef struct {
    u32 w[3];
    u32 a;
} Rec_v1DBC;

typedef float f32;

typedef double f64;

typedef struct { s32 x; s32 y; s32 z; } VecFx32;

struct Vec2 { short x,y; };

struct Arg { u16 a,b,c; u8 d,e; };

struct arg_021C295C {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};

typedef struct {
    u32 w[5];
} Blk20;

typedef struct {
    u32 w[8];
} Rec_021C295C;

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 wc;
    u32 w10;
    u32 w14;
    u32 kind;
} Rec_021C2A10;

struct Rgb555_021C0EF4 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

struct Rgb555_021C2BF0 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

struct Rgb555_021C2C30 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

struct Rgb555_021C2C70 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};

struct Rgb555 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *w, s16 x, s16 y, void *text, void *font, u16 color);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);
extern void func_020456F8(struct Descriptor *);
extern void func_02045798(struct Descriptor *,u8);
extern u8 func_02045758(struct Descriptor *);
extern u8 func_02045760(struct Descriptor *);
extern u8 func_02045748(struct Descriptor *);
extern u8 func_02045750(struct Descriptor *);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0207D7C4(V *a, V *b, V *c, int d, int e);
extern void func_0207D760(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern void func_0206A700(void);
extern void func_0207BCA0(V *a, V *b, V *c, V *d);
extern void func_0207C554(int a, int b, int c, int d, int e, int f, int g, V *h);
extern void func_0206A854(void);
extern u32 func_021C0E64();
extern void func_021C0E4C(u32, u32);
extern u32 func_021C0E54(struct Ring *r);
extern u32 func_021C0E5C();
extern void func_0207CA30(const s16_021C18F8 *,const s16_021C18F8 *,s16_021C18F8 *);
extern double cos(double);
extern double sin(double);
extern int func_021C0E08(int a0, int a1);
extern void func_021C0E3C(void *p);
extern void func_0206DF3C(const VecFx32 *pos, s32 *px, s32 *py);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B8C4(struct Obj *,u32);
extern void func_0204B9C4(struct Actor *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B954(struct Actor *,u32);
extern void func_0204B95C(struct Actor *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B974(struct Actor *a);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3B4(struct Obj *p);
extern int _s32_div_f(int, int);
extern void func_021C2E20(char *p);
extern void func_02021F64(u16 *,u16 *,u32,int,u16);
extern u32 func_0209C2B0(u32 a, u32 b);
extern int func_02082D44(int, int, int);
extern void func_02082BCC(void *, int, int);
struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap);
void func_021C0F48(u8 *p);
u32 func_021C0F5C(u32 a0, u32 a1);
void func_021C0F78(u8 *p, struct U16Vec *text);
void func_021C0FF8(u8 *p,int visible);
void func_021C1038(u8 *p,u8 palette);
int func_021C1090(u8 *p, void *a1);
u8 *func_021C10C8(u32 heap);
u32 func_021C10D8(void *a0);
void func_021C10E8(u8 *p, u8 *tab, int n);
void func_021C1124(u8 *p);
void func_021C112C(u8 *p);
void func_021C1154(u8 *h);
void func_021C1160(u8 *h);
void func_021C116C(u8 *h);
void func_021C1178(u8 *h);
void func_021C1184(u8 *h, u32 v);
void func_021C118C(u8 *h, u32 v);
void func_021C1194(u8 *p, struct Pos_021C0EF4 *v);
void func_021C11A4(u8 *p, int a1);
u8 func_021C11C8(u8 *p, u8 key);
u8 func_021C11D0(u8 *p, u8 n);
u8 func_021C11DC(u8 *p, u8 key);
u8 func_021C11E8(u8 *p, u8 n);
int func_021C11F4(u8 *p);
void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py);
void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py);
void func_021C124C(u8 *p);
void func_021C13E8(struct Big *p);
void func_021C14DC(u8 *p);
void func_021C15B8(u8 *p);
void func_021C1610(u32 a0);
void func_021C1628(u8 *a0);
void func_021C1638(u8 *a0);
void func_021C1648(u8 *a0);
void func_021C1658(u32 a0);
void func_021C1670(u8 *a0);
void func_021C1680(Rec_021C1638 *p);
void func_021C16C4(void *p);
void func_021C16DC(u32 *p, u32 a1);
void func_021C16E8(u32 a0);
void *func_021C16FC(void *p, u32 v);
u32 func_021C1704(void *a0);
void func_021C1720(u8 *a0, u8 *a1);
void func_021C17C4(u8 *p);
void func_021C1850(u8 *p);
void func_021C18C4(u8 *p);
void func_021C18F8(u8 *p);
void func_021C1A58(Rec_021C1A58 *p, u32 v);
void func_021C1A5C(Rec_021C1A5C *p, u32 v);
void func_021C1A64(u8 *p, const struct Pos_021C16C4 *v);
u8 func_021C1A84(u8 *p, u8 key);
void *func_021C1AB4(void *p, u32 n);
void *func_021C1AC0(u8 *p, u8 key);
int func_021C1AD4(u8 *p);
int func_021C1AFC(u8 *p);
void func_021C1B28(u8 *p, u8 *a, u8 *b);
u16 func_021C1B4C(void *p);
u16 func_021C1B60(void *p);
void func_021C1B74(u8 *p, u8 *rec, s16 *out);
u32 func_021C1D24(void *p);
s32 func_021C1D28(Rec_v0EF4 *p);
void func_021C1D64(u8 *p);
void func_021C1D74(u32 a0);
void func_021C1D7C(unsigned char *p, u32 a);
u8 *func_021C1DBC(u32 heap);
u32 func_021C1DE8(void *a0);
void func_021C1DF0(char *p);
void func_021C1E00(Rec_v1DBC *p);
void func_021C1E0C(u8 *p);
void func_021C1F44(const s16 *p, s32 *px, s32 *py);
u32 func_021C2070(u32 a0, u32 a1);
u32 func_021C209C(void *a0);
void func_021C20B4(int a0, int a1, int a2, int a3, int a4);
void func_021C20C4(void *p);
void func_021C20CC(u32 a0);
void func_021C20D8(void *p);
void func_021C20EC(void *p);
void func_021C2118(void *p);
void func_021C211C(void *p);
void func_021C2188(void *p);
void func_021C218C(void *p, u32 v);
u32 func_021C2194(void *p);
void func_021C21C4(u8 *p,int index);
void func_021C2250(u32 a0, u32 a1);
void func_021C2260(void *p);
void func_021C2288(u8 *p, int a, int b, int c, int d);
void func_021C253C(void *p, u8 a, u8 b, u32 c, u32 d);
u32 func_021C2550(u32 a0);
void func_021C256C(void *p, u32 v);
u32 func_021C25A8(void *a0);
void func_021C25B0(u8 *p);
void func_021C25C4(u8 *a0);
void func_021C25D0(u8 *p);
void func_021C2614(char *p);
void func_021C2630(char *p, char *q);
u32 func_021C2644(void *p, u32 i, u8 j);
u32 func_021C2654(void *p, u32 i, u32 j);
u32 func_021C2664(void *p, u32 i, u32 j);
u32 func_021C2674(void *p, u32 i, u32 j);
u32 func_021C2684(void *p, u32 v);
u32 func_021C26AC(const u8 *p, u8 unused, u8 key);
u32 func_021C26E8(u32 a0, u32 a1, u32 a2);
u32 func_021C270C(void *a0);
void func_021C271C(u32 a0, u32 a1, u32 a2);
void func_021C272C(u32 a0, u32 a1);
void func_021C2740(unsigned int a0, unsigned int a1);
void func_021C2748(u32 a0, u32 a1);
void func_021C278C(u8 *p);
void func_021C2888(void *p, u8 v);
void func_021C288C(void *p, u32 a, u32 b);
u8 func_021C2894(char *p);
u8 func_021C28A4(char *p);
u8 func_021C28BC(char *p);
void func_021C28CC(const u32 *p, u16 *a, u16 *b);
void func_021C28DC(const u32 *p, u16 *a, u16 *b);
void func_021C28EC(const u32 *p, u16 *a, u16 *b);
u32 func_021C28FC(u32 a0);
u32 func_021C2914(void *a0);
void func_021C291C(char *p, u32 v);
void func_021C2934(u32 a0, u32 a1, u32 a2);
void func_021C2950(u32 a0);
void func_021C2958(void *p, u32 v);
void func_021C295C(unsigned char *p);
void func_021C299C(int *p);
void func_021C29B4(void *p, const void *src);
u32 func_021C29C8(u32 a0);
u32 func_021C29D8(void *a0);
void func_021C29E8(void *p, u32 b, u32 c, u32 d);
void func_021C29F0(Rec_021C295C *p);
void func_021C29F8(u8 *p, u32 b, u16 c);
void func_021C2A00(u32 a0);
int func_021C2A08(char *p);
void func_021C2A10(u32 a0, u32 a1);
void func_021C2A18(u8 *p, u32 b, u16 c);
void func_021C2A28(void *p);
void func_021C2A30(Rec_021C2A10 *p);
void func_021C2AA0(u8 *p);
void func_021C2B10(u8 *p);
void func_021C2B80(u8 *p);
void func_021C2BF0(u8 *p);
void func_021C2C30(u8 *p);
void func_021C2C70(char *p);
void func_021C2CB0(char *p);
void func_021C2CF0(void *p);
void func_021C2D28(char *p);
void func_021C2D68(void *p);
int func_021C2D88(char *p);
u32 func_021C2D9C(u32 *p);
u32 func_021C2DA0(u32 a0);
u32 func_021C2DC4(void *a0);
void func_021C2DCC(char *p);
void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count);
extern const char d_021C4058[];
extern const char d_021C4064[];
extern V d_02148D8C;
extern V d_02148D98;
extern V d_02148DA4;
extern V d_02148B98;
extern struct Glb d_02148BCC;
extern V d_02148B54;
extern const short d_020A1B38[];
extern char d_021C408C[];















struct Record *func_021C0EF4(const struct Config *config, u32 a, u32 b, u32 heap)
{
    struct Record *p = func_02030734(heap,32,0,d_021C4058,55);
    p->config = *config;
    p->a=a;
    p->b=b;
    p->handle=func_020450F0(config->a,config->b,config->c,config->d,config->e,config->h,0);
    p->active=1;
    return p;
}















/*
 * Two-call wrapper: field +0x18, then the object itself.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0F48(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj26004 *)p)->f18));
    func_020307B0(p);
}















/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0F5C(u32 a0, u32 a1)
{
    u32 v1 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj26005 *)(((u8*)a0)))->f14), a1);
    func_021C0F78((u8 *)a0, (void *)v1);
    return func_020307B0((void *)v1);
}
















/*
 * y = p[6] written in both arms of the x if/else: the join value has no known range, so the s16 argument is sign-extended (lsls/asrs) as in the original.
 */
void func_021C0F78(u8 *p, struct U16Vec *text)
{
    u16 color;
    void *w;
    int x;
    int y;
    void *font;
    void *obj;
    color = ((p[8] & 31) << 10) | ((p[9] & 31) << 5) | (p[10] & 31);
    w = func_02045770(*(void **)(p + 0x18));
    func_02043B5C(w, p[10]);
    if (*(int *)(p + 0xC) != 0) {
        x = p[5] + func_021C1090(p, text);
        y = p[6];
    } else {
        x = p[5];
        y = p[6];
    }
    font = *(void **)(p + 0x10);
    func_0201C7D0(w, x, y, text, font, color);
    if (*(int *)(p + 0x1C) != 0) {
        obj = *(void **)(p + 0x18);
        func_02045334(obj);
        func_02045374(obj);
        func_02041B6C(func_02045730(obj));
    }
}















/*
 * tail: two zero padding bytes at 0x021C1036, not a follower.
 */
void func_021C0FF8(u8 *p,int visible)
{
    if (((struct Obj06716 *)p)->f1C==0 && visible!=0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        func_02045334(d);
        func_02045374((struct Cfg *)d);
        func_02041B6C(func_02045730(d));
    } else if (((struct Obj06716 *)p)->f1C!=0 && visible==0) {
        struct Descriptor *d=*(struct Descriptor * *)&((struct Obj06716 *)p)->f18;
        func_020456F8(d);
        func_02041B6C(func_02045730(d));
    }
    ((struct Obj06716 *)p)->f1C=visible;
}















void func_021C1038(u8 *p,u8 palette)
{
    u32 layer;
    u8 x,y,width,height;
    func_02045798(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18,palette);
    layer=func_02045730(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    x=func_02045758(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    y=func_02045760(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    width=func_02045748(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    height=func_02045750(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18);
    func_020413B0(layer,x,y,width,height,palette);
    if (((struct Obj03954 *)p)->f1C!=0) func_02041B6C(func_02045730(*(struct Descriptor * *)&((struct Obj03954 *)p)->f18));
}
















/*
 * Addresses are Black-image addresses.
 */
int func_021C1090(u8 *p, void *a1)
{
    int r;
    int x;
    x = func_02045738((struct Descriptor *)(((struct Obj14757 *)p)->f18)) * 8;
    x = x - func_0201D304((struct StrObj *)a1, ((struct Obj14757 *)p)->f10, 0);
    r = (int)(0.5f * (float)x);
    if (r < 0) {
        r = 0;
    }
    return r;
}















u8 *func_021C10C8(u32 heap)
{
    u8 *p = func_021C1DBC(heap);
    func_021C1D64(p);
    return p;
}















u32 func_021C10D8(void *a0)
{
    func_021C1D74((u32)a0);
    return func_021C1DE8(a0);
}
















void func_021C10E8(u8 *p, u8 *tab, int n)
{
    int i;
    func_021C1704((void *)p);
    for (i = 0; i < n; i++)
        func_021C1720(p, tab + i * 16);
    func_021C17C4(p);
    func_021C1850(p);
    func_021C18C4(p);
    func_021C18F8(p);
}
















/*
 * Tail-call veneer: branch to func_021C15B8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1124(u8 *p)
{
    func_021C15B8(p);
}















/*
 * When func_021C1D24() reports 1 and the +8 field is set, runs the
 * +0x3C update triplet.
 *
 * Addresses are Black-image addresses.
 */
void func_021C112C(u8 *p)
{
    if (func_021C1D24(p) == 1) {
    if (((struct Obj26006 *)p)->f8 != 0) {
    func_021C14DC(p);
    func_021C124C(p);
    func_021C13E8((struct Big *)p);
    }
    }
}
















void func_021C1154(u8 *h)
{
    func_021C16DC((u32 *)h, 1);
}
















/*
 * Tail-call veneer: forwards arg(s) a0, 2 to func_021C16DC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1160(u8 *h)
{
    func_021C16DC((u32 *)h, 2);
}
















/*
 * Tail-call veneer: forwards arg(s) a0, 3 to func_021C16DC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C116C(u8 *h)
{
    func_021C16DC((u32 *)h, 3);
}
















/*
 * Tail-call veneer: forwards arg(s) a0, 5 to func_021C16DC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1178(u8 *h)
{
    func_021C16DC((u32 *)h, 5);
}
















void func_021C1184(u8 *h, u32 v)
{
    func_021C1A58((Rec_021C1A58 *)h, v);
}
















/*
 * Tail-call veneer: branch to func_021C1A5C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C118C(u8 *h, u32 v)
{
    func_021C1A5C((Rec_021C1A5C *)h, v);
}















void func_021C1194(u8 *p, struct Pos_021C0EF4 *v)
{
    func_021C1A64(p, (const struct Pos_021C16C4 *)v);
    func_021C18F8(p);
}
















void func_021C11A4(u8 *p, int a1)
{
    struct Pos_021C0EF4 v;
    s16_021C11A4 y = ((struct Obj14758 *)p)->f1B6;
    s16_021C11A4 x = ((struct Obj14758 *)p)->f1B4;
    v.a = x;
    v.b = y;
    v.c = a1;
    func_021C1194(p, (struct Pos_021C0EF4 *)&v);
}
















/*
 * Tail-call veneer: branch to func_021C1A84.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021C11C8(u8 *p, u8 key)
{
    return func_021C1A84(p, key);
}
















/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021C11D0(u8 *p, u8 n)
{
    return *(u8 *)func_021C1AB4(p, n);
}
















u8 func_021C11DC(u8 *p, u8 key)
{
    return *((u8 *)func_021C1AC0(p, key) + 8);
}
















u8 func_021C11E8(u8 *p, u8 n)
{
    return *((u8 *)func_021C1AB4(p, n) + 8);
}
















/*
 * Tail-call veneer: branch to func_021C1D28.
 *
 * Addresses are Black-image addresses.
 */
int func_021C11F4(u8 *p)
{
    return func_021C1D28((Rec_v0EF4 *)p);
}
















void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py)
{
    s16_021C11FC s[4];
    func_021C1B74(h, func_021C1AC0(h, key), (s16 *)s);
    func_021C1F44(s, px, py);
}
















void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py)
{
    s16_021C1224 s[4];
    func_021C1B74(h, func_021C1AB4(h, n), (s16 *)s);
    func_021C1F44(s, px, py);
}















static inline void G3_PolygonAttr(int light,GXPolygonMode mode,GXCull cull,int id,int alpha,int misc)
{
    *(volatile u32 *)0x040004a4=light|(mode<<4)|(cull<<6)|(id<<24)|(alpha<<16)|misc;
}















static inline void G3_Begin(GXBegin primitive) { *(volatile u32 *)0x04000500=primitive; }















static inline void G3_Color(u16 rgb) { *(volatile u32 *)0x04000480=rgb; }















static inline void G3_Vtx(s16_021C124C x,s16_021C124C y,s16_021C124C z)
{
    *(volatile u32 *)0x0400048c=(u32)(u16)x|((u32)(u16)y<<16);
    *(volatile u32 *)0x0400048c=(u32)(u16)z;
}















static inline void G3_End(void) { *(volatile u32 *)0x04000504=0; }















void func_021C124C(u8 *p)
{
    int n,i,index;
    u32 rest=(u32)p;
    switch(*(u32 *)(p+8)) {
    case 0: n=0; break;
    case 1: n=*(u32 *)(p+16)*100/120; rest=100-n; break;
    case 2: n=*(u32 *)(p+16)*100/30; rest=100-n; break;
    case 3: n=(20-*(u32 *)(p+16))*100/20; rest=100-n; break;
    case 4: n=100; rest=0; break;
    case 5: n=*(u32 *)(p+16)*100/60; rest=100-n; break;
    }
    index=rest*3;
    for(i=0;i<n;i++) {
        G3_PolygonAttr(0,GX_POLYGONMODE_MODULATE,GX_CULL_NONE,p[index*10+0x41a],31,0);
        G3_Begin(GX_BEGIN_TRIANGLES);
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16_021C124C *)(p+index*10+0x412),*(s16_021C124C *)(p+index*10+0x414),*(s16_021C124C *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16_021C124C *)(p+index*10+0x412),*(s16_021C124C *)(p+index*10+0x414),*(s16_021C124C *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_Color(*(u16 *)(p+index*10+0x418));
        G3_Vtx(*(s16_021C124C *)(p+index*10+0x412),*(s16_021C124C *)(p+index*10+0x414),*(s16_021C124C *)(p+index*10+0x416));
        index=(index+1)%300;
        G3_End();
    }
}















/*
 * GX FIFO line draw: for each entry with state >= 3, a degenerate triangle from the
 * centre (c.x, c.y) to the centre plus vertex t[min]. Closed 2026-10-05 (wD9r lane52):
 * the vertex is indexed as a struct array p->c.t[b[1]] (not a p + k*6 base pointer),
 * the vertex words are packed x first ((u16)x | (u16)y << 16, the GX_FX16PAIR order),
 * and i is declared before n (spill slots n@0, i@4).
 *
 * Addresses are Black-image addresses.
 */
void func_021C13E8(struct Big *p)
{
    u8 b[2];
    u8 *e;
    int i;
    int n;

    if (func_021C1D28((Rec_v0EF4 *)((u8 *)p)) == 0) {
        *(volatile u32 *)0x040004A4 = 0x001F00C0;
        n = p->c.cnt;
        for (i = 0; i < n; i++) {
            e = func_021C1AB4((u8 *)p, i);
            func_021C1B28(e, &b[1], &b[0]);
            if (e[8] >= 3) {
                s16_021C13E8 px, py, x, y;
                u32 va, vb;
                px = p->c.x;
                py = p->c.y;
                x = px + p->c.t[b[1]].x;
                y = py + p->c.t[b[1]].y;
                *(volatile u32 *)0x04000500 = 0;
                *(volatile u32 *)0x04000480 = 0;
                va = (u16)px | ((u32)(u16)py << 16);
                vb = (u16)x | ((u32)(u16)y << 16);
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = vb;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x04000504 = 0;
            }
        }
    }
}















void func_021C14DC(u8 *p)
{
    V a;
    V b;
    V c;

    a.x = 0;
    a.y = 0;
    a.z = 0x1000;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    func_0207D7C4(&a, &b, &c, 1, 0);
    func_0207D760(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, 1, 0);
    func_0206A700();
    d_02148D8C = a;
    d_02148D98 = b;
    d_02148DA4 = c;
    func_0207BCA0(&a, &b, &c, &d_02148B98);
    d_02148BCC.flag &= ~0xE8;
    func_0207C554(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, &d_02148B54);
    d_02148BCC.flag &= ~0x50;
    func_0206A854();
}














void func_021C15B8(u8 *p)
{
    if (((struct Obj04640 *)p)->f14==0) {
        switch (((struct Obj04640 *)p)->f8) {
        case 0: func_021C1610((u32)p); break;
        case 1: func_021C1628(p); break;
        case 2: func_021C1638(p); break;
        case 3: func_021C1648(p); break;
        case 4: func_021C1658((u32)p); break;
        case 5: func_021C1670(p); break;
        }
    }
    func_021C1680((Rec_021C1638 *)((Rec_021C0EF4 *)p));
    func_021C16C4(p);
}














void func_021C1610(u32 a0)
{
    if (func_021C0E64(((struct Obj26010 *)(((u8*)a0)))->fC) == 0) {
    func_021C16E8(a0);
    }
}














void func_021C1628(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 120) {
    func_021C16FC(a0, 4);
    }
}













void func_021C1638(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 30) {
    func_021C16FC(a0, 4);
    }
}













void func_021C1648(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 20) {
    func_021C16FC(a0, 0);
    }
}













/*
 * When the +0x0c handle is idle, runs func_021C16E8().
 *
 * Addresses are Black-image addresses.
 */
void func_021C1658(u32 a0)
{
    if (func_021C0E64(((struct Obj26011 *)(((u8*)a0)))->fC) == 0) {
    func_021C16E8(a0);
    }
}













void func_021C1670(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 60) {
    func_021C16FC(a0, 4);
    }
}














/*
 * Bumps the record's +0x10 counter, then selects a ceiling by the word at
 * +8 and clamps the counter to it (the ceiling is uninitialised on the
 * default path, which is how the image reads too).  Called once from
 * 0x021C1604 with only r0 live.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1680(Rec_021C1638 *p)
{
    u32 v;

    p->counter++;
    switch (p->type) {
    case 0:
        v = (u32)-1;
        break;
    case 1:
        v = 0x78;
        break;
    case 2:
        v = 0x1e;
        break;
    case 3:
        v = 0x14;
        break;
    case 4:
        v = (u32)-1;
        break;
    case 5:
        v = 0x3c;
        break;
    }
    if (v < p->counter)
        p->counter = v;
}













/*
 * Count the u32 at +0x18 down to zero, clearing the u32 at +0x14 when it reaches it.
 *
 * Addresses are Black-image addresses.
 */
void func_021C16C4(void *p)
{
    u32 v;
    if (((struct Obj04640 *)p)->f14 == 0)
        return;
    if (((struct Obj04640 *)p)->f18 == 0)
        return;
    v = ((struct Obj04640 *)p)->f18 - 1;
    ((struct Obj04640 *)p)->f18 = v;
    if (v == 0)
        ((struct Obj04640 *)p)->f14 = 0;
}












/*
 * Word at +0xc forwarded to func_021C0E4C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C16DC(u32 *p, u32 a1)
{
    func_021C0E4C(p[3], a1);
}












void func_021C16E8(u32 a0)
{
    func_021C16FC((void *)(a0 + 0 + 0), func_021C0E54((struct Ring *)(((struct Obj04641 *)(((u8*)a0 + 0)))->fC)) + 0);
}













/*
 * Set +8 and clear +0x10.
 *
 * Addresses are Black-image addresses.
 */
void *func_021C16FC(void *p, u32 v)
{
    ((struct Obj04641 *)p)->f8 = v;
    ((struct Obj04641 *)p)->f10 = 0;
    return p;
}












u32 func_021C1704(void *a0)
{
    ((struct Obj00554 *)(((u8*)a0)))->f1AC = 0;
    func_021C0E5C(((struct Obj00554 *)(((u8*)a0)))->fC);
    return (u32)func_021C16FC(a0, 0);
}














void func_021C1720(u8 *a0, u8 *a1)
{
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC) + 28) = ((struct Obj03955 *)((u8*)a1))->f0;
    *(u32*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC) + 32) = (u32)(((struct Obj03955 *)(((u8*)a1)))->f4);
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 36)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 37)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 38)) = 0;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 39)) = ((struct Obj03955 *)(((u8*)a1)))->f8;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 40)) = ((struct Obj03955 *)(((u8*)a1)))->f9;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 41)) = ((struct Obj03955 *)(((u8*)a1)))->fA;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 42)) = ((struct Obj03955 *)(((u8*)a1)))->fB;
    *(u8*)(((u8*)a0 + 20 * ((struct Obj00554 *)(((u8*)a0)))->f1AC + 43)) = ((struct Obj03955 *)(((u8*)a1)))->fC;
    *(u8*)(((u8*)a0 + ((struct Obj00554 *)(((u8*)a0)))->f1AC * 20 + 44)) = ((struct Obj03955 *)(((u8*)a1)))->fD;
    ((struct Obj00554 *)(((u8*)a0)))->f1AC = ((struct Obj00554 *)(((u8*)a0)))->f1AC + 1;
}













/*
 * note: bubble sort of 0x14-byte records by u32 key (descending). Counters and bound are int and are
 *   declared and assigned separately (int i; int n; int j; n = ...; i = 0;): that order puts n in lr and i
 *   in ip and keeps n - 1 unhoisted.
 */
void func_021C17C4(u8 *p)
{
    int i;
    int n;
    int j;
    n = *(u8 *)(p + 0x1AC);
    i = 0;

    while (i < n - 1) {
        j = 0;
        while (j < n - 1 - i) {
            u8 *e = p + j * 0x14;
            if (*(u32 *)(e + 0x20) < *(u32 *)(e + 0x34)) {
                Rec_021C17C4 t = *(Rec_021C17C4 *)(e + 0x1C);
                *(Rec_021C17C4 *)(e + 0x1C) = *(Rec_021C17C4 *)(e + 0x30);
                *(Rec_021C17C4 *)(e + 0x30) = t;
            }
            j++;
        }
        i++;
    }
}












/*
 * lever: declare base before total, preserve both base stores, guard do-loop.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base=p;` before `base=p+0x1c;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021C1850(u8 *p)
{
    u8 *base;
    u32 total=func_021C1AD4(p);
    int count=p[0x1ac];
    int i=0;
    int remaining;
    if (count>0) {
        base=p+0x1c;
        do {
            u8 *record=base+i*20;
            record[8]=(((struct Obj14759 *)record)->f4*100)/total;
            i++;
        } while (i<count);
    }
    remaining=100-func_021C1AFC(p);
    i=0;
    while (remaining>0) {
        p[i*20+0x24]+=1;
        remaining--;
        i=(i+1)%count;
    }
}













void func_021C18C4(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++) {
        ((struct Ent_021C18C4 *)(p + 0x1C))[i].start = sum;
        ((struct Ent_021C18C4 *)(p + 0x1C))[i].end = sum + ((struct Ent_021C18C4 *)(p + 0x1C))[i].len - 1;
        sum += ((struct Ent_021C18C4 *)(p + 0x1C))[i].len;
    }
}












/*
 * Callee B60/B4C full matched bodies explicitly return (u16); caller uses their halfword payloads.
 */
void func_021C18F8(u8 *p)
{
    struct Range_021C0EF4 range;
    int count=p[0x1ac];
    int k=0;
    int i;
    for(i=0;i<count;i++) {
        u8 *rec;
        u16 color,color2;
        int j;
        rec=func_021C1AB4(p,i);
        color=func_021C1B60(rec);
        color2=func_021C1B4C(rec);
        func_021C1B28(rec,&range.min,&range.max);
        range.x=((struct Obj00554 *)p)->f1B4;
        range.y=((struct Obj00554 *)p)->f1B6;
        range.z=((struct Obj00554 *)p)->f1B8+i*205;
        for(j=range.min;j<=range.max;j++) {
            u8 *q=p+k*10;
            ((struct Obj03377 *)q)->f418=color;
            ((struct Obj03377 *)q)->f412=range.x;
            ((struct Obj03377 *)q)->f414=range.y;
            ((struct Obj03377 *)q)->f416=range.z;
            q[0x41a]=i;
            ((struct Obj03377 *)q)->f422=color2;
            func_0207CA30((s16_021C18F8 *)&range.x,(s16_021C18F8 *)(p+0x1ba+j*6),(s16_021C18F8 *)(p+0x412+((u32)k+1)*10));
            q[0x424]=i;
            ((struct Obj03377 *)q)->f42C=color2;
            func_0207CA30((s16_021C18F8 *)&range.x,(s16_021C18F8 *)(p+0x1ba+((j+1)%100)*6),(s16_021C18F8 *)(p+0x412+((u32)k+2)*10));
            q[0x42e]=i;
            k+=3;
        }
    }
}













void func_021C1A58(Rec_021C1A58 *p, u32 v)
{
    p->a = v;
}













/*
 * Stores a constant 1 at offset 0x14 and the argument at offset 0x18.
 * Reached only from the tail-call veneer func_021C118C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1A5C(Rec_021C1A5C *p, u32 v)
{
    p->flag = 1;
    p->value = v;
}













/*
 * A const source pointer fixes the load order (y, x, z).
 */
void func_021C1A64(u8 *p, const struct Pos_021C16C4 *v)
{
    s16_021C1A64 z = v->z;
    s16_021C1A64 y = v->y;
    s16_021C1A64 x = v->x;
    *(s16_021C1A64 *)(p + 0x1B4) = x;
    *(s16_021C1A64 *)(p + 0x1B6) = y;
    *(s16_021C1A64 *)(p + 0x1B8) = z;
}













u8 func_021C1A84(u8 *p, u8 key)
{
    int i;
    int n;
    u8 v;
    n = p[0x1AC];
    for (i = 0; i < n; i++) {
        v = p[0x1C + i * 0x14];
        if (v == key) {
            return i;
        }
    }
    return 0;
}













void *func_021C1AB4(void *p, u32 n)
{
    return (char *)p + 0x1c + n * 0x14;
}













void *func_021C1AC0(u8 *p, u8 key)
{
    return func_021C1AB4(p, func_021C1A84(p, key));
}













int func_021C1AD4(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++)
        sum += *(int *)(p + i * 0x14 + 0x20);
    return sum;
}













int func_021C1AFC(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++)
        sum += p[i * 0x14 + 0x24];
    return sum;
}













void func_021C1B28(u8 *p, u8 *a, u8 *b)
{
    u8 x = (u8)(int)(float)p[9];
    u8 y = (u8)(int)(float)p[10];
    *a = x;
    *b = y;
}












/*
 * Pack the bytes at +0xb, +0xc and +0xd into one u16, 5 and 10 bits apart.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021C1B4C(void *p)
{
    return (u16)(((struct Obj03956 *)p)->fB | (((struct Obj03956 *)p)->fC << 5) | (((struct Obj03956 *)p)->fD << 10));
}












/*
 * Pack the bytes at +0xe, +0xf and +0x10 into one u16, 5 and 10 bits apart.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021C1B60(void *p)
{
    return (u16)(((struct Obj03956 *)p)->fE | (((struct Obj03956 *)p)->fF << 5) | (((struct Obj03956 *)p)->f10 << 10));
}











/*
 * matching: the last block as a ternary on the float then one cast lets the ffix tail be shared;
 *   max kept in an int local loaded before min.
 */
void func_021C1B74(u8 *p, u8 *rec, s16 *out)
{
    struct Range_021C1B4C r;
    int mx;
    float f1, ang, cs, sn, pz, cx, cy, cz;
    func_021C1B28(rec, &r.min, &r.max);
    mx = r.max;
    f1 = (float)(r.min + mx + 1);
    ang = 1.5707964f - 0.01f * (3.1415927f * f1);
    cs = 0.42f * (float)cos((double)ang);
    sn = 0.42f * (float)sin((double)ang);
    pz = (float)*(s16 *)(p + mx * 6 + 0x1be) / 4096.0f;
    cx = (float)*(s16 *)(p + 0x1b4) / 4096.0f;
    cy = (float)*(s16 *)(p + 0x1b6) / 4096.0f;
    cz = (float)*(s16 *)(p + 0x1b8) / 4096.0f;
    if (cx + cs > 0.0f) out[0] = (s16)(0.5f + 4096.0f * (cx + cs));
    else out[0] = (s16)(4096.0f * (cx + cs) - 0.5f);
    if (cy + sn > 0.0f) out[1] = (s16)(0.5f + 4096.0f * (cy + sn));
    else out[1] = (s16)(4096.0f * (cy + sn) - 0.5f);
    out[2] = (s16)((cz + pz > 0.0f) ? (0.5f + 4096.0f * (cz + pz)) : (4096.0f * (cz + pz) - 0.5f));
}












u32 func_021C1D24(void *p)
{
    return ((struct Obj26017 *)p)->f4;
}











/*
 * Small dense switch on the word at offset 8.
 *
 * Addresses are Black-image addresses.
 */
s32 func_021C1D28(Rec_v0EF4 *p)
{
    switch (p->type) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 0;
    case 5:
        return 1;
    }
    return 0;
}










void func_021C1D64(u8 *p)
{
    func_021C1DF0((char *)p);
    func_021C1E0C(p);
}









/*
 * Tail-call veneer: branch to func_021C1E00.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1D74(u32 a0)
{
    func_021C1E00((void *)a0);
}








void func_021C1D7C(unsigned char *p, u32 a)
{
    ((struct Obj02555 *)p)->f0 = a;
    ((struct Obj02555 *)p)->f4 = 0;
    ((struct Obj02555 *)p)->f8 = 0;
    ((struct Obj02555 *)p)->fC = 0;
    ((struct Obj02555 *)p)->f14 = 0;
    ((struct Obj02555 *)p)->f18 = 0;
    ((struct Obj02555 *)p)->f1B0 = 0x7db;
    p[0x1ac] = 0;
    ((struct Obj02555 *)p)->f1B4 = -0xb2f;
    ((struct Obj02555 *)p)->f1B6 = -0xc9;
    ((struct Obj02555 *)p)->f1B8 = -0x1000;
}








u8 *func_021C1DBC(u32 heap)
{
    u8 *p = func_02030734(heap, 4044, 0, d_021C4064, 1588);
    func_021C1D7C(p, heap);
    return p;
}










/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C1DE8(void *a0)
{
    return func_020307B0(a0);
}










void func_021C1DF0(char *p)
{
    ((struct Obj14762 *)p)->fC = func_021C0E08(0xa, ((struct Obj14762 *)p)->f0);
}










/*
 * Tail-call veneer with one argument load: passes the word at offset 0xc on
 * to func_021C0E3C.  Reached from func_021C1D74's veneer.
 *
 * Addresses are Black-image addresses.
 */
void func_021C1E00(Rec_v1DBC *p)
{
    func_021C0E3C((void *)p->a);
}










/*
 * 100 points on a circle of radius r = (p+0x1b0)/4096, stored as FX32 s16
 * triples at p+0x1ba+6i. The base offset 0x1b0 is a local (o + 0xa, o + 0xc,
 * o + 0xe stay as spilled runtime adds); the first converted value goes through
 * a local so its _ffix call comes before the p + i*6 address.
 */
void func_021C1E0C(u8 *p)
{
    s32 i;
    f32 r;
    s32 o = 0x1b0;
    r = *(s32 *)(p + o) / 4096.0f;
    for (i = 0; i < 100; i++) {
        f32 t = 1.5707964f - (6.2831855f * (f32)i) / 100.0f;
        f32 x = r * (f32)cos((f64)t);
        f32 y = r * (f32)sin((f64)t);
        f32 z = 0.0f;
        s32 v = FX32_CONST(x);
        *(s16 *)(p + i * 6 + (o + 0xa)) = v;
        *(s16 *)(p + i * 6 + (o + 0xc)) = FX32_CONST(y);
        *(s16 *)(p + i * 6 + (o + 0xe)) = FX32_CONST(z);
    }
}










void func_021C1F44(const s16 *p, s32 *px, s32 *py)
{
    VecFx32 v;
    v.x = FX32_CONST(FX_FX32_TO_F32(p[0]));
    v.y = FX32_CONST(FX_FX32_TO_F32(p[1]));
    v.z = FX32_CONST(FX_FX32_TO_F32(p[2]));
    func_0206DF3C(&v, px, py);
}









u32 func_021C2070(u32 a0, u32 a1)
{
    u32 v1 = func_021C2550(a0);
    func_021C256C((void *)v1, a0);
    func_021C2630((char *)v1, (char *)a1);
    func_021C25B0((u8 *)v1);
    func_021C25D0((u8 *)v1);
    return v1;
}









u32 func_021C209C(void *a0)
{
    func_021C2614((char *)a0);
    func_021C25C4((u8 *)a0);
    return func_021C25A8(a0);
}










/*
 * Forwarding wrapper: passes a fifth (stack) argument through.
 *
 * Addresses are Black-image addresses.
 */
void func_021C20B4(int a0, int a1, int a2, int a3, int a4)
{
    func_021C2288((u8 *)a0, a1, a2, a3, a4);
}










/*
 * Tail-call veneer: branch to func_021C20EC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C20C4(void *p)
{
    func_021C20EC(p);
}










/*
 * Tail-call veneer: forwards arg(s) a0, 1 to func_021C218C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C20CC(u32 a0)
{
    func_021C218C((void *)a0, 1);
}








void func_021C20D8(void *p)
{
    func_021C218C(p, 0);
    func_021C2260(p);
}









void func_021C20EC(void *p)
{
    switch (((struct Obj06717 *)p)->f20) {
    case 0: func_021C2118(p); break;
    case 1: func_021C211C(p); break;
    case 2: func_021C2188(p); break;
    }
    (((struct Obj06717 *)p)->f24)++;
}









/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2118(void *p)
{
}









void func_021C211C(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj06717 *)p)->f298; i++) {
        char *e = (char *)p + i * 0x18;
        if (((struct Obj06718 *)e)->f28 == 0 && ((struct Obj06718 *)e)->f2C <= ((struct Obj06717 *)p)->f24)
            func_021C21C4(p, (u8)i);
        if (((struct Obj06718 *)e)->f28 == 1 && ((struct Obj06718 *)e)->f30 == 1 && ((struct Obj06718 *)e)->f34 <= ((struct Obj06717 *)p)->f24)
            func_021C2250((u32)p, (u8)i);
    }
    if (func_021C2194(p))
        func_021C218C(p, 2);
}









void func_021C2188(void *p)
{
}









/*
 * Set +0x20 and clear +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021C218C(void *p, u32 v)
{
    ((struct Obj14763 *)p)->f20 = v;
    ((struct Obj14763 *)p)->f24 = 0;
}









u32 func_021C2194(void *p)
{
    s32 i;
    for (i = 0; i < ((struct Obj26020 *)p)->f298; i++) {
        if (*(u32 *)((char *)p + 0x28 + i * 0x18) == 0)
            return 0;
    }
    return 1;
}








/*
 * tail: two zero padding bytes at 0x021C224E, not a follower.
 * ABI: B8C4's own source omits the visible original r1=0; retain it.
 *      Palette is selected only for the original modes 0..3; original
 *      default branch retains entry r5 without initializing it.
 */
void func_021C21C4(u8 *p,int index)
{
    u8 *record=p+0x28+index*24;
    struct Obj *obj=*(struct Obj * *)&((struct Obj06720 *)record)->f14;
    struct Vec2 point;
    u16 palette;
    point.x=record[0xe];
    point.y=record[0xf];
    ((struct Obj06720 *)record)->f0=1;
    switch (((struct Obj06720 *)record)->f10) {
    case 0: palette=((struct Obj06719 *)p)->f16; break;
    case 1: palette=((struct Obj06719 *)p)->f18; break;
    case 2: palette=((struct Obj06719 *)p)->f1A; break;
    case 3: palette=((struct Obj06719 *)p)->f1C; break;
    }
    func_0204B404(obj,&point,((struct Obj06719 *)p)->f14);
    func_0204B878(obj,palette);
    func_0204B8C4(obj,0);
    func_0204B9C4((struct Actor *)obj,1);
    func_0204B92C(obj,1);
    func_0204B954((struct Actor *)obj,0x12000);
    func_0204B95C((struct Actor *)obj);
    func_0204B3DC(obj,1);
}








void func_021C2250(u32 a0, u32 a1)
{
    func_0204B974((struct Actor *)(*(u32*)(((u8*)a0 + a1 * 24) + 60)));
}









void func_021C2260(void *p)
{
    s32 i;
    s32 n = ((struct Obj26021 *)p)->f298;
    for (i = 0; i < n; i++)
        func_0204B3DC((struct Obj *)*(u32 *)((char *)p + 0x3c + i * 0x18), 0);
}









/*
 * Element i of a 0x18-byte array at p+0x28; the half==0 flag stores are
 * written through that element base (p + 0x28 + i*0x18 + 8 / + 0xc). Colours
 * come from f += 1.0f (f first in _fadd), i declared before f with i = 0 as a
 * statement, half2 declared before w2, and y += 8 before f += 1.0f.
 * EXACT* = 690 bytes compiled, listing extent 692 (trailing pad).
 */
void func_021C2288(u8 *p, int a, int b, int c, int d)
{
    int i;
    float f = 0.0f;
    int j;
    int yb;
    int w = a - c;
    int half = (w - 4) / 8;
    int half2;
    int w2;
    int xx;
    int y;
    int r;

    i = 0;
    yb = b - 4;
    a -= 8;

    for (j = 0; j < half; j++) {
        func_021C253C(p + 0x28 + i * 0x18, a, yb, (u32)f, 0);
        a -= 8;
        f += 1.0f;
        i++;
    }
    if (half == 0) {
        if (w - 4 > 0) {
            func_021C253C(p + 0x28 + i * 0x18, a, yb, (u32)f, 0);
            if (w - 4 < 4) {
                *(u32 *)(p + 0x28 + i * 0x18 + 8) = 1;
                *(u16 *)(p + 0x28 + i * 0x18 + 0xc) = 1;
            }
            f = f + (2.0f * (float)(w - 4) / 8.0f - 1.0f);
            i++;
        }
    } else if ((w - 4) % 8 != 0) {
        r = (w - 4) - half * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        func_021C253C(p + 0x28 + i * 0x18, c + 4, yb, (u32)f, 0);
        f += 1.0f;
        i++;
    }
    func_021C253C(p + 0x28 + i * 0x18, c - 4, b - 4, (u32)f, 2);
    f += 1.0f;
    i++;
    w2 = d - b;
    half2 = (w2 - 4) / 8;
    xx = c - 4;
    y = b + 4;
    for (j = 0; j < half2; j++) {
        func_021C253C(p + 0x28 + i * 0x18, xx, y, (u32)f, 1);
        y += 8;
        f += 1.0f;
        i++;
    }
    if ((w2 - 4) % 8 != 0) {
        r = (w2 - 4) - half2 * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        func_021C253C(p + 0x28 + i * 0x18, xx, d - 8, (u32)f, 1);
        f += 1.0f;
        i++;
    }
    func_021C253C(p + 0x28 + i * 0x18, c - 4, d - 4, (u32)f, 3);
    p[0x298] = i + 1;
}









/*
 * Initialise the header: two mode bytes, two u16 fields, three cleared words.
 *
 * Addresses are Black-image addresses.
 */
void func_021C253C(void *p, u8 a, u8 b, u32 c, u32 d)
{
    ((struct Obj04642 *)p)->fE = a;
    ((struct Obj04642 *)p)->f0 = 0;
    ((struct Obj04642 *)p)->f8 = 0;
    ((struct Obj04642 *)p)->fC = 0;
    ((struct Obj04642 *)p)->fF = b;
    ((struct Obj04642 *)p)->f4 = c;
    ((struct Obj04642 *)p)->f10 = d;
}








u32 func_021C2550(u32 a0)
{
    return (u32)func_02030734(a0, 668, 0, (const char *)0x21C4074, 558);
}









/*
 * Initialise the container and clear its 0x1a 0x18-byte records.
 *
 * Addresses are Black-image addresses.
 */
void func_021C256C(void *p, u32 v)
{
    int i;
    ((struct Obj03378 *)p)->f0 = v;
    ((struct Obj03378 *)p)->f20 = 0;
    ((struct Obj03378 *)p)->f24 = 0;
    ((struct Obj03378 *)p)->f298 = 0;
    ((struct Obj03378 *)p)->f4 = 0;
    for (i = 0; i < 0x1a; i++) {
        u8 *e = (u8 *)p + i * 0x18;
        ((struct Obj04643 *)e)->f28 = 0;
        ((struct Obj04643 *)e)->f2C = 0;
        ((struct Obj04643 *)e)->f30 = 0;
        ((struct Obj04643 *)e)->f34 = 0;
        ((struct Obj04643 *)e)->f36 = 0;
        ((struct Obj04643 *)e)->f37 = 0;
        ((struct Obj04643 *)e)->f3C = 0;
    }
}









u32 func_021C25A8(void *a0)
{
    return func_020307B0(a0);
}








/*
 * Store the result of functional call func_0204B100(0x1a, 0, p->h0) into p->w4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C25B0(u8 *p)
{
    ((struct Obj03378 *)p)->f4 = (u32)func_0204B100(0x1a, 0, ((struct Obj03378 *)p)->f0);
}









/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 4)) to func_0204B1CC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C25C4(u8 *a0)
{
    func_0204B1CC((struct Bank *)((u32)(((struct Obj26022 *)a0)->f4)));
}








/*
 * tail: two zero padding bytes at 0x021C2612, not a follower.
 * ABI: 0204B294's legacy source says void; original caller stores returned
 *      r0 at 021C2608. Preserve that observable return and its seven inputs.
 */
void func_021C25D0(u8 *p)
{
    struct Arg arg;
    u32 *q=(u32 *)(p+8);
    int i=0;
    arg.a=0;
    arg.b=0;
    arg.c=0;
    arg.d=0;
    arg.e=0;
    for (;i<26;i++) {
        *(u32 *)(p+i*24+0x3c)=(u32)func_0204B294((void *)((struct Obj03378 *)p)->f4,q[0],q[1],q[2],&arg,((struct Obj08444 *)q)->fC,((struct Obj03378 *)p)->f0);
    }
}









void func_021C2614(char *p)
{
    int i;
    for (i = 0; i < 0x1A; i++)
        func_0204B3B4((struct Obj *)(*(int *)(p + 0x3c + i * 0x18)));
}









void func_021C2630(char *p, char *q)
{
    struct S { int a, b, c, d, e, f; };

    *(struct S *)(p + 8) = *(struct S *)q;
}









u32 func_021C2644(void *p, u32 i, u8 j)
{
    return *(u16 *)((char *)p + i * 0xd4 + 0xc + j * 0xc);
}









/*
 * Element field: u8 at +0xe of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2654(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0xe + j * 0xc);
}









/*
 * Element field: u8 at +0xf of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2664(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0xf + j * 0xc);
}









/*
 * Element field: u8 at +0x10 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2674(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0x10 + j * 0xc);
}









/*
 * Find the 0xd4-byte record whose byte +4 equals the argument; its index or zero.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2684(void *p, u32 v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(u8 *)((char *)p + i * 0xd4 + 4) == v)
            return (u8)i;
    }
    return 0;
}









/*
 * Const base pointer, i declared before e, e assigned in its own statement.
 */
u32 func_021C26AC(const u8 *p, u8 unused, u8 key)
{
    s32 i;
    const u8 *e;
    e = p + 4 + func_021C2684((void *)p, unused) * 0xd4;
    for (i = 0; i < e[1]; i++) {
        if (key == *(u16 *)(e + 8 + i * 0xc))
            return (u8)i;
    }
    return 0;
}








u32 func_021C26E8(u32 a0, u32 a1, u32 a2)
{
    u32 v1 = func_021C28FC(a0);
    func_021C291C((char *)v1, a0);
    func_021C2934(v1, a1, a2);
    return v1;
}








u32 func_021C270C(void *a0)
{
    func_021C2950((u32)a0);
    return func_021C2914(a0);
}







void func_021C271C(u32 a0, u32 a1, u32 a2)
{
    func_021C288C((void *)a0, a1, a2);
    func_021C278C((u8 *)a0);
}







void func_021C272C(u32 a0, u32 a1)
{
    func_021C2888((void *)a0, ((u32)((u32)a1 << 24) >> 24));
    func_021C278C((u8 *)a0);
}








/*
 * Tail-call veneer: branch to func_021C2748.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2740(unsigned int a0, unsigned int a1)
{
    func_021C2748(a0, a1);
}







/*
 * Pushes the +0x10 body through func_0204B3DC, then the +0x14 body when
 * func_021C28BC() is busy, the +0x18 body when either query fires, and the
 * +0x1c body unconditionally.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2748(u32 a0, u32 a1)
{
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f10, a1);
    if (func_021C28BC((char *)a0) != 0) {
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f14, a1);
    }
    if (func_021C28BC((char *)a0) != 0 || func_021C28A4((char *)a0) != 0) {
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f18, a1);
    }
    func_0204B3DC((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f1C, a1);
}








void func_021C278C(u8 *p)
{
    u32 z = 0;
    void *h = ((struct Obj03957 *)p)->f10;
    u8 *q = p + 0x20;
    u16 pos[2];

    pos[0] = ((struct Obj03957 *)p)->f4;
    pos[1] = ((struct Obj03957 *)p)->f8;

    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->f10);

    func_0204B8C4(h, 0);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f14;
    func_021C28EC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->fE);
    func_0204B8C4(h, func_021C28BC((char *)p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f18;
    func_021C28DC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->fE);
    func_0204B8C4(h, func_021C28A4((char *)p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, 0);

    h = ((struct Obj03957 *)p)->f1C;
    func_021C28CC((const u32 *)p, pos, pos + 1);
    func_0204B404(h, (const struct Vec2 *)pos, ((struct Obj03958 *)q)->fC);
    func_0204B878(h, ((struct Obj03958 *)q)->fE);
    func_0204B8C4(h, func_021C2894((char *)p) << 12);
    func_0204B974(h);
    func_0204B3DC(h, z);
}








/*
 * Field setter, u8 at +2.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2888(void *p, u8 v)
{
    ((struct Obj26023 *)p)->f2 = v;
}








/*
 * Store two u32 arguments at +4 and +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C288C(void *p, u32 a, u32 b)
{
    ((struct Obj03957 *)p)->f4 = a;
    ((struct Obj03957 *)p)->f8 = b;
}








u8 func_021C2894(char *p)
{
    return (u8)(((struct Obj26024 *)p)->f2 % 10);
}








u8 func_021C28A4(char *p)
{
    int t = ((struct Obj26025 *)p)->f2 % 100;
    return (u8)(t / 10);
}








u8 func_021C28BC(char *p)
{
    return (u8)(((struct Obj26026 *)p)->f2 / 100);
}







void func_021C28CC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0x14;
    *b = p[2] - 8;
}







void func_021C28DC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0xF;
    *b = p[2] - 8;
}







void func_021C28EC(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0xA;
    *b = p[2] - 8;
}






u32 func_021C28FC(u32 a0)
{
    return (u32)func_02030734(a0, 52, 0, (const char *)0x21C407C, 420);
}







u32 func_021C2914(void *a0)
{
    return func_020307B0(a0);
}







void func_021C291C(char *p, u32 v)
{
    int i;
    ((struct Obj10967 *)p)->f0 = v;
    ((struct Obj10967 *)p)->f2 = 0;
    ((struct Obj10967 *)p)->fC = 0;
    for (i = 0; i < 4; i++)
        *(int *)(p + 0x10 + i * 4) = 0;
}






void func_021C2934(u32 a0, u32 a1, u32 a2)
{
    func_021C2958((void *)a0, a2);
    func_021C29B4((void *)a0, (const void *)a1);
    func_021C295C((unsigned char *)a0);
}







/*
 * Tail-call veneer: branch to func_021C299C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2950(u32 a0)
{
    func_021C299C((int *)a0);
}







/*
 * Field setter, u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2958(void *p, u32 v)
{
    ((struct Obj26033 *)p)->fC = v;
}







void func_021C295C(unsigned char *p)
{
    struct arg_021C295C s;
    int *q = (int *)(p + 0x20);
    int i;

    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 0;
    s.e = 0;
    for (i = 0; i < 4; i++) {
        *(int *)(p + 0x10 + i * 4) =
            (int)func_0204B294((void *)((struct Obj14767 *)p)->fC, q[0], q[1], q[2], &s,
                          ((struct Obj08446 *)q)->fC,
                          ((struct Obj14767 *)p)->f0);
    }
}







void func_021C299C(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0204B3B4((struct Obj *)p[i + 4]);
}







/*
 * Copy a 20-byte block into the record at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021C29B4(void *p, const void *src)
{
    *(Blk20 *)((char *)p + 0x20) = *(const Blk20 *)src;
}






u32 func_021C29C8(u32 a0)
{
    u32 v1 = func_021C2DA0(a0);
    func_021C2DCC((char *)v1);
    return v1;
}






u32 func_021C29D8(void *a0)
{
    func_021C2E20((char *)a0);
    return func_021C2DC4(a0);
}







void func_021C29E8(void *p, u32 b, u32 c, u32 d)
{
    func_021C2DE0(p, (short unsigned int *)b, (short unsigned int *)c, d);
}







/*
 * Tail-call veneer: passes its argument through to func_021C2A30.
 *
 * Addresses are Black-image addresses.
 */
void func_021C29F0(Rec_021C295C *p)
{
    func_021C2A30((Rec_021C2A10 *)p);
}







/*
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C29FC names
 * func_021C2A18. Middle of the func_021BA31C blocker chain.
 *
 * Addresses are Black-image addresses.
 */
void func_021C29F8(u8 *p, u32 b, u16 c)
{
    func_021C2A18(p, b, c);
}






/*
 * Tail-call veneer to func_021C2A28.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A00(u32 a0)
{
    func_021C2A28((void *)a0);
}







/*
 * Tail-call veneer: branch to func_021C2D88.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2A08(char *p)
{
    return func_021C2D88(p);
}







/*
 * Tail-call veneer: forwards its first argument to func_021C2D9C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A10(u32 a0, u32 a1)
{
    func_021C2D9C((u32 *)a0);
}







/*
 * Unlabelled 14-byte ov217 leaf in a .word run; target of the veneer at
 * 0x021C29F8 and the bottom of the func_021BA31C blocker chain.  Store order
 * in the source is +0x14, +0x18, +0x1c, +0x12.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A18(u8 *p, u32 b, u16 c)
{
    ((struct Obj08447 *)p)->f14 = 1;
    ((struct Obj08447 *)p)->f18 = b;
    ((struct Obj08447 *)p)->f1C = 0;
    ((struct Obj08447 *)p)->f12 = c;
}







/*
 * Clear the u32 at +0x14.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A28(void *p)
{
    ((struct Obj26035 *)p)->f14 = 0;
}







/*
 * Dispatch: after two non-null guards, one of ten handlers is called on the
 * record, chosen by the word at offset 0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2A30(Rec_021C2A10 *p)
{
    if (p->w4 == 0)
        return;
    if (p->w14 == 0)
        return;
    switch (p->kind) {
    case 0:
        func_021C2AA0((u8 *)p);
        break;
    case 1:
        func_021C2B10((u8 *)p);
        break;
    case 2:
        func_021C2B80((u8 *)p);
        break;
    case 3:
        func_021C2BF0((u8 *)p);
        break;
    case 4:
        func_021C2C30((u8 *)p);
        break;
    case 5:
        func_021C2C70((char *)p);
        break;
    case 6:
        func_021C2CB0((char *)p);
        break;
    case 7:
        func_021C2CF0(p);
        break;
    case 8:
        func_021C2D28((char *)p);
        break;
    case 9:
        func_021C2D68(p);
        break;
    }
}






/*
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse value for value*10/32, retaining the dying local's register.
 */
void func_021C2AA0(u8 *p)
{
    u16 angle=(u16)((((struct Obj00115 *)p)->f1C<<16)/60u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*10/32;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],value,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C+=1;
}





/*
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse value for value*3/32, retaining the dying local's register.
 */
void func_021C2B10(u8 *p)
{
    u16 angle=(u16)((((struct Obj00115 *)p)->f1C<<16)/30u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*3/32;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],value,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C+=1;
}





/*
 * ABI: explicit fourth-argument byte narrowing; fifth packed halfword uses
 *   a scalar u16: original outgoing str word and callee ldrh preserve bits.
 * lever: reuse the byte local for the scaled value.
 */
void func_021C2B80(u8 *p)
{
    u16 angle=(u16)((((struct Obj00115 *)p)->f1C<<16)/90u);
    u8 value=(u8)(int)(16.0f+16.0f*((float)d_020A1B38[(angle>>4)*2]/4096.0f));
    value=value*3/32;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],value,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C+=1;
}





void func_021C2BF0(u8 *p)
{
    int weight;
    if ((((struct Obj00115 *)p)->f1C >> 2 & 1) == 0) weight=0;
    else weight=6;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],weight,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C += 1;
    if (((struct Obj00115 *)p)->f1C>20) {
        func_021C2A28(p);
        func_021C2D88((char *)p);
    }
}





/*
 * tail: two zero padding bytes at 0x021C2C6E, not a follower.
 * ABI: 02021F64 reads its fifth stack input as one RGB555 halfword;
 *      original caller stores the numeric u16 color as a full stack word.
 *      The legacy aggregate declaration inserts an extra strh setup.
 */
void func_021C2C30(u8 *p)
{
    int weight;
    if ((((struct Obj00115 *)p)->f1C >> 2 & 1) == 0) weight=0;
    else weight=6;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],weight,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C += 1;
    if (((struct Obj00115 *)p)->f1C>10) {
        func_021C2A28(p);
        func_021C2D88((char *)p);
    }
}





/*
 * Tail: 021C2CAE..021C2CB0 is two zero alignment bytes.
 * Callee 02021F64's legacy Rgb555_021C2BF0 aggregate input reads only its low
 * stack halfword; scalar u16 preserves the original caller's str word.
 */
void func_021C2C70(char *p)
{
    int weight = ((((struct Obj00115 *)p)->f1C >> 2) & 1) == 0 ? 0 : 6;
    func_02021F64(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 30) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}




/*
 * Tail: 021C2CEE..021C2CF0 is two zero alignment bytes.
 * Callee 02021F64's legacy Rgb555 aggregate input reads only its low
 * stack halfword; scalar u16 preserves the original caller's str word.
 */
void func_021C2CB0(char *p)
{
    int weight = ((((struct Obj00115 *)p)->f1C >> 2) & 1) == 0 ? 0 : 9;
    func_02021F64(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 20) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}




void func_021C2CF0(void *p)
{
    u32 n = ((struct Obj00115 *)p)->f1C;
    u8 v;
    if (n < 0x14)
        v = (u8)func_0209C2B0(n * 7, 0x14);
    else
        v = 7;
    func_02021F64((u16 *)(*(u32 *)&((struct Obj00115 *)p)->fC), (u16 *)(*(u32 *)&((struct Obj00115 *)p)->f8), ((struct Obj00115 *)p)->f10, v, ((struct Obj00115 *)p)->f12);
    (((struct Obj00115 *)p)->f1C)++;
}



/*
 * Original truncates weight to u8 before calling 02021F64; its legacy
 * Rgb555 stack input reads only the low halfword, so scalar u16 keeps
 * the original caller's full-word str without aggregate partial stores.
 */
void func_021C2D28(char *p)
{
    unsigned int weight = 7 - ((struct Obj00115 *)p)->f1C * 7 / 30;
    func_02021F64(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, (u8)weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 30) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}





void func_021C2D68(void *p)
{
    func_02021F64((unsigned short *)(*(u32 *)&((struct Obj00115 *)p)->fC), (unsigned short *)(*(u32 *)&((struct Obj00115 *)p)->f8), ((struct Obj00115 *)p)->f10, 7, ((struct Obj00115 *)p)->f12);
    (((struct Obj00115 *)p)->f1C)++;
}





int func_021C2D88(char *p)
{
    return func_02082D44(((struct Obj10968 *)p)->fC, ((struct Obj10968 *)p)->f8,
                         ((struct Obj10968 *)p)->f10 << 1);
}



u32 func_021C2D9C(u32 *p)
{
    return p[5];
}



u32 func_021C2DA0(u32 a0)
{
    u8 s[4];
    u32 p1 = (u32)func_02030734(a0, 32, 0, (const char *)0x21C408C, 667);
    ((struct Obj26037 *)((u8*)p1))->f0 = a0;
    return p1;
}




u32 func_021C2DC4(void *a0)
{
    return func_020307B0(a0);
}




void func_021C2DCC(char *p)
{
    u16 t = ((struct Obj14768 *)p)->f0;
    func_02082BCC(p, 0, 0x20);
    ((struct Obj14768 *)p)->f0 = t;
}



void func_021C2DE0(char *p, unsigned short *dst, unsigned short *src, int count)
{
    int i;
    ((struct Obj06721 *)p)->f4 = 1;
    *(unsigned short * *)&((struct Obj06721 *)p)->f8 = dst;
    ((struct Obj06721 *)p)->f10 = count;
    *(unsigned short * *)&((struct Obj06721 *)p)->fC = func_02030734(((struct Obj06721 *)p)->f0, count * 2, 0, d_021C408C, 728);
    for (i = 0; i < count; i++)
        (*(unsigned short **)(p + 12))[i] = src[i];
}
