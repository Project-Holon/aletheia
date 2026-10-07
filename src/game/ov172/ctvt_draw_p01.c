/*
 * file:     ctvt_draw_p01.c
 * unit:     yes
 * function: func_021BA174, func_021BA194, func_021BA1B4, func_021BA1D8, func_021BA1E4, func_021BA1E8, func_021BA234, func_021BA244, func_021BA248, func_021BA24C, func_021BA254, func_021BA270, func_021BA280, func_021BA2B8, func_021BA2C4, func_021BA8C4, func_021BA9EC, func_021BAE58, func_021BAEE0, func_021BB288, func_021BB4D0, func_021BB54C, func_021BB65C, func_021BB8F4, func_021BB938, func_021BB9E4
 * address:  0x021BA174
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6A00  0x021B6A00  thumb  ov172
 *   func_02082A7C  0x02082A7C  arm
 *   func_021B6A18  0x021B6A18  thumb  ov172
 *   func_02072A44  0x02072A44  arm
 *   func_02034714  0x02034714  arm
 *   func_02072A88  0x02072A88  arm
 *   func_02072AA0  0x02072AA0  arm
 *   func_02072BDC 0x02072BDC arm
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE010  0x021BE010  thumb  ov172
 *   func_021BE018  0x021BE018  thumb  ov172
 *   func_021BE024  0x021BE024  thumb  ov172
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_021BE0B4  0x021BE0B4  thumb  ov172
 *   func_021BE2E0  0x021BE2E0  thumb  ov172
 *   func_021BE1A4  0x021BE1A4  thumb  ov172
 *   func_0203D34C  0x0203D34C  arm
 *   func_021BE02C  0x021BE02C  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021BE0B0  0x021BE0B0  thumb  ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   func_021BE08C  0x021BE08C  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7B80  0x021B7B80  thumb  ov172
 *   func_021B7B3C  0x021B7B3C  thumb  ov172
 *   func_021B8084  0x021B8084  thumb  ov172
 *   func_021B8740  0x021B8740  thumb  ov172
 *   func_021B8B34  0x021B8B34  thumb  ov172
 *   func_021B8B48  0x021B8B48  thumb  ov172
 *   func_021B77B4  0x021B77B4  thumb  ov172
 *   d_020A1B38     0x020A1B38  data a2
 *   func_020362DC 0x020362DC arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BE0B8 0x021BE0B8 thumb ov172
 *   func_020061E4 0x020061E4 thumb
 *   func_02035C08  0x02035C08  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   func_0204B404  0x0204B404  arm
 *   d_021C6FF8     0x021C6FF8  data
 *   d_021C7014     0x021C7014  data
 *   d_021C6FBC     0x021C6FBC  data
 *   d_021C7030     0x021C7030  data
 *   d_021C6FDC     0x021C6FDC  data
 *   d_021C6FC8     0x021C6FC8  data
 *   d_021C7034     0x021C7034  data
 *   d_021C7038     0x021C7038  data
 *   d_021C703C     0x021C703C  data
 *   func_02035D20  0x02035D20  arm
 *   func_021BE0C8  0x021BE0C8  thumb  ov172
 *   func_02035C38  0x02035C38  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021BE054  0x021BE054  thumb  ov172
 *   func_021BDFFC  0x021BDFFC  thumb  ov172
 *   func_021B8BB8  0x021B8BB8  thumb  ov172
 *   func_021B6E88  0x021B6E88  thumb  ov172
 *   func_021B8BFC  0x021B8BFC  thumb  ov172
 *   func_0207E008  0x0207E008  arm
 *   func_0207E100  0x0207E100  arm
 *   func_021BE078  0x021BE078  thumb  ov172
 *   func_02035CB8  0x02035CB8  arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   d_021C6FB2     0x021C6FB2  data
 *   d_021C6FB4     0x021C6FB4  data
 *   d_021C6FB6     0x021C6FB6  data
 *   d_021C6FB8     0x021C6FB8  data
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_020452E8  0x020452E8  arm
 *   func_021BE0D0  0x021BE0D0  thumb  ov172
 *   func_021B80E4  0x021B80E4  thumb  ov172
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 */
#include "../../matched/include/Obj05447.h"
#include "../../matched/include/Obj24096.h"
#include "../../matched/include/Obj04555.h"
#include "../../matched/include/Obj24097.h"
#include "../../matched/include/Obj24098.h"
#include "../../matched/include/Obj24099.h"
#include "../../matched/include/Obj14306.h"
#include "../../matched/include/Obj24100.h"
#include "../../matched/include/Obj06562.h"
#include "../../matched/include/Obj00276.h"
#include "../../matched/include/Obj01265.h"
#include "../../matched/include/Obj00140.h"
#include "../../matched/include/Obj00024.h"
#include "../../matched/include/Obj01757.h"
#include "../../matched/include/Obj24101.h"
#include "../../matched/include/Obj02880.h"
#include "../../matched/include/Obj14307.h"
#include "../../matched/include/Obj00836.h"
#include "../../matched/include/Obj02881.h"

struct MsgBank;
struct U16Vec;
struct CharBuf;
struct Obj;
struct Descriptor;
struct Cfg;
struct PrintSys;
struct Actor;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32_021BA1B4;

typedef signed int     s32;

typedef unsigned int   u32_021BA1D8;

typedef unsigned int   u32_021BA1E4;

typedef unsigned int u32_021BA234;

typedef struct Slot02072BDC Slot02072BDC;

typedef unsigned int   u32_021BA244;

typedef unsigned int   u32_021BA248;

typedef unsigned int   u32_021BA24C;

typedef unsigned int   u32_021BA254;

typedef unsigned int   u32_021BA270;

typedef unsigned int   u32_021BA280;

typedef unsigned int   u32_021BA2B8;

typedef unsigned int   u32_021BA2C4;

typedef signed short   s16;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

typedef unsigned int   u32_021BA8C4;

typedef unsigned int   u32_021BA9EC;

typedef unsigned int u32_021BAE58;

typedef unsigned long u32_021BAEE0;

struct SpritePos {
    s16 x;
    s16 y;
};

typedef unsigned long u32_021BB288;

typedef unsigned int u32_021BB4D0;

struct PtS { s16 x, y; };

typedef unsigned long u32_021BB54C;

typedef unsigned long u32_021BB65C;

typedef unsigned int   u32_021BB8F4;

typedef unsigned int u32_021BB938;

typedef unsigned int u32_021BB9E4;

