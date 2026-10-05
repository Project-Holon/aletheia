/*
 * function: func_02208C10
 * address:  0x02208C10
 * packet:   pkt_02208C10
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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

void func_02208C10(Anim *p)
{
    p->state = 1;
}
