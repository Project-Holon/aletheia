/*
 * function: DSP_RecvDataCore
 * address:  0x0270505C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 DSP_RecvDataIsReadyCore(u32 ch);

u16 DSP_RecvDataCore(u32 ch)
{
    while (!DSP_RecvDataIsReadyCore(ch)) {
    }
    return *(volatile u16 *)(0x04004300 + ch * 8 + 0x24);
}