extern void func_02082BCC(void *p, int v, int n);
extern int func_021B6A00(void *a0, unsigned a1, void *a2);
extern void func_02082A7C(int v, void *p, unsigned n);
extern int func_021B6A18(int a, int b, int c);
extern int  func_02072A44(int size);
extern void func_02034714(const char *expr, u32_021BA1B4 line, const char *file);
extern void func_02072A88(u32_021BA1D8 *p);
extern int func_02072AA0(void *s, int fmt, void *data, int loop,
                         int start, int end, int rate, int vol, int freq, int e);
extern void func_02072BDC(Slot02072BDC *s);
extern u32_021BA254 func_0209C2B0(u32_021BA254 a, u32_021BA254 b);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern u32_021BA2B8 func_020307B0(void *p);
extern u16 func_021BE00C(u16 *p);
extern u32_021BA2C4  func_021BE010(void *c);
extern u32_021BA2C4  func_021BE018(void *c, int i);
extern u32_021BA2C4  func_021BE024(void *c);
extern u32_021BA2C4  func_021BE034(void *c);
extern u32_021BA2C4  func_021BE03C(void *c);
extern u32_021BA2C4  func_021BE044(void *c);
extern u32_021BA2C4  func_021BE0B4(void *c);
extern void func_021BE2E0(void *c);
extern void func_020498F4(void *a, u32_021BA2C4 b, u32_021BA2C4 c, u32_021BA2C4 d, u32_021BA2C4 e, u32_021BA2C4 f, u16 g);
extern void func_020409B4(u32_021BA2C4 a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32_021BA2C4  func_020275E4(void);
extern u32_021BA2C4  func_0202762C(void);
extern void *func_020490F4(u32_021BA2C4 id, u32_021BA2C4 heap);
extern void func_020414EC(u32_021BA2C4 a);
extern u32_021BA2C4 func_02049990(void *a0, u32_021BA2C4 a1, u32_021BA2C4 a2, u32_021BA2C4 a3, u32_021BA2C4 a4, u32_021BA2C4 a5, u32_021BA2C4 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02040618(u32_021BA2C4 a, u32_021BA2C4 b, u32_021BA2C4 c);
extern void func_02049238(void *a);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32_021BA2C4 v);
extern void func_0204B3DC(struct Obj *o, unsigned int k);
extern u32_021BA2C4 func_020450F0(u32_021BA2C4 layer, u32_021BA2C4 a, u32_021BA2C4 b, u32_021BA2C4 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *w);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32_021BA2C4 index);
extern void func_0201C724(void *owner, u32_021BA2C4 a, u32_021BA2C4 b, u32_021BA2C4 c, u32_021BA2C4 d, u32_021BA2C4 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_0203D34C(u32_021BA2C4 a, u32_021BA2C4 b);
extern void func_021BE1A4(char *p);
extern void func_0201F7A8(void *desc, u32_021BA8C4 kind);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32_021BA8C4 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern u32_021BA9EC  func_021BE02C(void *c);
extern u32_021BA9EC  func_021BDFDC(void *c);
extern u32_021BA9EC  func_021BDFE4(void *c);
extern void func_021BE0B0(void *c, u32_021BA9EC v);
extern u32_021BA9EC func_021BE0A4(void *p);
extern void func_021BE08C(void *c);
extern int func_021B7590(int x, char *p);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern void func_021B7B3C(int x, int y, int z);
extern void func_021B8084(void *a, char *q);
extern u32_021BA9EC func_021B8740(int a, int b, u8 c, u32_021BA9EC d);
extern void func_021B8B34(void *c, u32_021BA9EC v, u32_021BA9EC k);
extern int  func_021B8B48(void *c, u32_021BA9EC v, u32_021BA9EC k);
extern u32_021BA9EC func_021B77B4(int unused, void *p);
extern void func_0202208C(void *p1, u32_021BA9EC p2, u32_021BA9EC p3, u32_021BA9EC p4, u32_021BA9EC p5, u32_021BA9EC p6, u32_021BA9EC p7);
extern u32_021BA9EC  func_020221A4(void);
extern int func_02035C60(void);
extern u32_021BA9EC  func_020362DC(void);
extern u32_021BA9EC func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32_021BA9EC a);
extern void func_020061E4(u32_021BA9EC id);
extern s32 func_02061CA4(void *p, u32_021BA9EC a, u32_021BA9EC b, s32 size);
extern u32_021BAE58 func_0204B98C(struct Actor *);
extern u16 func_0204B898(struct Obj *);
extern void func_0204B878(struct Obj *, u16);
extern void func_021BE0B8(void *);
extern int func_02035C08(const void *p);
extern u32_021BAEE0 func_0204B3F4(struct Obj *p);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32_021BAEE0 which);
extern u32_021BB288 func_02035D20(u32_021BB288 *outA, u32_021BB288 *outB);
extern u32_021BB288 func_021BE0C8(void *p);
extern int func_02035C38(void);
extern u8 func_021BE054(void *p);
extern u32_021BB288 func_021BDFFC(void *p);
extern int func_021B8BB8(int a, unsigned char *p, int *out);
extern void func_021B6E88(char *p, void *q);
extern void func_021B8BFC(int unused, u8 *p);
extern void *func_0207E008(void);
extern u32_021BB288 func_0207E100(void);
extern u32_021BB288 func_021BE078(void *p);
extern u32_021BB288 func_02035CB8(u32_021BB288 *outA, u32_021BB288 *outB);
extern void func_02041EE4(u32_021BB4D0, u32_021BB4D0, u32_021BB4D0);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B8C4(struct Obj *p, u32_021BB54C value);
extern void func_0201C6EC(struct PrintSys *p);
extern u32_021BB8F4 func_021BE0D0(void *p);
extern u32_021BB8F4 func_021B80E4(int unused, char *p);
int func_021BA174(int unused, void *a, void *buf, unsigned n);
int func_021BA194(int unused, int a, void *buf, unsigned n);
void func_021BA1B4(char *p, u32_021BA1B4 a1);
void func_021BA1D8(void *p);
void func_021BA1E4(void *a0);
int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);
void func_021BA234(void *p);
u32_021BA244 func_021BA244(void *p);
int func_021BA248(void *p);
int func_021BA24C(void *p);
int func_021BA254(void *p);
int func_021BA270(void *p);
void func_021BA280(void *a, void *b);
void func_021BA2B8(int unused, int v);
void func_021BA2C4(void *a0, u8 *p);
void func_021BA8C4(u16 *a0, char *p);
int func_021BA9EC(void *a0, char *p);
void func_021BAE58(void *p, u8 *q);
void func_021BAEE0(void *ctx, u8 *p);
void func_021BB288(void *ctx, u8 *p);
void func_021BB4D0(void *unused, u8 *q);
void func_021BB54C(void *ctx, u8 *p);
void func_021BB65C(void *ctx, u8 *p, int k);
int func_021BB8F4(void *a0, int *out);
void func_021BB938(void *p, u8 *q, int id);
void func_021BB9E4(void *a0, char *a1);
extern s16 d_020A1B38[];
extern const u8 d_021C6FF8[];
extern const u8 d_021C7014[];
extern const u32_021BAEE0 d_021C6FBC[];
extern const struct SpritePos d_021C7030;
extern const u8 d_021C6FDC[];
extern const u32_021BAEE0 d_021C6FC8[];
extern const struct SpritePos d_021C7034;
extern const struct SpritePos d_021C7038;
extern const struct SpritePos d_021C703C;
extern const u8 d_021C6FB2[];
extern const u8 d_021C6FB4[];
extern const u8 d_021C6FB6[];
extern const u8 d_021C6FB8[];


