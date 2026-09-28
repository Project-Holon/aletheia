/*
 * function: func_0207D55C
 * address:  0x0207D55C
 * packet:   pkt_0207D55C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GXx_GetMasterBrightness_  0x0207D55C  arm
 *
 * TwlSDK libgx gx.o. Reads a master-brightness register back, negating it for
 * the fade-down mode.
 */

typedef unsigned short u16;
typedef volatile u16 vu16;

#define REG_GX_MASTER_BRIGHT_E_MOD_MASK   0xc000
#define REG_GX_MASTER_BRIGHT_E_MOD_SHIFT  14
#define REG_GX_MASTER_BRIGHT_E_VALUE_MASK 0x001f

int func_0207D55C(vu16 *reg)
{
    u16 mode = (u16)(*reg & REG_GX_MASTER_BRIGHT_E_MOD_MASK);

    if (mode == 0)
    {
        return 0;
    }
    else if (mode == (1 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT))
    {
        return *reg & REG_GX_MASTER_BRIGHT_E_VALUE_MASK;
    }
    else if (mode == (2 << REG_GX_MASTER_BRIGHT_E_MOD_SHIFT))
    {
        return -(*reg & REG_GX_MASTER_BRIGHT_E_VALUE_MASK);
    }
    else
    {
        return 0;
    }
}
