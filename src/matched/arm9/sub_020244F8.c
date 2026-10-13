/*
 * function: PMSI_PARAM_IsDecoWordAt
 * address:  0x020244F8
 * packet:   pkt_02024368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02024508  0x02024508  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Container {
    u8 pad[4];
    u16 arr[];
};

extern u32 sub_02024508(u32 x);

u32 PMSI_PARAM_IsDecoWordAt(struct Container *p, u32 idx)
{
    return sub_02024508(p->arr[idx]);
}
