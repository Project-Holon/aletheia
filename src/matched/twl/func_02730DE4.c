/*
 * function: func_02730DE4
 * address:  0x02730DE4
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
 *   func_0273042C 0x0273042C arm twl
 *   func_02730440 0x02730440 arm twl
 *   func_02730454 0x02730454 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 data_02732F6C[3][8];
extern u32 func_0273042C(u32 a);
extern u32 func_02730440(u32 a);
extern u32 func_02730454(u32 a);

u32 func_02730DE4(u32 ch, int n, u32 val)
{
    int run, start, i, lim;

    if (ch == 0) {
        n = n / 2;
    }
    run = 0;
    lim = 4;
    if (ch != 0) {
        lim = 8;
    }
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && cur == 3) {
            if (run == 0) {
                start = i;
            }
            run++;
            if (run >= n) {
                break;
            }
        } else {
            run = 0;
        }
    }
    if (run < n) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        data_02732F6C[ch][start + i] = (data_02732F6C[ch][start + i] & ~0x300) | (val << 8);
    }
    if (ch == 0) {
        return func_0273042C(start);
    }
    if (ch == 1) {
        return func_02730440(start);
    }
    if (ch == 2) {
        return func_02730454(start);
    }
    return 0;
}
