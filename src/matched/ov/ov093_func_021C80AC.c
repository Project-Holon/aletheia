/*
 * function: func_021C80AC
 * address:  0x021C80AC
 * packet:   pkt_ov093_021C80AC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);

int func_021C80AC(u8 *p, int key)
{
    u32 i;
    u32 total;
    u32 flagged;
    flagged = 0;
    total = 0;
    for (i = 0; i < p[0x782]; i++) {
        u8 *e = p + i * 16;
        if (key != func_021D5440(*(u8 **)(e + 0x7e0))) {
            total++;
            if (e[0x7ed] != 0) {
                flagged++;
            }
        }
    }
    return total == flagged;
}
