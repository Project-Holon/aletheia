/*
 * function: FIELD_MSGBG_SetBlend
 * address:  0x02193044
 * packet:   pkt_ov021_02193044
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void func_0207D63C(void *reg, u32 a, u32 b, u32 c, u32 d);

void FIELD_MSGBG_SetBlend(u32 v)
{
    if (v == 1)
        func_0207D63C((void *)0x04000050, 4, 0x1B, 0x10, 4);
}
