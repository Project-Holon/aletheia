/*
 * file:     union_app.c
 * unit:     yes
 * function: func_02183B60, func_02183BE0, func_02183BE8, func_02183C3C, func_02183CC0, func_02183D34, func_02183D4C, func_02183D94, func_02183DAC, func_02183DDC, func_02183E48, func_02183EE0, func_02183F6C, func_02183F7C, func_02183F84, func_02183F88, func_02183F98, func_02183FA8, func_02183FB8, func_0218401C, func_0218402C, func_02184060, func_021840A4, func_021840A8, func_021840AC, func_021840C8, func_021840FC, func_02184114, func_02184134, func_02184148, func_0218416C, func_02184174, func_0218417C, func_02184180, func_021841A0
 * address:  0x02183B60
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   d_021841C0     0x021841C0  data  a1
 *   func_020307B0  0x020307B0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0217410C  0x0217410C  thumb  ov011
 *   func_02173F20 0x02173F20 thumb ov012
 *   func_02173E68 0x02173E68 thumb ov012
 *   func_02174010 0x02174010 thumb ov012
 *   func_02173614  0x02173614  thumb  ov012
 *   func_02082D44  0x02082D44  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203CD98 0x0203CD98 arm
 */
#include "../../matched/include/Obj00660.h"
#include "../../matched/include/Obj09764.h"
#include "../../matched/include/Obj20328.h"
#include "../../matched/include/Obj20329.h"
#include "../../matched/include/Obj20330.h"

struct Entry;
struct Link;
struct C;
struct S;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Rec20 {
    u32 w[8];
} Rec20;

typedef void (*Cb_02183B60)(int idx, u8 *ent, u32 arg);

typedef struct Ent {
    u32 w[8];
    u8 f20[8];
} Ent;

typedef struct S_02183E48 {
    u8 b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    u8 b10, b11;
    u8 pad12[0x2c - 0x12];
    Ent ents[5];
    Cb_02183B60 cbf4;
    Cb_02183B60 cbf8;
    u32 argfc;
} S_02183E48;

typedef struct T14 {
    u8 pad[0x14];
    u8 f[1];
} T14;

typedef struct C {
    u8 pad[0x2830];
    T14 t;
} C;

typedef struct S_02183EE0 {
    u8 b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    u8 b10, b11;
    u8 pad12[0x2c - 0x12];
    Ent ents[5];
} S_02183EE0;

typedef struct { u32 w[10]; } Blk;

typedef struct { u8 pad[0x14]; u8 tab[1]; } Inner;

typedef void (*Cb_02183FA8)(void);

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern u32 func_0203D378(void);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02087C6C(void *p);
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_020307B0(void *p);
extern u32 func_02080D24(u32 a);
extern u32 func_0200FB24(void);
extern void func_02172D38(u8 *p);
extern int func_02172D68(u8 *p);
extern u32 func_0203D1C0(u32 index);
extern int func_0217410C(int a, int b);
extern u32 func_02173F20(void *p, u32 a);
extern u32 func_02173E68(u32 a);
extern u32 func_02174010(u32 a, void *p);
extern void func_02173614(u8 *self, const u8 *mac);
extern void func_02082D44(const void *src, void *dst, u32 len);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int func_0217357C(u8 *self, const u8 *mac, u32 a2, u32 a3);
extern void func_0203D1E8(u32 unused, void *arg);
extern int func_0203CD98(void);
u8 *func_02183B60(u8 *a, int heap, int kind, Rec20 *src);
void func_02183BE0(void *p);
int func_02183BE8(u8 *s, int i);
void func_02183C3C(u8 *s, u8 *c);
void func_02183CC0(u8 *s);
void func_02183D34(u8 *p);
void func_02183D4C(u8 *s);
void func_02183D94(u8 *p);
void func_02183DAC(u8 *p);
void func_02183DDC(u8 *s);
void func_02183E48(S_02183E48 *s, C *c);
void func_02183EE0(S_02183EE0 *s, C *c);
void func_02183F6C(u8 *p, u8 a);
void func_02183F7C(u8 *p);
u8 func_02183F84(u8 *p);
void func_02183F88(u8 *p, u8 a);
void func_02183F98(void *p, const void *value);
void func_02183FA8(u8 *p, u8 index);
void func_02183FB8(u8 *self, u8 *peer, u32 idx, const Blk *src);
int func_0218401C(u8 *p);
int func_0218402C(u8 *p);
void func_02184060(u8 *s, int i);
void func_021840A4(u8 *s, int i);
unsigned int func_021840A8(unsigned int entry);
void func_021840AC(u8 *s);
int func_021840C8(u8 *p);
void func_021840FC(u8 *p, Cb_02183FA8 a, Cb_02183FA8 b, void *arg);
int func_02184114(unsigned char *p);
void func_02184134(u8 *p);
void func_02184148(unsigned char *p, int a);
void func_0218416C(char *p);
void func_02184174(u8 *p);
u32 func_0218417C(u8 *p);
char *func_02184180(unsigned char *p, int i);
unsigned char func_021841A0(unsigned char *p);
extern u8 d_021841C0[];




