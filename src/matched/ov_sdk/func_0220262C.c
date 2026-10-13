/*
 * function: func_0220262C
 * address:  0x0220262C
 * packet:   pkt_0220262C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *

 *
 * Hand the size guess back to the main writer with the caller's handle.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void MI_CpuCopy8(u32 a, u32 b, u32 c);

void func_0220262C(u32 a, u32 b)
{
    MI_CpuCopy8(a, b, POKE_TOOL_GetPartyParamSize());
}