/*
 * Zero-fills a byte buffer, then runs func_021B6A00 over it.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA174(int unused, void *a, void *buf, unsigned n)
{
    func_02082BCC(buf, 0, n);
    return func_021B6A00(a, n, buf);
}


int func_021BA194(int unused, int a, void *buf, unsigned n)
{
    func_02082A7C(0, buf, n << 2);
    return func_021B6A18(a, (int)n, (int)buf);
}


void func_021BA1B4(char *p, u32_021BA1B4 a1)
{
    u32_021BA1B4 v = func_02072A44(7);

    ((struct Obj05447 *)p)->f20 = v;
    if (v == 0) {
        func_02034714((void *)0x021C7224, 0, (void *)0x021C7224);
    }
    ((struct Obj05447 *)p)->fC = 0;
}


void func_021BA1D8(void *p)
{
    func_02072A88((u32_021BA1D8 *)((struct Obj24096 *)p)->f20);
}


void func_021BA1E4(void *a0)
{
}


/*
 * Starts a sample on the channel at +0x20 when n > 0x20; records the handle and span.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq)
{
    if (n > 0x20) {
        int r = func_02072AA0((void *)self[8], 1, buf + 0x800, 0, 0, (int)(n >> 1), 0x1FF4, vol, freq, 0x40);
        self[3] = r;
        self[5] = 0;
        self[6] = (int)n;
        self[7] = freq;
        return r;
    }
    return 0;
}

void func_021BA234(void *p)
{
    ((struct Obj04555 *)p)->fC = 0;
    func_02072BDC(*(Slot02072BDC * *)&((struct Obj04555 *)p)->f20);
}


u32_021BA244 func_021BA244(void *p)
{
    return ((struct Obj24097 *)p)->fC;
}


int func_021BA248(void *p)
{
    return ((struct Obj24098 *)p)->f18;
}


int func_021BA24C(void *p)
{
    return (u16)((struct Obj24099 *)p)->f14;
}


int func_021BA254(void *p)
{
    return (u16)func_0209C2B0(((struct Obj14306 *)p)->f18 << 15,
                              ((struct Obj14306 *)p)->f1C * 0x10e);
}


/*
 * Test the byte at +0x10 against 0xb4, unsigned.
 *
 * Addresses are Black-image addresses.
 */
int func_021BA270(void *p)
{
    if (((struct Obj24100 *)p)->f10 >= 0xb4) {
        return 1;
    }
    return 0;
}


/*
 * Allocates the 0x98-byte record and seeds its counters.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA280(void *a, void *b)
{
    char *v = func_02030734((u32_021BA280)b, 0x98, 1, (void *)0x021C7228, 0xcf);

    v[0x36] = 0;
    v[0x37] = 3;
    ((struct Obj06562 *)v)->f28 = 0;
    ((struct Obj06562 *)v)->f24 = 0;
    ((struct Obj06562 *)v)->f34 = 0x8000;
}


void func_021BA2B8(int unused, int v)
{
    func_020307B0((void *)v);
}


/*
 * Scene constructor: loads the bank, builds fifteen sprite/button objects
 * from one descriptor, opens the text window and clears the state words.
 *
 * Addresses are Black-image addresses.
 */
void func_021BA2C4(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u8 i;
    void *bank;
    void *s;
    u32_021BA2C4 t1;
    u32_021BA2C4 t3;

    v = func_021BE00C(a0);
    func_020498F4((void *)func_021BE010(a0), 0x10, 7, 0, 0, 0, v);
    func_020409B4(7);
    func_02040588(5, 0);
    {
        u32_021BA2C4 t = *(volatile u16 *)0x04000304;
        *(volatile u16 *)0x04000304 = t & 0xFFFF7FFF;
    }
    bank = func_020490F4(func_020275E4(), v);
    func_020414EC(0);
    func_02049990(bank, func_0202762C(), 0, 0x60, 0, 0x600, 0, v);
    func_020413B0(0, 0, 0x15, 0x20, 3, 0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    func_02049238(bank);
    d.x = 0x10;
    d.y = 0xcc;
    d.z = 1;
    d.a = 8;
    d.b = 0;
    ((struct Obj00276 *)p)->f58 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x38;
    d.z = 0x3;
    ((struct Obj00276 *)p)->f5C = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x60;
    d.z = 0x5;
    ((struct Obj00276 *)p)->f60 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x88;
    d.z = 0x7;
    ((struct Obj00276 *)p)->f64 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xc8;
    if (func_021BE0B4(a0) == 1) {
        d.z = 0xc;
    } else {
        d.z = 0xa;
    }
    ((struct Obj00276 *)p)->f68 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xe0;
    d.y = 0xc0;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f6C = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 7), func_021BE018(a0, 3), func_021BE018(a0, 10), &d, 0, v);
    func_0204B92C((struct Obj *)((struct Obj00276 *)p)->f6C, 1);
    for (i = 0; i < 6; i++) {
        func_0204B3DC((struct Obj *)*(u32_021BA2C4 *)(p + i * 4 + 0x58), 1);
    }
    d.x = 0x38;
    d.y = 0x48;
    d.z = 0xe;
    ((struct Obj00276 *)p)->f70 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x5c;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f74 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x70;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f78 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x84;
    d.z = 0x11;
    ((struct Obj00276 *)p)->f7C = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.x = 0x2c;
    d.y = 0x8c;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f80 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 6), func_021BE018(a0, 2), func_021BE018(a0, 10), &d, 1, v);
    for (i = 0; i < 5; i++) {
        func_0204B3DC((struct Obj *)*(u32_021BA2C4 *)(p + i * 4 + 0x70), 0);
    }
    d.x = 0x10;
    d.y = 0xa0;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f84 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f84, 0);
    d.x = 0x88;
    d.y = 0xa0;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f88 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f88, 0);
    d.a = 0;
    ((struct Obj00276 *)p)->f8C = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f8C, 0);
    d.z = 0x19;
    d.a = 2;
    ((struct Obj00276 *)p)->f90 = (u32_021BA2C4)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f90, 0);
    func_021BB54C(a0, p);
    ((struct Obj00276 *)p)->f48 = 0;
    ((struct Obj00276 *)p)->f50 = 0;
    t1 = func_021BE034(a0);
    s = (void *)func_021BE03C(a0);
    t3 = func_021BE044(a0);
    *(u32_021BA2C4 *)&((struct Obj00276 *)p)->f4C = (u32_021BA2C4)func_020450F0(4, 3, 1, 0x1c, 2, 0xa, 1);
    func_02043B5C((struct CharBuf *)((u32_021BA2C4)func_02045770(((struct Obj00276 *)p)->f4C)), 0);
    s = func_02045EC0(s, 0xb);
    func_0201C724((void *)t3, (u32_021BA2C4)func_02045770(((struct Obj00276 *)p)->f4C), 1, 0, (u32_021BA2C4)s, t1, 0x440);
    func_02045808(s);
    ((struct Obj00276 *)p)->f40 = 1;
    ((struct Obj00276 *)p)->f0 = 0;
    p[4] = 0x18;
    p[5] = 0x18;
    ((struct Obj00276 *)p)->f96 = 0;
    ((struct Obj00276 *)p)->fC = 0;
    ((struct Obj00276 *)p)->f8 = 0;
    ((struct Obj00276 *)p)->f10 = 0;
    ((struct Obj00276 *)p)->f14 = 0;
    ((struct Obj00276 *)p)->f38 = 0;
    ((struct Obj00276 *)p)->f44 = 0;
    ((struct Obj00276 *)p)->f18 = 0;
    ((struct Obj00276 *)p)->f1C = 0;
    ((struct Obj00276 *)p)->f20 = 0;
    *(volatile u16 *)0x0500021A = ((struct Obj00276 *)p)->f34 & 0x7fff;
    func_021BB65C(a0, p, 0);
    func_0203D34C(1, v);
    func_021BE2E0(a0);
}