u8 *func_02183B60(u8 *a, int heap, int kind, Rec20 *src)
{
    u8 *s;
    u8 buf[0x28];

    s = func_02030734(heap, 0x100, 1, (const char *)d_021841C0, 0x4d);
    if (func_0203D378() == 1) {
        s[1] = 3;
    }
    s[0] = kind;
    s[0x10] = 0xff;
    s[0x11] = 0xff;
    func_02082BCC(buf, 0, 0x28);
    *(Rec20 *)buf = *src;
    func_02087C6C(buf + 0x20);
    func_02183FB8(s, a, func_0203D1A4((struct Link *)((u32)func_020399A8())), (const Blk *)buf);
    func_02184114(s);
    func_0218416C((char *)s);
    return s;
}




/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3 / pool) in ov022; blocker of
 * ov012 func_021743A4.
 */
void func_02183BE0(void *p)
{
    func_020307B0(p);
}




/*
 * Addresses are Black-image addresses.
 */
int func_02183BE8(u8 *s, int i)
{
    u32 n;
    u32 c;

    if (s[9] == 1) {
        return 0;
    }
    n = func_02080D24(s[1]);
    if (s[9] == 2) {
        c = s[0xa];
        if (c + 1 > s[0xb]) {
            return 0;
        }
    }
    if (n + 1 <= s[0]) {
        s[4] = s[4] | (u8)(1 << i);
        if (s[9] == 2) {
            s[0xa] = s[0xa] + 1;
        }
        return 1;
    }
    return 0;
}




void func_02183C3C(u8 *s, u8 *c)
{
    if (func_0200FB24() != 0) {
        return;
    }
    if (((struct Obj00660 *)s)->f28 == 1) {
        return;
    }
    if (((struct Obj00660 *)s)->f20 == 1) {
        func_02172D38(c);
        ((struct Obj00660 *)s)->f20 = 0;
        ((struct Obj00660 *)s)->f24 = 1;
        return;
    }
    if (((struct Obj00660 *)s)->f24 == 1) {
        if (func_02172D68(c) == 0) {
            ((struct Obj00660 *)s)->f24 = 0;
            ((struct Obj00660 *)s)->f28 = 1;
        }
        return;
    }
    if (func_0203D378() == 1) {
        func_02183EE0((S_02183EE0 *)((struct S *)s), (C *)((struct C *)c));
        func_02183D34(s);
        func_02183CC0(s);
        func_02183D4C(s);
        func_02183D94(s);
    }
    func_02183DAC(s);
    func_02183DDC(s);
    func_02183E48((S_02183E48 *)((struct S *)s), (C *)((struct C *)c));
}




void func_02183CC0(u8 *s)
{
    int i;
    u32 m;
    u32 r;
    u8 t;

    r = s[1];
    if (s[0x10] == 0xff) {
        for (i = 0; i < 5; i++) {
            m = 1 << i;
            if (s[1] & m) {
                if (func_0203D1C0((u8)i) == 0) {
                    r ^= m;
                }
            }
        }
        if (r != s[1]) {
            t = r;
            for (i = 0; i < 5; i++) {
                m = 1 << i;
                if (s[1] & m) {
                    if (!(r & m)) {
                        if (func_0217410C(t, i & 0xff) == 1) {
                            func_021840A4(s, (u8)i);
                            s[1] = s[1] ^ (u8)m;
                        }
                    }
                }
            }
        }
    }
}



void func_02183D34(u8 *p)
{
    if (p[12] != 0 && func_02173F20(p, p[12]) == 1) p[12] = 0;
}




