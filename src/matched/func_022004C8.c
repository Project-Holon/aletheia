/*
 * function: func_022004C8
 * address:  0x022004C8
 * packet:   pkt_022004C8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Probe the parent object; on success stamp 5 into +0x28 and report 2.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern int func_020221A4(void);

int func_022004C8(u8 *p)
{
    if (func_020221A4()) {
        *(u32 *)(p + 0x28) = 5;
    }
    return 2;
}