void func_021BA8C4(u16 *a0, char *p)
{
    u32_021BA8C4 r;
    u8 i;
    u16 v;

    v = func_021BE00C(a0);
    if (((struct Obj01265 *)p)->f28 == 1) {
        ((struct Obj01265 *)p)->f28 = (((struct Obj01265 *)p)->f24 == 0) ? 0 : 3;
    }
    r = 0;
    func_0203D34C(0, v);
    func_0201F7A8((void *)(((struct Obj01265 *)p)->f48), 0);
    r = ((struct Obj01265 *)p)->f48;
    func_020456F8((struct Descriptor *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    func_020452E8((struct Descriptor *)(((struct Obj01265 *)p)->f48));
    r = ((struct Obj01265 *)p)->f4C;
    func_020456F8((struct Descriptor *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    func_020452E8((struct Descriptor *)(((struct Obj01265 *)p)->f4C));
    r = ((struct Obj01265 *)p)->f50;
    if (r != 0) {
        func_020456F8((struct Descriptor *)r);
        func_020409B4(func_02045730((struct Descriptor *)r));
        func_020452E8((struct Descriptor *)(((struct Obj01265 *)p)->f50));
        ((struct Obj01265 *)p)->f50 = 0;
    }
    for (i = 0; i < 5; i++) {
        func_0204B3B4((struct Obj *)(*(u32_021BA8C4 *)(p + i * 4 + 0x70)));
    }
    for (i = 0; i < 6; i++) {
        func_0204B3B4((struct Obj *)(*(u32_021BA8C4 *)(p + i * 4 + 0x58)));
    }
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f90));
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f8C));
    func_0204B3DC((struct Obj *)((struct Obj01265 *)p)->f88, 0);
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f88));
    func_0204B3DC((struct Obj *)((struct Obj01265 *)p)->f84, 0);
    func_0204B3B4((struct Obj *)(((struct Obj01265 *)p)->f84));
    func_020414EC(0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_021BE1A4((char *)a0);
}


/*
 * 2026-10-02 (lane C1-04): byte-correct; one relocation wildcarded.
 * is `ldr r0, [r0, #0x10]; bx lr`, 021BE030 is the paired setter
 * `str r1, [r0, #0x10]; bx lr`; both missing from the layout, a figure
 * move). The only other file for that address is ov203's unrelated function.
 * The +0x96 wrap-around reload is a volatile read in the else arm.
 *
 * Scene state machine, one switch on the state word at +0, then the
 * per-frame tail (window release checks, key handling, colour fade).
 *
 * Addresses are Black-image addresses.
 */
