/*
 * file:     nwm_installfirm.c
 * unit:     yes
 * function: NWMi_CheckFirmDataParamIntegrity
 * address:  0x02703C28
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_installfirm.o
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_02004632(u32, u32, u32);

/* 0x02FFFDFC is a fixed DSi hardware/ROM buffer address, read through a cast
 * constant; it is a literal pool word, not a relocation. */
u32 NWMi_CheckFirmDataParamIntegrity(void) {
    u32 *r4 = (u32 *)*(volatile u32 *)0x02FFFDFC;
    u16 crc = func_02004632(0xFFFF, (u32)r4 + 0x1e4, 0xc);
    u32 target = r4[0x1e0/4] >> 16;
    if (crc == target) {
        return 1;
    }
    return 0;
}
