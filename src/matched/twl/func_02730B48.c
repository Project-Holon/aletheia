/*
 * function: MIi_DoFreeWram
 * address:  0x02730B48
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
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 data_02732F6C[3][8];
extern u32 MIi_SetWramBankMaster(u32, u32, u32);
extern u32 MIi_SetWramBankEnable(u32, u32, u32);

u32 MIi_DoFreeWram(u32 ch, u32 val)
{
    int lim, i, count;

    count = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        if ((v & 3) == val) {
            data_02732F6C[ch][i] = (v & ~3) | 3;
            MIi_SetWramBankMaster(ch, i, 1);
            MIi_SetWramBankEnable(ch, i, 0);
            count++;
        }
    }
    return count;
}