int func_021BA9EC(void *a0, char *p)
{
    u32_021BA9EC v;
    u32_021BA9EC flag;
    u32_021BA9EC z;
    u8 i;
    u32_021BA9EC t;
    u32_021BA9EC s;
    u32_021BA9EC k;

    v = func_021BE00C(a0);
    z = 0;
    ((struct Obj00140 *)p)->f8 = z;
    switch (((struct Obj00140 *)p)->f0) {
    case 0:
        if (func_021BE02C(a0) == 1) {
            func_0202208C((void *)z, 1, 1, z, 6, 1, v);
        } else {
            func_0202208C((void *)4, 1, 1, z, 6, 1, v);
        }
        ((struct Obj00140 *)p)->f0 = 1;
        break;
    case 1:
        if (func_020221A4() == 1) {
            ((struct Obj00140 *)p)->f18 = 1;
            ((struct Obj00140 *)p)->f0 = 4;
        }
        break;
    case 2:
        t = func_021BDFDC(a0);
        if (((struct Obj00140 *)p)->f20 != 0) {
            if (func_021B7590((int)a0, (char *)t) != 1) {
                break;
            }
        }
        func_0202208C(0, 0, 0, 0, 6, 1, v);
        ((struct Obj00140 *)p)->f0 = 3;
        ((struct Obj00140 *)p)->f18 = 0;
        break;
    case 3:
        if (func_020221A4() == 1) {
            if (((struct Obj00140 *)p)->f1C == 0) {
                return 1;
            }
            return 4;
        }
        break;
    case 4:
        if (func_021BB8F4(a0, (int *)p) == 0) {
            func_021BAE58(a0, (u8 *)p);
        }
        break;
    case 5:
        if (func_021BB8F4(a0, (int *)p) == 0) {
            func_021BAEE0(a0, (u8 *)p);
        }
        break;
    case 6:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x24);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 7;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 7:
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    case 8:
        if (func_021B8740((int)a0, func_021BDFE4(a0), 10, z) == 1) {
            ((struct Obj00140 *)p)->f0 = 9;
        }
        break;
    case 9:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x25);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 10;
        ((struct Obj00140 *)p)->f54 = z;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 10:
        ((struct Obj00140 *)p)->f54 = ((struct Obj00140 *)p)->f54 + 1;
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0
            || ((struct Obj00140 *)p)->f54 >= 300) {
            ((struct Obj00140 *)p)->f0 = 11;
        }
        break;
    case 11:
        func_021B8B34(a0, func_021BDFE4(a0), 0x2f);
        ((struct Obj00140 *)p)->f0 = 12;
        break;
    case 12:
        if (func_021B8B48(a0, func_021BDFE4(a0), 0x2f) == 1) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    case 13:
        func_021B8084(a0, (char *)func_021BDFE4(a0));
        func_021BB938(a0, (u8 *)p, 0x26);
        flag = 1;
        func_021BE0B0(a0, 1);
        ((struct Obj00140 *)p)->f0 = 14;
        func_021B7B80((int)a0, (char *)func_021BDFDC(a0));
        ((struct Obj00140 *)p)->f20 = flag;
        break;
    case 14:
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            ((struct Obj00140 *)p)->f1C = flag = 1;
            ((struct Obj00140 *)p)->f0 = 2;
            func_021BE0B0(a0, 1);
            func_021B7578((int)a0, (char *)func_021BDFDC(a0));
            ((struct Obj00140 *)p)->f20 = flag;
        }
        break;
    }
    func_021BB4D0(a0, (u8 *)p);
    if (((struct Obj00140 *)p)->f18 == 1) {
        func_021BB288(a0, (u8 *)p);
    }
    if (((struct Obj00140 *)p)->f38 == 1) {
        t = func_021BE044(a0);
        if (func_0201C6C4((struct PrintSys *)t, (void *)((u32_021BA9EC)func_02045770((struct Descriptor *)((struct Obj00140 *)p)->f48))) == 0) {
            func_0201F73C((void *)(((struct Obj00140 *)p)->f48), 2, 0x140, 9);
            func_02045334((struct Descriptor *)((struct Obj00140 *)p)->f48);
            func_02045374((struct Cfg *)(((struct Obj00140 *)p)->f48));
            func_02041B6C(4);
            i = 0;
            ((struct Obj00140 *)p)->f38 = 0;
            if (((struct Obj00140 *)p)->f3C == 1) {
                k = 1;
                for (i = 0; i < 5; i++) {
                    func_0204B3DC((struct Obj *)*(u32_021BA9EC *)(p + i * 4 + 0x70), k);
                }
            } else {
                k = i;
                for (i = 0; i < 5; i++) {
                    func_0204B3DC((struct Obj *)*(u32_021BA9EC *)(p + i * 4 + 0x70), k);
                }
            }
        }
    }
    if (((struct Obj00140 *)p)->f40 == 1) {
        t = func_021BE044(a0);
        if (func_0201C6C4((struct PrintSys *)t, (void *)((u32_021BA9EC)func_02045770((struct Descriptor *)((struct Obj00140 *)p)->f4C))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj00140 *)p)->f4C);
            func_02045374((struct Cfg *)(((struct Obj00140 *)p)->f4C));
            func_020409B4(4);
            ((struct Obj00140 *)p)->f40 = 0;
        }
    }
    if (((struct Obj00140 *)p)->f44 == 1 && ((struct Obj00140 *)p)->f50 != 0) {
        t = func_021BE044(a0);
        if (func_0201C6C4((struct PrintSys *)t, (void *)((u32_021BA9EC)func_02045770((struct Descriptor *)((struct Obj00140 *)p)->f50))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj00140 *)p)->f50);
            func_02045374((struct Cfg *)(((struct Obj00140 *)p)->f50));
            func_020409B4(0);
            ((struct Obj00140 *)p)->f44 = 0;
        }
    }
    if (*(s32 *)&((struct Obj00140 *)p)->f0 <= 5 && func_021BE0B4(a0) == 0) {
        v = func_021BDFDC(a0);
        if (func_020362DC() & 0x40) {
            func_021B7B3C((int)a0, v, 0);
        }
        if (func_020362DC() & 0x10) {
            func_021B7B3C((int)a0, v, 5);
        }
        if (func_020362DC() & 0x80) {
            func_021B7B3C((int)a0, v, 1);
        }
        if (func_020362DC() & 0x20) {
            func_021B7B3C((int)a0, v, 3);
        }
    }
    if (func_021BE0A4(a0) == 0 && (func_020362DC() & 0x200)) {
        if (func_021B77B4((int)a0, (void *)func_021BDFDC(a0)) == 0) {
            func_021BE08C(a0);
            func_020061E4(0x66C);
        }
    }
    t = *(volatile u16 *)&((struct Obj00140 *)p)->f96;
    ((struct Obj00140 *)p)->f96 = ((s32)(t + 0x400) >= 0x10000) ? t - 0xFC00 : *(volatile u16 *)&((struct Obj00140 *)p)->f96 + 0x400;
    s = d_020A1B38[(((struct Obj00140 *)p)->f96 >> 4) * 2 + 1];
    s = (s16)((s32)(s + 0x1000) / 2);
    s = (u8)(((s32)s * -9 >> 12) + 0x1c);
    ((struct Obj00140 *)p)->f94 = s | (s << 5) | (s << 10);
    func_02061CA4((void *)0xe, 0xde, (u32_021BA9EC)(p + 0x94), 2);
    return 3;
}

void func_021BAE58(void *p, u8 *q)
{
    if ((func_020362DC() & 1024) && ((struct Obj00024 *)q)->f38 == 0) {
        if (func_0204B98C(*(struct Actor * *)&((struct Obj00024 *)q)->f6C) == 0 ||
            func_0204B898(*(struct Obj * *)&((struct Obj00024 *)q)->f6C) == 1) {
            *(u32_021BAE58 *)&((struct Obj00024 *)q)->f0 = 5;
            q[4] = 0;
            func_021BB65C(p, q, 1);
            func_0204B878(*(struct Obj * *)&((struct Obj00024 *)q)->f6C, 1);
            func_020061E4(1644);
        }
    } else if (func_020362DC() & 2) {
        *(u32_021BAE58 *)&((struct Obj00024 *)q)->f0 = 2;
        func_020061E4(1361);
    }
    if (func_020362DC() & 12) {
        func_021BE0B8(p);
        func_021BB54C(p, q);
        func_020061E4(1647);
    }
}


