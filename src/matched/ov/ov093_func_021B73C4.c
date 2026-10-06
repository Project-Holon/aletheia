/*
 * function: func_021B73C4
 * address:  0x021B73C4
 * packet:   pkt_ov093_021B73C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   d_021EFD00     0x021EFD00  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct T {
    u8 pad00[0x21];
    u8 f21;
    u8 f22;
};

struct S {
    struct T *f00;
    u8 pad04[0x424];
    u8 f428[6];
    u8 pad42e[0x32];
    u32 f460;
    u8 pad464[7];
    u8 f46b;
    u8 f46c;
    u8 f46d;
    u8 pad46e[3];
    u8 f471;
};

extern u8 func_021B8BEC(u8 *p, u32 k, u8 n);
extern int (*d_021EFD00[7])(struct S *, u32 *);

int func_021B73C4(u32 *pp, struct S *s)
{
    if (*pp == 0) {
        switch (s->f00->f22) {
        case 0:
        default:
            s->f46b = 2;
            s->f428[0] = 0;
            s->f428[1] = 1;
            s->f428[2] = 0;
            s->f428[3] = 1;
            break;
        case 2:
            s->f471 = 2;
        case 1:
            s->f46b = 4;
            s->f428[0] = 0;
            s->f428[1] = 1;
            s->f428[2] = 2;
            s->f428[3] = 3;
            break;
        }
        s->f46c = s->f00->f21;
        s->f46d = func_021B8BEC((u8 *)s, s->f46c, 0);
        *pp = *pp + 1;
        return 0;
    }
    if (*pp < 7) {
        if (d_021EFD00[*pp](s, &s->f460) != 0) {
            s->f460 = 0;
            *pp = *pp + 1;
        }
        return 0;
    }
    return 1;
}
