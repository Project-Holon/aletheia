/*
 * function: func_0220672C
 * address:  0x0220672C
 * packet:   pkt_0220672C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (saves no lr), seeded by address.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u32 f00;
} Work;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x56];
    Work *work;
} Owner;

void func_0220672C(Owner *o)
{
    Work *w = o->work;

    if (w->f00 == 0)
        w->f00 = 1;
}
