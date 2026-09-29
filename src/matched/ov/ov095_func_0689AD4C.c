/*
 * function: func_0689AD4C
 * address:  0x0689AD4C
 * packet:   pkt_ov095_0689AD4C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689AD9C  0x0689AD9C  thumb  ov095
 *   func_0689ADAC  0x0689ADAC  thumb  ov095
 *   func_0689ADBC  0x0689ADBC  thumb  ov095
 *   func_0689ADCC  0x0689ADCC  thumb  ov095
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0689AD9C(u32 a);
extern int func_0689ADAC(u32 a, int b);
extern int func_0689ADBC(u32 a, u8 *p);
extern u8 func_0689ADCC(int a, u8 b);

typedef struct { u8 n; u8 pad[2]; u8 d[16]; } St;

void func_0689AD4C(St *st, u32 a, u32 b, u32 c)
{
    u8 x;

    if (func_0689AD9C(a) == 2) {
        if (func_0689ADAC(b, 0xb)) {
            if (func_0689ADBC(c, &x)) {
                st->d[st->n++] = x;
                st->d[st->n++] = func_0689ADCC(2, x);
            }
        }
    }
}
