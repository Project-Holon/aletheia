/*
 * function: SYMBOL_SAVE_InitBlock
 * address:  0x0200E098
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Zeroes 0x850 bytes then runs the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_InitBlock.c \
 *       --func SYMBOL_SAVE_InitBlock --addr 0x0200E098 --thumb --cc 1.1p1
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   SYMBOL_SAVE_UpdateChecksum  0x0200E024  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *p, u32 v, u32 size);
extern void SYMBOL_SAVE_UpdateChecksum(void *obj);

void SYMBOL_SAVE_InitBlock(u8 *p)
{
    MI_CpuFill8(p, 0, 0x850);
    SYMBOL_SAVE_UpdateChecksum(p);
}
