/*
 * function: WIPE_SUB_SetWindowOutside
 * address:  0x02023BFC
 * packet:   pkt_02023AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   reg_BLDCNT      0x0400004A  data
 *   reg_BLDCNT_SUB  0x0400104A  data
 */

typedef unsigned short u16;
typedef unsigned int   u32;

#define REG_BLDCNT     (*(volatile u16 *)0x0400004A)
#define REG_BLDCNT_SUB (*(volatile u16 *)0x0400104A)

void WIPE_SUB_SetWindowOutside(u32 a, u32 flag, u32 engine)
{
    u32 val;

    if (engine == 0) {
        val = (REG_BLDCNT & ~0x3f) | a;
        if (flag != 0) {
            val |= 0x20;
        }
        REG_BLDCNT = (u16)val;
    } else {
        val = (REG_BLDCNT_SUB & ~0x3f) | a;
        if (flag != 0) {
            val |= 0x20;
        }
        REG_BLDCNT_SUB = (u16)val;
    }
}
