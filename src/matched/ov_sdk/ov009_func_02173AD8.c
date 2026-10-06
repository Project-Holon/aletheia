/*
 * function: func_02173AD8
 * address:  0x02173AD8
 * packet:   pkt_02173AD8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Finds the first empty record (stride 0xc) among 0x9a entries and returns
 * its biased index; 0 when none is free.
 *
 * symbols:
 *   d_021AAA40     0x021AAA40  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021AAA40[];

u8 func_02173AD8(void)
{
    u8 i;

    for (i = 0; i < 0x9a; i++) {
        if (d_021AAA40[i * 0xc] == 0)
            return (i + 0x64) & 0xff;
    }
    return 0;
}
