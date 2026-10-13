/*
 * function: WIPE_SUB_SetWindowVisible
 * address:  0x02023B48
 * packet:   pkt_02023AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   reg_DISPCNT_SUB  0x04001000  data
 */

typedef unsigned int u32;

#define REG_DISPCNT     (*(volatile u32 *)0x04000000)
#define REG_DISPCNT_SUB (*(volatile u32 *)0x04001000)

void WIPE_SUB_SetWindowVisible(u32 val, u32 engine)
{
    if (engine == 0) {
        REG_DISPCNT = (REG_DISPCNT & 0xffff1fff) | (val << 13);
    } else {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & 0xffff1fff) | (val << 13);
    }
}
