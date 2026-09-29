/*
 * function: func_021EFBFC
 * address:  0x021EFBFC
 * packet:   pkt_ov026_021EFBFC
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   d_021EFD1C     0x021EFD1C  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020056EC(u32 v);
extern u8 d_021EFD1C[];

void func_021EFBFC(u16 *p)
{
    p[1] = 1;
    p[2] = 1;
    p[6] = func_020056EC(3) + 0x18;
    p[4] = 4;
    p[5] = d_021EFD1C[p[6]];
    p[7] = func_020056EC(0x12C) + 0xF0;
    p[8] = 0xD;
    p[9] = 0x692;
}
