/*
 * file:     os_ownerInfoEx.c
 * unit:     yes
 * function: OS_IsAvailableWireless_ltdmain, OS_IsForceDisableWireless_ltdmain
 * address:  0x027312D0
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libos.TWL.HYB.a os_ownerinfoex.o
 */

typedef unsigned char u8;
typedef unsigned int u32;

int OS_IsAvailableWireless_ltdmain(void)
{
    return ((**(volatile u32 **)0x02FFFDFC << 28) >> 31) == 1;
}

int OS_IsForceDisableWireless_ltdmain(void)
{
    volatile u8 *p = (volatile u8 *)0x02FFFD68;
    return ((u32)p[4] << 31 >> 31) == 1;
}