void func_021BAEE0(void *ctx, u8 *p)
{
    struct SpritePos pa;
    struct SpritePos pb;
    struct SpritePos pc;
    struct SpritePos pd;
    int k;
    int j;

    k = func_02035C08(d_021C6FF8);
    if (k == 0 && func_0204B3F4(((struct Obj00024 *)p)->f8C) == 0) {
        ((struct Obj00024 *)p)->f28 = 0;
        ((struct Obj00024 *)p)->f24 = 0;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        ((struct Obj00024 *)p)->f10 = 1;
        func_0204B3DC(((struct Obj00024 *)p)->f84, 1);
        func_0204B92C(((struct Obj00024 *)p)->f84, 1);
        func_020061E4(0x66c);
    }
    if (k == 1) {
        ((struct Obj00024 *)p)->f28 = 1;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        func_020061E4(0x66c);
    }
    if (k == 2) {
        ((struct Obj00024 *)p)->f28 = 2;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        func_020061E4(0x66c);
    }
    if (k == 3 && func_0204B3F4(((struct Obj00024 *)p)->f8C) == 0) {
        ((struct Obj00024 *)p)->f28 = 3;
        ((struct Obj00024 *)p)->f24 = 1;
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        ((struct Obj00024 *)p)->f14 = 1;
        func_0204B3DC(((struct Obj00024 *)p)->f88, 1);
        func_0204B92C(((struct Obj00024 *)p)->f88, 1);
        func_020061E4(0x66c);
    }
    if (k == 4) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        ((struct Obj00024 *)p)->f8 = 1;
        func_020061E4(0x66f);
    }
    if (((struct Obj00024 *)p)->f10 == 1) {
        j = func_02035C08(d_021C7014);
        if (j != -1) {
            p[0x36] = d_021C6FBC[j];
            ((struct Obj00024 *)p)->f8 = 1;
            pa = d_021C7030;
            func_0204B3DC(((struct Obj00024 *)p)->f8C, 1);
            func_0204B9A0(((struct Obj00024 *)p)->f8C);
            func_0204B92C(((struct Obj00024 *)p)->f8C, 1);
            func_0204B878(((struct Obj00024 *)p)->f8C, (u16)(j + 0x11));
            func_0204B404(((struct Obj00024 *)p)->f8C, (const struct Vec2 *)(&pa), 0);
            func_0204B3DC(((struct Obj00024 *)p)->f90, 0);
            func_020061E4(0x66c);
        }
    }
    if (((struct Obj00024 *)p)->f14 == 1) {
        j = func_02035C08(d_021C6FDC);
        if (j != -1) {
            p[0x37] = d_021C6FC8[j];
            ((struct Obj00024 *)p)->f8 = 1;
            func_020061E4(0x66c);
            pb = d_021C7034;
            func_0204B3DC(((struct Obj00024 *)p)->f8C, 1);
            func_0204B9A0(((struct Obj00024 *)p)->f8C);
            func_0204B92C(((struct Obj00024 *)p)->f8C, 1);
            func_0204B878(((struct Obj00024 *)p)->f8C, (u16)(j + 0x14));
            func_0204B404(((struct Obj00024 *)p)->f8C, (const struct Vec2 *)(&pb), 0);
            func_0204B3DC(((struct Obj00024 *)p)->f90, 0);
        }
    }
    if ((func_020362DC() & 0x400) || (func_020362DC() & 2) || k == 5) {
        if (*(int *)&((struct Obj00024 *)p)->f38 == 0) {
            ((struct Obj00024 *)p)->f0 = 4;
            p[4] = 0x18;
            ((struct Obj00024 *)p)->f8 = 1;
            func_021BB65C(ctx, p, 0);
            func_021BB9E4(ctx, (char *)p);
            func_020061E4(0x551);
            func_0204B878(((struct Obj00024 *)p)->f6C, 9);
        }
    }
    if (func_020362DC() & 0xc) {
        func_021BE0B8(ctx);
        func_021BB54C(ctx, p);
        func_020061E4(0x66f);
    }
    if (func_0204B3F4(((struct Obj00024 *)p)->f8C) == 1 && func_0204B98C(((struct Obj00024 *)p)->f8C) == 0) {
        func_021BB9E4(ctx, (char *)p);
    }
    if (((struct Obj00024 *)p)->f10 == 1 && func_0204B98C(((struct Obj00024 *)p)->f84) == 0 && func_0204B3F4(((struct Obj00024 *)p)->f90) == 0) {
        pc = d_021C7038;
        switch (p[0x36]) {
        case 1:
            pc.x = pc.x + 0x10;
            break;
        case 0:
            pc.x = pc.x + 0x20;
            break;
        case 2:
            break;
        }
        func_0204B404(((struct Obj00024 *)p)->f90, (const struct Vec2 *)(&pc), 0);
        func_0204B3DC(((struct Obj00024 *)p)->f90, 1);
    }
    if (((struct Obj00024 *)p)->f14 == 1 && func_0204B98C(((struct Obj00024 *)p)->f88) == 0 && func_0204B3F4(((struct Obj00024 *)p)->f90) == 0) {
        pd = d_021C703C;
        switch (p[0x37]) {
        case 3:
            pd.x = pd.x - 0x20;
            break;
        case 4:
            pd.x = pd.x - 0x10;
            break;
        case 6:
            pd.x = pd.x + 0x10;
            break;
        case 7:
            pd.x = pd.x + 0x20;
            break;
        }
        func_0204B404(((struct Obj00024 *)p)->f90, (const struct Vec2 *)(&pd), 0);
        func_0204B3DC(((struct Obj00024 *)p)->f90, 1);
    }
}


