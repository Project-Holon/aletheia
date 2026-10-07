/*
 * file:     union_app_p02.c
 * unit:     yes
 * function: func_02183DAC, func_02183DDC, func_02183E48, func_02183EE0, func_02183F6C, func_02183F7C, func_02183F84, func_02183F88, func_02183F98
 * address:  0x02183DAC
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
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02174010 0x02174010 thumb ov012
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02173614  0x02173614  thumb  ov012
 *   func_02082D44  0x02082D44  arm
 */
#include "../../matched/include/Obj00660.h"

struct Link;
struct Entry;
typedef unsigned char u8;

typedef unsigned int u32;

typedef void (*Cb)(int idx, u8 *ent, u32 arg);

typedef struct Ent {
    u32 w[8];
    u8 f20[8];
} Ent;

typedef struct S_02183E48 {
    u8 b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    u8 b10, b11;
    u8 pad12[0x2c - 0x12];
    Ent ents[5];
    Cb cbf4;
    Cb cbf8;
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

extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *);
extern u32 func_02174010(u32 a, void *p);
extern u32 func_0203D1C0(u32 index);
extern u32 func_0203D378(void);
extern void func_02173614(u8 *self, const u8 *mac);
extern void func_02082D44(const void *src, void *dst, u32 len);
void func_02183DAC(u8 *p);
void func_02183DDC(u8 *s);
void func_02183E48(S_02183E48 *s, C *c);
void func_02183EE0(S_02183EE0 *s, C *c);
void func_02183F6C(u8 *p, u8 a);
void func_02183F7C(u8 *p);
u8 func_02183F84(u8 *p);
void func_02183F88(u8 *p, u8 a);
void func_02183F98(void *p, const void *value);

void func_02183DAC(u8 *p)
{
    u32 i;
    if (p[13] != 0) {
        i = func_0203D1A4((struct Link *)func_020399A8());
        if (func_02174010(p[13], p + 0x2c + i * 40) == 1) p[13] = 0;
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_02183DDC(u8 *s)
{
    int i;
    u32 m;
    u8 *ents;
    Cb cb;

    if (s[7] != 0) {
        i = 0;
        ents = s + 0x2c;
        for (; i < 5; i++) {
            m = 1 << i;
            if (s[7] & m) {
                if ((s[0xe] & m) && (s[4] & m)) {
                    s[4] ^= (u8)m;
                    s[1] |= (u8)m;
                    cb = *(Cb *)&((struct Obj00660 *)s)->fF4;
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
    Cb cb;

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
