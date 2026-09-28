/*
 * function: func_02061FF8
 * address:  0x02061FF8
 * packet:   pkt_02061EB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02061D0C  0x02061D0C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02061D0C(void *p, int arg, u32 *buf);

typedef struct Node02061FF8 {
    u32 f00;
    u32 f04;
    u32 f08;
    struct Node02061FF8 *f0c;
} Node02061FF8;

void func_02061FF8(void *pp, int arg)
{
    Node02061FF8 *n = *(Node02061FF8 **)pp;

    while (n != 0) {
        u32 buf[2];
        buf[0] = n->f00;
        buf[1] = n->f00 + n->f04;
        if (func_02061D0C(pp, arg, buf) != 0) {
            n->f00 = buf[0];
            n->f04 = buf[1] - buf[0];
            n = *(Node02061FF8 **)pp;
        } else {
            n = n->f0c;
        }
    }
}
