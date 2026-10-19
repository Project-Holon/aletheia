/*
 * function: SCRCMD_PALPARK_ClearExpiredGPower
 * address:  0x021CC6A8
 * packet:   pkt_ov021_021CC6A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores the current value of GPOWER_GetExpiringPowerId in one variable and whether it changes away from 0x30 after a GPOWER_ClearByPowerId round trip in another.
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GPOWER_GetExpiringPowerId  0x02010F18  thumb
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   GPOWER_ClearByPowerId  0x02010F40  thumb
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *vm, void *ctx);
extern u8 GPOWER_GetExpiringPowerId(void);
extern void *GPOWER_LoadPowerTable(u32 heap);
extern void GPOWER_ClearByPowerId(u16 v, void *p);
extern void GPOWER_FreePowerTable(void *p);

int SCRCMD_PALPARK_ClearExpiredGPower(void *vm, void *ctx)
{
    u16 *a = SCRIPT_WORK_ReadWorkPointer(vm, ctx);
    u16 *b = SCRIPT_WORK_ReadWorkPointer(vm, ctx);
    void *p;

    *a = GPOWER_GetExpiringPowerId();
    if (*a != 0x30) {
        p = GPOWER_LoadPowerTable(0x8015);
        GPOWER_ClearByPowerId(*a, p);
        GPOWER_FreePowerTable(p);
        *b = (GPOWER_GetExpiringPowerId() != 0x30) ? 1 : 0;
    } else {
        *b = 0;
    }
    return 0;
}
