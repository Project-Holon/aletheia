/*
 * function: func_02183E48
 * address:  0x02183E48
 * packet:   pkt_ov022_02183E48
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02173614  0x02173614  thumb  ov012
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef void (*Cb)(int idx, u8 *ent, u32 arg);

typedef struct Ent {
    u32 w[8];
    u8 f20[8];
} Ent;

typedef struct S {
    u8 b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    u8 b10, b11;
    u8 pad12[0x2c - 0x12];
    Ent ents[5];
    Cb cbf4;
    Cb cbf8;
    u32 argfc;
} S;

typedef struct T14 {
    u8 pad[0x14];
    u8 f[1];
} T14;

extern int func_0203D1C0(int a);
extern int func_0203D378(void);
extern void func_02173614(u8 *a, u8 *b);

typedef struct C {
    u8 pad[0x2830];
    T14 t;
} C;

void func_02183E48(S *s, C *c)
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
