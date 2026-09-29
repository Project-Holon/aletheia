/*
 * function: func_021EFBA4
 * address:  0x021EFBA4
 * packet:   pkt_ov026_021EFBA4
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

void func_021EFBA4(u16 *p)
{
    int i;
    u16 *q;

    i = 0;
    p[1] = 0;
    p[2] = func_020056EC(2) + 1;
    for (; i < p[2]; i++) {
        q = (u16 *)((u8 *)p + i * 12);
        q[6] = func_020056EC(3) + 0x12;
        q[4] = 4;
        q[5] = d_021EFD1C[q[6]];
        q[7] = func_020056EC(0xF0) + 0x78;
        q[8] = 0x1C;
        q[9] = 0x693;
    }
}
