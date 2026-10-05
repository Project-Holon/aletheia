/*
 * function: func_02183EE0
 * address:  0x02183EE0
 * packet:   pkt_ov022_02183EE0
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sibling of func_02183E48 (same S/C layout).
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02173614  0x02173614  thumb  ov012
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ent {
    u32 w[8];
    u8 f20[8];
} Ent;

typedef struct S {
    u8 b00, b01, b02, b03, b04, b05, b06, b07, b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    u8 b10, b11;
    u8 pad12[0x2c - 0x12];
    Ent ents[5];
} S;

typedef struct T14 {
    u8 pad[0x14];
    u8 f[1];
} T14;

typedef struct C {
    u8 pad[0x2830];
    T14 t;
} C;

extern u32 func_0203D1C0(u32 index);
extern void func_02173614(u8 *self, const u8 *mac);

void func_02183EE0(S *s, C *c)
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