void func_02183D4C(u8 *s)
{
    int i;
    u8 m;

    if (s[0x10] != 0xff) {
        if (func_0203D1C0(s[0x10]) != 0) {
            return;
        }
        s[0x10] = 0xff;
        s[0x11] = 0xff;
    }
    m = s[0xf];
    if (m != 0) {
        for (i = 0; i < 5; i++) {
            if (m & (1 << i)) {
                s[0x10] = i;
                s[0x11] = i;
                s[0xf] = s[0xf] ^ (u8)(1 << i);
                return;
            }
        }
    }
}



/*
 * Callee's filed definition says void; original caller reads r0 at
 * 02183DA2, and ov012 callee leaves func_0203D3F8 result live.
 */
void func_02183D94(u8 *p)
{
    if (p[17] != 255 && func_02173E68(p[17]) == 1) p[17] = 255;
}



void func_02183DAC(u8 *p)
{
    u32 i;
    if (p[13] != 0) {
        i = func_0203D1A4((struct Link *)func_020399A8());
        if (func_02174010(p[13], p + 0x2c + i * 40) == 1) p[13] = 0;
    }
}




void func_02183DDC(u8 *s)
{
    int i;
    u32 m;
    u8 *ents;
    Cb_02183B60 cb;

    if (s[7] != 0) {
        i = 0;
        ents = s + 0x2c;
        for (; i < 5; i++) {
            m = 1 << i;
            if (s[7] & m) {
                if ((s[0xe] & m) && (s[4] & m)) {
                    s[4] ^= (u8)m;
                    s[1] |= (u8)m;
                    cb = *(Cb_02183B60 *)&((struct Obj00660 *)s)->fF4;
                    if (cb != 0) {
                        cb((u8)i, ents + i * 0x28, ((struct Obj00660 *)s)->fFC);
                    }
                    s[0x10] = 0xff;
                }
                s[7] = s[7] ^ (u8)m;
            }
        }
    }
}




void func_02183E48(S_02183E48 *s, C *c)
{
    int i;
    u32 m;
    u8 mask;
    Cb_02183B60 cb;

    for (i = 0; i < 5; i++) {
        m = 1 << i;
        if (s->b0e & m) {
            if (func_0203D1C0((u8)i) == 0) {
                if (func_0203D378() == 1 || (s->b01 & m)) {
                    cb = s->cbf8;
                    if (cb != 0) {
                        cb(i & 0xff, (u8 *)&s->ents[i], s->argfc);
                    }
                    s->b01 &= (u8)(m ^ 0xff);
                    s->b0e &= (u8)(m ^ 0xff);
                }
                func_02173614(c->t.f, s->ents[i].f20);
            }
        }
    }
}




void func_02183EE0(S_02183EE0 *s, C *c)
{
    u8 i;
    u32 m;

    for (i = 0; i < 5; i++) {
        m = 1 << i;
        if (s->b04 & m) {
            if (func_0203D1C0(i) == 0) {
                s->b04 ^= (u8)m;
                if (s->b0e & m) {
                    s->b0e &= (u8)(m ^ 0xff);
                    func_02173614(c->t.f, s->ents[i].f20);
                }
                if (s->b09 == 2 && s->b0a != 0) {
                    s->b0a--;
                }
            }
        }
    }
}




void func_02183F6C(u8 *p, u8 a)
{
    p[0xF] |= (u8)(1 << a);
}




/*
 * leaf:     Sole game blocker of assigned ov012 caller; root claim granted.
 */
void func_02183F7C(u8 *p)
{
    p[0x12] = 1;
}




/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s); blocker of ov012
 * func_021743A4.
 */
u8 func_02183F84(u8 *p)
{
    return p[0x12];
}




void func_02183F88(u8 *p, u8 a)
{
    p[0xC] |= (u8)(1 << a);
}




void func_02183F98(void *p, const void *value)
{
    func_02082D44(value, p, 4);
}


/*
 * Unlabelled bit-set leaf; follower 02183FB8 is separate labelled code.
 */
void func_02183FA8(u8 *p, u8 index)
{
    p[13] = p[13] | (u8)(1 << index);
}




