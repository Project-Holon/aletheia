/*
 * function: BTLV_INPUT_ReleaseBgLayers
 * address:  0x022025B4
 * packet:   pkt_ov094_022025B4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 i);

void BTLV_INPUT_ReleaseBgLayers(void)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_02040588((u8)(i + 4), (int)0);
        func_020403F4((u8)(i + 4));
    }
}
