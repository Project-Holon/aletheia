/*
 * unit:     yes
 * function: func_02012F68
 * address:  0x02012F68
 * packet:   pkt_02012F68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020071CC  0x020071CC  thumb
 *
 * Two leaves before func_02012F80 (the +0x6a8 getter): save-block getter
 * for block 0x42 through the handle's first word, and the +0x6a8 setter.
 * Seeded from ov048/ov171/ov205 (0x02012F68) and ov010 func_0215DDC8 and
 * func_0215DE0C (0x02012F74).
 */

typedef unsigned int u32;

extern void *func_020071CC(void *sys, unsigned int id);

void *func_02012F68(void **h)
{
    return func_020071CC(*h, 0x42);
}

void func_02012F74(void *h, void *w)
{
    *(void **)((char *)h + 0x6a8) = w;
}
