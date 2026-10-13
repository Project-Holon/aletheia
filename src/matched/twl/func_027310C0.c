/*
 * function: MIi_DoGetAllocatableWramSlot
 * address:  0x027310C0
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

u32 MIi_DoGetAllocatableWramSlot(u32 ch, u32 val)
{
    u32 mask;
    int i, lim;

    mask = 0;
    lim = (ch == 0) ? 4 : 8;
    for (i = 0; i < lim; i++) {
        u16 v = data_02732F6C[ch][i];
        u32 cur = (v & 0x300) >> 8;
        if ((v & 3) == 3 && (cur == val || cur == 3)) {
            mask |= 1 << i;
        }
    }
    return mask;
}
