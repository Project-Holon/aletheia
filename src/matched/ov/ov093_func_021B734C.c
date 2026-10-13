/*
 * function: BTL_MAIN_TaskCommSingle
 * address:  0x021B734C
 * packet:   pkt_ov093_021B734C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetClientTrainerIndex  0x021B8BEC  thumb  ov093
 *   gBtlMainCommSingleSteps     0x021EFD1C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct T {
    u8 pad00[0x21];
    u8 f21;
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
};

extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *p, u32 k, u8 n);
extern int (*gBtlMainCommSingleSteps[7])(struct S *, u32 *);

int BTL_MAIN_TaskCommSingle(u32 *pp, struct S *s)
{
    if (*pp == 0) {
        s->f46b = 2;
        s->f428[0] = 0;
        s->f428[1] = 1;
        s->f46c = s->f00->f21;
        s->f46d = BTL_MAIN_GetClientTrainerIndex((u8 *)s, s->f46c, 0);
        *pp = *pp + 1;
        return 0;
    }
    if (*pp < 7) {
        if (gBtlMainCommSingleSteps[*pp](s, &s->f460) != 0) {
            s->f460 = 0;
            *pp = *pp + 1;
        }
        return 0;
    }
    return 1;
}
