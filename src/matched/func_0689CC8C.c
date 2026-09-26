/*
 * function: func_0689CC8C
 * address:  0x0689CC8C
 * packet:   pkt_0689CC8C
 * region:   ov095
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct S {
    u32 arr[16];
    u8 _40[0x42 - 0x40];
    u8 f42;
    u8 _43;
    u8 f44;
};

int func_0689CC8C(struct S *s)
{
    u8 a = s->f44;

    if (a < s->f42) {
        s->f44++;
        return s->arr[a];
    }
    return 0;
}
