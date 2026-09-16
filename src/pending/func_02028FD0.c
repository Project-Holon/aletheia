/*
 * function: func_02028FD0
 * address:  0x02028FD0
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   g_flagTable_0209FE1C  0x0209FE1C  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct SoundParam {
    u8 pad00[4];
    u32 group;    /* +0x04 */
};

extern const u8 g_flagTable_0209FE1C[];

u32 func_02028FD0(struct SoundParam *obj, u32 kind)
{
    const u8 *p = g_flagTable_0209FE1C + obj->group * 8;
    return p[kind];
}
