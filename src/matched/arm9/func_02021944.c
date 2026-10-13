/*
 * function: PALANM_SetTransBit
 * address:  0x02021944
 * packet:   pkt_02021944
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_CheckBit  0x02021930  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct S02021944 {
    char pad[0x11a];
    u16 lo : 14;
    u16 hi : 2;
};

extern u8 PALANM_CheckBit(u32 val, int bit);

void PALANM_SetTransBit(struct S02021944 *p, int a1)
{
    if (PALANM_CheckBit(p->lo, a1) == 1)
        return;
    p->lo |= 1 << a1;
}
