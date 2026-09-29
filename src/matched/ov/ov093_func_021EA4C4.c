/*
 * function: func_021EA4C4
 * address:  0x021EA4C4
 * packet:   pkt_ov093_021EA4C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[0x1c];
    int (*f1c)(void *, void *);
    int (*f20)(void *, void *);
    void *f24;
    int f28;
};

int func_021EA4C4(struct S *s)
{
    if (s->f1c != 0) {
        if (s->f1c((char *)s + 0x28, s->f24) != 0) {
            s->f1c = 0;
            s->f28 = 0;
        }
        return 0;
    }
    if (s->f20 != 0) {
        if (s->f20((char *)s + 0x28, s->f24) != 0) {
            s->f20 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