void func_021BB288(void *ctx, u8 *p)
{
    u32_021BB288 x;
    u32_021BB288 y;
    int out1;
    u32_021BB288 x2;
    u32_021BB288 y2;
    int out2;
    u32_021BB288 s2;
    u32_021BB288 s1;
    u32_021BB288 base;
    u16 *pb;
    u32_021BB288 off;
    u32_021BB288 a2;
    u32_021BB288 v1;
    u32_021BB288 v2;
    u8 mode;
    u32_021BB288 base2;
    u8 *e;
    u32_021BB288 cur;

    func_02035D20(&x, &y);
    if (func_021BE0C8(ctx) == 1) {
        return;
    }
    if (func_02035C38() == 0) {
        ((struct Obj00024 *)p)->fC = 0;
    }
    if (func_02035C60() == 1 && ((struct Obj00024 *)p)->f8 == 0 && ((struct Obj00024 *)p)->f0 == 5 && y >= 0xa8) {
        if (((struct Obj00024 *)p)->f28 == 1) {
            ((struct Obj00024 *)p)->f28 = (((struct Obj00024 *)p)->f24 == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
        }
        func_021BB9E4(ctx, (char *)p);
        return;
    }
    if ((u32_021BB288)(((struct Obj00024 *)p)->f0 - 4) <= 1 && func_02035C60() == 1 && ((struct Obj00024 *)p)->f8 == 0 && ((struct Obj00024 *)p)->f28 == 3) {
        mode = func_021BE054(ctx);
        cur = func_021BDFE4(ctx);
        s1 = func_021BDFFC(ctx);
        e = (u8 *)func_021B8BB8((int)ctx, (unsigned char *)cur, &out1);
        if (out1 == 0) {
            e[0] = x;
            e[1] = y;
            e[2] = x;
            e[3] = y;
            e[6] = p[0x37];
            ((struct Obj01757 *)e)->f4 = ((struct Obj00024 *)p)->f34;
            if (mode == 1) {
                func_021B6E88((char *)s1, e);
            } else {
                func_021B8BFC((int)ctx, (u8 *)cur);
            }
        }
    }
    if (func_02035C60() == 1 && ((struct Obj00024 *)p)->f8 == 0) {
        if (((struct Obj00024 *)p)->f28 == 1) {
            pb = (u16 *)func_0207E008();
            off = y << 9;
            base = (x << 1) + (u32_021BB288)pb;
            func_0207E100();
            if (func_021BE078(ctx) == 1) {
                a2 = ((y >> 1) << 9) + ((x & ~1) + func_0207E100());
            } else {
                a2 = (y << 9) + ((x << 1) + func_0207E100());
            }
            v1 = *(u16 *)(off + base);
            if (v1 & 0x8000) {
                ((struct Obj00024 *)p)->f34 = v1;
            } else {
                v2 = ((struct Obj24101 *)a2)->f0;
                if (v2 & 0x8000) {
                    ((struct Obj00024 *)p)->f34 = v2;
                } else {
                    ((struct Obj00024 *)p)->f34 = 0x8000;
                }
            }
            *(volatile u16 *)0x0500021A = ((struct Obj00024 *)p)->f34 & 0x7fff;
            ((struct Obj00024 *)p)->f28 = (((struct Obj00024 *)p)->f24 == 0) ? 0 : 3;
            func_021BB54C(ctx, p);
            func_020061E4(0x66d);
        } else {
            ((struct Obj00024 *)p)->fC = 1;
            ((struct Obj00024 *)p)->f2C = 0xffff;
            ((struct Obj00024 *)p)->f30 = 0xffff;
            func_021BB9E4(ctx, (char *)p);
        }
    }
    if ((((struct Obj00024 *)p)->f28 == 0 || ((struct Obj00024 *)p)->f28 == 2) && ((struct Obj00024 *)p)->fC == 1) {
        func_02035CB8(&x2, &y2);
        if (((struct Obj00024 *)p)->fC == 1) {
            if (((struct Obj00024 *)p)->f2C != 0xffff && ((struct Obj00024 *)p)->f30 != 0xffff) {
                mode = func_021BE054(ctx);
                cur = func_021BDFE4(ctx);
                s2 = func_021BDFFC(ctx);
                e = (u8 *)func_021B8BB8((int)ctx, (unsigned char *)cur, &out2);
                if (out2 == 0) {
                    e[0] = ((struct Obj00024 *)p)->f2C;
                    e[1] = ((struct Obj00024 *)p)->f30;
                    e[2] = x2;
                    e[3] = y2;
                    e[6] = p[0x36];
                    if (((struct Obj00024 *)p)->f28 == 2) {
                        ((struct Obj01757 *)e)->f4 = 0;
                        e[6] = 2;
                    } else {
                        ((struct Obj01757 *)e)->f4 = ((struct Obj00024 *)p)->f34;
                    }
                    if (mode == 1) {
                        func_021B6E88((char *)s2, e);
                    } else {
                        func_021B8BFC((int)ctx, (u8 *)cur);
                    }
                } else {
                    ((struct Obj00024 *)p)->fC = 0;
                }
            }
            ((struct Obj00024 *)p)->f2C = x2;
            ((struct Obj00024 *)p)->f30 = y2;
        }
    }
}

void func_021BB4D0(void *unused, u8 *q)
{
    s16 pos[2];
    u8 i;
    int changed = 0;
    if (func_0204B98C(*(struct Actor * *)&((struct Obj02880 *)q)->f6C) == 0 ||
        func_0204B898(*(struct Obj * *)&((struct Obj02880 *)q)->f6C) == 1) {
        if ((u8)q[4] < (u8)q[5]) { q[5] -= 24; changed = 1; }
        else if ((u8)q[4] > (u8)q[5]) { q[5] += 24; changed = 1; }
    }
    if (changed == 1) {
        func_02041EE4(0, 3, 24 - (u8)q[5]);
        for (i = 0; i < 6; i++) {
            u8 *element = q + i * 4;
            func_0204B454(*(struct Actor * *)&((struct Obj14307 *)element)->f58, (struct PtS *)pos, 0);
            pos[1] = q[5] + 180;
            if (i == 5) pos[1] -= 12;
            func_0204B404((struct Obj *)(*(struct Actor * *)&((struct Obj14307 *)element)->f58), (const struct Vec2 *)pos, 0);
        }
    }
}


void func_021BB54C(void *ctx, u8 *p)
{
    int r;

    func_0204B878(((struct Obj00024 *)p)->f58, d_021C6FB2[((struct Obj00024 *)p)->f28 == 0]);
    func_0204B878(((struct Obj00024 *)p)->f5C, d_021C6FB4[((struct Obj00024 *)p)->f28 == 1]);
    func_0204B878(((struct Obj00024 *)p)->f60, d_021C6FB6[((struct Obj00024 *)p)->f28 == 2]);
    func_0204B878(((struct Obj00024 *)p)->f64, d_021C6FB8[((struct Obj00024 *)p)->f28 == 3]);
    r = func_021BE0B4(ctx);
    if (r == 1) {
        func_0204B878(((struct Obj00024 *)p)->f68, 12);
    } else {
        func_0204B878(((struct Obj00024 *)p)->f68, 10);
    }
    if (((struct Obj00024 *)p)->f28 != 0 && ((struct Obj00024 *)p)->f10 == 1) {
        ((struct Obj00024 *)p)->f10 = 0;
        func_0204B3DC(((struct Obj00024 *)p)->f84, 0);
        func_0204B9A0(((struct Obj00024 *)p)->f84);
        func_0204B8C4(((struct Obj00024 *)p)->f84, 0);
        func_0204B92C(((struct Obj00024 *)p)->f84, 0);
        func_0204B3DC(((struct Obj00024 *)p)->f90, 0);
    }
    if (((struct Obj00024 *)p)->f28 != 3 && ((struct Obj00024 *)p)->f14 == 1) {
        ((struct Obj00024 *)p)->f14 = 0;
        func_0204B3DC(((struct Obj00024 *)p)->f88, 0);
        func_0204B9A0(((struct Obj00024 *)p)->f88);
        func_0204B8C4(((struct Obj00024 *)p)->f88, 0);
        func_0204B92C(((struct Obj00024 *)p)->f88, 0);
        func_0204B3DC(((struct Obj00024 *)p)->f90, 0);
    }
}


void func_021BB65C(void *ctx, u8 *p, int k)
{
    void *last;
    void *w8;
    void *w7;
    void *w6;
    void *w5;
    void *w4;
    void *w3;
    void *w2;
    void *w1;
    void *w0;
    void *old;
    void *h3c;
    void *h44;
    u32_021BB65C h34;

    h34 = func_021BE034(ctx);
    h3c = (void *)func_021BE03C(ctx);
    h44 = (void *)func_021BE044(ctx);
    old = ((struct Obj00836 *)p)->f48;
    if (old != 0) {
        func_0201C6EC(h44);
        func_0201F7A8(((struct Obj00836 *)p)->f48, 2);
        func_020456F8(((struct Obj00836 *)p)->f48);
    }
    ((struct Obj00836 *)p)->f3C = k;
    if (k == 1) {
        ((struct Obj00836 *)p)->f48 = (void *)func_020450F0(4, 2, 8, 0x1c, 0xd, 0xa, 1);
        func_02043B5C(func_02045770(((struct Obj00836 *)p)->f48), 0xf);
        func_02045334(((struct Obj00836 *)p)->f48);
        w0 = func_02045EC0(h3c, 6);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x40, 0x4, (u32_021BB65C)w0, h34, 0x440);
        func_02045808(w0);
        w1 = func_02045EC0(h3c, 7);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x40, 0x18, (u32_021BB65C)w1, h34, 0x440);
        func_02045808(w1);
        w2 = func_02045EC0(h3c, 8);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x40, 0x2c, (u32_021BB65C)w2, h34, 0x440);
        func_02045808(w2);
        w3 = func_02045EC0(h3c, 10);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x40, 0x40, (u32_021BB65C)w3, h34, 0x440);
        func_02045808(w3);
        last = func_02045EC0(h3c, 9);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x40, 0x54, (u32_021BB65C)last, h34, 0x440);
        func_02045808(last);
    } else {
        ((struct Obj00836 *)p)->f48 = (void *)func_020450F0(4, 2, 0x10, 0x1c, 6, 0xa, 1);
        func_02043B5C(func_02045770(((struct Obj00836 *)p)->f48), 0xf);
        func_02045334(((struct Obj00836 *)p)->f48);
        w4 = func_02045EC0(h3c, 0);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x8, 0x0, (u32_021BB65C)w4, h34, 0x440);
        func_02045808(w4);
        w5 = func_02045EC0(h3c, 1);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x8, 0x10, (u32_021BB65C)w5, h34, 0x440);
        func_02045808(w5);
        w6 = func_02045EC0(h3c, 2);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x8, 0x20, (u32_021BB65C)w6, h34, 0x440);
        func_02045808(w6);
        w7 = func_02045EC0(h3c, 3);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x50, 0x0, (u32_021BB65C)w7, h34, 0x440);
        func_02045808(w7);
        w8 = func_02045EC0(h3c, 4);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x50, 0x10, (u32_021BB65C)w8, h34, 0x440);
        func_02045808(w8);
        last = func_02045EC0(h3c, 5);
        func_0201C724(h44, (u32_021BB65C)func_02045770(((struct Obj00836 *)p)->f48), 0x50, 0x20, (u32_021BB65C)last, h34, 0x440);
        func_02045808(last);
    }
    ((struct Obj00836 *)p)->f38 = 1;
    if (old != 0) {
        func_020452E8(old);
    }
}


