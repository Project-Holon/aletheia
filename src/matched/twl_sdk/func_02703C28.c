/*
 * function: NWMi_CheckFirmDataParamIntegrity
 * address:  0x02703C28
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 0x02FFFDFC is a fixed DSi hardware/ROM buffer address, so the original
 *   source read it through a cast constant (`(u32 *)*(volatile u32 *)`),
 *   the same shape as src/matched/OSi_VerifyStaticSegments.c.  It is a literal pool
 *   word, not a relocation, and needs no witness.
 *
 * symbols:
 *   SVC_GetCRC16  0x02004632  thumb arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 SVC_GetCRC16(u32, u32, u32);

u32 NWMi_CheckFirmDataParamIntegrity(void) {
    u32 *r4 = (u32 *)*(volatile u32 *)0x02FFFDFC;
    u16 crc = SVC_GetCRC16(0xFFFF, (u32)r4 + 0x1e4, 0xc);
    u32 target = r4[0x1e0/4] >> 16;
    if (crc == target) {
        return 1;
    }
    return 0;
}
