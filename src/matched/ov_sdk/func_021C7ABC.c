/*
 * function: arrangeAddress
 * address:  0x021C7ABC
 * packet:   pkt_021C7ABC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sanitises four three-byte rows of a global buffer: every leading byte that
 * is NUL, space or '0' becomes a space, except the third column which becomes
 * '0'; the run stops at the first other byte.
 *
 * symbols:
 *   func_021C78A0  0x021C78A0  arm  ov016
 *   gMemSsea     0x021DE5E4  data
 */

#include "../include/G_MemSsea.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct MemSsea *gMemSsea;

void func_021C78A0(void);

void arrangeAddress(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        char *row = ((char *)gMemSsea) + 8 + i * 3;
        int j;
        for (j = 0; j < 3; j++) {
            u8 c = row[j];
            if (c != 0x30 && c != 0x20 && c != 0)
                break;
            row[j] = (j == 2) ? 0x30 : 0x20;
        }
    }
    func_021C78A0();
}
