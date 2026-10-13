/*
 * function: PALANM_BlendChannelMask
 * address:  0x02022004
 * packet:   pkt_02021B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_BlendChannel  0x02021FD8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void PALANM_BlendChannel(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);

void PALANM_BlendChannelMask(u32 a0, u32 a1, u16 m, u32 a3, u32 a4)
{
    u32 i = 0;

    if (m == 0) {
        return;
    }
    do {
        if (m & 1) {
            PALANM_BlendChannel(a0, a1, (u16)i, 0x10, a3, a4);
        }
        m = (u16)(m >> 1);
        i += 0x10;
    } while (m != 0);
}
