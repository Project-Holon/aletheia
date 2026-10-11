/*
 * file:     unit_0689AD4C.c
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
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021B8588  0x021B8588  thumb
 *   func_021B8C5C  0x021B8C5C  thumb
 *   func_021B9A00  0x021B9A00  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B8588(u32 a);
extern int func_0201BEB8(u32 a, int b);
extern int func_021B9A00(u32 a, u8 *p);
extern u8 func_021B8C5C(int a, u8 b);

typedef struct { u8 n; u8 pad[2]; u8 d[16]; } St;

void func_0689AD4C(St *st, u32 a, u32 b, u32 c)
{
    u8 x;

    if (func_021B8588(a) == 2) {
        if (func_0201BEB8(b, 0xb)) {
            if (func_021B9A00(c, &x)) {
                st->d[st->n++] = x;
                st->d[st->n++] = func_021B8C5C(2, x);
            }
        }
    }
}
