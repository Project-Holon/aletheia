/*
 * file:     fld_trade_p06.c
 * unit:     yes
 * function: func_021CE934, func_021CE984, func_021CE9A0, func_021CE9E4, func_021CEA28, func_021CEA50, func_021CEA84, func_021CEAB0, func_021CEADC
 * address:  0x021CE934
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
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02008534  0x02008534  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190758  0x02190758  thumb  ov021
 *   func_02190794  0x02190794  thumb  ov021
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 */
#include "../../matched/include/Obj00011.h"

struct Sub0200852CObj;
struct WordSet;
struct Slot;
struct MsgBank;
struct P;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18, f1c, f20;
} S_021CE934;

typedef struct {
    u32 f0, f4, f8, fc, f10, f14, f18;
} S_021CE984;

typedef struct {
    u8 f0;
    u8 pad1[0x2B];
} Slot;

typedef struct {
    u8 pad0[0x70];
    Slot slots[4];
    u8 pad120[0x550 - 0x120];
    u8 f550[4];
} Work;

extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02190758(u32 a, u32 b, u32 c, u32 d);
extern void func_02190794(struct Slot **p, int x, int y, int w, int h);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_02190F7C(struct P *p);
extern void func_02190EB8(struct P *p, u32 b, u16 c, u32 d);
void func_021CE934(S_021CE934 *p, u32 b, u32 c);
void func_021CE984(u32 *p, u32 n);
void func_021CE9A0(u8 *p);
void func_021CE9E4(S_021CE984 *p, u32 m);
void func_021CEA28(Work *p);
int func_021CEA50(u8 *p);
void func_021CEA84(u8 *p, int n);
void func_021CEAB0(u8 *p);
u8 *func_021CEADC(u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021CE934(S_021CE934 *p, u32 b, u32 c)
{
    u32 n;

    if (p->fc != 0) {
        func_0201F02C((struct WordSet *)p->f4, 0, (void *)b);
        n = func_02008534((const struct Sub0200852CObj *)b);
        func_0201EFA4((struct WordSet *)p->f4, 1, n, 5, 2, 1);
        func_0201F250((struct WordSet *)p->f4, (void *)p->f20, (void *)p->f1c);
        func_02190758(p->fc, 0, (c & 0xfff) << 4, p->f20);
    }
}





void func_021CE984(u32 *p, u32 n)
{
    if (p[3] != 0) {
        func_02190794((struct Slot **)p[3], 0, n << 4, 0x90, 0x10);
    }
}





void func_021CE9A0(u8 *p)
{
    int i;

    if (p[0x518] != 0) {
        p[0x518] = 0;
        for (i = 0; i < 4; i++) {
            func_021CE984((u32 *)p, i);
            if (p[0x514] & (1 << i))
                func_021CE934((S_021CE934 *)p, (u32)(p + 0x494 + i * 32), (u8)i);
        }
    }
}





void func_021CE9E4(S_021CE984 *p, u32 m)
{
    u32 n;

    if (m == 8 && ((struct Obj00011 *)p)->f57A == 8)
        return;
    ((struct Obj00011 *)p)->f57A = m;
    n = (u32)func_02045EC0((struct MsgBank *)p->f8, m);
    func_0201F250((struct WordSet *)p->f4, (void *)p->f18, (void *)n);
    func_02045808((struct U16Vec *)n);
    func_02190F7C((struct P *)p->f14);
    func_02190EB8((struct P *)p->f14, 0, 0, p->f18);
}





void func_021CEA28(Work *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        p->f550[i] = p->slots[i].f0;
    }
}





int func_021CEA50(u8 *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (p[0x550 + i] != p[0x70 + i * 0x2c]) {
            return 0;
        }
    }
    return 1;
}




void func_021CEA84(u8 *p, int n)
{
    p[0x521] &= 0xff ^ (1 << n);
    p[0x522] &= 0xff ^ (1 << n);
}




void func_021CEAB0(u8 *p)
{
    if (p[0x523] == 1 || p[0x525] == 1) {
        p[0x524] = 1;
    } else {
        p[0x523] = 1;
        p[0x524] = 0;
    }
}




u8 *func_021CEADC(u8 *p)
{
    p[0x525] = 0;
    p[0x523] = p[0x524];
    p[0x524] = 0;
    return p;
}
