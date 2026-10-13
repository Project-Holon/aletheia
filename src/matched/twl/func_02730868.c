/*
 * function: MIi_DoAllocWram
 * address:  0x02730868
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
 *   MIi_SetWramBankMaster 0x02730294 arm twl
 *   MIi_SetWramBankEnable 0x0273032C arm twl
 *   MIi_GetAddress_A 0x0273042C arm twl
 *   MIi_GetAddress_B 0x02730440 arm twl
 *   MIi_GetAddress_C 0x02730454 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 data_02732F6C[3][8];
extern u32 MIi_SetWramBankMaster(u32, u32, u32);
extern u32 MIi_SetWramBankEnable(u32, u32, u32);
extern u32 MIi_GetAddress_A(u32 a);
extern u32 MIi_GetAddress_B(u32 a);
extern u32 MIi_GetAddress_C(u32 a);

u32 MIi_DoAllocWram(u32 ch, int n, u32 val)
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
        if ((v & 3) == 3 && (cur == val || cur == 3)) {
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
        data_02732F6C[ch][start + i] = (data_02732F6C[ch][start + i] & ~3) | val;
        MIi_SetWramBankMaster(ch, start + i, val);
        MIi_SetWramBankEnable(ch, start + i, 1);
    }
    if (ch == 0) {
        return MIi_GetAddress_A(start);
    }
    if (ch == 1) {
        return MIi_GetAddress_B(start);
    }
    if (ch == 2) {
        return MIi_GetAddress_C(start);
    }
    return 0;
}