/*
 * Maps the +4 state to an output code through the two ARM9 probes, 9/6/0xd.
 *
 * Addresses are Black-image addresses.
 */
int func_021BB8F4(void *a0, int *out)
{
    if (func_021BE0D0(a0) == 1) {
        int v = func_021B80E4((int)a0, (char *)func_021BDFE4(a0));

        *out = (v == 5) ? 9 : 6;
        return 1;
    }
    if (func_021BE054(a0) <= 1) {
        *out = 0xd;
        return 1;
    }
    return 0;
}

void func_021BB938(void *p, u8 *q, int id)
{
    u32_021BB938 font = func_021BE034(p);
    u32_021BB938 msgs = func_021BE03C(p);
    u32_021BB938 sys = func_021BE044(p);
    u32_021BB938 text;
    if (*(u32_021BB938 *)&((struct Obj02881 *)q)->f50 != 0) func_020452E8(((struct Obj02881 *)q)->f50);
    *(u32_021BB938 *)&((struct Obj02881 *)q)->f50 = func_020450F0(0, 1, q[4] == 0 ? 4 : 1, 30, 4, 10, 1);
    func_0201C6EC((struct PrintSys *)sys);
    func_02043B5C((struct CharBuf *)((u32_021BB938)func_02045770((struct Descriptor *)*(u32_021BB938 *)&((struct Obj02881 *)q)->f50)), 15);
    text = (u32_021BB938)func_02045EC0((struct MsgBank *)msgs, id);
    func_0201C724((void *)sys, (u32_021BB938)func_02045770((struct Descriptor *)*(u32_021BB938 *)&((struct Obj02881 *)q)->f50), 0, 0, text, font, 1088);
    func_02045808((struct U16Vec *)text);
    func_02045334((struct Descriptor *)*(u32_021BB938 *)&((struct Obj02881 *)q)->f50);
    func_02045374((struct Cfg *)(*(u32_021BB938 *)&((struct Obj02881 *)q)->f50));
    func_0201F73C((void *)(*(u32_021BB938 *)&((struct Obj02881 *)q)->f50), 1, 512, 9);
    ((struct Obj02881 *)q)->f44 = 1;
}


/*
 * Clears +0x10/+0x14 then runs the 0x84/0x88/0x8c/0x90 handles through the five
 * resource teardown entry points.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB9E4(void *a0, char *a1)
{
    *(u32_021BB9E4 *)&((struct Obj00024 *)a1)->f10 = 0;
    *(u32_021BB9E4 *)&((struct Obj00024 *)a1)->f14 = 0;
    func_0204B9A0(((struct Obj00024 *)a1)->f84);
    func_0204B9A0(((struct Obj00024 *)a1)->f88);
    func_0204B9A0(((struct Obj00024 *)a1)->f8C);
    func_0204B8C4(((struct Obj00024 *)a1)->f84, 0);
    func_0204B8C4(((struct Obj00024 *)a1)->f88, 0);
    func_0204B92C(((struct Obj00024 *)a1)->f84, 0);
    func_0204B92C(((struct Obj00024 *)a1)->f88, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f84, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f88, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f8C, 0);
    func_0204B3DC(((struct Obj00024 *)a1)->f90, 0);
}
