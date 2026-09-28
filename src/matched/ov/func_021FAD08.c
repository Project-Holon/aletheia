/*
 * function: func_021FAD08
 * address:  0x021FAD08
 * packet:   pkt_021FAD08
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Flush the queued value when the probe reports empty, then answer -1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern int func_0202CE40(u32 v, int z);

int func_021FAD08(u8 *p)
{
    if (func_0202CE40(*(u32 *)(p + 0x18), 0) == 0) {
        *(u32 *)(p + 0x48) = *(u32 *)(p + 0x4c);
    }
    return -1;
}
