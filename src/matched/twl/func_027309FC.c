/*
 * function: MIi_DoAllocWramSlot
 * address:  0x027309FC
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

u32 MIi_DoAllocWramSlot(u32 ch, int start, int n, u32 val)
{
    int end, i;

    if (ch == 0) {
        n = n / 2;
    }
    end = start + n;
    for (i = start; i < end; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) != 3 || (cur != val && cur != 3)) {
            return 0;
        }
    }
    for (i = start; i < end; i++) {
        data_02732F6C[ch][i] = (data_02732F6C[ch][i] & ~3) | val;
        MIi_SetWramBankMaster(ch, i, val);
        MIi_SetWramBankEnable(ch, i, 1);
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
