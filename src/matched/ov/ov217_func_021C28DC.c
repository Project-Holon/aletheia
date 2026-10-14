/*
 * function: PERCENTAGE_GetTensPosition
 * address:  0x021C28DC
 * packet:   pkt_ov217_021C28DC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void PERCENTAGE_GetTensPosition(const u32 *p, u16 *a, u16 *b)
{
    *a = p[1] + 0xF;
    *b = p[2] - 8;
}
