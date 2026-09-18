/*
 * function: func_020244D4
 * address:  0x020244D4
 * packet:   pkt_02024368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_020244D4(void *obj, u32 idx)
{
    u16 val = ((u16 *)((char *)obj + 4))[idx];

    if (val == 0xffff) {
        return 0xffff;
    }
    return (u16)(val & (0xffff >> 5));
}
