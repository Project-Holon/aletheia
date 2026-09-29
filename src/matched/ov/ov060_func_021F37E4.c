/*
 * function: func_021F37E4
 * address:  0x021F37E4
 * packet:   pkt_ov060_021F37E4
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021F3880  0x021F3880  thumb  ov060
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern void *func_02188D2C(void *p);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(void *p, int i, u16 j, int v);
extern void func_021BE4B4(void *p, int i, u16 j, int v);
extern u8 func_021F3880(void *a, void *b, void *c);

void func_021F37E4(u8 *out, void *b, void *c, void *d)
{
    void *s;
    int i;
    V *p;

    s = func_02188D2C(b);
    for (i = 0; i < 0x15; i++) {
        p = func_021BE480(s, 0, i);
        p->a = 0x1F8000;
        p->b = 0x20000;
        p->c = 0x1B8000;
        func_021BE4A4(s, 0, i, 1);
        func_021BE4B4(s, 0, i, 1);
    }
    *out = func_021F3880(c, s, d);
}
