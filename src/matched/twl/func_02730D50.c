/*
 * function: MIi_DoSwitchWramSlot
 * address:  0x02730D50
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

u32 MIi_DoSwitchWramSlot(u32 ch, int start, int n, u32 val, u32 newval)
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
            data_02732F6C[ch][i] = newval | (v & ~3);
            MIi_SetWramBankMaster(ch, i, newval);
            MIi_SetWramBankEnable(ch, i, 1);
            count++;
        }
    }
    return count;
}
