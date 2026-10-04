/*
 * function: func_02166658
 * address:  0x02166658
 * packet:   pkt_ov010_02166658
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unlabelled leaf (no lr save) called from func_02166734 case 4; 18 bytes
 * plus 2 bytes of alignment padding before func_0216666C.
 */
typedef unsigned char u8;
typedef unsigned int u32;

u32 func_02166658(void *p, u32 i)
{
    if (p == 0)
        return 10;
    return *(u32 *)((u8 *)p + i * 0x1C + 0x14);
}