void func_02183FB8(u8 *self, u8 *peer, u32 idx, const Blk *src)
{
    Inner *in = (Inner *)&peer[0x2830];
    *(Blk *)(self + 0x2c + idx * 0x28) = *src;
    self[0xe] |= (u8)(1 << idx);
    if (idx != func_0203D1A4((struct Link *)func_020399A8())) {
        u32 a = func_02008554((const struct Sub0200852CObj *)src);
        u32 b = func_02008550((const struct Sub0200852CObj *)src);
        func_0217357C(in->tab, (const u8 *)src + 0x20, a, (u8)b);
    }
}



int func_0218401C(u8 *p)
{
    if (p[1] != 0)
        return 1;
    return 0;
}


int func_0218402C(u8 *p)
{
    int i;
    u32 m;
    for (i = 0; i < 5; i++) {
        m = 1 << i;
        if ((p[1] & m) && func_0203D1C0((u8)i) == 1 && !(p[14] & m)) return 0;
    }
    return 1;
}



void func_02184060(u8 *s, int i)
{
    if (func_0203D378() == 1) {
        if ((s[0xe] & (1 << i)) && (s[4] & (1 << i))) {
            s[7] |= (u8)(1 << i);
        }
    } else {
        s[4] |= (u8)(1 << i);
        s[7] |= (u8)(1 << i);
    }
}


void func_021840A4(u8 *s, int i)
{
}


/*
 * Unlabelled size-return leaf. Extent follower 021840AC already filed separately.
 */
unsigned int func_021840A8(unsigned int entry)
{
    return 4;
}



void func_021840AC(u8 *s)
{
    s[1] = s[1] | (u8)(1 << func_0203D1A4((struct Link *)((u32)func_020399A8())));
}



/*
 * Unlabelled leaf (prints as a .word run in asm/overlays/ov022.s); the
 * sole blocker of ov012 func_0217325C's MATCH. Of the five overlays whose
 * window holds 0x021840C8 only ov022 has a function start there.
 */
int func_021840C8(u8 *p)
{
    if (p == 0)
        return 0;
    switch (p[9]) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        if (p[10] >= p[11])
            return 1;
        return 0;
    }
    return 0;
}



/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): stores the two
 * callbacks and their argument at 0xf4/0xf8/0xfc (the fields
 * func_02183E48 reads). Blocker of ov023 func_02184674.
 */
void func_021840FC(u8 *p, Cb_02183FA8 a, Cb_02183FA8 b, void *arg)
{
    *(Cb_02183FA8 *)&((struct Obj09764 *)p)->fF4 = a;
    *(Cb_02183FA8 *)&((struct Obj09764 *)p)->fF8 = b;
    ((struct Obj09764 *)p)->fFC = arg;
}



int func_02184114(unsigned char *p)
{
    if (p[4] == 0) {
        func_0203D1E8((u32)func_020399A8(), 0);
        p[9] = 1;
        return 1;
    }
    return 0;
}


/*
 * Original r0 return from 020399A8 flows into unused parameter 0 of
 * 0203D1E8; its r1 argument is literal payload 1. No implicit arguments.
 */
void func_02184134(u8 *p)
{
    func_0203D1E8((u32)func_020399A8(), (void *)1);
    p[9] = 0;
}


void func_02184148(unsigned char *p, int a)
{
    if (func_0203CD98()) {
        func_0203D1E8((int)func_020399A8(), (void *)1);
        p[9] = 2;
        p[11] = a;
        p[10] = 0;
    }
}


/*
 * Extent followers 0x02184174, 0x0218417C and 0x02184180 are matched separately.
 */
void func_0218416C(char *p)
{
    ((struct Obj20328 *)p)->f14 = 1;
}



/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): sets the word at
 * 0x20. Blocker of ov023 func_02184674.
 */
void func_02184174(u8 *p)
{
    ((struct Obj20329 *)p)->f20 = 1;
}



/*
 * Unlabelled leaf (a .word run in asm/overlays/ov022.s): returns the word
 * at 0x28. Blocker of ov023 func_02184674.
 */
u32 func_0218417C(u8 *p)
{
    return ((struct Obj20330 *)p)->f28;
}


/*
 * Unlabelled leaf; callers in ov023 (func_02186170, func_02185EA0).
 */
char *func_02184180(unsigned char *p, int i)
{
    int m;

    m = 1 << i;
    if (!(p[0xe] & m) || !(p[1] & m))
        return 0;
    return (char *)p + 0x2c + i * 0x28;
}


unsigned char func_021841A0(unsigned char *p)
{
    return p[1];
}
