/*
 * function: func_02731060
 * address:  0x02731060
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

u32 func_02731060(u32 ch, int start, int n, u32 val)
{
    int count, i, end;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if (val == ((v & 0x300) >> 8)) {
            data_02732F6C[ch][i] = (v & ~0x300) | 0x300;
            count++;
        }
    }
    return count;
}
