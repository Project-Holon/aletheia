/*
 * function: func_0202A994
 * address:  0x0202A994
 * packet:   pkt_0202A440
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0201ADE4(u32 a, int b, u32 c);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);

void func_0202A994(u32 a, u32 b, int c, u32 *out, u16 d)
{
    u32 t = c & 0xf;
    u32 u = (c & 0xf0) >> 4;
    u32 v;

    if (c == 0)
        return;

    v = (u32)func_0201ADE4((u16)a, (u16)b, d);

    if (t != 0) {
        *out = func_0201AE1C((const struct Personal *)v, 0x14);
        if (t == 1)
            *out = *out + 2;
        else
            *out = *out - 2;
    }

    if (u == 1)
        *out &= ~(u32)1;
    else if (u == 2)
        *out |= (u32)1;

    func_0201AE14((void *)v);
}
