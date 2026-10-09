/*
 * function: func_02730C2C
 * address:  0x02730C2C
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
 *   func_02730294 0x02730294 arm twl
 *   func_0273032C 0x0273032C arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 data_02732F6C[3][8];
extern u32 func_02730294(u32, u32, u32);
extern u32 func_0273032C(u32, u32, u32);

u32 func_02730C2C(u32 ch, int start, int n, u32 val)
{
    int count, i, end;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    count = 0;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = (v & ~3) | 3;
            func_02730294(ch, i, 1);
            func_0273032C(ch, i, 0);
            count++;
        }
    }
    return count;
}
