/*
 * file:     fld_trade_p04.c
 * unit:     yes
 * function: func_021CE934, func_021CE984, func_021CE9A0, func_021CE9E4, func_021CEA28, func_021CEA50, func_021CEA84, func_021CEAB0, func_021CEADC, func_021CEAF8, func_021CEB04, func_021CEB20, func_021CEB64, func_021CEB84
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
 *   func_02082D44  0x02082D44  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_021CEF1C  0x021CEF1C  thumb  ov021
 *   func_0219097C  0x0219097C  thumb  ov021
 *   data_021DB478  0x021DB478  data  a4
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021CEE00  0x021CEE00  thumb  ov021
 *   func_021CEE48  0x021CEE48  thumb  ov021
 *   func_021CEDA0  0x021CEDA0  thumb  ov021
 *   func_02190A14  0x02190A14  thumb  ov021
 *   func_020392B8  0x020392B8  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_021CF1AC  0x021CF1AC  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_02190B1C  0x02190B1C  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 */
#include "../../matched/include/Obj00011.h"
#include "../../matched/include/Obj00659.h"
#include "../../matched/include/Obj07591.h"

struct Sub0200852CObj;
struct WordSet;
struct Slot;
struct MsgBank;
struct P;
struct U16Vec;
struct Handle;
struct Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

typedef struct {
    u8 pad0[0x2c8];
    u32 busy;
    u32 result;
    u8 state;
    u8 pad2d1[2];
    u8 prev;
    u16 timer;
} Sub;

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
extern void func_02082D44(void *src, void *dst, int n);
extern u32 func_02188C54(u8 *p);
extern u32 func_02190A20(u32, u32);
extern void func_021CEF1C(u8 *p);
extern u32 func_0219097C(u32, const void *, u32);
extern int func_021909BC(void *a);
extern void func_021CEE00(u8 *p);
extern void func_021CEE48(u8 *p);
extern int func_021CEDA0(u8 *p);
extern void func_02190A14(u8 *p);
extern int func_020392B8(void);
extern int func_02039ACC(void);
extern u32 func_020362DC(void);
extern struct Entry *func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern u32 func_021CF1AC(u32 a, u32 b, u32 c);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_0219049C(u8 *p);
extern int func_02190B1C(u32 a);
extern u32 func_02190EF0(u32 *p);
void func_021CE934(S_021CE934 *p, u32 b, u32 c);
void func_021CE984(u32 *p, u32 n);
void func_021CE9A0(u8 *p);
void func_021CE9E4(S_021CE984 *p, u32 m);
void func_021CEA28(Work *p);
int func_021CEA50(u8 *p);
void func_021CEA84(u8 *p, int n);
void func_021CEAB0(u8 *p);
u8 *func_021CEADC(u8 *p);
void *func_021CEAF8(u8 *p);
void func_021CEB04(u8 *p, void *src);
void func_021CEB20(u8 *p);
void func_021CEB64(u8 *p);
u32 func_021CEB84(u8 *p);
extern const u8 data_021DB478[];



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


void *func_021CEAF8(u8 *p)
{
    return p + 0x494;
}



void func_021CEB04(u8 *p, void *src)
{
    func_02082D44(src, p + 0x494, 0x84);
    p[0x518] = 1;
}



/*
 * Addresses are Black-image addresses.
 */
void func_021CEB20(u8 *p)
{
    u32 h;

    h = func_02188C54((u8 *)(((struct Obj00659 *)p)->f0));
    ((struct Obj00659 *)p)->f13C = func_02190A20(0x10, ((struct Obj00659 *)p)->f528);
    func_021CEF1C(p);
    ((struct Obj00659 *)p)->f140 = func_0219097C(h, data_021DB478, ((struct Obj00659 *)p)->f13C);
    p[0x40c] = 0;
}



void func_021CEB64(u8 *p)
{
    if (((struct Obj07591 *)p)->f140 != 0) {
        func_021909BC((void *)(((struct Obj07591 *)p)->f140));
        ((struct Obj07591 *)p)->f140 = 0;
        p[0x40e] = 0;
    }
}



u32 func_021CEB84(u8 *p)
{
    u32 *w = (u32 *)(p + 0x130);
    Sub *s = (Sub *)(p + 0x13c);
    u32 r;

    switch (s->state) {
    case 0:
        if (s->busy == 0) {
            func_021CEE00(p);
            func_021CEE48(p);
            if (func_021CEDA0(p) == 0) {
                s->result = 3;
                s->state = 3;
            } else if (p[0x40d] == 1) {
                func_021CEF1C(p);
                func_02190A14((u8 *)(((struct Obj00011 *)p)->f140));
                p[0x40d] = 0;
            }
        } else if (func_020392B8() > 1) {
            if (func_02039ACC() == 1) {
                s->state++;
            }
        } else {
            if (func_020362DC() & 2) {
                s->prev = s->state;
                s->state = 4;
            }
            (s->timer)++;
            if (s->timer >= 300) {
                s->state = 6;
                func_021CE9E4((S_021CE984 *)p, 0x24);
            }
        }
        break;
    case 1:
        if (func_020399B8((u8 *)func_020399A8()) == 1) {
            ((struct Obj00011 *)p)->f52C = 0;
            if (func_021CF1AC((u32)(p + 0x30), 0, p[0x51b]) == 1) {
                s->state = 2;
            }
        } else if (func_020362DC() & 2) {
            s->prev = s->state;
            s->state = 4;
        }
        if (p[0x51a] == 1) {
            s->result = 1;
            s->state = 3;
        }
        break;
    case 2:
        if (((struct Obj00011 *)p)->f52C == 1) {
            s->result = 1;
            s->state = 3;
        } else if (((struct Obj00011 *)p)->f52C == 2) {
            s->result = 2;
            s->state = 3;
        } else if (func_020362DC() & 2) {
            s->prev = s->state;
            s->state = 4;
        }
        if (p[0x51a] == 1) {
            s->result = 1;
            s->state = 3;
        }
        break;
    case 3:
        return s->result;
    case 4:
        func_021CE9E4((S_021CE984 *)p, 0x23);
        *w = (u32)func_02190BE4((u16 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0)), 0);
        s->state = 5;
        break;
    case 5:
        r = func_02190C78((struct Handle *)(*w));
        if (func_0219049C((u8 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0))) == 1 && p[0x576] == 1) {
            r = 1;
        }
        if (r == 2 && func_0219049C((u8 *)func_02188C54((u8 *)(((struct Obj00011 *)p)->f0))) == 1) {
            if (p[0x519] == 1 || p[0x51a] == 1) {
                func_021909BC((void *)(*w));
                *w = 0;
                s->result = 1;
                s->state = 3;
            }
        } else {
            func_021909BC((void *)(*w));
            *w = 0;
            if (r == 1) {
                s->state = s->prev;
                func_021CE9E4((S_021CE984 *)p, 0x20);
                if (((struct Obj00011 *)p)->f140 != 0) {
                    func_02190B1C(((struct Obj00011 *)p)->f140);
                }
            } else {
                s->result = 3;
                s->state = 3;
            }
        }
        break;
    case 6:
        if (func_02190EF0((u32 *)(((struct Obj00011 *)p)->f14)) == 1) {
            s->result = 3;
            s->state = 3;
        }
        break;
    }
    return 0;
}
