/*
 * function: func_02208C30
 * address:  0x02208C30
 * packet:   pkt_02208C30
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
typedef signed int s32;

typedef struct Anim {
    u8 pad00[0x28];
    int state;
} Anim;

int func_02208C30(Anim *p)
{
    if (p->state == 0)
        return 1;
    return 0;
}
