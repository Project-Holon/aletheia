/*
 * function: func_02165C10
 * address:  0x02165C10
 * packet:   pkt_ov010_02165C10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;

int func_02165C10(u8 *p)
{
    switch (*(u16 *)(p + 0x30)) {
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x32:
        return 1;
    }
    return 0;
}
