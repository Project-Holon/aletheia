/*
 * function: func_021C576C
 * address:  0x021C576C
 * packet:   pkt_ov021_021C576C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Raises the done flag on map object 0x13 (EXACT*: pad).
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *func_02020350(void *a, u32 id);

void func_021C576C(void *a)
{
    *(u32 *)(func_02020350(a, 0x13) + 0x44) = 1;
}
