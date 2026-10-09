/*
 * function: func_02730CC0
 * address:  0x02730CC0
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

u32 func_02730CC0(u32 ch, u32 val, u32 newval)
{
    int lim, i, count;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = newval | (v & ~3);
            func_02730294(ch, i, newval);
            func_0273032C(ch, i, 1);
            count++;
        }
    }
    return count;
}
