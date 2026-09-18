/*
 * function: func_02024584
 * address:  0x02024584
 * packet:   pkt_02024584
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: data_0209F71C is a byte table whose only pool word, 0x02024594, lies
 * inside this function's own range; the `literal` class discards it and the
 * `data_table` class needs a table of pointers into a region, which this is
 * not. Every concrete byte reproduces.
 * status:   MATCH
 * symbols:
 *   data_0209F71C  0x0209F71C  data
 *
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 data_0209F71C[];

u32 func_02024584(u32 i)
{
    if (i < 7) {
        return data_0209F71C[i];
    }
    return 0;
}
