/*
 * function: func_02165C78
 * address:  0x02165C78
 * packet:   pkt_02165C78
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200E3A4  0x0200E3A4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0200E3A4(const u8 *bits, int id);

int func_02165C78(int a0, int a1)
{

a0 = a0 + 0x50;
a1 = 0x19;
    a0 = func_0200E3A4((const u8 *)a0, a1);
loc_02165C82:
    if (a0 != 0) goto loc_02165C8A;
loc_02165C86:
a0 = 0xff;
    return a0;
loc_02165C8A:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}
