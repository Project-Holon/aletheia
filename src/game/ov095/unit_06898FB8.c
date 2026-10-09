/*
 * file:     unit_06898FB8.c
 * function: func_06898FB8
 * address:  0x06898FB8
 * packet:   pkt_ov095_06898FB8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06899000  0x06899000  thumb
 *   func_06899010  0x06899010  thumb
 *   func_06899020  0x06899020  thumb
 *   func_06899030  0x06899030  thumb
 *   func_06899040  0x06899040  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_06899000(int a);
extern u8 *func_06899010(int p, int n, u8 v);
extern void func_06899020(u8 *p, int n, int c);
extern void func_06899030(u8 *p, u8 v);
extern void func_06899040(int p, u8 *q);

void func_06898FB8(int a0, int p, int a2, int *s)
{
    u8 v;
    u8 *t;

    if (*s != 0) {
        v = func_06899000(4);
        t = func_06899010(p, 4, v);
        func_06899020(t + 4, 2, 0x347);
        func_06899030(t + 4, v);
        func_06899040(p, t);
        *s = 0;
    }
}
