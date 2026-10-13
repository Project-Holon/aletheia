/*
 * function: MI_IsNDmaBusy
 * address:  0x0272FC90
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

unsigned int MI_IsNDmaBusy(int ch)
{
    return (*(volatile unsigned int *)(0x0400411C + ch * 0x1C) & 0x80000000) >> 31;
}
