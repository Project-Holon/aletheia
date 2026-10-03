/*
 * function: func_021B6994
 * address:  0x021B6994
 * packet:   pkt_ov093_021B6994
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u32 f04;
    u8 pad08[0x1a];
    u8 f22;
    u8 pad23;
    void *f24[4];
};

extern u32 func_0201AA18(void *p);

int func_021B6994(struct S **pp, u32 b)
{
    struct S *p = *pp;
    void *q;

    switch (p->f04) {
    case 0:
        return 1;
    case 3:
        return 1;
    case 2:
        return 3;
    case 1:
        if (p->f22 == 0) {
            return 2;
        }
        if (p->f00 == 3) {
            return 1;
        }
        q = p->f24[(u8)((b + 2) & 3)];
        if (q != 0 && (int)func_0201AA18(q) > 0) {
            return 1;
        }
        return 2;
    }
    return 1;
}
