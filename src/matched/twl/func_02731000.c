/*
 * function: func_02731000
 * address:  0x02731000
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732F6C 0x02732F6C data twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 data_02732F6C[3][8];

u32 func_02731000(u32 ch, u32 val)
{
    int count, i, lim;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if (val == ((v & 0x300) >> 8)) {
            data_02732F6C[ch][i] = (v & ~0x300) | 0x300;
            count++;
        }
    }
    return count;
}
